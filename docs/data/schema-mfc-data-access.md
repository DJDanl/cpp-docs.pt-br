---
title: Esquema (acesso a dados MFC) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- structures [C++], database
- databases [C++], schema
- database schema [C++], about database schemas
- database schema [C++]
- schemas [C++], database
- structures [C++]
ms.assetid: 7d17e35f-1ccf-4853-b915-5b8c7a45b9ee
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7892d994c60e4434ee63cc26f7b1208c442088e2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="schema--mfc-data-access"></a>Esquema (Acesso a dados MFC)
Um esquema de banco de dados descreve a estrutura atual das tabelas e exibições de banco de dados no banco de dados. Em geral, código gerado pelo assistente pressupõe que o esquema para a tabela ou tabelas acessadas por um conjunto de registros não será alterado, mas as classes de banco de dados podem lidar com algumas alterações de esquema, como adicionar, reordenar ou excluir colunas não acopladas. Se uma tabela for alterada, você deve, manualmente, atualizar o conjunto de registros para a tabela e recompilar o aplicativo.  
  
 Você também pode complementar o código gerado pelo assistente para lidar com um banco de dados cujo esquema não é totalmente conhecido no momento da compilação. Para obter mais informações, consulte [conjunto de registros: dinamicamente de associação de dados colunas (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Acesso a dados (MFC/ATL) de programação](../data/data-access-programming-mfc-atl.md)   
 [SQL](../data/odbc/sql.md)   
 [Conjunto de registros (ODBC)](../data/odbc/recordset-odbc.md)