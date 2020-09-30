---
title: Classe CDragListBox
ms.date: 11/04/2016
f1_keywords:
- CDragListBox
- AFXCMN/CDragListBox
- AFXCMN/CDragListBox::CDragListBox
- AFXCMN/CDragListBox::BeginDrag
- AFXCMN/CDragListBox::CancelDrag
- AFXCMN/CDragListBox::Dragging
- AFXCMN/CDragListBox::DrawInsert
- AFXCMN/CDragListBox::Dropped
- AFXCMN/CDragListBox::ItemFromPt
helpviewer_keywords:
- CDragListBox [MFC], CDragListBox
- CDragListBox [MFC], BeginDrag
- CDragListBox [MFC], CancelDrag
- CDragListBox [MFC], Dragging
- CDragListBox [MFC], DrawInsert
- CDragListBox [MFC], Dropped
- CDragListBox [MFC], ItemFromPt
ms.assetid: fee20b42-60ae-4aa9-83f9-5a3d9b96e33b
ms.openlocfilehash: b260d3a88fc8c3f2d341005c1e47cfd9ab668e1e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500354"
---
# <a name="cdraglistbox-class"></a>Classe CDragListBox

Além de fornecer a funcionalidade de uma caixa de listagem do Windows, a `CDragListBox` classe permite que o usuário mova itens da caixa de listagem, como nomes de File, na caixa de listagem.

## <a name="syntax"></a>Sintaxe

```
class CDragListBox : public CListBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDragListBox::CDragListBox](#cdraglistbox)|Constrói um objeto `CDragListBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDragListBox::BeginDrag](#begindrag)|Chamado pelo Framework quando uma operação de arrastar é iniciada.|
|[CDragListBox::CancelDrag](#canceldrag)|Chamado pelo Framework quando uma operação de arrastar foi cancelada.|
|[CDragListBox::D ragging](#dragging)|Chamado pelo Framework durante uma operação de arrastar.|
|[CDragListBox::D rawInsert](#drawinsert)|Desenha o guia de inserção da caixa de listagem de arrastar.|
|[CDragListBox::D ropped](#dropped)|Chamado pelo Framework depois que o item foi Descartado.|
|[CDragListBox::ItemFromPt](#itemfrompt)|Retorna as coordenadas do item que está sendo arrastado.|

## <a name="remarks"></a>Comentários

As caixas de listagem com esse recurso permitem que os usuários ordenem os itens de uma lista de qualquer maneira que seja mais útil para eles. Por padrão, a caixa de listagem moverá o item para o novo local na lista. No entanto, `CDragListBox` os objetos podem ser personalizados para copiar itens em vez de movê-los.

O controle de caixa de listagem associado à `CDragListBox` classe não deve ter o LBS_SORT ou o estilo de LBS_MULTIPLESELECT. Para obter uma descrição dos estilos de caixa de listagem, consulte [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles).

Para usar uma caixa de listagem de arrastar em uma caixa de diálogo existente do seu aplicativo, adicione um controle de caixa de listagem ao seu modelo de diálogo usando o editor de caixa de diálogo e, em seguida, atribua uma variável de membro (de categoria `Control` e tipo de variável `CDragListBox` ) correspondente ao controle do modo de listagem no seu modelo de diálogo.

Para obter mais informações sobre como atribuir controles a variáveis de membro, consulte o [atalho para definir variáveis de membro para controles de caixa de diálogo](../../windows/adding-editing-or-deleting-controls.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListBox](../../mfc/reference/clistbox-class.md)

`CDragListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

## <a name="cdraglistboxbegindrag"></a><a name="begindrag"></a> CDragListBox::BeginDrag

Chamado pelo Framework quando ocorre um evento que pode iniciar uma operação de arrastar, como pressionar o botão esquerdo do mouse.

```
virtual BOOL BeginDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do item que está sendo arrastado.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se arrastar for permitido, caso contrário 0.

### <a name="remarks"></a>Comentários

Substitua essa função se você quiser controlar o que acontece quando uma operação de arrastar é iniciada. A implementação padrão captura o mouse e permanece no modo de arrastar até que o usuário clique no botão esquerdo ou direito do mouse ou pressione ESC e, nesse momento, a operação de arrastar será cancelada.

## <a name="cdraglistboxcanceldrag"></a><a name="canceldrag"></a> CDragListBox::CancelDrag

Chamado pelo Framework quando uma operação de arrastar foi cancelada.

```
virtual void CancelDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do item que está sendo arrastado.

### <a name="remarks"></a>Comentários

Substitua essa função para lidar com qualquer processamento especial para o controle de caixa de listagem.

## <a name="cdraglistboxcdraglistbox"></a><a name="cdraglistbox"></a> CDragListBox::CDragListBox

Constrói um objeto `CDragListBox`.

```
CDragListBox();
```

## <a name="cdraglistboxdragging"></a><a name="dragging"></a> CDragListBox::D ragging

Chamado pelo Framework quando um item da caixa de listagem está sendo arrastado dentro do `CDragListBox` objeto.

```
virtual UINT Dragging(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas de tela x e y do cursor.

### <a name="return-value"></a>Valor Retornado

A ID de recurso do cursor a ser exibido. Os seguintes valores são possíveis:

- DL_COPYCURSOR indica que o item será copiado.

- DL_MOVECURSOR indica que o item será movido.

- DL_STOPCURSOR Indica que o destino de soltura atual não é aceitável.

### <a name="remarks"></a>Comentários

O comportamento padrão retorna DL_MOVECURSOR. Substitua essa função se desejar fornecer funcionalidade adicional.

## <a name="cdraglistboxdrawinsert"></a><a name="drawinsert"></a> CDragListBox::D rawInsert

Chamado pelo Framework para desenhar o guia de inserção antes do item com o índice indicado.

```
virtual void DrawInsert(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice de base zero do ponto de inserção.

### <a name="remarks"></a>Comentários

Um valor de-1 limpa o guia de inserção. Substitua essa função para modificar a aparência ou o comportamento do guia de inserção.

## <a name="cdraglistboxdropped"></a><a name="dropped"></a> CDragListBox::D ropped

Chamado pelo Framework quando um item é Descartado dentro de um `CDragListBox` objeto.

```
virtual void Dropped(
    int nSrcIndex,
    CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*nSrcIndex*<br/>
Especifica o índice de base zero da cadeia de caracteres descartada.

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do site de destino.

### <a name="remarks"></a>Comentários

O comportamento padrão copia o item da caixa de listagem e seus dados para o novo local e, em seguida, exclui o item original. Substitua essa função para personalizar o comportamento padrão, como permitir que cópias de itens da caixa de listagem sejam arrastadas para outros locais dentro da lista.

## <a name="cdraglistboxitemfrompt"></a><a name="itemfrompt"></a> CDragListBox::ItemFromPt

Chame essa função para recuperar o índice de base zero do item da caixa de listagem localizado em *pt*.

```
int ItemFromPt(
    CPoint pt,
    BOOL bAutoScroll = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas de um ponto dentro da caixa de listagem.

*bAutoScroll*<br/>
Diferente de zero se a rolagem for permitida, caso contrário 0.

### <a name="return-value"></a>Valor Retornado

Índice de base zero do item da caixa de listagem de arrastar.

## <a name="see-also"></a>Consulte também

[Exemplo de TSTCON do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)
