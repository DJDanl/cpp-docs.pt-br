---
title: CSimpleMapEqualHelper Class
ms.date: 11/04/2016
f1_keywords:
- CSimpleMapEqualHelper
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper::IsEqualKey
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper::IsEqualValue
helpviewer_keywords:
- CSimpleMapEqualHelper class
ms.assetid: 9bb2968a-d609-405c-8272-ff3b42df6164
ms.openlocfilehash: d137a35a517ea93139f036f6e9a7a8de06d518a7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330743"
---
# <a name="csimplemapequalhelper-class"></a>CSimpleMapEqualHelper Class

Esta classe é um ajudante para a classe [CSimpleMap.](../../atl/reference/csimplemap-class.md)

## <a name="syntax"></a>Sintaxe

```
template <class TKey, class TVal>
class CSimpleMapEqualHelper
```

#### <a name="parameters"></a>Parâmetros

*TKey*<br/>
O elemento chave.

*Tval*<br/>
O elemento de valor.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMapEqualHelper::IsEqualKey](#isequalkey)|(Estática) Testa duas chaves para igualdade.|
|[CSimpleMapEqualHelper::IsEqualValue](#isequalvalue)|(Estática) Testa dois valores para a igualdade.|

## <a name="remarks"></a>Comentários

Esta aula de traços `CSimpleMap` é um suplemento para a classe. Ele fornece métodos para `CSimpleMap` comparar dois elementos de objeto (especificamente, os componentes chave e valor) para a igualdade. Por padrão, as chaves e valores são comparados usando **operator==()**, mas se o mapa contém tipos de dados complexos que não possuem seu próprio operador de igualdade, esta classe pode ser substituída para fornecer a funcionalidade extra necessária.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="csimplemapequalhelperisequalkey"></a><a name="isequalkey"></a>CSimpleMapEqualHelper::IsEqualKey

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

## <a name="csimplemapequalhelperisequalvalue"></a><a name="isequalvalue"></a>CSimpleMapEqualHelper::IsEqualValue

Testa dois valores para a igualdade.

```
static bool IsEqualValue(const TVal& v1, const TVal& v2);
```

### <a name="parameters"></a>Parâmetros

*v1*<br/>
O primeiro valor.

*v2*<br/>
O segundo valor.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os valores são iguais, falsos de outra forma.

## <a name="see-also"></a>Confira também

[CSimpleMapEqualHelperFalsa Classe](../../atl/reference/csimplemapequalhelperfalse-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
