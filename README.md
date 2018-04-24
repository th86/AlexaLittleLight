Alexa Little Light
====

A minimalist example of Alexa-Lambda-Arduino integration. A user can invoke the Alexa skill by saying "Alexa, use little light," and verbally toggle the LED on an ESP8266 board.

**alexa.json** is the code of the Alexa skill, which has only one customized intent with several sample utterances and a customized binary slot.

**lambda.py** is the function code for AWS lambda. Remember to add the Alexa skill as the only trigger of the function. 

**server.ino** is the code for an ESP8266 board with Arduino (Wemos R1).

References

[VoiceOps with Alexa](https://github.com/msales/alexa-voiceops/blob/master/README.md)

[ALEXA VOICE CONTROL TV REMOTE ESP8266](http://www.instructables.com/id/Alexa-Voice-Control-TV-Remote-ESP8266/)