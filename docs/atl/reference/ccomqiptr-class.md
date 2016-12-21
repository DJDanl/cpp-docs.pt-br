---
title: "Classe de CComQIPtr | Microsoft Docs"
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
  - "ATL.CComQIPtr"
  - "ATL::CComQIPtr"
  - "CComQIPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComQIPtr"
ms.assetid: 969cacb5-05b6-4af4-b683-24911d70242d
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComQIPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe inteligente do ponteiro para gerenciar ponteiros da interface COM.  
  
## Sintaxe  
  
```  
  
      template<  
   class T,  
   const IID* piid = &__uuidof(T)  
>  
class CComQIPtr: public CComPtr<T>  
```  
  
#### Parâmetros  
 `T`  
 Uma interface COM que especifica o tipo de ponteiro para ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID de `T`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComQIPtr::CComQIPtr](../Topic/CComQIPtr::CComQIPtr.md)|Construtor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComQIPtr::operator \=](../Topic/CComQIPtr::operator%20=.md)|Atribui um ponteiro para o ponteiro de membro.|  
  
## Comentários  
 Usa `CComQIPtr` e [CComPtr](../../atl/reference/ccomptr-class.md) de ATL gerenciar os ponteiros da interface COM, ambas derivam de [CComPtrBase](../../atl/reference/ccomptrbase-class.md).  Ambas as classes realizam a contagem de referência automática com chamadas a `AddRef` e a **Versão**.  Os operadores sobrecarregados tratam operações do ponteiro.  
  
## Hierarquia de herança  
 [CComPtrBase](../../atl/reference/ccomptrbase-class.md)  
  
 [CComPtr](../../atl/reference/ccomptr-class.md)  
  
 `CComQIPtr`  
  
## Requisitos  
 **Cabeçalho:** atlcomcli.h  
  
## Consulte também  
 [CComPtr::CComPtr](../Topic/CComPtr::CComPtr.md)   
 [CComQIPtr::CComQIPtr](../Topic/CComQIPtr::CComQIPtr.md)   
 [Classe de CComPtrBase](../../atl/reference/ccomptrbase-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComQIPtrElementTraits](../Topic/CComQIPtrElementTraits%20Class.md)