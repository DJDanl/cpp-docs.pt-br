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
- C4854
- C4855
- C4856
- C4857
- C4872
- C4880
- C4881
- C4882
- C4916
- C4921
- C4934
- C4954
- C4955
- C4963
- C4966
- C4970
- C4971
- C4973
- C4974
- C4981
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
- C5047
- C5048
- C5049
- C5050
- C5051
- C5052
- C5053
- C5054
- C5055
- C5056
- C5057
- C5058
- C5059
- C5060
- C5061
- C5062
- C5063
- C5100
- C5101
- C5102
- C5103
- C5104
- C5106
- C5107
- C5108
- C5200
- C5201
- C5202
- C5203
- C5204
- C5205
- C5206
- C5207
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
- C4854
- C4855
- C4856
- C4857
- C4872
- C4880
- C4881
- C4882
- C4916
- C4921
- C4934
- C4954
- C4955
- C4963
- C4966
- C4970
- C4971
- C4973
- C4974
- C4981
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
- C5047
- C5048
- C5049
- C5050
- C5051
- C5052
- C5053
- C5054
- C5055
- C5056
- C5057
- C5058
- C5059
- C5060
- C5061
- C5062
- C5063
- C5100
- C5101
- C5102
- C5103
- C5104
- C5106
- C5107
- C5108
- C5200
- C5201
- C5202
- C5203
- C5204
- C5205
- C5206
- C5207
ms.openlocfilehash: 71a924982a1375f378e6935859aae05f0298bd22
ms.sourcegitcommit: 00af3df3331854b23693ee844e5e7c10c8b05a90
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/20/2020
ms.locfileid: "86491395"
---
# <a name="compiler-warnings-c4800-through-c5999"></a>Avisos do Compilador C4800 a C5999

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso que são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

