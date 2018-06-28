---
title: Classe CMFCBaseToolBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCBaseToolBar
- AFXBASETOOLBAR/CMFCBaseToolBar
- AFXBASETOOLBAR/CMFCBaseToolBar::GetDockingMode
- AFXBASETOOLBAR/CMFCBaseToolBar::GetMinSize
- AFXBASETOOLBAR/CMFCBaseToolBar::OnAfterChangeParent
dev_langs:
- C++
helpviewer_keywords:
- CMFCBaseToolBar [MFC], GetDockingMode
- CMFCBaseToolBar [MFC], GetMinSize
- CMFCBaseToolBar [MFC], OnAfterChangeParent
ms.assetid: 5d79206d-55e4-46f8-b1b8-042e34d7f9da
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 597adf6d7a32b537f31f9a824049dc9ffedf899f
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37037838"
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
|[CMFCBaseToolBar::OnAfterChangeParent](#onafterchangeparent)|Chamado pelo framework depois das alterações do pai do painel. (Substitui [CBasePane::OnAfterChangeParent](../../mfc/reference/cbasepane-class.md#onafterchangeparent).)|  
  
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
 [out] *tamanho*  
 O tamanho mínimo de uma barra de ferramentas.  
  
##  <a name="onafterchangeparent"></a>  CMFCBaseToolBar::OnAfterChangeParent  
 Chamado pelo framework depois das alterações do pai do painel.  
  
```  
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pWndOldParent*  
 Um ponteiro para a janela pai anterior.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
