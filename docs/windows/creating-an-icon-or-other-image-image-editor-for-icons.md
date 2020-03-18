---
title: 'Como: criar um ícone ou outra imagem'
ms.date: 02/15/2019
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
ms.openlocfilehash: 046b7e0070d95f5d17b3240884db76533f1c6ccd
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443918"
---
# <a name="how-to-create-an-icon-or-other-image"></a>Como: criar um ícone ou outra imagem

Você pode criar uma nova imagem, bitmap, ícone, cursor ou barra de ferramentas e, em seguida, usar o **Editor de imagem** para personalizar sua aparência. Você também pode criar um novo bitmap padronizado após um [modelo de recurso](../windows/how-to-use-resource-templates.md).

## <a name="icons-and-cursors-image-resources-for-display-devices"></a>Ícones e cursores: recursos de imagem para exibir dispositivos

Ícones e cursores são recursos gráficos que podem conter várias imagens em diferentes tamanhos e esquemas de cores para diferentes tipos de dispositivos de vídeo. Um cursor também tem um ponto de acesso, o local que o Windows usa para controlar sua posição. Os ícones e cursores são criados e editados usando o **Editor de imagem**, assim como bitmaps e outras imagens.

Quando você cria um novo ícone ou cursor, o **Editor de imagem** primeiro cria uma imagem de um tipo padrão. A imagem é inicialmente preenchida com a cor da tela (transparente). Se a imagem for um cursor, o ponto de acesso será inicialmente o canto superior esquerdo com coordenadas `0,0`.

Por padrão, o **Editor de imagem** dá suporte à criação de imagens adicionais para os dispositivos mostrados na tabela a seguir. Você pode criar imagens para outros dispositivos digitando largura, altura e parâmetros de contagem de cores na caixa de diálogo **imagem personalizada** .

|Cor|Largura (pixels)|Altura (pixels)|
|-----------|----------------------|-----------------------|
|Monocromático|16|16|
|Monocromático|32|32|
|Monocromático|48|48|
|Monocromático|64|64|
|Monocromático|96|96|
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

### <a name="create-a-device-image-icon-or-cursor"></a>Criar uma imagem do dispositivo (ícone ou cursor)

Quando você cria um novo ícone ou recurso de cursor, o **Editor de imagem** primeiro cria uma imagem em um estilo específico (32 × 32, 16 cores para ícones e 32 × 32, monocromático para cursores). Em seguida, você pode adicionar imagens em diferentes tamanhos e estilos ao ícone ou cursor inicial e editar cada imagem adicional, conforme necessário, para os diferentes dispositivos de vídeo. Você também pode editar uma imagem usando uma operação de recortar e colar de um tipo de imagem existente ou de um bitmap criado em um programa gráfico.

Quando você abre o ícone ou o recurso de cursor no [Editor de imagem](../windows/image-editor-for-icons.md), a imagem que mais se aproximar do dispositivo de vídeo atual será aberta por padrão.

> [!NOTE]
> Se o seu projeto ainda não contiver um arquivo. rc, consulte [criando um novo arquivo de script de recurso](../windows/how-to-create-a-resource-script-file.md).

A caixa de diálogo **novo tipo de imagem do dispositivo de &lt;&gt;** permite que você crie uma nova imagem de dispositivo de um tipo especificado. Para abrir a caixa de diálogo **novo \<dispositivo > imagem** , vá para **imagem** do menu > **novo tipo de imagem**. As seguintes propriedades incluídas são **tipo de imagem de destino** e **personalizado**.

A propriedade **tipo de imagem de destino** lista os tipos de imagem disponíveis onde você seleciona o tipo de imagem que deseja abrir:

||||
|-|-|-|
|-16 x 16, 16 cores|-48 x 48, 16 cores|-96 x 96, 16 cores|
|-16 x 16, 256 cores|-48 x 48, 256 cores|-96 x 96, 256 cores|
|-16 x 16, monocromático|-48 x 48, monocromático|-96 x 96, monocromático|
|-32 x 32, 16 cores|-64 x 64, 16 cores||
|-32 x 32, 256 cores|-64 x 64, 256 cores||
|-32 x 32, monocromático|-64 x 64, monocromático||

> [!NOTE]
> Todas as imagens existentes não serão exibidas nesta lista.

