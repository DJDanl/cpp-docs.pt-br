---
title: Editor de barra de ferramentas (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.toolbar.F1
- vc.editors.toolbar
- vc.editors.newtoolbarresource
helpviewer_keywords:
- resource editors [C++], Toolbar editor
- editors, toolbars
- toolbars [C++], editing
- Toolbar editor
- toolbars [C++], creating
- Toolbar editor [C++], creating new toolbars
- Insert Resource
- bitmaps [C++], converting to toolbars
- Toolbar editor [C++], converting bitmaps
- toolbars [C++], converting bitmaps
- New Toolbar Resource dialog box [C++]
- buttons [C++], custom toolbars
- toolbar buttons [C++], editing
- buttons
- toolbar buttons [C++], creating
- Toolbar editor [C++], creating buttons
- toolbar buttons [C++], button image
- toolbar buttons [C++], creating
- toolbar buttons (in Toolbar editor)
- toolbar buttons [C++], moving
- Toolbar editor [C++], moving buttons
- Toolbar editor [C++], copying buttons
- toolbars [C++], copying buttons
- toolbar buttons [C++], copying
- toolbar buttons [C++], deleting
- Toolbar editor [C++], deleting buttons
- Toolbar editor [C++], spacing toolbar buttons
- toolbar buttons [C++], space between buttons
- toolbar controls [MFC], command ID
- toolbar buttons [C++], setting properties
- Toolbar editor [C++], toolbar button properties
- command IDs, toolbar buttons
- size, toolbar buttons
- toolbar buttons [C++], setting properties
- Toolbar editor [C++], toolbar button properties
- status bars [C++], active toolbar button text
- command IDs, toolbar buttons
- width, toolbar buttons
- tool tips [C++], adding to toolbar buttons
- "\n in tool tip"
- toolbar buttons [C++], tool tips
- buttons [C++], tool tips
- Toolbar editor [C++], creating tool tips
ms.assetid: aa9f0adf-60f6-4f79-ab05-bc330f15ec43
ms.openlocfilehash: 61b4d3ba6fc70e78c6f794528822eb66fb94de7e
ms.sourcegitcommit: 5a7dbd640376e13379f5d5b2cf66c4842e5e737b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/08/2019
ms.locfileid: "55905778"
---
# <a name="toolbar-editor-c"></a>Editor de barra de ferramentas (C++)

O **barra de ferramentas** editor permite que você criar recursos de barra de ferramentas do C++ e converter os bitmaps para os recursos da barra de ferramentas. O **barra de ferramentas** editor usa uma exibição gráfica para mostrar uma barra de ferramentas e botões que se assemelhem como eles terão uma aparência em um aplicativo concluído.

O **barra de ferramentas** janela do editor mostra dois modos de exibição de uma imagem de botão, o mesmo que a janela do editor de imagem. Uma barra de divisão separa os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção. Acima de dois modos de exibição da imagem é a barra de ferramentas do assunto.

![Toolbar Editor](../mfc/media/vctoolbareditor.gif "vcToolbarEditor") Toolbar Editor

O **barra de ferramentas** editor é semelhante ao **imagem** editor na funcionalidade. Os itens de menu, ferramentas gráficas e grade de bitmap são iguais do **imagem** editor. Há um comando de menu na **imagem** menu para permitir que você alterne entre a **barra de ferramentas** editor e o **imagem** editor. Para obter mais informações sobre como usar o **gráficos** barra de ferramentas **cores** paleta, ou **imagem** menu, consulte [Editor de imagens](../windows/image-editor-for-icons.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

Com o **barra de ferramentas** editor, você pode:

## <a name="create-new-toolbars"></a>Criar novas barras de ferramentas

1. Na **Resource** exibir, clique com botão direito seu arquivo. RC e escolha **adicionar recurso** no menu de atalho. (Se você tiver uma barra de ferramentas em seu arquivo. RC, você pode simplesmente com o botão direito do **barra de ferramentas** pasta e selecione **barra de ferramentas Insert** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **adicionar recurso** caixa de diálogo, selecione **barra de ferramentas** no **tipo de recurso** lista e, em seguida, escolha **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **barra de ferramentas** tipo de recurso, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

## <a name="convert-bitmaps-to-toolbar-resources"></a>Converter bitmaps em recursos da barra de ferramentas

Você pode criar uma nova barra de ferramentas em um projeto C++, convertendo um bitmap. O gráfico a partir do bitmap que converte as imagens de botão para uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. Imagens podem ser de qualquer tamanho conforme o padrão é 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens do botão na **novos recursos da barra de ferramentas** caixa de diálogo quando você escolhe **barra de ferramentas do Editor** do **imagem** menu enquanto estiver no editor de imagens.

O **novos recursos da barra de ferramentas** caixa de diálogo permite que você especifique a largura e altura dos botões que você está adicionando a um recurso da barra de ferramentas em um projeto C++. O padrão é 16 × 15 pixels.

Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a **largura do botão** para 512, você só pode ter quatro botões. Se você definir a largura como 513, você só pode ter três botões.

A caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Largura do botão**|Fornece um espaço para que você insira a largura para os botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).|
|**Altura do botão**|Fornece um espaço para que você insira a altura dos botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).|

### <a name="to-convert-bitmaps-to-a-toolbar"></a>Para converter os bitmaps em uma barra de ferramentas

1. Abra um recurso de bitmap existente na [editor de imagens](../windows/image-editor-for-icons.md). (Se o bitmap não estiver em seu arquivo. RC, clique com botão direito no arquivo. RC, escolha **importação** no menu de atalho, navegue até o bitmap que você deseja adicionar ao seu arquivo. RC, e selecione **abrir**.)

1. Dos **imagem** menu, escolha **Editor de barra de ferramentas**.

   O **novos recursos da barra de ferramentas** caixa de diálogo é exibida. Você pode alterar a largura e altura das imagens do ícone para coincidir com o bitmap. A imagem da barra de ferramentas, em seguida, é exibida no editor de barra de ferramentas.

1. Para concluir a conversão, altere o comando **identificação** do botão usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Digite o novo **identificação** ou selecione um **ID** na lista suspensa.

   > [!TIP]
   > O **propriedades** janela contém um botão de pino na barra de título. Selecione este botão habilita ou desabilita **ocultar automaticamente** para a janela. Para percorrer rapidamente todas as propriedades do botão de barra de ferramentas sem precisar reabrir janelas de propriedade individuais, ative **ocultar automaticamente** desativado para que o **propriedades** janela permaneça estacionário.

Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o [janela de propriedades](/visualstudio/ide/reference/properties-window).

## <a name="create-move-and-edit-toolbar-buttons"></a>Criar, mover e editar os botões de barra de ferramentas

Você pode facilmente criar, mover, copiar e editar os botões de barra de ferramentas.

Por padrão, um botão novo ou em branco é exibido na extremidade direita da barra de ferramentas. Você pode mover esse botão antes de editá-lo. Quando você cria um novo botão, o outro botão em branco aparece à direita do botão editado. Quando você salva uma barra de ferramentas, o botão em branco não é salvo.

As propriedades de um botão de barra de ferramentas são:

|Propriedade|Descrição|
|--------------|-----------------|
|**ID**|Define a ID do botão. A lista suspensa fornece comuns **ID** nomes.|
|**Largura**|Define a largura do botão. é recomendável 16 pixels.|
|**Altura**|Define a altura do botão. A altura de um botão altera a altura de todos os botões na barra de ferramentas. é recomendável 15 pixels.|
|**Solicitar**|Define a mensagem exibida na barra de status. Adicionar um nome e \n adiciona uma dica de ferramenta a esse botão de barra de ferramentas. Para obter mais informações, consulte [criando uma dica de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md).|

**Largura** e **altura** se aplicam a todos os botões. Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a largura do botão como 512, você só pode ter quatro botões e se você definir a largura como 513, você pode ter apenas três botões.

Consulte as seguintes ações:

### <a name="to-create-a-new-toolbar-button"></a>Para criar um novo botão de barra de ferramentas

1. Na [exibição de recurso](../windows/resource-view-window.md) expanda a pasta de recurso (por exemplo, *Project1.rc*).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. Expanda o **barra de ferramentas** pasta e selecione uma barra de ferramentas para editar.

1. Atribua uma ID para o botão em branco na extremidade direita da barra de ferramentas. Você pode fazer isso editando o **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window). Por exemplo, você talvez queira dar a mesma ID de uma opção de menu a um botão de barra de ferramentas. Nesse caso, use a caixa de listagem suspensa para selecionar o **ID** da opção de menu.

   -ou-

   Selecione o botão em branco na extremidade direita da barra de ferramentas (na **modo de exibição da barra de ferramentas** painel) e começar a desenhar. Uma ID de comando do botão padrão é atribuída (ID_BUTTON\<n >).

