---
title: Classe CMFCDropDownFrame | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
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
dev_langs:
- C++
helpviewer_keywords:
- CMFCDropDownFrame class
ms.assetid: 09ff81a9-de00-43ec-9df9-b626f7728c4b
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5f045e4a3b580f12e64758737495c32963bea6db
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcdropdownframe-class"></a>Classe CMFCDropDownFrame
Fornece a funcionalidade de janela suspensa quadro suspensa barras de ferramentas e botões de barra de ferramentas da lista suspensa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDropDownFrame : public CMiniFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
|`CMFCDropDownFrame::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCDropDownFrame::GetParentMenuBar](#getparentmenubar)|Recupera a barra de menus do pai do quadro de lista suspensa.|  
|[CMFCDropDownFrame::GetParentPopupMenu](#getparentpopupmenu)|Recupera o menu pop-up do pai do quadro de lista suspensa.|  
|`CMFCDropDownFrame::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCDropDownFrame::RecalcLayout](#recalclayout)|Reposiciona o quadro de lista suspensa.|  
|[CMFCDropDownFrame::SetAutoDestroy](#setautodestroy)|Define se a janela de ferramentas de lista suspensa filho é destruída automaticamente.|  
  
### <a name="remarks"></a>Comentários  
 Essa classe não se destina a ser usada diretamente no seu código.  
  
 A estrutura usa essa classe para fornecer um comportamento de quadro para o `CMFCDropDownToolbar` e `CMFCDropDownToolbarButton` classes. Para obter mais informações sobre essas classes, consulte [CMFCDropDownToolBar classe](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [CMFCDropDownToolbarButton classe](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um `CMFCDropDownFrame` de objeto um `CFrameWnd` classe e como definir o filho janela suspensa da barra de ferramentas a ser destruído automaticamente.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#36;](../../mfc/reference/codesnippet/cpp/cmfcdropdownframe-class_1.cpp)]  
  
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
|[in] `pWndOriginToolbar`|A barra de ferramentas tem os botões de lista suspensa que usa esse método para preencher o novo objeto de quadro da lista suspensa.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o quadro de lista suspensa foi criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama base [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método para criar a janela do quadro de lista suspensa com o `WS_POPUP` estilo. A janela de quadro da lista suspensa aparece nas coordenadas de tela especificado. Esse método falhará se o [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método retorna `FALSE`.  
  
 O `CMFCDropDownFrame` classe cria uma cópia do fornecidas `CMFCDropDownToolBar` parâmetro. Esse método copia as imagens de botão e os estados do botão do `pWndOriginToolbar` parâmetro para o `m_pWndOriginToolbar` membro de dados.  
  
##  <a name="getparentmenubar"></a>CMFCDropDownFrame::GetParentMenuBar  
 Recupera a barra de menus do pai do quadro de lista suspensa.  
  
```  
CMFCMenuBar* GetParentMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a barra de menus do pai do quadro, o menu suspenso ou `NULL` se o quadro não tem nenhum pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera a barra de menus do pai do botão pai. Esse método retorna `NULL` se o quadro suspensa não tem nenhum botão pai ou no botão pai nenhuma barra de menu pai.  
  
##  <a name="getparentpopupmenu"></a>CMFCDropDownFrame::GetParentPopupMenu  
 Recupera o menu pop-up do pai do quadro de lista suspensa.  
  
```  
CMFCDropDownFrame* GetParentPopupMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o menu suspenso de pai do quadro, o menu suspenso ou `NULL` se o quadro não tem nenhum pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera menu pai do botão pai. Esse método retorna `NULL` se o quadro suspensa não tem nenhum botão pai ou no botão pai nenhum menu pai.  
  
##  <a name="recalclayout"></a>CMFCDropDownFrame::RecalcLayout  
 Reposiciona o quadro de lista suspensa.  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `bNotify`|Não utilizado.|  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o quadro de lista suspensa é criado ou a janela pai é redimensionada. Esse método calcula a posição e o tamanho do quadro suspensa usando a posição e o tamanho da janela pai.  
  
##  <a name="setautodestroy"></a>CMFCDropDownFrame::SetAutoDestroy  
 Define se a janela de ferramentas de lista suspensa filho é destruída automaticamente.  
  
```  
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAutoDestroy`  
 `TRUE`destruir automaticamente a janela de ferramentas de lista suspensa associada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se `bAutoDestroy` é `TRUE`, o `CMFCDropDownFrame` destruidor destrói a janela de ferramentas de lista suspensa associada. O valor padrão é `TRUE`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)

