# heya'!, welcome to the zorixScript documentation! 👋
*lets go through all the available functions, shall we?*

# bind
bind is the *MOST* important part of a zorixScript..
it must be placed at the *VERY TOP* of each zorixScript with no fail, or else the script ⚠️ **WON'T WORK!** ⚠️!

bind requires two arguments, "Type:" & "Id:"
this is what "bind()" looks like in code!:

bind(
Type: "TextButton"
Id: 2
)

bind basically tells the parser:
"hey unc, i want you to instruct [X Binded Object]!!"

and thats about it, now you can use the other functions! 🎊

# setBackgroundColor
setBackgroundColor is relatively self-explanatory, it sets the background color on *some* UI elements.
it requires 3 un-labeled arguments that represent R/G/B values.

this is what setBackgroundColor() looks like in code!:

setBackgroundColor(
255
255
255
)

the first value represents "R", second is "G", and third is "B".

# But wait, whats up with the format?! 🤔
The zorixscript parser is very simple, hence making it *VERY* picky in what formats work. the common rules are:

> No indentation
> Arguments *MUST* be passed in seperate lines
> And other stuff i can't recall..

okay lets resume..

# setTextColor
another self-explanatory one, this sets the text color on *some* UI elements!
it requires 3 un-labeled arguments that represent R/G/B values.

this is what setTextColor looks like in code!:

setTextColor(
0
0
0
)

the first value represents "R", second is "G", and third is "B".

# setText
this function sets (or changes) the text on *some* UI elements!
it requires 1 un-labeled argument that represents a string!

and here is what it looks like in code!:

setText(
"documentation text heh.."
)

# setPosition
this sets (or changes) the position of *any* UI element.
it requires 2 un-labeled arguments that represent X & Y values.

here is the code example!:

setPosition(
50
50
)

this sets the binded object to 50, 50 on the screen!

# resize
this resizes the size of *any* UI element.
it requires 2 un-labeled arguments that represent W & H values.

here is the code example!:

resize(
50
50
)

this resizes the binded object to 50, 50 on the screen!

---

Congratulations, you finished this terribly-written documentation of zorixScript.. 🎊😮‍💨
you can now use zorix without being terrible at it xx 🌺