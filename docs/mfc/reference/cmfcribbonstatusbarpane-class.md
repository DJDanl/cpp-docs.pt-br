---
title: Classe CMFCRibbonStatusBarPane
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonStatusBarPane
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::CMFCRibbonStatusBarPane
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::GetAlmostLargeText
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::GetTextAlign
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::IsAnimation
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::IsExtended
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::OnDrawBorder
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::OnFillBackground
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::SetAlmostLargeText
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::SetAnimationList
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::SetTextAlign
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::StartAnimation
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::StopAnimation
- AFXRIBBONSTATUSBARPANE/CMFCRibbonStatusBarPane::OnFinishAnimation
helpviewer_keywords:
- CMFCRibbonStatusBarPane [MFC], CMFCRibbonStatusBarPane
- CMFCRibbonStatusBarPane [MFC], GetAlmostLargeText
- CMFCRibbonStatusBarPane [MFC], GetTextAlign
- CMFCRibbonStatusBarPane [MFC], IsAnimation
- CMFCRibbonStatusBarPane [MFC], IsExtended
- CMFCRibbonStatusBarPane [MFC], OnDrawBorder
- CMFCRibbonStatusBarPane [MFC], OnFillBackground
- CMFCRibbonStatusBarPane [MFC], SetAlmostLargeText
- CMFCRibbonStatusBarPane [MFC], SetAnimationList
- CMFCRibbonStatusBarPane [MFC], SetTextAlign
- CMFCRibbonStatusBarPane [MFC], StartAnimation
- CMFCRibbonStatusBarPane [MFC], StopAnimation
- CMFCRibbonStatusBarPane [MFC], OnFinishAnimation
ms.assetid: 5d034c3c-ecca-4267-b88c-0f55a2884dd0
ms.openlocfilehash: bb4e09eabab17061812ed22b2739d06accd57fee
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753509"
---
# <a name="cmfcribbonstatusbarpane-class"></a>Classe CMFCRibbonStatusBarPane

