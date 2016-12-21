---
title: "M&#233;todo Mutex::Lock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Mutex::Lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Lock"
ms.assetid: 61d95072-b690-441e-a080-0bf94a733141
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Mutex::Lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Aguarda até que o objeto atual, ou o objeto de Mutex associado com o identificador especificado, liberar o mutex ou o intervalo de tempo limite especificado.  
  
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
 O identificador de um objeto Mutex.  
  
## <a name="return-value"></a>Valor de retorno  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](Mutex%20Class1.md)