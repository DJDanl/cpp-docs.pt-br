---
title: Editor de menu (C++)
ms.date: 02/15/2019
f1_keywords:
- vc.editors.menu.F1
- vc.editors.menu
helpviewer_keywords:
- resource editors [C++], Menu editor
- editors, menus
- Menu editor
- menus [C++], Menu editor
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
- menu commands [C++], selecting
- menus [C++], selecting
- commands [C++], menu commands
- commands [C++], copying on menus
- menu items, moving
- commands [C++], moving on menus
- menu items, copying
- menu items, deleting
- commands [C++], deleting from menus
- menus [C++], deleting
ms.assetid: 421fb215-6e12-4ec9-a3af-82d77f87bfa6
ms.openlocfilehash: b5d809fa4e0f608d4c0e6cbdaf8697688c6d3f9c
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037270"
---
# <a name="menu-editor-c"></a>Editor de menu (C++)

Menus permitem organizar os comandos de forma lógica e fácil de encontrar. Com o **Editor de Menu**, você pode criar e editar menus trabalhando diretamente com uma barra de menus ou em conjunto é semelhante no seu aplicativo concluído.

> [!TIP]
> Ao usar o **Editor de Menu**, em muitos casos, pode clicar duas vezes para exibir um menu pop-up de comandos usados com frequência. Os comandos disponíveis dependem do que o ponteiro estiver apontando para.

## <a name="how-to"></a>Como

O **Editor de Menu** permite que você:

### <a name="to-create-a-standard-menu"></a>Criar um menu padrão

1. Vá ao menu **modo de exibição** > **modo de exibição de recursos** e clique duas vezes no **Menu** título. Escolher **adicionar recurso**, em seguida, **Menu**.

1. Selecione o **Novo Item** caixa (o retângulo que contém *digite aqui*) na barra de menus.

   ![Caixa de novo Item no editor de menu](../windows/media/vcmenueditornewitembox.gif "vcMenuEditorNewItemBox")<br/>
   **Novo Item** caixa

1. Digite um nome para o novo menu, por exemplo, *arquivo*.

   O texto digitado aparece em ambas a **Editor de Menu** e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   Depois de você ter recebe um nome de seu novo menu na barra de menus, caixa novo item desloca para a direita (para permitir que você adicione outro menu) e outra caixa do novo item é aberta abaixo do menu do seu primeiro para que você possa adicionar comandos de menu a ele.

   ![Caixa de novo Item expandida](../windows/media/vcmenueditornewitemboxexpanded.gif "vcMenuEditorNewItemBoxExpanded")<br/>
   **Novo Item** deslocados para a caixa com foco após digitar o nome do menu

   > [!NOTE]
   > Para criar um único item de menu na barra de menus, defina as **pop-up** propriedade **falso**.

### <a name="to-create-a-submenu"></a>Para criar um submenu

1. Selecione o comando de menu para o qual você deseja criar um submenu.

1. No **Novo Item** caixa que aparece à direita, digite o nome do novo comando de menu. Este novo comando aparecerão primeiro no menu do submenu.

1. Adicione comandos de menu adicionais ao menu do submenu.

### <a name="to-insert-a-new-menu-between-existing-menus"></a>Para inserir um novo menu entre menus existentes

Selecione um existente nome do menu e pressione a **inserir** da chave, ou clique com botão direito na barra de menus e escolha **Inserir novo**.

   O **Novo Item** caixa é inserida antes do item selecionado.

### <a name="to-add-commands-to-a-menu"></a>Adicionar comandos a um menu

1. Crie um menu. Em seguida, selecione um nome no menu, por exemplo, **arquivo**.

   Cada menu expandirá e expor uma nova caixa de item para comandos. Por exemplo, você pode adicionar os comandos **New**, **abra**, e **fechar** para um **arquivo** menu.

1. Na caixa de novo item, digite um nome para o novo comando de menu.

   > [!NOTE]
   > O texto digitado aparece em ambas a **Editor de Menu** e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   > [!TIP]
   > Você pode definir uma tecla mnemônica (tecla de acesso) que permite ao usuário selecionar o comando de menu. Digite um e comercial (`&`) na frente de uma letra para especificá-lo como o mnemônico. O usuário pode selecionar o comando de menu, digitando essa letra.

1. No **propriedades** janela, selecione o menu de comando propriedades que se aplicam. Para obter detalhes, consulte [propriedades do comando de Menu](../windows/menu-command-properties.md).

1. No **Prompt** caixa a **propriedades** janela, digite a cadeia de caracteres de prompt você deseja que apareça na barra de status do seu aplicativo.

   Esta etapa cria uma entrada na tabela de cadeia de caracteres com o mesmo identificador de recurso que o comando de menu que você criou.

   > [!NOTE]
   > Prompts podem aplicar apenas a itens de menu com um **pop-up** propriedade de **verdadeiro**. Por exemplo, itens de menu de nível superior podem ter prompts se eles têm itens de submenu. A finalidade de um **Prompt** é indicar o que acontecerá se um usuário selecionar o item de menu.

