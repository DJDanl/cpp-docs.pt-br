---
title: Classe COleDropSource | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDropSource
- AFXOLE/COleDropSource
- AFXOLE/COleDropSource::COleDropSource
- AFXOLE/COleDropSource::GiveFeedback
- AFXOLE/COleDropSource::OnBeginDrag
- AFXOLE/COleDropSource::QueryContinueDrag
dev_langs:
- C++
helpviewer_keywords:
- COleDropSource [MFC], COleDropSource
- COleDropSource [MFC], GiveFeedback
- COleDropSource [MFC], OnBeginDrag
- COleDropSource [MFC], QueryContinueDrag
ms.assetid: d3eecc5f-a70b-4a01-b705-7d2c098ebe17
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f40ac527ba8ad7e65f025910e96a69f546842e30
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46447551"
---
# <a name="coledropsource-class"></a>Classe COleDropSource

Permite que os dados sejam arrastados para um destino de soltar.

## <a name="syntax"></a>Sintaxe

```
class COleDropSource : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropSource::COleDropSource](#coledropsource)|Constrói um objeto `COleDropSource`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropSource::GiveFeedback](#givefeedback)|Altera o cursor durante uma operação de arrastar e soltar.|
|[COleDropSource::OnBeginDrag](#onbegindrag)|Lida com a captura do mouse durante uma operação de arrastar e soltar.|
|[COleDropSource::QueryContinueDrag](#querycontinuedrag)|Verifica se arrastar deve continuar.|

## <a name="remarks"></a>Comentários

O [COleDropTarget](../../mfc/reference/coledroptarget-class.md) classe manipula a parte receptora da operação de arrastar e soltar. O `COleDropSource` objeto é responsável por determinar quando começa uma operação de arrastar, fornecendo comentários durante a operação de arrastar e determinar quando a operação de arrastar termina.

Para usar um `COleDropSource` de objeto, basta chamar o construtor. Isso simplifica o processo de determinar quais eventos, como um clique do mouse, iniciar uma operação de arrastar usando [COleDataSource::DoDragDrop](../../mfc/reference/coledatasource-class.md#dodragdrop), [COleClientItem::DoDragDrop](../../mfc/reference/coleclientitem-class.md#dodragdrop), ou [ COleServerItem::DoDragDrop](../../mfc/reference/coleserveritem-class.md#dodragdrop) função. Essas funções criará um `COleDropSource` objeto para você. Você talvez queira modificar o comportamento padrão do `COleDropSource` funções substituíveis. Essas funções de membro serão chamadas nos momentos apropriados pela estrutura.

Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource](/windows/desktop/api/oleidl/nn-oleidl-idropsource) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="coledropsource"></a>  COleDropSource::COleDropSource

Constrói um objeto `COleDropSource`.

```
COleDropSource();
```

##  <a name="givefeedback"></a>  COleDropSource::GiveFeedback

Chamado pelo framework depois de chamar [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover) ou [COleDropTarget::DragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).

```
virtual SCODE GiveFeedback(DROPEFFECT dropEffect);
```

### <a name="parameters"></a>Parâmetros

*dropEffect*<br/>
O efeito que você deseja exibir para o usuário, geralmente indicando o que aconteceria se uma operação de soltar ocorresse neste ponto com os dados selecionados. Normalmente, esse é o valor retornado pela chamada a mais recente [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter) ou [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover). Ele pode ser um ou mais das seguintes opções:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- Operação de rolagem de arrastar de um DROPEFFECT_SCROLL está prestes a ocorrer ou está ocorrendo no destino.

### <a name="return-value"></a>Valor de retorno

Retorna DRAGDROP_S_USEDEFAULTCURSORS se arrastando está em andamento, NOERROR se não for.

### <a name="remarks"></a>Comentários

Substitua essa função para fornecer comentários ao usuário sobre o que aconteceria se uma operação de soltar ocorrer neste ponto. A implementação padrão usa os cursores padrão OLE. Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource::GiveFeedback](/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback), [IDropTarget::DragOver](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover), e [IDropTarget::DragEnter](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) no SDK do Windows.

##  <a name="onbegindrag"></a>  COleDropSource::OnBeginDrag

Chamado pela estrutura de quando ocorre um evento que poderia começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.

```
virtual BOOL OnBeginDrag(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
Aponta para a janela que contém os dados selecionados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se arrastar for permitido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função se você quiser modificar a forma como o processo de arrastar é iniciado. A implementação padrão captura o mouse e permanece no modo arrastar até que o usuário clica no botão esquerdo ou direito do mouse ou pressiona ESC, momento em que ele libera o mouse.

##  <a name="querycontinuedrag"></a>  COleDropSource::QueryContinueDrag

Depois de arrastar começou, essa função é chamada repetidamente pela estrutura até que a operação de arrastar seja cancelada ou concluída.

```
virtual SCODE QueryContinueDrag(
    BOOL bEscapePressed,
    DWORD dwKeyState);
```

### <a name="parameters"></a>Parâmetros

*bEscapePressed*<br/>
Indica se a tecla ESC foi pressionada desde a última chamada para `COleDropSource::QueryContinueDrag`.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras do teclado. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

### <a name="return-value"></a>Valor de retorno

DRAGDROP_S_CANCEL se a tecla ESC ou o botão direito é pressionado ou botão esquerdo é gerado antes de arrastar é iniciado. DRAGDROP_S_DROP se ocorrer uma operação de soltar. Caso contrário S_OK.

### <a name="remarks"></a>Comentários

Substituir que essa função se você quiser alterar o ponto no qual arrastando é cancelada ou uma operação de soltar ocorre.

A implementação padrão inicia a operação de soltar ou cancela a operação de arrastar da seguinte maneira. Cancela uma operação de arrastar quando a tecla ESC ou o botão direito do mouse é pressionado. Ele inicia uma operação de soltar quando o botão esquerdo do mouse é gerado depois de arrastar foi iniciada. Caso contrário, ele retorna S_OK e não executa nenhuma outra operação.

Porque essa função é chamada com frequência, ele deve ser otimizado tanto quanto possível.

## <a name="see-also"></a>Consulte também

[Exemplo MFC HIERSVR](../../visual-cpp-samples.md)<br/>
[Exemplo MFC OCLIENT](../../visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



