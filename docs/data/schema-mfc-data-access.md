---
title: Esquema (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- structures [C++], database
- databases [C++], schema
- database schema [C++], about database schemas
- database schema [C++]
- schemas [C++], database
- structures [C++]
ms.assetid: 7d17e35f-1ccf-4853-b915-5b8c7a45b9ee
ms.openlocfilehash: cc333ee987ed0c6cba6cb11730d8f940e49d525d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039026"
---
# <a name="schema--mfc-data-access"></a>Esquema (Acesso a dados MFC)

Um esquema de banco de dados descreve a estrutura atual das tabelas e exibições de banco de dados no banco de dados. Em geral, código gerado pelo assistente pressupõe que o esquema para a tabela ou tabelas acessadas por um conjunto de registros não será alterado, mas as classes de banco de dados podem lidar com algumas alterações de esquema, como adicionar, reordenar ou excluir colunas não acopladas. Se uma tabela for alterada, você deve, manualmente, atualizar o conjunto de registros para a tabela e recompilar o aplicativo.

Você também pode complementar o código gerado pelo assistente para lidar com um banco de dados cujo esquema não é totalmente conhecido no momento da compilação. Para obter mais informações, consulte [conjunto de registros: Associando dinamicamente colunas de dados (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

## <a name="see-also"></a>Consulte também

[Acesso a dados (MFC/ATL) de programação](../data/data-access-programming-mfc-atl.md)<br/>
[SQL](../data/odbc/sql.md)<br/>
[Conjunto de registros (ODBC)](../data/odbc/recordset-odbc.md)