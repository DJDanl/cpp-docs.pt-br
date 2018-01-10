---
title: "Como: usar a referência cruzada do mapa de mensagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.messages
dev_langs: C++
helpviewer_keywords: windows [MFC], message maps
ms.assetid: 2e863d23-9e58-45ba-b5e4-a8ceefccd0c8
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 25f78fb2e2c5700cbb1f7c8dcb093795ce001c13
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-the-message-map-cross-reference"></a>Como usar a referência cruzada do mapa de mensagem
Nas entradas rotuladas \<memberFxn >, escrever sua própria função de membro para um derivado [CWnd](../../mfc/reference/cwnd-class.md) classe. Atribuir qualquer nome que você deseja que a sua função. Outras funções, como `OnActivate`, são funções de membro da classe `CWnd`. Se chamado, eles passam a mensagem para o `DefWindowProc` função do Windows. Para processar mensagens de notificação do Windows, substitua correspondente `CWnd` função em sua classe derivada. A função deve chamar a função sobrecarregada em sua classe base para permitir que a classe base e Windows responder à mensagem.  
  
 Em todos os casos, colocar o protótipo de função a `CWnd`-cabeçalho de classe derivada e o código a entrada de mapa de mensagem conforme mostrado.  
  
 Os seguintes termos são usados:  
  
|Termo|Definição|  
|----------|----------------|  
|id|Qualquer usuário definido pelo ID do item de menu (**WM_COMMAND** mensagens) ou controle ID (mensagens de notificação de janela filho).|  
|"mensagem" e "wNotifyCode"|IDs de mensagem Windows conforme definido no WINDOWS. H.|  
|nMessageVariable|Nome de uma variável que contém o valor de retorno de **RegisterWindowMessage** função do Windows.|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)

