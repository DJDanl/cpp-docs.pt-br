---
title: Classe u_rect
ms.date: 11/04/2016
f1_keywords:
- ATL::_U_RECT
- _U_RECT
- ATL._U_RECT
helpviewer_keywords:
- U_RECT class
- _U_RECT class
ms.assetid: 5f880a2d-09cf-4327-bf32-a3519c4dcd63
ms.openlocfilehash: 306092a00a1e119263f4563eea181d7d3ee2b4b2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326368"
---
# <a name="urect-class"></a>Classe u_rect

Essa classe de adaptador do argumento permite tanto `RECT` ponteiros ou referências a serem passados para uma função que é implementada em termos de ponteiros.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class _U_RECT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_RECT::_U_RECT](#_u_rect___u_rect)|O construtor.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_RECT::m_lpRect](#_u_rect__m_lprect)|Ponteiro para um `RECT`.|

## <a name="remarks"></a>Comentários

A classe define duas sobrecargas de construtor: uma aceita um **RECT &** argumento e o outro aceita um `LPRECT` argumento. O primeiro construtor armazena o endereço do argumento de referência no membro de dados único da classe, [m_lpRect](#_u_rect__m_lprect). O argumento para o construtor do ponteiro é armazenado diretamente, sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="_u_rect__m_lprect"></a>  _U_RECT::m_lpRect

A classe contém o valor passado para qualquer um dos seus construtores como pública `LPRECT` membro de dados.

```
LPRECT m_lpRect;
```

##  <a name="_u_rect___u_rect"></a>  _U_RECT::_U_RECT

O endereço do argumento de referência é armazenado no membro de dados único da classe, [m_lpRect](#_u_rect__m_lprect).

```
_U_RECT(RECT& rc);
_U_RECT(LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*rc*<br/>
Uma referência a `RECT`.

*lpRect*<br/>
Um `RECT` ponteiro.

### <a name="remarks"></a>Comentários

O argumento para o construtor do ponteiro é armazenado diretamente, sem conversão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
