---
title: Mapas de mensagem derivados
ms.date: 11/19/2018
helpviewer_keywords:
- message handling [MFC], derived message handlers
- messages, routing
- message maps [MFC], derived
- derived message maps
ms.assetid: 21829556-6e64-40c3-8279-fed85d99de77
ms.openlocfilehash: 0868b12720cfa338ab7275a358e065506adc11d1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615923"
---
# <a name="derived-message-maps"></a>Mapas de mensagem derivados

Durante a manipulação de mensagens, a verificação do mapa de mensagens da própria classe não é o fim da história do mapa de mensagens. O que acontece se `CMyView` a classe (derivada de `CView` ) não tiver entrada correspondente para uma mensagem

Tenha em mente que `CView` , por sua vez, a classe base do `CMyView` , é derivada de `CWnd` . Portanto, `CMyView` *é* um `CView` e *é* um `CWnd` . Cada uma dessas classes tem seu próprio mapa de mensagens. A figura "uma hierarquia de exibição" abaixo mostra a relação hierárquica das classes, mas tenha em mente que um `CMyView` objeto é um único objeto que tem as características de todas as três classes.

![Hierarquia de uma exibição](../mfc/media/vc38621.gif "Hierarquia de uma exibição") <br/>
Uma hierarquia de exibição

Portanto, se uma mensagem não puder ser correspondida no `CMyView` mapa de mensagens da classe, a estrutura também pesquisará o mapa de mensagens de sua classe base imediata. A `BEGIN_MESSAGE_MAP` macro no início do mapa da mensagem especifica dois nomes de classe como seus argumentos:

[!code-cpp[NVC_MFCMessageHandling#2](codesnippet/cpp/derived-message-maps_1.cpp)]

O primeiro argumento nomeia a classe à qual o mapa de mensagem pertence. O segundo argumento fornece uma conexão com a classe base imediata — `CView` aqui, de modo que a estrutura também pode pesquisar seu mapa de mensagens.

Os manipuladores de mensagens fornecidos em uma classe base são, portanto, herdados pela classe derivada. Isso é muito semelhante às funções de membro virtual normais sem a necessidade de tornar todas as funções de membro de manipulador virtuais.

Se nenhum manipulador for encontrado em nenhum dos mapas de mensagens de classe base, o processamento padrão da mensagem será executado. Se a mensagem for um comando, a estrutura a direcionará para o próximo destino de comando. Se for uma mensagem padrão do Windows, a mensagem será passada para o procedimento de janela padrão apropriado.

Para acelerar a correspondência do mapa de mensagens, a estrutura armazena em cache as correspondências recentes na probabilidade de que ela receba a mesma mensagem novamente. Uma consequência disso é que a estrutura processa mensagens sem tratamento com muita eficiência. Os mapas de mensagens também são mais eficientes em termos de espaço do que as implementações que usam funções virtuais.

## <a name="see-also"></a>Consulte também

[Como o Framework pesquisa mapas de mensagem](how-the-framework-searches-message-maps.md)
