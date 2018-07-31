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
ms.openlocfilehash: 344f567ab014fc854dcb44eebadcd7346af8e851
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39339978"
---
# <a name="recordset-locking-records-odbc"></a>Conjunto de registros: bloqueando registros (ODBC)
Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica:  
  
-   [Os tipos de bloqueio de registros disponíveis](#_core_record.2d.locking_modes).  
  
-   [Como bloquear registros em seu conjunto de registros durante as atualizações](#_core_locking_records_in_your_recordset).  
  
 Quando você usa um conjunto de registros para atualizar um registro na fonte de dados, seu aplicativo pode bloquear o registro para que nenhum outro usuário possa atualizar o registro ao mesmo tempo. O estado de um registro atualizado por dois usuários ao mesmo tempo é indefinido, a menos que o sistema pode garantir que dois usuários não é possível atualizar um registro ao mesmo tempo.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você tiver implementado a busca de linhas em massa, algumas informações não se aplica. Por exemplo, você não pode chamar o `Edit` e `Update` funções de membro. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_record.2d.locking_modes"></a> Modos de bloqueio de registros  
 As classes de banco de dados fornecem dois [modos de bloqueio de registros](../../mfc/reference/crecordset-class.md#setlockingmode):  
  
-   Otimista de bloqueio (padrão)  
  
-   Bloqueio pessimista  
  
 Atualizando um registro ocorre em três etapas:  
  
1.  Iniciar a operação chamando o [editar](../../mfc/reference/crecordset-class.md#edit) função de membro.  
  
2.  Você alterar os campos apropriados do registro atual.  
  
3.  Encerrar a operação — e normalmente confirmar a atualização — chamando o [atualizar](../../mfc/reference/crecordset-class.md#update) função de membro.  
  
 Bloqueio otimista bloqueia o registro na fonte de dados somente durante o `Update` chamar. Se você usar o bloqueio otimista em um ambiente multiusuário, o aplicativo deve tratar um `Update` condição de falha. Bloqueio pessimista bloqueia o registro, assim que você chame `Edit` e não liberá-lo até que você chamada `Update` (falhas são indicadas por meio das `CDBException` mecanismo, não por um valor FALSE retornado por `Update`). Bloqueio pessimista tem uma penalidade de desempenho potencial para outros usuários, porque o acesso simultâneo ao mesmo registro talvez seja necessário esperar até a conclusão do seu aplicativo `Update` processo.  
  
##  <a name="_core_locking_records_in_your_recordset"></a> Bloqueio de registros no seu conjunto de registros  
 Se você quiser alterar um objeto de conjunto de registros [modo de bloqueio](#_core_record.2d.locking_modes) do padrão, você deve alterar o modo antes de chamar `Edit`.  
  
#### <a name="to-change-the-current-locking-mode-for-your-recordset"></a>Para alterar o modo de bloqueio atual para seu conjunto de registros  
  
1.  Chame o [SetLockingMode](../../mfc/reference/crecordset-class.md#setlockingmode) função de membro, especificando a `CRecordset::pessimistic` ou `CRecordset::optimistic`.  
  
 O novo modo de bloqueio permanecerá em vigor até você alterá-lo novamente ou o conjunto de registros é fechado.  
  
> [!NOTE]
>  Drivers ODBC de relativamente poucas atualmente suporte para bloqueio pessimista.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)