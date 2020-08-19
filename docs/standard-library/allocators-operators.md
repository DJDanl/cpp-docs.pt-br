---
title: Operadores &lt;alocadores&gt;
ms.date: 11/04/2016
f1_keywords:
- allocators/std::operator!=
- allocators/std::operator==
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
ms.openlocfilehash: 2d2f928ab3773ed8e0b0afdc0113db2ef5b2a3dd
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561212"
---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;

Essas são as funções de operador de modelo global definidas em &lt; alocadores &gt; . Para funções de operador de membro de classe, consulte a documentação da classe.

|||
|-|-|
|[operador! =](#op_neq)|[operador = =](#op_eq_eq)|

## <a name="operator"></a><a name="op_neq"></a> operador! =

Testa a desigualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator!=(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Um dos objetos alocadores a serem testados quanto à desigualdade.

*Certo*\
Um dos objetos alocadores a serem testados quanto à desigualdade.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos de alocador não forem iguais; **`false`** se os objetos de alocador forem iguais.

### <a name="remarks"></a>Comentários

O operador de modelo retorna `!(left == right)`.

## <a name="operator"></a><a name="op_eq_eq"></a> operador = =

Testa a igualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator==(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Um dos objetos alocadores a serem testados quanto à igualdade.

*Certo*\
Um dos objetos alocadores a serem testados quanto à igualdade.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos de alocador forem iguais; **`false`** se os objetos de alocador não forem iguais.

### <a name="remarks"></a>Comentários

Esse operador de modelo retorna `left.equals(right)`.

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
