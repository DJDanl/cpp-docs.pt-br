---
title: '&lt;funcional&gt;'
ms.date: 02/21/2019
f1_keywords:
- <functional>
- functional/std::<functional>
- std::<functional>
helpviewer_keywords:
- functors
- functional header
ms.assetid: 7dd463e8-a29f-49bc-aedd-8fa53b54bfbc
ms.openlocfilehash: 9f1eaf69f49a449877b9013dca62ab49cb8a5b48
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838042"
---
# <a name="ltfunctionalgt"></a>&lt;funcional&gt;

Define as funções de biblioteca padrão do C++ que ajudam a construir *objetos de função*, também conhecidos como *transmissão functors*e seus vinculadores. Um objeto de função é um objeto de um tipo que define `operator()`. Um objeto de função pode ser um ponteiro de função, mas normalmente o objeto é usado para armazenar informações adicionais que possam ser acessadas durante uma chamada de função.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<functional>

**Namespace:** std

## <a name="remarks"></a>Comentários

Os algoritmos exigem dois tipos de objetos de função: *unário* e *binário*. Objetos de função unários exigem um argumento e objetos de função binários requerem dois argumentos. Um objeto de função e ponteiros de função podem ser passados como um predicado para um algoritmo, mas objetos de função também são adaptáveis e aumentam o escopo, a flexibilidade e a eficiência da Biblioteca Padrão C++. Se, por exemplo, um valor precisasse ser associado a uma função antes de ser passado para um algoritmo, um ponteiro de função não poderia ser usado. Adaptadores de função convertem ponteiros de função em objetos de função adaptáveis que podem ser associados a um valor. O cabeçalho \<functional> também contém adaptadores de função de membro que permitem que as funções de membro sejam chamadas como objetos de função adaptáveis. Funções são adaptáveis se tiverem declarações de tipo aninhado especificando seus tipos de retorno e argumento. Objetos de função e seus adaptadores permitem que a Biblioteca Padrão C++ atualize aplicativos existentes e ajudam a integrar a biblioteca ao ambiente de programação do C++.

A implementação dos objetos de função no \<functional> inclui o *operador transparente transmissão functors*. que são especializações de objetos de função padrão e não usam parâmetros de modelo e executam o encaminhamento perfeito dos argumentos da função e o retorno perfeito do resultado. Essas especializações de modelo não exigem que você especifique tipos de argumento ao invocar functores de operadores bit a bit, lógicos, de comparação e aritméticos. Você pode sobrecarregar operadores bit a bit, aritméticos, de comparação ou bit para seus próprios tipos ou para combinações heterogêneas de tipos e, em seguida, usar os functores de operadores transparentes como argumentos de função. Por exemplo, se seu tipo *MyType* implementar `operator<`, você pode chamar `sort(my_collection.begin(), my_collection.end(), less<>())` em vez de especificar explicitamente o tipo `sort(my_collection.begin(), my_collection.end(), less<MyType>())`.

Os recursos a seguir são adicionados em C++ 11, C++ 14 e C++ 17:

- Uma *assinatura de chamada* é o nome de um tipo de retorno seguido por uma lista separada por vírgulas de zero ou mais tipos de argumento, entre parênteses.

- Um *tipo que pode ser chamado* é um ponteiro para a função, um ponteiro para a função membro, um ponteiro para dados do membro ou um tipo de classe cujos objetos podem aparecer imediatamente à esquerda de um operador de chamada de função.

- Um *objeto que pode ser chamado* é um objeto de tipo que pode ser chamado.

- Um *tipo de wrapper de chamada* é um tipo que contém um objeto que pode ser chamado e dá suporte a uma operação de chamada que é encaminhada a esse objeto.

- Um *wrapper de chamada* é um objeto do tipo wrapper de chamada.

- Um *objeto de destino* é o objeto que pode ser chamado mantido por um objeto de wrapper de chamada.

