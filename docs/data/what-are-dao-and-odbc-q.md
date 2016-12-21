---
title: "O que s&#227;o DAO e ODBC? | Microsoft Docs"
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
  - "DAO (Objetos de Acesso a Dados), e ODBC"
  - "ODBC, sobre ODBC"
ms.assetid: 22cc2f75-7ff6-47bc-ac56-56a40591104c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que s&#227;o DAO e ODBC?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os objetos \(DAOs\) de acesso a dados e o ODBC são as APIs que fornecem a capacidade de gravar aplicativos que é independente de qualquer sistema de gerenciamento específico da base de dados \(DBMS\).  
  
 DAO é familiar aos programadores base de dados do que usam o Microsoft Access basic ou o Microsoft Visual Basic.  DAO usa o mecanismo de base de dados do Microsoft Jet para fornecer um conjunto de objetos de acesso a dados: objetos de base de dados, objetos de tabledef e de querydef, objetos do conjunto de registros, e outros.  DAO funciona melhor com arquivos de .mdb como aqueles criados pelo Microsoft Access, mas você também pode acessar fontes de dados ODBC por meio de DAO e do mecanismo de base de dados do Microsoft Jet.  
  
 O fornece uma API ODBC que os fornecedores diferentes de base de dados implementa pelos drivers ODBC específicos ao DBMS específico.  O programa usa essa API para chamar o gerenciador de driver ODBC, que passa as chamadas para o driver apropriado.  O driver, por sua vez, interage com o DBMS usando o SQL.  
  
> [!NOTE]
>  O ODBC é um maior parte da arquitetura \(WOSA\) de padrões abertos do Microsoft Windows.  DAO é otimizado em torno do mecanismo de base de dados do Microsoft Jet, mas você ainda pode acessar ODBC e outras fontes de dados externas com esse mecanismo, e a API ODBC distintos e as classes MFC baseado nele ainda estão disponíveis e ainda têm sua função para execução em sua seleção de ferramentas da base de dados.  
  
## Consulte também  
 [Perguntas frequentes de acesso aos dados](../data/data-access-frequently-asked-questions-mfc-data-access.md)