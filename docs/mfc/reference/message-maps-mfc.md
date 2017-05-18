---
title: Mensagem de mapas (MFC) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.messages
dev_langs:
- C++
helpviewer_keywords:
- message maps [C++], MFC
- Windows messages [C++], message maps
- messages [C++], Windows
- MFC [C++], messages
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: bb31d35e221c9f5d06dc34408bed500b4a18b077
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="message-maps-mfc"></a>Mapas de mensagem (MFC)
Esta seção da referência lista todos os [macros de mapeamento de mensagem](../../mfc/reference/message-map-macros-mfc.md) e [CWnd](../../mfc/reference/cwnd-class.md) protótipos de função de entradas de mapa de mensagens junto com o membro correspondente:  
  
|Categoria|Descrição|  
|--------------|-----------------|  
|[WM_COMMAND manipulador de mensagens](../../mfc/reference/wm-command-message-handler.md)|Manipula **WM_COMMAND** mensagens geradas por seleções de menu de usuário ou chaves de acesso do menu.|  
|[Manipuladores de mensagens de notificação de janela filho](../../mfc/reference/child-window-notification-message-handlers.md)|Lidar com mensagens de notificação de janelas filho.|  
|[Manipuladores de mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)|Lidar com **WM _** mensagens, como `WM_PAINT`.|  
|[Manipuladores de mensagens definidas pelo usuário](../../mfc/reference/user-defined-handlers.md)|Lidar com mensagens definidas pelo usuário.|  
  
 (Para obter uma explicação das terminologias e convenções usadas nesta referência, consulte [como usar o mapa de mensagem referência cruzada](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).)  
  
 Como o Windows é um sistema operacional orientado a mensagens, uma grande parte da programação para o ambiente Windows envolve a manipulação de mensagens. Ocorre sempre que clicar em um evento, como um mouse ou um pressionamento de tecla, uma mensagem é enviada para o aplicativo, que deve, em seguida, manipular o evento.  
  
 A biblioteca Microsoft Foundation Class oferece um modelo de programação otimizado para programação baseada em mensagem. Nesse modelo, "mapas de mensagem" são usados para designar quais funções tratará várias mensagens para uma determinada classe. Mapas de mensagem contém uma ou mais macros que especificam quais mensagens serão manipuladas pelo quais funções. Por exemplo, uma mensagem mapa contendo uma `ON_COMMAND` macro pode parecer semelhante a esta:  
  
 [!code-cpp[NVC_MFCMessageMaps n º&16;](../../mfc/reference/codesnippet/cpp/message-maps-mfc_1.cpp)]  
  
 O `ON_COMMAND` macro é usada para tratar mensagens de comando geradas por menus, botões e teclas de aceleração. [Macros](../../mfc/reference/message-map-macros-mfc.md) estão disponíveis para mapear o seguinte:  
  
## <a name="windows-messages"></a>Mensagens do Windows  
  
-   Notificações de controle  
  
-   Mensagens definidas pelo usuário  
  
## <a name="command-messages"></a>Mensagens de comando  
  
-   Mensagens definidas pelo usuário registradas  
  
-   Mensagens de atualização da interface do usuário  
  
## <a name="ranges-of-messages"></a>Intervalos de mensagens  
  
-   Comandos  
  
-   Mensagens de manipulador de atualização  
  
-   Notificações de controle  
  
 Embora as macros de mapa de mensagem são importantes, geralmente não precisa usá-los diretamente. Isso ocorre porque a janela Propriedades automaticamente cria entradas de mapa de mensagem nos arquivos de origem quando você usá-lo para associar funções de manipulação de mensagem mensagens. Qualquer momento em que você deseja editar ou adicionar uma entrada de mapa da mensagem, você pode usar a janela Propriedades.  
  
> [!NOTE]
>  A janela Propriedades não oferece suporte a intervalos de mapas de mensagem. Você deve escrever essas entradas de mapa de mensagem.  
  
 No entanto, os mapas de mensagem são uma parte importante da Microsoft Foundation Class Library. Você deve entender o que eles fazem e documentação é fornecida para eles.  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


