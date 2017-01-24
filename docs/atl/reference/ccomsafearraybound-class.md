---
title: "Classe de CComSafeArrayBound | Microsoft Docs"
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
  - "ATL.CComSafeArrayBound"
  - "ATL::CComSafeArrayBound"
  - "CComSafeArrayBound"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComSafeArrayBound"
ms.assetid: dd6299db-5f84-4630-bbf0-f5add5318437
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComSafeArrayBound
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para uma estrutura de [SAFEARRAYBOUND](http://msdn.microsoft.com/pt-br/303a9bdb-71d6-4f14-8747-84cf84936c6d) .  
  
## Sintaxe  
  
```  
  
class CComSafeArrayBound : public SAFEARRAYBOUND  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CComSafeArrayBound](../Topic/CComSafeArrayBound::CComSafeArrayBound.md)|o construtor.|  
|[GetCount](../Topic/CComSafeArrayBound::GetCount.md)|Chamar esse método para retornar o número de elementos.|  
|[GetLowerBound](../Topic/CComSafeArrayBound::GetLowerBound.md)|Chamar este método para retornar o limite inferior.|  
|[GetUpperBound](../Topic/CComSafeArrayBound::GetUpperBound.md)|Chamar este método para retornar o limite superior.|  
|[SetCount](../Topic/CComSafeArrayBound::SetCount.md)|Chamar esse método para definir o número de elementos.|  
|[SetLowerBound](../Topic/CComSafeArrayBound::SetLowerBound.md)|Chamar esse método para definir o limite inferior.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../Topic/CComSafeArrayBound::operator%20=.md)|Defina a `CComSafeArrayBound` um novo valor.|  
  
## Comentários  
 Essa classe é um wrapper para a estrutura de **SAFEARRAYBOUND** usada por [CComSafeArray](../Topic/CComSafeArray%20Class.md).  Fornece métodos para ver e definindo aos limites superior e inferior de uma única dimensão de `CComSafeArray` objeto e o número de elementos que ele contém.  Um objeto multidimensional de `CComSafeArray` usa uma matriz de objetos de `CComSafeArrayBound` , um para cada dimensão.  Portanto, ao usar métodos como [GetCount](../Topic/CComSafeArrayBound::GetCount.md), esteja ciente que este método não retornará o número total de elementos em uma matriz multidimensional.  
  
 **Cabeçalho:** atlsafe.h  
  
## Requisitos  
 **Cabeçalho:** atlsafe.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)