Você pode, também, copiar e colar uma imagem em uma barra de ferramentas, como um novo botão.

### <a name="to-add-an-image-to-a-toolbar-as-a-button"></a>Para adicionar uma imagem para uma barra de ferramentas, como um botão

1. Na [exibição de recurso](../windows/resource-view-window.md), abra a barra de ferramentas clicando duas vezes nele.

1. Em seguida, abra a imagem que você deseja adicionar à barra de ferramentas.

   > [!NOTE]
   > Se você abrir a imagem no Visual Studio, ele será aberto na **imagem** editor. Você também pode abrir a imagem em outros programas de elementos gráficos.

1. Dos **edite** menu, escolha **cópia**.

1. Alterne para sua barra de ferramentas selecionando seu guia na parte superior da janela de origem.

1. Dos **edite** menu, escolha **colar**.

   A imagem será exibida na barra de ferramentas, como um novo botão.

### <a name="to-move-a-toolbar-button"></a>Para mover um botão de barra de ferramentas

No **modo de exibição da barra de ferramentas** painel, arraste o botão que você deseja mover para o novo local na barra de ferramentas.

### <a name="to-copy-buttons-from-a-toolbar"></a>Para copiar os botões da barra de ferramentas

1. Mantenha pressionada a **Ctrl** chave.

