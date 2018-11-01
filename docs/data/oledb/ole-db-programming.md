---
title: Programação de banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- OLE DB [C++]
- data access [C++], OLE DB programming
- OLE DB [C++], about OLE DB
ms.assetid: 52a80d66-17a9-43a1-9b90-392ae43cea2b
ms.openlocfilehash: 8b56378eb93216891f4c0b540d622dbdb412b8cc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576911"
---
# <a name="ole-db-programming"></a>Programação de banco de dados OLE

Microsoft OLE DB é uma tecnologia herdada; para novos aplicativos é a API de acesso a dados necessários para servidores vinculados do SQL. Todos os outros novos aplicativos devem usar o ODBC. O provedor OLE DB atual para o SQL Server é SQLNCLI11. DLL. O provedor ainda está enviando em SQL Server 2016. Esta documentação destina-se a desenvolvedores que estão mantendo os aplicativos existentes que já usam o OLE DB.

Os modelos OLE DB são modelos de C++ que facilitam a tecnologia de banco de dados do OLE DB de alto desempenho usar, fornecendo classes que implementam muitos comumente usados interfaces OLE DB. Esta biblioteca de modelos é dividida em modelos de consumidor e provedor.

Visual C++ também tem suporte do Assistente para criação de aplicativos de início do OLE DB.

Além disso, você pode usar atributos para implementar os modelos de consumidor do OLE DB.

|Para saber mais a respeito|Consulte|
|-------------------------|---------|
|Usando os modelos de consumidor OLE DB (tópicos conceituais)|[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)|
|Usando modelos do provedor der OLE DB (tópicos conceituais)|[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)|
|Macros e classes de modelos OLE DB|[Referência de modelos OLE DB](../../data/oledb/ole-db-templates.md) (Visual C++)|
|Atributos do consumidor OLE DB |[Atributos de consumidor do OLE DB](../../windows/ole-db-consumer-attributes.md)|
|Interfaces OLE DB|[Referência do programador de OLE DB](/previous-versions/windows/desktop/ms713643(v%3dvs.85)) (no SDK do Windows)|
|Exemplos de modelos OLE DB|[Exemplos de modelos OLE DB](https://github.com/Microsoft/VCSamples)|
|Visão geral de programação (Visual C++) de acesso a dados|[Programação de acesso a dados](../../data/data-access-programming-mfc-atl.md)|
|Tópicos conceituais do ODBC|[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)|

## <a name="see-also"></a>Consulte também

[Acesso a dados](../data-access-in-cpp.md)