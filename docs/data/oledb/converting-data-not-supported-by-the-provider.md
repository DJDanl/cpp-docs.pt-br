---
title: "Dados de convers&#227;o n&#227;o suportados pelo provedor | Microsoft Docs"
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
  - "modelos de provedor do OLE DB, tipos de dados sem suporte"
ms.assetid: f495e50f-530a-4fab-ab54-e0c359785845
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dados de convers&#227;o n&#227;o suportados pelo provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando o consumidor solicita um tipo de dados que não é suportada pelo provedor, o código do modelo do provedor OLE DB para `IRowsetImpl::GetData` chama Msdadc.dll para converter o tipo de dados.  
  
 Se você implementa uma interface como `IRowsetChange` que requerem a conversão de dados, você pode chamar Msdaenum.dll para fazer a conversão.  Use `GetData`, definido em Atldb.h, como um exemplo.  
  
## Consulte também  
 [Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)