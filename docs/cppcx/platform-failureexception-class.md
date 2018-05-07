---
title: 'Classe Platform:: failureexception | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::FailureException::FailureException
- VCCORLIB/Platform::FailureException
dev_langs:
- C++
helpviewer_keywords:
- Platform::FailureException
ms.assetid: 1729cd07-bfc2-448e-9db5-185d5cbf5b81
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1094810663ce0a0abf8234af386d7a8427472ced
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="platformfailureexception-class"></a>Classe Platform::FailureException
Gerada quando a operação falhou. É o equivalente a E_FAIL HRESULT.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public ref class FailureException : COMException,    IException,    IPrintable,    IEquatable  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte a classe [COMException](../cppcx/platform-comexception-class.md) .  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  
  
## <a name="see-also"></a>Consulte também  
 [Classe Platform::COMException](../cppcx/platform-comexception-class.md)