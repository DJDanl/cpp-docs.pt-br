---
title: Criar uma tabela programaticamente em uma fonte de dados ODBC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- programmatically creating ODBC tables [C++]
- tables [C++]
- ODBC data sources, creating tables in
- tables [C++], creating programmatically
ms.assetid: 9ca68fb5-c3df-424a-a75c-e3fb01cc1b18
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5ea8ddc8e683c0e5f0681bdf98cbddca180e4023
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33090504"
---
# <a name="data-source-programmatically-creating-a-table-in-an-odbc-data-source"></a>Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC
Este tópico explica como criar uma tabela de dados de origem, usando o `ExecuteSQL` função de membro de classe `CDatabase`, passando a função de uma cadeia de caracteres que contém um **CREATE TABLE** instrução SQL.  
  
 Para obter informações gerais sobre as fontes de dados ODBC em MFC, consulte [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md). O tópico [fonte de dados: Configurando programaticamente uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-configuring-an-odbc-data-source.md) descreve criar fontes de dados.  
  
 Quando você tem a fonte de dados estabelecida, você pode facilmente criar tabelas usando o `ExecuteSQL` função de membro e o **CREATE TABLE** instrução SQL. Por exemplo, se você tivesse um `CDatabase` objeto chamado `myDB`, você pode usar o seguinte código do MFC para criar uma tabela:  
  
```  
myDB.ExecuteSQL("CREATE TABLE OFFICES (OfficeID TEXT(4)" ",   
                         OfficeName TEXT(10))");  
```  
  
 Este exemplo de código cria uma tabela chamada "Escritórios" em que a conexão de fonte de dados Microsoft Access mantida pelo `myDB`; a tabela contém dois campos "OfficeID" e "OfficeName".  
  
> [!NOTE]
>  Os tipos de campo especificados no **CREATE TABLE** instrução SQL pode variar de acordo com o driver ODBC que você está usando. O programa Microsoft Query (distribuído com 1.5 do Visual C++) é uma maneira de descobrir que tipos de campo estão disponíveis para uma fonte de dados. No Microsoft Query, clique em **arquivo**, clique em **Table_Definition**, selecione uma tabela de uma fonte de dados e olhar o tipo mostrado o **tipo** caixa de combinação. Também existe uma sintaxe SQL para criar índices.  
  
## <a name="see-also"></a>Consulte também  
 [Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)