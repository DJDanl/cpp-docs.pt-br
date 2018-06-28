---
title: Classe CMFCColorButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton::CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton::EnableAutomaticButton
- AFXCOLORBUTTON/CMFCColorButton::EnableOtherButton
- AFXCOLORBUTTON/CMFCColorButton::GetAutomaticColor
- AFXCOLORBUTTON/CMFCColorButton::GetColor
- AFXCOLORBUTTON/CMFCColorButton::SetColor
- AFXCOLORBUTTON/CMFCColorButton::SetColorName
- AFXCOLORBUTTON/CMFCColorButton::SetColumnsNumber
- AFXCOLORBUTTON/CMFCColorButton::SetDocumentColors
- AFXCOLORBUTTON/CMFCColorButton::SetPalette
- AFXCOLORBUTTON/CMFCColorButton::SizeToContent
- AFXCOLORBUTTON/CMFCColorButton::IsDrawXPTheme
- AFXCOLORBUTTON/CMFCColorButton::OnDraw
- AFXCOLORBUTTON/CMFCColorButton::OnDrawBorder
- AFXCOLORBUTTON/CMFCColorButton::OnDrawFocusRect
- AFXCOLORBUTTON/CMFCColorButton::OnShowColorPopup
- AFXCOLORBUTTON/CMFCColorButton::RebuildPalette
- AFXCOLORBUTTON/CMFCColorButton::UpdateColor
- AFXCOLORBUTTON/CMFCColorButton::m_bEnabledInCustomizeMode
dev_langs:
- C++
helpviewer_keywords:
- CMFCColorButton [MFC], CMFCColorButton
- CMFCColorButton [MFC], EnableAutomaticButton
- CMFCColorButton [MFC], EnableOtherButton
- CMFCColorButton [MFC], GetAutomaticColor
- CMFCColorButton [MFC], GetColor
- CMFCColorButton [MFC], SetColor
- CMFCColorButton [MFC], SetColorName
- CMFCColorButton [MFC], SetColumnsNumber
- CMFCColorButton [MFC], SetDocumentColors
- CMFCColorButton [MFC], SetPalette
- CMFCColorButton [MFC], SizeToContent
- CMFCColorButton [MFC], IsDrawXPTheme
- CMFCColorButton [MFC], OnDraw
- CMFCColorButton [MFC], OnDrawBorder
- CMFCColorButton [MFC], OnDrawFocusRect
- CMFCColorButton [MFC], OnShowColorPopup
- CMFCColorButton [MFC], RebuildPalette
- CMFCColorButton [MFC], UpdateColor
- CMFCColorButton [MFC], m_bEnabledInCustomizeMode
ms.assetid: 9fdf34ae-4cc5-4c5e-9d89-1c50e8a73699
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fd59f9575fdbde798b46bee343f7f7724968a478
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37038306"
---
# <a name="cmfccolorbutton-class"></a>Classe CMFCColorButton
O `CMFCColorButton` e [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) classes são usadas em conjunto para implementar um controle de seletor de cor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorButton : public CMFCButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorButton::CMFCColorButton](#cmfccolorbutton)|Constrói um novo objeto `CMFCColorButton`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorButton::EnableAutomaticButton](#enableautomaticbutton)|Habilita e desabilita um botão "automático" que será posicionado acima dos botões de cor regular. (O botão automático padrão do sistema é rotulado **automática**.)|  
|[CMFCColorButton::EnableOtherButton](#enableotherbutton)|Habilita e desabilita um botão "outro" que será posicionado abaixo dos botões de cor regular. (O padrão do sistema é rotulado "outro" botão **mais cores**.)|  
|[CMFCColorButton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|  
|[CMFCColorButton::GetColor](#getcolor)|Recupera a cor do botão.|  
|[CMFCColorButton::SetColor](#setcolor)|Define a cor do botão.|  
|[CMFCColorButton::SetColorName](#setcolorname)|Define um nome de cor.|  
|[CMFCColorButton::SetColumnsNumber](#setcolumnsnumber)|Define o número de colunas na caixa de diálogo Seletor de cores.|  
|[CMFCColorButton::SetDocumentColors](#setdocumentcolors)|Especifica uma lista de cores específicas de documentos que são exibidos na caixa de diálogo Seletor de cores.|  
|[CMFCColorButton::SetPalette](#setpalette)|Especifica uma paleta de cores padrão.|  
|[CMFCColorButton::SizeToContent](#sizetocontent)|Altera o tamanho do controle button, dependendo de seu tamanho de texto e imagem.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorButton::IsDrawXPTheme](#isdrawxptheme)|Indica se o botão de cor atual é exibido no estilo visual do Windows XP.|  
|[CMFCColorButton::OnDraw](#ondraw)|Chamado pelo framework para exibir uma imagem do botão.|  
|[CMFCColorButton::OnDrawBorder](#ondrawborder)|Chamado pelo framework para exibir a borda do botão.|  
|[CMFCColorButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo framework para exibir um retângulo de foco quando o botão tem foco.|  
|[CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)|Chamado pelo framework quando a caixa de diálogo de seletor de cor está prestes a ser exibido.|  
|[CMFCColorButton::RebuildPalette](#rebuildpalette)|Inicializa o `m_pPalette` protegido membro de dados para a paleta especificada ou a paleta padrão do sistema.|  
|[CMFCColorButton::UpdateColor](#updatecolor)|Chamado pelo framework quando o usuário seleciona uma cor na paleta de caixa de diálogo Seletor de cores.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|`m_bAltColorDlg`|Um booliano. Se `TRUE`, exibe a estrutura de [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo de cor quando o *outros* botão é clicado, ou se `FALSE`, a caixa de diálogo de cor do sistema. O valor padrão é `TRUE`. Para obter mais informações, consulte [CMFCColorButton::EnableOtherButton](#enableotherbutton).|  
|`m_bAutoSetFocus`|Um booliano. Se `TRUE`, a estrutura define o foco no menu de cor quando o menu é exibido, ou se `FALSE`, não altera o foco. O valor padrão é `TRUE`.|  
|[CMFCColorButton::m_bEnabledInCustomizeMode](#m_benabledincustomizemode)|Indica se o modo de personalização está habilitado para o botão de cor.|  
|`m_Color`|Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor. Contém a cor atualmente selecionada.|  
|`m_ColorAutomatic`|Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor. Contém a cor padrão selecionado no momento.|  
|`m_Colors`|Um [CArray](../../mfc/reference/carray-class.md) de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valores. Contém as cores disponíveis no momento.|  
|`m_lstDocColors`|Um [CList](../../mfc/reference/clist-class.md) de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valores. Contém as cores do documento atual.|  
|`m_nColumns`|Um inteiro. Contém o número de colunas a serem exibidas na grade de cores em um menu de seleção de cor.|  
|`m_pPalette`|Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md). Contém as cores que estão disponíveis no menu seleção de cor atual.|  
|`m_pPopup`|Um ponteiro para um [CMFCColorPopupMenu classe](../../mfc/reference/cmfccolorpopupmenu-class.md) objeto. O menu de seleção de cor é exibido quando você clica no botão de cor.|  
|`m_strAutoColorText`|Uma cadeia de caracteres. O rótulo do botão "automático" em um menu de seleção de cor.|  
|`m_strDocColorsText`|Uma cadeia de caracteres. O rótulo do botão em um menu de seleção de cor que exibe as cores do documento.|  
|`m_strOtherText`|Uma cadeia de caracteres. O rótulo do botão "outro" em um menu de seleção de cor.|  
  
## <a name="remarks"></a>Comentários  
 Por padrão, o `CMFCColorButton` classe se comporta como um botão de ação que abre uma caixa de diálogo do seletor de cores. Caixa de diálogo Seletor de cor contém uma matriz de botões de cor pequeno e um botão "outros" que exibe um seletor de cores personalizadas. (O padrão do sistema é rotulado "outro" botão **mais cores**.) Quando um usuário seleciona uma cor nova, o `CMFCColorButton` objeto reflete a alteração e exibe a cor selecionada.  
  
 Criar um controle de botão de cor diretamente no seu código ou usando o **ClassWizard** ferramenta e um modelo de caixa de diálogo. Se você criar um controle de botão de cor diretamente, adicione um `CMFCColorButton` variável ao seu aplicativo e, em seguida, chame o construtor e `Create` métodos do `CMFCColorButton` objeto. Se você usar o **ClassWizard**, adicione um `CButton` variável ao seu aplicativo e, em seguida, altere o tipo da variável de `CButton` para `CMFCColorButton`.  
  
 Caixa de diálogo Seletor de cores ( [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md)) é exibida, o [CMFCColorButton::OnShowColorPopup](#onshowcolorpopup) método quando o framework chama o `OnLButtonDown` manipulador de eventos. O [CMFCColorButton::OnShowColorPopup](#onshowcolorpopup) método pode ser substituído para dar suporte a seleção de cor personalizada.  
  
 O `CMFCColorButton` notifica o objeto pai que está sendo alterado uma cor, enviando-um `WM_COMMAND | BN_CLICKED` notificação. O pai usa o [CMFCColorButton::GetColor](#getcolor) método para recuperar a cor atual.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um botão de cor usando vários métodos no `CMFCColorButton` classe. Os métodos de definir a cor do botão de cor e seu número de colunas e habilitar o automático e outros botões. Este exemplo é parte do [exemplo de demonstração de barra de Status](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StatusBarDemo#10](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_1.h)]  
[!code-cpp[NVC_MFC_StatusBarDemo#11](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolorbutton.h  
  
##  <a name="cmfccolorbutton"></a>  CMFCColorButton::CMFCColorButton  
 Constrói um novo objeto `CMFCColorButton`.  
  
```  
CMFCColorButton();
```  
  
##  <a name="enableautomaticbutton"></a>  CMFCColorButton::EnableAutomaticButton  
 Habilitar ou desabilitar o botão "automático" de um controle de seletor de cores e definir a cor automático (padrão).  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszLabel*  
 Especifica o texto do botão automático.  
  
 [in] *automáticaCor*  
 Um valor RGB que especifica a cor do padrão do botão automático.  
  
 [in] *bAtivar*  
 Especifica se o botão automático está habilitado ou desabilitado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enableotherbutton"></a>  CMFCColorButton::EnableOtherButton  
 Habilitar ou desabilitar o botão "outro", que aparece abaixo de botões de cor regular.  
  
```  
void EnableOtherButton(
    LPCTSTR lpszLabel,  
    BOOL bAltColorDlg=TRUE,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszLabel*  
 Especifica o texto do botão.  
  
 [in] *bAltColorDlg*  
 Especifica se o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo ou a caixa de diálogo de cor do sistema é aberta quando o usuário clica no botão.  
  
 [in] *bAtivar*  
 Especifica se o botão "outro" está habilitado ou desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Clique no botão "outro" para exibir uma caixa de diálogo de cor. Se o *bAltColorDlg* parâmetro é `TRUE`, o [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md) é exibido; caso contrário, a caixa de diálogo de cor do sistema é exibida.  
  
##  <a name="getautomaticcolor"></a>  CMFCColorButton::GetAutomaticColor  
 Recupera a cor atual do automático (padrão).  
  
```  
COLORREF GetAutomaticColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor RGB que representa a cor automática atual.  
  
### <a name="remarks"></a>Comentários  
 A cor automática atual é definida pelo [CMFCColorButton::EnableAutomaticButton](#enableautomaticbutton) método.  
  
##  <a name="getcolor"></a>  CMFCColorButton::GetColor  
 Recupera a cor atualmente selecionada.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor RGB.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isdrawxptheme"></a>  CMFCColorButton::IsDrawXPTheme  
 Indica se o botão de cor atual é exibido no estilo visual do Windows XP.  
  
```  
BOOL IsDrawXPTheme() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` se há suporte para os estilos visuais e o botão de cor atual é exibido no estilo visual do Windows XP. Caso contrário, `FALSE`.  
  
##  <a name="m_benabledincustomizemode"></a>  CMFCColorButton::m_bEnabledInCustomizeMode  
 Define um botão de cor para o modo de personalização.  
  
```  
BOOL m_bEnabledInCustomizeMode;  
```  
  
### <a name="remarks"></a>Comentários  
 Se você precisar adicionar um botão de cor para a página da caixa de diálogo uma personalização (ou permitir que o usuário fazer outra seleção de cor durante a personalização), habilitar o botão, definindo a `m_bEnabledInCustomizeMode` membro `TRUE`. Por padrão, esse membro é definido como `FALSE`.  
  
##  <a name="ondraw"></a>  CMFCColorButton::OnDraw  
 Chamado pelo framework para processar uma imagem do botão.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rect,  
    UINT uiState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Aponta para o contexto de dispositivo que é usada para renderizar a imagem do botão.  
  
 [in] *rect*  
 Um retângulo que circunda o botão.  
  
 [in] *uiState*  
 Especifica o estado visual do botão.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para personalizar o processo de renderização.  
  
##  <a name="ondrawborder"></a>  CMFCColorButton::OnDrawBorder  
 Chamado pelo framework para exibir a borda do botão.  
  
```  
virtual void OnDrawBorder(
    CDC* pDC,  
    CRect& rectClient,  
    UINT uiState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Aponta para o contexto de dispositivo usado para desenhar a borda.  
  
 [in] *rectClient*  
 Um retângulo no contexto do dispositivo especificado pelo o *pDC* parâmetro que define os limites do botão a ser desenhada.  
  
 [in] *uiState*  
 Especifica o estado visual do botão.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar a aparência da borda do botão de cor.  
  
##  <a name="ondrawfocusrect"></a>  CMFCColorButton::OnDrawFocusRect  
 Chamado pelo framework para exibir um retângulo de foco quando o botão tem foco.  
  
```  
virtual void OnDrawFocusRect(
    CDC* pDC,  
    const CRect& rectClient);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Aponta para o contexto de dispositivo usado para desenhar o retângulo de foco.  
  
 [in] *rectClient*  
 Um retângulo no contexto de dispositivo especificado pelo *pDC* parâmetro que define os limites do botão.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para personalizar a aparência do retângulo de foco.  
  
##  <a name="onshowcolorpopup"></a>  CMFCColorButton::OnShowColorPopup  
 Chamado antes da barra de cores pop-up é exibida.  
  
```  
virtual void OnShowColorPopup();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="rebuildpalette"></a>  CMFCColorButton::RebuildPalette  
 Inicializa o `m_pPalette` protegido membro de dados para a paleta especificada ou a paleta padrão do sistema.  
  
```  
void RebuildPalette(CPalette* pPal);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *pPal*|Um ponteiro para uma paleta lógica ou `NULL`. Se `NULL`, a paleta padrão do sistema é usada.|  
  
##  <a name="setcolor"></a>  CMFCColorButton::SetColor  
 Especifica a cor do botão.  
  
```  
void SetColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *cor*  
 Um valor RGB.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcolorname"></a>  CMFCColorButton::SetColorName  
 Especifica o nome de uma cor.  
  
```  
static void SetColorName(
    COLORREF color,  
    const CString& strName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *cor*  
 O valor da cor RGB.  
  
 [in] *strName*  
 Nome da cor.  
  
### <a name="remarks"></a>Comentários  
 A lista de nomes de cor é global por aplicativo. Consequentemente, esse método transfere seus parâmetros para [CMFCColorBar::SetColorName](../../mfc/reference/cmfccolorbar-class.md#setcolorname).  
  
##  <a name="setcolumnsnumber"></a>  CMFCColorButton::SetColumnsNumber  
 Define o número de colunas que são exibidas na tabela de cores é apresentada ao usuário durante o processo de seleção de cor do usuário.  
  
```  
void SetColumnsNumber(int nColumns);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nColumns*  
 Especifica o número de colunas.  
  
### <a name="remarks"></a>Comentários  
 O usuário pode selecionar uma cor de uma barra de cores pop-up que exibe uma tabela de cores predefinidas. Use esse método para definir o número de colunas na tabela.  
  
##  <a name="setdocumentcolors"></a>  CMFCColorButton::SetDocumentColors  
 Especifica um conjunto de cores e o nome do conjunto. O conjunto de cores é exibido usando um [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) objeto.  
  
```  
void SetDocumentColors(
    LPCTSTR lpszLabel,  
    CList<COLORREF,COLORREF>& lstColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszLabel*  
 Especifica o rótulo a ser exibido com o conjunto de cores do documento.  
  
 [in] *lstColors*  
 Uma referência a uma lista de valores RGB.  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCColorButton` objeto mantém uma lista de valores RGB são transferidos para um [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) objeto. Quando a barra de cores é exibida, essas cores são mostradas em uma seção especial cujo nome é especificado pelo *lpszLabel* parâmetro.  
  
##  <a name="setpalette"></a>  CMFCColorButton::SetPalette  
 Especifica as cores padrão para exibir na barra de cores de pop-up.  
  
```  
void SetPalette(CPalette* pPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pPalette*  
 Um ponteiro para uma paleta de cores.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sizetocontent"></a>  CMFCColorButton::SizeToContent  
 Redimensiona o controle de botão para ajustar seu texto e imagem.  
  
```  
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bCalcOnly*  
 Se for diferente de zero, o novo tamanho do controle button é calculado, mas o tamanho real não é alterado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que especifica um novo tamanho do controle de botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="updatecolor"></a>  CMFCColorButton::UpdateColor  
 Chamado pelo framework quando o usuário seleciona uma cor da barra de cores exibe quando o usuário clica no botão de cor.  
  
```  
virtual void UpdateColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *cor*  
 Cor selecionada pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 O `UpdateColor` função altera a cor do botão selecionado no momento e notificará seu pai enviando uma mensagem WM_COMMAND com uma notificação de BN_CLICKED padrão. Use o [CMFCColorButton::GetColor](#getcolor) método para recuperar a cor selecionada.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)   
 [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)   
 [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449)   
 [Classe CPalette](../../mfc/reference/cpalette-class.md)   
 [Classe CArray](../../mfc/reference/carray-class.md)   
 [Classe CList](../../mfc/reference/clist-class.md)   
 [CString](../../atl-mfc-shared/reference/cstringt-class.md)
