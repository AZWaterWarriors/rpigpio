# rpigpio
## A lightweight, efficient Raspberry Pi 4 Model B GPIO C Library

## Usage

### Setup GPIO
> setupio();

Initializes GPIO by memory mapping the pins.  Returns 0 on success.

### Write binary value to pin
> writepin(pin, value);

Writes either high (1) or low (0) to pin based on value.

### Read binary value from pin
> getpin(pin);

Returns 1 (high) or 0 (low) depending on value of pin.

### Close GPIO
> closeio();

The library needs to close the file to allow other programs to access it.  This does that.  Return value is arbitrary.
