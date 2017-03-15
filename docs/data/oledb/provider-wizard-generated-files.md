---
title: "Arquivos gerados pelo Assistente do Provedor | Microsoft Docs"
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
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos gerados pelo Assistente do Provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O assistente do provedor OLE DB de ATL gerencia os seguintes arquivos.  Os tópicos a seguir usam o nome curto “MyProvider”, mas os nomes exatos de arquivo dependem da opção que você fez ao criar o provedor.  
  
|Nome do arquivo|Descrição|  
|---------------------|---------------|  
|MyProviderRS.cpp|Contém o método de `Execute` auxiliar de comando e o mapa da coluna do provedor.|  
|MyProviderDS.h|Implementa o objeto de fonte de dados.  Esse arquivo de cabeçalho contém o mapa para propriedades da fonte de dados.|  
|MyProviderRS.h|Implementa os objetos de comando e do conjunto de linhas.  Esse arquivo de cabeçalho contém o mapa para propriedades de conjunto de linhas e do comando.|  
|MyProviderSess.h|Implementa o objeto de sessão.  Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades da sessão.|  
|MyProvider.rgs|Contém os objetos registrados gerados pelo assistente do provedor OLE DB.|  
  
## Consulte também  
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)