//----------------------------------------------------------------------------------------------------------------------------------

#include "mass_storage_class.h"
#include "sd_card_interface.h"
#include "usb_interface.h"

//----------------------------------------------------------------------------------------------------------------------------------


const USB_DeviceDescriptor_1 Mass_Storage_DevDesc =
{
  sizeof (USB_DeviceDescriptor_1),
  DEVICE_DESCRIPTOR,
  0x0200,                 //Version 2.0
  0x00,
  0x00,
  0x00,
  USB_EP0_FIFO_SIZE,      //Ep0 FIFO size
  0x0483,                 //STM
  0x5720,                 //Mass storage device
  0x0200,                 //Release version
  0x01,                   //iManufacturer
  0x02,                   //iProduct
  0x00,                   //ISerial
  0x01
};

const Mass_Storage_Descriptor Mass_Storage_ConfDesc =
{
  {
    sizeof (USB_ConfigDescriptor_1),
    CONFIGURATION_DESCRIPTOR,
    CONFIG_MASS_STORAGE_DESCRIPTOR_LEN, //Total length of the Configuration descriptor
    0x01, //NumInterfaces
    0x01, //Configuration Value
    0x00, //Configuration Description String Index
    0xC0, //Self Powered, no remote wakeup
    0x32 //Maximum power consumption 500 mA
  },
  {
    sizeof (USB_InterfaceDescriptor_1),
    INTERFACE_DESCRIPTOR,
    0x00, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x02, //ep number
    0x08, //Interface Class    (Mass storage interface)
    0x06, //Interface Subclass
    0x50, //Interface Protocol (Bulk only transport)
    0x04  //Interface Description String Index
  },
  {
    {
      sizeof (USB_EndPointDescriptor_1),
      ENDPOINT_DESCRIPTOR,
      0x81, //endpoint 1 IN
      2,    //bulk
      512,  //IN EP FIFO size  512 bytes
      0
    },
    {
      sizeof (USB_EndPointDescriptor_1),
      ENDPOINT_DESCRIPTOR,
      0x01, //endpoint 1 OUT
      2,    //bulk
      512,  //OUT EP FIFO size  512 bytes
      0
    }
  }
};

//USB String Descriptors
const uint8 StringLangID[4] =
{
  0x04,
  0x03,
  0x09,
  0x04 // LangID = 0x0409: U.S. English
};

const uint8 StringVendor[62] =
{
  0x3E, // Size of Vendor string
  0x03, // bDescriptorType
  0x48, 0x00, 0x65, 0x00, 0x72, 0x00, 0x6F, 0x00, 0x4A, 0x00, 0x65, 0x00, 0x20, 0x00, 0x53, 0x00,
  0x63, 0x00, 0x61, 0x00, 0x6E, 0x00, 0x6E, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x20, 0x00,
  0x44, 0x00, 0x72, 0x00, 0x69, 0x00, 0x76, 0x00, 0x65, 0x00, 0x73, 0x00, 0x20, 0x00, 0x2D, 0x00,
  0x20, 0x00, 0x48, 0x00, 0x32, 0x00, 0x37, 0x00, 0x35, 0x00, 0x30, 0x00, 
};


const uint8 StringProduct[38] =
{
  0x26, // bLength
  0x03, // bDescriptorType
  0x48, 0x00, 0x32, 0x00, 0x37, 0x00, 0x35, 0x00, 0x30, 0x00, 0x20, 0x00, 0x20, 0x00,
  0x55, 0x00, 0x73, 0x00, 0x62, 0x00, 0x20, 0x00, 0x44, 0x00, 0x65, 0x00, 0x76, 0x00, 0x69, 0x00,
  0x63, 0x00, 0x65, 0x00, 0x73, 0x00, 
};

const uint8 StringSerial[30] =
{
  0x1E, // bLength
  0x03, // bDescriptorType
  0x43, 0x00, 0x44, 0x00, 0x43, 0x00, 0x20, 0x00, 0x41, 0x00, 0x43, 0x00, 0x4D, 0x00, 0x20, 0x00, 
  0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x66, 0x00, 0x69, 0x00, 0x67, 0x00, 
};

