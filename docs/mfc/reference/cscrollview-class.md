---
title: Classe CScrollView
ms.date: 11/04/2016
f1_keywords:
- CScrollView
- AFXWIN/CScrollView
- AFXWIN/CScrollView::CScrollView
- AFXWIN/CScrollView::CheckScrollBars
- AFXWIN/CScrollView::FillOutsideRect
- AFXWIN/CScrollView::GetDeviceScrollPosition
- AFXWIN/CScrollView::GetDeviceScrollSizes
- AFXWIN/CScrollView::GetScrollPosition
- AFXWIN/CScrollView::GetTotalSize
- AFXWIN/CScrollView::ResizeParentToFit
- AFXWIN/CScrollView::ScrollToPosition
- AFXWIN/CScrollView::SetScaleToFitSize
- AFXWIN/CScrollView::SetScrollSizes
helpviewer_keywords:
- CScrollView [MFC], CScrollView
- CScrollView [MFC], CheckScrollBars
- CScrollView [MFC], FillOutsideRect
- CScrollView [MFC], GetDeviceScrollPosition
- CScrollView [MFC], GetDeviceScrollSizes
- CScrollView [MFC], GetScrollPosition
- CScrollView [MFC], GetTotalSize
- CScrollView [MFC], ResizeParentToFit
- CScrollView [MFC], ScrollToPosition
- CScrollView [MFC], SetScaleToFitSize
- CScrollView [MFC], SetScrollSizes
ms.assetid: 4ba16dac-1acb-4be0-bb55-5fb695b6948d
ms.openlocfilehash: 5d0eb163fae2aa5fc63470e1c499311ab1a402a6
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754415"
---
# <a name="cscrollview-class"></a>Classe CScrollView

Um [CView](../../mfc/reference/cview-class.md) com recursos de rolagem.

## <a name="syntax"></a>Sintaxe

