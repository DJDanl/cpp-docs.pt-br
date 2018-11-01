---
title: Criar programaticamente uma tabela em uma fonte de dados ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- programmatically creating ODBC tables [C++]
- tables [C++]
- ODBC data sources, creating tables in
- tables [C++], creating programmatically
ms.assetid: 9ca68fb5-c3df-424a-a75c-e3fb01cc1b18
ms.openlocfilehash: 139efb7a34baacb2bb6ad424d13f2d337eb12af6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661650"
---
# <a name="data-source-programmatically-creating-a-table-in-an-odbc-data-source"></a>Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC

Este tópico explica como criar uma tabela para seus dados de origem, usando o `ExecuteSQL` função de membro da classe `CDatabase`, passando a função de uma cadeia de caracteres que contém um **CREATE TABLE** instrução SQL.

Para obter informações gerais sobre as fontes de dados ODBC no MFC, consulte [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md). O tópico [fonte de dados: Configurando programaticamente uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-configuring-an-odbc-data-source.md) descreve a criação de fontes de dados.

Quando você tem a fonte de dados estabelecida, você pode facilmente criar tabelas usando o `ExecuteSQL` função de membro e o **CREATE TABLE** instrução SQL. Por exemplo, se você tivesse uma `CDatabase` objeto chamado `myDB`, você pode usar o seguinte código do MFC para criar uma tabela:

```
myDB.ExecuteSQL("CREATE TABLE OFFICES (OfficeID TEXT(4)" ",
                         OfficeName TEXT(10))");
```

Este exemplo de código cria uma tabela chamada "Escritórios" em que a conexão de fonte de dados do Microsoft Access mantido pelo `myDB`; a tabela contém dois campos "OfficeID" e "OfficeName".

> [!NOTE]
>  Os tipos de campo especificados na **CREATE TABLE** instrução SQL pode variar de acordo com o driver ODBC que você está usando. O programa Microsoft Query (distribuído com o Visual C++ 1.5) é uma maneira de descobrir quais tipos de campo estão disponíveis para uma fonte de dados. No Microsoft Query, clique em **arquivo**, clique em **Table_Definition**, selecione uma tabela de uma fonte de dados e examinar o tipo mostrados na **tipo** caixa de combinação. Sintaxe SQL também existe para criar índices.

## <a name="see-also"></a>Consulte também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)