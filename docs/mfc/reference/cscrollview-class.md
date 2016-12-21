---
title: "Classe de CScrollView | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CScrollView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CScrollView"
  - "enrolando modos de exibição"
  - "modos de exibição, imprima"
ms.assetid: 4ba16dac-1acb-4be0-bb55-5fb695b6948d
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CScrollView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[CView](../Topic/CView%20Class.md) com recursos de rolagem.  
  
## Sintaxe  
  
```  
class CScrollView : public CView  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CScrollView::CScrollView](../Topic/CScrollView::CScrollView.md)|Constrói um objeto de `CScrollView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CScrollView::CheckScrollBars](../Topic/CScrollView::CheckScrollBars.md)|Indica se o modo de exibição de rolagem horizontal e tem barras de rolagem vertical.|  
|[CScrollView::FillOutsideRect](../Topic/CScrollView::FillOutsideRect.md)|Preenche a área de uma exibição fora da área de rolagem.|  
|[CScrollView::GetDeviceScrollPosition](../Topic/CScrollView::GetDeviceScrollPosition.md)|Obtém a atual posição de rolagem em unidades de dispositivo.|  
|[CScrollView::GetDeviceScrollSizes](../Topic/CScrollView::GetDeviceScrollSizes.md)|Obtém o modo atual de mapeamento, o tamanho total, e a linha e tamanhos de página de exibição de rolagem.  Tamanhos estão em unidades de dispositivo.|  
|[CScrollView::GetScrollPosition](../Topic/CScrollView::GetScrollPosition.md)|Obtém a atual posição de rolagem em unidades lógicas.|  
|[CScrollView::GetTotalSize](../Topic/CScrollView::GetTotalSize.md)|Obtém o tamanho total do modo de rolagem em unidades lógicas.|  
|[CScrollView::ResizeParentToFit](../Topic/CScrollView::ResizeParentToFit.md)|Faz com que o tamanho de exibição dite o tamanho do seu tile.|  
|[CScrollView::ScrollToPosition](../Topic/CScrollView::ScrollToPosition.md)|Rola o modo de exibição um determinado ponto, especificado em unidades lógicas.|  
|[CScrollView::SetScaleToFitSize](../Topic/CScrollView::SetScaleToFitSize.md)|Coloca o modo de rolagem no modo de escala\-à\- ajuste.|  
|[CScrollView::SetScrollSizes](../Topic/CScrollView::SetScrollSizes.md)|Defina o modo de mapeamento de exibição de rolagem, tamanho total, e a rolagem horizontal e vertical atinge.|  
  
## Comentários  
 Você pode manipular o padrão rolagem você mesmo em qualquer classe derivada de `CView` substituindo as funções de membro mensagem\- mapeadas de [OnHScroll](../Topic/CWnd::OnHScroll.md) e de [OnVScroll](../Topic/CWnd::OnVScroll.md) .  Mas `CScrollView` adicione os seguintes recursos aos recursos de `CView` :  
  
-   Gerencia tamanhos da janela e o viewport e modos de mapeamento.  
  
-   Rola automaticamente em resposta às mensagens de barra de rolagem.  
  
