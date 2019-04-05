---
title: 'Como: Criar um ícone ou outra imagem'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
- vc.editors.newimagetype
- vc.editors.customimage
- vc.editors.opendeviceimage
- vc.editors.image.editing
- vc.editors.image.editing
helpviewer_keywords:
- bitmaps [C++]
- images [C++], creating
- resources [C++], creating images
- bitmaps [C++], creating
- graphics [C++], creating
- Image editor [C++], creating images
- cursors [C++], creating
- image resources [C++], display devices
- icons [C++], creating
- cursors [C++], types
- icons [C++]
- Image editor [C++], icons and cursors
- cursors [C++]
- display devices [C++], creating icons for
- cursors [C++], hot spots
- icons [C++], types
- icons [C++], creating
- display devices [C++], creating image
- images [C++], creating for display devices
- icons [C++], inserting
- New <Device> Image Type dialog box [C++]
- Custom Image dialog box [C++]
- Open <Device> Image dialog box [C++]
- New Device Image command
- display devices [C++], adding images
- cursors [C++], adding
- icons, adding
- display devices [C++], copying images
- cursors [C++], copying
- icons, copying
- cursors [C++], deleting
- display devices [C++], deleting device image
- icons, erasing
- icons, deleting
- cursors [C++], undoing changes
- icons, undoing changes
- cursors [C++], screen regions
- inverse colors [C++], device images
- transparent regions, device images
- transparency, device images
- Image editor [C++], device images
- inverse regions, device images
- cursors [C++], transparent regions
- screen colors
- regions, transparent
- icons [C++], transparent regions
- display devices [C++], transparent and screen regions
- transparent regions in devices
- regions, inverse
- colors [C++], Image editor
- device projects [C++], transparent images
- icons [C++], screen regions
- 256-color palette
- cursors [C++], color
- colors [C++], icons
- colors [C++], cursors
- icons, color
- colors [C++], icons and cursors
- color palettes, 256-color
- palettes, 256-color
- cursors [C++], hot spots
- hot spots
- .gif files [C++], saving bitmaps as
- jpg files [C++], saving bitmaps as
- jpeg files [C++], saving bitmaps as
- .jpg files [C++], saving bitmaps as
- Image editor [C++], converting image formats
- gif files [C++], saving bitmaps as
- bitmaps [C++], converting formats
- .jpeg files [C++], saving bitmaps as
- graphics [C++], converting formats
- images [C++], converting formats
- images [C++], stand-alone editing
- Image editor [C++], converting image formats
- graphics [C++], converting formats
- images [C++], converting formats
ms.assetid: 66db3fb2-cfc1-48a2-9bdd-53f61eb7ee30
ms.openlocfilehash: d10593ffbae7aef55adc3334057402b6952d8ba7
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59027591"
---
# <a name="how-to-create-an-icon-or-other-image"></a>Como: Criar um ícone ou outra imagem

Você pode criar uma nova imagem, bitmap, ícone, cursor ou barra de ferramentas e, em seguida, use o **Editor de imagens** para personalizar sua aparência. Você também pode criar um novo bitmap em conformidade com um [modelo de recurso](../windows/how-to-use-resource-templates.md).

## <a name="icons-and-cursors-image-resources-for-display-devices"></a>Ícones e cursores: Recursos de imagem para exibir dispositivos

Ícones e cursores são os recursos gráficos que podem conter várias imagens em tamanhos diferentes e esquemas para diferentes tipos de dispositivos de exibição de cores. Um cursor também tem um ponto de acesso, o local do Windows usa para acompanhar sua posição. Ícones e cursores são criados e editados usando o **Editor de imagens**, assim como bitmaps e outras imagens.

Quando você cria um novo ícone ou cursor, o **Editor de imagens** primeiro cria uma imagem de um tipo padrão. Inicialmente, a imagem é preenchida com a cor da tela (transparente). Se a imagem é um cursor, o ponto de acesso é inicialmente o canto superior esquerdo com coordenadas `0,0`.

Por padrão, o **Editor de imagens** suporta a criação de imagens adicionais para os dispositivos exibidos na tabela a seguir. Você pode criar imagens para outros dispositivos, digitando parâmetros de largura, altura e contagem de cor para o **Custom Image** caixa de diálogo.

|Cor|Largura (pixels)|Altura (pixels)|
|-----------|----------------------|-----------------------|
|Monocromo|16|16|
|Monocromo|32|32|
|Monocromo|48|48|
|Monocromo|64|64|
|Monocromo|96|96|
|16|16|16|
|16|32|32|
|16|64|64|
|16|48|48|
|16|96|96|
|256|16|16|
|256|32|32|
|256|48|48|
|256|64|64|
|256|96|96|

