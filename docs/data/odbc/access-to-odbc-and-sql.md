---
title: Acesso a ODBC e SQL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- API calls [C++], calling DAO or ODBC directly
- Windows API [C++], calling from MFC
- ODBC API functions [C++]
- ODBC API functions [C++], calling from MFC
- SQL [C++], calling ODBC API functions
- ODBC [C++], API functions
ms.assetid: 5613d7dc-00b7-4646-99ae-1116c05c52b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4fb5daa988614e7e9cb058fce183c6af5b50dd30
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33087810"
---
# <a name="access-to-odbc-and-sql"></a>Acesso a ODBC e SQL
A biblioteca Microsoft Foundation Class encapsula muitas chamadas de API do Windows e ainda permite que você chame qualquer função de API do Windows diretamente. As classes de banco de dados oferecem a mesma flexibilidade em relação a API ODBC. Enquanto as classes de banco de dados protegem as empresas de grande parte da complexidade do ODBC, você pode chamar funções API ODBC diretamente de qualquer lugar no seu programa.  
  
 Da mesma forma, as classes de banco de dados blindar de precisar trabalhar com [SQL](../../data/odbc/sql.md), mas você pode usar o SQL diretamente se desejar. Você pode personalizar objetos de conjunto de registros, passando uma instrução SQL personalizada (ou partes de configuração da instrução padrão) quando você abre o conjunto de registros. Você também pode fazer chamadas SQL diretamente usando o [ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql) função de membro de classe [CDatabase](../../mfc/reference/cdatabase-class.md).  
  
 Para obter mais informações, consulte [ODBC: chamando o funções dos API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) e [SQL: fazendo direto SQL chamadas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)