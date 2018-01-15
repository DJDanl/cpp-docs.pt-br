---
title: Classe CMFCDropDownToolBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::AllowShowOnPaneMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::LoadBitmap
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::LoadToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnLButtonUp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnMouseMove
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnSendCommand
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnUpdateCmdUI
dev_langs: C++
helpviewer_keywords:
- CMFCDropDownToolBar [MFC], AllowShowOnPaneMenu
- CMFCDropDownToolBar [MFC], LoadBitmap
- CMFCDropDownToolBar [MFC], LoadToolBar
- CMFCDropDownToolBar [MFC], OnLButtonUp
- CMFCDropDownToolBar [MFC], OnMouseMove
- CMFCDropDownToolBar [MFC], OnSendCommand
- CMFCDropDownToolBar [MFC], OnUpdateCmdUI
ms.assetid: 78818ec5-83ce-42fa-a0d4-2d9d5ecc8770
caps.latest.revision: "37"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7a2f53fa75d8637445e155043d6a40787402accb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcdropdowntoolbar-class"></a>Classe CMFCDropDownToolBar
Uma barra de ferramentas é exibida quando o usuário pressiona e mantém um botão de barra de ferramentas de nível superior.  
  
   [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDropDownToolBar : public CMFCToolBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDropDownToolBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|  
|[CMFCDropDownToolBar::LoadBitmap](#loadbitmap)|(Substitui [CMFCToolBar::LoadBitmap](../../mfc/reference/cmfctoolbar-class.md#loadbitmap).)|  
|[CMFCDropDownToolBar::LoadToolBar](#loadtoolbar)|(Substitui [CMFCToolBar::LoadToolBar](../../mfc/reference/cmfctoolbar-class.md#loadtoolbar).)|  
|[CMFCDropDownToolBar::OnLButtonUp](#onlbuttonup)||  
|[CMFCDropDownToolBar::OnMouseMove](#onmousemove)||  
|[CMFCDropDownToolBar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|  
|[CMFCDropDownToolBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [CMFCToolBar::OnUpdateCmdUI](http://msdn.microsoft.com/en-us/571a38ab-2a56-4968-9796-273516126f80).)|  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCDropDownToolBar` objeto combina a aparência visual de uma barra de ferramentas com o comportamento de um menu pop-up. Quando o usuário pressiona e mantém um botão de barra de ferramentas de lista suspensa (consulte [CMFCDropDownToolbarButton classe](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)), uma barra de ferramentas do menu suspenso é exibido e o usuário pode selecionar um botão da barra de ferramentas lista suspensa, rolando a ele e liberar o mouse botão. Depois que o usuário seleciona um botão na barra de ferramentas lista suspensa, esse botão é exibido como o botão atual na barra de nível superior.  
  
 Uma barra de ferramentas de lista suspensa não pode ser personalizada ou encaixada, e não tem um estado destacável.  
  
 A ilustração a seguir mostra um `CMFCDropDownToolBar` objeto:  
  
 ![Exemplo de CMFCDropDownToolbar](../../mfc/reference/media/cmfcdropdown.png "cmfcdropdown")  
  
 Você cria um `CMFCDropDownToolBar` da mesma maneira que você cria uma barra de ferramentas comuns de objeto (consulte [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md)).  
  
 Para inserir a barra de ferramentas de lista suspensa em uma barra de ferramentas do pai:  
  
 1. Reserve uma ID de recurso fictício do botão no recurso pai da barra de ferramentas.  
  
 2. Criar um `CMFCDropDownToolBarButton` objeto que contém a barra de ferramentas de lista suspensa (para obter mais informações, consulte [CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md#cmfcdropdowntoolbarbutton)).  
  
 3. Substitua o botão fictício com o `CMFCDropDownToolBarButton` objeto usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).  
  
 Para obter mais informações sobre os botões da barra de ferramentas, consulte [passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md). Para obter um exemplo de uma barra de ferramentas do menu suspenso, consulte o projeto de exemplo VisualStudioDemo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CMFCDropDownToolBar` classe. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#29](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#30](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
##  <a name="allowshowonpanemenu"></a>CMFCDropDownToolBar::AllowShowOnPaneMenu  

  
```  
virtual BOOL AllowShowOnPaneMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="loadbitmap"></a>CMFCDropDownToolBar::LoadBitmap  
 Carrega imagens da barra de ferramentas de recursos do aplicativo.  
  
```  
virtual BOOL LoadBitmap(
    UINT uiResID,  
    UINT uiColdResID=0,  
    UINT uiMenuResID=0,  
    BOOL bLocked=FALSE,  
    UINT uiDisabledResID=0,  
    UINT uiMenuDisabledResID=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 A ID de recurso do bitmap que se refere às imagens da barra de ferramentas ativa.  
  
 [in] `uiColdResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas frios.  
  
 [in] `uiMenuResID`  
 A ID de recurso do bitmap que se refere às imagens de menu comum.  
  
 [in] `bLocked`  
 `TRUE`para bloquear a barra de ferramentas. Caso contrário, `FALSE`.  
  
 [in] `uiDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens da barra de ferramentas desabilitado.  
  
 [in] `uiMenuDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens de menu desativado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCToolBar::LoadToolBarEx](../../mfc/reference/cmfctoolbar-class.md#loadtoolbarex) método chama esse método para carregar as imagens que estão associadas com a barra de ferramentas. Substitua este método para executar o carregamento personalizado de recursos de imagem.  
  
 Chamar o `LoadBitmapEx` método carregar imagens adicionais depois de criar a barra de ferramentas.  
  
##  <a name="loadtoolbar"></a>CMFCDropDownToolBar::LoadToolBar  

  
```  
virtual BOOL LoadToolBar(
    UINT uiResID,  
    UINT uiColdResID = 0,  
    UINT uiMenuResID = 0,
    BOOL = FALSE,  
    UINT uiDisabledResID = 0,  
    UINT uiMenuDisabledResID = 0,  
    UINT uiHotResID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 [in] `uiColdResID`  
 [in] `uiMenuResID`  
 [in] `BOOL`  
 [in] `uiDisabledResID`  
 [in] `uiMenuDisabledResID`  
 [in] `uiHotResID`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onlbuttonup"></a>CMFCDropDownToolBar::OnLButtonUp  

  
```  
afx_msg void OnLButtonUp(
    UINT nFlags,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nFlags`  
 [in] `point`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onmousemove"></a>CMFCDropDownToolBar::OnMouseMove  

  
```  
afx_msg void OnMouseMove(
    UINT nFlags,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nFlags`  
 [in] `point`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onsendcommand"></a>CMFCDropDownToolBar::OnSendCommand  

  
```  
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onupdatecmdui"></a>CMFCDropDownToolBar::OnUpdateCmdUI  

  
```  
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,  
    BOOL bDisableIfNoHndler);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTarget`  
 [in] `bDisableIfNoHndler`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [CMFCToolBar::Create](../../mfc/reference/cmfctoolbar-class.md#create)   
 [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)   
 [Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



