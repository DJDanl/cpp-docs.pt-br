---
title: Macros de mapa (MFC) da mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.messages
dev_langs:
- C++
helpviewer_keywords:
- message map macros
- Windows messages [C++], declaration
- demarcating Windows messages
- message maps [C++], macros
- message maps [C++], declaration and demarcation
- message mapping macros
- ranges, message map
- message map ranges
ms.assetid: 531b15ce-32b5-4ca0-a849-bb519616c731
caps.latest.revision: 10
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
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: f890e0675be58c8e20e313bea54b4145e2ce0bf3
ms.lasthandoff: 02/25/2017

---
# <a name="message-map-macros-mfc"></a>Macros de mapa de mensagem (MFC)
Para oferecer suporte a mapas de mensagem, o MFC fornece as seguintes macros:  
  
### <a name="message-map-declaration-and-demarcation-macros"></a>Mapa de mensagem declaração e demarcação Macros  
  
|||  
|-|-|  
|[DECLARE_MESSAGE_MAP](http://msdn.microsoft.com/library/c225e7e0-a81b-495c-97f9-3e0aa1f65036)|Declara que um mapa da mensagem será usado em uma classe para mapear mensagens para funções (deve ser usado na declaração da classe).|  
|[BEGIN_MESSAGE_MAP](http://msdn.microsoft.com/library/d9201e18-04e0-4639-9810-f15768627fc2)|Começa a definição de um mapa de mensagem (deve ser usado na implementação da classe).|  
|[END_MESSAGE_MAP](http://msdn.microsoft.com/library/40f611f1-a3b4-4097-b683-091bf7cfab8b)|Termina a definição de um mapa de mensagem (deve ser usado na implementação da classe).|  
  
### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagem  
  
|||  
|-|-|  
|[ON_COMMAND](http://msdn.microsoft.com/library/f24f8bda-2cf4-49d5-aa3d-6f2e6bb003f2)|Indica qual função tratará uma mensagem de comando especificado.|  
|[ON_CONTROL](http://msdn.microsoft.com/library/2cb7ebdf-296b-4606-b191-3449835003db)|Indica qual função tratará uma mensagem de notificação do controle especificado.|  
|[ON_MESSAGE](http://msdn.microsoft.com/library/e2faeb13-9f6e-4c0d-9f6d-b2e141a0db1e)|Indica qual função tratará uma mensagem definida pelo usuário.|  
|[ON_OLECMD](http://msdn.microsoft.com/library/6c86327c-3d48-42ac-9dae-e0ccd3a81793)|Indica qual função irá manipular um comando de menu de um DocObject ou em seu contêiner.|  
|[ON_REGISTERED_MESSAGE](http://msdn.microsoft.com/library/93c1c068-ae8c-4e04-8a60-a603800ab57d)|Indica qual função tratará uma mensagem registrada definidos pelo usuário.|  
|[ON_REGISTERED_THREAD_MESSAGE](http://msdn.microsoft.com/library/3f598bc2-b2f0-410f-8ba0-7714502170f3)|Indica qual função tratará uma mensagem registrada definida pelo usuário quando você tem um `CWinThread` classe.|  
|[ON_THREAD_MESSAGE](http://msdn.microsoft.com/library/f718f47a-d5b1-4514-914b-e3fe2d919003)|Indica qual função tratará uma mensagem definida pelo usuário quando você tem um `CWinThread` classe.|  
|[ON_UPDATE_COMMAND_UI](http://msdn.microsoft.com/library/c4de3c21-2d2e-4b89-a4ce-d0c0e2d9edc4)|Indica qual função tratará uma mensagem de comando de atualização de interface do usuário especificado.|  
  
### <a name="message-map-range-macros"></a>Macros de intervalo de mapa de mensagem  
  
|||  
|-|-|  
|[ON_COMMAND_RANGE](http://msdn.microsoft.com/library/c52719fc-dd6e-48c9-af79-383f48d608e0)|Indica qual função tratará o intervalo de IDs de comando especificadas nos dois primeiros parâmetros para a macro.|  
|[ON_UPDATE_COMMAND_UI_RANGE](http://msdn.microsoft.com/library/b7105bf1-44ad-4b00-b947-31478f964729)|Indica qual manipulador de atualização tratará o intervalo de IDs de comando especificadas nos dois primeiros parâmetros para a macro.|  
|[ON_CONTROL_RANGE](http://msdn.microsoft.com/library/46f0e1bb-569b-4b8b-9b80-89701d1cd7fd)|Indica qual função manipulará notificações do intervalo de IDs especificadas no segundo e terceiro parâmetros para a macro do controle. O primeiro parâmetro é uma mensagem de notificação de controle, como **BN_CLICKED**.|  
  
 Para obter mais informações sobre mapas de mensagem, a declaração de mapa de mensagem e macros demarcação e as macros de mapeamento de mensagem, consulte [mapas de mensagem](../../mfc/reference/message-maps-mfc.md) e [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md). Para obter mais informações sobre intervalos de mapas de mensagem, consulte [manipuladores para intervalos de mapas de mensagem](../../mfc/handlers-for-message-map-ranges.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)



