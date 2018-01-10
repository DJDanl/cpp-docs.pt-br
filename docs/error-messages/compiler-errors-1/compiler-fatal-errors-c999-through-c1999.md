---
title: "Erros fatais do compilador C999 até C1999 | Microsoft Docs"
ms.custom: 
ms.date: 11/17/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1012
- C1013
- C1014
- C1016
- C1018
- C1019
- C1020
- C1021
- C1022
- C1023
- C1034
- C1035
- C1036
- C1037
- C1038
- C1041
- C1045
- C1047
- C1048
- C1049
- C1053
- C1063
- C1068
- C1069
- C1070
- C1074
- C1077
- C1082
- C1086
- C1087
- C1088
- C1089
- C1090
- C1091
- C1098
- C1099
- C1100
- C1101
- C1102
- C1103
- C1104
- C1105
- C1108
- C1109
- C1110
- C1111
- C1112
- C1114
- C1190
- C1193
- C1195
- C1196
- C1201
- C1202
- C1205
- C1206
- C1207
- C1208
- C1209
- C1210
- C1211
- C1300
- C1301
- C1302
- C1306
- C1310
- C1312
- C1352
- C1353
- C1383
- C1384
- C1451
- C1505
- C1508
- C1510
- C1852
- C1901
- C1903
- C1904
helpviewer_keywords:
- C1012
- C1013
- C1014
- C1016
- C1018
- C1019
- C1020
- C1021
- C1022
- C1023
- C1034
- C1035
- C1036
- C1037
- C1038
- C1041
- C1045
- C1047
- C1048
- C1049
- C1053
- C1063
- C1068
- C1069
- C1070
- C1074
- C1077
- C1082
- C1086
- C1087
- C1088
- C1089
- C1090
- C1091
- C1098
- C1099
- C1100
- C1101
- C1102
- C1103
- C1104
- C1105
- C1108
- C1109
- C1110
- C1111
- C1112
- C1114
- C1190
- C1193
- C1195
- C1196
- C1201
- C1202
- C1205
- C1206
- C1207
- C1208
- C1209
- C1210
- C1211
- C1300
- C1301
- C1302
- C1306
- C1310
- C1312
- C1352
- C1353
- C1383
- C1384
- C1451
- C1505
- C1508
- C1510
- C1852
- C1901
- C1903
- C1904
dev_langs: C++
ms.assetid: 6c8df109-7594-48ed-987a-97d9fe2b04af
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f91cd5525fa09e9ab324ce25feabd0dc01b48d4d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-fatal-errors-c999-through-c1999"></a>Erros fatais do compilador C999 até C1999

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro fatal C999](../../error-messages/compiler-errors-1/fatal-error-c999.md)|MENSAGEM desconhecida, escolha o comando de suporte técnico no menu Ajuda do Visual C++ ou abrir o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro fatal C1001](../../error-messages/compiler-errors-1/fatal-error-c1001.md)|Erro interno no compilador.<br /><br /> (arquivo do compilador '*arquivo*', linha *número*)<br /><br /> Para contornar esse problema, tente simplificar ou alterar o programa próximo aos locais listados acima. Escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abrir o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro fatal C1002](../../error-messages/compiler-errors-1/fatal-error-c1002.md)|compilador está fora do espaço de heap no passo 2|
|[Erro fatal C1003](../../error-messages/compiler-errors-1/fatal-error-c1003.md)|Contagem de erro exceder *número*; interrompendo compilação|
|[Erro fatal C1004](../../error-messages/compiler-errors-1/fatal-error-c1004.md)|fim-de-arquivo inesperado encontrado|
|[Erro fatal C1005](../../error-messages/compiler-errors-1/fatal-error-c1005.md)|cadeia de caracteres muito grande para o buffer|
|[Erro fatal C1007](../../error-messages/compiler-errors-1/fatal-error-c1007.md)|sinalizador não reconhecido '*cadeia de caracteres*'in'*opção*'|
|[Erro fatal C1008](../../error-messages/compiler-errors-1/fatal-error-c1008.md)|Nenhum arquivo de entrada especificado|
|[Erro fatal C1009](../../error-messages/compiler-errors-1/fatal-error-c1009.md)|limite do compilador: macros com aninhamento muito profundo|
|[Erro fatal C1010](../../error-messages/compiler-errors-1/fatal-error-c1010.md)|fim de arquivo inesperado durante a procura de cabeçalho pré-compilado. Você esqueceu de adicionar ' #include <*arquivo*>' para sua fonte?|
|Erro fatal C1012|parênteses: faltando '*caracteres*"|
|Erro fatal C1013|limite do compilador: muitos parênteses abertos|
|Erro fatal C1014|incluem muitos arquivos: profundidade = *número*|
|Erro fatal C1016|#ifdef / #ifndef esperava um identificador|
|[Erro fatal C1017](../../error-messages/compiler-errors-1/fatal-error-c1017.md)|expressão constante inteira inválida|
|Erro fatal C1018|#elif inesperado|
|Erro fatal C1019|inesperado #else|
|Erro fatal C1020|#endif inesperado|
|Erro fatal C1021|comando de pré-processador inválido '*cadeia de caracteres*'|
|Erro fatal C1022|#endif esperado|
|Erro fatal C1023|'*arquivo*': erro inesperado com pch, tente recompilá-lo|
|[Erro fatal C1026](../../error-messages/compiler-errors-1/fatal-error-c1026.md)|estouro de pilha do analisador, programa muito complexo|
|[Erro fatal C1033](../../error-messages/compiler-errors-1/fatal-error-c1033.md)|não é possível abrir o banco de dados do programa '*arquivo*'|
|Erro fatal C1034|*arquivo*: nenhum caminho de include definido|
|Erro fatal C1035|expressão muito complexa; simplificar a expressão|
|Erro fatal C1036|não é possível substituir o formato de banco de dados do programa anterior, exclua '*arquivo*' e recompile|
|Erro fatal C1037|não é possível abrir o arquivo de objeto '*arquivo*'|
|Erro fatal C1038|limite do compilador: '*função*': controlar o estado de fluxo muito complexo; Simplifique a função|
|Erro fatal C1041|não é possível abrir o banco de dados do programa '*arquivo*'; se vários CL. EXE de gravação para o mesmo. PDB do arquivo, use /FS|
|Erro fatal C1045|limite do compilador: especificações de vinculação com aninhamento muito profundo|
|[Erro fatal C1046](../../error-messages/compiler-errors-1/fatal-error-c1046.md)|limite do compilador: *estrutura* com aninhamento muito profundo|
|Erro fatal C1047|O arquivo de objeto ou de biblioteca '*arquivo*' foi criado com um compilador mais antigo do que outros objetos; objetos antigo de recriação e bibliotecas|
|Erro fatal C1048|opção desconhecida '*cadeia de caracteres*'in'*opção*'|
|Erro fatal C1049|argumento numérico inválido '*valor*'|
|[Erro fatal C1051](../../error-messages/compiler-errors-1/fatal-error-c1051.md)|arquivo de banco de dados do programa, '*arquivo*', tem um formato obsoleto, exclua-o e recompile|
|[Erro fatal C1052](fatal-error-c1052.md)|arquivo de banco de dados do programa, '*filename*', foi gerado pelo vinculador com /debug: fastlink; compilador não pode atualizar esses arquivos PDB; exclua-o ou use /Fd para especificar um nome de arquivo PDB diferente|
|Erro fatal C1053|'*função*': função muito grande|
|[Erro fatal C1054](../../error-messages/compiler-errors-1/fatal-error-c1054.md)|limite do compilador: inicializadores com aninhamento muito profundo|
|[Erro fatal C1055](../../error-messages/compiler-errors-1/fatal-error-c1055.md)|limite do compilador: sem chaves|
|[Erro fatal C1057](../../error-messages/compiler-errors-1/fatal-error-c1057.md)|fim de arquivo inesperado na expansão de macro|
|[Erro fatal C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md)|o compilador está fora do espaço de heap|
|[Erro fatal C1061](../../error-messages/compiler-errors-1/fatal-error-c1061.md)|limite do compilador: blocos com aninhamento muito profundo|
|Erro fatal C1063|limite do compilador: estouro de pilha do compilador|
|[Erro fatal C1064](../../error-messages/compiler-errors-1/fatal-error-c1064.md)|limite do compilador: token estourou o buffer interno|
|[Erro fatal C1065](../../error-messages/compiler-errors-1/fatal-error-c1065.md)|limite do compilador: sem marcas|
|[Erro fatal C1067](../../error-messages/compiler-errors-1/fatal-error-c1067.md)|limite do compilador: limite de 64K para tamanho de um registro de tipo foi excedido|
|Erro fatal C1068|não é possível abrir o arquivo '*arquivo*'|
|Erro fatal C1069|não é possível ler a linha de comando do compilador|
|Erro fatal C1070|incompatível #if / #endif emparelhar no arquivo '*arquivo*'|
|[Erro fatal C1071](../../error-messages/compiler-errors-1/fatal-error-c1071.md)|fim de arquivo inesperado encontrado no comentário|
|[Erro fatal C1073](../../error-messages/compiler-errors-1/fatal-error-c1073.md)|Erro interno envolvendo compilação incremental (arquivo do compilador '*arquivo*', linha *número*)|
|Erro fatal C1074|'IDB' é uma extensão inválida para o arquivo PDB: *arquivo*|
|[Erro fatal C1075](../../error-messages/compiler-errors-1/fatal-error-c1075.md)|à esquerda *token* tinha correspondência no final do arquivo|
|[Erro fatal C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md)|limite do compilador: limite de heap interno atingido; Use /Zm para especificar um limite superior|
|Erro fatal C1077|limite do compilador: não é possível ter mais de *número* opções de linha de comando|
|[Erro fatal C1079](../../error-messages/compiler-errors-1/fatal-error-c1079.md)|limite do compilador: limite de tamanho de arquivo PCH excedido|
|[Erro fatal C1080](../../error-messages/compiler-errors-1/fatal-error-c1080.md)|limite do compilador: limite excedido para a opção de linha de comando de *número* caracteres|
|[Erro fatal C1081](../../error-messages/compiler-errors-1/fatal-error-c1081.md)|'*arquivo*': nome de arquivo muito longo|
|Erro fatal C1082|não é possível fechar *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1083](../../error-messages/compiler-errors-1/fatal-error-c1083.md)|não é possível abrir *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1084](../../error-messages/compiler-errors-1/fatal-error-c1084.md)|não é possível ler *tipo* arquivo: '*arquivo*': *mensagem*|
|[Erro fatal C1085](../../error-messages/compiler-errors-1/fatal-error-c1085.md)|não é possível gravar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1086|não é possível buscar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1087|não é possível determinar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1088|não é possível liberar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1089|não é possível truncar *tipo* arquivo: '*arquivo*': *mensagem*|
|Erro fatal C1090|Falha na chamada à API PDB, código de erro '*código*': '*mensagem*'|
|Erro fatal C1091|limite do compilador: cadeia de caracteres excede *número* bytes de comprimento|
|[Erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md)|Editar e continuar não dá suporte a alterações em tipos de dados; compilação necessária|
|[Erro fatal C1093](../../error-messages/compiler-errors-1/fatal-error-c1093.md)|Chamada de API '*função*'com falha'*HRESULT*': '*descrição*'|
|[Erro fatal C1094](../../error-messages/compiler-errors-1/fatal-error-c1094.md)|'-Zm*número*': opção de linha de comando é inconsistente com o valor usado para compilar cabeçalho pré-compilado ('-Zm*número*')|
|Erro fatal C1098|Incompatibilidade de versão com mecanismo editar e continuar|
|Erro fatal C1099|Editar e continuar encerrando compilação do mecanismo|
|Erro fatal C1100|não é possível inicializar o OLE: *erro*|
|Erro fatal C1101|não é possível criar o manipulador para atributo '*identificador*'|
|Erro fatal C1102|não é possível inicializar: *erro*|
|Erro fatal C1103|Erro fatal ao importar progid: '*mensagem*'|
|Erro fatal C1104|Erro fatal ao importar libid: '*mensagem*'|
|Erro fatal C1105|*mensagem*: *erro*|
|[Erro fatal C1107](../../error-messages/compiler-errors-1/fatal-error-c1107.md)|não foi possível encontrar o assembly '*assembly*': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH|
|Erro fatal C1108|não é possível localizar a DLL: '*arquivo*'|
|Erro fatal C1109|não é possível localizar '*símbolo*'na DLL'*arquivo*'|
|Erro fatal C1110|muitas definições de modelo/generic aninhada|
|Erro fatal C1111|número excessivo de parâmetros de modelo/generic|
|Erro fatal C1112|limite do compilador: `'number`' muitos argumentos de macro, apenas *número* permitido|
|[Erro fatal C1113](../../error-messages/compiler-errors-1/fatal-error-c1113.md)|#using falhou em '*arquivo*'|
|Erro fatal C1114|'*arquivo*': WinRT não oferece suporte a #using de um assembly gerenciado|
|[Erro fatal C1120](../../error-messages/compiler-errors-1/fatal-error-c1120.md)|chamada a GetProcAddress falhou para '*função*'|
|[Erro fatal C1121](../../error-messages/compiler-errors-1/fatal-error-c1121.md)|chamada a CryptoAPI falhou|
|[Erro fatal C1126](../../error-messages/compiler-errors-1/fatal-error-c1126.md)|alocação automática excede *tamanho*|
|[Erro fatal C1128](../../error-messages/compiler-errors-1/fatal-error-c1128.md)|número de seções excedeu o limite de formato de arquivo de objeto: compile com /bigobj|
|[Erro fatal C1189](../../error-messages/compiler-errors-1/fatal-error-c1189.md)|#error: *mensagem*|
|Erro fatal C1190|código gerenciado direcionado requer uma ' / clr' opção|
|[Erro fatal C1191](../../error-messages/compiler-errors-1/fatal-error-c1191.md)|'*arquivo*' só podem ser importados no escopo global|
|[Erro fatal C1192](../../error-messages/compiler-errors-1/fatal-error-c1192.md)|#using falhou em '*arquivo*'|
|Erro fatal C1193|Erro esperado em *arquivo*(*linha*) não atingido|
|Erro fatal C1195|uso de /Yu e /Yc na mesma linha de comando é incompatível com a opção /clr|
|Erro fatal C1196|'*identificador*': identificador encontrado na biblioteca de tipos '*typelib*' não é um identificador válido do C++|
|[Erro fatal C1197](../../error-messages/compiler-errors-1/fatal-error-c1197.md)|não é possível referenciar '*arquivo*'como o programa já referenciou'*arquivo*'|
|Erro fatal C1201|não é possível continuar após erro de sintaxe na definição do modelo de classe|
|Erro fatal C1202|recursiva tipo ou função dependência contexto muito complexo|
|Erro fatal C1205|Genéricos não são suportados pela versão do tempo de execução instalada|
|Erro fatal C1206|Dados Per-appdomain não há suporte para a versão do tempo de execução instalado|
|Erro fatal C1207|Templates gerenciados não suportados pela versão do tempo de execução instalada|
|Erro fatal C1208|Não há suporte para alocar classes de referência na pilha pela versão do tempo de execução instalada|
|Erro fatal C1209|Friend assemblies não suportados pela versão do tempo de execução instalada|
|Erro fatal C1210|/CLR: pure e /CLR: safe não são suportados pela versão do tempo de execução instalada|
|Erro fatal C1211|Não há suporte para o atributo personalizado TypeForwardedTo pela versão do tempo de execução instalada|
|Erro fatal C1300|Erro ao acessar o banco de dados do programa *arquivo* (*mensagem*)|
|Erro fatal C1301|Erro ao acessar o banco de dados do programa *arquivo*inválido, Formatar, exclua e recompile|
|Erro fatal C1302|Nenhum dado de perfil para módulo '*módulo*'no banco de dados de perfil'*arquivo*'|
|[Erro fatal C1305](../../error-messages/compiler-errors-1/fatal-error-c1305.md)|banco de dados de perfil '*arquivo*' para uma arquitetura diferente|
|Erro fatal C1306|última alteração na base de dados de perfil '*arquivo*' não era análise de otimização; decisões de otimização podem estar desatualizadas|
|[Erro fatal C1307](../../error-messages/compiler-errors-1/fatal-error-c1307.md)|programa foi editado desde que foram coletados dados de perfil|
|[Erro fatal C1308](../../error-messages/compiler-errors-1/fatal-error-c1308.md)|*arquivo*: não há suporte para vinculação assemblies|
|[Erro fatal C1309](../../error-messages/compiler-errors-1/fatal-error-c1309.md)|Versões incompatíveis do C2. DLL e pgodb*ver*. DLL|
|Erro fatal C1310|otimizações guiadas por perfil não estão disponíveis com OpenMP|
|[Erro fatal C1311](../../error-messages/compiler-errors-1/fatal-error-c1311.md)|Formato COFF não pode inicializar estaticamente '*símbolo*' com *número* bytes de um endereço|
|Erro fatal C1312|Muitas ramificações condicionais na função.  Simplifique ou Refatore o código-fonte.|
|[Erro fatal C1313](../../error-messages/compiler-errors-1/fatal-error-c1313.md)|limite do compilador: *tipo* blocos não podem ser aninhados mais profundo que *número* níveis|
|[Erro fatal C1350](../../error-messages/compiler-errors-1/fatal-error-c1350.md)|Erro ao carregar a dll '*arquivo*': dll não encontrada|
|[Erro fatal C1351](../../error-messages/compiler-errors-1/fatal-error-c1351.md)|Erro ao carregar a dll '*arquivo*': versão incompatível|
|Erro fatal C1352|MSIL inválido ou corrompido na função '*função*'do módulo'*módulo*'|
|Erro fatal C1353|Falha na operação de metadados: tempo de execução não instalado ou versão incompatível|
|[Erro fatal C1382](../../error-messages/compiler-errors-1/fatal-error-c1382.md)|o arquivo PCH '*arquivo*'foi recompilado desde'*obj*' foi gerado. Recompile este objeto|
|Erro fatal C1383|opção de compilador /GL é incompatível com a versão instalada do common language runtime|
|Erro fatal C1384|Configuração incorreta para PGO_PATH_TRANSLATION ao vincular '*arquivo*'|
|Erro fatal C1451|Falha ao gerar informações de depuração ao compilar o gráfico de chamada para o Concurrency:: parallel_for_each em: '*callsite*'|
|Erro fatal C1505|Erro de visão antecipada do analisador irrecuperável|
|[Erro fatal C1506](../../error-messages/compiler-errors-1/fatal-error-c1506.md)|Erro de escopo de bloco irrecuperável|
|Erro fatal C1508|limite do compilador: '*função*': mais de 65535 bytes de argumento|
|[Erro fatal C1509](../../error-messages/compiler-errors-1/fatal-error-c1509.md)|limite do compilador: muitos estados de manipulador de exceção na função '*função*'; Simplifique a função|
|[Erro fatal C1510](../../error-messages/compiler-errors-1/fatal-error-c1510.md)|Não é possível abrir o recurso de linguagem clui.dll|
|[Erro fatal C1601](../../error-messages/compiler-errors-1/fatal-error-c1601.md)|opcode de assembly embutido não suportado|
|[Erro fatal C1602](../../error-messages/compiler-errors-1/fatal-error-c1602.md)|sem suporte intrínseco|
|[Erro fatal C1603](../../error-messages/compiler-errors-1/fatal-error-c1603.md)|destino de ramificação de assembly embutido fora de intervalo por *número* bytes|
|Erro fatal C1852|'*arquivo*' não é um arquivo de cabeçalho pré-compilado válido|
|[Erro fatal C1853](../../error-messages/compiler-errors-1/fatal-error-c1853.md)|'*arquivo*' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é de C++ e você estiver usando do C (ou vice-versa)|
|[Erro fatal C1854](../../error-messages/compiler-errors-1/fatal-error-c1854.md)|não é possível substituir informação formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: '*arquivo*'|
|[Erro fatal C1900](../../error-messages/compiler-errors-1/fatal-error-c1900.md)|Incompatibilidade de IL entre '*ferramenta*'version'*número*'e'*ferramenta*'version'*número*'|
|Erro fatal C1901|Erro de gerenciamento de memória interna|
|[Erro fatal C1902](../../error-messages/compiler-errors-1/fatal-error-c1902.md)|Incompatibilidade de Gerenciador de banco de dados do programa; Verifique a instalação|
|Erro fatal C1903|não é possível recuperar de erros anteriores; interrompendo compilação|
|Erro fatal C1904|a interação do provedor inválido: '*arquivo*'|
|[Erro fatal C1905](../../error-messages/compiler-errors-1/fatal-error-c1905.md)|Front-end e back-end incompatíveis (devem ter como destino mesmo processador).|