### <a name="create-a-device-image-icon-or-cursor"></a>Criar uma imagem de dispositivo (ícone ou cursor)

Quando você cria um novo ícone ou cursor, o **Editor de imagens** primeiro cria uma imagem em um estilo específico (32 × 32, 16 cores para ícones e 32 × 32, monocromo para cursores). Você pode, em seguida, adicionar imagens em tamanhos diferentes e estilos para o ícone inicial ou o cursor e edite cada imagem adicional, conforme necessário, para os dispositivos de exibição diferentes. Você também pode editar uma imagem usando uma operação de copiar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa de gráfico.

Quando você abre o recurso de ícone ou cursor na [Editor de imagens](../windows/image-editor-for-icons.md), a imagem a maioria dos combinar o dispositivo de exibição atual é aberta por padrão.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

O **New &lt;dispositivo&gt; tipo de imagem** caixa de diálogo permite que você crie uma nova imagem de dispositivo de um tipo especificado. Para abrir o **New \<dispositivo > imagem** caixa de diálogo, vá ao menu **imagem** > **novo tipo de imagem**. As seguintes propriedades incluídas estão **tipo de imagem de destino** e **personalizado**.

O **tipo de imagem de destino** propriedade lista os tipos de imagem disponível em que você selecionar a imagem do tipo que você deseja abrir:

||||
|-|-|-|
|– 16 x 16, 16 cores|-48 x 48, 16 cores|-96 x 96, 16 cores|
|– 16 x 16, 256 cores|-48 x 48, 256 cores|-96 x 96, 256 cores|
|– 16 x 16, monocromo|-48 x 48, monocromo|-96 x 96, monocromo|
|-32 x 32, 16 cores|-64 x 64, 16 cores||
|-32 x 32, 256 cores|-64 x 64, 256 cores||
|-32 x 32, monocromo|-64 x 64, monocromo||

> [!NOTE]
> Todas as imagens existentes não serão exibidas nessa lista.

O **personalizado** propriedade abre o **imagem personalizada** caixa de diálogo na qual você pode criar uma nova imagem com um tamanho personalizado e o número de cores.

O **imagem personalizada** caixa de diálogo permite que você crie uma nova imagem com um tamanho personalizado e o número de cores. As propriedades a seguir incluídas são:

|Propriedade|Descrição|
|---|---|
|**Largura**|Fornece um espaço para que você insira a largura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Altura**|Fornece um espaço para que você insira a altura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Cores**|Fornece um espaço para que você escolha o número de cores para a imagem personalizada: 2, 16 ou 256.|

Use o **abra &lt;dispositivo&gt; imagem** caixa de diálogo para abrir imagens de dispositivo em projetos do C++. Ele lista as imagens de dispositivo existentes no recurso atual (imagens que fazem parte do recurso atual). É a seguinte propriedade incluída:

|Propriedade|Descrição|
|---|---|
|**Imagens atuais**|Lista as imagens incluídas no recurso. Selecione o tipo de imagem que você deseja abrir.|

#### <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), clique com botão direito seu *. rc* de arquivo e, em seguida, escolha **inserir recurso**. Se você já tiver um recurso de imagem existente em seu *. rc* arquivo, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir**.

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**. Para ícones, essa ação cria um recurso de ícone com um 32 × 32, o ícone de 16 cores. Para cursores de 32 × 32, imagem monocromática de (2 cores) é criada.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

### <a name="to-add-an-image-for-a-different-display-device"></a>Para adicionar uma imagem para um dispositivo de exibição diferente

1. Vá ao menu **imagem** > **nova imagem de dispositivo**, ou clique com botão direito no **Editor de imagens** painel e escolha **nova imagem de dispositivo**.

1. Selecione o tipo de imagem que você deseja adicionar. Você também pode selecionar **personalizado** para criar um ícone cujo tamanho não está disponível na lista padrão.

### <a name="to-copy-a-device-image"></a>Para copiar uma imagem de dispositivo

1. Vá ao menu **imagem** > **Abrir imagem do dispositivo** e escolha uma imagem da lista de imagens atual. Por exemplo, escolha 32 × 32, versão de 16 cores de um ícone.

1. Copie a imagem do ícone exibido no momento (**Ctrl**+**C**).

1. Abrir uma imagem diferente do ícone em outro **Editor de imagens** janela. Por exemplo, abra o 16 × 16, versão de 16 cores do ícone.

1. Cole a imagem de ícone (**Ctrl**+**V**) de um **Editor de imagens** janela para outra. Se você estiver colando um tamanho maior em um tamanho menor, você pode usar os identificadores de ícone para redimensionar a imagem.

