---
title: "M&#233;todo RuntimeClassBaseT::GetImplementedIIDS | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetImplementedIIDS"
ms.assetid: adae54da-521d-4add-87f5-242fbd85f33b
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClassBaseT::GetImplementedIIDS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
__forceinline static HRESULT GetImplementedIIDS(  
   _In_ T* implements,  
   _Out_ ULONG *iidCount,  
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids  
);  
```  
  
#### Parâmetros  
 `T`  
 O tipo do parâmetro de `implements` .  
  
 `implements`  
 Ponteiro para o tipo especificado pelo parâmetro `T`.  
  
 `iidCount`  
 O número máximo de IDs de interface a ser recuperado.  
  
 `iids`  
 Se essa operação for concluída com êxito, uma matriz de IDs de interface implementado pelo tipo `T`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que descreve o erro.  
  
## Comentários  
 Recupera uma matriz de IDs da interface que são implementados por um tipo especificado.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)