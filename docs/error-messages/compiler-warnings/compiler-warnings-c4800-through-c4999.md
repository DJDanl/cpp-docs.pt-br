---
title: Avisos do Compilador C4800 a C5999
ms.date: 04/21/2019
f1_keywords:
- C4808
- C4809
- C4825
- C4827
- C4837
- C4841
- C4842
- C4843
- C4844
- C4845
- C4846
- C4847
- C4848
- C4872
- C4880
- C4881
- C4882
- C4910
- C4916
- C4921
- C4934
- C4951
- C4954
- C4955
- C4963
- C4966
- C4970
- C4971
- C4973
- C4974
- C4981
- C4985
- C4987
- C4988
- C4989
- C4990
- C4991
- C4992
- C4998
- C5022
- C5023
- C5024
- C5025
- C5026
- C5027
- C5028
- C5029
- C5030
- C5031
- C5032
- C5033
- C5034
- C5035
- C5036
- C5037
- C5039
- C5040
- C5041
- C5042
- C5043
- C5044
- C5045
- C5046
- C5047
- C5048
- C5049
- C5050
- C5100
- C5101
- C5102
- C5103
- C5104
- C5105
- C5106
- C5107
helpviewer_keywords:
- C4808
- C4809
- C4825
- C4827
- C4837
- C4841
- C4842
- C4843
- C4844
- C4845
- C4846
- C4847
- C4848
- C4872
- C4880
- C4881
- C4882
- C4910
- C4916
- C4921
- C4934
- C4951
- C4954
- C4955
- C4963
- C4966
- C4970
- C4971
- C4973
- C4974
- C4981
- C4985
- C4987
- C4988
- C4989
- C4990
- C4991
- C4992
- C4998
- C5022
- C5023
- C5024
- C5025
- C5026
- C5027
- C5028
- C5029
- C5030
- C5031
- C5032
- C5033
- C5034
- C5035
- C5036
- C5037
- C5039
- C5040
- C5041
- C5042
- C5043
- C5044
- C5045
- C5046
- C5047
- C5048
- C5049
- C5050
- C5100
- C5101
- C5102
- C5103
- C5104
- C5105
- C5106
- C5107
ms.openlocfilehash: 93ff809d640efab6852e855f85e7b6e0109d9c1d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280303"
---
# <a name="compiler-warnings-c4800-through-c5999"></a>Avisos do Compilador C4800 a C5999

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