const uint8 StringInterface[30] =
{
  0x1E, // bLength
  0x03, // bDescriptorType
  0x43, 0x00, 0x44, 0x00, 0x43, 0x00, 0x20, 0x00, 0x41, 0x00, 0x43, 0x00, 0x4D, 0x00, 0x20, 0x00, 
  0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x66, 0x00, 0x69, 0x00, 0x67, 0x00, 
};



const uint8 scsi_inquiry_string[36] =
{
  0x00, 0x80, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00, 0x46, 0x31, 0x43, 0x31, 0x30, 0x30, 0x53, 0x20, 
  0x20, 0x58, 0x69, 0x61, 0x6F, 0x54, 0x61, 0x6F, 0x51, 0x69, 0x20, 0x20, 0x44, 0x69, 0x73, 0x6B, 
  0x20, 0x31, 0x2E, 0x30
};

const uint8 scsi_sense_data[4] =
{
  0x03, 0x00, 0x00, 0x00
};

//----------------------------------------------------------------------------------------------------------------------------------

extern uint32 cardsectorsize;
extern uint32 cardsectors;

volatile uint32 scsi_start_lba;
volatile uint32 scsi_block_count;

volatile uint32 scsi_byte_count;
volatile uint32 scsi_bytes_received;

//uint32 scsi_data_block[128];  //512 byte block on a 32 bit boundary aligned for reading and writing to the sd card

volatile uint8 *scsi_data_in_ptr;
volatile uint8 *scsi_data_end_ptr;

volatile uint32 scsi_available_blocks;

uint8 scsi_capacity[8];

volatile uint32 msc_state = MSC_WAIT_COMMAND;

MSC_Status_Wrapper csw;

//----------------------------------------------------------------------------------------------------------------------------------

