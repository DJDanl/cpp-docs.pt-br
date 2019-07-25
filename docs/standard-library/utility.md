---
title: '&lt;utility&gt;'
ms.date: 11/04/2016
f1_keywords:
- <utility>
helpviewer_keywords:
- utility header
ms.assetid: c4491103-5da9-47a1-9c2b-ed8bc64b0599
ms.openlocfilehash: eaae94bcffcda6e113001dd7070bcc80e7c14d09
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458075"
---
# <a name="ltutilitygt"></a>&lt;utility&gt;

Define os tipos, funções e operadores da Biblioteca Padrão C++ que ajudam a construir e gerenciar pares de objetos úteis sempre que dois objetos precisam ser tratados como se fossem um.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<utility>

**Namespace:** std

## <a name="remarks"></a>Comentários

Os pares são amplamente usados na Biblioteca Padrão C++. Eles são necessários como os argumentos e valores retornados para diversas funções e como tipos de elemento para contêineres como a [classe map](../standard-library/map-class.md) e a [classe multimap](../standard-library/multimap-class.md). O cabeçalho \<utility> é incluído automaticamente por \<map> para auxiliar no gerenciamento de elementos do tipo par chave/valor.

> [!NOTE]
> O \<cabeçalho > do utilitário usa a `#include <initializer_list>`instrução. Ele também se refere `class tuple` como definido em \<> de tupla.

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|-|
|[chars_format](../standard-library/chars-format-class.md)|Formato de ponto flutuante para conversão numérica primitiva.|
|[tuple_element](../standard-library/tuple-element-class-tuple.md)|Uma classe que encapsula o tipo de um elemento `pair`.|
|[tuple_size](../standard-library/tuple-size-class-tuple.md)|Uma classe que encapsula a contagem do elemento `pair`.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[index_sequence](../standard-library/utility-functions.md#index_sequence)||
|[index_sequence_for](../standard-library/utility-functions.md#index_sequence_for)||
|[make_index_sequence](../standard-library/utility-functions.md#make_index_sequence)||
|[make_integer_sequence](../standard-library/utility-functions.md#make_integer_sequence)||

### <a name="functions"></a>Funções

|||
|-|-|
|[as_const](../standard-library/utility-functions.md#asconst)|Retorna o tipo.|
|[declval](../standard-library/utility-functions.md#declval)|Avaliação de expressão abreviada.|
|[exchange](../standard-library/utility-functions.md#exchange)|Atribui um novo valor a um objeto e retorna seu valor antigo.|
|[forward](../standard-library/utility-functions.md#forward)|Evita que o tipo de referência (`lvalue` ou `rvalue`) do argumento seja obscurecido por encaminhamento perfeito.|
|[from_chars](../standard-library/utility-functions.md#from_chars)||
|[get](../standard-library/utility-functions.md#get)|Uma função que obtém um elemento de um objeto `pair`.|
|[make_pair](../standard-library/utility-functions.md#make_pair)|Uma função modelo auxiliar usada para construir objetos do tipo `pair`, em que os tipos de componente são baseados nos tipos de dados transmitidos como parâmetros.|
|[move](../standard-library/utility-functions.md#move)|Retorna o que foi passado no argumento como uma referência `rvalue`.|
|[move_if_noexcept](../standard-library/utility-functions.md#moveif)||
|[swap](../standard-library/utility-functions.md#swap)|Troca os elementos de dois objetos `pair`.|
|[to_chars](../standard-library/utility-functions.md#to_chars)|Converte o valor em uma cadeia de caracteres.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/utility-operators.md#op_neq)|Testa se o objeto pair à esquerda do operador é diferente do objeto pair à direita.|
|[operator==](../standard-library/utility-operators.md#op_eq_eq)|Testa se o objeto pair à esquerda do operador é igual ao objeto pair à direita.|
|[operator\<](../standard-library/utility-operators.md#op_lt)|Testa se o objeto pair à esquerda do operador é menor que o objeto pair à direita.|
|[operator\<=](../standard-library/utility-operators.md#op_gt_eq)|Testa se o objeto pair à esquerda do operador é menor que ou igual ao objeto pair à direita.|
|[operator>](../standard-library/utility-operators.md#op_gt)|Testa se o objeto pair à esquerda do operador é maior que o objeto pair à direita.|
|[operator>=](../standard-library/utility-operators.md#op_gt_eq)|Testa se o objeto pair à esquerda do operador é maior que ou igual ao objeto pair à direita.|

### <a name="structs"></a>Structs

|||
|-|-|
|[from_chars_result](../standard-library/from-chars-result-structure.md)|Um struct usado para `from_chars`o.|
|[identity](../standard-library/identity-structure.md)|Um struct que fornece uma definição de tipo como o parâmetro do modelo.|
|[in_place_t](../standard-library/in-place-t-struct.md)|Também inclui structs `in_place_type_t` e `in_place_index_t`.|
|[integer_sequence](../standard-library/integer-sequence-class.md)|Representa uma sequência de inteiros.|
|[pair](../standard-library/pair-structure.md)|Um tipo que fornece a capacidade de tratar dois objetos como um único objeto.|
|[piecewise_construct_t](../standard-library/piecewise-construct-t-structure.md)|Um tipo usado para manter o Construtor separado e a sobrecarga de função.|
|[to_chars_result](../standard-library/to-chars-result-structure.md)|Um struct usado para `to_chars`o.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