|Aviso|Mensagem|
|-------------|------------|
|[Aviso do compilador (nível 4) C4800](compiler-warning-level-3-c4800.md)| Conversão implícita de '*tipo*' em bool. Possível perda de informações |
|[Aviso do compilador (nível 1) C4803](compiler-warning-level-1-c4803.md)|'*método*': o método raise possui uma classe de armazenamento diferente do evento, '*evento*'|
|[Aviso do compilador (nível 1) C4804](compiler-warning-level-1-c4804.md)|'*operação*': uso não seguro de tipo 'bool' em operação|
|[Aviso do compilador (nível 1) C4805](compiler-warning-level-1-c4805.md)|'*operação*': mistura não segura de tipo '*type1*'e tipo'*type2*' em operação|
|[Aviso do compilador (nível 1) C4806](compiler-warning-level-1-c4806.md)|'*operação*': operação não segura: nenhum valor do tipo '*type1*'promovido para o tipo'*type2*' pode ser igual à constante fornecida|
|[Aviso do compilador (nível 1) C4807](compiler-warning-level-1-c4807.md)|'*operação*': mistura não segura de tipo '*type1*'e assinado o campo de bits do tipo'*type2*'|
|Aviso do compilador (nível 1) C4808|caso de '*valor*' é não um valor válido para a condição de switch de tipo 'bool'|
|Aviso do compilador (nível 1) C4809|instrução switch possui rótulo 'default' redundante; todos os rótulos 'case' possíveis são fornecidos|
|[Aviso do compilador (nível 1) C4810](compiler-warning-level-1-c4810.md)|valor de pragma Pack (show) = = n|
|[Aviso do compilador (nível 1) C4811](compiler-warning-level-1-c4811.md)|valor de pragma conform (forScope, show) = = valor|
|[Aviso do compilador (nível 1) C4812](compiler-warning-level-1-c4812.md)|estilo de declaração obsoleta: use '*new_syntax*' em vez disso|
|[Aviso do compilador (nível 1) C4813](compiler-warning-level-1-c4813.md)|'*função*': uma função friend de uma classe local deve ter sido declarada anteriormente|
|[Aviso do compilador (nível 4) C4816](compiler-warning-level-4-c4816.md)|'*param*': parâmetro possui uma matriz de tamanho zero que será truncada (a menos que o objeto é passado por referência)|
|[Aviso do compilador (nível 1) C4817](compiler-warning-level-1-c4817.md)|'*membro*': uso inválido de '.' para acessar este membro; compilador substituiu por '->'|
|[Aviso do compilador (nível 1) C4819](compiler-warning-level-1-c4819.md)|O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados|
|[Aviso do compilador (nível 4) C4820](compiler-warning-level-4-c4820.md)|'*bytes*'bytes de preenchimento adicionados após o constructo'*member_name*'|
|[Aviso do compilador (nível 1) C4821](compiler-warning-level-1-c4821.md)|Não é possível determinar o tipo de codificação Unicode, salve o arquivo com assinatura (BOM)|
|[Aviso do compilador (nível 1) C4822](compiler-warning-level-1-c4822.md)|'função de membro': função de membro de classe local não tem um corpo|
|[Aviso do compilador (nível 3) C4823](compiler-warning-level-3-c4823.md)|'*função*': usa ponteiros de fixação de desenrolamento, mas semântica não está habilitada. Considere o uso de /EHa|
|Aviso do compilador (nível 2) C4826|Conversão de '*type1*'para'*type2*' é estendido com sinal. Isso pode causar um comportamento inesperado de tempo de execução.|
|Aviso do compilador (nível 3) C4827|Um método 'ToString' público com 0 parâmetro deve ser marcado como virtual e substituir|
|[Aviso do compilador (nível 1) C4829](compiler-warning-level-1-c4829.md)|Parâmetros possivelmente incorretos para função principal. Considere a possibilidade de ' int principal (Platform:: array\<Platform:: String ^ > ^ argv)'|
|[Aviso do compilador (nível 1) C4835](compiler-warning-level-1-c4835.md)|'*variável*': o inicializador para dados exportados não será executado até que o código gerenciado é executado pela primeira vez no host assembly|
|Aviso do compilador (nível 4) C4837|trígrafo detectado: '?? *caractere*'substituído por'*caractere*'|
|[Aviso do compilador (nível 1) C4838](compiler-warning-level-1-c4838.md)|conversão de '*type_1*'para'*type_2*' requer uma conversão redutora|
|[Aviso do compilador (nível 3) C4839](compiler-warning-level-3-c4839.md)|uso não padrão da classe*tipo*' como um argumento para uma função variadic|
|[Aviso do compilador (nível 4) C4840](compiler-warning-level-4-c4840.md)|o uso não portátil da classe*tipo*' como um argumento para uma função variadic|
|Aviso do compilador (nível 4) C4841|extensão não padrão usada: designador de membro composto usado no offsetof|
|Aviso do compilador (nível 4) C4842|o resultado de 'offsetof' aplicado a um tipo usando a herança múltipla não é garantido para ser consistente entre versões do compilador|
|C4843 de aviso do compilador|'*type1*': Um manipulador de exceção de referência ao tipo de matriz ou função está inacessível, use '*type2*' em vez disso|
|C4844 de aviso do compilador|' Exportar módulo *module_name*;' agora é a sintaxe preferencial para declarar uma interface de módulo|
| Aviso do compilador (nível 4) C4845 | \_\_declspec (nenhum\_init\_all)' será ignorado se ' / d1initall\[0\|1\|2\|3]' não foi especificado na linha de comando |
| Aviso do compilador (nível 4) C4846 | '*valor*' não é um argumento válido para ' / d1initall': sinalizador de linha de comando ignorado |
| Aviso do compilador (nível 4) C4847 | '\_\_declspec (nenhum\_init\_all)' só pode ser aplicada a uma função, um tipo de classe ou uma variável local: ignorado |
| Aviso do compilador (nível 1) C4848 | suporte para o atributo padrão ' nenhuma\_exclusivo\_seu endereço de C + + 17 e versões anteriores é uma extensão de fornecedor |
|[Aviso do compilador (nível 4) C4866](c4866.md)| compilador não pode impor a ordem de avaliação da esquerda para a direita para a chamada para *operator_name*|
|[Aviso (erro) C4867 do compilador](compiler-warning-c4867.md)|'*função*': faltando lista de argumentos de chamada de função; use '*chamar*' para criar um ponteiro para membro|
|[Aviso do compilador (nível 4) C4868](compiler-warning-c4868.md)|'_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|
|Aviso do compilador (nível 2) C4872|divisão de ponto flutuante por zero detectado ao compilar o grafo de chamada para o Concurrency:: parallel_for_each em: '*local*'|
|Aviso do compilador (nível 1) C4880|conversão de ' const *type_1*'para'*type_2*': constness de um ponteiro ou referência podem resultar em comportamento indefinido em uma função de amp restringido|
|Aviso do compilador (nível 4) C4881|o construtor e/ou o destruidor não será invocado para inicializar a variável tile_static '*variável*'|
|Aviso do compilador (nível 1) C4882|a transmissão de functors com operadores de chamada não constantes para Concurrency:: parallel_for_each foi preterida|
|[C4900 de aviso do compilador](compiler-warning-level-1-c4900.md)|Incompatibilidade de linguagem intermediária entre '*tool1*'version'*version1*'e'*tool2*'version'*version2*'|
|[Aviso do compilador (nível 1) C4905](compiler-warning-level-1-c4905.md)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|
|[Aviso do compilador (nível 1) C4906](compiler-warning-level-1-c4906.md)|literal de cadeia de caracteres convertido em 'LPWSTR'|
|[Aviso do compilador (nível 1) C4910](compiler-warning-level-1-c4910.md)|'\<identificador >: 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita|
|[Aviso do compilador (nível 1) C4912](compiler-warning-level-1-c4912.md)|'*atributo*': atributo possui comportamento indefinido em um UDT aninhado|
|[Aviso do compilador (nível 4) C4913](compiler-warning-level-4-c4913.md)|usuário definido pelo operador binário ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado|
|Aviso do compilador (nível 1) C4916|para ter um dispid, '*descrição*': deve ser introduzido por uma interface|
|[Aviso do compilador (nível 1) C4917](compiler-warning-level-1-c4917.md)|'*declarador*': um GUID só pode ser associado uma classe, interface ou namespace|
|[Aviso do compilador (nível 4) C4918](compiler-warning-level-4-c4918.md)|'*caractere*': caractere inválido na lista de otimização do pragma|
|[Aviso do compilador (nível 1) C4920](compiler-warning-level-1-c4920.md)|enumeração enum membro member_1 = value_1 já visto em enumeração de enum como member_2 = value_2|
|Aviso do compilador (nível 3) C4921|'*descrição*': valor do atributo '*atributo*' não deve ser especificado várias vezes|
|[Aviso do compilador (nível 1) C4925](compiler-warning-level-1-c4925.md)|'*método*': método dispinterface não pode ser chamado a partir do script|
|[Aviso do compilador (nível 1) C4926](compiler-warning-level-1-c4926.md)|'*identificador*': símbolo já definido: atributos ignorados|
|[Aviso do compilador (nível 1) C4927](compiler-warning-level-1-c4927.md)|conversão ilegal; mais de uma conversão definida pelo usuário foi aplicada implicitamente|
|[Aviso do compilador (nível 1) C4928](compiler-warning-level-1-c4928.md)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|
|[Aviso do compilador (nível 1) C4929](compiler-warning-level-1-c4929.md)|'*arquivo*': typelibrary contém uma union; ignorando o qualificador 'embedded_idl'|
|[Aviso do compilador (nível 1) C4930](compiler-warning-level-1-c4930.md)|'*protótipo*': função prototipada não chamada (era uma definição de variável se destina?)|
|[Aviso do compilador (nível 4) C4931](compiler-warning-level-4-c4931.md)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|
|[Aviso do compilador (nível 4) C4932](compiler-warning-level-4-c4932.md)|Identifier (*identificador*) e \_identificador (*identificador*) são indistinguíveis|
|Aviso do compilador (nível 1) C4934|'__delegate(multicast)' é preterido, use '\_delegate ' em vez disso|
|[Aviso do compilador (nível 1) C4935](compiler-warning-level-1-c4935.md)|especificador de acesso de assembly modificado de '*acesso*'|
|[Aviso do compilador (nível 1, erro) C4936](compiler-warning-c4936.md)|Este declspec é suportado apenas quando compilado com /clr ou /clr: pure|
|[Aviso do compilador (nível 4) C4937](compiler-warning-level-4-c4937.md)|'*text1*'e'*Texto2*'são indistinguíveis como argumentos para'*diretiva*'|
|[Aviso do compilador (nível 4) C4938](compiler-warning-level-4-c4938.md)|'*var*': Variável de redução de ponto flutuante pode causar resultados inconsistentes sob /fp: strict ou #pragma fenv_access|
|[C4939 de aviso do compilador](compiler-warning-level-1-c4939.md)|#pragma vtordisp é preterido e será removido em uma versão futura do Visual C++|
|[Aviso do compilador (nível 1) C4944](compiler-warning-level-1-c4944.md)|'*símbolo*': não é possível importar símbolo de '*assembly1*': como*símbolo*' já existe no escopo atual|
|[Aviso do compilador (nível 1) C4945](compiler-warning-level-1-c4945.md)|'*símbolo*': não é possível importar símbolo de '*assembly1*': como*símbolo*'já foi importado de outro assembly'*assembly2* '|
|[Aviso do compilador (nível 1) C4946](compiler-warning-level-1-c4946.md)|reinterpret_cast usado entre classes relacionadas: '*class1*'e'*class2*'|
|[Aviso do compilador (nível 1) C4947](compiler-warning-level-1-c4947.md)|'*type_or_member*': marcado como obsoleto|
|[Aviso do compilador (nível 2) C4948](compiler-warning-level-2-c4948.md)|tipo de retorno de '*acessador*' não coincide com o último tipo de parâmetro do setter correspondente|
|[Aviso do compilador (nível 1 e nível 4) C4949](compiler-warning-level-1-and-level-4-c4949.md)|pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'|
|[Aviso do compilador (nível 1, erro) C4950](compiler-warning-c4950.md)|'*type_or_member*': marcado como obsoleto|
|[Aviso do compilador (nível 1) C4951](compiler-warning-level-1-c4951.md)|'*função*' foi editado desde o perfil de dados foram coletados, dados de perfil de função não usados|
|[Aviso do compilador (nível 1) C4952](compiler-warning-level-1-c4952.md)|'*função*': nenhum dado de perfil encontrado no banco de dados do programa '*pgd_file*'|
|[Aviso do compilador (nível 1) C4953](compiler-warning-level-1-c4953.md)|Item embutido '*função*' foi editado desde o perfil de dados foram coletados, dados de perfil não usados|
|C4954 de aviso do compilador|'*função*': não analisado (contém expressão de switch __int64)|
|C4955 de aviso do compilador|'*import2*': importação ignorada; já importado de '*import1*'|
|[Aviso do compilador (nível 1, erro) C4956](compiler-warning-c4956.md)|'*tipo*': esse tipo não é verificável|
|[Aviso do compilador (nível 1, erro) C4957](compiler-warning-c4957.md)|'*cast*': conversão explícita de '*cast_from*'para'*cast_to*' não é verificável|
|[Aviso do compilador (nível 1, erro) C4958](compiler-warning-c4958.md)|'*operação*': aritmética de ponteiro não é verificável|
|[Aviso do compilador (nível 1, erro) C4959](compiler-warning-c4959.md)|não é possível definir o tipo não gerenciado '*tipo*' em /CLR: safe porque o acesso aos seus membros produz código não verificável|
|[Aviso do compilador (nível 4) C4960](compiler-warning-level-4-c4960.md)|'*função*' é muito grande para ser analisado|
|[Aviso do compilador (nível 1) C4961](compiler-warning-c4961.md)|Nenhum dado de perfil foi mesclado em 'arquivo. PGD,' otimizações guiadas por perfil desabilitadas|
|[Aviso do compilador (nível 4) C4962](compiler-warning-c4962.md)|'*função*': Otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente|
|Aviso do compilador (nível 1) C4963|'*descrição*': nenhum dado de perfil encontrado; opções de compilação diferentes foram usadas em compilação instrumentada|
|[Aviso do compilador (nível 1) C4964](compiler-warning-level-1-c4964.md)|Não há opções de otimização foram especificadas; informações de perfil não serão coletadas|
|[Aviso do compilador (nível 1) C4965](compiler-warning-level-1-c4965.md)|box implícito de inteiro 0; Use nullptr ou conversão explícita|
|Aviso do compilador (nível 1) C4966|'*função*' tem a anotação code_seg com o nome de segmento sem suporte, anotação ignorada|
|C4970 de aviso do compilador|construtor delegate: objeto de destino ignorado desde '*tipo*' é estático|
|Aviso do compilador (nível 1) C4971|Ordem de argumentos: \<objeto de destino >, \<função de destino > para construtor delegate é preterida, use \<função de destino >, \<objeto de destino = "" >|
|[Aviso do compilador (nível 1, erro) C4972](compiler-warning-c4972.md)|Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável|
|Aviso do compilador (nível 1) C4973|'*símbolo*': marcados como preteridos|
|Aviso do compilador (nível 1) C4974|'*símbolo*': marcados como preteridos|
|Aviso do compilador (nível 3) C4981|Warbird: função '*função*' marcada como forceinline não embutida porque contém semântica de exceção|
|Aviso do compilador (nível 3) C4985|o nome do símbolo ': atributos não presentes em declaração anterior.|
|[C4986 de aviso do compilador](compiler-warning-c4986.md)|'*declaração*': especificação de exceção não corresponde à declaração anterior|
|Aviso do compilador (nível 4) C4987|extensão não padrão usada: 'throw (...)'|
|Aviso do compilador (nível 4) C4988|'*variável*': variável declarada fora do escopo de classe/função|
|Aviso do compilador (nível 4) C4989|'*tipo*': tipo tem definições conflitantes.|
|Aviso do compilador (nível 3) C4990|Warbird: *mensagem*|
|Aviso do compilador (nível 3) C4991|Warbird: função '*função*' marcada como forceinline não embutida porque o nível de proteção do item embutido é maior que o pai|
|Aviso do compilador (nível 3) C4992|Warbird: função '*função*' marcada como forceinline não embutida porque contém assembly embutido que não pode ser protegido|
|[Aviso do compilador (nível 3) C4995](compiler-warning-level-3-c4995.md)|'*função*': nome foi marcado como #pragma preterido|
|[Aviso do compilador (nível 3) C4996](compiler-warning-level-3-c4996.md)|'*descrição*': *mensagem*|
|[Aviso do compilador (nível 1) C4997](compiler-warning-level-1-c4997.md)|'*classe*': coclass não implementa uma interface COM ou pseudointerface|
|Aviso do compilador (nível 1) C4998|Falha na EXPECTATIVA: *expectativa*(*valor*)|
|[C4999 de aviso do compilador](compiler-warning-level-1-c4999.md)|Aviso desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|
|C5022 de aviso do compilador|'*tipo*': vários construtores de movimento especificados|
|C5023 de aviso do compilador|'*tipo*': vários operadores de atribuição de movimento especificados|
|Aviso do compilador (nível 4) C5024|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|Aviso do compilador (nível 4) C5025|'*tipo*': mover operador de atribuição foi implicitamente definido como excluído|
|Aviso do compilador (nível 1 e nível 4) C5026|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|Aviso do compilador (nível 1 e nível 4) C5027|'*tipo*': mover operador de atribuição foi implicitamente definido como excluído|
|Aviso do compilador (nível 1) C5028|'*name*': Alinhamento especificado na declaração anterior (*número*) não especificado na definição|
|Aviso do compilador (nível 4) C5029|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas|
|Aviso do compilador (nível 3) C5030|atributo '*atributo*' não é reconhecido|
|Aviso do compilador (nível 4) C5031|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado por push em outro arquivo mostrado|
|Aviso do compilador (nível 4) C5032|detectado Warning (push) #pragma com nenhum Warning (POP) #pragma correspondente|
|Aviso do compilador (nível 1) C5033|'*classe de armazenamento*' não é uma classe de armazenamento com suporte|
|Aviso C5034 do compilador|Use intrínseco '*intrínseco*' faz com que a função *função* seja compilada como código de convidado|
|C5035 de aviso do compilador|usar o recurso '*recurso*' faz com que a função *função* seja compilada como código de convidado|
|Aviso do compilador (nível 1) C5036|conversão de ponteiro de função varargs ao compilar com/Hybrid:x86arm64 '*type1*'para'*type2*'|
|Aviso do compilador (erro) C5037|'*função de membro*': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão|
|[Aviso do compilador (nível 4) C5038](c5038.md)|membro de dados '*member1*'será inicializados após o membro de dados'*membro2*'|
|Aviso do compilador (nível 4) C5039|'*função*': ponteiro ou referência a função potencialmente lançada passada para a função C externa em - EHc. Um comportamento indefinido pode ocorrer se essa função gera uma exceção.|
|Aviso do compilador (nível 3) C5040|especificações de exceção dinâmica são válidas somente no c++14 e versões anteriores; tratar como noexcept (False)|
|Aviso do compilador (nível 1) C5041|'*definição*': definição fora de linha para o membro de dados estáticos constexpr não é necessária e foi preterida no c++17|
|Aviso do compilador (nível 3) C5042|'*declaração*': declarações de função no escopo de bloco não podem ser especificado 'inline' em C++ padrão; remova o especificador "embutido"|
|Aviso do compilador (nível 2) C5043|'*especificação*': especificação de exceção não corresponde à declaração anterior|
|Aviso do compilador (nível 4) C5044|Um argumento para a opção de linha de comando *opção* aponta para um caminho '*caminho*' que não existe|
|[C5045 de aviso do compilador](c5045.md)|Compilador inserirá a mitigação de espectro para carga de memória se a opção /Qspectre especificado|
|[Aviso do compilador (nível 2) C5046](c5046.md)|'*função*': Símbolo que envolvem o tipo com vinculação interna não definida|
| Aviso do compilador (nível 1) C5047 | uso de não-padrão \_ \_se\_existe com módulos não tem suporte |
| Aviso do compilador (nível 1) C5048 | Uso da macro '*macroname*' pode resultar em saída não determinística. |
| Aviso do compilador (nível 1) C5049 | '*string*': Inserir um caminho completo pode resultar em saída dependente da máquina |
| Aviso do compilador (nível 1) C5050 | Possíveis ambiente incompatível durante a importação de módulo '*module_name*': *problema* |
| Aviso do compilador (nível 1) C5100 | \_\_VA\_ARGS\_ \_ é reservado para uso em macros variadic |
| Aviso do compilador (nível 1) C5101 | uso da diretiva de pré-processador na lista de argumentos de macro do tipo função é um comportamento indefinido |
| Aviso do compilador (nível 1) C5102 | Ignorando a definição de macro de linha de comando inválida '*valor*' |
| Aviso do compilador (nível 1) C5103 | colando '*token1*'e'*token2*' não resulta em um token válido de pré-processamento |
| Aviso do compilador (nível 1) C5104 | encontrado '*string1*#*string2*'na lista de substituição de macro, você quis dizer'*string1*"" #*string2*'? |
| Aviso do compilador (nível 1) C5105 | expansão de macro produzindo 'defined' possui comportamento indefinido |
| Aviso do compilador (nível 1) C5106 | macro redefinido com nomes de parâmetro diferentes |
| Aviso do compilador (nível 1) C5107 | faltando encerrando '*char*' caractere |

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Avisos do compilador C4000 - C5999](compiler-warnings-c4000-c5999.md)
