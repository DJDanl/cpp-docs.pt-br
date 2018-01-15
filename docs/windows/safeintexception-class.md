---
title: Classe SafeIntException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: SafeIntException Class
dev_langs: C++
helpviewer_keywords: SafeIntException class
ms.assetid: 88bef958-1f48-4d55-ad4f-d1f9581a293a
caps.latest.revision: "8"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 91f1c80273d0e1ed41ea86774c71fcbe8ad1bbf6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safeintexception-class"></a>Classe SafeIntException
O `SafeInt` classe usa `SafeIntException` para identificar o motivo pelo qual uma operação matemática não pode ser concluída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class SafeIntException;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
 [SafeIntException::SafeIntException](../windows/safeintexception-safeintexception.md)  
 Cria um objeto `SafeIntException`.  
  
## <a name="remarks"></a>Comentários  
 O [classe SafeInt](../windows/safeint-class.md) é a única classe que usa o `SafeIntException` classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [Classe SafeIntException](../windows/safeintexception-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** msl::utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)