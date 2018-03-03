---
title: 'Controles ActiveX MFC: Pintando um controle ActiveX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], painting
- MFC ActiveX controls [MFC], optimizing
ms.assetid: 25fff9c0-4dab-4704-aaae-8dfb1065dee3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a2a2dc7b0cebbfaa6f6fe7dbe7dc69e5d4f80121
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-painting-an-activex-control"></a>Controles ActiveX MFC: pintando um controle ActiveX
Este artigo descreve o processo de pintura do controle ActiveX e como você pode alterar o código para otimizar o processo. (Consulte [otimizando o desenho de controle](../mfc/optimizing-control-drawing.md) para técnicas sobre como otimizar o desenho não tem controles individualmente restaurem objetos GDI selecionados anteriormente. Depois que todos os controles foi emitidos, o contêiner pode restaurar automaticamente os objetos originais.)  
  
 Os exemplos neste artigo são de um controle criado pelo Assistente de controle ActiveX do MFC com as configurações padrão. Para obter mais informações sobre como criar um aplicativo de controle de esqueleto usando o Assistente de controle ActiveX MFC, consulte o artigo [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md).  
  
 Os tópicos a seguir são abordados:  
  
-   [O processo geral de um controle e o código criado pelo Assistente de controle ActiveX para oferecer suporte a pintura de pintura](#_core_the_painting_process_of_an_activex_control)  
  
-   [Como otimizar o processo de pintura](#_core_optimizing_your_paint_code)  
  
-   [Como desenhar seu controle usando metarquivos](#_core_painting_your_control_using_metafiles)  
  
##  <a name="_core_the_painting_process_of_an_activex_control"></a>O processo de pintura de um controle ActiveX  
 Quando controles ActiveX são inicialmente exibidos ou são redesenhados, elas seguirão um processo de pintura semelhante a outros aplicativos desenvolvidos usando MFC, com uma diferença importante: os controles ActiveX podem estar em um ativo ou em um estado inativo.  
  
 Um controle ativo é representado em um contêiner de controle ActiveX por uma janela filho. Como outras janelas, ele é responsável por pintura em si quando um `WM_PAINT` mensagem é recebida. A classe base do controle, [COleControl](../mfc/reference/colecontrol-class.md), manipula esta mensagem no seu `OnPaint` função. Esta implementação padrão chama o `OnDraw` função do seu controle.  
  
 Um controle inativo é pintado diferente. Quando o controle estiver inativo, sua janela é invisível ou que não existe, portanto ele não pode receber uma mensagem de pintura. Em vez disso, o contêiner de controle chama diretamente o `OnDraw` função do controle. Isso é diferente do processo de pintura do controle de um ativo em que o `OnPaint` nunca é chamada de função de membro.  
  
 Conforme descrito nos parágrafos anteriores, como um controle ActiveX é atualizado depende do estado do controle. No entanto, como o framework chama o `OnDraw` função de membro em ambos os casos, você adiciona a maior parte do seu código de pintura nessa função de membro.  
  
 O `OnDraw` função de membro controla a pintura de controle. Quando um controle está inativo, o contêiner de controle chama `OnDraw`, transmitindo o contexto de dispositivo do contêiner de controle e as coordenadas da área retangular de ocupado pelo controle.  
  
 O retângulo passado pelo framework para o `OnDraw` função membro contém a área ocupada pelo controle. Se o controle estiver ativo, o canto superior esquerdo é (0, 0) e o contexto de dispositivo passado para a janela filho que contém o controle. Se o controle estiver inativo, a coordenada superior esquerda não é necessariamente (0, 0) e o contexto de dispositivo passado para o contêiner de controle que contém o controle.  
  
> [!NOTE]
>  É importante que as modificações `OnDraw` não dependem de ponto esquerda superior do retângulo são iguais (0, 0) e desenhar somente dentro do retângulo passado para `OnDraw`. Se você desenhar além da área do retângulo, poderão ocorrer resultados inesperados.  
  
 A implementação padrão fornecida pelo Assistente de controle ActiveX do MFC no arquivo de implementação de controle (. CPP), mostrado abaixo, pinta o retângulo com um pincel em branco e preenche a elipse com a cor de plano de fundo atual.  
  
 [!code-cpp[NVC_MFC_AxUI#1](../mfc/codesnippet/cpp/mfc-activex-controls-painting-an-activex-control_1.cpp)]  
  
> [!NOTE]
>  Quando pintando um controle, você não deve fazer suposições sobre o estado do contexto do dispositivo que é passado como o *pdc* parâmetro para o `OnDraw` função. Ocasionalmente, o contexto de dispositivo é fornecido pelo aplicativo de contêiner e não serão necessariamente inicializado para o estado padrão. Em particular, selecione explicitamente canetas, pincéis, cores, fontes e outros recursos que depende de seu código de desenho.  
  
##  <a name="_core_optimizing_your_paint_code"></a>Otimizando o código de pintura  
 Depois que o controle é pintura em si com êxito, a próxima etapa é otimizar o `OnDraw` função.  
  
 A implementação padrão de controle ActiveX pintura pinta a área do controle inteiro. Isso é suficiente para controles simples, mas em muitos casos redesenho controle seria mais rápido se apenas a parte que é necessário atualizar foi pintada novamente, em vez de todo o controle.  
  
 O `OnDraw` função fornece um método fácil de otimização passando `rcInvalid`, a área retangular do controle precisa ser redesenhada. Use esta área, geralmente menor do que a área de controle inteiro, para acelerar o processo de pintura.  
  
##  <a name="_core_painting_your_control_using_metafiles"></a>Pintura seu controle usando metarquivos  
 Na maioria dos casos o `pdc` parâmetro para o `OnDraw` função aponta para um contexto de dispositivo de tela (DC). No entanto, ao imprimir imagens do controle ou durante uma sessão de visualização de impressão, o controlador de domínio recebida para a renderização é um tipo especial chamado "metarquivo DC". Ao contrário de uma tela de controlador de domínio, que trata as solicitações enviadas a ele imediatamente, um controlador de domínio de metarquivo armazena as solicitações a serem reproduzidas mais tarde. Alguns aplicativos de contêiner também podem optar por processar a imagem de controle usando um controlador de domínio no modo de design de metarquivo.  
  
 Metarquivo desenho solicitações pode ser feito pelo contêiner por meio de duas funções de interface: **IViewObject::Draw** (essa função também pode ser chamada para desenhar não-metarquivo) e **IDataObject::**. Quando um controlador de domínio é passado como um dos parâmetros de metarquivo, a estrutura MFC faz uma chamada para [COleControl::OnDrawMetafile](../mfc/reference/colecontrol-class.md#ondrawmetafile). Como esta é uma função membro virtual, substitua essa função na classe de controle para fazer qualquer processamento especial. As chamadas do comportamento padrão `COleControl::OnDraw`.  
  
 Para certificar-se de que o controle pode ser desenhado na tela e Metarquivo contextos de dispositivo, você deve usar apenas as funções de membro que têm suporte em uma tela e um controlador de domínio de metarquivo. Lembre-se de que o sistema de coordenadas não pode ser medido em pixels.  
  
 Porque a implementação padrão de `OnDrawMetafile` chama o controle `OnDraw` função, use somente as funções de membro que são adequadas para metarquivo e um contexto de dispositivo da tela, a menos que você substitua `OnDrawMetafile`. A seguir lista o subconjunto de `CDC` funções de membro que podem ser usadas em um meta-arquivo e um contexto de dispositivo da tela. Para obter mais informações sobre essas funções, consulte a classe [CDC](../mfc/reference/cdc-class.md) no *referência MFC*.  
  
|Arco|BibBlt|Corda|  
|---------|------------|-----------|  
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
  
 Além `CDC` funções de membro, há várias outras funções que são compatíveis em um controlador de domínio de metarquivo. Isso inclui [CPalette::AnimatePalette](../mfc/reference/cpalette-class.md#animatepalette), [CFont::CreateFontIndirect](../mfc/reference/cfont-class.md#createfontindirect)e três funções de membro de `CBrush`: [CreateBrushIndirect](../mfc/reference/cbrush-class.md#createbrushindirect), [CreateDIBPatternBrush](../mfc/reference/cbrush-class.md#createdibpatternbrush), e [CreatePatternBrush](../mfc/reference/cbrush-class.md#createpatternbrush).  
  
 Funções que não são registradas em um metarquivo são: [DrawFocusRect](../mfc/reference/cdc-class.md#drawfocusrect), [DrawIcon](../mfc/reference/cdc-class.md#drawicon), [DrawText](../mfc/reference/cdc-class.md#drawtext), [ExcludeUpdateRgn](../mfc/reference/cdc-class.md#excludeupdatergn), [FillRect](../mfc/reference/cdc-class.md#fillrect), [FrameRect](../mfc/reference/cdc-class.md#framerect), [GrayString](../mfc/reference/cdc-class.md#graystring), [InvertRect](../mfc/reference/cdc-class.md#invertrect), [ScrollDC](../mfc/reference/cdc-class.md#scrolldc)e [TabbedTextOut](../mfc/reference/cdc-class.md#tabbedtextout). Como um controlador de domínio de metarquivo não é realmente associado um dispositivo, você não pode usar SetDIBits, GetDIBits e CreateDIBitmap com um controlador de domínio de metarquivo. Você pode usar SetDIBitsToDevice e StretchDIBits com um controlador de domínio de metarquivo como o destino. [CreateCompatibleDC](../mfc/reference/cdc-class.md#createcompatibledc), [CreateCompatibleBitmap](../mfc/reference/cbitmap-class.md#createcompatiblebitmap), e [CreateDiscardableBitmap](../mfc/reference/cbitmap-class.md#creatediscardablebitmap) não são significativos com um controlador de domínio de metarquivo.  
  
 Outro ponto a considerar ao usar um controlador de domínio de metarquivo é que o sistema de coordenadas não pode ser medido em pixels. Por esse motivo, todo o código de desenho deve ser ajustado para se ajustar no retângulo passado para `OnDraw` no `rcBounds` parâmetro. Isso impede que a pintura acidental fora do controle porque `rcBounds` representa o tamanho da janela do controle.  
  
 Depois que você implementou metarquivo renderização para o controle, use o contêiner de teste para testar o metarquivo. Consulte [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
#### <a name="to-test-the-controls-metafile-using-test-container"></a>Para testar o metarquivo do controle usando o contêiner de teste  
  
1.  O contêiner de teste **editar** menu, clique em **Inserir novo controle**.  
  
2.  No **Inserir novo controle** , selecione o controle e clique em **Okey**.  
  
     O controle será exibido no contêiner de teste.  
  
3.  Sobre o **controle** menu, clique em **desenhar metarquivo**.  
  
     Uma janela separada é exibida na qual o metarquivo é exibido. Você pode alterar o tamanho da janela para ver como a escala afeta metarquivo do controle. Você pode fechar esta janela a qualquer momento.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

