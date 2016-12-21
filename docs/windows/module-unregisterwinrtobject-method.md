---
title: "M&#233;todo Module::UnregisterWinRTObject | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module::UnregisterWinRTObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método UnregisterWinRTObject"
ms.assetid: 32334aa7-2293-40d2-9a89-4b02e2e31f3c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::UnregisterWinRTObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cancela o registro de um ou mais [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objetos para que outros aplicativos não podem se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual HRESULT UnregisterWinRTObject(  
   unsigned int,  
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cookie`  
 Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.  
  
## <a name="return-value"></a>Valor de retorno  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe de módulo](../windows/module-class.md)