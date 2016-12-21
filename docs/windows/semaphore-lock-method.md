---
title: "M&#233;todo Semaphore::Lock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Semaphore::Lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Lock"
ms.assetid: 0eef6ede-dc7d-4f09-a6c8-2f7d39d65bfa
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Semaphore::Lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Aguarda até que o objeto atual, ou o objeto de semáforo associado com o identificador especificado, está no estado sinalizado ou o intervalo de tempo limite especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLock Lock(  
   DWORD milliseconds = INFINITE  
);  
  
static SyncLock Lock(  
   HANDLE h,  
   DWORD milliseconds = INFINITE  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `milliseconds`  
 O intervalo de tempo limite, em milissegundos. O valor padrão é INFINITO, o que espera indefinidamente.  
  
 `h`  
 Um identificador para um objeto de semáforo.  
  
## <a name="return-value"></a>Valor de retorno  
 Um Details::SyncLockWithStatusT \< HandleTraits::SemaphoreTraits >  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
[Classe Semaphore](../windows/semaphore-class.md)
 