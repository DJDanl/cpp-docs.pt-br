---
title: Mensagem de mapas (MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.messages
dev_langs:
- C++
helpviewer_keywords:
- message maps [MFC], MFC
- Windows messages [MFC], message maps
- messages [MFC], Windows
- MFC, messages
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4d1479ac7cb119ef206f8c20b6fa53bf7017b8ac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="message-maps-mfc"></a>Mapas de mensagem (MFC)
Esta seção da referência lista todos os [macros de mapeamento de mensagem](../../mfc/reference/message-map-macros-mfc.md) e todos os [CWnd](../../mfc/reference/cwnd-class.md) protótipos de função de entradas de mapa de mensagem junto com o membro correspondente:  
  
|Categoria|Descrição|  
|--------------|-----------------|  
|ON\_manipulador de mensagens de comando|Manipula `WM_COMMAND` mensagens geradas por seleções do menu de usuário ou chaves de acesso do menu.|  
|[Manipuladores de mensagens de notificação de janela filho](../../mfc/reference/child-window-notification-message-handlers.md)|Lidar com mensagens de notificação de janelas filho.|  
|[Manipuladores de mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)|Tratar `WM_` mensagens, como `WM_PAINT`.|  
|[Manipuladores de mensagens definidas pelo usuário](../../mfc/reference/user-defined-handlers.md)|Tratar mensagens definidas pelo usuário.|  
  
 (Para obter uma explicação da terminologia e as convenções usadas nesta referência, consulte [como usar o mapa de mensagem de referência cruzada](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).)  
  
 Como o Windows é um sistema operacional orientado a mensagens, grande parte da programação para o ambiente Windows envolve a manipulação de mensagens. Ocorre sempre que clicar em um evento, como um pressionamento de tecla ou um mouse, uma mensagem é enviada para o aplicativo, que deve tratar o evento.  
  
 A biblioteca Microsoft Foundation Class oferece um modelo de programação otimizado para programação de mensagem. Nesse modelo, "mensagem mapas" são usadas para designar quais funções tratará várias mensagens para uma determinada classe. Mapas de mensagem contém uma ou mais macros que especifique quais mensagens são manipuladas por quais funções. Por exemplo, uma mensagem mapa que contém um `ON_COMMAND` macro algo parecido com isto:  
  
 [!code-cpp[NVC_MFCMessageMaps#16](../../mfc/reference/codesnippet/cpp/message-maps-mfc_1.cpp)]  
  
 O `ON_COMMAND` macro é usada para tratar mensagens de comando geradas pelos menus, botões e teclas de aceleração. [Macros](../../mfc/reference/message-map-macros-mfc.md) estão disponíveis para mapear o seguinte:  
  
## <a name="windows-messages"></a>Mensagens do Windows  
  
-   Notificações de controle  
  
-   Mensagens definidas pelo usuário  
  
## <a name="command-messages"></a>Mensagens de comando  
  
-   Registrado mensagens definidas pelo usuário  
  
-   Mensagens de atualização de interface do usuário  
  
## <a name="ranges-of-messages"></a>Intervalos de mensagens  
  
-   Comandos  
  
-   Mensagens de manipulador de atualização  
  
-   Notificações de controle  
  
 Embora as macros de mapa de mensagem são importantes, você geralmente não precisará usá-los diretamente. Isso ocorre porque a janela Propriedades automaticamente cria entradas de mapa de mensagem nos arquivos de origem quando você usá-lo para associar funções de manipulação de mensagens de mensagens. Qualquer momento em que você deseja editar ou adicionar uma entrada de mapa de mensagem, você pode usar a janela Propriedades.  
  
> [!NOTE]
>  A janela Propriedades não oferece suporte a intervalos de mapas de mensagem. Você deve escrever essas entradas de mapa de mensagem.  
  
 No entanto, os mapas de mensagem são uma parte importante do que a biblioteca Microsoft Foundation Class. Você deve entender o que fazer e documentação é fornecida para eles.  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

