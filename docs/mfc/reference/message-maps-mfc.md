---
title: Mapas de mensagem (MFC)
ms.date: 09/07/2019
helpviewer_keywords:
- message maps [MFC], MFC
- Windows messages [MFC], message maps
- messages [MFC], Windows
- MFC, messages
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
ms.openlocfilehash: 4305d9b1db297eebcb189d2fad98b8c634ed1133
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908034"
---
# <a name="message-maps-mfc"></a>Mapas de mensagem (MFC)

Esta seção da referência lista todas as [macros de mapeamento de mensagem](../../mfc/reference/message-map-macros-mfc.md) e todas as entradas de mapa de mensagem [CWnd](../../mfc/reference/cwnd-class.md) junto com os protótipos de função de membro correspondentes:

|Categoria|Descrição|
|--------------|-----------------|
|No\_manipulador de mensagem de comando|Lida `WM_COMMAND` com mensagens geradas pelas seleções de menu do usuário ou pelas teclas de acesso do menu.|
|[Manipuladores de mensagens de notificação de janela filho](../../mfc/reference/child-window-notification-message-handlers.md)|Manipule mensagens de notificação de janelas filhas.|
|[Manipuladores de mensagens WM_](../../mfc/reference/handlers-for-wm-messages.md)|Manipule `WM_` mensagens, `WM_PAINT`como.|
|[Manipuladores de mensagens definidos pelo usuário](../../mfc/reference/user-defined-handlers.md)|Manipule mensagens definidas pelo usuário.|

(Para obter uma explicação sobre a terminologia e as convenções usadas nesta referência, consulte [como usar a referência cruzada do mapa de mensagens](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).)

Como o Windows é um sistema operacional orientado a mensagens, uma grande parte da programação para o ambiente Windows envolve a manipulação de mensagens. Cada vez que um evento, como um pressionamento de tecla ou um clique do mouse, uma mensagem é enviada para o aplicativo, que deve manipular o evento.

O biblioteca MFC oferece um modelo de programação otimizado para programação baseada em mensagem. Nesse modelo, "mapas de mensagem" são usados para designar quais funções manipularão várias mensagens para uma classe específica. Os mapas de mensagens contêm uma ou mais macros que especificam quais mensagens serão tratadas por quais funções. Por exemplo, um mapa de mensagens contendo `ON_COMMAND` uma macro pode ser semelhante a este:

[!code-cpp[NVC_MFCMessageMaps#16](../../mfc/reference/codesnippet/cpp/message-maps-mfc_1.cpp)]

A `ON_COMMAND` macro é usada para lidar com mensagens de comando geradas por menus, botões e teclas de aceleração. As [macros](../../mfc/reference/message-map-macros-mfc.md) estão disponíveis para mapear o seguinte:

## <a name="windows-messages"></a>Mensagens do Windows

- Notificações de controle

- Mensagens definidas pelo usuário

## <a name="command-messages"></a>Mensagens de comando

- Mensagens registradas definidas pelo usuário

- Mensagens de atualização da interface do usuário

## <a name="ranges-of-messages"></a>Intervalos de mensagens

- Comandos

- Atualizar mensagens do manipulador

- Notificações de controle

Embora as macros de mapa de mensagem sejam importantes, geralmente você não precisará usá-las diretamente. Isso ocorre porque o [Assistente de classe](mfc-class-wizard.md) cria automaticamente entradas de mapa de mensagem em seus arquivos de origem ao usá-lo para associar funções de manipulação de mensagens com mensagens. Sempre que desejar editar ou adicionar uma entrada de mapa de mensagem, você poderá usar o assistente de classe.

> [!NOTE]
>  O assistente de classe não oferece suporte a intervalos de mapa de mensagem. Você deve escrever essas entradas de mapa de mensagem por conta própria.

No entanto, os mapas de mensagens são uma parte importante do biblioteca MFC. Você deve entender o que eles fazem e a documentação é fornecida para eles.

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)
