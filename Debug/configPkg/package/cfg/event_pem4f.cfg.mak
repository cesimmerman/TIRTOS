# invoke SourceDir generated makefile for event.pem4f
event.pem4f: .libraries,event.pem4f
.libraries,event.pem4f: package/cfg/event_pem4f.xdl
	$(MAKE) -f C:\Users\simmermance\Documents\Repos\event_MSP_EXP432P401R_tirtos_ccs/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\simmermance\Documents\Repos\event_MSP_EXP432P401R_tirtos_ccs/src/makefile.libs clean

