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
ms.openlocfilehash: d60082092bd42fbe220eee08953ad5fda0ff0a85
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64339595"
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
|[CScrollView::CheckScrollBars](#checkscrollbars)|Indica se a exibição de rolagem tem barras de rolagem horizontal e vertical.|
|[CScrollView::FillOutsideRect](#filloutsiderect)|Preenche a área de uma exibição fora da área de rolagem.|
|[CScrollView::GetDeviceScrollPosition](#getdevicescrollposition)|Obtém a atual posição de rolagem em unidades de dispositivo.|
|[CScrollView::GetDeviceScrollSizes](#getdevicescrollsizes)|Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e página do modo de exibição rolável. Tamanhos são em unidades de dispositivo.|
|[CScrollView::GetScrollPosition](#getscrollposition)|Obtém a atual posição de rolagem em unidades lógicas.|
|[CScrollView::GetTotalSize](#gettotalsize)|Obtém o tamanho total da exibição da rolagem em unidades lógicas.|
|[CScrollView::ResizeParentToFit](#resizeparenttofit)|Faz com que o tamanho da exibição a ser Determine o tamanho de seu quadro.|
|[CScrollView::ScrollToPosition](#scrolltoposition)|Rola a exibição para um determinado ponto, especificado em unidades lógicas.|
|[CScrollView::SetScaleToFitSize](#setscaletofitsize)|Coloca a exibição de rolagem no modo de escala para caber.|
|[CScrollView::SetScrollSizes](#setscrollsizes)|Define o modo de mapeamento do modo de exibição de rolagem, tamanho total e quantidades de rolagem horizontal e vertical.|

## <a name="remarks"></a>Comentários

Você pode manipular o padrão de rolagem por conta própria em qualquer classe derivada de `CView` , substituindo a mensagem mapeada [OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) funções de membro. Mas `CScrollView` adiciona os seguintes recursos para sua `CView` recursos:

- Ele gerencia os tamanhos de janela e o visor e modos de mapeamento.

- Rola automaticamente em resposta às mensagens da barra de rolagem.

- Rola automaticamente em resposta às mensagens do teclado, mouse não rolam ou a roda do IntelliMouse.

Para rolar automaticamente em resposta às mensagens do teclado, adicionar uma mensagem WM_KEYDOWN e de teste para VK_DOWN, VK_PREV e chame [SetScrollPos](/windows/desktop/api/winuser/nf-winuser-setscrollpos).

Você pode lidar com a roda do mouse para rolar por conta própria, substituindo a mensagem mapeada [OnMouseWheel](../../mfc/reference/cwnd-class.md#onmousewheel) e [OnRegisteredMouseWheel](../../mfc/reference/cwnd-class.md#onregisteredmousewheel) funções de membro. Como são para `CScrollView`, o comportamento recomendado para dar suporte a essas funções de membro [WM_MOUSEWHEEL](/windows/desktop/inputdev/wm-mousewheel), a mensagem de rotação da roda.

Para tirar proveito da rolagem automática, derive sua classe de exibição da `CScrollView` em vez do `CView`. Quando o modo de exibição é criado, se você deseja calcular o tamanho da exibição rolável com base no tamanho do documento, a chamada a `SetScrollSizes` função de membro de sua substituição de um [cview:: Oninitialupdate](../../mfc/reference/cview-class.md#oninitialupdate) ou [ CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate). (Você deve escrever seu próprio código para consultar o tamanho do documento. Por exemplo, consulte o [exemplo de Scribble](../../overview/visual-cpp-samples.md).)

A chamada para o `SetScrollSizes` função de membro define o modo de mapeamento do modo de exibição, as dimensões total da exibição da rolagem e os valores para rolar horizontalmente e verticalmente. Todos os tamanhos são em unidades lógicas. O tamanho lógico do modo de exibição normalmente é calculado dos dados armazenados no documento, mas em alguns casos, você talvez queira especificar um tamanho fixo. Para obter exemplos de ambas as abordagens, consulte [CScrollView::SetScrollSizes](#setscrollsizes).

Você especifique os valores de rolar horizontalmente e verticalmente em unidades lógicas. Por padrão, se o usuário clica em um eixo de barra de rolagem fora da caixa de rolagem, `CScrollView` rolar uma "página". Se o usuário clica em uma seta de rolagem em ambas as extremidades de uma barra de rolagem, `CScrollView` Rola uma "linha". Por padrão, uma página é 1/10 do tamanho total do modo de exibição; uma linha é 1/10 do tamanho da página. Substituir esses valores padrão passando tamanhos personalizados no `SetScrollSizes` função de membro. Por exemplo, você pode definir o tamanho horizontal para uma fração da largura do tamanho total e o tamanho vertical para a altura de uma linha na fonte atual.

Em vez de rolagem, `CScrollView` pode dimensionar automaticamente o modo de exibição para o tamanho da janela atual. Nesse modo, a exibição não tem nenhuma barra de rolagem e o modo de exibição lógico é ampliado ou reduzido para ajustar exatamente a área de cliente da janela. Para usar essa capacidade de dimensionar para caber, chame [CScrollView::SetScaleToFitSize](#setscaletofitsize). (Chame o `SetScaleToFitSize` ou `SetScrollSizes`, mas não ambos.)

Antes do `OnDraw` função de membro da sua classe derivada é chamada, `CScrollView` ajusta automaticamente a origem do visor para o `CPaintDC` objeto de contexto de dispositivo que ele passa para `OnDraw`.

Para ajustar a origem do visor para a janela de rolagem `CScrollView` substituições [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc). Esse ajuste é automática para o `CPaintDC` contexto de dispositivo que `CScrollView` passa para `OnDraw`, mas você deve chamar `CScrollView::OnPrepareDC` por conta própria para outros contextos de dispositivo você usa, como um `CClientDC`. Você pode substituir `CScrollView::OnPrepareDC` para definir a caneta, cor de plano de fundo e outros atributos de desenho, mas chamar a classe base para fazer o dimensionamento.

Barras de rolagem podem aparecer em três locais em relação a um modo de exibição, conforme mostrado nos seguintes casos:

- Barras de rolagem de estilo de janela padrão podem ser definidas para o modo de exibição usando o WS_HSCROLL e WS_VSCROLL[estilos Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles).

- Controles de barra de rolagem também podem ser adicionados para o quadro que contém a exibição, caso em que a estrutura encaminha mensagens WM_HSCROLL e WM_VSCROLL da janela do quadro para a exibição ativa no momento.

- A estrutura também encaminha role as mensagens de um `CSplitterWnd` controle de splitter para o painel ativo no momento do divisor (um modo de exibição). Quando colocada em uma [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md) com barras de rolagem compartilhado, um `CScrollView` objeto usará aqueles compartilhados em vez de criar o seu próprio.

Para obter mais informações sobre como usar `CScrollView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [derivado exibição Classes disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

`CScrollView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="checkscrollbars"></a>  CScrollView::CheckScrollBars

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

##  <a name="cscrollview"></a>  CScrollView::CScrollView

Constrói um objeto `CScrollView`.

```
CScrollView();
```

### <a name="remarks"></a>Comentários

Você deve chamar `SetScrollSizes` ou `SetScaleToFitSize` antes da rolagem de modo de exibição é utilizável.

##  <a name="filloutsiderect"></a>  CScrollView::FillOutsideRect

Chamar `FillOutsideRect` para preencher a área do modo de exibição que aparece fora da área de rolagem.

```
void FillOutsideRect(
    CDC* pDC,
    CBrush* pBrush);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto de dispositivo no qual o preenchimento deve ser feito.

*pBrush*<br/>
Pincel com a qual a área é a ser preenchido.

### <a name="remarks"></a>Comentários

Use `FillOutsideRect` no seu modo de exibição de rolagem `OnEraseBkgnd` função do manipulador para evitar o redesenho da tela de fundo excessiva.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#164](../../mfc/codesnippet/cpp/cscrollview-class_1.cpp)]

##  <a name="getdevicescrollposition"></a>  CScrollView::GetDeviceScrollPosition

Chamar `GetDeviceScrollPosition` quando precisar que as posições atuais de horizontais e verticais das caixas de rolagem nas barras de rolagem.

```
CPoint GetDeviceScrollPosition() const;
```

### <a name="return-value"></a>Valor de retorno

As posições horizontais e verticais (em unidades de dispositivo) das caixas de rolagem, como um `CPoint` objeto.

### <a name="remarks"></a>Comentários

Esse par de coordenadas corresponde ao local do documento ao qual o canto superior esquerdo do modo de exibição foi rolado. Isso é útil para a compensação de posições de dispositivo de mouse para posições de dispositivo de exibição de rolagem.

`GetDeviceScrollPosition` Retorna os valores em unidades de dispositivo. Se você quiser unidades lógicas, use `GetScrollPosition` em vez disso.

##  <a name="getdevicescrollsizes"></a>  CScrollView::GetDeviceScrollSizes

`GetDeviceScrollSizes` Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e página do modo de exibição rolável.

```
void GetDeviceScrollSizes(
    int& nMapMode,
    SIZE& sizeTotal,
    SIZE& sizePage,
    SIZE& sizeLine) const;
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
Retorna o modo de mapeamento atual para esta exibição. Para obter uma lista de valores possíveis, consulte `SetScrollSizes`.

*sizeTotal*<br/>
Retorna o tamanho total atual da exibição da rolagem em unidades de dispositivo.

*sizePage*<br/>
Retorna os valores atuais horizontais e verticais para rolar em cada direção em resposta a um mouse clique em um eixo de barra de rolagem. O `cx` membro contém a quantidade de horizontal. O `cy` membro contém a quantidade de vertical.

*sizeLine*<br/>
Retorna os valores atuais horizontais e verticais para rolar em cada direção em resposta a um mouse clique em uma seta de rolagem. O `cx` membro contém a quantidade de horizontal. O `cy` membro contém a quantidade de vertical.

### <a name="remarks"></a>Comentários

Tamanhos são em unidades de dispositivo. Essa função membro raramente é chamada.

##  <a name="getscrollposition"></a>  CScrollView::GetScrollPosition

Chamar `GetScrollPosition` quando precisar que as posições atuais de horizontais e verticais das caixas de rolagem nas barras de rolagem.

```
CPoint GetScrollPosition() const;
```

### <a name="return-value"></a>Valor de retorno

As posições horizontais e verticais (em unidades lógicas) das caixas de rolagem, como um `CPoint` objeto.

### <a name="remarks"></a>Comentários

Esse par de coordenadas corresponde ao local do documento ao qual o canto superior esquerdo do modo de exibição foi rolado.

`GetScrollPosition` Retorna os valores em unidades lógicas. Se você quiser que as unidades de dispositivo, use `GetDeviceScrollPosition` em vez disso.

##  <a name="gettotalsize"></a>  CScrollView::GetTotalSize

Chamar `GetTotalSize` para recuperar os tamanhos atuais de horizontais e verticais da exibição da rolagem.

```
CSize GetTotalSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho total da exibição da rolagem em unidades lógicas. O tamanho horizontal está no `cx` membro do `CSize` valor de retorno. O tamanho vertical está no `cy` membro.

##  <a name="resizeparenttofit"></a>  CScrollView::ResizeParentToFit

Chamar `ResizeParentToFit` para permitir que o tamanho do modo de exibição Determine o tamanho de sua janela de quadro.

```
void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShrinkOnly*<br/>
O tipo de redimensionamento para executar. O valor padrão, TRUE, reduz a janela do quadro, se apropriado. Barras de rolagem ainda aparecerá para exibições grandes ou janelas com moldura pequeno. Um valor FALSE faz com que a exibição sempre redimensionar a janela do quadro exatamente. Isso pode ser um pouco perigoso, pois a janela do quadro poderia fique muito grande para caber na janela de quadro MDI (interface MDI) da vários documento ou a tela.

### <a name="remarks"></a>Comentários

Isso é recomendado apenas para modos de exibição em janelas de quadro MDI filho. Use `ResizeParentToFit` no `OnInitialUpdate` função de manipulador de seus derivados `CScrollView` classe. Para obter um exemplo dessa função de membro, consulte [CScrollView::SetScrollSizes](#setscrollsizes).

`ResizeParentToFit` pressupõe-se de que o tamanho da janela do modo de exibição foi definido. Se o tamanho da janela de exibição não foi definido quando `ResizeParentToFit` é chamado, você obterá uma asserção. Para garantir que isso não aconteça, fazer a chamada a seguir antes de chamar `ResizeParentToFit`:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

##  <a name="scrolltoposition"></a>  CScrollView::ScrollToPosition

Chamar `ScrollToPosition` para rolar para um determinado ponto no modo de exibição.

```
void ScrollToPosition(POINT pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
O ponto de rolar para, em unidades lógicas. O `x` membro deve ser um valor positivo (maior que ou igual a 0, até o tamanho total do modo de exibição). O mesmo é verdadeiro para o `y` membro quando o modo de mapeamento é MM_TEXT. O `y` membro for negativo em modos de mapeamento diferentes MM_TEXT.

### <a name="remarks"></a>Comentários

O modo de exibição será ser rolado para que esse ponto está no canto superior esquerdo da janela. Essa função de membro não deve ser chamada se o modo de exibição é dimensionado para ajustar.

##  <a name="setscaletofitsize"></a>  CScrollView::SetScaleToFitSize

Chamar `SetScaleToFitSize` quando você deseja dimensionar o tamanho do visor para o tamanho da janela atual automaticamente.

```
void SetScaleToFitSize(SIZE sizeTotal);
```

### <a name="parameters"></a>Parâmetros

*sizeTotal*<br/>
Os tamanhos horizontais e verticais ao qual a exibição deve ser dimensionado. Tamanho da exibição de rolagem é medido em unidades lógicas. O tamanho horizontal está contido no `cx` membro. O tamanho vertical está contido no `cy` membro. Ambos `cx` e `cy` deve ser maior que ou igual a 0.

### <a name="remarks"></a>Comentários

Com as barras de rolagem, apenas uma parte do modo de exibição lógica pode estar visível a qualquer momento. Mas com a capacidade de dimensionar para caber o modo de exibição não tem nenhuma barra de rolagem e o modo de exibição lógico é ampliado ou reduzido para ajustar exatamente a área de cliente da janela. Quando a janela é redimensionada, o modo de exibição desenha seus dados em uma nova escala com base no tamanho da janela.

Normalmente, você colocará a chamada para `SetScaleToFitSize` em seu substituto do modo de exibição `OnInitialUpdate` função de membro. Se você não quiser que o dimensionamento automático, chame o `SetScrollSizes` função de membro em vez disso.

`SetScaleToFitSize` pode ser usado para implementar uma operação "Reduzir para caber". Use `SetScrollSizes` para reinicializar a rolagem.

`SetScaleToFitSize` pressupõe-se de que o tamanho da janela do modo de exibição foi definido. Se o tamanho da janela de exibição não foi definido quando `SetScaleToFitSize` é chamado, você obterá uma asserção. Para garantir que isso não aconteça, fazer a chamada a seguir antes de chamar `SetScaleToFitSize`:

[!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]

##  <a name="setscrollsizes"></a>  CScrollView::SetScrollSizes

Chamar `SetScrollSizes` quando a exibição está prestes a ser atualizado.

```
void SetScrollSizes(
    int nMapMode,
    SIZE sizeTotal,
    const SIZE& sizePage = sizeDefault,
    const SIZE& sizeLine = sizeDefault);
```

### <a name="parameters"></a>Parâmetros

*nMapMode*<br/>
O modo de mapeamento a ser definido para este modo de exibição. Os possíveis valores incluem:

|Modo de mapeamento|Unidade lógica|Estende positivos do eixo y...|
|------------------|------------------|---------------------------------|
|MM_TEXT|1 pixel|Para baixo|
|MM_HIMETRIC|0,01 mm|Para cima|
|MM_TWIPS|1/1440 em|Para cima|
|MM_HIENGLISH|0,001 pol|Para cima|
|MM_LOMETRIC|0,1 mm|Para cima|
|MM_LOENGLISH|0,01 pol|Para cima|

Todos os modos são definidos pelo Windows. Dois modos de mapeamento padrão, MM_ISOTROPIC e MM_ANISOTROPIC, não são usados para `CScrollView`. A biblioteca de classes fornece o `SetScaleToFitSize` a função de membro para dimensionar o modo de exibição para o tamanho da janela. A coluna três na tabela acima descreve a orientação de coordenadas.

*sizeTotal*<br/>
O tamanho total da exibição da rolagem. O `cx` membro contém a extensão horizontal. O `cy` membro contém a extensão vertical. Tamanhos são em unidades lógicas. Ambos `cx` e `cy` deve ser maior que ou igual a 0.

*sizePage*<br/>
As quantidades horizontais e verticais para rolar em cada direção em resposta a um mouse clique em um eixo de barra de rolagem. O `cx` membro contém a quantidade de horizontal. O `cy` membro contém a quantidade de vertical.

*sizeLine*<br/>
As quantidades horizontais e verticais para rolar em cada direção em resposta a um mouse clique em uma seta de rolagem. O `cx` membro contém a quantidade de horizontal. O `cy` membro contém a quantidade de vertical.

### <a name="remarks"></a>Comentários

Chamá-lo em seu substituto do `OnUpdate` a função de membro para ajustar as características de rolagem quando, por exemplo, o documento é exibido inicialmente ou quando ele altera o tamanho.

Você normalmente irá obter informações sobre o tamanho do documento de associados do modo de exibição, chamando uma função de membro de documento, talvez chamada `GetMyDocSize`, que você fornece a sua classe derivada de documento. O código a seguir mostra essa abordagem:

[!code-cpp[NVC_MFCDocView#166](../../mfc/codesnippet/cpp/cscrollview-class_3.cpp)]

Como alternativa, às vezes, talvez seja necessário definir um tamanho fixo, como no código a seguir:

[!code-cpp[NVC_MFCDocView#167](../../mfc/codesnippet/cpp/cscrollview-class_4.cpp)]

Você deve definir o modo de mapeamento para qualquer um dos modos de mapeamento do Windows, exceto MM_ISOTROPIC ou MM_ANISOTROPIC. Se você quiser usar um modo de mapeamento irrestrita, chame o `SetScaleToFitSize` função de membro em vez de `SetScrollSizes`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#168](../../mfc/codesnippet/cpp/cscrollview-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#169](../../mfc/codesnippet/cpp/cscrollview-class_6.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC DIBLOOK](../../overview/visual-cpp-samples.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)
