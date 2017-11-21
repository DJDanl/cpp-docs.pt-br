---
title: 'Construtor mutex:: mutex | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Mutex::Mutex
dev_langs: C++
helpviewer_keywords: Mutex, constructor
ms.assetid: 504afcdc-775a-4c98-a06f-4fb4663eba3f
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d2a0187c26f8f0a170881d0b683cb462a0a24b81
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mutexmutex-constructor"></a>Construtor Mutex::Mutex
Inicializa uma nova instância da classe Mutex.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
explicit Mutex(  
   HANDLE h  
);  
  
Mutex(  
   _Inout_ Mutex&& h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `h`  
 Um identificador ou uma referência de rvalue para um identificador, um objeto Mutex.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa um objeto Mutex do identificador especificado. O segundo construtor inicializa um objeto Mutex do identificador especificado e move a propriedade do mutex ao objeto Mutex atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](../windows/mutex-class1.md)