---
title: '&lt;variant&gt;'
ms.date: 04/04/2019
f1_keywords:
- <variant>
helpviewer_keywords:
- <variant>
ms.openlocfilehash: 6074c80b20ae0c69d34768bc16d7aaae16c99579
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232814"
---
# <a name="ltvariantgt"></a>&lt;variant&gt;

Um objeto Variant mantém e gerencia um valor. Se a variante mantiver um valor, o tipo desse valor terá que ser um dos tipos de argumento de modelo fornecidos para Variant. Esses argumentos de modelo são chamados de alternativas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<variant>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador = =](../standard-library/forward-list-operators.md#op_eq_eq)|Testa se o objeto Variant no lado esquerdo do operador é igual ao objeto Variant no lado direito.|
|[operador! =](../standard-library/forward-list-operators.md#op_neq)|Testa se o objeto Variant no lado esquerdo do operador não é igual ao objeto Variant no lado direito.|
|[<do operador](../standard-library/forward-list-operators.md#op_lt)|Testa se o objeto Variant no lado esquerdo do operador é menor que o objeto Variant no lado direito.|
|[<do operador =](../standard-library/forward-list-operators.md#op_lt_eq)|Testa se o objeto Variant no lado esquerdo do operador é menor ou igual ao objeto Variant no lado direito.|
|[>do operador](../standard-library/forward-list-operators.md#op_gt)|Testa se o objeto Variant no lado esquerdo do operador é maior que o objeto Variant no lado direito.|
|[>do operador =](../standard-library/forward-list-operators.md#op_lt_eq)|Testa se o objeto Variant no lado esquerdo do operador é maior ou igual ao objeto Variant no lado direito.|

### <a name="functions"></a>Funções

|||
|-|-|
|[get](../standard-library/variant-functions.md#get)|Obtém a variante de um objeto.|
|[get_if](../standard-library/variant-functions.md#get_if)|Obtém a variante de um objeto, se ele existir.|
|[holds_alternative](../standard-library/variant-functions.md#holds_alternative)|Retornar **`true`** se houver uma variante.|
|[permuta](../standard-library/variant-functions.md#swap)|Troca uma **variante**.|
|[Visite](../standard-library/variant-functions.md#visit)|Move para a próxima **variante**.|

### <a name="classes"></a>Classes

|||
|-|-|
|[bad_variant_access](../standard-library/bad-variant-access-class.md)|Objetos lançados para relatar acessos inválidos ao valor de um objeto Variant.|
|[variant](../standard-library/variant.md)|Um objeto para manter um valor de um de seus tipos alternativos ou nenhum valor.|

### <a name="structs"></a>Estruturas

|||
|-|-|
|[hash](../standard-library/hash-structure.md)||
|[monoestado](../standard-library/monostate-structure.md)|Um tipo alternativo para uma variante para tornar o tipo de variante padrão constructible.|
|[uses_allocator](../standard-library/uses-allocator-structure.md)||
|[variant_alternative](../standard-library/variant-alternative-structure.md)|Ajuda os objetos variantes.|
|[variant_size](../standard-library/variant-size-structure.md)|Ajuda os objetos variantes.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[variant_npos](../standard-library/variant-functions.md#variant_npos)||

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
