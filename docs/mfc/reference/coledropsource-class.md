---
title: Classe COleDropSource
ms.date: 11/04/2016
f1_keywords:
- COleDropSource
- AFXOLE/COleDropSource
- AFXOLE/COleDropSource::COleDropSource
- AFXOLE/COleDropSource::GiveFeedback
- AFXOLE/COleDropSource::OnBeginDrag
- AFXOLE/COleDropSource::QueryContinueDrag
helpviewer_keywords:
- COleDropSource [MFC], COleDropSource
- COleDropSource [MFC], GiveFeedback
- COleDropSource [MFC], OnBeginDrag
- COleDropSource [MFC], QueryContinueDrag
ms.assetid: d3eecc5f-a70b-4a01-b705-7d2c098ebe17
ms.openlocfilehash: 324c4b7273f021b43c319fb0a494ac843856c78a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375017"
---
# <a name="coledropsource-class"></a>Classe COleDropSource

Permite que os dados sejam arrastados para um alvo de queda.

## <a name="syntax"></a>Sintaxe

```
class COleDropSource : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropFonte::COleDropSource](#coledropsource)|Constrói um objeto `COleDropSource`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropSource::GiveFeedback](#givefeedback)|Altera o cursor durante uma operação de arrastar e soltar.|
|[COleDropFonte::OnBeginDrag](#onbegindrag)|Lida com a captura do mouse durante uma operação de arrastar e soltar.|
|[COleDropFonte::QueryContinuaDrag](#querycontinuedrag)|Verifica se o arrasto deve continuar.|

## <a name="remarks"></a>Comentários

A classe [COleDropTarget](../../mfc/reference/coledroptarget-class.md) lida com a parte receptora da operação de arrastar e soltar. O `COleDropSource` objeto é responsável por determinar quando uma operação de arrasto começa, fornecer feedback durante a operação de arrasto e determinar quando a operação de arrasto termina.

Para usar `COleDropSource` um objeto, basta chamar o construtor. Isso simplifica o processo de determinação de quais eventos, como um clique do mouse, iniciam uma operação de arrasto usando [COleDataFonte::DoDragDrop,](../../mfc/reference/coledatasource-class.md#dodragdrop) [COleClientItem::DoDragDrop](../../mfc/reference/coleclientitem-class.md#dodragdrop)ou [COleServerItem::DoDragDrop.](../../mfc/reference/coleserveritem-class.md#dodragdrop) Essas funções criarão um `COleDropSource` objeto para você. Você pode querer modificar o `COleDropSource` comportamento padrão das funções superridíveis. Essas funções de membros serão chamadas nos momentos apropriados pelo quadro.

Para obter mais informações sobre operações de arrastar e soltar usando o OLE, consulte o artigo [OLE arrastar e soltar](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource](/windows/win32/api/oleidl/nn-oleidl-idropsource) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledropsourcecoledropsource"></a><a name="coledropsource"></a>COleDropFonte::COleDropSource

Constrói um objeto `COleDropSource`.

```
COleDropSource();
```

## <a name="coledropsourcegivefeedback"></a><a name="givefeedback"></a>COleDropSource::GiveFeedback

Chamado pela estrutura depois de chamar [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover) ou [COleDropTarget::DragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).

```
virtual SCODE GiveFeedback(DROPEFFECT dropEffect);
```

### <a name="parameters"></a>Parâmetros

*Dropeffect*<br/>
O efeito que você gostaria de exibir para o usuário, geralmente indicando o que aconteceria se uma queda ocorresse neste momento com os dados selecionados. Normalmente, este é o valor retornado pela chamada mais recente para [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter) ou [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover). Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

### <a name="return-value"></a>Valor retornado

Retorna DRAGDROP_S_USEDEFAULTCURSORS se arrastar estiver em andamento, NOERROR se não estiver.

### <a name="remarks"></a>Comentários

Anular essa função para fornecer feedback ao usuário sobre o que aconteceria se uma queda ocorresse neste momento. A implementação padrão usa os cursores padrão oLE. Para obter mais informações sobre operações de arrastar e soltar usando o OLE, consulte o artigo [OLE arrastar e soltar](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource::GiveFeedback](/windows/win32/api/oleidl/nf-oleidl-idropsource-givefeedback), [IDropTarget::DragOver](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragover)e [IDropTarget::DragEnter](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragenter) no Windows SDK.

## <a name="coledropsourceonbegindrag"></a><a name="onbegindrag"></a>COleDropFonte::OnBeginDrag

Chamado pela estrutura quando ocorre um evento que pode iniciar uma operação de arrasto, como pressionar o botão esquerdo do mouse.

```
virtual BOOL OnBeginDrag(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que contém os dados selecionados.

### <a name="return-value"></a>Valor retornado

Não zero se arrastar é permitido, caso contrário 0.

### <a name="remarks"></a>Comentários

Anular essa função se você quiser modificar a forma como o processo de arrasto é iniciado. A implementação padrão captura o mouse e permanece no modo de arrastar até que o usuário clique no botão esquerdo ou direito do mouse ou clique em ESC, momento em que ele libera o mouse.

## <a name="coledropsourcequerycontinuedrag"></a><a name="querycontinuedrag"></a>COleDropFonte::QueryContinuaDrag

Após o início do arrasto, essa função é chamada repetidamente pelo framework até que a operação de arrasto seja cancelada ou concluída.

```
virtual SCODE QueryContinueDrag(
    BOOL bEscapePressed,
    DWORD dwKeyState);
```

### <a name="parameters"></a>Parâmetros

*bEscapePressed*<br/>
Afirma se a chave ESC foi pressionada `COleDropSource::QueryContinueDrag`desde a última chamada para .

*Dwkeystate*<br/>
Contém o estado das teclas modificadoras no teclado. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

### <a name="return-value"></a>Valor retornado

DRAGDROP_S_CANCEL se a tecla ESC ou o botão direito for pressionado ou o botão esquerdo for levantado antes de arrastar a partida. DRAGDROP_S_DROP se ocorrer uma operação de queda. Caso contrário, S_OK.

### <a name="remarks"></a>Comentários

Anular esta função se você quiser alterar o ponto em que o arrasto é cancelado ou ocorre uma queda.

A implementação padrão inicia a queda ou cancela o arrasto da seguinte forma. Ele cancela uma operação de arrastar quando a tecla ESC ou o botão direito do mouse são pressionados. Ele inicia uma operação de queda quando o botão esquerdo do mouse é levantado após o arrasto ter sido iniciado. Caso contrário, ele retorna S_OK e não realiza mais operações.

Como essa função é chamada com freqüência, ela deve ser otimizada tanto quanto possível.

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
