Dim message, sapi
message="enter message here, make sure it is long, just copy and paste the same thing a lot" 
Set sapi=CreateObject("sapi.spvoice") 
sapi.Speak message
