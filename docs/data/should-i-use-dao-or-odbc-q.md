---
title: "Devo usar DAO ou ODBC? | Microsoft Docs"
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
  - "DAO [C++], vs. ODBC"
  - "classes de banco de dados [C++], DAO"
  - "classes de banco de dados [C++], ODBC"
  - "ODBC [C++], vs. DAO"
ms.assetid: 9f67613f-0056-4ece-8c3a-9872e9563d57
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Devo usar DAO ou ODBC?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use modelos ODBC ou OLE DB para novos projetos.  Você só deve usar DAO manter os aplicativos existentes.  
  
 O conjunto de MFC classifica você deve usar?  Isso depende das suas necessidades:  
  
-   Use as classes de ODBC se você estiver trabalhando estritamente com fontes de dados ODBC, particularmente em situações cliente\/servidor, onde as classes de MFC ODBC fornecem o melhor desempenho.  
  
-   Use as classes de DAO se você estiver trabalhando com primeiro bases de dados do Microsoft Jet \(.mdb\) ou com outros formatos de base de dados do que o mecanismo de base de dados do Microsoft Jet pode ler diretamente.  Para obter uma lista disso, consulte [Que bases de dados posso acessar com DAO e ODBC?](../data/what-data-sources-can-i-access-with-dao-and-odbc-q.md)  
  
-   Acessar fontes de dados ODBC por meio das classes de DAO quando você deseja que a velocidade do mecanismo de base de dados do Microsoft Jet e a funcionalidade adicional das classes de DAO.  
  
    > [!NOTE]
    >  DAO requer espaço de disco rígido adicional.  
  
 As classes de DAO têm as seguintes vantagens:  
  
-   Melhorar o desempenho em alguns casos, especialmente ao usar bases de dados do Microsoft Jet \(.mdb\).  
  
-   Compatibilidade com as classes de ODBC e com o Microsoft Access básico e Microsoft Visual Basic.  
  
-   Acesso às regras de validação.  
  
-   Capacidade de especificar relações entre tabelas.  
  
-   Um modelo mais rico de acesso a dados, com suporte para a linguagem de definição de dados \(DDL\) e a linguagem de manipulação de dados \(DML\).  Para obter mais informações, consulte [Definição e a manipulação do base de dados](../Topic/Are%20DDL%20and%20DML%20Supported?.md).  
  
 A tabela a seguir resume as principais diferenças para ajudá\-lo a escolher.  
  
### Escolha entre classes de MFC DAO e ODBC  
  
|Pode I|Com classes de DAO?|Com classes de ODBC?|  
|------------|-------------------------|--------------------------|  
|Acessar arquivos .MDB|Sim|Sim|  
|Fontes de dados ODBC de acesso|Sim|Sim|  
|Disponível para o de 16 bits|Não|Sim|  
|Disponível para o de 32 bits|Sim|Sim|  
|Disponível para o de 64 bits|Não|Sim|  
|Consolidação da base de dados|Sim|Não|  
|Suporte do mecanismo de base de dados|O mecanismo de base de dados do Microsoft Jet|DBMS de destino|  
|Suporte do DDL|Sim|Somente com chamadas diretos ODBC|  
|Suporte do DML|Sim|Sim|  
|Natureza da implementação de MFC|“” Funções de wrapper do DAO|Abstração simplificada em vez de um wrapper “” API ODBC|  
|Para ótimo|arquivos do Microsoft Access \(.mdb\)|Qualquer DBMS para que você tenha um driver, especialmente em situações cliente\/servidor|  
|Suporte a transações|A solução, ou para dados ODBC, no base de dados|Por base de dados|  
  
 Lembre\-se de que os recursos dos drivers ODBC variam.  Para obter mais informações, consulte *a referência* e a ajuda ODBC programmer's reference do driver ODBC.  
  
## Consulte também  
 [Perguntas frequentes de acesso aos dados](../data/data-access-frequently-asked-questions-mfc-data-access.md)