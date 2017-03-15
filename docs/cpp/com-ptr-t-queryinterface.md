---
title: "_com_ptr_t::QueryInterface | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_ptr_t::QueryInterface"
  - "_com_ptr_t.QueryInterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método QueryInterface"
ms.assetid: d03292f1-6b02-40db-9756-8b0837a97319
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_ptr_t::QueryInterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função de membro `QueryInterface` de **IUnknown** no ponteiro de interface encapsulado.  
  
## Sintaxe  
  
```  
  
      template<typename _InterfaceType> HRESULT QueryInterface (  
   const IID& iid,  
   _InterfaceType*& p   
) throw ( );  
template<typename _InterfaceType> HRESULT QueryInterface (  
   const IID& iid,  
   _InterfaceType** p  
) throw( );  
```  
  
#### Parâmetros  
 `iid`  
 **IID** de um ponteiro da interface.  
  
 `p`  
 Ponteiro da interface bruto.  
  
## Comentários  
 Chama **IUnknown::QueryInterface** no ponteiro encapsulado da interface com a **IID** especificada e retorna o ponteiro bruto da interface resultante em `p`.  Essa rotina retorna `HRESULT` para indicar êxito ou falha.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)