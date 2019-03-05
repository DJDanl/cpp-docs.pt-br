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
ms.openlocfilehash: 85c646e2fa524268e4559b587f90c5e06971b765
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300319"
---
# <a name="cmfcribbonslider-class"></a>Classe CMFCRibbonSlider

O `CMFCRibbonSlider` classe implementa um controle deslizante que você pode adicionar uma barra de faixa de opções ou na barra de status da faixa de opções. O controle deslizante da faixa de opções lembra os controles deslizantes que aparecem nos aplicativos do Office 2007.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonSlider : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonSlider::CMFCRibbonSlider](#cmfcribbonslider)|Constrói e inicializa um controle deslizante de faixa de opções.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonSlider::GetPos](#getpos)|Retorna a posição atual do controle deslizante.|
|[CMFCRibbonSlider::GetRangeMax](#getrangemax)|Retorna o valor máximo do controle deslizante.|
|[CMFCRibbonSlider::GetRangeMin](#getrangemin)|Retorna o valor mínimo do controle deslizante.|
|[CMFCRibbonSlider::GetRegularSize](#getregularsize)|Retorna o tamanho regular do elemento da faixa de opções. (Substitui [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|
|[CMFCRibbonSlider::GetZoomIncrement](#getzoomincrement)|Retorna o tamanho do incremento de zoom para o controle deslizante.|
|[CMFCRibbonSlider::HasZoomButtons](#haszoombuttons)|Especifica se o controle deslizante tem botões de zoom.|
|[CMFCRibbonSlider::OnDraw](#ondraw)|Chamado pelo framework para desenhar o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|
|[CMFCRibbonSlider::SetPos](#setpos)|Define a posição atual do controle deslizante.|
|[CMFCRibbonSlider::SetRange](#setrange)|Especifica o intervalo do controle deslizante, definindo os valores mínimo e máximo.|
|[CMFCRibbonSlider::SetZoomButtons](#setzoombuttons)|Mostra ou oculta os botões de zoom.|
|[CMFCRibbonSlider::SetZoomIncrement](#setzoomincrement)|Define o tamanho do incremento de zoom para o controle deslizante.|

## <a name="remarks"></a>Comentários

Você pode usar o `SetRange` método para configurar o intervalo de incrementos de zoom para o controle deslizante. Você pode definir a posição atual do controle deslizante usando o `SetPos` método.

Você pode exibir botões de zoom circular à esquerda e direita do controle deslizante, usando o `SetZoomButtons` método. Por padrão, o controle deslizante é horizontal, o botão de zoom à esquerda exibe um sinal de subtração e o botão de zoom à direita exibe um sinal de adição.

O `SetZoomIncrement` método define o incremento para adicionar ou subtrair da posição atual quando um usuário clica nos botões de zoom.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonSlider` classe para definir as propriedades do controle deslizante. O exemplo mostra como construir um `CMFCRibbonSlider` do objeto, exibir botões de zoom, definir a posição atual do controle deslizante e defina o intervalo de valores para o controle deslizante.

[!code-cpp[NVC_MFC_RibbonApp#12](../../mfc/reference/codesnippet/cpp/cmfcribbonslider-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonSlider](../../mfc/reference/cmfcribbonslider-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonslider.h

##  <a name="cmfcribbonslider"></a>  CMFCRibbonSlider::CMFCRibbonSlider

Construa um controle deslizante da faixa de opções.

```
CMFCRibbonSlider(
    UINT nID,
    int nWidth=100);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[in] ID do controle deslizante.

[in]. *nWidth* largura do controle deslizante em pixels.

### <a name="remarks"></a>Comentários

Constrói um controle deslizante da faixa de opções que está *nWidth* pixels de largura da categoria do painel em que o controle deslizante é adicionado. Por padrão, o controle deslizante é horizontal.

##  <a name="getpos"></a>  CMFCRibbonSlider::GetPos

Retorna a posição atual do controle deslizante.

```
int GetPos() const;
```

### <a name="return-value"></a>Valor de retorno

A posição atual do controle deslizante, que é uma posição relativa ao início do controle deslizante.

##  <a name="getrangemax"></a>  CMFCRibbonSlider::GetRangeMax

Obtém o incremento máximo do controle deslizante que o controle deslizante pode viajar no controle deslizante.

```
int GetRangeMax() const;
```

### <a name="return-value"></a>Valor de retorno

O incremento máximo do controle deslizante que o controle deslizante pode viajar no controle deslizante.

##  <a name="getrangemin"></a>  CMFCRibbonSlider::GetRangeMin

Retorna o menor incremento que o controle deslizante pode viajar no controle deslizante.

```
int GetRangeMin() const;
```

### <a name="return-value"></a>Valor de retorno

O incremento mínimo que o controle deslizante pode viajar no controle deslizante.

##  <a name="getregularsize"></a>  CMFCRibbonSlider::GetRegularSize

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getzoomincrement"></a>  CMFCRibbonSlider::GetZoomIncrement

Obter o incremento de zoom para o controle deslizante.

```
int GetZoomIncrement() const;
```

### <a name="return-value"></a>Valor de retorno

O incremento de zoom para o controle deslizante.

##  <a name="haszoombuttons"></a>  CMFCRibbonSlider::HasZoomButtons

Especifica se o controle deslizante tem botões de zoom.

```
BOOL HasZoomButtons() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle deslizante tem botões de zoom; FALSE caso contrário.

##  <a name="ondraw"></a>  CMFCRibbonSlider::OnDraw

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpos"></a>  CMFCRibbonSlider::SetPos

Defina a posição atual do controle deslizante.

```
void SetPos(
    int nPos,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
[in] Especifica a posição a ser definido para o controle deslizante. A posição é relativo ao início do controle deslizante.

*bRedraw*<br/>
[in] Se for TRUE, o controle deslizante será redesenhado.

##  <a name="setrange"></a>  CMFCRibbonSlider::SetRange

Defina o intervalo de valores para o controle deslizante.

```
void SetRange(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
[in] Especifica o valor mínimo do controle deslizante.

*nMax*<br/>
[in] Especifica o valor máximo do controle deslizante.

### <a name="remarks"></a>Comentários

Especifica o intervalo de valores para o controle deslizante, definindo os valores mínimo e máximo.

##  <a name="setzoombuttons"></a>  CMFCRibbonSlider::SetZoomButtons

Exibir ou ocultar botões de zoom.

```
void SetZoomButtons(BOOL bSet=TRUE);
```

### <a name="parameters"></a>Parâmetros

[in]. *bSet* True para exibir botões de zoom; FALSO para ocultá-los.

##  <a name="setzoomincrement"></a>  CMFCRibbonSlider::SetZoomIncrement

Defina o incremento de zoom para o controle deslizante.

```
void SetZoomIncrement(int nZoomIncrement);
```

### <a name="parameters"></a>Parâmetros

*nZoomIncrement*<br/>
[in] Especifica o incremento de zoom do controle deslizante.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)
