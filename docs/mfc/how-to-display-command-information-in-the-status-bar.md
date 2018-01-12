---
title: "Como: exibir informações do comando na barra de Status | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- prompts [MFC]
- displaying command status [MFC]
- status bars [MFC], message area
- status bars [MFC], displaying command information
ms.assetid: de895cbe-61ee-46bf-9787-76b247527d6d
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: da836f48592d97b3526c568eb9d9a830428f53a3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-display-command-information-in-the-status-bar"></a>Como exibir informações do comando na barra de status
Quando você executar o Assistente de aplicativo para criar o esqueleto do seu aplicativo, você pode dar suporte a uma barra de ferramentas e uma barra de status. Somente uma opção no Assistente de aplicativo oferece suporte a ambos. Quando houver uma barra de status, o aplicativo fornece automaticamente comentários úteis, como o usuário move o ponteiro sobre os itens nos menus. O aplicativo exibe uma cadeia de caracteres de prompt automaticamente na barra de status quando o item de menu é realçado. Por exemplo, quando o usuário move o ponteiro sobre o **Recortar** comando o **editar** menu, a barra de status pode exibir "Recorta a seleção e a coloca na área de transferência" na área de mensagem da barra de status. O prompt de ajuda o usuário a entender a finalidade do item de menu. Isso também funciona quando o usuário clica em um botão de barra de ferramentas.  
  
 Você pode adicionar a esta Ajuda da barra de status definindo cadeias de caracteres de prompt para itens de menu que você adicionar ao programa. Para fazer isso, forneça as cadeias de caracteres de prompt quando você edita as propriedades do item de menu no editor de menu. Você define as cadeias de caracteres são armazenadas no arquivo de recurso do aplicativo; eles têm as mesmas IDs que os comandos que explicam por eles.  
  
 Por padrão, o Assistente de aplicativo adiciona `AFX_IDS_IDLEMESSAGE`, a ID de uma mensagem de "Pronta" padrão, que é exibida quando o programa está aguardando novas mensagens. Se você especificar a opção de ajuda sensível ao contexto no Assistente do aplicativo, a mensagem será alterada para "Para obter ajuda, pressione F1."  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)

