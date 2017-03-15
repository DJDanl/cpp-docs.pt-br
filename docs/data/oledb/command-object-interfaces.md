---
title: "Interfaces de objeto do comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces de objeto do comando [C++]"
  - "objetos de comando [OLE DB]"
  - "OLE DB [C++], interfaces de objeto de comando"
ms.assetid: dacff5ae-252c-4f20-9ad7-4e602cc48536
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces de objeto do comando
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O objeto de comando usa a interface de `IAccessor` para especificar associações de parâmetro.  O consumidor chama `IAccessor::CreateAccessor`, passando a uma matriz de estruturas de `DBBINDING` .  `DBBINDING` contém informações sobre as associações de coluna \(como o tipo e comprimento.\)  O provedor recebe as estruturas e determina como os dados devem ser transferidos e se as conversões são necessárias.  
  
 A interface de `ICommandText` fornece uma maneira de especificar um comando de texto.  A interface de `ICommandProperties` trata todas as propriedades do comando.  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)