---
title: Criando Menus pop-up | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- context menus, Menu Editor
- pop-up menus, creating
- menus, pop-up
- menus, creating
- shortcut menus, creating
- pop-up menus, displaying
ms.assetid: dff4dddf-2e8d-4c34-b755-90baae426b58
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6185f52eeaf56ac0d31cb8e9f22715db36514725
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-pop-up-menus"></a>Criando menus pop-up
[Menus pop-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usando os menus pop-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá-lo ao código do aplicativo.  
  
 Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](http://msdn.microsoft.com/library/windows/desktop/ms648002) para fazer com que o menu seja exibido. Depois que o usuário foi descartado do menu pop-up clicando fora, ou clica em um comando, essa função retornará. Se o usuário escolhe um comando, essa mensagem de comando será enviada para a janela cujo identificador foi passado.  
  
### <a name="to-create-a-pop-up-menu"></a>Para criar um menu pop-up  
  
1.  [Criar um menu](../windows/creating-a-menu.md) com um título vazio (não fornecer um **legenda**).  
  
2.  [Adicionar um comando de menu para o novo menu](../windows/adding-commands-to-a-menu.md). Mover para o primeiro comando de menu abaixo do título de menu em branco (a legenda temporária diz tipo aqui). Digite um **legenda** e outras informações.  
  
     Repita esse processo para quaisquer outros comandos de menu no menu pop-up.  
  
3.  Salve o recurso de menu.  
  
    > [!TIP]
    >  Para obter mais informações sobre como exibir o menu pop-up, consulte [exibindo um Menu como um Menu pop-up](../windows/viewing-a-menu-as-a-pop-up-menu.md).  
  

  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Conectando um Menu pop-up para seu aplicativo](../windows/connecting-a-pop-up-menu-to-your-application.md)   
 [Editor de Menu](../windows/menu-editor.md)