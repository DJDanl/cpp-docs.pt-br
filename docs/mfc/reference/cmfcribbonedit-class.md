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
ms.openlocfilehash: ab621a05f9b658eee9babb14e257680fa95e0f96
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375173"
---
# <a name="cmfcribbonedit-class"></a>Classe CMFCRibbonEdit

Implementa um controle de edição localizado em uma barra de fita.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CMFCRibbonEdit::CanBeStretched](#canbestretched)|Indica se a `CMFCRibbonEdit` altura do controle pode aumentar verticalmente até a altura de uma linha de fita.|
|[CMFCRibbonEdit::CMFCRibbonEdit](#cmfcribbonedit)|Constrói um objeto `CMFCRibbonEdit`.|
|[CMFCRibbonEdit:::CopyFrom](#copyfrom)|Copia o estado do `CMFCRibbonEdit` objeto especificado para o objeto atual. `CMFCRibbonEdit`|
|[CMFCRibbonEdit::CreateEdit](#createedit)|Cria uma nova caixa `CMFCRibbonEdit` de texto para o objeto.|
|[CMFCRibbonEdit::DestroyCtrl](#destroyctrl)|Destrói o `CMFCRibbonEdit` objeto.|
|[CMFCRibbonEdit::DropDownList](#dropdownlist)|Derruba uma caixa de lista.|
|[CMFCRibbonEdit::EnableSpinButtons](#enablespinbuttons)|Habilita e define o intervalo do botão de rotação para a caixa de texto.|
|[CMFCRibbonEdit::GetCompactSize](#getcompactsize)|Recupera o tamanho compacto `CFMCRibbonEdit` do objeto.|
|[CMFCRibbonEdit::GetEditText](#getedittext)|Recupera o texto na caixa de texto.|
|[CMFCRibbonedit::GetIntermediateSize](#getintermediatesize)|Recupera o tamanho intermediário `CMFCRibbonEdit` do objeto.|
|[CMFCRibbonEdit::GetTextalign](#gettextalign)|Recupera o alinhamento do texto na caixa de texto.|
|[CMFCRibbonEdit::GetWidth](#getwidth)|Recupera a largura, em pixels, do `CMFCRibbonEdit` controle.|
|[CMFCRibbonEdit::HasCompactmode](#hascompactmode)|Indica se o tamanho `CMFCRibbonEdit` do display para o controle pode ser compacto.|
|[CMFCRibbonedit::HasFocus](#hasfocus)|Indica se `CMFCRIbbonEdit` o controle tem o foco.|
|[CMFCRibbonedit::HasLargemode](#haslargemode)|Indica se o tamanho `CMFCRibbonEdit` do display para o controle pode ser grande.|
|[CMFCRibbonEdit::HasSpinButtons](#hasspinbuttons)|Indica se a caixa de texto tem um botão de rotação.|
|[CMFCRibbonedit::ishighlighted](#ishighlighted)|Indica se `CMFCRibbonEdit` o controle está destacado.|
|[CMFCRibbonEdit::OnAfterChangeRect](#onafterchangerect)|Chamado pela estrutura quando as dimensões do retângulo do display para as alterações de `CMFCRibbonEdit` controle.|
|[CMFCRibbonedit::OnDraw](#ondraw)|Chamado pela estrutura para `CMFCRibbonEdit` desenhar o controle.|
|[CMFCRibbonedit::OnDrawlabelandImage](#ondrawlabelandimage)|Chamado pela estrutura para desenhar o `CMFCRibbonEdit` rótulo e a imagem para o controle.|
|[CMFCRibbonedit::Ondrawonlist](#ondrawonlist)|Chamado pela estrutura para `CMFCRibbonEdit` desenhar o controle em uma caixa de lista de comandos.|
|[CMFCRibbonedit::OnEnable](#onenable)|Chamado pela estrutura para ativar `CMFCRibbonEdit` ou desativar o controle.|
|[CMFCRibbonedit::OnHighlight](#onhighlight)|Chamado pela estrutura quando o ponteiro entra ou `CMFCRibbonEdit` sai dos limites do controle.|
|[CMFCRibbonedit::OnKey](#onkey)|Chamado pelo framework quando o usuário pressiona `CMFCRibbonEdit` uma dica de tecla e o controle tem o foco.|
|[CMFCRibbonedit::OnlbuttonDown](#onlbuttondown)|Chamado pela estrutura para `CMFCRibbonEdit` atualizar o controle quando o usuário pressiona o botão esquerdo do mouse no controle.|
|[CMFCRibbonedit::Onlbuttonup](#onlbuttonup)|Chamado pela estrutura quando o usuário libera o botão esquerdo do mouse.|
|[CMFCRibbonedit::OnRTLChanged](#onrtlchanged)|Chamado pelo framework para `CMFCRibbonEdit` atualizar o controle quando o layout muda de direção.|
|[CMFCRibbonedit::OnShow](#onshow)|Chamado pela estrutura para mostrar `CMFCRibbonEdit` ou esconder o controle.|
|[CMFCRibbonEdit::Redesenhar](#redraw)|Atualiza a exibição `CMFCRibbonEdit` do controle.|
|[CMFCRibbonEdit::setACCData](#setaccdata)|Define os dados de `CMFCRibbonEdit` acessibilidade para o objeto.|
|[CMFCRibbonEdit::setEditText](#setedittext)|Define o texto na caixa de texto.|
|[CMFCRibbonEdit::SetTextAlign](#settextalign)|Define o alinhamento de texto da caixa de texto.|
|[CMFCRibbonEdit::SetWidth](#setwidth)|Define a largura da caixa `CMFCRibbonEdit` de texto para o controle.|

## <a name="remarks"></a>Comentários

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCRibbonEdit` demonstra como construir um objeto, mostrar botões de rotação ao lado do controle de edição e definir o texto do controle de edição. Este trecho de código faz parte da amostra de [demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#7](../../mfc/reference/codesnippet/cpp/cmfcribbonedit-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonEdit.h

## <a name="cmfcribboneditcanbestretched"></a><a name="canbestretched"></a>CMFCRibbonEdit::CanBeStretched

Indica se a altura do controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode aumentar verticalmente até a altura de uma linha de fita.

```cpp
virtual BOOL CanBeStretched();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditcmfcribbonedit"></a><a name="cmfcribbonedit"></a>CMFCRibbonEdit::CMFCRibbonEdit

Constrói um objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
CMFCRibbonEdit(
    UINT nID,
    int nWidth,
    LPCTSTR lpszLabel = NULL,
    int nImage = -1);

CMFCRibbonEdit();
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] ID de `CMFCRibbonEdit` comando para o controle.

*Nwidth*<br/>
[em] A largura, em pixels, da `CMFCRibbonEdit` caixa de texto para o controle.

*lpszLabel*<br/>
[em] O rótulo `CMFCRibbonEdit` para o controle.

*Nimage*<br/>
[em] Índice da pequena imagem para `CMFCRibbonEdit` usar para o controle. A coleção de pequenas imagens é mantida pela categoria fita dos pais.

### <a name="remarks"></a>Comentários

O `CMFCRibbonEdit` controle não usa uma imagem grande.

## <a name="cmfcribboneditcopyfrom"></a><a name="copyfrom"></a>CMFCRibbonEdit:::CopyFrom

Copia o estado do objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) especificado para o objeto [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) atual.

```cpp
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] O `CMFCRibbonEdit` objeto de origem.

### <a name="remarks"></a>Comentários

O parâmetro *src* deve `CMFCRibbonEdit`ser do tipo .

## <a name="cmfcribboneditcreateedit"></a><a name="createedit"></a>CMFCRibbonEdit::CreateEdit

Cria uma nova caixa de texto para o objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual CMFCRibbonRichEditCtrl* CreateEdit(
    CWnd* pWndParent,
    DWORD dwEditStyle);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a `CMFCRibbonEdit` janela pai do objeto.

*dwEditStyle*<br/>
[em] Especifica o estilo da caixa de texto. Você pode combinar os estilos de janela listados na seção Observações com os [estilos de controle de edição](/windows/win32/Controls/edit-control-styles) descritos no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a nova caixa de texto se o método foi bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Substituir este método em uma classe derivada para criar uma caixa de texto personalizada.

Você pode aplicar os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a uma caixa de texto:

- **Estilo**

- **Ws_visible**

- **Ws_disabled**

- **Ws_group**

- **Ws_tabstop**

## <a name="cmfcribboneditdestroyctrl"></a><a name="destroyctrl"></a>CMFCRibbonEdit::DestroyCtrl

Destrói o objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void DestroyCtrl();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditdropdownlist"></a><a name="dropdownlist"></a>CMFCRibbonEdit::DropDownList

Derruba uma caixa de lista.

```cpp
virtual void DropDownList();
```

### <a name="remarks"></a>Comentários

Por padrão, este método não faz nada. Anular este método para baixar uma caixa de lista.

## <a name="cmfcribboneditenablespinbuttons"></a><a name="enablespinbuttons"></a>CMFCRibbonEdit::EnableSpinButtons

Habilita e define o intervalo do botão de rotação para a caixa de texto.

```cpp
void EnableSpinButtons(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
[em] O valor mínimo do botão de giro.

*Nmax*<br/>
[em] O valor máximo do botão de giro.

### <a name="remarks"></a>Comentários

Os botões de rotação exibem uma seta para cima e para baixo e permitem que os usuários se movam através de um conjunto fixo de valores.

## <a name="cmfcribboneditgetcompactsize"></a><a name="getcompactsize"></a>CMFCRibbonEdit::GetCompactSize

Recupera o tamanho compacto do objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o objeto.

### <a name="return-value"></a>Valor retornado

O tamanho compacto `CMFCRibbonEdit` do objeto.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditgetedittext"></a><a name="getedittext"></a>CMFCRibbonEdit::GetEditText

Recupera o texto na caixa de texto.

```cpp
CString GetEditText() const;
```

### <a name="return-value"></a>Valor retornado

O texto na caixa de texto.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditgetintermediatesize"></a><a name="getintermediatesize"></a>CMFCRibbonedit::GetIntermediateSize

Recupera o tamanho intermediário do objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o objeto.

### <a name="return-value"></a>Valor retornado

O tamanho intermediário `CMFCRibbonEdit` do objeto.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditgettextalign"></a><a name="gettextalign"></a>CMFCRibbonEdit::GetTextalign

Recupera o alinhamento do texto na caixa de texto.

```cpp
int GetTextAlign() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de alinhamento de texto enumerado. Consulte a seção Observações para obter possíveis valores.

### <a name="remarks"></a>Comentários

O valor retornado é um dos seguintes estilos de controle de edição:

- **ES_LEFT** para alinhamento à esquerda

- **ES_CENTER** para alinhamento central

- **ES_RIGHT** para alinhamento certo

Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles).

## <a name="cmfcribboneditgetwidth"></a><a name="getwidth"></a>CMFCRibbonEdit::GetWidth

Recupera a largura, em pixels, do controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
int GetWidth(BOOL bInFloatyMode = FALSE) const;
```

### <a name="parameters"></a>Parâmetros

*bInFloatyMode*<br/>
[em] TRUE se `CMFCRibbonEdit` o controle estiver no modo flutuante; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

A largura, em pixels, do `CMFCRibbonEdit` controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonedithascompactmode"></a><a name="hascompactmode"></a>CMFCRibbonEdit::HasCompactmode

Indica se o tamanho do display para o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode ser compacto.

```cpp
virtual BOOL HasCompactMode() const;
```

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, este método sempre retorna TRUE. Anular este método para indicar se o tamanho do display pode ser compacto.

## <a name="cmfcribbonedithasfocus"></a><a name="hasfocus"></a>CMFCRibbonedit::HasFocus

Indica se o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) tem o foco.

```cpp
virtual BOOL HasFocus() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se `CMFCRibbonEdit` o controle tiver o foco; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonedithaslargemode"></a><a name="haslargemode"></a>CMFCRibbonedit::HasLargemode

Indica se o tamanho do display para o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) pode ser grande.

```cpp
virtual BOOL HasLargeMode() const;
```

### <a name="return-value"></a>Valor retornado

Sempre retorna FALSO.

### <a name="remarks"></a>Comentários

Por padrão, este método sempre retorna FALSO. Anular este método para indicar se o tamanho do display pode ser grande.

## <a name="cmfcribbonedithasspinbuttons"></a><a name="hasspinbuttons"></a>CMFCRibbonEdit::HasSpinButtons

Indica se a caixa de texto tem um botão de rotação.

```cpp
virtual BOOL HasSpinButtons() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a caixa de texto tiver um botão de giro; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditishighlighted"></a><a name="ishighlighted"></a>CMFCRibbonedit::ishighlighted

Indica se o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) está destacado.

```cpp
virtual BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se `CMFCRibbonEdit` o controle for destacado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonafterchangerect"></a><a name="onafterchangerect"></a>CMFCRibbonEdit::OnAfterChangeRect

Chamado pela estrutura quando as dimensões do retângulo do display para a alteração do controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnAfterChangeRect(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditondraw"></a><a name="ondraw"></a>CMFCRibbonedit::OnDraw

Chamado pela estrutura para desenhar o controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditondrawlabelandimage"></a><a name="ondrawlabelandimage"></a>CMFCRibbonedit::OnDrawlabelandImage

Chamado pela estrutura para desenhar o rótulo e a imagem para o controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnDrawLabelAndImage(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditondrawonlist"></a><a name="ondrawonlist"></a>CMFCRibbonedit::Ondrawonlist

Chamado pela estrutura para desenhar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) em uma caixa de lista de comandos.

```cpp
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
[em] Ponteiro para um contexto `CMFCRibbonEdit` de dispositivo para o controle.

*strText*<br/>
[em] O texto [ ](../../mfc/reference/cmfcribbonedit-class.md "cmfcribbonedit")de exibição .

*nTextOffset*<br/>
[em] Distância, em pixels, do lado esquerdo da caixa de lista para o texto de exibição.

*Rect*<br/>
[em] O retângulo do `CMFCRibbonEdit` display para o controle.

*bIsSelected*<br/>
[em] Este parâmetro não é usado.

*bHighlighted*<br/>
[em] Este parâmetro não é usado.

### <a name="remarks"></a>Comentários

A caixa de lista de comandos exibe controles de fita para permitir que os usuários personalizem a barra de ferramentas de acesso rápido.

## <a name="cmfcribboneditonenable"></a><a name="onenable"></a>CMFCRibbonedit::OnEnable

Chamado pela estrutura para ativar ou desativar o controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnEnable(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] VERDADEIRO para habilitar o controle; FALSO para desativar o controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonhighlight"></a><a name="onhighlight"></a>CMFCRibbonedit::OnHighlight

Chamado pelo framework quando o ponteiro entra ou sai dos limites do controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnHighlight(BOOL bHighlight);
```

### <a name="parameters"></a>Parâmetros

*bDestaque*<br/>
[em] VERDADE se o ponteiro estiver nos `CMFCRibbonEdit` limites do controle; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonkey"></a><a name="onkey"></a>CMFCRibbonedit::OnKey

Chamado pelo framework quando o usuário pressiona uma dica de tecla e o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) tem o foco.

```cpp
virtual BOOL OnKey(BOOL bIsMenuKey);
```

### <a name="parameters"></a>Parâmetros

*bIsMenukey*<br/>
[em] TRUE se a dica de chave exibir um menu pop-up; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

VERDADE se o evento foi tratado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonlbuttondown"></a><a name="onlbuttondown"></a>CMFCRibbonedit::OnlbuttonDown

Chamado pela estrutura para atualizar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) quando o usuário pressiona o botão esquerdo do mouse no controle.

```cpp
virtual void OnLButtonDown(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] Este parâmetro não é usado.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonlbuttonup"></a><a name="onlbuttonup"></a>CMFCRibbonedit::Onlbuttonup

Chamado pela estrutura quando o usuário libera o botão esquerdo do mouse.

```cpp
virtual void OnLButtonUp(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] Este parâmetro não é usado.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonrtlchanged"></a><a name="onrtlchanged"></a>CMFCRibbonedit::OnRTLChanged

Chamado pela estrutura para atualizar o controle [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) quando o layout muda de direção.

```cpp
virtual void OnRTLChanged(BOOL bIsRTL);
```

### <a name="parameters"></a>Parâmetros

*bIsRTL*<br/>
[em] TRUE se o layout for da direita para a esquerda; FALSO se o layout estiver da esquerda para a direita.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditonshow"></a><a name="onshow"></a>CMFCRibbonedit::OnShow

Chamado pela estrutura para mostrar ou ocultar o controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] VERDADEIRO para mostrar o controle; FALSO para esconder o controle.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditredraw"></a><a name="redraw"></a>CMFCRibbonEdit::Redesenhar

Atualiza a exibição do controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual void Redraw();
```

### <a name="remarks"></a>Comentários

Este método redesenha o retângulo de exibição para o `CMFCRibbonEdit` objeto, chamando indiretamente [cwnd::RedrawWindow](/windows/win32/api/winuser/nf-winuser-redrawwindow) com o conjunto de bandeiras RDW_INVALIDATE, RDW_ERASE e RDW_UPDATENOW definido.

## <a name="cmfcribboneditsetaccdata"></a><a name="setaccdata"></a>CMFCRibbonEdit::setACCData

Define os dados de acessibilidade para o objeto [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
Ponteiro para a janela `CMFCRibbonEdit` pai para o objeto.

*dados*<br/>
Os dados de `CMFCRibbonEdit` acessibilidade do objeto.

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboneditsetedittext"></a><a name="setedittext"></a>CMFCRibbonEdit::setEditText

Define o texto na caixa de texto.

```cpp
void SetEditText(CString strText);
```

### <a name="parameters"></a>Parâmetros

*strText*<br/>
[em] O texto para a caixa de texto.

## <a name="cmfcribboneditsettextalign"></a><a name="settextalign"></a>CMFCRibbonEdit::SetTextAlign

Define o alinhamento de texto da caixa de texto.

```cpp
void SetTextAlign(int nAlign);
```

### <a name="parameters"></a>Parâmetros

*nAlinhar*<br/>
[em] Um valor de alinhamento de texto enumerado. Consulte a seção Observações para obter possíveis valores.

### <a name="remarks"></a>Comentários

O parâmetro *nAlign* é um dos seguintes estilos de controle de edição:

- ES_LEFT para alinhamento à esquerda

- ES_CENTER para alinhamento central

- ES_RIGHT para alinhamento certo

Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles).

## <a name="cmfcribboneditsetwidth"></a><a name="setwidth"></a>CMFCRibbonEdit::SetWidth

Define a largura da caixa de texto para o controle [CMFCRibbonEdit.](../../mfc/reference/cmfcribbonedit-class.md)

```cpp
void SetWidth(
    int nWidth,
    BOOL bInFloatyMode = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
[em] A largura, em pixels, da caixa de texto.

*bInFloatyMode*<br/>
TRUE para definir a largura para o modo flutuante; FALSE para definir a largura para o modo regular.

### <a name="remarks"></a>Comentários

O `CMFCRibbonEdit` controle tem duas larguras dependendo do seu modo de exibição: modo flutuante e modo regular.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
