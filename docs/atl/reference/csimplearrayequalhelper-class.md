---
title: Classe CSimpleArrayEqualHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper::IsEqual
dev_langs:
- C++
helpviewer_keywords:
- CSimpleArrayEqualHelper class
ms.assetid: a2b55d89-78c9-42ef-842c-5304c6d20ad6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 87b23ba46ee4a8e25c15b4d9e51b87c444da67f1
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758209"
---
# <a name="csimplearrayequalhelper-class"></a>Classe CSimpleArrayEqualHelper

Essa classe é um auxiliar para o [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.

## <a name="syntax"></a>Sintaxe

```
template <class T>  
class CSimpleArrayEqualHelper
```

#### <a name="parameters"></a>Parâmetros

`T`  
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

*T1*  
Um objeto do tipo T.

*T2*  
Um objeto do tipo T.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

## <a name="see-also"></a>Consulte também

[Classe CSimpleArray](../../atl/reference/csimplearray-class.md)   
[Classe CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
