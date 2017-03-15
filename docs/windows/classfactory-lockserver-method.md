---
title: "M&#233;todo ClassFactory::LockServer | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::ClassFactory::LockServer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método LockServer"
ms.assetid: 8d859815-956d-4f81-a5af-7cdee7e945de
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ClassFactory::LockServer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Incrementa ou diminui o número de base de objetos que são controlados pelo objeto ClassFactory atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   LockServer  
)(BOOL fLock);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fLock`  
 `true` para incrementar o número de objetos rastreados. `false` para diminuir o número de objetos rastreados.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, E_FAIL.  
  
## <a name="remarks"></a>Comentários  
 ClassFactory mantém o controle de objetos em uma instância subjacente do [módulo](../windows/module-class.md) classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ClassFactory](../windows/classfactory-class.md)