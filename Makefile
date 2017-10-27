IPADDR?=10.38.40.199

all:
	platformio run

upload:
	platformio run --target upload

ota:
	platformio run --target upload --upload-port ${IPADDR}


help:
	@echo "Targets are:"
	@echo "\tall"
	@echo "\tupload"

