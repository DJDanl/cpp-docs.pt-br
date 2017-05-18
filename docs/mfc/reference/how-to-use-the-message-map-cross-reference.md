---
title: "Como: usar a referência cruzada do mapa de mensagem | Documentos do Microsoft"
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
- windows [C++], message maps
ms.assetid: 2e863d23-9e58-45ba-b5e4-a8ceefccd0c8
caps.latest.revision: 11
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2f9b6dc2d455b45f0fc81d1a0b0bafc24033af6b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="how-to-use-the-message-map-cross-reference"></a>Como usar a referência cruzada do mapa de mensagem
Nas entradas de rotulado \<memberFxn >, escrever sua própria função de membro para um derivado [CWnd](../../mfc/reference/cwnd-class.md) classe. Atribuir qualquer nome que a sua função. Outras funções, como `OnActivate`, são funções de membro da classe `CWnd`. Se chamado, eles passam a mensagem para o `DefWindowProc` função do Windows. Para processar mensagens de notificação do Windows, substitua correspondente `CWnd` função em sua classe derivada. Sua função deve chamar a função sobrecarregada em sua classe base para permitir que a classe base e Windows responder à mensagem.  
  
 Em todos os casos, colocar o protótipo de função a `CWnd`-cabeçalho de classe derivada e código de entrada do mapa de mensagem conforme mostrado.  
  
 Os seguintes termos são usados:  
  
|Termo|Definição|  
|----------|----------------|  
|id|Qualquer usuário definido pelo ID do item de menu (**WM_COMMAND** mensagens) ou controle ID (mensagens de notificação de janela filho).|  
|"message" e "wNotifyCode"|IDs de mensagem Windows conforme definido no WINDOWS. H.|  
|nMessageVariable|Nome de uma variável que contém o valor de retorno de **RegisterWindowMessage** função do Windows.|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)


