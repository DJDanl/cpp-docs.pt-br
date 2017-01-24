---
title: "Operador Mutex::operator= | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::Mutex::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador operator="
ms.assetid: 9b0ee206-a930-4fea-8dc0-1f79839e9d13
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador Mutex::operator=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui o Mutex especificado (move) do objeto para o objeto de Mutex atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Mutex& operator=(  
   _Inout_ Mutex&& h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `h`  
 Uma referência rvalue para um objeto Mutex.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto atual do Mutex.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o **Mover semântica** seção [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](Mutex%20Class1.md)