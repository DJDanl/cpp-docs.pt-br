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
ms.openlocfilehash: 7b63fb66b800bd758c7f4c89c553e857ad9bbfbc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367764"
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
|[CMFCColorbar::ContextToSize](#contexttosize)|Calcula as margens verticais e horizontais necessárias para conter os botões no controle da barra de cores e, em seguida, ajusta a localização desses botões.|
|[CMFCColorbar::Criarcontrole](#createcontrol)|Cria uma janela de controle de `CMFCColorBar` barra de cores, anexa-a ao objeto e redimensiona o controle para conter a paleta de cores especificada.|
|[CMFCColorbar::Criar](#create)|Cria uma janela de controle de `CMFCColorBar` barra de cor e a anexa ao objeto.|
|[CMFCColorbar::Ativarbotão automático](#enableautomaticbutton)|Mostra ou esconde o botão automático.|
|[CMFCColorbar::Ativaroutro botão](#enableotherbutton)|Ativa ou desativa a exibição de uma caixa de diálogo que permite ao usuário selecionar mais cores.|
|[CMFCColorbar::GetColor](#getcolor)|Recupera a cor selecionada no momento.|
|[CMFCColorbar::getCommandID](#getcommandid)|Recupera o ID de comando do controle atual da barra de cores.|
|[CMFCColorbar::gethighlightedColor](#gethighlightedcolor)|Recupera a cor que significa que um botão de cor tem o foco; ou seja, o botão está *quente.*|
|[CMFCColorBar::GetHorzMargin](#gethorzmargin)|Recupera a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.|
|[CMFCColorBar::GetVertMargin](#getvertmargin)|Recupera a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.|
|[CMFCColorbar::Istearoff](#istearoff)|Indica se a barra de cores atual é ancorável.|
|[CMFCColorbar::setColor](#setcolor)|Define a cor selecionada no momento.|
|[CMFCColorbar::setNome de cores](#setcolorname)|Define um novo nome para uma cor especificada.|
|[CMFCColorbar::setCommandID](#setcommandid)|Define um novo ID de comando para um controle de barra de cores.|
|[CMFCColorbar::setDocumentCores](#setdocumentcolors)|Define a lista de cores usadas no documento atual.|
|[CMFCColorBar::SetHorzMargin](#sethorzmargin)|Define a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.|
|[CMFCColorBar::SetVertMargin](#setvertmargin)|Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorBar::Ajustar locais](#adjustlocations)|Ajusta as posições dos botões de cor no controle da barra de cores.|
|[CMFCColorBar::Permitiralteraralterarrótulos de texto](#allowchangetextlabels)|Indica se a etiqueta de texto dos botões de cor pode mudar.|
|[CMFCColorbar::AllowshowonList](#allowshowonlist)|Indica se o objeto de controle da barra de cor pode aparecer em uma lista de barras de ferramentas durante o processo de personalização.|
|[CMFCColorBar::CalcSize](#calcsize)|Chamado pela estrutura como parte do processo de cálculo do layout.|
|[CMFCColorBar::Criarpaleta](#createpalette)|Inicializa uma paleta com as cores em uma matriz especificada de cores.|
|[CMFCColorbar::GetColorGridSize](#getcolorgridsize)|Calcula o número de linhas e colunas na grade de um controle de barra de cores.|
|[CMFCColorbar::GetExtraHeight](#getextraheight)|Calcula a altura adicional que a barra de cores atual requer para exibir elementos diversos da interface do usuário, como **o** outro botão, cores do documento e assim por diante.|
|[CMFCColorBar::InitColors](#initcolors)|Inicializa uma matriz de cores com as cores em uma paleta especificada ou na paleta padrão do sistema.|
|[CMFCColorbar::Onkey](#onkey)|Chamado pela estrutura quando um usuário pressiona um botão de teclado.|
|[CMFCColorbar::OnSendCommand](#onsendcommand)|Chamado pela estrutura para fechar uma hierarquia de controles popup.|
|[CMFCColorBar::OnUpdateCmdUI](#onupdatecmdui)|Chamado pela estrutura para ativar ou desativar um item de interface de usuário de um controle de barra de cores antes que o item seja exibido.|
|[CMFCColorbar::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de cores.|
|[CMFCColorBar::Reconstruir](#rebuild)|Desenha completamente o controle da barra de cores.|
|[CMFCColorBar::SelectPaleta](#selectpalette)|Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle atual da barra de cores.|
|[CMFCColorbar::setproplist](#setproplist)|Define `m_pWndPropList` o membro de dados protegido para o ponteiro especificado para um controle de grade de propriedade.|
|[CMFCColorbar::ShowCommandMessageString](#showcommandmessagestring)|Solicita a janela de quadro que possui o controle da barra de cores para atualizar a linha de mensagens na barra de status.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bInternal`|Um campo booleano que determina se os eventos do rato são processados. Normalmente, os eventos do mouse são processados quando este campo é TRUE e o modo de personalização é FALSO.|
|`m_bIsEnabled`|Um booleano que indica se um controle está ativado.|
|`m_bIsTearOff`|Um booleano que indica se o controle da barra de cor suporta a copagem.|
|`m_BoxSize`|Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o tamanho de uma célula em uma grade de barras de cor.|
|`m_bShowDocColorsWhenDocked`|Um booleano que indica se deve mostrar as cores do documento quando a barra de cor estiver encaixada. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|
|`m_bStdColorDlg`|Um booleano que indica se deve mostrar a caixa de diálogo de cor padrão do sistema ou a caixa de diálogo [CMFCColorDialog.](../../mfc/reference/cmfccolordialog-class.md) Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|
|`m_ColorAutomatic`|Um [COLORREF](/windows/win32/gdi/colorref) que armazena a cor automática atual. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|
|`m_ColorNames`|Um objeto [CMap](../../mfc/reference/cmap-class.md) que associa um conjunto de cores RGB com seus nomes.|
|`m_colors`|Um [CArray](../../mfc/reference/carray-class.md) de valores [COLORREF](/windows/win32/gdi/colorref) que contém as cores exibidas no controle da barra de cores.|
|`m_ColorSelected`|Um valor [COLORREF](/windows/win32/gdi/colorref) que é a cor que o usuário selecionou atualmente a partir do controle da barra de cores.|
|`m_lstDocColors`|Uma [Lista C](../../mfc/reference/clist-class.md) de valores [COLORREF](/windows/win32/gdi/colorref) que contém as cores que são usadas atualmente em um documento.|
|`m_nCommandID`|Um inteiro não assinado que é o ID de comando de um botão de cor.|
|`m_nHorzMargin`|Um inteiro que é a margem horizontal entre os botões de cor em uma grade de cores.|
|`m_nHorzOffset`|Um inteiro que é o deslocamento horizontal para o centro do botão de cor. Esse valor é significativo se o botão exibir texto ou uma imagem, além de uma cor.|
|`m_nNumColumns`|Um inteiro que é o número de colunas em uma grade de controle de barras de cores de cores.|
|`m_nNumColumnsVert`|Um inteiro que é o número de colunas em uma grade de cores orientada verticalmente.|
|`m_nNumRowsHorz`|Um inteiro que é o número de colunas em uma grade de cores horizontalmente orientada.|
|`m_nRowHeight`|Um inteiro que é a altura de uma linha de botões de cor em uma grade de cores.|
|`m_nVertMargin`|Um inteiro que é a margem vertical entre os botões de cor em uma grade de cores.|
|`m_nVertOffset`|Um inteiro que é o deslocamento vertical para o centro do botão de cor. Esse valor é significativo se o botão exibir texto ou uma imagem, além de uma cor.|
|`m_Palette`|Uma [Paleta de](../../mfc/reference/cpalette-class.md) cores que são usadas no controle da barra de cores.|
|`m_pParentBtn`|Um ponteiro para um objeto [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) que é o pai do botão atual. Esse valor é significativo se o botão de cor estiver em uma hierarquia de controles de barra de ferramentas ou estiver em um controle de grade de propriedade de cor.|
|`m_pParentRibbonBtn`|Um ponteiro para um objeto [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md) que está na fita e é o botão pai do botão atual. Esse valor é significativo se o botão de cor estiver em uma hierarquia de controles de barra de ferramentas ou estiver em um controle de grade de propriedade de cor.|
|`m_pWndPropList`|Um ponteiro para um objeto [CMFCPropertyGridCtrl.](../../mfc/reference/cmfcpropertygridctrl-class.md)|
|`m_strAutoColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto exibido no botão **Automático.** Para obter mais informações, consulte [CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton).|
|`m_strDocColors`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto exibido no botão cores do documento. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|
|`m_strOtherColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto exibido no *outro* botão. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|

## <a name="remarks"></a>Comentários

Normalmente, você não `CMFCColorBar` cria um objeto diretamente. Em vez disso, a [CLASSE CMFCColorMenuButton (usada](../../mfc/reference/cmfccolormenubutton-class.md) em menus e `CMFCColorBar` barras de ferramentas) ou a Classe [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) cria o objeto.

A `CMFCColorBar` classe fornece as seguintes funcionalidades:

- Ajusta automaticamente a lista de cores do documento.

- Salva e restaura seu estado, juntamente com o estado do documento.

- Gerencia o botão "automático".

- Usa o controle [CMFCColorPickerCtrl Class](../../mfc/reference/cmfccolorpickerctrl-class.md) para selecionar uma cor personalizada.

- Suporta um estado "tear-off" (se for criado usando o [CMFCColorMenuButton Class](../../mfc/reference/cmfccolormenubutton-class.md)).

Para incorporar `CMFCColorBar` a funcionalidade em seu aplicativo:

1. Crie um botão de menu regular e atribua-o a um ID, por exemplo, ID_CHAR_COLOR.

1. Na classe de janela do quadro, substitua o método [CFrameWndEx::OnShowPopupMenu](../../mfc/reference/cframewndex-class.md#onshowpopupmenu) e substitua o botão de menu regular por um objeto [CMFCColorMenuButton Class](../../mfc/reference/cmfccolormenubutton-class.md) (chamando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)).

1. Defina todos os estilos e habilite ou desative os recursos do objeto durante a `CMFCColorBar` criação do [CMFCColorMenuButton Class.](../../mfc/reference/cmfccolormenubutton-class.md) O `CMFCColorMenuButton` objeto cria `CMFCColorBar` dinamicamente o `CreatePopupMenu` objeto após a estrutura chamar o método.

Quando o usuário clica em um botão `ON_COMMAND` de controle de barra de cor, a estrutura usa a macro para notificar o pai do controle da barra de cores. Na macro, o parâmetro ID de comando é o valor atribuído ao botão de controle da barra de cores na etapa 1 (ID_CHAR_COLOR neste exemplo). Para obter mais informações, consulte as classes [CMFCColorMenuButton Class,](../../mfc/reference/cmfccolormenubutton-class.md) [CMFCColorButton Class,](../../mfc/reference/cmfccolorbutton-class.md) [CMFCColorPickerCtrl Class,](../../mfc/reference/cmfccolorpickerctrl-class.md) [CFrameWndEx Class](../../mfc/reference/cframewndex-class.md)e [CMFCToolBar Class.](../../mfc/reference/cmfctoolbar-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma barra `CMFCColorBar` de cor usando vários métodos na classe. Os métodos definem as margens horizontais e verticais, habilitam o outro botão, criam uma janela de controle de barra de cor e definem a cor selecionada no momento. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#1](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#2](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[Cmfctoolbar](../../mfc/reference/cmfctoolbar-class.md)

[Cmfcpopupmenubar](../../mfc/reference/cmfcpopupmenubar-class.md)

[CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorbar.h

## <a name="cmfccolorbaradjustlocations"></a><a name="adjustlocations"></a>CMFCColorBar::Ajustar locais

Ajusta as posições dos botões de cor no controle da barra de cores.

```
virtual void AdjustLocations();
```

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura durante WM_SIZE processamento de mensagens.

## <a name="cmfccolorbarallowchangetextlabels"></a><a name="allowchangetextlabels"></a>CMFCColorBar::Permitiralteraralterarrótulos de texto

Indica se a etiqueta de texto dos botões de cor pode mudar.

```
virtual BOOL AllowChangeTextLabels() const;
```

### <a name="return-value"></a>Valor retornado

Sempre FALSE.

### <a name="remarks"></a>Comentários

Por padrão, este método sempre retorna FALSE, o que significa que os rótulos de texto não podem ser modificados. Anular este método para permitir a modificação de rótulos de texto.

## <a name="cmfccolorbarallowshowonlist"></a><a name="allowshowonlist"></a>CMFCColorbar::AllowshowonList

Indica se o objeto de controle da barra de cor pode aparecer em uma lista de barras de ferramentas durante o processo de personalização.

```
virtual BOOL AllowShowOnList() const;
```

### <a name="return-value"></a>Valor retornado

Sempre TRUE.

### <a name="remarks"></a>Comentários

Por padrão, este método sempre retorna TRUE, o que significa que a estrutura pode exibir o controle da barra de cores durante o processo de personalização. Substituir este método para implementar um comportamento diferente.

## <a name="cmfccolorbarcalcsize"></a><a name="calcsize"></a>CMFCColorBar::CalcSize

Chamado pela estrutura como parte do processo de cálculo do layout.

```
virtual CSize CalcSize(BOOL bVertDock);
```

### <a name="parameters"></a>Parâmetros

*bVertDock*<br/>
[em] TRUE para especificar que o controle da barra de cores está encaixado verticalmente; FALSO para especificar que o controle da barra de cor está ancorado horizontalmente.

### <a name="return-value"></a>Valor retornado

O tamanho da matriz de botões de cor em um controle de barra de cor.

## <a name="cmfccolorbarcmfccolorbar"></a><a name="cmfccolorbar"></a>CMFCColorBar::CMFCColorBar

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
[em] Uma matriz de cores que a estrutura exibe no controle da barra de cores.

*cor*<br/>
[em] A cor inicialmente selecionada.

*lpszAutoColor*<br/>
[em] A etiqueta de texto do botão de cor *automático* (padrão) ou NULL.

A etiqueta padrão para o botão automático é **Automatic**.

*lpszOtherColor*<br/>
[em] O rótulo de texto do *outro* botão, que exibe mais opções de cores, ou NULL.

A etiqueta padrão para o outro botão é **Mais Cores...**.

*lpszDocCores*<br/>
[em] O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que o documento usa atualmente.

*LstDocCores*<br/>
[em] Uma lista de cores que o documento usa atualmente.

*nColumns*<br/>
[em] O número de colunas que a matriz de cores tem.

*nRowsDockHorz*<br/>
[em] O número de linhas que a barra de cores tem quando está ancorada horizontalmente.

*nColDockVert*<br/>
[em] O número de colunas que a barra de cores tem quando está encaixada verticalmente.

*corAutomático*<br/>
[em] A cor padrão que a estrutura se aplica quando você clica no botão automático.

*nCommandID*<br/>
[em] O iD do comando de controle da barra de cores.

*pParentBtn*<br/>
[em] Um ponteiro para um botão pai.

*src*<br/>
[em] Um objeto `CMFCColorBar` existente a ser copiado para o novo `CMFCColorBar` objeto.

*uiCommandID*<br/>
[em] O id de comando.

## <a name="cmfccolorbarcontexttosize"></a><a name="contexttosize"></a>CMFCColorbar::ContextToSize

Calcula as margens verticais e horizontais necessárias para conter os botões no controle da barra de cores e ajusta a localização desses botões.

```
void ContextToSize(
    BOOL bSquareButtons = TRUE,
    BOOL bCenterButtons = TRUE);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bSquareButtons*|[em] TRUE para especificar que a forma dos botões em um controle de barra de cor são quadrados; caso contrário, FALSE. O valor padrão é TRUE.|
|*bCenterButtons*|[em] TRUE para especificar que o conteúdo na face de um botão de controle da barra de cores está centrado; caso contrário, FALSE. O valor padrão é TRUE.|

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbarcreate"></a><a name="create"></a>CMFCColorbar::Criar

Cria uma janela de controle de `CMFCColorBar` barra de cor e a anexa ao objeto.

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

*Pparentwnd*<br/>
[em] Ponteiro para a janela dos pais.

*Dwstyle*<br/>
[em] Uma combinação bitwise (OR) de estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*nID*<br/>
[em] O id de comando.

*Ppalette*<br/>
[em] Ponteiro para uma paleta de cores. O padrão é NULO.

*nColumns*<br/>
[em] O número de colunas no controle da barra de cores. O padrão é 0.

*nRowsDockHorz*<br/>
[em] O número de linhas no controle da barra de cores quando está ancorado horizontalmente. O padrão é 0.

*nColDockVert*<br/>
[em] O número de colunas no controle da barra de cores quando está ancorado verticalmente. O padrão é 0.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para construir `CMFCColorBar` um objeto, chame o construtor de classe, em seguida, este método. O `Create` método cria o controle do Windows e inicializa uma lista de cores.

## <a name="cmfccolorbarcreatecontrol"></a><a name="createcontrol"></a>CMFCColorbar::Criarcontrole

Cria uma janela de controle de `CMFCColorBar` barra de cores, anexa-a ao objeto e redimensiona a janela de controle para conter a paleta de cores especificada.

```
virtual BOOL CreateControl(
    CWnd* pParentWnd,
    const CRect& rect,
    UINT nID,
    int nColumns=-1,
    CPalette* pPalette=NULL);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Ponteiro para a janela dos pais. Não pode ser NULL.

*Rect*<br/>
[em] Um retângulo delimitador que especifica onde desenhar o controle da barra de cores.

*nID*<br/>
[em] A id de controle.

*nColumns*<br/>
[em] O número ideal de colunas no controle da barra de cores. Este método modifica esse número para se encaixar na paleta de cores especificada. O padrão é -1, o que significa que este parâmetro não está especificado.

*Ppalette*<br/>
[em] Ponteiro para uma paleta de cores, ou NULL. Se este parâmetro for NULO, este método calculará o tamanho do controle da barra de cor como se 20 cores fossem especificadas. O padrão é NULO.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método usa os parâmetros *rect,* *nColumns*e *pPalette* para calcular o número ou linhas e colunas apropriadas no controle da barra de cores e, em seguida, chama o método [CMFCColorBar::Create.](#create)

## <a name="cmfccolorbarcreatepalette"></a><a name="createpalette"></a>CMFCColorBar::Criarpaleta

Inicializa uma paleta com as cores em uma matriz especificada de cores.

```
static BOOL CreatePalette(
    const CArray<COLORREF, COLORREF>& arColors,
    CPalette& palette);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*arCores*|[em] Uma série de cores.|
|*paleta*|[em] Uma paleta de cores.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="cmfccolorbarenableautomaticbutton"></a><a name="enableautomaticbutton"></a>CMFCColorbar::Ativarbotão automático

Mostra ou esconde o botão automático.

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] A etiqueta de texto do botão de cor *automático* (padrão) ou NULL.

A etiqueta padrão para o botão automático é **Automatic**.

*corAutomático*<br/>
[em] A cor padrão que a estrutura se aplica quando você clica no botão automático.

*Benable*<br/>
[em] TRUE para ativar o botão automático; FALSO para desativar o botão automático. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

O rótulo de texto do botão automático é excluído se o parâmetro *lpszLabel* for NULL ou o parâmetro *bEnable* for FALSE.

## <a name="cmfccolorbarenableotherbutton"></a><a name="enableotherbutton"></a>CMFCColorbar::Ativaroutro botão

Ativa ou desativa a exibição de uma caixa de diálogo que permite ao usuário selecionar mais cores.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O rótulo de texto do *outro* botão, que exibe mais opções de cores, ou NULL.

A etiqueta padrão para este botão é **Mais Cores...**.

*bAltColorDlg*<br/>
[em] FIEL para exibir a caixa de diálogo [CMFCColorDialog;](../../mfc/reference/cmfccolordialog-class.md) FALSE para exibir a caixa de diálogo [CColorDialog](../../mfc/reference/ccolordialog-class.md) padrão. O valor padrão é TRUE.

*Benable*<br/>
[em] TRUE para ativar o botão; FALSO para desativar o botão. O valor padrão é TRUE.

## <a name="cmfccolorbargetcolor"></a><a name="getcolor"></a>CMFCColorbar::GetColor

Recupera a cor selecionada no momento.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor atualmente selecionada.

## <a name="cmfccolorbargetcolorgridsize"></a><a name="getcolorgridsize"></a>CMFCColorbar::GetColorGridSize

Calcula o número de linhas e colunas na grade de um controle de barra de cores.

```
CSize GetColorGridSize(BOOL bVertDock) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bVertDock*|[em] TRUE para realizar o cálculo para um controle de barra de cor encaixado verticalmente; caso contrário, realize o cálculo para um controle horizontalmente encaixado.|

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) cujo `cx` componente contém o `cy` número de colunas e cujo componente contém o número de linhas.

## <a name="cmfccolorbargetcommandid"></a><a name="getcommandid"></a>CMFCColorbar::getCommandID

Recupera o ID de comando do controle atual da barra de cores.

```
UINT GetCommandID() const;
```

### <a name="return-value"></a>Valor retornado

Uma id de comando.

### <a name="remarks"></a>Comentários

Quando o usuário seleciona uma nova cor, a estrutura envia o ID `CMFCColorBar` de comando em uma mensagem WM_COMMAND para notificar o pai do objeto.

## <a name="cmfccolorbargetextraheight"></a><a name="getextraheight"></a>CMFCColorbar::GetExtraHeight

Calcula a altura adicional que a barra de cores atual requer para exibir elementos diversos da interface do usuário, como o **outro** botão ou cores do documento.

```
int GetExtraHeight(int nNumColumns) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nNumColumns*|[em] Se o controle da barra de cores contiver as cores do documento, o número de colunas a serem exibidas na grade de cores do documento. Caso contrário, este valor não é usado.|

### <a name="return-value"></a>Valor retornado

A altura extra calculada que é necessária.

## <a name="cmfccolorbargethighlightedcolor"></a><a name="gethighlightedcolor"></a>CMFCColorbar::gethighlightedColor

Recupera a cor que significa que um botão de cor tem o foco; ou seja, o botão está *quente.*

```
COLORREF GetHighlightedColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbargethorzmargin"></a><a name="gethorzmargin"></a>CMFCColorBar::GetHorzMargin

Recupera a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.

```
int GetHorzMargin();
```

### <a name="return-value"></a>Valor retornado

A margem horizontal.

## <a name="cmfccolorbargetvertmargin"></a><a name="getvertmargin"></a>CMFCColorBar::GetVertMargin

Recupera a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.

```
int GetVertMargin() const;
```

### <a name="return-value"></a>Valor retornado

A margem vertical.

## <a name="cmfccolorbarinitcolors"></a><a name="initcolors"></a>CMFCColorBar::InitColors

Inicializa uma matriz de cores com as cores em uma paleta especificada ou com a paleta padrão do sistema.

```
static int InitColors(
    CPalette* pPalette,
    CArray<COLORREF, COLORREF>& arColors);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ppalette*|[em] Um ponteiro para um objeto de paleta, ou NULL. Se este parâmetro for NULO, este método usará a paleta padrão do sistema operacional.|
|*arCores*|[em] Uma série de cores.|

### <a name="return-value"></a>Valor retornado

O número de elementos na matriz de cores.

## <a name="cmfccolorbaristearoff"></a><a name="istearoff"></a>CMFCColorbar::Istearoff

Indica se a barra de cores atual é ancorável.

```
BOOL IsTearOff() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controle da barra de cor atual estiver ancorado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle da barra de cores for ancorável, ele pode ser arrancado de uma barra de controle e ancorado em outro local.

## <a name="cmfccolorbaronkey"></a><a name="onkey"></a>CMFCColorbar::Onkey

Chamado pela estrutura quando um usuário pressiona um botão de teclado.

```
virtual BOOL OnKey(UINT nChar);
```

### <a name="parameters"></a>Parâmetros

*Nchar*<br/>
[em] O código de chave virtual para a chave que um usuário pressionou.

### <a name="return-value"></a>Valor retornado

TRUE se este método processa a chave especificada; caso contrário, FALSE.

## <a name="cmfccolorbaronsendcommand"></a><a name="onsendcommand"></a>CMFCColorbar::OnSendCommand

Chamado pela estrutura para fechar uma hierarquia de controles pop-up.

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Pbutton*|[em] Ponteiro para um controle que reside em uma barra de ferramentas.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="cmfccolorbaronupdatecmdui"></a><a name="onupdatecmdui"></a>CMFCColorBar::OnUpdateCmdUI

Chamado pela estrutura para ativar ou desativar um item de interface de usuário de um controle de barra de cores antes que o item seja exibido.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

*Ptarget*<br/>
[em] Ponteiro para uma janela que contém um item de interface de usuário para atualizar.

*bDisableIfNoHndler*<br/>
[em] TRUE desabilitar o item de interface do usuário se nenhum manipulador for definido em um mapa de mensagem; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando um usuário do seu aplicativo clica em um item de interface de usuário, o item deve saber se ele deve ser exibido como ativado ou desativado. O alvo da mensagem de comando fornece essas informações implementando um manipulador de comando ON_UPDATE_COMMAND_UI. Use este método para ajudar a processar o comando. Para obter mais informações, consulte [Classe CCmdUI](../../mfc/reference/ccmdui-class.md).

## <a name="cmfccolorbaropencolordialog"></a><a name="opencolordialog"></a>CMFCColorbar::OpenColorDialog

Abre uma caixa de diálogo de cores.

```
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,
    COLORREF& colorRes);
```

### <a name="parameters"></a>Parâmetros

*corPadrão*<br/>
[em] A cor selecionada por padrão quando a caixa de diálogo de cor é aberta.

*coresRes*<br/>
[fora] A cor que um usuário selecionou.

### <a name="return-value"></a>Valor retornado

TRUE se o usuário selecionou uma cor; FALSO se o usuário cancelou a caixa de diálogo de cor.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbarrebuild"></a><a name="rebuild"></a>CMFCColorBar::Reconstruir

Desenha completamente o controle da barra de cores.

```
virtual void Rebuild();
```

## <a name="cmfccolorbarselectpalette"></a><a name="selectpalette"></a>CMFCColorBar::SelectPaleta

Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle atual da barra de cores.

```
CPalette* SelectPalette(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDC*|[em] Ponteiro para o contexto do dispositivo do botão pai do controle da barra de cores atual.|

### <a name="return-value"></a>Valor retornado

Ponteiro para a paleta que é substituído pela paleta do botão pai do controle da barra de cores atual.

## <a name="cmfccolorbarsetcolor"></a><a name="setcolor"></a>CMFCColorbar::setColor

Define a cor selecionada no momento.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Um valor de cor RGB.

## <a name="cmfccolorbarsetcolorname"></a><a name="setcolorname"></a>CMFCColorbar::setNome de cores

Define um novo nome para uma cor especificada.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] O valor RGB de uma cor.

*strName*<br/>
[em] O novo nome para a cor especificada.

### <a name="remarks"></a>Comentários

Este método altera o nome da `CMFCColorBar` cor especificada em todos os objetos da sua aplicação.

## <a name="cmfccolorbarsetcommandid"></a><a name="setcommandid"></a>CMFCColorbar::setCommandID

Define um novo ID de comando para um controle de barra de cores.

```
void SetCommandID(UINT nCommandID);
```

### <a name="parameters"></a>Parâmetros

*nCommandID*<br/>
[em] Uma id de comando.

### <a name="remarks"></a>Comentários

Chame este método para modificar o ID de comando de um controle de barra de cores e notificar a janela pai do controle que o ID alterou.

## <a name="cmfccolorbarsetdocumentcolors"></a><a name="setdocumentcolors"></a>CMFCColorbar::setDocumentCores

Define a lista de cores usadas no documento atual.

```
void SetDocumentColors(
    LPCTSTR lpszCaption,
    CList<COLORREF,COLORREF>& lstDocColors,
    BOOL bShowWhenDocked=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszCaption*<br/>
[em] Uma legenda que é exibida quando o controle da barra de cores não está encaixado.

*LstDocCores*<br/>
[em] Uma lista de cores que substitui as cores atuais do documento.

*bShowWhenDocked*<br/>
[em] É VERDADEIRO para mostrar as cores do documento quando o controle da barra de cores estiver encaixado; caso contrário, FALSE. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

*As cores* dos documentos são as cores usadas atualmente em um documento. O framework mantém automaticamente uma lista de cores de documentos, mas você pode usar esse método para modificar a lista.

## <a name="cmfccolorbarsethorzmargin"></a><a name="sethorzmargin"></a>CMFCColorBar::SetHorzMargin

Define a margem horizontal, que é o espaço entre a célula de cor esquerda ou direita e o limite da área do cliente.

```
void SetHorzMargin(int nHorzMargin);
```

### <a name="parameters"></a>Parâmetros

*nHorzMargin*<br/>
[em] A margem horizontal, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o [construtor CMFCColorBar::CMFCColorBar](#cmfccolorbar) define a margem horizontal para 4 pixels.

## <a name="cmfccolorbarsetproplist"></a><a name="setproplist"></a>CMFCColorbar::setproplist

Define `m_pWndPropList` o membro de dados protegido para o ponteiro especificado para um controle de grade de propriedade.

```
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pWndList*|[em] Ponteiro para objeto de controle da grade de propriedade.|

## <a name="cmfccolorbarsetvertmargin"></a><a name="setvertmargin"></a>CMFCColorBar::SetVertMargin

Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite da área do cliente.

```
void SetVertMargin(int nVertMargin);
```

### <a name="parameters"></a>Parâmetros

*nVertMargin*<br/>
[em] A margem vertical, em pixels.

### <a name="remarks"></a>Comentários

Por padrão, o [construtor CMFCColorBar::CMFCColorBar](#cmfccolorbar) define a margem vertical para 4 pixels.

## <a name="cmfccolorbarshowcommandmessagestring"></a><a name="showcommandmessagestring"></a>CMFCColorbar::ShowCommandMessageString

Solicita a janela de quadro que possui o controle da barra de cores para atualizar a linha de mensagens na barra de status.

```
virtual void ShowCommandMessageString(UINT uiCmdId);
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
[em] Uma id de comando. (Este parâmetro é ignorado.)

### <a name="remarks"></a>Comentários

Este método envia a mensagem WM_SETMESSAGESTRING ao proprietário do controle da barra de cores.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