-   Rola automaticamente em resposta às mensagens do teclado, de um mouse que não são de rolagem, ou a roda de IntelliMouse.  
  
 Para rolar automaticamente em resposta às mensagens do teclado, adicione uma mensagem WM\_KEYDOWN, e testar para VK\_DOWN, VK\_PREV e chamada [SetScrollPos](http://msdn.microsoft.com/library/windows/desktop/bb787597).  
  
 Você pode manipular rolagem da roda do mouse você mesmo substituindo as funções de membro mensagem\- mapeadas de [OnMouseWheel](../Topic/CWnd::OnMouseWheel.md) e de [OnRegisteredMouseWheel](../Topic/CWnd::OnRegisteredMouseWheel.md) .  Como são para `CScrollView`, essas funções de membro oferecem suporte ao comportamento recomendado para [WM\_MOUSEWHEEL](http://msdn.microsoft.com/library/windows/desktop/ms645617), a mensagem de rotação de roda.  
  
 Para aproveitar de rolagem automático, derive sua classe de visualização de `CScrollView` em vez de `CView`.  Quando o modo é criada primeiramente, se você desejar calcular o tamanho de exibição de rolagem baseada no tamanho do documento, chame a função de membro de `SetScrollSizes` de sua sobrescrita de [CView::OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) ou de [CView::OnUpdate](../Topic/CView::OnUpdate.md).  \(Você deve escrever seu próprio código para ver o tamanho do documento.  Para um exemplo, consulte [O exemplo rabiscar](../../top/visual-cpp-samples.md).\)  
  
 A chamada para a função de membro de `SetScrollSizes` define o modo de mapeamento de exibição, as dimensões gerais do modo de rolagem, e as quantidades para rolar horizontalmente e verticalmente.  Todos os tamanhos estão em unidades lógicas.  O tamanho lógico de exibição é calculado em geral dos dados armazenados no documento, mas em alguns casos você pode querer especificar um tamanho fixo.  Para exemplos das duas abordagens, consulte [CScrollView::SetScrollSizes](../Topic/CScrollView::SetScrollSizes.md).  
  
 Você especifica as quantidades para rolar horizontalmente e verticalmente em unidades lógicas.  Por padrão, se o usuário clica em um eixo de barra de rolagem fora da caixa de rolagem, `CScrollView` colocar uma página “.” Se o usuário clica em uma seta de rolagem em qualquer uma das extremidades de uma barra de rolagem, `CScrollView` colocar uma linha “.” Por padrão, uma página é 1\/10 de tamanho total de exibição; uma linha é 1\/10 de tamanho de página.  Substituir esses valores padrão passando tamanhos personalizados na função de membro de `SetScrollSizes` .  Por exemplo, você pode definir o tamanho horizontal qualquer fração de altura tamanho total e de tamanho vertical para a altura de uma linha em uma fonte atual.  
  
 Em vez de rolagem, `CScrollView` pode dimensionar automaticamente modo ao tamanho da janela atual.  Em esse modo, a exibição não tem barra de rolagem lógica e a exibição é alongada ou reduzida para caber exatamente a área cliente da janela.  Para usar este recurso de escala\-à\- ajuste, chame [CScrollView::SetScaleToFitSize](../Topic/CScrollView::SetScaleToFitSize.md).  \(Chamar `SetScaleToFitSize` ou `SetScrollSizes`, mas não ambos.\)  
  
 Antes que a função de membro de `OnDraw` de sua classe derivada de exibição é chamada, `CScrollView` ajustar automaticamente a fonte do viewport para o objeto de dispositivo contexto de `CPaintDC` que passa a `OnDraw`.  
  
 Para ajustar a fonte do viewport para a janela de rolagem, `CScrollView` substitui [CView::OnPrepareDC](../Topic/CView::OnPrepareDC.md).  Este ajuste é automática para o contexto do dispositivo de `CPaintDC` que `CScrollView` passa a `OnDraw`, mas você deve chamar **CScrollView::OnPrepareDC** você mesmo para todos os outros contextos de dispositivo você usar, como `CClientDC`.  Você pode substituir **CScrollView::OnPrepareDC** para definir a caneta, a cor do plano de fundo, e outros atributos de desenho, mas chama a classe base para fazer ao dimensionamento.  
  
 As barras de rolagem podem aparecer em três local relativo a um modo de exibição, conforme mostrado nos seguintes casos:  
  
-   As barras de rolagem estilo padrão do windows podem ser definidas para a exibição usando **WS\_HSCROLL** e **WS\_VSCROLL**[Estilos do windows](../Topic/Window%20Styles.md).  
  
-   Controles de barra de rolagem também podem ser adicionados ao quadro que contém a exibição em esse caso, a estrutura `WM_HSCROLL` e encaminha mensagens de `WM_VSCROLL` da janela de quadro chave para o modo ativo no momento.  
  
-   A estrutura também encaminha mensagens de rolagem de um controle separator de `CSplitterWnd` ao formulário ativo separator \(uma exibição\).  Quando colocado em [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md) com barras de rolagem compartilhados, um objeto de `CScrollView` usará compartilhados em vez de criar seus próprios.  
  
 Para obter mais informações sobre como usar `CScrollView`, consulte [Arquitetura do documento\/exibição](../Topic/Document-View%20Architecture.md) e [Classes derivadas de exibição disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 `CScrollView`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos DIBLOOK](../../top/visual-cpp-samples.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Classe de CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)