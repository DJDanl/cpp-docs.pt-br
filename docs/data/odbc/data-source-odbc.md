---
title: Fonte de dados (ODBC)
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC data sources, configuring
- CDatabase class, data source connections
- ODBC data sources
- configuring ODBC data sources
- ODBC data sources, represented by CDatabase
ms.assetid: b246721f-b9e1-49bd-a6c7-f348b8c3d537
ms.openlocfilehash: ed9eeb8f5ef0d53846761062cf2c6575d2eaf9e6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213287"
---
# <a name="data-source-odbc"></a>Fonte de dados (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Em termos de banco de dados, uma fonte de dado é um conjunto específico de dados, as informações necessárias para acessar esses dados e o local da fonte de dados, que pode ser descrito usando um nome de fonte de dados. Para trabalhar com a classe [CDatabase](../../mfc/reference/cdatabase-class.md), a fonte de dados deve ser aquela que você configurou por meio do Administrador ODBC (Open Database Connectivity). Exemplos de fontes de dados incluem um banco de dado remoto em execução no Microsoft SQL Server em uma rede ou um arquivo do Microsoft Access em um diretório local. Em seu aplicativo, você pode acessar qualquer fonte de dados para a qual você tem um driver ODBC.

Você pode ter uma ou mais fontes de dados ativas em seu aplicativo ao mesmo tempo, cada uma representada por um objeto `CDatabase`. Você também pode ter várias conexões simultâneas com qualquer fonte de dados. Você pode se conectar a fontes de dados remotas e locais, dependendo dos drivers que você instalou e dos recursos de seus drivers ODBC. Para obter mais informações sobre fontes de dados e o Administrador ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md) e [ODBC Administrator](../../data/odbc/odbc-administrator.md).

Os tópicos a seguir explicam mais sobre fontes de dados:

- [Fonte de dados: gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md)

- [Fonte de dados: determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)