### <a name="to-delete-a-device-image"></a>Para excluir uma imagem de dispositivo

Enquanto a imagem do ícone é exibida na **Editor de imagens**, vá ao menu **imagem** > **excluir imagem do dispositivo**. Quando você exclui a última imagem de ícone no recurso, o recurso também é excluído.

> [!NOTE]
> Quando você pressiona o **/DEL** chave, as imagens e cores que você desenhou em um ícone são excluídas, mas o ícone permanece e você agora pode reprojetar a ele. Se você pressionar **/DEL** por engano, pressione **Ctrl**+**Z** desfazer a ação.

### <a name="to-create-transparent-or-inverse-regions-in-device-images"></a>Para criar regiões transparentes ou inversas em imagens de dispositivo

No [Editor de imagens](../windows/image-editor-for-icons.md), a imagem de ícone ou cursor inicial tem um atributo transparente. Embora as imagens de ícone e cursor são retangulares, muitos não aparecem isso porque partes da imagem são transparentes e a imagem subjacente na tela mostra por meio do ícone ou cursor. Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida. Criar esse efeito, definindo a cor da tela e as cores invertidas na [janela de cores](../windows/colors-window-image-editor-for-icons.md).

As cores da tela e o inverso é aplicar a ícones e cursores da forma e a imagem derivada de cor ou atribuir regiões inversos. As cores indicam partes da imagem que têm esses atributos. Você pode alterar as cores que representam os atributos de cor da tela e cor inverso no modo de edição. Essas alterações não afetam a aparência do ícone ou cursor em seu aplicativo.

> [!NOTE]
> As caixas de diálogo e os comandos de menu vistos podem ser diferentes daqueles descritos na **Ajuda**, dependendo da edição ou das configurações ativas. Para alterar suas configurações, vá ao menu **ferramentas** > **importar e exportar configurações**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

#### <a name="to-create-transparent-or-inverse-regions"></a>Para criar regiões transparentes ou inversas

1. No **cores** janela, escolha o seletor **cor da tela** ou **inverso cor**.

1. Aplique a tela ou cores invertidas em sua imagem usando uma ferramenta de desenho. Para obter mais informações sobre ferramentas de desenho, consulte [usando uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md).

#### <a name="to-change-the-screen-or-inverse-color"></a>Para alterar a cor da tela ou inverso

1. Selecione o **cores da tela** seletor ou o **inverso cor** seletor.

1. Escolha uma cor na **cores** paleta na **cores** janela.

   A cor complementar é atribuído automaticamente para o seletor de outro.

   > [!TIP]
   > Se você clicar duas vezes o **cores da tela** ou **inverso cor** seletor, o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) é exibida.

### <a name="use-the-256-color-palette"></a>Use a paleta de 256 cores

Usando o **Editor de imagens**, ícones e cursores podem ser dimensionados grandes (64 x 64) com uma paleta de 256 cores para escolher de. Depois de criar o recurso, um estilo de imagem do dispositivo é selecionado.

#### <a name="to-create-a-256-color-icon-or-cursor"></a>Para criar um ícone de 256 cores ou cursor

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), clique com botão direito seu *. rc* de arquivo e, em seguida, escolha **inserir recurso**. Se você já tiver um recurso de imagem existente em seu *. rc* arquivo, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir**.

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**.

1. Vá ao menu **imagem** > **nova imagem de dispositivo** e selecione o estilo de imagem de 256 cores que você deseja.

#### <a name="to-choose-a-color-from-the-256-color-palette-for-large-icons"></a>Para escolher uma cor da paleta de 256 cores de ícones grandes

Para desenhar com uma seleção da paleta de 256 cores, você precisará selecionar as cores do **cores** paleta na [janela cores](../windows/colors-window-image-editor-for-icons.md).

1. Selecione o ícone grande ou cursor ou criar um novo ícone grande ou cursor.

1. Escolha uma cor de 256 cores exibidas nos **cores** paleta na **cores** janela.

   A cor selecionada se tornará a cor atual na **cores** paleta na **cores** janela.

   > [!NOTE]
   > A paleta inicial usada para imagens de 256 cores corresponde a paleta retornada pelo `CreateHalftonePalette` API do Windows. Todos os ícones destinados para o shell do Windows devem usar essa paleta para evitar a cintilação durante a realização da paleta.

### <a name="to-set-a-cursors-hot-spot"></a>Para definir o ponto de acesso de um cursor

O ponto de acesso de um cursor é o ponto de para qual Windows refere-se em controle de posição do cursor. Por padrão, o ponto de acesso é definido para o canto superior esquerdo do cursor com coordenadas `0,0`. O **Hotspot** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window) mostra as coordenadas de ponto de acesso.

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md), escolha o **defina ponto de acesso** ferramenta.

