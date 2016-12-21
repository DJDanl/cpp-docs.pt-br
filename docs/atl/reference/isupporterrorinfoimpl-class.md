---
title: "Classe de ISupportErrorInfoImpl | Microsoft Docs"
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
  - "ATL::ISupportErrorInfoImpl<piid>"
  - "ATL::ISupportErrorInfoImpl"
  - "ISupportErrorInfoImpl"
  - "ATL.ISupportErrorInfoImpl<piid>"
  - "ATL.ISupportErrorInfoImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "informações de erro, ATL"
  - "Implementação de ISupportErrorInfo ATL"
  - "Classe de ISupportErrorInfoImpl"
ms.assetid: e33a4b11-a123-41cf-bcea-7b19743902af
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de ISupportErrorInfoImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma implementação padrão de [ISupportErrorInfo Interface](http://msdn.microsoft.com/pt-br/42d33066-36b4-4a5b-aa5d-46682e560f32) e pode ser usada quando apenas uma única interface gera erros em um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template<  
const IID* piid   
>  
class ATL_NO_VTABLE ISupportErrorInfoImpl :  
public ISupportErrorInfo  
```  
  
#### Parâmetros  
 `piid`  
 Um ponteiro para o IID de uma interface que suporte [IErrorInfo](http://msdn.microsoft.com/pt-br/4dda6909-2d9a-4727-ae0c-b5f90dcfa447).  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](../Topic/ISupportErrorInfoImpl::InterfaceSupportsErrorInfo.md)|Indica se a interface identificada por `riid` oferece suporte a interface de [IErrorInfo](http://msdn.microsoft.com/pt-br/4dda6909-2d9a-4727-ae0c-b5f90dcfa447) .|  
  
## Comentários  
 [ISupportErrorInfo Interface](http://msdn.microsoft.com/pt-br/42d33066-36b4-4a5b-aa5d-46682e560f32) garante que as informações de erro pode ser retornada para o cliente.  Os objetos que usam **IErrorInfo** devem implementar **ISupportErrorInfo**.  
  
 A classe `ISupportErrorInfoImpl` fornece uma implementação padrão de **ISupportErrorInfo** e pode ser usada quando apenas uma única interface gera erros em um objeto.  Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/CPP/isupporterrorinfoimpl-class_1.h)]  
  
## Hierarquia de herança  
 `ISupportErrorInfo`  
  
 `ISupportErrorInfoImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)