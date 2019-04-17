---
title: Classe CMFCColorBar
ms.date: 11/04/2016
f1_keywords:
- CMFCColorBar
- AFXCOLORBAR/CMFCColorBar
- AFXCOLORBAR/CMFCColorBar::CMFCColorBar
- AFXCOLORBAR/CMFCColorBar::ContextToSize
- AFXCOLORBAR/CMFCColorBar::CreateControl
- AFXCOLORBAR/CMFCColorBar::Create
- AFXCOLORBAR/CMFCColorBar::EnableAutomaticButton
- AFXCOLORBAR/CMFCColorBar::EnableOtherButton
- AFXCOLORBAR/CMFCColorBar::GetColor
- AFXCOLORBAR/CMFCColorBar::GetCommandID
- AFXCOLORBAR/CMFCColorBar::GetHighlightedColor
- AFXCOLORBAR/CMFCColorBar::GetHorzMargin
- AFXCOLORBAR/CMFCColorBar::GetVertMargin
- AFXCOLORBAR/CMFCColorBar::IsTearOff
- AFXCOLORBAR/CMFCColorBar::SetColor
- AFXCOLORBAR/CMFCColorBar::SetColorName
- AFXCOLORBAR/CMFCColorBar::SetCommandID
- AFXCOLORBAR/CMFCColorBar::SetDocumentColors
- AFXCOLORBAR/CMFCColorBar::SetHorzMargin
- AFXCOLORBAR/CMFCColorBar::SetVertMargin
- AFXCOLORBAR/CMFCColorBar::AdjustLocations
- AFXCOLORBAR/CMFCColorBar::AllowChangeTextLabels
- AFXCOLORBAR/CMFCColorBar::AllowShowOnList
- AFXCOLORBAR/CMFCColorBar::CalcSize
- AFXCOLORBAR/CMFCColorBar::CreatePalette
- AFXCOLORBAR/CMFCColorBar::GetColorGridSize
- AFXCOLORBAR/CMFCColorBar::GetExtraHeight
- AFXCOLORBAR/CMFCColorBar::InitColors
- AFXCOLORBAR/CMFCColorBar::OnKey
- AFXCOLORBAR/CMFCColorBar::OnSendCommand
- AFXCOLORBAR/CMFCColorBar::OnUpdateCmdUI
- AFXCOLORBAR/CMFCColorBar::OpenColorDialog
- AFXCOLORBAR/CMFCColorBar::Rebuild
- AFXCOLORBAR/CMFCColorBar::SelectPalette
- AFXCOLORBAR/CMFCColorBar::SetPropList
- AFXCOLORBAR/CMFCColorBar::ShowCommandMessageString
helpviewer_keywords:
- CMFCColorBar [MFC], CMFCColorBar
- CMFCColorBar [MFC], ContextToSize
- CMFCColorBar [MFC], CreateControl
- CMFCColorBar [MFC], Create
- CMFCColorBar [MFC], EnableAutomaticButton
- CMFCColorBar [MFC], EnableOtherButton
- CMFCColorBar [MFC], GetColor
- CMFCColorBar [MFC], GetCommandID
- CMFCColorBar [MFC], GetHighlightedColor
- CMFCColorBar [MFC], GetHorzMargin
- CMFCColorBar [MFC], GetVertMargin
- CMFCColorBar [MFC], IsTearOff
- CMFCColorBar [MFC], SetColor
- CMFCColorBar [MFC], SetColorName
- CMFCColorBar [MFC], SetCommandID
- CMFCColorBar [MFC], SetDocumentColors
- CMFCColorBar [MFC], SetHorzMargin
- CMFCColorBar [MFC], SetVertMargin
- CMFCColorBar [MFC], AdjustLocations
- CMFCColorBar [MFC], AllowChangeTextLabels
- CMFCColorBar [MFC], AllowShowOnList
- CMFCColorBar [MFC], CalcSize
- CMFCColorBar [MFC], CreatePalette
- CMFCColorBar [MFC], GetColorGridSize
- CMFCColorBar [MFC], GetExtraHeight
- CMFCColorBar [MFC], InitColors
- CMFCColorBar [MFC], OnKey
- CMFCColorBar [MFC], OnSendCommand
- CMFCColorBar [MFC], OnUpdateCmdUI
- CMFCColorBar [MFC], OpenColorDialog
- CMFCColorBar [MFC], Rebuild
- CMFCColorBar [MFC], SelectPalette
- CMFCColorBar [MFC], SetPropList
- CMFCColorBar [MFC], ShowCommandMessageString
ms.assetid: 4756ee40-25a5-4cee-af7f-acab7993d1c7
ms.openlocfilehash: 4eee24eb93be446f6b4f2631b70736c13a02f45c
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58771401"
---
# <a name="cmfccolorbar-class"></a>Classe CMFCColorBar

