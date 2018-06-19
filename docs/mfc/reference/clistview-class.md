---
title: Classe CListView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CListView
- AFXCVIEW/CListView
- AFXCVIEW/CListView::CListView
- AFXCVIEW/CListView::GetListCtrl
- AFXCVIEW/CListView::RemoveImageList
dev_langs:
- C++
helpviewer_keywords:
- CListView [MFC], CListView
- CListView [MFC], GetListCtrl
- CListView [MFC], RemoveImageList
ms.assetid: 7626bdb2-a1b8-4eab-b631-6743710a8432
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3930ad915ff908b8931733a9f0362320e24dc2cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33366337"
---
# <a name="clistview-class"></a>Classe CListView
Simplifica o uso do controle de lista e de [CListCtrl](../../mfc/reference/clistctrl-class.md), a classe que encapsula a funcionalidade de controle de lista, com a arquitetura do modo de exibição de documentos do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CListView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListView::CListView](#clistview)|Constrói um objeto `CListView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListView::GetListCtrl](#getlistctrl)|Retorna o controle de lista associado com o modo de exibição.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListView::RemoveImageList](#removeimagelist)|Remove a lista de imagem especificado da exibição de lista.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre essa arquitetura, consulte a visão geral para o [CView](../../mfc/reference/cview-class.md) classe e as referências cruzadas citadas existe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CListView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcview.h  
  
##  <a name="clistview"></a>  CListView::CListView  
 Constrói um objeto `CListView`.  
  
```  
CListView();
```  
  
##  <a name="getlistctrl"></a>  CListView::GetListCtrl  
 Chame essa função de membro para obter uma referência para o controle de lista associado com o modo de exibição.  
  
```  
CListCtrl& GetListCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o controle de lista associado com o modo de exibição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView#7](../../atl/reference/codesnippet/cpp/clistview-class_1.cpp)]  
  
##  <a name="removeimagelist"></a>  CListView::RemoveImageList  
 Remove a lista de imagem especificado da exibição de lista.  
  
```  
void RemoveImageList(int nImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nImageList`  
 O índice baseado em zero da imagem a ser removido.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC ROWLIST](../../visual-cpp-samples.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)
