.PHONY:all
all:sevice client

sevice:sevice.c commom.c
	gcc $^ -o $@
client:client.c commom.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f sevice client
