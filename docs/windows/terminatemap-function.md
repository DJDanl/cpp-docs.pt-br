---
title: "Fun&#231;&#227;o TerminateMap | Microsoft Docs"
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
  - "module/Microsoft::WRL::Details::TerminateMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função TerminateMap"
ms.assetid: 1c314a61-da5d-49bb-ac44-c34ee3c23b66
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o TerminateMap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline bool TerminateMap(  
   _In_ ModuleBase *module,   
   _In_opt_z_ const wchar_t *serverName,   
    bool forceTerminate) throw()  
```  
  
## <a name="parameters"></a>Parâmetros  
 `module`  
 Um [módulo](../windows/module-class.md).  
  
 `serverName`  
 O nome de um subconjunto de fábricas de classe no módulo especificado pelo parâmetro `module`.  
  
 `forceTerminate`  
 `true` Para encerrar a classe fábricas, independentemente de eles estão ativas; `false` não encerrar as fábricas de classe se qualquer factory está ativa.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se todas as fábricas de classe foram finalizadas. Caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Fecha as fábricas de classe no módulo especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)