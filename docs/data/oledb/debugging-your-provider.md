---
title: "Depurando o provedor | Microsoft Docs"
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
  - "depuração [C++], provedores"
  - "Provedores OLE DB, depuração"
  - "Depurador Visual C++, depurando provedores"
  - "Depurador Visual C++"
ms.assetid: 90d4e7db-06ea-4de0-a7f4-4f3751d50d93
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Depurando o provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Há duas maneiras para depurar seu provedor:  
  
-   Como provedores são criados no processo, você pode criar um código de consumidor usando os modelos de consumidor OLE DB e etapa no provedor normalmente.  
  
-   Você pode usar o utilitário ITEST que vem com o Visual C\+\+.  
  
### Usar o utilitário ITEST  
  
1.  Abra o projeto do provedor.  
  
2.  Sobre o **projetos** menu, clique em **configurações**.  
  
3.  No **páginas de propriedade** caixa de diálogo, clique o **Depurar** guia.  
  
4.  No **Executable for Debug Session** selecione o aplicativo ITEST.  
  
5.  Definir pontos de interrupção e depuração como de costume.  
  
## Consulte também  
 [Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)