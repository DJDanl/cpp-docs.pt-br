---
title: Editor de barra de ferramentas (C++)
ms.date: 02/14/2019
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
ms.openlocfilehash: 9d50561c598f17e251425972590c0663efe6e832
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387885"
---
# <a name="toolbar-editor-c"></a>Editor de barra de ferramentas (C++)

O **barra de ferramentas do Editor** permite que você criar recursos de barra de ferramentas e converter os bitmaps para os recursos da barra de ferramentas. O **barra de ferramentas do Editor** usa uma exibição gráfica para mostrar uma barra de ferramentas e botões que se assemelhem como eles terão uma aparência em um aplicativo concluído.

O **barra de ferramentas do Editor** janela mostra dois modos de exibição de uma imagem de botão, o mesmo que o **Editor de imagens** janela. Uma barra de divisão separa os dois painéis e você pode arrastar a barra de divisão do lado a lado para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção e superior os dois modos de exibição da imagem é a barra de ferramentas do assunto.

![Toolbar Editor](../mfc/media/vctoolbareditor.gif "vcToolbarEditor")<br/>
**Editor de barra de ferramentas**

O **barra de ferramentas do Editor** é semelhante ao **Editor de imagens** na funcionalidade e os itens de menu, ferramentas gráficas e grade de bitmap entre os dois são iguais. Há um comando de menu na **imagem** menu para alternar entre as **barra de ferramentas do Editor** e o **Editor de imagens**. Para obter mais informações sobre como usar o **gráficos** barra de ferramentas **cores** paleta, ou **imagem** menu, consulte [Editor de imagens](../windows/image-editor-for-icons.md).

Você pode criar uma nova barra de ferramentas em um projeto C++, convertendo um bitmap. O gráfico a partir do bitmap que converte as imagens de botão para uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. Imagens podem ser de qualquer tamanho conforme o padrão é 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens do botão na **novo recurso da barra de ferramentas** caixa de diálogo quando você escolhe **barra de ferramentas do Editor** do **imagem** menu enquanto no  **Editor de imagens**.

O **novos recursos da barra de ferramentas** caixa de diálogo permite que você especifique a largura e altura dos botões que você está adicionando a um recurso da barra de ferramentas em um projeto C++. O padrão é 16 × 15 pixels.

Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048, portanto, se você definir a **largura do botão** à *512*, você só pode ter quatro botões. Se você definir a largura como *513*, você pode ter apenas três botões.

O **novos recursos da barra de ferramentas** caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---------------|
|**Largura do botão**|Fornece um espaço para que você insira a largura para os botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas.|
|**Altura do botão**|Fornece um espaço para que você insira a altura dos botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas.|

> [!NOTE]
> As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).

Por padrão, um botão novo ou em branco é exibido na extremidade direita da barra de ferramentas. Você pode mover esse botão antes de editá-lo. Quando você cria um novo botão, o outro botão em branco aparece à direita do botão editado. Quando você salva uma barra de ferramentas, o botão em branco não é salvo.

Um botão de barra de ferramentas tem as seguintes propriedades:

|Propriedade|Descrição|
|--------------|-----------------|
|**ID**|Define a ID do botão. A lista suspensa fornece comuns **ID** nomes.|
|**Largura**|Define a largura do botão. é recomendável 16 pixels.|
|**Altura**|Define a altura do botão. A altura de um botão altera a altura de todos os botões na barra de ferramentas. é recomendável 15 pixels.|
|**Solicitar**|Define a mensagem exibida na barra de status. Adicionando *\n* e adiciona um nome de uma **dica de ferramenta** a esse botão de barra de ferramentas. Para obter mais informações, consulte [criando uma dica de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md).|

**Largura** e **altura** se aplicam a todos os botões. Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048, portanto, se você definir a largura do botão como *512*, você só pode ter quatro botões e se você definir a largura *513*, você pode ter apenas três botões.

## <a name="how-to"></a>Como

O **barra de ferramentas do Editor** permite que você:

### <a name="to-create-new-toolbars"></a>Para criar novas barras de ferramentas

1. Na **exibição de recurso**, clique com botão direito seu *. rc* arquivo e escolha **adicionar recurso**. Se você tiver uma barra de ferramentas em seu *. rc* arquivo, você pode clique com botão direito do **barra de ferramentas** pasta e selecione **Inserir barra de ferramentas**.

1. No **adicionar recurso** caixa de diálogo, selecione **barra de ferramentas** no **tipo de recurso** lista e, em seguida, escolha **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **barra de ferramentas** tipo de recurso, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

### <a name="to-convert-bitmaps-to-toolbar-resources"></a>Para converter os bitmaps aos recursos da barra de ferramentas

1. Abra um recurso de bitmap existente na [Editor de imagens](../windows/image-editor-for-icons.md). Se o bitmap não estiver em seu *. rc* de arquivos, clique com botão direito a *. rc* arquivo e escolha **importação**, em seguida, navegue até o bitmap que você deseja adicionar ao seu *. rc*  do arquivo e selecione **aberto**.

1. Vá ao menu **imagem** > **Editor da barra de ferramentas**.

   O **novos recursos da barra de ferramentas** caixa de diálogo é exibida. Você pode alterar a largura e altura das imagens do ícone para coincidir com o bitmap. A imagem da barra de ferramentas, em seguida, é exibida na **barra de ferramentas do Editor**.

