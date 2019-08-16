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
ms.openlocfilehash: b89daaae4bb578d328e1468cc29470825e19c670
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502600"
---
# <a name="cscrollview-class"></a>Classe CScrollView

Um [cvisualização](../../mfc/reference/cview-class.md) com recursos de rolagem.

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
|[CScrollView::CheckScrollBars](#checkscrollbars)|Indica se a exibição de rolagem tem barras de rolagem horizontal e vertical.|
|[CScrollView::FillOutsideRect](#filloutsiderect)|Preenche a área de uma exibição fora da área de rolagem.|
|[CScrollView::GetDeviceScrollPosition](#getdevicescrollposition)|Obtém a posição de rolagem atual nas unidades do dispositivo.|
|[CScrollView::GetDeviceScrollSizes](#getdevicescrollsizes)|Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e de página da exibição rolável. Os tamanhos estão em unidades de dispositivo.|
|[CScrollView::GetScrollPosition](#getscrollposition)|Obtém a posição de rolagem atual em unidades lógicas.|
|[CScrollView::GetTotalSize](#gettotalsize)|Obtém o tamanho total da exibição de rolagem em unidades lógicas.|
|[CScrollView::ResizeParentToFit](#resizeparenttofit)|Faz com que o tamanho da exibição dite o tamanho de seu quadro.|
|[CScrollView::ScrollToPosition](#scrolltoposition)|Rola a exibição para um determinado ponto, especificado em unidades lógicas.|
|[CScrollView::SetScaleToFitSize](#setscaletofitsize)|Coloca a exibição de rolagem no modo de escala a ajuste.|
|[CScrollView::SetScrollSizes](#setscrollsizes)|Define o modo de mapeamento da exibição de rolagem, o tamanho total e os valores de rolagem horizontal e vertical.|

## <a name="remarks"></a>Comentários

Você pode manipular a rolagem padrão em qualquer classe derivada de `CView` , substituindo as funções de membro [OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) mapeadas por mensagem. Mas `CScrollView` adiciona os seguintes recursos a seus `CView` recursos:

- Ele gerencia tamanhos de janela e visor e modos de mapeamento.

- Ele rola automaticamente em resposta a mensagens da barra de rolagem.

- Ele rola automaticamente em resposta a mensagens do teclado, de um mouse sem rolagem ou da roda do IntelliMouse.

Para rolar automaticamente em resposta a mensagens do teclado, adicione uma mensagem WM_KEYDOWN e teste para VK_DOWN, VK_PREV e chame [SetScrollPos](/windows/win32/api/winuser/nf-winuser-setscrollpos).

Você pode manipular a rolagem de roda do mouse substituindo as funções de membro [OnMouseWheel](../../mfc/reference/cwnd-class.md#onmousewheel) e [OnRegisteredMouseWheel](../../mfc/reference/cwnd-class.md#onregisteredmousewheel) mapeadas por mensagem. Como são para `CScrollView`o, essas funções de membro dão suporte ao comportamento recomendado para [WM_MOUSEWHEEL](/windows/win32/inputdev/wm-mousewheel), a mensagem de rotação de roda.

Para aproveitar a rolagem automática, derive a classe View de `CScrollView` em vez `CView`de de. Quando a exibição é criada pela primeira vez, se você quiser calcular o tamanho da exibição rolável com base no tamanho do documento, chame a `SetScrollSizes` função de membro da sua substituição de [cvisualização:: OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) ou [cvisualização:: OnUpdate](../../mfc/reference/cview-class.md#onupdate). (Você deve escrever seu próprio código para consultar o tamanho do documento. Para obter um exemplo, consulte o [exemplo de rabisco](../../overview/visual-cpp-samples.md).)

A chamada para a `SetScrollSizes` função membro define o modo de mapeamento da exibição, o total de dimensões da exibição de rolagem e os valores a rolar horizontalmente e verticalmente. Todos os tamanhos estão em unidades lógicas. O tamanho lógico da exibição geralmente é calculado a partir dos dados armazenados no documento, mas, em alguns casos, você pode desejar especificar um tamanho fixo. Para obter exemplos de ambas as abordagens, consulte [CScrollView:: SetScrollSizes](#setscrollsizes).

Você especifica os valores a rolar horizontal e verticalmente em unidades lógicas. Por padrão, se o usuário clicar em um eixo da barra de rolagem fora da `CScrollView` caixa de rolagem, rolará uma "página". Se o usuário clicar em uma seta de rolagem em qualquer uma das extremidades `CScrollView` de uma barra de rolagem, rolará uma "linha". Por padrão, uma página é 1/10 do tamanho total da exibição; uma linha é 1/10 do tamanho da página. Substitua esses valores padrão passando os `SetScrollSizes` tamanhos personalizados na função membro. Por exemplo, você pode definir o tamanho horizontal como uma fração da largura do tamanho total e do tamanho vertical para a altura de uma linha na fonte atual.

Em vez de rolar, `CScrollView` o pode dimensionar automaticamente a exibição para o tamanho da janela atual. Nesse modo, o modo de exibição não tem barras de rolagem e a exibição lógica é ampliada ou reduzida para se ajustar exatamente à área do cliente da janela. Para usar esse recurso de escala a ajuste, chame [CScrollView:: SetScaleToFitSize](#setscaletofitsize). (Chame um `SetScaleToFitSize` ou `SetScrollSizes`, mas não ambos.)

Antes que `OnDraw` a função membro da classe de exibição derivada seja chamada `CScrollView` , o ajusta automaticamente a origem do visor `CPaintDC` para o objeto de contexto de dispositivo para `OnDraw`o qual ele passa.

Para ajustar a origem do visor para a janela de rolagem, `CScrollView` substitui [cvisualização:: OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc). Esse ajuste é automático para o `CPaintDC` contexto de dispositivo `CScrollView` que passa `OnDraw`para, mas você deve `CScrollView::OnPrepareDC` chamar-se para outros contextos de dispositivo que você usar, `CClientDC`como um. Você pode substituir `CScrollView::OnPrepareDC` para definir a caneta, a cor do plano de fundo e outros atributos de desenho, mas chamar a classe base para fazer o dimensionamento.

As barras de rolagem podem aparecer em três locais em relação a uma exibição, conforme mostrado nos seguintes casos:

- Barras de rolagem de estilo de janela padrão podem ser definidas para a exibição usando os[estilos do Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles)WS_HSCROLL e WS_VSCROLL.

- Os controles de barra de rolagem também podem ser adicionados ao quadro que contém a exibição. nesse caso, a estrutura encaminha as mensagens WM_HSCROLL e WM_VSCROLL da janela do quadro para a exibição ativa no momento.

- A estrutura também encaminha mensagens de rolagem de `CSplitterWnd` um controle de Splitter para o painel de divisão ativo no momento (uma exibição). Quando colocado em um [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md) com barras de rolagem compartilhadas, um `CScrollView` objeto usará os compartilhados em vez de criar o seu próprio.

Para obter mais informações sobre `CScrollView`como usar o, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [classes de exibição derivadas disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cvisualização](../../mfc/reference/cview-class.md)

`CScrollView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="checkscrollbars"></a>CScrollView::CheckScrollBars

Chame essa função de membro para determinar se a exibição de rolagem tem barras horizontais e verticais.

```
void CheckScrollBars(
    BOOL& bHasHorzBar,
    BOOL& bHasVertBar) const;
```

### <a name="parameters"></a>Parâmetros

*bHasHorzBar*<br/>
Indica que o aplicativo tem uma barra de rolagem horizontal.

*bHasVertBar*<br/>
Indica que o aplicativo tem uma barra de rolagem vertical.

##  <a name="cscrollview"></a>CScrollView::CScrollView

Constrói um objeto `CScrollView`.

```
CScrollView();
```

### <a name="remarks"></a>Comentários

Você deve chamar `SetScrollSizes` ou `SetScaleToFitSize` antes de a exibição de rolagem ser utilizável.

##  <a name="filloutsiderect"></a>  CScrollView::FillOutsideRect

Chame `FillOutsideRect` para preencher a área da exibição que aparece fora da área de rolagem.

```
void FillOutsideRect(
    CDC* pDC,
    CBrush* pBrush);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto do dispositivo no qual o preenchimento deve ser feito.

*pBrush*<br/>
Pincel com o qual a área deve ser preenchida.

### <a name="remarks"></a>Comentários

Use `FillOutsideRect` na função de manipulador da `OnEraseBkgnd` exibição de rolagem para evitar o redesenho em segundo plano excessivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#164](../../mfc/codesnippet/cpp/cscrollview-class_1.cpp)]

##  <a name="getdevicescrollposition"></a>  CScrollView::GetDeviceScrollPosition

Chame `GetDeviceScrollPosition` quando precisar das posições horizontal e vertical atuais das caixas de rolagem nas barras de rolagem.

```
CPoint GetDeviceScrollPosition() const;
```

### <a name="return-value"></a>Valor de retorno

As posições horizontal e vertical (em unidades de dispositivo) das caixas de rolagem `CPoint` como um objeto.

### <a name="remarks"></a>Comentários

Esse par de coordenadas corresponde ao local no documento no qual o canto superior esquerdo da exibição foi rolado. Isso é útil para deslocar as posições de dispositivo do mouse para rolar a exibição de posições do dispositivo.

`GetDeviceScrollPosition`Retorna valores em unidades de dispositivo. Se você quiser unidades lógicas, `GetScrollPosition` use em vez disso.

##  <a name="getdevicescrollsizes"></a>  CScrollView::GetDeviceScrollSizes

`GetDeviceScrollSizes`Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e de página da exibição rolável.

```
void GetDeviceScrollSizes(
    int& nMapMode,
    SIZE& sizeTotal,
    SIZE& sizePage,
    SIZE& sizeLine) const;
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
Retorna o modo de mapeamento atual desta exibição. Para obter uma lista de valores possíveis, consulte `SetScrollSizes`.

*sizeTotal*<br/>
Retorna o tamanho total atual da exibição de rolagem nas unidades do dispositivo.

*sizePage*<br/>
Retorna os valores horizontais e verticais atuais para rolar em cada direção em resposta a um clique do mouse em um eixo da barra de rolagem. O `cx` membro contém o valor horizontal. O `cy` membro contém o valor vertical.

*sizeLine*<br/>
Retorna os valores horizontais e verticais atuais para rolar em cada direção em resposta a um clique do mouse em uma seta de rolagem. O `cx` membro contém o valor horizontal. O `cy` membro contém o valor vertical.

### <a name="remarks"></a>Comentários

Os tamanhos estão em unidades de dispositivo. Essa função de membro raramente é chamada.

##  <a name="getscrollposition"></a>  CScrollView::GetScrollPosition

Chame `GetScrollPosition` quando precisar das posições horizontal e vertical atuais das caixas de rolagem nas barras de rolagem.

```
CPoint GetScrollPosition() const;
```

### <a name="return-value"></a>Valor de retorno

As posições horizontal e vertical (em unidades lógicas) das caixas de rolagem `CPoint` como um objeto.

### <a name="remarks"></a>Comentários

Esse par de coordenadas corresponde ao local no documento no qual o canto superior esquerdo da exibição foi rolado.

`GetScrollPosition`Retorna valores em unidades lógicas. Se você quiser unidades de dispositivo, `GetDeviceScrollPosition` use em vez disso.

##  <a name="gettotalsize"></a>CScrollView:: GetTotalSize

Chame `GetTotalSize` para recuperar os tamanhos horizontal e vertical atuais da exibição de rolagem.

```
CSize GetTotalSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho total da exibição de rolagem em unidades lógicas. O tamanho horizontal está no `cx` membro `CSize` do valor de retorno. O tamanho vertical está no `cy` membro.

##  <a name="resizeparenttofit"></a>  CScrollView::ResizeParentToFit

Chame `ResizeParentToFit` para permitir que o tamanho da sua exibição dite o tamanho da janela do quadro.

```
void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShrinkOnly*<br/>
O tipo de redimensionamento a ser executado. O valor padrão, TRUE, reduz a janela do quadro, se apropriado. As barras de rolagem ainda aparecerão para grandes exibições ou janelas de quadros pequenas. Um valor FALSE faz com que a exibição sempre redimensione a janela do quadro exatamente. Isso pode ser um pouco perigoso, uma vez que a janela do quadro pode ficar muito grande para se ajustar dentro da janela de quadro da interface de vários documentos (MDI) ou da tela.

### <a name="remarks"></a>Comentários

Isso é recomendado apenas para exibições em janelas de quadros filho MDI. Use `ResizeParentToFit` `CScrollView` na função de manipuladordaclassederivada.`OnInitialUpdate` Para obter um exemplo dessa função de membro, consulte [CScrollView:: SetScrollSizes](#setscrollsizes).

`ResizeParentToFit`pressupõe que o tamanho da janela de exibição foi definido. Se o tamanho da janela de exibição não tiver sido `ResizeParentToFit` definido quando for chamado, você receberá uma asserção. Para garantir que isso não aconteça, faça a seguinte chamada antes de chamar `ResizeParentToFit`:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

##  <a name="scrolltoposition"></a>CScrollView::ScrollToPosition

Chame `ScrollToPosition` para rolar para um determinado ponto na exibição.

```
void ScrollToPosition(POINT pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
O ponto para rolar até, em unidades lógicas. O `x` membro deve ser um valor positivo (maior ou igual a 0, até o tamanho total da exibição). O mesmo é verdadeiro para o `y` membro quando o modo de mapeamento é MM_TEXT. O `y` membro é negativo em modos de mapeamento diferentes de MM_TEXT.

### <a name="remarks"></a>Comentários

O modo de exibição será rolado para que esse ponto esteja no canto superior esquerdo da janela. Essa função de membro não deve ser chamada se a exibição for dimensionada para caber.

##  <a name="setscaletofitsize"></a>  CScrollView::SetScaleToFitSize

Chame `SetScaleToFitSize` quando desejar dimensionar automaticamente o tamanho do visor para o tamanho da janela atual.

```
void SetScaleToFitSize(SIZE sizeTotal);
```

### <a name="parameters"></a>Parâmetros

*sizeTotal*<br/>
Os tamanhos horizontal e vertical para os quais a exibição deve ser dimensionada. O tamanho da exibição de rolagem é medido em unidades lógicas. O tamanho horizontal está contido no `cx` membro. O tamanho vertical está contido no `cy` membro. `cx` E`cy` deve ser maior ou igual a 0.

### <a name="remarks"></a>Comentários

Com as barras de rolagem, apenas uma parte da exibição lógica pode estar visível a qualquer momento. Mas com a capacidade de ajustar ao ajuste, a exibição não tem barras de rolagem e a exibição lógica é ampliada ou reduzida para se ajustar exatamente à área do cliente da janela. Quando a janela é redimensionada, a exibição desenha seus dados em uma nova escala com base no tamanho da janela.

Normalmente, você colocará a chamada `SetScaleToFitSize` para em sua substituição da função de `OnInitialUpdate` membro da exibição. Se você não quiser o dimensionamento automático, chame `SetScrollSizes` a função de membro em vez disso.

`SetScaleToFitSize`pode ser usado para implementar uma operação de "ajuste de zoom". Use `SetScrollSizes` para reinicializar a rolagem.

`SetScaleToFitSize`pressupõe que o tamanho da janela de exibição foi definido. Se o tamanho da janela de exibição não tiver sido `SetScaleToFitSize` definido quando for chamado, você receberá uma asserção. Para garantir que isso não aconteça, faça a seguinte chamada antes de chamar `SetScaleToFitSize`:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

##  <a name="setscrollsizes"></a>  CScrollView::SetScrollSizes

Chame `SetScrollSizes` quando a exibição estiver prestes a ser atualizada.

```
void SetScrollSizes(
    int nMapMode,
    SIZE sizeTotal,
    const SIZE& sizePage = sizeDefault,
    const SIZE& sizeLine = sizeDefault);
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
O modo de mapeamento a ser definido para esta exibição. Os possíveis valores incluem:

|Modo de mapeamento|Unidade lógica|Eixo y positivo estende...|
|------------------|------------------|---------------------------------|
|MM_TEXT|1 pixel|Abaixo|
|MM_HIMETRIC|0, 1 mm|Para cima|
|MM_TWIPS|1/1440 em|Para cima|
|MM_HIENGLISH|0, 1 em|Para cima|
|MM_LOMETRIC|0,1 mm|Para cima|
|MM_LOENGLISH|0, 1 em|Para cima|

Todos esses modos são definidos pelo Windows. Dois modos de mapeamento padrão, MM_ISOTROPIC e MM_ANISOTROPIC, não são usados `CScrollView`para. A biblioteca de classes fornece `SetScaleToFitSize` a função de membro para dimensionar a exibição para o tamanho da janela. A coluna três na tabela acima descreve a orientação da coordenada.

*sizeTotal*<br/>
O tamanho total da exibição de rolagem. O `cx` membro contém a extensão horizontal. O `cy` membro contém a extensão vertical. Os tamanhos estão em unidades lógicas. `cx` E`cy` deve ser maior ou igual a 0.

*sizePage*<br/>
Os valores horizontais e verticais para rolar em cada direção em resposta a um clique do mouse em um eixo da barra de rolagem. O `cx` membro contém o valor horizontal. O `cy` membro contém o valor vertical.

*sizeLine*<br/>
Os valores horizontal e vertical para rolar em cada direção em resposta a um clique do mouse em uma seta de rolagem. O `cx` membro contém o valor horizontal. O `cy` membro contém o valor vertical.

### <a name="remarks"></a>Comentários

Chame-o em sua substituição da `OnUpdate` função membro para ajustar as características de rolagem quando, por exemplo, o documento é exibido inicialmente ou quando ele muda de tamanho.

Normalmente, você obterá informações de tamanho do documento associado da exibição chamando uma função de membro de documento, `GetMyDocSize`talvez chamada, que você fornece com a classe de documento derivada. O código a seguir mostra essa abordagem:

[!code-cpp[NVC_MFCDocView#166](../../mfc/codesnippet/cpp/cscrollview-class_3.cpp)]

Como alternativa, às vezes você pode precisar definir um tamanho fixo, como no código a seguir:

[!code-cpp[NVC_MFCDocView#167](../../mfc/codesnippet/cpp/cscrollview-class_4.cpp)]

Você deve definir o modo de mapeamento para qualquer um dos modos de mapeamento do Windows, exceto MM_ISOTROPIC ou MM_ANISOTROPIC. Se você quiser usar um modo de mapeamento irrestrito, chame a `SetScaleToFitSize` função de membro em vez de. `SetScrollSizes`

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#168](../../mfc/codesnippet/cpp/cscrollview-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#169](../../mfc/codesnippet/cpp/cscrollview-class_6.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de DIBLOOK do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)
