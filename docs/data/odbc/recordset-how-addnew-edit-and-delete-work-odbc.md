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
ms.openlocfilehash: 8799ac36c443898f1e32b539f017e682bbf3e033
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212895"
---
# <a name="recordset-how-addnew-edit-and-delete-work-odbc"></a>Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como as funções de membro `AddNew`, `Edit`e `Delete` da classe `CRecordset` funcionam. Os tópicos abordados incluem:

- [Como a adição de registros funciona](#_core_adding_a_record)

- [Visibilidade dos registros adicionados](#_core_visibility_of_added_records)

- [Como funcionam os registros de edição](#_core_editing_an_existing_record)

- [Como a exclusão de registros funciona](#_core_deleting_a_record)

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Como um suplemento, talvez você queira ler o [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md), que descreve a função correspondente do suporte RFX nas operações de atualização.

##  <a name="adding-a-record"></a><a name="_core_adding_a_record"></a>Adicionando um registro

Adicionar um novo registro a um conjunto de registros envolve chamar a função de membro [AddNew](../../mfc/reference/crecordset-class.md#addnew) do conjunto de registros, definir os valores dos membros de dados de campo do novo registro e chamar a função de membro [Update](../../mfc/reference/crecordset-class.md#update) para gravar o registro na fonte de dados.

Como uma pré-condição para chamar `AddNew`, o conjunto de registros não deve ter sido aberto como somente leitura. As funções de membro `CanUpdate` e `CanAppend` permitem que você determine essas condições.

Quando você chama `AddNew`:

- O registro no buffer de edição é armazenado, portanto, seu conteúdo poderá ser restaurado se a operação for cancelada.

- Os membros de dados de campo são sinalizados para que seja possível detectar alterações neles mais tarde. Os membros de dados de campo também são marcados como limpos (inalterados) e definidos como nulos.

Depois de chamar `AddNew`, o buffer de edição representa um novo registro vazio, pronto para ser preenchido com valores. Para fazer isso, você define manualmente os valores atribuindo-os a eles. Em vez de especificar um valor de dados real para um campo, você pode chamar `SetFieldNull` para especificar o valor NULL.

Para confirmar suas alterações, você chama `Update`. Quando você chama `Update` para o novo registro:

- Se o driver ODBC oferecer suporte à função de API `::SQLSetPos` ODBC, o MFC usará a função para adicionar o registro na fonte de dados. Com o `::SQLSetPos`, o MFC pode adicionar um registro com mais eficiência, pois não precisa construir e processar uma instrução SQL.

- Se `::SQLSetPos` não puder ser usado, o MFC fará o seguinte:

   1. Se nenhuma alteração for detectada, `Update` não fará nada e retornará 0.

   1. Se houver alterações, `Update` construirá uma instrução SQL **Insert** . As colunas representadas por todos os membros de dados de campo sujos são listadas na instrução **Insert** . Para forçar a inclusão de uma coluna, chame a função de membro [SetFieldDirty](../../mfc/reference/crecordset-class.md#setfielddirty) :

        ```cpp
        SetFieldDirty( &m_dataMember, TRUE );
        ```

   1. `Update` confirma o novo registro — a instrução **Insert** é executada e o registro é confirmado na tabela na fonte de dados (e o conjunto de registros, se não for um instantâneo), a menos que uma transação esteja em andamento.

   1. O registro armazenado é restaurado para o buffer de edição. O registro que era atual antes da chamada de `AddNew` é atual novamente, independentemente de a instrução **Insert** ter sido executada com êxito.

   > [!TIP]
   > Para obter controle completo de um novo registro, adote a seguinte abordagem: defina os valores de todos os campos que terão valores e, em seguida, defina explicitamente os campos que permanecerão nulos chamando `SetFieldNull` com um ponteiro para o campo e o parâmetro TRUE (o padrão). Se você quiser garantir que um campo não seja gravado na fonte de dados, chame `SetFieldDirty` com um ponteiro para o campo e o parâmetro FALSE e não modifique o valor do campo. Para determinar se um campo pode ser nulo, chame `IsFieldNullable`.

   > [!TIP]
   > Para detectar quando os membros de dados do conjunto de registros mudam o valor, o MFC usa um PSEUDO_NULL valor apropriado para cada tipo de dados que você pode armazenar em um conjunto de registros. Se você precisar definir explicitamente um campo para o valor PSEUDO_NULL e o campo já estiver marcado como NULL, você também deverá chamar `SetFieldNull`, passando o endereço do campo no primeiro parâmetro e FALSE no segundo parâmetro.

##  <a name="visibility-of-added-records"></a><a name="_core_visibility_of_added_records"></a>Visibilidade dos registros adicionados

Quando um registro adicionado é visível para o conjunto de registros? Os registros adicionados às vezes aparecem e, às vezes, não são visíveis, dependendo de duas coisas:

- O que o driver é capaz de fazer.

- O que a estrutura pode aproveitar.

Se o driver ODBC oferecer suporte à função `::SQLSetPos` API ODBC, o MFC usará a função para adicionar registros. Com `::SQLSetPos`, os registros adicionados são visíveis para qualquer conjunto de registros MFC atualizável. Sem suporte para a função, os registros adicionados não são visíveis e você deve chamar `Requery` para vê-los. Usar `::SQLSetPos` também é mais eficiente.

##  <a name="editing-an-existing-record"></a><a name="_core_editing_an_existing_record"></a>Editando um registro existente

A edição de um registro existente em um conjunto de registros envolve a rolagem para o registro, chamando a função de membro [Editar](../../mfc/reference/crecordset-class.md#edit) do conjunto de registros, definindo os valores dos membros de dados de campo do novo registro e chamando a função de membro de [atualização](../../mfc/reference/crecordset-class.md#update) para gravar o registro alterado na fonte de dados.

Como uma pré-condição para chamar `Edit`, o conjunto de registros deve ser atualizável e em um registro. As funções de membro `CanUpdate` e `IsDeleted` permitem que você determine essas condições. O registro atual também não deve ter sido excluído e deve haver registros no conjunto de registros (ambos `IsBOF` e `IsEOF` retornam 0).

Quando você chama `Edit`, o registro no buffer de edição (o registro atual) é armazenado. Os valores do registro armazenado são usados posteriormente para detectar se algum campo foi alterado.

Depois de chamar `Edit`, o buffer de edição ainda representa o registro atual, mas agora está pronto para aceitar as alterações nos membros de dados de campo. Para alterar o registro, você define manualmente os valores de todos os membros de dados de campo que deseja editar. Em vez de especificar um valor de dados real para um campo, você pode chamar `SetFieldNull` para especificar o valor NULL. Para confirmar suas alterações, chame `Update`.

> [!TIP]
> Para sair do modo de `AddNew` ou `Edit`, chame `Move` com o parâmetro *AFX_MOVE_REFRESH*.

Como uma pré-condição para chamar `Update`, o conjunto de registros não deve estar vazio e o registro atual não deve ter sido excluído. `IsBOF`, `IsEOF`e `IsDeleted` devem retornar 0.

Quando você chama `Update` para o registro editado:

- Se o driver ODBC oferecer suporte à função de API `::SQLSetPos` ODBC, o MFC usará a função para atualizar o registro na fonte de dados. Com o `::SQLSetPos`, o driver compara o buffer de edição com o registro correspondente no servidor, atualizando o registro no servidor se os dois forem diferentes. Com o `::SQLSetPos`, o MFC pode atualizar um registro com mais eficiência, pois não precisa construir e processar uma instrução SQL.

   \- ou –

- Se `::SQLSetPos` não puder ser usado, o MFC fará o seguinte:

   1. Se não houver nenhuma alteração, `Update` não fará nada e retornará 0.

   1. Se houver alterações, o `Update` construirá uma instrução SQL **Update** . As colunas listadas na instrução **Update** baseiam-se nos membros de dados de campo que foram alterados.

   1. `Update` confirma as alterações — executa a instrução **Update** — e o registro é alterado na fonte de dados, mas não é confirmado se uma transação está em andamento (consulte [Transaction: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md) para obter informações sobre como a transação afeta a atualização). O ODBC mantém uma cópia do registro, que também é alterada.

   1. Ao contrário do processo de `AddNew`, o processo de `Edit` não restaura o registro armazenado. O registro editado permanece em vigor como o registro atual.

   > [!CAUTION]
   > Quando você se prepara para atualizar um conjunto de registros chamando `Update`, tome cuidado para que o conjunto de registros inclua todas as colunas que compõem a chave primária da tabela (ou todas as colunas de qualquer índice exclusivo na tabela ou colunas suficientes para identificar a linha de forma exclusiva). Em alguns casos, a estrutura pode usar apenas as colunas selecionadas no conjunto de registros para identificar qual registro em sua tabela deve ser atualizado. Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela. Nesse caso, a estrutura gera exceções quando você chama `Update`.

   > [!TIP]
   > Se você chamar `AddNew` ou `Edit` depois de ter chamado a função anteriormente, mas antes de chamar `Update`, o buffer de edição será atualizado com o registro armazenado, substituindo o registro novo ou editado em andamento. Esse comportamento oferece uma maneira de anular um `AddNew` ou `Edit` e iniciar um novo: se você determinar que o registro em andamento está defeituoso, basta chamar `Edit` ou `AddNew` novamente.

##  <a name="deleting-a-record"></a><a name="_core_deleting_a_record"></a>Excluindo um registro

A exclusão de um registro de um conjunto de registros envolve a rolagem para o registro e a chamada da função de membro [delete](../../mfc/reference/crecordset-class.md#delete) do conjunto de registros. Ao contrário de `AddNew` e `Edit`, `Delete` não requer uma chamada de correspondência para `Update`.

Como uma pré-condição para chamar `Delete`, o conjunto de registros deve ser atualizável e deve estar em um registro. As funções de membro `CanUpdate`, `IsBOF`, `IsEOF`e `IsDeleted` permitem determinar essas condições.

Quando você chama `Delete`:

- Se o driver ODBC oferecer suporte à função de API `::SQLSetPos` ODBC, o MFC usará a função para excluir o registro na fonte de dados. Usar `::SQLSetPos` geralmente é mais eficiente do que usar o SQL.

   \- ou –

- Se `::SQLSetPos` não puder ser usado, o MFC fará o seguinte:

   1. Não é feito backup do registro atual no buffer de edição como em `AddNew` e `Edit`.

   1. `Delete` constrói uma instrução SQL **delete** que remove o registro.

      O registro atual no buffer de edição não é armazenado como em `AddNew` e `Edit`.

   1. `Delete` confirma a exclusão — executa a instrução **delete** . O registro é marcado como excluído na fonte de dados e, se o registro for um instantâneo, em ODBC.

   1. Os valores do registro excluído ainda estão nos membros de dados de campo do conjunto de registros, mas os membros de dados de campo são marcados como nulos e a função de membro `IsDeleted` do conjunto de registros retorna um valor diferente de zero.

   > [!NOTE]
   > Depois de excluir um registro, você deve rolar para outro registro para reabastecer o buffer de edição com os dados do novo registro. É um erro chamar `Delete` novamente ou chamar `Edit`.

Para obter informações sobre as instruções SQL usadas em operações de atualização, consulte [SQL](../../data/odbc/sql.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)
