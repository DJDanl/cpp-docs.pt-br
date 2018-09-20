---
title: Classe CSplitterWndEx | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx::OnDrawSplitter
dev_langs:
- C++
helpviewer_keywords:
- CSplitterWndEx [MFC], OnDrawSplitter
ms.assetid: 33e5eef3-05e1-4a07-a968-bf9207ce8598
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7df892a3d3f038655f37b78fa88babb09d50df2d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373448"
---
# <a name="csplitterwndex-class"></a>Classe CSplitterWndEx



Representa uma janela separadora personalizada.

## <a name="syntax"></a>Sintaxe

```
class CSplitterWndEx : public CSplitterWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CSplitterWndEx::CSplitterWndEx`|Construtor padrão.|
|`CSplitterWndEx::~CSplitterWndEx`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWndEx::OnDrawSplitter](#ondrawsplitter)|Chamado pelo framework para desenhar uma janela separadora. (Substitui [CSplitterWnd::OnDrawSplitter](csplitterwnd-class.md#ondrawsplitter).)|

## <a name="remarks"></a>Comentários

Substituir o `OnDrawSplitter` método para personalizar a aparência dos componentes do gráficos de uma janela separadora.

O `CSplitterWndEx` classe é usada junto com o [OnDrawSplitterBorder](cmfcvisualmanager-class.md#ondrawsplitterborder), [OnDrawSplitterBox](cmfcvisualmanager-class.md#ondrawsplitterbox), e [OnFillSplitterBackground](cmfcvisualmanager-class.md#onfillsplitterbackground) métodos, que são implementado por um Gerenciador de visual. Para fazer com que um gerente desenhar uma janela separadora em seu aplicativo, substitua as declarações do `CSplitterWnd` classe com o `CSplitterWndEx` classe. Para aplicativos de janela de quadro, a classe de janela divisora é declarada na classe CMainFrame que está localizada em mainfrm.h. Por exemplo, consulte o `OutlookDemo` exemplo no diretório de exemplos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](cobject-class.md)

[CCmdTarget](ccmdtarget-class.md)

[CWnd](cwnd-class.md)

[CSplitterWnd](csplitterwnd-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsplitterwndex.h

##  <a name="ondrawsplitter"></a>  CSplitterWndEx::OnDrawSplitter

Chamado pelo framework para desenhar uma janela separadora.

```
virtual void OnDrawSplitter(
   CDC* pDC,
   ESplitType nType,
   const CRect& rect
);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para o contexto de dispositivo. Se esse parâmetro for NULL, o framework redesenha a janela ativa.

*nType*<br/>
[in] Um do `CSplitterWnd::ESplitType` valores de enumeração que especifica o elemento de janela divisor para desenhar. Os valores válidos são `splitBox`, `splitBar`, `splitIntersection` e `splitBorder`.

*Rect*<br/>
[in] Um retângulo delimitador que especifica as dimensões e o local para desenhar o elemento de janela de divisão especificada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Classes](mfc-classes.md)<br/>
[Classe CSplitterWnd](csplitterwnd-class.md)<br/>
[Classe CMFCVisualManager](cmfcvisualmanager-class.md)