A propriedade **personalizada** abre a caixa de diálogo **imagem personalizada** na qual é possível criar uma nova imagem com um tamanho personalizado e um número de cores.

A caixa de diálogo **imagem personalizada** permite que você crie uma nova imagem com um tamanho personalizado e um número de cores. As seguintes propriedades incluídas são:

|Propriedade|Descrição|
|---|---|
|**Largura**|Fornece um espaço para inserir a largura da imagem personalizada em pixels (1-512, limite de 2048).|
|**Altura**|Fornece um espaço para inserir a altura da imagem personalizada em pixels (1-512, limite de 2048).|
|**Cores**|Fornece um espaço para você escolher o número de cores para a imagem personalizada: 2, 16 ou 256.|

Use a caixa de diálogo **abrir &lt;dispositivo&gt; imagem** para abrir imagens de C++ dispositivo em projetos. Ele lista as imagens de dispositivo existentes no recurso atual (imagens que fazem parte do recurso atual). A seguinte propriedade incluída é:

|Propriedade|Descrição|
|---|---|
|**Imagens atuais**|Lista as imagens incluídas no recurso. Selecione o tipo de imagem que você deseja abrir.|

#### <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e escolha **Inserir recurso**. Se você já tiver um recurso de imagem existente no arquivo *. rc* , como um cursor, poderá clicar com o botão direito do mouse na pasta **cursor** e selecionar **Insert cursor**.

