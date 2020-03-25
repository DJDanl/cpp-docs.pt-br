---
title: Selecionando e manipulando registros
ms.date: 05/09/2019
helpviewer_keywords:
- records, selecting
- record selection, MFC ODBC classes
- ODBC recordsets, selecting records
ms.assetid: 7f0b3a4a-9941-4475-a612-9ec8d15b7691
ms.openlocfilehash: 596ee602b5358fbd854888f43f21748fd4d85b7a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212700"
---
# <a name="selecting-and-manipulating-records"></a>Selecionando e manipulando registros

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Normalmente, quando você seleciona registros de uma fonte de dados usando uma instrução **SELECT** SQL, você obtém um conjunto de resultados, que é um conjunto de registros de uma tabela ou de uma consulta. Com as classes de banco de dados, você usa um objeto de conjunto de registros para selecionar e acessar o conjunto de resultados. Este é um objeto de uma classe específica do aplicativo derivada da classe [CRecordset](../../mfc/reference/crecordset-class.md). Quando você define uma classe de conjunto de registros, especifica a fonte de dados à qual associá-la, a tabela a ser usada e as colunas da tabela. O Assistente de Aplicativo MFC ou **Adicionar Classe** (conforme descrito em [Como adicionar um consumidor ODBC do MFC)](../../mfc/reference/adding-an-mfc-odbc-consumer.md) cria uma classe com uma conexão com uma fonte de dados específica. Os assistentes escrevem a função de membro [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql) da classe `CRecordset` para retornar o nome da tabela.

Usando um objeto [CRecordset](../../mfc/reference/crecordset-class.md) em tempo de execução, você pode:

- Examinar os campos de dados do registro atual.

- Filtrar ou classificar o conjunto de registros.

- Personalizar a instrução **SELECT** SQL padrão.

- Rolar até os registros selecionados.

- Adicionar, atualizar ou excluir registros (se a fonte de dados e o conjunto de registros forem atualizáveis).

- Testar se o conjunto de registros permite a repetição de consulta e atualizar o conteúdo do conjunto de registros.

Quando você termina de usar o objeto de conjunto de registros, feche-o e destrua-o. Para saber mais sobre conjuntos de registros, confira [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md).

## <a name="see-also"></a>Confira também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)
