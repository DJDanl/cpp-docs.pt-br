---
title: "Consumidores e provedores de banco de dados OLE | Microsoft Docs"
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
  - "Consumidores OLE DB"
  - "Consumidores OLE DB, Arquitetura de dados OLE DB"
  - "Provedores OLE DB"
  - "Provedores OLE DB, Arquitetura de dados OLE DB"
  - "OLE DB, modelo de dados"
ms.assetid: 886cb39d-652b-4557-93f0-4b1b0754d8bc
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Consumidores e provedores de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A arquitetura do OLE DB usa o modelo dos consumidores os provedores e.  Um consumidor faz solicitações de dados.  Um provedor responde a essas solicitações colocando dados em um formato de tabela e retorno ao consumidor.  Qualquer chamada que o consumidor pode fazer deve ser implementado no provedor.  
  
 Definido tecnicamente, um consumidor é qualquer sistema ou código do aplicativo \(não necessariamente um componente de OLE DB\) que os dados dos acessa através do OLE DB da interface.  As interfaces são implementadas em um provedor.  Assim, um provedor é qualquer componente de software que implementar interfaces OLE DB para encapsular o acesso aos dados e o expor a outros objetos \(ou seja, consumidores\).  
  
 Em termos de funções, um consumidor chama os métodos em interfaces OLE DB; um provedor OLE DB do implementa as interfaces necessários OLE DB.  
  
 OLE DB evita os termos cliente e servidor porque essas funções nem sempre fazem sentido, especialmente em uma situação de em camadas.  Como um consumidor pode ser um componente em uma camada que funciona outro componente, chamar um componente do cliente seria confusa.  Além disso, um provedor às vezes mais atua como um driver da base de dados de um servidor.  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)