A `CMFCRibbonStatusBarPane` classe implementa um elemento de fita que você pode adicionar a uma barra de status de fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonStatusBarPane : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBarPane::CMFCRibbonStatusBarPane](#cmfcribbonstatusbarpane)|Constrói e inicializa um objeto `CMFCRibbonStatusBarPane`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBarPane::GetAlmostLargeText](#getalmostlargetext)|Retorna a seqüência que define a seqüência de texto mais longa que pode ser exibida no painel sem truncação.|
|[CMFCRibbonStatusBarPane::GetTextAlign](#gettextalign)|Retorna a configuração atual do alinhamento de texto.|
|[CMFCRibbonStatusBarPane::IsAnimation](#isanimation)|Determina se a animação está em andamento.|
|[CMFCRibbonStatusBarPane::IsExtended](#isextended)|Determina se o painel está localizado na área estendida da barra de status da fita.|
|[CMFCRibbonStatusBarPane::OnDrawBorder](#ondrawborder)|(Substitui [cmfcribbonbutton::OnDrawBorder](../../mfc/reference/cmfcribbonbutton-class.md#ondrawborder).)|
|[CMFCRibbonStatusBarPane::OnFillBackground](#onfillbackground)|(Substitui [cmfcribbonbutton::OnFillBackground](../../mfc/reference/cmfcribbonbutton-class.md#onfillbackground).)|
|[CMFCRibbonStatusBarPane::SetAlmostLargeText](#setalmostlargetext)|Define a seqüência de texto mais longa que pode ser exibida no painel sem truncação.|
|[CMFCRibbonStatusBarPane::SetAnimationList](#setanimationlist)|Atribui ao painel uma lista de imagens que pode ser usada para animação.|
|[CMFCRibbonStatusBarPane::SetTextAlign](#settextalign)|Define o alinhamento do texto.|
|[CMFCRibbonStatusBarPane::StartAnimation](#startanimation)|Inicia a animação atribuída ao painel.|
|[CMFCRibbonStatusBarPane::StopAnimation](#stopanimation)|Interrompe a animação atribuída ao painel. .|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBarPane::OnFinishAnimation](#onfinishanimation)|Chamado pela estrutura quando a animação atribuída ao painel pára.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar `CMFCRibbonStatusBarPane` os vários métodos da classe. O exemplo mostra como `CMFCRibbonStatusBarPane` construir um objeto, definir o alinhamento de texto do rótulo do painel da barra de status, definir o texto mais longo que pode ser exibido no painel da barra de status sem truncação, anexar ao painel da barra de status uma lista de imagens que pode ser usada para animação e iniciar a animação.

[!code-cpp[NVC_MFC_RibbonApp#2](../../mfc/reference/codesnippet/cpp/cmfcribbonstatusbarpane-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[Cmfcribbonstatusbarpane](../../mfc/reference/cmfcribbonstatusbarpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonstatusbarpane.h

## <a name="cmfcribbonstatusbarpanecmfcribbonstatusbarpane"></a><a name="cmfcribbonstatusbarpane"></a>CMFCRibbonStatusBarPane::CMFCRibbonStatusBarPane

Construa um objeto de painel na barra de status.

```
CMFCRibbonStatusBarPane(
    UINT nCmdID,
    LPCTSTR lpszText,
    BOOL bIsStatic=FALSE,
    HICON hIcon=NULL,
    LPCTSTR lpszAlmostLargeText=NULL);

CMFCRibbonStatusBarPane(
    UINT nCmdID,
    LPCTSTR lpszText,
    HBITMAP hBmpAnimationList,
    int cxAnimation=16,
    COLORREF clrTrnsp=RGB(192,192 1,192) 1,
    HICON hIcon=NULL,
    BOOL bIsStatic=FALSE);

CMFCRibbonStatusBarPane(
    UINT nCmdID,
    LPCTSTR lpszText,
    UINT uiAnimationListResID,
    int cxAnimation=16,
    COLORREF clrTrnsp=RGB(192, 192 1, 192) 1,
    HICON hIcon=NULL,
    BOOL bIsStatic=FALSE);
```

### <a name="parameters"></a>Parâmetros

*Ncmdid*<br/>
[em] Especifica o ID de comando do painel.

*lpszText*<br/>
[em] Especifica a seqüência de texto a ser exibida no painel.

*bIsstatic*<br/>
[em] Se TRUE, o painel de status não pode ser destacado ou selecionado clicando nele.

*Hicon*<br/>
[em] Especifica uma alça para um ícone a ser exibido no painel.

*lpszAlmostLargeText*<br/>
[em] Especifica a seqüência de texto mais longa que pode ser exibida pelo painel.

*hBmpAnimationList*<br/>
[em] Especifica uma alça para uma lista de imagens que é usada para animação.

*cxAnimation*<br/>
[em] Especifica a largura, em pixels, do ícone na lista de imagens que é usada para animação.

*clrTrnsp*<br/>
[em] Especifica a cor transparente das imagens na lista de imagens usadas para animação.

*uiAnimationListResID*<br/>
[em] Especifica um ID de recurso de uma lista de imagens que é usada para animação.

## <a name="cmfcribbonstatusbarpanegetalmostlargetext"></a><a name="getalmostlargetext"></a>CMFCRibbonStatusBarPane::GetAlmostLargeText

Obtém a seqüência de texto mais longa que o painel da barra de status pode exibir.

```
LPCTSTR GetAlmostLargeText() const;
```

### <a name="return-value"></a>Valor retornado

A seqüência de texto mais longa que o painel da barra de status pode exibir.

## <a name="cmfcribbonstatusbarpanegettextalign"></a><a name="gettextalign"></a>CMFCRibbonStatusBarPane::GetTextAlign

Obtém a configuração atual do alinhamento de texto do rótulo do painel da barra de status.

```
int GetTextAlign() const;
```

### <a name="return-value"></a>Valor retornado

O alinhamento de texto atual que pode ser um dos seguintes:

- TA_LEFT

- TA_CENTER

- TA_RIGHT.

## <a name="cmfcribbonstatusbarpaneisanimation"></a><a name="isanimation"></a>CMFCRibbonStatusBarPane::IsAnimation

Determina se a animação está em andamento.

```
BOOL IsAnimation() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se a animação estiver em andamento; FALSO de outra forma.

## <a name="cmfcribbonstatusbarpaneisextended"></a><a name="isextended"></a>CMFCRibbonStatusBarPane::IsExtended

Determine se o painel está localizado na área estendida da barra de status da fita.

```
BOOL IsExtended() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o painel estiver na barra de status área estendida. FALSO de outra forma.

## <a name="cmfcribbonstatusbarpaneondrawborder"></a><a name="ondrawborder"></a>CMFCRibbonStatusBarPane::OnDrawBorder

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual void OnDrawBorder(CDC*);
```

### <a name="parameters"></a>Parâmetros

[em] *CDC&#42;*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarpaneonfillbackground"></a><a name="onfillbackground"></a>CMFCRibbonStatusBarPane::OnFillBackground

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual COLORREF OnFillBackground(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarpaneonfinishanimation"></a><a name="onfinishanimation"></a>CMFCRibbonStatusBarPane::OnFinishAnimation

Framework chama esse método quando a animação atribuída ao painel termina.

```
virtual void OnFinishAnimation();
```

### <a name="remarks"></a>Comentários

`StopAnimation`método chama `OnFinishAnimation` o método, que você pode usar para limpar dados quando a animação termina.

## <a name="cmfcribbonstatusbarpanesetalmostlargetext"></a><a name="setalmostlargetext"></a>CMFCRibbonStatusBarPane::SetAlmostLargeText

Defina o texto mais longo que pode ser exibido no painel da barra de status sem truncação.

```cpp
void SetAlmostLargeText(LPCTSTR lpszAlmostLargeText);
```

### <a name="parameters"></a>Parâmetros

*lpszAlmostLargeText*<br/>
[em] Especifica a seqüência mais longa que pode ser exibida no painel da barra de status sem truncação.

### <a name="remarks"></a>Comentários

A biblioteca calcula o tamanho do texto que *lpszAlmostLargeText* especifica e redimensiona o painel de acordo. O texto será truncado se ainda não caber no painel.

## <a name="cmfcribbonstatusbarpanesetanimationlist"></a><a name="setanimationlist"></a>CMFCRibbonStatusBarPane::SetAnimationList

Anexa ao painel da barra de status uma lista de imagens que pode ser usada para animação.

```cpp
void SetAnimationList(
    HBITMAP hBmpAnimationList,
    int cxAnimation=16,
    COLORREF clrTransp=RGB(192, 192 1, 192) 1);

BOOL SetAnimationList(
    UINT uiAnimationListResID,
    int cxAnimation=16,
    COLORREF clrTransp=RGB(192, 192 1, 192) 1);
```

### <a name="parameters"></a>Parâmetros

*hBmpAnimationList*<br/>
[em] Especifica uma alça para uma lista de imagens.

*cxAnimation*<br/>
[em] Especifica a largura, em pixels, do quadro na lista de imagens.

*clrTransp*<br/>
[em] Especifica a cor transparente da lista de imagens.

*uiAnimationListResID*<br/>
[em] Especifica o ID de recurso da lista de imagens.

### <a name="return-value"></a>Valor retornado

TRUE se a lista de imagens for anexada com sucesso ao painel da barra de status; FALSO de outra forma.

## <a name="cmfcribbonstatusbarpanesettextalign"></a><a name="settextalign"></a>CMFCRibbonStatusBarPane::SetTextAlign

Define o alinhamento de texto do rótulo do painel da barra de status.

```cpp
void SetTextAlign(int nAlign);
```

### <a name="parameters"></a>Parâmetros

*nAlinhar*<br/>
[em] Especifica o alinhamento do texto.

### <a name="remarks"></a>Comentários

*nAlign* pode ter um dos seguintes valores:

- TA_LEFT: alinhamento à esquerda

- TA_CENTER: alinhamento central

- TA_RIGHT: alinhamento à direita

## <a name="cmfcribbonstatusbarpanestartanimation"></a><a name="startanimation"></a>CMFCRibbonStatusBarPane::StartAnimation

Inicia a animação que você atribui ao painel.

```cpp
void StartAnimation(
    UINT nFrameDelay=500,
    UINT nDuration=-1);
```

### <a name="parameters"></a>Parâmetros

*nFrameDelay*<br/>
[em] Especifica a taxa de quadros de animação, em milissegundos.

*nDuração*<br/>
[em] Especifica quanto tempo para reproduzir a animação, em milissegundos. Use -1 para um loop infinito.

### <a name="remarks"></a>Comentários

Você deve especificar uma alça para `StartAnimation` uma `SetAnimationList`lista de imagens antes de ligar usando .

## <a name="cmfcribbonstatusbarpanestopanimation"></a><a name="stopanimation"></a>CMFCRibbonStatusBarPane::StopAnimation

Interrompe a animação que você atribuiu ao painel da barra de status.

```cpp
void StopAnimation();
```

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)<br/>
[Classe CMFCRibbonStatusBar](../../mfc/reference/cmfcribbonstatusbar-class.md)
