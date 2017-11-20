---
title: 'Conjunto de registros: Como conjuntos de registros atualizam registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- records, updating
- ODBC recordsets, updating
- recordsets, editing records
- updating recordsets
- recordsets, updating
ms.assetid: 5ceecc06-7a86-43b1-93db-a54fb1e717c7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5ca360ce914fea69163a400df2f9bc00750920e7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-how-recordsets-update-records-odbc"></a>Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Além de sua capacidade de selecionar os registros de uma fonte de dados, conjuntos de registros podem (opcionalmente) atualizar ou excluir os registros selecionados ou adicionar novos registros. Três fatores determinam a capacidade de atualização de um conjunto de registros: se a fonte de dados conectada é atualizável, as opções especificadas quando você cria um objeto recordset e o SQL que é criado.  
  
> [!NOTE]
>  O SQL no qual seu `CRecordset` com base em objeto pode afetar a capacidade de atualização do seu conjunto de registros. Por exemplo, se seu SQL contém uma junção ou um **GROUP BY** cláusula, MFC define a capacidade de atualização **FALSE**.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Este tópico explica:  
  
-   [Sua função na atualização do conjunto de registros](#_core_your_role_in_recordset_updating) e o que faz a estrutura para você.  
  
-   [O conjunto de registros como um buffer de edição](#_core_the_edit_buffer) e [diferenças entre os instantâneos e dynasets](#_core_dynasets_and_snapshots).  
  
 [Conjunto de registros: Como AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md) descreve as ações dessas funções de ponto de vista do conjunto de registros.  
  
 [Conjunto de registros: Mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md) conclui a história de atualização de conjunto de registros, explicando como transações afetam atualizações, como rolagem ou um conjunto de registros de fechamento afeta as atualizações em andamento e como as atualizações interagem com as atualizações de outros usuários.  
  
##  <a name="_core_your_role_in_recordset_updating"></a>Sua função na atualização do conjunto de registros  
 A tabela a seguir mostra a função usando conjuntos de registros para adicionar, editar ou excluir registros, juntamente com a estrutura que se faz para você.  
  
### <a name="recordset-updating-you-and-the-framework"></a>Atualizando o conjunto de registros: Você e o Framework  
  
|Você|A estrutura|  
|---------|-------------------|  
|Determine se a fonte de dados é atualizável (ou appendable).|Fontes [CDatabase](../../mfc/reference/cdatabase-class.md) funções de membro para testar a capacidade de atualização ou a appendability a fonte de dados.|  
|Abra um conjunto de registros atualizável (de qualquer tipo).||  
|Determinar se o conjunto de registros é atualizável chamando `CRecordset` atualizar funções como `CanUpdate` ou `CanAppend`.||  
|Chame funções de membro para adicionar, editar e excluir registros de conjunto de registros.|Gerencia a mecânica de troca de dados entre o objeto de conjunto de registros e a fonte de dados.|  
|Opcionalmente, use transações para controlar o processo de atualização.|Fontes de `CDatabase` funções de membro para oferecer suporte a transações.|  
  
 Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_the_edit_buffer"></a>O Buffer de edição  
 Feito coletivamente, os membros de um conjunto de registros de dados de campo servem como um buffer de edição que contém um registro, o registro atual. Operações de atualização usam esse buffer para operar no registro atual.  
  
-   Quando você adiciona um registro, o buffer de edição é usado para criar um novo registro. Quando terminar de adicionar o registro, o registro que foi anteriormente atual se torna atual novamente.  
  
-   Quando você atualizar o buffer (Editar) um registro, a edição é usado para definir os membros de dados do campo do conjunto de registros para novos valores. Quando você terminar de atualizar, o registro atualizado ainda é atual.  
  
 Quando você chama [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [editar](../../mfc/reference/crecordset-class.md#edit), o registro atual é armazenado para que ele possa ser restaurado posteriormente, conforme necessário. Quando você chama [excluir](../../mfc/reference/crecordset-class.md#delete), o registro atual não está armazenado, mas está marcado como excluído e você deve rolar para outro registro.  
  
> [!NOTE]
>  O buffer de edição não desempenha nenhuma função na exclusão do registro. Quando você excluir o registro atual, o registro é marcado como excluído, e o conjunto de registros é "não está em um registro" até que você rolar para um registro diferente.  
  
##  <a name="_core_dynasets_and_snapshots"></a>Instantâneos e dynasets  
 [Dynasets](../../data/odbc/dynaset.md) enquanto você rola para o registro de atualização de conteúdo do registro. [Instantâneos](../../data/odbc/snapshot.md) são representações estáticas de registros, para que o conteúdo do registro não é atualizado, a menos que você chame [Requery](../../mfc/reference/crecordset-class.md#requery). Para usar toda a funcionalidade do dynasets, você deve estar trabalhando com um driver ODBC que está de acordo com o nível correto de suporte à API de ODBC. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: como fazer AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md)