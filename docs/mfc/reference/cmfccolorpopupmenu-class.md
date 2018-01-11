---
title: Classe CMFCColorPopupMenu | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::CreateTearOffBar
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::GetMenuBar
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::SetPropList
dev_langs: C++
helpviewer_keywords:
- CMFCColorPopupMenu [MFC], CMFCColorPopupMenu
- CMFCColorPopupMenu [MFC], CreateTearOffBar
- CMFCColorPopupMenu [MFC], GetMenuBar
- CMFCColorPopupMenu [MFC], SetPropList
ms.assetid: 0bf9efe8-aed5-4ab7-b23b-eb284b4668be
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f91c8a6929ada133b3c2ab9f6fc26e9477a88d6b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfccolorpopupmenu-class"></a>Classe CMFCColorPopupMenu
Representa um menu pop-up que os usuários usam para selecionar as cores em um documento ou aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorPopupMenu : public CMFCPopupMenu  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCColorPopupMenu::CMFCColorPopupMenu](#cmfccolorpopupmenu)|Constrói um objeto `CMFCColorPopupMenu`.|  
|`CMFCColorPopupMenu::~CMFCColorPopupMenu`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCColorPopupMenu::CreateTearOffBar](#createtearoffbar)|Cria uma barra de cores destacável acoplável. (Substitui [CMFCPopupMenu::CreateTearOffBar](../../mfc/reference/cmfcpopupmenu-class.md#createtearoffbar).)|  
|[CMFCColorPopupMenu::GetMenuBar](#getmenubar)|Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que é inserido no menu pop-up. (Substitui [CMFCPopupMenu::GetMenuBar](../../mfc/reference/cmfcpopupmenu-class.md#getmenubar).)|  
|`CMFCColorPopupMenu::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCColorPopupMenu::SetPropList](#setproplist)|Define o objeto de controle de grade de propriedade do embedded `CMFCColorBar` objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`m_bEnabledInCustomizeMode`|Um valor booleano que determina se deve mostrar a barra de cores.|  
|`m_wndColorBar`|O `CMFCColorBar` objeto que fornece uma seleção de cor.|  
  
### <a name="remarks"></a>Comentários  
 Esta classe herda a funcionalidade do menu pop-up do `CMFCPopupMenu` classe e gerencia um `CMFCColorBar` objeto que fornece uma seleção de cor. Quando a estrutura da barra de ferramentas está no modo de personalização e `m_bEnabledInCustomizeMode` membro é definido como `FALSE`, o objeto de barra de cores não é mostrado. Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)  
  
 Para obter mais informações sobre `CMFCColorBar`, consulte [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)  
  
 [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)  
  
 [CMFCColorPopupMenu](../../mfc/reference/cmfccolorpopupmenu-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolorpopupmenu.h  
  
##  <a name="cmfccolorpopupmenu"></a>CMFCColorPopupMenu::CMFCColorPopupMenu  
 Constrói um objeto `CMFCColorPopupMenu`.  
  
```  
CMFCColorPopupMenu(
    const CArray<COLORREF, COLORREF>& colors,  
    COLORREF color,  
    LPCTSTR lpszAutoColor,  
    LPCTSTR lpszOtherColor,  
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,  
    int nColumns,  
    int nHorzDockRows,  
    int nVertDockColumns,  
    COLORREF colorAutomatic,  
    UINT uiCommandID,  
    BOOL bStdColorDlg = FALSE);

 
CMFCColorPopupMenu(
    CMFCColorButton* pParentBtn,  
    const CArray<COLORREF, COLORREF>& colors,  
    COLORREF color,  
    LPCTSTR lpszAutoColor,  
    LPCTSTR lpszOtherColor,  
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,  
    int nColumns,  
    COLORREF colorAutomatic);

 
CMFCColorPopupMenu(
    CMFCRibbonColorButton* pParentBtn,  
    const CArray<COLORREF, COLORREF>& colors,  
    COLORREF color,  
    LPCTSTR lpszAutoColor,  
    LPCTSTR lpszOtherColor,  
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,  
    int nColumns,  
    COLORREF colorAutomatic,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `colors`  
 Uma matriz de cores exibe a estrutura no menu pop-up.  
  
 [in] `color`  
 A cor padrão selecionado.  
  
 [in] `lpszAutoColor`  
 O rótulo de texto a *automático* botão de cor (padrão), ou `NULL`.  
  
 O rótulo padrão para o botão automático é **automática**.  
  
 [in] `lpszOtherColor`  
 O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou `NULL`.  
  
 O rótulo padrão para o outro botão é **mais cores...** .  
  
 [in] `lpszDocColors`  
 O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que atualmente usa o documento.  
  
 [in] `lstDocColors`  
 Uma lista de cores que atualmente usa o documento.  
  
 [in] `nColumns`  
 O número de colunas que tem a matriz de cores.  
  
 [in] `nHorzDockRows`  
 O número de linhas que a barra de cores tem quando ela estiver encaixada horizontalmente.  
  
 [in] `nVertDockColumns`  
 O número de colunas da barra de cores com quando ela estiver encaixada verticalmente.  
  
 [in] `colorAutomatic`  
 A cor padrão que se aplica a estrutura de quando você clica no botão automático.  
  
 [in] `uiCommandID`  
 ID do comando de controle de barra de cores.  
  
 [in] `bStdColorDlg`  
 Um valor booleano que indica se a caixa de diálogo de cor padrão do sistema ou o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo.  
  
 [in] `pParentBtn`  
 Um ponteiro para um botão de pai.  
  
 [in] `nID`  
 A ID de comando.  
  
### <a name="remarks"></a>Comentários  
 Cada sobrecarregado construtor define o `m_bEnabledInCustomizeMode` membro `FALSE`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCColorPopupMenu` objeto.  
  
 [!code-cpp[NVC_MFC_RibbonApp#34](../../mfc/reference/codesnippet/cpp/cmfccolorpopupmenu-class_1.cpp)]  
  
##  <a name="createtearoffbar"></a>CMFCColorPopupMenu::CreateTearOffBar  
 Cria uma barra de cores destacável acoplável.  
  
```  
virtual CPane* CreateTearOffBar(
    CFrameWnd* pWndMain,  
    UINT uiID,  
    LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pWndMain`|Ponteiro para a janela pai da barra destacável.|  
|[in] `uiID`|A ID de comando da barra destacável.|  
|[in] `lpszName`|O texto da janela da barra destacável.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o novo objeto barra destacável controle.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria um [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) do objeto e converte-o para um [CPane classe](../../mfc/reference/cpane-class.md) ponteiro. Você pode converter esse valor para um [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) ponteiro usando um das macros de conversão descritas em [tipo de conversão de objetos de classe MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md).  
  
##  <a name="getmenubar"></a>CMFCColorPopupMenu::GetMenuBar  
 Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que é inserido no menu pop-up.  
  
```  
virtual CMFCPopupMenuBar* GetMenuBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o item inserido `CMFCPopupMenuBar`.  
  
### <a name="remarks"></a>Comentários  
 No menu pop-up de cor foi inserida [CMFCPopupMenuBar classe](../../mfc/reference/cmfcpopupmenubar-class.md) objeto. Substitua este método em uma classe derivada, se seu aplicativo usa um tipo diferente de incorporado.  
  
##  <a name="setproplist"></a>CMFCColorPopupMenu::SetPropList  
 Define o objeto de controle de grade de propriedade do embedded `CMFCColorBar` objeto.  
  
```  
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndList`  
 Ponteiro para um objeto de controle de grade de propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
