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
ms.openlocfilehash: 0659e5335e1ebc495280a4e0cb5c0167f3b45e1d
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58768205"
---
# <a name="cmfcbutton-class"></a>Classe CMFCButton

O `CMFCButton` classe adiciona funcionalidade para o [CButton](../../mfc/reference/cbutton-class.md) classe como alinhar o texto do botão, combinar o texto do botão e uma imagem, selecionar um cursor e especificando uma dica de ferramenta.

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
|[CMFCButton::CleanUp](#cleanup)|Redefine as variáveis internas e libera recursos alocados como imagens, bitmaps e ícones.|
|`CMFCButton::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCButton::DrawItem`|Chamado pelo framework quando um aspecto visual de um botão desenhado pelo proprietário é alterado. (Substitui [CButton::DrawItem](../../mfc/reference/cbutton-class.md#drawitem).)|
|[CMFCButton::EnableFullTextTooltip](#enablefulltexttooltip)|Especifica se deve exibir o texto completo de uma dica de ferramenta em uma janela de dica de ferramenta grande ou uma versão truncada do texto em uma janela pequena dica de ferramenta.|
|[CMFCButton::EnableMenuFont](#enablemenufont)|Especifica se a fonte do texto de botão é o mesmo que a fonte do menu de aplicativo.|
|[CMFCButton::EnableWindowsTheming](#enablewindowstheming)|Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCButton::GetToolTipCtrl](#gettooltipctrl)|Retorna uma referência ao controle de dica de ferramenta subjacente.|
|[CMFCButton::IsAutoCheck](#isautocheck)|Indica se uma caixa de seleção ou botão de opção é um botão automático.|
|[CMFCButton::IsAutorepeatCommandMode](#isautorepeatcommandmode)|Indica se um botão é definido para o modo de repetição automática.|
|[CMFCButton::IsCheckBox](#ischeckbox)|Indica se um botão é um botão da caixa de seleção.|
|[CMFCButton::IsChecked](#ischecked)|Indica se o botão atual é verificado.|
|[CMFCButton::IsHighlighted](#ishighlighted)|Indica se um botão está realçado.|
|[CMFCButton::IsPressed](#ispressed)|Indica se um botão é enviada por push e realçado.|
|[CMFCButton::IsPushed](#ispushed)|Indica se um botão é pressionado.|
|[CMFCButton::IsRadioButton](#isradiobutton)|Indica se um botão é um botão de opção.|
|[CMFCButton::IsWindowsThemingEnabled](#iswindowsthemingenabled)|Indica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::OnDrawParentBackground`|Desenha a tela de fundo do pai de um botão na área especificada. (Substitui [AFX_GLOBAL_DATA::DrawParentBackground](../../mfc/reference/afx-global-data-structure.md)|
|`CMFCButton::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCButton::SetAutorepeatMode](#setautorepeatmode)|Define um botão para o modo de repetição automática.|
|[CMFCButton::SetCheckedImage](#setcheckedimage)|Define a imagem para um botão marcado.|
|[CMFCButton::SetFaceColor](#setfacecolor)|Define a cor de plano de fundo para o texto do botão.|
|[CMFCButton::SetImage](#setimage)|Define a imagem para um botão.|
|[CMFCButton::SetMouseCursor](#setmousecursor)|Define a imagem do cursor.|
|[CMFCButton::SetMouseCursorHand](#setmousecursorhand)|Define o cursor para a imagem de uma mão.|
|[CMFCButton::SetStdImage](#setstdimage)|Usa um `CMenuImages` objeto para definir a imagem do botão.|
|[CMFCButton::SetTextColor](#settextcolor)|Define a cor do texto do botão para um botão que não está selecionado.|
|[CMFCButton::SetTextHotColor](#settexthotcolor)|Define a cor do texto do botão para um botão que está selecionado.|
|[CMFCButton::SetTooltip](#settooltip)|Associa uma dica de ferramenta com um botão.|
|[CMFCButton::SizeToContent](#sizetocontent)|Redimensiona um botão para conter o texto de botão e a imagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton::OnDraw](#ondraw)|Chamado pelo framework para desenhar um botão.|
|[CMFCButton::OnDrawBorder](#ondrawborder)|Chamado pelo framework para desenhar a borda de um botão.|
|[CMFCButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo framework para desenhar o retângulo de foco para um botão.|
|[CMFCButton::OnDrawText](#ondrawtext)|Chamado pelo framework para desenhar o texto do botão.|
|[CMFCButton::OnFillBackground](#onfillbackground)|Chamado pelo framework para desenhar a tela de fundo do texto do botão.|
|[CMFCButton::SelectFont](#selectfont)|Recupera a fonte que está associada com o contexto de dispositivo especificado.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton::m_nAlignStyle](#m_nalignstyle)|Especifica o alinhamento do texto do botão.|
|[CMFCButton::m_bDontUseWinXPTheme](#m_bDontUseWinXPTheme)|Especifica se deve usar temas do Windows XP.|
|[CMFCButton::m_bDrawFocus](#m_bdrawfocus)|Indica se é necessário desenhar um retângulo de foco ao redor de um botão.|
|[CMFCButton::m_nFlatStyle](#m_nflatstyle)|Especifica o estilo do botão, como sem borda, simples, simples de ponto e vírgula ou 3D.|
|[CMFCButton::m_bGrayDisabled](#m_bGrayDisabled)|Quando for verdadeiro, permite que um botão desabilitado a ser desenhado como acinzentado.|
|[CMFCButton::m_bHighlightChecked](#m_bhighlightchecked)|Indica se é para realçar um botão de estilo BS_CHECKBOX quando o cursor passa sobre ele.|
|[CMFCButton::m_bResponseOnButtonDown](#m_bResponseOnButtonDown)|Indica se deve responder a botão para baixo de eventos.|
|[CMFCButton::m_bRightImage](#m_brightimage)|Indica se deve exibir uma imagem à direita do botão.|
|[CMFCButton::m_bTopImage](#m_bTopImage)| Indica se a imagem está sobre o botão.|
|[CMFCButton::m_bTransparent](#m_btransparent)|Indica se o botão é transparente.|
|[CMFCButton::m_bWasDblClk](#m_bWasDblClk)| Indica se o último clique o evento foi um clique duplo.|

## <a name="remarks"></a>Comentários

Outros tipos de botões são derivados do `CMFCButton` classe, como o [CMFCURLLinkButton](../../mfc/reference/cmfclinkctrl-class.md) classe, que dá suporte a hiperlinks, e o `CMFCColorButton` classe, que dá suporte a uma caixa de diálogo do seletor de cor.

O estilo de um `CMFCButton` objeto pode ser *3D*, *simples*, *-e-simples* ou *nenhuma borda*. Texto do botão pode ser alinhado na parte esquerda, superior ou centro de um botão. Em tempo de execução, você pode controlar se o botão exibe o texto, uma imagem ou texto e uma imagem. Você também pode especificar que uma imagem de cursor específico ser exibida quando o cursor passa sobre um botão.

Criar um controle de botão diretamente em seu código ou usando o **MFC Class Wizard** ferramenta e um modelo de caixa de diálogo. Se você criar diretamente um controle de botão, adicione uma `CMFCButton` variável ao seu aplicativo e, em seguida, chame o construtor e `Create` métodos do `CMFCButton` objeto. Se você usar o **MFC Class Wizard**, adicione uma `CButton` variável ao seu aplicativo e, em seguida, altere o tipo da variável de `CButton` para `CMFCButton`.

Para lidar com mensagens de notificação em um aplicativo de caixa de diálogo, adicione uma entrada de mapa de mensagem e um manipulador de eventos para cada notificação. As notificações enviadas por uma `CMFCButton` objeto são iguais àquelas enviadas por um `CButton` objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar as propriedades do botão usando vários métodos no `CMFCButton` classe. O exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

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

**Cabeçalho:** afxbutton.h

##  <a name="cleanup"></a>  CMFCButton::CleanUp

Redefine as variáveis internas e libera recursos alocados como imagens, bitmaps e ícones.

```
virtual void CleanUp();
```

##  <a name="enablefulltexttooltip"></a>  CMFCButton::EnableFullTextTooltip

Especifica se deve exibir o texto completo de uma dica de ferramenta em uma janela de dica de ferramenta grande ou uma versão truncada do texto em uma janela pequena dica de ferramenta.

```
void EnableFullTextTooltip(BOOL bOn=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
[in] TRUE para exibir todo o texto; FALSE para texto de exibição truncado.

### <a name="remarks"></a>Comentários

##  <a name="enablemenufont"></a>  CMFCButton::EnableMenuFont

Especifica se a fonte do texto de botão é o mesmo que a fonte do menu de aplicativo.

```
void EnableMenuFont(
    BOOL bOn=TRUE,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
[in] TRUE para usar a fonte do menu de aplicativo como a fonte do texto de botão; FALSE para usar a fonte do sistema. O padrão é TRUE.

*bRedraw*<br/>
[in] TRUE para redesenhar imediatamente a tela; Caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Se você não usar esse método para especificar a fonte do texto de botão, você pode especificar a fonte com o [CWnd::SetFont](../../mfc/reference/cwnd-class.md#setfont) método. Se você não especificar uma fonte em todos os, a estrutura define uma fonte padrão.

##  <a name="enablewindowstheming"></a>  CMFCButton::EnableWindowsTheming

Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static void EnableWindowsTheming(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
[in] TRUE para usar o tema atual do Windows para desenhar bordas do botão; FALSO para não usar o tema do Windows. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Esse método afeta todos os botões em seu aplicativo que são derivados de `CMFCButton` classe.

##  <a name="gettooltipctrl"></a>  CMFCButton::GetToolTipCtrl

Retorna uma referência ao controle de dica de ferramenta subjacente.

```
CToolTipCtrl& GetToolTipCtrl();
```

### <a name="return-value"></a>Valor de retorno

Uma referência para o controle de dica de ferramenta subjacente.

### <a name="remarks"></a>Comentários

##  <a name="isautocheck"></a>  CMFCButton::IsAutoCheck

Indica se uma caixa de seleção ou botão de opção é um botão automático.

```
BOOL IsAutoCheck() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão tem o estilo BS_AUTOCHECKBOX ou BS_AUTORADIOBUTTON; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isautorepeatcommandmode"></a>  CMFCButton::IsAutorepeatCommandMode

Indica se um botão é definido para o modo de repetição automática.

```
BOOL IsAutorepeatCommandMode() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão está definido para o modo de repetição automática; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o [CMFCButton::SetAutorepeatMode](#setautorepeatmode) método para definir um botão para o modo de repetição automática.

##  <a name="ischeckbox"></a>  CMFCButton::IsCheckBox

Indica se um botão é um botão da caixa de seleção.

```
BOOL IsCheckBox() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão tem o estilo BS_CHECKBOX ou BS_AUTOCHECKBOX; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ischecked"></a>  CMFCButton::IsChecked

Indica se o botão atual é verificado.

```
BOOL IsChecked() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão atual estiver verificado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A estrutura usa diferentes maneiras de indicar que os diferentes tipos de botões são verificados. Por exemplo, um botão de opção é verificado quando ele contém um ponto. uma caixa de seleção é marcada quando ela contém um **X**.

##  <a name="ishighlighted"></a>  CMFCButton::IsHighlighted

Indica se um botão está realçado.

```
BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão está realçado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um botão fica realçado quando o mouse passa sobre o botão.

##  <a name="ispressed"></a>  CMFCButton::IsPressed

Indica se um botão é enviada por push e realçado.

```
BOOL IsPressed() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão for pressionado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ispushed"></a>  CMFCButton::IsPushed

Indica se um botão é pressionado.

```
BOOL IsPushed() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o botão é pressionado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isradiobutton"></a>  CMFCButton::IsRadioButton

Indica se um botão é um botão de opção.

```
BOOL IsRadioButton() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o estilo de botão for BS_RADIOBUTTON ou BS_AUTORADIOBUTTON; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="iswindowsthemingenabled"></a>  CMFCButton::IsWindowsThemingEnabled

Indica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static BOOL IsWindowsThemingEnabled();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o estilo da borda do botão corresponde ao tema atual do Windows; Caso contrário, FALSE.

## <a name="a-namembdontusewinxptheme-cmfcbuttonmbdontusewinxptheme"></a><a name="m_bDontUseWinXPTheme"/> CMFCButton::m_bDontUseWinXPTheme

Especifica se deve usar temas do Windows XP, quando o botão de desenho.

```
BOOL m_bDontUseWinXPTheme;
```

##  <a name="m_bdrawfocus"></a>  CMFCButton::m_bDrawFocus

Indica se é necessário desenhar um retângulo de foco ao redor de um botão.

```
BOOL m_bDrawFocus;
```

### <a name="remarks"></a>Comentários

Defina o `m_bDrawFocus` membro como TRUE para especificar que a estrutura será desenhar um retângulo de foco ao redor do texto do botão e se o botão recebe o foco da imagem.

O `CMFCButton` construtor inicializa esse membro como TRUE.

##  <a name="m_bGrayDisabled"></a>  CMFCButton::m_bGrayDisabled

Quando for verdadeiro, permite que um botão desabilitado a ser desenhado como acinzentado.

```
BOOL m_bGrayDisabled;
```

##  <a name="m_bhighlightchecked"></a>  CMFCButton::m_bHighlightChecked

Indica se é para realçar um botão de estilo BS_CHECKBOX quando o cursor passa sobre ele.

```
BOOL m_bHighlightChecked;
```

### <a name="remarks"></a>Comentários

Defina o `m_bHighlightChecked` membro como TRUE para especificar que o framework irá realçar um botão de estilo BS_CHECKBOX quando o mouse passa sobre ele.

##  <a name="m_bResponseOnButtonDown"></a> CMFCButton::m_bResponseOnButtonDown

Indica se deve responder a botão para baixo de eventos.

```
BOOL m_bResponseOnButtonDown;
```

##  <a name="m_brightimage"></a>  CMFCButton::m_bRightImage

Indica se deve exibir uma imagem à direita do botão.

```
BOOL m_bRightImage;
```

##  <a name="m_bTopImage"></a>  CMFCButton::m_bTopImage](#m_bTopImage)

Indica se a imagem está sobre o botão.

```
BOOL m_bTopImage;
```

### <a name="remarks"></a>Comentários

Defina o `m_bRightImage` membro como TRUE para especificar que o framework exibirá a imagem do botão à direita do rótulo de texto do botão.

##  <a name="m_btransparent"></a>  CMFCButton::m_bTransparent

Indica se o botão é transparente.

```
BOOL m_bTransparent;
```

### <a name="remarks"></a>Comentários

Defina o `m_bTransparent` membro como TRUE para especificar que o framework fará o botão transparente. O `CMFCButton` construtor inicializa esse membro como FALSE.

##  <a name="m_nalignstyle"></a>  CMFCButton::m_nAlignStyle

Especifica o alinhamento do texto do botão.

```
AlignStyle m_nAlignStyle;
```

### <a name="remarks"></a>Comentários

Use um dos seguintes `CMFCButton::AlignStyle` valores de enumeração para especificar o alinhamento do texto do botão:

|Valor|Descrição|
|-----------|-----------------|
|ALIGN_CENTER|(Padrão) Alinha o texto do botão para o centro do botão.|
|ALIGN_LEFT|Alinha o texto do botão à esquerda do botão.|
|ALIGN_RIGHT|Alinha o texto do botão à direita do botão.|

O `CMFCButton` construtor inicializa este membro para ALIGN_CENTER.

##  <a name="m_bWasDblClk"></a>  CMFCButton::m_bWasDblClk](#m_bWasDblClk)|

Indica se o último clique o evento foi um clique duplo. |

```
BOOL m_bWasDblClk;
```

##  <a name="m_nflatstyle"></a>  CMFCButton::m_nFlatStyle

Especifica o estilo do botão, como sem borda, simples, simples de ponto e vírgula ou 3D.

```
FlatStyle  m_nFlatStyle;
```

### <a name="remarks"></a>Comentários

A seguinte tabela lista o `CMFCButton::m_nFlatStyle` valores de enumeração que especificam a aparência de um botão.

|Valor|Descrição|
|-----------|-----------------|
|BUTTONSTYLE_3D|(Padrão) O botão parece ter lados altos, tridimensionais. Quando o botão é clicado, é exibido no botão seja pressionado em um recuo de profundidade.|
|BUTTONSTYLE_FLAT|Quando não fará uma pausa o mouse sobre o botão, o botão parece ser bidimensional e não tem lados gerados. Quando o mouse passa sobre o botão, o botão parece ter lados baixos, tridimensionais. Quando o botão é clicado, é exibido no botão seja pressionado em um recuo superficial.|
|BUTTONSTYLE_SEMIFLAT|O botão parece ter lados baixos, tridimensionais. Quando o botão é clicado, é exibido no botão seja pressionado em um recuo de profundidade.|
|BUTTONSTYLE_NOBORDERS|O botão não tiver gerado lados e sempre aparece bidimensional. O botão não parece ser pressionado em um recuo quando ele for clicado.|

O `CMFCButton` construtor inicializa este membro para BUTTONSTYLE_3D.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir os valores da `m_nFlatStyle` variável de membro no `CMFCButton` classe. Este exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#29](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_5.cpp)]

##  <a name="ondraw"></a>  CMFCButton::OnDraw

Chamado pelo framework para desenhar um botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rect*<br/>
[in] Uma referência a um retângulo que delimita o botão.

*uiState*<br/>
[in] O estado atual do botão. Para obter mais informações, consulte o `itemState` membro a [estrutura DRAWITEMSTRUCT](/windows/desktop/api/winuser/ns-winuser-tagdrawitemstruct) tópico.

### <a name="remarks"></a>Comentários

Substitua este método para usar seu próprio código para desenhar um botão.

##  <a name="ondrawborder"></a>  CMFCButton::OnDrawBorder

Chamado pelo framework para desenhar a borda de um botão.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect& rectClient,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[in] Uma referência a um retângulo que delimita o botão.

*uiState*<br/>
[in] O estado atual do botão. Para obter mais informações, consulte o `itemState` membro a [estrutura DRAWITEMSTRUCT](/windows/desktop/api/winuser/ns-winuser-tagdrawitemstruct) tópico.

### <a name="remarks"></a>Comentários

Substitua este método para usar seu próprio código para desenhar a borda.

##  <a name="ondrawfocusrect"></a>  CMFCButton::OnDrawFocusRect

Chamado pelo framework para desenhar o retângulo de foco para um botão.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[in] Uma referência a um retângulo que delimita o botão.

### <a name="remarks"></a>Comentários

Substitua este método para usar seu próprio código para desenhar o retângulo de foco.

##  <a name="ondrawtext"></a>  CMFCButton::OnDrawText

Chamado pelo framework para desenhar o texto do botão.

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
[in] Um ponteiro para um contexto de dispositivo.

*rect*<br/>
[in] Uma referência a um retângulo que delimita o botão.

*strText*<br/>
[in] O texto a ser desenhado.

*uiDTFlags*<br/>
[in] Sinalizadores que especificam como formatar o texto. Para obter mais informações, consulte o *nFormat* parâmetro do [CDC::DrawText](../../mfc/reference/cdc-class.md#drawtext) método.

*uiState*<br/>
[in] Reservado.

### <a name="remarks"></a>Comentários

Substitua este método para usar seu próprio código para desenhar o texto do botão.

##  <a name="onfillbackground"></a>  CMFCButton::OnFillBackground

Chamado pelo framework para desenhar a tela de fundo do texto do botão.

```
virtual void OnFillBackground(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[in] Uma referência a um retângulo que delimita o botão.

### <a name="remarks"></a>Comentários

Substitua este método para usar seu próprio código para desenhar a tela de fundo de um botão.

##  <a name="selectfont"></a>  CMFCButton::SelectFont

Recupera a fonte que está associada com o contexto de dispositivo especificado.

```
virtual CFont* SelectFont(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

### <a name="return-value"></a>Valor de retorno

Substitua este método para usar seu próprio código para recuperar a fonte.

### <a name="remarks"></a>Comentários

##  <a name="setautorepeatmode"></a>  CMFCButton::SetAutorepeatMode

Define um botão para o modo de repetição automática.

```
void SetAutorepeatMode(int nTimeDelay=500);
```

### <a name="parameters"></a>Parâmetros

*nTimeDelay*<br/>
[in] Um número não negativo que especifica o intervalo entre as mensagens enviadas para a janela pai. O intervalo é medido em milissegundos e seu valor padrão é 500 milissegundos. Especifique zero para desabilitar o modo de mensagem de repetição automática.

### <a name="remarks"></a>Comentários

Esse método faz com que o botão Enviar constantemente mensagens WM_COMMAND para a janela pai até que o botão é liberado, ou o *nTimeDelay* parâmetro for definido como zero.

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
[in] Identificador do ícone que contém o bitmap e a máscara para a nova imagem.

*bAutoDestroy*<br/>
[in] TRUE para especificar que os recursos de bitmap ser destruído automaticamente. Caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
[in] Identificador para o ícone que contém a imagem para o estado selecionado.

*hBitmap*<br/>
[in] Identificador para o bitmap que contém a imagem para o estado não selecionado.

*hBitmapHot*<br/>
[in] Identificador para o bitmap que contém a imagem para o estado selecionado.

*bMap3dColors*<br/>
[in] Especifica uma cor transparente para o plano de fundo do botão; ou seja, a face do botão. TRUE para usar o valor de cor RGB (192, 192, 192); FALSE para usar o valor de cor definido pelo `AFX_GLOBAL_DATA::clrBtnFace`.

*uiBmpResId*<br/>
[in] ID de recurso para a imagem não selecionado.

*uiBmpHotResId*<br/>
[in] ID de recurso para a imagem selecionada.

*hIconDisabled*<br/>
[in] Identificador para o ícone para a imagem desabilitado.

*hBitmapDisabled*<br/>
[in] Identificador para o bitmap que contém a imagem desabilitada.

*uiBmpDsblResID*<br/>
[in] ID do recurso de bitmap desabilitado.

*bAlphaBlend*<br/>
[in] True para usar imagens de 32 bits apenas que usam o canal alfa. FALSE, para não usar imagens de canal alfa apenas. O padrão é FALSE.

### <a name="remarks"></a>Comentários

##  <a name="setfacecolor"></a>  CMFCButton::SetFaceColor

Define a cor de plano de fundo para o texto do botão.

```
void SetFaceColor(
    COLORREF crFace,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*crFace*<br/>
[in] Um valor de cor RGB.

*bRedraw*<br/>
[in] TRUE para redesenhar a tela imediatamente; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método para definir uma nova cor de preenchimento para a tela de fundo do botão (face). Observe que o plano de fundo não será preenchida quando o [CMFCButton::m_bTransparent](#m_btransparent) variável de membro é TRUE.

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
[in] Identificador do ícone que contém o bitmap e a máscara para a nova imagem.

*bAutoDestroy*<br/>
[in] TRUE para especificar que os recursos de bitmap ser destruído automaticamente. Caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
[in] Identificador para o ícone que contém a imagem para o estado selecionado.

*hBitmap*<br/>
[in] Identificador para o bitmap que contém a imagem para o estado não selecionado.

*hBitmapHot*<br/>
[in] Identificador para o bitmap que contém a imagem para o estado selecionado.

*uiBmpResId*<br/>
[in] ID de recurso para a imagem não selecionado.

*uiBmpHotResId*<br/>
[in] ID de recurso para a imagem selecionada.

*bMap3dColors*<br/>
[in] Especifica uma cor transparente para o plano de fundo do botão; ou seja, a face do botão. TRUE para usar o valor de cor RGB (192, 192, 192); FALSE para usar o valor de cor definido pelo `AFX_GLOBAL_DATA::clrBtnFace`.

*hIconDisabled*<br/>
[in] Identificador para o ícone para a imagem desabilitado.

*hBitmapDisabled*<br/>
[in] Identificador para o bitmap que contém a imagem desabilitada.

*uiBmpDsblResID*<br/>
[in] ID do recurso de bitmap desabilitado.

*bAlphaBlend*<br/>
[in] True para usar imagens de 32 bits apenas que usam o canal alfa. FALSE, para não usar imagens de canal alfa apenas. O padrão é FALSE.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar as várias versões dos `SetImage` método no `CMFCButton` classe. O exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#31](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_2.cpp)]

##  <a name="setmousecursor"></a>  CMFCButton::SetMouseCursor

Define a imagem do cursor.

```
void SetMouseCursor(HCURSOR hcursor);
```

### <a name="parameters"></a>Parâmetros

*hcursor*<br/>
[in] O identificador de um cursor.

### <a name="remarks"></a>Comentários

Use esse método para associar uma imagem do cursor, como o cursor de mão, com o botão. O cursor é carregado dos recursos do aplicativo.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `SetMouseCursor` método no `CMFCButton` classe. O exemplo faz parte do código na [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#30](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_6.cpp)]

##  <a name="setmousecursorhand"></a>  CMFCButton::SetMouseCursorHand

Define o cursor para a imagem de uma mão.

```
void SetMouseCursorHand();
```

### <a name="remarks"></a>Comentários

Use esse método para associar a imagem do cursor de mão com o botão. O cursor é carregado dos recursos do aplicativo.

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
[in] Um dos identificadores de imagem do botão que é definido no `CMenuImage::IMAGES_IDS` enumeração. Os valores de imagem especificam imagens como setas, pinos e botões de opção.

*state*<br/>
[in] Um dos identificadores de estado de imagem de botão que é definido no `CMenuImages::IMAGE_STATE` enumeração. Os estados de imagem especificam cores do botão como cinza de preto, cinza, luz cinza, branco e escuro. O valor padrão é `CMenuImages::ImageBlack`.

*idDisabled*<br/>
[in] Um dos identificadores de imagem do botão que é definido no `CMenuImage::IMAGES_IDS` enumeração. A imagem indica que o botão está desabilitado. O valor padrão é a primeira imagem do botão ( `CMenuImages::IdArrowDown`).

### <a name="remarks"></a>Comentários

##  <a name="settextcolor"></a>  CMFCButton::SetTextColor

Define a cor do texto do botão para um botão que não está selecionado.

```
void SetTextColor(COLORREF clrText);
```

### <a name="parameters"></a>Parâmetros

*clrText*<br/>
[in] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="settexthotcolor"></a>  CMFCButton::SetTextHotColor

Define a cor do texto do botão para um botão que está selecionado.

```
void SetTextHotColor(COLORREF clrTextHot);
```

### <a name="parameters"></a>Parâmetros

*clrTextHot*<br/>
[in] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="settooltip"></a>  CMFCButton::SetTooltip

Associa uma dica de ferramenta com um botão.

```
void SetTooltip(LPCTSTR lpszToolTipText);
```

### <a name="parameters"></a>Parâmetros

*lpszToolTipText*<br/>
[in] Ponteiro para o texto da dica de ferramenta. Especifique NULL para desativar a dica de ferramenta.

### <a name="remarks"></a>Comentários

##  <a name="sizetocontent"></a>  CMFCButton::SizeToContent

Redimensiona um botão para conter o texto de botão e a imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
[in] TRUE para calcular, mas não alterar, o novo tamanho do botão; FALSE para alterar o tamanho do botão. O padrão é FALSE.

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
