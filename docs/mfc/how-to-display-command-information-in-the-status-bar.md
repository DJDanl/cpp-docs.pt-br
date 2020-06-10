---
title: Como exibir informações do comando na barra de status
ms.date: 11/04/2016
helpviewer_keywords:
- prompts [MFC]
- displaying command status [MFC]
- status bars [MFC], message area
- status bars [MFC], displaying command information
ms.assetid: de895cbe-61ee-46bf-9787-76b247527d6d
ms.openlocfilehash: bff5d5b20ecc9b20b7b1e8335cda34d582441425
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622533"
---
# <a name="how-to-display-command-information-in-the-status-bar"></a>Como exibir informações do comando na barra de status

Ao executar o assistente de aplicativo para criar o esqueleto de seu aplicativo, você pode dar suporte a uma barra de ferramentas e uma barra de status. Apenas uma opção no assistente de aplicativo dá suporte a ambos. Quando uma barra de status está presente, o aplicativo fornece automaticamente comentários úteis à medida que o usuário move o ponteiro sobre os itens nos menus. O aplicativo exibe automaticamente uma cadeia de caracteres de prompt na barra de status quando o item de menu é realçado. Por exemplo, quando o usuário move o ponteiro do mouse sobre o comando **recortar** no menu **Editar** , a barra de status pode exibir "recorta a seleção e coloca-a na área de transferência" no ponto de mensagem da barra de status. O prompt ajuda o usuário a entender a finalidade do item de menu. Isso também funciona quando o usuário clica em um botão da barra de ferramentas.

Você pode adicionar a essa ajuda da barra de status definindo cadeias de caracteres de prompt para itens de menu que você adiciona ao programa. Para fazer isso, forneça as cadeias de caracteres de prompt ao editar as propriedades do item de menu no editor de menu. As cadeias de caracteres que você define são armazenadas no arquivo de recurso do aplicativo; Eles têm as mesmas IDs que os comandos que explicam.

Por padrão, o assistente de aplicativo adiciona **AFX_IDS_IDLEMESSAGE**, a ID de uma mensagem padrão "pronta", que é exibida quando o programa está aguardando novas mensagens. Se você especificar a opção de ajuda contextual no assistente do aplicativo, a mensagem será alterada para "para obter ajuda, pressione F1."

## <a name="see-also"></a>Consulte também

[Tratamento e mapeamento de mensagem](message-handling-and-mapping.md)
