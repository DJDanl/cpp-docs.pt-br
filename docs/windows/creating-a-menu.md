---
title: Criando Menus (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.menu
helpviewer_keywords:
- mnemonics [C++], associating menu items
- menus [C++], associating commands with mnemonic keys
- menus [C++], creating
- menus [C++], adding items
- commands [C++], adding to menus
- menu items, adding to menus
- submenus
- submenus [C++], creating
- menus [C++], creating
- context menus [C++], Menu Editor
- pop-up menus [C++], creating
- menus [C++], pop-up
- menus [C++], creating
- shortcut menus [C++], creating
- pop-up menus [C++], displaying
- pop-up menus [C++], connecting to applications
- context menus [C++], connecting to applications
- shortcut menus [C++], connecting to applications
- pop-up menus
ms.assetid: 66f94448-9b97-4b73-bf97-10d4bf87cc65
ms.openlocfilehash: e3b3cc58b82f68c55ac98601fd11775422c901e5
ms.sourcegitcommit: 5a7dbd640376e13379f5d5b2cf66c4842e5e737b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/08/2019
ms.locfileid: "55905765"
---
# <a name="creating-menus-c"></a>Criando Menus (C++)

> [!NOTE]
> O **janela recursos** não está disponível nas edições Express.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-create-a-standard-menu"></a>Criar um menu padrão

1. Dos **modo de exibição** menu, selecione **exibição de recurso** e, em seguida, clique duas vezes no **Menu** título e escolha **adicionar recurso**. Escolher **Menu**.

1. Selecione o **Novo Item** caixa (o retângulo que contém "Digite aqui") na barra de menus.

   ![Caixa de novo Item no editor de menu](../windows/media/vcmenueditornewitembox.gif "vcMenuEditorNewItemBox")<br/>
   Caixa de novo Item

1. Digite um nome para o novo menu, por exemplo, "Arquivo".

   O texto digitado aparece em ambas a **Menu** editor e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   Depois de você ter recebe um nome de seu novo menu na barra de menus, caixa novo item desloca para a direita (para permitir que você adicione outro menu) e outra caixa do novo item é aberta abaixo do menu do seu primeiro para que você possa adicionar comandos de menu a ele.

   ![Caixa de novo Item expandida](../windows/media/vcmenueditornewitemboxexpanded.gif "vcMenuEditorNewItemBoxExpanded")<br/>
   Depois de digitar o nome do Menu deslocados para a caixa de novo Item com foco

   > [!NOTE]
   > Para criar um único item de menu na barra de menus, defina as **pop-up** propriedade **falso**.

## <a name="to-create-a-submenu"></a>Para criar um submenu

1. Selecione o comando de menu para o qual você deseja criar um submenu.

1. No **Novo Item** caixa que aparece à direita, digite o nome do novo comando de menu. Este novo comando aparecerão primeiro no menu do submenu.

1. Adicione comandos de menu adicionais ao menu do submenu.

## <a name="to-insert-a-new-menu-between-existing-menus"></a>Para inserir um novo menu entre menus existentes

Selecione um existente nome do menu e pressione a **inserir** chave. O **Novo Item** caixa é inserida antes do item selecionado.

   \- ou -

Clique com botão direito na barra de menus e escolha **Inserir novo** no menu de atalho.

## <a name="to-add-commands-to-a-menu"></a>Adicionar comandos a um menu

1. Crie um menu.

1. Selecione um nome no menu, por exemplo, **arquivo**.

   Cada menu expandirá e expor uma nova caixa de item para comandos. Por exemplo, você pode adicionar os comandos **New**, **abra**, e **fechar** para um **arquivo** menu.

1. Na caixa de novo item, digite um nome para o novo comando de menu.

   > [!NOTE]
   > O texto digitado aparece em ambas a **Menu** editor e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   > [!TIP]
   > Você pode definir uma tecla mnemônica (tecla de acesso) que permite ao usuário selecionar o comando de menu. Digite um e comercial (`&`) na frente de uma letra para especificá-lo como o mnemônico. O usuário pode selecionar o comando de menu, digitando essa letra.

1. No **propriedades** janela, selecione o menu de comando propriedades que se aplicam. Para obter detalhes, consulte [propriedades do comando de Menu](../windows/menu-command-properties.md).

1. No **Prompt** caixa a **propriedades** janela, digite a cadeia de caracteres de prompt você deseja que apareça na barra de status do seu aplicativo.

   Esta etapa cria uma entrada na tabela de cadeia de caracteres com o mesmo identificador de recurso que o comando de menu que você criou.

   > [!NOTE]
   > Prompts podem aplicar apenas a itens de menu com um **pop-up** propriedade de **verdadeiro**. Por exemplo, itens de menu de nível superior podem ter prompts se eles têm itens de submenu. A finalidade de um **Prompt** é indicar o que acontecerá se um usuário selecionar o item de menu.

1. Pressione **Enter** para concluir o comando de menu.

   A nova caixa de item é selecionada para que você possa criar comandos de menu adicionais.

## <a name="to-create-pop-up-menus"></a>Para criar menus pop-up

[Menus pop-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usando menus pop-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá-lo ao código do aplicativo.

Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) para fazer com que o menu seja exibido. Depois que o usuário foi descartado no menu pop-up selecionando fora dela, ou tiver selecionado um comando, o que a função retornará. Se o usuário escolhe um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.

### <a name="to-create-a-pop-up-menu"></a>Para criar um menu pop-up

1. [Criar um menu](../windows/creating-a-menu.md) com um título vazio (não fornecem uma **legenda**).

1. [Adicionar um comando de menu ao menu novo](../windows/adding-commands-to-a-menu.md). Mover para o primeiro comando de menu abaixo do título de menu em branco (a legenda temporária diz `Type Here`). Digite um **legenda** e quaisquer outras informações.

   Repita esse processo para quaisquer outros comandos de menu no menu pop-up.

1. Salve o recurso de menu.

### <a name="to-connect-a-pop-up-menu-to-your-application"></a>Para se conectar a um menu pop-up para seu aplicativo

1. Adicione um manipulador de mensagens para WM_CONTEXTMENU (por exemplo). Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

1. Adicione o seguinte código para o manipulador de mensagens:

    ```cpp
    CMenu menu;
    VERIFY(menu.LoadMenu(IDR_MENU1));
    CMenu* pPopup = menu.GetSubMenu(0);
    ASSERT(pPopup != NULL);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
    ```

   > [!NOTE]
   > O [CPoint](../atl-mfc-shared/reference/cpoint-class.md) passados pela mensagem manipulador está em coordenadas da tela.

   > [!NOTE]
   > Conectando um menu pop-up ao seu aplicativo requer o MFC.

### <a name="to-view-a-menu-resource-as-a-pop-up-menu"></a>Para exibir um recurso de menu como um menu pop-up

Normalmente, quando você estiver trabalhando na **Menu** editor, um recurso de menu é exibido como uma barra de menus. No entanto, você pode ter recursos de menu que são adicionados à barra de menus do aplicativo enquanto o programa está em execução.

O menu de atalho e escolha **exibir como Popup** no menu de atalho.

   Essa opção é apenas uma preferência de exibição e não modificará seu menu.

   > [!NOTE]
   > Para alterar de volta para o modo de exibição da barra de menus, clique em **exibir como Popup** novamente (que remove a marca de seleção e retorna o modo de exibição da barra de menus).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)