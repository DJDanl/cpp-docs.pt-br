---
title: "Erros fatais do compilador C999 até C1999 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
dev_langs:
- C++
ms.assetid: 6c8df109-7594-48ed-987a-97d9fe2b04af
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: 8de993694813842e6c892bc349848a8b0a030a25
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-fatal-errors-c999-through-c1999"></a>Erros fatais do compilador C999 até C1999
Os artigos nesta parte da documentação contêm informações sobre uma subseção de erros do compilador do Visual C++. Você pode acessar as informações aqui ou no **saída** janela no Visual Studio, você pode selecionar um número de erro e pressione a tecla F1.  
  
|Erro|Mensagem|  
|-----------|-------------|  
|[Erro fatal C999](../../error-messages/compiler-errors-1/fatal-error-c999.md)|MENSAGEM desconhecida, escolha o comando de suporte técnico no menu Ajuda do Visual C++ ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|  
|[Erro fatal C1001](../../error-messages/compiler-errors-1/fatal-error-c1001.md)|Ocorreu um erro interno no compilador.<br /><br /> (arquivo de compilador '`file`', linha `number`)<br /><br /> Para contornar esse problema, tente simplificar ou alterar o programa quase locais listados acima. Escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|  
|[Erro fatal C1002](../../error-messages/compiler-errors-1/fatal-error-c1002.md)|espaço de heap do compilador insuficiente no passo 2|  
|[Erro fatal C1003](../../error-messages/compiler-errors-1/fatal-error-c1003.md)|Contagem de erros excede `number`; interromper a compilação|  
|[Erro fatal C1004](../../error-messages/compiler-errors-1/fatal-error-c1004.md)|fim de arquivo inesperado encontrado|  
|[Erro fatal C1005](../../error-messages/compiler-errors-1/fatal-error-c1005.md)|cadeia de caracteres muito grande para o buffer|  
|[Erro fatal C1007](../../error-messages/compiler-errors-1/fatal-error-c1007.md)|sinalizador não reconhecido '`string`'em'`option`'|  
|[Erro fatal C1008](../../error-messages/compiler-errors-1/fatal-error-c1008.md)|nenhum arquivo de entrada especificado|  
|[Erro fatal C1009](../../error-messages/compiler-errors-1/fatal-error-c1009.md)|limite do compilador: macros com aninhamento muito profundo|  
|[Erro fatal C1010](../../error-messages/compiler-errors-1/fatal-error-c1010.md)|fim de arquivo inesperado durante a procura de cabeçalho pré-compilado. Você esqueceu de adicionar ' #include `file`>' para a sua fonte?|  
|Erro fatal C1012|parênteses: ausente '`character`"|  
|Erro fatal C1013|limite do compilador: muitos parênteses abertos|  
|Erro fatal C1014|muitos arquivos de inclusão: profundidade =`number`|  
|Erro fatal C1016|#um identificador é esperado ifdef / #ifndef|  
|[Erro fatal C1017](../../error-messages/compiler-errors-1/fatal-error-c1017.md)|expressão de constante inteira inválida|  
|Erro fatal C1018|#elif inesperado|  
|Erro fatal C1019|#else inesperado|  
|Erro fatal C1020|#endif inesperado|  
|Erro fatal C1021|comando de pré-processador inválido '`string`'|  
|Erro fatal C1022|#endif esperado|  
|Erro fatal C1023|'`file`': erro inesperado com pch, tente recriar o pch|  
|[Erro fatal C1026](../../error-messages/compiler-errors-1/fatal-error-c1026.md)|estouro na pilha do analisador, programa muito complexo|  
|[Erro fatal C1033](../../error-messages/compiler-errors-1/fatal-error-c1033.md)|não é possível abrir o banco de dados do programa '`file`'|  
|Erro fatal C1034|`file`: não incluir um conjunto de caminhos|  
|Erro fatal C1035|expressão muito complexa; simplifique-a|  
|Erro fatal C1036|não é possível substituir o formato de banco de dados do programa anterior, excluir '`file`' e recompilar|  
|Erro fatal C1037|não é possível abrir o arquivo de objeto '`file`'|  
|Erro fatal C1038|limite do compilador: '`function`': controlar o estado de fluxo muito complexo; simplificar a função|  
|Erro fatal C1041|não é possível abrir o banco de dados do programa '`file`'; se vários CL. EXE gravar o mesmo. PDB do arquivo, use /FS|  
|Erro fatal C1045|limite do compilador: especificações de vinculação com aninhamento muito profundo|  
|[Erro fatal C1046](../../error-messages/compiler-errors-1/fatal-error-c1046.md)|limite do compilador: `structure` profundamente aninhados|  
|Erro fatal C1047|O arquivo de biblioteca ou de objeto '`file`' foi criado com um compilador mais antigo do que outros objetos; reconstrução antigos objetos e bibliotecas|  
|Erro fatal C1048|opção desconhecida '`string`'em'`option`'|  
|Erro fatal C1049|argumento numérico inválido '`value`'|  
|[Erro fatal C1051](../../error-messages/compiler-errors-1/fatal-error-c1051.md)|arquivo de banco de dados do programa, '`file`', tem um formato obsoleto, exclua-o e recompile|  
|Erro fatal C1053|'`function`': função muito grande|  
|[Erro fatal C1054](../../error-messages/compiler-errors-1/fatal-error-c1054.md)|limite do compilador: inicializadores com aninhamento muito profundo|  
|[Erro fatal C1055](../../error-messages/compiler-errors-1/fatal-error-c1055.md)|limite do compilador: sem chaves|  
|[Erro fatal C1057](../../error-messages/compiler-errors-1/fatal-error-c1057.md)|fim de arquivo inesperado na expansão de macro|  
|[Erro fatal C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md)|o compilador está fora do espaço de heap|  
|[Erro fatal C1061](../../error-messages/compiler-errors-1/fatal-error-c1061.md)|limite do compilador: blocos com aninhamento muito profundo|  
|Erro fatal C1063|limite do compilador: estouro de pilha do compilador|  
|[Erro fatal C1064](../../error-messages/compiler-errors-1/fatal-error-c1064.md)|limite do compilador: o token estourou o buffer interno|  
|[Erro fatal C1065](../../error-messages/compiler-errors-1/fatal-error-c1065.md)|limite do compilador: sem marcas|  
|[Erro fatal C1067](../../error-messages/compiler-errors-1/fatal-error-c1067.md)|limite do compilador: o limite de 64K de tamanho de um registro de tipo foi excedido|  
|Erro fatal C1068|não é possível abrir o arquivo '`file`'|  
|Erro fatal C1069|não é possível ler a linha de comando do compilador|  
|Erro fatal C1070|incompatíveis #if / #endif par no arquivo '`file`'|  
|[Erro fatal C1071](../../error-messages/compiler-errors-1/fatal-error-c1071.md)|fim de arquivo inesperado encontrado no comentário|  
|[Erro fatal C1073](../../error-messages/compiler-errors-1/fatal-error-c1073.md)|Erro interno que envolvem a compilação incremental (arquivo de compilador '`file`', linha `number`)|  
|Erro fatal C1074|'IDB' é ilegal extensão para o arquivo PDB:`file`|  
|[Erro fatal C1075](../../error-messages/compiler-errors-1/fatal-error-c1075.md)|à esquerda `token` foi não correspondentes ao final do arquivo|  
|[Erro fatal C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md)|limite do compilador: limite de heap interno atingido; use /Zm para especificar um limite mais alto|  
|Erro fatal C1077|limite do compilador: não é possível ter mais de `number` opções de linha de comando|  
|[Erro fatal C1079](../../error-messages/compiler-errors-1/fatal-error-c1079.md)|limite do compilador: Limite de tamanho de arquivo PCH excedido|  
|[Erro fatal C1080](../../error-messages/compiler-errors-1/fatal-error-c1080.md)|limite do compilador: limite de opção excedida de linha de comando de `number` caracteres|  
|[Erro fatal C1081](../../error-messages/compiler-errors-1/fatal-error-c1081.md)|'`file`': nome de arquivo muito longo|  
|Erro fatal C1082|não é possível fechar `type` arquivo: '`file`':`message`|  
|[Erro fatal C1083](../../error-messages/compiler-errors-1/fatal-error-c1083.md)|não é possível abrir `type` arquivo: '`file`':`message`|  
|[Erro fatal C1084](../../error-messages/compiler-errors-1/fatal-error-c1084.md)|não é possível ler `type` arquivo: '`file`':`message`|  
|[Erro fatal C1085](../../error-messages/compiler-errors-1/fatal-error-c1085.md)|não é possível gravar `type` arquivo: '`file`':`message`|  
|Erro fatal C1086|não é possível buscar `type` arquivo: '`file`':`message`|  
|Erro fatal C1087|não é possível informar `type` arquivo: '`file`':`message`|  
|Erro fatal C1088|não é possível liberar `type` arquivo: '`file`':`message`|  
|Erro fatal C1089|não é possível truncar `type` arquivo: '`file`':`message`|  
|Erro fatal C1090|Falha na chamada de API de PDB, código de erro '`code`': '`message`'|  
|Erro fatal C1091|limite do compilador: cadeia de caracteres excede `number` bytes de comprimento|  
|[Erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md)|Editar e Continuar não suporta alterações em tipos de dados; compilação necessária|  
|[Erro fatal C1093](../../error-messages/compiler-errors-1/fatal-error-c1093.md)|API call '`function`' failed '`HRESULT`' : '`description`'|  
|[Erro fatal C1094](../../error-messages/compiler-errors-1/fatal-error-c1094.md)|'-Zm`number`': opção de linha de comando é inconsistente com o valor usado para criar o cabeçalho pré-compilado ('-Zm`number`')|  
|Erro fatal C1098|Incompatibilidade de versão com mecanismo Editar e Continuar|  
|Erro fatal C1099|Mecanismo Editar e Continuar encerrando compilação|  
|Erro fatal C1100|não foi possível inicializar o OLE:`error`|  
|Erro fatal C1101|não é possível criar o manipulador para o atributo '`identifier`'|  
|Erro fatal C1102|não foi possível inicializar:`error`|  
|Erro fatal C1103|Erro fatal ao importar progid: '`message`'|  
|Erro fatal C1104|Erro fatal ao importar libid: '`message`'|  
|Erro fatal C1105|`message`: `error`|  
|[Erro fatal C1107](../../error-messages/compiler-errors-1/fatal-error-c1107.md)|não foi possível encontrar o assembly '`assembly`': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH|  
|Erro fatal C1108|não é possível localizar a DLL: '`file`'|  
|Erro fatal C1109|não é possível localizar '`symbol`'na DLL'`file`'|  
|Erro fatal C1110|muitas definições de modelo/genérico aninhado|  
|Erro fatal C1111|número excessivo de parâmetros de modelo/genérico|  
|Erro fatal C1112|limite do compilador: `'number`' muitos argumentos de macro, apenas `number` permitido|  
|[Erro fatal C1113](../../error-messages/compiler-errors-1/fatal-error-c1113.md)|#usando falhou em '`file`'|  
|Erro fatal C1114|'`file`': WinRT não suporta #using de um assembly gerenciado|  
|[Erro fatal C1120](../../error-messages/compiler-errors-1/fatal-error-c1120.md)|plano de GetProcAddress falhou para '`function`'|  
|[Erro fatal C1121](../../error-messages/compiler-errors-1/fatal-error-c1121.md)|falha na chamada a CryptoAPI|  
|[Erro fatal C1126](../../error-messages/compiler-errors-1/fatal-error-c1126.md)|excede a alocação automática`size`|  
|[Erro fatal C1128](../../error-messages/compiler-errors-1/fatal-error-c1128.md)|o número de seções excedeu o limite de formato de arquivo do objeto: compile com /bigobj|  
|[Erro fatal C1189](../../error-messages/compiler-errors-1/fatal-error-c1189.md)|#Erro:`message`|  
|Erro fatal C1190|código gerenciado direcionado requer uma opção '/clr'|  
|[Erro fatal C1191](../../error-messages/compiler-errors-1/fatal-error-c1191.md)|'`file`' só podem ser importados no escopo global|  
|[Erro fatal C1192](../../error-messages/compiler-errors-1/fatal-error-c1192.md)|#usando falhou em '`file`'|  
|Erro fatal C1193|um erro esperado em `file`(`line`) não foi atingido|  
|Erro fatal C1195|uso de /Yu e /Yc na mesma linha de comando é incompatível com a opção /clr|  
|Erro fatal C1196|'`identifier`': identificador encontrado na biblioteca de tipos '`typelib`' não é um identificador válido do C++|  
|[Erro fatal C1197](../../error-messages/compiler-errors-1/fatal-error-c1197.md)|não é possível referenciar '`file`'como o programa já está referenciado'`file`'|  
|Erro fatal C1201|não é possível continuar após erro de sintaxe na definição de template de classe|  
|Erro fatal C1202|tipo recursivo ou contexto de dependência de função muito complexo|  
|Erro fatal C1205|Generics não são suportados pela versão de tempo de execução instalada|  
|Erro fatal C1206|Dados per-appdomain não são suportados pela versão de tempo de execução instalada|  
|Erro fatal C1207|Templates gerenciados não suportados pela versão de tempo de execução instalada|  
|Erro fatal C1208|Alocar classes de referência na pilha não é suportado pela versão de tempo de execução instalada|  
|Erro fatal C1209|Friend assemblies não suportados pela versão de tempo de execução instalada|  
|Erro fatal C1210|/clr:pure e /clr:safe não são suportados pela versão de tempo de execução instalada|  
|Erro fatal C1211|O Atributo Personalizado TypeForwardedTo não é suportado pela versão de tempo de execução instalada|  
|Erro fatal C1300|Erro ao acessar o banco de dados do programa `file` (`message`)|  
|Erro fatal C1301|Erro ao acessar o banco de dados do programa `file`inválido, Formatar, exclua e recrie|  
|Erro fatal C1302|Nenhum dado de perfil para o módulo '`module`'no banco de dados de perfil'`file`'|  
|[Erro fatal C1305](../../error-messages/compiler-errors-1/fatal-error-c1305.md)|banco de dados de perfil '`file`' é uma arquitetura diferente|  
|Erro fatal C1306|última alteração ao banco de dados de perfil '`file`' não era análise de otimização; decisões de otimização podem estar desatualizadas|  
|[Erro fatal C1307](../../error-messages/compiler-errors-1/fatal-error-c1307.md)|programa foi editado após os dados de perfil serem coletados|  
|[Erro fatal C1308](../../error-messages/compiler-errors-1/fatal-error-c1308.md)|`file`: não há suporte para a vinculação de assemblies|  
|[Erro fatal C1309](../../error-messages/compiler-errors-1/fatal-error-c1309.md)|Versões não correspondentes de C2. DLL e pgodb`ver`. DLL|  
|Erro fatal C1310|otimizações guiadas por perfil não estão disponíveis com OpenMP|  
|[Erro fatal C1311](../../error-messages/compiler-errors-1/fatal-error-c1311.md)|Formato COFF estaticamente não é possível inicializar '`symbol`' com `number` byte de um endereço|  
|Erro fatal C1312|Muitas ramificações condicionais na função.  Simplifique ou refatorar o código-fonte.|  
|[Erro fatal C1313](../../error-messages/compiler-errors-1/fatal-error-c1313.md)|limite do compilador: `type` blocos não podem ser aninhados mais profundo que `number` níveis|  
|[Erro fatal C1350](../../error-messages/compiler-errors-1/fatal-error-c1350.md)|Erro ao carregar a dll '`file`': dll não encontrado|  
|[Erro fatal C1351](../../error-messages/compiler-errors-1/fatal-error-c1351.md)|Erro ao carregar a dll '`file`': versão incompatível|  
|Erro fatal C1352|MSIL inválido ou corrompido na função '`function`'do módulo'`module`'|  
|Erro fatal C1353|falha na operação de metadados: tempo de execução não instalado ou versão incompatível|  
|[Erro fatal C1382](../../error-messages/compiler-errors-1/fatal-error-c1382.md)|o arquivo PCH '`file`'foi reconstruído desde'`obj`' foi gerado. Recompile esse objeto|  
|Erro fatal C1383|opção de compilador /GL é incompatível com a versão instalada de common language runtime|  
|Erro fatal C1384|Configuração incorreta para PGO_PATH_TRANSLATION durante a vinculação '`file`'|  
|Erro fatal C1451|Falha ao gerar informações de depuração ao compilar o gráfico de chamada para concurrency::parallel_for_each em: '`callsite`'|  
|Erro fatal C1505|erro irrecuperável de look-ahead do analisador|  
|[Erro fatal C1506](../../error-messages/compiler-errors-1/fatal-error-c1506.md)|erro irrecuperável de escopo de blocos|  
|Erro fatal C1508|limite do compilador: '`function`': mais de 65.535 bytes de argumento|  
|[Erro fatal C1509](../../error-messages/compiler-errors-1/fatal-error-c1509.md)|limite do compilador: muitos estados de manipulador de exceção na função '`function`'; simplificar a função|  
|Erro fatal C1510|Não é possível abrir recurso de linguagem clui.dll|  
|[Erro fatal C1601](../../error-messages/compiler-errors-1/fatal-error-c1601.md)|opcode de assembly embutido não suportado|  
|[Erro fatal C1602](../../error-messages/compiler-errors-1/fatal-error-c1602.md)|intrínseco não suportado|  
|[Erro fatal C1603](../../error-messages/compiler-errors-1/fatal-error-c1603.md)|destino de ramificação de assembly embutido fora do intervalo por `number` bytes|  
|Erro fatal C1852|'`file`' não é um arquivo válido de cabeçalho pré-compilado|  
|[Erro fatal C1853](../../error-messages/compiler-errors-1/fatal-error-c1853.md)|'`file`' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você estiver usando do C (ou vice-versa)|  
|[Erro fatal C1854](../../error-messages/compiler-errors-1/fatal-error-c1854.md)|não é possível substituir informações formadas durante a criação do cabeçalho pré-compilado no arquivo de objeto: '`file`'|  
|[Erro fatal C1900](../../error-messages/compiler-errors-1/fatal-error-c1900.md)|II incompatibilidade entre '`tool`'version'`number`'e'`tool`'version'`number`'|  
|Erro fatal C1901|Erro de gerenciamento de memória interna|  
|[Erro fatal C1902](../../error-messages/compiler-errors-1/fatal-error-c1902.md)|Incompatibilidade do gerenciador de banco de dados do programa; verifique sua instalação|  
|Erro fatal C1903|Não é possível recuperar de erro(s) anterior(es); interrompendo compilação|  
|Erro fatal C1904|a interação do provedor inválido: '`file`'|  
|[Erro fatal C1905](../../error-messages/compiler-errors-1/fatal-error-c1905.md)|Front-end e back-end incompatíveis (devem ter como alvo o mesmo processador).|
