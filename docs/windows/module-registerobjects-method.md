---
title: "M&#233;todo Module::RegisterObjects | Microsoft Docs"
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
  - "module/Microsoft::WRL::Module::RegisterObjects"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método RegisterObjects"
ms.assetid: db4077b7-068d-4534-aaa5-41b5444ccb49
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::RegisterObjects
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Registra COM ou [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objetos para outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT RegisterObjects(  
   ModuleBase* module,   
   const wchar_t* serverName);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `module`  
 Uma matriz de COM ou [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objetos.  
  
 `serverName`  
 Nome do servidor que criou os objetos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
## <a name="see-also"></a>Consulte também
[Classe de módulo](../windows/module-class.md)