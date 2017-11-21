---
title: 'Conjunto de registros: Adicionando registros em massa (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ODBC recordsets, adding records
- recordsets, adding records
- bulk record additions to recordsets
ms.assetid: 4685f656-14b9-4f10-a1c5-147b2b89a0b4
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 937e5273a0b999672dbbc98a927d34909d04136b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-adding-records-in-bulk-odbc"></a>Conjunto de registros: adicionando registros em massa (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 O MFC [CRecordset](../../mfc/reference/crecordset-class.md) classe tem uma nova otimização que melhora a eficiência durante a adição de novos registros em massa para uma tabela.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Uma nova opção para o **dwOptions** parâmetro para o [CRecordset::Open](../../mfc/reference/crecordset-class.md#open) função de membro, **optimizeBulkAdd**, melhora o desempenho quando você está adicionando vários registros consecutivamente sem chamar **Requery** ou **fechar**. Somente os campos que são sujos antes do primeiro **atualização** chamada são marcados como sujos para subsequentes `AddNew` / **atualização** chamadas.  
  
 Se você estiver usando as classes de banco de dados para aproveitar o **:: SQLSetPos** API ODBC de função para adicionar, editar e excluir registros, essa otimização é necessário.  
  
 Se a biblioteca de cursores ODBC é carregada ou o driver ODBC não oferece suporte à adição, edição e exclusão por meio de **:: SQLSetPos**, essa otimização deve aumentar em massa adicionar o desempenho. Para ativar essa otimização, defina o **dwOptions** parâmetro o **abrir** chamada para o conjunto de registros para o seguinte:  
  
```  
appendOnly | optimizeBulkAdd  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)   
 [Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)