1. No **modo de exibição da barra de ferramentas** painel, arraste o botão para seu novo local na barra de ferramentas ou em um local na barra de ferramentas do outro.

### <a name="to-delete-a-toolbar-button"></a>Para excluir um botão de barra de ferramentas

Selecione o botão de barra de ferramentas e arraste-o da barra de ferramentas.

### <a name="to-insert-or-remove-space-between-buttons-on-a-toolbar"></a>Para inserir ou remover um espaço entre botões em uma barra de ferramentas

Em geral, para inserir um espaço entre botões, arraste-os dos outros na barra de ferramentas. Para remover espaço, arraste-os em direção uns aos outros.

|Ação|Etapa|
|------|------|
|Para inserir um espaço antes de um botão que não é seguido por um espaço|Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.|
|Para inserir um espaço antes de um botão que é seguido por um espaço e manter o espaço à direita|Arraste o botão até que a borda direita ou inferior é simplesmente tocar no botão Avançar ou apenas se sobrepõe a ela.|
|Para inserir um espaço antes de um botão que é seguido por um espaço e fechar aquele espaço seguir|Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.|
|Para remover um espaço entre botões em uma barra de ferramentas|Arraste o botão em um lado do espaço para o botão do outro lado do espaço até que ele se sobrepõe no botão Avançar sobre na metade.|

> [!NOTE]
> Se não há nenhum espaço no lado do botão que você está arrastando longe do e arrastar o botão metade após o botão adjacente, o **barra de ferramentas** editor também insere um espaço no lado oposto do botão que você está arrastando.

### <a name="to-change-the-properties-of-a-toolbar-button"></a>Para alterar as propriedades de um botão de barra de ferramentas

1. Em um projeto do C++, selecione o botão de barra de ferramentas.

1. Digite a nova ID na **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window), ou use a lista suspensa para selecionar um novo **ID**.

### <a name="to-create-a-tool-tip-for-a-toolbar-button"></a>Para criar uma dica de ferramenta para um botão de barra de ferramentas

1. Selecione o botão de barra de ferramentas.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), no **Prompt** campo de propriedade, adicione uma descrição do botão de barra de status; após a mensagem, adicione `\n` e o nome de dica de ferramenta.

Um exemplo comum de uma dica de ferramenta é o **Print** botão na **WordPad**:

1. Abra **WordPad**.

1. Passe o ponteiro do mouse sobre o **impressão** botão da barra de ferramentas.

1. Observe que a palavra `Print` agora está flutuando sob o ponteiro do mouse.

1. Observe a barra de status (na parte inferior a **WordPad** janela)-Observe que ele agora mostra o texto `Prints the active document`.

O `Print` na **etapa 3** é o "nome de dica de ferramenta" e o `Prints the active document` da **etapa 4** é a "Descrição do botão da barra de status de".

Se você quiser que esse efeito usando o **barra de ferramentas** editor, defina as **Prompt** propriedade `Prints the active document\nPrint`.

> [!NOTE]
> Você pode editar o texto de aviso usando o [janela de propriedades](/visualstudio/ide/reference/properties-window).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Menus e outros recursos](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)<br/>
[Propriedades do botão de barra de ferramentas](../windows/toolbar-button-properties.md)<br/>
