---
title: Classe CMFCCaptionBar
ms.date: 11/04/2016
f1_keywords:
- CMFCCaptionBar
- AFXCAPTIONBAR/CMFCCaptionBar
- AFXCAPTIONBAR/CMFCCaptionBar::Create
- AFXCAPTIONBAR/CMFCCaptionBar::DoesAllowDynInsertBefore
- AFXCAPTIONBAR/CMFCCaptionBar::EnableButton
- AFXCAPTIONBAR/CMFCCaptionBar::GetAlignment
- AFXCAPTIONBAR/CMFCCaptionBar::GetBorderSize
- AFXCAPTIONBAR/CMFCCaptionBar::GetButtonRect
- AFXCAPTIONBAR/CMFCCaptionBar::GetMargin
- AFXCAPTIONBAR/CMFCCaptionBar::IsMessageBarMode
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveBitmap
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveButton
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveIcon
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveText
- AFXCAPTIONBAR/CMFCCaptionBar::SetBitmap
- AFXCAPTIONBAR/CMFCCaptionBar::SetBorderSize
- AFXCAPTIONBAR/CMFCCaptionBar::SetButton
- AFXCAPTIONBAR/CMFCCaptionBar::SetButtonPressed
- AFXCAPTIONBAR/CMFCCaptionBar::SetButtonToolTip
- AFXCAPTIONBAR/CMFCCaptionBar::SetFlatBorder
- AFXCAPTIONBAR/CMFCCaptionBar::SetIcon
- AFXCAPTIONBAR/CMFCCaptionBar::SetImageToolTip
- AFXCAPTIONBAR/CMFCCaptionBar::SetMargin
- AFXCAPTIONBAR/CMFCCaptionBar::SetText
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawBackground
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawBorder
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawButton
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawImage
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawText
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarBackground
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarBorder
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarText
helpviewer_keywords:
- CMFCCaptionBar [MFC], Create
- CMFCCaptionBar [MFC], DoesAllowDynInsertBefore
- CMFCCaptionBar [MFC], EnableButton
- CMFCCaptionBar [MFC], GetAlignment
- CMFCCaptionBar [MFC], GetBorderSize
- CMFCCaptionBar [MFC], GetButtonRect
- CMFCCaptionBar [MFC], GetMargin
- CMFCCaptionBar [MFC], IsMessageBarMode
- CMFCCaptionBar [MFC], RemoveBitmap
- CMFCCaptionBar [MFC], RemoveButton
- CMFCCaptionBar [MFC], RemoveIcon
- CMFCCaptionBar [MFC], RemoveText
- CMFCCaptionBar [MFC], SetBitmap
- CMFCCaptionBar [MFC], SetBorderSize
- CMFCCaptionBar [MFC], SetButton
- CMFCCaptionBar [MFC], SetButtonPressed
- CMFCCaptionBar [MFC], SetButtonToolTip
- CMFCCaptionBar [MFC], SetFlatBorder
- CMFCCaptionBar [MFC], SetIcon
- CMFCCaptionBar [MFC], SetImageToolTip
- CMFCCaptionBar [MFC], SetMargin
- CMFCCaptionBar [MFC], SetText
- CMFCCaptionBar [MFC], OnDrawBackground
- CMFCCaptionBar [MFC], OnDrawBorder
- CMFCCaptionBar [MFC], OnDrawButton
- CMFCCaptionBar [MFC], OnDrawImage
- CMFCCaptionBar [MFC], OnDrawText
- CMFCCaptionBar [MFC], m_clrBarBackground
- CMFCCaptionBar [MFC], m_clrBarBorder
- CMFCCaptionBar [MFC], m_clrBarText
ms.assetid: acb54d5f-14ff-4c96-aeb3-7717cf566d9a
ms.openlocfilehash: 3a1e8890176fe686b54fe4756dfd578869cbcdfb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367790"
---
# <a name="cmfccaptionbar-class"></a>Classe CMFCCaptionBar

Um `CMFCCaptionBar` objeto é uma barra de controle que pode exibir três elementos: um botão, um rótulo de texto e um bitmap. Ele só pode exibir um elemento de cada tipo de cada vez. Você pode alinhar cada elemento às bordas esquerda ou direita do controle ou ao centro. Você também pode aplicar um estilo plano ou 3D nas bordas superior e inferior da barra de legendas.

## <a name="syntax"></a>Sintaxe

