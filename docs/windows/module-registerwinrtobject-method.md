---
title: "M&#233;todo Module::RegisterWinRTObject | Microsoft Docs"
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
  - "module/Microsoft::WRL::Module::RegisterWinRTObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método RegisterWinRTObject"
ms.assetid: a2782c9c-b9c5-4e4b-9c8d-ef513aea20c5
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::RegisterWinRTObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Registra um ou mais [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objetos para outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT RegisterWinRTObject(const wchar_t* serverName,  
   wchar_t** activatableClassIds,  
   WINRT_REGISTRATION_COOKIE* cookie,  
   unsigned int count)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `serverName`  
 Um nome que especifica um subconjunto dos objetos afetados por esta operação.  
  
 `activatableClassIds`  
 Uma matriz de ativável CLSIDs para registrar.  
  
 `cookie`  
 Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revogar o registro.  
  
 `count`  
 O número de objetos a registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um erro HRESULT, como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe de módulo](../windows/module-class.md)