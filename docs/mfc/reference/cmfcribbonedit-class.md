---
title: Classe CMFCRibbonEdit
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::CanBeStretched
- AFXRIBBONEDIT/CMFCRibbonEdit::CopyFrom
- AFXRIBBONEDIT/CMFCRibbonEdit::CreateEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::DestroyCtrl
- AFXRIBBONEDIT/CMFCRibbonEdit::DropDownList
- AFXRIBBONEDIT/CMFCRibbonEdit::EnableSpinButtons
- AFXRIBBONEDIT/CMFCRibbonEdit::GetCompactSize
- AFXRIBBONEDIT/CMFCRibbonEdit::GetEditText
- AFXRIBBONEDIT/CMFCRibbonEdit::GetIntermediateSize
- AFXRIBBONEDIT/CMFCRibbonEdit::GetTextAlign
- AFXRIBBONEDIT/CMFCRibbonEdit::GetWidth
- AFXRIBBONEDIT/CMFCRibbonEdit::HasCompactMode
- AFXRIBBONEDIT/CMFCRibbonEdit::HasFocus
- AFXRIBBONEDIT/CMFCRibbonEdit::HasLargeMode
- AFXRIBBONEDIT/CMFCRibbonEdit::HasSpinButtons
- AFXRIBBONEDIT/CMFCRibbonEdit::IsHighlighted
- AFXRIBBONEDIT/CMFCRibbonEdit::OnAfterChangeRect
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDraw
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDrawLabelAndImage
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDrawOnList
- AFXRIBBONEDIT/CMFCRibbonEdit::OnEnable
- AFXRIBBONEDIT/CMFCRibbonEdit::OnHighlight
- AFXRIBBONEDIT/CMFCRibbonEdit::OnKey
- AFXRIBBONEDIT/CMFCRibbonEdit::OnLButtonDown
- AFXRIBBONEDIT/CMFCRibbonEdit::OnLButtonUp
- AFXRIBBONEDIT/CMFCRibbonEdit::OnRTLChanged
- AFXRIBBONEDIT/CMFCRibbonEdit::OnShow
- AFXRIBBONEDIT/CMFCRibbonEdit::Redraw
- AFXRIBBONEDIT/CMFCRibbonEdit::SetACCData
- AFXRIBBONEDIT/CMFCRibbonEdit::SetEditText
- AFXRIBBONEDIT/CMFCRibbonEdit::SetTextAlign
- AFXRIBBONEDIT/CMFCRibbonEdit::SetWidth
helpviewer_keywords:
- CMFCRibbonEdit [MFC], CMFCRibbonEdit
- CMFCRibbonEdit [MFC], CanBeStretched
- CMFCRibbonEdit [MFC], CMFCRibbonEdit
- CMFCRibbonEdit [MFC], CopyFrom
- CMFCRibbonEdit [MFC], CreateEdit
- CMFCRibbonEdit [MFC], DestroyCtrl
- CMFCRibbonEdit [MFC], DropDownList
- CMFCRibbonEdit [MFC], EnableSpinButtons
- CMFCRibbonEdit [MFC], GetCompactSize
- CMFCRibbonEdit [MFC], GetEditText
- CMFCRibbonEdit [MFC], GetIntermediateSize
- CMFCRibbonEdit [MFC], GetTextAlign
- CMFCRibbonEdit [MFC], GetWidth
- CMFCRibbonEdit [MFC], HasCompactMode
- CMFCRibbonEdit [MFC], HasFocus
- CMFCRibbonEdit [MFC], HasLargeMode
- CMFCRibbonEdit [MFC], HasSpinButtons
- CMFCRibbonEdit [MFC], IsHighlighted
- CMFCRibbonEdit [MFC], OnAfterChangeRect
- CMFCRibbonEdit [MFC], OnDraw
- CMFCRibbonEdit [MFC], OnDrawLabelAndImage
- CMFCRibbonEdit [MFC], OnDrawOnList
- CMFCRibbonEdit [MFC], OnEnable
- CMFCRibbonEdit [MFC], OnHighlight
- CMFCRibbonEdit [MFC], OnKey
- CMFCRibbonEdit [MFC], OnLButtonDown
- CMFCRibbonEdit [MFC], OnLButtonUp
- CMFCRibbonEdit [MFC], OnRTLChanged
- CMFCRibbonEdit [MFC], OnShow
- CMFCRibbonEdit [MFC], Redraw
- CMFCRibbonEdit [MFC], SetACCData
- CMFCRibbonEdit [MFC], SetEditText
- CMFCRibbonEdit [MFC], SetTextAlign
- CMFCRibbonEdit [MFC], SetWidth
ms.assetid: 9b85f1f2-446b-454e-9af9-104fdad8a897
ms.openlocfilehash: 4f973074fbec3d04b1c1a74852b02ff2564217c1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504943"
---
# <a name="cmfcribbonedit-class"></a>Classe CMFCRibbonEdit