void usb_mass_storage_out_ep_callback(unsigned char *pdat, int len)
{
  //usb_handle_mass_storage_write in Ghidra

  
  //Data coming from the host contains a CBW and needs to be handled here

  
  //Need a state machine to handle the data from the host. On startup the system is in an idle state
  //When data is received in this state it should be a CBW that needs to be checked
  
  //State_Command
    //Check if the length is that of a CBW
    //Check if the signature matches
    //When invalid stall the endpoints and switch to need reset stage
  
    //When valid setup a CSW for the response
    //Handle the command given in the CBW


  
  //Handle host data based on the current state
  switch(msc_state)
  {
    case MSC_WAIT_COMMAND:
    {
      //Make the data accessible as a command block wrapper
      MSC_Command_Wrapper *cbw = (MSC_Command_Wrapper *)pdat;


      //LUN should be zero since this device only supports the single unit

      //The direction bit tells if the host will send data or the device needs to send data

      //Command length needs to be from 1 to 16, otherwise it is an error

      //Check if the data is valid
      if((len == MSC_CBW_LENGTH) && (cbw->signature == MSC_CBW_SIGNATURE))
      {
        //If so process the command

        //First 
        //Copy the tag to the csw and set the csw signature (can be done in a setup routine)
        csw.signature    = MSC_CSW_SIGNATURE;
        csw.tag          = cbw->tag;
        csw.data_residue = 0;
        csw.status       = MSC_CSW_STATUS_OK;

        //Parse the command
        switch(cbw->command[0])
        {
          case SCSI_CMD_INQUIRY:
            usb_write_ep1_data((void *)scsi_inquiry_string, sizeof(scsi_inquiry_string));
              
            //Switch to status state (No more data to send)
            msc_state = MSC_SEND_STATUS;
            break;

          case SCSI_CMD_PREVENT_ALLOW_MEDIUM_REMOVAL:
            //Use this command to block the return to scope mode if the host says so!!!
            
          //Ignore these commands for now
          case SCSI_CMD_TEST_UNIT_READY:
          case SCSI_CMD_START_STOP_UNIT:
            //Needs to be done here since the data needs to be ready before the in request is send from the host
            //Send the ok status
            usb_write_ep1_data((void *)&csw, MSC_CSW_LENGTH);

            //Switch to wait for command state
            msc_state = MSC_WAIT_COMMAND;
            break;

          case SCSI_CMD_READ_CAPACITY_10:
            {
              uint32 sectors = cardsectors - 1;

              //Need to return the last logical block address and the block size
              scsi_capacity[0] = sectors >> 24;
              scsi_capacity[1] = sectors >> 16;
              scsi_capacity[2] = sectors >> 8;
              scsi_capacity[3] = sectors;

              scsi_capacity[4] = cardsectorsize >> 24;
              scsi_capacity[5] = cardsectorsize >> 16;
              scsi_capacity[6] = cardsectorsize >> 8;
              scsi_capacity[7] = cardsectorsize;

              usb_write_ep1_data((void *)scsi_capacity, sizeof(scsi_capacity));

              //Switch to status state (No more data to send)
              msc_state = MSC_SEND_STATUS;
            }
            break;

          case SCSI_CMD_MODE_SENSE_6:
            usb_write_ep1_data((void *)scsi_inquiry_string, sizeof(scsi_inquiry_string));

            //Switch to status state (No more data to send)
            msc_state = MSC_SEND_STATUS;
            break;

          case SCSI_CMD_READ_10:
            //This requires a bit more checking!!!!!
            //Get the lba to access
            scsi_start_lba = (cbw->command[2] << 24) | (cbw->command[3] << 16) | (cbw->command[4] << 8) | cbw->command[5];

            //get the block count
            scsi_block_count = (cbw->command[7] << 8) | cbw->command[8];

            //Need to handle possible error conditions here
            //Check on cbw data transfer length
            //check on scsi command length
            //check on data direction

            //Do a per block read and transfer
            //Not really needed since it will fall through in the send action
            if(scsi_block_count > 1)
            {
              msc_state = MSC_SEND_DATA;
            }
            else
            {
              msc_state = MSC_SEND_STATUS;
            }

            //Check if this can be done directly to the usb fifo
            //Need to handle error conditions here too

            scsi_data_in_ptr = (uint8 *)viewthumbnaildata;

            if(scsi_block_count > SCSI_MAX_BLOCK_COUNT)
            {
              scsi_available_blocks = SCSI_MAX_BLOCK_COUNT;
            }
            else
            {
              scsi_available_blocks = scsi_block_count;
            }

            sd_card_read(scsi_start_lba, scsi_available_blocks, (uint8 *)scsi_data_in_ptr);

            usb_write_ep1_data((void *)scsi_data_in_ptr, cardsectorsize);

            //One full buffer done
            scsi_block_count -= scsi_available_blocks;

            //select the next sector to read
            scsi_start_lba += scsi_available_blocks;

            //Point to next data to transfer
            scsi_data_in_ptr += cardsectorsize;

            //Already one block done
            scsi_available_blocks--;
            break;


          case SCSI_CMD_WRITE_10:
            //This requires a bit more checking!!!!!
            //Get the lba to access
            scsi_start_lba = (cbw->command[2] << 24) | (cbw->command[3] << 16) | (cbw->command[4] << 8) | cbw->command[5];

            //get the block count
            scsi_block_count = (cbw->command[7] << 8) | cbw->command[8];

            //Need the number of bytes to receive
            scsi_byte_count = scsi_block_count * 512;
            scsi_bytes_received = 0;

            //Point to the start of the buffer to receive the payload data into
            scsi_data_in_ptr = (uint8 *)viewthumbnaildata;
            scsi_data_end_ptr = scsi_data_in_ptr + sizeof(viewthumbnaildata);


            //Next out transaction holds the payload data
            msc_state = MSC_RECEIVE_DATA;
            break;
        }
      }
      else
      {
        //Not a valid command block wrapper then stall the endpoints
        usb_device_stall_tx_ep();
        usb_device_stall_rx_ep();
      }
    }
    break;
      
    case MSC_RECEIVE_DATA:
    {
      //Calculate the last location when this data is written to the buffer. Needs to stay below the end of the buffer
      register uint8 *tptr = (uint8 *)scsi_data_in_ptr + len;
      
      //Check if there is still room in the buffer
      if(tptr < scsi_data_end_ptr)
      {
        //Need to load it into a buffer before writing to the card
        memcpy((uint8 *)scsi_data_in_ptr, pdat, len);

        scsi_bytes_received += len;
        
        //Need to determine here if this was the last data
        if(len >= scsi_byte_count)
        {
          //Last payload data received so write it to the card and switch to status state
          //Get the number of sectors to write to the card to free the buffer
          uint32 sectors = scsi_bytes_received / 512;
          uint32 bytesdone = sectors * 512;

          //Check if there is a non full sector at the end
          if(bytesdone < scsi_bytes_received)
          {
            //If so do one sector extra
            sectors++;
          }
          
          //Need to handle errors here!!!!!
          //Need to write the data to the card
          sd_card_write(scsi_start_lba, sectors, (uint8 *)viewthumbnaildata);
          
          //Next action is send the status to the host
          usb_write_ep1_data((void *)&csw, MSC_CSW_LENGTH);

          //switch to wait for command state
          msc_state = MSC_WAIT_COMMAND;
        }
        else
        {
          //Take of the received bytes to see if more needs to come
          scsi_byte_count -= len;

          //Point to the next location in the buffer to store the next load
          scsi_data_in_ptr = tptr;
        }
      }
      else
      {
        //Get the number of sectors to write to the card to free the buffer
        uint32 sectors = scsi_bytes_received / 512;
        uint32 bytesdone = sectors * 512;
        
        scsi_data_in_ptr = (uint8 *)viewthumbnaildata;
        
        //Need to handle errors here!!!!!
        //Need to write the data to the card
        sd_card_write(scsi_start_lba, sectors, (uint8 *)scsi_data_in_ptr);
        
        //Point to next logical block address to write to
        scsi_start_lba += sectors;
        
        //Check if there is data left
        if(bytesdone < scsi_bytes_received)
        {
          uint32 bytesleft = scsi_bytes_received - bytesdone;
          
          //If so copy the remainder to the start of the buffer
          memcpy((uint8 *)scsi_data_in_ptr, (uint8 *)scsi_data_in_ptr + bytesdone, bytesleft);
          
          //Set pointer to the end of this left over data
          scsi_data_in_ptr += bytesleft;
          
          //At this moment still data received
          scsi_bytes_received = bytesleft;
        }
        else
        {
          //Reset the number of received bytes for handling remainder of payload data
          scsi_bytes_received = 0;
        }
      }
    } 
    break;
  }
}

