---
title: "O que &#233; modelo de programa&#231;&#227;o de banco de dados MFC? | Microsoft Docs"
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
  - "DAO [C++], MFC"
  - "acesso a dados [C++], tecnologias"
  - "bancos de dados [C++], MFC"
  - "MFC [C++], aplicativos de banco de dados"
  - "ODBC [C++], MFC"
  - "Classes ODBC [C++], Classes de banco de dados MFC"
ms.assetid: f6f15bb8-4115-41f2-ad68-036e74a11bd9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que &#233; modelo de programa&#231;&#227;o de banco de dados MFC?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora o MFC implementa DAO e ODBC bastante diferente subjacentes, têm as interfaces semelhantes que ele relativamente fácil de mover um do outro seus aplicativos, particularmente ODBC a DAO.  Para obter informações sobre como mover ODBC a DAO, consulte [Observação 55 técnica](../Topic/TN055:%20Migrating%20MFC%20ODBC%20Database%20Class%20Applications%20to%20MFC%20DAO%20Classes.md).  As interfaces de DAO e ODBC em MFC também são muito semelhantes às de no Visual Basic.  
  
 O modelo de programação MFC fornece um objeto base de dados de cada uma base de dados aberto.  O objeto base de dados representa a conexão com o base de dados.  Você faz consultas e atualizações usando objetos do conjunto de registros.  DAO fornece os objetos adicionais, para trabalhar com estrutura de tabela, salvando consulta para reutilização, e assim por diante, descrito posteriormente.  MFC O fornece classes para cada um desses objetos: um conjunto de classes que definem DAO e outro para ODBC.  
  
 Usar o MFC facilita o acesso a dados.  As classes da base de dados de DAO e ODBC fornecem as abstrações de alto nível que o liberam de usar DAO ou ODBC diretamente.  Gravar nas APIs é mais complexo do que usar as classes MFC.  Isso é especialmente verdadeiro se você for pequena, escrever aplicativos relativamente simples.  
  
 As classes de base de dados adicionam os seguintes componentes na biblioteca MFC da classe:  
  
-   Classes da base de dados do C\+\+ que fornecem API de alto nível para acessar bases de dados com DAO ou ODBC  
  
-   Extensões do assistente de aplicativo e **Adicionar Classe** para criar classes específicos do aplicativo de base de dados  
  
-   Programas de exemplo que ilustram o uso de classes e dos assistentes  
  
-   Documentação online que inclui visões gerais, artigos sobre tópicos de programação, e materiais de referência de classe  
  
 Para obter mais informações sobre esses componentes, consulte [ODBC e MFC](../data/odbc/odbc-and-mfc.md).  
  
 Para obter mais informações, consulte:  
  
-   [Escolha entre DAO e ODBC](../data/should-i-use-dao-or-odbc-q.md).  
  
-   [Disponibilidade do idioma \(DDL\) da base de definição de dados \(DML\) e linguagem de manipulação de base de dados](../Topic/Are%20DDL%20and%20DML%20Supported?.md) em DAO e ODBC.  
  
-   [Instalando o suporte da base de dados de MFC](../data/installing-mfc-database-support.md).  
  
-   As classes de [ODBC](../data/odbc/odbc-and-mfc.md) MFC no.  
  
-   [Documentação de programação de acesso a dados MFC](../data/mfc-database-documentation.md).  
  
-   [Como o ODBC implementa MFC](../data/odbc/odbc-and-mfc.md).  
  
## Consulte também  
 [Perguntas frequentes de acesso aos dados](../data/data-access-frequently-asked-questions-mfc-data-access.md)