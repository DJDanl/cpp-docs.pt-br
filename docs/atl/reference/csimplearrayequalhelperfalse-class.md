---
title: CSimpleArrayEqualHelperClasse false
ms.date: 11/04/2016
f1_keywords:
- CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse::IsEqual
helpviewer_keywords:
- CSimpleArrayEqualHelperFalse class
ms.assetid: 6918af6f-d23d-49eb-8482-c44272f5ffeb
ms.openlocfilehash: 5eca3145d64895e34b599fbf83834af142b65973
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330886"
---
# <a name="csimplearrayequalhelperfalse-class"></a>CSimpleArrayEqualHelperClasse false

Esta classe é um ajudante para a classe [CSimpleArray.](../../atl/reference/csimplearray-class.md)

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CSimpleArrayEqualHelperFalse
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArrayEqualHelperFalse::IsEqual](#isequal)|(Estática) Retorna falso.|

## <a name="remarks"></a>Comentários

Essa aula de traços `CSimpleArray` é um complemento para a classe. Ele sempre retorna falso, e `ATLASSERT` além disso, vai ligar com um argumento de falso se ele for sempre referenciado. Em situações em que o teste de igualdade não é suficientemente definido, esta classe permite que uma matriz contendo elementos opere corretamente para a maioria dos métodos, mas falhe de forma bem definida para métodos que dependem de comparações como [CSimpleArray::Find](../../atl/reference/csimplearray-class.md#find).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="csimplearrayequalhelperfalseisequal"></a><a name="isequal"></a>CSimpleArrayEqualHelperFalse::IsEqual

Retorna false.

```
static bool IsEqual(const T&, const T&);
```

### <a name="return-value"></a>Valor retornado

Retorna false.

### <a name="remarks"></a>Comentários

Este método sempre retorna falso, e ligará `ATLASSERT` com um argumento falso se referenciado. O objetivo `CSimpleArrayEqualHelperFalse::IsEqual` é forçar métodos que utilizam comparações para falhar de forma bem definida quando os testes de igualdade não foram adequadamente definidos.

## <a name="see-also"></a>Confira também

[Classe CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
