---
title: "Interface de IThreadPoolConfig | Microsoft Docs"
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
  - "IThreadPoolConfig"
  - "ATL::IThreadPoolConfig"
  - "ATL.IThreadPoolConfig"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IThreadPoolConfig"
ms.assetid: 69e642bf-6925-46e6-9a37-cce52231b1cc
caps.latest.revision: 24
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de IThreadPoolConfig
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa interface fornece métodos para configurar um pool de segmentos.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      __interface  
__declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660"))  
IThreadPoolConfig :  
public IUnknown  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetSize](../Topic/IThreadPoolConfig::GetSize.md)|Chamar esse método para obter o número de segmentos no pool.|  
|[GetTimeout](../Topic/IThreadPoolConfig::GetTimeout.md)|Chamar esse método para obter o tempo máximo em milissegundos que o pool de segmentos esperará um segmento para fechar.|  
|[SetSize](../Topic/IThreadPoolConfig::SetSize.md)|Chamar esse método para definir o número de segmentos no pool.|  
|[SetTimeout](../Topic/IThreadPoolConfig::SetTimeout.md)|Chamar esse método para definir a hora máximo em milissegundos que o pool de segmentos esperará um segmento para fechar.|  
  
## Comentários  
 Essa interface é implementada por [CThreadPool](../Topic/CThreadPool%20Class.md).  
  
## Requisitos  
 **Cabeçalho:** atlutil.h  
  
## Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe de CThreadPool](../Topic/CThreadPool%20Class.md)