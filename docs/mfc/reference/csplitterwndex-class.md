---
title: Classe CSplitterWndEx
ms.date: 11/04/2016
f1_keywords:
- CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx::OnDrawSplitter
helpviewer_keywords:
- CSplitterWndEx [MFC], OnDrawSplitter
ms.assetid: 33e5eef3-05e1-4a07-a968-bf9207ce8598
ms.openlocfilehash: d7952e3082bf68cff7ad9ba218073081ee522320
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363919"
---
# <a name="csplitterwndex-class"></a>Classe CSplitterWndEx

Representa uma janela de divisor personalizada.

## <a name="syntax"></a>Sintaxe

```
class CSplitterWndEx : public CSplitterWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CSplitterWndEx::CSplitterWndEx`|Construtor padrão.|
|`CSplitterWndEx::~CSplitterWndEx`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWndEx::OnDrawSplitter](#ondrawsplitter)|Chamado pela estrutura para desenhar uma janela de divisor. (Substitui [csplitterwnd::OnDrawSplitter](csplitterwnd-class.md#ondrawsplitter).)|

## <a name="remarks"></a>Comentários

Anular o `OnDrawSplitter` método para personalizar a aparência dos componentes gráficos de uma janela de divisor.

A `CSplitterWndEx` classe é usada em conjunto com os métodos [OnDrawSplitterBorder,](cmfcvisualmanager-class.md#ondrawsplitterborder) [OnDrawSplitterBox](cmfcvisualmanager-class.md#ondrawsplitterbox)e [OnFillSplitterBackground,](cmfcvisualmanager-class.md#onfillsplitterbackground) que são implementados por um gerenciador visual. Para fazer com que um gerenciador visual desenhe uma `CSplitterWnd` janela `CSplitterWndEx` de divisor em sua aplicação, substitua as declarações da classe pela classe. Para aplicações de janela de quadro, a classe janela divisor é declarada na classe CMainFrame que está localizada em mainfrm.h. Por exemplo, veja `OutlookDemo` a amostra no diretório Amostras.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](cobject-class.md)

[Ccmdtarget](ccmdtarget-class.md)

[CWnd](cwnd-class.md)

[Csplitterwnd](csplitterwnd-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsplitterwndex.h

## <a name="csplitterwndexondrawsplitter"></a><a name="ondrawsplitter"></a>CSplitterWndEx::OnDrawSplitter

Chamado pela estrutura para desenhar uma janela de divisor.

```
virtual void OnDrawSplitter(
   CDC* pDC,
   ESplitType nType,
   const CRect& rect
);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o contexto do dispositivo. Se este parâmetro for NULO, a estrutura redesenha a janela ativa.

*nType*<br/>
[em] Um dos `CSplitterWnd::ESplitType` valores de enumeração que especifica o elemento da janela do divisor para desenhar. Os valores válidos são `splitBox`, `splitBar`, `splitIntersection` e `splitBorder`.

*Rect*<br/>
[em] Um retângulo delimitador que especifica as dimensões e o local para desenhar o elemento da janela do divisor especificado.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Classes](mfc-classes.md)<br/>
[Classe CSplitterWnd](csplitterwnd-class.md)<br/>
[Classe CMFCVisualManager](cmfcvisualmanager-class.md)
