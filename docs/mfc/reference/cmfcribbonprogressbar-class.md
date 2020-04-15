---
title: Classe CMFCRibbonProgressBar
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetPos
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRangeMax
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRangeMin
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRegularSize
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::IsInfiniteMode
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::OnDraw
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetInfiniteMode
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetPos
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetRange
helpviewer_keywords:
- CMFCRibbonProgressBar [MFC], CMFCRibbonProgressBar
- CMFCRibbonProgressBar [MFC], GetPos
- CMFCRibbonProgressBar [MFC], GetRangeMax
- CMFCRibbonProgressBar [MFC], GetRangeMin
- CMFCRibbonProgressBar [MFC], GetRegularSize
- CMFCRibbonProgressBar [MFC], IsInfiniteMode
- CMFCRibbonProgressBar [MFC], OnDraw
- CMFCRibbonProgressBar [MFC], SetInfiniteMode
- CMFCRibbonProgressBar [MFC], SetPos
- CMFCRibbonProgressBar [MFC], SetRange
ms.assetid: de3d9f2e-ed59-480e-aa7d-08a33ab36c67
ms.openlocfilehash: 063f8ce560af84d350abc0114644f6a63f969f95
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368858"
---
# <a name="cmfcribbonprogressbar-class"></a>Classe CMFCRibbonProgressBar