A pseudo função `INVOKE(f, t1, t2, ..., tN)` significa uma das possibilidades a seguir:

- `(t1.*f)(t2, ..., tN)` quando `f` é um ponteiro para uma função membro da classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`.

- `((*t1).*f)(t2, ..., tN)` quando `f` é um ponteiro para uma função membro da classe `T` e `t1` não é um dos tipos descritos no item anterior.

- `t1.*f` quando N == 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`.

- `(*t1).*f` quando N == 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` não é um dos tipos descritos no item anterior.

- `f(t1, t2, ..., tN)` em todos os outros casos.

A pseudo função `INVOKE(f, t1, t2, ..., tN, R)` significa que `INVOKE(f, t1, t2, ..., tN)` foi convertido implicitamente para `R`.

Se um wrapper de chamada tiver um *tipo de resultado fraco*, o tipo de seu membro `result_type` será baseado no tipo `T` do objeto de destino do wrapper, da seguinte maneira:

- Se `T` for um ponteiro para função, `result_type` será um sinônimo do tipo de retorno de `T`.

- Se `T` for um ponteiro para função membro, `result_type` será um sinônimo do tipo de retorno de `T`.

- Se `T` for um tipo de classe que tem um tipo de membro `result_type`, `result_type` será sinônimo de `T::result_type`.

- Caso contrário, não há nenhum membro `result_type`.

Cada wrapper de chamada tem um construtor de movimentação e um construtor de cópia. Um *wrapper de chamada simples* é um wrapper de chamada que tem um operador de atribuição e cujo construtor de cópia, construtor de movimentação e operador de atribuição não geram exceções. Um *wrapper de chamada de encaminhamento* é um wrapper de chamada que pode ser chamado usando uma lista de argumentos arbitrários e que fornece os argumentos como referências ao objeto que pode ser chamado encapsulado. Todos os argumentos rvalue são fornecidos como referências de rvalue e os argumentos de lvalue são entregues como referências de lvalue.

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[bad_function_call](../standard-library/bad-function-call-class.md)|Uma classe que descreve uma exceção gerada para indicar que uma chamada para `operator()` em um objeto [function](../standard-library/function-class.md) falhou porque o objeto estava vazio.|
|[binary_negate](../standard-library/binary-negate-class.md)|Um modelo de classe que fornece uma função de membro que nega o valor de retorno de uma função binária especificada.<br/> (Preterido em C++ 17.) |
|[binder1st](../standard-library/binder1st-class.md)|Um modelo de classe que fornece um construtor que converte um objeto de função binária em um objeto de função unário associando o primeiro argumento da função Binary a um valor especificado.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[binder2nd](../standard-library/binder2nd-class.md)|Um modelo de classe que fornece um construtor que converte um objeto de função binária em um objeto de função unário associando o segundo argumento da função Binary a um valor especificado.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[boyer_moore_horspool_searcher](../standard-library/boyer-moore-horspool-searcher-class.md)||
|[boyer_moore_searcher](../standard-library/boyer-moore-searcher-class.md)||
|[const_mem_fun_ref_t](../standard-library/const-mem-fun-ref-t-class.md)|Uma classe de adaptador que permite que uma função de membro const que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de referência.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[const_mem_fun_t](../standard-library/const-mem-fun-t-class.md)|Uma classe de adaptador que permite que uma função de membro const que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de ponteiro.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[const_mem_fun1_ref_t](../standard-library/const-mem-fun1-ref-t-class.md)|Uma classe de adaptador que permite que uma função membro const que usa um único argumento seja chamada como um objeto de função binária quando inicializado com um argumento de referência.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[const_mem_fun1_t](../standard-library/const-mem-fun1-t-class.md)|Uma classe de adaptador que permite que uma função de membro const que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[default_searcher](../standard-library/default-searcher-class.md)||
|[função](../standard-library/function-class.md)|Uma classe que encapsula um objeto que pode ser chamado.|
|[hash](../standard-library/hash-class.md)|Uma classe que computa um código hash para um valor.|
|[is_bind_expression](../standard-library/is-bind-expression-class.md)|Uma classe que testa se um tipo específico é gerado chamando `bind`.|
|[is_placeholder](../standard-library/is-placeholder-class.md)|Uma classe que testa se um tipo específico é um espaço reservado.|
|[mem_fun_ref_t](../standard-library/mem-fun-ref-t-class.md)|Uma classe de adaptador que permite que uma `non_const` função de membro que não usa argumentos seja chamada como um objeto de função unário quando inicializada com um argumento de referência.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[mem_fun_t](../standard-library/mem-fun-t-class.md)|Uma classe de adaptador que permite que uma `non_const` função de membro que não usa argumentos seja chamada como um objeto de função unário quando inicializada com um argumento de ponteiro.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[mem_fun1_ref_t](../standard-library/mem-fun1-ref-t-class.md)|Uma classe de adaptador que permite que uma `non_const` função de membro que usa um único argumento seja chamada como um objeto de função binária quando inicializada com um argumento de referência.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[mem_fun1_t](../standard-library/mem-fun1-t-class.md)|Uma classe de adaptador que permite que uma `non_const` função de membro que usa um único argumento seja chamada como um objeto de função binária quando inicializada com um argumento de ponteiro.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[pointer_to_binary_function](../standard-library/pointer-to-binary-function-class.md)|Converte um ponteiro de função binária em uma função binária adaptável.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[pointer_to_unary_function](../standard-library/pointer-to-unary-function-class.md)|Converte um ponteiro de função unária em uma função unária adaptável.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[reference_wrapper](../standard-library/reference-wrapper-class.md)|Uma classe que encapsula uma referência.|
|[unary_negate](../standard-library/unary-negate-class.md)|Um modelo de classe que fornece uma função de membro que nega o valor de retorno de uma função unário especificada.<br/> (Preterido em C++ 17.)  |

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[bind](../standard-library/functional-functions.md#bind)|Associa argumentos a um objeto que pode ser chamado.|
|[bind1st](../standard-library/functional-functions.md#bind1st)|Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binária em um objeto de função unária, associando o primeiro argumento da função binária a um valor especificado.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[bind2nd](../standard-library/functional-functions.md#bind2nd)|Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binária em um objeto de função unária, associando o segundo argumento da função binária a um valor especificado.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[bit_and](../standard-library/functional-functions.md#bit_and)|Retorna o AND lógico bit a bit (operador binário &) dos dois parâmetros.|
|[bit_not](../standard-library/functional-functions.md#bit_not)|Retorna o complemento lógico bit a bit (operador ~) do parâmetro.<br/> (Adicionado em C++ 14.) |
|[bit_or](../standard-library/functional-functions.md#bit_or)|Retorna o OR lógico bit a bit (operador &#124;) dos dois parâmetros.|
|[bit_xor](../standard-library/functional-functions.md#bit_xor)|Retorna o XOR lógico bit a bit (operador ^) dos dois parâmetros.|
|[cref](../standard-library/functional-functions.md#cref)|Constrói uma constante `reference_wrapper` de um argumento.|
|[invoke](../standard-library/functional-functions.md#invoke)||
|[mem_fn](../standard-library/functional-functions.md#mem_fn)|Gera um wrapper de chamada simples.|
|[mem_fun](../standard-library/functional-functions.md#mem_fun)|Funções de modelo auxiliares usadas para construir adaptadores de objeto de função para funções membro, quando inicializadas com argumentos de ponteiro.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref)|Uma função de modelo auxiliar usada para construir adaptadores de objeto de função para funções membro, quando inicializada com argumentos de referência.|
|[not1](../standard-library/functional-functions.md#not1)|Retorna o complemento de um predicado unário.<br/> (Preterido em C++ 17.) |
|[not2](../standard-library/functional-functions.md#not2)|Retorna o complemento de um predicado binário.<br/> (Preterido em C++ 17.) |
|[not_fn](../standard-library/functional-functions.md#not_fn)|Retorna o complemento do resultado de seu objeto de função.<br/> (Adicionado em C++ 17.) |
|[ptr_fun](../standard-library/functional-functions.md#ptr_fun)|Uma função de modelo auxiliar usada para converter ponteiros de funções unárias e binárias, respectivamente, em funções adaptáveis unárias e binárias.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[referência](../standard-library/functional-functions.md#ref)|Constrói um `reference_wrapper` de um argumento.|
|[permuta](../standard-library/functional-functions.md#swap)|Troca dois objetos `function`.|

### <a name="structs"></a>Estruturas

|Nome|Descrição|
|-|-|
|[binary_function](../standard-library/binary-function-struct.md)|Uma classe base vazia que define tipos que podem ser herdados por uma classe derivada que fornece um objeto de função binária.<br/> (Preterido em C++ 11, removido em C++ 17.) |
|[divides](../standard-library/divides-struct.md)|A classe fornece um objeto de função predefinida que executa a operação de divisão aritmética em elementos de um tipo de valor especificado.|
|[equal_to](../standard-library/equal-to-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é igual a outro valor desse tipo.|
|[greater](../standard-library/greater-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é maior que outro valor desse tipo.|
|[greater_equal](../standard-library/greater-equal-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é maior ou igual a outro valor desse tipo.|
|[less](../standard-library/less-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é menor que outro valor desse tipo.|
|[less_equal](../standard-library/less-equal-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é menor ou igual a outro valor desse tipo.|
|[logical_and](../standard-library/logical-and-struct.md)|A classe fornece um objeto de função predefinido que executa a operação lógica de conjunção dos elementos de um tipo de valor especificado e testa se o resultado é verdadeiro ou falso.|
|[logical_not](../standard-library/logical-not-struct.md)|A classe fornece um objeto de função predefinido que executa a operação lógica de negação dos elementos de um tipo de valor especificado e testa se o resultado é verdadeiro ou falso.|
|[logical_or](../standard-library/logical-or-struct.md)|A classe fornece um objeto de função predefinido que executa a operação lógica de disjunção dos elementos de um tipo de valor especificado e testa se o resultado é verdadeiro ou falso.|
|[minus](../standard-library/minus-struct.md)|A classe fornece um objeto de função predefinido que executa a operação aritmética de subtração em elementos de um tipo de valor especificado.|
|[igual](../standard-library/modulus-struct.md)|A classe fornece um objeto de função predefinido que executa a operação aritmética de módulo em elementos de um tipo de valor especificado.|
|[multiplies](../standard-library/multiplies-struct.md)|A classe fornece um objeto de função predefinido que executa a operação aritmética de multiplicação em elementos de um tipo de valor especificado.|
|[negate](../standard-library/negate-struct.md)|A classe fornece um objeto de função predefinido que retorna o negativo de um valor de elemento.|
|[not_equal_to](../standard-library/not-equal-to-struct.md)|Um predicado binário que testa se um valor de um tipo especificado não é igual a outro valor desse tipo.|
|[plus](../standard-library/plus-struct.md)|A classe fornece um objeto de função predefinida que executa a operação aritmética de adição em elementos de um tipo de valor especificado.|
|[unary_function](../standard-library/unary-function-struct.md)|Uma classe base vazia que define tipos que podem ser herdados por uma classe derivada que fornece um objeto de função unária.<br/> (Preterido em C++ 11, removido em C++ 17.) |

### <a name="objects"></a>Objetos

|Nome|Descrição|
|-|-|
|[_1.._M](../standard-library/1-object.md)|Espaços reservados para argumentos substituíveis.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador = =](../standard-library/functional-operators.md#op_eq_eq)|Não permite comparações de igualdade de objetos que podem ser chamados.|
|[operador! =](../standard-library/functional-operators.md#op_neq)|Não permite comparações de desigualdade de objetos que podem ser chamados.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
