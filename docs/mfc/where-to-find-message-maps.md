---
title: Onde encontrar mapas de mensagem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- macros, message map
- locating message maps
- message classes [MFC], finding
- message-map macros
ms.assetid: bf59fbc8-b222-42d3-b5d3-0a79aa3cb923
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6fa0b0b31d76c55851d69f4c528f11e7d23ff0d9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="where-to-find-message-maps"></a>Onde encontrar mapas de mensagens
Quando você cria um novo aplicativo de esqueleto com o Assistente de aplicativo, o Assistente de aplicativo grava um mapa de mensagem para cada classe de destino do comando que cria para você. Isso inclui o aplicativo derivado, documento, exibição e classes de janela do quadro. Alguns desses mapas de mensagem já tem as entradas fornecidas pelo Assistente de aplicativo para determinadas mensagens e comandos predefinidos, e alguns são apenas espaços reservados para manipuladores que serão adicionados.  
  
 Mapa de mensagem da classe está localizado na. Arquivo CPP da classe. Trabalhando com os mapas de mensagem básica criado pelo Assistente de aplicativo, use a janela Propriedades para adicionar entradas para as mensagens e comandos que tratará cada classe. Um mapa de mensagem típico pode parecer com o seguinte depois de adicionar algumas entradas:  
  
 [!code-cpp[NVC_MFCMessageHandling#1](../mfc/codesnippet/cpp/where-to-find-message-maps_1.cpp)]  
  
 O mapa de mensagens consiste em uma coleção de macros. Duas macros, [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) e [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map), colchete o mapa da mensagem. Outras macros, como `ON_COMMAND`, preencha o conteúdo do mapa de mensagem.  
  
> [!NOTE]
>  As macros de mapa de mensagem não são seguidas por ponto e vírgula.  
  
 Quando você usar o Assistente para Adicionar classe para criar uma nova classe, ele fornece um mapa de mensagem para a classe. Como alternativa, você pode criar um mapa de mensagem manualmente usando o editor de código fonte.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