| Aviso | Mensagem |
|--|--|
| [Aviso do compilador (nível 4) C4800](compiler-warning-level-3-c4800.md) | Conversão implícita de '*Type*' para `bool` . Possível perda de informações |
| [Aviso do compilador (nível 1) C4803](compiler-warning-level-1-c4803.md) | '*Method*': o método Raise tem uma classe de armazenamento diferente do do evento, '*Event*' |
| [Aviso do compilador (nível 1) C4804](compiler-warning-level-1-c4804.md) | '*Operation*': uso não seguro do tipo ' `bool` ' na operação |
| [Aviso do compilador (nível 1) C4805](compiler-warning-level-1-c4805.md) | '*Operation*': combinação não segura do tipo '*type1*' e tipo '*type2*' na operação |
| [Aviso do compilador (nível 1) C4806](compiler-warning-level-1-c4806.md) | '*Operation*': operação não segura: nenhum valor do tipo '*type1*' promovido para o tipo '*type2*' pode ser igual à constante especificada |
| [Aviso do compilador (nível 1) C4807](compiler-warning-level-1-c4807.md) | '*Operation*': combinação não segura do tipo '*type1*' e campo de bit assinado do tipo '*type2*' |
| Aviso do compilador (nível 1) C4808 | `case`'*Value*' não é um valor válido para a `switch` condição do tipo ' `bool` ' |
| Aviso do compilador (nível 1) C4809 | `switch`a instrução tem ' `default` ' rótulo redundante; todos os possíveis `case` Rótulos ' ' são fornecidos |
| [Aviso do compilador (nível 1) C4810](compiler-warning-level-1-c4810.md) | valor de `pragma pack(show)` = = n |
| [Aviso do compilador (nível 1) C4811](compiler-warning-level-1-c4811.md) | valor do `pragma conform(forScope, show)`  ==  *valor* |
| [Aviso do compilador (nível 1) C4812](compiler-warning-level-1-c4812.md) | estilo de declaração obsoleto: use '*new_syntax*' em vez disso |
| [Aviso do compilador (nível 1) C4813](compiler-warning-level-1-c4813.md) | '*Function*': uma função Friend de uma classe local deve ter sido declarada anteriormente |
| [Aviso do compilador (nível 4) C4816](compiler-warning-level-4-c4816.md) | '*param*': o parâmetro tem uma matriz de tamanho zero que será truncada (a menos que o objeto seja passado por referência) |
| [Aviso do compilador (nível 1) C4817](compiler-warning-level-1-c4817.md) | '*Member*': uso inválido de '. ' para acessar este membro; compilador substituído por '-> ' |
| [Aviso do compilador (nível 1) C4819](compiler-warning-level-1-c4819.md) | O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo em formato Unicode para evitar a perda de dados |
| [Aviso do compilador (nível 4) C4820](compiler-warning-level-4-c4820.md) | '*bytes*' bytes de preenchimento adicionados após a construção '*member_name*' |
| [Aviso do compilador (nível 1) C4821](compiler-warning-level-1-c4821.md) | Não é possível determinar o tipo de codificação Unicode. Salve o arquivo com a assinatura (BOM) |
| [Aviso do compilador (nível 1) C4822](compiler-warning-level-1-c4822.md) | ' função de membro ': a função membro de classe local não tem um corpo |
| [Aviso do compilador (nível 3) C4823](compiler-warning-level-3-c4823.md) | '*Function*': usa ponteiros de fixação, mas semântica de liberação não está habilitada. Considere usar`/EHa` |
| Aviso do compilador (nível 2) C4826 | A conversão de '*type1*' em '*type2*' é um sinal estendido. Isso pode causar um comportamento de tempo de execução inesperado. |
| Aviso do compilador (nível 3) C4827 | Um método público ' `ToString` ' com 0 parâmetros deve ser marcado como `virtual` e`override` |
| [Aviso do compilador (nível 1) C4829](compiler-warning-level-1-c4829.md) | Parâmetros possivelmente incorretos para funcionar `main` . Considere ' `int main(Platform::Array<Platform::String^>^ argv)` ' |
| [Aviso do compilador (nível 1) C4835](compiler-warning-level-1-c4835.md) | '*Variable*': o inicializador para dados exportados não será executado até que o código gerenciado seja executado pela primeira vez no assembly do host |
| Aviso do compilador (nível 4) C4837 | trigraph detectado: ' `??` *Character*' substituído por '*Character*' |
| [Aviso do compilador (nível 1) C4838](compiler-warning-level-1-c4838.md) | conversão de '*type_1*' em '*type_2*' requer uma conversão de restrição |
| [Aviso do compilador (nível 3) C4839](compiler-warning-level-3-c4839.md) | uso não padrão da classe '*Type*' como um argumento para uma função Variadic |
| [Aviso do compilador (nível 4) C4840](compiler-warning-level-4-c4840.md) | uso não portátil da classe '*Type*' como um argumento para uma função Variadic |
| Aviso do compilador (nível 4) C4841 | extensão não padrão usada: designador de membro composto usado em`offsetof` |
| Aviso do compilador (nível 4) C4842 | o resultado de ' `offsetof` ' aplicado a um tipo usando a herança múltipla não é garantido como consistente entre as versões do compilador |
| Aviso do compilador C4843 | '*type1*': um manipulador de exceção de referência à matriz ou ao tipo de função está inacessível; em vez disso, use '*type2*' |
| Aviso do compilador C4844 | ' `export module` *`module_name`* `;` ' agora é a sintaxe preferida para declarar uma interface de módulo |
| Aviso do compilador (nível 4) C4845 | ' `__declspec(no_init_all)` ' será ignorado se ' `/d1initall[0|1|2|3]` ' não tiver sido especificado na linha de comando |
| Aviso do compilador (nível 4) C4846 | '*Value*' não é um argumento válido para ' `/d1initall` ': sinalizador de linha de comando ignorado |
| Aviso do compilador (nível 4) C4847 | ' `__declspec(no_init_all)` ' só pode ser aplicado a uma função, um tipo de classe ou uma variável local: ignorado |
| Aviso do compilador (nível 1) C4848 | o suporte para o atributo padrão ' `no_unique_address` ' em c++ 17 e anterior é uma extensão de fornecedor |
| Aviso do compilador C4854 | o ponteiro nulo de referência de associação à referência tem comportamento indefinido |
| Aviso do compilador C4855 | a captura implícita de ' `this` ' via ' `[=]` ' foi preterida na ' versão ' |
| Aviso do compilador C4856 | '*Value*' não é um argumento válido para ' `/d1initAll:FillPattern` ' (o valor deve estar entre 0 e 255). Sinalizador de linha de comando ignorado |
| Aviso do compilador C4857 | O modo c++/CLI não oferece suporte a versões C++ mais recentes do que C++ 17; definindo idioma como`/std:c++17` |
| [Aviso do compilador (nível 4) C4866](c4866.md) | o compilador pode não impor a ordem de avaliação da esquerda para a direita para chamar para *operator_name* |
| [Aviso do compilador (erro) C4867](compiler-warning-c4867.md) | '*Function*': chamada de função ausente na lista de argumentos; Use '*Call*' para criar um ponteiro para membro |
| [Aviso do compilador (nível 4) C4868](compiler-warning-c4868.md) | o compilador '_File_(*line_number*) ' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização de chaves |
| Aviso do compilador (nível 2) C4872 | Divisão de ponto flutuante por zero detectada ao compilar o grafo de chamada para o `concurrency::parallel_for_each` em: '*Location*' |
| Aviso do compilador (nível 1) C4880 | conversão de ' const *type_1*' em '*type_2*': a conversão de uma constante de um ponteiro ou referência pode resultar em um comportamento indefinido em uma função de amp restrito |
| Aviso do compilador (nível 4) C4881 | o construtor e/ou o destruidor não serão invocados para a `tile_static` variável '*variable-name*' |
| Aviso do compilador (nível 1) C4882 | a passagem de transmissão functors com operadores de chamada não const para `concurrency::parallel_for_each` é preterida |
| [Aviso do compilador C4900](compiler-warning-level-1-c4900.md) | Incompatibilidade de Il entre '*Tool1*' versão '*versão*' e '*tool2*' versão '*Version2*' |
| [Aviso do compilador (nível 1) C4905](compiler-warning-level-1-c4905.md) | conversão de cadeia de caracteres literal largo para ' `LPSTR` ' |
| [Aviso do compilador (nível 1) C4906](compiler-warning-level-1-c4906.md) | conversão de cadeia de caracteres literal para ' `LPWSTR` ' |
| [Aviso do compilador (nível 1) C4910](compiler-warning-level-1-c4910.md) | ' \<identifier> : ' __declspec (dllexport) ' e ' extern ' são incompatíveis em uma instanciação explícita |
| [Aviso do compilador (nível 1) C4912](compiler-warning-level-1-c4912.md) | '*Attribute*': atributo tem comportamento indefinido em um UDT aninhado |
| [Aviso do compilador (nível 4) C4913](compiler-warning-level-4-c4913.md) | o operador binário definido pelo usuário ' `,` ' existe, mas nenhuma sobrecarga pôde converter todos os operandos, operador binário interno padrão ' `,` ' usado |
| Aviso do compilador (nível 1) C4916 | para ter um `dispid` , '*Description*': deve ser introduzido por uma interface |
| [Aviso do compilador (nível 1) C4917](compiler-warning-level-1-c4917.md) | '*Declarador*': um GUID só pode ser associado a uma classe, interface ou namespace |
| [Aviso do compilador (nível 4) C4918](compiler-warning-level-4-c4918.md) | '*Character*': caractere inválido na lista de otimização de pragma |
| [Aviso do compilador (nível 1) C4920](compiler-warning-level-1-c4920.md) | enum enum *-Name* member *member_1* = *value_1* já visto em enum *enum-name* as *member_2* = *value_2* |
| Aviso do compilador (nível 3) C4921 | '*Description*': o valor de atributo '*Attribute*' não deve ser especificado em várias vezes |
| [Aviso do compilador (nível 1) C4925](compiler-warning-level-1-c4925.md) | '*Method*': método de dispinterface não pode ser chamado a partir de script |
| [Aviso do compilador (nível 1) C4926](compiler-warning-level-1-c4926.md) | '*Identifier*': símbolo já definido: atributos ignorados |
| [Aviso do compilador (nível 1) C4927](compiler-warning-level-1-c4927.md) | conversão inválida; mais de uma conversão definida pelo usuário foi aplicada implicitamente |
| [Aviso do compilador (nível 1) C4928](compiler-warning-level-1-c4928.md) | inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada |
| [Aviso do compilador (nível 1) C4929](compiler-warning-level-1-c4929.md) | '*File*': biblioteca contém uma Union; ignorando o qualificador ' embedded_idl ' |
| [Aviso do compilador (nível 1) C4930](compiler-warning-level-1-c4930.md) | '*Prototype*': função de protótipo não chamada (era uma definição de variável pretendida?) |
| [Aviso do compilador (nível 4) C4931](compiler-warning-level-4-c4931.md) | Estamos supondo que a biblioteca de tipos foi criada para ponteiros de *número*de bits |
| [Aviso do compilador (nível 4) C4932](compiler-warning-level-4-c4932.md) | `__identifier(`*identificador* `)` do e o `__identifier(` *identificador* `)` são indistinguíveis |
| Aviso do compilador (nível 1) C4934 | ' `__delegate(multicast)` ' foi preterido, use ' `__delegate` ' em vez disso |
| [Aviso do compilador (nível 1) C4935](compiler-warning-level-1-c4935.md) | especificador de acesso de assembly modificado de '*acesso*' |
| [Aviso do compilador (nível 1, erro) C4936](compiler-warning-c4936.md) | Este __declspec só tem suporte quando compilado com `/clr` ou`/clr:pure` |
| [Aviso do compilador (nível 4) C4937](compiler-warning-level-4-c4937.md) | '*text1*' e '*Texto2*' são indistinguíveis como argumentos para '*diretiva*' |
| [Aviso do compilador (nível 4) C4938](compiler-warning-level-4-c4938.md) | '*var*': variável de redução de ponto flutuante pode causar resultados inconsistentes em `/fp:strict` ou`#pragma fenv_access` |
| [Aviso do compilador C4939](compiler-warning-level-1-c4939.md) | #pragma vtordisp foi preterida e será removida em uma versão futura do Visual C++ |
| [Aviso do compilador (nível 1) C4944](compiler-warning-level-1-c4944.md) | '*Symbol*': não é possível importar o símbolo de '*Assembly1*': já existe um '*Symbol*' no escopo atual |
| [Aviso do compilador (nível 1) C4945](compiler-warning-level-1-c4945.md) | '*Symbol*': não é possível importar o símbolo de '*Assembly1*': como '*Symbol*' já foi importado de outro assembly '*Assembly2*' |
| [Aviso do compilador (nível 1) C4946](compiler-warning-level-1-c4946.md) | `reinterpret_cast`usado entre as classes relacionadas: '*Class1*' e '*class2*' |
| [Aviso do compilador (nível 1) C4947](compiler-warning-level-1-c4947.md) | '*Type_or_Member*': marcado como obsoleto |
| [Aviso do compilador (nível 2) C4948](compiler-warning-level-2-c4948.md) | o tipo de retorno de '*acessador*' não corresponde ao último tipo de parâmetro do setter correspondente |
| [Aviso do compilador (níveis 1 e 4) C4949](compiler-warning-level-1-and-level-4-c4949.md) | pragmas ' `managed` ' e ' `unmanaged` ' são significativos somente quando compilados com ' `/clr[:option]` ' |
| [Aviso do compilador (nível 1, erro) C4950](compiler-warning-c4950.md) | '*Type_or_Member*': marcado como obsoleto |
| [Aviso do compilador (nível 1) C4951](compiler-warning-level-1-c4951.md) | '*Function*' foi editado desde que os dados de perfil foram coletados, dados de perfil de função não usados |
| [Aviso do compilador (nível 1) C4952](compiler-warning-level-1-c4952.md) | '*Function*': nenhum dado de perfil encontrado no banco de dados do programa '*PGD-File*' |
| [Aviso do compilador (nível 1) C4953](compiler-warning-level-1-c4953.md) | '*Function*' embutido foi editado desde que os dados do perfil foram coletados, dados de perfil não usados |
| Aviso do compilador C4954 | '*Function*': não foi criado um perfil (contém a `__int64` expressão switch) |
| Aviso do compilador C4955 | '*import2*': importação ignorada; Já importado de '*import1*' |
| [Aviso do compilador (nível 1, erro) C4956](compiler-warning-c4956.md) | '*Type*': este tipo não é verificável |
| [Aviso do compilador (nível 1, erro) C4957](compiler-warning-c4957.md) | '*Cast*': conversão explícita de '*cast_from*' em '*cast_to*' não é verificável |
| [Aviso do compilador (nível 1, erro) C4958](compiler-warning-c4958.md) | '*Operation*': aritmética de ponteiro não é verificável |
| [Aviso do compilador (nível 1, erro) C4959](compiler-warning-c4959.md) | Não é possível definir o tipo não gerenciado '*Type*' no `/clr:safe` porque o acesso aos seus membros produz código não verificável |
| [Aviso do compilador (nível 4) C4960](compiler-warning-level-4-c4960.md) | '*Function*' é muito grande para ser criado |
| [Aviso do compilador (nível 1) C4961](compiler-warning-c4961.md) | Nenhum dado de perfil foi mesclado em '*PGD-File*', otimizações guiadas por perfil desabilitadas |
| [Aviso do compilador (nível 4) C4962](compiler-warning-c4962.md) | '*Function*': otimizações guiadas por perfil desabilitadas porque otimizações fizeram com que os dados de perfil se tornem inconsistentes |
| Aviso do compilador (nível 1) C4963 | '*Description*': nenhum dado de perfil encontrado; opções de compilador diferentes foram usadas na compilação instrumentada |
| [Aviso do compilador (nível 1) C4964](compiler-warning-level-1-c4964.md) | Nenhuma opção de otimização foi especificada; as informações de perfil não serão coletadas |
| [Aviso do compilador (nível 1) C4965](compiler-warning-level-1-c4965.md) | caixa implícita de inteiro 0; usar nullptr ou conversão explícita |
| Aviso do compilador (nível 1) C4966 | '*Function*' tem `__code_seg` anotação com nome de segmento sem suporte, anotação ignorada |
| Aviso do compilador C4970 | Construtor delegate: objeto de destino ignorado porque '*Type*' é estático |
| Aviso do compilador (nível 1) C4971 | Ordem de argumento: \<target object> , \<target function> para Construtor delegate é preterido, use \<target function> ,\<target object=""> |
| [Aviso do compilador (nível 1, erro) C4972](compiler-warning-c4972.md) | Modificar diretamente ou tratar o resultado de uma operação unbox como um lvalue não é verificável |
| Aviso do compilador (nível 1) C4973 | '*Symbol*': marcado como preterido |
| Aviso do compilador (nível 1) C4974 | '*Symbol*': marcado como preterido |
| Aviso do compilador (nível 3) C4981 | Warbird: função '*Function*' marcada como __forceinline não embutida porque contém semântica de exceção |
| [Aviso do compilador C4984](compiler-warning-c4984.md) | ' `if constexpr` ' é uma extensão de linguagem c++ 17 |
| [Aviso do compilador (nível 4) C4985](compiler-warning-level-4-c4985.md) | '*symbol_name*': atributos não presentes na declaração anterior. |
| [Aviso do compilador C4986](compiler-warning-c4986.md) | '*declaração*': a especificação de exceção não corresponde à declaração anterior |
| Aviso do compilador (nível 4) C4987 | extensão não padrão usada: ' `throw (...)` ' |
| Aviso do compilador (nível 4) C4988 | '*Variable*': variável declarada fora do escopo de classe/função |
| Aviso do compilador (nível 4) C4989 | '*Type*': o tipo tem definições conflitantes. |
| Aviso do compilador (nível 3) C4990 | Warbird: *mensagem* |
| Aviso do compilador (nível 3) C4991 | Warbird: função '*Function*' marcada como `__forceinline` não embutida porque o nível de proteção do embutido é maior que o pai |
| Aviso do compilador (nível 3) C4992 | Warbird: função '*Function-Name*' marcada como `__forceinline` não embutida porque contém assembly embutido que não pode ser protegido |
| [Aviso do compilador (nível 3) C4995](compiler-warning-level-3-c4995.md) | '*Function*': o nome foi marcado como #pragma preterido |
| [Aviso do compilador (nível 3) C4996](compiler-warning-level-3-c4996.md) | '*preterido-declaração*': *reprovação-mensagem* (ou "foi declarado preterido") |
| [Aviso do compilador (nível 1) C4997](compiler-warning-level-1-c4997.md) | "*Class*": coclass não implementa uma interface com ou pseudo-interface |
| Aviso do compilador (nível 1) C4998 | FALHA na expectativa: *expectativa*(*valor*) |
| [Aviso do compilador C4999](compiler-warning-level-1-c4999.md) | AVISO desconhecido escolha o comando de suporte técnico no menu Visual C++ ajuda ou abra o arquivo de ajuda do suporte técnico para obter mais informações |
| Aviso do compilador C5022 | '*Type*': vários construtores de movimentação especificados |
| Aviso do compilador C5023 | '*Type*': vários operadores de atribuição de movimento especificados |
| Aviso do compilador (nível 4) C5024 | '*Type*': o construtor de movimentação foi implicitamente definido como excluído |
| Aviso do compilador (nível 4) C5025 | '*Type*': o operador de atribuição de movimento foi implicitamente definido como excluído |
| Aviso do compilador (nível 1 e nível 4) C5026 | '*Type*': o construtor de movimentação foi implicitamente definido como excluído |
| Aviso do compilador (nível 1 e nível 4) C5027 | '*Type*': o operador de atribuição de movimento foi implicitamente definido como excluído |
| Aviso do compilador (nível 1) C5028 | '*Name*': alinhamento especificado em declaração anterior (*Number*) não especificado na definição |
| Aviso do compilador (nível 4) C5029 | extensão não padrão usada: os atributos de alinhamento em C++ se aplicam somente a variáveis, membros de dados e tipos de marca |
| Aviso do compilador (nível 3) C5030 | o atributo '*Attribute-Name*' não é reconhecido |
| Aviso do compilador (nível 4) C5031 | `#pragma warning(pop)`: provável incompatibilidade, estado de aviso de pop-up enviado por push em arquivo diferente |
| Aviso do compilador (nível 4) C5032 | detectado sem `#pragma warning(push)` nenhum correspondente`#pragma warning(pop)` |
| Aviso do compilador (nível 1) C5033 | '*Storage-Class*' não é mais uma classe de armazenamento com suporte |
| Aviso do compilador C5034 | o uso de intrínseco '*intrínseco*' faz com que o *nome da função* de função seja compilado como código de convidado |
| Aviso do compilador C5035 | o uso do recurso '*Feature*' faz com que o *nome da função* de função seja compilado como código de convidado |
| Aviso do compilador (nível 1) C5036 | conversão de ponteiro de função varargs ao compilar com `/hybrid:x86arm64` '*type1*' para '*type2*' |
| Aviso do compilador (erro) C5037 | '*Member-function*': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão |
| [Aviso do compilador (nível 4) C5038](c5038.md) | o membro de dados '*member1*' será inicializado após o membro de dados '*membro2*' |
| Aviso do compilador (nível 4) C5039 | '*Function*': ponteiro ou referência para gerar potencialmente a função passada para a `extern C` função em `-EHc` . O comportamento indefinido poderá ocorrer se essa função lançar uma exceção. |
| Aviso do compilador (nível 3) C5040 | as especificações de exceção dinâmicas são válidas somente no C++ 14 e versões anteriores; tratando como noexcept (false) |
| Aviso do compilador (nível 1) C5041 | '*Definition*': definição fora de linha para membro de dados estáticos de constexpr não é necessária e é preterida em c++ 17 |
| Aviso do compilador (nível 3) C5042 | '*declaração*': declarações de função em escopo de bloco não podem ser especificadas ' inline ' no C++ padrão; remover especificador ' inline ' |
| Aviso do compilador (nível 2) C5043 | '*especificação*': a especificação de exceção não corresponde à declaração anterior |
| Aviso do compilador (nível 4) C5044 | Um argumento para opção de linha de comando *-Name* aponta para um caminho '*Path-Name*' que não existe |
| [Aviso do compilador C5045](c5045.md) | O compilador irá inserir a mitigação Spectre para a carga de memória se a opção/Qspectre for especificada |
| [Aviso do compilador (nível 2) C5046](c5046.md) | '*Function*': símbolo que envolve o tipo com vínculo interno não definido |
| Aviso do compilador (nível 1) C5047 | Não há suporte para o uso de não padrão `__if_exists` com módulos |
| Aviso do compilador (nível 1) C5048 | O uso da macro '*macroname*' pode resultar em uma saída não determinística |
| Aviso do compilador (nível 1) C5049 | '*String*': a inserção de um caminho completo pode resultar em saída dependente de computador |
| Aviso do compilador (nível 1) C5050 | Possível ambiente incompatível ao importar o módulo '*module_name*': *problema* |
| Aviso do compilador C5051 | o atributo ' attribute-Name ' requer pelo menos ' nível padrão '; aceita |
| Aviso do compilador C5052 | A palavra-chave ' keyword-Name ' foi introduzida em C++ \<version> e requer o uso da opção de linha de comando ' Option-Name ' |
| Aviso do compilador C5053 | o suporte para ' `explicit(<expr>)` ' em c++ 17 e anterior é uma extensão de fornecedor |
| Aviso do compilador C5054 | operador ' operator-Name ': preterido entre enumerações de tipos diferentes |
| Aviso do compilador C5055 | operador ' operator-Name ': preterido entre enumerações e tipos de ponto flutuante |
| Aviso do compilador C5056 | Operator ' operator-Name ': preterido para tipos de matriz |
| Aviso do compilador C5057 | a referência de unidade de cabeçalho para ' name ' já existe.  Ignorando a unidade de cabeçalho ' Header-Name ' |
| Aviso do compilador C5058 | erro do sistema de arquivos: não é possível encontrar o arquivo de cabeçalho ' File-Name ' para a unidade de cabeçalho ' Unit-Name ' |
| Aviso do compilador C5059 | verificações de tempo de execução e endereço não tem suporte no momento-desabilitar verificações de tempo de execução |
| Aviso do compilador C5060 | `/Qpar`e o resolvedor de endereço não tem suporte no momento-desabilitando a paralelização automática |
| Aviso do compilador C5061 | o uso de um operador de vírgula como uma expressão de subscrito foi preterido |
| Aviso do compilador C5062 | Não há mais suporte para a inicialização de lista direta de enumeração entre ' Type-1 ' e ' type-2 ' |
| Aviso do compilador C5063 | ' `std::is_constant_evaluated` ' sempre é avaliado como verdadeiro em expressões avaliadas por constante de manifesto |
| Aviso do compilador (nível 1) C5100 | `__VA_ARGS__`é reservado para uso em Macros Variadic |
| Aviso do compilador (nível 1) C5101 | o uso da diretiva de pré-processador em uma lista de argumentos de macro semelhante a função é um comportamento indefinido |
| Aviso do compilador (nível 1) C5102 | ignorando definição de macro de linha de comando inválida '*Value*' |
| Aviso do compilador (nível 1) C5103 | colar '*token1*' e '*token2*' não resulta em um token de pré-processamento válido |
| Aviso do compilador (nível 1) C5104 | encontrado '*string1* `#` *string2*' na lista de substituição de macro, você quis dizer '*seqüência1* `""#` *string2*'? |
| [Aviso do compilador (nível 1) C5105](c5105.md) | a expansão de macro produzindo ' defined ' tem comportamento indefinido |
| Aviso do compilador (nível 1) C5106 | macro redefinida com nomes de parâmetros diferentes |
| Aviso do compilador (nível 1) C5107 | caractere '*Char*' de terminação ausente |
| Aviso do compilador C5108 | `__VA_OPT__`é reservado para uso em Macros Variadic |
| Aviso do compilador C5200 | o recurso ' feature-Name ' requer o sinalizador de compilador ' Option-Name ' |
| Aviso do compilador C5201 | uma declaração de módulo só pode aparecer no início de uma unidade de tradução, a menos que um fragmento de módulo global seja usado |
| Aviso do compilador C5202 | um fragmento de módulo global só pode conter diretivas de pré-processador |
| Aviso do compilador C5203 | um nome de Declarador entre parênteses depois de ' Explicit ' será considerado um especificador explícito em C++ 20 |
| Aviso do compilador C5204 | ' Type-Name ': classe tem funções virtuais, mas seu destruidor trivial não é virtual; as instâncias de objetos derivados desta classe podem não ser destruídas corretamente |
| Aviso do compilador C5205 | a exclusão de uma classe abstrata ' Type-Name ' que tem um destruidor não virtual resulta em um comportamento indefinido |
| Aviso do compilador C5206 | tipos de retorno deduzidos para corrotinas é uma extensão não padrão |
| Aviso do compilador C5207 | o requisito simples declara a validade da expressão ' `e->id` '. Você quis dizer ' `{ e } -> id` '? Você pode suprimir o aviso usando ' `{ e->id }` ' |
| [Aviso do compilador (nível 1) C5208](c5208.md) | a classe sem nome usada no `typedef` nome não pode declarar membros diferentes de membros de dados não estáticos, enumerações de membros ou classes de membro |

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas de compilação e do compilador C/C++](../compiler-errors-1/c-cpp-build-errors.md) \
[Avisos do compilador C4000 a C5999](compiler-warnings-c4000-c5999.md)
