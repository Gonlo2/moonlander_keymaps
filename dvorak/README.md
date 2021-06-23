# Custom Spanish Dvorak

Layout in Spanish designed mainly to avoid fatigue the hands minimizing the displacement and bad postures of the fingers. To achieve this we have opted for the creation of a layout based on dvorak where most of the modifiers or recurring keys that I use when programming are as close as possible to the default position of the fingers.

This code is based on the result of the [Oryz](https://configure.zsa.io/moonlander) visual generator with some modifications since it is not possible to achieve some things through the GUI:

- Hold the U key enable the tmux layer where any key with the exception of the arrow keys are appendend with a tap of Ctrl-B and with the arrow keys Ctrl-B is held.
- Tap the thumb key to tap ctrl-w and hold it to keep the right alt. This isn't possible because qmk only allow use a basic key code for the mod-tap feature.
- Forbid using shift and a normal key with the same hand to retrain muscle memory.
- Use the side keys rgb leds to show the current active layer because moonlander has the keyboard status LEDs on the top of the chassis but, given that to achieve a fine finish of the chassis, they are not clearly visible because the keys have a considerable height and cover them.

The latest Oryz Moonlander layout could be found [here](https://configure.zsa.io/moonlander/layouts/yEyKr/latest).
