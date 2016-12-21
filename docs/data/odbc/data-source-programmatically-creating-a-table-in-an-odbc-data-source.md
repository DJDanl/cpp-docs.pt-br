---
title: "Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC | Microsoft Docs"
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
  - "Fontes de dados ODBC, criando tabelas em"
  - "criando tabelas ODBC de forma programática [C++]"
  - "tabelas [C++]"
  - "tabelas [C++], criando de forma programática"
ms.assetid: 9ca68fb5-c3df-424a-a75c-e3fb01cc1b18
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como criar uma tabela para a fonte de dados, usando a função de membro de `ExecuteSQL` da classe `CDatabase`, passando a função uma cadeia de caracteres que contém uma instrução SQL de **CREATE TABLE** .  
  
 Para obter informações gerais sobre as fontes de dados ODBC no, consulte. [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)MFC  O tópico descreve [Fonte de dados: Configurando programaticamente uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-configuring-an-odbc-data-source.md) criar fontes de dados.  
  
 Quando você tem a fonte de dados estabelecida, você pode facilmente criar tabelas usando a função de membro de `ExecuteSQL` e a instrução SQL de **CREATE TABLE** .  Por exemplo, se você tivesse um objeto de `CDatabase` chamado `myDB`, você pode usar o seguinte código MFC para criar uma tabela:  
  
```  
myDB.ExecuteSQL("CREATE TABLE OFFICES (OfficeID TEXT(4)" ",   
                         OfficeName TEXT(10))");  
```  
  
 Este exemplo de código cria uma tabela chamada “ESCRITÓRIOS” na conexão de fonte de dados do Microsoft Access mantida por `myDB`; a tabela contém dois campos “OfficeID” e “OfficeName”.  
  
> [!NOTE]
>  Os tipos de campo especificados na instrução SQL de **CREATE TABLE** podem variar de acordo com o driver ODBC que você está usando.  O programa de consulta da Microsoft \(distribuída com o Visual C\+\+ 1,5\) é uma maneira de descobrir quais tipos de campos estão disponíveis para uma fonte de dados.  Na consulta da Microsoft, clique em **Arquivo**, clique em **Table\_Definition**, selecione uma tabela de uma fonte de dados, e observar o tipo mostrado na caixa de combinação de **Tipo** .  A sintaxe de SQL também existe para criar índices.  
  
## Consulte também  
 [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)