```
class CMFCCaptionBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCCaptionBar::Criar](#create)|Cria o controle da barra de `CMFCCaptionBar` legendas e anexa-o ao objeto.|
|[CMFCCaptionBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Indica se outro painel pode ser inserido dinamicamente entre a barra de legendas e seu quadro pai. (Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[CMFCCaptionBar::Ativarbotão](#enablebutton)|Ativa ou desativa o botão na barra de legendas.|
|[CMFCCaptionBar::GetAlignment](#getalignment)|Retorna o alinhamento do elemento especificado.|
|[CMFCcaptionBar::getBorderSize](#getbordersize)|Retorna o tamanho da borda da barra de legendas.|
|[CMFCCaptionBar::GetButtonRect](#getbuttonrect)|Recupera o retângulo delimitador do botão na barra de legendas.|
|[CMFCCaptionBar::GetMargin](#getmargin)|Retorna a distância entre a borda dos elementos da barra de legenda e a borda do controle da barra de legendas.|
|[CMFCCaptionBar::IsMessageBarMode](#ismessagebarmode)|Especifica se a barra de legendas está no modo barra de mensagens.|
|[CMFCCaptionBar::RemoveBitmap](#removebitmap)|Remove a imagem bitmap da barra de legendas.|
|[CMFCCaptionBar::RemoveButton](#removebutton)|Remove o botão da barra de legendas.|
|[CMFCCaptionBar::RemoveIcon](#removeicon)|Remove o ícone da barra de legendas.|
|[CMFCCaptionBar::RemoveText](#removetext)|Remove o rótulo de texto da barra de legendas.|
|[CMFCCaptionBar::SetBitmap](#setbitmap)|Define a imagem bitmap para a barra de legendas.|
|[CMFCCaptionBar::SetBorderSize](#setbordersize)|Define o tamanho da borda da barra de legendas.|
|[CMFCCaptionBar::setButton](#setbutton)|Define o botão para a barra de legendas.|
|[CMFCCaptionBar::setButtonPressed](#setbuttonpressed)|Especifica se o botão permanece pressionado.|
|[CMFCCaptionBar::setButtonToolTip](#setbuttontooltip)|Define a dica de ferramenta para o botão.|
|[CMFCCaptionBar::setFlatBorder](#setflatborder)|Define o estilo de borda da barra de legendas.|
|[CMFCCaptionBar::setIcon](#seticon)|Define o ícone como uma barra de legendas.|
|[CMFCCaptionBar::setImagetoolTip](#setimagetooltip)|Define a dica de ferramenta para a imagem para a barra de legendas.|
|[CMFCCaptionBar::setMargin](#setmargin)|Define a distância entre a borda do elemento da barra de legendae e a borda do controle da barra de legendas.|
|[CMFCCaptionBar::SetText](#settext)|Define o rótulo de texto para a barra de legendas.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCCaptionBar::OnDrawBackground](#ondrawbackground)|Chamado pela estrutura para preencher o fundo da barra de legendas.|
|[CMFCcaptionBar::OnDrawBorder](#ondrawborder)|Chamado pelo framework para desenhar a borda da barra de legendas.|
|[CMFCCaptionBar::OnDrawButton](#ondrawbutton)|Chamado pelo framework para desenhar o botão da barra de legendas.|
|[CMFCCaptionBar::OnDrawImage](#ondrawimage)|Chamado pelo framework para desenhar a imagem da barra de legendas.|
|[CMFCCaptionBar::OnDrawText](#ondrawtext)|Chamado pelo framework para desenhar o texto da barra de legendas.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCCaptionBar::m_clrBarBackground](#m_clrbarbackground)|A cor de fundo da barra de legendas.|
|[CMFCCaptionBar::m_clrBarBorder](#m_clrbarborder)|A cor da borda da barra de legendas.|
|[CMFCCaptionBar::m_clrBarText](#m_clrbartext)|A cor do texto da barra de legenda.|

## <a name="remarks"></a>Comentários

Para criar uma barra de legendas, siga estas etapas:

1. Construa `CMFCCaptionBar` o objeto. Normalmente, você adicionaria a barra de legendas a uma classe de janela de quadro.

1. Ligue para o [CMFCCaptionBar::Crie](#create) o método para criar `CMFCCaptionBar` o controle da barra de legendas e anexá-lo ao objeto.

1. Ligue para [CMFCCaptionBar::SetButton,](#setbutton) [CMFCCaptionBar::SetText,](#settext) [CMFCCaptionBar::SetIcon](#seticon)e [CMFCCaptionBar::SetBitmap](#setbitmap) para definir os elementos da barra de legendas.

Ao definir o elemento do botão, você deve atribuir um ID de comando ao botão. Quando o usuário clica no botão, a barra de legendas roteia as mensagens WM_COMMAND que possuem esse ID para a janela do quadro pai.

A barra de legendas também pode funcionar no modo barra de mensagens, que emula a barra de mensagens que aparece nos aplicativos do Microsoft Office 2007. No modo barra de mensagens, a barra de legendaexibe um bitmap, uma mensagem e um botão (que normalmente abre uma caixa de diálogo.) Você pode atribuir uma dica de ferramenta ao bitmap.

Para ativar o modo barra de mensagens, ligue para [CMFCCaptionBar::Criar](#create) e definir o quarto parâmetro (bIsMessageBarMode) como TRUE.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCCaptionBar` usar vários métodos na classe. O exemplo mostra como criar o controle da barra de legendas, definir uma borda 3D da barra de legendas, definir a distância, em pixels, entre a borda dos elementos da barra de legendae e a borda do controle da barra de legendas, definir o botão para a barra de legendas, definir a dica de ferramenta para o botão, definir a etiqueta de texto para a barra de legendas, definir a imagem bitmap para a barra de legendas, definir a barra de legendas , e defina a dica de ferramenta para a imagem na barra de legendas. Este trecho de código faz parte da amostra de [demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#1](../../mfc/reference/codesnippet/cpp/cmfccaptionbar-class_1.h)]
[!code-cpp[NVC_MFC_MSOffice2007Demo#2](../../mfc/reference/codesnippet/cpp/cmfccaptionbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCCaptionBar](../../mfc/reference/cmfccaptionbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcaptionbar.h

## <a name="cmfccaptionbarcreate"></a><a name="create"></a>CMFCCaptionBar::Criar

Cria o controle da barra de `CMFCCaptionBar` legendas e anexa-o ao objeto.

```
BOOL Create(
    DWORD dwStyle,
    CWnd* pParentWnd,
    UINT uID,
    int nHeight=-1,
    BOOL bIsMessageBarMode=FALSE);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
A combinação or lógica dos estilos de barra de legenda.

*Pparentwnd*<br/>
A janela pai do controle da barra de legendas.

*Uid*<br/>
O ID do controle da barra de legendas.

*Nheight*<br/>
A altura, em pixels, do controle da barra de legendas. Se for -1, a altura é calculada de acordo com a altura do ícone, o texto e o botão que o controle da barra de legendas exibe.

*bIsMessageBarMode*<br/>
TRUE se a barra de legendas estiver no modo barra de mensagens; FALSO de outra forma.

### <a name="return-value"></a>Valor retornado

TRUE se o controle da barra de legendas for criado com sucesso; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Você constrói `CMFCCaptionBar` um objeto em dois passos. Primeiro você chama o construtor, e `Create` depois você chama o método, que `CMFCCaptionBar` cria o controle do Windows e o anexa ao objeto.

## <a name="cmfccaptionbardoesallowdyninsertbefore"></a><a name="doesallowdyninsertbefore"></a>CMFCCaptionBar::DoesAllowDynInsertBefore

Indica se outro painel pode ser inserido dinamicamente entre a barra de legendas e seu quadro pai.

```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor retornado

Retorna FALSO, a menos que substituído.

### <a name="remarks"></a>Comentários

## <a name="cmfccaptionbarenablebutton"></a><a name="enablebutton"></a>CMFCCaptionBar::Ativarbotão

Ativa ou desativa o botão na barra de legendas.

```
void EnableButton(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para ativar o botão, FALSE para desativar o botão.

## <a name="cmfccaptionbargetalignment"></a><a name="getalignment"></a>CMFCCaptionBar::GetAlignment

Retorna o alinhamento do elemento especificado.

```
BarElementAlignment GetAlignment(BarElement elem);
```

### <a name="parameters"></a>Parâmetros

*Elem*<br/>
[em] Um elemento de barra de legenda para o qual recuperar o alinhamento.

### <a name="return-value"></a>Valor retornado

O alinhamento de um elemento, como um botão, um bitmap, texto ou um ícone.

### <a name="remarks"></a>Comentários

O alinhamento do elemento pode ser um dos seguintes valores:

- ALIGN_INVALID

- ALIGN_LEFT

- ALIGN_RIGHT

- ALIGN_CENTER

## <a name="cmfccaptionbargetbordersize"></a><a name="getbordersize"></a>CMFCcaptionBar::getBorderSize

Retorna o tamanho da borda da barra de legendas.

```
int GetBorderSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho, em pixels, da fronteira.

## <a name="cmfccaptionbargetbuttonrect"></a><a name="getbuttonrect"></a>CMFCCaptionBar::GetButtonRect

Recupera o retângulo delimitador do botão na barra de legendas.

```
CRect GetButtonRect() const;
```

### <a name="return-value"></a>Valor retornado

Um `CRect` objeto que contém as coordenadas do retângulo delimitador do botão na barra de legendas.

## <a name="cmfccaptionbargetmargin"></a><a name="getmargin"></a>CMFCCaptionBar::GetMargin

Retorna a distância entre a borda dos elementos da barra de legenda e a borda do controle da barra de legendas.

```
int GetMargin() const;
```

### <a name="return-value"></a>Valor retornado

A distância, em pixels, entre a borda dos elementos da barra de legendae e a borda do controle da barra de legendas.

## <a name="cmfccaptionbarismessagebarmode"></a><a name="ismessagebarmode"></a>CMFCCaptionBar::IsMessageBarMode

Especifica se a barra de legendas está no modo barra de mensagens.

```
BOOL IsMessageBarMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a barra de legendas estiver no modo barra de mensagens; FALSO de outra forma.

### <a name="remarks"></a>Comentários

No modo barra de mensagens, a barra de legendaexibe uma imagem com uma dica de ferramenta, um texto de mensagem e um botão.

## <a name="cmfccaptionbarm_clrbarbackground"></a><a name="m_clrbarbackground"></a>CMFCCaptionBar::m_clrBarBackground

A cor de fundo da barra de legendas.

```
COLORREF m_clrBarBackground
```

## <a name="cmfccaptionbarm_clrbarborder"></a><a name="m_clrbarborder"></a>CMFCCaptionBar::m_clrBarBorder

A cor da borda da barra de legendas.

```
COLORREF m_clrBarBorder
```

## <a name="cmfccaptionbarm_clrbartext"></a><a name="m_clrbartext"></a>CMFCCaptionBar::m_clrBarText

A cor do texto da barra de legenda.

```
COLORREF m_clrBarText
```

## <a name="cmfccaptionbarondrawbackground"></a><a name="ondrawbackground"></a>CMFCCaptionBar::OnDrawBackground

Chamado pela estrutura para preencher o fundo da barra de legendas.

```
virtual void OnDrawBackground(
    CDC* pDC,
    CRect rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para o contexto do dispositivo da barra de legendas.

*Rect*<br/>
[em] O retângulo delimitador para preencher.

### <a name="remarks"></a>Comentários

O `OnDrawBackground` método é chamado quando o fundo da barra de legendas está prestes a ser preenchido. A implementação padrão preenche o plano de fundo usando a cor [CMFCCaptionBar::m_clrBarBackground.](#m_clrbarbackground)

Anular este método `CMFCCaptionBar` em uma classe derivada para personalizar a aparência da barra de legendas.

## <a name="cmfccaptionbarondrawborder"></a><a name="ondrawborder"></a>CMFCcaptionBar::OnDrawBorder

Chamado pelo framework para desenhar a borda da barra de legendas.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um contexto de dispositivo que é usado para exibir as bordas.

*Rect*<br/>
[em] O retângulo delimitador.

### <a name="remarks"></a>Comentários

Por padrão, as bordas têm o estilo plano.

Anular este método `CMFCCaptionBar` em uma classe derivada para personalizar a aparência das bordas da barra de legendas.

## <a name="cmfccaptionbarondrawbutton"></a><a name="ondrawbutton"></a>CMFCCaptionBar::OnDrawButton

Chamado pelo framework para desenhar o botão da barra de legendas.

```
virtual void OnDrawButton(
    CDC* pDC,
    CRect rect,
    const CString& strButton,
    BOOL bEnabled);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo que é usado para exibir o botão.

*Rect*<br/>
[em] O retângulo delimitador do botão.

*strButton*<br/>
[em] A etiqueta de texto do botão.

*bEnabled*<br/>
[em] TRUE se o botão estiver ativado; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Anular este método `CMFCCaptionBar` em uma classe derivada para personalizar a aparência do botão da barra de legendas.

## <a name="cmfccaptionbarondrawimage"></a><a name="ondrawimage"></a>CMFCCaptionBar::OnDrawImage

Chamado pelo framework para desenhar a imagem da barra de legendas.

```
virtual void OnDrawImage(
    CDC* pDC,
    CRect rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo que é usado para exibir a imagem.

*Rect*<br/>
[em] Especifica o retângulo delimitador da imagem.

### <a name="remarks"></a>Comentários

Anular este método `CMFCCaptionBar` em uma classe derivada para personalizar a aparência da imagem.

## <a name="cmfccaptionbarondrawtext"></a><a name="ondrawtext"></a>CMFCCaptionBar::OnDrawText

Chamado pelo framework para desenhar o texto da barra de legendas.

```
virtual void OnDrawText(
    CDC* pDC,
    CRect rect,
    const CString& strText);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo que é usado para exibir o botão.

*Rect*<br/>
[em] O retângulo delimitador do texto.

*strText*<br/>
[em] A seqüência de texto a ser exibida.

### <a name="remarks"></a>Comentários

A implementação padrão exibe `CDC::DrawText` o texto usando e [CMFCCaptionBar::m_clrBarText](#m_clrbartext) cor.

Anular este método `CMFCCaptionBar` em uma classe derivada para personalizar a aparência do texto da barra de legendas.

## <a name="cmfccaptionbarremovebitmap"></a><a name="removebitmap"></a>CMFCCaptionBar::RemoveBitmap

Remove a imagem bitmap da barra de legendas.

```
void RemoveBitmap();
```

## <a name="cmfccaptionbarremovebutton"></a><a name="removebutton"></a>CMFCCaptionBar::RemoveButton

Remove o botão da barra de legendas.

```
void RemoveButton();
```

### <a name="remarks"></a>Comentários

O layout dos elementos da barra de legendas são ajustados automaticamente.

## <a name="cmfccaptionbarremoveicon"></a><a name="removeicon"></a>CMFCCaptionBar::RemoveIcon

Remove o ícone da barra de legendas.

```
void RemoveIcon();
```

## <a name="cmfccaptionbarremovetext"></a><a name="removetext"></a>CMFCCaptionBar::RemoveText

Remove o rótulo de texto da barra de legendas.

```
void RemoveText();
```

## <a name="cmfccaptionbarsetbitmap"></a><a name="setbitmap"></a>CMFCCaptionBar::SetBitmap

Define a imagem bitmap para a barra de legendas.

```
void SetBitmap(
    HBITMAP hBitmap,
    COLORREF clrTransparent,
    BOOL bStretch=FALSE,
    BarElementAlignment bmpAlignment=ALIGN_RIGHT);

void SetBitmap(
    UINT uiBmpResID,
    COLORREF clrTransparent,
    BOOL bStretch=FALSE,
    BarElementAlignment bmpAlignment=ALIGN_RIGHT);
```

### <a name="parameters"></a>Parâmetros

*Hbitmap*<br/>
[em] A alça do bitmap a ser definida.

*clrTransparent*<br/>
[em] Um valor RGB que especifica a cor transparente do bitmap.

*Bstretch*<br/>
[em] Se TRUE, o bitmap é estendido se não se encaixar no retângulo delimitador da imagem. Caso contrário, o bitmap não é esticado.

*bmpAlignment*<br/>
[em] O alinhamento do bitmap.

### <a name="remarks"></a>Comentários

Use este método para definir um bitmap em uma barra de legendas.

O bitmap anterior é destruído automaticamente. Se a barra de legendas exibir um ícone porque você chamou o método [CMFCCaptionBar::SetIcon,](#seticon) o bitmap não será exibido a menos que você remova o ícone chamando [CMFCCaptionBar::RemoveIcon](#removeicon).

O bitmap está alinhado conforme especificado pelo parâmetro *bmpAlignment.*  Este parâmetro pode ser um `BarElementAlignment` dos seguintes valores:

- ALIGN_INVALID

- ALIGN_LEFT

- ALIGN_RIGHT

- ALIGN_CENTER

## <a name="cmfccaptionbarsetbordersize"></a><a name="setbordersize"></a>CMFCCaptionBar::SetBorderSize

Define o tamanho da borda da barra de legendas.

```
void SetBorderSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
[em] O novo tamanho, em pixels, da borda da barra de legendas.

## <a name="cmfccaptionbarsetbutton"></a><a name="setbutton"></a>CMFCCaptionBar::setButton

Define o botão para a barra de legendas.

```
void SetButton(
    LPCTSTR lpszLabel,
    UINT uiCmdUI,
    BarElementAlignment btnAlignmnet=ALIGN_LEFT,
    BOOL bHasDropDownArrow=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
O rótulo de comando do botão.

*uiCmdUI*<br/>
O botão é o comando ID.

*btnAlignmnet*<br/>
O alinhamento do botão.

*bHasDropDownArrow*<br/>
VERDADE se o botão exibir uma seta solta, FALSO de outra forma.

## <a name="cmfccaptionbarsetbuttonpressed"></a><a name="setbuttonpressed"></a>CMFCCaptionBar::setButtonPressed

Especifica se o botão permanece pressionado.

```
void SetButtonPressed(BOOL bPresed=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bPresed*<br/>
VERDADE se o botão mantiver seu estado pressionado, FALSO de outra forma.

## <a name="cmfccaptionbarsetbuttontooltip"></a><a name="setbuttontooltip"></a>CMFCCaptionBar::setButtonToolTip

Define a dica de ferramenta para o botão.

```
void SetButtonToolTip(
    LPCTSTR lpszToolTip,
    LPCTSTR lpszDescription=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszToolTip*<br/>
[em] A legenda da dica de ferramenta.

*lpszDescrição*<br/>
[em] A descrição da dica da ferramenta.

## <a name="cmfccaptionbarsetflatborder"></a><a name="setflatborder"></a>CMFCCaptionBar::setFlatBorder

Define o estilo de borda da barra de legendas.

```
void SetFlatBorder(BOOL bFlat=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFlat*<br/>
[em] VERDADE se a borda de uma barra de legendas é plana. FALSO se a fronteira for 3D.

## <a name="cmfccaptionbarseticon"></a><a name="seticon"></a>CMFCCaptionBar::setIcon

Define o ícone como uma barra de legendas.

```
void SetIcon(
    HICON hIcon,
    BarElementAlignment iconAlignment=ALIGN_RIGHT);
```

### <a name="parameters"></a>Parâmetros

*Hicon*<br/>
[em] A alça do ícone a definir.

*íconeAlinhamento*<br/>
[em] O alinhamento do ícone.

### <a name="remarks"></a>Comentários

As barras de legendapodem exibir ícones ou bitmaps. Consulte [CMFCCaptionBar::SetBitmap](#setbitmap) para descobrir como exibir um bitmap. Se você definir um ícone e um bitmap, o ícone será sempre exibido. Ligue para [cmfccaptionbar::RemoveIcon](#removeicon) para remover um ícone da barra de legendas.

O ícone está alinhado de acordo com o parâmetro *iconAlignment.* Pode ser um dos `BarElementAlignment` seguintes valores:

- ALIGN_INVALID

- ALIGN_LEFT

- ALIGN_RIGHT

- ALIGN_CENTER

## <a name="cmfccaptionbarsetimagetooltip"></a><a name="setimagetooltip"></a>CMFCCaptionBar::setImagetoolTip

Define a dica de ferramenta para a imagem na barra de legendas.

```
void SetImageToolTip(
    LPCTSTR lpszToolTip,
    LPCTSTR lpszDescription=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszToolTip*<br/>
[em] O texto da dica de ferramenta.

*lpszDescrição*<br/>
[em] A descrição da dica da ferramenta.

## <a name="cmfccaptionbarsetmargin"></a><a name="setmargin"></a>CMFCCaptionBar::setMargin

Define a distância entre a borda do elemento da barra de legendae e a borda do controle da barra de legendas.

```
void SetMargin(int nMargin);
```

### <a name="parameters"></a>Parâmetros

*nMargem*<br/>
[em] A distância, em pixels, entre a borda dos elementos da barra de legendae e a borda do controle da barra de legendas.

## <a name="cmfccaptionbarsettext"></a><a name="settext"></a>CMFCCaptionBar::SetText

Define o rótulo de texto para a barra de legendas.

```
void SetText(
    const CString& strText,
    BarElementAlignment textAlignment=ALIGN_RIGHT);
```

### <a name="parameters"></a>Parâmetros

*strText*<br/>
[em] A seqüência de texto a definir.

*Textalignment*<br/>
[em] O alinhamento de texto.

### <a name="remarks"></a>Comentários

O rótulo de texto está alinhado conforme especificado pelo parâmetro *textAlignment.* Pode ser um dos `BarElementAlignment` seguintes valores:

- ALIGN_INVALID

- ALIGN_LEFT

- ALIGN_RIGHT

- ALIGN_CENTER

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
