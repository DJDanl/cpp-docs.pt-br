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
ms.openlocfilehash: 9911672ec139ab1598db8005e9b7b909e85dd33d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410070"
---
# <a name="cmfcribbonstatusbarpane-class"></a>Classe CMFCRibbonStatusBarPane

O `CMFCRibbonStatusBarPane` classe implementa um elemento de faixa de opções que você pode adicionar a uma barra de status da faixa de opções.

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
|[CMFCRibbonStatusBarPane::GetAlmostLargeText](#getalmostlargetext)|Retorna a cadeia de caracteres que define a cadeia de caracteres de texto mais longa que pode ser exibida no painel sem truncamento.|
|[CMFCRibbonStatusBarPane::GetTextAlign](#gettextalign)|Retorna a configuração atual do alinhamento de texto.|
|[CMFCRibbonStatusBarPane::IsAnimation](#isanimation)|Determina se a animação está em andamento.|
|[CMFCRibbonStatusBarPane::IsExtended](#isextended)|Determina se o painel está localizado na área estendida da barra de status da faixa de opções.|
|[CMFCRibbonStatusBarPane::OnDrawBorder](#ondrawborder)|(Substitui [CMFCRibbonButton::OnDrawBorder](../../mfc/reference/cmfcribbonbutton-class.md#ondrawborder).)|
|[CMFCRibbonStatusBarPane::OnFillBackground](#onfillbackground)|(Substitui [CMFCRibbonButton::OnFillBackground](../../mfc/reference/cmfcribbonbutton-class.md#onfillbackground).)|
|[CMFCRibbonStatusBarPane::SetAlmostLargeText](#setalmostlargetext)|Define a cadeia de caracteres de texto mais longa que pode ser exibida no painel sem truncamento.|
|[CMFCRibbonStatusBarPane::SetAnimationList](#setanimationlist)|Atribui uma lista de imagens que pode ser usada para animação ao painel.|
|[CMFCRibbonStatusBarPane::SetTextAlign](#settextalign)|Define o alinhamento de texto.|
|[CMFCRibbonStatusBarPane::StartAnimation](#startanimation)|Inicia a animação que é atribuída ao painel.|
|[CMFCRibbonStatusBarPane::StopAnimation](#stopanimation)|Interrompe a animação que é atribuída ao painel. .|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBarPane::OnFinishAnimation](#onfinishanimation)|Chamado pelo framework quando interrompe a animação que é atribuída ao painel.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar os vários métodos no `CMFCRibbonStatusBarPane` classe. O exemplo mostra como construir um `CMFCRibbonStatusBarPane` de objeto, definir o alinhamento do texto do rótulo do painel da barra de status, definir o texto mais longo que pode ser exibida no painel da barra de status sem truncamento, anexar para o painel da barra de status de uma lista de imagens que pode ser usada para um omentários e iniciar a animação.

[!code-cpp[NVC_MFC_RibbonApp#2](../../mfc/reference/codesnippet/cpp/cmfcribbonstatusbarpane-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonStatusBarPane](../../mfc/reference/cmfcribbonstatusbarpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonstatusbarpane.h

##  <a name="cmfcribbonstatusbarpane"></a>  CMFCRibbonStatusBarPane::CMFCRibbonStatusBarPane

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

*nCmdID*<br/>
[in] Especifica a ID de comando do painel.

*lpszText*<br/>
[in] Especifica a cadeia de caracteres de texto a ser exibido no painel.

*bIsStatic*<br/>
[in] Se for TRUE, o painel de status não pode ser realçado ou selecionado clicando nele.

*hIcon*<br/>
[in] Especifica um identificador para um ícone a ser exibido no painel.

*lpszAlmostLargeText*<br/>
[in] Especifica a cadeia de caracteres de texto mais longa que pode ser exibida pelo painel.

*hBmpAnimationList*<br/>
[in] Especifica um identificador para uma lista de imagens que é usado para animação.

*cxAnimation*<br/>
[in] Especifica a largura, em pixels, do ícone na lista de imagens que é usado para animação.

*clrTrnsp*<br/>
[in] Especifica a cor transparente da imagens na lista de imagens que são usados para animação.

*uiAnimationListResID*<br/>
[in] Especifica uma ID de recurso de uma lista de imagens que é usada para animação.

##  <a name="getalmostlargetext"></a>  CMFCRibbonStatusBarPane::GetAlmostLargeText

Obtém a cadeia de caracteres de texto mais longa que o painel da barra de status pode exibir.

```
LPCTSTR GetAlmostLargeText() const;
```

### <a name="return-value"></a>Valor de retorno

A cadeia de texto mais longa que o painel da barra de status pode exibir.

##  <a name="gettextalign"></a>  CMFCRibbonStatusBarPane::GetTextAlign

Obtém a configuração atual do alinhamento do texto do rótulo do painel da barra de status.

```
int GetTextAlign() const;
```

### <a name="return-value"></a>Valor de retorno

O alinhamento de texto atual que pode ser um dos seguintes:

- TA_LEFT

- TA_CENTER

- TA_RIGHT.

##  <a name="isanimation"></a>  CMFCRibbonStatusBarPane::IsAnimation

Determina se a animação está em andamento.

```
BOOL IsAnimation() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a animação está em andamento. FALSE caso contrário.

##  <a name="isextended"></a>  CMFCRibbonStatusBarPane::IsExtended

Determine se o painel está localizado na área estendida da barra de status da faixa de opções.

```
BOOL IsExtended() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o painel está na área estendida da barra de status. FALSE caso contrário.

##  <a name="ondrawborder"></a>  CMFCRibbonStatusBarPane::OnDrawBorder

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual void OnDrawBorder(CDC*);
```

### <a name="parameters"></a>Parâmetros

[in] *CDC&#42;*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onfillbackground"></a>  CMFCRibbonStatusBarPane::OnFillBackground

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual COLORREF OnFillBackground(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onfinishanimation"></a>  CMFCRibbonStatusBarPane::OnFinishAnimation

Estrutura chama esse método quando termina a animação que é atribuída ao painel.

```
virtual void OnFinishAnimation();
```

### <a name="remarks"></a>Comentários

`StopAnimation` chamadas de método a `OnFinishAnimation` método, que você pode usar para limpar os dados quando a animação termina.

##  <a name="setalmostlargetext"></a>  CMFCRibbonStatusBarPane::SetAlmostLargeText

Defina o texto mais longo que pode ser exibido no painel da barra de status sem truncamento.

```
void SetAlmostLargeText(LPCTSTR lpszAlmostLargeText);
```

### <a name="parameters"></a>Parâmetros

*lpszAlmostLargeText*<br/>
[in] Especifica a cadeia de caracteres mais longa que pode ser exibida no painel de barra de status sem truncamento.

### <a name="remarks"></a>Comentários

A biblioteca calcula o tamanho do texto que *lpszAlmostLargeText* Especifica e redimensiona o painel de acordo. O texto será truncado se ele ainda não se ajustar no painel.

##  <a name="setanimationlist"></a>  CMFCRibbonStatusBarPane::SetAnimationList

Anexa uma lista de imagens que pode ser usada para animação para o painel da barra de status.

```
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
[in] Especifica um identificador para uma lista de imagens.

*cxAnimation*<br/>
[in] Especifica a largura, em pixels, do quadro na lista de imagens.

*clrTransp*<br/>
[in] Especifica a cor transparente da lista de imagens.

*uiAnimationListResID*<br/>
[in] Especifica a ID do recurso da lista de imagens.

### <a name="return-value"></a>Valor de retorno

TRUE se a lista de imagens é anexada com êxito para o painel da barra de status; FALSE caso contrário.

##  <a name="settextalign"></a>  CMFCRibbonStatusBarPane::SetTextAlign

Define o alinhamento do texto do rótulo do painel da barra de status.

```
void SetTextAlign(int nAlign);
```

### <a name="parameters"></a>Parâmetros

*nAlign*<br/>
[in] Especifica o alinhamento do texto.

### <a name="remarks"></a>Comentários

*nAlign* pode ter um dos seguintes valores:

- TA_LEFT: alinhamento à esquerda

- TA_CENTER: alinhamento centralizado

- TA_RIGHT: alinhamento à direita

##  <a name="startanimation"></a>  CMFCRibbonStatusBarPane::StartAnimation

Inicia a animação que você atribui ao painel.

```
void StartAnimation(
    UINT nFrameDelay=500,
    UINT nDuration=-1);
```

### <a name="parameters"></a>Parâmetros

*nFrameDelay*<br/>
[in] Especifica a taxa de quadros de animação, em milissegundos.

*nDuration*<br/>
[in] Especifica quanto para reproduzir a animação, em milissegundos. Use -1 para um loop infinito.

### <a name="remarks"></a>Comentários

Você deve especificar um identificador para uma lista de imagens antes de chamar `StartAnimation` usando `SetAnimationList`.

##  <a name="stopanimation"></a>  CMFCRibbonStatusBarPane::StopAnimation

Interrompe a animação que você atribuiu ao painel da barra de status.

```
void StopAnimation();
```

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)<br/>
[Classe CMFCRibbonStatusBar](../../mfc/reference/cmfcribbonstatusbar-class.md)
