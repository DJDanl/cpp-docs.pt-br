---
title: 'Fonte de dados: determinando o esquema da fonte de dados (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC data sources [C++], schema
- schemas [C++], data sources
- data sources [C++], determining schema
ms.assetid: 17284acb-eb10-4f27-9944-ad1d973c0b05
ms.openlocfilehash: ed6500c5718cf90b39600b12659a3090fe9532ce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50580734"
---
# <a name="data-source-determining-the-schema-of-the-data-source-odbc"></a>Fonte de dados: determinando o esquema da fonte de dados (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Para configurar os membros de dados em seu `CRecordset` objetos, você precisa saber o esquema da fonte de dados ao qual você está se conectando. Determinando o esquema de uma fonte de dados envolve a obtenção de uma lista de tabelas na fonte de dados, uma lista de colunas em cada tabela, o tipo de dados de cada coluna e a existência de todos os índices.

## <a name="see-also"></a>Consulte também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)<br/>
[Fonte de dados: gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md)