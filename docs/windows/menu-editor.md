---
title: Editor de menuC++()
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
ms.openlocfilehash: a21ff3ba736bd345e4b8399a761b5a8d9db531ac
ms.sourcegitcommit: 9aab425662a66825772f091112986952f341f7c8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/16/2019
ms.locfileid: "72444978"
---
# <a name="menu-editor-c"></a>Editor de menuC++()

Os menus permitem que você organize os comandos de maneira lógica e fácil de encontrar. Com o **Editor de menu**, você pode criar e editar menus trabalhando diretamente com uma barra de menus que se assemelha bastante ao seu aplicativo concluído.

> [!TIP]
> Ao usar o **Editor de menu**, em muitas instâncias, você pode clicar com o botão direito do mouse para exibir um menu pop-up de comandos usados com frequência. Os comandos disponíveis dependem do que o ponteiro está apontando.

## <a name="how-to"></a>Como

O **Editor de menus** permite que você:

### <a name="to-create-a-standard-menu"></a>Criar um menu padrão

1. Vá para a **exibição**de menu  > **Other Windows** > **modo de exibição de recursos** e clique com o botão direito do mouse no título do **menu** . Escolha **Adicionar recurso**e, em seguida, **menu**.

1. Selecione a caixa **novo item** (o retângulo que contém o *tipo aqui*) na barra de menus.

   ![Nova caixa de item no editor de menu](../windows/media/vcmenueditornewitembox.gif "vcMenuEditorNewItemBox")<br/>
   **Nova** caixa de item

