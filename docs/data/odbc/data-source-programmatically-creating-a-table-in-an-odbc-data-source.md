---
title: Criar programáticamente uma tabela em uma fonte de dados ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- programmatically creating ODBC tables [C++]
- tables [C++]
- ODBC data sources, creating tables in
- tables [C++], creating programmatically
ms.assetid: 9ca68fb5-c3df-424a-a75c-e3fb01cc1b18
ms.openlocfilehash: 6cf26cad7fe39f374daf371902525087b446658c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358833"
---
# <a name="data-source-programmatically-creating-a-table-in-an-odbc-data-source"></a>Fonte de dados: criando uma tabela programaticamente em uma fonte de dados ODBC

Este tópico explica como criar uma tabela para `ExecuteSQL` sua fonte `CDatabase`de dados, usando a função de membro da classe, passando a função uma string que contém uma declaração **CREATE TABLE** SQL.

Para obter informações gerais sobre as fontes de dados da ODBC no MFC, consulte [Data Source (ODBC)](../../data/odbc/data-source-odbc.md). O tópico [Fonte de Dados: Programática Configuração de uma Fonte de Dados ODBC](../../data/odbc/data-source-programmatically-configuring-an-odbc-data-source.md) descreve a criação de fontes de dados.

Quando você tem a fonte de dados estabelecida, `ExecuteSQL` você pode facilmente criar tabelas usando a função de membro e a declaração **CREATE TABLE** SQL. Por exemplo, se `CDatabase` você `myDB`tivesse um objeto chamado, você poderia usar o seguinte código MFC para criar uma tabela:

```
myDB.ExecuteSQL("CREATE TABLE OFFICES (OfficeID TEXT(4)" ",
                         OfficeName TEXT(10))");
```

Este exemplo de código cria uma tabela chamada "OFFICES" `myDB`na conexão de origem de dados do Microsoft Access mantida por ; a tabela contém dois campos "OfficeID" e "OfficeName".

> [!NOTE]
> Os tipos de campo especificados na declaração **CREATE TABLE** SQL podem variar de acordo com o driver ODBC que você está usando. O programa Microsoft Query (distribuído com o Visual C++ 1.5) é uma maneira de descobrir quais tipos de campo estão disponíveis para uma fonte de dados. Em Consulta microsoft, clique em **Arquivo**, clique **Table_Definition,** selecione uma tabela de uma fonte de dados e veja o tipo mostrado na caixa de combinação **Tipo.** A sintaxe SQL também existe para criar índices.

## <a name="see-also"></a>Confira também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
