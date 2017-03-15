---
title: Estrutura SOCKADDR | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SOCKADDR
dev_langs:
- C++
helpviewer_keywords:
- SOCKADDR structure
ms.assetid: df1ed66a-f4b8-43f8-8db8-8c2533d25f68
caps.latest.revision: 12
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 28984fcc5614a5f901a01ffdeff4ea5f360f63fc
ms.lasthandoff: 02/25/2017

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
 Kit do desenvolvedor do Microsoft TCP/IP Sockets só oferece suporte os domínios de endereço da Internet. Para realmente preencher valores para cada parte de um endereço, você deve usar o `SOCKADDR_IN` estrutura de dados, que é especificamente para esse formato de endereço. O `SOCKADDR` e `SOCKADDR_IN` estruturas de dados têm o mesmo tamanho. Você simplesmente converter para alternar entre os tipos de estrutura de dois.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Estrutura SOCKADDR_IN](../../mfc/reference/sockaddr-in-structure.md)   
 [CAsyncSocket::Create](../../mfc/reference/casyncsocket-class.md#create)   
 [CSocket::Create](../../mfc/reference/csocket-class.md#create)


