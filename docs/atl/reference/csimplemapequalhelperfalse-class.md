---
title: CSimpleMapEqualHelperFalsa Classe
ms.date: 11/04/2016
f1_keywords:
- CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualKey
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualValue
helpviewer_keywords:
- CSimpleMapEqualHelperFalse class
ms.assetid: a873eea3-e130-45cc-a476-61ee79511c3b
ms.openlocfilehash: b6bf1d4e3be849004e13e593fb5f4b5cb87f8123
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330730"
---
# <a name="csimplemapequalhelperfalse-class"></a>CSimpleMapEqualHelperFalsa Classe

Esta classe é um ajudante para a classe [CSimpleMap.](../../atl/reference/csimplemap-class.md)

## <a name="syntax"></a>Sintaxe

```
template <class TKey, class TVal>
class CSimpleMapEqualHelperFalse
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMapEqualHelperFalse::IsEqualKey](#isequalkey)|(Estática) Testa duas chaves para igualdade.|
|[CSimpleMapEqualHelperFalse::IsEqualValue](#isequalvalue)|(Estática) Retorna falso.|

## <a name="remarks"></a>Comentários

Esta aula de traços `CSimpleMap` é um suplemento para a classe. Ele fornece um método para comparar `CSimpleMap` dois elementos contidos no objeto, especificamente dois elementos de valor ou dois elementos-chave.

A comparação de valor sempre retornará falsa, e além disso, ligará `ATLASSERT` com um argumento falso se ele for mencionado. Em situações em que o teste de igualdade não é suficientemente definido, esta classe permite que um mapa contendo pares de chave/valor opere corretamente para a maioria dos métodos, mas falhe de forma bem definida para métodos que dependem de comparações como [CSimpleMap::FindVal](../../atl/reference/csimplemap-class.md#findval).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="csimplemapequalhelperfalseisequalkey"></a><a name="isequalkey"></a>CSimpleMapEqualHelperFalse::IsEqualKey

Testa duas chaves para igualdade.

```
static bool IsEqualKey(const TKey& k1, const TKey& k2);
```

### <a name="parameters"></a>Parâmetros

*k1*<br/>
A primeira chave.

*k2*<br/>
A segunda chave.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se as chaves forem iguais, falsas de outra forma.

### <a name="remarks"></a>Comentários

Este método chama [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md).

## <a name="csimplemapequalhelperfalseisequalvalue"></a><a name="isequalvalue"></a>CSimpleMapEqualHelperFalse::IsEqualValue

Retorna false.

```
static bool IsEqualValue(const TVal&, const TVal&);
```

### <a name="return-value"></a>Valor retornado

Retorna false.

### <a name="remarks"></a>Comentários

Este método sempre retorna falso, e chamará `ATLASSERT` com um argumento falso se ele for sempre referenciado. O objetivo `CSimpleMapEqualHelperFalse::IsEqualValue` é forçar métodos que utilizam comparações para falhar de forma bem definida quando os testes de igualdade não foram adequadamente definidos.

## <a name="see-also"></a>Confira também

[CSimpleMapEqualHelper Class](../../atl/reference/csimplemapequalhelper-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
