---
title: Mensagem de mapas (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- message maps, ATL
- ATL, message handlers
ms.assetid: 9e100400-65c7-4a85-8857-4e6cb6dd7340
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 650dcd31e07ef1995f09b0521991d79726b22774
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="message-maps-atl"></a>Mapas de mensagem (ATL)
Um mapa de mensagem associa uma função de manipulador com uma mensagem específica, um comando ou uma notificação. Por meio da ATL [macros de mapa de mensagem](../atl/reference/message-map-macros-atl.md), você pode especificar um mapa de mensagem para uma janela. Os procedimentos de janela `CWindowImpl`, `CDialogImpl`, e `CContainedWindowT` direcionar mensagens da janela para seu mapa de mensagem.  
  
 O [funções de manipulador de mensagens](../atl/message-handler-functions.md) aceitar um argumento adicional do tipo `BOOL&`. Esse argumento indica se uma mensagem foi processada, e ele é definido como `TRUE` por padrão. Uma função de manipulador, em seguida, pode definir o argumento `FALSE` para indicar que ele não tratada uma mensagem. Nesse caso, ATL continuará procurar por uma função de manipulador adicional no mapa de mensagem. Ao definir esse argumento como `FALSE`, você pode primeiro executar alguma ação em resposta a uma mensagem e, em seguida, permitir que o processamento padrão ou outra função de manipulador para manipular a mensagem de término.  
  
## <a name="chained-message-maps"></a>Mapas de mensagem encadeadas  
 ATL também permite que você para mapas de mensagem de cadeia, que direciona a tratamento para um mapa de mensagem definido em outra classe de mensagens. Por exemplo, você pode implementar comuns a manipulação de mensagens em uma classe separada para fornecer comportamento uniforme para todas as janelas do encadeamento para essa classe. É possível encadear uma classe base ou um membro de dados da sua classe.  
  
 ATL também dá suporte a encadeamento dinâmico, que permite a cadeia de mapa de mensagem de outro objeto em tempo de execução. Para implementar o encadeamento dinâmico, você deve derivar a classe de [CDynamicChain](../atl/reference/cdynamicchain-class.md). Em seguida, declare o [CHAIN_MSG_MAP_DYNAMIC](reference/message-map-macros-atl.md#chain_msg_map_dynamic) macro em seu mapa de mensagem. `CHAIN_MSG_MAP_DYNAMIC`requer um número exclusivo que identifica o objeto e o mapa de mensagens para o qual você está encadeamento. Você deve definir esse valor exclusivo por meio de uma chamada para `CDynamicChain::SetChainEntry`.  
  
 É possível encadear a qualquer classe que declara um mapa de mensagem, desde que a classe derivada de [CMessageMap](../atl/reference/cmessagemap-class.md). `CMessageMap`permite que um objeto para expor seus mapas de mensagem a outros objetos. Observe que `CWindowImpl` já deriva de `CMessageMap`.  
  
## <a name="alternate-message-maps"></a>Mapas de mensagem alternativo  
 Por fim, ATL dá suporte a mapas de mensagem alternativo, declarados com o [ALT_MSG_MAP](reference/message-map-macros-atl.md#alt_msg_map) macro. Cada mapa de mensagem alternativo é identificado por um número exclusivo que você passa para `ALT_MSG_MAP`. Usando mensagens alternativos mapas, você pode manipular as mensagens do windows vários em um mapa. Observe que, por padrão, `CWindowImpl` não usa mapas de mensagem alternativo. Para adicionar esse suporte, substitua o `WindowProc` método no seu `CWindowImpl`-derivado da classe e chamar `ProcessWindowMessage` com o identificador de mapa de mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)

