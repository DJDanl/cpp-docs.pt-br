---
title: Classe CMFCRibbonSlider
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider::CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetPos
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRangeMax
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRangeMin
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRegularSize
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetZoomIncrement
- AFXRIBBONSLIDER/CMFCRibbonSlider::HasZoomButtons
- AFXRIBBONSLIDER/CMFCRibbonSlider::OnDraw
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetPos
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetRange
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetZoomButtons
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetZoomIncrement
helpviewer_keywords:
- CMFCRibbonSlider [MFC], CMFCRibbonSlider
- CMFCRibbonSlider [MFC], GetPos
- CMFCRibbonSlider [MFC], GetRangeMax
- CMFCRibbonSlider [MFC], GetRangeMin
- CMFCRibbonSlider [MFC], GetRegularSize
- CMFCRibbonSlider [MFC], GetZoomIncrement
- CMFCRibbonSlider [MFC], HasZoomButtons
- CMFCRibbonSlider [MFC], OnDraw
- CMFCRibbonSlider [MFC], SetPos
- CMFCRibbonSlider [MFC], SetRange
- CMFCRibbonSlider [MFC], SetZoomButtons
- CMFCRibbonSlider [MFC], SetZoomIncrement
ms.assetid: 9351ac34-f234-4e42-91e2-763f1989c8ff
ms.openlocfilehash: f2a05ca1433ca3a44b0459360e3f09fe7a274c68
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368828"
---
# <a name="cmfcribbonslider-class"></a>Classe CMFCRibbonSlider