//----------------------------------------------------------------------------------------------------------------------------------

void usb_mass_storage_in_ep_callback(void)
{
  //This will only need to handle data transfer to the host when there is a lot of data requested. > 512 bytes
  //or a data packet has been send and the csw needs to follow

  switch(msc_state)
  {
    case MSC_SEND_DATA:
      //Need check on if more data needs to be send!!!!

      if(scsi_available_blocks)
      {
        usb_write_ep1_data((void *)scsi_data_in_ptr, cardsectorsize);

        //one more block done
        scsi_available_blocks--;

        //Point to next data to transfer
        scsi_data_in_ptr += cardsectorsize;
        
        //Check if more data needs to be read from the SD card
        if((scsi_available_blocks == 0) && scsi_block_count)
        {
          //Reset the pointer to the beginning of the buffer
          scsi_data_in_ptr = (uint8 *)viewthumbnaildata;

          if(scsi_block_count > SCSI_MAX_BLOCK_COUNT)
          {
            scsi_available_blocks = SCSI_MAX_BLOCK_COUNT;
          }
          else
          {
            scsi_available_blocks = scsi_block_count;
          }
          
          //Need to handle errors here!!!!!!
          //Read the next block if needed
          sd_card_read(scsi_start_lba, scsi_available_blocks, (uint8 *)scsi_data_in_ptr);
          
          //One full buffer done
          scsi_block_count -= scsi_available_blocks;

          //select the next sector to read
          scsi_start_lba += scsi_available_blocks;
        }        
        break;
      }
      
      //No more data to send then fall through to status
      
    case MSC_SEND_STATUS:
      //If not send status state
      usb_write_ep1_data((void *)&csw, MSC_CSW_LENGTH);
      
      //switch to wait for command state
      msc_state = MSC_WAIT_COMMAND;
      break;
  }
}

//----------------------------------------------------------------------------------------------------------------------------------