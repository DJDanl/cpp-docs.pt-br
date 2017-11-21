---
title: Derivado de mapas de mensagem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- message handling [MFC], derived message handlers
- messages, routing
- message maps [MFC], derived
- derived message maps
ms.assetid: 21829556-6e64-40c3-8279-fed85d99de77
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e70f2298ed916db7d9c7b2d059ef7ce69b4060c9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="derived-message-maps"></a>Mapas de mensagem derivados
Durante a manipulação, verificando uma mensagem da classe de mensagem mapa não é o final do texto de mapa de mensagem. O que acontece se classe `CMyView` (derivado de `CView`) não tem nenhuma entrada correspondente para uma mensagem  
  
 Tenha em mente que `CView`, a classe base de `CMyView`, é derivado por sua vez `CWnd`. Portanto, `CMyView` *é* um `CView` e *é* um `CWnd`. Cada uma dessas classes tem seu próprio mapa de mensagem. A Figura "A exibição de hierarquia" abaixo mostra a relação hierárquica das classes, mas tenha em mente que uma `CMyView` objeto é um único objeto que tem as características de todos os três classes.  
  
 ![Hierarquia de uma exibição](../mfc/media/vc38621.gif "vc38621")  
Uma hierarquia de exibição  
  
 Portanto, se uma mensagem não pode ser correspondida na classe `CMyView`do mapa da mensagem, a estrutura também procura o mapeamento de mensagem de sua classe base imediata. O `BEGIN_MESSAGE_MAP` macro no início do mapa de mensagem especifica dois nomes de classe como argumentos:  
  
 [!code-cpp[NVC_MFCMessageHandling#2](../mfc/codesnippet/cpp/derived-message-maps_1.cpp)]  
  
 O primeiro argumento nomeia a classe à qual pertence o mapa da mensagem. O segundo argumento fornece uma conexão com a classe base imediata — `CView` aqui — para o framework possa procurar seu mapa de mensagem muito.  
  
 Os manipuladores de mensagem fornecidos em uma classe base, portanto, são herdados pela classe derivada. Isso é muito semelhante às funções de membro virtual normal sem a necessidade de fazer todas as funções de manipulador de membro virtual.  
  
 Se nenhum manipulador foi encontrado em nenhum dos mapas de mensagem de classe base, o processamento da mensagem padrão será executado. Se a mensagem é um comando, a estrutura roteia para o próximo destino de comando. Se for uma mensagem do Windows padrão, a mensagem é passada para o procedimento de janela padrão apropriado.  
  
 Para agilizar a correspondência de mapa de mensagem, o framework armazena em cache recentes correspondências na probabilidade de que ele receberá a mesma mensagem novamente. Uma consequência disso é que os processos do framework sem tratamento mensagens de maneira muito eficiente. Mapas de mensagem também são mais eficientes para o espaço do que implementações que usam funções virtuais.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

