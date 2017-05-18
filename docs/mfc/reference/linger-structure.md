---
title: Estrutura de LINGER | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LINGER
dev_langs:
- C++
helpviewer_keywords:
- LINGER structure
ms.assetid: 1fb1c5bf-a64e-4a6c-89d6-1734e4fdbb1b
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: ed880c29f43c074ba61f52b11f812a79eece0416
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linger-structure"></a>Estrutura de LINGER
O `LINGER` estrutura é usada para manipular o **SO_LINGER** e **SO_DONTLINGER** opções de `CAsyncSocket::GetSockOpt`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct linger {  
    u_short l_onoff;            // option on/off  
    u_short l_linger;           // linger time  
};  
```  
  
## <a name="remarks"></a>Comentários  
 Definindo o **SO_DONTLINGER** opção impede que o bloqueio na função de membro **fechar** enquanto aguarda unsent dados a serem enviados. A definição dessa opção é equivalente à configuração **SO_LINGER** com **l_onoff** definido como 0.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CAsyncSocket::GetSockOpt](../../mfc/reference/casyncsocket-class.md#getsockopt)   
 [CAsyncSocket::SetSockOpt](../../mfc/reference/casyncsocket-class.md#setsockopt)


