---
title: "Erro MSB3254 (MSBuild) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
helpviewer_keywords: 
  - "MSB3254"
ms.assetid: cb9636b2-d9b3-466d-959c-14c7c8017a78
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "douge"
---
# Erro MSB3254 (MSBuild)
**MSB3254: O arquivo \<name\> será ignorada porque não pode ser lido.  Este arquivo foi passado a InstalledAssemblySubsetTables ou encontrado procurando a pasta de \<name\> no TargetFrameworkDirectories.**  
  
 Este erro ocorre quando o arquivo XML de [!INCLUDE[net_client_v35_long](../Token/net_client_v35_long_md.md)] , client.xml, não pode ser lido.  O arquivo é ilegível devido a danos, o bloqueio, ou para qualquer outro problema.  
  
 [!INCLUDE[net_client_v35_long](../Token/net_client_v35_long_md.md)] é um subconjunto da biblioteca em tempo de execução completa de [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] 3,5.  Para obter mais informações sobre o [!INCLUDE[net_client_v35_long](../Token/net_client_v35_long_md.md)], consulte [.NET Framework Client Profile](../Topic/.NET%20Framework%20Client%20Profile.md).  
  
 Procedimentos  
  
### Para corrigir este erro  
  
-   Garanta que você tenha permissões e acesso completo completo para o arquivo, ou reinstalar\-se a biblioteca em tempo de execução redistribuível de [!INCLUDE[net_client_v35_long](../Token/net_client_v35_long_md.md)] para substituir o arquivo corrompido.  
  
## Consulte também  
 [Elemento Project \(MSBuild\)](../Topic/Project%20Element%20\(MSBuild\).md)   
 [Recursos adicionais](../Topic/Additional%20MSBuild%20Resources.md)