Implementa um controle que indica visualmente o progresso de uma operação demorada.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonProgressBar : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonProgressBar::CMFCRibbonProgressBar](#cmfcribbonprogressbar)|Constrói e inicializa um objeto `CMFCRibbonProgressBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonProgressBar::GetPos](#getpos)|Retorna o progresso atual.|
|[CMFCRibbonProgressBar::GetRangeMax](#getrangemax)|Retorna o valor máximo da faixa atual.|
|[CMFCRibbonProgressBar::GetRangeMin](#getrangemin)|Retorna o valor mínimo da faixa atual.|
|[CMFCRibbonProgressBar::getRegularSize](#getregularsize)|Retorna o tamanho regular do elemento da fita. (Substitui [cmfcribbonbaseelement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|
|[CMFCRibbonProgressBar::IsinfiniteMode](#isinfinitemode)|Especifica se a barra de progresso está funcionando no modo infinito.|
|[CMFCRibbonProgressBar::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o elemento da fita. (Substitui [cmfcribbonbaseelement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|
|[CMFCRibbonProgressBar::setInfiniteMode](#setinfinitemode)|Define a barra de progresso para funcionar no modo infinito.|
|[CMFCRibbonProgressBar::SetPos](#setpos)|Define o progresso atual.|
|[CMFCRibbonProgressBar::setRange](#setrange)|Define os valores mínimo e máximo.|

## <a name="remarks"></a>Comentários

A `CMFCRibbonProgressBar` pode operar em dois modos: regular e infinito. No modo regular, a barra de progresso é preenchida da esquerda para a direita e pára quando atinge o valor máximo. No modo infinito, a barra de progresso é repetidamente preenchida do valor mínimo para o valor máximo. Você pode usar o modo infinito para indicar que uma operação está em andamento, mas que o tempo de conclusão é desconhecido.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonProgressBar` usar vários métodos na classe. O exemplo mostra como definir a barra de progresso para funcionar no modo infinito (onde o tempo de conclusão de uma operação é desconhecido), definir os valores mínimos e máximos para a barra de progresso e definir a posição atual da barra de progresso. Este trecho de código faz parte da amostra de [demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#11](../../mfc/reference/codesnippet/cpp/cmfcribbonprogressbar-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonprogressbar](../../mfc/reference/cmfcribbonprogressbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonProgressBar.h

## <a name="cmfcribbonprogressbarcmfcribbonprogressbar"></a><a name="cmfcribbonprogressbar"></a>CMFCRibbonProgressBar::CMFCRibbonProgressBar

Constrói e inicializa um objeto [CMFCRibbonProgressBar.](../../mfc/reference/cmfcribbonprogressbar-class.md)

```
CMFCRibbonProgressBar();

CMFCRibbonProgressBar(
    UINT nID,
    int nWidth = 90,
    int nHeight = 22);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] Especifica o ID de comando para a barra de progresso da fita.

*Nwidth*<br/>
[em] Especifica a largura, em pixels, da barra de progresso da fita.

*Nheight*<br/>
[em] Especifica a altura, em pixels, da barra de progresso da fita.

## <a name="cmfcribbonprogressbargetpos"></a><a name="getpos"></a>CMFCRibbonProgressBar::GetPos

Retorna a posição atual da barra de progresso.

```
int GetPos () const;
```

### <a name="return-value"></a>Valor retornado

Um valor representando a posição atual da barra de progresso.

### <a name="remarks"></a>Comentários

O conjunto de intervalos deve estar dentro do intervalo especificado pelo método [CMFCRibbonProgressBar::SetRange.](#setrange)

## <a name="cmfcribbonprogressbargetrangemax"></a><a name="getrangemax"></a>CMFCRibbonProgressBar::GetRangeMax

Retorna o valor máximo atual da barra de progresso.

```
int GetRangeMax() const;
```

### <a name="return-value"></a>Valor retornado

O valor máximo da faixa atual.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonprogressbargetrangemin"></a><a name="getrangemin"></a>CMFCRibbonProgressBar::GetRangeMin

Retorna o valor de faixa mínima atual da barra de progresso.

```
int GetRangeMin() const;
```

### <a name="return-value"></a>Valor retornado

O valor mínimo da faixa atual.

## <a name="cmfcribbonprogressbargetregularsize"></a><a name="getregularsize"></a>CMFCRibbonProgressBar::getRegularSize

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonprogressbarisinfinitemode"></a><a name="isinfinitemode"></a>CMFCRibbonProgressBar::IsinfiniteMode

Especifica se a barra de progresso está funcionando no modo infinito.

```
BOOL IsInfiniteMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a barra de progresso estiver no modo infinito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

No modo infinito, a barra de progresso preenche repetidamente do valor mínimo ao valor máximo. Você pode usar o modo infinito para indicar que uma operação está em andamento, mas que o tempo de conclusão é desconhecido.

## <a name="cmfcribbonprogressbarondraw"></a><a name="ondraw"></a>CMFCRibbonProgressBar::OnDraw

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonprogressbarsetinfinitemode"></a><a name="setinfinitemode"></a>CMFCRibbonProgressBar::setInfiniteMode

Define a barra de progresso para funcionar no modo infinito.

```
void SetInfiniteMode(BOOL bSet = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSet*<br/>
[em] TRUE para especificar que a barra de progresso está no modo infinito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Normalmente, se a barra de progresso estiver no modo infinito, ele está dizendo ao usuário que uma operação está em andamento, mas que o tempo de conclusão é desconhecido. Assim, a barra de progresso preenche repetidamente do valor mínimo para o valor máximo.

## <a name="cmfcribbonprogressbarsetpos"></a><a name="setpos"></a>CMFCRibbonProgressBar::SetPos

Define a posição atual da barra de progresso.

```
void SetPos(
    int nPos,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
[em] Especifica a posição para a qual a barra de progresso está definida.

*Bredraw*<br/>
[em] Especifica se a barra de progresso deve ser redesenhada.

### <a name="remarks"></a>Comentários

O conjunto de intervalos deve estar dentro do intervalo especificado pelo método [CMFCRibbonProgressBar::SetRange.](#setrange)

## <a name="cmfcribbonprogressbarsetrange"></a><a name="setrange"></a>CMFCRibbonProgressBar::setRange

Define os valores mínimo e máximo para a barra de progresso.

```
void SetRange(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
[em] Especifica o valor mínimo da faixa.

*Nmax*<br/>
[em] Especifica o valor máximo da faixa.

### <a name="remarks"></a>Comentários

Use este método para definir o intervalo da barra de progresso definindo valores mínimos e máximos.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
