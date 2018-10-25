---
title: Esquema (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- structures [C++], database
- databases [C++], schema
- database schema [C++], about database schemas
- database schema [C++]
- schemas [C++], database
- structures [C++]
ms.assetid: 7d17e35f-1ccf-4853-b915-5b8c7a45b9ee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 597b3870dbfc70b6e1ac392a45491ee0f1804c2f
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055418"
---
# <a name="schema--mfc-data-access"></a>Esquema (Acesso a dados MFC)

Um esquema de banco de dados descreve a estrutura atual das tabelas e exibições de banco de dados no banco de dados. Em geral, código gerado pelo assistente pressupõe que o esquema para a tabela ou tabelas acessadas por um conjunto de registros não será alterado, mas as classes de banco de dados podem lidar com algumas alterações de esquema, como adicionar, reordenar ou excluir colunas não acopladas. Se uma tabela for alterada, você deve, manualmente, atualizar o conjunto de registros para a tabela e recompilar o aplicativo.

Você também pode complementar o código gerado pelo assistente para lidar com um banco de dados cujo esquema não é totalmente conhecido no momento da compilação. Para obter mais informações, consulte [conjunto de registros: dinamicamente associando dados colunas (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

## <a name="see-also"></a>Consulte também

[Acesso a dados (MFC/ATL) de programação](../data/data-access-programming-mfc-atl.md)<br/>
[SQL](../data/odbc/sql.md)<br/>
[Conjunto de registros (ODBC)](../data/odbc/recordset-odbc.md)