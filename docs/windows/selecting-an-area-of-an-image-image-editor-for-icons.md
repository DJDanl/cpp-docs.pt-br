---
title: 'Como: editar uma imagem'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.image.editing
helpviewer_keywords:
- Image editor [C++], image selection
- Image editor [C++], selecting images
- images [C++], selecting
- cursors [C++], selecting areas of
- Image editor [C++], editing images
- Clipboard [C++], pasting
- images [C++], editing
- images [C++], deleting selected parts
- images [C++], copying selected parts
- images [C++], moving selected parts
- images [C++], dragging and replicating selected parts
- images [C++], pasting into
- graphics [C++], editing
- Image editor [C++], flipping and rotating images
- images [C++], flipping
- images [C++], rotating
- Image editor [C++], resizing images
- graphics [C++], resizing
- images [C++], resizing
- resizing images
- size [C++], images
- images [C++], cropping
- images [C++], extending
- Image editor [C++], cropping or extending images
- Image editor [C++], shrinking and stretching images
- images [C++], stretching
- images [C++], shrinking
- bitmaps [C++], shrinking
- bitmaps [C++], stretching
- Image editor [C++], editing images
- images [C++], editing
- images [C++], properties
- Image editor [C++], Properties window
- Properties window, image editor
ms.assetid: 8b6ce4ad-eba1-4ece-86ba-cea92c3edff2
ms.openlocfilehash: 6d973ad444f719b905af5a33e47ef28f4895111f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447297"
---
# <a name="how-to-edit-an-image"></a>Como: editar uma imagem

Você pode usar as ferramentas de seleção para definir uma área de uma imagem que deseja recortar, copiar, limpar, redimensionar, inverter ou mover. Com a ferramenta de **seleção de retângulo** , você pode definir e selecionar uma região retangular da imagem. Com a ferramenta de **seleção irregular** , você pode desenhar um contorno à mão da área que deseja selecionar para a operação recortar, copiar ou outra.

> [!NOTE]
> Consulte a **seleção de retângulo** e as ferramentas de **seleção irregular** modeladas na [barra de ferramentas do editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou exiba as dicas de ferramenta associadas a cada botão na barra de ferramentas do editor de **imagem** .

Você também pode criar um pincel personalizado a partir de uma seleção. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).

## <a name="how-to"></a>Como

Para editar uma imagem, consulte Como:

### <a name="to-select-an-image"></a>Para selecionar uma imagem

1. Use a barra de ferramentas do **Editor de imagem** ou vá para a **imagem** de menu > **ferramentas** e escolha a ferramenta de seleção desejada.

1. Mova o ponto de inserção para um canto da área da imagem que você deseja selecionar. As cruzes aparecem quando o ponto de inserção está sobre a imagem.

1. Arraste o ponto de inserção para o canto oposto da área que você deseja selecionar. Um retângulo mostra quais pixels serão selecionados. Todos os pixels dentro do retângulo, incluindo aqueles sob o retângulo, são incluídos na seleção.

1. Solte o botão do mouse. A borda de seleção inclui a área selecionada.

#### <a name="to-select-an-entire-image"></a>Para selecionar uma imagem inteira

Selecione a imagem fora da seleção atual. A borda de seleção altera o foco e engloba a imagem inteira novamente.

### <a name="to-edit-parts-of-an-image"></a>Para editar partes de uma imagem

Você pode executar operações de edição padrão, recortando, copiando, limpando e movendo — em uma [seleção](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md), se a seleção é a imagem inteira ou apenas uma parte dela. Como o **Editor de imagem** usa a **área de transferência do Windows**, você pode transferir imagens entre o editor de **imagem** e outros aplicativos para Windows.

Além disso, você pode redimensionar a seleção, independentemente de ela incluir a imagem inteira ou apenas uma parte.

#### <a name="to-cut-the-current-selection-and-move-it-to-the-clipboard"></a>Para recortar a seleção atual e movê-la para a área de transferência

Vá para menu **editar** > **recortar**.

#### <a name="to-copy-the-selection"></a>Para copiar a seleção

1. Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar dele, exceto nas alças de dimensionamento.

1. Mantenha pressionada a tecla **Ctrl** enquanto arrasta a seleção para um novo local. A área da seleção original não foi alterada.

1. Para copiar a seleção para a imagem em seu local atual, selecione fora do cursor de seleção.

#### <a name="to-paste-the-clipboard-contents-into-an-image"></a>Para colar o conteúdo da área de transferência em uma imagem

