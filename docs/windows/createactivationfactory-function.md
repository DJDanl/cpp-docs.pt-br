---
title: "Fun&#231;&#227;o CreateActivationFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::Details::CreateActivationFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função CreateActivationFactory"
ms.assetid: a1a53e04-6757-4faf-a4c8-ecf06e43b959
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o CreateActivationFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma fábrica que gerencia instâncias da classe especificada que pode ser alternada por Tempo de Execução do Windows.  
  
## Sintaxe  
  
```cpp  
  
template<typename Factory>  
   inline HRESULT STDMETHODCALLTYPE CreateActivationFactory(  
      _In_ unsigned int *flags,    
      _In_ const CreatorMap* entry,   
      REFIID riid,   
     _Outptr_ IUnknown **ppFactory) throw();  
  
```  
  
#### Parâmetros  
 `flags`  
 Uma combinação de uma ou mais valores de enumeração [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
 `entry`  
 Ponteiro para [CreatorMap](../windows/creatormap-structure.md) que contém informações de inicialização e do registro sobre o parâmetro `riid`.  
  
 `riid`  
 Referência a uma ID de interface  
  
 `ppFactory`  
 Se essa operação for concluída com êxito, um ponteiro para uma fábrica de ativação.  
  
## Valor de Retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Um erro de afirmar é emitido se o parâmetro `Factory` do modelo não se deriva da interface IActivationFactory.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)