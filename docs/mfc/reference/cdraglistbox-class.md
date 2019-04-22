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
ms.openlocfilehash: d8afc5b14f5f52ca7a4d28a3d3c3c5440b7c819f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58781582"
---
# <a name="cdraglistbox-class"></a>Classe CDragListBox

Além de fornecer a funcionalidade de uma caixa de listagem do Windows, o `CDragListBox` classe permite que o usuário mova itens de caixa de lista, como nomes de arquivo, dentro da caixa de lista.

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
|[CDragListBox::BeginDrag](#begindrag)|Chamado pelo framework quando uma operação de arrastar for iniciado.|
|[CDragListBox::CancelDrag](#canceldrag)|Chamado pelo framework quando uma operação de arrastar foi cancelada.|
|[CDragListBox::Dragging](#dragging)|Chamado pelo framework durante uma operação de arrastar.|
|[CDragListBox::DrawInsert](#drawinsert)|Desenha o guia de inserção da caixa de listagem de arrastar.|
|[CDragListBox::Dropped](#dropped)|Chamado pelo framework depois que o item foi descartado.|
|[CDragListBox::ItemFromPt](#itemfrompt)|Retorna as coordenadas do item que está sendo arrastado.|

## <a name="remarks"></a>Comentários

Caixas de listagem com esse recurso permitem aos usuários solicitar os itens em uma lista de maneira que for mais útil para eles. Por padrão, a caixa de listagem será mover o item para o novo local na lista. No entanto, `CDragListBox` objetos podem ser personalizados para copiar itens em vez de movê-los.

O controle de caixa de listagem associado com o `CDragListBox` classe não deve ter o LBS_SORT ou o estilo LBS_MULTIPLESELECT. Para obter uma descrição dos estilos de caixa de lista, consulte [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles).

Para usar uma caixa de listagem de arrastar em uma caixa de diálogo existente do seu aplicativo, adicione um controle de caixa de listagem ao seu modelo de caixa de diálogo usando o editor de caixa de diálogo e, em seguida, atribuir uma variável de membro (da categoria `Control` e o tipo de variável `CDragListBox`) correspondente à caixa de listagem controle em seu modelo de caixa de diálogo.

Para obter mais informações sobre como atribuir controles para variáveis de membro, consulte [atalho para definir variáveis de membro para controles de caixa de diálogo](../../windows/defining-member-variables-for-dialog-controls.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListBox](../../mfc/reference/clistbox-class.md)

`CDragListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="begindrag"></a>  CDragListBox::BeginDrag

Chamado pela estrutura de quando ocorre um evento que poderia começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.

```
virtual BOOL BeginDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se arrastar for permitido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função se você quiser controlar o que acontece quando começa uma operação de arrastar. A implementação padrão captura o mouse e permanece no modo arrastar até que o usuário clica no botão esquerdo ou direito do mouse ou pressiona ESC, momento em que a operação de arrastar seja cancelada.

##  <a name="canceldrag"></a>  CDragListBox::CancelDrag

Chamado pelo framework quando uma operação de arrastar foi cancelada.

```
virtual void CancelDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.

### <a name="remarks"></a>Comentários

Substitua essa função para lidar com qualquer processamento especial para o controle de caixa de listagem.

##  <a name="cdraglistbox"></a>  CDragListBox::CDragListBox

Constrói um objeto `CDragListBox`.

```
CDragListBox();
```

##  <a name="dragging"></a>  CDragListBox::Dragging

Chamado pelo framework quando um item de caixa de listagem está sendo arrastado dentro a `CDragListBox` objeto.

```
virtual UINT Dragging(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém x e y coordenadas do cursor de tela.

### <a name="return-value"></a>Valor de retorno

A ID de recurso do cursor a ser exibido. Os seguintes valores são possíveis:

- DL_COPYCURSOR indica que o item será copiado.

- DL_MOVECURSOR indica que o item será movido.

- DL_STOPCURSOR indica que o destino de soltar atual não é aceitável.

### <a name="remarks"></a>Comentários

O comportamento padrão retorna DL_MOVECURSOR. Substitua essa função para fornecer funcionalidade adicional.

##  <a name="drawinsert"></a>  CDragListBox::DrawInsert

Chamado pelo framework para desenhar o guia de inserção antes do item com índice indicado.

```
virtual void DrawInsert(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice baseado em zero do ponto de inserção.

### <a name="remarks"></a>Comentários

Um valor de - 1 limpa o guia de inserção. Substitua essa função para modificar a aparência ou o comportamento do guia de inserção.

##  <a name="dropped"></a>  CDragListBox::Dropped

Chamado pelo framework quando um item é removido dentro de um `CDragListBox` objeto.

```
virtual void Dropped(
    int nSrcIndex,
    CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*nSrcIndex*<br/>
Especifica o índice baseado em zero da cadeia de caracteres descartada.

*pt*<br/>
Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do site de destino.

### <a name="remarks"></a>Comentários

O comportamento padrão copia o item de caixa de listagem e seus dados para o novo local e, em seguida, exclui o item original. Substitua essa função para personalizar o comportamento padrão, como a habilitação de cópias dos itens de caixa de lista a ser arrastado para outros locais dentro da lista.

##  <a name="itemfrompt"></a>  CDragListBox::ItemFromPt

Chamada para essa função para recuperar o índice baseado em zero do item de caixa de lista localizada em *pt*.

```
int ItemFromPt(
    CPoint pt,
    BOOL bAutoScroll = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas de um ponto dentro da caixa de listagem.

*bAutoScroll*<br/>
Diferente de zero se a rolagem é permitida, caso contrário, 0.

### <a name="return-value"></a>Valor de retorno

Índice baseado em zero do item de caixa de lista arrastar.

## <a name="see-also"></a>Consulte também

[Exemplo MFC TSTCON](../../overview/visual-cpp-samples.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)