1. Na [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **cursor** e escolha **novo**. Para ícones, essa ação cria um recurso de ícone com um ícone 32 × 32, 16 cores. Para cursores, uma imagem de 32 × 32, monocromático (2 cores) é criada.

   Se um sinal de adição ( **+** ) aparecer ao lado do tipo de recurso de imagem na caixa de diálogo **Inserir recurso** , significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **novo**.

### <a name="to-add-an-image-for-a-different-display-device"></a>Para adicionar uma imagem para um dispositivo de vídeo diferente

1. Vá para **imagem** do menu > **nova imagem do dispositivo**ou clique com o botão direito do mouse no painel do editor de **imagens** e escolha **nova imagem do dispositivo**.

1. Selecione o tipo de imagem que você deseja adicionar. Você também pode selecionar **personalizado** para criar um ícone cujo tamanho não esteja disponível na lista padrão.

### <a name="to-copy-a-device-image"></a>Para copiar uma imagem de dispositivo

1. Vá para a **imagem** do menu > **abra a imagem do dispositivo** e escolha uma imagem na lista imagens atuais. Por exemplo, escolha a versão 32 × 32, 16 cores de um ícone.

1. Copiar a imagem de ícone exibida no momento (**Ctrl**+**C**).

1. Abra uma imagem diferente do ícone em outra janela do **Editor de imagens** . Por exemplo, abra a versão 16 × 16, 16 cores do ícone.

1. Cole a imagem do ícone (**Ctrl**+**V**) de uma janela do **Editor de imagem** para a outra. Se estiver colando um tamanho maior em um tamanho menor, você poderá usar as alças de ícone para redimensionar a imagem.

### <a name="to-delete-a-device-image"></a>Para excluir uma imagem de dispositivo

Enquanto a imagem do ícone é exibida no **Editor de imagem**, vá para **imagem** do menu > **excluir imagem do dispositivo**. Quando você exclui a imagem do último ícone no recurso, o recurso também é excluído.

> [!NOTE]
> Quando você pressiona a tecla **del** , as imagens e cores que você desenhou em um ícone são excluídas, mas o ícone permanece e agora você pode recriá-la. Se você pressionar **del** por engano, pressione **Ctrl**+**Z** para desfazer a ação.

### <a name="to-create-transparent-or-inverse-regions-in-device-images"></a>Para criar regiões transparentes ou inversas em imagens de dispositivos

No [Editor de imagem](../windows/image-editor-for-icons.md), o ícone inicial ou a imagem do cursor tem um atributo transparente. Embora as imagens de ícone e cursor sejam retangulares, muitas delas não aparecem, pois as partes da imagem são transparentes e a imagem subjacente na tela mostra o ícone ou cursor. Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida. Você cria esse efeito definindo a cor da tela e a cor inversa na [janela cores](../windows/colors-window-image-editor-for-icons.md).

A tela e as cores inversas que você aplica a ícones e cursores forma e cor a imagem derivada ou atribui regiões inversas. As cores indicam partes da imagem que têm esses atributos. Você pode alterar as cores que representam os atributos cor da tela e cor inversa na edição. Essas alterações não afetam a aparência do ícone ou cursor em seu aplicativo.

> [!NOTE]
> As caixas de diálogo e os comandos de menu vistos podem ser diferentes daqueles descritos na **Ajuda**, dependendo da edição ou das configurações ativas. Para alterar as configurações, vá até **ferramentas** de menu > **configurações de importação e exportação**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

#### <a name="to-create-transparent-or-inverse-regions"></a>Para criar regiões transparentes ou inversas

1. Na janela **cores** , escolha a cor da **tela** do seletor ou a **cor inversa**.

1. Aplique a tela ou a cor inversa em sua imagem usando uma ferramenta de desenho. Para obter mais informações sobre ferramentas de desenho, consulte [usando uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md).

#### <a name="to-change-the-screen-or-inverse-color"></a>Para alterar a tela ou a cor inversa

1. Selecione o seletor de **cor da tela** ou o seletor de **cor inversa** .

1. Escolha uma cor na paleta **cores** na janela **cores** .

   A cor complementar é atribuída automaticamente ao outro seletor.

   > [!TIP]
   > Se você clicar duas vezes no seletor de cor da **tela** ou **de cor inversa** , a [caixa de diálogo Seletor de cores personalizado](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) será exibida.

### <a name="use-the-256-color-palette"></a>Usar a paleta de cores 256

Usando o **Editor de imagem**, ícones e cursores podem ser dimensionados grande (64 × 64) com uma paleta de cores 256 para escolher. Depois de criar o recurso, um estilo de imagem do dispositivo é selecionado.

#### <a name="to-create-a-256-color-icon-or-cursor"></a>Para criar um ícone ou cursor de cor de 256

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e escolha **Inserir recurso**. Se você já tiver um recurso de imagem existente no arquivo *. rc* , como um cursor, poderá clicar com o botão direito do mouse na pasta **cursor** e selecionar **Insert cursor**.

1. Na [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **cursor** e escolha **novo**.

1. Vá para a **imagem** do menu > **nova imagem do dispositivo** e selecione o estilo de imagem 256-cor desejado.

#### <a name="to-choose-a-color-from-the-256-color-palette-for-large-icons"></a>Para escolher uma cor da paleta de cores 256 para ícones grandes

Para desenhar com uma seleção da paleta de cores 256, você precisa selecionar as cores da paleta **cores** na [janela cores](../windows/colors-window-image-editor-for-icons.md).

1. Selecione o ícone grande ou cursor ou crie um novo ícone ou cursor grande.

1. Escolha uma cor das cores 256 exibidas na paleta **cores** na janela **cores** .

   A cor selecionada se tornará a cor atual na paleta **cores** na janela **cores** .

   > [!NOTE]
   > A paleta inicial usada para imagens de cor de 256 corresponde à paleta retornada pela API do Windows `CreateHalftonePalette`. Todos os ícones destinados ao shell do Windows devem usar essa paleta para evitar cintilações durante a realização da paleta.

### <a name="to-set-a-cursors-hot-spot"></a>Para definir o ponto de acesso de um cursor

O ponto de acesso de um cursor é o ponto para o qual o Windows se refere ao controle da posição do cursor. Por padrão, o ponto de acesso é definido como o canto superior esquerdo do cursor com coordenadas `0,0`. A propriedade **hotspot** na [janela Propriedades](/visualstudio/ide/reference/properties-window) mostra as coordenadas de ponto de acesso.

1. Na [barra de ferramentas do editor de imagem](../windows/toolbar-image-editor-for-icons.md), escolha a ferramenta **definir hotspot** .

1. Selecione o pixel que você deseja atribuir como ponto de acesso do cursor.

   A propriedade **hotspot** na janela **Propriedades** exibe as novas coordenadas.

### <a name="to-create-and-save-a-bitmap-as-a-gif-or-jpeg"></a>Para criar e salvar um bitmap como um. gif ou. jpeg

Quando você cria um bitmap, a imagem é criada no formato de bitmap (. bmp). Você pode, no entanto, salvar a imagem como GIF ou JPEG ou em outros formatos gráficos.

> [!NOTE]
> Esse processo não se aplica a ícones e cursores.

1. Vá até o **arquivo** de menu > **abrir**e, em seguida, selecione **arquivo**.

1. Na **caixa de diálogo novo arquivo**, escolha a **pasta C++ Visual** e, em seguida, selecione **arquivo de bitmap (. bmp)** na caixa **modelos** e selecione **abrir**.

   O bitmap é aberto no **Editor de imagem**.

1. Faça alterações no novo bitmap, conforme necessário.

1. Com o bitmap ainda aberto no **Editor de imagens**, vá para o menu **arquivo** > **Salvar *filename*. bmp como**.

1. Na caixa de diálogo **salvar arquivo como** , digite o nome que você deseja dar ao arquivo e a extensão que denota o formato de arquivo desejado na caixa nome do **arquivo** . Por exemplo, *MyFile. gif*.

   > [!NOTE]
   > Você deve criar ou abrir o bitmap fora do seu projeto para salvá-lo como outro formato de arquivo. Se você criar ou abri-lo em seu projeto, o comando **salvar como** não estará disponível. Para obter mais informações, consulte [exibindo recursos em um arquivo de script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

1. Selecione **Salvar**.

### <a name="to-convert-an-image-from-one-format-to-another"></a>Para converter uma imagem de um formato para outro

Você pode abrir imagens GIF ou JPEG no **Editor de imagens** e salvá-las como bitmaps. Além disso, você pode abrir um arquivo de bitmap e salvá-lo como GIF ou JPEG. As imagens com as quais você trabalha não precisam fazer parte de um projeto para edição no ambiente de desenvolvimento (consulte [edição de imagens autônomas](../windows/editing-an-image-outside-of-a-project-image-editor-for-icons.md)).

1. Abra a imagem no **Editor de imagem**.

1. Vá para o **arquivo** de menu > **salvar o *nome de arquivo* como**.

1. Na caixa de diálogo **salvar arquivo como** , na caixa **nome do arquivo** , digite o nome do arquivo e a extensão que denota o formato desejado.

1. Selecione **Salvar**.

### <a name="to-add-a-new-image-resource-to-an-unmanaged-c-project"></a>Para adicionar um novo recurso de imagem a um C++ projeto não gerenciado

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e escolha **Inserir recurso**. Se você já tiver um recurso de imagem existente no arquivo *. rc* , como um cursor, poderá simplesmente clicar com o botão direito do mouse na pasta **cursor** e selecionar **Insert cursor**.

1. Na [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione o tipo de recurso de imagem que você gostaria de criar (**bitmap**, por exemplo) e escolha **novo**.

   Se um sinal de adição ( **+** ) aparecer ao lado do tipo de recurso de imagem na caixa de diálogo **Inserir recurso** , significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **novo**.

### <a name="to-add-a-new-image-resource-to-a-project-in-a-net-programming-language"></a>Para adicionar um novo recurso de imagem a um projeto em uma linguagem de programação .NET

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse na pasta do projeto (por exemplo, *WindowsApplication1*).

1. No menu de atalho, selecione **Adicionar**e, em seguida, escolha **Adicionar novo item**.

1. No painel **categorias** , expanda a pasta **itens do projeto local** e, em seguida, escolha **recursos**.

1. No painel **modelos** , escolha o tipo de recurso que você deseja adicionar ao seu projeto.

   O recurso é adicionado ao seu projeto no **Gerenciador de soluções** e o recurso é aberto no [Editor de imagem](../windows/image-editor-for-icons.md). Agora você pode usar todas as ferramentas disponíveis no **Editor de imagens** para modificar a imagem. Para obter mais informações sobre como adicionar imagens a um projeto gerenciado, consulte [carregando uma imagem em tempo de design](/dotnet/framework/winforms/controls/how-to-load-a-picture-using-the-designer-windows-forms).

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
<!--
[Converting Bitmaps to Toolbars](../windows/converting-bitmaps-to-toolbars.md)<br/>
[Creating New Toolbars](../windows/creating-new-toolbars.md)<br/>
[Icons](/windows/win32/menurc/icons)<br/>
[Cursors](/windows/win32/menurc/cursors)<br/>-->