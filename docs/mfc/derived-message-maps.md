---
title: Mapas de mensagem derivados
ms.date: 11/04/2016
helpviewer_keywords:
- message handling [MFC], derived message handlers
- messages, routing
- message maps [MFC], derived
- derived message maps
ms.assetid: 21829556-6e64-40c3-8279-fed85d99de77
ms.openlocfilehash: 1413290bc04af37a6d3204150dff5244e1dcb5c5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50662521"
---
# <a name="derived-message-maps"></a>Mapas de mensagem derivados

Durante a manipulação, verificar uma mensagem da classe de mensagem mapa não é o fim da história do mapa de mensagem. O que acontece se classe `CMyView` (derivado de `CView`) não tem nenhuma entrada correspondente para uma mensagem

Tenha em mente que `CView`, a classe base `CMyView`, é derivado, por sua vez, de `CWnd`. Assim `CMyView` *é* um `CView` e *é* um `CWnd`. Cada uma dessas classes tem seu próprio mapa de mensagem. A figura a "A hierarquia de exibição" abaixo mostra a relação hierárquica das classes, mas tenha em mente que um `CMyView` objeto é um único objeto que tem as características de todas as três classes.

![Hierarquia de um modo de exibição](../mfc/media/vc38621.gif "vc38621") A hierarquia de exibição

Portanto, se uma mensagem não pode ser correspondida na classe `CMyView`do mapa da mensagem, o framework também procura o mapa de mensagem da sua classe base imediata. O `BEGIN_MESSAGE_MAP` macro no início do mapa de mensagens especifica dois nomes de classe como argumentos:

[!code-cpp[NVC_MFCMessageHandling#2](../mfc/codesnippet/cpp/derived-message-maps_1.cpp)]

O primeiro argumento nomeia a classe à qual pertence o mapa da mensagem. O segundo argumento fornece uma conexão com a classe base imediata — `CView` aqui — portanto, a estrutura também pode pesquisar seu mapa de mensagem.

Os manipuladores de mensagens fornecidos em uma classe base, portanto, são herdados pela classe derivada. Isso é muito semelhante às funções de membro virtual normal sem a necessidade de tornar todas as funções de membro de manipulador virtual.

Se nenhum manipulador for encontrado em qualquer um dos mapas de mensagem de classe base, processamento de padrão da mensagem é executado. Se a mensagem é um comando, o framework encaminha para o próximo destino do comando. Se for uma mensagem padrão do Windows, a mensagem é passada para o procedimento de janela padrão apropriado.

Para acelerar a correspondência de mapa de mensagem, o framework armazena em cache correspondências recentes sobre a probabilidade de que ele receberá a mesma mensagem novamente. Uma consequência disso é que os processos de estrutura sem tratamento mensagens muito eficiente. Mapas de mensagem também são mais eficientes para o espaço do que as implementações que usam funções virtuais.

## <a name="see-also"></a>Consulte também

[Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

