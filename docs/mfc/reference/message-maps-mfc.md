---
title: Mapas de mensagem (MFC)
ms.date: 09/07/2019
helpviewer_keywords:
- message maps [MFC], MFC
- Windows messages [MFC], message maps
- messages [MFC], Windows
- MFC, messages
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
ms.openlocfilehash: 8080becf1a1a153322bfd03cbd7006eaf2ce4e13
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356569"
---
# <a name="message-maps-mfc"></a>Mapas de mensagem (MFC)

Esta seção da referência lista todas as [macros](../../mfc/reference/message-map-macros-mfc.md) de mapeamento de mensagens e todas as entradas de mapa de mensagem [CWnd,](../../mfc/reference/cwnd-class.md) juntamente com os protótipos de função de membro correspondentes:

|Categoria|Descrição|
|--------------|-----------------|
|ON\_COMMAND Message Handler|Lida `WM_COMMAND` com mensagens geradas por seleções de menu do usuário ou chaves de acesso de menu.|
|[Manipuladores de mensagens de notificação de janela filho](../../mfc/reference/child-window-notification-message-handlers.md)|Manuseie mensagens de notificação de janelas de crianças.|
|[manipuladores de mensagens WM_](../../mfc/reference/handlers-for-wm-messages.md)|Manuseie `WM_` mensagens, como `WM_PAINT`.|
|[Manipuladores de mensagens definidos pelo usuário](../../mfc/reference/user-defined-handlers.md)|Manuseie mensagens definidas pelo usuário.|

(Para obter uma explicação sobre a terminologia e as convenções utilizadas nesta referência, consulte [Como Usar o Mapa de Mensagens De Referência Cruzada](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).)

Como o Windows é um sistema operacional orientado a mensagens, uma grande parte da programação para o ambiente Windows envolve o manuseio de mensagens. Cada vez que um evento como um pressionamento de tecla ou clique do mouse ocorre, uma mensagem é enviada para o aplicativo, que deve então lidar com o evento.

A Microsoft Foundation Class Library oferece um modelo de programação otimizado para programação baseada em mensagens. Neste modelo, "mapas de mensagens" são usados para designar quais funções lidarão com várias mensagens para uma determinada classe. Os mapas de mensagens contêm uma ou mais macros que especificam quais mensagens serão tratadas por quais funções. Por exemplo, um mapa `ON_COMMAND` de mensagem contendo uma macro pode parecer algo assim:

[!code-cpp[NVC_MFCMessageMaps#16](../../mfc/reference/codesnippet/cpp/message-maps-mfc_1.cpp)]

A `ON_COMMAND` macro é usada para lidar com mensagens de comando geradas por menus, botões e teclas do acelerador. [As macros](../../mfc/reference/message-map-macros-mfc.md) estão disponíveis para mapear o seguinte:

## <a name="windows-messages"></a>Mensagens do Windows

- Notificações de controle

- Mensagens definidas pelo usuário

## <a name="command-messages"></a>Mensagens de Comando

- Mensagens definidas pelo usuário registradas

- Mensagens de atualização da interface do usuário

## <a name="ranges-of-messages"></a>Intervalos de Mensagens

- Comandos

- Atualizar mensagens de manipulador

- Notificações de controle

Embora as macros de mapa de mensagem sejam importantes, você geralmente não terá que usá-las diretamente. Isso porque o [Assistente de Classe](mfc-class-wizard.md) cria automaticamente entradas de mapa de mensagens em seus arquivos de origem quando você o usa para associar funções de manipulação de mensagens com mensagens. Sempre que você quiser editar ou adicionar uma entrada de mapa de mensagem, você pode usar o Assistente de Classe.

> [!NOTE]
> O Assistente de Classe não suporta intervalos de mapa de mensagem. Você deve escrever essas entradas de mapa de mensagem você mesmo.

No entanto, os mapas de mensagens são uma parte importante da Biblioteca de Classes da Microsoft Foundation. Você deve entender o que eles fazem, e a documentação é fornecida para eles.

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)
