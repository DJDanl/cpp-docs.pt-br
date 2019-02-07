---
title: 'Ícones e cursores: Recursos de imagem para exibir dispositivos (C++ Editor de imagens para ícones)'
ms.date: 11/04/2016
f1_keywords:
- vc.editors.icon
- vc.editors.newimagetype
- vc.editors.customimage
- vc.editors.opendeviceimage
- vc.editors.image.editing
helpviewer_keywords:
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
ms.assetid: 8f0809a8-0cf0-4da9-b23d-51f28bf15f5b
ms.openlocfilehash: 027c3c0380a73c624432bbe45758b3296732949a
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55849939"
---
# <a name="icons-and-cursors-image-resources-for-display-devices-c-image-editor-for-icons"></a>Ícones e cursores: Recursos de imagem para exibir dispositivos (C++ Editor de imagens para ícones)

Ícones e cursores são os recursos gráficos que podem conter várias imagens em tamanhos diferentes e esquemas para diferentes tipos de dispositivos de exibição de cores. Além disso, um cursor tem um "ponto de acesso", o local do Windows usa para acompanhar sua posição. Ícones e cursores são criados e editados usando o **imagem** editor, assim como bitmaps e outras imagens.

Quando você cria um novo ícone ou cursor, o **imagem** editor primeiro cria uma imagem de um tipo padrão. Inicialmente, a imagem é preenchida com a cor da tela (transparente). Se a imagem é um cursor, o ponto de acesso é inicialmente o canto superior esquerdo (coordenadas 0,0).

Por padrão, o **imagem** editor dá suporte à criação de imagens adicionais para os dispositivos mostrados na tabela a seguir. Você pode criar imagens para outros dispositivos, digitando parâmetros de largura, altura e contagem de cor para o [caixa de diálogo imagem personalizada](custom-image-dialog-box-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

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

## <a name="create-a-device-image-icon-or-cursor"></a>Criar uma imagem de dispositivo (ícone ou cursor)

Quando você cria um novo ícone ou cursor, o **imagem** editor primeiro cria uma imagem em um estilo específico (32 × 32, 16 cores para ícones e 32 × 32, monocromo para cursores). Você pode, em seguida, adicionar imagens em tamanhos diferentes e estilos para o ícone inicial ou o cursor e edite cada imagem adicional, conforme necessário, para os dispositivos de exibição diferentes. Você também pode editar uma imagem usando uma operação de copiar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa de gráfico.

Quando você abre o recurso de ícone ou cursor na [editor de imagens](../windows/image-editor-for-icons.md), a imagem a maioria dos combinar o dispositivo de exibição atual é aberta por padrão.

### <a name="new-ltdevicegt-image-type-dialog-box"></a>Novos &lt;dispositivo&gt; caixa de diálogo de tipo de imagem

O **New &lt;dispositivo&gt; tipo de imagem** caixa de diálogo permite que você crie uma nova imagem de dispositivo de um tipo especificado. Para abrir o **New \<dispositivo > imagem** caixa de diálogo, selecione **novo tipo de imagem** sobre a **imagem** menu. As seguintes propriedades incluídas estão **tipo de imagem de destino** e **personalizado**.

#### <a name="target-image-type"></a>Tipo de imagem de destino

Lista os tipos de imagem disponível. Selecione o tipo de imagem que você deseja abrir:

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

#### <a name="custom"></a>Personalizado

Abre o **imagem personalizada** caixa de diálogo na qual você pode criar uma nova imagem com um tamanho personalizado e o número de cores.

O **imagem personalizada** caixa de diálogo permite que você crie uma nova imagem com um tamanho personalizado e o número de cores. As propriedades a seguir incluídas são:

|Propriedade|Descrição|
|---|---|
|**Largura**|Fornece um espaço para que você insira a largura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Altura**|Fornece um espaço para que você insira a altura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Cores**|Fornece um espaço para que você escolha o número de cores para a imagem personalizada: 2, 16 ou 256.|

### <a name="open-ltdevicegt-image-dialog-box"></a>Abra &lt;dispositivo&gt; caixa de diálogo imagem

Use o **abra &lt;dispositivo&gt; imagem** caixa de diálogo para abrir imagens de dispositivo em projetos do C++. Ele lista as imagens de dispositivo existentes no recurso atual (imagens que fazem parte do recurso atual). É a seguinte propriedade incluída:

|Propriedade|Descrição|
|---|---|
|**Imagens atuais**|Lista as imagens incluídas no recurso. Selecione o tipo de imagem que você deseja abrir.|

### <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**. Para ícones, essa ação cria um recurso de ícone com um 32 × 32, o ícone de 16 cores. Para cursores de 32 × 32, imagem monocromática de (2 cores) é criada.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

## <a name="add-an-image-for-a-different-display-device"></a>Adicionar uma imagem para um dispositivo de exibição diferente

1. No **imagem** menu, selecione **nova imagem de dispositivo** (ou clique com botão direito no **Editor de imagens** painel e escolha **nova imagem de dispositivo** da menu de atalho).

1. Selecione o tipo de imagem que você deseja adicionar. Você também pode selecionar **personalizado** para criar um ícone cujo tamanho não está disponível na lista padrão.

## <a name="copy-a-device-image"></a>Copiar uma imagem de dispositivo

1. Sobre o **imagem** menu, selecione **Abrir imagem do dispositivo** e escolha uma imagem da lista de imagens atual. Por exemplo, escolha 32 × 32, versão de 16 cores de um ícone.

1. Copie a imagem do ícone exibido no momento (**Ctrl**+**C**).

1. Abrir uma imagem diferente do ícone em outro **Editor de imagens** janela. Por exemplo, abra o 16 × 16, versão de 16 cores do ícone.

1. Cole a imagem de ícone (**Ctrl**+**V**) de um **Editor de imagens** janela para outra. Se você estiver colando um tamanho maior em um tamanho menor, você pode usar os identificadores de ícone para redimensionar a imagem.

## <a name="delete-a-device-image"></a>Excluir uma imagem de dispositivo

Enquanto a imagem do ícone é exibida na **imagem** editor, selecione **excluir imagem do dispositivo** do **imagem** menu. Quando você exclui a última imagem de ícone no recurso, o recurso também é excluído.

   > [!NOTE]
   > Quando você pressiona o **/DEL** chave, as imagens e cores que você desenhou em um ícone serão excluídas, mas o ícone permanecerá; agora é possível recriá-lo. Se você pressionar **/DEL** por engano, você pode pressionar **Ctrl**+**Z** desfazer a ação.

## <a name="create-transparent-or-inverse-regions-in-device-images"></a>Criar regiões transparentes ou inversas em imagens de dispositivo

No [editor de imagens](../windows/image-editor-for-icons.md), a imagem de ícone ou cursor inicial tem um atributo transparente. Embora as imagens de ícone e cursor são retangulares, muitos não aparecem isso porque as partes da imagem são transparentes; mostra a imagem subjacente na tela por meio do ícone ou cursor. Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida. Criar esse efeito, definindo a cor da tela e as cores invertidas na [janela de cores](../windows/colors-window-image-editor-for-icons.md).

As cores da tela e o inverso é aplicar a ícones e cursores da forma e a imagem derivada de cor ou atribuir regiões inversos. As cores indicam partes da imagem que têm esses atributos. Você pode alterar as cores que representam os atributos de cor da tela e cor inverso no modo de edição. Essas alterações não afetam a aparência do ícone ou cursor em seu aplicativo.

> [!NOTE]
> As caixas de diálogo e os comandos de menu vistos podem ser diferentes daqueles descritos na **Ajuda**, dependendo da edição ou das configurações ativas. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

### <a name="to-create-transparent-or-inverse-regions"></a>Para criar regiões transparentes ou inversas

1. No **cores** janela, selecione a **cor da tela** seletor ou o **inverso cor** seletor.

1. Aplique a tela ou cores invertidas em sua imagem usando uma ferramenta de desenho. Para obter mais informações sobre ferramentas de desenho, consulte [usando uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md).

### <a name="to-change-the-screen-or-inverse-color"></a>Para alterar a cor da tela ou inverso

1. Selecione o **cores da tela** seletor ou o **inverso cor** seletor.

1. Escolha uma cor na **cores** paleta na **cores** janela.

   A cor complementar é atribuído automaticamente para o seletor de outro.

   > [!TIP]
   > Se você clicar duas vezes o **cores da tela** ou **inverso cor** seletor, o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) é exibida.

