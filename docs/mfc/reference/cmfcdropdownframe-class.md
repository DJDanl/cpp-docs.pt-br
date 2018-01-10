---
title: Classe CMFCDropDownFrame | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDropDownFrame
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::Create
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::GetParentMenuBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::GetParentPopupMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::RecalcLayout
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::SetAutoDestroy
dev_langs: C++
helpviewer_keywords:
- CMFCDropDownFrame [MFC], Create
- CMFCDropDownFrame [MFC], GetParentMenuBar
- CMFCDropDownFrame [MFC], GetParentPopupMenu
- CMFCDropDownFrame [MFC], RecalcLayout
- CMFCDropDownFrame [MFC], SetAutoDestroy
ms.assetid: 09ff81a9-de00-43ec-9df9-b626f7728c4b
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 01b3e5b56621d7bf8d42aad12e216208338bbacd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcdropdownframe-class"></a>Classe CMFCDropDownFrame
Fornece a funcionalidade de janela do quadro da lista suspensa barras de ferramentas de lista suspensa e botões de barra de ferramentas de lista suspensa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDropDownFrame : public CMiniFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDropDownFrame::CMFCDropDownFrame`|Construtor padrão.|  
|`CMFCDropDownFrame::~CMFCDropDownFrame`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCDropDownFrame::Create](#create)|Cria um objeto `CMFCDropDownFrame`.|  
|`CMFCDropDownFrame::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCDropDownFrame::GetParentMenuBar](#getparentmenubar)|Recupera a barra de menus do pai do quadro de lista suspensa.|  
|[CMFCDropDownFrame::GetParentPopupMenu](#getparentpopupmenu)|Recupera o menu pop-up do pai do quadro de lista suspensa.|  
|`CMFCDropDownFrame::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCDropDownFrame::RecalcLayout](#recalclayout)|Reposiciona o quadro da lista suspensa.|  
|[CMFCDropDownFrame::SetAutoDestroy](#setautodestroy)|Define se a janela de ferramentas de lista suspensa filho é destruída automaticamente.|  
  
### <a name="remarks"></a>Comentários  
 Essa classe não se destina a ser usada diretamente do seu código.  
  
 A estrutura usa essa classe para fornecer um comportamento de quadro para o `CMFCDropDownToolbar` e `CMFCDropDownToolbarButton` classes. Para obter mais informações sobre essas classes, consulte [CMFCDropDownToolBar classe](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [CMFCDropDownToolbarButton classe](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um `CMFCDropDownFrame` de objeto um `CFrameWnd` classe e como definir o filho janela suspensa da barra de ferramentas a ser destruído automaticamente.  
  
 [!code-cpp[NVC_MFC_RibbonApp#36](../../mfc/reference/codesnippet/cpp/cmfcdropdownframe-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)  
  
 [CMFCDropDownFrame](../../mfc/reference/cmfcdropdownframe-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
##  <a name="create"></a>CMFCDropDownFrame::Create  
 Cria um objeto `CMFCDropDownFrame`.  
  
```  
virtual BOOL Create(
    CWnd* pWndParent,  
    int x,  
    int y,  
    CMFCDropDownToolBar* pWndOriginToolbar);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pWndParent`|A janela pai do quadro de lista suspensa.|  
|[in] `x`|A coordenada horizontal da tela para o local do quadro suspensa.|  
|[in] `y`|A coordenada vertical da tela para o local do quadro suspensa.|  
|[in] `pWndOriginToolbar`|A barra de ferramentas tem os botões de menu suspenso que usa esse método para popular o novo objeto de quadro da lista suspensa.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o quadro da lista suspensa foi criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método chama a base de [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método para criar a janela do quadro de lista suspensa com o `WS_POPUP` estilo. A janela do quadro da lista suspensa é exibida em coordenadas especificadas da tela. Esse método falhar se o [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método retornará `FALSE`.  
  
 O `CMFCDropDownFrame` classe cria uma cópia do fornecido `CMFCDropDownToolBar` parâmetro. Esse método copia as imagens de botão e os estados de botão do `pWndOriginToolbar` parâmetro para o `m_pWndOriginToolbar` membro de dados.  
  
##  <a name="getparentmenubar"></a>CMFCDropDownFrame::GetParentMenuBar  
 Recupera a barra de menus do pai do quadro de lista suspensa.  
  
```  
CMFCMenuBar* GetParentMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a barra de menus do pai do quadro, o menu suspenso ou `NULL` se o quadro não tem nenhum pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna a barra de menus do pai do botão pai. Este método retorna `NULL` se o quadro da lista suspensa não tem nenhum botão pai ou no botão pai nenhuma barra de menus do pai.  
  
##  <a name="getparentpopupmenu"></a>CMFCDropDownFrame::GetParentPopupMenu  
 Recupera o menu pop-up do pai do quadro de lista suspensa.  
  
```  
CMFCDropDownFrame* GetParentPopupMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o menu suspenso de pai do quadro, o menu suspenso ou `NULL` se o quadro não tem nenhum pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna o menu pai do botão pai. Este método retorna `NULL` se o quadro da lista suspensa não tem nenhum botão pai ou no botão pai nenhum menu pai.  
  
##  <a name="recalclayout"></a>CMFCDropDownFrame::RecalcLayout  
 Reposiciona o quadro da lista suspensa.  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `bNotify`|Não utilizado.|  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o quadro da lista suspensa é criado ou a janela pai é redimensionada. Esse método calcula a posição e o tamanho do quadro suspensa usando a posição e o tamanho da janela pai.  
  
##  <a name="setautodestroy"></a>CMFCDropDownFrame::SetAutoDestroy  
 Define se a janela de ferramentas de lista suspensa filho é destruída automaticamente.  
  
```  
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAutoDestroy`  
 `TRUE`para destruir automaticamente a janela de ferramentas de lista suspensa associada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se `bAutoDestroy` é `TRUE`, em seguida, o `CMFCDropDownFrame` destruidor destrói a janela de ferramentas de lista suspensa associada. O valor padrão é `TRUE`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)
