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
ms.openlocfilehash: 84756eb177fcec1981f3f2ed018d57eb27df9823
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523690"
---
# <a name="cmfcbasetoolbar-class"></a>Classe CMFCBaseToolBar

Classe base para as barras de ferramentas.

## <a name="syntax"></a>Sintaxe

```
class CMFCBaseToolBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCBaseToolBar::CMFCBaseToolBar`|Construtor padrão.|
|`CMFCBaseToolBar::~CMFCBaseToolBar`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCBaseToolBar::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCBaseToolBar::GetDockingMode](#getdockingmode)|Retorna o modo de encaixe. (Substitui [CBasePane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).)|
|[CMFCBaseToolBar::GetMinSize](#getminsize)|Retorna o tamanho mínimo de uma barra de ferramentas. (Substitui [CPane::GetMinSize](../../mfc/reference/cpane-class.md#getminsize).)|
|[CMFCBaseToolBar::OnAfterChangeParent](#onafterchangeparent)|Chamado pelo framework após as alterações do pai do painel. (Substitui [CBasePane::OnAfterChangeParent](../../mfc/reference/cbasepane-class.md#onafterchangeparent).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetoolbar.h

##  <a name="getdockingmode"></a>  CMFCBaseToolBar::GetDockingMode

Retorna o modo de encaixe.

```
virtual AFX_DOCK_TYPE GetDockingMode() const;
```

### <a name="return-value"></a>Valor de retorno

O modo de encaixe.

##  <a name="getminsize"></a>  CMFCBaseToolBar::GetMinSize

Retorna o tamanho mínimo de uma barra de ferramentas.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
[out] O tamanho mínimo de uma barra de ferramentas.

##  <a name="onafterchangeparent"></a>  CMFCBaseToolBar::OnAfterChangeParent

Chamado pelo framework após as alterações do pai do painel.

```
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```

### <a name="parameters"></a>Parâmetros

*pWndOldParent*<br/>
[in] Um ponteiro para a janela pai anterior.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
