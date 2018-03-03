---
title: Estrutura SOCKADDR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SOCKADDR
dev_langs:
- C++
helpviewer_keywords:
- SOCKADDR structure [MFC]
ms.assetid: df1ed66a-f4b8-43f8-8db8-8c2533d25f68
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 55b310ec83aae35c7386d61849663752811651d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sockaddr-structure"></a>Estrutura SOCKADDR
O `SOCKADDR` estrutura é usada para armazenar um endereço IP (Internet Protocol) para uma máquina que participam de uma comunicação de Windows Sockets.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct sockaddr {  
    unsigned short sa_family;  
    char sa_data[14];  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *sa_family*  
 Família de endereços de soquete.  
  
 *sa_data*  
 Tamanho máximo de todas as estruturas de endereço de soquete diferente.  
  
## <a name="remarks"></a>Comentários  
 TCP/IP Sockets do Microsoft Developer Kit só oferece suporte os domínios de endereço da Internet. Para realmente preencher valores para cada parte de um endereço, você deve usar o `SOCKADDR_IN` estrutura de dados, que é específico para esse formato de endereço. O `SOCKADDR` e `SOCKADDR_IN` estruturas de dados têm o mesmo tamanho. Você simplesmente converter para alternar entre os tipos de estrutura de dois.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Estrutura SOCKADDR_IN](../../mfc/reference/sockaddr-in-structure.md)   
 [CAsyncSocket::Create](../../mfc/reference/casyncsocket-class.md#create)   
 [CSocket::Create](../../mfc/reference/csocket-class.md#create)

