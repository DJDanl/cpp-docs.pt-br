---
title: Criando Menus pop-up (C++)
ms.date: 11/04/2016
helpviewer_keywords:
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
ms.assetid: dff4dddf-2e8d-4c34-b755-90baae426b58
ms.openlocfilehash: cf2e3578f49cb6b4af8797052273211f699a6b4f
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702824"
---
# <a name="creating-pop-up-menus-c"></a>Criando Menus pop-up (C++)

[Menus pop-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usando menus pop-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá-lo ao código do aplicativo.

Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) para fazer com que o menu seja exibido. Depois que o usuário foi descartado no menu pop-up selecionando fora dela, ou tiver selecionado um comando, o que a função retornará. Se o usuário escolhe um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.

## <a name="to-create-a-pop-up-menu"></a>Para criar um menu pop-up

1. [Criar um menu](../windows/creating-a-menu.md) com um título vazio (não fornecem uma **legenda**).

1. [Adicionar um comando de menu ao menu novo](../windows/adding-commands-to-a-menu.md). Mover para o primeiro comando de menu abaixo do título de menu em branco (a legenda temporária diz `Type Here`). Digite um **legenda** e quaisquer outras informações.

   Repita esse processo para quaisquer outros comandos de menu no menu pop-up.

1. Salve o recurso de menu.

## <a name="to-connect-a-pop-up-menu-to-your-application"></a>Para se conectar a um menu pop-up para seu aplicativo

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

## <a name="to-view-a-menu-resource-as-a-pop-up-menu"></a>Para exibir um recurso de menu como um menu pop-up

Normalmente, quando você estiver trabalhando na **Menu** editor, um recurso de menu é exibido como uma barra de menus. No entanto, você pode ter recursos de menu que são adicionados à barra de menus do aplicativo enquanto o programa está em execução.

O menu de atalho e escolha **exibir como Popup** no menu de atalho.

   Essa opção é apenas uma preferência de exibição e não modificará seu menu.

   > [!NOTE]
   > Para alterar de volta para o modo de exibição da barra de menus, clique em **exibir como Popup** novamente (que remove a marca de seleção e retorna o modo de exibição da barra de menus).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)
