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
ms.openlocfilehash: 5434801969a55387a5b5555c9a4ade22f1969e7d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367785"
---
# <a name="cmfcbutton-class"></a>Classe CMFCButton

A `CMFCButton` classe adiciona funcionalidade à classe [CButton,](../../mfc/reference/cbutton-class.md) como alinhar texto do botão, combinar texto de botão e uma imagem, selecionar um cursor e especificar uma ponta de ferramenta.

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
|[CMFCButton::Limpeza](#cleanup)|Redefine variáveis internas e libera recursos alocados, como imagens, bitmaps e ícones.|
|`CMFCButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCButton::DrawItem`|Chamado pela estrutura quando um aspecto visual de um botão desenhado pelo proprietário foi alterado. (Substitui [cbutton::DrawItem](../../mfc/reference/cbutton-class.md#drawitem).)|
|[CMFCButton::HabilitarFullTexttooltip](#enablefulltexttooltip)|Especifica se é para exibir o texto completo de uma dica de ferramenta em uma grande janela de dica de ferramenta ou uma versão truncada do texto em uma pequena janela de dica de ferramenta.|
|[CMFCButton::Habilitarmenufonte](#enablemenufont)|Especifica se a fonte de texto do botão é a mesma da fonte do menu do aplicativo.|
|[CMFCButton::AtivarWindowsTheming](#enablewindowstheming)|Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCButton::GetToolTipCtrl](#gettooltipctrl)|Retorna uma referência ao controle de ponta de ferramenta subjacente.|
|[CMFCButton::IsAutoCheck](#isautocheck)|Indica se uma caixa de seleção ou um botão de rádio é um botão automático.|
|[CMFCButton::IsAutoRepeatCommandMode](#isautorepeatcommandmode)|Indica se um botão está configurado para o modo de repetição automática.|
|[CMFCButton::IsCheckBox](#ischeckbox)|Indica se um botão é um botão de caixa de seleção.|
|[CMFCButton::IsChecked](#ischecked)|Indica se o botão atual é verificado.|
|[CMFCButton::Ishighlighted](#ishighlighted)|Indica se um botão está destacado.|
|[BOTÃO CMFC::Ispressed](#ispressed)|Indica se um botão é pressionado e destacado.|
|[CMFCButton::IsPushed](#ispushed)|Indica se um botão é pressionado.|
|[CMFCButton::IsRadioButton](#isradiobutton)|Indica se um botão é um botão de rádio.|
|[CMFCButton::IsWindowsThemingAtivado](#iswindowsthemingenabled)|Indica se o estilo da borda do botão corresponde ao tema atual do Windows.|
|`CMFCButton::OnDrawParentBackground`|Desenha o plano de fundo do pai de um botão na área especificada. [(SubstituiAFX_GLOBAL_DATA::DrawParentBackground](../../mfc/reference/afx-global-data-structure.md)|
|`CMFCButton::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. (Substitui [cwnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCButton::SetAutorepeatMode](#setautorepeatmode)|Define um botão para o modo de repetição automática.|
|[CMFCButton::SetCheckImage](#setcheckedimage)|Define a imagem como um botão verificado.|
|[CMFCButton::SetFaceColor](#setfacecolor)|Define a cor de fundo do texto do botão.|
|[CMFCButton::SetImage](#setimage)|Define a imagem como um botão.|
|[CMFCButton::SetMouseCursor](#setmousecursor)|Define a imagem do cursor.|
|[CMFCButton::SetMouseCursorHand](#setmousecursorhand)|Define o cursor à imagem de uma mão.|
|[CMFCButton::SetStdImage](#setstdimage)|Usa `CMenuImages` um objeto para definir a imagem do botão.|
|[CMFCButton::SetTextColor](#settextcolor)|Define a cor do texto do botão para um botão que não está selecionado.|
|[CMFCButton::SetTextHotColor](#settexthotcolor)|Define a cor do texto do botão para um botão selecionado.|
|[CMFCButton::SetTooltip](#settooltip)|Associa uma dica de ferramenta com um botão.|
|[BOTÃO CMFC::SizeToContent](#sizetocontent)|Redimensiona um botão para conter o texto e a imagem do botão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton::OnDraw](#ondraw)|Chamado pela estrutura para desenhar um botão.|
|[CMFCButton::OnDrawBorder](#ondrawborder)|Chamado pela estrutura para desenhar a borda de um botão.|
|[CMFCButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pela estrutura para desenhar o retângulo de foco para um botão.|
|[CMFCButton::OnDrawText](#ondrawtext)|Chamado pelo framework para desenhar o texto do botão.|
|[CMFCButton::OnFillBackground](#onfillbackground)|Chamado pelo framework para desenhar o plano de fundo do texto do botão.|
|[CMFCButton::SelectFont](#selectfont)|Recupera a fonte associada ao contexto do dispositivo especificado.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCButton::m_nAlignStyle](#m_nalignstyle)|Especifica o alinhamento do texto do botão.|
|[CMFCButton::m_bDontUseWinXPTheme](#m_bDontUseWinXPTheme)|Especifica se deve usar os temas do Windows XP.|
|[CMFCButton::m_bDrawFocus](#m_bdrawfocus)|Indica se deve desenhar um retângulo de foco em torno de um botão.|
|[CMFCButton::m_nFlatStyle](#m_nflatstyle)|Especifica o estilo do botão, como sem bordas, plano, semi-plano ou 3D.|
|[CMFCButton::m_bGrayDisabled](#m_bGrayDisabled)|Quando TRUE, habilita que um botão desativado seja desenhado como cinza..|
|[CMFCButton::m_bHighlightChecked](#m_bhighlightchecked)|Indica se deve destacar um botão de estilo BS_CHECKBOX quando o cursor paira sobre ele.|
|[CMFCButton::m_bResponseOnButtonDown](#m_bResponseOnButtonDown)|Indica se deve responder aos eventos de botão para baixo.|
|[CMFCButton::m_bRightImage](#m_brightimage)|Indica se é para exibir uma imagem no lado direito do botão.|
|[CMFCButton::m_bTopImage](#m_bTopImage)| Indica se a imagem está em cima do botão.|
|[CMFCButton::m_bTransparent](#m_btransparent)|Indica se o botão é transparente.|
|[CMFCButton::m_bWasDblClk](#m_bWasDblClk)| Indica se o último evento de clique foi um clique duplo.|

## <a name="remarks"></a>Comentários

Outros tipos de botões são `CMFCButton` derivados da classe, como a classe [CMFCURLLinkButton,](../../mfc/reference/cmfclinkctrl-class.md) que suporta hiperlinks, e a `CMFCColorButton` classe, que suporta uma caixa de diálogo de seleção de cores.

O estilo `CMFCButton` de um objeto pode ser *3D,* *plano,* *semi-plano* ou *sem borda.* O texto do botão pode ser alinhado à esquerda, superior ou centro de um botão. No tempo de execução, você pode controlar se o botão exibe texto, uma imagem ou texto e uma imagem. Você também pode especificar que uma imagem específica do cursor será exibida quando o cursor paira sobre um botão.

Crie um controle de botão diretamente em seu código ou usando a ferramenta **MFC Class Wizard** e um modelo de caixa de diálogo. Se você criar um controle `CMFCButton` de botão diretamente, adicione uma variável `Create` ao seu `CMFCButton` aplicativo e, em seguida, chame o construtor e os métodos do objeto. Se você usar o **Assistente de Classe MFC,** adicione uma `CButton` variável ao `CButton` `CMFCButton`seu aplicativo e, em seguida, altere o tipo da variável de .

Para lidar com mensagens de notificação em um aplicativo de caixa de diálogo, adicione uma entrada de mapa de mensagem e um manipulador de eventos para cada notificação. As notificações `CMFCButton` enviadas por um objeto são `CButton` as mesmas enviadas por um objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar as propriedades do `CMFCButton` botão usando vários métodos na classe. O exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#31](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_2.cpp)]
[!code-cpp[NVC_MFC_NewControls#32](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_3.cpp)]
[!code-cpp[NVC_MFC_NewControls#33](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_4.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfcbutton](../../mfc/reference/cmfcbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbutton.h

## <a name="cmfcbuttoncleanup"></a><a name="cleanup"></a>CMFCButton::Limpeza

Redefine variáveis internas e libera recursos alocados, como imagens, bitmaps e ícones.

```
virtual void CleanUp();
```

## <a name="cmfcbuttonenablefulltexttooltip"></a><a name="enablefulltexttooltip"></a>CMFCButton::HabilitarFullTexttooltip

Especifica se é para exibir o texto completo de uma dica de ferramenta em uma grande janela de dica de ferramenta ou uma versão truncada do texto em uma pequena janela de dica de ferramenta.

```
void EnableFullTextTooltip(BOOL bOn=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
[em] VERDADEIRO para exibir todo o texto; FALSO para exibir texto truncado.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonenablemenufont"></a><a name="enablemenufont"></a>CMFCButton::Habilitarmenufonte

Especifica se a fonte de texto do botão é a mesma da fonte do menu do aplicativo.

```
void EnableMenuFont(
    BOOL bOn=TRUE,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
[em] TRUE para usar a fonte do menu do aplicativo como fonte de texto do botão; FALSO para usar a fonte do sistema. O padrão é TRUE.

*Bredraw*<br/>
[em] TRUE para redesenhar imediatamente a tela; caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Se você não usar este método para especificar a fonte de texto do botão, você pode especificar a fonte com o método [CWnd::SetFont.](../../mfc/reference/cwnd-class.md#setfont) Se você não especificar uma fonte, a estrutura definirá uma fonte padrão.

## <a name="cmfcbuttonenablewindowstheming"></a><a name="enablewindowstheming"></a>CMFCButton::AtivarWindowsTheming

Especifica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static void EnableWindowsTheming(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] É VERDADE usar o tema atual do Windows para desenhar bordas de botão; FALSO para não usar o tema do Windows. O padrão é TRUE.

### <a name="remarks"></a>Comentários

Este método afeta todos os botões da sua `CMFCButton` aplicação que são derivados da classe.

## <a name="cmfcbuttongettooltipctrl"></a><a name="gettooltipctrl"></a>CMFCButton::GetToolTipCtrl

Retorna uma referência ao controle de ponta de ferramenta subjacente.

```
CToolTipCtrl& GetToolTipCtrl();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao controle de ponta de ferramenta subjacente.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonisautocheck"></a><a name="isautocheck"></a>CMFCButton::IsAutoCheck

Indica se uma caixa de seleção ou um botão de rádio é um botão automático.

```
BOOL IsAutoCheck() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o botão tiver estilo BS_AUTOCHECKBOX ou BS_AUTORADIOBUTTON; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonisautorepeatcommandmode"></a><a name="isautorepeatcommandmode"></a>CMFCButton::IsAutoRepeatCommandMode

Indica se um botão está configurado para o modo de repetição automática.

```
BOOL IsAutorepeatCommandMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão estiver configurado para o modo de repetição automática; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o método [CMFCButton::SetAutorepeatMode](#setautorepeatmode) para definir um botão para o modo de repetição automática.

## <a name="cmfcbuttonischeckbox"></a><a name="ischeckbox"></a>CMFCButton::IsCheckBox

Indica se um botão é um botão de caixa de seleção.

```
BOOL IsCheckBox() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o botão tiver BS_CHECKBOX ou estilo BS_AUTOCHECKBOX; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonischecked"></a><a name="ischecked"></a>CMFCButton::IsChecked

Indica se o botão atual é verificado.

```
BOOL IsChecked() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão atual for verificado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A estrutura usa diferentes maneiras de indicar que diferentes tipos de botões são verificados. Por exemplo, um botão de rádio é verificado quando contém um dono; uma caixa de seleção é verificada quando contém um **X**.

## <a name="cmfcbuttonishighlighted"></a><a name="ishighlighted"></a>CMFCButton::Ishighlighted

Indica se um botão está destacado.

```
BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão for destacado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um botão fica destacado quando o mouse paira sobre o botão.

## <a name="cmfcbuttonispressed"></a><a name="ispressed"></a>BOTÃO CMFC::Ispressed

Indica se um botão é pressionado e destacado.

```
BOOL IsPressed() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão for pressionado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonispushed"></a><a name="ispushed"></a>CMFCButton::IsPushed

Indica se um botão é pressionado.

```
BOOL IsPushed() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão for pressionado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonisradiobutton"></a><a name="isradiobutton"></a>CMFCButton::IsRadioButton

Indica se um botão é um botão de rádio.

```
BOOL IsRadioButton() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o estilo do botão for BS_RADIOBUTTON ou BS_AUTORADIOBUTTON; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttoniswindowsthemingenabled"></a><a name="iswindowsthemingenabled"></a>CMFCButton::IsWindowsThemingAtivado

Indica se o estilo da borda do botão corresponde ao tema atual do Windows.

```
static BOOL IsWindowsThemingEnabled();
```

### <a name="return-value"></a>Valor retornado

TRUE se o estilo da borda do botão corresponder ao tema atual do Windows; caso contrário, FALSE.

## <a name="cmfcbuttonm_bdontusewinxptheme"></a><a name="m_bDontUseWinXPTheme"/>CMFCButton::m_bDontUseWinXPTheme

Especifica se deve usar os temas do Windows XP ao desenhar o botão.

```
BOOL m_bDontUseWinXPTheme;
```

## <a name="cmfcbuttonm_bdrawfocus"></a><a name="m_bdrawfocus"></a>CMFCButton::m_bDrawFocus

Indica se deve desenhar um retângulo de foco em torno de um botão.

```
BOOL m_bDrawFocus;
```

### <a name="remarks"></a>Comentários

Defina `m_bDrawFocus` o membro como TRUE para especificar que a estrutura desenhará um retângulo de foco em torno do texto e da imagem do botão se o botão receber foco.

O `CMFCButton` construtor inicializa este membro para TRUE.

## <a name="cmfcbuttonm_bgraydisabled"></a><a name="m_bGrayDisabled"></a>CMFCButton::m_bGrayDisabled

Quando TRUE, habilita que um botão desativado seja desenhado como cinza..

```
BOOL m_bGrayDisabled;
```

## <a name="cmfcbuttonm_bhighlightchecked"></a><a name="m_bhighlightchecked"></a>CMFCButton::m_bHighlightChecked

Indica se deve destacar um botão de estilo BS_CHECKBOX quando o cursor paira sobre ele.

```
BOOL m_bHighlightChecked;
```

### <a name="remarks"></a>Comentários

Defina `m_bHighlightChecked` o membro como TRUE para especificar que a estrutura destacará um botão de estilo BS_CHECKBOX quando o mouse passar o mouse sobre ele.

## <a name="cmfcbuttonm_bresponseonbuttondown"></a><a name="m_bResponseOnButtonDown"></a>CMFCButton::m_bResponseOnButtonDown

Indica se deve responder aos eventos de botão para baixo.

```
BOOL m_bResponseOnButtonDown;
```

## <a name="cmfcbuttonm_brightimage"></a><a name="m_brightimage"></a>CMFCButton::m_bRightImage

Indica se é para exibir uma imagem no lado direito do botão.

```
BOOL m_bRightImage;
```

## <a name="cmfcbuttonm_btopimagem_btopimage"></a><a name="m_bTopImage"></a>CMFCButton::m_bTopImage](#m_bTopImage)

Indica se a imagem está em cima do botão.

```
BOOL m_bTopImage;
```

### <a name="remarks"></a>Comentários

Defina `m_bRightImage` o membro como TRUE para especificar que a estrutura exibirá a imagem do botão à direita do rótulo de texto do botão.

## <a name="cmfcbuttonm_btransparent"></a><a name="m_btransparent"></a>CMFCButton::m_bTransparent

Indica se o botão é transparente.

```
BOOL m_bTransparent;
```

### <a name="remarks"></a>Comentários

Defina `m_bTransparent` o membro como TRUE para especificar que a estrutura tornará o botão transparente. O `CMFCButton` construtor inicializa este membro para FALSE.

## <a name="cmfcbuttonm_nalignstyle"></a><a name="m_nalignstyle"></a>CMFCButton::m_nAlignStyle

Especifica o alinhamento do texto do botão.

```
AlignStyle m_nAlignStyle;
```

### <a name="remarks"></a>Comentários

Use um dos `CMFCButton::AlignStyle` seguintes valores de enumeração para especificar o alinhamento do texto do botão:

|Valor|Descrição|
|-----------|-----------------|
|ALIGN_CENTER|(Padrão) Alinha o texto do botão ao centro do botão.|
|ALIGN_LEFT|Alinha o texto do botão ao lado esquerdo do botão.|
|ALIGN_RIGHT|Alinha o texto do botão ao lado direito do botão.|

A `CMFCButton` construtora inicia esse membro para ALIGN_CENTER.

## <a name="cmfcbuttonm_bwasdblclkm_bwasdblclk"></a><a name="m_bWasDblClk"></a>CMFCButton::m_bWasDblClk](#m_bWasDblClk)|

Indica se o último evento de clique foi um clique duplo.|

```
BOOL m_bWasDblClk;
```

## <a name="cmfcbuttonm_nflatstyle"></a><a name="m_nflatstyle"></a>CMFCButton::m_nFlatStyle

Especifica o estilo do botão, como sem bordas, plano, semi-plano ou 3D.

```
FlatStyle  m_nFlatStyle;
```

### <a name="remarks"></a>Comentários

A tabela a `CMFCButton::m_nFlatStyle` seguir lista os valores de enumeração que especificam a aparência de um botão.

|Valor|Descrição|
|-----------|-----------------|
|BUTTONSTYLE_3D|(Padrão) O botão parece ter lados tridimensionais altos. Quando o botão é clicado, o botão parece ser pressionado em um recuo profundo.|
|BUTTONSTYLE_FLAT|Quando o mouse não pausa sobre o botão, o botão parece ser bidimensional e não tem lados elevados. Quando o mouse faz uma pausa sobre o botão, o botão parece ter lados tridimensionais baixos. Quando o botão é clicado, o botão parece ser pressionado em um recuo raso.|
|BUTTONSTYLE_SEMIFLAT|O botão parece ter lados tridimensionais baixos. Quando o botão é clicado, o botão parece ser pressionado em um recuo profundo.|
|BUTTONSTYLE_NOBORDERS|O botão não tem lados elevados e sempre aparece bidimensional. O botão não parece ser pressionado em um recuo quando é clicado.|

A `CMFCButton` construtora inicia esse membro para BUTTONSTYLE_3D.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `m_nFlatStyle` definir os `CMFCButton` valores da variável membro na classe. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#29](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_5.cpp)]

## <a name="cmfcbuttonondraw"></a><a name="ondraw"></a>CMFCButton::OnDraw

Chamado pela estrutura para desenhar um botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Uma referência a um retângulo que limita o botão.

*uiState*<br/>
[em] O estado atual do botão. Para obter mais `itemState` informações, consulte o membro do tópico [DRAWITSTRUTRUCT Structure.](/windows/win32/api/winuser/ns-winuser-drawitemstruct)

### <a name="remarks"></a>Comentários

Anular este método para usar seu próprio código para desenhar um botão.

## <a name="cmfcbuttonondrawborder"></a><a name="ondrawborder"></a>CMFCButton::OnDrawBorder

Chamado pela estrutura para desenhar a borda de um botão.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect& rectClient,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[em] Uma referência a um retângulo que limita o botão.

*uiState*<br/>
[em] O estado atual do botão. Para obter mais `itemState` informações, consulte o membro do tópico [DRAWITSTRUTRUCT Structure.](/windows/win32/api/winuser/ns-winuser-drawitemstruct)

### <a name="remarks"></a>Comentários

Anular este método para usar seu próprio código para desenhar a fronteira.

## <a name="cmfcbuttonondrawfocusrect"></a><a name="ondrawfocusrect"></a>CMFCButton::OnDrawFocusRect

Chamado pela estrutura para desenhar o retângulo de foco para um botão.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[em] Uma referência a um retângulo que limita o botão.

### <a name="remarks"></a>Comentários

Anular este método para usar seu próprio código para desenhar o retângulo de foco.

## <a name="cmfcbuttonondrawtext"></a><a name="ondrawtext"></a>CMFCButton::OnDrawText

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
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Uma referência a um retângulo que limita o botão.

*strText*<br/>
[em] O texto para desenhar.

*uiDTFlags*<br/>
[em] Sinalizadores que especificam como formatar o texto. Para obter mais informações, consulte o parâmetro *nFormat* do método [CDC::DrawText.](../../mfc/reference/cdc-class.md#drawtext)

*uiState*<br/>
[in] Reservado.

### <a name="remarks"></a>Comentários

Anular este método para usar seu próprio código para desenhar o texto do botão.

## <a name="cmfcbuttononfillbackground"></a><a name="onfillbackground"></a>CMFCButton::OnFillBackground

Chamado pelo framework para desenhar o plano de fundo do texto do botão.

```
virtual void OnFillBackground(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[em] Uma referência a um retângulo que limita o botão.

### <a name="remarks"></a>Comentários

Anular este método para usar seu próprio código para desenhar o plano de fundo de um botão.

## <a name="cmfcbuttonselectfont"></a><a name="selectfont"></a>CMFCButton::SelectFont

Recupera a fonte associada ao contexto do dispositivo especificado.

```
virtual CFont* SelectFont(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

### <a name="return-value"></a>Valor retornado

Anular este método para usar seu próprio código para recuperar a fonte.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsetautorepeatmode"></a><a name="setautorepeatmode"></a>CMFCButton::SetAutorepeatMode

Define um botão para o modo de repetição automática.

```
void SetAutorepeatMode(int nTimeDelay=500);
```

### <a name="parameters"></a>Parâmetros

*nTimeDelay*<br/>
[em] Um número não negativo que especifica o intervalo entre as mensagens enviadas para a janela pai. O intervalo é medido em milissegundos e seu valor padrão é de 500 milissegundos. Especifique zero para desativar o modo de mensagem de repetição automática.

### <a name="remarks"></a>Comentários

Esse método faz com que o botão envie constantemente mensagens WM_COMMAND para a janela pai até que o botão seja liberado ou o parâmetro *nTimeDelay* seja definido como zero.

## <a name="cmfcbuttonsetcheckedimage"></a><a name="setcheckedimage"></a>CMFCButton::SetCheckImage

Define a imagem como um botão verificado.

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

*Hicon*<br/>
[em] Manuseie o ícone que contém o bitmap e a máscara para a nova imagem.

*bAutoDestroy*<br/>
[em] TRUE para especificar que os recursos do bitmap serão destruídos automaticamente; caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
[em] Manuseie o ícone que contém a imagem para o estado selecionado.

*Hbitmap*<br/>
[em] Manuseie o bitmap que contém a imagem para o estado não selecionado.

*hBitmapHot*<br/>
[em] Manuseie o bitmap que contém a imagem para o estado selecionado.

*bMap3dCores*<br/>
[em] Especifica uma cor transparente para o plano de fundo do botão; ou seja, o rosto do botão. VERDADEIRO para usar o valor de cor RGB (192, 192, 192); FALSO para usar o `AFX_GLOBAL_DATA::clrBtnFace`valor de cor definido por .

*uiBmpResId*<br/>
[em] ID de recurso para a imagem não selecionada.

*uiBmpHotResId*<br/>
[em] ID de recurso para a imagem selecionada.

*hIconDisabled*<br/>
[em] Manuseie o ícone para a imagem desativada.

*hBitmapDesativado*<br/>
[em] Manuseie o bitmap que contém a imagem desativada.

*uiBmpDsblResID*<br/>
[em] ID de recursos do bitmap desativado.

*bAlphaBlend*<br/>
[em] TRUE usar apenas imagens de 32 bits que usam o canal alfa; FALSE, para não usar apenas imagens de canal alfa. O padrão é FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsetfacecolor"></a><a name="setfacecolor"></a>CMFCButton::SetFaceColor

Define a cor de fundo do texto do botão.

```
void SetFaceColor(
    COLORREF crFace,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*crFace*<br/>
[em] Um valor de cor RGB.

*Bredraw*<br/>
[em] TRUE para redesenhar a tela imediatamente; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método para definir uma nova cor de preenchimento para o fundo do botão (face). Observe que o plano de fundo não está preenchido quando a variável de membro [CMFCButton::m_bTransparent](#m_btransparent) é TRUE.

## <a name="cmfcbuttonsetimage"></a><a name="setimage"></a>CMFCButton::SetImage

Define a imagem como um botão.

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

*Hicon*<br/>
[em] Manuseie o ícone que contém o bitmap e a máscara para a nova imagem.

*bAutoDestroy*<br/>
[em] TRUE para especificar que os recursos do bitmap serão destruídos automaticamente; caso contrário, FALSE. O padrão é TRUE.

*hIconHot*<br/>
[em] Manuseie o ícone que contém a imagem para o estado selecionado.

*Hbitmap*<br/>
[em] Manuseie o bitmap que contém a imagem para o estado não selecionado.

*hBitmapHot*<br/>
[em] Manuseie o bitmap que contém a imagem para o estado selecionado.

*uiBmpResId*<br/>
[em] ID de recurso para a imagem não selecionada.

*uiBmpHotResId*<br/>
[em] ID de recurso para a imagem selecionada.

*bMap3dCores*<br/>
[em] Especifica uma cor transparente para o plano de fundo do botão; ou seja, o rosto do botão. VERDADEIRO para usar o valor de cor RGB (192, 192, 192); FALSO para usar o `AFX_GLOBAL_DATA::clrBtnFace`valor de cor definido por .

*hIconDisabled*<br/>
[em] Manuseie o ícone para a imagem desativada.

*hBitmapDesativado*<br/>
[em] Manuseie o bitmap que contém a imagem desativada.

*uiBmpDsblResID*<br/>
[em] ID de recursos do bitmap desativado.

*bAlphaBlend*<br/>
[em] TRUE usar apenas imagens de 32 bits que usam o canal alfa; FALSE, para não usar apenas imagens de canal alfa. O padrão é FALSO.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `SetImage` usar `CMFCButton` várias versões do método na classe. O exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#31](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_2.cpp)]

## <a name="cmfcbuttonsetmousecursor"></a><a name="setmousecursor"></a>CMFCButton::SetMouseCursor

Define a imagem do cursor.

```
void SetMouseCursor(HCURSOR hcursor);
```

### <a name="parameters"></a>Parâmetros

*Hcursor*<br/>
[em] A alça de um cursor.

### <a name="remarks"></a>Comentários

Use este método para associar uma imagem do cursor, como o cursor de mão, com o botão. O cursor é carregado a partir dos recursos da aplicação.

### <a name="example"></a>Exemplo

O exemplo a seguir `SetMouseCursor` demonstra como `CMFCButton` usar o método na classe. O exemplo é parte do código na [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#28](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#30](../../mfc/reference/codesnippet/cpp/cmfcbutton-class_6.cpp)]

## <a name="cmfcbuttonsetmousecursorhand"></a><a name="setmousecursorhand"></a>CMFCButton::SetMouseCursorHand

Define o cursor à imagem de uma mão.

```
void SetMouseCursorHand();
```

### <a name="remarks"></a>Comentários

Use este método para associar a imagem do cursor de uma mão com o botão. O cursor é carregado a partir dos recursos da aplicação.

## <a name="cmfcbuttonsetstdimage"></a><a name="setstdimage"></a>CMFCButton::SetStdImage

Usa `CMenuImages` um objeto para definir a imagem do botão.

```
void SetStdImage(
    CMenuImages::IMAGES_IDS id,
    CMenuImages::IMAGE_STATE state=CMenuImages::ImageBlack,
    CMenuImages::IMAGES_IDS idDisabled=(CMenuImages::IMAGES_IDS)0);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Um dos identificadores de imagem do `CMenuImage::IMAGES_IDS` botão que é definido na enumeração. Os valores da imagem especificam imagens como setas, pinos e botões de rádio.

*Estado*<br/>
[em] Um dos identificadores de estado de `CMenuImages::IMAGE_STATE` imagem do botão que é definido na enumeração. Os estados da imagem especificam cores de botão como preto, cinza, cinza claro, branco e cinza escuro. O valor padrão é `CMenuImages::ImageBlack`.

*idDisabled*<br/>
[em] Um dos identificadores de imagem do `CMenuImage::IMAGES_IDS` botão que é definido na enumeração. A imagem indica que o botão está desativado. O valor padrão é a `CMenuImages::IdArrowDown`primeira imagem de botão ( ).

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsettextcolor"></a><a name="settextcolor"></a>CMFCButton::SetTextColor

Define a cor do texto do botão para um botão que não está selecionado.

```
void SetTextColor(COLORREF clrText);
```

### <a name="parameters"></a>Parâmetros

*clrText*<br/>
[em] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsettexthotcolor"></a><a name="settexthotcolor"></a>CMFCButton::SetTextHotColor

Define a cor do texto do botão para um botão selecionado.

```
void SetTextHotColor(COLORREF clrTextHot);
```

### <a name="parameters"></a>Parâmetros

*clrTextHot*<br/>
[em] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsettooltip"></a><a name="settooltip"></a>CMFCButton::SetTooltip

Associa uma dica de ferramenta com um botão.

```
void SetTooltip(LPCTSTR lpszToolTipText);
```

### <a name="parameters"></a>Parâmetros

*lpszToolTipText*<br/>
[em] Incline para o texto para a dica de ferramenta. Especifique NULL para desativar a dica de ferramenta.

### <a name="remarks"></a>Comentários

## <a name="cmfcbuttonsizetocontent"></a><a name="sizetocontent"></a>BOTÃO CMFC::SizeToContent

Redimensiona um botão para conter o texto e a imagem do botão.

```
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
[em] VERDADEIRO para calcular, mas não mudar, o novo tamanho do botão; FALSO para alterar o tamanho do botão. O padrão é FALSO.

### <a name="return-value"></a>Valor retornado

Um `CSize` objeto que contém o novo tamanho do botão.

### <a name="remarks"></a>Comentários

Por padrão, este método calcula um novo tamanho que inclui uma margem horizontal de 10 pixels e uma margem vertical de 5 pixels.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)<br/>
[Classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)<br/>
[Classe CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)