A `CMFCRibbonSlider` classe implementa um controle deslizante que você pode adicionar a uma barra de fita ou barra de status de fita. O controle deslizante de fita se assemelha aos controles deslizantes de zoom que aparecem nos aplicativos do Office 2007.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonSlider : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonSlider::CMFCRibbonSlider](#cmfcribbonslider)|Constrói e inicializa um controle deslizante de fita.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonSlider::GetPos](#getpos)|Retorna a posição atual do controle deslizante.|
|[CONTROLE DO CMFCRibbon::GetRangeMax](#getrangemax)|Retorna o valor máximo do controle deslizante.|
|[CMFCRibbonSlider::GetRangeMin](#getrangemin)|Retorna o valor mínimo do controle deslizante.|
|[CONTROLE DO CMFCRibbon::GetRegularSize](#getregularsize)|Retorna o tamanho regular do elemento da fita. (Substitui [cmfcribbonbaseelement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|
|[CMFCRibbonSlider::GetZoomIncrement](#getzoomincrement)|Retorna o tamanho do incremento de zoom para o controle deslizante.|
|[CMFCRibbonSlider::HasZoomButtons](#haszoombuttons)|Especifica se o controle deslizante tem botões de zoom.|
|[CONTROLE DESLIZANTE CMFCRibbon::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o elemento da fita. (Substitui [cmfcribbonbaseelement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|
|[CONTROLE DO CMFCRibbon::SetPos](#setpos)|Define a posição atual do controle deslizante.|
|[CONTROLE DESLIZANTE CMFCRibbon::SetRange](#setrange)|Especifica o intervalo do controle deslizante definindo os valores mínimo e máximo.|
|[CONTROLE DO CMFCRibbon::SetZoomButtons](#setzoombuttons)|Mostra ou esconde os botões de zoom.|
|[CONTROLE DO CMFCRibbon::SetZoomIncrement](#setzoomincrement)|Define o tamanho do incremento de zoom para o controle do controle deslizante.|

## <a name="remarks"></a>Comentários

Você pode `SetRange` usar o método para configurar o intervalo de incrementos de zoom para o controle deslizante. Você pode definir a posição atual `SetPos` do controle deslizante usando o método.

Você pode exibir botões de zoom circulares no lado esquerdo `SetZoomButtons` e direito do controle deslizante usando o método. Por padrão, o controle deslizante é horizontal, o botão de zoom esquerdo exibe um sinal de menos e o botão de zoom direito exibe um sinal de mais.

O `SetZoomIncrement` método define o incremento para adicionar ou subtrair da posição atual quando um usuário clica nos botões de zoom.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonSlider` usar vários métodos na classe para definir as propriedades do controle deslizante. O exemplo mostra como `CMFCRibbonSlider` construir um objeto, exibir botões de zoom, definir a posição atual do controle deslizante e definir o intervalo de valores para o controle do controle deslizante.

[!code-cpp[NVC_MFC_RibbonApp#12](../../mfc/reference/codesnippet/cpp/cmfcribbonslider-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonslider](../../mfc/reference/cmfcribbonslider-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonslider.h

## <a name="cmfcribbonslidercmfcribbonslider"></a><a name="cmfcribbonslider"></a>CMFCRibbonSlider::CMFCRibbonSlider

Construa um controle deslizante de fita.

```
CMFCRibbonSlider(
    UINT nID,
    int nWidth=100);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] ID do controle deslizante.

[in]. *nLargura* Largura do controle deslizante em pixels.

### <a name="remarks"></a>Comentários

Constrói um controle deslizante de fita que é *nLargura* pixels de largura na categoria do painel onde o controle deslizante é adicionado. Por padrão, o controle deslizante é horizontal.

## <a name="cmfcribbonslidergetpos"></a><a name="getpos"></a>CMFCRibbonSlider::GetPos

Retorna a posição atual do controle deslizante.

```
int GetPos() const;
```

### <a name="return-value"></a>Valor retornado

A posição atual do controle deslizante, que é uma posição relativa ao início do controle deslizante.

## <a name="cmfcribbonslidergetrangemax"></a><a name="getrangemax"></a>CONTROLE DO CMFCRibbon::GetRangeMax

Obtém o incremento máximo do controle deslizante que o controle deslizante pode viajar no controle deslizante.

```
int GetRangeMax() const;
```

### <a name="return-value"></a>Valor retornado

O incremento máximo do controle deslizante que o controle deslizante pode viajar no controle deslizante.

## <a name="cmfcribbonslidergetrangemin"></a><a name="getrangemin"></a>CMFCRibbonSlider::GetRangeMin

Retorna o incremento mínimo que o controle deslizante pode viajar no controle deslizante.

```
int GetRangeMin() const;
```

### <a name="return-value"></a>Valor retornado

O incremento mínimo que o controle deslizante pode viajar no controle deslizante.

## <a name="cmfcribbonslidergetregularsize"></a><a name="getregularsize"></a>CONTROLE DO CMFCRibbon::GetRegularSize

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonslidergetzoomincrement"></a><a name="getzoomincrement"></a>CMFCRibbonSlider::GetZoomIncrement

Obtenha o incremento de zoom para o controle do controle deslizante.

```
int GetZoomIncrement() const;
```

### <a name="return-value"></a>Valor retornado

O incremento de zoom para o controle deslizante.

## <a name="cmfcribbonsliderhaszoombuttons"></a><a name="haszoombuttons"></a>CMFCRibbonSlider::HasZoomButtons

Especifica se o controle deslizante tem botões de zoom.

```
BOOL HasZoomButtons() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controle deslizante tiver botões de zoom; FALSO de outra forma.

## <a name="cmfcribbonsliderondraw"></a><a name="ondraw"></a>CONTROLE DESLIZANTE CMFCRibbon::OnDraw

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonslidersetpos"></a><a name="setpos"></a>CONTROLE DO CMFCRibbon::SetPos

Defina a posição atual do controle deslizante.

```
void SetPos(
    int nPos,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
[em] Especifica a posição a definir para o controle deslizante. A posição é relativa ao início do controle deslizante.

*Bredraw*<br/>
[em] Se TRUE, o controle deslizante será redesenhado.

## <a name="cmfcribbonslidersetrange"></a><a name="setrange"></a>CONTROLE DESLIZANTE CMFCRibbon::SetRange

Defina o intervalo de valores para o controle deslizante.

```
void SetRange(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
[em] Especifica o valor mínimo do controle deslizante.

*Nmax*<br/>
[em] Especifica o valor máximo do controle deslizante.

### <a name="remarks"></a>Comentários

Especifica a faixa de valores para o controle deslizante definindo os valores mínimo e máximo.

## <a name="cmfcribbonslidersetzoombuttons"></a><a name="setzoombuttons"></a>CONTROLE DO CMFCRibbon::SetZoomButtons

Exibir ou ocultar botões de zoom.

```
void SetZoomButtons(BOOL bSet=TRUE);
```

### <a name="parameters"></a>Parâmetros

[in]. *bSet* TRUE para exibir botões de zoom; FALSO para escondê-los.

## <a name="cmfcribbonslidersetzoomincrement"></a><a name="setzoomincrement"></a>CONTROLE DO CMFCRibbon::SetZoomIncrement

Defina o incremento de zoom para o controle do controle deslizante.

```
void SetZoomIncrement(int nZoomIncrement);
```

### <a name="parameters"></a>Parâmetros

*nZoomIncrement*<br/>
[em] Especifica o incremento de zoom do controle deslizante.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)
