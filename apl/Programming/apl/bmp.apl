⎕IO ← 0
ascii ← (65↓⍳91),97↓⍳123
alpha ← (⊢,⎕C)⎕A
hex ← (⍳10),6↑⎕A
stringtohex ← {(hex⌷⍨⊢)¨↑(16 16⊤⊢)¨(ascii⌷⍨⊢)¨{⍸⍵=¨alpha}¨⍵}
⎕SH '/usr/bin/echo -en ''\xde\xad\xbe\xef'' > /path/to/file'

