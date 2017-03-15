---
title: "Construtor Semaphore::Semaphore | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Semaphore::Semaphore"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Sinal, o construtor"
ms.assetid: 91c22ae7-181e-460d-ad40-70c3a53b26fd
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor Semaphore::Semaphore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe Semaphore.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
explicit Semaphore(  
   HANDLE h  
);  
  
WRL_NOTHROW Semaphore(  
   _Inout_ Semaphore&& h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `h`  
 Um identificador ou uma referência de rvalue para um objeto de semáforo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Semaphore](../windows/semaphore-class.md)