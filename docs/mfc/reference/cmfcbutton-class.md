---
title: Classe CMFCButton
ms.date: 08/28/2018
f1_keywords:
- CMFCButton
- AFXBUTTON/CMFCButton
- AFXBUTTON/CMFCButton::CleanUp
- AFXBUTTON/CMFCButton::EnableFullTextTooltip
- AFXBUTTON/CMFCButton::EnableMenuFont
- AFXBUTTON/CMFCButton::EnableWindowsTheming
- AFXBUTTON/CMFCButton::GetToolTipCtrl
- AFXBUTTON/CMFCButton::IsAutoCheck
- AFXBUTTON/CMFCButton::IsAutorepeatCommandMode
- AFXBUTTON/CMFCButton::IsCheckBox
- AFXBUTTON/CMFCButton::IsChecked
- AFXBUTTON/CMFCButton::IsHighlighted
- AFXBUTTON/CMFCButton::IsPressed
- AFXBUTTON/CMFCButton::IsPushed
- AFXBUTTON/CMFCButton::IsRadioButton
- AFXBUTTON/CMFCButton::IsWindowsThemingEnabled
- AFXBUTTON/CMFCButton::SetAutorepeatMode
- AFXBUTTON/CMFCButton::SetCheckedImage
- AFXBUTTON/CMFCButton::SetFaceColor
- AFXBUTTON/CMFCButton::SetImage
- AFXBUTTON/CMFCButton::SetMouseCursor
- AFXBUTTON/CMFCButton::SetMouseCursorHand
- AFXBUTTON/CMFCButton::SetStdImage
- AFXBUTTON/CMFCButton::SetTextColor
- AFXBUTTON/CMFCButton::SetTextHotColor
- AFXBUTTON/CMFCButton::SetTooltip
- AFXBUTTON/CMFCButton::SizeToContent
- AFXBUTTON/CMFCButton::OnDraw
- AFXBUTTON/CMFCButton::OnDrawBorder
- AFXBUTTON/CMFCButton::OnDrawFocusRect
- AFXBUTTON/CMFCButton::OnDrawText
- AFXBUTTON/CMFCButton::OnFillBackground
- AFXBUTTON/CMFCButton::SelectFont
- AFXBUTTON/CMFCButton::m_bDrawFocus
- AFXBUTTON/CMFCButton::m_bHighlightChecked
- AFXBUTTON/CMFCButton::m_bRightImage
- AFXBUTTON/CMFCButton::m_bTransparent
- AFXBUTTON/CMFCButton::m_nAlignStyle
- AFXBUTTON/CMFCButton::m_nFlatStyle
helpviewer_keywords:
- CMFCButton [MFC], CleanUp
- CMFCButton [MFC], EnableFullTextTooltip
- CMFCButton [MFC], EnableMenuFont
- CMFCButton [MFC], EnableWindowsTheming
- CMFCButton [MFC], GetToolTipCtrl
- CMFCButton [MFC], IsAutoCheck
- CMFCButton [MFC], IsAutorepeatCommandMode
- CMFCButton [MFC], IsCheckBox
- CMFCButton [MFC], IsChecked
- CMFCButton [MFC], IsHighlighted
- CMFCButton [MFC], IsPressed
- CMFCButton [MFC], IsPushed
- CMFCButton [MFC], IsRadioButton
- CMFCButton [MFC], IsWindowsThemingEnabled
- CMFCButton [MFC], SetAutorepeatMode
- CMFCButton [MFC], SetCheckedImage
- CMFCButton [MFC], SetFaceColor
- CMFCButton [MFC], SetImage
- CMFCButton [MFC], SetMouseCursor
- CMFCButton [MFC], SetMouseCursorHand
- CMFCButton [MFC], SetStdImage
- CMFCButton [MFC], SetTextColor
- CMFCButton [MFC], SetTextHotColor
- CMFCButton [MFC], SetTooltip
- CMFCButton [MFC], SizeToContent
- CMFCButton [MFC], OnDraw
- CMFCButton [MFC], OnDrawBorder
- CMFCButton [MFC], OnDrawFocusRect
- CMFCButton [MFC], OnDrawText
- CMFCButton [MFC], OnFillBackground
- CMFCButton [MFC], SelectFont
- CMFCButton [MFC], m_bDrawFocus
- CMFCButton [MFC], m_bHighlightChecked
- CMFCButton [MFC], m_bRightImage
- CMFCButton [MFC], m_bTransparent
- CMFCButton [MFC], m_nAlignStyle
- CMFCButton [MFC], m_nFlatStyle
ms.assetid: 4b32f57c-7a53-4734-afb9-d47e3359f62e
ms.openlocfilehash: 7628ac353d01c2a6853e35a35bd1f702d3bb041e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505854"
---
# <a name="cmfcbutton-class"></a>Classe CMFCButton

