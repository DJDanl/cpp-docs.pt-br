---
title: Classe CTreeView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTreeView
- AFXCVIEW/CTreeView
- AFXCVIEW/CTreeView::CTreeView
- AFXCVIEW/CTreeView::GetTreeCtrl
dev_langs:
- C++
helpviewer_keywords:
- CTreeView [MFC], CTreeView
- CTreeView [MFC], GetTreeCtrl
ms.assetid: 5df583a6-d69f-42ca-9d8d-57e04558afff
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7530569d5e5313ebfcbdaf92ebd245962b9e443c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ctreeview-class"></a>Classe CTreeView
Simplifica o uso do controle de árvore e [CTreeCtrl](../../mfc/reference/ctreectrl-class.md), a classe que encapsula a funcionalidade de controle de árvore, com a arquitetura do modo de exibição de documentos do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTreeView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTreeView::CTreeView](#ctreeview)|Constrói um objeto `CTreeView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTreeView::GetTreeCtrl](#gettreectrl)|Retorna o controle de árvore associado à exibição.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre essa arquitetura, consulte a visão geral para o [CView](../../mfc/reference/cview-class.md) classe e as referências cruzadas citadas existe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CTreeView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcview.h  
  
##  <a name="ctreeview"></a>CTreeView::CTreeView  
 Constrói um objeto `CTreeView`.  
  
```  
CTreeView();
```  
  
##  <a name="gettreectrl"></a>CTreeView::GetTreeCtrl  
 Retorna uma referência para o controle de árvore associada à exibição.  
  
```  
CTreeCtrl& GetTreeCtrl() const;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)
