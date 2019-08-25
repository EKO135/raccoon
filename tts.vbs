Dim message, sapi
message="enter your very own message here" 
Set sapi=CreateObject("sapi.spvoice") 
sapi.Speak message