O `CMFCColorBar` classe representa uma barra de controle de encaixe que pode selecionar cores em um documento ou aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorBar : public CMFCPopupMenuBar
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorBar::CMFCColorBar](#cmfccolorbar)|Constrói um objeto `CMFCColorBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorBar::ContextToSize](#contexttosize)|Calcula as margens verticais e horizontais que são necessários para conter os botões no controle de barra de cores e, em seguida, ajusta o local desses botões.|
|[CMFCColorBar::CreateControl](#createcontrol)|Cria uma janela de controle de barra de cores, anexa-o para o `CMFCColorBar` de objeto e redimensiona o controle para conter a paleta de cores especificada.|
|[CMFCColorBar::Create](#create)|Cria uma janela de controle de barra de cores e anexa-o para o `CMFCColorBar` objeto.|
|[CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton)|Mostra ou oculta o botão automático.|
|[CMFCColorBar::EnableOtherButton](#enableotherbutton)|Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.|
|[CMFCColorBar::GetColor](#getcolor)|Recupera a cor atualmente selecionada.|
|[CMFCColorBar::GetCommandID](#getcommandid)|Recupera a ID de comando do controle de barra de cores atual.|
|[CMFCColorBar::GetHighlightedColor](#gethighlightedcolor)|Recupera a cor que indica que um botão de cor tem o foco; ou seja, o botão está *hot*.|
|[CMFCColorBar::GetHorzMargin](#gethorzmargin)|Recupera a margem horizontal, que é o espaço entre a esquerda ou célula de cor direita e os limites da área de cliente.|
|[CMFCColorBar::GetVertMargin](#getvertmargin)|Recupera a margem vertical, o que é o espaço entre a parte superior ou célula de cor inferior e os limites da área de cliente.|
|[CMFCColorBar::IsTearOff](#istearoff)|Indica se a barra de cores atual é encaixável.|
|[CMFCColorBar::SetColor](#setcolor)|Define a cor que está selecionada no momento.|
|[CMFCColorBar::SetColorName](#setcolorname)|Define um novo nome para uma cor especificada.|
|[CMFCColorBar::SetCommandID](#setcommandid)|Define uma nova ID de comando para um controle de barra de cores.|
|[CMFCColorBar::SetDocumentColors](#setdocumentcolors)|Define a lista de cores usadas no documento atual.|
|[CMFCColorBar::SetHorzMargin](#sethorzmargin)|Define a margem horizontal, que é o espaço entre a esquerda ou célula de cor direita e os limites da área de cliente.|
|[CMFCColorBar::SetVertMargin](#setvertmargin)|Define a margem vertical, o que é o espaço entre a célula de cor superior ou inferior e os limites da área de cliente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorBar::AdjustLocations](#adjustlocations)|Ajusta as posições dos botões de cor no controle de barra de cores.|
|[CMFCColorBar::AllowChangeTextLabels](#allowchangetextlabels)|Indica se o rótulo de texto dos botões de cor pode alterar.|
|[CMFCColorBar::AllowShowOnList](#allowshowonlist)|Indica se o objeto de controle de barra de cores pode aparecer em uma lista da barra de ferramentas durante o processo de personalização.|
|[CMFCColorBar::CalcSize](#calcsize)|Chamado pelo framework como parte do processo de cálculo de layout.|
|[CMFCColorBar::CreatePalette](#createpalette)|Inicializa uma paleta com as cores em uma matriz de cores especificada.|
|[CMFCColorBar::GetColorGridSize](#getcolorgridsize)|Calcula o número de linhas e colunas na grade de um controle de barra de cores.|
|[CMFCColorBar::GetExtraHeight](#getextraheight)|Calcula a altura adicional que a barra de cores atual requer para exibir elementos de interface do usuário diversos, como o **outros** botão, cores de documento e assim por diante.|
|[CMFCColorBar::InitColors](#initcolors)|Inicializa uma matriz de cores com as cores na paleta de padrão do sistema ou de uma paleta especificada.|
|[CMFCColorBar::OnKey](#onkey)|Chamado pelo framework quando um usuário pressiona um botão do teclado.|
|[CMFCColorBar::OnSendCommand](#onsendcommand)|Chamado pelo framework para fechar uma hierarquia de controles de pop-up.|
|[CMFCColorBar::OnUpdateCmdUI](#onupdatecmdui)|Chamado pelo framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores antes do item é exibido.|
|[CMFCColorBar::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de cor.|
|[CMFCColorBar::Rebuild](#rebuild)|Completamente redesenha o controle de barra de cores.|
|[CMFCColorBar::SelectPalette](#selectpalette)|Define a paleta lógica do contexto de dispositivo especificado para a paleta do botão pai do controle de barra de cores atual.|
|[CMFCColorBar::SetPropList](#setproplist)|Define o `m_pWndPropList` protegido membro de dados para o ponteiro especificado para um controle de grade de propriedade.|
|[CMFCColorBar::ShowCommandMessageString](#showcommandmessagestring)|Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha de mensagem na barra de status.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bInternal`|Um campo booliano que determina se os eventos de mouse são processados. Normalmente, os eventos de mouse são processados quando esse campo é verdadeiro e modo de personalização é FALSE.|
|`m_bIsEnabled`|Um booliano que indica se um controle está habilitado.|
|`m_bIsTearOff`|Um booliano que indica se o controle de barra de cores oferece suporte de encaixe.|
|`m_BoxSize`|Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o tamanho de uma célula em uma grade de barra de cores.|
|`m_bShowDocColorsWhenDocked`|Um booliano que indica se deve ser mostrada cores de documento quando a barra de cores é encaixada. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|
|`m_bStdColorDlg`|Um valor booliano que indica se deve mostrar a caixa de diálogo de cor padrão do sistema ou o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|
|`m_ColorAutomatic`|Um [COLORREF](/windows/desktop/gdi/colorref) que armazena a cor automática atual. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|
|`m_ColorNames`|Uma [CMap](../../mfc/reference/cmap-class.md) cores com seus nomes de objeto que associa um conjunto de RGB.|
|`m_colors`|Um [CArray](../../mfc/reference/carray-class.md) dos [COLORREF](/windows/desktop/gdi/colorref) valores que contém as cores que são exibidas no controle de barra de cores.|
|`m_ColorSelected`|Um [COLORREF](/windows/desktop/gdi/colorref) valor que é a cor que o usuário tiver selecionado no momento do controle de barra de cores.|
|`m_lstDocColors`|Um [CList](../../mfc/reference/clist-class.md) dos [COLORREF](/windows/desktop/gdi/colorref) valores que contém as cores que são atualmente usadas em um documento.|
|`m_nCommandID`|Um inteiro sem sinal que é a ID de comando de um botão de cor.|
|`m_nHorzMargin`|Um inteiro que é a margem horizontal entre os botões de cor em uma grade de cores.|
|`m_nHorzOffset`|Um inteiro que é o deslocamento horizontal para o centro do botão de cor. Esse valor é significativo se o botão exibe o texto ou uma imagem, além de uma cor.|
|`m_nNumColumns`|Um inteiro que é o número de colunas em uma grade de controle de barra de cores de cores.|
|`m_nNumColumnsVert`|Um inteiro que é o número de colunas em uma grade orientada verticalmente de cores.|
|`m_nNumRowsHorz`|Um inteiro que é o número de colunas em uma grade orientada horizontalmente de cores.|
|`m_nRowHeight`|Um inteiro que é a altura de uma linha de botões de cor em uma grade de cores.|
|`m_nVertMargin`|Um inteiro que é a margem vertical entre os botões de cor em uma grade de cores.|
|`m_nVertOffset`|Um inteiro que é o deslocamento vertical para o centro do botão de cor. Esse valor é significativo se o botão exibe o texto ou uma imagem, além de uma cor.|
|`m_Palette`|Um [CPalette](../../mfc/reference/cpalette-class.md) das cores que são usadas no controle de barra de cores.|
|`m_pParentBtn`|Um ponteiro para um [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) objeto que é o pai do botão atual. Esse valor é significativo se o botão de cor está em uma hierarquia de controles de barra de ferramentas ou está em um controle de grade de propriedade de cor.|
|`m_pParentRibbonBtn`|Um ponteiro para um [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md) objeto que está na faixa de opções e o botão do pai do botão atual. Esse valor é significativo se o botão de cor está em uma hierarquia de controles de barra de ferramentas ou está em um controle de grade de propriedade de cor.|
|`m_pWndPropList`|Um ponteiro para um [CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) objeto.|
|`m_strAutoColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido na **automático** botão. Para obter mais informações, consulte [CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton).|
|`m_strDocColors`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão de cores do documento. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|
|`m_strOtherColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido na *outros* botão. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|

## <a name="remarks"></a>Comentários

Normalmente, você não crie um `CMFCColorBar` diretamente do objeto. Em vez disso, o [classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) (usado em menus e barras de ferramentas) ou o [classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) cria o `CMFCColorBar` objeto.

O `CMFCColorBar` classe fornece a seguinte funcionalidade:

- Ajusta automaticamente a lista de cores do documento.

- Salva e restaura o estado, junto com o estado do documento.

- Gerencia o botão "automático".

- Usa o [classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) controle para selecionar uma cor personalizada.

- Dá suporte a um estado "destacáveis" (se ela for criada usando o [classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)).

Para incorporar o `CMFCColorBar` funcionalidade em seu aplicativo:

1. Criar um botão de menu comum e atribuí-lo uma ID, por exemplo ID_CHAR_COLOR.

1. Em sua classe de janela de quadro, substituir os [CFrameWndEx::OnShowPopupMenu](../../mfc/reference/cframewndex-class.md#onshowpopupmenu) método e substituir o menu comum de botão com um [classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) objeto (chamando [CMFCToolBar: : ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)).

1. Definir todos os estilos e habilitar ou desabilitar os recursos do `CMFCColorBar` do objeto durante [classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) criação. O `CMFCColorMenuButton` objeto cria dinamicamente o `CMFCColorBar` objeto após a estrutura chama o `CreatePopupMenu` método.

Quando o usuário clica em um botão de controle de barra de cores, a estrutura usa a `ON_COMMAND` macro para notificar o pai do controle de barra de cores. Na macro, o parâmetro de ID de comando é o valor que você atribuiu ao botão de controle de barra de cores na etapa 1 (ID_CHAR_COLOR neste exemplo). Para obter mais informações, consulte o [classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md), [classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md), [classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md), [classe CFrameWndEx](../../mfc/reference/cframewndex-class.md), e [classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) classes.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma barra de cores usando vários métodos no `CMFCColorBar` classe. Os métodos de definir as margens horizontais e verticais, habilitam o outro botão, criam uma janela de controle de barra de cores e define a cor atualmente selecionada. Este exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#1](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#2](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

[CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)

[CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorbar.h

##  <a name="adjustlocations"></a>  CMFCColorBar::AdjustLocations

Ajusta as posições dos botões de cor no controle de barra de cores.

```
virtual void AdjustLocations();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo framework durante o processamento da mensagem WM_SIZE.

##  <a name="allowchangetextlabels"></a>  CMFCColorBar::AllowChangeTextLabels

Indica se o rótulo de texto dos botões de cor pode alterar.

```
virtual BOOL AllowChangeTextLabels() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre FALSE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna FALSE, que significa que os rótulos de texto não podem ser modificados. Substitua este método para habilitar a modificação de rótulos de texto.

##  <a name="allowshowonlist"></a>  CMFCColorBar::AllowShowOnList

Indica se o objeto de controle de barra de cores pode aparecer em uma lista da barra de ferramentas durante o processo de personalização.

```
virtual BOOL AllowShowOnList() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre TRUE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna TRUE, que significa que a estrutura pode exibir o controle de barra de cores durante o processo de personalização. Substitua este método para implementar um comportamento diferente.

##  <a name="calcsize"></a>  CMFCColorBar::CalcSize

Chamado pelo framework como parte do processo de cálculo de layout.

```
virtual CSize CalcSize(BOOL bVertDock);
```

### <a name="parameters"></a>Parâmetros

*bVertDock*<br/>
[in] TRUE para especificar que o controle de barra de cores é encaixado verticalmente; FALSO para especificar que o controle de barra de cores é ancorado na horizontal.

### <a name="return-value"></a>Valor de retorno

O tamanho da matriz de botões de cor em um controle de barra de cores.

##  <a name="cmfccolorbar"></a>  CMFCColorBar::CMFCColorBar

Constrói um objeto `CMFCColorBar`.

```
CMFCColorBar(
    const CArray<COLORREF,COLORREF>& colors,
    COLORREF color,
    LPCTSTR lpszAutoColor,
    LPCTSTR lpszOtherColor,
    LPCTSTR lpszDocColors,
    CList<COLORREF,COLORREF>& lstDocColors,
    int nColumns,
    int nRowsDockHorz,
    int nColDockVert,
    COLORREF colorAutomatic,
    UINT nCommandID,
    CMFCColorButton* pParentBtn);

CMFCColorBar(
    const CArray<COLORREF,COLORREF>& colors,
    COLORREF color,
    LPCTSTR lpszAutoColor,
    LPCTSTR lpszOtherColor,
    LPCTSTR lpszDocColors,
    CList<COLORREF,COLORREF>& lstDocColors,
    int nColumns,
    COLORREF colorAutomatic,
    UINT nCommandID,
    CMFCRibbonColorButton* pParentRibbonBtn);

CMFCColorBar(
    CMFCColorBar& src,
    UINT uiCommandID);
```

### <a name="parameters"></a>Parâmetros

*Cores*<br/>
[in] Uma matriz de cores que o framework exibe no controle de barra de cores.

*color*<br/>
[in] A cor selecionada inicialmente.

*lpszAutoColor*<br/>
[in] O rótulo de texto a *automática* botão de cor (padrão), ou nulo.

O rótulo padrão do botão automático estiver **automática**.

*lpszOtherColor*<br/>
[in] O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou nulo.

É o rótulo padrão para o outro botão **mais cores...**.

*lpszDocColors*<br/>
[in] O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que atualmente usa o documento.

*lstDocColors*<br/>
[in] Uma lista de cores que atualmente usa o documento.

*nColumns*<br/>
[in] O número de colunas que tem a matriz de cores.

*nRowsDockHorz*<br/>
[in] O número de linhas que a barra de cores tem quando ela estiver encaixada horizontalmente.

*nColDockVert*<br/>
[in] O número de colunas que a barra de cores tem quando ela estiver encaixada verticalmente.

*colorAutomatic*<br/>
[in] A cor padrão que a estrutura se aplica quando você clicar no botão automático.

*nCommandID*<br/>
[in] ID do comando de controle de barra de cores.

*pParentBtn*<br/>
[in] Um ponteiro para um botão de pai.

*src*<br/>
[in] Um existente `CMFCColorBar` o objeto a ser copiado para o novo `CMFCColorBar` objeto.

*uiCommandID*<br/>
[in] A ID de comando.

##  <a name="contexttosize"></a>  CMFCColorBar::ContextToSize

Calcula as margens verticais e horizontais que são necessários para conter os botões no controle de barra de cores e ajusta o local desses botões.

```
void ContextToSize(
    BOOL bSquareButtons = TRUE,
    BOOL bCenterButtons = TRUE);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bSquareButtons*|[in] TRUE para especificar que a forma dos botões em um controle de barra de cores são quadrado; Caso contrário, FALSE. O valor padrão é TRUE.|
|*bCenterButtons*|[in] TRUE para especificar que o conteúdo de face de um botão de controle de barra de cores é centralizado; Caso contrário, FALSE. O valor padrão é TRUE.|

### <a name="remarks"></a>Comentários

##  <a name="create"></a>  CMFCColorBar::Create

Cria uma janela de controle de barra de cores e anexa-o para o `CMFCColorBar` objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle,
    UINT nID,
    CPalette* pPalette=NULL,
    int nColumns=0,
    int nRowsDockHorz=0,
    int nColDockVert=0);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
[in] Ponteiro para a janela pai.

*dwStyle*<br/>
[in] Uma combinação bit a bit (OR) de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*nID*<br/>
[in] A ID de comando.

*pPalette*<br/>
[in] Ponteiro para uma paleta de cores. O padrão é NULL.

*nColumns*<br/>
[in] O número de colunas no controle de barra de cores. O padrão é 0.

*nRowsDockHorz*<br/>
[in] O número de linhas no controle de barra de cores quando ela estiver encaixada horizontalmente. O padrão é 0.

*nColDockVert*<br/>
[in] O número de colunas no controle de barra de cores quando ela estiver encaixada verticalmente. O padrão é 0.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para construir um `CMFCColorBar` de objeto, chame o construtor de classe e em seguida, esse método. O `Create` método cria o controle do Windows e a inicializa de uma lista de cores.

##  <a name="createcontrol"></a>  CMFCColorBar::CreateControl

Cria uma janela de controle de barra de cores, anexa-o para o `CMFCColorBar` de objeto e redimensiona a janela de controle para conter a paleta de cores especificada.

```
virtual BOOL CreateControl(
    CWnd* pParentWnd,
    const CRect& rect,
    UINT nID,
    int nColumns=-1,
    CPalette* pPalette=NULL);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
[in] Ponteiro para a janela pai. Não pode ser NULL.

*rect*<br/>
[in] Um retângulo delimitador que especifica o local desenhar o controle de barra de cores.

*nID*<br/>
[in] A ID do controle.

*nColumns*<br/>
[in] O número ideal de colunas no controle de barra de cores. Esse método modifica esse número de acordo com a paleta de cores especificada. O padrão é -1, o que significa que esse parâmetro não for especificado.

*pPalette*<br/>
[in] Ponteiro para uma paleta de cores, ou NULL. Se esse parâmetro for NULL, esse método calcula o tamanho do controle de barra de cores, como se 20 cores foram especificadas. O padrão é NULL.

### <a name="return-value"></a>Valor de retorno

TRUE se este método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa o *rect*, *nColumns*, e *pPalette* parâmetros para calcular o número apropriado ou linhas e colunas no controle de barra de cores e, em seguida, chama o [CMFCColorBar::Create](#create) método.

##  <a name="createpalette"></a>  CMFCColorBar::CreatePalette

Inicializa uma paleta com as cores em uma matriz de cores especificada.

```
static BOOL CreatePalette(
    const CArray<COLORREF, COLORREF>& arColors,
    CPalette& palette);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*arColors*|[in] Uma matriz de cores.|
|*palette*|[in] Uma paleta de cores.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

##  <a name="enableautomaticbutton"></a>  CMFCColorBar::EnableAutomaticButton

Mostra ou oculta o botão automático.

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[in] O rótulo de texto a *automática* botão de cor (padrão), ou nulo.

O rótulo padrão do botão automático estiver **automática**.

*colorAutomatic*<br/>
[in] A cor padrão que a estrutura se aplica quando você clicar no botão automático.

*bEnable*<br/>
[in] TRUE para habilitar o botão automático; FALSE para desabilitar o botão automático. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

O rótulo de texto do botão automático será excluído se o *lpszLabel* parâmetro for nulo ou o *bAtivar* parâmetro é falso.

##  <a name="enableotherbutton"></a>  CMFCColorBar::EnableOtherButton

Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[in] O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou nulo.

O rótulo padrão para este botão é **mais cores...**.

*bAltColorDlg*<br/>
[in] True para exibir o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo. FALSE para exibir o padrão [CColorDialog](../../mfc/reference/ccolordialog-class.md) caixa de diálogo. O valor padrão é TRUE.

*bEnable*<br/>
[in] TRUE para habilitar o botão; FALSE para desabilitar o botão. O valor padrão é TRUE.

##  <a name="getcolor"></a>  CMFCColorBar::GetColor

Recupera a cor atualmente selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor atualmente selecionada.

##  <a name="getcolorgridsize"></a>  CMFCColorBar::GetColorGridSize

Calcula o número de linhas e colunas na grade de um controle de barra de cores.

```
CSize GetColorGridSize(BOOL bVertDock) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bVertDock*|[in] TRUE para executar o cálculo para um controle encaixado na vertical na barra de cores; Caso contrário, realize o cálculo para um controle encaixado na horizontal.|

### <a name="return-value"></a>Valor de retorno

Um [CSize](../../atl-mfc-shared/reference/csize-class.md) do objeto cuja `cx` componente contém o número de colunas e cujo `cy` componente contém o número de linhas.

##  <a name="getcommandid"></a>  CMFCColorBar::GetCommandID

Recupera a ID de comando do controle de barra de cores atual.

```
UINT GetCommandID() const;
```

### <a name="return-value"></a>Valor de retorno

Uma ID de comando.

### <a name="remarks"></a>Comentários

Quando o usuário seleciona uma nova cor, a estrutura envia a ID de comando em uma mensagem WM_COMMAND para notificar o pai do `CMFCColorBar` objeto.

##  <a name="getextraheight"></a>  CMFCColorBar::GetExtraHeight

Calcula a altura adicional que a barra de cores atual requer para exibir elementos de interface de usuário diversos, como o **outros** as cores do botão ou documento.

```
int GetExtraHeight(int nNumColumns) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nNumColumns*|[in] Se o controle de barra de cores contém cores de documento, o número de colunas a serem exibidas na grade de cores do documento. Caso contrário, esse valor não é usado.|

### <a name="return-value"></a>Valor de retorno

A altura extra calculada é necessária.

##  <a name="gethighlightedcolor"></a>  CMFCColorBar::GetHighlightedColor

Recupera a cor que indica que um botão de cor tem o foco; ou seja, o botão está *hot*.

```
COLORREF GetHighlightedColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="gethorzmargin"></a>  CMFCColorBar::GetHorzMargin

Recupera a margem horizontal, que é o espaço entre a esquerda ou célula de cor direita e os limites da área de cliente.

```
int GetHorzMargin();
```

### <a name="return-value"></a>Valor de retorno

A margem horizontal.

##  <a name="getvertmargin"></a>  CMFCColorBar::GetVertMargin

Recupera a margem vertical, o que é o espaço entre a parte superior ou célula de cor inferior e os limites da área de cliente.

```
int GetVertMargin() const;
```

### <a name="return-value"></a>Valor de retorno

A margem vertical.

##  <a name="initcolors"></a>  CMFCColorBar::InitColors

Inicializa uma matriz de cores com as cores em uma paleta especificada, ou com a paleta do sistema padrão.

```
static int InitColors(
    CPalette* pPalette,
    CArray<COLORREF, COLORREF>& arColors);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pPalette*|[in] Um ponteiro para um objeto de paleta, ou nulo. Se esse parâmetro for NULL, esse método usa a paleta padrão do sistema operacional.|
|*arColors*|[in] Uma matriz de cores.|

### <a name="return-value"></a>Valor de retorno

O número de elementos na matriz de cores.

##  <a name="istearoff"></a>  CMFCColorBar::IsTearOff

Indica se a barra de cores atual é encaixável.

```
BOOL IsTearOff() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle de barra de cores atual seja encaixável; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle de barra de cores é encaixável, pode ser interrompida desativar uma barra de controle e encaixado em outro local.

##  <a name="onkey"></a>  CMFCColorBar::OnKey

Chamado pelo framework quando um usuário pressiona um botão do teclado.

```
virtual BOOL OnKey(UINT nChar);
```

### <a name="parameters"></a>Parâmetros

*nChar*<br/>
[in] O código de tecla virtual para a chave que o usuário pressionou.

### <a name="return-value"></a>Valor de retorno

TRUE se este método processa a chave especificada; Caso contrário, FALSE.

##  <a name="onsendcommand"></a>  CMFCColorBar::OnSendCommand

Chamado pelo framework para fechar uma hierarquia de controles pop-up.

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pButton*|[in] Ponteiro para um controle que reside em uma barra de ferramentas.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

##  <a name="onupdatecmdui"></a>  CMFCColorBar::OnUpdateCmdUI

Chamado pelo framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores antes do item é exibido.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

*pTarget*<br/>
[in] Ponteiro para uma janela que contém um item de interface do usuário para atualizar.

*bDisableIfNoHndler*<br/>
[in] TRUE para desabilitar o item de interface do usuário, se nenhum manipulador é definido em um mapa de mensagem Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando um usuário de seu aplicativo clica em um item de interface do usuário, o item deve saber se ele deve ser exibido como habilitado ou desabilitado. O destino da mensagem de comando fornece essas informações com a implementação de um manipulador de comando ON_UPDATE_COMMAND_UI. Use esse método para ajudar a processar o comando. Para obter mais informações, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

##  <a name="opencolordialog"></a>  CMFCColorBar::OpenColorDialog

Abre uma caixa de diálogo de cor.

```
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,
    COLORREF& colorRes);
```

### <a name="parameters"></a>Parâmetros

*colorDefault*<br/>
[in] A cor que é selecionada por padrão quando abre a caixa de diálogo de cor.

*colorRes*<br/>
[out] A cor que o usuário selecionou.

### <a name="return-value"></a>Valor de retorno

TRUE se o usuário selecionou uma cor. FALSE se o usuário cancelou a caixa de diálogo de cor.

### <a name="remarks"></a>Comentários

##  <a name="rebuild"></a>  CMFCColorBar::Rebuild

Completamente redesenha o controle de barra de cores.

```
virtual void Rebuild();
```

##  <a name="selectpalette"></a>  CMFCColorBar::SelectPalette

Define a paleta lógica do contexto de dispositivo especificado para a paleta do botão pai do controle de barra de cores atual.

```
CPalette* SelectPalette(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDC*|[in] Ponteiro para o contexto de dispositivo do botão pai do controle de barra de cores atual.|

### <a name="return-value"></a>Valor de retorno

Ponteiro para a paleta que é substituído pela paleta do botão pai do controle de barra de cores atual.

##  <a name="setcolor"></a>  CMFCColorBar::SetColor

Define a cor que está selecionada no momento.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
[in] Um valor de cor RGB.

##  <a name="setcolorname"></a>  CMFCColorBar::SetColorName

Define um novo nome para uma cor especificada.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
[in] O valor RGB da cor.

*strName*<br/>
[in] O novo nome para a cor especificada.

### <a name="remarks"></a>Comentários

Esse método altera o nome da cor especificada em todos os `CMFCColorBar` objetos em seu aplicativo.

##  <a name="setcommandid"></a>  CMFCColorBar::SetCommandID

Define uma nova ID de comando para um controle de barra de cores.

```
void SetCommandID(UINT nCommandID);
```

### <a name="parameters"></a>Parâmetros

*nCommandID*<br/>
[in] Uma ID de comando.

### <a name="remarks"></a>Comentários

Chame esse método para modificar a ID de comando de um controle de barra de cores e notificar a janela pai do controle que a ID foi alterada.

##  <a name="setdocumentcolors"></a>  CMFCColorBar::SetDocumentColors

Define a lista de cores usadas no documento atual.

```
void SetDocumentColors(
    LPCTSTR lpszCaption,
    CList<COLORREF,COLORREF>& lstDocColors,
    BOOL bShowWhenDocked=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszCaption*<br/>
[in] Uma legenda que é exibida quando o controle de barra de cores não está encaixado.

*lstDocColors*<br/>
[in] Uma lista de cores que substitui as cores do documento atual.

*bShowWhenDocked*<br/>
[in] TRUE para mostrar as cores do documento quando o controle de barra de cores é encaixado; Caso contrário, FALSE. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

*Cores de documento* são as cores que são atualmente usadas em um documento. O framework mantém uma lista de cores de documento automaticamente, mas você pode usar esse método para modificar a lista.

##  <a name="sethorzmargin"></a>  CMFCColorBar::SetHorzMargin

Define a margem horizontal, que é o espaço entre a esquerda ou célula de cor direita e o limite da área de cliente.

```
void SetHorzMargin(int nHorzMargin);
```

### <a name="parameters"></a>Parâmetros

*nHorzMargin*<br/>
[in] A margem horizontal, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o [CMFCColorBar::CMFCColorBar](#cmfccolorbar) construtor define a margem horizontal como 4 pixels.

##  <a name="setproplist"></a>  CMFCColorBar::SetPropList

Define o `m_pWndPropList` protegido membro de dados para o ponteiro especificado para um controle de grade de propriedade.

```
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pWndList*|[in] Ponteiro para objeto de controle de grade de propriedade.|

##  <a name="setvertmargin"></a>  CMFCColorBar::SetVertMargin

Define a margem vertical, o que é o espaço entre a célula de cor superior ou inferior e os limites da área de cliente.

```
void SetVertMargin(int nVertMargin);
```

### <a name="parameters"></a>Parâmetros

*nVertMargin*<br/>
[in] A margem vertical, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o [CMFCColorBar::CMFCColorBar](#cmfccolorbar) construtor define a margem vertical com 4 pixels.

##  <a name="showcommandmessagestring"></a>  CMFCColorBar::ShowCommandMessageString

Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha de mensagem na barra de status.

```
virtual void ShowCommandMessageString(UINT uiCmdId);
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
[in] Uma ID de comando. (Esse parâmetro é ignorado).

### <a name="remarks"></a>Comentários

Esse método envia a mensagem WM_SETMESSAGESTRING para o proprietário do controle de barra de cores.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
