---
title: "M&#233;todo EventSource::Add | Microsoft Docs"
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
  - "event/Microsoft::WRL::EventSource::Add"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Add"
ms.assetid: 8bded85b-929e-4425-a464-e5de67bb774c
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo EventSource::Add
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Acrescenta o manipulador de eventos representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto EventSource atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT Add(  
   _In_ TDelegateInterface* delegateInterface,  
   _Out_ EventRegistrationToken* token  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `delegateInterface`  
 A interface para um objeto delegado, que representa um manipulador de eventos.  
  
 `token`  
 Quando essa operação for concluída, um identificador que representa o evento. Usar esse token como o parâmetro para o [Remove](../Topic/EventSource::Remove%20Method.md) método para descartar o manipulador de eventos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)