1. Vá para o menu **editar** > **colar**.

   O conteúdo da área de transferência, rodeado pela borda de seleção, aparece no canto superior esquerdo do painel.

1. Posicione o ponteiro dentro da borda de seleção e arraste a imagem para o local desejado na imagem.

1. Para ancorar a imagem em seu novo local, selecione fora da borda de seleção.

#### <a name="to-delete-the-current-selection-without-moving-it-to-the-clipboard"></a>Para excluir a seleção atual sem movê-la para a área de transferência

Vá para o menu **editar** > **excluir**.

   A área original da seleção é preenchida com a cor da tela de fundo atual.

> [!NOTE]
> Você pode acessar os comandos **recortar**, **copiar**, **colar**e **excluir** clicando com o botão direito do mouse na janela **modo de exibição de recursos** .

#### <a name="to-move-the-selection"></a>Para mover a seleção

1. Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar dele, exceto nas alças de dimensionamento.

1. Arraste a seleção para o novo local.

1. Para ancorar a seleção na imagem em seu novo local, selecione fora da borda de seleção.

Para obter mais informações sobre como desenhar com uma seleção, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).

### <a name="to-flip-an-image"></a>Para inverter uma imagem

Você pode inverter ou girar uma imagem para criar uma imagem espelhada do original, virar a imagem de cabeça para baixo ou girar a imagem para a direita 90 graus de cada vez.

- Para virar a imagem horizontalmente (imagem espelho), vá para **imagem** do menu > **inverter horizontal**.

- Para virar a imagem verticalmente (virar de cabeça para baixo), vá para a **imagem** do menu > **inverter verticalmente**.

- Para girar a imagem 90 graus, vá para a **imagem** do menu > **girar 90 graus**.

   > [!NOTE]
   > Você também pode usar as [teclas do acelerador (atalho)](../windows/accelerator-keys-image-editor-for-icons.md) para esses comandos ou acessar os comandos no menu de atalho (selecione fora da imagem enquanto estiver no **Editor de imagens**).

### <a name="to-resize-an-image"></a>Para redimensionar a imagem

