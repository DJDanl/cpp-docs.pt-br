---
title: "Quais origens de dados posso acessar com DAO e ODBC? | Microsoft Docs"
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
  - "DAO [C++], tipos de fonte de dados"
  - "dados [C++], DAO"
  - "dados [C++], ODBC"
  - "acesso a dados [C++], DAO"
  - "fonte de dados [C++], acessível com DAO e ODBC"
  - "bancos de dados [C++], acessando em DAO"
  - "Perguntas frequentes [C++], bancos de dados acessíveis"
  - "ODBC [C++], fontes de dados acessíveis"
  - "Fonte de dados ODBC [C++], acessível"
ms.assetid: c88abb45-526a-467a-a01b-d9396bd63236
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quais origens de dados posso acessar com DAO e ODBC?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ambos os conjuntos de classes de MFC permitem acessar uma ampla variedade de fontes de dados e torná\-la possível gravar aplicativos que são independentes da fonte de dados.  
  
##  <a name="_core_databases_you_can_access_with_dao"></a> Bases de dados que você pode acessar com DAO  
 Usando DAO e classes de MFC DAO, você pode acessar as seguintes fontes de dados:  
  
-   Bases de dados usando o mecanismo de base de dados do Microsoft Jet, criado com o Microsoft Access ou o Microsoft Visual Basic, versões 1.x, 2.x, e 3,0 do mecanismo de base de dados.  
  
-   Bases de dados de instaláveis ISAM, incluindo:  
  
    -   dBASE III, dBASE IV, e dBASE 5,0  
  
    -   Paradox, versões 3.x, 4.x, e 5.x  
  
-   Bases de dados de ODBC, incluindo mas não limitam a Microsoft SQL Server, em um servidor de SYBASE o SQL Server, e de ORACLE.  Para acessar um base de dados ODBC, você deve ter um driver ODBC apropriado para o base de dados que você deseja acessar.  Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C\+\+ e para obter informações sobre como obter drivers adicionais, consulte [Lista de driver ODBC](../data/odbc/odbc-driver-list.md).  
  
-   O Microsoft Excel, planilhas de versões, 3,0, 4,0, 5,0 e 7,0.  
  
-   Planilhas WKS, WK1, WK3, e WK4 de Lotus.  
  
-   Arquivos de texto.  
  
 DAO é usado com melhor bases de dados do que o mecanismo de base de dados do Microsoft Jet pode ler, que inclui qualquer acima exceto fontes de dados ODBC.  O desempenho é melhor com bases de dados do Microsoft Jet \(.mdb\).  Anexar tabelas externas, principalmente nas fontes de dados ODBC, em uma base de dados .mdb é mais eficiente do que abriu o base de dados externo diretamente pelas classes MFC DAO sem anexar.  
  
##  <a name="_core_databases_you_can_access_with_odbc"></a> Bases de dados que você pode acessar com ODBC  
 Usando o ODBC e classes de MFC ODBC, você pode acessar qualquer fonte de dados, local ou remotamente, para que o usuário do aplicativo tenha um driver ODBC. os drivers ODBC de 16 bits, de 32 bits e de 64 bits, estão disponíveis para uma ampla variedade de fontes de dados.  Se você estiver trabalhando com uma base de dados do Microsoft Jet \(.mdb\), é mais eficaz usar as classes de DAO do que o driver ODBC do Microsoft Access.  
  
## Consulte também  
 [Perguntas frequentes de acesso aos dados](../data/data-access-frequently-asked-questions-mfc-data-access.md)