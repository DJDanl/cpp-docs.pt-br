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
ms.openlocfilehash: 25bfe3ef67fcca7708179d1a316af05b3ba49dda
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505426"
---
# <a name="cmfccolorbar-class"></a>Classe CMFCColorBar

A `CMFCColorBar` classe representa uma barra de controle de encaixe que pode selecionar cores em um documento ou aplicativo.

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
|[CMFCColorBar::ContextToSize](#contexttosize)|Calcula as margens vertical e horizontal que são necessárias para conter os botões no controle de barra de cores e, em seguida, ajusta o local desses botões.|
|[CMFCColorBar::CreateControl](#createcontrol)|Cria uma janela de controle de barra de cores, anexa- `CMFCColorBar` a ao objeto e redimensiona o controle para conter a paleta de cores especificada.|
|[CMFCColorBar:: criar](#create)|Cria uma janela de controle de barra de cores e a anexa `CMFCColorBar` ao objeto.|
|[CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton)|Mostra ou oculta o botão automático.|
|[CMFCColorBar::EnableOtherButton](#enableotherbutton)|Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.|
|[CMFCColorBar::GetColor](#getcolor)|Recupera a cor atualmente selecionada.|
|[CMFCColorBar::GetCommandID](#getcommandid)|Recupera a ID de comando do controle de barra de cores atual.|
|[CMFCColorBar::GetHighlightedColor](#gethighlightedcolor)|Recupera a cor que significa que um botão de cor tem o foco; ou seja, o botão está *quente*.|
|[CMFCColorBar::GetHorzMargin](#gethorzmargin)|Recupera a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.|
|[CMFCColorBar::GetVertMargin](#getvertmargin)|Recupera a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.|
|[CMFCColorBar::IsTearOff](#istearoff)|Indica se a barra de cores atual é encaixáveis.|
|[CMFCColorBar::SetColor](#setcolor)|Define a cor selecionada no momento.|
|[CMFCColorBar::SetColorName](#setcolorname)|Define um novo nome para uma cor especificada.|
|[CMFCColorBar::SetCommandID](#setcommandid)|Define uma nova ID de comando para um controle de barra de cores.|
|[CMFCColorBar::SetDocumentColors](#setdocumentcolors)|Define a lista de cores que são usadas no documento atual.|
|[CMFCColorBar::SetHorzMargin](#sethorzmargin)|Define a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.|
|[CMFCColorBar::SetVertMargin](#setvertmargin)|Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorBar::AdjustLocations](#adjustlocations)|Ajusta as posições dos botões de cor no controle de barra de cores.|
|[CMFCColorBar::AllowChangeTextLabels](#allowchangetextlabels)|Indica se o rótulo de texto dos botões de cor pode ser alterado.|
|[CMFCColorBar::AllowShowOnList](#allowshowonlist)|Indica se o objeto de controle de barra de cores pode aparecer em uma lista de barras de ferramentas durante o processo de personalização.|
|[CMFCColorBar::CalcSize](#calcsize)|Chamado pelo Framework como parte do processo de cálculo de layout.|
|[CMFCColorBar::CreatePalette](#createpalette)|Inicializa uma paleta com as cores em uma matriz de cores especificada.|
|[CMFCColorBar::GetColorGridSize](#getcolorgridsize)|Calcula o número de linhas e colunas na grade de um controle de barra de cores.|
|[CMFCColorBar::GetExtraHeight](#getextraheight)|Calcula a altura adicional que a barra de cores atual requer para exibir diversos elementos da interface do usuário, como o **outro** botão, as cores do documento e assim por diante.|
|[CMFCColorBar::InitColors](#initcolors)|Inicializa uma matriz de cores com as cores em uma paleta especificada ou na paleta padrão do sistema.|
|[CMFCColorBar::OnKey](#onkey)|Chamado pelo Framework quando um usuário pressiona um botão de teclado.|
|[CMFCColorBar::OnSendCommand](#onsendcommand)|Chamado pelo Framework para fechar uma hierarquia de controles pop-up.|
|[CMFCColorBar::OnUpdateCmdUI](#onupdatecmdui)|Chamado pelo Framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores antes de o item ser exibido.|
|[CMFCColorBar::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo cor.|
|[CMFCColorBar::Rebuild](#rebuild)|Redesenha completamente o controle de barra de cores.|
|[CMFCColorBar::SelectPalette](#selectpalette)|Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle da barra de cores atual.|
|[CMFCColorBar::SetPropList](#setproplist)|Define o `m_pWndPropList` membro de dados protegidos para o ponteiro especificado para um controle de grade de propriedade.|
|[CMFCColorBar::ShowCommandMessageString](#showcommandmessagestring)|Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha da mensagem na barra de status.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bInternal`|Um campo booliano que determina se os eventos do mouse são processados. Normalmente, os eventos do mouse são processados quando esse campo é TRUE e o modo de personalização é FALSE.|
|`m_bIsEnabled`|Um booliano que indica se um controle está habilitado.|
|`m_bIsTearOff`|Um booliano que indica se o controle de barra de cores dá suporte a encaixe.|
|`m_BoxSize`|Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o tamanho de uma célula em uma grade de barras de cores.|
|`m_bShowDocColorsWhenDocked`|Um booliano que indica se as cores do documento devem ser mostradas quando a barra de cores é encaixada. Para obter mais informações, consulte [CMFCColorBar:: SetDocumentColors](#setdocumentcolors).|
|`m_bStdColorDlg`|Um booliano que indica se a caixa de diálogo de cores do sistema padrão ou a caixa de diálogo [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) deve ser mostrada. Para obter mais informações, consulte [CMFCColorBar:: EnableOtherButton](#enableotherbutton).|
|`m_ColorAutomatic`|Um [COLORREF](/windows/win32/gdi/colorref) que armazena a cor automática atual. Para obter mais informações, consulte [CMFCColorBar:: EnableOtherButton](#enableotherbutton).|
|`m_ColorNames`|Um objeto de [mapa](../../mfc/reference/cmap-class.md) de objetos que associa um conjunto de cores RGB com seus nomes.|
|`m_colors`|Um [CArray](../../mfc/reference/carray-class.md) de valores de [COLORREF](/windows/win32/gdi/colorref) que contém as cores que são exibidas no controle de barra de cores.|
|`m_ColorSelected`|Um valor de [COLORREF](/windows/win32/gdi/colorref) que é a cor que o usuário selecionou atualmente do controle de barra de cores.|
|`m_lstDocColors`|Um [CList](../../mfc/reference/clist-class.md) de valores de [COLORREF](/windows/win32/gdi/colorref) que contém as cores usadas atualmente em um documento.|
|`m_nCommandID`|Um inteiro sem sinal que é a ID de comando de um botão de cor.|
|`m_nHorzMargin`|Um inteiro que é a margem horizontal entre os botões de cor em uma grade de cores.|
|`m_nHorzOffset`|Um inteiro que é o deslocamento horizontal para o centro do botão de cor. Esse valor será significativo se o botão exibir texto ou uma imagem além de uma cor.|
|`m_nNumColumns`|Um número inteiro que é o número de colunas em uma grade de cores de controle da barra de cores.|
|`m_nNumColumnsVert`|Um inteiro que é o número de colunas em uma grade de cores verticalmente orientada.|
|`m_nNumRowsHorz`|Um inteiro que é o número de colunas em uma grade de cores horizontalmente orientada.|
|`m_nRowHeight`|Um inteiro que é a altura de uma linha de botões de cor em uma grade de cores.|
|`m_nVertMargin`|Um inteiro que é a margem vertical entre os botões de cor em uma grade de cores.|
|`m_nVertOffset`|Um inteiro que é o deslocamento vertical para o centro do botão de cor. Esse valor será significativo se o botão exibir texto ou uma imagem além de uma cor.|
|`m_Palette`|Uma [CPalette](../../mfc/reference/cpalette-class.md) das cores que são usadas no controle da barra de cores.|
|`m_pParentBtn`|Um ponteiro para um objeto [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) que é o pai do botão atual. Esse valor será significativo se o botão de cor estiver em uma hierarquia de controles da barra de ferramentas ou estiver em um controle de grade de propriedade de cor.|
|`m_pParentRibbonBtn`|Um ponteiro para um objeto [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md) que está na faixa de faixas e é o botão pai do botão atual. Esse valor será significativo se o botão de cor estiver em uma hierarquia de controles da barra de ferramentas ou estiver em um controle de grade de propriedade de cor.|
|`m_pWndPropList`|Um ponteiro para um objeto [CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) .|
|`m_strAutoColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão **automático** . Para obter mais informações, consulte [CMFCColorBar:: EnableAutomaticButton](#enableautomaticbutton).|
|`m_strDocColors`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão cores do documento. Para obter mais informações, consulte [CMFCColorBar:: SetDocumentColors](#setdocumentcolors).|
|`m_strOtherColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no *outro* botão. Para obter mais informações, consulte [CMFCColorBar:: EnableOtherButton](#enableotherbutton).|

## <a name="remarks"></a>Comentários

Normalmente, você não cria um `CMFCColorBar` objeto diretamente. Em vez disso, a [Classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) (usada em menus e barras de ferramentas) ou na [classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) cria o `CMFCColorBar` objeto.

A `CMFCColorBar` classe fornece a seguinte funcionalidade:

- Ajusta automaticamente a lista de cores do documento.

- Salva e restaura seu estado, junto com o estado do documento.

- Gerencia o botão "automático".

- Usa o controle de [Classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) para selecionar uma cor personalizada.

- Dá suporte a um estado de "desmontagem" (se for criado usando a [Classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)).

Para incorporar a `CMFCColorBar` funcionalidade em seu aplicativo:

1. Crie um botão de menu regular e atribua a ele uma ID, por exemplo, ID_CHAR_COLOR.

1. Em sua classe de janela do quadro, substitua o método [CFrameWndEx:: OnShowPopupMenu](../../mfc/reference/cframewndex-class.md#onshowpopupmenu) e substitua o botão de menu regular por um objeto de [Classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) (chamando [CMFCToolBar:: ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)).

1. Defina todos os estilos e habilite ou desabilite os recursos `CMFCColorBar` do objeto durante a criação da [Classe CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) . O `CMFCColorMenuButton` objeto cria dinamicamente o `CMFCColorBar` objeto depois que a estrutura chama `CreatePopupMenu` o método.

Quando o usuário clica em um botão de controle de barra de cores, `ON_COMMAND` a estrutura usa a macro para notificar o pai do controle de barra de cores. Na macro, o parâmetro ID do comando é o valor que você atribuiu ao botão controle da barra de cores na etapa 1 (ID_CHAR_COLOR neste exemplo). Para obter mais informações, consulte a classe [CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md), classe [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md), classe [CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md), classe [CFrameWndEx](../../mfc/reference/cframewndex-class.md)e classes de [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma barra de cores usando vários métodos na `CMFCColorBar` classe. Os métodos definem as margens horizontal e vertical, habilitam o outro botão, cria uma janela de controle de barra de cores e define a cor atualmente selecionada. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

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

**Cabeçalho:** afxcolorbar. h

##  <a name="adjustlocations"></a>CMFCColorBar::AdjustLocations

Ajusta as posições dos botões de cor no controle de barra de cores.

```
virtual void AdjustLocations();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework durante o processamento de mensagens WM_SIZE.

##  <a name="allowchangetextlabels"></a>  CMFCColorBar::AllowChangeTextLabels

Indica se o rótulo de texto dos botões de cor pode ser alterado.

```
virtual BOOL AllowChangeTextLabels() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre FALSE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna FALSE, o que significa que os rótulos de texto não podem ser modificados. Substitua esse método para habilitar a modificação de rótulos de texto.

##  <a name="allowshowonlist"></a>CMFCColorBar::AllowShowOnList

Indica se o objeto de controle de barra de cores pode aparecer em uma lista de barras de ferramentas durante o processo de personalização.

```
virtual BOOL AllowShowOnList() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre verdadeiro.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna TRUE, o que significa que a estrutura pode exibir o controle de barra de cores durante o processo de personalização. Substitua esse método para implementar um comportamento diferente.

##  <a name="calcsize"></a>CMFCColorBar::CalcSize

Chamado pelo Framework como parte do processo de cálculo de layout.

```
virtual CSize CalcSize(BOOL bVertDock);
```

### <a name="parameters"></a>Parâmetros

*bVertDock*<br/>
no TRUE para especificar que o controle de barra de cores é encaixado verticalmente; FALSE para especificar que o controle de barra de cores é encaixado horizontalmente.

### <a name="return-value"></a>Valor de retorno

O tamanho da matriz de botões de cor em um controle de barra de cores.

##  <a name="cmfccolorbar"></a>CMFCColorBar::CMFCColorBar

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

*cores*<br/>
no Uma matriz de cores que a estrutura exibe no controle de barra de cores.

*color*<br/>
no A cor selecionada inicialmente.

*lpszAutoColor*<br/>
no O rótulo de texto do botão de cor *automático* (padrão) ou NULL.

O rótulo padrão do botão automático é **automático**.

*lpszOtherColor*<br/>
no O rótulo de texto do *outro* botão, que exibe mais opções de cor ou nulo.

É o rótulo padrão para o outro botão **mais cores...** .

*lpszDocColors*<br/>
no O rótulo de texto do botão cores do documento. A paleta cores do documento lista todas as cores que o documento usa atualmente.

*lstDocColors*<br/>
no Uma lista de cores que o documento usa atualmente.

*nColumns*<br/>
no O número de colunas que a matriz de cores tem.

*nRowsDockHorz*<br/>
no O número de linhas que a barra de cores tem quando é encaixada horizontalmente.

*nColDockVert*<br/>
no O número de colunas que a barra de cores tem quando é encaixada verticalmente.

*colorAutomatic*<br/>
no A cor padrão que a estrutura aplica quando você clica no botão automático.

*nCommandID*<br/>
no A ID do comando de controle da barra de cores.

*pParentBtn*<br/>
no Um ponteiro para um botão pai.

*src*<br/>
no Um objeto `CMFCColorBar` existente a ser copiado para o `CMFCColorBar` novo objeto.

*uiCommandID*<br/>
no A ID do comando.

##  <a name="contexttosize"></a>CMFCColorBar::ContextToSize

Calcula as margens vertical e horizontal que são necessárias para conter os botões no controle de barra de cores e ajusta o local desses botões.

```
void ContextToSize(
    BOOL bSquareButtons = TRUE,
    BOOL bCenterButtons = TRUE);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bSquareButtons*|no TRUE para especificar que a forma dos botões em um controle de barra de cores é quadrado; caso contrário, FALSE. O valor padrão é TRUE.|
|*bCenterButtons*|no TRUE para especificar que o conteúdo na face de um botão de controle de barra de cores está centralizado; caso contrário, FALSE. O valor padrão é TRUE.|

### <a name="remarks"></a>Comentários

##  <a name="create"></a>CMFCColorBar:: criar

Cria uma janela de controle de barra de cores e a anexa `CMFCColorBar` ao objeto.

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
no Ponteiro para a janela pai.

*dwStyle*<br/>
no Uma combinação de bits (ou) de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*nID*<br/>
no A ID do comando.

*pPalette*<br/>
no Ponteiro para uma paleta de cores. O padrão é NULL.

*nColumns*<br/>
no O número de colunas no controle da barra de cores. O padrão é 0.

*nRowsDockHorz*<br/>
no O número de linhas no controle da barra de cores quando ela é encaixada horizontalmente. O padrão é 0.

*nColDockVert*<br/>
no O número de colunas no controle da barra de cores quando ela é encaixada verticalmente. O padrão é 0.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para construir um `CMFCColorBar` objeto, chame o construtor de classe e, em seguida, esse método. O `Create` método cria o controle do Windows e Inicializa uma lista de cores.

##  <a name="createcontrol"></a>CMFCColorBar:: CreateControl

Cria uma janela de controle de barra de cores, anexa- `CMFCColorBar` a ao objeto e redimensiona a janela de controle para conter a paleta de cores especificada.

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
no Ponteiro para a janela pai. Não pode ser NULL.

*rect*<br/>
no Um retângulo delimitador que especifica onde desenhar o controle de barra de cores.

*nID*<br/>
no A ID de controle.

*nColumns*<br/>
no O número ideal de colunas no controle de barra de cores. Esse método modifica esse número para se ajustar à paleta de cores especificada. O padrão é-1, o que significa que esse parâmetro não é especificado.

*pPalette*<br/>
no Ponteiro para uma paleta de cores ou NULL. Se esse parâmetro for nulo, esse método calculará o tamanho do controle de barra de cores como se foram especificadas 20 cores. O padrão é NULL.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método tiver sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa os parâmetros *Rect*, *nColumns*e *pPalette* para calcular o número ou as linhas ou colunas apropriadas no controle de barra de cores e, em seguida, chama o método [CMFCColorBar:: Create](#create) .

##  <a name="createpalette"></a>CMFCColorBar:: CreatePalette

Inicializa uma paleta com as cores em uma matriz de cores especificada.

```
static BOOL CreatePalette(
    const CArray<COLORREF, COLORREF>& arColors,
    CPalette& palette);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*arColors*|no Uma matriz de cores.|
|*palette*|no Uma paleta de cores.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

##  <a name="enableautomaticbutton"></a>CMFCColorBar::EnableAutomaticButton

Mostra ou oculta o botão automático.

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no O rótulo de texto do botão de cor *automático* (padrão) ou NULL.

O rótulo padrão do botão automático é **automático**.

*colorAutomatic*<br/>
no A cor padrão que a estrutura aplica quando você clica no botão automático.

*bEnable*<br/>
no TRUE para habilitar o botão automático; FALSE para desabilitar o botão automático. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

O rótulo de texto do botão automático será excluído se o parâmetro *lpszLabel* for nulo ou se o parâmetro *bEnable* for false.

##  <a name="enableotherbutton"></a>CMFCColorBar::EnableOtherButton

Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no O rótulo de texto do *outro* botão, que exibe mais opções de cor ou nulo.

O rótulo padrão para este botão é **mais cores...** .

*bAltColorDlg*<br/>
no TRUE para exibir a caixa de diálogo [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) ; FALSE para exibir a caixa de diálogo [CColorDialog](../../mfc/reference/ccolordialog-class.md) padrão. O valor padrão é TRUE.

*bEnable*<br/>
no TRUE para habilitar o botão; FALSE para desabilitar o botão. O valor padrão é TRUE.

##  <a name="getcolor"></a>CMFCColorBar:: GetColor

Recupera a cor atualmente selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor selecionada no momento.

##  <a name="getcolorgridsize"></a>CMFCColorBar::GetColorGridSize

Calcula o número de linhas e colunas na grade de um controle de barra de cores.

```
CSize GetColorGridSize(BOOL bVertDock) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bVertDock*|no TRUE para executar o cálculo de um controle de barra de cores encaixado verticalmente; caso contrário, execute o cálculo para um controle encaixado horizontalmente.|

### <a name="return-value"></a>Valor de retorno

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) cujo `cx` componente contém o número de colunas e cujo `cy` componente contém o número de linhas.

##  <a name="getcommandid"></a>CMFCColorBar:: getcommandid

Recupera a ID de comando do controle de barra de cores atual.

```
UINT GetCommandID() const;
```

### <a name="return-value"></a>Valor de retorno

Uma ID de comando.

### <a name="remarks"></a>Comentários

Quando o usuário seleciona uma nova cor, a estrutura envia a ID de comando em uma mensagem WM_COMMAND para notificar o pai `CMFCColorBar` do objeto.

##  <a name="getextraheight"></a>CMFCColorBar::GetExtraHeight

Calcula a altura adicional que a barra de cores atual requer para exibir diversos elementos da interface do usuário, como **outras** cores de botão ou documento.

```
int GetExtraHeight(int nNumColumns) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nNumColumns*|no Se o controle de barra de cores contiver cores de documento, o número de colunas a serem exibidas na grade de cores do documento. Caso contrário, esse valor não será usado.|

### <a name="return-value"></a>Valor de retorno

A altura extra calculada necessária.

##  <a name="gethighlightedcolor"></a>  CMFCColorBar::GetHighlightedColor

Recupera a cor que significa que um botão de cor tem o foco; ou seja, o botão está *quente*.

```
COLORREF GetHighlightedColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="gethorzmargin"></a>  CMFCColorBar::GetHorzMargin

Recupera a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.

```
int GetHorzMargin();
```

### <a name="return-value"></a>Valor de retorno

A margem horizontal.

##  <a name="getvertmargin"></a>  CMFCColorBar::GetVertMargin

Recupera a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.

```
int GetVertMargin() const;
```

### <a name="return-value"></a>Valor de retorno

A margem vertical.

##  <a name="initcolors"></a>CMFCColorBar::InitColors

Inicializa uma matriz de cores com as cores em uma paleta especificada ou com a paleta padrão do sistema.

```
static int InitColors(
    CPalette* pPalette,
    CArray<COLORREF, COLORREF>& arColors);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pPalette*|no Um ponteiro para um objeto Palette ou NULL. Se esse parâmetro for nulo, esse método usará a paleta padrão do sistema operacional.|
|*arColors*|no Uma matriz de cores.|

### <a name="return-value"></a>Valor de retorno

O número de elementos na matriz de cores.

##  <a name="istearoff"></a>  CMFCColorBar::IsTearOff

Indica se a barra de cores atual é encaixáveis.

```
BOOL IsTearOff() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle da barra de cores atual for encaixáveis; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle de barra de cores for encaixáveis, ele poderá ser interrompido em uma barra de controle e encaixado em outro local.

##  <a name="onkey"></a>CMFCColorBar::OnKey

Chamado pelo Framework quando um usuário pressiona um botão de teclado.

```
virtual BOOL OnKey(UINT nChar);
```

### <a name="parameters"></a>Parâmetros

*nChar*<br/>
no O código de chave virtual para a chave que um usuário pressionou.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método processar a chave especificada; caso contrário, FALSE.

##  <a name="onsendcommand"></a>CMFCColorBar::OnSendCommand

Chamado pelo Framework para fechar uma hierarquia de controles pop-up.

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pButton*|no Ponteiro para um controle que reside em uma barra de ferramentas.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

##  <a name="onupdatecmdui"></a>  CMFCColorBar::OnUpdateCmdUI

Chamado pelo Framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores antes de o item ser exibido.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

*pTarget*<br/>
no Ponteiro para uma janela que contém um item de interface de usuário a ser atualizado.

*bDisableIfNoHndler*<br/>
no TRUE para desabilitar o item de interface do usuário se nenhum manipulador for definido em um mapa de mensagens; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando um usuário do seu aplicativo clica em um item de interface do usuário, o item deve saber se ele deve ser exibido como habilitado ou desabilitado. O destino da mensagem de comando fornece essas informações implementando um manipulador de comando ON_UPDATE_COMMAND_UI. Use esse método para ajudar a processar o comando. Para obter mais informações, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

##  <a name="opencolordialog"></a>CMFCColorBar::OpenColorDialog

Abre uma caixa de diálogo cor.

```
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,
    COLORREF& colorRes);
```

### <a name="parameters"></a>Parâmetros

*colorDefault*<br/>
no A cor que é selecionada por padrão quando a caixa de diálogo cor é aberta.

*colorRes*<br/>
fora A cor que um usuário selecionou.

### <a name="return-value"></a>Valor de retorno

TRUE se o usuário selecionou uma cor; FALSE se o usuário cancelou a caixa de diálogo cor.

### <a name="remarks"></a>Comentários

##  <a name="rebuild"></a>CMFCColorBar:: Rebuild

Redesenha completamente o controle de barra de cores.

```
virtual void Rebuild();
```

##  <a name="selectpalette"></a>CMFCColorBar::SelectPalette

Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle da barra de cores atual.

```
CPalette* SelectPalette(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDC*|no Ponteiro para o contexto do dispositivo do botão pai do controle da barra de cores atual.|

### <a name="return-value"></a>Valor de retorno

Ponteiro para a paleta que é substituída pela paleta do botão pai do controle da barra de cores atual.

##  <a name="setcolor"></a>CMFCColorBar:: setColor

Define a cor selecionada no momento.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no Um valor de cor RGB.

##  <a name="setcolorname"></a>CMFCColorBar:: SetColorName

Define um novo nome para uma cor especificada.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no O valor RGB de uma cor.

*strName*<br/>
no O novo nome da cor especificada.

### <a name="remarks"></a>Comentários

Esse método altera o nome da cor especificada em todos os `CMFCColorBar` objetos em seu aplicativo.

##  <a name="setcommandid"></a>CMFCColorBar:: setcommandid

Define uma nova ID de comando para um controle de barra de cores.

```
void SetCommandID(UINT nCommandID);
```

### <a name="parameters"></a>Parâmetros

*nCommandID*<br/>
no Uma ID de comando.

### <a name="remarks"></a>Comentários

Chame esse método para modificar a ID de comando de um controle de barra de cores e para notificar a janela pai do controle de que a ID foi alterada.

##  <a name="setdocumentcolors"></a>CMFCColorBar::SetDocumentColors

Define a lista de cores que são usadas no documento atual.

```
void SetDocumentColors(
    LPCTSTR lpszCaption,
    CList<COLORREF,COLORREF>& lstDocColors,
    BOOL bShowWhenDocked=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszCaption*<br/>
no Uma legenda que é exibida quando o controle da barra de cores não está encaixado.

*lstDocColors*<br/>
no Uma lista de cores que substitui as cores atuais do documento.

*bShowWhenDocked*<br/>
no TRUE para mostrar as cores do documento quando o controle da barra de cores estiver encaixado; caso contrário, FALSE. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

As *cores do documento* são as cores usadas atualmente em um documento. A estrutura mantém automaticamente uma lista de cores do documento, mas você pode usar esse método para modificar a lista.

##  <a name="sethorzmargin"></a>  CMFCColorBar::SetHorzMargin

Define a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.

```
void SetHorzMargin(int nHorzMargin);
```

### <a name="parameters"></a>Parâmetros

*nHorzMargin*<br/>
no A margem horizontal, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o construtor [CMFCColorBar:: CMFCColorBar](#cmfccolorbar) define a margem horizontal como 4 pixels.

##  <a name="setproplist"></a>CMFCColorBar:: setproplist

Define o `m_pWndPropList` membro de dados protegidos para o ponteiro especificado para um controle de grade de propriedade.

```
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pWndList*|no Ponteiro para objeto de controle de grade de propriedade.|

##  <a name="setvertmargin"></a>  CMFCColorBar::SetVertMargin

Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.

```
void SetVertMargin(int nVertMargin);
```

### <a name="parameters"></a>Parâmetros

*nVertMargin*<br/>
no A margem vertical, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o construtor [CMFCColorBar:: CMFCColorBar](#cmfccolorbar) define a margem vertical como 4 pixels.

##  <a name="showcommandmessagestring"></a>  CMFCColorBar::ShowCommandMessageString

Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha da mensagem na barra de status.

```
virtual void ShowCommandMessageString(UINT uiCmdId);
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
no Uma ID de comando. (Esse parâmetro é ignorado.)

### <a name="remarks"></a>Comentários

Esse método envia a mensagem WM_SETMESSAGESTRING para o proprietário do controle de barra de cores.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