O comportamento do **Editor de imagem** durante o redimensionamento de uma imagem depende de você ter [selecionado](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas parte dela.

Quando a seleção inclui apenas parte da imagem, o **Editor de imagem** reduz a seleção excluindo linhas ou colunas de pixels e preenchendo as regiões vagadas com a cor de plano de fundo atual. Ele também pode ampliar a seleção duplicando linhas ou colunas de pixels.

Quando a seleção inclui a imagem inteira, o **Editor de imagem** reduz e amplia a imagem, ou corta e estende-a.

Há dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e a [janela Propriedades](/visualstudio/ide/reference/properties-window). Você arrasta as alças de dimensionamento para alterar o tamanho de toda ou parte de uma imagem. Os identificadores de dimensionamento que você pode arrastar são sólidos. Não é possível arrastar identificadores vazios. Use a janela **Propriedades** para redimensionar toda a imagem, não uma parte selecionada.

![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")<br/>
Alças de dimensionamento

> [!NOTE]
> Se você tiver a opção de **grade de blocos** selecionada na [caixa de diálogo Configurações de grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensione os snaps para a próxima linha de grade de bloco. Se apenas a opção **grade de pixels** for selecionada (a configuração padrão), o redimensionamento será ajustado para o próximo pixel disponível.

#### <a name="to-resize-an-entire-image-using-the-properties-window"></a>Para redimensionar uma imagem inteira usando a janela Propriedades

1. Abra a imagem cujas propriedades você deseja alterar.

1. Nas caixas **largura** e **altura** na [janela Propriedades](/visualstudio/ide/reference/properties-window), digite as dimensões desejadas.

   Se você estiver aumentando o tamanho da imagem, o **Editor de imagem** estenderá a imagem para a direita, para baixo ou para ambas, e preencherá a nova região com a cor de plano de fundo atual. A imagem não está ampliada.

   Se você reduzir o tamanho da imagem, o **Editor de imagem** cortará a imagem na borda direita ou inferior, ou em ambas.

   > [!NOTE]
   > Você pode usar as propriedades **Width** e **Height** para redimensionar apenas a imagem inteira, não para redimensionar uma seleção parcial.

#### <a name="to-crop-or-extend-an-entire-image"></a>Para cortar ou estender uma imagem inteira

1. Selecione a imagem inteira.

   Se parte da imagem estiver selecionada no momento e você quiser selecionar a imagem inteira, selecione qualquer lugar na imagem fora da borda de seleção atual.

1. Arraste uma alça de dimensionamento até que a imagem tenha o tamanho correto.

Normalmente, o **Editor de imagem** corta ou amplia uma imagem ao redimensioná-la movendo uma alça de dimensionamento. Se você mantiver a tecla **Shift** pressionada ao mover uma alça de dimensionamento, o **Editor de imagem** reduzirá ou ampliará a imagem.

#### <a name="to-shrink-or-stretch-an-entire-image"></a>Para reduzir ou alongar uma imagem inteira

1. Selecione a imagem inteira.

   Se uma parte da imagem estiver selecionada no momento e você quiser selecionar a imagem inteira, selecione qualquer lugar na imagem fora da borda de seleção atual.

1. Mantenha pressionada a tecla **Shift** e arraste uma alça de dimensionamento até que a imagem tenha o tamanho correto.

#### <a name="to-shrink-or-stretch-part-of-an-image"></a>Para reduzir ou ampliar parte de uma imagem

1. Selecione a parte da imagem que você deseja redimensionar. Para obter mais informações, consulte [selecionando uma área da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md).

1. Arraste uma das alças de dimensionamento até que a seleção tenha o tamanho correto.

### <a name="to-edit-an-image-outside-of-a-project"></a>Para editar uma imagem fora de um projeto

Você pode abrir e editar imagens no ambiente de desenvolvimento da mesma forma como faria em qualquer aplicativo gráfico, por exemplo, abrindo um bitmap para edição autônoma. As imagens com as quais você trabalha não precisam fazer parte de um projeto do Visual Studio.

1. Vá até o **arquivo** de menu > **abrir**.

1. Na caixa **arquivos do tipo** , selecione **todos os arquivos**.

1. Localize e abra a imagem que você deseja editar.

### <a name="to-change-image-properties"></a>Para alterar as propriedades da imagem

Você pode definir ou modificar as propriedades de uma imagem usando o [janela Propriedades](/visualstudio/ide/reference/properties-window).

1. Abra a imagem no **Editor de imagem**.

1. Na janela **Propriedades** , altere qualquer uma ou todas as propriedades da imagem.

   |Propriedade|Descrição|
   |--------------|-----------------|
   |**Cores**|Especifica o esquema de cores para a imagem. Selecione **monocromático**, **16**ou **256**ou **true color**.<br/><br/>Se você já tiver desenhado a imagem com uma paleta de 16 cores, selecionar **monocromático** causará substituições de preto e branco para as cores na imagem. O contraste nem sempre é mantido: por exemplo, áreas adjacentes de vermelho e verde são convertidas em preto.|
   |**Filename**|Especifica o nome do arquivo de imagem.<br/><br/>Por padrão, o Visual Studio atribui um nome de arquivo base criado removendo os quatro primeiros caracteres ("IDB_") do identificador de recurso padrão (IDB_BITMAP1) e adicionando a extensão apropriada. O nome do arquivo para a imagem neste exemplo seria *Bitmap1. bmp*. Você pode renomeá-lo *MYBITMAP1. bmp*.|
   |**Altura**|Define a altura da imagem (em pixels). O valor padrão é 48.<br/><br/>A imagem é cortada ou o espaço em branco é adicionado abaixo da imagem existente.|
   |**ID**|Define o identificador do recurso.<br/><br/>Para uma imagem, Microsoft Visual Studio, por padrão, atribui o próximo identificador disponível em uma série: IDB_BITMAP1, IDB_BITMAP2 e assim por diante. Nomes semelhantes são usados para ícones e cursores.|
   |**Palette**|Altera as propriedades de cor.<br/><br/>Clique duas vezes para selecionar uma cor e exibir a [caixa de diálogo Seletor de cores personalizado](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Defina a cor digitando os valores RGB ou HSL nas caixas de texto apropriadas.|
   |**SaveCompressed**|Indica se a imagem está em um formato compactado. Esta propriedade é somente para leitura.<br/><br/>O Visual Studio não permite que você salve imagens em um formato compactado, portanto, para qualquer imagem criada no Visual Studio, essa propriedade será **falsa**. Se você abrir uma imagem compactada (criada em outro programa) no Visual Studio, essa propriedade será **verdadeira**. Se você salvar uma imagem compactada usando o Visual Studio, ela será descompactada e essa propriedade será revertida para **false**.|
   |**Largura**|Define a largura da imagem (em pixels). O valor padrão para bitmaps é 48.<br/><br/>A imagem é cortada ou o espaço em branco é adicionado à direita da imagem existente.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>