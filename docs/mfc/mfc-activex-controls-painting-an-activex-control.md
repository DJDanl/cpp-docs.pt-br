---
title: 'Controles ActiveX MFC: pintando um controle ActiveX'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], painting
- MFC ActiveX controls [MFC], optimizing
ms.assetid: 25fff9c0-4dab-4704-aaae-8dfb1065dee3
ms.openlocfilehash: a01a66402471b295a6e57af8af265c50685b4a1f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618218"
---
# <a name="mfc-activex-controls-painting-an-activex-control"></a>Controles ActiveX MFC: pintando um controle ActiveX

Este artigo descreve o processo de pintura do controle ActiveX e como você pode alterar o código de pintura para otimizar o processo. (Veja [otimizando o desenho de controle](optimizing-control-drawing.md) para obter técnicas sobre como otimizar o desenho sem que os controles restaurem individualmente objetos GDI selecionados anteriormente. Depois que todos os controles tiverem sido desenhados, o contêiner poderá restaurar automaticamente os objetos originais.)

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Os exemplos neste artigo são de um controle criado pelo assistente de controle ActiveX do MFC com as configurações padrão. Para obter mais informações sobre como criar um aplicativo de controle de esqueleto usando o assistente de controle ActiveX do MFC, consulte o artigo [Assistente de controle ActiveX do MFC](reference/mfc-activex-control-wizard.md).

Os seguintes tópicos são abordados:

