---
title: Editor de barraC++de ferramentas ()
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
ms.openlocfilehash: 72c42a06da8276d118c6c204f838ed4b31d142b9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514683"
---
# <a name="toolbar-editor-c"></a>Editor de barraC++de ferramentas ()

O **Editor de barra de ferramentas** permite que você crie recursos da barra de ferramentas e converta bitmaps em recursos da barra de ferramentas. O **Editor da barra de ferramentas** usa uma exibição gráfica para mostrar uma barra de ferramentas e botões que se assemelham exatamente à forma como eles aparecerão em um aplicativo concluído.

A janela **Editor da barra de ferramentas** mostra dois modos de exibição de uma imagem de botão, o mesmo que a janela do editor de **imagens** . Uma barra de divisão separa os dois painéis e você pode arrastar a barra de divisão do lado a lado para alterar os tamanhos relativos dos painéis. O painel ativo exibe uma borda de seleção e, acima, as duas exibições da imagem são a barra de ferramentas do assunto.

![Editor de barra de ferramentas](../mfc/media/vctoolbareditor.gif "vcToolbarEditor")<br/>
**Editor de barra de ferramentas**

O **Editor de barra de ferramentas** é semelhante ao **Editor de imagens** na funcionalidade e os itens de menu, as ferramentas gráficas e a grade de bitmap entre os dois são os mesmos. Há um comando de menu no menu **imagem** para alternar entre o **Editor de barra de ferramentas** e o editor de **imagem**. Para obter mais informações sobre como usar a barra de ferramentas de **gráficos** , a paleta de **cores** ou o menu **imagem** , consulte [Editor de imagem](../windows/image-editor-for-icons.md).

Você pode criar uma nova barra de ferramentas C++ em um projeto convertendo um bitmap. O gráfico do bitmap é convertido para as imagens de botão de uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. As imagens podem ter qualquer tamanho, pois o padrão tem 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens de botão na caixa de diálogo **novo recurso de barra de ferramentas** ao escolher **Editor de barra de ferramentas** no menu **imagem** enquanto estiver no **Editor de imagem**.

A caixa de diálogo **novo recurso de barra de ferramentas** permite especificar a largura e a altura dos botões que você está adicionando a um recurso C++ da barra de ferramentas em um projeto. O padrão é 16 × 15 pixels.

Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048, portanto, se você definir a **largura do botão** como *512*, só poderá ter quatro botões. Se você definir a largura como *513*, só poderá ter três botões.

A caixa de diálogo **novo recurso de barra de ferramentas** tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---------------|
|**Largura do botão**|Fornece um espaço para inserir a largura dos botões da barra de ferramentas que você está convertendo de um recurso de bitmap em um recurso da barra de ferramentas.|
|**Altura do botão**|Fornece um espaço para inserir a altura dos botões da barra de ferramentas que você está convertendo de um recurso de bitmap em um recurso da barra de ferramentas.|

> [!NOTE]
> As imagens são cortadas para a largura e a altura especificadas, e as cores são ajustadas para usar cores de barra de ferramentas padrão (16 cores).

Por padrão, um botão novo ou em branco é exibido na extremidade direita da barra de ferramentas. Você pode mover esse botão antes de editá-lo. Quando você cria um novo botão, outro botão em branco é exibido à direita do botão editado. Quando você salva uma barra de ferramentas, o botão em branco não é salvo.

Um botão da barra de ferramentas tem as seguintes propriedades:

|Propriedade|Descrição|
|--------------|-----------------|
|**ID**|Define a ID do botão. A lista suspensa fornece nomes de **ID** comuns.|
|**Largura**|Define a largura do botão. é recomendável 16 pixels.|
|**Altura**|Define a altura do botão. A altura de um botão altera a altura de todos os botões na barra de ferramentas. são recomendados 15 pixels.|
|**Aviso**|Define a mensagem exibida na barra de status. Adicionar *\n* e um nome adiciona uma **dica de ferramenta** a esse botão da barra de ferramentas. Para obter mais informações, consulte [criando uma dica de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md).|