Implementa um controle de edição que está localizado em uma barra de faixa de faixas.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonEdit : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonEdit::CMFCRibbonEdit](#cmfcribbonedit)|Constrói um objeto `CMFCRibbonEdit`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonEdit::CanBeStretched](#canbestretched)|Indica se a altura do `CMFCRibbonEdit` controle pode aumentar verticalmente para a altura de uma linha da faixa de faixas.|
|[CMFCRibbonEdit::CMFCRibbonEdit](#cmfcribbonedit)|Constrói um objeto `CMFCRibbonEdit`.|
|[CMFCRibbonEdit::CopyFrom](#copyfrom)|Copia o estado do objeto especificado `CMFCRibbonEdit` para o objeto atual `CMFCRibbonEdit` .|
|[CMFCRibbonEdit::CreateEdit](#createedit)|Cria uma nova caixa de texto para `CMFCRibbonEdit` o objeto.|
|[CMFCRibbonEdit::DestroyCtrl](#destroyctrl)|Destrói o `CMFCRibbonEdit` objeto.|
|[CMFCRibbonEdit::DropDownList](#dropdownlist)|Desce uma caixa de listagem.|
|[CMFCRibbonEdit::EnableSpinButtons](#enablespinbuttons)|Habilita e define o intervalo do botão de rotação para a caixa de texto.|
|[CMFCRibbonEdit::GetCompactSize](#getcompactsize)|Recupera o tamanho do Compact do `CFMCRibbonEdit` objeto.|
|[CMFCRibbonEdit::GetEditText](#getedittext)|Recupera o texto na caixa de texto.|
|[CMFCRibbonEdit::GetIntermediateSize](#getintermediatesize)|Recupera o tamanho intermediário do `CMFCRibbonEdit` objeto.|
|[CMFCRibbonEdit::GetTextAlign](#gettextalign)|Recupera o alinhamento do texto na caixa de texto.|
|[CMFCRibbonEdit::GetWidth](#getwidth)|Recupera a largura, em pixels, do `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::HasCompactMode](#hascompactmode)|Indica se o tamanho `CMFCRibbonEdit` de exibição do controle pode ser compacto.|
|[CMFCRibbonEdit::HasFocus](#hasfocus)|Indica se o `CMFCRIbbonEdit` controle tem o foco.|
|[CMFCRibbonEdit::HasLargeMode](#haslargemode)|Indica se o tamanho `CMFCRibbonEdit` de exibição do controle pode ser grande.|
|[CMFCRibbonEdit::HasSpinButtons](#hasspinbuttons)|Indica se a caixa de texto tem um botão de rotação.|
|[CMFCRibbonEdit::IsHighlighted](#ishighlighted)|Indica se o `CMFCRibbonEdit` controle está realçado.|
|[CMFCRibbonEdit::OnAfterChangeRect](#onafterchangerect)|Chamado pelo Framework quando as dimensões do retângulo `CMFCRibbonEdit` de exibição do controle são alteradas.|
|[CMFCRibbonEdit::OnDraw](#ondraw)|Chamado pelo Framework para desenhar o `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::OnDrawLabelAndImage](#ondrawlabelandimage)|Chamado pelo Framework para desenhar o rótulo e a imagem do `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::OnDrawOnList](#ondrawonlist)|Chamado pelo Framework para desenhar o `CMFCRibbonEdit` controle em uma caixa de listagem de comandos.|
|[CMFCRibbonEdit::OnEnable](#onenable)|Chamado pelo Framework para habilitar ou desabilitar o `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::OnHighlight](#onhighlight)|Chamado pelo Framework quando o ponteiro entra ou sai dos limites do `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::OnKey](#onkey)|Chamado pelo Framework quando o usuário pressiona um KeyTip e o `CMFCRibbonEdit` controle tem o foco.|
|[CMFCRibbonEdit::OnLButtonDown](#onlbuttondown)|Chamado pelo Framework para atualizar o `CMFCRibbonEdit` controle quando o usuário pressiona o botão esquerdo do mouse no controle.|
|[CMFCRibbonEdit::OnLButtonUp](#onlbuttonup)|Chamado pelo Framework quando o usuário libera o botão esquerdo do mouse.|
|[CMFCRibbonEdit::OnRTLChanged](#onrtlchanged)|Chamado pelo Framework para atualizar o `CMFCRibbonEdit` controle quando o layout muda de direção.|
|[CMFCRibbonEdit::OnShow](#onshow)|Chamado pelo Framework para mostrar ou ocultar o `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::Redraw](#redraw)|Atualiza a exibição do `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::SetACCData](#setaccdata)|Define os dados de acessibilidade para `CMFCRibbonEdit` o objeto.|
|[CMFCRibbonEdit::SetEditText](#setedittext)|Define o texto na caixa de texto.|
|[CMFCRibbonEdit::SetTextAlign](#settextalign)|Define o alinhamento de texto da caixa de texto.|
|[CMFCRibbonEdit::SetWidth](#setwidth)|Define a largura da caixa `CMFCRibbonEdit` de texto do controle.|

## <a name="remarks"></a>Comentários

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCRibbonEdit` objeto, mostrar botões de rotação ao lado do controle de edição e definir o texto do controle de edição. Este trecho de código faz parte do [exemplo de demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#7](../../mfc/reference/codesnippet/cpp/cmfcribbonedit-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonEdit. h

##  <a name="canbestretched"></a>  CMFCRibbonEdit::CanBeStretched

Indica se a altura do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode aumentar verticalmente para a altura de uma linha da faixa de faixas.

```
virtual BOOL CanBeStretched();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna FALSE.

### <a name="remarks"></a>Comentários

##  <a name="cmfcribbonedit"></a>CMFCRibbonEdit::CMFCRibbonEdit

Constrói um objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
CMFCRibbonEdit(
    UINT nID,
    int nWidth,
    LPCTSTR lpszLabel = NULL,
    int nImage = -1);

CMFCRibbonEdit();
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
no ID de comando do `CMFCRibbonEdit` controle.

*nWidth*<br/>
no A largura, em pixels, da caixa `CMFCRibbonEdit` de texto do controle.

*lpszLabel*<br/>
no O rótulo `CMFCRibbonEdit` do controle.

*nImage*<br/>
no Índice da imagem pequena a ser usada para o `CMFCRibbonEdit` controle. A coleção de imagens pequenas é mantida pela categoria pai da faixa de faixas.

### <a name="remarks"></a>Comentários

O `CMFCRibbonEdit` controle não usa uma imagem grande.

##  <a name="copyfrom"></a>  CMFCRibbonEdit::CopyFrom

Copia o estado do objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) especificado para o objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) atual.

```
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no O objeto `CMFCRibbonEdit` de origem.

### <a name="remarks"></a>Comentários

O parâmetro *src* deve ser do tipo `CMFCRibbonEdit`.

##  <a name="createedit"></a>CMFCRibbonEdit:: CreateEdit

Cria uma nova caixa de texto para o objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual CMFCRibbonRichEditCtrl* CreateEdit(
    CWnd* pWndParent,
    DWORD dwEditStyle);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Um ponteiro para a janela pai do `CMFCRibbonEdit` objeto.

*dwEditStyle*<br/>
no Especifica o estilo da caixa de texto. Você pode combinar os estilos de janela listados na seção comentários com os [estilos de controle de edição](/windows/win32/Controls/edit-control-styles) descritos no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a nova caixa de texto se o método foi bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para criar uma caixa de texto Personalizada.

Você pode aplicar os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a uma caixa de texto:

- **WS_CHILD**

- **WS_VISIBLE**

- **WS_DISABLED**

- **WS_GROUP**

- **WS_TABSTOP**

##  <a name="destroyctrl"></a>  CMFCRibbonEdit::DestroyCtrl

Destrói o objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void DestroyCtrl();
```

### <a name="remarks"></a>Comentários

##  <a name="dropdownlist"></a>  CMFCRibbonEdit::DropDownList

Desce uma caixa de listagem.

```
virtual void DropDownList();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método não faz nada. Substitua esse método para listar uma caixa de listagem.

##  <a name="enablespinbuttons"></a>CMFCRibbonEdit::EnableSpinButtons

Habilita e define o intervalo do botão de rotação para a caixa de texto.

```
void EnableSpinButtons(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
no O valor mínimo do botão de rotação.

*nMax*<br/>
no O valor máximo do botão de rotação.

### <a name="remarks"></a>Comentários

Os botões de rotação exibem uma seta para cima e para baixo e permitem que os usuários se movimentem por um conjunto fixo de valores.

##  <a name="getcompactsize"></a>CMFCRibbonEdit::GetCompactSize

Recupera o tamanho compacto do objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o objeto.

### <a name="return-value"></a>Valor de retorno

O tamanho do Compact do `CMFCRibbonEdit` objeto.

### <a name="remarks"></a>Comentários

##  <a name="getedittext"></a>  CMFCRibbonEdit::GetEditText

Recupera o texto na caixa de texto.

```
CString GetEditText() const;
```

### <a name="return-value"></a>Valor de retorno

O texto na caixa de texto.

### <a name="remarks"></a>Comentários

##  <a name="getintermediatesize"></a>CMFCRibbonEdit::GetIntermediateSize

Recupera o tamanho intermediário do objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o objeto.

### <a name="return-value"></a>Valor de retorno

O tamanho intermediário do `CMFCRibbonEdit` objeto.

### <a name="remarks"></a>Comentários

##  <a name="gettextalign"></a>  CMFCRibbonEdit::GetTextAlign

Recupera o alinhamento do texto na caixa de texto.

```
int GetTextAlign() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor enumerado de alinhamento de texto. Consulte a seção comentários para obter os valores possíveis.

### <a name="remarks"></a>Comentários

O valor retornado é um dos seguintes estilos de controle de edição:

- **ES_LEFT** para alinhamento à esquerda

- **ES_CENTER** para alinhamento de centro

- **ES_RIGHT** para alinhamento à direita

Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles).

##  <a name="getwidth"></a>  CMFCRibbonEdit::GetWidth

Recupera a largura, em pixels, do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
int GetWidth(BOOL bInFloatyMode = FALSE) const;
```

### <a name="parameters"></a>Parâmetros

*bInFloatyMode*<br/>
no TRUE se o `CMFCRibbonEdit` controle estiver no modo flutuante; caso contrário, false.

### <a name="return-value"></a>Valor de retorno

A largura, em pixels, do `CMFCRibbonEdit` controle.

### <a name="remarks"></a>Comentários

##  <a name="hascompactmode"></a>CMFCRibbonEdit::HasCompactMode

Indica se o tamanho de exibição do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode ser compactado.

```
virtual BOOL HasCompactMode() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna TRUE. Substitua esse método para indicar se o tamanho de exibição pode ser compacto.

##  <a name="hasfocus"></a>  CMFCRibbonEdit::HasFocus

Indica se o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) tem o foco.

```
virtual BOOL HasFocus() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o `CMFCRibbonEdit` controle tiver o foco; caso contrário, false.

### <a name="remarks"></a>Comentários

##  <a name="haslargemode"></a>  CMFCRibbonEdit::HasLargeMode

Indica se o tamanho de exibição do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode ser grande.

```
virtual BOOL HasLargeMode() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna FALSE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna FALSE. Substitua esse método para indicar se o tamanho de exibição pode ser grande.

##  <a name="hasspinbuttons"></a>  CMFCRibbonEdit::HasSpinButtons

Indica se a caixa de texto tem um botão de rotação.

```
virtual BOOL HasSpinButtons() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de texto tiver um botão de rotação; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ishighlighted"></a>  CMFCRibbonEdit::IsHighlighted

Indica se o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) está realçado.

```
virtual BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o `CMFCRibbonEdit` controle estiver realçado; caso contrário, false.

### <a name="remarks"></a>Comentários

##  <a name="onafterchangerect"></a>  CMFCRibbonEdit::OnAfterChangeRect

Chamado pelo Framework quando as dimensões do retângulo de exibição do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) são alteradas.

```
virtual void OnAfterChangeRect(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o controle.

### <a name="remarks"></a>Comentários

##  <a name="ondraw"></a>CMFCRibbonEdit:: OnDraw

Chamado pelo Framework para desenhar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o controle.

### <a name="remarks"></a>Comentários

##  <a name="ondrawlabelandimage"></a>  CMFCRibbonEdit::OnDrawLabelAndImage

Chamado pelo Framework para desenhar o rótulo e a imagem para o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void OnDrawLabelAndImage(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o controle.

### <a name="remarks"></a>Comentários

##  <a name="ondrawonlist"></a>CMFCRibbonEdit::OnDrawOnList

Chamado pelo Framework para desenhar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) em uma caixa de listagem de comandos.

```
virtual void OnDrawOnList(
    CDC* pDC,
    CString strText,
    int nTextOffset,
    CRect rect,
    BOOL bIsSelected,
    BOOL bHighlighted);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo para `CMFCRibbonEdit` o controle.

*strText*<br/>
no A [](../../mfc/reference/cmfcribbonedit-class.md "classe CMFCRibbonEdit") de texto de exibição.

*nTextOffset*<br/>
no Distância, em pixels, do lado esquerdo da caixa de listagem até o texto de exibição.

*rect*<br/>
no O retângulo de exibição do `CMFCRibbonEdit` controle.

*bIsSelected*<br/>
no Esse parâmetro não é usado.

*bHighlighted*<br/>
no Esse parâmetro não é usado.

### <a name="remarks"></a>Comentários

A caixa de listagem comandos exibe os controles da faixa de lista para permitir que os usuários personalizem a barra de ferramentas de acesso rápido.

##  <a name="onenable"></a>CMFCRibbonEdit:: OnEnable

Chamado pelo Framework para habilitar ou desabilitar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void OnEnable(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no TRUE para habilitar o controle; FALSE para desabilitar o controle.

### <a name="remarks"></a>Comentários

##  <a name="onhighlight"></a>  CMFCRibbonEdit::OnHighlight

Chamado pelo Framework quando o ponteiro entra ou sai dos limites do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void OnHighlight(BOOL bHighlight);
```

### <a name="parameters"></a>Parâmetros

*bHighlight*<br/>
no TRUE se o ponteiro estiver nos limites do `CMFCRibbonEdit` controle; caso contrário, false.

### <a name="remarks"></a>Comentários

##  <a name="onkey"></a>CMFCRibbonEdit::OnKey

Chamado pelo Framework quando o usuário pressiona um KeyTip e o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) tem o foco.

```
virtual BOOL OnKey(BOOL bIsMenuKey);
```

### <a name="parameters"></a>Parâmetros

*bIsMenuKey*<br/>
no TRUE se o KeyTip exibir um menu pop-up; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

TRUE se o evento foi tratado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="onlbuttondown"></a>  CMFCRibbonEdit::OnLButtonDown

Chamado pelo Framework para atualizar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) quando o usuário pressiona o botão esquerdo do mouse no controle.

```
virtual void OnLButtonDown(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
no Esse parâmetro não é usado.

### <a name="remarks"></a>Comentários

##  <a name="onlbuttonup"></a>  CMFCRibbonEdit::OnLButtonUp

Chamado pelo Framework quando o usuário libera o botão esquerdo do mouse.

```
virtual void OnLButtonUp(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
no Esse parâmetro não é usado.

### <a name="remarks"></a>Comentários

##  <a name="onrtlchanged"></a>CMFCRibbonEdit::OnRTLChanged

Chamado pelo Framework para atualizar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) quando o layout muda de direção.

```
virtual void OnRTLChanged(BOOL bIsRTL);
```

### <a name="parameters"></a>Parâmetros

*bIsRTL*<br/>
no TRUE se o layout for da direita para a esquerda; FALSE se o layout for da esquerda para a direita.

### <a name="remarks"></a>Comentários

##  <a name="onshow"></a>  CMFCRibbonEdit::OnShow

Chamado pelo Framework para mostrar ou ocultar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no TRUE para mostrar o controle; FALSE para ocultar o controle.

### <a name="remarks"></a>Comentários

##  <a name="redraw"></a>CMFCRibbonEdit:: redesenhar

Atualiza a exibição do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual void Redraw();
```

### <a name="remarks"></a>Comentários

Esse método redesenha o retângulo de exibição para o `CMFCRibbonEdit` objeto chamando indiretamente [CWnd:: RedrawWindow](/windows/win32/api/winuser/nf-winuser-redrawwindow) com os sinalizadores RDW_INVALIDATE, RDW_ERASE e RDW_UPDATENOW definidos.

##  <a name="setaccdata"></a>  CMFCRibbonEdit::SetACCData

Define os dados de acessibilidade para o objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
Ponteiro para a janela pai do `CMFCRibbonEdit` objeto.

*data*<br/>
Os dados de acessibilidade para `CMFCRibbonEdit` o objeto.

### <a name="return-value"></a>Valor de retorno

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

##  <a name="setedittext"></a>  CMFCRibbonEdit::SetEditText

Define o texto na caixa de texto.

```
void SetEditText(CString strText);
```

### <a name="parameters"></a>Parâmetros

*strText*<br/>
no O texto da caixa de texto.

##  <a name="settextalign"></a>  CMFCRibbonEdit::SetTextAlign

Define o alinhamento de texto da caixa de texto.

```
void SetTextAlign(int nAlign);
```

### <a name="parameters"></a>Parâmetros

*nAlign*<br/>
no Um valor enumerado de alinhamento de texto. Consulte a seção comentários para obter os valores possíveis.

### <a name="remarks"></a>Comentários

O parâmetro *nAlign* é um dos seguintes estilos de controle de edição:

- ES_LEFT para alinhamento à esquerda

- ES_CENTER para alinhamento de centro

- ES_RIGHT para alinhamento à direita

Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles).

##  <a name="setwidth"></a>  CMFCRibbonEdit::SetWidth

Define a largura da caixa de texto para o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) .

```
void SetWidth(
    int nWidth,
    BOOL bInFloatyMode = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
no A largura, em pixels, da caixa de texto.

*bInFloatyMode*<br/>
TRUE para definir a largura para o modo flutuante; FALSE para definir a largura do modo normal.

### <a name="remarks"></a>Comentários

O `CMFCRibbonEdit` controle tem duas larguras, dependendo do seu modo de exibição: modo flutuante e modo normal.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
