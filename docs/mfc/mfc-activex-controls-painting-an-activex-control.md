---
title: 'Controles ActiveX MFC: pintando um controle ActiveX'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], painting
- MFC ActiveX controls [MFC], optimizing
ms.assetid: 25fff9c0-4dab-4704-aaae-8dfb1065dee3
ms.openlocfilehash: fd98af90e86b6b98a856e633e50c5bf266cc466a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364581"
---
# <a name="mfc-activex-controls-painting-an-activex-control"></a>Controles ActiveX MFC: pintando um controle ActiveX

Este artigo descreve o processo de pintura de controle ActiveX e como você pode alterar o código de pintura para otimizar o processo. (Consulte [Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md) para obter técnicas sobre como otimizar o desenho, não tendo controles de restauração individualmente de objetos GDI selecionados anteriormente. Depois de todos os controles terem sido desenhados, o recipiente pode restaurar automaticamente os objetos originais.)

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Exemplos neste artigo são de um controle criado pelo MFC ActiveX Control Wizard com configurações padrão. Para obter mais informações sobre a criação de um aplicativo de controle de esqueleto usando o MFC ActiveX Control Wizard, consulte o artigo [MFC ActiveX Control Wizard](../mfc/reference/mfc-activex-control-wizard.md).

Veja os tópicos que serão abordados:

