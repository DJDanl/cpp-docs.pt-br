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
ms.openlocfilehash: d59d0bfc75f654cd9f8f15ff851ad42a619e271f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

