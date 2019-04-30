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
ms.openlocfilehash: 8dedad4e99a37b13dc618859c8e6d8a83a65ea76
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64339607"
---
# <a name="csplitterwndex-class"></a>Classe CSplitterWndEx

Representa uma janela separadora personalizada.

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

*rect*<br/>
[in] Um retângulo delimitador que especifica as dimensões e o local para desenhar o elemento de janela de divisão especificada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Classes](mfc-classes.md)<br/>
[Classe CSplitterWnd](csplitterwnd-class.md)<br/>
[Classe CMFCVisualManager](cmfcvisualmanager-class.md)
