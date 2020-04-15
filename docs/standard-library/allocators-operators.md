---
title: Operadores &lt;alocadores&gt;
ms.date: 11/04/2016
f1_keywords:
- allocators/std::operator!=
- allocators/std::operator==
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
ms.openlocfilehash: 7bc37e98ed85582cac8fc7ae21e54a6d5da9e06f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364960"
---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;

Estas são as funções &lt;globais do&gt;operador de modelo definidas em alocadores . Para as funções de operador de classe, consulte a documentação da classe.

|||
|-|-|
|[operador!=](#op_neq)|[operador==](#op_eq_eq)|

## <a name="operator"></a><a name="op_neq"></a>operador!=

Testa a desigualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator!=(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Deixou*|Um dos objetos alocadores a serem testados quanto à desigualdade.|
|*Certo*|Um dos objetos alocadores a serem testados quanto à desigualdade.|

### <a name="return-value"></a>Valor retornado

**true** se os objetos alocadores não forem iguais, **false** se eles forem iguais.

### <a name="remarks"></a>Comentários

O operador de modelo retorna `!(left == right)`.

## <a name="operator"></a><a name="op_eq_eq"></a>operador==

Testa a igualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator==(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Deixou*|Um dos objetos alocadores a serem testados quanto à igualdade.|
|*Certo*|Um dos objetos alocadores a serem testados quanto à igualdade.|

### <a name="return-value"></a>Valor retornado

**true** se os objetos alocadores forem iguais, **false** se eles não forem iguais.

### <a name="remarks"></a>Comentários

Esse operador de modelo retorna `left.equals(right)`.

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
