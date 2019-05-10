---
title: Erros do compilador C3200 a C3299
ms.date: 04/21/2019
f1_keywords:
- C3220
- C3221
- C3245
- C3249
- C3250
- C3256
- C3257
- C3258
- C3259
- C3260
- C3261
- C3263
- C3267
- C3281
- C3294
helpviewer_keywords:
- C3220
- C3221
- C3245
- C3249
- C3250
- C3256
- C3257
- C3258
- C3259
- C3260
- C3261
- C3263
- C3267
- C3281
- C3294
ms.assetid: 6b3104f6-63bc-4823-b6f3-b8a16be4b87f
ms.openlocfilehash: 6965fcde5f7cc93464593e83f787d0a5838398dd
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64856962"
---
# <a name="compiler-errors-c3200-through-c3299"></a>Erros do compilador C3200 a C3299

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C3200](compiler-error-c3200.md)|'*tipo*': argumento de template inválido para parâmetro de modelo '*parâmetro*', esperado um modelo de classe|
|[Erro do compilador C3201](compiler-error-c3201.md)|a lista de parâmetros de modelo para o modelo de classe '*modelo*'não coincide com a lista de parâmetros de modelo para o parâmetro de modelo'*parâmetro*'|
|[Erro do compilador C3202](compiler-error-c3202.md)|'*identificador*': padrão inválido argumento, esperado um modelo de classe|
|[Erro do compilador C3203](compiler-error-c3203.md)|'*identificador*': classe não especializada modelo/genérico não pode ser usado como um argumento de modelo/genérico para o parâmetro de modelo/genérico '*parâmetro*', esperado um tipo real|
|[Erro do compilador C3204](compiler-error-c3204.md)|'*função*' não pode ser chamado de dentro de um bloco catch|
|[Erro do compilador C3205](compiler-error-c3205.md)|lista de argumentos para o parâmetro de modelo '*identificador*' está ausente|
|[Erro do compilador C3206](compiler-error-c3206.md)|'*função*': argumento de modelo/genérico inválido para '*modelo*', faltando lista de argumentos de modelo/genérico no modelo de classe/genérico '*tipo*'|
|[Erro do compilador C3207](compiler-error-c3207.md)|'*função*': argumento de template inválido para '*parâmetro*', o modelo de classe esperado|
|[Erro do compilador C3208](compiler-error-c3208.md)|'*função*': lista de parâmetros de template para template de classe '*modelo*'não coincide com lista de parâmetros de template para parâmetro de modelo'*parâmetro*'|
|[Erro do compilador C3209](compiler-error-c3209.md)|'*tipo*': classe genérica deve ser uma classe gerenciada/WinRT|
|[Erro do compilador C3210](compiler-error-c3210.md)|'*identificador*': declaração de acesso só pode ser aplicada a um membro de classe base|
|[Erro do compilador C3211](compiler-error-c3211.md)|'*função*': especialização explícita está usando a sintaxe de especialização parcial, use o modelo <> em vez disso|
|[Erro do compilador C3212](compiler-error-c3212.md)|'*função*': uma especialização explícita de um membro de modelo deve ser um membro de uma especialização explícita|
|[Erro do compilador C3213](compiler-error-c3213.md)|classe de base*classe*'é menos acessível que'*derived_class*'|
|[Erro do compilador C3214](compiler-error-c3214.md)|'*argumento*': argumento de tipo inválido para parâmetro de generic '*parâmetro*'de genérico'*tipo*', não atende à restrição '*restrição*'|
|[Erro do compilador C3215](compiler-error-c3215.md)|'*constraint1*': parâmetro de tipo genérico já restringido por '*restrição2*'|
|[Erro do compilador C3216](compiler-error-c3216.md)|restrição deve ser um parâmetro genérico, não '*tipo*'|
|[Erro do compilador C3217](compiler-error-c3217.md)|'*parâmetro*': parâmetro genérico não pode ser restringido nesta declaração|
|[Erro do compilador C3218](compiler-error-c3218.md)|'*tipo*': não é permitido como uma restrição de tipo|
|[Erro do compilador C3219](compiler-error-c3219.md)|'*parâmetro*': parâmetro genérico não pode ser restrito por várias não interfaces: '*tipo*'|
|Erro do compilador C3220|'*interface*': interface não pode possuir progid|
|Erro do compilador C3221|'*membro*': vários 'default' e 'casos' atributos não são permitidos em um membro|
|[Erro do compilador C3222](compiler-error-c3222.md)|'*função*': não é possível declarar argumentos padrão para o membro de um tipo gerenciado/WinRT ou funções genéricas|
|[Erro do compilador C3223](compiler-error-c3223.md)|'*propriedade*': não é possível aplicar 'typeid' a uma propriedade|
|[Erro do compilador C3224](compiler-error-c3224.md)|'*tipo*': leva nenhuma classe de generic sobrecarregada*número*' argumentos de tipo genérico|
|[Erro do compilador C3225](compiler-error-c3225.md)|argumento de tipo genérico para '*argumento*'não pode ser'*tipo*', ele deve ser um tipo de valor ou um identificador para um tipo de referência|
|[Erro do compilador C3226](compiler-error-c3226.md)|Uma declaração de modelo não é permitida dentro de uma declaração genérica|
|[Erro do compilador C3227](compiler-error-c3227.md)|'*tipo*': não é possível usar '*operador*' para alocar um tipo genérico|
|[Erro do compilador C3228](compiler-error-c3228.md)|'*função*': argumento de tipo genérico para '*argumento*'não pode ser'*tipo*', ele deve ser um tipo de valor ou tipo de identificador|
|[Erro do compilador C3229](compiler-error-c3229.md)|'*tipo*': indireções em um parâmetro de tipo genérico não são permitidas.|
|[Erro do compilador C3230](compiler-error-c3230.md)|'*função*': argumento de tipo de modelo para '*argumento*' não pode conter um parâmetro de tipo genérico: '*tipo*'|
|[Erro do compilador C3231](compiler-error-c3231.md)|'*tipo*': argumento de tipo de modelo não é possível usar um parâmetro de tipo genérico|
|[Erro do compilador C3232](compiler-error-c3232.md)|'*parâmetro*': um parâmetro de tipo genérico não pode ser usado em um nome qualificado|
|[Erro do compilador C3233](compiler-error-c3233.md)|'*tipo*': parâmetro de tipo genérico já restringido|
|[Erro do compilador C3234](compiler-error-c3234.md)|uma classe genérica não deve derivar de um parâmetro de tipo genérico|
|[Erro do compilador C3235](compiler-error-c3235.md)|'*especialização*': especialização explícita ou parcial de uma classe genérica não é permitida|
|[Erro do compilador C3236](compiler-error-c3236.md)|instanciação explícita de um genérico não é permitida|
|[Erro do compilador C3237](compiler-error-c3237.md)|'*classe*': uma classe genérica não pode ser um atributo personalizado|
|[Erro do compilador C3238](compiler-error-c3238.md)|'*tipo*': um tipo com este nome já foi encaminhado para o assembly '*assembly*'|
|[Erro do compilador C3239](compiler-error-c3239.md)|'*tipo*': ponteiro para ponteiro interior/pin não é permitido pelo common language runtime|
|[Erro do compilador C3240](compiler-error-c3240.md)|'*identificador*': deve ser uma função de membro abstract não sobrecarregada de '*tipo*'|
|[Erro do compilador C3241](compiler-error-c3241.md)|'*membro*': esse método não foi introduzido por '*interface*'|
|[Erro do compilador C3242](compiler-error-c3242.md)|'*função*': você pode substituir apenas explicitamente funções virtuais|
|[Erro do compilador C3243](compiler-error-c3243.md)|Nenhuma das funções sobrecarregadas foi introduzida por '*interface*'|
|[Erro do compilador C3244](compiler-error-c3244.md)|'*membro*': esse método foi introduzido por '*interface1*'não por'*interface2*'|
|Erro do compilador C3245|'*função*': uso de um modelo de variável requer a lista de argumentos de modelo|
|[Erro do compilador C3246](compiler-error-c3246.md)|'*classe*': não pode herdar de '*base_class*'pois ele foi declarado como'*herança*'|
|[Erro do compilador C3247](compiler-error-c3247.md)|'*coclass*': uma coclass não pode herdar de outra coclass*base_class*'|
|[Erro do compilador C3248](compiler-error-c3248.md)|Obsoleto. '*função*': função declarada como 'sealed' não pode ser substituída por '*função*'|
|Erro do compilador C3249|instrução ilegal ou subexpressão para a função 'constexpr'|
|Erro do compilador C3250|'*declaração*': declaração não é permitida no corpo de função 'constexpr'|
|[Erro do compilador C3251](compiler-error-c3251.md)|não é possível invocar o método da classe base em uma instância de tipo de valor|
|[Erro do compilador C3252](compiler-error-c3252.md)|'*função*': não é possível reduzir acessibilidade de um método virtual em um tipo gerenciado/WinRT|
|[Erro do compilador C3253](compiler-error-c3253.md)|'*função*': erro com a substituição explícita|
|[Erro do compilador C3254](compiler-error-c3254.md)|'*função*': classe contém substituição explícita '*função*', mas não deriva de uma interface que contém a declaração da função|
|[Erro do compilador C3255](compiler-error-c3255.md)|'*tipo*': não é possível alocar dinamicamente este objeto de tipo value em heap nativo|
|Erro do compilador C3256|'*função*': uso da variável não produz uma expressão constante|
|Erro do compilador C3257|Obsoleto.|
|Erro do compilador C3258|Obsoleto.|
|Erro do compilador C3259|funções 'constexpr' só podem ter uma instrução de retorno|
|Erro do compilador C3260|'*token*': Ignorando token inesperado antes do corpo lambda|
|Erro do compilador C3261|uma função que retorna uma matriz gerenciada/WinRT deve possuir colchetes de matriz no final da declaração: '*identificador*(...) []'|
|[Erro do compilador C3262](compiler-error-c3262.md)|indexação de array inválida: *número* dimensão (ões) especificada para *número*-dimensional '*tipo*'|
|Erro do compilador C3263|Obsoleto.|
|[Erro do compilador C3264](compiler-error-c3264.md)|'*identificador*': um construtor de classe não pode ter um tipo de retorno|
|[Erro do compilador C3265](compiler-error-c3265.md)|não é possível declarar um gerenciado '*managed_construct*'em um unmanaged'*unmanaged_construct*'|
|[Erro do compilador C3266](compiler-error-c3266.md)|'*função*': um construtor de classe deve ter uma lista de parâmetros 'void'|
|Erro do compilador C3267|Obsoleto.|
|[Erro do compilador C3268](compiler-error-c3268.md)|'*função*': uma função genérica ou uma função de membro de uma classe genérica não pode ter uma lista de parâmetros variáveis|
|[Erro do compilador C3269](compiler-error-c3269.md)|'*função*': uma função de membro de um tipo gerenciado/WinRT não pode ser declarada com '...'|
|[Erro do compilador C3270](compiler-error-c3270.md)|'*campo*': o atributo FieldOffset só pode ser usado no contexto de StructLayout(LayoutKind::Explicit)|
|[Erro do compilador C3271](compiler-error-c3271.md)|'*campo*': valor inválido '*número*' para o atributo FieldOffset|
|[Erro do compilador C3272](compiler-error-c3272.md)|'*símbolo*': símbolo requer FieldOffset, porque ele é um membro de classe/struct *type_name* definidos com StructLayout(LayoutKind::Explicit)|
|[Erro do compilador C3273](compiler-error-c3273.md)|'*palavra-chave*': não é permitido no bloco try de C++|
|[Erro do compilador C3274](compiler-error-c3274.md)|Por fim /&#95;&#95;, por fim, sem try correspondente|
|[Erro do compilador C3275](compiler-error-c3275.md)|'*identificador*': não é possível usar este símbolo sem qualificador|
|[Erro do compilador C3276](compiler-error-c3276.md)|'*palavra-chave*': ignorar finalmente /&#95;&#95;, por fim, bloco tem um comportamento indefinido durante manipulação de encerramento|
|[Erro do compilador C3277](compiler-error-c3277.md)|não é possível definir uma enumeração não gerenciada '*enumeração*'inside gerenciado'*tipo*'|
|[Erro do compilador C3278](compiler-error-c3278.md)|direcionar a chamada de interface ou método puro '*função*' falhará em tempo de execução|
|[Erro do compilador C3279](compiler-error-c3279.md)|especializações parciais e explícitas, bem como instanciações explícitas de modelos de classe declaradas no namespace cli não são permitidas|
|[Erro do compilador C3280](compiler-error-c3280.md)|'*função*': uma função de membro de um tipo gerenciado não pode ser compilada como uma função não gerenciada|
|Erro do compilador C3281|'*função*': operador global não pode ter um tipo gerenciado/WinRT '*tipo*' na assinatura|
|[Erro do compilador C3282](compiler-error-c3282.md)|listas de parâmetro genérico só podem aparecer em funções, estruturas ou classes do WinRT/gerenciado|
|[Erro do compilador C3283](compiler-error-c3283.md)|'*interface*': uma interface não pode ter um construtor de instância|
|[Erro do compilador C3284](compiler-error-c3284.md)|as restrições de parâmetro genérico '*parâmetro*'da função'*declarator*'deve corresponder as restrições de parâmetro genérico'*parâmetro*'da função'*declarador*'|
|[Erro do compilador C3285](compiler-error-c3285.md)|para cada instrução não pode operar em variáveis do tipo '*tipo*'|
|[Erro do compilador C3286](compiler-error-c3286.md)|'*especificador*': uma variável de iteração não pode ter qualquer especificadores de classe de armazenamento|
|[Erro do compilador C3287](compiler-error-c3287.md)|o tipo '*tipo*' (tipo de retorno de GetEnumerator) deve ter uma função de membro MoveNext pública adequada e a propriedade Current pública|
|[Erro do compilador C3288](compiler-error-c3288.md)|'*tipo*': cancelamento inválido de um tipo de identificador|
|[Erro do compilador C3289](compiler-error-c3289.md)|'*identificador*': uma propriedade trivial não pode ser indexada.|
|[Erro do compilador C3290](compiler-error-c3290.md)|'*tipo*': uma propriedade trivial não pode ter o tipo de referência|
|[Erro do compilador C3291](compiler-error-c3291.md)|'default': não pode ser o nome de uma propriedade trivial|
|[Erro do compilador C3292](compiler-error-c3292.md)|o namespace cli não pode ser reaberto|
|[Erro do compilador C3293](compiler-error-c3293.md)|'*identificador*': use 'default' para acessar a propriedade padrão (indexador) para a classe*classe*'|
|Erro do compilador C3294|Obsoleto.|
|[Erro do compilador C3295](compiler-error-c3295.md)|' #pragma *especificador*' só pode ser usada em global ou escopo de namespace|
|[Erro do compilador C3296](compiler-error-c3296.md)|'*identificador*': já existe uma propriedade com esse nome|
|[Erro do compilador C3297](compiler-error-c3297.md)|' *restrição2*': não é possível usar ' *constraint1*' como uma restrição porque ' *constraint1*' tem a restrição de valor|
|[Erro do compilador C3298](compiler-error-c3298.md)|' *constraint1*': não é possível usar ' *restrição2*' como uma restrição porque ' *restrição2*' possui a restrição ref e ' *constraint1*' tem a restrição de valor|
|[Erro do compilador C3299](compiler-error-c3299.md)|' *função*': não é possível especificar restrições, elas são herdadas do método base|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
