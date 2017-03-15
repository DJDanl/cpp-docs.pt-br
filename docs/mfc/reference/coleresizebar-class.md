---
title: Classe COleResizeBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleResizeBar
dev_langs:
- C++
helpviewer_keywords:
- OLE items, resizing
- in-place items
- in-place items, resizing
- resizing in-place OLE items
- control bars, resizing
- COleResizeBar class
ms.assetid: 56a708d9-28c5-4eb0-9404-77b688d91c63
caps.latest.revision: 23
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 99ba53c771d018b8c69c5951703b9d6f7b4afe9b
ms.lasthandoff: 02/25/2017

---
# <a name="coleresizebar-class"></a>Classe COleResizeBar
Um tipo de barra de controle que oferece suporte ao redimensionamento de itens OLE no local.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleResizeBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleResizeBar::COleResizeBar](#coleresizebar)|Constrói um objeto `COleResizeBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleResizeBar::Create](#create)|Cria e inicializa uma janela filho do Windows e associa-o para o `COleResizeBar` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `COleResizeBar`os objetos aparecem como uma [CRectTracker](../../mfc/reference/crecttracker-class.md) com uma borda tracejada e externa alças de redimensionamento.  
  
 `COleResizeBar`objetos são geralmente incorporados membros dos objetos de janela com moldura derivados de [COleIPFrameWnd](../../mfc/reference/coleipframewnd-class.md) classe.  
  
 Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `COleResizeBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-namecoleresizebara--coleresizebarcoleresizebar"></a><a name="coleresizebar"></a>COleResizeBar::COleResizeBar  
 Constrói um objeto `COleResizeBar`.  
  
```  
COleResizeBar();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar **criar** para criar o objeto de barra de redimensionamento.  
  
##  <a name="a-namecreatea--coleresizebarcreate"></a><a name="create"></a>COleResizeBar::Create  
 Cria uma janela filho e o associa a `COleResizeBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE,  
    UINT nID = AFX_IDW_RESIZE_BAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para a janela pai da barra de redimensionamento.  
  
 `dwStyle`  
 Especifica o [estilo de janela](../../mfc/reference/window-styles.md) atributos.  
  
 `nID`  
 ID da janela de filho da barra de redimensionamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de redimensionamento foi criada; Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC SUPERPAD](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)

