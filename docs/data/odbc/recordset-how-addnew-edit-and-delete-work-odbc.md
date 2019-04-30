---
title: 'Conjunto de registros: Como AddNew, editar e excluir trabalho (ODBC)'
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
ms.openlocfilehash: e5fc6ad2a1fe00367cd8a0b1c53ac914b95018ab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397829"
---
# <a name="recordset-how-addnew-edit-and-delete-work-odbc"></a>Conjunto de registros: Como AddNew, editar e excluir trabalho (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Este tópico explica como o `AddNew`, `Edit`, e `Delete` funções de membro de classe `CRecordset` funcione. Os tópicos abordados incluem:

- [Como a adição de registros funciona](#_core_adding_a_record)

- [Visibilidade de registros adicionados](#_core_visibility_of_added_records)

- [Como funciona a edição de registros](#_core_editing_an_existing_record)

- [Como a exclusão de registros funciona](#_core_deleting_a_record)

> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Como um suplemento, você talvez queira ler [troca de campos do registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md), que descreve a função correspondente do RFX em operações de atualização.

##  <a name="_core_adding_a_record"></a> Adicionar um registro

Adicionar um novo registro para um conjunto de registros envolve chamar o conjunto de registros [AddNew](../../mfc/reference/crecordset-class.md#addnew) função de membro, definindo os valores de membros de dados de campo do novo registro e, em seguida, chamar o [atualização](../../mfc/reference/crecordset-class.md#update) função de membro para gravar o registro para a fonte de dados.

Como uma pré-condição para chamar `AddNew`, o conjunto de registros deve não ter sido aberto como somente leitura. O `CanUpdate` e `CanAppend` funções de membro permitem determinar essas condições.

Quando você chama `AddNew`:

- O registro no buffer de edição é armazenado, seu conteúdo pode ser restaurado se a operação for cancelada.

- Os membros de dados de campo são sinalizados para que seja possível detectar alterações em-los mais tarde. Os dados também são membros do campo Limpar (inalterada) e definido como um valor nulo.

Depois de chamar `AddNew`, o buffer de edição representa um novo, vazio registro, pronto para ser preenchido com valores. Para fazer isso, você definir manualmente os valores, atribuindo a eles. Em vez de especificar um valor de dados reais de um campo, você pode chamar `SetFieldNull` para especificar o valor Null.

Para confirmar suas alterações, você deve chamar `Update`. Quando você chama `Update` para o novo registro:

- Se o driver ODBC dá suporte a `::SQLSetPos` função de API do ODBC, o MFC usa a função para adicionar o registro na fonte de dados. Com `::SQLSetPos`, MFC pode adicionar um registro com mais eficiência porque ele não precisa construir e processar uma instrução SQL.

- Se `::SQLSetPos` não pode ser usado, o MFC faz o seguinte:

   1. Se nenhuma alteração seja detectada, `Update` não faz nada e retornará 0.

   1. Se houver alterações, `Update` constrói um SQL **inserir** instrução. As colunas representadas por todos os membros de dados de campo sujas são listadas na **inserir** instrução. Para forçar uma coluna a ser incluído, chame o [SetFieldDirty](../../mfc/reference/crecordset-class.md#setfielddirty) função de membro:

        ```cpp
        SetFieldDirty( &m_dataMember, TRUE );
        ```

   1. `Update` confirma o novo registro — o **inserir** instrução é executada e o registro é confirmado para a tabela na fonte de dados (e o conjunto de registros, se não um instantâneo), a menos que uma transação está em andamento.

   1. O registro armazenado é restaurado para o buffer de edição. O registro que foi atual antes do `AddNew` chamada é atual novamente, independentemente se o **inserir** instrução foi executada com êxito.

   > [!TIP]
   > Para obter um controle de um novo registro, usar a seguinte abordagem: definir os valores de todos os campos que têm valores e, em seguida, defina explicitamente todos os campos que serão sempre Null chamando `SetFieldNull` com um ponteiro para o campo e o parâmetro TRUE (padrão). Se você quiser garantir que um campo não é gravado para a fonte de dados, chamada `SetFieldDirty` com um ponteiro para o campo e o parâmetro como FALSE e não modifique o valor do campo. Para determinar se um campo pode ser Null, chamar `IsFieldNullable`.

   > [!TIP]
   > Para detectar quando o valor de alterar os membros de dados do conjunto de registros, o MFC usa um valor PSEUDO_NULL apropriado para cada tipo de dados que você pode armazenar em um conjunto de registros. Se você deve definir explicitamente um campo para o valor PSEUDO_NULL e o campo já acontece para ser marcados como Null, você também deve chamar `SetFieldNull`, passando o endereço do campo no primeiro parâmetro e FALSE no segundo parâmetro.

##  <a name="_core_visibility_of_added_records"></a> Visibilidade de registros adicionados

Quando um registro adicionado é visível para o conjunto de registros? Registros adicionados às vezes aparecem e algumas vezes não são visíveis, dependendo das duas coisas:

- O que o driver é capaz de.

- O que o framework pode aproveitar.

Se o driver ODBC dá suporte a `::SQLSetPos` função de API do ODBC, o MFC usa a função para adicionar registros. Com `::SQLSetPos`, adicionados registros são visíveis para qualquer conjunto de registros atualizável do MFC. Sem suporte para a função, adicionada registros não são visíveis, e você deve chamar `Requery` para vê-los. Usando `::SQLSetPos` também é mais eficiente.

##  <a name="_core_editing_an_existing_record"></a> Editando um registro existente

A edição de um registro existente em um conjunto de registros envolve a rolagem para o registro, o conjunto de registros de chamada [edite](../../mfc/reference/crecordset-class.md#edit) função de membro, definindo os valores de membros de dados de campo do novo registro e, em seguida, chamar o [atualizar](../../mfc/reference/crecordset-class.md#update)função de membro para gravar o registro alterado para a fonte de dados.

Como uma pré-condição para chamar `Edit`, o conjunto de registros deve ser atualizável e em um registro. O `CanUpdate` e `IsDeleted` funções de membro permitem determinar essas condições. O registro atual também não já tenham sido excluído, e deve haver registros no conjunto de registros (ambos `IsBOF` e `IsEOF` retornam 0).

Quando você chama `Edit`, o registro no buffer de edição (o registro atual) é armazenado. Os valores do registro armazenado posteriormente são usados para detectar se todos os campos foram alterados.

Depois de chamar `Edit`, o buffer de edição ainda representa o registro atual, mas agora está pronto para aceitar as alterações para os membros de dados do campo. Para alterar o registro, você definir manualmente os valores de quaisquer membros de dados de campo que você deseja editar. Em vez de especificar um valor de dados reais de um campo, você pode chamar `SetFieldNull` para especificar o valor Null. Para confirmar suas alterações, chame `Update`.

> [!TIP]
> Para tirar proveito do `AddNew` ou `Edit` modo, chame `Move` com o parâmetro *AFX_MOVE_REFRESH*.

Como uma pré-condição para chamar `Update`, o conjunto de registros não pode estar vazio e o registro atual não tenham sido excluído. `IsBOF`, `IsEOF`, e `IsDeleted` devem todas retornar 0.

Quando você chama `Update` para o registro editado:

- Se o driver ODBC dá suporte a `::SQLSetPos` função de API do ODBC, o MFC usa a função para atualizar o registro na fonte de dados. Com `::SQLSetPos`, o driver comparará seu buffer de edição com o registro correspondente no servidor, atualizando o registro no servidor se os dois forem diferentes. Com `::SQLSetPos`, MFC pode atualizar um registro com mais eficiência porque ele não precisa construir e processar uma instrução SQL.

   \- ou -

- Se `::SQLSetPos` não pode ser usado, o MFC faz o seguinte:

   1. Se não houve nenhuma alteração `Update` não faz nada e retornará 0.

   1. Se houver alterações, `Update` constrói um SQL **atualização** instrução. As colunas listadas na **atualização** instrução se baseiam os membros de dados de campo que foram alterados.

   1. `Update` confirma as alterações — executa o **atualização** instrução — e o registro é alterado na fonte de dados, mas não confirmada se uma transação está em andamento (consulte [transação: Execução de uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md) para obter informações sobre como a transação afeta a atualização). ODBC mantém uma cópia do registro, que também será alterado.

   1. Ao contrário do processo para `AddNew`, o `Edit` processo não restaura o registro armazenado. O registro editado permanece em vigor, como o registro atual.

   > [!CAUTION]
   > Quando você se preparar para atualizar um conjunto de registros chamando `Update`, tome cuidado que seu conjunto de registros inclui todas as colunas que compõem a chave primária da tabela (ou todas as colunas de qualquer índice exclusivo na tabela ou colunas suficientes para identificar exclusivamente a linha). Em alguns casos, o framework pode usar somente as colunas selecionadas no seu conjunto de registros para identificar qual registro na tabela a ser atualizada. Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela. Nesse caso, o framework lança exceções ao chamar `Update`.

   > [!TIP]
   > Se você chamar `AddNew` ou `Edit` depois de ter chamado a qualquer função anteriormente, mas antes de chamar `Update`, o buffer de edição é atualizado com o registro armazenado, substituindo o registro novo ou editado em andamento. Esse comportamento oferece uma maneira para anular uma `AddNew` ou `Edit` e iniciar uma nova: se você determinar que o registro em andamento está com defeito, simplesmente chame `Edit` ou `AddNew` novamente.

##  <a name="_core_deleting_a_record"></a> Excluindo um registro

Excluir um registro de um conjunto de registros envolve a rolagem para o registro e o conjunto de registros de chamada [excluir](../../mfc/reference/crecordset-class.md#delete) função de membro. Diferentemente `AddNew` e `Edit`, `Delete` não requer uma chamada correspondente para `Update`.

Como uma pré-condição para chamar `Delete`, o conjunto de registros deve ser atualizável e ele deve estar em um registro. O `CanUpdate`, `IsBOF`, `IsEOF`, e `IsDeleted` funções de membro permitem determinar essas condições.

Quando você chama `Delete`:

- Se o driver ODBC dá suporte a `::SQLSetPos` função de API do ODBC, o MFC usa a função para excluir o registro na fonte de dados. Usando `::SQLSetPos` é geralmente mais eficiente do que usando o SQL.

   \- ou -

- Se `::SQLSetPos` não pode ser usado, o MFC faz o seguinte:

   1. O registro atual no buffer de edição não é feito como na `AddNew` e `Edit`.

   1. `Delete` constrói um SQL **excluir** instrução que remove o registro.

      O registro atual no buffer de edição não é armazenado como na `AddNew` e `Edit`.

   1. `Delete` confirma a exclusão — executa o **excluir** instrução. O registro é marcado como excluído na fonte de dados e, se o registro é um instantâneo, no ODBC.

   1. Os valores do registro excluído ainda estão em membros de dados de campo do conjunto de registros, mas os membros de dados do campo marcado como Null e o conjunto de registros `IsDeleted` função membro retorna um valor diferente de zero.

   > [!NOTE]
   > Depois de excluir um registro, você deve rolar para outro registro para preencher novamente o buffer de edição com os novos dados do registro. É um erro ao chamar `Delete` novamente ou chamar `Edit`.

Para obter informações sobre instruções SQL usada em operações de atualização, consulte [SQL](../../data/odbc/sql.md).

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)