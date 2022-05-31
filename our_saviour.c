#include <stdio.h>
#include <string.h>

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}

int main(){
        const char* st = "23303124417070656C6C657A206C65732068656E64656B3F";
        int length = strlen(st);
        int i;
        char buf = 0;
        for(i = 0; i < length; i++){
                if(i % 2 != 0){
                        printf("%c", hex_to_ascii(buf, st[i]));
                }else{
                        buf = st[i];
                }
        }
}

void send_message(char msg[]) {

	char msg_complet[MAX_MSG_SIZE-100]="#";
	char data[MAX_MSG_SIZE-105];
	char id[3] = {(ID-ID%10)+48, 48+ID%10};
	int i = 0;
	int j = 0;

	// Get message from memory
	while(msg[i] != '\0') {
		data[i] = msg[i];
		i++;
	}
	for (j=i; j<MAX_MSG_SIZE-105; j++) {
		data[j]=0;
	}

	strcat(msg_complet, id);
	strcat(msg_complet, "$");
	// temp
	strcat(msg_complet, "0");
	strcat(msg_complet, "$");
	strcat(msg_complet, data);
	strcat(msg_complet, "?");

	test_at_tx(msg_complet);
}

/*******************************************
 * TODO: explain to each group that the entry variable should be a char
 *
 */
void receive_message(char msg[]) {

	char data[MAX_MSG_SIZE];
	int i = 0;
	int j = 0;

	/*
	// Get message from memory
	while(msg[i] != '\0') {
		data[i] = msg[i];
		i++;
	}
	i = 0;

	// If data = '#'
	if (data[0]=='2' && data[1]=='3') {
		// If data = ID
		if ( (data[2]==(ID-ID%10+48)) && (data[3]==(ID%10+48)) ) {
			i=69;
		}
	}

	if (i) {
		// If data = '$'
		if (data[4]='2' && data[5]=='4') {
			// If data = any int between 0 & 9 (who knows...)
			mode = data[7]-48;
		}

		// If data = '$'
		if (data[8]='2' && data[9]=='4') {

			// Decode all DATA
			while(data[i] != '\0') {
				final_data[i-i/2] = hex_to_ascii(data[i], data[i+1]);
				i+=2;
			}
		}
	}
	*/
	while(msg[i] != '\0') {
		data[j] = hex_to_ascii(msg[i], msg[i+1]);
		i+=2;
		j++;
	}

	for (i=j; i<MAX_MSG_SIZE; i++) {
		data[i]=0;
	}

	if (data[0]=='#' // Beginning of  protocol thread
		&& ((data[1]-48)*16 + data[2]-48)==ID	// ID verification
		&& data[3]=='$') // Continuity of data verification
	{
		mode = data[4] - 48; // Interprete mode

		if (data[5]='$') {
			i = 6;

			while(data[i] != '\0') {
				i++;
			}
		}
	}
	else
	{
		// The received data is not for this device nor from protocol
	}

	HAL_UART_Transmit(&huart2, data, sizeof(data), HAL_MAX_DELAY);
}

void test_at_rx(void) {

	HAL_Delay(E5_WAIT);
	// Enter receive mode
	HAL_UART_Transmit(&huart1, AT_TEST_RX, sizeof(AT_TEST_RX), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, AT_TEST_RX, sizeof(AT_TEST_RX), HAL_MAX_DELAY);
}

int hex_to_int(char c) {

        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;

        if(result > 9) result--;
        return result;
}

int hex_to_ascii(char c, char d) {

        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);

        return high+low;
}
