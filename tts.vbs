Dim message, sapi
message="enter your very own message here, btw cop paste it a ton" 
Set sapi=CreateObject("sapi.spvoice") 
sapi.Speak message
