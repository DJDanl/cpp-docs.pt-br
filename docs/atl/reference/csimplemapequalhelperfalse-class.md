---
title: Classe CSimpleMapEqualHelperFalse
ms.date: 11/04/2016
f1_keywords:
- CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualKey
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualValue
helpviewer_keywords:
- CSimpleMapEqualHelperFalse class
ms.assetid: a873eea3-e130-45cc-a476-61ee79511c3b
ms.openlocfilehash: 9c4241049ad323047f06c0b29f946521f2c02167
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62277888"
---
# <a name="csimplemapequalhelperfalse-class"></a>Classe CSimpleMapEqualHelperFalse

Essa classe é um auxiliar para o [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.

## <a name="syntax"></a>Sintaxe

```
template <class TKey, class TVal>
class CSimpleMapEqualHelperFalse
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMapEqualHelperFalse::IsEqualKey](#isequalkey)|(Estático) Testes de duas chaves quanto à igualdade.|
|[CSimpleMapEqualHelperFalse::IsEqualValue](#isequalvalue)|(Estático) Retorna falso.|

## <a name="remarks"></a>Comentários

Essa classe de características é um suplemento para o `CSimpleMap` classe. Ele fornece um método para comparar dois elementos contidos no `CSimpleMap` objeto, especificamente dois elementos de valor ou os dois elementos principais.

A comparação de valor sempre retornará false e, além disso, irá chamar `ATLASSERT` com um argumento de false se ele nunca é referenciado. Em situações em que o teste de igualdade não está suficientemente definido, essa classe permite que um mapa que contém pares chave/valor para operar corretamente para a maioria dos métodos, mas falhar de maneira bem definida para os métodos que dependem de comparações, como [CSimpleMap:: FindVal](../../atl/reference/csimplemap-class.md#findval).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

##  <a name="isequalkey"></a>  CSimpleMapEqualHelperFalse::IsEqualKey

Testes de duas chaves quanto à igualdade.

```
static bool IsEqualKey(const TKey& k1, const TKey& k2);
```

### <a name="parameters"></a>Parâmetros

*k1*<br/>
A primeira chave.

*k2*<br/>
A segunda chave.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se as chaves são iguais, caso contrário, false.

### <a name="remarks"></a>Comentários

Este método chama [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md).

##  <a name="isequalvalue"></a>  CSimpleMapEqualHelperFalse::IsEqualValue

Retorna false.

```
static bool IsEqualValue(const TVal&, const TVal&);
```

### <a name="return-value"></a>Valor de retorno

Retorna false.

### <a name="remarks"></a>Comentários

Esse método sempre retorna false e chamará `ATLASSERT` com um argumento de false se ele nunca é referenciado. A finalidade de `CSimpleMapEqualHelperFalse::IsEqualValue` é forçar métodos usando comparações falhe de maneira bem definida, quando os testes de igualdade não foram definidos adequadamente.

## <a name="see-also"></a>Consulte também

[Classe CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
