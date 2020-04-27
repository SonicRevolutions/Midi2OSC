# Midi2OSC
Arduino midi to OSC converter 

I’ve got an Arduino Uno R3 with Ethernet shield hooked up to a Novation Launch Control XL that’s connected to a Kenton USB to midi converter to adjust bus 1 send levels on a Behringer XR12 digital mixer.
The Behringer’s midi implementation is pretty poor, its input channels levels are controllable by midi cc’s but the bus input channels aren’t.
Using the midi2osc converter I can use one of the Launch Control knob rows like sends as you have on analog mixers. I’ve got an Eventide H9 connected to the aux outputs of the XR12 and routed bus 1 to the aux outputs.

See https://www.notesandvolts.com/2015/02/midi-and-arduino-build-midi-input.html on how to build an Arduino midi input.
