---
title: 'Como: usar a referência cruzada do mapa de mensagem | Microsoft Docs'
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
- windows [MFC], message maps
ms.assetid: 2e863d23-9e58-45ba-b5e4-a8ceefccd0c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bf76d8f7bb86bf3325a072df80a45e2f0a3ad985
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338892"
---
# <a name="how-to-use-the-message-map-cross-reference"></a>Como usar a referência cruzada do mapa de mensagem
Nas entradas de rotulado \<memberFxn >, escrever sua própria função de membro para um derivada [CWnd](../../mfc/reference/cwnd-class.md) classe. Atribuir qualquer nome que desejar de sua função. Outras funções, como `OnActivate`, são funções de membro da classe `CWnd`. Se chamado, eles passam a mensagem para o `DefWindowProc` função do Windows. Para processar mensagens de notificação do Windows, substitua correspondente `CWnd` função em sua classe derivada. Sua função deve chamar a função sobrecarregada em sua classe base para permitir que a classe base e o Windows respondem à mensagem.  
  
 Em todos os casos, colocar o protótipo de função a `CWnd`-cabeçalho de classe derivada e o código a entrada de mapa de mensagem conforme mostrado.  
  
 Os seguintes termos são usados:  
  
|Termo|Definição|  
|----------|----------------|  
|id|Qualquer ID de item de menu definido pelo usuário (mensagens WM_COMMAND) ou a ID do controle (mensagens de notificação de janela filho).|  
|"message" e "wNotifyCode"|Windows IDs de mensagem definido no WINDOWS. H.|  
|nMessageVariable|Nome de uma variável que contém o valor de retorno de `RegisterWindowMessage` função do Windows.|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)

