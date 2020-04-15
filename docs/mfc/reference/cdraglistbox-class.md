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
ms.openlocfilehash: 0d1ae94948e1143a5bac17985423c4bd1bfbaf65
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374037"
---
# <a name="cdraglistbox-class"></a>Classe CDragListBox

Além de fornecer a funcionalidade de uma `CDragListBox` caixa de lista do Windows, a classe permite que o usuário mova itens da caixa de lista, como nomes de arquivos, dentro da caixa de lista.

## <a name="syntax"></a>Sintaxe

```
class CDragListBox : public CListBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cdraglistbox::CDragListBox](#cdraglistbox)|Constrói um objeto `CDragListBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cdraglistbox::BeginDrag](#begindrag)|Chamado pela estrutura quando uma operação de arrasto começa.|
|[cdraglistbox::cancelando](#canceldrag)|Chamado pela estrutura quando uma operação de arrasto foi cancelada.|
|[CDragListBox::Dragging](#dragging)|Chamado pela estrutura durante uma operação de arrasto.|
|[CDragListBox::DrawInsert](#drawinsert)|Desenha o guia de inserção da caixa de lista de arrasto.|
|[CDragListBox::D caiu](#dropped)|Chamado pelo quadro depois que o item foi retirado.|
|[CDragListBox::ItemFromT](#itemfrompt)|Retorna as coordenadas do item que está sendo arrastado.|

## <a name="remarks"></a>Comentários

Listar caixas com esse recurso permite que os usuários solicitem os itens em uma lista de qualquer maneira que seja mais útil para eles. Por padrão, a caixa de lista moverá o item para o novo local da lista. No `CDragListBox` entanto, os objetos podem ser personalizados para copiar itens em vez de movê-los.

O controle da caixa `CDragListBox` de lista associado à classe não deve ter o LBS_SORT ou o estilo LBS_MULTIPLESELECT. Para obter uma descrição dos estilos da caixa de lista, consulte [Estilos de caixa de lista](../../mfc/reference/styles-used-by-mfc.md#list-box-styles).

Para usar uma caixa de lista de arrastar em uma caixa de diálogo existente do seu aplicativo, adicione um `Control` controle de `CDragListBox`caixa de lista ao modelo de diálogo usando o editor de diálogo e, em seguida, atribua uma variável de membro (de Categoria e Tipo variável) correspondente ao controle de caixa de lista no modelo de caixa de diálogo.

Para obter mais informações sobre como atribuir controles às variáveis de membro, consulte [Atalho para definir variáveis de membro para controles de diálogo](../../windows/defining-member-variables-for-dialog-controls.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListBox](../../mfc/reference/clistbox-class.md)

`CDragListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cdraglistboxbegindrag"></a><a name="begindrag"></a>cdraglistbox::BeginDrag

Chamado pela estrutura quando ocorre um evento que pode iniciar uma operação de arrasto, como pressionar o botão esquerdo do mouse.

```
virtual BOOL BeginDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do item sendo arrastado.

### <a name="return-value"></a>Valor retornado

Não zero se arrastar é permitido, caso contrário 0.

### <a name="remarks"></a>Comentários

Anular esta função se você quiser controlar o que acontece quando uma operação de arrasto começa. A implementação padrão captura o mouse e permanece no modo de arrastar até que o usuário clique no botão esquerdo ou direito do mouse ou pressione ESC, momento em que a operação de arrastar é cancelada.

## <a name="cdraglistboxcanceldrag"></a><a name="canceldrag"></a>cdraglistbox::cancelando

Chamado pela estrutura quando uma operação de arrasto foi cancelada.

```
virtual void CancelDrag(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do item sendo arrastado.

### <a name="remarks"></a>Comentários

Anular esta função para lidar com qualquer processamento especial para o controle da caixa de lista.

## <a name="cdraglistboxcdraglistbox"></a><a name="cdraglistbox"></a>cdraglistbox::CDragListBox

Constrói um objeto `CDragListBox`.

```
CDragListBox();
```

## <a name="cdraglistboxdragging"></a><a name="dragging"></a>CDragListBox::Dragging

Chamado pela estrutura quando um item da caixa `CDragListBox` de lista está sendo arrastado dentro do objeto.

```
virtual UINT Dragging(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas de tela x e y do cursor.

### <a name="return-value"></a>Valor retornado

O id de recurso do cursor a ser exibido. Os seguintes valores são possíveis:

- DL_COPYCURSOR Indica que o item será copiado.

- DL_MOVECURSOR Indica que o item será movido.

- DL_STOPCURSOR Indica que a meta de queda atual não é aceitável.

### <a name="remarks"></a>Comentários

O comportamento padrão retorna DL_MOVECURSOR. Anular esta função se você quiser fornecer funcionalidade adicional.

## <a name="cdraglistboxdrawinsert"></a><a name="drawinsert"></a>CDragListBox::DrawInsert

Chamado pelo framework para desenhar o guia de inserção antes do item com o índice indicado.

```
virtual void DrawInsert(int nItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Índice baseado em zero do ponto de inserção.

### <a name="remarks"></a>Comentários

Um valor de - 1 limpa o guia de inserção. Anular esta função para modificar a aparência ou o comportamento do guia de inserção.

## <a name="cdraglistboxdropped"></a><a name="dropped"></a>CDragListBox::D caiu

Chamado pela estrutura quando um item `CDragListBox` é descartado dentro de um objeto.

```
virtual void Dropped(
    int nSrcIndex,
    CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*nSrcIndex*<br/>
Especifica o índice baseado em zero da seqüência de fios descartados.

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que contém as coordenadas do local de queda.

### <a name="remarks"></a>Comentários

O comportamento padrão copia o item da caixa de lista e seus dados para o novo local e, em seguida, exclui o item original. Substituir essa função para personalizar o comportamento padrão, como permitir que cópias de itens da caixa de lista sejam arrastadas para outros locais dentro da lista.

## <a name="cdraglistboxitemfrompt"></a><a name="itemfrompt"></a>CDragListBox::ItemFromT

Chame esta função para recuperar o índice baseado em zero do item da caixa de lista localizado no *pt*.

```
int ItemFromPt(
    CPoint pt,
    BOOL bAutoScroll = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Um objeto [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) contendo as coordenadas de um ponto dentro da caixa de lista.

*bAutoScroll*<br/>
Não zero se a rolagem for permitida, caso contrário 0.

### <a name="return-value"></a>Valor retornado

Índice baseado em zero do item da caixa de lista de arrasto.

## <a name="see-also"></a>Confira também

[Amostra de MFC TSTCON](../../overview/visual-cpp-samples.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)
