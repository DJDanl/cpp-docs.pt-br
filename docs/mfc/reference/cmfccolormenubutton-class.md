---
title: Classe CMFCColorMenuButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
dev_langs:
- C++
helpviewer_keywords:
- CMFCColorMenuButton class
ms.assetid: 42685704-e994-4f7b-9553-62283c27b754
caps.latest.revision: 29
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
ms.openlocfilehash: a9b1e7a3dbfe4d98b3d51850723eb22ec1f9da06
ms.lasthandoff: 02/25/2017

---
# <a name="cmfccolormenubutton-class"></a>Classe CMFCColorMenuButton
O `CMFCColorMenuButton` classe oferece suporte a um comando de menu ou um botão que inicia uma caixa de diálogo do seletor de cores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorMenuButton : public CMFCToolBarMenuButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::CMFCColorMenuButton](#cmfccolormenubutton)|Constrói um objeto `CMFCColorMenuButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton)|Habilita e desabilita um botão "automático" que está posicionado acima dos botões de cor normal. (O botão automática padrão do sistema é rotulado como **automáticas**.)|  
|[CMFCColorMenuButton::EnableDocumentColors](#enabledocumentcolors)|Permite a exibição de cores de documento específico, em vez de cores do sistema.|  
|[CMFCColorMenuButton::EnableOtherButton](#enableotherbutton)|Habilita e desabilita um botão "outro" que será posicionado abaixo dos botões de cor normal. (O padrão do sistema é rotulado como "outro" botão **mais cores... **.)|  
|[CMFCColorMenuButton::EnableTearOff](#enabletearoff)|Habilita a capacidade de separar um painel de cor.|  
|[CMFCColorMenuButton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|  
|[CMFCColorMenuButton::GetColor](#getcolor)|Recupera a cor do botão.|  
|[CMFCColorMenuButton::GetColorByCmdID](#getcolorbycmdid)|Recupera a cor que corresponde a uma ID de comando especificado.|  
|[CMFCColorMenuButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando altera a janela pai.|  
|[CMFCColorMenuButton::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de seleção de cor.|  
|[CMFCColorMenuButton::SetColor](#setcolor)|Define a cor do botão de cor atual.|  
|[CMFCColorMenuButton::SetColorByCmdID](#setcolorbycmdid)|Define a cor do botão de menu cor especificada.|  
|[CMFCColorMenuButton::SetColorName](#setcolorname)|Define um novo nome para a cor especificada.|  
|[CMFCColorMenuButton::SetColumnsNumber](#setcolumnsnumber)|Define o número de colunas que são exibidas por um `CMFCColorBar` objeto.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorMenuButton::CopyFrom](#copyfrom)|Copia outro botão da barra de ferramentas para o botão atual.|  
|[CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu)|Cria uma caixa de diálogo do seletor de cores.|  
|[CMFCColorMenuButton::IsEmptyMenuAllowed](#isemptymenuallowed)|Indica se os menus vazias têm suporte.|  
|[CMFCColorMenuButton::OnDraw](#ondraw)|Chamado pela estrutura para exibir uma imagem em um botão.|  
|[CMFCColorMenuButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pela estrutura antes de uma `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.|  
  
## <a name="remarks"></a>Comentários  
 Para substituir o menu da barra de ferramentas ou comando botão original com um `CMFCColorMenuButton` de objeto, criar o `CMFCColorMenuButton` objeto, qualquer apropriado [CMFCColorBar classe](../../mfc/reference/cmfccolorbar-class.md) estilos e, em seguida, chame o `ReplaceButton` método o [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) classe. Se você personalizar uma barra de ferramentas, chame o [CMFCToolBarsCustomizeDialog::ReplaceButton](../../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) método.  
  
 A caixa de diálogo do seletor de cores é criada durante o processamento de [CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu) manipulador de eventos. O manipulador de eventos notifica o quadro principal com um `WM_COMMAND` mensagem. O `CMFCColorMenuButton` objeto envia a ID do controle que é atribuída para o botão de barra de ferramentas ou comando de menu original.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar e configurar um botão de menu de cor usando vários métodos na `CMFCColorMenuButton` classe. No exemplo, um `CPalette` objeto é criado primeiro e, em seguida, usado para construir um objeto de `CMFCColorMenuButton` classe. O `CMFCColorMenuButton` objeto é configurado, em seguida, permitindo seu automático e outros botões e definindo a cor e o número de colunas. Esse código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad n º&5;](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_1.h)]  
[!code-cpp[NVC_MFC_WordPad n º&6;](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_2.cpp)]  
  
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
 O primeiro construtor é o construtor padrão. A cor do objeto atual e cor automática são inicializados para preto (RGB (0, 0, 0)).  
  
 O segundo construtor inicializa o botão para a cor que corresponde à ID de comando especificado.  
  
##  <a name="copyfrom"></a>CMFCColorMenuButton::CopyFrom  
 Copia uma [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md)-objeto derivado para outro.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Botão de origem para copiar.  
  
### <a name="remarks"></a>Comentários  
 Substitui esse método para copiar os objetos que derivam de `CMFCColorMenuButton` objeto.  
  
##  <a name="createpopupmenu"></a>CMFCColorMenuButton::CreatePopupMenu  
 Cria uma caixa de diálogo do seletor de cores.  
  
```  
virtual CMFCPopupMenu* CreatePopupMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto que representa uma caixa de diálogo do seletor de cores.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura quando o usuário pressionar um botão de menu de cor.  
  
##  <a name="enableautomaticbutton"></a>CMFCColorMenuButton::EnableAutomaticButton  
 Habilita e desabilita um botão "automático" que está posicionado acima dos botões de cor normal. (O botão automática padrão do sistema é rotulado como **automáticas**.)  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 Especifica o texto do botão que é exibido quando o botão se torna automática.  
  
 [in] `colorAutomatic`  
 Especifica uma nova cor automática.  
  
 [in] `bEnable`  
 Especifica se o botão é automático ou não.  
  
### <a name="remarks"></a>Comentários  
 O botão automática se aplica a cor padrão atual.  
  
##  <a name="enabledocumentcolors"></a>CMFCColorMenuButton::EnableDocumentColors  
 Permite a exibição de cores de documento específico, em vez de cores do sistema.  
  
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
 Use esse método para exibir as cores do documento atual ou a paleta de cores do sistema quando o usuário clica em um botão de menu de cor.  
  
##  <a name="enableotherbutton"></a>CMFCColorMenuButton::EnableOtherButton  
 Habilita e desabilita um botão "outro" que será posicionado abaixo dos botões de cor normal. (O padrão do sistema é rotulado como "outro" botão **mais cores... **.)  
  
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
 Especifica a ID do painel destacável.  
  
 [in] `nVertDockColumns`  
 Especifica o número de colunas no painel encaixado na vertical cor enquanto estiver em estado destacável.  
  
 [in] `nHorzDockRows`  
 Especifica o número de linhas para o painel Cor ancorada horizontalmente no estado destacável.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para habilitar o recurso "destacável" para o painel de cor que surge quando o `CMFCColorMenuButton` é pressionado.  
  
##  <a name="getautomaticcolor"></a>CMFCColorMenuButton::GetAutomaticColor  
 Recupera a cor automática atual.  
  
```  
COLORREF GetAutomaticColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor automática atual.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para obter a cor automática é definida por [CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton).  
  
##  <a name="getcolor"></a>CMFCColorMenuButton::GetColor  
 Recupera a cor do botão.  
  
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
 Use esse método quando você tem vários botões de cor em um aplicativo. Quando o usuário clica em um botão de cor, o botão envia sua ID de comando em um `WM_COMMAND` mensagem ao seu pai. O `GetColorByCmdID` método usa a ID de comando para recuperar a cor correspondente.  
  
##  <a name="isemptymenuallowed"></a>CMFCColorMenuButton::IsEmptyMenuAllowed  
 Indica se os menus vazias têm suporte.  
  
```  
virtual BOOL IsEmptyMenuAllowed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se são permitidas menus vazias; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Menus vazias são suportados por padrão. Substitui esse método para alterar esse comportamento na classe derivada.  
  
##  <a name="onchangeparentwnd"></a>CMFCColorMenuButton::OnChangeParentWnd  
 Chamado pela estrutura quando altera a janela pai.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a nova janela pai.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>CMFCColorMenuButton::OnDraw  
 Chamado pela estrutura para exibir uma imagem em um botão.  
  
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
 Um retângulo que circunda a área a ser redesenhado.  
  
 [in] `pImages`  
 Aponta para uma lista de imagens da barra de ferramentas.  
  
 [in] `bHorz`  
 `TRUE`para especificar que a barra de ferramentas está em um estado ancorado horizontal; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
 [in] `bCustomizeMode`  
 `TRUE`para especificar que o aplicativo está no modo de personalização. Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
 [in] `bHighlight`  
 `TRUE`para especificar que o botão é realçado; Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
 [in] `bDrawBorder`  
 `TRUE`para especificar que a borda do botão é exibida; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
 [in] `bGrayDisabledButtons`  
 `TRUE`para especificar que desabilitado botões estão cinza (esmaecido). Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawoncustomizelist"></a>CMFCColorMenuButton::OnDrawOnCustomizeList  
 Chamado pela estrutura antes de uma `CMFCColorMenuButton` objeto é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.  
  
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
 Este método é chamado pela estrutura quando um `CMFCColorMenuButton` objeto é exibido na caixa de listagem durante o processo de personalização da barra de ferramentas.  
  
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
 Retorna a cor selecionada pelo usuário na caixa de diálogo de cor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário selecionar uma nova cor. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando o botão de menu é clicado, chame este método para abrir uma caixa de diálogo de cor. Se o valor de retorno é diferente de zero, a cor selecionada pelo usuário é armazenada no `colorRes` parâmetro. Use o [CMFCColorMenuButton::EnableOtherButton](#enableotherbutton) método para alternar entre a caixa de diálogo cores padrão e o [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo.  
  
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
 `TRUE`Para aplicar o `clr` cores de parâmetro para qualquer botão de menu associados ou barra de ferramentas; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para alterar a cor do botão de cor atual. Se o `bNotify` parâmetro for diferente de zero, a cor do botão correspondente em qualquer menu pop-up associado ou a barra de ferramentas é alterada para a cor especificada pelo `clr` parâmetro.  
  
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

