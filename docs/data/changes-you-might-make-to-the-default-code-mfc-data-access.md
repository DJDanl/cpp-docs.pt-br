---
title: Alterações que podem ser feitas ao código padrão (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views [C++], customizing default code
ms.assetid: 9992ed37-a6bf-45a5-a572-5c14e42b6628
ms.openlocfilehash: 5b8b118c5320e57f2bae5925d3df98650b0288c9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50611387"
---
# <a name="changes-you-might-make-to-the-default-code--mfc-data-access"></a>Alterações que podem ser feitas ao código padrão (Acesso a dados MFC)

O [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) grava uma classe de conjunto de registros que seleciona todos os registros em uma única tabela. Geralmente, você irá querer modificar esse comportamento em uma ou mais das seguintes maneiras:

- Defina um filtro ou uma ordem de classificação do conjunto de registros. Fazer isso no `OnInitialUpdate` depois que o objeto recordset é construído, mas antes seu `Open` função membro é chamada. Para obter mais informações, consulte [conjunto de registros: filtrando registros (ODBC)](../data/odbc/recordset-filtering-records-odbc.md) e [conjunto de registros: Classificando registros (ODBC)](../data/odbc/recordset-sorting-records-odbc.md).

- Parametrizar o conjunto de registros. Especifique o valor do parâmetro de tempo de execução real após o filtro. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../data/odbc/recordset-parameterizing-a-recordset-odbc.md)

- Passar uma cadeia de caracteres SQL personalizada para o [abrir](../mfc/reference/crecordset-class.md#open) função de membro. Para uma discussão sobre o que você pode fazer com essa técnica, consulte [SQL: SQL instrução (ODBC Personalizando seu conjunto de registros)](../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

## <a name="see-also"></a>Consulte também

[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)