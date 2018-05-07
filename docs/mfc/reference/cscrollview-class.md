---
title: Classe CScrollView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 82ffdb26c5766a0ff7cbada511c9bc9c82ebfd93
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CScrollView::CheckScrollBars](#checkscrollbars)|Indica se o modo de exibição de rolagem tem barras de rolagem horizontal e vertical.|  
|[CScrollView::FillOutsideRect](#filloutsiderect)|Preenche a área de visualização para fora da área de rolagem.|  
|[CScrollView::GetDeviceScrollPosition](#getdevicescrollposition)|Obtém a posição de rolagem atual em unidades de dispositivo.|  
|[CScrollView::GetDeviceScrollSizes](#getdevicescrollsizes)|Obtém o modo de mapeamento atual, o tamanho total e os tamanhos de linha e página do modo de exibição rolável. Tamanhos são em unidades de dispositivo.|  
|[CScrollView::GetScrollPosition](#getscrollposition)|Obtém a posição de rolagem atual em unidades lógicas.|  
|[CScrollView::GetTotalSize](#gettotalsize)|Obtém o tamanho total da exibição da rolagem em unidades lógicas.|  
|[CScrollView::ResizeParentToFit](#resizeparenttofit)|Faz com que o tamanho da exibição a ser determinam o tamanho do quadro.|  
|[CScrollView::ScrollToPosition](#scrolltoposition)|Rola o modo de exibição para um determinado ponto especificado em unidades lógicas.|  
|[CScrollView::SetScaleToFitSize](#setscaletofitsize)|Coloca o modo de exibição de rolagem no modo de escala para caber.|  
|[CScrollView::SetScrollSizes](#setscrollsizes)|Define o modo de mapeamento, tamanho total e quantidades de rolagem horizontal e vertical da exibição da rolagem.|  
  
## <a name="remarks"></a>Comentários  
 Você pode manipular padrão rolagem por conta própria em qualquer classe derivada de `CView` , substituindo a mensagem mapeada [OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) funções de membro. Mas `CScrollView` adiciona os seguintes recursos para sua `CView` recursos:  
  
-   Ele gerencia os tamanhos de janela e visor e modos de mapeamento.  
  
-   Rola automaticamente em resposta a mensagens da barra de rolagem.  
  
-   Rola automaticamente em resposta a mensagens de teclado, mouse não rolagem ou a roda do IntelliMouse.  
  
 Para rolar automaticamente em resposta a mensagens do teclado, adicionar uma mensagem WM_KEYDOWN e de teste para VK_DOWN, VK_PREV e chamada [SetScrollPos](http://msdn.microsoft.com/library/windows/desktop/bb787597).  
  
 Você pode manipular a roda do mouse para rolar por conta própria, substituindo a mensagem mapeada [OnMouseWheel](../../mfc/reference/cwnd-class.md#onmousewheel) e [OnRegisteredMouseWheel](../../mfc/reference/cwnd-class.md#onregisteredmousewheel) funções de membro. Como eles são para `CScrollView`, o comportamento recomendado para dar suporte a essas funções de membro [WM_MOUSEWHEEL](http://msdn.microsoft.com/library/windows/desktop/ms645617), a mensagem de rotação da roda.  
  
 Para tirar proveito de rolagem automática, derive sua classe de exibição da `CScrollView` em vez de `CView`. Quando o modo de exibição é criado, se você deseja calcular o tamanho da exibição rolável com base no tamanho do documento, chamada de `SetScrollSizes` a função de membro de sua substituição do [CView::OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) ou [ CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate). (Você deve escrever seu próprio código para consultar o tamanho do documento. Para obter um exemplo, consulte o [Rabisco exemplo](../../visual-cpp-samples.md).)  
  
 A chamada para o `SetScrollSizes` função membro define o modo de mapeamento do modo de exibição, as dimensões total da exibição da rolagem e os valores para rolar horizontalmente e verticalmente. Todos os tamanhos estão em unidades lógicas. O tamanho lógico do modo de exibição normalmente é calculado dos dados armazenados no documento, mas em alguns casos, você talvez queira especificar um tamanho fixo. Para obter exemplos de ambas as abordagens, consulte [CScrollView::SetScrollSizes](#setscrollsizes).  
  
 Você especificar valores para rolar horizontalmente e verticalmente em unidades lógicas. Por padrão, se o usuário clica em um eixo de barra de rolagem fora da caixa de rolagem, `CScrollView` rolar uma "página". Se o usuário clica em uma seta de rolagem em ambas as extremidades de uma barra de rolagem, `CScrollView` rola "linha". Por padrão, uma página é 1/10 do tamanho total do modo de exibição; uma linha é 1/10 do tamanho da página. Substituir esses valores padrão, passando tamanhos personalizados no `SetScrollSizes` função de membro. Por exemplo, você pode definir o tamanho horizontal para alguma fração da largura do tamanho total e o tamanho vertical para a altura de uma linha na fonte atual.  
  
 Em vez de rolagem, `CScrollView` possível dimensionar automaticamente a exibição para o tamanho da janela atual. Nesse modo, o modo de exibição tem sem barras de rolagem e o modo de exibição lógico é ampliado ou reduzido se ajuste exatamente a área cliente da janela. Para usar esse recurso escala para ajustar, chame [CScrollView::SetScaleToFitSize](#setscaletofitsize). (Chame `SetScaleToFitSize` ou `SetScrollSizes`, mas não ambos.)  
  
 Antes do `OnDraw` a função de membro da sua classe derivada de exibição é chamada, `CScrollView` ajusta automaticamente a origem do visor para o `CPaintDC` objeto de contexto de dispositivo que ele passa para `OnDraw`.  
  
 Para ajustar a origem do visor para a janela de rolagem, `CScrollView` substitui [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc). Esse ajuste é automática para o `CPaintDC` contexto de dispositivo que `CScrollView` passa para `OnDraw`, mas você deve chamar **CScrollView::OnPrepareDC** por conta própria para outros contextos de dispositivo usar, como um `CClientDC`. Você pode substituir **CScrollView::OnPrepareDC** para definir a caneta, cor de plano de fundo e outros atributos de desenho, mas chame a classe base para fazer o dimensionamento.  
  
 Barras de rolagem podem ser exibido em três locais em relação a um modo de exibição, conforme mostrado nos seguintes casos:  
  
-   Barras de rolagem de estilo de janela padrão podem ser definidas para o modo de exibição usando o **WS_HSCROLL** e **WS_VSCROLL**[estilos Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
-   Controles de barra de rolagem também podem ser adicionados ao quadro que contém o modo de exibição, nesse caso o framework encaminha `WM_HSCROLL` e `WM_VSCROLL` mensagens de janela do quadro para a exibição ativa no momento.  
  
-   A estrutura também encaminha Role mensagens de um `CSplitterWnd` controle de separador para o painel do divisor ativo no momento (um modo de exibição). Quando colocada em um [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md) com barras de rolagem compartilhado, um `CScrollView` objeto usará os compartilhados em vez de criar o seu próprio.  
  
 Para obter mais informações sobre como usar `CScrollView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [derivado exibição Classes disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 `CScrollView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="checkscrollbars"></a>  CScrollView::CheckScrollBars  
 Chame essa função de membro para determinar se o modo de exibição de rolagem tem barras horizontais e verticais.  
  
```  
void CheckScrollBars(
    BOOL& bHasHorzBar,  
    BOOL& bHasVertBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *bHasHorzBar*  
 Indica que o aplicativo tem uma barra de rolagem horizontal.  
  
 *bHasVertBar*  
 Indica que o aplicativo tem uma barra de rolagem vertical.  
  
##  <a name="cscrollview"></a>  CScrollView::CScrollView  
 Constrói um objeto `CScrollView`.  
  
```  
CScrollView();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar `SetScrollSizes` ou `SetScaleToFitSize` antes da rolagem exibição é utilizável.  
  
##  <a name="filloutsiderect"></a>  CScrollView::FillOutsideRect  
 Chamar `FillOutsideRect` para preencher a área de exibição que aparece fora da área de rolagem.  
  
```  
void FillOutsideRect(
    CDC* pDC,  
    CBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Contexto de dispositivo no qual o preenchimento é deve ser feito.  
  
 `pBrush`  
 Pincel com a qual a área é a ser preenchida.  
  
### <a name="remarks"></a>Comentários  
 Use `FillOutsideRect` em seu modo de exibição de rolagem `OnEraseBkgnd` função de manipulador para evitar redesenho excessiva.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#164](../../mfc/codesnippet/cpp/cscrollview-class_1.cpp)]  
  
##  <a name="getdevicescrollposition"></a>  CScrollView::GetDeviceScrollPosition  
 Chamar `GetDeviceScrollPosition` quando você precisar de posições atuais de horizontais e verticais das caixas de rolagem nas barras de rolagem.  
  
```  
CPoint GetDeviceScrollPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As posições horizontais e verticais (em unidades de dispositivo) das caixas de rolagem como um `CPoint` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse par de coordenadas corresponde ao local do documento para que tenha sido rolado o canto superior esquerdo da exibição. Isso é útil para a compensação de posições de dispositivo de mouse para as posições de dispositivo de exibição da rolagem.  
  
 `GetDeviceScrollPosition` Retorna valores em unidades de dispositivo. Se você quiser que as unidades lógicas, use `GetScrollPosition` em vez disso.  
  
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
 `nMapMode`  
 Retorna o modo de mapeamento atual para este modo de exibição. Para obter uma lista de valores possíveis, consulte `SetScrollSizes`.  
  
 `sizeTotal`  
 Retorna o tamanho total atual da exibição da rolagem em unidades de dispositivo.  
  
 `sizePage`  
 Retorna os valores atuais horizontais e verticais para rolar em cada direção em resposta a um mouse clique em um eixo de barra de rolagem. O **cx** membro contém a quantidade horizontal. O **cy** membro contém a quantidade de vertical.  
  
 `sizeLine`  
 Retorna os valores atuais horizontais e verticais para rolar em cada direção em resposta a um mouse clique em uma seta de rolagem. O **cx** membro contém a quantidade horizontal. O **cy** membro contém a quantidade de vertical.  
  
### <a name="remarks"></a>Comentários  
 Tamanhos são em unidades de dispositivo. Essa função de membro raramente é chamada.  
  
##  <a name="getscrollposition"></a>  CScrollView::GetScrollPosition  
 Chamar `GetScrollPosition` quando você precisar de posições atuais de horizontais e verticais das caixas de rolagem nas barras de rolagem.  
  
```  
CPoint GetScrollPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As posições horizontais e verticais (em unidades lógicas) das caixas de rolagem como um `CPoint` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse par de coordenadas corresponde ao local do documento para que tenha sido rolado o canto superior esquerdo da exibição.  
  
 `GetScrollPosition` Retorna valores em unidades lógicas. Se você quiser que as unidades de dispositivo, use `GetDeviceScrollPosition` em vez disso.  
  
##  <a name="gettotalsize"></a>  CScrollView::GetTotalSize  
 Chamar `GetTotalSize` para recuperar os tamanhos atuais horizontais e verticais da exibição da rolagem.  
  
```  
CSize GetTotalSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho total da exibição da rolagem em unidades lógicas. O tamanho horizontal está no **cx** membro o `CSize` valor de retorno. O tamanho vertical está no **cy** membro.  
  
##  <a name="resizeparenttofit"></a>  CScrollView::ResizeParentToFit  
 Chamar `ResizeParentToFit` para permitir que o tamanho do modo de exibição determinam o tamanho da sua janela do quadro.  
  
```  
void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bShrinkOnly*  
 O tipo de redimensionamento para executar. O valor padrão, **TRUE**, reduz a janela do quadro se apropriado. Barras de rolagem ainda aparecerá para exibições grandes ou janelas com moldura pequeno. Um valor de **FALSE** faz com que o modo de exibição sempre redimensionar a janela do quadro exatamente. Isso pode ser um pouco perigoso, desde que a janela do quadro pode obter muito grande para caber na janela de quadro vários documentos MDI (interface) ou a tela.  
  
### <a name="remarks"></a>Comentários  
 Isso é recomendado apenas para modos de exibição em janelas de quadro filho MDI. Use `ResizeParentToFit` no `OnInitialUpdate` função do manipulador de derivada `CScrollView` classe. Para obter um exemplo dessa função de membro, consulte [CScrollView::SetScrollSizes](#setscrollsizes).  
  
 `ResizeParentToFit` pressupõe-se de que o tamanho da janela de exibição foi definido. Se o tamanho da janela de exibição não foi definido quando `ResizeParentToFit` é chamado, você obterá uma declaração. Para garantir que isso não aconteça, fazer a chamada a seguir antes de chamar `ResizeParentToFit`:  
  
 [!code-cpp[NVC_MFCDocView#165](../../mfc/codesnippet/cpp/cscrollview-class_2.cpp)]  
  
##  <a name="scrolltoposition"></a>  CScrollView::ScrollToPosition  
 Chamar `ScrollToPosition` rolar para um determinado ponto no modo de exibição.  
  
```  
void ScrollToPosition(POINT pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 O ponto de rolar, em unidades lógicas. O **x** membro deve ser um valor positivo (maior ou igual a 0, até o tamanho total do modo de exibição). O mesmo é verdadeiro para o **y** membro quando o modo de mapeamento é `MM_TEXT`. O **y** membro é negativo no mapeamento de modos diferentes de `MM_TEXT`.  
  
### <a name="remarks"></a>Comentários  
 O modo de exibição será ser rolado para que esse ponto está no canto superior esquerdo da janela. Essa função de membro não deve ser chamada se o modo de exibição é dimensionado para ajustar.  
  
##  <a name="setscaletofitsize"></a>  CScrollView::SetScaleToFitSize  
 Chamar `SetScaleToFitSize` quando você deseja dimensionar o tamanho do visor para o tamanho da janela atual automaticamente.  
  
```  
void SetScaleToFitSize(SIZE sizeTotal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sizeTotal`  
 Os tamanhos horizontais e verticais para que a exibição é dimensionado. Tamanho da exibição da rolagem é medido em unidades lógicas. O tamanho horizontal está contido no **cx** membro. O tamanho vertical está contido no **cy** membro. Ambos **cx** e **cy** deve ser maior que ou igual a 0.  
  
### <a name="remarks"></a>Comentários  
 Barras de rolagem, apenas uma parte do modo de exibição lógica pode estar visível a qualquer momento. Mas com a capacidade de dimensionar para ajustar a exibição tem sem barras de rolagem e o modo de exibição lógico é ampliado ou reduzido se ajuste exatamente a área cliente da janela. Quando a janela é redimensionada, o modo de exibição desenha seus dados em uma escala de novo com base no tamanho da janela.  
  
 Normalmente você vai fazer a chamada para `SetScaleToFitSize` em sua substituição do modo de exibição `OnInitialUpdate` função de membro. Se você não quiser que o dimensionamento automático, chame o `SetScrollSizes` função de membro em vez disso.  
  
 `SetScaleToFitSize` pode ser usado para implementar uma operação "Zoom para ajustar". Use `SetScrollSizes` para reinicializar a rolagem.  
  
 `SetScaleToFitSize` pressupõe-se de que o tamanho da janela de exibição foi definido. Se o tamanho da janela de exibição não foi definido quando `SetScaleToFitSize` é chamado, você obterá uma declaração. Para garantir que isso não aconteça, fazer a chamada a seguir antes de chamar `SetScaleToFitSize`:  
  
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
 `nMapMode`  
 O modo de mapeamento a ser definido para este modo de exibição. Os possíveis valores incluem:  
  
|Modo de mapeamento|Unidade lógica|Estende positivos do eixo y...|  
|------------------|------------------|---------------------------------|  
|`MM_TEXT`|1 pixel|Para baixo|  
|`MM_HIMETRIC`|mm 0,01|Para cima|  
|`MM_TWIPS`|1/1440 em|Para cima|  
|`MM_HIENGLISH`|em 0,001|Para cima|  
|`MM_LOMETRIC`|0,1 mm|Para cima|  
|`MM_LOENGLISH`|in 0,01|Para cima|  
  
 Todos os modos são definidos pelo Windows. Dois modos de mapeamento padrão, `MM_ISOTROPIC` e `MM_ANISOTROPIC`, não são usados para `CScrollView`. A biblioteca de classe fornece a `SetScaleToFitSize` a função de membro para expandir a exibição para o tamanho da janela. A coluna três na tabela acima descreve a orientação de coordenadas.  
  
 `sizeTotal`  
 O tamanho total da exibição da rolagem. O **cx** membro contém a extensão horizontal. O **cy** membro contém a extensão vertical. Tamanhos estão em unidades lógicas. Ambos **cx** e **cy** deve ser maior que ou igual a 0.  
  
 `sizePage`  
 Os valores horizontais e verticais para rolar em cada direção em resposta a um mouse clique em um eixo de barra de rolagem. O **cx** membro contém a quantidade horizontal. O **cy** membro contém a quantidade de vertical.  
  
 `sizeLine`  
 Os valores horizontais e verticais para rolar em cada direção em resposta a um mouse clique em uma seta de rolagem. O **cx** membro contém a quantidade horizontal. O **cy** membro contém a quantidade de vertical.  
  
### <a name="remarks"></a>Comentários  
 Chamá-la em sua substituição do `OnUpdate` a função de membro para ajustar as características de rolagem quando, por exemplo, o documento é exibido inicialmente ou quando ele altera o tamanho.  
  
 Você geralmente obterá informações sobre o tamanho do documento associado do modo de exibição chamando uma função de membro de documento, talvez chamado `GetMyDocSize`, que você fornece à sua classe derivada de documento. O código a seguir mostra essa abordagem:  
  
 [!code-cpp[NVC_MFCDocView#166](../../mfc/codesnippet/cpp/cscrollview-class_3.cpp)]  
  
 Como alternativa, às vezes, talvez seja necessário definir um tamanho fixo, como no código a seguir:  
  
 [!code-cpp[NVC_MFCDocView#167](../../mfc/codesnippet/cpp/cscrollview-class_4.cpp)]  
  
 Você deve definir o modo de mapeamento para qualquer um dos modos de mapeamento de Windows, exceto `MM_ISOTROPIC` ou `MM_ANISOTROPIC`. Se você quiser usar um modo de mapeamento irrestrita, chame o `SetScaleToFitSize` a função de membro em vez de `SetScrollSizes`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#168](../../mfc/codesnippet/cpp/cscrollview-class_5.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#169](../../mfc/codesnippet/cpp/cscrollview-class_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)
