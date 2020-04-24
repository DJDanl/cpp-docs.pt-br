---
title: Classe CMFCCaptionButton
ms.date: 11/04/2016
f1_keywords:
- CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetHit
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetIconID
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetRect
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetSize
- AFXCAPTIONBUTTON/CMFCCaptionButton::IsMiniFrameButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::Move
- AFXCAPTIONBUTTON/CMFCCaptionButton::OnDraw
- AFXCAPTIONBUTTON/CMFCCaptionButton::SetMiniFrameButton
helpviewer_keywords:
- CMFCCaptionButton [MFC], CMFCCaptionButton
- CMFCCaptionButton [MFC], GetHit
- CMFCCaptionButton [MFC], GetIconID
- CMFCCaptionButton [MFC], GetRect
- CMFCCaptionButton [MFC], GetSize
- CMFCCaptionButton [MFC], IsMiniFrameButton
- CMFCCaptionButton [MFC], Move
- CMFCCaptionButton [MFC], OnDraw
- CMFCCaptionButton [MFC], SetMiniFrameButton
ms.assetid: c5774b38-c0dd-414a-9ede-3b2f78f233ec
ms.openlocfilehash: 1b0a999f1fd1e3df1b0a971220454397cead02a9
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752601"
---
# <a name="cmfccaptionbutton-class"></a>Classe CMFCCaptionButton

A `CMFCCaptionButton` classe implementa um botão exibido na barra de legendas para um painel de encaixe ou uma janela de miniquadro. Normalmente, a estrutura cria botões de legenda automaticamente.

## <a name="syntax"></a>Sintaxe

```
class CMFCCaptionButton : public CObject
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|----------|-----------------|
|[CMFCCaptionButton::CMFCCaptionButton](#cmfccaptionbutton)|Constrói um objeto CMFCCaptionButton.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCCaptionButton::GetHit](#gethit)|Retorna o comando representado pelo botão.|
|[CMFCcaptionbutton::GetIconID](#geticonid)|Retorna o ID da imagem associado ao botão.|
|[CMFCCaptionButton::GetRect](#getrect)|Retorna o retângulo ocupado pelo botão.|
|[CMFCCaptionButton::GetSize](#getsize)|Retorna a largura e a altura do botão.|
|[CMFCCaptionButton::isminiframebutton](#isminiframebutton)|Indica se a altura da barra de título está definida como tamanho mini.|
|[CMFCCaptionButton::Mover](#move)|Define o local de desenho do botão e o estado do show da janela.|
|[CMFCCaptionButton::OnDraw](#ondraw)|Desenha o botão de legenda.|
|[CMFCCaptionButton::setMiniFrameButton](#setminiframebutton)|Define o tamanho mini da barra de título.|

## <a name="remarks"></a>Comentários

Você pode derivar uma classe da [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) e usar o método protegido, `AddButton`para adicionar botões de legenda a uma janela de mini quadro.

CPaneFrameWnd.h define iDs de comando para dois tipos de botões de legenda:

- AFX_CAPTION_BTN_PIN, que exibe um botão de pino quando o painel de encaixe suporta o modo de ocultação automática.

- AFX_CAPTION_BTN_CLOSE, que exibe um botão **Fechar** quando o painel pode ser fechado ou escondido.

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCCaptionButton` demonstra como construir um objeto e definir o tamanho mini da barra de título.

