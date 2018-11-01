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
ms.assetid: dff4dddf-2e8d-4c34-b755-90baae426b58
ms.openlocfilehash: 243a2489918f74243ce3b2268ec44c4fe4c1b566
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506776"
---
# <a name="creating-pop-up-menus-c"></a>Criando Menus pop-up (C++)

[Menus pop-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usando menus pop-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá-lo ao código do aplicativo.

Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) para fazer com que o menu seja exibido. Depois que o usuário foi descartado no menu pop-up clicando fora dele ou clicou em um comando, essa função retornará. Se o usuário escolhe um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.

### <a name="to-create-a-pop-up-menu"></a>Para criar um menu pop-up

1. [Criar um menu](../windows/creating-a-menu.md) com um título vazio (não fornecem uma **legenda**).

2. [Adicionar um comando de menu ao menu novo](../windows/adding-commands-to-a-menu.md). Mover para o primeiro comando de menu abaixo do título de menu em branco (a legenda temporária diz `Type Here`). Digite um **legenda** e quaisquer outras informações.

   Repita esse processo para quaisquer outros comandos de menu no menu pop-up.

3. Salve o recurso de menu.

   > [!TIP]
   > Para obter mais informações sobre como exibir o menu pop-up, consulte [exibindo um Menu como um Menu pop-up](../windows/viewing-a-menu-as-a-pop-up-menu.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Conectando um menu pop-up ao aplicativo](../windows/connecting-a-pop-up-menu-to-your-application.md)<br/>
[Editor de Menu](../windows/menu-editor.md)