- [O processo geral para pintar um controle e o código criado pelo ActiveX Control Wizard para suportar a pintura](#_core_the_painting_process_of_an_activex_control)

- [Como otimizar o processo de pintura](#_core_optimizing_your_paint_code)

- [Como pintar seu controle usando metaarquivos](#_core_painting_your_control_using_metafiles)

## <a name="the-painting-process-of-an-activex-control"></a><a name="_core_the_painting_process_of_an_activex_control"></a>O processo de pintura de um controle ActiveX

Quando os controles ActiveX são exibidos inicialmente ou redesenhados, eles seguem um processo de pintura semelhante a outros aplicativos desenvolvidos usando MFC, com uma distinção importante: os controles ActiveX podem estar em um estado ativo ou inativo.

Um controle ativo é representado em um recipiente de controle ActiveX por uma janela de criança. Como outras janelas, é responsável por se pintar quando uma mensagem WM_PAINT é recebida. A classe base do controle, [COleControl,](../mfc/reference/colecontrol-class.md)lida `OnPaint` com esta mensagem em sua função. Esta implementação `OnDraw` padrão chama a função do seu controle.

Um controle inativo é pintado de forma diferente. Quando o controle está inativo, sua janela é invisível ou inexistente, por isso não pode receber uma mensagem de pintura. Em vez disso, o `OnDraw` recipiente de controle chama diretamente a função do controle. Isso difere do processo de pintura de `OnPaint` um controle ativo, na forma de a função do membro nunca ser chamada.

Como discutido nos parágrafos anteriores, a forma como um controle ActiveX é atualizado depende do estado do controle. No entanto, como `OnDraw` o framework chama a função de membro em ambos os casos, você adiciona a maioria do seu código de pintura nesta função de membro.

A `OnDraw` função do membro lida com a pintura de controle. Quando um controle está inativo, `OnDraw`o recipiente de controle chama , passando o contexto do dispositivo do recipiente de controle e as coordenadas da área retangular ocupada pelo controle.

O retângulo passado pelo `OnDraw` quadro para a função de membro contém a área ocupada pelo controle. Se o controle estiver ativo, o canto superior esquerdo é (0, 0) e o contexto do dispositivo passado é para a janela filho que contém o controle. Se o controle estiver inativo, a coordenada superior esquerda não é necessariamente (0, 0) e o contexto do dispositivo passado é para o recipiente de controle que contém o controle.

> [!NOTE]
> É importante que suas `OnDraw` modificações não dependam do ponto esquerdo superior do retângulo ser igual a (0, 0) e que você desenhe apenas dentro do retângulo passado para `OnDraw`. Resultados inesperados podem ocorrer se você desenhar além da área do retângulo.

A implementação padrão fornecida pelo MFC ActiveX Control Wizard no arquivo de implementação de controle (. CPP), mostrado abaixo, pinta o retângulo com um pincel branco e preenche a elipse com a cor de fundo atual.

[!code-cpp[NVC_MFC_AxUI#1](../mfc/codesnippet/cpp/mfc-activex-controls-painting-an-activex-control_1.cpp)]

> [!NOTE]
> Ao pintar um controle, você não deve fazer suposições sobre o estado do `OnDraw` contexto do dispositivo que é passado como o parâmetro *pdc* para a função. Ocasionalmente, o contexto do dispositivo é fornecido pela aplicação do contêiner e não será necessariamente inicializado para o estado padrão. Em particular, selecione explicitamente as canetas, pincéis, cores, fontes e outros recursos dos quais seu código de desenho depende.

## <a name="optimizing-your-paint-code"></a><a name="_core_optimizing_your_paint_code"></a>Otimizando seu código de pintura

Depois que o controle estiver se pintando `OnDraw` com sucesso, o próximo passo é otimizar a função.

A implementação padrão da pintura de controle ActiveX pinta toda a área de controle. Isso é suficiente para controles simples, mas em muitos casos repintar o controle seria mais rápido se apenas a parte que precisava de atualização fosse repintada, em vez de todo o controle.

A `OnDraw` função fornece um método fácil de otimização passando *rcInvalid*, a área retangular do controle que precisa ser redesenhado. Use esta área, geralmente menor que toda a área de controle, para acelerar o processo de pintura.

## <a name="painting-your-control-using-metafiles"></a><a name="_core_painting_your_control_using_metafiles"></a>Pintando seu controle usando metaarquivos

Na maioria dos *casos,* o `OnDraw` parâmetro pdc para a função aponta para um contexto de dispositivo de tela (DC). No entanto, ao imprimir imagens do controle ou durante uma sessão de visualização de impressão, o DC recebido para renderização é um tipo especial chamado "metafile DC". Ao contrário de uma DC de tela, que imediatamente lida com solicitações enviadas a ele, um metaarquivo DC armazena solicitações para serem reproduzidas posteriormente. Algumas aplicações de contêiner também podem optar por renderizar a imagem de controle usando um METAFile DC quando no modo de design.

As solicitações de desenho de metaarquivo podem `IViewObject::Draw` ser feitas pelo contêiner através de duas funções de interface: (esta função também pode ser chamada para desenho não-metaarquivo) e `IDataObject::GetData`. Quando um DC de metaarquivo é passado como um dos parâmetros, a estrutura MFC faz uma chamada para [COleControl::OnDrawMetafile](../mfc/reference/colecontrol-class.md#ondrawmetafile). Por se trata de uma função de membro virtual, anule essa função na classe de controle para fazer qualquer processamento especial. O comportamento `COleControl::OnDraw`padrão chama .

Para garantir que o controle possa ser desenhado tanto nos contextos do dispositivo de tela quanto de metaarquivo, você deve usar apenas funções de membro que são suportadas tanto em uma tela quanto em um DC metaarquivo. Esteja ciente de que o sistema de coordenadas pode não ser medido em pixels.

Como a implementação padrão `OnDrawMetafile` das `OnDraw` chamadas da função do controle, use apenas funções de membro adequadas `OnDrawMetafile`tanto para um metaarquivo quanto para um contexto de dispositivo de tela, a menos que você anule . A seguir, lista `CDC` o subconjunto de funções de membro que podem ser usados tanto em um metaarquivo quanto em um contexto de dispositivo de tela. Para obter mais informações sobre essas funções, consulte a classe [CDC](../mfc/reference/cdc-class.md) no *MFC Reference*.

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

Além das `CDC` funções de membro, existem várias outras funções compatíveis em um DC metaarquivo. Estes incluem [CPalette::AnimatePalette,](../mfc/reference/cpalette-class.md#animatepalette) [CFont::CreateFontIndirect](../mfc/reference/cfont-class.md#createfontindirect)e `CBrush`três funções de membros de : [CreateBrushIndirect,](../mfc/reference/cbrush-class.md#createbrushindirect) [CreateDIBPatternBrush](../mfc/reference/cbrush-class.md#createdibpatternbrush)e [CreatePatternBrush](../mfc/reference/cbrush-class.md#createpatternbrush).

As funções que não estão gravadas em um metaarquivo são: [DrawFocusRect,](../mfc/reference/cdc-class.md#drawfocusrect) [DrawIcon](../mfc/reference/cdc-class.md#drawicon), [DrawText,](../mfc/reference/cdc-class.md#drawtext) [ExcludeUpdateRgn,](../mfc/reference/cdc-class.md#excludeupdatergn) [FillRect,](../mfc/reference/cdc-class.md#fillrect) [FrameRect,](../mfc/reference/cdc-class.md#framerect) [GrayString,](../mfc/reference/cdc-class.md#graystring) [InvertRect,](../mfc/reference/cdc-class.md#invertrect) [ScrollDC](../mfc/reference/cdc-class.md#scrolldc)e [TabbedTextOut](../mfc/reference/cdc-class.md#tabbedtextout). Como um DC de metaarquivo não está realmente associado a um dispositivo, você não pode usar SetDIBits, GetDIBits e CreateDIBitmap com um DC de metaarquivo. Você pode usar SetDIBitsToDevice e StretchDIBits com um DC de metaarquivo como destino. [CreateCompatibleDC,](../mfc/reference/cdc-class.md#createcompatibledc) [CreateCompatibleBitmap](../mfc/reference/cbitmap-class.md#createcompatiblebitmap)e [CreateDiscardableBitmap](../mfc/reference/cbitmap-class.md#creatediscardablebitmap) não são significativos com um DC de metaarquivo.

Outro ponto a considerar ao usar um metaarquivo DC é que o sistema de coordenadas pode não ser medido em pixels. Por esta razão, todo o seu código de desenho deve `OnDraw` ser ajustado para caber no retângulo passado para o parâmetro *rcBounds.* Isso evita a pintura acidental fora do controle porque *rcBounds* representa o tamanho da janela do controle.

Depois de implementar a renderização de metaarquivos para o controle, use O Recipiente de Teste para testar o metaarquivo. Consulte [Propriedades de teste e eventos com o recipiente de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o recipiente de teste.

#### <a name="to-test-the-controls-metafile-using-test-container"></a>Para testar o metaarquivo do controle usando o recipiente de teste

1. No menu **Editar** do contêiner de teste, clique **em Inserir novo controle**.

1. Na **caixa Inserir novo controle,** selecione o controle e clique em **OK**.

   O controle aparecerá no recipiente de teste.

1. No menu **Controle,** clique em **Desenhar Metafile**.

   Uma janela separada é exibida na qual o metaarquivo é exibido. Você pode alterar o tamanho desta janela para ver como o dimensionamento afeta o metaarquivo do controle. Você pode fechar essa janela a qualquer momento.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
