---
title: '&lt;Variant&gt;'
ms.date: 04/04/2019
f1_keywords:
- <variant>
helpviewer_keywords:
- <variant>
ms.openlocfilehash: 7a812ccc3c8cb2a660c01ad2b17ea75b5d5c9542
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268438"
---
# <a name="ltvariantgt"></a>&lt;Variant&gt;

Um objeto variante contém e gerencia um valor. Se a variante contém um valor, que tipo de valor deve ser um dos tipos de argumento de modelo fornecidos a variante. Esses argumentos de modelo são chamados de alternativas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<variante >

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/forward-list-operators.md#op_eq_eq)|Testa se o objeto de variante no lado esquerdo do operador é igual ao objeto de variante no lado direito.|
|[operator!=](../standard-library/forward-list-operators.md#op_neq)|Testa se o objeto de variante no lado esquerdo do operador não é igual ao objeto de variante no lado direito.|
|[operator<](../standard-library/forward-list-operators.md#op_lt)|Testa se o objeto de variante no lado esquerdo do operador é menor que o objeto de variante no lado direito.|
|[operator<=](../standard-library/forward-list-operators.md#op_lt_eq)|Testa se a variante do objeto no lado esquerdo do operador é menor ou igual ao objeto de variante no lado direito.|
|[operator>](../standard-library/forward-list-operators.md#op_gt)|Testa se o objeto de variante no lado esquerdo do operador é maior que o objeto de variante no lado direito.|
|[operator>=](../standard-library/forward-list-operators.md#op_lt_eq)|Testa se o objeto de variante no lado esquerdo do operador é maior que ou igual ao objeto de variante no lado direito.|

### <a name="functions"></a>Funções

|||
|-|-|
|[get](../standard-library/variant-functions.md#get)|Obtém a variante de um objeto.|
|[get_if](../standard-library/variant-functions.md#get_if)|Obtém a variante de um objeto se ele existir.|
|[holds_alternative](../standard-library/variant-functions.md#holds_alternative)|Retornar **verdadeira** se existir uma variante.|
|[swap](../standard-library/variant-functions.md#swap)|Alterna uma **variante**.|
|[Visite o](../standard-library/variant-functions.md#visit)|Move para a próxima **variante**.|

### <a name="classes"></a>Classes

|||
|-|-|
|[bad_variant_access](../standard-library/bad-variant-access-class.md)|Objetos lançados para acessos de relatório inválido para o valor de um objeto variante.|
|[Variant](../standard-library/variant.md)|Um objeto como armazenar um valor de um de seus tipos alternativos ou nenhum valor.|

### <a name="structs"></a>Structs

|||
|-|-|
|[hash](../standard-library/hash-structure.md)||
|[monostate](../standard-library/monostate-structure.md)|Um tipo alternativo para uma variante para tornar o padrão de tipo de variante pode ser construído.|
|[uses_allocator](../standard-library/uses-allocator-structure.md)||
|[variant_alternative](../standard-library/variant-alternative-structure.md)|Auxilia os objetos variantes.|
|[variant_size](../standard-library/variant-size-structure.md)|Auxilia os objetos variantes.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[variant_npos](../standard-library/variant-functions.md#variant_npos)||

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
