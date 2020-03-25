---
title: Criar programaticamente uma tabela em uma fonte de dados ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- programmatically creating ODBC tables [C++]
- tables [C++]
- ODBC data sources, creating tables in
- tables [C++], creating programmatically
ms.assetid: 9ca68fb5-c3df-424a-a75c-e3fb01cc1b18
ms.openlocfilehash: 25c975560d6a73ce67294d97830b2f5bec9cd635
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213272"
---
# <a name="data-source-programmatically-creating-a-table-in-an-odbc-data-source"></a>Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC

Este tópico explica como criar uma tabela para sua fonte de dados, usando a função de membro `ExecuteSQL` da classe `CDatabase`, passando a função uma cadeia de caracteres que contém uma instrução SQL **CREATE TABLE** .

Para obter informações gerais sobre fontes de dados ODBC no MFC, consulte [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md). A fonte de dados do tópico [: configurar programaticamente uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-configuring-an-odbc-data-source.md) descreve como criar fontes de dados.

Quando a fonte de dados for estabelecida, você poderá criar tabelas facilmente usando a função de membro `ExecuteSQL` e a instrução SQL **CREATE TABLE** . Por exemplo, se você tivesse um objeto `CDatabase` chamado `myDB`, poderá usar o seguinte código MFC para criar uma tabela:

```
myDB.ExecuteSQL("CREATE TABLE OFFICES (OfficeID TEXT(4)" ",
                         OfficeName TEXT(10))");
```

Este exemplo de código cria uma tabela chamada "escritórios" na conexão de fonte de dados do Microsoft Access mantida pelo `myDB`; a tabela contém dois campos "OfficeId" e "OfficeName".

> [!NOTE]
>  Os tipos de campo especificados na instrução SQL **CREATE TABLE** podem variar de acordo com o driver ODBC que você está usando. O programa Microsoft Query (distribuído com o C++ Visual 1,5) é uma maneira de descobrir quais tipos de campo estão disponíveis para uma fonte de dados. No Microsoft Query, clique em **arquivo**, clique em **Table_Definition**, selecione uma tabela de uma fonte de dados e examine o tipo mostrado na caixa de combinação **tipo** . A sintaxe SQL também existe para criar índices.

## <a name="see-also"></a>Confira também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
