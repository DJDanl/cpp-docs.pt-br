---
title: "Melhorando o provedor somente leitura simples | Microsoft Docs"
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
  - "Classe IRowsetLocate"
  - "Classe IRowsetLocate, adicionando a provedores de modelo OLE DB"
  - "provedores somente leitura [C++]"
  - "provedores somente leitura simples [C++]"
ms.assetid: cba0e09f-44c1-41c1-9456-332aa13dc158
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Melhorando o provedor somente leitura simples
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta seção mostra como aprimorar [provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) criado na seção anterior.  `IRowsetLocateImpl` cria uma implementação da interface de `IRowsetLocate` e adiciona suporte do medidor para você.  
  
 Quando você tem um provedor de funcionamento, talvez você queira aprimorar\-lo para fazer a atualização do provedor, trata transações, ou aprimora o desempenho do algoritmo de busca.  A maioria dos aprimoramentos do provedor envolvem adicionar uma interface para um objeto COM existente.  
  
 O exemplo nos seguintes tópicos aprimora o mecanismo de busca adicionando a interface de `IRowsetLocate` a `CAgentRowset`.  Os tópicos a seguir mostram como:  
  
-   [Faça RMyProviderRowset herdar de IRowsetLocate](../../data/oledb/modifying-the-inheritance-of-rmyproviderrowset.md).  
  
-   [Determinar dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## Consulte também  
 [Criando um provedor somente leitura simples](../../data/oledb/creating-a-simple-read-only-provider.md)