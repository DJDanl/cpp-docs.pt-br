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
ms.openlocfilehash: 386b005777b3e31dd74916a41bc5af2ab82df210
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330873"
---
# <a name="csimplearrayequalhelper-class"></a>Classe CSimpleArrayEqualHelper

Esta classe é um ajudante para a classe [CSimpleArray.](../../atl/reference/csimplearray-class.md)

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CSimpleArrayEqualHelper
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArrayEqualHelper::IsEqual](#isequal)|(Estática) Testa `CSimpleArray` dois elementos de objeto para igualdade.|

## <a name="remarks"></a>Comentários

Esta aula de traços `CSimpleArray` é um suplemento para a classe. Ele fornece um método para comparar `CSimpleArray` dois elementos armazenados em um objeto. Por padrão, os elementos são comparados usando **operator=()**, mas se a matriz contém tipos de dados complexos que não possuem seu próprio operador de igualdade, você precisará substituir essa classe.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="csimplearrayequalhelperisequal"></a><a name="isequal"></a>CSimpleArrayEqualHelper::IsEqual

Testa `CSimpleArray` dois elementos de objeto para igualdade.

```
static bool IsEqual(
    const T& t1,
    const T& t2);
```

### <a name="parameters"></a>Parâmetros

*T1*<br/>
Um objeto do tipo T.

*t2*<br/>
Um objeto do tipo T.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os elementos são iguais, falsos de outra forma.

## <a name="see-also"></a>Confira também

[Classe CSimpleArray](../../atl/reference/csimplearray-class.md)<br/>
[CSimpleArrayEqualHelperClasse false](../../atl/reference/csimplearrayequalhelperfalse-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
