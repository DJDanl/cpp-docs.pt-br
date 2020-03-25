---
title: Acesso a ODBC e SQL
ms.date: 11/04/2016
helpviewer_keywords:
- API calls [C++], calling DAO or ODBC directly
- Windows API [C++], calling from MFC
- ODBC API functions [C++]
- ODBC API functions [C++], calling from MFC
- SQL [C++], calling ODBC API functions
- ODBC [C++], API functions
ms.assetid: 5613d7dc-00b7-4646-99ae-1116c05c52b4
ms.openlocfilehash: 0b590ce9309cbbe95285001cc5befe70a1d1961f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213324"
---
# <a name="access-to-odbc-and-sql"></a>Acesso a ODBC e SQL

O biblioteca MFC encapsula muitas chamadas à API do Windows e ainda permite que você chame qualquer função da API do Windows diretamente. As classes de banco de dados oferecem a mesma flexibilidade em relação à API ODBC. Embora as classes de banco de dados protejam você de grande parte da complexidade do ODBC, você pode chamar funções da API do ODBC diretamente de qualquer lugar em seu programa.

Da mesma forma, as classes de banco de dados protegem você de ter que trabalhar muito com o [SQL](../../data/odbc/sql.md), mas você pode usar o SQL diretamente se desejar. Você pode personalizar objetos Recordset passando uma instrução SQL personalizada (ou definindo partes da instrução padrão) ao abrir o conjunto de registros. Você também pode fazer chamadas SQL diretamente usando a função membro [ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql) da classe [CDatabase](../../mfc/reference/cdatabase-class.md).

Para obter mais informações, consulte [ODBC: chamando funções da API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) e [SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md).

## <a name="see-also"></a>Confira também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)
