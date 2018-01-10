---
title: SafeIntException::SafeIntException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- SafeIntException
- SafeIntException.SafeIntException
- SafeIntException::SafeIntException
dev_langs: C++
helpviewer_keywords: SafeIntException, constructor
ms.assetid: 8e5a0c24-a56b-4c80-9ee8-876604b1e7dc
caps.latest.revision: "6"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 85bf6bae5ba07154bdeb807171dd2d3df61d0774
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safeintexceptionsafeintexception"></a>SafeIntException::SafeIntException
Cria um objeto `SafeIntException`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SafeIntException();  
  
SafeIntException(  
   SafeIntError code  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `code`  
 Um valor de dados enumerados que descreve o erro que ocorreu.  
  
## <a name="remarks"></a>Comentários  
 Os valores possíveis para `code` são definidos no arquivo Safeint.h. Para sua conveniência, os possíveis valores também são listados aqui.  
  
-   `SafeIntNoError`  
  
-   `SafeIntArithmeticOverflow`  
  
-   `SafeIntDivideByZero`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** msl::utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)   
 [Classe SafeInt](../windows/safeint-class.md)