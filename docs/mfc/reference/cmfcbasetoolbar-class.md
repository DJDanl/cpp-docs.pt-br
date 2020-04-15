---
title: Classe CMFCBaseToolBar
ms.date: 11/04/2016
f1_keywords:
- CMFCBaseToolBar
- AFXBASETOOLBAR/CMFCBaseToolBar
- AFXBASETOOLBAR/CMFCBaseToolBar::GetDockingMode
- AFXBASETOOLBAR/CMFCBaseToolBar::GetMinSize
- AFXBASETOOLBAR/CMFCBaseToolBar::OnAfterChangeParent
helpviewer_keywords:
- CMFCBaseToolBar [MFC], GetDockingMode
- CMFCBaseToolBar [MFC], GetMinSize
- CMFCBaseToolBar [MFC], OnAfterChangeParent
ms.assetid: 5d79206d-55e4-46f8-b1b8-042e34d7f9da
ms.openlocfilehash: 027fe8569ff133bb3f348c9d0607f19c6d778c4e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367838"
---
# <a name="cmfcbasetoolbar-class"></a>Classe CMFCBaseToolBar

Classe base para barras de ferramentas.

## <a name="syntax"></a>Sintaxe

```
class CMFCBaseToolBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCBaseToolBar::CMFCBaseToolBar`|Construtor padrão.|
|`CMFCBaseToolBar::~CMFCBaseToolBar`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCBaseToolBar::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCBaseToolBar::GetDockingMode](#getdockingmode)|Retorna o modo de acoplamento. (Substitui [cbasepane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).)|
|[CMFCBaseToolBar::GetMinSize](#getminsize)|Retorna o tamanho mínimo de uma barra de ferramentas. (Substitui [cpane::GetMinSize](../../mfc/reference/cpane-class.md#getminsize).)|
|[CMFCBaseToolbar::OnafterChangeParent](#onafterchangeparent)|Chamado pelo framework após as mudanças dos paido painel. (Substitui [cbasepane::OnAfterChangeParent](../../mfc/reference/cbasepane-class.md#onafterchangeparent).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetoolbar.h

## <a name="cmfcbasetoolbargetdockingmode"></a><a name="getdockingmode"></a>CMFCBaseToolBar::GetDockingMode

Retorna o modo de acoplamento.

```
virtual AFX_DOCK_TYPE GetDockingMode() const;
```

### <a name="return-value"></a>Valor retornado

O modo de acoplamento.

## <a name="cmfcbasetoolbargetminsize"></a><a name="getminsize"></a>CMFCBaseToolBar::GetMinSize

Retorna o tamanho mínimo de uma barra de ferramentas.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
[fora] O tamanho mínimo de uma barra de ferramentas.

## <a name="cmfcbasetoolbaronafterchangeparent"></a><a name="onafterchangeparent"></a>CMFCBaseToolbar::OnafterChangeParent

Chamado pelo framework após as mudanças dos paido painel.

```
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```

### <a name="parameters"></a>Parâmetros

*pWndOldParent*<br/>
[em] Um ponteiro para a janela dos pais anteriores.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
