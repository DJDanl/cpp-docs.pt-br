---
title: Classe CDefaultCharTraits
ms.date: 11/04/2016
f1_keywords:
- CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits::CharToLower
- ATLCOLL/ATL::CDefaultCharTraits::CharToUpper
helpviewer_keywords:
- CDefaultCharTraits class
ms.assetid: f94a3934-597f-401d-8513-ed6924ae069a
ms.openlocfilehash: fe599ee0e84c393bed656b7304fd13d55ce95a50
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57296105"
---
# <a name="cdefaultchartraits-class"></a>Classe CDefaultCharTraits

Essa classe fornece duas funções estáticas para a conversão de caracteres entre letras maiusculas e minúsculas.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CDefaultCharTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultCharTraits::CharToLower](#chartolower)|(Estático) Chame essa função para converter um caractere em maiusculas.|
|[CDefaultCharTraits::CharToUpper](#chartoupper)|(Estático) Chame essa função para converter um caractere em minúsculas.|

## <a name="remarks"></a>Comentários

Essa classe fornece funções que são utilizadas pela classe [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="chartolower"></a>  CDefaultCharTraits::CharToLower

Chame essa função para converter um caractere em minúsculas.

```
static wchar_t CharToLower(wchar_t x);
static char CharToLower(char x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O caractere a ser convertido em minúsculas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#132](../../atl/codesnippet/cpp/cdefaultchartraits-class_1.cpp)]

##  <a name="chartoupper"></a>  CDefaultCharTraits::CharToUpper

Chame essa função para converter um caractere em maiusculas.

```
static wchar_t CharToUpper(wchar_t x);
static char CharToUpper(char x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O caractere a ser convertido em maiúsculas.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
