---
title: "M&#233;todo WeakReference::Resolve | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::WeakReference::Resolve"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Resolve"
ms.assetid: fc65a4b7-48a0-4d64-a793-37f566fdd8e7
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo WeakReference::Resolve
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
  
STDMETHOD(Resolve)  
   (REFIID riid,   
   _Deref_out_opt_ IInspectable **ppvObject  
);  
```  
  
#### Parâmetros  
 `riid`  
 Uma ID de interface  
  
 `ppvObject`  
 Quando esta operação concluir, uma cópia de referência forte atual se a contagem forte de referência for diferente de zero.  
  
## Valor de retorno  
  
-   S\_OK se essa operação é bem\-sucedida e forte a contagem de referência são zero.  O parâmetro de `ppvObject` é definido como `nullptr`.  
  
-   S\_OK se essa operação é bem\-sucedida e forte a contagem de referência são diferentes de zero.  O parâmetro de `ppvObject` é definido como a referência forte.  
  
-   Caso contrário, um HRESULT que indica o motivo dessa operação falhou.  
  
## Comentários  
 Define o ponteiro especificado ao valor de referência forte atual se a contagem forte de referência for diferente de zero.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Classe WeakReference](../windows/weakreference-class1.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)