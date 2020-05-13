---
title: 'Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- records [C++], updating
- record editing [C++], in recordsets
- recordsets [C++], adding records
- records [C++], adding
- ODBC recordsets [C++], adding records
- recordsets [C++], editing records
- recordsets [C++], updating
- AddNew method
- ODBC recordsets [C++], deleting records
- records [C++], deleting in recordsets
- data in recordsets [C++]
- recordsets [C++], deleting records
- ODBC recordsets [C++], editing records
- records [C++], editing
ms.assetid: cab43d43-235a-4bed-ac05-67d10e94f34e
ms.openlocfilehash: 63718a6be3a9ce19ddbce923a84def21448c42a0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366997"
---
# <a name="recordset-how-addnew-edit-and-delete-work-odbc"></a>Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica `AddNew` `Edit`como `Delete` o , e `CRecordset` o membro funciona de trabalho de classe. Os tópicos abordados incluem:

- [Como funciona a adição de registros](#_core_adding_a_record)

- [Visibilidade de registros adicionados](#_core_visibility_of_added_records)

- [Como funciona a edição de registros](#_core_editing_an_existing_record)

- [Como funciona a exclusão de registros](#_core_deleting_a_record)

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Como um suplemento, você pode querer ler [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md), que descreve o papel correspondente do RFX em operações de atualização.

## <a name="adding-a-record"></a><a name="_core_adding_a_record"></a>Adicionando um Registro

Adicionar um novo registro a um conjunto de registros envolve chamar a função [addNew](../../mfc/reference/crecordset-class.md#addnew) do recordset, definir os valores dos membros de dados de campo do novo registro e chamar a função de membro [Atualizar](../../mfc/reference/crecordset-class.md#update) para gravar o registro na fonte de dados.

Como pré-condição `AddNew`para a chamada, o conjunto de registros não deve ter sido aberto apenas como leitura. As `CanUpdate` `CanAppend` funções e membros permitem determinar essas condições.

Quando você `AddNew`chama:

- O registro no buffer de edição é armazenado, de modo que seu conteúdo pode ser restaurado se a operação for cancelada.

- Os membros de dados de campo são sinalizados para que seja possível detectar alterações neles mais tarde. Os membros dos dados de campo também são marcados como limpos (inalterados) e definidos como Nulos.

Após a `AddNew`chamada, o buffer de edição representa um registro novo e vazio, pronto para ser preenchido com valores. Para fazer isso, você define manualmente os valores atribuindo-lhes. Em vez de especificar um valor real `SetFieldNull` de dados para um campo, você pode ligar para especificar o valor Nulo.

Para cometer suas mudanças, você chama `Update`. Quando você `Update` chama para o novo registro:

- Se o driver ODBC `::SQLSetPos` suportar a função API ODBC, o MFC usará a função para adicionar o registro na fonte de dados. Com `::SQLSetPos`, MFC pode adicionar um registro de forma mais eficiente porque não precisa construir e processar uma declaração SQL.

- Se `::SQLSetPos` não puder ser usado, o MFC faz o seguinte:

   1. Se nenhuma alteração for `Update` detectada, não faz nada e retorna 0.

   1. Se houver alterações, `Update` construa uma instrução SQL **INSERT.** As colunas representadas por todos os membros de dados de campo sujo estão listadas na instrução **INSERT.** Para forçar a incluir uma coluna, ligue para a função [setFieldDirty:](../../mfc/reference/crecordset-class.md#setfielddirty)

        ```cpp
        SetFieldDirty( &m_dataMember, TRUE );
        ```

   1. `Update`compromete o novo registro — a instrução **INSERT** é executada e o registro é comprometido com a tabela na fonte de dados (e no conjunto de registros, se não um instantâneo) a menos que uma transação esteja em andamento.

   1. O registro armazenado é restaurado no buffer de edição. O registro que estava `AddNew` em dia antes da chamada está atualizado novamente, independentemente de a instrução **INSERT** ter sido executada com sucesso.

   > [!TIP]
   > Para o controle completo de um novo registro, adote a seguinte abordagem: defina os valores `SetFieldNull` de quaisquer campos que tenham valores e, em seguida, defina explicitamente quaisquer campos que permaneçam nulos, chamando com um ponteiro para o campo e o parâmetro TRUE (o padrão). Se você quiser garantir que um campo não esteja `SetFieldDirty` gravado na fonte de dados, ligue com um ponteiro para o campo e o parâmetro FALSE e não modifique o valor do campo. Para determinar se um campo pode `IsFieldNullable`ser nulo, ligue .

   > [!TIP]
   > Para detectar quando os membros do registro de dados mudam de valor, o MFC usa um valor PSEUDO_NULL apropriado para cada tipo de dados que você pode armazenar em um conjunto de registros. Se você deve explicitamente definir um campo para o valor PSEUDO_NULL e o `SetFieldNull`campo já está marcado Como Nulo, você também deve chamar , passando o endereço do campo no primeiro parâmetro e FALSE no segundo parâmetro.

## <a name="visibility-of-added-records"></a><a name="_core_visibility_of_added_records"></a>Visibilidade de registros adicionados

Quando um registro adicionado é visível ao seu conjunto de registros? Os registros adicionados às vezes aparecem e às vezes não são visíveis, dependendo de duas coisas:

- Do que seu motorista é capaz.

- O que a estrutura pode tirar proveito.

Se o driver ODBC `::SQLSetPos` suportar a função API ODBC, o MFC usará a função para adicionar registros. Com `::SQLSetPos`, os registros adicionados são visíveis para qualquer conjunto de registros MFC updatable. Sem suporte para a função, os registros `Requery` adicionados não são visíveis e você deve ligar para vê-los. O `::SQLSetPos` uso também é mais eficiente.

## <a name="editing-an-existing-record"></a><a name="_core_editing_an_existing_record"></a>Edição de um registro existente

Editar um registro existente em um conjunto de registros envolve rolar para o registro, chamar a função de membro [Editar](../../mfc/reference/crecordset-class.md#edit) do conjunto de registros, definir os valores dos membros de dados de campo do novo registro e chamar a função de membro [atualizar](../../mfc/reference/crecordset-class.md#update) para gravar o registro alterado na fonte de dados.

Como pré-condição `Edit`para a chamada, o conjunto de registros deve ser updatable e em um registro. As `CanUpdate` `IsDeleted` funções e membros permitem determinar essas condições. O registro atual também não deve ter sido apagado, e deve `IsBOF` haver `IsEOF` registros no conjunto de registros (ambos e retorno 0).

Quando você `Edit`chama, o registro no buffer de edição (o registro atual) é armazenado. Os valores do registro armazenado são posteriormente usados para detectar se algum campo foi alterado.

Após a `Edit`chamada, o buffer de edição ainda representa o registro atual, mas agora está pronto para aceitar alterações nos membros de dados de campo. Para alterar o registro, você define manualmente os valores de todos os membros de dados de campo que deseja editar. Em vez de especificar um valor real `SetFieldNull` de dados para um campo, você pode ligar para especificar o valor Nulo. Para cometer suas `Update`alterações, ligue.

> [!TIP]
> Para sair `AddNew` do `Edit` modo, `Move` ligue com o parâmetro *AFX_MOVE_REFRESH*.

Como pré-condição `Update`para a chamada, o conjunto de registros não deve estar vazio e o registro atual não deve ter sido excluído. `IsBOF`, `IsEOF`e `IsDeleted` todos devem retornar 0.

Quando você `Update` chama para o registro editado:

- Se o driver ODBC `::SQLSetPos` suportar a função API ODBC, o MFC usará a função para atualizar o registro na fonte de dados. Com `::SQLSetPos`, o driver compara o buffer de edição com o registro correspondente no servidor, atualizando o registro no servidor se os dois forem diferentes. Com `::SQLSetPos`, O MFC pode atualizar um registro de forma mais eficiente porque não precisa construir e processar uma declaração SQL.

   \- ou –

- Se `::SQLSetPos` não puder ser usado, o MFC faz o seguinte:

   1. Se não houve mudanças, `Update` não faz nada e retorna 0.

   1. Se houver alterações, `Update` construa uma declaração SQL **UPDATE.** As colunas listadas na declaração **UPDATE** são baseadas nos membros de dados de campo que foram alterados.

   1. `Update`compromete as alterações — executa a declaração **UPDATE** — e o registro é alterado na fonte de dados, mas não comprometido se uma transação estiver em andamento (veja [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md) para obter informações sobre como a transação afeta a atualização). A ODBC mantém uma cópia do registro, que também muda.

   1. Ao contrário `AddNew`do `Edit` processo para , o processo não restaura o registro armazenado. O registro editado permanece no lugar como o registro atual.

   > [!CAUTION]
   > Quando você se preparar para `Update`atualizar um conjunto de registros ligando, tome cuidado para que seu conjunto de registros inclua todas as colunas que compõem a chave principal da tabela (ou todas as colunas de qualquer índice único na tabela, ou colunas suficientes para identificar a linha com exclusividade). Em alguns casos, o framework pode usar apenas as colunas selecionadas em seu conjunto de registros para identificar qual registro em sua tabela para atualizar. Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela. Neste caso, o quadro lança exceções quando você chama `Update`.

   > [!TIP]
   > Se você `AddNew` `Edit` ligar ou depois de ter chamado `Update`qualquer função anteriormente, mas antes de chamar, o buffer de edição é atualizado com o registro armazenado, substituindo o registro novo ou editado em andamento. Esse comportamento lhe dá uma `AddNew` `Edit` maneira de abortar um ou começar um novo: se você `Edit` determinar `AddNew` que o registro em andamento está defeituoso, basta ligar ou novamente.

## <a name="deleting-a-record"></a><a name="_core_deleting_a_record"></a>Excluindo um registro

Excluir um registro de um conjunto de registros envolve rolar para o registro e chamar a função de membro [Excluir](../../mfc/reference/crecordset-class.md#delete) do conjunto de registros. Ao `AddNew` `Edit`contrário `Delete` e , não `Update`requer uma chamada correspondente para .

Como pré-condição `Delete`para a chamada, o conjunto de registros deve ser updatable e deve estar em um registro. As `CanUpdate` `IsBOF`funções , `IsEOF`e `IsDeleted` membros permitem determinar essas condições.

Quando você `Delete`chama:

- Se o driver ODBC `::SQLSetPos` suportar a função API ODBC, o MFC usará a função para excluir o registro na fonte de dados. O `::SQLSetPos` uso é geralmente mais eficiente do que o uso de SQL.

   \- ou –

- Se `::SQLSetPos` não puder ser usado, o MFC faz o seguinte:

   1. O registro atual no buffer de edição `AddNew` `Edit`não é feito como em e .

   1. `Delete`constrói uma declaração SQL **DELETE** que remove o registro.

      O registro atual no buffer de `AddNew` edição `Edit`não é armazenado como em e .

   1. `Delete`comete a exclusão — executa a **declaração DELETE.** O registro é marcado excluído na fonte de dados e, se o registro for um instantâneo, no ODBC.

   1. Os valores do registro excluído ainda estão nos membros de dados de campo do conjunto de `IsDeleted` registros, mas os membros de dados de campo são marcados como Nulo e a função de membro do conjunto de registros retorna um valor não zero.

   > [!NOTE]
   > Depois de excluir um registro, você deve rolar para outro registro para recarregar o buffer de edição com os dados do novo registro. É um erro `Delete` ligar novamente `Edit`ou ligar.

Para obter informações sobre as instruções SQL usadas em operações de atualização, consulte [SQL](../../data/odbc/sql.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)
