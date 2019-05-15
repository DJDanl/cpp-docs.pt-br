---
title: Mapas de mensagem (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- message maps [MFC], MFC
- Windows messages [MFC], message maps
- messages [MFC], Windows
- MFC, messages
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
ms.openlocfilehash: 14c08a008456160fe817f066e5b22b06b9f9fa14
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611822"
---
# <a name="message-maps-mfc"></a>Mapas de mensagem (MFC)

Esta seção da referência lista todos os [macros de mapeamento de mensagem](../../mfc/reference/message-map-macros-mfc.md) e todos os [CWnd](../../mfc/reference/cwnd-class.md) protótipos de função de entradas de mapa de mensagens, juntamente com o membro correspondente:

|Categoria|Descrição|
|--------------|-----------------|
|ON\_manipulador de mensagens de comando|Manipula `WM_COMMAND` mensagens geradas por seleções de menu de usuário ou chaves de acesso do menu.|
|[Manipuladores de mensagens de notificação de janela filho](../../mfc/reference/child-window-notification-message-handlers.md)|Lidar com mensagens de notificação de janelas filho.|
|[Manipuladores de mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)|Manipular `WM_` mensagens, como `WM_PAINT`.|
|[Manipuladores de mensagens definidas pelo usuário](../../mfc/reference/user-defined-handlers.md)|Lidar com mensagens definidas pelo usuário.|

(Para obter uma explicação da terminologia e as convenções usadas nesta referência, consulte [como usar o mapa de mensagem de referência cruzada](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).)

Como o Windows é um sistema de operacional orientado a mensagens, uma grande parte da programação para o ambiente do Windows envolve a manipulação de mensagens. Ocorre sempre que clicar em um evento, como um pressionamento de tecla ou um mouse, uma mensagem é enviada para o aplicativo, que deve, em seguida, manipular o evento.

A biblioteca Microsoft Foundation Class oferece um modelo de programação otimizado para a programação baseada em mensagem. Nesse modelo, "mapas de mensagem" são usadas para designar funções que irá manipular várias mensagens para uma determinada classe. Mapas de mensagem contêm uma ou mais macros que especificam quais mensagens serão manipuladas pelo quais funções. Por exemplo, uma mensagem mapa que contém um `ON_COMMAND` macro pode parecer semelhante ao seguinte:

[!code-cpp[NVC_MFCMessageMaps#16](../../mfc/reference/codesnippet/cpp/message-maps-mfc_1.cpp)]

O `ON_COMMAND` macro é usada para lidar com mensagens de comando geradas por menus, botões e teclas de aceleração. [Macros](../../mfc/reference/message-map-macros-mfc.md) estão disponíveis para mapear o seguinte:

## <a name="windows-messages"></a>Mensagens do Windows

- Notificações de controle

- Mensagens definidas pelo usuário

## <a name="command-messages"></a>Mensagens de comando

- Registrado mensagens definidas pelo usuário

- Mensagens de atualização de interface do usuário

## <a name="ranges-of-messages"></a>Intervalos de mensagens

- Comandos

- Mensagens de manipulador de atualização

- Notificações de controle

Embora as macros de mapa de mensagem são importantes, geralmente não precisará usá-los diretamente. Isso ocorre porque a janela Propriedades cria automaticamente as entradas de mapa de mensagens nos arquivos de origem quando usá-lo para associar funções de manipulação de mensagens com mensagens. Sempre que você deseja editar ou adicionar uma entrada de mapa de mensagem, você pode usar a janela Propriedades.

> [!NOTE]
>  A janela Propriedades não oferece suporte a intervalos de mapa de mensagem. Você deve escrever essas entradas de mapa de mensagem.

No entanto, os mapas de mensagem são uma parte importante do que a biblioteca Microsoft Foundation Class. Você deve entender o que eles fazem e documentação é fornecida para eles.

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)
