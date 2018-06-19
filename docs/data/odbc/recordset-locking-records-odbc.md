---
title: 'Conjunto de registros: Bloqueando registros (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- locks [C++], recordsets
- optimistic locking
- pessimistic locking in ODBC
- recordsets [C++], locking records
- optimistic locking, ODBC
- ODBC recordsets [C++], locking records
- data [C++], locking
ms.assetid: 8fe8fcfe-b55a-41a8-9136-94a7cd1e4806
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1fcef3233e4c2035cc481128d81723dad03fb18b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33092130"
---
# <a name="recordset-locking-records-odbc"></a>Conjunto de registros: bloqueando registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica:  
  
-   [Os tipos de bloqueio de registro disponível](#_core_record.2d.locking_modes).  
  
-   [Como bloquear registros de registros durante as atualizações](#_core_locking_records_in_your_recordset).  
  
 Quando você usa um conjunto de registros para atualizar um registro na fonte de dados, seu aplicativo pode bloquear o registro para que nenhum outro usuário possa atualizar o registro ao mesmo tempo. O estado de um registro atualizado por dois usuários ao mesmo tempo é indefinido, a menos que o sistema pode garantir que dois usuários não é possível atualizar um registro simultaneamente.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você tiver implementado a busca de linhas em massa, algumas informações não se aplicam. Por exemplo, você não pode chamar o **editar** e **atualização** funções de membro. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_record.2d.locking_modes"></a> Modos de bloqueio de registro  
 As classes de banco de dados fornecem dois [modos de bloqueio de registro](../../mfc/reference/crecordset-class.md#setlockingmode):  
  
-   Otimista de bloqueio (o padrão)  
  
-   bloqueio pessimista  
  
 Atualizando um registro ocorre em três etapas:  
  
1.  Iniciar a operação chamando o [editar](../../mfc/reference/crecordset-class.md#edit) função de membro.  
  
2.  Você alterar os campos apropriados do registro atual.  
  
3.  Encerrar a operação — e normalmente confirmar a atualização — chamando o [atualizar](../../mfc/reference/crecordset-class.md#update) função de membro.  
  
 Bloqueio otimista bloqueia o registro na fonte de dados somente durante o **atualização** chamar. Se você usar o bloqueio otimista em um ambiente multiusuário, o aplicativo deve tratar uma **atualização** condição de falha. Pessimista bloqueia o registro tão logo você chamar **editar** e não liberá-lo até que você chamada **atualização** (falhas são indicadas por meio de `CDBException` mecanismo, não por um valor de **FALSE** retornado por **atualização**). Bloqueio pessimista tem uma penalidade de desempenho potencial para outros usuários, porque o acesso simultâneo ao mesmo registro talvez precise aguardar até a conclusão do seu aplicativo **atualização** processo.  
  
##  <a name="_core_locking_records_in_your_recordset"></a> Registros de bloqueio de registros  
 Se você quiser alterar um objeto de conjunto de registros [modo de bloqueio](#_core_record.2d.locking_modes) do padrão, você deve alterar o modo antes de chamar **editar**.  
  
#### <a name="to-change-the-current-locking-mode-for-your-recordset"></a>Para alterar o modo de bloqueio atual para o conjunto de registros  
  
1.  Chamar o [SetLockingMode](../../mfc/reference/crecordset-class.md#setlockingmode) função de membro, especificando o **CRecordset::pessimistic** ou **CRecordset::optimistic**.  
  
 O novo modo de bloqueio permanece em vigor até que você alterá-lo novamente, ou o conjunto de registros é fechado.  
  
> [!NOTE]
>  Drivers ODBC relativamente poucas atualmente suportam pessimista.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)