1. Pressione **Enter** para concluir o comando de menu.

   A nova caixa de item é selecionada para que você possa criar comandos de menu adicionais.

### <a name="to-select-multiple-menu-commands-to-run-bulk-operations-such-as-deleting-or-changing-properties"></a>Para selecionar vários comandos de menu para executar operações em massa como excluindo ou alterando as propriedades

Enquanto mantém pressionada a **Ctrl** da chave, selecione os menus ou comandos do submenu desejado.

### <a name="to-move-and-copy-menus-and-menu-commands"></a>Mover e copiar os menus e comandos de menu

- Use o método de arrastar e soltar:

   1. Arrastar ou copiar o item que você deseja mover para:

      - Um novo local no menu atual.

      - Um menu diferente. Você pode navegar para outros menus, arrastando o ponteiro do mouse sobre eles.

   1. Cancelar o comando de menu quando o guia de inserção mostra a posição desejada.

- Use os comandos de menu de atalho:

   1. Clique com botão direito um ou mais menus ou comandos de menu e escolha **Recortar** (para mover) ou **cópia**.

   1. Se você estiver movendo os itens para outro menu recurso ou o arquivo de script de recurso [abri-lo em outra janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

   1. Selecione a posição do menu ou comando de menu que você deseja mover ou copiar para.

   1. No menu de atalho, escolha **colar**. O item movido ou copiado é colocado antes do item selecionado.

> [!NOTE]
> Você também pode arrastar, copie e cole a outros menus em outras janelas do menu.

### <a name="to-delete-a-menu-or-menu-command"></a>Para excluir um menu ou um comando de menu

Clique no nome do menu ou comando e escolha **excluir**.

> [!NOTE]
> Da mesma forma, você pode usar o menu de atalho para realizar outras ações como copiar, recortar, colar, inserir novas, separador de inserir, editar IDs, modo de exibição como pop-up, verificar mnemônicos, etc.

## <a name="pop-up-menus"></a>Menus pop-up

[Menus pop-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usando menus pop-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá-lo ao código do aplicativo.

Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) para fazer com que o menu seja exibido. Depois que o usuário foi descartado no menu pop-up selecionando fora dela, ou tiver selecionado um comando, o que a função retornará. Se o usuário escolhe um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.

> [!NOTE]
> Para programas de biblioteca Microsoft Foundation Class (MFC) e programas ATL, use **assistentes de código** conectem os comandos de menu ao código. Para obter mais informações, consulte [adicionando um evento](../ide/adding-an-event-visual-cpp.md) e [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

- Para criar um menu pop-up, criar um menu com um título vazio e não fornecer um *legenda*. Em seguida, adicione um comando de menu ao menu novo, mova para o primeiro comando de menu abaixo do título de menu em branco com a legenda temporário *tipo aqui* e digite um *legenda* e quaisquer outras informações.

   Repita esse processo para quaisquer outros comandos de menu no menu pop-up e não se esqueça de salvar o recurso de menu.

- Para se conectar a um menu pop-up para seu aplicativo, por exemplo, adicionar um manipulador de mensagens para WM_CONTEXTMENU, em seguida, adicione o seguinte código para o manipulador de mensagens:

    ```cpp
    CMenu menu;
    VERIFY(menu.LoadMenu(IDR_MENU1));
    CMenu* pPopup = menu.GetSubMenu(0);
    ASSERT(pPopup != NULL);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
    ```

   > [!NOTE]
   > O [CPoint](../atl-mfc-shared/reference/cpoint-class.md) passados pela mensagem manipulador está em coordenadas da tela.

Normalmente, quando você estiver trabalhando na **Editor de Menu**, um recurso de menu é exibido como uma barra de menus. No entanto, você pode ter recursos de menu que são adicionados à barra de menus do aplicativo enquanto o programa está em execução.

- Para exibir um recurso de menu como um menu pop-up, o menu de atalho e escolha **exibir como Popup**.

   Essa opção é apenas uma preferência de exibição e não modificará seu menu.

> [!TIP]
> Para alterar novamente para o modo de barra de menus, selecione **exibir como Popup** novamente. Essa ação remove a marca de seleção e retorna o modo de exibição da barra de menus.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Comandos de menu](../windows/menu-command-properties.md)<br/>

<!--
[User-Interface Objects and Command IDs](../mfc/user-interface-objects-and-command-ids.md)<br/>
[Menus](../mfc/menus-mfc.md)<br/>
[Menus](https://msdn.microsoft.com/library/windows/desktop/ms646977.aspx)-->