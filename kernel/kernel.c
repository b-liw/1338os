#define VIDEO_MEM 0xB8000

void kmain();

char *vidptr = (char*) VIDEO_MEM;
int line_counter = 7;

struct text_attr_st {
	char c;
	char attr;
};

typedef struct text_attr_st text_attr_t;

void entry_point() {
	kmain();
	while(1) {}
}

void println(char *message) {
	line_counter++;
	vidptr = (char*) VIDEO_MEM + line_counter * (80 * 2);
	text_attr_t *TextBuffer = (text_attr_t*) vidptr;
	char *p_next_char = message;
	int i = 0;
	while(*p_next_char) {
		TextBuffer[i].c = *p_next_char;
		TextBuffer[i].attr = 0x04;
		p_next_char++;
		vidptr+=2;
		i++;
	}
}

void kmain() {
	println("Executing code in C from kernel");
	println("I hope everything works");
	println(":)");
	return;
}