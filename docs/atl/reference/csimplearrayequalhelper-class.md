---
title: Classe CSimpleArrayEqualHelper
ms.date: 11/04/2016
f1_keywords:
- CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper::IsEqual
helpviewer_keywords:
- CSimpleArrayEqualHelper class
ms.assetid: a2b55d89-78c9-42ef-842c-5304c6d20ad6
ms.openlocfilehash: e677a5d12918649597db9614b965118f8d6b7da6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50656217"
---
# <a name="csimplearrayequalhelper-class"></a>Classe CSimpleArrayEqualHelper

Essa classe é um auxiliar para o [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CSimpleArrayEqualHelper
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArrayEqualHelper::IsEqual](#isequal)|(Estático) Testa dois `CSimpleArray` igualdade de elementos do objeto.|

## <a name="remarks"></a>Comentários

Essa classe de características é um suplemento para o `CSimpleArray` classe. Ele fornece um método para comparar dois elementos armazenados em um `CSimpleArray` objeto. Por padrão, os elementos são comparados usando **operator=()**, mas se a matriz contiver tipos de dados complexos que não têm seu próprios operador de igualdade, você precisará substituir essa classe.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

##  <a name="isequal"></a>  CSimpleArrayEqualHelper::IsEqual

Testa dois `CSimpleArray` igualdade de elementos do objeto.

```
static bool IsEqual(
    const T& t1,
    const T& t2);
```

### <a name="parameters"></a>Parâmetros

*T1*<br/>
Um objeto do tipo T.

*T2*<br/>
Um objeto do tipo T.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

## <a name="see-also"></a>Consulte também

[Classe CSimpleArray](../../atl/reference/csimplearray-class.md)<br/>
[Classe CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
