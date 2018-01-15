---
title: Classe CMFCColorMenuButton | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
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
dev_langs: C++
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
caps.latest.revision: "29"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2c6e976b1a5497e8d2814208b6b3260037458fc0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfccolormenubutton-class"></a>Classe CMFCColorMenuButton
O `CMFCColorMenuButton` classe oferece suporte a um comando de menu ou um botão que inicia uma caixa de diálogo do seletor de cores.  
  
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
|[CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton)|Habilita e desabilita um botão "automático" que será posicionado acima dos botões de cor regular. (O botão automático padrão do sistema é rotulado **automática**.)|  
|[CMFCColorMenuButton::EnableDocumentColors](#enabledocumentcolors)|Ativa a exibição de cores específica do documento em vez de cores do sistema.|  
|[CMFCColorMenuButton::EnableOtherButton](#enableotherbutton)|Habilita e desabilita um botão "outro" que será posicionado abaixo dos botões de cor regular. (O padrão do sistema é rotulado "outro" botão **mais cores**.)|  
|[CMFCColorMenuButton::EnableTearOff](#enabletearoff)|Habilita a capacidade de separar um painel de cor.|  
|[CMFCColorMenuButton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|  
|[CMFCColorMenuButton::GetColor](#getcolor)|Recupera a cor do botão atual.|  
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
|[CMFCColorMenuButton::CopyFrom](#copyfrom)|Copia o outro botão da barra de ferramentas para o botão atual.|  
|[CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu)|Cria uma caixa de diálogo do seletor de cores.|  
|[CMFCColorMenuButton::IsEmptyMenuAllowed](#isemptymenuallowed)|Indica se há suporte para o menus vazias.|  
|[CMFCColorMenuButton::OnDraw](#ondraw)|Chamado pelo framework para exibir uma imagem em um botão.|  
|[CMFCColorMenuButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pelo framework antes de uma `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.|  
  
## <a name="remarks"></a>Comentários  
 Para substituir o menu da barra de ferramentas ou comando botão original com um `CMFCColorMenuButton` do objeto, crie o `CMFCColorMenuButton` objeto, definir qualquer apropriado [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) estilos e, em seguida, chame o `ReplaceButton` método o [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) classe. Se você personalizar uma barra de ferramentas, chame o [CMFCToolBarsCustomizeDialog::ReplaceButton](../../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) método.  
  
 Caixa de diálogo Seletor de cores é criada durante o processamento de [CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu) manipulador de eventos. O manipulador de eventos notifica o quadro pai com um `WM_COMMAND` mensagem. O `CMFCColorMenuButton` objeto envia a ID de controle que é atribuída para o botão de barra de ferramentas ou comando de menu original.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar e configurar um botão de menu de cor usando vários métodos no `CMFCColorMenuButton` classe. No exemplo, um `CPalette` objeto é criado pela primeira vez e, em seguida, usado para construir um objeto do `CMFCColorMenuButton` classe. O `CMFCColorMenuButton` objeto é configurado, em seguida, habilitar seu automático e outros botões e definindo a cor e o número de colunas. Esse código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#5](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_1.h)]  
[!code-cpp[NVC_MFC_WordPad#6](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)  
  
 [CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolormenubutton.h  
  
##  <a name="cmfccolormenubutton"></a>CMFCColorMenuButton::CMFCColorMenuButton  
 Constrói um objeto `CMFCColorMenuButton`.  
  
```  
CMFCColorMenuButton();

 
CMFCColorMenuButton(
    UINT uiCmdID,  
    LPCTSTR lpszText,  
    CPalette* pPalette=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Uma ID de comando do botão.  
  
 [in] `lpszText`  
 O texto do botão.  
  
 [in] `pPalette`  
 Um ponteiro para uma paleta de cores do botão.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor é o construtor padrão. A cor do objeto atual e cor automática são inicializados para preto RGB ((0, 0, 0)).  
  
 O segundo construtor inicializa o botão para a cor que corresponde à ID de comando especificado.  
  
##  <a name="copyfrom"></a>CMFCColorMenuButton::CopyFrom  
 Copia um [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md)-derivados do objeto para outro.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Botão de origem para copiar.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para copiar os objetos que derivam de `CMFCColorMenuButton` objeto.  
  
##  <a name="createpopupmenu"></a>CMFCColorMenuButton::CreatePopupMenu  
 Cria uma caixa de diálogo do seletor de cores.  
  
```  
virtual CMFCPopupMenu* CreatePopupMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto que representa uma caixa de diálogo do seletor de cores.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando o usuário pressiona um botão de menu de cor.  
  
##  <a name="enableautomaticbutton"></a>CMFCColorMenuButton::EnableAutomaticButton  
 Habilita e desabilita um botão "automático" que será posicionado acima dos botões de cor regular. (O botão automático padrão do sistema é rotulado **automática**.)  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 Especifica o texto do botão é exibido quando o botão ficará automática.  
  
 [in] `colorAutomatic`  
 Especifica uma nova cor automática.  
  
 [in] `bEnable`  
 Especifica se o botão é automático ou não.  
  
### <a name="remarks"></a>Comentários  
 O botão automático aplica-se a cor padrão atual.  
  
##  <a name="enabledocumentcolors"></a>CMFCColorMenuButton::EnableDocumentColors  
 Ativa a exibição de cores específica do documento em vez de cores do sistema.  
  
```  
void EnableDocumentColors(
    LPCTSTR lpszLabel,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 Especifica o texto do botão.  
  
 [in] `bEnable`  
 `TRUE`Para exibir as cores específicas do documento ou `FALSE` para exibir cores do sistema.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para exibir as cores do documento atual ou as cores de paleta do sistema quando o usuário clica em um botão de menu de cor.  
  
##  <a name="enableotherbutton"></a>CMFCColorMenuButton::EnableOtherButton  
 Habilita e desabilita um botão "outro" que será posicionado abaixo dos botões de cor regular. (O padrão do sistema é rotulado "outro" botão **mais cores**.)  
  
```  
void EnableOtherButton(
    LPCTSTR lpszLabel,  
    BOOL bAltColorDlg=TRUE,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 Especifica o texto do botão.  
  
 [in] `bAltColorDlg`  
 Especifique `TRUE` para exibir o `CMFCColorDialog` caixa de diálogo, ou `FALSE` para exibir a caixa de diálogo de cor padrão do sistema.  
  
 [in] `bEnable`  
 Especifique `TRUE` para exibir o botão "outro"; caso contrário, `FALSE`. O padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enabletearoff"></a>CMFCColorMenuButton::EnableTearOff  
 Habilita a capacidade de separar um painel de cor.  
  
```  
void EnableTearOff(
    UINT uiID,  
    int nVertDockColumns=-1,  
    int nHorzDockRows=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 Especifica a ID para o painel destacável.  
  
 [in] `nVertDockColumns`  
 Especifica o número de colunas no painel de cor encaixado na vertical, enquanto estiver no estado destacável.  
  
 [in] `nHorzDockRows`  
 Especifica o número de linhas para o painel encaixado na horizontal cor enquanto estiver no estado destacável.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para habilitar o recurso "destacável" para o painel de cor que surge quando o `CMFCColorMenuButton` botão é pressionado.  
  
##  <a name="getautomaticcolor"></a>CMFCColorMenuButton::GetAutomaticColor  
 Recupera a cor automática atual.  
  
```  
COLORREF GetAutomaticColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor automática atual.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para obter a cor automática que é definida por [CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton).  
  
##  <a name="getcolor"></a>CMFCColorMenuButton::GetColor  
 Recupera a cor do botão atual.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcolorbycmdid"></a>CMFCColorMenuButton::GetColorByCmdID  
 Recupera a cor que corresponde a uma ID de comando especificado.  
  
```  
static COLORREF GetColorByCmdID(UINT uiCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Uma ID de comando.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor que corresponde à ID de comando especificado.  
  
### <a name="remarks"></a>Comentários  
 Use esse método quando você tem vários botões de cor em um aplicativo. Quando o usuário clica em um botão de cor, o botão envia sua ID de comando um `WM_COMMAND` mensagem ao seu pai. O `GetColorByCmdID` método usa a ID de comando para recuperar a cor correspondente.  
  
##  <a name="isemptymenuallowed"></a>CMFCColorMenuButton::IsEmptyMenuAllowed  
 Indica se há suporte para o menus vazias.  
  
```  
virtual BOOL IsEmptyMenuAllowed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se menus vazios são permitidos; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Menus vazias têm suporte por padrão. Substitua este método para alterar esse comportamento na classe derivada.  
  
##  <a name="onchangeparentwnd"></a>CMFCColorMenuButton::OnChangeParentWnd  
 Chamado pelo framework quando a janela pai é alterado.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a nova janela pai.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>CMFCColorMenuButton::OnDraw  
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
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Um retângulo que circunda área seja redesenhado.  
  
 [in] `pImages`  
 Aponta para uma lista de imagens da barra de ferramentas.  
  
 [in] `bHorz`  
 `TRUE`para especificar que a barra de ferramentas está em um estado encaixado horizontal; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
 [in] `bCustomizeMode`  
 `TRUE`para especificar que o aplicativo está no modo de personalização. Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
 [in] `bHighlight`  
 `TRUE`para especificar que o botão é realçado; Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
 [in] `bDrawBorder`  
 `TRUE`para especificar que a borda do botão é exibida; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
 [in] `bGrayDisabledButtons`  
 `TRUE`para especificar que desabilitado botões estão esmaecidos (esmaecido). Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawoncustomizelist"></a>CMFCColorMenuButton::OnDrawOnCustomizeList  
 Chamado pelo framework antes de uma `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.  
  
```  
virtual int OnDrawOnCustomizeList(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Um retângulo que circunda o botão a ser desenhada.  
  
 [in] `bSelected`  
 `TRUE`Especifica que o botão está no estado selecionado. Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura do botão.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo framework quando um `CMFCColorMenuButton` objeto é exibido na caixa de listagem durante o processo de personalização da barra de ferramentas.  
  
##  <a name="opencolordialog"></a>CMFCColorMenuButton::OpenColorDialog  
 Abre uma caixa de diálogo de seleção de cor.  
  
```  
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,  
    COLORREF& colorRes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `colorDefault`  
 A cor padrão que está selecionada na caixa de diálogo de cor.  
  
 [out] `colorRes`  
 Retorna a cor que o usuário seleciona a caixa de diálogo de cor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário seleciona uma cor nova. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando o botão de menu é clicado, chame este método para abrir uma caixa de diálogo de cor. Se o valor de retorno é diferente de zero, a cor selecionada pelo usuário é armazenada no `colorRes` parâmetro. Use o [CMFCColorMenuButton::EnableOtherButton](#enableotherbutton) método para alternar entre a caixa de diálogo de cor padrão e o [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo.  
  
##  <a name="setcolor"></a>CMFCColorMenuButton::SetColor  
 Define a cor do botão de cor atual.  
  
```  
virtual void SetColor(
    COLORREF clr,  
    BOOL bNotify=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `clr`  
 Um valor de cor RGB.  
  
 [in] `bNotify`  
 `TRUE`Para aplicar o `clr` cor de parâmetro para qualquer botão de menu associado ou barra de ferramentas; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para alterar a cor do botão de cor atual. Se o `bNotify` parâmetro é diferente de zero, a cor do botão correspondente em qualquer barra de ferramentas ou menu pop-up associado é alterada para a cor especificada pelo `clr` parâmetro.  
  
##  <a name="setcolorbycmdid"></a>CMFCColorMenuButton::SetColorByCmdID  
 Define a cor do botão de menu cor especificada.  
  
```  
static void SetColorByCmdID(
    UINT uiCmdID,  
    COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 A ID de recurso de um botão de menu de cor.  
  
 [in] `color`  
 Um valor de cor RGB.  
  
##  <a name="setcolorname"></a>CMFCColorMenuButton::SetColorName  
 Define um novo nome para a cor especificada.  
  
```  
static void SetColorName(
    COLORREF color,  
    const CString& strName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 O valor RGB da cor cujo nome é alterado.  
  
 [in] `strName`  
 O novo nome da cor.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcolumnsnumber"></a>CMFCColorMenuButton::SetColumnsNumber  
 Define o número de colunas a serem exibidas em um controle de seleção de cor ( [CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) objeto).  
  
```  
void SetColumnsNumber(int nColumns);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nColumns`  
 O número de colunas a serem exibidas.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)   
 [Classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)
