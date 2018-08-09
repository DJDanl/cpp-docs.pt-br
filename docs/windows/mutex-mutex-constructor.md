---
title: 'Construtor mutex:: mutex | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Mutex
dev_langs:
- C++
helpviewer_keywords:
- Mutex, constructor
ms.assetid: 504afcdc-775a-4c98-a06f-4fb4663eba3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d87c07f7fa4f1dfa6cbb34545d74d75e8a867583
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40017078"
---
# <a name="mutexmutex-constructor"></a>Construtor Mutex::Mutex
Inicializa uma nova instância dos **Mutex** classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
explicit Mutex(  
   HANDLE h  
);  
  
Mutex(  
   _Inout_ Mutex&& h  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *h*  
 Um identificador ou uma referência de rvalue a um identificador para um **Mutex** objeto.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa um **Mutex** objeto do identificador especificado. O segundo construtor inicializa um **Mutex** objeto de identificador especificado e, em seguida, move o propriedade do mutex para atual **Mutex** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](../windows/mutex-class1.md)