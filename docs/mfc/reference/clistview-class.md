---
title: Classe CListView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CListView
dev_langs:
- C++
helpviewer_keywords:
- views, and common controls
- CListView class
ms.assetid: 7626bdb2-a1b8-4eab-b631-6743710a8432
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: ebf6c93aa6d88d1942af4ecb9e3373fa57d84b65
ms.lasthandoff: 02/25/2017

---
# <a name="clistview-class"></a>Classe CListView
Simplifica o uso do controle de lista e de [CListCtrl](../../mfc/reference/clistctrl-class.md), a classe que encapsula a funcionalidade de controle de lista, com a arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CListView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
|[CListView::RemoveImageList](#removeimagelist)|Remove a lista de imagem especificada na exibição de lista.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre essa arquitetura, consulte a visão geral para o [CView](../../mfc/reference/cview-class.md) classe e as referências cruzadas citadas lá.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CListView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcview.h  
  
##  <a name="a-nameclistviewa--clistviewclistview"></a><a name="clistview"></a>CListView::CListView  
 Constrói um objeto `CListView`.  
  
```  
CListView();
```  
  
##  <a name="a-namegetlistctrla--clistviewgetlistctrl"></a><a name="getlistctrl"></a>CListView::GetListCtrl  
 Chame essa função de membro para obter uma referência para o controle de lista associado com o modo de exibição.  
  
```  
CListCtrl& GetListCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o controle de lista associado com o modo de exibição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView&#7;](../../atl/reference/codesnippet/cpp/clistview-class_1.cpp)]  
  
##  <a name="a-nameremoveimagelista--clistviewremoveimagelist"></a><a name="removeimagelist"></a>CListView::RemoveImageList  
 Remove a lista de imagem especificada na exibição de lista.  
  
```  
void RemoveImageList(int nImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nImageList`  
 O índice baseado em zero da imagem para remover.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC ROWLIST](../../visual-cpp-samples.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)

