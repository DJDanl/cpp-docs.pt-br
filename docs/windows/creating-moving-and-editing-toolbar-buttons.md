---
title: Criando, movendo e editando botões da barra de ferramentas (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.toolbar
helpviewer_keywords:
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
ms.assetid: d0f0c6c6-9d7e-42b5-a86a-7558127386e7
ms.openlocfilehash: 2a67123e444ad208eaae74a24b72288f2dbb3bdb
ms.sourcegitcommit: 52c05e10b503e834c443ef11e7ca1987e332f876
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2019
ms.locfileid: "55742694"
---
# <a name="creating-moving-and-editing-toolbar-buttons-c"></a>Criando, movendo e editando botões da barra de ferramentas (C++)

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

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

Consulte as seguintes ações:

## <a name="to-create-a-new-toolbar-button"></a>Para criar um novo botão de barra de ferramentas

1. Na [exibição de recurso](../windows/resource-view-window.md) expanda a pasta de recurso (por exemplo, *Project1.rc*).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. Expanda o **barra de ferramentas** pasta e selecione uma barra de ferramentas para editar.

1. Atribua uma ID para o botão em branco na extremidade direita da barra de ferramentas. Você pode fazer isso editando o **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window). Por exemplo, você talvez queira dar a mesma ID de uma opção de menu a um botão de barra de ferramentas. Nesse caso, use a caixa de listagem suspensa para selecionar o **ID** da opção de menu.

   -ou-

   Selecione o botão em branco na extremidade direita da barra de ferramentas (na **modo de exibição da barra de ferramentas** painel) e começar a desenhar. Uma ID de comando do botão padrão é atribuída (ID_BUTTON\<n >).

Você pode, também, copiar e colar uma imagem em uma barra de ferramentas, como um novo botão.

## <a name="to-add-an-image-to-a-toolbar-as-a-button"></a>Para adicionar uma imagem para uma barra de ferramentas, como um botão

1. Na [exibição de recurso](../windows/resource-view-window.md), abra a barra de ferramentas clicando duas vezes nele.

1. Em seguida, abra a imagem que você deseja adicionar à barra de ferramentas.

   > [!NOTE]
   > Se você abrir a imagem no Visual Studio, ele será aberto na **imagem** editor. Você também pode abrir a imagem em outros programas de elementos gráficos.

1. Dos **edite** menu, escolha **cópia**.

1. Alterne para sua barra de ferramentas selecionando seu guia na parte superior da janela de origem.

1. Dos **edite** menu, escolha **colar**.

   A imagem será exibida na barra de ferramentas, como um novo botão.

## <a name="to-move-a-toolbar-button"></a>Para mover um botão de barra de ferramentas

No **modo de exibição da barra de ferramentas** painel, arraste o botão que você deseja mover para o novo local na barra de ferramentas.

## <a name="to-copy-buttons-from-a-toolbar"></a>Para copiar os botões da barra de ferramentas

1. Mantenha pressionada a **Ctrl** chave.

1. No **modo de exibição da barra de ferramentas** painel, arraste o botão para seu novo local na barra de ferramentas ou em um local na barra de ferramentas do outro.

## <a name="to-delete-a-toolbar-button"></a>Para excluir um botão de barra de ferramentas

Selecione o botão de barra de ferramentas e arraste-o da barra de ferramentas.

## <a name="to-insert-or-remove-space-between-buttons-on-a-toolbar"></a>Para inserir ou remover um espaço entre botões em uma barra de ferramentas

Em geral, para inserir um espaço entre botões, arraste-os dos outros na barra de ferramentas. Para remover espaço, arraste-os em direção uns aos outros.

### <a name="to-insert-a-space-before-a-button-that-isnt-followed-by-a-space"></a>Para inserir um espaço antes de um botão que não é seguido por um espaço

Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.

### <a name="to-insert-a-space-before-a-button-that-is-followed-by-a-space-and-to-keep-the-trailing-space"></a>Para inserir um espaço antes de um botão que é seguido por um espaço e manter o espaço à direita

Arraste o botão até que a borda direita ou inferior é simplesmente tocar no botão Avançar ou apenas se sobrepõe a ela.

### <a name="to-insert-a-space-before-a-button-that-is-followed-by-a-space-and-close-up-that-following-space"></a>Para inserir um espaço antes de um botão que é seguido por um espaço e fechar aquele espaço seguir

Arraste o botão à direita ou para baixo até que ele se sobrepõe no botão Avançar sobre na metade.

### <a name="to-remove-a-space-between-buttons-on-a-toolbar"></a>Para remover um espaço entre botões em uma barra de ferramentas

Arraste o botão em um lado do espaço para o botão do outro lado do espaço até que ele se sobrepõe no botão Avançar sobre na metade.

   Se não há nenhum espaço no lado do botão que você está arrastando longe do e arrastar o botão metade após o botão adjacente, o **barra de ferramentas** editor também insere um espaço no lado oposto do botão que você está arrastando.

## <a name="to-change-the-properties-of-a-toolbar-button"></a>Para alterar as propriedades de um botão de barra de ferramentas

1. Em um projeto do C++, selecione o botão de barra de ferramentas.

1. Digite a nova ID na **ID** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window), ou use a lista suspensa para selecionar um novo **ID**.

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Editor de barra de ferramentas](../windows/toolbar-editor.md)
