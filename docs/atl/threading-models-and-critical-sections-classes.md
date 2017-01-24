---
title: "Modelos de segmenta&#231;&#227;o e classes das se&#231;&#245;es cr&#237;ticos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.atl.threads.models"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, seções críticos"
  - "ATL, multithreading"
  - "seções críticos"
  - "threading [ATL], modelos"
ms.assetid: 759f05ef-6285-4be6-a2cc-78572dd75146
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de segmenta&#231;&#227;o e classes das se&#231;&#245;es cr&#237;ticos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes definem um modelo de threads e uma seção crítica:  
  
-   [CAtlAutoThreadModule](../atl/reference/catlautothreadmodule-class.md) implementa com agrupados, o servidor de apartamento\- COM o modelo.  
  
-   [CAtlAutoThreadModuleT](../atl/reference/catlautothreadmodulet-class.md) fornece métodos para implementar com agrupados, o servidor de apartamento\- COM o modelo.  
  
-   [CComMultiThreadModel](../atl/reference/ccommultithreadmodel-class.md) fornece métodos para incrementar thread\-safe e contador uma variável.  Fornece uma seção crítica.  
  
-   [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md) fornece métodos para incrementar thread\-safe e contador uma variável.  Não fornece uma seção crítica.  
  
-   [CComSingleThreadModel](../atl/reference/ccomsinglethreadmodel-class.md) fornece métodos para incrementar e contador uma variável.  Não fornece uma seção crítica.  
  
-   [CComObjectThreadModel](../Topic/CComObjectThreadModel.md) determina a classe apropriada do modelo de threads para uma única classe de objeto.  
  
-   [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md) determina a classe apropriada do modelo de threads para um objeto que seja globalmente disponível.  
  
-   [CComAutoCriticalSection](../atl/reference/ccomautocriticalsection-class.md) contém métodos para obter e definir uma seção crítica.  A seção crítica é inicializada automaticamente.  
  
-   [CComCriticalSection](../Topic/CComCriticalSection%20Class.md) contém métodos para obter e definir uma seção crítica.  A seção crítica deve ser explicitamente inicializada.  
  
-   [CComFakeCriticalSection](../atl/reference/ccomfakecriticalsection-class.md) espelha os métodos em `CComCriticalSection` sem fornecer uma seção crítica.  Os métodos em `CComFakeCriticalSection` não fazem nada.  
  
-   [CRTThreadTraits](../Topic/CRTThreadTraits%20Class.md) fornece a função de criação para um segmento de CRT.  Use esta classe se o segmento irá usar funções de CRT.  
  
-   [Win32ThreadTraits](../Topic/Win32ThreadTraits%20Class.md) fornece a função de criação para um segmento do Windows.  Use esta classe se o segmento não usará funções de CRT.  
  
## Consulte também  
 [Visão geral de classe](../atl/atl-class-overview.md)