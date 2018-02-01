.PHONY:all
all:sevice client
sevice:sevice.c
	gcc $^ -o $@
client:client.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f sevice client
