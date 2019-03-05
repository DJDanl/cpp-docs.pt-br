---
title: Mapas de mensagem (ATL)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- message maps, ATL
- ATL, message handlers
ms.assetid: 9e100400-65c7-4a85-8857-4e6cb6dd7340
ms.openlocfilehash: 1b8b3fcb2f10f975ebdf68a285c7d5e364b9e1b4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57292569"
---
# <a name="message-maps-atl"></a>Mapas de mensagem (ATL)

Um mapa de mensagem associa uma função de manipulador com uma mensagem em particular, o comando ou a notificação. Com o uso do ATL [macros de mapa de mensagem](../atl/reference/message-map-macros-atl.md), você pode especificar um mapa de mensagem para uma janela. Os procedimentos de janela `CWindowImpl`, `CDialogImpl`, e `CContainedWindowT` direcionar mensagens de uma janela para seu mapa de mensagem.

O [funções de manipulador de mensagens](../atl/message-handler-functions.md) aceitar um argumento adicional do tipo `BOOL&`. Esse argumento indica se uma mensagem foi processada, e ele é definido como TRUE por padrão. Uma função do manipulador, em seguida, pode definir o argumento como FALSE para indicar que ele não foi tratada uma mensagem. Nesse caso, o ATL continuará a procurar por uma função de manipulador ainda mais no mapa de mensagens. Ao definir esse argumento como FALSE, você pode primeiro realizar alguma ação em resposta a uma mensagem e, em seguida, permitir que o processamento padrão ou outra função de manipulador para lidar com a mensagem de término.

## <a name="chained-message-maps"></a>Mapas de mensagem encadeadas

ATL também permite que você mapas de mensagem de cadeia, que direciona a tratamento para um mapa de mensagem definido em outra classe de mensagens. Por exemplo, você pode implementar comuns manipulação de mensagens em uma classe separada para fornecer um comportamento uniforme para todas as janelas de encadeamento para essa classe. É possível encadear para uma classe base ou um membro de dados da sua classe.

ATL também dá suporte a encadeamento dinâmico, que permite que você em cadeia ao mapa de mensagem de outro objeto em tempo de execução. Para implementar o encadeamento dinâmico, você deve derivar sua classe de [CDynamicChain](../atl/reference/cdynamicchain-class.md). Em seguida, declarar o [CHAIN_MSG_MAP_DYNAMIC](reference/message-map-macros-atl.md#chain_msg_map_dynamic) macro no seu mapa de mensagem. CHAIN_MSG_MAP_DYNAMIC requer um número exclusivo que identifica o objeto e o mapa da mensagem para o qual você está encadeamento. Você deve definir esse valor exclusivo por meio de uma chamada para `CDynamicChain::SetChainEntry`.

É possível encadear a qualquer classe que declara um mapa de mensagem, desde que a classe deriva [CMessageMap](../atl/reference/cmessagemap-class.md). `CMessageMap` permite que um objeto exponha seus mapas de mensagem a outros objetos. Observe que `CWindowImpl` já deriva de `CMessageMap`.

## <a name="alternate-message-maps"></a>Mapas de mensagem alternativo

Por fim, o ATL dá suporte a mapas de mensagens alternativos, declarados com o [ALT_MSG_MAP](reference/message-map-macros-atl.md#alt_msg_map) macro. Cada mapa de mensagem alternativa é identificado por um número exclusivo, o que você passa para ALT_MSG_MAP. Usando a mensagem alternativa mapas, você pode manipular as mensagens de várias janelas em um mapa. Observe que, por padrão, `CWindowImpl` não usa mapas de mensagem alternativo. Para adicionar esse suporte, substitua os `WindowProc` método no seu `CWindowImpl`-derivado da classe e chamar `ProcessWindowMessage` com o identificador de mapa de mensagem.

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)
