---
title: Erros fatais do compilador C999 até C1999
ms.date: 11/17/2017
f1_keywords:
- C1034
- C1036
- C1041
- C1048
- C1049
- C1063
- C1069
- C1101
- C1102
- C1105
- C1110
- C1111
- C1112
- C1114
- C1193
- C1195
- C1300
- C1301
- C1302
- C1306
- C1384
- C1451
- C1505
- C1901
helpviewer_keywords:
- C1034
- C1036
- C1041
- C1048
- C1049
- C1063
- C1069
- C1101
- C1102
- C1105
- C1110
- C1111
- C1112
- C1114
- C1193
- C1195
- C1300
- C1301
- C1302
- C1306
- C1384
- C1451
- C1505
- C1901
ms.assetid: 6c8df109-7594-48ed-987a-97d9fe2b04af
ms.openlocfilehash: 17c456f6ab248964cbd19cd9695da290254ccf1b
ms.sourcegitcommit: 42e65c171aaa17a15c20b155d22e3378e27b4642
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2019
ms.locfileid: "58356212"
---
# <a name="compiler-fatal-errors-c999-through-c1999"></a>Erros fatais do compilador C999 até C1999

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro fatal C999](../../error-messages/compiler-errors-1/fatal-error-c999.md)|. Mensagem desconhecida escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro fatal C1001](../../error-messages/compiler-errors-1/fatal-error-c1001.md)|Erro interno no compilador.<br /> (arquivo do compilador '*arquivo*', linha *número*)<br /> Para contornar esse problema, tente simplificar ou alterar o programa próximo aos locais listados acima. Escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro fatal C1002](../../error-messages/compiler-errors-1/fatal-error-c1002.md)|o compilador está fora do espaço de heap no passo 2|
|[Erro fatal C1003](../../error-messages/compiler-errors-1/fatal-error-c1003.md)|Contagem de erros excede *número*; interrompendo compilação|
|[Erro fatal C1004](../../error-messages/compiler-errors-1/fatal-error-c1004.md)|fim-de-arquivo inesperado encontrado|
|[Erro fatal C1005](../../error-messages/compiler-errors-1/fatal-error-c1005.md)|muito grande para o buffer de cadeia de caracteres|
|[Erro fatal C1007](../../error-messages/compiler-errors-1/fatal-error-c1007.md)|sinalizador não reconhecido '*cadeia de caracteres*'in'*opção*'|
|[Erro fatal C1008](../../error-messages/compiler-errors-1/fatal-error-c1008.md)|Nenhum arquivo de entrada especificado|
|[Erro fatal C1009](../../error-messages/compiler-errors-1/fatal-error-c1009.md)|limite do compilador: macros com aninhamento muito profundo|
|[Erro fatal C1010](../../error-messages/compiler-errors-1/fatal-error-c1010.md)|fim de arquivo inesperado durante a procura de cabeçalho pré-compilado. Você esqueceu de adicionar ' #include \< *arquivo*>' à sua fonte?|
|[Erro fatal C1012](fatal-error-c1012.md)|Parêntese sem correspondência: ausente '*caractere*"|
|[Erro fatal C1013](fatal-error-c1013.md)|limite do compilador: muitos parênteses abertos|
|[Erro fatal C1014](fatal-error-c1014.md)|muitos arquivos de inclusão: profundidade = *número*|
|[Erro fatal C1016](fatal-error-c1016.md)|#ifdef / #ifndef esperava um identificador|
|[Erro fatal C1017](../../error-messages/compiler-errors-1/fatal-error-c1017.md)|expressão de constante de inteiro inválido|
|[Erro fatal C1018](fatal-error-c1018.md)|#elif inesperado|
|[Erro fatal C1019](fatal-error-c1019.md)|inesperado #else|
|[Erro fatal C1020](fatal-error-c1020.md)|#endif inesperado|
|[Erro fatal C1021](fatal-error-c1021.md)|comando de pré-processador inválido '*cadeia de caracteres*'|
|[Erro fatal C1022](fatal-error-c1022.md)|#endif esperado|
|[Erro fatal C1023](fatal-error-c1023.md)|'*arquivo*': erro inesperado com pch, tente recompilá-lo|
|[Erro fatal C1026](../../error-messages/compiler-errors-1/fatal-error-c1026.md)|estouro de pilha do analisador, programa muito complexo|
|[Erro fatal C1033](../../error-messages/compiler-errors-1/fatal-error-c1033.md)|não é possível abrir o banco de dados do programa '*arquivo*'|
|Erro fatal C1034|*arquivo*: nenhum caminho de include definido|
|[Erro fatal C1035](fatal-error-c1035.md)|expressão muito complexa; Simplificar expressão|
|Erro fatal C1036|não é possível substituir o formato de banco de dados do programa anterior, exclua '*arquivo*' e recompile|
|[Erro fatal C1037](fatal-error-c1037.md)|não é possível abrir o arquivo de objeto '*arquivo*'|
|[Erro fatal C1038](fatal-error-c1038.md)|limite do compilador: '*função*': controlar o estado de fluxo muito complexo; Simplifique a função|
|Erro fatal C1041|não é possível abrir o banco de dados do programa '*arquivo*'; se vários CL. EXE escrever no mesmo. PDB do arquivo, use /FS|
|[Erro fatal C1045](fatal-error-c1045.md)|limite do compilador: especificações de vinculação com aninhamento muito profundo|
|[Erro fatal C1046](../../error-messages/compiler-errors-1/fatal-error-c1046.md)|limite do compilador: *estrutura* com aninhamento muito profundo|
|[Erro fatal C1047](fatal-error-c1047.md)|O arquivo de biblioteca ou objeto '*arquivo*' foi criado com um compilador mais antigo que outros objetos; objetos antigos de recompilação e bibliotecas|
|Erro fatal C1048|opção desconhecida '*cadeia de caracteres*'in'*opção*'|
|Erro fatal C1049|argumento numérico inválido '*valor*'|
|[Erro fatal C1051](../../error-messages/compiler-errors-1/fatal-error-c1051.md)|arquivo de banco de dados do programa, '*arquivo*', tem um formato obsoleto, exclua-o e recompile|
|[Erro fatal C1052](fatal-error-c1052.md)|arquivo de banco de dados do programa, '*filename*', foi gerado pelo vinculador com /debug: fastlink; compilador não pode atualizar esses arquivos PDB; exclua-o ou use /Fd para especificar um nome de arquivo PDB diferente|
|[Erro fatal C1053](fatal-error-c1053.md)|'*função*': função muito grande|
|[Erro fatal C1054](../../error-messages/compiler-errors-1/fatal-error-c1054.md)|limite do compilador: inicializadores com aninhamento muito profundo|
|[Erro fatal C1055](../../error-messages/compiler-errors-1/fatal-error-c1055.md)|limite do compilador: sem chaves|
|[Erro fatal C1057](../../error-messages/compiler-errors-1/fatal-error-c1057.md)|fim de arquivo inesperado na expansão de macro|
|[Erro fatal C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md)|o compilador está fora do espaço de heap|
|[Erro fatal C1061](../../error-messages/compiler-errors-1/fatal-error-c1061.md)|limite do compilador: blocos aninhados muito profundamente|
|Erro fatal C1063|limite do compilador: estouro de pilha do compilador|
|[Erro fatal C1064](../../error-messages/compiler-errors-1/fatal-error-c1064.md)|limite do compilador: token estourou o buffer interno|
|[Erro fatal C1065](../../error-messages/compiler-errors-1/fatal-error-c1065.md)|limite do compilador: sem marcas|
|[Erro fatal C1067](../../error-messages/compiler-errors-1/fatal-error-c1067.md)|limite do compilador: Limite de 64 mil em tamanho de um registro de tipo foi excedido|
|[Erro fatal C1068](fatal-error-c1068.md)|não é possível abrir o arquivo '*arquivo*'|
|Erro fatal C1069|não é possível ler a linha de comando do compilador|
|[Erro fatal C1070](fatal-error-c1070.md)|incompatíveis #if / #endif emparelhar no arquivo '*arquivo*'|
|[Erro fatal C1071](../../error-messages/compiler-errors-1/fatal-error-c1071.md)|fim de arquivo inesperado encontrado no comentário|
|[Erro fatal C1073](../../error-messages/compiler-errors-1/fatal-error-c1073.md)|Erro interno envolvendo compilação incremental (arquivo do compilador '*arquivo*', linha *número*)|
|[Erro fatal C1074](fatal-error-c1074.md)|'IDB' é uma extensão inválida para o arquivo PDB: *arquivo*|
|[Erro fatal C1075](../../error-messages/compiler-errors-1/fatal-error-c1075.md)|à esquerda *token* foi sem correspondência no final do arquivo|
|[Erro fatal C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md)|limite do compilador: limite de heap interno atingido; Use /Zm para especificar um limite superior|
|[Erro fatal C1077](fatal-error-c1077.md)|limite do compilador: não é possível ter mais de *número* opções de linha de comando|
|[Erro fatal C1079](../../error-messages/compiler-errors-1/fatal-error-c1079.md)|limite do compilador: Limite de tamanho de arquivo PCH excedido|
|[Erro fatal C1080](../../error-messages/compiler-errors-1/fatal-error-c1080.md)|limite do compilador: limite excedido para a opção de linha de comando do *número* caracteres|
|[Erro fatal C1081](../../error-messages/compiler-errors-1/fatal-error-c1081.md)|'*arquivo*': nome de arquivo muito longo|
|[Erro fatal C1082](fatal-error-c1082.md)|não é possível fechar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1083](../../error-messages/compiler-errors-1/fatal-error-c1083.md)|não é possível abrir *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1084](../../error-messages/compiler-errors-1/fatal-error-c1084.md)|não é possível ler *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1085](../../error-messages/compiler-errors-1/fatal-error-c1085.md)|não é possível gravar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1086](fatal-error-c1086.md)|não é possível buscar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1087](fatal-error-c1087.md)|não é possível informar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1088](fatal-error-c1088.md)|não é possível liberar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1089](fatal-error-c1089.md)|não é possível truncar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1090|Falha na chamada à API PDB, código de erro '*código*': '*mensagem*'|
|[Erro fatal C1091](fatal-error-c1091.md)|limite do compilador: cadeia de caracteres excede *número* bytes de comprimento|
|[Erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md)|Editar e continuar não dá suporte a alterações em tipos de dados; Compilar necessária|
|[Erro fatal C1093](../../error-messages/compiler-errors-1/fatal-error-c1093.md)|Chamada à API '*função*'com falha'*HRESULT*': '*descrição*'|
|[Erro fatal C1094](../../error-messages/compiler-errors-1/fatal-error-c1094.md)|'-Zm*número*': opção de linha de comando é inconsistente com o valor usado para compilar cabeçalho pré-compilado ('-Zm*número*')|
|[Erro fatal C1098](fatal-error-c1098.md)|Incompatibilidade de versão com mecanismo editar e continuar|
|[Erro fatal C1099](fatal-error-c1099.md)|Editar e continuar encerrando compilação do mecanismo|
|[Erro fatal C1100](fatal-error-c1100.md)|não foi possível inicializar OLE: *erro*|
|Erro fatal C1101|não é possível criar o manipulador para atributo '*identificador*'|
|Erro fatal C1102|não foi possível inicializar: *erro*|
|[Erro fatal C1103](fatal-error-c1103.md)|Erro fatal ao importar progid: '*mensagem*'|
|[Erro fatal C1104](fatal-error-c1104.md)|Erro fatal ao importar libid: '*mensagem*'|
|Erro fatal C1105|*mensagem*: *erro*|
|[Erro fatal C1107](../../error-messages/compiler-errors-1/fatal-error-c1107.md)|não foi possível encontrar o assembly '*assembly*': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH|
|[Erro fatal C1108](fatal-error-c1108.md)|não é possível localizar a DLL: '*arquivo*'|
|[Erro fatal C1109](fatal-error-c1109.md)|não é possível localizar '*símbolo*'na DLL'*arquivo*'|
|Erro fatal C1110|muitas definições de modelo/generic aninhado|
|Erro fatal C1111|número excessivo de parâmetros de modelo/genérico|
|Erro fatal C1112|limite do compilador: `'number`' muitos argumentos de macro, apenas *número* permitido|
|[Erro fatal C1113](../../error-messages/compiler-errors-1/fatal-error-c1113.md)|#using falhou em '*arquivo*'|
|Erro fatal C1114|'*file*': WinRT não oferece suporte a #using de um assembly gerenciado|
|[Erro fatal C1120](../../error-messages/compiler-errors-1/fatal-error-c1120.md)|chamada a GetProcAddress falhou para '*função*'|
|[Erro fatal C1121](../../error-messages/compiler-errors-1/fatal-error-c1121.md)|chamada a CryptoAPI falhou|
|[Erro fatal C1126](../../error-messages/compiler-errors-1/fatal-error-c1126.md)|a alocação automática excede *tamanho*|
|[Erro fatal C1128](../../error-messages/compiler-errors-1/fatal-error-c1128.md)|número de seções excedeu o limite de formato de arquivo de objeto: compile com /bigobj|
|[Erro fatal C1189](../../error-messages/compiler-errors-1/fatal-error-c1189.md)|#error: *mensagem*|
|[Erro fatal C1190](fatal-error-c1190.md)|código gerenciado direcionado requer uma ' / clr' opção|
|[Erro fatal C1191](../../error-messages/compiler-errors-1/fatal-error-c1191.md)|'*arquivo*' só podem ser importados no escopo global|
|[Erro fatal C1192](../../error-messages/compiler-errors-1/fatal-error-c1192.md)|#using falhou em '*arquivo*'|
|Erro fatal C1193|um erro esperado em *arquivo*(*linha*) não atingido|
|Erro fatal C1195|uso de /Yu e /Yc na mesma linha de comando é incompatível com a opção /clr|
|[Erro fatal C1196](fatal-error-c1196.md)|'*identificador*': identificador encontrado na biblioteca de tipos '*typelib*' não é um identificador válido do C++|
|[Erro fatal C1197](../../error-messages/compiler-errors-1/fatal-error-c1197.md)|não é possível referenciar '*arquivo*'como o programa já referenciou'*arquivo*'|
|[Erro fatal C1201](fatal-error-c1201.md)|não é possível continuar após erro de sintaxe na definição do modelo de classe|
|[Erro fatal C1202](fatal-error-c1202.md)|recursiva função ou tipo de contexto de dependência muito complexo|
|[Erro fatal C1205](fatal-error-c1205.md)|Generics não são suportados pela versão do tempo de execução instalado|
|[Erro fatal C1206](fatal-error-c1206.md)|Dados Per-appdomain não há suporte para a versão do tempo de execução instalado|
|[Erro fatal C1207](fatal-error-c1207.md)|Templates gerenciados não suportados pela versão do tempo de execução instalado|
|[Erro fatal C1208](fatal-error-c1208.md)|Não há suporte para alocar classes de referência na pilha pela versão do tempo de execução instalado|
|[Erro fatal C1209](fatal-error-c1209.md)|Friend assemblies não suportados pela versão do tempo de execução instalado|
|[Erro fatal C1210](fatal-error-c1210.md)|/CLR: pure e /CLR: safe não são suportados pela versão do tempo de execução instalado|
|[Erro fatal C1211](fatal-error-c1211.md)|Não há suporte para o atributo personalizado TypeForwardedTo pela versão do tempo de execução instalado|
|Erro fatal C1300|Erro ao acessar o banco de dados do programa *arquivo* (*mensagem*)|
|Erro fatal C1301|Erro ao acessar o banco de dados do programa *arquivo*inválido, Formatar, exclua e recompile|
|Erro fatal C1302|Nenhum dado de perfil para módulo '*módulo*'no banco de dados de perfil'*arquivo*'|
|[Erro fatal C1305](../../error-messages/compiler-errors-1/fatal-error-c1305.md)|banco de dados de perfil '*arquivo*' é para uma arquitetura diferente|
|Erro fatal C1306|última alteração ao banco de dados de perfil '*arquivo*' não foi análise de otimização; decisões de otimização podem estar desatualizadas|
|[Erro fatal C1307](../../error-messages/compiler-errors-1/fatal-error-c1307.md)|programa foi editado desde que foram coletados dados de perfil|
|[Erro fatal C1308](../../error-messages/compiler-errors-1/fatal-error-c1308.md)|*arquivo*: não há suporte para a vinculação de assemblies|
|[Erro fatal C1309](../../error-messages/compiler-errors-1/fatal-error-c1309.md)|Versões incompatíveis do C2. DLL e pgodb*vidor*. DLL|
|[Erro fatal C1310](fatal-error-c1310.md)|otimizações guiadas por perfil não estão disponíveis com OpenMP|
|[Erro fatal C1311](../../error-messages/compiler-errors-1/fatal-error-c1311.md)|Formato COFF não é possível inicializar estaticamente '*símbolo*' com *número* bytes de um endereço|
|[Erro fatal C1312](fatal-error-c1312.md)|Muitas ramificações condicionais na função.  Simplifique ou Refatore o código-fonte.|
|[Erro fatal C1313](../../error-messages/compiler-errors-1/fatal-error-c1313.md)|limite do compilador: *tipo* blocos não podem ser aninhados mais profundo *número* níveis|
|[Erro fatal C1350](../../error-messages/compiler-errors-1/fatal-error-c1350.md)|Erro ao carregar a dll '*arquivo*': dll não encontrada|
|[Erro fatal C1351](../../error-messages/compiler-errors-1/fatal-error-c1351.md)|Erro ao carregar a dll '*arquivo*': versão incompatível|
|[Erro fatal C1352](fatal-error-c1352.md)|MSIL inválido ou corrompido na função '*função*'do módulo'*módulo*'|
|[Erro fatal C1353](fatal-error-c1353.md)|Falha na operação de metadados: tempo de execução não instalado ou incompatibilidade de versão|
|[Erro fatal C1382](../../error-messages/compiler-errors-1/fatal-error-c1382.md)|o arquivo PCH '*arquivo*'foi recriado desde'*obj*' foi gerado. Recompile este objeto|
|[Erro fatal C1383](fatal-error-c1383.md)|opção de compilador /GL é incompatível com a versão instalada do common language runtime|
|Erro fatal C1384|Configuração incorreta para PGO_PATH_TRANSLATION ao vincular '*arquivo*'|
|Erro fatal C1451|Falha ao gerar informações de depuração ao compilar o grafo de chamada para o Concurrency:: parallel_for_each em: '*callsite*'|
|Erro fatal C1505|Erro de previsão do analisador irrecuperável|
|[Erro fatal C1506](../../error-messages/compiler-errors-1/fatal-error-c1506.md)|Erro de escopo de bloco irrecuperável|
|[Erro fatal C1508](fatal-error-c1508.md)|limite do compilador: '*função*': mais de 65535 bytes de argumento|
|[Erro fatal C1509](../../error-messages/compiler-errors-1/fatal-error-c1509.md)|limite do compilador: muitos estados de manipulador de exceção na função '*função*'; Simplifique a função|
|[Erro fatal C1510](../../error-messages/compiler-errors-1/fatal-error-c1510.md)|Não é possível abrir o recurso de linguagem clui. dll|
|[Erro fatal C1601](../../error-messages/compiler-errors-1/fatal-error-c1601.md)|opcode de assembly embutido não suportado|
|[Erro fatal C1602](../../error-messages/compiler-errors-1/fatal-error-c1602.md)|intrínseco não suportado|
|[Erro fatal C1603](../../error-messages/compiler-errors-1/fatal-error-c1603.md)|destino de ramificação do assembly embutido fora do intervalo por *número* bytes|
|[Erro fatal C1852](fatal-error-c1852.md)|'*arquivo*' não é um arquivo de cabeçalho pré-compilado válido|
|[Erro fatal C1853](../../error-messages/compiler-errors-1/fatal-error-c1853.md)|'*arquivo*' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você estiver usando do C (ou vice-versa)|
|[Erro fatal C1854](../../error-messages/compiler-errors-1/fatal-error-c1854.md)|não é possível substituir informação formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: '*arquivo*'|
|[Erro fatal C1900](../../error-messages/compiler-errors-1/fatal-error-c1900.md)|Incompatibilidade de linguagem intermediária entre '*ferramenta*'version'*número*'e'*ferramenta*'version'*número*'|
|Erro fatal C1901|Erro de gerenciamento de memória interna|
|[Erro fatal C1902](../../error-messages/compiler-errors-1/fatal-error-c1902.md)|incompatibilidade de Gerenciador de banco de dados do programa; Verifique sua instalação|
|[Erro fatal C1903](fatal-error-c1903.md)|não é possível recuperar de erro (s) anterior; interrompendo compilação|
|[Erro fatal C1904](fatal-error-c1904.md)|interação de provedor incorreta: '*arquivo*'|
|[Erro fatal C1905](../../error-messages/compiler-errors-1/fatal-error-c1905.md)|Front-end e back-end não compatíveis (devem usar o mesmo processador).|