A `CMFCButton` classe adiciona funcionalidade à classe [CButton](../../mfc/reference/cbutton-class.md) , como texto de botão de alinhamento, combinação de texto de botão e imagem, seleção de um cursor e especificação de uma dica de ferramenta.

## <a name="syntax"></a>Sintaxe

```
class CMFCButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCButton::CMFCButton`|Construtor padrão.|
|`CMFCButton::~CMFCButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton:: CleanUp](#cleanup)|Redefine as variáveis internas e libera recursos alocados, como imagens, bitmaps e ícones.|
|`CMFCButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCButton::DrawItem`|Chamado pelo Framework quando um aspecto visual de um botão desenhado pelo proprietário foi alterado. (Substitui [CButton::D rawitem](../../mfc/reference/cbutton-class.md#drawitem).)|
|[CMFCButton::EnableFullTextTooltip](#enablefulltexttooltip)|Especifica se é para exibir o texto completo de uma dica de ferramenta em uma janela de dica de ferramenta grande ou uma versão truncada do texto em uma pequena janela de dica de ferramenta.|
|[CMFCButton::EnableMenuFont](#enablemenufont)|Especifica se a fonte do texto do botão é igual à fonte do menu do aplicativo.|
|[CMFCButton::EnableWindowsTheming](#enablewindowstheming)|Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCButton::GetToolTipCtrl](#gettooltipctrl)|Retorna uma referência ao controle de dica de ferramenta subjacente.|
|[CMFCButton::IsAutoCheck](#isautocheck)|Indica se uma caixa de seleção ou botão de opção é um botão automático.|
|[CMFCButton::IsAutorepeatCommandMode](#isautorepeatcommandmode)|Indica se um botão está definido para o modo de repetição automática.|
|[CMFCButton::IsCheckBox](#ischeckbox)|Indica se um botão é um botão de caixa de seleção.|
|[CMFCButton:: IsChecked](#ischecked)|Indica se o botão atual está marcado.|
|[CMFCButton:: realce](#ishighlighted)|Indica se um botão está realçado.|
|[CMFCButton:: ispressioned](#ispressed)|Indica se um botão é enviado por push e realçado.|
|[CMFCButton:: ispushed](#ispushed)|Indica se um botão é enviado por push.|
|[CMFCButton:: isradiobutton](#isradiobutton)|Indica se um botão é um botão de opção.|
|[CMFCButton::IsWindowsThemingEnabled](#iswindowsthemingenabled)|Indica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::OnDrawParentBackground`|Desenha o plano de fundo do pai de um botão na área especificada. (Substitui [AFX_GLOBAL_DATA::D rawparentbackground](../../mfc/reference/afx-global-data-structure.md)|
|`CMFCButton::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . (Substitui [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCButton::SetAutorepeatMode](#setautorepeatmode)|Define um botão para modo de repetição automática.|
|[CMFCButton::SetCheckedImage](#setcheckedimage)|Define a imagem para um botão marcado.|
|[CMFCButton::SetFaceColor](#setfacecolor)|Define a cor do plano de fundo do texto do botão.|
|[CMFCButton::SetImage](#setimage)|Define a imagem para um botão.|
|[CMFCButton::SetMouseCursor](#setmousecursor)|Define a imagem do cursor.|
|[CMFCButton::SetMouseCursorHand](#setmousecursorhand)|Define o cursor para a imagem de uma mão.|
|[CMFCButton::SetStdImage](#setstdimage)|Usa um `CMenuImages` objeto para definir a imagem do botão.|
|[CMFCButton::SetTextColor](#settextcolor)|Define a cor do texto do botão para um botão que não está selecionado.|
|[CMFCButton::SetTextHotColor](#settexthotcolor)|Define a cor do texto do botão para um botão selecionado.|
|[CMFCButton:: SetToolTip](#settooltip)|Associa uma dica de ferramenta a um botão.|
|[CMFCButton::SizeToContent](#sizetocontent)|Redimensiona um botão para conter o texto e a imagem do botão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton:: OnDraw](#ondraw)|Chamado pelo Framework para desenhar um botão.|
|[CMFCButton::OnDrawBorder](#ondrawborder)|Chamado pelo Framework para desenhar a borda de um botão.|
|[CMFCButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo Framework para desenhar o retângulo de foco de um botão.|
|[CMFCButton:: ondrawtext](#ondrawtext)|Chamado pelo Framework para desenhar o texto do botão.|
|[CMFCButton::OnFillBackground](#onfillbackground)|Chamado pelo Framework para desenhar o plano de fundo do texto do botão.|
|[CMFCButton::SelectFont](#selectfont)|Recupera a fonte associada ao contexto do dispositivo especificado.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton::m_nAlignStyle](#m_nalignstyle)|Especifica o alinhamento do texto do botão.|
|[CMFCButton::m_bDontUseWinXPTheme](#m_bDontUseWinXPTheme)|Especifica se os temas do Windows XP devem ser usados.|
|[CMFCButton::m_bDrawFocus](#m_bdrawfocus)|Indica se um retângulo de foco deve ser desenhado em um botão.|
|[CMFCButton::m_nFlatStyle](#m_nflatstyle)|Especifica o estilo do botão, como sem borda, simples, semisimples ou 3D.|
|[CMFCButton::m_bGrayDisabled](#m_bGrayDisabled)|Quando TRUE, permite que um botão desabilitado seja desenhado como esmaecido.|
|[CMFCButton::m_bHighlightChecked](#m_bhighlightchecked)|Indica se um botão de estilo BS_CHECKBOX deve ser realçado quando o cursor passa sobre ele.|
|[CMFCButton::m_bResponseOnButtonDown](#m_bResponseOnButtonDown)|Indica se é para responder a eventos de botão para baixo.|
|[CMFCButton::m_bRightImage](#m_brightimage)|Indica se uma imagem deve ser exibida no lado direito do botão.|
|[CMFCButton::m_bTopImage](#m_bTopImage)| Indica se a imagem está na parte superior do botão.|
|[CMFCButton::m_bTransparent](#m_btransparent)|Indica se o botão é transparente.|
|[CMFCButton::m_bWasDblClk](#m_bWasDblClk)| Indica se o último evento de clique foi um clique duplo.|

## <a name="remarks"></a>Comentários

Outros tipos de botões são derivados da `CMFCButton` classe, como a classe [CMFCURLLinkButton](../../mfc/reference/cmfclinkctrl-class.md) , que dá suporte a hiperlinks e a `CMFCColorButton` classe, que dá suporte a uma caixa de diálogo Seletor de cores.

O estilo de um `CMFCButton` objeto pode ser *3D*, *simples*, *semisimples* ou *nenhuma borda*. O texto do botão pode ser alinhado à esquerda, à parte superior ou ao centro de um botão. Em tempo de execução, você pode controlar se o botão exibe texto, imagem ou texto e uma imagem. Você também pode especificar que uma imagem de cursor específica seja exibida quando o cursor passar sobre um botão.

Crie um controle de botão diretamente no seu código ou usando a ferramenta do **Assistente de classe do MFC** e um modelo de caixa de diálogo. Se você criar um controle de botão diretamente, adicione `CMFCButton` uma variável ao seu aplicativo e, em seguida, chame `Create` o construtor e `CMFCButton` os métodos do objeto. Se você usar o **Assistente de classe do MFC**, `CButton` adicione uma variável ao seu aplicativo e, em seguida, altere o tipo `CButton` da `CMFCButton`variável de para.

Para lidar com mensagens de notificação em um aplicativo de caixa de diálogo, adicione uma entrada de mapa de mensagem e um manipulador de eventos para cada notificação. As notificações enviadas por um `CMFCButton` objeto são as mesmas que as enviadas por um `CButton` objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar as propriedades do botão usando vários métodos na `CMFCButton` classe. O exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#31](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_2.cpp)]
[!code-cpp[NVC_MFC_NewControls#32](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_3.cpp)]
[!code-cpp[NVC_MFC_NewControls#33](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_4.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCButton](../../mfc/reference/cmfcbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbutton. h

##  <a name="cleanup"></a>CMFCButton:: CleanUp

Redefine as variáveis internas e libera recursos alocados, como imagens, bitmaps e ícones.

```
virtual void CleanUp();
```

##  <a name="enablefulltexttooltip"></a>CMFCButton::EnableFullTextTooltip

Especifica se é para exibir o texto completo de uma dica de ferramenta em uma janela de dica de ferramenta grande ou uma versão truncada do texto em uma pequena janela de dica de ferramenta.

```
void EnableFullTextTooltip(BOOL bOn=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
no TRUE para exibir todo o texto; FALSE para exibir texto truncado.

### <a name="remarks"></a>Comentários

##  <a name="enablemenufont"></a>CMFCButton::EnableMenuFont

Especifica se a fonte do texto do botão é igual à fonte do menu do aplicativo.

```
void EnableMenuFont(
    BOOL bOn=TRUE,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
no TRUE para usar a fonte do menu do aplicativo como a fonte do texto do botão; FALSE para usar a fonte do sistema. O padrão é TRUE.

*bRedraw*<br/>
no TRUE para redesenhar a tela imediatamente; caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Se você não usar esse método para especificar a fonte do texto do botão, poderá especificar a fonte com o método [CWnd:: SetFont](../../mfc/reference/cwnd-class.md#setfont) . Se você não especificar uma fonte, a estrutura definirá uma fonte padrão.

##  <a name="enablewindowstheming"></a>  CMFCButton::EnableWindowsTheming

Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static void EnableWindowsTheming(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no TRUE para usar o tema atual do Windows para desenhar bordas de botão; FALSE para não usar o tema do Windows. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Esse método afeta todos os botões em seu aplicativo que são derivados da `CMFCButton` classe.

##  <a name="gettooltipctrl"></a>  CMFCButton::GetToolTipCtrl

Retorna uma referência ao controle de dica de ferramenta subjacente.

```
CToolTipCtrl& GetToolTipCtrl();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao controle ToolTip subjacente.

### <a name="remarks"></a>Comentários

##  <a name="isautocheck"></a>CMFCButton::IsAutoCheck

Indica se uma caixa de seleção ou botão de opção é um botão automático.

```
BOOL IsAutoCheck() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão tiver o estilo BS_AUTOCHECKBOX ou BS_AUTORADIOBUTTON; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isautorepeatcommandmode"></a>CMFCButton::IsAutorepeatCommandMode

Indica se um botão está definido para o modo de repetição automática.

```
BOOL IsAutorepeatCommandMode() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão estiver definido como modo de repetição automática; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o método [CMFCButton:: SetAutorepeatMode](#setautorepeatmode) para definir um botão para modo de repetição automática.

##  <a name="ischeckbox"></a>CMFCButton:: ischeckbox

Indica se um botão é um botão de caixa de seleção.

```
BOOL IsCheckBox() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão tiver o estilo BS_CHECKBOX ou BS_AUTOCHECKBOX; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ischecked"></a>CMFCButton:: IsChecked

Indica se o botão atual está marcado.

```
BOOL IsChecked() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão atual estiver marcado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A estrutura usa maneiras diferentes para indicar que tipos diferentes de botões são verificados. Por exemplo, um botão de opção é verificado quando ele contém um ponto; uma caixa de seleção é marcada quando contém um **X**.

##  <a name="ishighlighted"></a>CMFCButton:: realce

Indica se um botão está realçado.

```
BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão estiver realçado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um botão é realçado quando o mouse passa sobre o botão.

##  <a name="ispressed"></a>CMFCButton:: ispressioned

Indica se um botão é enviado por push e realçado.

```
BOOL IsPressed() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão for pressionado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ispushed"></a>CMFCButton:: ispushed

Indica se um botão é enviado por push.

```
BOOL IsPushed() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão for enviado por push; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isradiobutton"></a>CMFCButton:: isradiobutton

Indica se um botão é um botão de opção.

```
BOOL IsRadioButton() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o estilo do botão for BS_RADIOBUTTON ou BS_AUTORADIOBUTTON; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="iswindowsthemingenabled"></a>  CMFCButton::IsWindowsThemingEnabled

Indica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static BOOL IsWindowsThemingEnabled();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o estilo da borda do botão corresponder ao tema atual do Windows; caso contrário, FALSE.

## <a name="a-namem_bdontusewinxptheme-cmfcbuttonm_bdontusewinxptheme"></a><a name="m_bDontUseWinXPTheme"/>CMFCButton::m_bDontUseWinXPTheme

Especifica se os temas do Windows XP devem ser usados ao desenhar o botão.

```
BOOL m_bDontUseWinXPTheme;
```

##  <a name="m_bdrawfocus"></a>CMFCButton::m_bDrawFocus

Indica se um retângulo de foco deve ser desenhado em um botão.

```
BOOL m_bDrawFocus;
```

### <a name="remarks"></a>Comentários

Defina o `m_bDrawFocus` membro como true para especificar que o Framework desenhará um retângulo de foco em volta do texto e da imagem do botão se o botão receber o foco.

O `CMFCButton` construtor inicializa esse membro como true.

##  <a name="m_bGrayDisabled"></a>CMFCButton::m_bGrayDisabled

Quando TRUE, permite que um botão desabilitado seja desenhado como esmaecido.

```
BOOL m_bGrayDisabled;
```

##  <a name="m_bhighlightchecked"></a>CMFCButton::m_bHighlightChecked

Indica se um botão de estilo BS_CHECKBOX deve ser realçado quando o cursor passa sobre ele.

```
BOOL m_bHighlightChecked;
```

### <a name="remarks"></a>Comentários

Defina o `m_bHighlightChecked` membro como true para especificar que a estrutura irá destacar um botão de estilo BS_CHECKBOX quando o mouse passar sobre ele.

##  <a name="m_bResponseOnButtonDown"></a>CMFCButton::m_bResponseOnButtonDown

Indica se é para responder a eventos de botão para baixo.

```
BOOL m_bResponseOnButtonDown;
```

##  <a name="m_brightimage"></a>CMFCButton::m_bRightImage

Indica se uma imagem deve ser exibida no lado direito do botão.

```
BOOL m_bRightImage;
```

##  <a name="m_bTopImage"></a>  CMFCButton::m_bTopImage](#m_bTopImage)

Indica se a imagem está na parte superior do botão.

```
BOOL m_bTopImage;
```

### <a name="remarks"></a>Comentários

Defina o `m_bRightImage` membro como verdadeiro para especificar que a estrutura exibirá a imagem do botão à direita do rótulo de texto do botão.

##  <a name="m_btransparent"></a>CMFCButton::m_bTransparent

Indica se o botão é transparente.

```
BOOL m_bTransparent;
```

### <a name="remarks"></a>Comentários

Defina o `m_bTransparent` membro como true para especificar que o Framework tornará o botão transparente. O `CMFCButton` construtor inicializa esse membro como false.

##  <a name="m_nalignstyle"></a>CMFCButton::m_nAlignStyle

Especifica o alinhamento do texto do botão.

```
AlignStyle m_nAlignStyle;
```

### <a name="remarks"></a>Comentários

Use um dos seguintes `CMFCButton::AlignStyle` valores de enumeração para especificar o alinhamento do texto do botão:

|Valor|Descrição|
|-----------|-----------------|
|ALIGN_CENTER|Os Alinha o texto do botão ao centro do botão.|
|ALIGN_LEFT|Alinha o texto do botão ao lado esquerdo do botão.|
|ALIGN_RIGHT|Alinha o texto do botão ao lado direito do botão.|

O `CMFCButton` construtor inicializa esse membro para ALIGN_CENTER.

##  <a name="m_bWasDblClk"></a>  CMFCButton::m_bWasDblClk](#m_bWasDblClk)|

Indica se o último evento de clique foi um clique duplo. |

```
BOOL m_bWasDblClk;
```

##  <a name="m_nflatstyle"></a>CMFCButton::m_nFlatStyle

Especifica o estilo do botão, como sem borda, simples, semisimples ou 3D.

```
FlatStyle  m_nFlatStyle;
```

### <a name="remarks"></a>Comentários

A tabela a seguir lista `CMFCButton::m_nFlatStyle` os valores de enumeração que especificam a aparência de um botão.

|Valor|Descrição|
|-----------|-----------------|
|BUTTONSTYLE_3D|Os O botão parece ter alto e três lados tridimensionais. Quando o botão é clicado, o botão parece ser pressionado em um recuo profundo.|
|BUTTONSTYLE_FLAT|Quando o mouse não pausa sobre o botão, o botão parece ser bidimensional e não tem lados elevados. Quando o mouse pausa sobre o botão, o botão parece ter lados baixos e tridimensionais. Quando o botão é clicado, o botão parece ser pressionado em um recuo superficial.|
|BUTTONSTYLE_SEMIFLAT|O botão parece ter lados baixos e tridimensionais. Quando o botão é clicado, o botão parece ser pressionado em um recuo profundo.|
|BUTTONSTYLE_NOBORDERS|O botão não tem lados elevados e sempre aparece bidimensional. O botão não parece ser pressionado em um recuo quando clicado.|

O `CMFCButton` construtor inicializa esse membro para BUTTONSTYLE_3D.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir os valores da `m_nFlatStyle` variável de membro `CMFCButton` na classe. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#29](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_5.cpp)]

##  <a name="ondraw"></a>CMFCButton:: OnDraw

Chamado pelo Framework para desenhar um botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rect*<br/>
no Uma referência a um retângulo que limita o botão.

*uiState*<br/>
no O estado atual do botão. Para obter mais informações, consulte `itemState` o membro do tópico de [Estrutura DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) .

### <a name="remarks"></a>Comentários

Substitua esse método para usar seu próprio código para desenhar um botão.

##  <a name="ondrawborder"></a>CMFCButton::OnDrawBorder

Chamado pelo Framework para desenhar a borda de um botão.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect& rectClient,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
no Uma referência a um retângulo que limita o botão.

*uiState*<br/>
no O estado atual do botão. Para obter mais informações, consulte `itemState` o membro do tópico de [Estrutura DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) .

### <a name="remarks"></a>Comentários

Substitua esse método para usar seu próprio código para desenhar a borda.

##  <a name="ondrawfocusrect"></a>CMFCButton::OnDrawFocusRect

Chamado pelo Framework para desenhar o retângulo de foco de um botão.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
no Uma referência a um retângulo que limita o botão.

### <a name="remarks"></a>Comentários

Substitua esse método para usar seu próprio código para desenhar o retângulo de foco.

##  <a name="ondrawtext"></a>CMFCButton:: ondrawtext

Chamado pelo Framework para desenhar o texto do botão.

```
virtual void OnDrawText(
    CDC* pDC,
    const CRect& rect,
    const CString& strText,
    UINT uiDTFlags,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rect*<br/>
no Uma referência a um retângulo que limita o botão.

*strText*<br/>
no O texto a ser desenhado.

*uiDTFlags*<br/>
no Sinalizadores que especificam como formatar o texto. Para obter mais informações, consulte o parâmetro *nFormat* do método [CDC::D rawtext](../../mfc/reference/cdc-class.md#drawtext) .

*uiState*<br/>
[in] Reservado.

### <a name="remarks"></a>Comentários

Substitua esse método para usar seu próprio código para desenhar o texto do botão.

##  <a name="onfillbackground"></a>CMFCButton::OnFillBackground

Chamado pelo Framework para desenhar o plano de fundo do texto do botão.

```
virtual void OnFillBackground(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
no Uma referência a um retângulo que limita o botão.

### <a name="remarks"></a>Comentários

Substitua esse método para usar seu próprio código para desenhar o plano de fundo de um botão.

##  <a name="selectfont"></a>CMFCButton::SelectFont

Recupera a fonte associada ao contexto do dispositivo especificado.

```
virtual CFont* SelectFont(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

### <a name="return-value"></a>Valor de retorno

Substitua esse método para usar seu próprio código para recuperar a fonte.

### <a name="remarks"></a>Comentários

##  <a name="setautorepeatmode"></a>CMFCButton::SetAutorepeatMode

Define um botão para modo de repetição automática.

```
void SetAutorepeatMode(int nTimeDelay=500);
```

### <a name="parameters"></a>Parâmetros

*nTimeDelay*<br/>
no Um número não negativo que especifica o intervalo entre as mensagens enviadas para a janela pai. O intervalo é medido em milissegundos e seu valor padrão é de 500 milissegundos. Especifique zero para desabilitar o modo de mensagem de repetição automática.

### <a name="remarks"></a>Comentários

Esse método faz com que o botão envie mensagens WM_COMMAND constantemente para a janela pai até que o botão seja liberado ou o parâmetro *nTimeDelay* seja definido como zero.

##  <a name="setcheckedimage"></a>  CMFCButton::SetCheckedImage

Define a imagem para um botão marcado.

```
void SetCheckedImage(
    HICON hIcon,
    BOOL bAutoDestroy=TRUE,
    HICON hIconHot=NULL,
    HICON hIconDisabled=NULL,
    BOOL bAlphaBlend=FALSE);

void SetCheckedImage(
    HBITMAP hBitmap,
    BOOL bAutoDestroy=TRUE,
    HBITMAP hBitmapHot=NULL,
    BOOL bMap3dColors=TRUE,
    HBITMAP hBitmapDisabled=NULL);

void SetCheckedImage(
    UINT uiBmpResId,
    UINT uiBmpHotResId=0,
    UINT uiBmpDsblResID=0);
```

### <a name="parameters"></a>Parâmetros

*hIcon*<br/>
no Identificador para o ícone que contém o bitmap e a máscara da nova imagem.

*bAutoDestroy*<br/>
no TRUE para especificar que os recursos de bitmap sejam destruídos automaticamente; caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
no Identificador para o ícone que contém a imagem do estado selecionado.

*hBitmap*<br/>
no Identificador para o bitmap que contém a imagem do estado não selecionado.

*hBitmapHot*<br/>
no Identificador para o bitmap que contém a imagem do estado selecionado.

*bMap3dColors*<br/>
no Especifica uma cor transparente para o plano de fundo do botão; ou seja, a face do botão. TRUE para usar o valor de cor RGB (192, 192, 192); FALSE para usar o valor de cor definido `AFX_GLOBAL_DATA::clrBtnFace`por.

*uiBmpResId*<br/>
no ID de recurso para a imagem não selecionada.

*uiBmpHotResId*<br/>
no ID de recurso da imagem selecionada.

*hIconDisabled*<br/>
no Identificador para o ícone da imagem desabilitada.

*hBitmapDisabled*<br/>
no Identificador para o bitmap que contém a imagem desabilitada.

*uiBmpDsblResID*<br/>
no ID de recurso do bitmap desabilitado.

*bAlphaBlend*<br/>
no TRUE para usar apenas imagens de 32 bits que usam o canal alfa; FALSE, para não usar somente imagens de canal alfa. O padrão é FALSE.

### <a name="remarks"></a>Comentários

##  <a name="setfacecolor"></a>CMFCButton::SetFaceColor

Define a cor do plano de fundo do texto do botão.

```
void SetFaceColor(
    COLORREF crFace,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*crFace*<br/>
no Um valor de cor RGB.

*bRedraw*<br/>
no TRUE para redesenhar a tela imediatamente; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método para definir uma nova cor de preenchimento para o plano de fundo do botão (face). Observe que o plano de fundo não é preenchido quando a variável de membro [CMFCButton:: m_bTransparent](#m_btransparent) é verdadeira.

##  <a name="setimage"></a>  CMFCButton::SetImage

Define a imagem para um botão.

```
void SetImage(
    HICON hIcon,
    BOOL bAutoDestroy=TRUE,
    HICON hIconHot=NULL,
    HICON hIconDisabled=NULL,
    BOOL bAlphaBlend=FALSE);

void SetImage(
    HBITMAP hBitmap,
    BOOL bAutoDestroy=TRUE,
    HBITMAP hBitmapHot=NULL,
    BOOL bMap3dColors=TRUE,
    HBITMAP hBitmapDisabled=NULL);

void SetImage(
    UINT uiBmpResId,
    UINT uiBmpHotResId=0,
    UINT uiBmpDsblResID=0);
```

### <a name="parameters"></a>Parâmetros

*hIcon*<br/>
no Identificador para o ícone que contém o bitmap e a máscara da nova imagem.

*bAutoDestroy*<br/>
no TRUE para especificar que os recursos de bitmap sejam destruídos automaticamente; caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
no Identificador para o ícone que contém a imagem do estado selecionado.

*hBitmap*<br/>
no Identificador para o bitmap que contém a imagem do estado não selecionado.

*hBitmapHot*<br/>
no Identificador para o bitmap que contém a imagem do estado selecionado.

*uiBmpResId*<br/>
no ID de recurso para a imagem não selecionada.

*uiBmpHotResId*<br/>
no ID de recurso da imagem selecionada.

*bMap3dColors*<br/>
no Especifica uma cor transparente para o plano de fundo do botão; ou seja, a face do botão. TRUE para usar o valor de cor RGB (192, 192, 192); FALSE para usar o valor de cor definido `AFX_GLOBAL_DATA::clrBtnFace`por.

*hIconDisabled*<br/>
no Identificador para o ícone da imagem desabilitada.

*hBitmapDisabled*<br/>
no Identificador para o bitmap que contém a imagem desabilitada.

*uiBmpDsblResID*<br/>
no ID de recurso do bitmap desabilitado.

*bAlphaBlend*<br/>
no TRUE para usar apenas imagens de 32 bits que usam o canal alfa; FALSE, para não usar somente imagens de canal alfa. O padrão é FALSE.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar várias versões do `SetImage` método `CMFCButton` na classe. O exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#31](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_2.cpp)]

##  <a name="setmousecursor"></a>CMFCButton::SetMouseCursor

Define a imagem do cursor.

```
void SetMouseCursor(HCURSOR hcursor);
```

### <a name="parameters"></a>Parâmetros

*hcursor*<br/>
no O identificador de um cursor.

### <a name="remarks"></a>Comentários

Use este método para associar uma imagem de cursor, como o cursor à mão, com o botão. O cursor é carregado dos recursos do aplicativo.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `SetMouseCursor` método `CMFCButton` na classe. O exemplo faz parte do código no exemplo de [novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#30](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_6.cpp)]

##  <a name="setmousecursorhand"></a>  CMFCButton::SetMouseCursorHand

Define o cursor para a imagem de uma mão.

```
void SetMouseCursorHand();
```

### <a name="remarks"></a>Comentários

Use este método para associar a imagem do cursor de uma mão ao botão. O cursor é carregado dos recursos do aplicativo.

##  <a name="setstdimage"></a>  CMFCButton::SetStdImage

Usa um `CMenuImages` objeto para definir a imagem do botão.

```
void SetStdImage(
    CMenuImages::IMAGES_IDS id,
    CMenuImages::IMAGE_STATE state=CMenuImages::ImageBlack,
    CMenuImages::IMAGES_IDS idDisabled=(CMenuImages::IMAGES_IDS)0);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
no Um dos identificadores de imagem de botão que é definido na `CMenuImage::IMAGES_IDS` enumeração. Os valores da imagem especificam imagens como setas, pins e botões de opção.

*state*<br/>
no Um dos identificadores de estado da imagem do botão que é definido `CMenuImages::IMAGE_STATE` na enumeração. Os Estados de imagem especificam cores de botão como preto, cinza, cinza claro, branco e cinza escuro. O valor padrão é `CMenuImages::ImageBlack`.

*idDisabled*<br/>
no Um dos identificadores de imagem de botão que é definido na `CMenuImage::IMAGES_IDS` enumeração. A imagem indica que o botão está desabilitado. O valor padrão é a primeira imagem de botão `CMenuImages::IdArrowDown`().

### <a name="remarks"></a>Comentários

##  <a name="settextcolor"></a>CMFCButton::SetTextColor

Define a cor do texto do botão para um botão que não está selecionado.

```
void SetTextColor(COLORREF clrText);
```

### <a name="parameters"></a>Parâmetros

*clrText*<br/>
no Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="settexthotcolor"></a>  CMFCButton::SetTextHotColor

Define a cor do texto do botão para um botão selecionado.

```
void SetTextHotColor(COLORREF clrTextHot);
```

### <a name="parameters"></a>Parâmetros

*clrTextHot*<br/>
no Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="settooltip"></a>CMFCButton:: SetToolTip

Associa uma dica de ferramenta a um botão.

```
void SetTooltip(LPCTSTR lpszToolTipText);
```

### <a name="parameters"></a>Parâmetros

*lpszToolTipText*<br/>
no Ponteiro para o texto da dica de ferramenta. Especifique NULL para desabilitar a dica de ferramenta.

### <a name="remarks"></a>Comentários

##  <a name="sizetocontent"></a>CMFCButton::SizeToContent

Redimensiona um botão para conter o texto e a imagem do botão.

```
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
no TRUE para calcular, mas não alterar, o novo tamanho do botão; FALSE para alterar o tamanho do botão. O padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

Um `CSize` objeto que contém o novo tamanho do botão.

### <a name="remarks"></a>Comentários

Por padrão, esse método calcula um novo tamanho que inclui uma margem horizontal de 10 pixels e uma margem vertical de 5 pixels.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)<br/>
[Classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)<br/>
[Classe CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)
