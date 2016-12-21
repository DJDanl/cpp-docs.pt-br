---
title: "Classe de CComObjectGlobal | Microsoft Docs"
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
  - "CComObjectGlobal"
  - "ATL::CComObjectGlobal<Base>"
  - "ATL::CComObjectGlobal"
  - "ATL.CComObjectGlobal"
  - "ATL.CComObjectGlobal<Base>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComObjectGlobal"
ms.assetid: 79bdee55-66e4-4536-b5b3-bdf09f78b9a6
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComObjectGlobal
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe gerencia uma contagem de referência módulo que contém o objeto de `Base` .  
  
## Sintaxe  
  
```  
  
      template<  
   class Base   
>  
class CComObjectGlobal :  
   public Base  
```  
  
#### Parâmetros  
 `Base`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como qualquer outra interface você deseja oferecer suporte no objeto.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComObjectGlobal::CComObjectGlobal](../Topic/CComObjectGlobal::CComObjectGlobal.md)|o construtor.|  
|[CComObjectGlobal::~CComObjectGlobal](../Topic/CComObjectGlobal::~CComObjectGlobal.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComObjectGlobal::AddRef](../Topic/CComObjectGlobal::AddRef.md)|Implementa `AddRef`global.|  
|[CComObjectGlobal::QueryInterface](../Topic/CComObjectGlobal::QueryInterface.md)|Implementa `QueryInterface`global.|  
|[CComObjectGlobal::Release](../Topic/CComObjectGlobal::Release.md)|Implementa **Versão**global.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComObjectGlobal::m\_hResFinalConstruct](../Topic/CComObjectGlobal::m_hResFinalConstruct.md)|Contém **HRESULT** retornado durante a compilação do objeto de `CComObjectGlobal` .|  
  
## Comentários  
 `CComObjectGlobal` gerencia uma contagem de referência módulo que contém o objeto de `Base` .  `CComObjectGlobal` garante que o objeto não seja excluído enquanto o módulo não é liberado.  O objeto será removido somente quando a contagem de referência no módulo inteiro vá para zero.  
  
 Por exemplo, usando `CComObjectGlobal`, uma fábrica da classe pode conter um objeto global comuns que é compartilhada por todos seus clientes.  
  
## Hierarquia de herança  
 `Base`  
  
 `CComObjectGlobal`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComObjectStack](../Topic/CComObjectStack%20Class.md)   
 [Classe de CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe de CComObject](../../atl/reference/ccomobject-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)