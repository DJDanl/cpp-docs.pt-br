---
title: '&lt;type_traits&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <type_traits>
dev_langs:
- C++
helpviewer_keywords:
- typetrait header
- type_traits
ms.assetid: 2260b51f-8160-4c66-a82f-00b534cb60d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5c7d09615b5f9ec7f0f72acde965d5ffbd018c9c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33863368"
---
# <a name="lttypetraitsgt"></a>&lt;type_traits&gt;

Define modelos que fornecem constantes de tempo de compilação e informações sobre as propriedades dos argumentos de tipo ou produzem tipos transformados.

## <a name="syntax"></a>Sintaxe

```cpp
#include <type_traits>
```

## <a name="remarks"></a>Comentários

As classes e os modelos no \<type_traits > são usadas para dar suporte a inferência de tipo, classificação e transformação em tempo de compilação, para detectar erros de tipo e para ajudá-lo a otimizar o código genérico. Essas classes e modelos incluem características de tipo unário que descrevem uma propriedade de um tipo, características de tipo binário que descrevem uma relação entre tipos e características de transformação que modificam uma propriedade de um tipo.

Para dar suporte a características de tipo, uma classe auxiliar, `integral_constant`, é definida. Ela tem especializações de modelo `true_type` e `false_type` que formam as classes de base para predicados de tipo. Um *predicado de tipo* é um modelo que usa um ou mais argumentos de tipo. Quando um predicado de tipo *mantém verdadeiro*, ele é derivado publicamente, direta ou indiretamente, de [true_type](../standard-library/type-traits-typedefs.md#true_type). Quando um predicado de tipo *mantém falso*, ele é derivado publicamente, direta ou indiretamente, de [false_type](../standard-library/type-traits-typedefs.md#false_type).

Um *modificador de tipo* ou uma *característica da transformação* é um modelo que usa um ou mais argumentos de modelo e tem um membro, `type`, que é sinônimo do tipo modificado.

### <a name="alias-templates"></a>Modelos de alias

Para simplificar expressões de características de tipo, são fornecidos [modelos de alias](../cpp/aliases-and-typedefs-cpp.md) para `typename some_trait<T>::type`, em que "`some_trait`" é o nome de classe do modelo. Por exemplo, [add_const](../standard-library/add-const-class.md) tem o modelo de alias para seu tipo `add_const_t`, definido como:

```cpp
template <class T>
using add_const_t = typename add_const<T>::type;
```

|||||
|-|-|-|-|
|add_const_t|aligned_storage_t|make_signed_t|remove_pointer_t|
|add_cv_t|aligned_union_t|make_unsigned_t|remove_reference_t|
|add_lvalue_reference_t|common_type_t|remove_all_extents_t|remove_volatile_t|
|add_pointer_t|conditional_t|remove_const_t|result_of_t|
|add_rvalue_reference_t|decay_t|remove_cv_t|underlying_type_t|
|add_volatile_t|enable_if_t|remove_extent_t||

### <a name="classes"></a>Classes

Classe auxiliar e typedefs

|||
|-|-|
|[integral_constant](../standard-library/integral-constant-class-bool-constant-class.md)|Cria uma constante integral de um tipo e valor.|
|[true_type](../standard-library/type-traits-typedefs.md#true_type)|Mantém uma constante integral com valor verdadeiro.|
|[false_type](../standard-library/type-traits-typedefs.md#false_type)|Mantém uma constante integral com valor falso.|

Categorias de tipo principal

|||
|-|-|
|[is_void](../standard-library/is-void-class.md)|Testa se o tipo é `void`.|
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

|||
|-|-|
|[is_reference](../standard-library/is-reference-class.md)|Testa se o tipo é uma referência.|
|[is_arithmetic](../standard-library/is-arithmetic-class.md)|Testa se o tipo é aritmético.|
|[is_fundamental](../standard-library/is-fundamental-class.md)|Testa se o tipo é `void` ou aritmético.|
|[is_object](../standard-library/is-object-class.md)|Testa se o tipo é um tipo de objeto.|
|[is_scalar](../standard-library/is-scalar-class.md)|Testa se o tipo é escalar.|
|[is_compound](../standard-library/is-compound-class.md)|Testa se o tipo não é escalar.|
|[is_member_pointer](../standard-library/is-member-pointer-class.md)|Testa se o tipo é um ponteiro para um membro.|

Propriedades de tipo

|||
|-|-|
|[is_const](../standard-library/is-const-class.md)|Testa se o tipo é `const`.|
|[is_volatile](../standard-library/is-volatile-class.md)|Testa se o tipo é `volatile`.|
|[is_trivial](../standard-library/is-trivial-class.md)|Testa se o tipo é trivial.|
|[is_trivially_copyable](../standard-library/is-trivially-copyable-class.md)|Testa se o tipo é trivialmente copiável.|
|[is_standard_layout](../standard-library/is-standard-layout-class.md)|Testa se o tipo é um layout padrão.|
|[is_pod](../standard-library/is-pod-class.md)|Testa se o tipo é um POD.|
|[is_literal_type](../standard-library/is-literal-type-class.md)|Testa se o tipo pode ser uma variável `constexpr` ou usado em uma função `constexpr`.|
|[is_empty](../standard-library/is-empty-class.md)|Testa se o tipo é uma classe vazia.|
|[is_polymorphic](../standard-library/is-polymorphic-class.md)|Testa se o tipo é uma classe polimórfica.|
|[is_abstract](../standard-library/is-abstract-class.md)|Testa se o tipo é uma classe abstrata.|
|[is_final](../standard-library/is-final-class.md)|Testa se o tipo é um tipo de classe marcado como `final`.|
|[is_signed](../standard-library/is-signed-class.md)|Testa se o tipo é um inteiro com sinal.|
|[is_unsigned](../standard-library/is-unsigned-class.md)|Testa se o tipo é um inteiro sem sinal.|
|[is_constructible](../standard-library/is-constructible-class.md)|Testa se o tipo é construível usando os tipos de argumento especificados.|
|[is_default_constructible](../standard-library/type-traits-functions.md#is_default_constructible)|Testa se o tipo tem um construtor padrão.|
|[is_copy_constructible](../standard-library/type-traits-functions.md#is_copy_constructible)|Testa se o tipo tem um construtor de cópia.|
|[is_move_constructible](../standard-library/type-traits-functions.md#is_move_constructible)|Testa se o tipo tem um construtor de movimentação.|
|[is_assignable](../standard-library/type-traits-functions.md#is_assignable)|Testa se ao primeiro tipo pode ser atribuído um valor do segundo tipo.|
|[is_copy_assignable](../standard-library/type-traits-functions.md#is_copy_assignable)|Testa se a um tipo pode ser atribuído um valor de referência constante do tipo.|
|[is_move_assignable](../standard-library/type-traits-functions.md#is_move_assignable)|Testa se a um tipo pode ser atribuída uma referência rvalue do tipo.|
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
|[is_nothrow_destructible](../standard-library/is-nothrow-destructible-class.md)|Testa se o tipo é destrutível e se o destruidor não efetua lançamentos.|
|[has_virtual_destructor](http://msdn.microsoft.com/en-us/c0f85f0b-c63c-410d-a046-72eeaf44f7eb)|Testa se o tipo tem um destruidor virtual.|

Consultas de tipo de propriedade

|||
|-|-|
|[alignment_of](../standard-library/alignment-of-class.md)|Obtém o alinhamento de um tipo.|
|[rank](../standard-library/rank-class.md)|Obtém o número de dimensões da matriz.|
|[extent](../standard-library/extent-class.md)|Obtém o número de elementos na dimensão de matriz especificada.|

Relações de tipo

|||
|-|-|
|[is_same](../standard-library/is-same-class.md)|Testa se dois tipos são iguais.|
|[is_base_of](../standard-library/is-base-of-class.md)|Testa se um tipo é a base de outro.|
|[is_convertible](../standard-library/is-convertible-class.md)|Testa se o tipo pode ser convertido em outro.|

Modificações constantes voláteis

|||
|-|-|
|[add_const](../standard-library/add-const-class.md)|Produz um tipo `const` de tipo.|
|[add_volatile](../standard-library/add-volatile-class.md)|Produz um tipo `volatile` de tipo.|
|[add_cv](../standard-library/add-cv-class.md)|Produz um tipo `const volatile` de tipo.|
|[remove_const](../standard-library/remove-const-class.md)|Produz um tipo não constante de tipo.|
|[remove_volatile](../standard-library/remove-volatile-class.md)|Produz um tipo não volátil de tipo.|
|[remove_cv](../standard-library/remove-cv-class.md)|Produz um tipo não constante e não volátil de tipo.|

Modificações de referência

|||
|-|-|
|[add_lvalue_reference](../standard-library/add-lvalue-reference-class.md)|Produz uma referência para o tipo do tipo.|
|[add_rvalue_reference](../standard-library/add-rvalue-reference-class.md)|Produz uma referência rvalue para o tipo do tipo|
|[remove_reference](../standard-library/remove-reference-class.md)|Produz um tipo de não referência do tipo.|

Assinar modificações

|||
|-|-|
|[make_signed](../standard-library/make-signed-class.md)|Produz o tipo, se assinado ou o menor tipo assinado, maior ou igual em tamanho ao tipo.|
|[make_unsigned](../standard-library/make-unsigned-class.md)|Produz o tipo, se não assinado ou o menor tipo não assinado, maior ou igual em tamanho ao tipo.|

Modificações de matriz

|||
|-|-|
|[remove_all_extents](../standard-library/remove-all-extents-class.md)|Cria o tipo de não matriz de um tipo de matriz.|
|[remove_extent](../standard-library/remove-extent-class.md)|Produz o tipo de elemento de um tipo de matriz.|

Modificações de ponteiro

|||
|-|-|
|[add_pointer](../standard-library/add-pointer-class.md)|Produz um ponteiro para o tipo do tipo.|
|[remove_pointer](../standard-library/remove-pointer-class.md)|Produz um tipo de um ponteiro para tipo.|

Outras transformações

|||
|-|-|
|[aligned_storage](../standard-library/aligned-storage-class.md)|Aloca memória não inicializada para um tipo alinhado.|
|[aligned_union](../standard-library/aligned-union-class.md)|Aloca memória não inicializada para uma união alinhada com um construtor ou destruidor não trivial.|
|[common_type](../standard-library/common-type-class.md)|Produz o tipo comum de todos os tipos de pacote de parâmetros.|
|[conditional](../standard-library/conditional-class.md)|Se a condição for verdadeira, produzirá o primeiro tipo especificado, caso contrário, o segundo tipo especificado.|
|[decay](../standard-library/decay-class.md)|Produz o tipo passado por valor. Cria o tipo de não referência, não constante, não volátil ou cria um ponteiro para o tipo.|
|[enable_if](../standard-library/enable-if-class.md)|Se a condição for verdadeira, produzirá o tipo especificado, caso contrário, nenhum tipo.|
|[result_of](../standard-library/result-of-class.md)|Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados.|
|[underlying_type](../standard-library/underlying-type-class.md)|Produz o tipo integral subjacente para um tipo de enumeração.|

## <a name="see-also"></a>Consulte também

[\<functional>](../standard-library/functional.md)<br/>