1. Para concluir a conversão, altere o comando **identificação** do botão usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Digite o novo *identificação* ou selecione um **ID** na lista suspensa.

   > [!TIP]
   > O **propriedades** janela contém um botão de pino na barra de título e selecionar esse habilita ou desabilita **ocultar automaticamente** para a janela. Para percorrer todas as propriedades do botão de barra de ferramentas sem precisar reabrir janelas de propriedade individuais, ative **ocultar automaticamente** desativado para que o **propriedades** janela permaneça estacionário.

   Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o [janela de propriedades](/visualstudio/ide/reference/properties-window).

### <a name="to-manage-toolbar-buttons"></a>Para gerenciar os botões da barra de ferramentas

#### <a name="to-create-a-new-toolbar-button"></a>Para criar um novo botão de barra de ferramentas

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources) expanda a pasta de recurso (por exemplo, *Project1.rc*).

1. Expanda o **barra de ferramentas** pasta e selecione uma barra de ferramentas para editar, siga um destes procedimentos:

   - Atribua uma ID para o botão em branco na extremidade direita da barra de ferramentas. Você pode fazer isso editando o **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window). Por exemplo, você talvez queira dar a mesma ID de uma opção de menu a um botão de barra de ferramentas. Nesse caso, use a caixa de listagem suspensa para selecionar o **ID** da opção de menu.

   - Selecione o botão em branco na extremidade direita da barra de ferramentas do **modo de exibição da barra de ferramentas** painel e começar a desenhar. Uma ID de comando do botão padrão é atribuída (ID_BUTTON\<n >).

#### <a name="to-add-an-image-to-a-toolbar-as-a-button"></a>Para adicionar uma imagem para uma barra de ferramentas, como um botão

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), abra a barra de ferramentas clicando duas vezes nele.

1. Em seguida, abra a imagem que você deseja adicionar à barra de ferramentas.

   > [!NOTE]
   > Se você abrir a imagem no Visual Studio, ele será aberto na **Editor de imagens**. Você também pode abrir a imagem em outros programas de elementos gráficos.

1. Vá ao menu **edite** > **cópia**.

1. Alterne para sua barra de ferramentas selecionando seu guia na parte superior da janela de origem.

1. Vá ao menu **edite** > **colar**.

   A imagem será exibida na barra de ferramentas, como um novo botão.

#### <a name="to-move-a-toolbar-button"></a>Para mover um botão de barra de ferramentas

No **modo de exibição da barra de ferramentas** painel, arraste o botão que você deseja mover para o novo local na barra de ferramentas.

- Para copiar os botões da barra de ferramentas, mantenha pressionada a **Ctrl** chave e, na **modo de exibição da barra de ferramentas** painel, arraste o botão para seu novo local na barra de ferramentas ou em um local na barra de ferramentas do outro.

- Para excluir um botão de barra de ferramentas, selecione o botão de barra de ferramentas e arraste-o da barra de ferramentas.

- Para inserir ou remover o espaço entre botões em uma barra de ferramentas, ou arrastá-los longe ou em direção uma outra na barra de ferramentas.

|Ação|Etapa|
|------|------|
|Para inserir um espaço antes de um botão que não é seguido por um espaço|Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.|
|Para inserir um espaço antes de um botão que é seguido por um espaço e manter o espaço à direita|Arraste o botão até que a borda direita ou inferior é simplesmente tocar no botão Avançar ou apenas se sobrepõe a ela.|
|Para inserir um espaço antes de um botão que é seguido por um espaço e fechar aquele espaço seguir|Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.|
|Para remover um espaço entre botões em uma barra de ferramentas|Arraste o botão em um lado do espaço para o botão do outro lado do espaço até que ele se sobrepõe no botão Avançar sobre na metade.|

> [!NOTE]
> Se não há nenhum espaço no lado do botão que você está arrastando longe do e arrastar o botão metade após o botão adjacente, o **barra de ferramentas do Editor** insere um espaço no lado oposto do botão que você está arrastando.

#### <a name="to-change-the-properties-of-a-toolbar-button"></a>Para alterar as propriedades de um botão de barra de ferramentas

1. Em um projeto do C++, selecione o botão de barra de ferramentas.

1. Digite a nova ID na **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window), ou use a lista suspensa para selecionar um novo **ID**.

#### <a name="to-create-a-tool-tip-for-a-toolbar-button"></a>Para criar uma dica de ferramenta para um botão de barra de ferramentas

1. Selecione o botão de barra de ferramentas.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), no **Prompt** campo, adicione uma descrição do botão de barra de status e depois da mensagem, adicione `\n` e o nome de dica de ferramenta.

Por exemplo, para ver a dica de ferramenta para o **Print** botão na **WordPad**:

1. Abra **WordPad**.

1. Passe o ponteiro do mouse sobre o **Print** botão da barra de ferramentas e observe a palavra `Print` agora está flutuando sob o ponteiro do mouse.

1. Observe a barra de status na parte inferior a **WordPad** janela e observe que agora mostra o texto `Prints the active document`.

`Print` é o nome de dica de ferramenta e `Prints the active document` é a descrição do botão de barra de status.

Se você quiser que esse efeito usando o **barra de ferramentas do Editor**, defina o **Prompt** propriedade `Prints the active document\nPrint`.

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)
<!--
[Menus and Other Resources](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)<br/>
[Toolbar Button Properties](../windows/toolbar-button-properties.md)<br/>-->
