---
title: classe _U_MENUorID
ms.date: 11/04/2016
f1_keywords:
- ATL._U_MENUorID
- ATL::_U_MENUorID
- _U_MENUorID
helpviewer_keywords:
- U_MENUorID class
- _U_MENUorID class
ms.assetid: cfc8032b-61b4-4a68-ba3a-92b82500ccae
ms.openlocfilehash: 419c9e79178db12efe278838ec8630e04ac3c461
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325834"
---
# <a name="_u_menuorid-class"></a>classe _U_MENUorID

Esta classe fornece invólucros para `CreateWindow` e `CreateWindowEx`.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class _U_MENUorID
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_MENUorID:_U_MENUorID](#_u_menuorid___u_menuorid)|O construtor.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_MENUorID:m_hMenu](#_u_menuorid__m_hmenu)|Uma alça para um menu.|

## <a name="remarks"></a>Comentários

Esta classe de adaptador de argumento permite que IDs (UINTs) ou alças de menu (HMENUs) sejam passadas para uma função sem exigir um elenco explícito por parte do chamador.

Esta classe foi projetada para implementar invólucros na API do Windows, particularmente as funções [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) e [CreateWindowEx,](/windows/win32/api/winuser/nf-winuser-createwindowexw) ambas aceitam um argumento HMENU que pode ser um identificador de janela filho (UINT) em vez de uma alça de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl::Create](cwindowimpl-class.md#create).

A classe define duas sobrecargas de construtores: uma aceita um argumento UINT e a outra aceita um argumento HMENU. O argumento UINT é apenas lançado para um HMENU na construtora e o resultado armazenado no membro único de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu). O argumento para o construtor HMENU é armazenado diretamente sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="_u_menuoridm_hmenu"></a><a name="_u_menuorid__m_hmenu"></a>_U_MENUorID:m_hMenu

A classe detém o valor repassado a qualquer um de seus construtores como membro público de dados HMENU.

```
HMENU m_hMenu;
```

## <a name="_u_menuorid_u_menuorid"></a><a name="_u_menuorid___u_menuorid"></a>_U_MENUorID:_U_MENUorID

O argumento UINT é apenas lançado para um HMENU na construtora e o resultado armazenado no membro único de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu).

```
_U_MENUorID(UINT nID);
_U_MENUorID(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Um identificador de janela infantil.

*Hmenu*<br/>
Uma alça de menu.

### <a name="remarks"></a>Comentários

O argumento para o construtor HMENU é armazenado diretamente sem conversão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
