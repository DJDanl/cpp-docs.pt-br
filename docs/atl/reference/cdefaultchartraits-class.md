---
title: Classe CDefaultChartraits
ms.date: 11/04/2016
f1_keywords:
- CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits::CharToLower
- ATLCOLL/ATL::CDefaultCharTraits::CharToUpper
helpviewer_keywords:
- CDefaultCharTraits class
ms.assetid: f94a3934-597f-401d-8513-ed6924ae069a
ms.openlocfilehash: 40c4d107d05e6d7b610e7c46be920d91d8fe6086
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327100"
---
# <a name="cdefaultchartraits-class"></a>Classe CDefaultChartraits

Esta classe fornece duas funções estáticas para converter caracteres entre maiúsculas e minúsculas.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CDefaultCharTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultchartraits::Chartolower](#chartolower)|(Estática) Chame esta função para converter um caractere em maiúsculas.|
|[CDefaultchartraits::Chartoupper](#chartoupper)|(Estática) Chame esta função para converter um caractere em minúsculas.|

## <a name="remarks"></a>Comentários

Esta classe fornece funções que são utilizadas pela classe [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cdefaultchartraitschartolower"></a><a name="chartolower"></a>CDefaultchartraits::Chartolower

Chame esta função para converter um caractere em minúsculas.

```
static wchar_t CharToLower(wchar_t x);
static char CharToLower(char x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O caractere a ser convertido em minúsculas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#132](../../atl/codesnippet/cpp/cdefaultchartraits-class_1.cpp)]

## <a name="cdefaultchartraitschartoupper"></a><a name="chartoupper"></a>CDefaultchartraits::Chartoupper

Chame esta função para converter um caractere em maiúsculas.

```
static wchar_t CharToUpper(wchar_t x);
static char CharToUpper(char x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O caractere a ser convertido em maiúsculas.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
