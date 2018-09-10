---
title: Adicionando comandos a um Menu (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.menu
dev_langs:
- C++
helpviewer_keywords:
- menu items, adding to menus
- menus [C++], adding items
- commands [C++], adding to menus
ms.assetid: 1523a755-0ab5-42f8-9e98-bb9881564431
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2c67242195f54f543bdc8c0c1be49fbed69fe91
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318714"
---
# <a name="adding-commands-to-a-menu-c"></a>Adicionando comandos a um Menu (C++)

### <a name="to-add-commands-to-a-menu"></a>Adicionar comandos a um menu

1. [Criar um menu](../windows/creating-a-menu.md).

2. Clique em um nome de menu, por exemplo, **arquivo**.

   Cada menu expandirá e expor uma nova caixa de item para comandos. Por exemplo, você pode adicionar os comandos **New**, **abra**, e **fechar** para um **arquivo** menu.

3. Na caixa de novo item, digite um nome para o novo comando de menu.

   > [!NOTE]
   > O texto digitado aparece em ambas a **Menu** editor e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   > [!TIP]
   > Você pode definir uma tecla mnemônica (tecla de acesso) que permite ao usuário selecionar o comando de menu. Digite um e comercial (`&`) na frente de uma letra para especificá-lo como o mnemônico. O usuário pode selecionar o comando de menu, digitando essa letra.

4. No **propriedades** janela, selecione o menu de comando propriedades que se aplicam. Para obter detalhes, consulte [propriedades do comando de Menu](../windows/menu-command-properties.md).

5. No **Prompt** caixa a **propriedades** janela, digite a cadeia de caracteres de prompt você deseja que apareça na barra de status do seu aplicativo.

   Isso cria uma entrada na tabela de cadeia de caracteres com o mesmo identificador de recurso que o comando de menu que você criou.

   > [!NOTE]
   > Prompts podem aplicar apenas a itens de menu com um **pop-up** propriedade de **verdadeiro**. Por exemplo, itens de menu de nível superior podem ter prompts se eles têm itens de submenu. A finalidade de um **Prompt** é indicar o que acontecerá se um usuário clica no item de menu.

6. Pressione **Enter** para concluir o comando de menu.

   A nova caixa de item é selecionada para que você possa criar comandos de menu adicionais.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)  