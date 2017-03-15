---
title: "Manipuladores definidos pelo usuário | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.handlers
dev_langs:
- C++
helpviewer_keywords:
- ON_REGISTERED_MESSAGE macro
- ON_MESSAGE macro
- user-defined handlers
ms.assetid: 99478294-bef0-4ba7-a369-25a6abdcdb62
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f0fc367bc19f0db23efddfc69fdeac519185ff0c
ms.lasthandoff: 02/25/2017

---
# <a name="user-defined-handlers"></a>Manipuladores definidos do usuário
As seguintes entradas de mapa correspondem aos protótipos de função.  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_MESSAGE ( \<mensagem >, \<memberFxn >)|afx_msg LRESULT memberFxn (WPARAM, LPARAM);|  
|ON_REGISTERED_MESSAGE ( \<nMessageVariable >, \<memberFxn >)|afx_msg LRESULT memberFxn (WPARAM, LPARAM);|  
|ON_THREAD_MESSAGE ( \<mensagem >, \<memberFxn >)|afx_msg memberFxn void (WPARAM, LPARAM);|  
|ON_REGISTERED_THREAD_MESSAGE ( \<nMessageVariable >, \<memberFxn >)|afx_msg memberFxn void (WPARAM, LPARAM);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


