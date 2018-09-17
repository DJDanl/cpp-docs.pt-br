---
title: Classe CMFCColorMenuButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableAutomaticButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableDocumentColors
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableOtherButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableTearOff
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetAutomaticColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetColorByCmdID
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnChangeParentWnd
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OpenColorDialog
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColorByCmdID
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColorName
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColumnsNumber
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CopyFrom
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CreatePopupMenu
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::IsEmptyMenuAllowed
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnDraw
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnDrawOnCustomizeList
dev_langs:
- C++
helpviewer_keywords:
- CMFCColorMenuButton [MFC], CMFCColorMenuButton
- CMFCColorMenuButton [MFC], EnableAutomaticButton
- CMFCColorMenuButton [MFC], EnableDocumentColors
- CMFCColorMenuButton [MFC], EnableOtherButton
- CMFCColorMenuButton [MFC], EnableTearOff
- CMFCColorMenuButton [MFC], GetAutomaticColor
- CMFCColorMenuButton [MFC], GetColor
- CMFCColorMenuButton [MFC], GetColorByCmdID
- CMFCColorMenuButton [MFC], OnChangeParentWnd
- CMFCColorMenuButton [MFC], OpenColorDialog
- CMFCColorMenuButton [MFC], SetColor
- CMFCColorMenuButton [MFC], SetColorByCmdID
- CMFCColorMenuButton [MFC], SetColorName
- CMFCColorMenuButton [MFC], SetColumnsNumber
- CMFCColorMenuButton [MFC], CopyFrom
- CMFCColorMenuButton [MFC], CreatePopupMenu
- CMFCColorMenuButton [MFC], IsEmptyMenuAllowed
- CMFCColorMenuButton [MFC], OnDraw
- CMFCColorMenuButton [MFC], OnDrawOnCustomizeList
ms.assetid: 42685704-e994-4f7b-9553-62283c27b754
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ab793b8c758b95c259c717a794436b59057d4273
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712979"
---
# <a name="cmfccolormenubutton-class"></a>Classe CMFCColorMenuButton
O `CMFCColorMenuButton` classe dá suporte a um comando de menu ou um botão de barra de ferramentas que inicia uma caixa de diálogo do seletor de cor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorMenuButton : public CMFCToolBarMenuButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::CMFCColorMenuButton](#cmfccolormenubutton)|Constrói um objeto `CMFCColorMenuButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton)|Habilita e desabilita um botão de "automático" que está posicionado acima dos botões de cor regular. (O botão automático do padrão do sistema é rotulado **automática**.)|  
|[CMFCColorMenuButton::EnableDocumentColors](#enabledocumentcolors)|Permite a exibição de cores de documento específico, em vez de cores do sistema.|  
|[CMFCColorMenuButton::EnableOtherButton](#enableotherbutton)|Habilita e desabilita um botão "other" que é posicionado abaixo dos botões de cor regular. (O padrão do sistema "other" botão é rotulado **mais cores**.)|  
|[CMFCColorMenuButton::EnableTearOff](#enabletearoff)|Habilita a capacidade de separar um painel de cores.|  
|[CMFCColorMenuButton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|  
|[CMFCColorMenuButton::GetColor](#getcolor)|Recupera a cor do botão.|  
|[CMFCColorMenuButton::GetColorByCmdID](#getcolorbycmdid)|Recupera a cor que corresponde a uma ID de comando especificado.|  
|[CMFCColorMenuButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo framework quando a janela pai é alterado.|  
|[CMFCColorMenuButton::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de seleção de cor.|  
|[CMFCColorMenuButton::SetColor](#setcolor)|Define a cor do botão de cor atual.|  
|[CMFCColorMenuButton::SetColorByCmdID](#setcolorbycmdid)|Define a cor do botão de menu cor especificada.|  
|[CMFCColorMenuButton::SetColorName](#setcolorname)|Define um novo nome para a cor especificada.|  
|[CMFCColorMenuButton::SetColumnsNumber](#setcolumnsnumber)|Define o número de colunas que são exibidas por um `CMFCColorBar` objeto.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::CopyFrom](#copyfrom)|Copia o outro botão de barra de ferramentas para o botão atual.|  
|[CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu)|Cria uma caixa de diálogo do seletor de cor.|  
|[CMFCColorMenuButton::IsEmptyMenuAllowed](#isemptymenuallowed)|Indica se menus vazias têm suporte.|  
|[CMFCColorMenuButton::OnDraw](#ondraw)|Chamado pelo framework para exibir uma imagem em um botão.|  
|[CMFCColorMenuButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pelo framework antes de um `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.|  
  
## <a name="remarks"></a>Comentários  
 Para substituir o original comando ou uma barra de ferramentas do botão de menu com um `CMFCColorMenuButton` do objeto, crie a `CMFCColorMenuButton` objeto, o conjunto apropriado de qualquer [classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) estilos e, em seguida, chame o `ReplaceButton` método o [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) classe. Se você personalizar uma barra de ferramentas, chame o [CMFCToolBarsCustomizeDialog::ReplaceButton](../../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) método.  
  
 A caixa de diálogo do seletor de cor é criada durante o processamento do [CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu) manipulador de eventos. Quadro principal com uma mensagem WM_COMMAND notifica o manipulador de eventos. O `CMFCColorMenuButton` objeto envia a ID do controle que é atribuída para o botão de barra de ferramentas ou comando de menu original.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar e configurar um botão de menu de cor usando vários métodos no `CMFCColorMenuButton` classe. No exemplo, uma `CPalette` objeto é criado pela primeira vez e, em seguida, usado para construir um objeto do `CMFCColorMenuButton` classe. O `CMFCColorMenuButton` objeto é configurado, em seguida, habilitando seu automático e outros botões e definindo sua cor e o número de colunas. Esse código é parte do [exemplo de Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#5](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_1.h)]  
[!code-cpp[NVC_MFC_WordPad#6](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)  
  
 [CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolormenubutton.h  
  
##  <a name="cmfccolormenubutton"></a>  CMFCColorMenuButton::CMFCColorMenuButton  
 Constrói um objeto `CMFCColorMenuButton`.  
  
```  
CMFCColorMenuButton();

 
CMFCColorMenuButton(
    UINT uiCmdID,  
    LPCTSTR lpszText,  
    CPalette* pPalette=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdID*<br/>
[in] Uma ID de comando do botão.  
  
*lpszText*<br/>
[in] O texto do botão.  
  
*pPalette*<br/>
[in] Um ponteiro para uma paleta de cores do botão.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor é o construtor padrão. A cor do objeto atual e à cor automática são inicializados para preto (RGB (0, 0, 0)).  
  
 O segundo construtor inicializa o botão para a cor que corresponde à ID de comando especificado.  
  
##  <a name="copyfrom"></a>  CMFCColorMenuButton::CopyFrom  
 Copia uma [classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)-derivados do objeto para outro.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
*src*<br/>
[in] Botão de origem para copiar.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para copiar os objetos que derivam de `CMFCColorMenuButton` objeto.  
  
##  <a name="createpopupmenu"></a>  CMFCColorMenuButton::CreatePopupMenu  
 Cria uma caixa de diálogo do seletor de cor.  
  
```  
virtual CMFCPopupMenu* CreatePopupMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto que representa uma caixa de diálogo do seletor de cor.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo framework quando o usuário pressiona um botão de menu de cor.  
  
##  <a name="enableautomaticbutton"></a>  CMFCColorMenuButton::EnableAutomaticButton  
 Habilita e desabilita um botão de "automático" que está posicionado acima dos botões de cor regular. (O botão automático do padrão do sistema é rotulado **automática**.)  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszLabel*<br/>
[in] Especifica o texto do botão que é exibido quando o botão se torna automático.  
  
*automáticaCor*<br/>
[in] Especifica uma nova cor automática.  
  
*bAtivar*<br/>
[in] Especifica se o botão é automático ou não.  
  
### <a name="remarks"></a>Comentários  
 O botão automático se aplica a cor padrão atual.  
  
##  <a name="enabledocumentcolors"></a>  CMFCColorMenuButton::EnableDocumentColors  
 Permite a exibição de cores de documento específico, em vez de cores do sistema.  
  
```  
void EnableDocumentColors(
    LPCTSTR lpszLabel,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszLabel*<br/>
[in] Especifica o texto do botão.  
  
*bAtivar*<br/>
[in] TRUE para exibir cores de documento específico ou falso para exibir cores do sistema.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para exibir as cores do documento atual ou as cores de paleta do sistema quando o usuário clica em um botão de menu de cor.  
  
##  <a name="enableotherbutton"></a>  CMFCColorMenuButton::EnableOtherButton  
 Habilita e desabilita um botão "other" que é posicionado abaixo dos botões de cor regular. (O padrão do sistema "other" botão é rotulado **mais cores**.)  
  
```  
void EnableOtherButton(
    LPCTSTR lpszLabel,  
    BOOL bAltColorDlg=TRUE,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszLabel*<br/>
[in] Especifica o texto do botão.  
  
*bAltColorDlg*<br/>
[in] Especifique TRUE para exibir o `CMFCColorDialog` caixa de diálogo, ou falso para exibir a caixa de diálogo de cor padrão do sistema.  
  
*bAtivar*<br/>
[in] Especifique TRUE para exibir o botão "other"; Caso contrário, FALSE. O padrão é TRUE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enabletearoff"></a>  CMFCColorMenuButton::EnableTearOff  
 Habilita a capacidade de separar um painel de cores.  
  
```  
void EnableTearOff(
    UINT uiID,  
    int nVertDockColumns=-1,  
    int nHorzDockRows=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
*uiID*<br/>
[in] Especifica a ID para o painel destacáveis.  
  
*nVertDockColumns*<br/>
[in] Especifica o número de colunas no painel de cor encaixado na vertical no estado destacáveis.  
  
*nHorzDockRows*<br/>
[in] Especifica o número de linhas para o painel de cores ancorada horizontalmente enquanto estiver no estado destacáveis.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para habilitar o recurso "destacáveis" para o painel de cores pop-up quando o `CMFCColorMenuButton` é pressionado.  
  
##  <a name="getautomaticcolor"></a>  CMFCColorMenuButton::GetAutomaticColor  
 Recupera a cor automática atual.  
  
```  
COLORREF GetAutomaticColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor automática atual.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para obter a cor automática que é definida por [CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton).  
  
##  <a name="getcolor"></a>  CMFCColorMenuButton::GetColor  
 Recupera a cor do botão.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcolorbycmdid"></a>  CMFCColorMenuButton::GetColorByCmdID  
 Recupera a cor que corresponde a uma ID de comando especificado.  
  
```  
static COLORREF GetColorByCmdID(UINT uiCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdID*<br/>
[in] Uma ID de comando.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor que corresponde à ID de comando especificado.  
  
### <a name="remarks"></a>Comentários  
 Use esse método quando você tem vários botões de cor em um aplicativo. Quando o usuário clica em um botão de cor, o botão envia sua ID de comando em uma mensagem WM_COMMAND ao seu pai. O `GetColorByCmdID` método usa a ID de comando para recuperar a cor correspondente.  
  
##  <a name="isemptymenuallowed"></a>  CMFCColorMenuButton::IsEmptyMenuAllowed  
 Indica se menus vazias têm suporte.  
  
```  
virtual BOOL IsEmptyMenuAllowed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se menus vazias são permitidas; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Menus vazias têm suporte por padrão. Substitua este método para alterar esse comportamento na classe derivada.  
  
##  <a name="onchangeparentwnd"></a>  CMFCColorMenuButton::OnChangeParentWnd  
 Chamado pelo framework quando a janela pai é alterado.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
*pWndParent*<br/>
[in] Um ponteiro para a nova janela pai.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>  CMFCColorMenuButton::OnDraw  
 Chamado pelo framework para exibir uma imagem em um botão.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rect,  
    CMFCToolBarImages* pImages,  
    BOOL bHorz=TRUE,  
    BOOL bCustomizeMode=FALSE,  
    BOOL bHighlight=FALSE,  
    BOOL bDrawBorder=TRUE,  
    BOOL bGrayDisabledButtons=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.  
  
*Rect*<br/>
[in] Um retângulo que delimita a área a ser redesenhado.  
  
*pImages*<br/>
[in] Aponta para uma lista de imagens da barra de ferramentas.  
  
*bHorz*<br/>
[in] TRUE para especificar que a barra de ferramentas está em um estado de ancoramento horizontal; Caso contrário, FALSE. O padrão é TRUE.  
  
*bCustomizeMode*<br/>
[in] TRUE para especificar que o aplicativo está no modo de personalização. Caso contrário, FALSE. O padrão é FALSE.  
  
*bHighlight*<br/>
[in] TRUE para especificar que o botão está realçado; Caso contrário, FALSE. O padrão é FALSE.  
  
*bDrawBorder*<br/>
[in] TRUE para especificar que a borda do botão é exibida; Caso contrário, FALSE. O padrão é TRUE.  
  
*bGrayDisabledButtons*<br/>
[in] TRUE para especificar que os botões desabilitados são cinza (esmaecido). Caso contrário, FALSE. O padrão é TRUE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawoncustomizelist"></a>  CMFCColorMenuButton::OnDrawOnCustomizeList  
 Chamado pelo framework antes de um `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.  
  
```  
virtual int OnDrawOnCustomizeList(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.  
  
*Rect*<br/>
[in] Um retângulo que delimita o botão a ser desenhado.  
  
*bSelected*<br/>
[in] O valor TRUE Especifica que o botão estiver no estado selecionado; Caso contrário, FALSE.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura do botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando um `CMFCColorMenuButton` objeto é exibido na caixa de listagem durante o processo de personalização da barra de ferramentas.  
  
##  <a name="opencolordialog"></a>  CMFCColorMenuButton::OpenColorDialog  
 Abre uma caixa de diálogo de seleção de cor.  
  
```  
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,  
    COLORREF& colorRes);
```  
  
### <a name="parameters"></a>Parâmetros  
*colorDefault*<br/>
[in] A cor padrão é selecionada na caixa de diálogo de cor.  
  
*colorRes*<br/>
[out] Retorna a cor que o usuário seleciona na caixa de diálogo de cor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário seleciona uma nova cor. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando o botão de menu é clicado, chame esse método para abrir uma caixa de diálogo de cor. Se o valor de retorno é diferente de zero, a cor selecionada pelo usuário é armazenada na *colorRes* parâmetro. Use o [CMFCColorMenuButton::EnableOtherButton](#enableotherbutton) método para alternar entre a caixa de diálogo de cores padrão e o [classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo.  
  
##  <a name="setcolor"></a>  CMFCColorMenuButton::SetColor  
 Define a cor do botão de cor atual.  
  
```  
virtual void SetColor(
    COLORREF clr,  
    BOOL bNotify=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
*CLR*<br/>
[in] Um valor de cor RGB.  
  
*bNotify*<br/>
[in] TRUE para aplicar a *clr* cor de parâmetro para qualquer botão de menu associado ou botão de barra de ferramentas; caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para alterar a cor do botão de cor atual. Se o *bNotify* parâmetro é diferente de zero, a cor do botão correspondente em qualquer menu pop-up associado ou a barra de ferramentas é alterada para a cor especificada pela *clr* parâmetro.  
  
##  <a name="setcolorbycmdid"></a>  CMFCColorMenuButton::SetColorByCmdID  
 Define a cor do botão de menu cor especificada.  
  
```  
static void SetColorByCmdID(
    UINT uiCmdID,  
    COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdID*<br/>
[in] A ID de recurso de um botão de menu de cor.  
  
*Cor*<br/>
[in] Um valor de cor RGB.  
  
##  <a name="setcolorname"></a>  CMFCColorMenuButton::SetColorName  
 Define um novo nome para a cor especificada.  
  
```  
static void SetColorName(
    COLORREF color,  
    const CString& strName);
```  
  
### <a name="parameters"></a>Parâmetros  
*Cor*<br/>
[in] O valor RGB da cor cujo nome é alterado.  
  
*strName*<br/>
[in] O novo nome da cor.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcolumnsnumber"></a>  CMFCColorMenuButton::SetColumnsNumber  
 Define o número de colunas a serem exibidas em um controle de seleção de cor ( [CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) objeto).  
  
```  
void SetColumnsNumber(int nColumns);
```  
  
### <a name="parameters"></a>Parâmetros  
*nColumns*<br/>
[in] O número de colunas a serem exibidas.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)   
 [Classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)
