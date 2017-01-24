---
title: "Classes ODBC e de banco de dados | Microsoft Docs"
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
  - "classes de banco de dados [C++], ODBC"
  - "MFC [C++], ODBC e"
  - "Funções API de ODBC [C++]"
  - "Classes ODBC [C++], Classes de banco de dados MFC"
ms.assetid: b166f82d-6f85-4556-aac8-fb851235d22c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes ODBC e de banco de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes da base de dados de MFC ODBC encapsulam as chamadas de função de API ODBC se você faria normalmente em funções de membro das classes de [CDatabase](../../mfc/reference/cdatabase-class.md) e de [CRecordset](../Topic/CRecordset%20Class.md) .  Por exemplo, as sequências de chamada complexas ODBC, associar de registros retornados aos locais de armazenamento, tratar de condições de erro, e outras operações são gerenciadas por você para classes de base de dados.  No, você usa uma interface consideravelmente mais simples da classe para manipular registros por meio de um objeto do conjunto de registros.  
  
> [!NOTE]
>  As fontes de dados ODBC são acessíveis por meio das classes MFC ODBC, como descrito neste TÓPICO, ou as classes de \(DAO\) do objeto de acesso a dados de MFC.  
  
 Embora as classes da base de dados encapsulem a funcionalidade de ODBC, não fornecem um mapeamento um\-para\-um de funções de ODBC API.  As classes de base de dados fornecem um nível mais alto de abstração, modelado após os objetos de acesso a dados localizados no Microsoft Access e no Microsoft Visual Basic.  Para obter mais informações, consulte [Que é o modelo de programação da base de dados de MFC?](../../data/what-is-the-mfc-database-programming-model-q.md).  
  
## Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)