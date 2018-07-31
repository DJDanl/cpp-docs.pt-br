---
title: 'Conjunto de registros: Como conjuntos de registros atualizam registros (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- records, updating
- ODBC recordsets, updating
- recordsets, editing records
- updating recordsets
- recordsets, updating
ms.assetid: 5ceecc06-7a86-43b1-93db-a54fb1e717c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2697952b500c7643bf0723c99395e56ebc48ad84
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39340697"
---
# <a name="recordset-how-recordsets-update-records-odbc"></a>Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)
Este tópico se aplica às classes ODBC do MFC.  
  
 Além de sua capacidade de selecionar os registros de uma fonte de dados, conjuntos de registros podem (opcionalmente) atualizar ou excluir os registros selecionados ou adicionar novos registros. Três fatores determinam a capacidade de atualização de um conjunto de registros: se a fonte de dados conectada é atualizável, as opções especificadas quando você cria um objeto recordset e o SQL que é criado.  
  
> [!NOTE]
>  O SQL no qual seu `CRecordset` com base em objeto pode afetar a capacidade de atualização do seu conjunto de registros. Por exemplo, se seu SQL contém uma junção ou um **GROUP BY** cláusula, o MFC define a capacidade de atualização como FALSE.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Este tópico explica:  
  
-   [Sua função na atualização do conjunto de registros](#_core_your_role_in_recordset_updating) e o que a estrutura faz para você.  
  
-   [O conjunto de registros como um buffer de edição](#_core_the_edit_buffer) e o [diferenças entre os instantâneos e dynasets](#_core_dynasets_and_snapshots).  
  
 [Conjunto de registros: Como AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md) descreve as ações de uma dessas funções do ponto de vista do conjunto de registros.  
  
 [Conjunto de registros: Mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md) conclui a história de atualização do conjunto de registros, explicando como transações afetam atualizações, como fechar um conjunto de registros ou de rolagem afeta as atualizações em andamento e como suas atualizações interagem com as atualizações de outros usuários.  
  
##  <a name="_core_your_role_in_recordset_updating"></a> Sua função na atualização do conjunto de registros  
 A tabela a seguir mostra a sua função no uso de conjuntos de registros para adicionar, editar ou excluir registros, juntamente com o que a estrutura faz para você.  
  
### <a name="recordset-updating-you-and-the-framework"></a>Atualizando o conjunto de registros: Você e a estrutura  
  
|Você|A estrutura|  
|---------|-------------------|  
|Determine se a fonte de dados é atualizável (ou appendable).|Suprimentos [CDatabase](../../mfc/reference/cdatabase-class.md) funções de membro para testar a fonte de dados updateability ou appendability.|  
|Abra um conjunto de registros atualizável (de qualquer tipo).||  
|Determinar se o conjunto de registros é atualizável, chamando `CRecordset` atualizar funções, como `CanUpdate` ou `CanAppend`.||  
|Chame funções de membro para adicionar, editar e excluir registros de conjunto de registros.|Gerencia a mecânica de troca de dados entre seu objeto de conjunto de registros e a fonte de dados.|  
|Opcionalmente, use transações para controlar o processo de atualização.|Fontes de `CDatabase` funções de membro para dar suporte a transações.|  
  
 Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_the_edit_buffer"></a> O Buffer de edição  
 Tirado coletivamente, os membros de dados do campo de um conjunto de registros servem como um buffer de edição que contém um registro — o registro atual. Operações de atualização usam esse buffer para operar no registro atual.  
  
-   Quando você adiciona um registro, o buffer de edição é usado para criar um novo registro. Quando terminar de adicionar o registro, o registro que foi anteriormente atual se torna atual novamente.  
  
-   Quando você atualizar (Editar) um registro, a edição de buffer é usado para definir os membros de dados do campo do conjunto de registros com valores novos. Quando você terminar de atualizar, o registro atualizado ainda é atual.  
  
 Quando você chama [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [editar](../../mfc/reference/crecordset-class.md#edit), o registro atual é armazenado para que possam ser restaurado posteriormente, conforme necessário. Quando você chama [excluir](../../mfc/reference/crecordset-class.md#delete), o registro atual não é armazenado, mas está marcado como excluído e você deve rolar para outro registro.  
  
> [!NOTE]
>  O buffer de edição não desempenha nenhuma função na exclusão de registros. Quando você exclui o registro atual, o registro é marcado como excluído e o conjunto de registros é "não está em um registro" até que você rolar para um registro diferente.  
  
##  <a name="_core_dynasets_and_snapshots"></a> Instantâneos e dynasets  
 [Dynasets](../../data/odbc/dynaset.md) atualizar conteúdo de um registro, conforme você rola para o registro. [Instantâneos](../../data/odbc/snapshot.md) são representações estáticas de registros, para que o conteúdo de um registro não é atualizado, a menos que você chame [Requery](../../mfc/reference/crecordset-class.md#requery). Para usar toda a funcionalidade do dynasets, você deve estar trabalhando com um driver ODBC que está de acordo com o nível correto de suporte da API do ODBC. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: como fazer AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md)