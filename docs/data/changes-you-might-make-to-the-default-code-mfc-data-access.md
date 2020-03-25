---
title: Alterações que podem ser feitas ao código padrão (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views [C++], customizing default code
ms.assetid: 9992ed37-a6bf-45a5-a572-5c14e42b6628
ms.openlocfilehash: 7ea616caf176cd1e9e2f26bee1339640067b4e3e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213454"
---
# <a name="changes-you-might-make-to-the-default-code--mfc-data-access"></a>Alterações que podem ser feitas ao código padrão (Acesso a dados MFC)

O [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) grava uma classe recordset para você que seleciona todos os registros em uma única tabela. Geralmente, você irá querer modificar esse comportamento em uma ou mais das seguintes maneiras:

- Defina um filtro ou uma ordem de classificação do conjunto de registros. Faça isso em `OnInitialUpdate` depois que o objeto Recordset for construído, mas antes de sua função de membro `Open` ser chamada. Para obter mais informações, consulte conjunto de registros [: filtrando registros (ODBC)](../data/odbc/recordset-filtering-records-odbc.md) e conjunto de registros [: classificando registros (ODBC)](../data/odbc/recordset-sorting-records-odbc.md).

- Parametrizar o conjunto de registros. Especifique o valor do parâmetro de tempo de execução real após o filtro. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../data/odbc/recordset-parameterizing-a-recordset-odbc.md)

- Passe uma cadeia de caracteres SQL personalizada para a função de membro [Open](../mfc/reference/crecordset-class.md#open) . Para obter uma discussão sobre o que você pode realizar com essa técnica, consulte [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

## <a name="see-also"></a>Confira também

[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)
