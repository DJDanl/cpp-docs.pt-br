---
title: classe _U_RECT
ms.date: 11/04/2016
f1_keywords:
- ATL::_U_RECT
- _U_RECT
- ATL._U_RECT
helpviewer_keywords:
- U_RECT class
- _U_RECT class
ms.assetid: 5f880a2d-09cf-4327-bf32-a3519c4dcd63
ms.openlocfilehash: 8a4d5b2a770b3f0ecfe10be0fbad22a702aa0531
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325805"
---
# <a name="_u_rect-class"></a>classe _U_RECT

Esta classe de adaptador de argumento permite que `RECT` ponteiros ou referências sejam passadas para uma função que é implementada em termos de ponteiros.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class _U_RECT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_RECT::_U_RECT](#_u_rect___u_rect)|O construtor.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_RECT:m_lpRect](#_u_rect__m_lprect)|Ponteiro para `RECT`um .|

## <a name="remarks"></a>Comentários

A classe define duas sobrecargas de construtores: uma aceita um **argumento DE RECT&** e a outra aceita um `LPRECT` argumento. A primeira construtora armazena o endereço do argumento de referência no membro único de dados da classe, [m_lpRect](#_u_rect__m_lprect). O argumento para o construtor de ponteiros é armazenado diretamente sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="_u_rectm_lprect"></a><a name="_u_rect__m_lprect"></a>_U_RECT:m_lpRect

A classe detém o valor repassado a `LPRECT` qualquer um de seus construtores como membro de dados públicos.

```
LPRECT m_lpRect;
```

## <a name="_u_rect_u_rect"></a><a name="_u_rect___u_rect"></a>_U_RECT::_U_RECT

O endereço do argumento de referência é armazenado no membro único de dados da classe, [m_lpRect](#_u_rect__m_lprect).

```
_U_RECT(RECT& rc);
_U_RECT(LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Rc*<br/>
Uma referência a `RECT`.

*Lprect*<br/>
Um `RECT` ponteiro.

### <a name="remarks"></a>Comentários

O argumento para o construtor de ponteiros é armazenado diretamente sem conversão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
