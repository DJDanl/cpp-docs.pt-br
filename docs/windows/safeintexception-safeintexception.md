---
title: SafeIntException::SafeIntException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeIntException
- SafeIntException.SafeIntException
- SafeIntException::SafeIntException
dev_langs:
- C++
helpviewer_keywords:
- SafeIntException, constructor
ms.assetid: 8e5a0c24-a56b-4c80-9ee8-876604b1e7dc
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 393c424feb2a84fff85ba0efb5de7cbcaf54737c
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016753"
---
# <a name="safeintexceptionsafeintexception"></a>SafeIntException::SafeIntException
Cria uma **SafeIntException** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
SafeIntException();  
  
SafeIntException(  
   SafeIntError code  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *código*  
 Um valor de dados enumerado que descreve o erro que ocorreu.  
  
## <a name="remarks"></a>Comentários  
 Os valores possíveis para *código* são definidos no arquivo safeint. Para sua conveniência, os possíveis valores também são listados aqui.  
  
-   `SafeIntNoError`  
  
-   `SafeIntArithmeticOverflow`  
  
-   `SafeIntDivideByZero`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint  
  
 **Namespace:** MSL:: Utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca SafeInt](../windows/safeint-library.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)   
 [Classe SafeInt](../windows/safeint-class.md)