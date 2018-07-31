---
title: As alterações que podem ser feitas ao código padrão (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views [C++], customizing default code
ms.assetid: 9992ed37-a6bf-45a5-a572-5c14e42b6628
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 29b5373bd9fb638e7ee4d20cba0c64b9354be70f
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39339192"
---
# <a name="changes-you-might-make-to-the-default-code--mfc-data-access"></a>Alterações que podem ser feitas ao código padrão (Acesso a dados MFC)
O [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) grava uma classe de conjunto de registros que seleciona todos os registros em uma única tabela. Geralmente, você irá querer modificar esse comportamento em uma ou mais das seguintes maneiras:  
  
-   Defina um filtro ou uma ordem de classificação do conjunto de registros. Fazer isso no `OnInitialUpdate` depois que o objeto recordset é construído, mas antes seu `Open` função membro é chamada. Para obter mais informações, consulte [conjunto de registros: filtrando registros (ODBC)](../data/odbc/recordset-filtering-records-odbc.md) e [conjunto de registros: Classificando registros (ODBC)](../data/odbc/recordset-sorting-records-odbc.md).  
  
-   Parametrizar o conjunto de registros. Especifique o valor do parâmetro de tempo de execução real após o filtro. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../data/odbc/recordset-parameterizing-a-recordset-odbc.md)  
  
-   Passar uma cadeia de caracteres SQL personalizada para o [abrir](../mfc/reference/crecordset-class.md#open) função de membro. Para uma discussão sobre o que você pode fazer com essa técnica, consulte [SQL: SQL instrução (ODBC Personalizando seu conjunto de registros)](../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)