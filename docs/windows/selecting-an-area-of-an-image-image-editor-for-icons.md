---
title: 'Como: Editar uma imagem'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.image.editing
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
ms.openlocfilehash: 849da0d14987a057d39d5f9531e97545b3d4b8cf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387937"
---
# <a name="how-to-edit-an-image"></a>Como: Editar uma imagem

Você pode usar ferramentas de seleção para definir uma área de uma imagem que você deseja recortar, copiar, limpar, redimensionar, inverter ou mover. Com o **seleção de retângulo** ferramenta você pode definir e selecionar uma região retangular da imagem. Com o **seleção Irregular** ferramenta você pode desenhar um contorno à mão livre da área que você deseja selecionar para o recorte, cópia ou outra operação.

> [!NOTE]
> Consulte a **seleção de retângulo** e **seleção Irregular** ferramentas mostrada na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou exibir as dicas de ferramenta associadas com cada botão o **Editor de imagens** barra de ferramentas.

Você também pode criar um pincel personalizado a partir de uma seleção. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).

## <a name="how-to"></a>Como

Para editar uma imagem, consulte como:

### <a name="to-select-an-image"></a>Para selecionar uma imagem

1. Use o **Editor de imagens** barra de ferramentas ou vá até o menu **imagem** > **ferramentas** e escolha a ferramenta de seleção que você deseja.

1. Mova o ponto de inserção para um canto da área de imagem que você deseja selecionar. Cruzes aparecem quando o ponto de inserção é sobre a imagem.

1. Arraste o ponto de inserção para o canto oposto da área que você deseja selecionar. Um retângulo mostra quais pixels serão selecionados. Todos os pixels dentro do retângulo, inclusive as encontradas sob o retângulo, estão incluídos na seleção.

1. Solte o botão do mouse. A borda de seleção abrange a área selecionada.

#### <a name="to-select-an-entire-image"></a>Para selecionar uma imagem inteira

Selecione a imagem de fora a seleção atual. A borda de seleção altera o foco e abrange a imagem inteira novamente.

### <a name="to-edit-parts-of-an-image"></a>Para editar as partes de uma imagem

Você pode executar operações de edição padrão — recortar, copiar, limpar e movendo — em uma [seleção](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md), se a seleção é a imagem inteira ou parte dela. Porque o **Editor de imagens** usa o **área de transferência do Windows**, você pode transferir imagens entre o **Editor de imagens** e outros aplicativos para Windows.

Além disso, você pode redimensionar a seleção, se ele inclui a imagem inteira ou apenas uma parte.

#### <a name="to-cut-the-current-selection-and-move-it-to-the-clipboard"></a>Para recortar a seleção atual e mova-o para a área de transferência

Vá ao menu **edite** > **Recortar**.

#### <a name="to-copy-the-selection"></a>Para copiar a seleção

1. Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar dele, exceto as alças de dimensionamento.

1. Mantenha pressionada a **Ctrl** enquanto você arrasta a seleção para um novo local da chave. A área da seleção original permanece inalterada.

1. Para copiar a seleção para a imagem em seu local atual, selecione fora do cursor de seleção.

#### <a name="to-paste-the-clipboard-contents-into-an-image"></a>Para colar o conteúdo da área de transferência em uma imagem

1. Vá ao menu **edite** > **colar**.

   O conteúdo da área de transferência, entre a borda de seleção aparece no canto superior esquerdo do painel.

1. Posicione o ponteiro dentro da borda de seleção e arraste a imagem para o local desejado na imagem.

1. Para ancorar a imagem em seu novo local, selecione fora da borda de seleção.

#### <a name="to-delete-the-current-selection-without-moving-it-to-the-clipboard"></a>Para excluir a seleção atual sem movê-lo na área de transferência

Vá ao menu **edite** > **excluir**.

   A área original da seleção é preenchida com a cor de plano de fundo atual.

> [!NOTE]
> Você pode acessar o **Recortar**, **cópia**, **colar**, e **excluir** comandos clicando no **domododeexibiçãoderecursos** janela.

#### <a name="to-move-the-selection"></a>Para mover a seleção

1. Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar dele, exceto as alças de dimensionamento.

1. Arraste a seleção para o novo local.

1. Para ancorar a seleção da imagem em seu novo local, selecione fora da borda de seleção.

Para obter mais informações sobre desenho com uma seleção, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).

### <a name="to-flip-an-image"></a>Inverter uma imagem

Você pode inverter ou girar uma imagem para criar uma imagem espelhada do original, ative a imagem de cabeça para baixo ou girar a imagem à direita 90 graus por vez.

- Para inverter a imagem horizontalmente (imagem espelhada), vá ao menu **imagem** > **Inverter horizontalmente**.

- Para inverter a imagem verticalmente (Ativar cabeça para baixo), vá ao menu **imagem** > **Inverter verticalmente**.

- Para girar a imagem 90 graus, vá ao menu **imagem** > **Girar 90 graus**.

   > [!NOTE]
   > Você também pode usar o [teclas de aceleração (atalho)](../windows/accelerator-keys-image-editor-for-icons.md) para que esses comandos ou acessar os comandos no menu de atalho (selecione fora da imagem ao mesmo tempo na **Editor de imagens**).

### <a name="to-resize-an-image"></a>Para redimensionar uma imagem

O comportamento do **Editor de imagens** enquanto redimensionando uma imagem depende do fato de ter sido [selecionado](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas uma parte dele.

Quando a seleção inclui apenas a parte da imagem, o **Editor de imagens** reduz a seleção de exclusão de linhas ou colunas de pixels e preenchendo as regiões vazias com a cor de plano de fundo atual. Ele também pode estender a seleção duplicando linhas ou colunas de pixels.

Quando a seleção inclui toda a imagem, o **Editor de imagens** tanto é reduzido e alonga a imagem, ou corta e estende-o.

Há dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e o [janela de propriedades](/visualstudio/ide/reference/properties-window). Você arrastar as alças de dimensionamento para alterar o tamanho de todos ou parte de uma imagem. Alças de dimensionamento que você pode arrastar são sólidas. Você não pode arrastar as alças que estão vazios. Use o **propriedades** somente, de janela para redimensionar toda a imagem não é uma parte selecionada.

![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")<br/>
Alças de dimensionamento

> [!NOTE]
> Se você tiver o **grade lado a lado** opção selecionada na [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensionamento, em seguida, se ajusta para a próxima linha de grade lado a lado. Se apenas a **grade de pixels** opção é selecionada (a configuração padrão), redimensionamento de snaps de pixel para a próxima disponível.

#### <a name="to-resize-an-entire-image-using-the-properties-window"></a>Para redimensionar uma imagem inteira usando a janela Propriedades

1. Abra a imagem cujas propriedades você deseja alterar.

1. No **largura** e **altura** nas caixas de [janela propriedades](/visualstudio/ide/reference/properties-window), digite as dimensões que você deseja.

   Se você aumentar o tamanho da imagem, o **Editor de imagens** estende a imagem à direita, para baixo, ou ambos e preenche a nova região com a cor de plano de fundo atual. A imagem não está esticada.

   Se você reduzir o tamanho da imagem, o **Editor de imagens** corta a imagem na borda direita ou inferior, ou ambos.

   > [!NOTE]
   > Você pode usar o **largura** e **altura** propriedades redimensionar somente a imagem inteira, não para redimensionar uma seleção parcial.

#### <a name="to-crop-or-extend-an-entire-image"></a>Para cortar ou estender uma imagem inteira

1. Selecione a imagem inteira.

   Se parte da imagem está selecionado no momento, e você deseja selecionar a imagem inteira, selecione qualquer lugar na imagem de fora da borda da seleção atual.

1. Arraste uma alça de dimensionamento até que a imagem é o tamanho correto.

Normalmente, o **Editor de imagens** corta ou amplia uma imagem quando você redimensioná-la ao mover uma alça de dimensionamento. Se você mantiver pressionada a **Shift** chave conforme você move uma alça de dimensionamento, o **Editor de imagens** reduz ou alonga a imagem.

#### <a name="to-shrink-or-stretch-an-entire-image"></a>Para reduzir ou alongar uma imagem inteira

1. Selecione a imagem inteira.

   Se uma parte da imagem está selecionada no momento e você deseja selecionar a imagem inteira, selecione qualquer lugar na imagem de fora da borda da seleção atual.

1. Mantenha pressionada a **Shift** da chave e arrastar uma alça de dimensionamento até que a imagem é o tamanho correto.

#### <a name="to-shrink-or-stretch-part-of-an-image"></a>Para reduzir ou ampliar parte de uma imagem

1. Selecione a parte da imagem que você deseja redimensionar. Para obter mais informações, consulte [selecionando uma área da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md).

1. Arraste uma das alças de dimensionamento até que a seleção é o tamanho correto.

### <a name="to-edit-an-image-outside-of-a-project"></a>Para editar uma imagem fora de um projeto

Você pode abrir e editar imagens no ambiente de desenvolvimento, assim como faria em qualquer aplicativo de elementos gráficos, por exemplo, abrindo um bitmap para edição autônoma. Trabalhar com imagens não precisam ser parte de um projeto do Visual Studio.

1. Vá ao menu **arquivo** > **abrir**.

1. No **arquivos do tipo** caixa, selecione **todos os arquivos**.

1. Localize e abra a imagem que você deseja editar.

### <a name="to-change-image-properties"></a>Para alterar propriedades da imagem

Você pode definir ou modificar propriedades de uma imagem usando o [janela de propriedades](/visualstudio/ide/reference/properties-window).

1. Abra a imagem na **Editor de imagens**.

1. No **propriedades** janela, altere uma ou todas as propriedades para a sua imagem.

   |Propriedade|Descrição|
   |--------------|-----------------|
   |**Cores**|Especifica o esquema de cores para a imagem. Selecione **monocromático**, **16**, ou **256**, ou **True Color**.<br/><br/>Se você já foram desenhados a imagem com uma paleta de cores de 16, selecionando **monocromático** faz com que as substituições de preto e branco para as cores da imagem. Contraste não seja sempre mantido: por exemplo, nas áreas adjacentes de vermelho e verde são ambos convertidas em preto.|
   |**Filename**|Especifica o nome do arquivo de imagem.<br/><br/>Por padrão, o Visual Studio atribui um nome de arquivo base criada ao remover os primeiros quatro caracteres ("IDB_") o identificador de recurso padrão (IDB_BITMAP1) além de incluir a extensão apropriada. O nome de arquivo para a imagem neste exemplo seria *BITMAP1.bmp*. Você pode renomeá-la *MYBITMAP1.bmp*.|
   |**Altura**|Define a altura da imagem (em pixels). O valor padrão é 48.<br/><br/>A imagem é cortada ou espaço em branco é adicionado abaixo da imagem existente.|
   |**ID**|Define o identificador do recurso.<br/><br/>Para uma imagem, Microsoft Visual Studio, por padrão, atribui o próximo identificador disponível em uma série: IDB_BITMAP1, IDB_BITMAP2 e assim por diante. Nomes semelhantes são usados para ícones e cursores.|
   |**Paleta**|Alterações de propriedades de cor.<br/><br/>Clique duas vezes para selecionar uma cor e exibir o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Defina a cor, digitando valores RGB ou HSL nas caixas de texto apropriado.|
   |**SaveCompressed**|Indica se a imagem está em um formato compactado. Esta propriedade é somente para leitura.<br/><br/>Visual Studio não permite que você salvar imagens em um formato compactado, portanto, para todas as imagens criadas no Visual Studio, essa propriedade serão **falsos**. Se você abrir uma imagem compactada (criada em outro programa) no Visual Studio, essa propriedade será **verdadeira**. Se você salvar uma imagem compactada usando o Visual Studio, ele será descompactado e essa propriedade será revertido para **falsos**.|
   |**Largura**|Define a largura da imagem (em pixels). O valor padrão para bitmaps é 48.<br/><br/>A imagem é cortada ou espaço em branco é adicionado à direita da imagem existente.|

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: Usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como: Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>