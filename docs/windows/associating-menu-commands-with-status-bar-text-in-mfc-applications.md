---
title: Associando comandos de Menu com o texto da barra de Status em aplicativos MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- status bars, associating menu items
- menus, status bar text
ms.assetid: 757c0e02-bc97-493f-bccd-6cc6887ebc64
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ea0f68bbd0c426aee8141c27d6852bfaaa6ed523
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="associating-menu-commands-with-status-bar-text-in-mfc-applications"></a>Associando comandos de menu ao texto da barra de status em aplicativos MFC
O aplicativo pode exibir o texto descritivo para cada um dos comandos de menu que um usuário pode selecionar. Você pode fazer isso atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade na janela Propriedades. Se você tiver uma cadeia de caracteres no [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC automaticamente exibirá esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando o usuário focalizar um item de menu.  
  
### <a name="to-associate-a-menu-command-with-a-status-bar-text-string"></a>Para associar um comando de menu com uma barra de cadeia de caracteres de texto de status  
  
1.  No **Menu** editor, selecione o comando de menu.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associado no **Prompt** caixa.  
  

  
 **Requisitos**  
  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)   
 [Adicionando comandos a um Menu](../windows/adding-commands-to-a-menu.md)   
 [Editor de Menu](../windows/menu-editor.md)