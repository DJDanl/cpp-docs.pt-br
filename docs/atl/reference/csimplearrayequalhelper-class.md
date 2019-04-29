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
ms.openlocfilehash: 8b7e32ddab5b2f0667b17b0f127ac2e7e5d9a426
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62277988"
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

*t1*<br/>
Um objeto do tipo T.

*t2*<br/>
Um objeto do tipo T.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

## <a name="see-also"></a>Consulte também

[Classe CSimpleArray](../../atl/reference/csimplearray-class.md)<br/>
[Classe CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
