---
title: Adicionando comandos a um Menu | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.menu
dev_langs: C++
helpviewer_keywords:
- menu items, adding to menus
- menus, adding items
- commands, adding to menus
- commands
- menu items
ms.assetid: 1523a755-0ab5-42f8-9e98-bb9881564431
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d53f868fd76877152bb3ec81fdba85c1d97b3aac
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-commands-to-a-menu"></a>Adicionando comandos a um menu
### <a name="to-add-commands-to-a-menu"></a>Para adicionar comandos a um menu  
  
1.  [Criar um menu](../windows/creating-a-menu.md).  
  
2.  Clique em um nome de menu, por exemplo, o arquivo.  
  
     Cada menu irá expandir e expor uma nova caixa de item para comandos. Por exemplo, adicione os comandos novo, abrir e fechar um menu arquivo.  
  
3.  Na caixa de novo item, digite um nome para o novo comando de menu.  
  
    > [!NOTE]
    >  O texto aparece no editor de Menu e na **legenda** caixa o [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.  
  
    > [!TIP]
    >  Você pode definir uma tecla mnemônica (tecla de acesso) que permite ao usuário selecionar o comando de menu. Digite um e comercial (&) na frente de uma letra para especificá-lo como um mnemônico. O usuário pode selecionar o comando de menu digitando essa letra.  
  
4.  Na janela Propriedades, selecione as propriedades de comando de menu que se aplicam. Para obter detalhes, consulte [propriedades do comando de Menu](../windows/menu-command-properties.md).  
  
5.  No **Prompt** na janela Propriedades, digite a cadeia de caracteres de prompt que devem aparecer na barra de status do seu aplicativo.  
  
     Isso cria uma entrada na tabela de cadeia de caracteres com o mesmo identificador de recurso que o comando de menu que você criou.  
  
    > [!NOTE]
    >  Avisos só podem ser aplicadas aos itens de menu com um **pop-up** propriedade **True**. Por exemplo, os itens de menu de nível superior podem ter prompts se eles têm itens de submenu. A finalidade de um Prompt é para indicar o que acontecerá se um usuário clica no item de menu.  
  
6.  Pressione **ENTER** para concluir o comando de menu.  
  
     A caixa de novo item é selecionada para que você possa criar os comandos de menu adicionais.  
  

  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)   
