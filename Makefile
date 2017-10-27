all:
	platformio run

upload:
	platformio run --target upload

ota:
	platformio run --target upload --upload-port 10.38.40.199


help:
	@echo "Targets are:"
	@echo "\tall"
	@echo "\tupload"

