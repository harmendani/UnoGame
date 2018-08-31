/* Responsável pelo fluxo do sistema controlando as transições
** e o sistema como um todo.
*/

/*Responsável por iniciar o sistema*/
void runSystem();

/* Responsável pela inteligência do sistema gerenciado as transições*/
void controllerCore();

/*Dispara o fim dos testes validando e salvando os dados obtidos do Motor Data*/
void abortSystem();

/*Finaliza o sistema limpando os buffers e fechando o sistema por completo*/
void closeSystem();