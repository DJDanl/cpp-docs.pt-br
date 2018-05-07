---
title: Estrutura de LINGER | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- LINGER
dev_langs:
- C++
helpviewer_keywords:
- LINGER structure [MFC]
ms.assetid: 1fb1c5bf-a64e-4a6c-89d6-1734e4fdbb1b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f19ab7e05b4e27a3b00576339d0b60b37bdba4a7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
 Definindo o **SO_DONTLINGER** opção impede que o bloqueio na função de membro **fechar** enquanto aguarda não enviados dados a serem enviados. A definição dessa opção é equivalente à configuração **SO_LINGER** com **l_onoff** definido como 0.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CAsyncSocket::GetSockOpt](../../mfc/reference/casyncsocket-class.md#getsockopt)   
 [CAsyncSocket::SetSockOpt](../../mfc/reference/casyncsocket-class.md#setsockopt)

