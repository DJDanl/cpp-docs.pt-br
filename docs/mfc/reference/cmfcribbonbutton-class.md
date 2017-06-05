---
title: Classe CMFCRibbonButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonButton
- AFXRIBBONBUTTON/CMFCRibbonButton
- AFXRIBBONBUTTON/CMFCRibbonButton::CMFCRibbonButton
- AFXRIBBONBUTTON/CMFCRibbonButton::AddSubItem
- AFXRIBBONBUTTON/CMFCRibbonButton::CanBeStretched
- AFXRIBBONBUTTON/CMFCRibbonButton::CleanUpSizes
- AFXRIBBONBUTTON/CMFCRibbonButton::ClosePopupMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::DrawBottomText
- AFXRIBBONBUTTON/CMFCRibbonButton::DrawImage
- AFXRIBBONBUTTON/CMFCRibbonButton::DrawRibbonText
- AFXRIBBONBUTTON/CMFCRibbonButton::FindSubItemIndexByID
- AFXRIBBONBUTTON/CMFCRibbonButton::GetCommandRect
- AFXRIBBONBUTTON/CMFCRibbonButton::GetCompactSize
- AFXRIBBONBUTTON/CMFCRibbonButton::GetIcon
- AFXRIBBONBUTTON/CMFCRibbonButton::GetImageIndex
- AFXRIBBONBUTTON/CMFCRibbonButton::GetImageSize
- AFXRIBBONBUTTON/CMFCRibbonButton::GetIntermediateSize
- AFXRIBBONBUTTON/CMFCRibbonButton::GetMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::GetMenuRect
- AFXRIBBONBUTTON/CMFCRibbonButton::GetRegularSize
- AFXRIBBONBUTTON/CMFCRibbonButton::GetSubItems
- AFXRIBBONBUTTON/CMFCRibbonButton::GetTextRowHeight
- AFXRIBBONBUTTON/CMFCRibbonButton::GetToolTipText
- AFXRIBBONBUTTON/CMFCRibbonButton::HasCompactMode
- AFXRIBBONBUTTON/CMFCRibbonButton::HasIntermediateMode
- AFXRIBBONBUTTON/CMFCRibbonButton::HasLargeMode
- AFXRIBBONBUTTON/CMFCRibbonButton::HasMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::IsAlwaysDrawBorder
- AFXRIBBONBUTTON/CMFCRibbonButton::IsAlwaysLargeImage
- AFXRIBBONBUTTON/CMFCRibbonButton::IsApplicationButton
- AFXRIBBONBUTTON/CMFCRibbonButton::IsCommandAreaHighlighted
- AFXRIBBONBUTTON/CMFCRibbonButton::IsDefaultCommand
- AFXRIBBONBUTTON/CMFCRibbonButton::IsDefaultPanelButton
- AFXRIBBONBUTTON/CMFCRibbonButton::IsDrawTooltipImage
- AFXRIBBONBUTTON/CMFCRibbonButton::IsLargeImage
- AFXRIBBONBUTTON/CMFCRibbonButton::IsMenuAreaHighlighted
- AFXRIBBONBUTTON/CMFCRibbonButton::IsMenuOnBottom
- AFXRIBBONBUTTON/CMFCRibbonButton::IsPopupDefaultMenuLook
- AFXRIBBONBUTTON/CMFCRibbonButton::IsRightAlignMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::IsSingleLineText
- AFXRIBBONBUTTON/CMFCRibbonButton::OnCalcTextSize
- AFXRIBBONBUTTON/CMFCRibbonButton::OnDrawBorder
- AFXRIBBONBUTTON/CMFCRibbonButton::OnDraw
- AFXRIBBONBUTTON/CMFCRibbonButton::OnFillBackground
- AFXRIBBONBUTTON/CMFCRibbonButton::RemoveAllSubItems
- AFXRIBBONBUTTON/CMFCRibbonButton::RemoveSubItem
- AFXRIBBONBUTTON/CMFCRibbonButton::SetACCData
- AFXRIBBONBUTTON/CMFCRibbonButton::SetAlwaysLargeImage
- AFXRIBBONBUTTON/CMFCRibbonButton::SetDefaultCommand
- AFXRIBBONBUTTON/CMFCRibbonButton::SetDescription
- AFXRIBBONBUTTON/CMFCRibbonButton::SetImageIndex
- AFXRIBBONBUTTON/CMFCRibbonButton::SetMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::SetParentCategory
- AFXRIBBONBUTTON/CMFCRibbonButton::SetRightAlignMenu
- AFXRIBBONBUTTON/CMFCRibbonButton::SetText
- AFXRIBBONBUTTON/CMFCRibbonButton::OnClick
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonButton class
ms.assetid: 732e941c-9504-4b83-a691-d18075965d53
caps.latest.revision: 42
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
ms.openlocfilehash: 08672f10cf67a773f2af8d12130c4e3f5b497e11
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonbutton-class"></a>Classe CMFCRibbonButton
O `CMFCRibbonButton` classe implementa botões que você pode posicionar em elementos da barra de faixa de opções, como painéis, barras de ferramentas de acesso rápido e menus pop-up.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonButton : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonButton::CMFCRibbonButton](#cmfcribbonbutton)|Constrói um objeto de botão da faixa de opções.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonButton::AddSubItem](#addsubitem)|Adiciona um item de menu ao menu pop-up que é associado ao botão.|  
|[CMFCRibbonButton::CanBeStretched](#canbestretched)|(Substitui [CMFCRibbonBaseElement::CanBeStretched](../../mfc/reference/cmfcribbonbaseelement-class.md#canbestretched).)|  
|[CMFCRibbonButton::CleanUpSizes](#cleanupsizes)|(Substitui [CMFCRibbonBaseElement::CleanUpSizes](../../mfc/reference/cmfcribbonbaseelement-class.md#cleanupsizes).)|  
|[CMFCRibbonButton::ClosePopupMenu](#closepopupmenu)|(Substitui [CMFCRibbonBaseElement::ClosePopupMenu](../../mfc/reference/cmfcribbonbaseelement-class.md#closepopupmenu).)|  
|[CMFCRibbonButton::DrawBottomText](#drawbottomtext)||  
|[CMFCRibbonButton::DrawImage](#drawimage)|(Substitui [CMFCRibbonBaseElement::DrawImage](../../mfc/reference/cmfcribbonbaseelement-class.md#drawimage).)|  
|[CMFCRibbonButton::DrawRibbonText](#drawribbontext)||  
|[CMFCRibbonButton::FindSubItemIndexByID](#findsubitemindexbyid)|Retorna o índice de um item de menu pop-up que é associado à ID de comando especificado.|  
|[CMFCRibbonButton::GetCommandRect](#getcommandrect)||  
|[CMFCRibbonButton::GetCompactSize](#getcompactsize)|Retorna o tamanho compacto do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetCompactSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getcompactsize).)|  
|[CMFCRibbonButton::GetIcon](#geticon)||  
|[CMFCRibbonButton::GetImageIndex](#getimageindex)|Retorna o índice da imagem que está associada ao botão.|  
|[CMFCRibbonButton::GetImageSize](#getimagesize)|Retorna o tamanho da imagem do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetImageSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getimagesize).)|  
|[CMFCRibbonButton::GetIntermediateSize](#getintermediatesize)|Retorna o tamanho do elemento de faixa de opções em seu estado intermediário. (Substitui [CMFCRibbonBaseElement::GetIntermediateSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getintermediatesize).)|  
|[CMFCRibbonButton::GetMenu](#getmenu)|Retorna um identificador para um menu do Windows que é atribuído ao botão da faixa de opções.|  
|[CMFCRibbonButton::GetMenuRect](#getmenurect)||  
|[CMFCRibbonButton::GetRegularSize](#getregularsize)|Retorna o tamanho normal do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|  
|[CMFCRibbonButton::GetSubItems](#getsubitems)||  
|[CMFCRibbonButton::GetTextRowHeight](#gettextrowheight)||  
|[CMFCRibbonButton::GetToolTipText](#gettooltiptext)|Retorna o texto de dica de ferramenta do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetToolTipText](../../mfc/reference/cmfcribbonbaseelement-class.md#gettooltiptext).)|  
|[CMFCRibbonButton::HasCompactMode](#hascompactmode)|Especifica se o elemento de faixa de opções possui um modo compacto. (Substitui [CMFCRibbonBaseElement::HasCompactMode](../../mfc/reference/cmfcribbonbaseelement-class.md#hascompactmode).)|  
|[CMFCRibbonButton::HasIntermediateMode](#hasintermediatemode)|Especifica se o elemento de faixa de opções tem um modo de intermediário. (Substitui [CMFCRibbonBaseElement::HasIntermediateMode](../../mfc/reference/cmfcribbonbaseelement-class.md#hasintermediatemode).)|  
|[CMFCRibbonButton::HasLargeMode](#haslargemode)|Determina se o elemento de faixa de opções tem um grande modo. (Substitui [CMFCRibbonBaseElement::HasLargeMode](../../mfc/reference/cmfcribbonbaseelement-class.md#haslargemode).)|  
|[CMFCRibbonButton::HasMenu](#hasmenu)|(Substitui [CMFCRibbonBaseElement::HasMenu](../../mfc/reference/cmfcribbonbaseelement-class.md#hasmenu).)|  
|[CMFCRibbonButton::IsAlwaysDrawBorder](#isalwaysdrawborder)||  
|[CMFCRibbonButton::IsAlwaysLargeImage](#isalwayslargeimage)|(Substitui [CMFCRibbonBaseElement::IsAlwaysLargeImage](../../mfc/reference/cmfcribbonbaseelement-class.md#isalwayslargeimage).)|  
|[CMFCRibbonButton::IsApplicationButton](#isapplicationbutton)||  
|[CMFCRibbonButton::IsCommandAreaHighlighted](#iscommandareahighlighted)||  
|[CMFCRibbonButton::IsDefaultCommand](#isdefaultcommand)|Determina se você tiver habilitado o comando padrão para um botão da faixa de opções.|  
|[CMFCRibbonButton::IsDefaultPanelButton](#isdefaultpanelbutton)||  
|[CMFCRibbonButton::IsDrawTooltipImage](#isdrawtooltipimage)||  
|[CMFCRibbonButton::IsLargeImage](#islargeimage)||  
|[CMFCRibbonButton::IsMenuAreaHighlighted](#ismenuareahighlighted)||  
|[CMFCRibbonButton::IsMenuOnBottom](#ismenuonbottom)||  
|[CMFCRibbonButton::IsPopupDefaultMenuLook](#ispopupdefaultmenulook)||  
|[CMFCRibbonButton::IsRightAlignMenu](#isrightalignmenu)|Determina se o menu é alinhado à direita.|  
|[CMFCRibbonButton::IsSingleLineText](#issinglelinetext)||  
|[CMFCRibbonButton::OnCalcTextSize](#oncalctextsize)|(Substitui [CMFCRibbonBaseElement::OnCalcTextSize](../../mfc/reference/cmfcribbonbaseelement-class.md#oncalctextsize).)|  
|[CMFCRibbonButton::OnDrawBorder](#ondrawborder)||  
|[CMFCRibbonButton::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|  
|[CMFCRibbonButton::OnFillBackground](#onfillbackground)||  
|[CMFCRibbonButton::RemoveAllSubItems](#removeallsubitems)|Remove todos os itens de menu no menu pop-up.|  
|[CMFCRibbonButton::RemoveSubItem](#removesubitem)|Remove um item de menu no menu pop-up.|  
|[CMFCRibbonButton::SetACCData](#setaccdata)|(Substitui [CMFCRibbonBaseElement::SetACCData](../../mfc/reference/cmfcribbonbaseelement-class.md#setaccdata).)|  
|[CMFCRibbonButton::SetAlwaysLargeImage](#setalwayslargeimage)|Especifica se o botão exibe uma grande ou pequena imagem quando o usuário recolhe o botão.|  
|[CMFCRibbonButton::SetDefaultCommand](#setdefaultcommand)|Ativa o comando padrão do botão faixa de opções.|  
|[CMFCRibbonButton::SetDescription](#setdescription)|Define a descrição para o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::SetDescription](../../mfc/reference/cmfcribbonbaseelement-class.md#setdescription).)|  
|[CMFCRibbonButton::SetImageIndex](#setimageindex)|Atribui um índice para a imagem do botão.|  
|[CMFCRibbonButton::SetMenu](#setmenu)|Atribui um menu pop-up para o botão faixa de opções.|  
|[CMFCRibbonButton::SetParentCategory](#setparentcategory)|(Substitui [CMFCRibbonBaseElement::SetParentCategory](../../mfc/reference/cmfcribbonbaseelement-class.md#setparentcategory).)|  
|[CMFCRibbonButton::SetRightAlignMenu](#setrightalignmenu)|Alinha o menu pop-up à direita do botão.|  
|[CMFCRibbonButton::SetText](#settext)|Define o texto para o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::SetText](../../mfc/reference/cmfcribbonbaseelement-class.md#settext).)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonButton::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no botão.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar os vários métodos na `CMFCRibbonButton` classe. O exemplo mostra como construir um objeto de `CMFCRibbonButton` classe, atribuir um menu pop-up ao botão faixa de opções, definir a descrição do botão, remova um item de menu no menu pop-up e alinhar à direita do menu pop-up para a borda do botão.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#7;](../../mfc/reference/codesnippet/cpp/cmfcribbonbutton-class_1.cpp)]  
  
## <a name="remarks"></a>Comentários  
 Para usar um botão da faixa de opções em um aplicativo, construir o objeto de botão e adicioná-lo à faixa de opções apropriada [painel](../../mfc/reference/cmfcribbonpanel-class.md).  
  
```  
CMFCRibbonPanel* pPanel = pCategory->AddPanel (
    _T("Clipboard"), // Panel name  
    m_PanelIcons.ExtractIcon (0)); // Panel icon  

// Create the first button ("Paste"):  
CMFCRibbonButton* pPasteButton = 
    new CMFCRibbonButton (ID_EDIT_PASTE, _T("Paste"), -1, 0);

// The third parameter (-1) disables small images for button.  
// This button is always displayed with a large image  
// Associate a pop-up menu with the "Paste" button:  
pPasteButton->SetMenu (IDR_CONTEXT_MENU);

// Add buttons to the panel. These buttons have only small images.  
pPanel->Add (new CMFCRibbonButton (ID_EDIT_CUT, _T("Cut"), 1));
pPanel->Add (new CMFCRibbonButton (ID_EDIT_COPY, _T("Copy"), 2));
pPanel->Add (new CMFCRibbonButton (ID_EDIT_PAINT, _T("Paint"), 9));
```  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonbutton.h  
  
##  <a name="addsubitem"></a>CMFCRibbonButton::AddSubItem  
 Adiciona um item de menu ao menu pop-up que é associado ao botão.  
  
```  
void AddSubItem(
    CMFCRibbonBaseElement* pSubItem,  
    int nIndex=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pSubItem`  
 Especifica um ponteiro para o novo elemento a ser adicionado.  
  
 [in] `nIndex`  
 Especifica o índice no qual você deseja adicionar o elemento à matriz de itens de menu do botão; -1 para adicionar o elemento ao final da matriz de itens de menu.  
  
##  <a name="canbestretched"></a>CMFCRibbonButton::CanBeStretched  

  
```  
virtual BOOL CanBeStretched();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cleanupsizes"></a>CMFCRibbonButton::CleanUpSizes  

  
```  
virtual void CleanUpSizes();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="closepopupmenu"></a>CMFCRibbonButton::ClosePopupMenu  

  
```  
virtual void ClosePopupMenu();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cmfcribbonbutton"></a>CMFCRibbonButton::CMFCRibbonButton  
 Constrói um objeto de botão da faixa de opções.  
  
```  
CMFCRibbonButton(
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex=-1,  
    int nLargeImageIndex=-1,  
    BOOL bAlwaysShowDescription=FALSE);

CMFCRibbonButton(
    UINT nID,  
    LPCTSTR lpszText,  
    HICON hIcon,  
    BOOL bAlwaysShowDescription=FALSE,  
    HICON hIconSmall=NULL,  
    BOOL bAutoDestroyIcon=FALSE,  
    BOOL bAlphaBlendIcon=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Especifica a ID de comando do botão.  
  
 [in] `lpszText`  
 Especifica o rótulo de texto do botão.  
  
 [in] `nSmallImageIndex`  
 Especifica um índice baseado em zero da imagem em miniatura do botão na lista de imagens da categoria pai.  
  
 [in] `nLargeImageIndex`  
 Especifica um índice baseado em zero da imagem grande do botão na lista de imagens da categoria pai.  
  
 [in] `hIcon`  
 Especifica um identificador para o ícone que o aplicativo usa como a imagem do botão.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCRibbonButton` objeto.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&6;](../../mfc/reference/codesnippet/cpp/cmfcribbonbutton-class_2.cpp)]  
  
##  <a name="drawbottomtext"></a>CMFCRibbonButton::DrawBottomText  

  
```  
CSize DrawBottomText(
    CDC* pDC,  
    BOOL bCalcOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 [in] `bCalcOnly`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="drawimage"></a>CMFCRibbonButton::DrawImage  

  
```  
virtual void DrawImage(
    CDC* pDC,  
    RibbonImageType type,  
    CRect rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 [in] `type`  
 [in] `rectImage`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="drawribbontext"></a>CMFCRibbonButton::DrawRibbonText  

  
```  
virtual int DrawRibbonText(
    CDC* pDC,  
    const CString& strText,  
    CRect rectText,  
    UINT uiDTFlags,  
    COLORREF clrText = (COLORREF)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 [in] `strText`  
 [in] `rectText`  
 [in] `uiDTFlags`  
 [in] `clrText`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="findsubitemindexbyid"></a>CMFCRibbonButton::FindSubItemIndexByID  
 Retorna o índice de um item de menu pop-up que é associado à ID de comando especificado.  
  
```  
int FindSubItemIndexByID(UINT uiID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 Especifica a ID de comando do item de menu pop-up.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item sub que está associado com o `uiID`. -1 se não houver nenhum item tal subpropriedades.  
  
##  <a name="getcommandrect"></a>CMFCRibbonButton::GetCommandRect  

  
```  
CRect GetCommandRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcompactsize"></a>CMFCRibbonButton::GetCompactSize  

  
```  
virtual CSize GetCompactSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="geticon"></a>CMFCRibbonButton::GetIcon  

  
```  
HICON GetIcon(BOOL bLargeIcon = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bLargeIcon`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getimageindex"></a>CMFCRibbonButton::GetImageIndex  
 Retorna o índice da imagem que está associada ao botão.  
  
```  
int GetImageIndex(BOOL bLargeImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bLargeImage`  
 Se `TRUE`, retorna o índice de imagem na lista de imagens que contém as imagens grandes; caso contrário, retorna o índice de imagem na lista de imagens que contém as imagens pequenas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da imagem do botão na lista de imagens associadas.  
  
##  <a name="getimagesize"></a>CMFCRibbonButton::GetImageSize  

  
```  
virtual CSize GetImageSize(RibbonImageType type) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `type`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getintermediatesize"></a>CMFCRibbonButton::GetIntermediateSize  

  
```  
virtual CSize GetIntermediateSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getmenu"></a>CMFCRibbonButton::GetMenu  
 Retorna um identificador para um menu do Windows que é atribuído ao botão da faixa de opções.  
  
```  
HMENU GetMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um menu do Windows atribuído ao botão; `NULL` se não há nenhum menu atribuído.  
  
##  <a name="getmenurect"></a>CMFCRibbonButton::GetMenuRect  

  
```  
CRect GetMenuRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getregularsize"></a>CMFCRibbonButton::GetRegularSize  

  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsubitems"></a>CMFCRibbonButton::GetSubItems  

  
```  
const CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& GetSubItems() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettextrowheight"></a>CMFCRibbonButton::GetTextRowHeight  

  
```  
int GetTextRowHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettooltiptext"></a>CMFCRibbonButton::GetToolTipText  

  
```  
virtual CString GetToolTipText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hascompactmode"></a>CMFCRibbonButton::HasCompactMode  

  
```  
virtual BOOL HasCompactMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasintermediatemode"></a>CMFCRibbonButton::HasIntermediateMode  

  
```  
virtual BOOL HasIntermediateMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="haslargemode"></a>CMFCRibbonButton::HasLargeMode  

  
```  
virtual BOOL HasLargeMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasmenu"></a>CMFCRibbonButton::HasMenu  

  
```  
virtual BOOL HasMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isalwaysdrawborder"></a>CMFCRibbonButton::IsAlwaysDrawBorder  

  
```  
virtual BOOL IsAlwaysDrawBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isalwayslargeimage"></a>CMFCRibbonButton::IsAlwaysLargeImage  

  
```  
virtual BOOL IsAlwaysLargeImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isapplicationbutton"></a>CMFCRibbonButton::IsApplicationButton  

  
```  
virtual BOOL IsApplicationButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="iscommandareahighlighted"></a>CMFCRibbonButton::IsCommandAreaHighlighted  

  
```  
virtual BOOL IsCommandAreaHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isdefaultcommand"></a>CMFCRibbonButton::IsDefaultCommand  
 Especifica se o comando padrão para um botão da faixa de opções está habilitado.  
  
```  
BOOL IsDefaultCommand() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se você tiver habilitado o comando padrão para um botão da faixa de opções. `FALSE` caso contrário.  
  
##  <a name="isdefaultpanelbutton"></a>CMFCRibbonButton::IsDefaultPanelButton  

  
```  
virtual BOOL IsDefaultPanelButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isdrawtooltipimage"></a>CMFCRibbonButton::IsDrawTooltipImage  

  
```  
virtual BOOL IsDrawTooltipImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="islargeimage"></a>CMFCRibbonButton::IsLargeImage  

  
```  
BOOL IsLargeImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenuareahighlighted"></a>CMFCRibbonButton::IsMenuAreaHighlighted  

  
```  
virtual BOOL IsMenuAreaHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenuonbottom"></a>CMFCRibbonButton::IsMenuOnBottom  

  
```  
BOOL IsMenuOnBottom() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ispopupdefaultmenulook"></a>CMFCRibbonButton::IsPopupDefaultMenuLook  

  
```  
virtual BOOL IsPopupDefaultMenuLook() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isrightalignmenu"></a>CMFCRibbonButton::IsRightAlignMenu  
 Especifica se o menu é alinhado à direita.  
  
```  
BOOL IsRightAlignMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o menu é alinhado à direita; Caso contrário, `FALSE`.  
  
##  <a name="issinglelinetext"></a>CMFCRibbonButton::IsSingleLineText  

  
```  
BOOL IsSingleLineText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oncalctextsize"></a>CMFCRibbonButton::OnCalcTextSize  

  
```  
virtual void OnCalcTextSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onclick"></a>CMFCRibbonButton::OnClick  
 Chamado pela estrutura quando o usuário clica no botão.  
  
```  
virtual void OnClick(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Especifica a posição do clique do mouse.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para manipular esse evento.  
  
##  <a name="ondraw"></a>CMFCRibbonButton::OnDraw  

  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawborder"></a>CMFCRibbonButton::OnDrawBorder  

  
```  
virtual void OnDrawBorder(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfillbackground"></a>CMFCRibbonButton::OnFillBackground  

  
```  
virtual COLORREF OnFillBackground(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removeallsubitems"></a>CMFCRibbonButton::RemoveAllSubItems  
 Remove todos os itens de menu no menu pop-up.  
  
```  
void RemoveAllSubItems();
```  
  
##  <a name="removesubitem"></a>CMFCRibbonButton::RemoveSubItem  
 Remove um item de menu no menu pop-up.  
  
```  
BOOL RemoveSubItem(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice baseado em zero do item de menu que você deseja remover.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o item especificado foi removido com êxito; Caso contrário, `FALSE` se `nIndex` for negativo ou exceder o número de itens de menu no menu pop-up.  
  
##  <a name="setaccdata"></a>CMFCRibbonButton::SetACCData  
 Define os dados de acessibilidade para o botão faixa de opções.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParent`  
 A janela pai para o elemento de faixa de opções.  
  
 `data`  
 Os dados de acessibilidade para o elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se bem-sucedido; caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setalwayslargeimage"></a>CMFCRibbonButton::SetAlwaysLargeImage  
 Especifica se o botão exibe uma grande ou pequena imagem quando o usuário recolhe o botão.  
  
```  
void SetAlwaysLargeImage(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 Se `TRUE`, o botão exibe uma imagem grande. Caso contrário, o botão exibe uma imagem pequena.  
  
##  <a name="setdefaultcommand"></a>CMFCRibbonButton::SetDefaultCommand  
 Ativa o comando padrão do botão faixa de opções.  
  
```  
void SetDefaultCommand(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 Se `TRUE`, o botão pode executar o comando padrão. Se `FALSE`, o botão não é possível executar o comando padrão.  
  
### <a name="remarks"></a>Comentários  
 `bSet`é relevante apenas quando o botão tem um menu. Se `bSet` é `TRUE`, o botão pode executar o comando padrão e o menu pop-up atribuído aparece somente quando um usuário clica na seta na extremidade direita do botão. Caso contrário, o botão não é possível executar o comando padrão e o menu pop-up será exibida, independentemente de qual área do botão o usuário clica.  
  
##  <a name="setdescription"></a>CMFCRibbonButton::SetDescription  

  
```  
virtual void SetDescription(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setimageindex"></a>CMFCRibbonButton::SetImageIndex  
 Atribui um índice para a imagem do botão.  
  
```  
void SetImageIndex(
    int nIndex,  
    BOOL bLargeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de imagem.  
  
 [in] `bLargeImage`  
 Se `TRUE`, o índice especificado se refere à lista de imagens grandes. Caso contrário, o índice refere-se à lista de imagens pequenas.  
  
##  <a name="setmenu"></a>CMFCRibbonButton::SetMenu  
 Atribui um menu pop-up para o botão faixa de opções.  
  
```  
void SetMenu(
    HMENU hMenu,  
    BOOL bIsDefaultCommand=FALSE,  
    BOOL bRightAlign=FALSE);

void SetMenu(
    UINT uiMenuResID,  
    BOOL bIsDefaultCommand=FALSE,  
    BOOL bRightAlign=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMenu`  
 Um identificador para um menu do Windows.  
  
 `bIsDefaultCommand`  
 Se `TRUE`, o botão pode executar o comando padrão; caso contrário, o botão exibe um menu pop-up.  
  
 `bRightAlign`  
 Se `TRUE`, o menu é alinhado à direita. Caso contrário, o menu é alinhado à esquerda.  
  
 `uiMenuResID`  
 Uma ID de recurso do menu.  
  
### <a name="remarks"></a>Comentários  
 Quando o aplicativo atribui o menu para o botão, o botão exibe uma seta do lado direito. Se `bIsDefaultCommand` é `TRUE`, o menu é exibido apenas quando o usuário clica na seta. Se o usuário clica no botão, o comando padrão é executado. Se `bIsDefaultCommand` é `FALSE`, aparece o menu clicando em qualquer lugar no botão.  
  
##  <a name="setparentcategory"></a>CMFCRibbonButton::SetParentCategory  

  
```  
virtual void SetParentCategory(CMFCRibbonCategory* pParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setrightalignmenu"></a>CMFCRibbonButton::SetRightAlignMenu  
 Alinha o menu pop-up para a borda do botão.  
  
```  
void SetRightAlignMenu(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 Se `TRUE`, o menu é alinhado à direita. Caso contrário, o menu é alinhado à esquerda  
  
##  <a name="settext"></a>CMFCRibbonButton::SetText  

  
```  
virtual void SetText(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

