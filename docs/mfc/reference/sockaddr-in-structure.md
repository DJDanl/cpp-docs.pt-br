---
title: Estrutura SOCKADDR_IN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- SOCKADDR_IN
dev_langs:
- C++
helpviewer_keywords:
- SOCKADDR_IN structure [MFC]
ms.assetid: e8cd7c34-78bd-4e28-a990-eb3ca070b7a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5e5ec6ebf4329ff03c75240dc7cec93e9ba46331
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885732"
---
# <a name="sockaddrin-structure"></a>Estrutura SOCKADDR_IN
Na família de endereços da Internet, o `SOCKADDR_IN` estrutura é usada pelos soquetes do Windows para especificar um endereço de ponto de extremidade local ou remoto ao qual se conectar a um soquete.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct sockaddr_in{  
    short sin_family;  
    unsigned short sin_port;  
struct in_addr sin_addr;  
    char sin_zero[8];  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *sin_family*  
 Família de endereços (deve ser AF_INET).  
  
 *sin_port*  
 Porta do IP.  
  
 *sin_addr*  
 Endereço IP.  
  
 *sin_zero*  
 Preenchimento para fazer o mesmo tamanho que a estrutura `SOCKADDR`.  
  
## <a name="remarks"></a>Comentários  
 Essa é a forma do `SOCKADDR` estruturar específicas para a família de endereços de Internet e pode ser convertido em `SOCKADDR`.  
  
 O componente de endereço IP dessa estrutura é do tipo `IN_ADDR`. O `IN_ADDR` estrutura é definida no arquivo de cabeçalho WINSOCK do Windows Sockets. H da seguinte maneira:  
  
```  
struct in_addr {
    union {
        struct {  
            unsigned char s_b1, s_b2, s_b3, s_b4;  
        } S_un_b;  
        struct {  
            unsigned short s_w1, s_w2;
        } S_un_w;
        unsigned long S_addr;
    } S_un;  
};  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** winsock2.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Estrutura SOCKADDR](../../mfc/reference/sockaddr-structure.md)
