---
title: Estrutura FILETIME | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- FILETIME
dev_langs:
- C++
helpviewer_keywords:
- FILETIME structure
ms.assetid: e09557e2-b6d7-4dd5-a5b9-6328bca88595
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: bf835cf913e4cb758983d21f63ef41a1af4c8a85
ms.lasthandoff: 02/25/2017

---
# <a name="filetime-structure"></a>Estrutura FILETIME
O `FILETIME` estrutura é um valor de 64 bits que representa o número de intervalos de 100 nanossegundos desde 1 de janeiro de 1601.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _FILETIME {  
    DWORD dwLowDateTime;   /* low 32 bits */  
    DWORD dwHighDateTime;  /* high 32 bits */  
} FILETIME, *PFILETIME, *LPFILETIME;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwLowDateTime*  
 Especifica a baixa de 32 bits do tempo de arquivo.  
  
 *dwHighDateTime*  
 Especifica a alta de 32 bits do tempo de arquivo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** windef.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CTime::CTime](../../atl-mfc-shared/reference/ctime-class.md#ctime)


