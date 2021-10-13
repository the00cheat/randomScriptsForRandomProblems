## Webp Image to Animated Gif

### Files

- [giphy.webp](giphy.webp)
  - Downloaded from giphy.com 
- [giphy.gif](giphy.gif)
  - Converted from a webp animated format to a gif (pronounced with a G like golf)
- [webp2gif](webp2gif)
  - Python script to convert webp files with multiple frames for animation to gif (pronounced with a G like golf)


### Code 

This is a quick implementation with very little error checking or usefullness for that matter. Well, we did show how you could turn a snippet of code into a shell command, so there is that nugget...

- We didn't try to get the filename from the input file to be used as an output file name.
- We didn't check to make sure file contents are correct.
- We didn't even check to make sure they exist!

- Usage: `webp2gif giphy.webp giphy.gif`
  
```python
#!/usr/local/bin/python3

from PIL import Image
import sys

if len(sys.argv) < 3:
    print("Need input file and output file!")
    sys.exit(0)


im = Image.open(sys.argv[1]) # argv[1] is the webp file to open

# argv[2] is the filename to write the gif to. 
im.save(sys.argv[2], 'gif', save_all=True, optimize=True, background=0)
```