```
class CScrollView : public CView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CScrollView::CScrollView](#cscrollview)|Constrói um objeto `CScrollView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CScrollView::CheckScrollBars](#checkscrollbars)|Indica se a visualização do pergaminho tem barras de rolagem horizontais e verticais.|
|[CScrollView::FillOutsideRect](#filloutsiderect)|Preenche a área de uma vista fora da área de rolagem.|
|[CScrollView::GetDeviceScrollPosition](#getdevicescrollposition)|Obtém a posição atual do pergaminho nas unidades do dispositivo.|
|[CScrollView::GetDeviceScrollSizes](#getdevicescrollsizes)|Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e página da exibição rolável. Os tamanhos estão em unidades de dispositivos.|
|[CScrollView::GetScrollPosition](#getscrollposition)|Obtém a posição atual do pergaminho em unidades lógicas.|
|[CScrollView::GetTotalSize](#gettotalsize)|Obtém o tamanho total da exibição do pergaminho em unidades lógicas.|
|[CScrollView::RedimensionarParentToFit](#resizeparenttofit)|Faz com que o tamanho da vista dite o tamanho de seu quadro.|
|[CScrollView::ScrollToPosition](#scrolltoposition)|Rola a exibição para um determinado ponto, especificado em unidades lógicas.|
|[CScrollView::SetScaleToFitSize](#setscaletofitsize)|Coloca a visualização de rolagem no modo escala-para-ajuste.|
|[CScrollView::SetScrollSizes](#setscrollsizes)|Define o modo de mapeamento da exibição de rolagem, o tamanho total e os valores de rolagem horizontal e vertical.|

## <a name="remarks"></a>Comentários

Você pode lidar com rolagem padrão `CView` em qualquer classe derivada, substituindo as funções de membro [OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) mapeadas por mensagem. Mas `CScrollView` adiciona os seguintes recursos às suas `CView` capacidades:

- Ele gerencia tamanhos de janelas e visualizações e modos de mapeamento.

- Ele rola automaticamente em resposta a mensagens de barra de rolagem.

- Ele rola automaticamente em resposta às mensagens do teclado, de um mouse que não rola ou da roda IntelliMouse.

Para rolar automaticamente em resposta às mensagens do teclado, adicione uma mensagem de WM_KEYDOWN e teste para VK_DOWN, VK_PREV e ligue [para SetScrollPos](/windows/win32/api/winuser/nf-winuser-setscrollpos).

Você pode lidar com a roda do mouse rolando-se sobrepondo as funções de membro [onMouseWheel](../../mfc/reference/cwnd-class.md#onmousewheel) e [OnRegisteredMouseWheel.](../../mfc/reference/cwnd-class.md#onregisteredmousewheel) Como são `CScrollView`para, essas funções de membro suportam o comportamento recomendado para [WM_MOUSEWHEEL](/windows/win32/inputdev/wm-mousewheel), a mensagem de rotação da roda.

Para aproveitar a rolagem automática, obtenha `CScrollView` sua `CView`classe de visualização em vez de . Quando a exibição for criada pela primeira vez, se você quiser calcular o tamanho `SetScrollSizes` da exibição rolável com base no tamanho do documento, chame a função de membro a partir da substituição de [CView::OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) ou [CView:OnUpdate](../../mfc/reference/cview-class.md#onupdate). (Você deve escrever seu próprio código para consultar o tamanho do documento. Por exemplo, consulte a [amostra Scribble](../../overview/visual-cpp-samples.md).)

A chamada `SetScrollSizes` para a função membro define o modo de mapeamento da exibição, as dimensões totais da exibição do pergaminho e os valores para rolar horizontal e verticalmente. Todos os tamanhos estão em unidades lógicas. O tamanho lógico da exibição geralmente é calculado a partir de dados armazenados no documento, mas em alguns casos você pode querer especificar um tamanho fixo. Para exemplos de ambas as abordagens, consulte [CScrollView::SetScrollSizes](#setscrollsizes).

Você especifica os valores para rolar horizontal e verticalmente em unidades lógicas. Por padrão, se o usuário clicar em um eixo `CScrollView` de barra de rolagem fora da caixa de rolagem, rolará uma "página". Se o usuário clicar em uma seta de `CScrollView` rolagem em cada extremidade de uma barra de rolagem, rolará uma "linha". Por padrão, uma página é 1/10 do tamanho total da exibição; uma linha é 1/10 do tamanho da página. Anular esses valores padrão passando tamanhos personalizados na função do `SetScrollSizes` membro. Por exemplo, você pode definir o tamanho horizontal para alguma fração da largura do tamanho total e do tamanho vertical para a altura de uma linha na fonte atual.

Em vez de `CScrollView` rolar, pode dimensionar automaticamente a exibição para o tamanho atual da janela. Neste modo, a exibição não tem barras de rolagem e a visão lógica é esticada ou encolhida para exatamente se adequar à área cliente da janela. Para usar esse recurso de escala para ajuste, chame [CScrollView::SetScaleToFitSize](#setscaletofitsize). (Ligue `SetScaleToFitSize` para `SetScrollSizes`um ou, mas não ambos.)

Antes `OnDraw` que a função membro da sua `CScrollView` classe de exibição derivada `CPaintDC` seja chamada, ajusta automaticamente a origem da porta de exibição para o objeto de contexto do dispositivo para `OnDraw`o que ele passa .

Para ajustar a origem da porta `CScrollView` de exibição para a janela de rolagem, substitui [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc). Este ajuste é `CPaintDC` automático para `CScrollView` o `OnDraw`contexto do `CScrollView::OnPrepareDC` dispositivo que passa para , mas você `CClientDC`deve chamar-se para quaisquer outros contextos de dispositivo que você usa, como um . Você pode `CScrollView::OnPrepareDC` substituir para definir a caneta, a cor de fundo e outros atributos de desenho, mas chame a classe base para fazer o dimensionamento.

As barras de rolagem podem aparecer em três lugares em relação a uma exibição, conforme mostrado nos seguintes casos:

- As barras de rolagem padrão no estilo janela podem ser definidas para a exibição usando o WS_HSCROLL e WS_VSCROLL[Estilos do Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles).

- Os controles da barra de rolagem também podem ser adicionados ao quadro que contém a exibição, nesse caso, o framework encaminha WM_HSCROLL e WM_VSCROLL mensagens da janela do quadro para a exibição ativa atualmente.

- O framework também encaminha mensagens de rolagem de um `CSplitterWnd` controle divisor para o painel de divisor ativo atualmente (uma exibição). Quando colocado em um [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md) com `CScrollView` barras de rolagem compartilhadas, um objeto usará as compartilhadas em vez de criar a sua própria.

Para obter mais `CScrollView`informações sobre como usar, consulte [Document/View Architecture](../../mfc/document-view-architecture.md) e [Derived View Classes Disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

`CScrollView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cscrollviewcheckscrollbars"></a><a name="checkscrollbars"></a>CScrollView::CheckScrollBars

Ligue para esta função de membro para determinar se a exibição do pergaminho tem barras horizontais e verticais.

```cpp
void CheckScrollBars(
    BOOL& bHasHorzBar,
    BOOL& bHasVertBar) const;
```

### <a name="parameters"></a>Parâmetros

*bHashorzBar*<br/>
Indica que o aplicativo tem uma barra de rolagem horizontal.

*bHasVertBar*<br/>
Indica que o aplicativo tem uma barra de rolagem vertical.

## <a name="cscrollviewcscrollview"></a><a name="cscrollview"></a>CScrollView::CScrollView

Constrói um objeto `CScrollView`.

```
CScrollView();
```

### <a name="remarks"></a>Comentários

Você deve `SetScrollSizes` ligar `SetScaleToFitSize` para um ou antes que a exibição do pergaminho seja utilizável.

## <a name="cscrollviewfilloutsiderect"></a><a name="filloutsiderect"></a>CScrollView::FillOutsideRect

Chamada `FillOutsideRect` para preencher a área da vista que aparece fora da área de rolagem.

```cpp
void FillOutsideRect(
    CDC* pDC,
    CBrush* pBrush);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto do dispositivo em que o enchimento deve ser feito.

*pBrush*<br/>
Pincel com o qual a área deve ser preenchida.

### <a name="remarks"></a>Comentários

Use `FillOutsideRect` na função de `OnEraseBkgnd` manipulador da visualização de pergaminho para evitar repintura excessiva de fundo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#164](../../mfc/codesnippet/cpp/cscrollview-class_1.cpp)]

## <a name="cscrollviewgetdevicescrollposition"></a><a name="getdevicescrollposition"></a>CScrollView::GetDeviceScrollPosition

Ligue `GetDeviceScrollPosition` quando precisar das posições horizontais e verticais atuais das caixas de rolagem nas barras de rolagem.

```
CPoint GetDeviceScrollPosition() const;
```

### <a name="return-value"></a>Valor retornado

As posições horizontais e verticais (em `CPoint` unidades de dispositivo) das caixas de rolagem como objeto.

### <a name="remarks"></a>Comentários

Este par de coordenadas corresponde ao local no documento para o qual o canto superior esquerdo da exibição foi rolado. Isso é útil para compensar as posições do dispositivo do mouse para as posições do dispositivo de exibição de rolagem.

`GetDeviceScrollPosition`retorna valores em unidades do dispositivo. Se você quiser unidades `GetScrollPosition` lógicas, use em vez disso.

## <a name="cscrollviewgetdevicescrollsizes"></a><a name="getdevicescrollsizes"></a>CScrollView::GetDeviceScrollSizes

`GetDeviceScrollSizes`obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e página da exibição rolável.

```cpp
void GetDeviceScrollSizes(
    int& nMapMode,
    SIZE& sizeTotal,
    SIZE& sizePage,
    SIZE& sizeLine) const;
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
Retorna o modo de mapeamento atual para esta exibição. Para obter uma lista de valores possíveis, consulte `SetScrollSizes`.

*tamanhoTotal*<br/>
Retorna o tamanho total atual da exibição do pergaminho nas unidades do dispositivo.

*sizePage*<br/>
Retorna as quantidades horizontais e verticais atuais para rolar em cada direção em resposta a um clique do mouse em um eixo de barra de rolagem. O `cx` membro contém a quantidade horizontal. O `cy` membro contém a quantidade vertical.

*sizeLine*<br/>
Retorna as quantidades horizontais e verticais atuais para rolar em cada direção em resposta a um clique do mouse em uma seta de rolagem. O `cx` membro contém a quantidade horizontal. O `cy` membro contém a quantidade vertical.

### <a name="remarks"></a>Comentários

Os tamanhos estão em unidades de dispositivos. Esta função de membro raramente é chamada.

## <a name="cscrollviewgetscrollposition"></a><a name="getscrollposition"></a>CScrollView::GetScrollPosition

Ligue `GetScrollPosition` quando precisar das posições horizontais e verticais atuais das caixas de rolagem nas barras de rolagem.

```
CPoint GetScrollPosition() const;
```

### <a name="return-value"></a>Valor retornado

As posições horizontais e verticais (em `CPoint` unidades lógicas) das caixas de rolagem como objeto.

### <a name="remarks"></a>Comentários

Este par de coordenadas corresponde ao local no documento para o qual o canto superior esquerdo da exibição foi rolado.

`GetScrollPosition`retorna valores em unidades lógicas. Se você quiser unidades `GetDeviceScrollPosition` de dispositivo, use em vez disso.

## <a name="cscrollviewgettotalsize"></a><a name="gettotalsize"></a>CScrollView::GetTotalSize

Chamada `GetTotalSize` para recuperar os tamanhos horizontais e verticais atuais da exibição do pergaminho.

```
CSize GetTotalSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho total da exibição do pergaminho em unidades lógicas. O tamanho horizontal `cx` está no `CSize` membro do valor de retorno. O tamanho vertical `cy` está no membro.

## <a name="cscrollviewresizeparenttofit"></a><a name="resizeparenttofit"></a>CScrollView::RedimensionarParentToFit

Ligue `ResizeParentToFit` para que o tamanho da sua vista dite o tamanho da janela do quadro.

```cpp
void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShrinkOnly*<br/>
O tipo de redimensionamento para executar. O valor padrão, TRUE, reduz a janela do quadro, se for o caso. As barras de rolagem ainda aparecerão para vistas grandes ou janelas de molduras pequenas. Um valor de FALSE faz com que a vista sempre redimensione a janela do quadro exatamente. Isso pode ser um pouco perigoso, já que a janela do quadro pode ficar muito grande para caber dentro da janela de quadro de interface de documento múltiplo (MDI) ou na tela.

### <a name="remarks"></a>Comentários

Isso é recomendado apenas para visualizações em janelas de moldura de criança MDI. Use `ResizeParentToFit` na `OnInitialUpdate` função de manipulador `CScrollView` da sua classe derivada. Para um exemplo desta função de membro, consulte [CScrollView::SetScrollSizes](#setscrollsizes).

`ResizeParentToFit`presume que o tamanho da janela de exibição foi definido. Se o tamanho da janela `ResizeParentToFit` de exibição não tiver sido definido quando for chamado, você terá uma afirmação. Para garantir que isso não aconteça, faça `ResizeParentToFit`a seguinte chamada antes de ligar:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

## <a name="cscrollviewscrolltoposition"></a><a name="scrolltoposition"></a>CScrollView::ScrollToPosition

Chamada `ScrollToPosition` para rolar para um determinado ponto de vista.

```cpp
void ScrollToPosition(POINT pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
O ponto para rolar, em unidades lógicas. O `x` membro deve ser um valor positivo (maior ou igual a 0, até o tamanho total da vista). O mesmo vale `y` para o membro quando o modo de mapeamento é MM_TEXT. O `y` membro é negativo em modos de mapeamento diferentes de MM_TEXT.

### <a name="remarks"></a>Comentários

A vista será rolada de modo que este ponto esteja no canto superior esquerdo da janela. Esta função de membro não deve ser chamada se a exibição for dimensionada para se encaixar.

## <a name="cscrollviewsetscaletofitsize"></a><a name="setscaletofitsize"></a>CScrollView::SetScaleToFitSize

Ligue `SetScaleToFitSize` quando quiser dimensionar o tamanho da porta de exibição para o tamanho da janela atual automaticamente.

```cpp
void SetScaleToFitSize(SIZE sizeTotal);
```

### <a name="parameters"></a>Parâmetros

*tamanhoTotal*<br/>
Os tamanhos horizontal e vertical para os quais a vista deve ser dimensionada. O tamanho da visualização do pergaminho é medido em unidades lógicas. O tamanho horizontal está `cx` contido no membro. O tamanho vertical está `cy` contido no membro. Ambos `cx` `cy` e devem ser maiores ou iguais a 0.

### <a name="remarks"></a>Comentários

Com barras de rolagem, apenas uma parte da visão lógica pode ser visível a qualquer momento. Mas com a capacidade de escala para ajuste, a exibição não tem barras de rolagem e a visão lógica é esticada ou encolhida para exatamente se adequar à área cliente da janela. Quando a janela é redimensionada, a visualização desenha seus dados em uma nova escala com base no tamanho da janela.

Você normalmente colocará a `SetScaleToFitSize` chamada em sua substituição da `OnInitialUpdate` função de membro da exibição. Se você não quiser dimensionamento `SetScrollSizes` automático, ligue para a função membro.

`SetScaleToFitSize`pode ser usado para implementar uma operação "Zoom to Fit". Use `SetScrollSizes` para reinicializar a rolagem.

`SetScaleToFitSize`presume que o tamanho da janela de exibição foi definido. Se o tamanho da janela `SetScaleToFitSize` de exibição não tiver sido definido quando for chamado, você terá uma afirmação. Para garantir que isso não aconteça, faça `SetScaleToFitSize`a seguinte chamada antes de ligar:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

## <a name="cscrollviewsetscrollsizes"></a><a name="setscrollsizes"></a>CScrollView::SetScrollSizes

Ligue `SetScrollSizes` quando a vista estiver prestes a ser atualizada.

```cpp
void SetScrollSizes(
    int nMapMode,
    SIZE sizeTotal,
    const SIZE& sizePage = sizeDefault,
    const SIZE& sizeLine = sizeDefault);
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
O modo de mapeamento a ser definido para esta exibição. Os valores possíveis incluem:

|Modo de mapeamento|Unidade Lógica|O eixo y positivo se estende...|
|------------------|------------------|---------------------------------|
|Mm_text|1 pixel|Descendente|
|Mm_himetric|0,01 mm|Ascendente|
|Mm_twips|1/1440 em|Ascendente|
|MM_HIENGLISH|0,001 em|Ascendente|
|MM_LOMETRIC|0,1 mm|Ascendente|
|Mm_loenglish|0,01 em|Ascendente|

Todos esses modos são definidos pelo Windows. Dois modos de mapeamento padrão, MM_ISOTROPIC `CScrollView`e MM_ANISOTROPIC, não são usados para . A biblioteca de `SetScaleToFitSize` classe fornece a função membro para dimensionar a exibição para o tamanho da janela. A coluna três na tabela acima descreve a orientação de coordenadas.

*tamanhoTotal*<br/>
O tamanho total da exibição do pergaminho. O `cx` membro contém a extensão horizontal. O `cy` membro contém a extensão vertical. Os tamanhos estão em unidades lógicas. Ambos `cx` `cy` e devem ser maiores ou iguais a 0.

*sizePage*<br/>
O valor horizontal e vertical equivale a rolar em cada direção em resposta a um clique do mouse em um eixo de barra de rolagem. O `cx` membro contém a quantidade horizontal. O `cy` membro contém a quantidade vertical.

*sizeLine*<br/>
A horizontal e vertical equivale a rolar em cada direção em resposta a um clique do mouse em uma seta de rolagem. O `cx` membro contém a quantidade horizontal. O `cy` membro contém a quantidade vertical.

### <a name="remarks"></a>Comentários

Chame-o na substituição `OnUpdate` da função membro para ajustar as características de rolagem quando, por exemplo, o documento for exibido inicialmente ou quando ele mudar de tamanho.

Você normalmente obterá informações de tamanho do documento associado da exibição, chamando uma função de membro do documento, talvez chamada `GetMyDocSize`de , que você fornece com sua classe de documento derivada. O código a seguir mostra esta abordagem:

[!code-cpp[NVC_MFCDocView#166](../../mfc/codesnippet/cpp/cscrollview-class_3.cpp)]

Alternativamente, às vezes você pode precisar definir um tamanho fixo, como no seguinte código:

[!code-cpp[NVC_MFCDocView#167](../../mfc/codesnippet/cpp/cscrollview-class_4.cpp)]

Você deve definir o modo de mapeamento para qualquer um dos modos de mapeamento do Windows, exceto MM_ISOTROPIC ou MM_ANISOTROPIC. Se você quiser usar um modo de `SetScaleToFitSize` mapeamento sem `SetScrollSizes`restrições, chame a função de membro em vez de .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#168](../../mfc/codesnippet/cpp/cscrollview-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#169](../../mfc/codesnippet/cpp/cscrollview-class_6.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC DIBLOOK](../../overview/visual-cpp-samples.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)