1. Digite um nome para o novo menu, por exemplo, *arquivo*.

   O texto que você digitar aparecerá no **Editor de menu** e na caixa **legenda** na [janela Propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades do novo menu em qualquer local.

   Depois que você tiver dado ao seu novo menu um nome na barra de menus, a caixa New-Item mudará para a direita (para permitir que você adicione outro menu) e outra caixa New-Item será aberta abaixo do primeiro menu para que você possa adicionar comandos de menu a ele.

   ![Caixa de novo item expandida](../windows/media/vcmenueditornewitemboxexpanded.gif "vcMenuEditorNewItemBoxExpanded")<br/>
   **Nova** caixa de item com foco deslocado depois que você digita o nome do menu

   > [!NOTE]
   > Para criar um menu de item único na barra de menus, defina a propriedade **Popup** como **false**.

### <a name="to-create-a-submenu"></a>Para criar um submenu

1. Selecione o comando de menu para o qual você deseja criar um submenu.

1. Na caixa **novo item** que aparece à direita, digite o nome do novo comando de menu. Esse novo comando aparecerá primeiro no menu do submenu.

1. Adicione comandos de menu adicionais ao menu de submenu.

### <a name="to-insert-a-new-menu-between-existing-menus"></a>Para inserir um novo menu entre os menus existentes

Selecione um nome de menu existente e pressione a tecla **Insert** , ou clique com o botão direito do mouse na barra de menus e escolha **Inserir novo**.

   A caixa **novo item** é inserida antes do item selecionado.

### <a name="to-add-commands-to-a-menu"></a>Para adicionar comandos a um menu

1. Crie um menu. Em seguida, selecione um nome de menu, por exemplo, **arquivo**.

   Cada menu irá expandir e expor uma nova caixa de item para comandos. Por exemplo, você pode adicionar os comandos **novo**, **abrir**e **Fechar** a um menu **arquivo** .

1. Na caixa novo item, digite um nome para o novo comando de menu.

   > [!NOTE]
   > O texto que você digitar aparecerá no **Editor de menu** e na caixa **legenda** na [janela Propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades do novo menu em qualquer local.

   > [!TIP]
   > Você pode definir uma chave mnemônico (tecla de acesso) que permite ao usuário selecionar o comando de menu. Digite um e comercial (`&`) na frente de uma letra para especificá-lo como o mnemônico. O usuário pode selecionar o comando de menu digitando essa letra.

1. Na janela **Propriedades** , selecione as propriedades do comando de menu que se aplicam. Para obter detalhes, consulte [Propriedades de comando de menu](../windows/menu-command-properties.md).

1. Na caixa **prompt** na janela **Propriedades** , digite a cadeia de caracteres do prompt que você deseja que apareça na barra de status do aplicativo.

   Esta etapa cria uma entrada na tabela de cadeia de caracteres com o mesmo identificador de recurso que o comando de menu que você criou.

   > [!NOTE]
   > Os prompts só podem ser aplicados a itens de menu com uma propriedade **Popup** de **true**. Por exemplo, itens de menu de nível superior podem ter prompts se tiverem itens de submenu. A finalidade de um **prompt** é indicar o que acontecerá se um usuário selecionar o item de menu.

1. Pressione **Enter** para concluir o comando de menu.

   A caixa novo item é selecionada para que você possa criar comandos de menu adicionais.

### <a name="to-select-multiple-menu-commands-to-run-bulk-operations-such-as-deleting-or-changing-properties"></a>Para selecionar vários comandos de menu para executar operações em massa, como excluir ou alterar propriedades

Mantendo pressionada a tecla **Ctrl** , selecione os comandos de menus ou submenu desejados.

### <a name="to-move-and-copy-menus-and-menu-commands"></a>Para mover e copiar menus e comandos de menu

- Use o método de arrastar e soltar:

   1. Arraste ou copie o item para o qual você deseja mover:

      - Um novo local no menu atual.

      - Um menu diferente. Você pode navegar para outros menus arrastando o ponteiro do mouse sobre eles.

   1. Solte o comando de menu quando o guia de inserção mostrar a posição desejada.

- Usar comandos do menu de atalho:

   1. Clique com o botão direito do mouse em um ou mais menus ou comandos de menu e escolha **recortar** (para mover) ou **copiar**.

   1. Se você estiver movendo os itens para outro recurso de menu ou arquivo de script de recurso, [abra-o em outra janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

   1. Selecione a posição do menu ou comando de menu que você deseja mover ou copiar.

   1. No menu de atalho, escolha **colar**. O item movido ou copiado é colocado antes do item selecionado.

> [!NOTE]
> Você também pode arrastar, copiar e colar para outros menus em outras janelas de menu.

### <a name="to-delete-a-menu-or-menu-command"></a>Para excluir um menu ou comando de menu

Clique com o botão direito do mouse no nome do menu ou comando e escolha **excluir**.

> [!NOTE]
> Da mesma forma, você pode usar o menu de atalho para executar outras ações, como copiar, recortar, colar, Inserir novo, inserir separador, editar IDs, exibir como pop-up, verificar mnemônicos, etc.

## <a name="pop-up-menus"></a>Menus pop-up

Os [menus pop-up](../mfc/menus-mfc.md) exibem comandos usados com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. O uso de menus pop-up em seu aplicativo requer a criação do próprio menu e, em seguida, a conexão ao código do aplicativo.

Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](/windows/win32/api/winuser/nf-winuser-trackpopupmenu) para que o menu seja exibido. Depois que o usuário tiver descartado o menu pop-up selecionando fora dele, ou tiver selecionado um comando, essa função retornará. Se o usuário escolher um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.

> [!NOTE]
> Para programas da biblioteca do Microsoft Foundation Class (MFC) e programas da ATL, use **assistentes de código** para vincular comandos de menu ao código. Para obter mais informações, consulte [adicionando um evento](../ide/adding-an-event-visual-cpp.md) e [mapeando mensagens para o Functions](../mfc/reference/mapping-messages-to-functions.md).

- Para criar um menu pop-up, crie um menu com um título vazio e não forneça uma *legenda*. Em seguida, adicione um comando de menu ao menu novo, mova para o primeiro comando de menu abaixo do título do menu em branco com a legenda temporária *Digite aqui* e digite uma *legenda* e qualquer outra informação.

   Repita esse processo para qualquer outro comando de menu no menu pop-up e certifique-se de salvar o recurso de menu.

- Para conectar um menu pop-up ao seu aplicativo, por exemplo, adicione um manipulador de mensagens para WM_CONTEXTMENU e, em seguida, adicione o seguinte código ao manipulador de mensagens:

    ```cpp
    CMenu menu;
    VERIFY(menu.LoadMenu(IDR_MENU1));
    CMenu* pPopup = menu.GetSubMenu(0);
    ASSERT(pPopup != NULL);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
    ```

   > [!NOTE]
   > O [CPoint](../atl-mfc-shared/reference/cpoint-class.md) passado pelo manipulador de mensagens está em coordenadas de tela.

Normalmente, quando você está trabalhando no **Editor de menu**, um recurso de menu é exibido como uma barra de menus. No entanto, você pode ter recursos de menu que são adicionados à barra de menus do aplicativo enquanto o programa está em execução.

- Para exibir um recurso de menu como um menu pop-up, clique com o botão direito do mouse no menu e escolha **Exibir como pop**-up.

   Essa opção é apenas uma preferência de exibição e não modificará seu menu.

> [!TIP]
> Para voltar para a exibição de barra de menus, selecione **Exibir como pop-up** novamente. Essa ação remove a marca de seleção e retorna sua exibição de barra de menus.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Comandos de menu](../windows/menu-command-properties.md)<br/>
[Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)<br/>
[Menus](../mfc/menus-mfc.md)<br/>
[Menus](/windows/win32/menurc/menus)