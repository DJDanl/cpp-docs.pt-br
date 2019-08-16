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
ms.openlocfilehash: 3a1e27ca6c1019eb8716194b3b7711238d015d6d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503995"
---
# <a name="coledropsource-class"></a>Classe COleDropSource

Permite que os dados sejam arrastados para um destino de soltura.

## <a name="syntax"></a>Sintaxe

```
class COleDropSource : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropSource::COleDropSource](#coledropsource)|Constrói um objeto `COleDropSource`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropSource::GiveFeedback](#givefeedback)|Altera o cursor durante uma operação de arrastar e soltar.|
|[COleDropSource::OnBeginDrag](#onbegindrag)|Manipula a captura do mouse durante uma operação de arrastar e soltar.|
|[COleDropSource::QueryContinueDrag](#querycontinuedrag)|Verifica se o recurso de arrastar deve continuar.|

## <a name="remarks"></a>Comentários

A classe [COleDropTarget](../../mfc/reference/coledroptarget-class.md) manipula a parte de recebimento da operação de arrastar e soltar. O `COleDropSource` objeto é responsável por determinar quando começa uma operação de arrastar, fornecendo comentários durante a operação de arrastar e determinando quando a operação de arrastar termina.

Para usar um `COleDropSource` objeto, basta chamar o construtor. Isso simplifica o processo de determinação de quais eventos, como um clique do mouse, inicia uma operação de arrastar usando [COleDataSource::D oDragDrop](../../mfc/reference/coledatasource-class.md#dodragdrop), [COleClientItem::D oDragDrop](../../mfc/reference/coleclientitem-class.md#dodragdrop)ou [COleServerItem::D função oDragDrop](../../mfc/reference/coleserveritem-class.md#dodragdrop) . Essas funções criarão um `COleDropSource` objeto para você. Talvez você queira modificar o comportamento padrão das `COleDropSource` funções substituíveis. Essas funções de membro serão chamadas nos horários apropriados da estrutura.

Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource](/windows/win32/api/oleidl/nn-oleidl-idropsource) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="coledropsource"></a>  COleDropSource::COleDropSource

Constrói um objeto `COleDropSource`.

```
COleDropSource();
```

##  <a name="givefeedback"></a>  COleDropSource::GiveFeedback

Chamado pelo Framework depois de chamar [COleDropTarget:: OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover) ou [COleDropTarget::D ragenter](../../mfc/reference/coledroptarget-class.md#ondragenter).

```
virtual SCODE GiveFeedback(DROPEFFECT dropEffect);
```

### <a name="parameters"></a>Parâmetros

*dropEffect*<br/>
O efeito que você gostaria de exibir para o usuário, geralmente indicando o que aconteceria se uma queda fosse feita neste ponto com os dados selecionados. Normalmente, esse é o valor retornado pela chamada mais recente para [cvisualização:: OnDragEnter](../../mfc/reference/cview-class.md#ondragenter) ou [Cvisualização:: OnDragOver](../../mfc/reference/cview-class.md#ondragover). Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

### <a name="return-value"></a>Valor de retorno

Retorna DRAGDROP_S_USEDEFAULTCURSORS se o recurso de arrastar estiver em andamento, NOERROR se não for.

### <a name="remarks"></a>Comentários

Substitua essa função para fornecer comentários ao usuário sobre o que aconteceria se uma queda ocorrer neste ponto. A implementação padrão usa os cursores padrão OLE. Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

Para obter mais informações, consulte [IDropSource:: GiveFeedback](/windows/win32/api/oleidl/nf-oleidl-idropsource-givefeedback), [IDropTarget::D ragover](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragover)e [IDropTarget::D ragenter](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragenter) no SDK do Windows.

##  <a name="onbegindrag"></a>  COleDropSource::OnBeginDrag

Chamado pelo Framework quando ocorre um evento que pode iniciar uma operação de arrastar, como pressionar o botão esquerdo do mouse.

```
virtual BOOL OnBeginDrag(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que contém os dados selecionados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se arrastar for permitido, caso contrário 0.

### <a name="remarks"></a>Comentários

Substitua essa função se desejar modificar a maneira como o processo de arrastar é iniciado. A implementação padrão captura o mouse e permanece no modo de arrastar até que o usuário clique no botão esquerdo ou direito do mouse ou pressione ESC, no momento em que ele libera o mouse.

##  <a name="querycontinuedrag"></a>  COleDropSource::QueryContinueDrag

Depois de arrastar ter começado, essa função é chamada repetidamente pela estrutura até que a operação de arrastar seja cancelada ou concluída.

```
virtual SCODE QueryContinueDrag(
    BOOL bEscapePressed,
    DWORD dwKeyState);
```

### <a name="parameters"></a>Parâmetros

*bEscapePressed*<br/>
Indica se a tecla ESC foi pressionada desde a última chamada para `COleDropSource::QueryContinueDrag`.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras no teclado. Essa é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

### <a name="return-value"></a>Valor de retorno

DRAGDROP_S_CANCEL se a tecla ESC ou o botão direito for pressionado ou o botão esquerdo for gerado antes de arrastar ser iniciado. DRAGDROP_S_DROP se uma operação de soltar deve ocorrer. Caso contrário, S_OK.

### <a name="remarks"></a>Comentários

Substitua essa função se desejar alterar o ponto em que a arrastar é cancelada ou uma queda ocorre.

A implementação padrão inicia o drop ou cancela o arraste da seguinte maneira. Ele cancela uma operação de arrastar quando a tecla ESC ou o botão direito do mouse é pressionado. Ele inicia uma operação DROP quando o botão esquerdo do mouse é acionado após o arrasto ser iniciado. Caso contrário, retornará S_OK e não executará nenhuma outra operação.

Como essa função é chamada com frequência, ela deve ser otimizada o máximo possível.

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
