---
title: "Fun&#231;&#227;o CreateClassFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::Details::CreateClassFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função CreateClassFactory"
ms.assetid: 772d5d1b-8872-4745-81ca-521a39564713
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o CreateClassFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma fábrica que gerencia instâncias da classe especificada.  
  
## Sintaxe  
  
```cpp  
  
template<typename Factory>  
inline HRESULT STDMETHODCALLTYPE CreateClassFactory(  
   _In_ unsigned int *flags,   
   _In_ const CreatorMap* entry,   
   REFIID riid,   
   _Outptr_ IUnknown **ppFactory  
) throw();  
  
```  
  
#### Parâmetros  
 `flags`  
 Uma combinação de uma ou mais valores de enumeração [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
 `entry`  
 Ponteiro para [CreatorMap](../windows/creatormap-structure.md) que contém informações de inicialização e do registro sobre o parâmetro `riid`.  
  
 `riid`  
 Referência a uma ID de interface  
  
 `ppFactory`  
 Se essa operação for concluída com êxito, um ponteiro para uma fábrica da classe.  
  
## Valor de Retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Um erro de afirmar é emitido se o parâmetro `Factory` do modelo não se deriva da interface IClassFactory.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)