A **largura** e a **altura** se aplicam a todos os botões. Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048, portanto, se você definir a largura do botão como *512*, só poderá ter quatro botões e, se definir a largura como *513*, só poderá ter três botões.

## <a name="how-to"></a>Como

O **Editor de barra de ferramentas** permite que você:

### <a name="to-create-new-toolbars"></a>Para criar novas barras de ferramentas

1. Em **modo de exibição de recursos**, clique com o botão direito do mouse no arquivo *. rc* e escolha **Adicionar recurso**. Se você tiver uma barra de ferramentas existente em seu arquivo *. rc* , poderá clicar com o botão direito do mouse na pasta **Toolbar** e selecionar **Inserir barra de ferramentas**.

1. Na caixa de diálogo **Adicionar recurso** , selecione **barra de ferramentas** na lista **tipo de recurso** e escolha **novo**.

   Se um sinal de adição **+** () aparecer ao lado do tipo de recurso **da barra de ferramentas** , isso significará que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **novo**.

### <a name="to-convert-bitmaps-to-toolbar-resources"></a>Para converter bitmaps em recursos da barra de ferramentas

1. Abra um recurso de bitmap existente no [Editor de imagens](../windows/image-editor-for-icons.md). Se o bitmap ainda não estiver no arquivo *. rc* , clique com o botão direito do mouse no arquivo *. rc* e escolha **importar**e, em seguida, navegue até o bitmap que você deseja adicionar ao arquivo *. rc* e selecione **abrir**.

1. Acesse o menu**Editor da barra de ferramentas**de **imagem** > .

   A caixa de diálogo **novo recurso de barra de ferramentas** é exibida. Você pode alterar a largura e a altura das imagens de ícone para corresponder ao bitmap. A imagem da barra de ferramentas é exibida no **Editor da barra de ferramentas**.

1. Para concluir a conversão, altere a **ID** de comando do botão usando o [janela Propriedades](/visualstudio/ide/reference/properties-window). Digite a nova *ID* ou selecione uma **ID** na lista suspensa.

   > [!TIP]
   > A janela **Propriedades** contém um botão de pino na barra de título e a seleção habilita ou desabilita **ocultar automaticamente** para a janela. Para percorrer todas as propriedades do botão da barra de ferramentas sem precisar reabrir as janelas de propriedades individuais, desative **ocultar automaticamente** para que a janela **Propriedades** permaneça estacionário.

   Você também pode alterar as IDs de comando dos botões na nova barra de ferramentas usando o [janela Propriedades](/visualstudio/ide/reference/properties-window).

### <a name="to-manage-toolbar-buttons"></a>Para gerenciar botões da barra de ferramentas

#### <a name="to-create-a-new-toolbar-button"></a>Para criar um novo botão da barra de ferramentas

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) expanda a pasta de recursos (por exemplo, *Projeto1. rc*).

1. Expanda a pasta **barra de ferramentas** e selecione uma barra de ferramentas para editar e siga um destes procedimentos:

   - Atribua uma ID ao botão em branco na extremidade direita da barra de ferramentas. Você pode fazer isso editando a propriedade **ID** na [janela Propriedades](/visualstudio/ide/reference/properties-window). Por exemplo, você pode desejar dar um botão de barra de ferramentas com a mesma ID como uma opção de menu. Nesse caso, use a caixa de listagem suspensa para selecionar a **ID** da opção de menu.

   - Selecione o botão em branco na extremidade direita da barra de ferramentas no painel **exibição da barra de ferramentas** e comece a desenhar. Uma ID de comando de botão padrão é atribuída\<(ID_BUTTON n >).

#### <a name="to-add-an-image-to-a-toolbar-as-a-button"></a>Para adicionar uma imagem a uma barra de ferramentas como um botão

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), abra a barra de ferramentas clicando duas vezes nela.