## <a name="use-the-256-color-palette"></a>Use a paleta de 256 cores

Usando o **imagem** editor, ícones e cursores podem ser dimensionados grandes (64 × 64) com uma paleta de 256 cores à sua escolha. Depois de criar o recurso, um estilo de imagem do dispositivo é selecionado.

### <a name="to-create-a-256-color-icon-or-cursor"></a>Para criar um ícone de 256 cores ou cursor

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**.

1. Sobre o **imagem** menu, selecione **nova imagem de dispositivo**.

1. Selecione o estilo de imagem de 256 cores que você deseja.

### <a name="to-choose-a-color-from-the-256-color-palette-for-large-icons"></a>Para escolher uma cor da paleta de 256 cores de ícones grandes

Para desenhar com uma seleção da paleta de 256 cores, você precisará selecionar as cores do **cores** paleta na [janela cores](../windows/colors-window-image-editor-for-icons.md).

1. Selecione o ícone grande ou cursor ou criar um novo ícone grande ou cursor.

1. Escolha uma cor de 256 cores exibidas nos **cores** paleta na **cores** janela.

   A cor selecionada se tornará a cor atual na **cores** paleta na **cores** janela.

   > [!NOTE]
   > A paleta inicial usada para imagens de 256 cores corresponde a paleta retornada pelo `CreateHalftonePalette` API do Windows. Todos os ícones destinados para o shell do Windows devem usar essa paleta para evitar a cintilação durante a realização da paleta.

## <a name="set-a-cursor39s-hot-spot"></a>Definir um cursor&#39;s do ponto de acesso

O ponto de acesso de um cursor é o ponto de para qual Windows refere-se em controle de posição do cursor. Por padrão, o ponto de acesso é definido para o canto superior esquerdo do cursor (coordenadas 0,0). O **Hotspot** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window) mostra as coordenadas de ponto de acesso.

### <a name="to-set-a-cursors-hot-spot"></a>Para definir o ponto de acesso de um cursor

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md), escolha o **defina ponto de acesso** ferramenta.

1. Selecione o pixel que você deseja atribuir como o ponto de acesso do cursor.

   O **Hotspot** propriedade no **propriedades** janela exibe as novas coordenadas.

   > [!TIP]
   > Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Menu imagem](../windows/image-menu-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Ícones](/windows/desktop/menurc/icons)<br/>
[Cursores](/windows/desktop/menurc/cursors)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
