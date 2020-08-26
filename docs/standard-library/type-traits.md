---
title: '&lt;type_traits&gt;'
ms.date: 02/21/2019
f1_keywords:
- <type_traits>
helpviewer_keywords:
- typetrait header
- type_traits
ms.assetid: 2260b51f-8160-4c66-a82f-00b534cb60d4
ms.openlocfilehash: 42c94daf331fd9a17e050067e4c4e495af180b0c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841695"
---
# <a name="lttype_traitsgt"></a>&lt;type_traits&gt;

Define modelos para constantes de tempo de compilação que fornecem informações sobre as propriedades de seus argumentos de tipo ou produzem tipos transformados.

## <a name="syntax"></a>Sintaxe

```cpp
#include <type_traits>
```

## <a name="remarks"></a>Comentários

As classes e os modelos no \<type_traits> são usados para dar suporte à inferência de tipos, classificação e transformação no momento da compilação. Eles também são usados para detectar erros relacionados ao tipo e para ajudá-lo a otimizar seu código genérico. As características do tipo unário descrevem uma propriedade de um tipo, as características do tipo binary descrevem uma relação entre os tipos e as características da transformação modificam uma propriedade de um tipo.

A classe auxiliar `integral_constant` e suas especializações de modelo `true_type` e `false_type` formam as classes base para predicados de tipo. Um *predicado de tipo* é um modelo que usa um ou mais argumentos de tipo. Quando um predicado de tipo é *verdadeiro*, ele é derivado publicamente, direta ou indiretamente, de [true_type](../standard-library/type-traits-typedefs.md#true_type). Quando um predicado de tipo *tem false*, ele é derivado publicamente, direta ou indiretamente, de [false_type](../standard-library/type-traits-typedefs.md#false_type).

Um *modificador de tipo* ou uma *característica da transformação* é um modelo que usa um ou mais argumentos de modelo e tem um membro, `type`, que é sinônimo do tipo modificado.

### <a name="alias-templates"></a>Modelos de alias

Para simplificar as expressões de características de tipo, os [modelos de alias](../cpp/aliases-and-typedefs-cpp.md) para `typename some_trait<T>::type` são fornecidos, em que *some_trait* é o nome do modelo de classe. Por exemplo, [add_const](../standard-library/add-const-class.md) tem o modelo de alias para seu tipo `add_const_t`, definido como:

```cpp
template <class T>
using add_const_t = typename add_const<T>::type;
```

Estes são os aliases fornecidos para os `type` Membros:

:::row:::
   :::column:::
      `add_const_t`\
      `add_cv_t`\
      `add_lvalue_reference_t`\
      `add_pointer_t`\
      `add_rvalue_reference_t`\
      `add_volatile_t`\
      `aligned_storage_t`\
      `aligned_union_t`\
   :::column-end:::
   :::column:::
      `common_type_t`\
      `conditional_t`\
      `decay_t`\
      `enable_if_t`\
      `invoke_result_t`\
      `make_signed_t`\
      `make_unsigned_t`\
      `remove_all_extents_t`\
   :::column-end:::
   :::column:::
      `remove_const_t`\
      `remove_cv_t`\
      `remove_extent_t`\
      `remove_pointer_t`\
      `remove_reference_t`\
      `remove_volatile_t`\
      `result_of_t`\
      `underlying_type_t`\
   :::column-end:::
:::row-end:::

### <a name="classes"></a>Classes

Classe auxiliar e typedefs

|Nome|Descrição|
|-|-|
|[integral_constant](../standard-library/integral-constant-class-bool-constant-class.md)|Cria uma constante integral de um tipo e valor.|
|[true_type](../standard-library/type-traits-typedefs.md#true_type)|Mantém uma constante integral com valor verdadeiro.|
|[false_type](../standard-library/type-traits-typedefs.md#false_type)|Mantém uma constante integral com valor falso.|

Categorias de tipo principal

|Nome|Descrição|
|-|-|
|[is_void](../standard-library/is-void-class.md)|Testa se o tipo é **`void`** .|
|[is_null_pointer](../standard-library/is-null-pointer-class.md)|Testa se o tipo é `std::nullptr_t`.|
|[is_integral](../standard-library/is-integral-class.md)|Testa se o tipo é integral.|
|[is_floating_point](../standard-library/is-floating-point-class.md)|Testa se o tipo é um ponto flutuante.|
|[is_array](../standard-library/is-array-class.md)|Testa se o tipo é uma matriz.|
|[is_pointer](../standard-library/is-pointer-class.md)|Testa se o tipo é um ponteiro.|
|[is_lvalue_reference](../standard-library/is-lvalue-reference-class.md)|Testa se o tipo é uma referência lvalue.|
|[is_rvalue_reference](../standard-library/is-rvalue-reference-class.md)|Testa se o tipo é uma referência rvalue.|
|[is_member_object_pointer](../standard-library/is-member-object-pointer-class.md)|Testa se o tipo é um ponteiro para um objeto do membro.|
|[is_member_function_pointer](../standard-library/is-member-function-pointer-class.md)|Testa se o tipo é um ponteiro para uma função do membro.|
|[is_enum](../standard-library/is-enum-class.md)|Testa se o tipo é uma enumeração.|
|[is_union](../standard-library/is-union-class.md)|Testa se o tipo é uma união.|
|[is_class](../standard-library/is-class-class.md)|Testa se o tipo é uma classe.|
|[is_function](../standard-library/is-function-class.md)|Testa se o tipo é um tipo de função.|

Categorias de tipo de composição

|Nome|Descrição|
|-|-|
|[is_reference](../standard-library/is-reference-class.md)|Testa se o tipo é uma referência.|
|[is_arithmetic](../standard-library/is-arithmetic-class.md)|Testa se o tipo é aritmético.|
|[is_fundamental](../standard-library/is-fundamental-class.md)|Testa se o tipo é **`void`** ou aritmético.|
|[is_object](../standard-library/is-object-class.md)|Testa se o tipo é um tipo de objeto.|
|[is_scalar](../standard-library/is-scalar-class.md)|Testa se o tipo é escalar.|
|[is_compound](../standard-library/is-compound-class.md)|Testa se o tipo não é escalar.|
|[is_member_pointer](../standard-library/is-member-pointer-class.md)|Testa se o tipo é um ponteiro para um membro.|

Propriedades de tipo

|Nome|Descrição|
|-|-|
|[is_const](../standard-library/is-const-class.md)|Testa se o tipo é **`const`** .|
|[is_volatile](../standard-library/is-volatile-class.md)|Testa se o tipo é **`volatile`** .|
|[is_trivial](../standard-library/is-trivial-class.md)|Testa se o tipo é trivial.|
|[is_trivially_copyable](../standard-library/is-trivially-copyable-class.md)|Testa se o tipo é trivialmente copiável.|
|[is_standard_layout](../standard-library/is-standard-layout-class.md)|Testa se o tipo é um layout padrão.|
|[is_pod](../standard-library/is-pod-class.md)|Testa se o tipo é um POD.|
|[is_literal_type](../standard-library/is-literal-type-class.md)|Testa se o tipo pode ser uma **`constexpr`** variável ou usado em uma **`constexpr`** função.|
|[is_empty](../standard-library/is-empty-class.md)|Testa se o tipo é uma classe vazia.|
|[is_polymorphic](../standard-library/is-polymorphic-class.md)|Testa se o tipo é uma classe polimórfica.|
|[is_abstract](../standard-library/is-abstract-class.md)|Testa se o tipo é uma classe abstrata.|
|[is_final](../standard-library/is-final-class.md)|Testa se o tipo é um tipo de classe marcado como `final`.|
|[is_aggregate](../standard-library/is-aggregate-class.md)||
|[is_signed](../standard-library/is-signed-class.md)|Testa se o tipo é um inteiro com sinal.|
|[is_unsigned](../standard-library/is-unsigned-class.md)|Testa se o tipo é um inteiro sem sinal.|
|[is_constructible](../standard-library/is-constructible-class.md)|Testa se o tipo é construível usando os tipos de argumento especificados.|
|[is_default_constructible](../standard-library/type-traits-functions.md#is_default_constructible)|Testa se o tipo tem um construtor padrão.|
|[is_copy_constructible](../standard-library/type-traits-functions.md#is_copy_constructible)|Testa se o tipo tem um construtor de cópia.|
|[is_move_constructible](../standard-library/type-traits-functions.md#is_move_constructible)|Testa se o tipo tem um construtor de movimentação.|
|[is_assignable](../standard-library/type-traits-functions.md#is_assignable)|Testa se ao primeiro tipo pode ser atribuído um valor do segundo tipo.|
|[is_copy_assignable](../standard-library/type-traits-functions.md#is_copy_assignable)|Testa se a um tipo pode ser atribuído um valor de referência constante do tipo.|
|[is_move_assignable](../standard-library/type-traits-functions.md#is_move_assignable)|Testa se a um tipo pode ser atribuída uma referência rvalue do tipo.|
|[is_swappable](../standard-library/type-traits-functions.md#is_swappable)||
|[is_swappable_with](../standard-library/type-traits-functions.md#is_swappable_with)||
|[is_destructible](../standard-library/is-destructible-class.md)|Testa se o tipo é destrutível.|
|[is_trivially_constructible](../standard-library/is-trivially-constructible-class.md)|Testa se o tipo usa operações não triviais ao ser construído com o uso de tipos especificados.|
|[is_trivially_default_constructible](../standard-library/is-trivially-default-constructible-class.md)|Testa se o tipo usa operações não triviais quando construído por padrão.|
|[is_trivially_copy_constructible](../standard-library/is-trivially-copy-constructible-class.md)|Testa se o tipo usa operações não triviais quando construído por cópia.|
|[is_trivially_move_constructible](../standard-library/type-traits-functions.md#is_trivially_move_constructible)|Testa se o tipo usa operações não triviais quando construído por movimentação.|
|[is_trivially_assignable](../standard-library/is-trivially-assignable-class.md)|Testa se os tipos são atribuíveis e se a atribuição usa operações não triviais.|
|[is_trivially_copy_assignable](../standard-library/type-traits-functions.md#is_trivially_copy_assignable)|Testa se o tipo é atribuível a cópia e se a atribuição usa operações não triviais.|
|[is_trivially_move_assignable](../standard-library/type-traits-functions.md#is_trivially_move_assignable)|Testa se o tipo é atribuível a movimentação e se a atribuição usa operações não triviais.|
|[is_trivially_destructible](../standard-library/is-trivially-destructible-class.md)|Testa se o tipo é destrutível e se o destruidor usa operações não triviais.|
|[is_nothrow_constructible](../standard-library/is-nothrow-constructible-class.md)|Testa se o tipo é construível e se não efetua lançamentos quando construído usando os tipos especificados.|
|[is_nothrow_default_constructible](../standard-library/is-nothrow-default-constructible-class.md)|Testa se o tipo é construível por padrão e se não efetua lançamentos quando construído por padrão.|
|[is_nothrow_copy_constructible](../standard-library/is-nothrow-copy-constructible-class.md)|Testa se o tipo é construível por cópia e se o construtor de cópia não efetua lançamentos.|
|[is_nothrow_move_constructible](../standard-library/is-nothrow-move-constructible-class.md)|Testa se o tipo é construível por movimentação e se o construtor de movimentação não efetua lançamentos.|
|[is_nothrow_assignable](../standard-library/is-nothrow-assignable-class.md)|Testa se o tipo é atribuível usando o tipo especificado e a atribuição não efetua lançamentos.|
|[is_nothrow_copy_assignable](../standard-library/is-nothrow-copy-assignable-class.md)|Testa se o tipo é atribuível usando a cópia e a atribuição não efetua lançamentos.|
|[is_nothrow_move_assignable](../standard-library/type-traits-functions.md#is_nothrow_move_assignable)|Testa se o tipo é atribuível por movimentação e se a atribuição não efetua lançamentos.|
|[is_nothrow_swappable](../standard-library/type-traits-functions.md#is_nothrow_swappable)||
|[is_nothrow_swappable_with](../standard-library/type-traits-functions.md#is_nothrow_swappable_with)||
|[is_nothrow_destructible](../standard-library/is-nothrow-destructible-class.md)|Testa se o tipo é destrutível e se o destruidor não efetua lançamentos.|
|`has_virtual_destructor`|Testa se o tipo tem um destruidor virtual.|
|`has_unique_object_representations`||
| [is_invocable](is-invocable-classes.md) | Testa se um tipo callable pode ser invocado usando os tipos de argumento especificados.<br/> Adicionado em C++ 17. |
| [is_invocable_r](is-invocable-classes.md) | Testa se um tipo callable pode ser invocado usando os tipos de argumento especificados e o resultado é conversível para o tipo especificado.<br/> Adicionado em C++ 17. |
| [is_nothrow_invocable](is-invocable-classes.md) | Testa se um tipo callable pode ser invocado usando os tipos de argumento especificados e é conhecido por não gerar exceções.<br/> Adicionado em C++ 17. |
| [is_nothrow_invocable_r](is-invocable-classes.md) | Testa se um tipo callable pode ser invocado usando os tipos de argumento especificados e é conhecido por não gerar exceções, e o resultado é conversível para o tipo especificado.<br/> Adicionado em C++ 17. |

Consultas de tipo de propriedade

|Nome|Descrição|
|-|-|
|[alignment_of](../standard-library/alignment-of-class.md)|Obtém o alinhamento de um tipo.|
|[Fique](../standard-library/rank-class.md)|Obtém o número de dimensões da matriz.|
|[tention](../standard-library/extent-class.md)|Obtém o número de elementos na dimensão de matriz especificada.|

Relações de tipo

|Nome|Descrição|
|-|-|
|[is_same](../standard-library/is-same-class.md)|Testa se dois tipos são iguais.|
|[is_base_of](../standard-library/is-base-of-class.md)|Testa se um tipo é a base de outro.|
|[is_convertible](../standard-library/is-convertible-class.md)|Testa se o tipo pode ser convertido em outro.|

Modificações constantes voláteis

|Nome|Descrição|
|-|-|
|[add_const](../standard-library/add-const-class.md)|Produz um **`const`** tipo do tipo.|
|[add_volatile](../standard-library/add-volatile-class.md)|Produz um **`volatile`** tipo do tipo.|
|[add_cv](../standard-library/add-cv-class.md)|Produz um **`const volatile`** tipo do tipo.|
|[remove_const](../standard-library/remove-const-class.md)|Produz um tipo não constante de tipo.|
|[remove_volatile](../standard-library/remove-volatile-class.md)|Produz um tipo não volátil de tipo.|
|[remove_cv](../standard-library/remove-cv-class.md)|Produz um tipo não constante e não volátil de tipo.|

Modificações de referência

|Nome|Descrição|
|-|-|
|[add_lvalue_reference](../standard-library/add-lvalue-reference-class.md)|Produz uma referência para o tipo do tipo.|
|[add_rvalue_reference](../standard-library/add-rvalue-reference-class.md)|Produz uma referência rvalue para o tipo do tipo|
|[remove_reference](../standard-library/remove-reference-class.md)|Produz um tipo de não referência do tipo.|

Assinar modificações

|Nome|Descrição|
|-|-|
|[make_signed](../standard-library/make-signed-class.md)|Produz o tipo, se assinado ou o menor tipo assinado, maior ou igual em tamanho ao tipo.|
|[make_unsigned](../standard-library/make-unsigned-class.md)|Produz o tipo, se não assinado ou o menor tipo não assinado, maior ou igual em tamanho ao tipo.|

Modificações de matriz

|Nome|Descrição|
|-|-|
|[remove_all_extents](../standard-library/remove-all-extents-class.md)|Cria o tipo de não matriz de um tipo de matriz.|
|[remove_extent](../standard-library/remove-extent-class.md)|Produz o tipo de elemento de um tipo de matriz.|

Modificações de ponteiro

|Nome|Descrição|
|-|-|
|[add_pointer](../standard-library/add-pointer-class.md)|Produz um ponteiro para o tipo do tipo.|
|[remove_pointer](../standard-library/remove-pointer-class.md)|Produz um tipo de um ponteiro para tipo.|

Outras transformações

|Nome|Descrição|
|-|-|
|[aligned_storage](../standard-library/aligned-storage-class.md)|Aloca memória não inicializada para um tipo alinhado.|
|[aligned_union](../standard-library/aligned-union-class.md)|Aloca memória não inicializada para uma união alinhada com um construtor ou destruidor não trivial.|
|[common_type](../standard-library/common-type-class.md)|Produz o tipo comum de todos os tipos de pacote de parâmetros.|
|[condiciona](../standard-library/conditional-class.md)|Se a condição for verdadeira, produzirá o primeiro tipo especificado, caso contrário, o segundo tipo especificado.|
|[decay](../standard-library/decay-class.md)|Produz o tipo passado por valor. Cria o tipo de não referência, não constante, não volátil ou cria um ponteiro para o tipo.|
|[enable_if](../standard-library/enable-if-class.md)|Se a condição for verdadeira, produzirá o tipo especificado, caso contrário, nenhum tipo.|
|[invoke_result](invoke-result-class.md)|Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados. <br/>Adicionado em C++ 17. |
|[result_of](../standard-library/result-of-class.md)|Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados. <br/>Adicionado em C++ 14, preterido em C++ 17. |
|[underlying_type](../standard-library/underlying-type-class.md)|Produz o tipo integral subjacente para um tipo de enumeração.|

Características do operador lógico

|Nome|Descrição|
|-|-|
|[conjunção](../standard-library/conjunction-class.md)||
|[disjunção](../standard-library/disjunction-class.md)||
|[negação](../standard-library/negation-class.md)||

## <a name="see-also"></a>Confira também

[\<functional>](../standard-library/functional.md)
