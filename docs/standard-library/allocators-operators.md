---
title: Operadores &lt;alocadores&gt;
ms.date: 11/04/2016
f1_keywords:
- allocators/std::operator!=
- allocators/std::operator==
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
ms.openlocfilehash: a21708ca090b0db561391308f347d90b77c62645
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623565"
---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;

Essas são as funções de operador de modelo global definidas em &lt; alocadores &gt; . Para funções de operador de membro de classe, consulte a documentação da classe.

|||
|-|-|
|[operador! =](#op_neq)|[operador = =](#op_eq_eq)|

## <a name="operator"></a><a name="op_neq"></a>operador! =

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
|*mantida*|Um dos objetos alocadores a serem testados quanto à desigualdade.|
|*Certo*|Um dos objetos alocadores a serem testados quanto à desigualdade.|

### <a name="return-value"></a>Valor Retornado

**true** se os objetos alocadores não forem iguais, **false** se eles forem iguais.

### <a name="remarks"></a>Comentários

O operador de modelo retorna `!(left == right)`.

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

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
|*mantida*|Um dos objetos alocadores a serem testados quanto à igualdade.|
|*Certo*|Um dos objetos alocadores a serem testados quanto à igualdade.|

### <a name="return-value"></a>Valor Retornado

**true** se os objetos alocadores forem iguais, **false** se eles não forem iguais.

### <a name="remarks"></a>Comentários

Esse operador de modelo retorna `left.equals(right)`.

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