1. Em seguida, abra a imagem que você deseja adicionar à sua barra de ferramentas.

   > [!NOTE]
   > Se você abrir a imagem no Visual Studio, ela será aberta no **Editor de imagem**. Você também pode abrir a imagem em outros programas gráficos.

1. Vá para o menu **Editar** > **cópia**.

1. Alterne para a barra de ferramentas selecionando sua guia na parte superior da janela de origem.

1. Vá para o menu **Editar** > **colar**.

   A imagem será exibida na barra de ferramentas como um novo botão.

#### <a name="to-move-a-toolbar-button"></a>Para mover um botão da barra de ferramentas

No painel **exibição da barra de ferramentas** , arraste o botão que você deseja mover para o novo local na barra de ferramentas.

- Para copiar botões de uma barra de ferramentas, mantenha pressionada a tecla **Ctrl** e, no painel **exibição da barra de ferramentas** , arraste o botão para o novo local na barra de ferramentas ou para um local em outra barra de ferramentas.

- Para excluir um botão da barra de ferramentas, selecione o botão da barra de ferramentas e arraste-o para fora da barra de ferramentas.

- Para inserir ou remover espaço entre os botões em uma barra de ferramentas, arraste-os para longe ou para outro na barra de ferramentas.

|Ação|Etapa|
|------|------|
|Para inserir um espaço antes de um botão que não é seguido por um espaço|Arraste o botão para a direita ou para baixo até que ele se sobreponha ao próximo botão sobre a metade.|
|Para inserir um espaço antes de um botão seguido por um espaço e manter o espaço à direita|Arraste o botão até que a borda direita ou inferior esteja apenas tocando no botão Avançar ou simplesmente sobreponha-o.|
|Para inserir um espaço antes de um botão seguido por um espaço e fechar o espaço seguinte|Arraste o botão para a direita ou para baixo até que ele se sobreponha ao próximo botão sobre a metade.|
|Para remover um espaço entre botões em uma barra de ferramentas|Arraste o botão em um lado do espaço para o botão no outro lado do espaço até que ele se sobreponha ao botão avançar sobre a metade.|

> [!NOTE]
> Se não houver espaço no lado do botão para o qual você está arrastando e você arrastar o botão mais do que o meio do botão adjacente, o **Editor da barra de ferramentas** inserirá um espaço no lado oposto do botão que você está arrastando.

#### <a name="to-change-the-properties-of-a-toolbar-button"></a>Para alterar as propriedades de um botão da barra de ferramentas

1. Em um C++ projeto, selecione o botão da barra de ferramentas.

1. Digite a nova ID na propriedade **ID** na [janela Propriedades](/visualstudio/ide/reference/properties-window)ou use a lista suspensa para selecionar uma nova **ID**.

#### <a name="to-create-a-tool-tip-for-a-toolbar-button"></a>Para criar uma dica de ferramenta para um botão da barra de ferramentas

1. Selecione o botão da barra de ferramentas.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), no campo **prompt** , adicione uma descrição do botão para a barra de status e depois da mensagem, adicione `\n` e o nome da dica de ferramenta.

Por exemplo, para ver a dica de ferramenta do botão **Imprimir** no **WordPad**:

1. Abra o **WordPad**.

1. Focalize o ponteiro do mouse sobre o botão da barra de ferramentas imprimir `Print` e observe que a palavra agora está flutuando no ponteiro do mouse.

1. Examine a barra de status na parte inferior da janela do **WordPad** e observe que agora ela mostra o texto `Prints the active document`.

`Print`é o nome da dica de `Prints the active document` ferramenta e é a descrição do botão da barra de status.

Se você quiser esse efeito usando o **Editor de barra de ferramentas**, defina a `Prints the active document\nPrint`propriedade **prompt** como.

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Menus e outros recursos](/windows/win32/menurc/resources)
[dos editores de recursos](../windows/resource-editors.md)<br/>
[Propriedades do botão de barra de ferramentas](../windows/toolbar-button-properties.md)<br/>