- [O processo geral para pintar um controle e o código criado pelo assistente de controle ActiveX para dar suporte à pintura](#_core_the_painting_process_of_an_activex_control)

- [Como otimizar o processo de pintura](#_core_optimizing_your_paint_code)

- [Como pintar seu controle usando os metaarquivos](#_core_painting_your_control_using_metafiles)

## <a name="the-painting-process-of-an-activex-control"></a><a name="_core_the_painting_process_of_an_activex_control"></a>O processo de pintura de um controle ActiveX

Quando os controles ActiveX são inicialmente exibidos ou redesenhados, eles seguem um processo de pintura semelhante a outros aplicativos desenvolvidos usando o MFC, com uma distinção importante: os controles ActiveX podem estar em um estado ativo ou inativo.

Um controle ativo é representado em um contêiner de controle ActiveX por uma janela filho. Assim como outras janelas, é responsável por pintar a si mesmo quando uma mensagem de WM_PAINT é recebida. A classe base do controle, [COleControl](reference/colecontrol-class.md), manipula essa mensagem em sua `OnPaint` função. Essa implementação padrão chama a `OnDraw` função do seu controle.

Um controle inativo é pintado de forma diferente. Quando o controle está inativo, sua janela fica invisível ou não existe, portanto, não pode receber uma mensagem de pintura. Em vez disso, o contêiner de controle chama diretamente a `OnDraw` função do controle. Isso é diferente do processo de pintura de um controle ativo, pois a `OnPaint` função de membro nunca é chamada.

Conforme discutido nos parágrafos anteriores, como um controle ActiveX é atualizado depende do estado do controle. No entanto, como a estrutura chama a `OnDraw` função de membro em ambos os casos, você adiciona a maioria do seu código de pintura nessa função de membro.

A `OnDraw` função membro manipula a pintura do controle. Quando um controle está inativo, o contêiner de controle chama `OnDraw` , passando o contexto do dispositivo do contêiner de controle e as coordenadas da área retangular ocupada pelo controle.

O retângulo passado pela estrutura para a `OnDraw` função membro contém a área ocupada pelo controle. Se o controle estiver ativo, o canto superior esquerdo será (0, 0) e o contexto do dispositivo passado será para a janela filho que contém o controle. Se o controle estiver inativo, a coordenada superior esquerda não será necessariamente (0, 0) e o contexto do dispositivo passado será para o contêiner de controle que contém o controle.

> [!NOTE]
> É importante que suas modificações `OnDraw` não dependam do ponto esquerdo superior do retângulo sendo igual a (0, 0) e que você desenha somente dentro do retângulo passado para `OnDraw` . Resultados inesperados podem ocorrer se você desenhar além da área do retângulo.

A implementação padrão fornecida pelo assistente de controle ActiveX do MFC no arquivo de implementação de controle (. CPP), mostrado abaixo, pinta o retângulo com um pincel branco e preenche a elipse com a cor de plano de fundo atual.

[!code-cpp[NVC_MFC_AxUI#1](codesnippet/cpp/mfc-activex-controls-painting-an-activex-control_1.cpp)]

> [!NOTE]
> Ao pintar um controle, você não deve fazer suposições sobre o estado do contexto do dispositivo que é passado como o parâmetro de *PDC* para a `OnDraw` função. Ocasionalmente, o contexto do dispositivo é fornecido pelo aplicativo de contêiner e não será necessariamente inicializado para o estado padrão. Especificamente, selecione explicitamente as canetas, pincéis, cores, fontes e outros recursos dos quais seu código de desenho depende.

## <a name="optimizing-your-paint-code"></a><a name="_core_optimizing_your_paint_code"></a>Otimizando seu código de pintura

Depois que o controle é pintado com êxito, a próxima etapa é otimizar a `OnDraw` função.

A implementação padrão da pintura do controle ActiveX pinta toda a área de controle. Isso é suficiente para controles simples, mas, em muitos casos, a repintura do controle seria mais rápida se apenas a parte que precisava da atualização fosse redesenhada, em vez de todo o controle.

A `OnDraw` função fornece um método fácil de otimização, passando *rcInvalid*, a área retangular do controle que precisa ser redesenhada. Use essa área, normalmente menor do que a área de controle inteira, para acelerar o processo de pintura.

## <a name="painting-your-control-using-metafiles"></a><a name="_core_painting_your_control_using_metafiles"></a>Pintando seu controle usando os metaarquivos

Na maioria dos casos, o parâmetro *PDC* para a `OnDraw` função aponta para um contexto de dispositivo de tela (DC). No entanto, ao imprimir imagens do controle ou durante uma sessão de visualização de impressão, o DC recebido para renderização é um tipo especial chamado de "metarquivo DC". Ao contrário de um controlador de domínio de tela, que lida imediatamente com solicitações enviadas a ele, um DC de metarquivo armazena solicitações para serem reproduzidas em um momento posterior. Alguns aplicativos de contêiner também podem optar por renderizar a imagem de controle usando um DC de metarquivo no modo de design.

As solicitações de desenho de metarquivo podem ser feitas pelo contêiner por meio de duas funções de interface: `IViewObject::Draw` (essa função também pode ser chamada para desenho sem metarquivo) e `IDataObject::GetData` . Quando um DC de metarquivo é passado como um dos parâmetros, a estrutura do MFC faz uma chamada para [COleControl:: OnDrawMetafile](reference/colecontrol-class.md#ondrawmetafile). Como essa é uma função membro virtual, substitua essa função na classe de controle para fazer qualquer processamento especial. O comportamento padrão chama `COleControl::OnDraw` .

Para certificar-se de que o controle pode ser desenhado em contextos de dispositivo de tela e de metarquivo, você deve usar somente funções de membro com suporte em um DC de tela e de metarquivo. Lembre-se de que o sistema de coordenadas pode não ser medido em pixels.

Como a implementação padrão de `OnDrawMetafile` chama a função do controle `OnDraw` , use somente funções de membro que são adequadas para um contexto de um metarquivo e um dispositivo de tela, a menos que você substitua `OnDrawMetafile` . O a seguir lista o subconjunto de `CDC` funções de membro que podem ser usadas em um metarquivo e em um contexto de dispositivo de tela. Para obter mais informações sobre essas funções, consulte classe [CDC](reference/cdc-class.md) na *referência do MFC*.

|Arc|BibBlt|Chord|
|---------|------------|-----------|
|`Ellipse`|`Escape`|`ExcludeClipRect`|
|`ExtTextOut`|`FloodFill`|`IntersectClipRect`|
|`LineTo`|`MoveTo`|`OffsetClipRgn`|
|`OffsetViewportOrg`|`OffsetWindowOrg`|`PatBlt`|
|`Pie`|`Polygon`|`Polyline`|
|`PolyPolygon`|`RealizePalette`|`RestoreDC`|
|`RoundRect`|`SaveDC`|`ScaleViewportExt`|
|`ScaleWindowExt`|`SelectClipRgn`|`SelectObject`|
|`SelectPalette`|`SetBkColor`|`SetBkMode`|
|`SetMapMode`|`SetMapperFlags`|`SetPixel`|
|`SetPolyFillMode`|`SetROP2`|`SetStretchBltMode`|
|`SetTextColor`|`SetTextJustification`|`SetViewportExt`|
|`SetViewportOrg`|`SetWindowExt`|`SetWindowORg`|
|`StretchBlt`|`TextOut`||

Além das `CDC` funções de membro, há várias outras funções que são compatíveis com um DC de metarquivo. Isso inclui [CPalette:: AnimatePalette](reference/cpalette-class.md#animatepalette), [CFont:: CreateFontIndirect](reference/cfont-class.md#createfontindirect)e três funções de membro de `CBrush` : [CreateBrushIndirect](reference/cbrush-class.md#createbrushindirect), [CreateDIBPatternBrush](reference/cbrush-class.md#createdibpatternbrush)e [CreatePatternBrush](reference/cbrush-class.md#createpatternbrush).

As funções que não são registradas em um metarquivo são: [DrawFocusRect](reference/cdc-class.md#drawfocusrect), [DrawIcon](reference/cdc-class.md#drawicon), [DrawText](reference/cdc-class.md#drawtext), [ExcludeUpdateRgn](reference/cdc-class.md#excludeupdatergn), [FillRect](reference/cdc-class.md#fillrect), [FrameRect](reference/cdc-class.md#framerect), [GrayString](reference/cdc-class.md#graystring), [InvertRect](reference/cdc-class.md#invertrect), [ScrollDC](reference/cdc-class.md#scrolldc)e [TabbedTextOut](reference/cdc-class.md#tabbedtextout). Como um DC de metarquivo não está realmente associado a um dispositivo, você não pode usar SetDIBits, GetDIBits e CreateDIBitmap com um DC de metarquivo. Você pode usar SetDIBitsToDevice e StretchDIBits com um DC de metarquivo como o destino. [CreateCompatibleDC](reference/cdc-class.md#createcompatibledc), [CreateCompatibleBitmap](reference/cbitmap-class.md#createcompatiblebitmap)e [CreateDiscardableBitmap](reference/cbitmap-class.md#creatediscardablebitmap) não são significativos com um DC de metarquivo.

Outro ponto a ser considerado ao usar um DC de metarquivo é que o sistema de coordenadas pode não ser medido em pixels. Por esse motivo, todo o seu código de desenho deve ser ajustado para caber no retângulo passado para `OnDraw` no parâmetro *rcBounds* . Isso impede a pintura acidental fora do controle porque *rcBounds* representa o tamanho da janela do controle.

Depois de implementar a renderização de metarquivo para o controle, use o contêiner de teste para testar o metarquivo. Consulte [testando Propriedades e eventos com o contêiner de teste](testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

#### <a name="to-test-the-controls-metafile-using-test-container"></a>Para testar o metarquivo do controle usando o contêiner de teste

1. No menu **Editar** do contêiner de teste, clique em **Inserir novo controle**.

1. Na caixa **Inserir novo controle** , selecione o controle e clique em **OK**.

   O controle aparecerá no contêiner de teste.

1. No menu **controle** , clique em **desenhar metarquivo**.

   Uma janela separada é exibida na qual o metarquivo é exibido. Você pode alterar o tamanho dessa janela para ver como o dimensionamento afeta o metarquivo do controle. Você pode fechar essa janela a qualquer momento.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