1. Selecione o pixel que você deseja atribuir como o ponto de acesso do cursor.

   O **Hotspot** propriedade no **propriedades** janela exibe as novas coordenadas.

### <a name="to-create-and-save-a-bitmap-as-a-gif-or-jpeg"></a>Para criar e salvar um bitmap como um. gif ou JPEG

Quando você cria um bitmap, a imagem é criada no formato de bitmap (. bmp). No entanto, você pode, salve a imagem como GIF ou JPEG ou em outros formatos de gráfico.

> [!NOTE]
> Esse processo não se aplica a ícones e cursores.

1. Vá ao menu **arquivo** > **abra**, em seguida, selecione **arquivo**.

1. No **caixa de diálogo Novo arquivo**, escolha o **Visual C++** pasta, em seguida, selecione **arquivo de Bitmap (. bmp)** no **modelos** caixa e selecione  **Abra**.

   O bitmap é aberto na **Editor de imagens**.

1. Faça alterações em seu novo bitmap, conforme necessário.

1. Com o bitmap ainda aberto na **Editor de imagens**, vá ao menu **arquivo** > **salvar *filename*bmp como**.

1. No **salvar arquivo como** caixa de diálogo, digite o nome que você deseja dar o arquivo e a extensão que indica o formato de arquivo que você deseja na **nome do arquivo** caixa. Por exemplo, *myfile.gif*.

   > [!NOTE]
   > Você deve criar ou abrir o bitmap fora do seu projeto para salvá-lo como outro formato de arquivo. Se você criar ou abri-lo em seu projeto, o **Salvar como** comando estará disponível. Para obter mais informações, consulte [exibir recursos em um recurso de Script arquivo externa de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

1. Selecione **Salvar**.

### <a name="to-convert-an-image-from-one-format-to-another"></a>Converter uma imagem de um formato para outro

Você pode abrir imagens GIF ou JPEG na **Editor de imagens** e salvá-los como bitmaps. Além disso, você pode abrir um arquivo de bitmap e salvá-lo como um GIF ou JPEG. Trabalhar com imagens de não precisam ser parte de um projeto para edição no ambiente de desenvolvimento (consulte [edição de imagem autônoma](../windows/editing-an-image-outside-of-a-project-image-editor-for-icons.md)).

1. Abra a imagem na **Editor de imagens**.

1. Vá ao menu **arquivo** > **salvar *filename* como**.

1. No **salvar arquivo como** na caixa de **nome do arquivo** , digite o nome do arquivo e a extensão que indica o formato desejado.

1. Selecione **Salvar**.

### <a name="to-add-a-new-image-resource-to-an-unmanaged-c-project"></a>Para adicionar um novo recurso de imagem a um projeto de C++ não gerenciado

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), clique com botão direito seu *. rc* de arquivo e, em seguida, escolha **inserir recurso**. Se você já tiver um recurso de imagem existente em seu *. rc* arquivo, como um cursor, você pode simplesmente com o botão direito do **Cursor** pasta e selecione **Cursor inserir**.

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione o tipo de recurso de imagem que você deseja criar (**Bitmap**, por exemplo), em seguida, escolha **New**.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

### <a name="to-add-a-new-image-resource-to-a-project-in-a-net-programming-language"></a>Para adicionar um novo recurso de imagem a um projeto em uma linguagem de programação do .NET

1. Na **Gerenciador de soluções**, clique na pasta de projeto (por exemplo, *WindowsApplication1*).

1. No menu de atalho, selecione **Add**, em seguida, escolha **Adicionar Novo Item**.

1. No **categorias** painel, expanda o **itens de projeto locais** pasta, em seguida, escolha **recursos**.

1. No **modelos** painel, escolha o tipo de recurso que você deseja adicionar ao seu projeto.

   O recurso é adicionado ao seu projeto no **Gerenciador de soluções** e o recurso é aberto na [Editor de imagens](../windows/image-editor-for-icons.md). Agora você pode usar todas as ferramentas disponíveis na **Editor de imagens** para modificar sua imagem. Para obter mais informações sobre como adicionar imagens a um projeto gerenciado, consulte [carregando uma imagem em tempo de Design](/dotnet/framework/winforms/controls/how-to-load-a-picture-using-the-designer-windows-forms).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: Use uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como: Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
<!--
[Converting Bitmaps to Toolbars](../windows/converting-bitmaps-to-toolbars.md)<br/>
[Creating New Toolbars](../windows/creating-new-toolbars.md)<br/>
[Icons](/windows/desktop/menurc/icons)<br/>
[Cursors](/windows/desktop/menurc/cursors)<br/>-->