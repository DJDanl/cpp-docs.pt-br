---
title: "Controles ActiveX MFC: pintando um controle ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX MFC, otimizando"
  - "Controles ActiveX MFC, pintura"
ms.assetid: 25fff9c0-4dab-4704-aaae-8dfb1065dee3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: pintando um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve o processo de pintura do controle ActiveX e como você pode alterar o código de pintura para otimizar o processo. \(Consulte [Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md) para técnicas sobre como otimizar o desenho não tendo controles de restauração individualmente objetos selecionados anteriormente de GDI.  Depois que todos os controles foram extraídos, o contêiner pode restaurar automaticamente os objetos originais.\)  
  
 Os exemplos neste artigo são de um controle criado pelo assistente de controle ActiveX de MFC com as configurações padrão.  Para obter mais informações sobre como criar um aplicativo de esqueleto de controle usando o assistente de controle ActiveX de MFC, consulte o artigo [Assistente de controle ActiveX de MFC](../mfc/reference/mfc-activex-control-wizard.md).  
  
 Os tópicos são cobertos:  
  
-   [O processo geral para pintar um controle e o código criados pelo assistente de controle ActiveX para dar suporte à pintura](#_core_the_painting_process_of_an_activex_control)  
  
-   [Como otimizar o processo de pintura](#_core_optimizing_your_paint_code)  
  
-   [Como pintar o controle usando metarquivos](#_core_painting_your_control_using_metafiles)  
  
##  <a name="_core_the_painting_process_of_an_activex_control"></a> O processo de pintura de um controle ActiveX  
 Quando os controles ActiveX são inicialmente exibidos ou redesenhados, seguem um processo de pintura semelhante a outros aplicativos desenvolvidos usando o MFC, com uma distinção importante: Os controles ActiveX podem estar em um estado ativo ou inativo.  
  
 Um controle ativo é representado em um contêiner do controle ActiveX por uma janela filho.  Como outras janelas, é responsável por pintar\-se quando uma mensagem de `WM_PAINT` é recebida.  A classe base de controle, [COleControl](../mfc/reference/colecontrol-class.md), trata esta mensagem na função de `OnPaint` .  Essa implementação padrão chama a função de `OnDraw` do controle.  
  
 Um controle inativa é pintado de maneira diferente.  Quando o controle é inativa, a janela é invisível ou inexistente, o que pode não receber uma mensagem de pintura.  Em vez disso, o contêiner do controle chama diretamente a função de `OnDraw` do controle.  Isso difere do processo de pintura ativa de um controle que a função de membro de `OnPaint` nunca será chamada.  
  
 Como discutido em parágrafos anteriores, como um controle ActiveX é atualizado depende do estado do controle.  No entanto, como a estrutura chama a função de membro de `OnDraw` em ambos os casos, você adiciona a maioria do código de pintura nesta função de membro.  
  
 Os identificadores da função de membro de `OnDraw` controlam paint.  Quando um controle estiver inativa, o contêiner do controle chama `OnDraw`, passando o contexto do dispositivo do contêiner do controle e as coordenadas da área retangular ocupada pelo controle.  
  
 O retângulo passado pela estrutura à função de membro de `OnDraw` contém a área ocupada pelo controle.  Se o controle está ativa, o canto superior esquerdo for \(0, 0\) e o contexto do dispositivo é passado para a janela filho que contém o controle.  Se o controle está inativo, a coordenada superior esquerdo não é necessariamente \(0, 0\) e o contexto do dispositivo é passado para o contêiner do controle que contém o controle.  
  
> [!NOTE]
>  É importante que suas alterações a `OnDraw` não dependem do ponto superior esquerdo do retângulo que é igual a \(0, 0\) e que você desenha somente dentro do retângulo passado a `OnDraw`.  Resultados inesperados podem ocorrer se você desenha além da área do retângulo.  
  
 A implementação padrão fornecida pelo assistente do controle ActiveX MFC no arquivo de implementação de controle \(.CPP\), mostrado abaixo, pinta o retângulo com uma escova branca e preenche a elipse à cor do plano de fundo atual.  
  
 [!code-cpp[NVC_MFC_AxUI#1](../mfc/codesnippet/CPP/mfc-activex-controls-painting-an-activex-control_1.cpp)]  
  
> [!NOTE]
>  Para pintar um controle, você não deve fazer suposições sobre o estado de contexto do dispositivo que é passado como parâmetro de *pdc* à função de `OnDraw` .  O contexto do dispositivo é fornecido pelo aplicativo ocasionalmente de contêiner e não será inicializado necessariamente ao estado padrão.  Selecione em particular, explicitamente as penalidades, escovas, cores, fontes, e outros recursos do que seu código de desenho depende.  
  
##  <a name="_core_optimizing_your_paint_code"></a> Otimizando o código de pintura  
 Depois que o controle está pintando com êxito, a próxima etapa é otimizar a função de `OnDraw` .  
  
 A implementação padrão do controle ActiveX que pt pinturas a área de controle inteira.  Isso é suficiente para controles simples, mas em muitos casos repintar o controle será mais rápido se apenas a parte que foi necessário atualizar pintada novamente, em vez do controle inteiro.  
  
 A função de `OnDraw` fornece um método fácil de otimização `rcInvalid`, passando a área retangular de controle que precisa redesenhar.  Use esta área, geralmente menor do que a área de controle inteira, para acelerar o processamento de pintura.  
  
##  <a name="_core_painting_your_control_using_metafiles"></a> Pintando o controle usando metarquivos  
 Na maioria dos casos o parâmetro de `pdc` a pontos da função de `OnDraw` a um contexto \(DC\) do dispositivo da tela.  Porém, quando as imagens de impressão de controle ou durante uma sessão de visualização de impressão, a DC. recebida de renderização são um tipo especial chamado de uma “DC. metarquivo”.  Ao contrário de uma DC. da tela, que manipule imediatamente as solicitações enviaram\-lhe, uma DC. de metarquivo armazenam solicitações ser executada novamente mais tarde.  Alguns aplicativos de contêineres também podem escolher para renderização da imagem de controle usando uma DC. de metarquivo no modo de design.  
  
 As solicitações de desenho de metarquivo podem ser feitas pelo contêiner com duas funções da interface: **IViewObject::Draw** \(essa função também pode ser chamada para o desenho do não metarquivo\) e **IDataObject::GetData**.  Quando uma DC. de metarquivo é transmitida como um dos parâmetros, a estrutura MFC faz uma chamada a [COleControl::OnDrawMetafile](../Topic/COleControl::OnDrawMetafile.md).  Como essa é uma função de membro virtual, substitua esta função na classe do controle para fazer qualquer processamento especial.  O comportamento padrão `COleControl::OnDraw`chama.  
  
 Para garantir que o controle pode ser desenhada na tela e contextos de dispositivo EMF do, você deve usar só as funções de membro que têm suporte em uma tela e uma DC. de metarquivo.  Lembre\-se de que o sistema de coordenadas não pode ser medido em pixels.  
  
 Como a implementação padrão de `OnDrawMetafile` chama a função de `OnDraw` de controle, use somente as funções de membro que são adequadas para um metarquivo e um contexto do dispositivo da tela, a menos que você substituir `OnDrawMetafile`.  O a seguir lista o subconjunto das funções de membro de `CDC` que podem ser usadas em um metarquivo e em um contexto do dispositivo da tela.  Para obter mais informações sobre essas funções, consulte a classe [CDC](../Topic/CDC%20Class.md)*na referência de MFC*.  
  
|Arco|BibBlt|Corda|  
|----------|------------|-----------|  
|**Elipse**|**Escape**|`ExcludeClipRect`|  
|`ExtTextOut`|`FloodFill`|`IntersectClipRect`|  
|`LineTo`|`MoveTo`|`OffsetClipRgn`|  
|`OffsetViewportOrg`|`OffsetWindowOrg`|`PatBlt`|  
|`Pie`|**Polígono**|`Polyline`|  
|`PolyPolygon`|`RealizePalette`|`RestoreDC`|  
|`RoundRect`|`SaveDC`|`ScaleViewportExt`|  
|`ScaleWindowExt`|`SelectClipRgn`|`SelectObject`|  
|`SelectPalette`|`SetBkColor`|`SetBkMode`|  
|`SetMapMode`|`SetMapperFlags`|`SetPixel`|  
|`SetPolyFillMode`|`SetROP2`|`SetStretchBltMode`|  
|`SetTextColor`|`SetTextJustification`|`SetViewportExt`|  
|`SetViewportOrg`|`SetWindowExt`|`SetWindowORg`|  
|`StretchBlt`|`TextOut`||  
  
 Além das funções de membro de `CDC` , existem várias outras funções que são compatíveis em uma DC. de metarquivo.  Esses incluem [CPalette::AnimatePalette](../Topic/CPalette::AnimatePalette.md), [CFont::CreateFontIndirect](../Topic/CFont::CreateFontIndirect.md), e as funções de três membros de `CBrush`: [CreateBrushIndirect](../Topic/CBrush::CreateBrushIndirect.md), [CreateDIBPatternBrush](../Topic/CBrush::CreateDIBPatternBrush.md), e [CreatePatternBrush](../Topic/CBrush::CreatePatternBrush.md).  
  
 As funções que não são registradas em um metarquivo são: [DrawFocusRect](../Topic/CDC::DrawFocusRect.md), [DrawIcon](../Topic/CDC::DrawIcon.md), [DrawText](../Topic/CDC::DrawText.md), [ExcludeUpdateRgn](../Topic/CDC::ExcludeUpdateRgn.md), [FillRect](../Topic/CDC::FillRect.md), [FrameRect](../Topic/CDC::FrameRect.md), [GrayString](../Topic/CDC::GrayString.md), [InvertRect](../Topic/CDC::InvertRect.md), [ScrollDC](../Topic/CDC::ScrollDC.md), e [TabbedTextOut](../Topic/CDC::TabbedTextOut.md).  Como uma DC. de metarquivo não é realmente associada a um dispositivo, você não pode usar SetDIBits, GetDIBits, e CreateDIBitmap com uma DC. de metarquivo.  Você pode usar SetDIBitsToDevice e StretchDIBits com uma DC. de metarquivo como o destino.  [CreateCompatibleDC](../Topic/CDC::CreateCompatibleDC.md), [CreateCompatibleBitmap](../Topic/CBitmap::CreateCompatibleBitmap.md), e [CreateDiscardableBitmap](../Topic/CBitmap::CreateDiscardableBitmap.md) não são significativos com uma DC. de metarquivo.  
  
 Outro ponto para ver quando usar uma DC. de metarquivo é que o sistema de coordenadas não pode ser medido em pixels.  Por esse motivo, todo o código de desenho deve ser ajustado para caber no retângulo passado a `OnDraw` no parâmetro de `rcBounds` .  Isso impede paint acidental fora do controle como `rcBounds` representa o tamanho da janela de controle.  
  
 Depois que você implementar a renderização de metarquivo para o controle, use o contêiner de teste para testar o metarquivo.  Consulte [Propriedades e eventos de teste com contêineres de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter mais informações sobre como acessar o contêiner de teste.  
  
#### Para testar o metarquivo de controle usando o contêiner de teste  
  
1.  No menu de **Editar** do contêiner de teste, clique em **Insert New Control**.  
  
2.  Na caixa de **Insert New Control** o controle, selecione e clique em **OK**.  
  
     O controle aparecerá no contêiner de teste.  
  
3.  No menu de **Controle** , clique em **Draw Metafile**.  
  
     Uma janela separada será exibida na qual o metarquivo é exibido.  Você pode alterar o tamanho dessa janela para ver como dimensionar afeta o metarquivo do controle.  Você pode fechar essa janela a qualquer momento.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)