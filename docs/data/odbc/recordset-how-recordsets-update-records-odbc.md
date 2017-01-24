---
title: "Conjunto de registros: como conjuntos de registros atualizam registros (ODBC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conjunto de registros ODBC, atualizando"
  - "registros, atualizando"
  - "conjuntos de registros, editando registros"
  - "conjuntos de registros, atualizando"
  - "atualizando conjuntos de registros"
ms.assetid: 5ceecc06-7a86-43b1-93db-a54fb1e717c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Além da capacidade de selecionar registros de uma fonte de dados, os conjuntos de registros podem \(opcionalmente\) a atualização ou exclusão os registros selecionados ou adicionar novos registros.  Três fatores determinam o updateability de um conjunto de registros: se a fonte de dados conectada do é atualizável, as opções que você especifica quando você cria um objeto do conjunto de registros, e SQL que é criado.  
  
> [!NOTE]
>  SQL em que o objeto de `CRecordset` é baseado pode afetar o updateability do conjunto de registros.  Por exemplo, se o contém uma junção ou uma cláusula de **AGRUPAR POR** , o MFC define o updateability a **Falso**.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Este tópico explica:  
  
-   [A função na atualização do conjunto de registros](#_core_your_role_in_recordset_updating) e o que a estrutura faz para você.  
  
-   [O conjunto de registros como um buffer de edição](#_core_the_edit_buffer) e [diferenças entre dynasets e instantâneos](#_core_dynasets_and_snapshots).  
  
 [Conjunto de registros: Como AddNew, edição e, trabalho de exclusão \(ODBC\)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md) descreve as ações dessas funções do ponto de vista do conjunto de registros.  
  
 [Conjunto de registros: Mais sobre atualizações \(ODBC\)](../../data/odbc/recordset-more-about-updates-odbc.md) conclui o histórico de atualização do conjunto de registros explicando como atualizações de influência de transações, como fechar um conjunto de registros ou o rolar afetam as atualizações em andamento, e como as atualizações interagem com as atualizações de outros usuários.  
  
##  <a name="_core_your_role_in_recordset_updating"></a> A função na atualização do conjunto de registros  
 A tabela a seguir mostra a função em usar conjuntos de registros para adicionar, editar, excluir ou registros, junto com o qual a estrutura faz para você.  
  
### Atualizar do conjunto de registros: Você e a estrutura  
  
|Você|A estrutura|  
|----------|-----------------|  
|Determina se a fonte de dados é atualizável \(ou appendable\).|Funções de membro de [CDatabase](../../mfc/reference/cdatabase-class.md) de fontes para testar o updateability ou o appendability da fonte de dados.|  
|Abrir um conjunto de registros atualizável \(\) de qualquer tipo.||  
|Determina se o conjunto de registros é atualizável chamando\-se funções de atualização de `CRecordset` como `CanUpdate` ou `CanAppend`.||  
|Chamar funções de membro do conjunto de registros para adicionar, editar, e excluir registros.|Gerencia a mecânica de troca de dados entre o objeto do conjunto de registros e a fonte de dados.|  
|Opcionalmente, usam transações para controlar o processo de atualização.|O fornece funções de membro de `CDatabase` para suportar transações.|  
  
 Para obter mais informações sobre transações, consulte [Transações \(ODBC\)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_the_edit_buffer"></a> O buffer de edição  
 Feitos coletivamente, os membros de dados do campo de um saquês do conjunto de registros como uma edição armazenadas em buffer que contém um registro — o registro atual.  As operações de atualização usam esse buffer para operar no registro atual.  
  
-   Quando você adiciona um registro, o buffer de edição é usado para criar um novo registro.  Quando terminar de adicionar o registro, o registro que anteriormente era atual se torna atual novamente.  
  
-   Quando você atualiza um registro \(edição\), o buffer de edição é usado para definir os membros de dados do campo do conjunto de registros para novos valores.  Quando você terminar de atualização, o registro atualizado ainda atual.  
  
 Quando você chama [AddNew](../Topic/CRecordset::AddNew.md) ou [Edição](../Topic/CRecordset::Edit.md), o registro atual é armazenado para que possa ser restaurado posteriormente conforme necessário.  Quando você chama [Excluir](../Topic/CRecordset::Delete.md), o registro atual não está armazenado mas está marcado como excluído e é necessário rolar para outro registro.  
  
> [!NOTE]
>  O buffer da edição do não executa nenhuma função na exclusão do registro.  Quando você exclui o registro atual, o registro será marcado como excluído, e o conjunto de registros é “não” em um registro que você navegue até um registro diferente.  
  
##  <a name="_core_dynasets_and_snapshots"></a> Dynasets e instantâneos  
 atualização de[Dynasets](../../data/odbc/dynaset.md) o conteúdo de um registro como você percorrer o registro.  [Instantâneos](../Topic/Snapshot.md) é representações estáticos dos registros, assim que o conteúdo de um registro não são atualizados a menos que você chame [Você consulte novamente](../Topic/CRecordset::Requery.md).  Para usar toda a funcionalidade de dynasets, você deve trabalhar com um driver ODBC que esteja de acordo com o nível correto de suporte de ODBC API.  Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: como AddNew, editar e excluir trabalho \(ODBC\)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md)