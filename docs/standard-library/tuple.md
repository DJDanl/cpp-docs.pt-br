---
title: '&lt;tuple&gt;'
ms.date: 11/04/2016
f1_keywords:
- <tuple>
helpviewer_keywords:
- tuple header
ms.assetid: e4ef5c2d-318b-44f6-8bce-fce4ecd796a3
ms.openlocfilehash: a391a77ea65a203a7eddde12046c5df89a77194a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447156"
---
# <a name="lttuplegt"></a>&lt;tuple&gt;

Define um modelo `tuple` cujas instâncias mantêm objetos de tipos variados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<tuple>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|[Classe tuple](../standard-library/tuple-class.md)|Encapsula uma sequência de comprimento fixo de elementos.|
|[Classe tuple_element](../standard-library/tuple-element-class-tuple.md)|Encapsula o tipo de um elemento `tuple`.|
|[Classe tuple_size](../standard-library/tuple-size-class-tuple.md)|Encapsula contagem de elemento `tuple`.|
|[uses_allocator](../standard-library/uses-allocator-structure.md)||

### <a name="objects"></a>Objetos

|||
|-|-|
|[tuple_element_t](../standard-library/tuple-functions.md#tuple_element_t)||
|[tuple_size_v](../standard-library/tuple-functions.md#tuple_size_v)||

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/tuple-operators.md#op_eq_eq)|Comparação de `tuple` objetos, igual.|
|[operator!=](../standard-library/tuple-operators.md#op_neq)|Comparação de `tuple` objetos, não igual.|
|[operator<](../standard-library/tuple-operators.md#op_lt)|Comparação de `tuple` objetos, menor que.|
|[operator<=](../standard-library/tuple-operators.md#op_lt_eq)|Comparação de `tuple` objetos, menor ou igual a.|
|[operator>](../standard-library/tuple-operators.md#op_gt)|Comparação de `tuple` objetos, maior que.|
|[operator>=](../standard-library/tuple-operators.md#op_gt_eq)|Comparação de `tuple` objetos, maior ou igual a.|

### <a name="functions"></a>Funções

|||
|-|-|
|[apply](../standard-library/tuple-functions.md#apply)|Chama uma função com uma tupla.|
|[forward_as_tuple](../standard-library/tuple-functions.md#forward)|Constrói uma tupla de referências.|
|[get](../standard-library/tuple-functions.md#get)|Obtém um elemento de um objeto `tuple`.|
|[make_from_tuple](../standard-library/tuple-functions.md#make_from_tuple)|Abreviar para criar `tuple`um.|
|[make_tuple](../standard-library/tuple-functions.md#make_tuple)|Constitui uma `tuple` dos valores de elemento.|
|[swap](../standard-library/tuple-functions.md#swap)||
|[tie](../standard-library/tuple-functions.md#tie)|Constitui um `tuple` das referências do elemento.|
|[tuple_cat](../standard-library/tuple-functions.md#tuple_cat)|Constrói um objeto de tupla com um intervalo dos elementos de tipo.|

## <a name="see-also"></a>Consulte também

[\<array>](../standard-library/array.md)
