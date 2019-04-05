---
title: 'Fonte de dados: Determinando o esquema da fonte de dados (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC data sources [C++], schema
- schemas [C++], data sources
- data sources [C++], determining schema
ms.assetid: 17284acb-eb10-4f27-9944-ad1d973c0b05
ms.openlocfilehash: c419a3ac2d870e6a85675492ee6c9b726427a0e9
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59040024"
---
# <a name="data-source-determining-the-schema-of-the-data-source-odbc"></a>Fonte de dados: Determinando o esquema da fonte de dados (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Para configurar os membros de dados em seu `CRecordset` objetos, você precisa saber o esquema da fonte de dados ao qual você está se conectando. Determinando o esquema de uma fonte de dados envolve a obtenção de uma lista de tabelas na fonte de dados, uma lista de colunas em cada tabela, o tipo de dados de cada coluna e a existência de todos os índices.

## <a name="see-also"></a>Consulte também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)<br/>
[Fonte de dados: Gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md)