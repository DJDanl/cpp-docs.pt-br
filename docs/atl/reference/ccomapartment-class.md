---
title: "Classe de CComApartment | Microsoft Docs"
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
  - "ATL::CComApartment"
  - "CComApartment"
  - "ATL.CComApartment"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "construção em módulos de ATL EXE"
  - "Classe de CComApartment"
ms.assetid: dbc177d7-7ee4-45f2-b563-d578a467ca93
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComApartment
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece suporte para gerenciar um compartimento com agrupados em um módulo de EXE.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CComApartment  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComApartment::CComApartment](../Topic/CComApartment::CComApartment.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComApartment::Apartment](../Topic/CComApartment::Apartment.md)|Marca o endereço inicial do segmento.|  
|[CComApartment::GetLockCount](../Topic/CComApartment::GetLockCount.md)|Retorna a contagem de bloqueio atual da thread.|  
|[CComApartment::Lock](../Topic/CComApartment::Lock.md)|Sai a contagem de bloqueio de segmento.|  
|[CComApartment::Unlock](../Topic/CComApartment::Unlock.md)|Diminui a contagem de bloqueio de segmento.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComApartment::m\_dwThreadID](../Topic/CComApartment::m_dwThreadID.md)|Contém o identificador de segmento.|  
|[CComApartment::m\_hThread](../Topic/CComApartment::m_hThread.md)|Contém o identificador de segmento.|  
|[CComApartment::m\_nLockCnt](../Topic/CComApartment::m_nLockCnt.md)|Contém a contagem de bloqueio atual da thread.|  
  
## Comentários  
 `CComApartment` é usado por [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) para gerenciar um compartimento com agrupados em um módulo de EXE.  `CComApartment` fornece métodos para incrementar e diminuir a contagem de bloqueio em um thread.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)