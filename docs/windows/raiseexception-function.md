---
title: "Fun&#231;&#227;o RaiseException | Microsoft Docs"
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
  - "internal/Microsoft::WRL::Details::RaiseException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função RaiseException"
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o RaiseException
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
inline void __declspec(noreturn)  
   RaiseException(  
      HRESULT hr,   
      DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);  
```  
  
#### Parâmetros  
 `hr`  
 O código de exceção de exceção que está sendo gerado; isto é, o HRESULT de uma operação com falha.  
  
 `dwExceptionFlags`  
 Um sinalizador que indica uma exceção continuable \(o valor do sinalizador é zero\), ou exceção noncontinuable \(o valor do sinalizador for diferente de zero\).  Por padrão, a exceção será noncontinuable.  
  
## Comentários  
 Gerencie uma exceção no thread de chamada.  
  
 Para obter mais informações, veja a função de **RaiseException** do windows.  
  
## Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)