[!code-cpp[NVC_MFC_RibbonApp#43](../../mfc/reference/codesnippet/cpp/cmfccaptionbutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfccaptionbutton](../../mfc/reference/cmfccaptionbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcaptionbutton.h

## <a name="cmfccaptionbuttoncmfccaptionbutton"></a><a name="cmfccaptionbutton"></a>CMFCCaptionButton::CMFCCaptionButton

Constrói um objeto `CMFCCaptionButton`.

```
CMFCCaptionButton();

CMFCCaptionButton(
    UINT nHit,
    BOOL bLeftAlign = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nHit*<br/>
[em] O comando associado ao botão.

*bLeftAlign*<br/>
[em] Especifica se o botão está alinhado à esquerda.

A tabela a seguir lista os valores possíveis para o parâmetro *nHit.*

|Valor|Comando|
|-----------|-------------|
|AFX_HTCLOSE|Feche o botão.|
|HTMINBUTTON|Minimizar o botão.|
|HTMAXBUTTON|Maximizar o botão.|
|AFX_HTLEFTBUTTON|Botão de seta esquerda.|
|AFX_HTRIGHTBUTTON|Botão de seta direita.|
|AFX_HTMENU|Botão do menu de seta para baixo.|
|Htnowhere|O valor padrão; não representa nenhum comando.|

### <a name="remarks"></a>Comentários

Por padrão, os botões de legenda não estão associados a um comando.

Os botões de legenda estão alinhados à direita ou à esquerda.

## <a name="cmfccaptionbuttongethit"></a><a name="gethit"></a>CMFCCaptionButton::GetHit

Retorna o comando representado pelo botão.

```
UINT GetHit() const;
```

### <a name="return-value"></a>Valor retornado

O comando representado pelo botão.

A tabela a seguir lista possíveis valores de retorno.

|Valor|Comando|
|-----------|-------------|
|AFX_HTCLOSE|Feche o botão.|
|HTMINBUTTON|Minimizar o botão.|
|HTMAXBUTTON|Maximizar o botão.|
|AFX_HTLEFTBUTTON|Botão de seta esquerda.|
|AFX_HTRIGHTBUTTON|Botão de seta direita.|
|AFX_HTMENU|Botão do menu de seta para baixo.|
|Htnowhere|O valor padrão; não representa nenhum comando.|

## <a name="cmfccaptionbuttongeticonid"></a><a name="geticonid"></a>CMFCcaptionbutton::GetIconID

Retorna o ID da imagem associado ao botão.

```
virtual CMenuImages::IMAGES_IDS GetIconID(
    BOOL bHorz,
    BOOL bMaximized = FALSE) const;
```

### <a name="parameters"></a>Parâmetros

*Bhorz*<br/>
[em] TRUE para IDs de imagem de seta esquerda ou direita; FALSO para iDs de imagem de seta para cima ou para baixo.

*bMaximizado*<br/>
[em] TRUE para um ID de imagem maximizado; FALSO para um ID de imagem minimizado.

### <a name="return-value"></a>Valor retornado

A imagem id.

### <a name="remarks"></a>Comentários

Os parâmetros especificam IDs de imagem para minimizar ou maximizar botões de legenda.

## <a name="cmfccaptionbuttongetrect"></a><a name="getrect"></a>CMFCCaptionButton::GetRect

Retorna o retângulo ocupado pelo botão.

```
virtual CRect GetRect() const;
```

### <a name="return-value"></a>Valor retornado

O retângulo que representa a localização do botão.

### <a name="remarks"></a>Comentários

Se você não puder ver o botão, o tamanho retornado é 0.

## <a name="cmfccaptionbuttongetsize"></a><a name="getsize"></a>CMFCCaptionButton::GetSize

Retorna a largura e a altura do botão.

```
static CSize GetSize();
```

### <a name="return-value"></a>Valor retornado

As dimensões externas do botão.

### <a name="remarks"></a>Comentários

O tamanho retornado inclui margem de botão e borda.

## <a name="cmfccaptionbuttonisminiframebutton"></a><a name="isminiframebutton"></a>CMFCCaptionButton::isminiframebutton

Indica se a altura da barra de título está definida como tamanho mini.

```
BOOL IsMiniFrameButton() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a legenda estiver definida como mini tamanho; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfccaptionbuttonmove"></a><a name="move"></a>CMFCCaptionButton::Mover

Define o local de desenho do botão e o estado do show da janela.

```cpp
void Move(
    const CPoint& ptTo,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

*ptTo*<br/>
[em] A nova localização.

*bOcultar*<br/>
[em] Se para mostrar o botão.

## <a name="cmfccaptionbuttonondraw"></a><a name="ondraw"></a>CMFCCaptionButton::OnDraw

Desenha o botão de legenda.

```
virtual void OnDraw(
    CDC* pDC,
    BOOL bActive,
    BOOL bHorz = TRUE,
    BOOL bMaximized = TRUE,
    BOOL bDisabled = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto do dispositivo para o botão.

*Bactive*<br/>
[em] Se para desenhar uma imagem de botão ativo.

*Bhorz*<br/>
[em] Reservado para uso em uma classe derivada.

*bMaximizado*<br/>
[em] Se para desenhar uma imagem de botão maximizada.

*bDisabled*<br/>
[em] Se deve desenhar uma imagem de botão ativada.

### <a name="remarks"></a>Comentários

O parâmetro *bMaximized* é usado quando o botão é um botão maximizar ou minimizar.

## <a name="cmfccaptionbuttonsetminiframebutton"></a><a name="setminiframebutton"></a>CMFCCaptionButton::setMiniFrameButton

Define o tamanho mini da barra de título.

```cpp
void SetMiniFramebutton(BOOL bSet = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSet*<br/>
[em] TRUE para a altura da barra de mini título; FALSE para altura da barra de título padrão.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)
