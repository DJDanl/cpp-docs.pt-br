---
title: 'Como: Exibir informações de comando na barra de Status'
ms.date: 11/04/2016
helpviewer_keywords:
- prompts [MFC]
- displaying command status [MFC]
- status bars [MFC], message area
- status bars [MFC], displaying command information
ms.assetid: de895cbe-61ee-46bf-9787-76b247527d6d
ms.openlocfilehash: c93787b3799306d6008299e7c1be6e429bc4c2d9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160283"
---
# <a name="how-to-display-command-information-in-the-status-bar"></a>Como: Exibir informações de comando na barra de Status

Quando você executa o Assistente de aplicativo para criar o esqueleto do aplicativo, você pode dar suporte a uma barra de ferramentas e uma barra de status. Apenas uma opção no Assistente de aplicativo dá suporte a ambos. Quando uma barra de status estiver presente, o aplicativo fornece automaticamente comentários úteis quando o usuário move o ponteiro sobre os itens nos menus. O aplicativo exibe automaticamente uma cadeia de caracteres de prompt na barra de status quando o item de menu é realçado. Por exemplo, quando o usuário move o ponteiro sobre o **Recortar** comando as **editar** menu, a barra de status pode exibir "Recorta a seleção e a coloca na área de transferência" na área de mensagem da barra de status. O prompt ajuda o usuário a entender a finalidade do item de menu. Isso também funciona quando o usuário clica em um botão de barra de ferramentas.

Você pode adicionar a essa Ajuda da barra de status com a definição de cadeias de caracteres de prompt para itens de menu que você adiciona ao programa. Para fazer isso, forneça as cadeias de caracteres de prompt quando você edita as propriedades do item de menu no editor de menu. Você define as cadeias de caracteres são armazenadas no arquivo de recurso do aplicativo; eles têm as mesmas IDs que os comandos que eles explicam.

Por padrão, o Assistente de aplicativo adiciona **AFX_IDS_IDLEMESSAGE**, a ID de uma mensagem de "Pronta" padrão, que é exibida quando o programa está aguardando novas mensagens. Se você especificar a opção de ajuda sensível ao contexto no Assistente do aplicativo, a mensagem é alterada para "Para obter ajuda, pressione F1."

## <a name="see-also"></a>Consulte também

[Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)
