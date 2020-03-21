---
title: 'Conjunto de registros: recuperando registros em massa (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- bulk row fetching, implementing
- ODBC recordsets, bulk row fetching
- bulk record field exchange
- bulk row fetching
- bulk RFX functions
- recordsets, bulk row fetching
- DoBulkFieldExchange method
- fetching ODBC records in bulk
- RFX (ODBC), bulk
- rowsets, bulk row fetching
- RFX (ODBC), bulk row fetching
ms.assetid: 20d10fe9-c58a-414a-b675-cdf9aa283e4f
ms.openlocfilehash: cd9597da7ab4c405f90a145182d63945cef48c53
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079817"
---
# <a name="recordset-fetching-records-in-bulk-odbc"></a>Conjunto de registros: recuperando registros em massa (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

A classe `CRecordset` fornece suporte para busca de linha em massa, o que significa que vários registros podem ser recuperados ao mesmo tempo durante uma única busca, em vez de recuperar um registro por vez da fonte de dados. Você pode implementar a busca de linha em massa somente em uma classe de `CRecordset` derivada. O processo de transferência de dados da fonte de dados para o objeto Recordset é chamado de troca de campo de registro em massa (suporte RFX em massa). Observe que se você não estiver usando a busca de linha em massa em uma classe derivada de `CRecordset`, os dados serão transferidos por meio do suporte RFX (Record Field Exchange). Para obter mais informações, consulte [Record Field Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

Este tópico explica:

- [Como o CRecordset dá suporte à busca de linha em massa](#_core_how_crecordset_supports_bulk_row_fetching).

- [Algumas considerações especiais ao usar a busca de linha em massa](#_core_special_considerations).

- [Como implementar o intercâmbio de campo de registro em massa](#_core_how_to_implement_bulk_record_field_exchange).

##  <a name="how-crecordset-supports-bulk-row-fetching"></a><a name="_core_how_crecordset_supports_bulk_row_fetching"></a>Como o CRecordset dá suporte à busca de linha em massa

Antes de abrir o objeto recordset, você pode definir um tamanho de conjunto de linhas com a função membro `SetRowsetSize`. O tamanho do conjunto de linhas especifica quantos registros devem ser recuperados durante uma única busca. Quando a busca de linha em massa é implementada, o tamanho padrão do conjunto de linhas é 25. Se a busca de linha em massa não for implementada, o tamanho do conjunto de linhas permanecerá fixo em 1.

Depois de inicializar o tamanho do conjunto de linhas, chame a função de membro [Open](../../mfc/reference/crecordset-class.md#open) . Aqui você deve especificar a opção `CRecordset::useMultiRowFetch` do parâmetro *dwOptions* para implementar a busca em massa de linha. Você também pode definir a opção `CRecordset::userAllocMultiRowBuffers`. O mecanismo de troca de campo de registro em massa usa matrizes para armazenar as várias linhas de dados recuperadas durante uma busca. Esses buffers de armazenamento podem ser alocados automaticamente pela estrutura ou você pode alocá-los manualmente. A especificação da opção de `CRecordset::userAllocMultiRowBuffers` significa que você fará a alocação.

A tabela a seguir lista as funções de membro fornecidas pelo `CRecordset` para oferecer suporte à busca de linha em massa.

|Função de membro|DESCRIÇÃO|
|---------------------|-----------------|
|[CheckRowsetError](../../mfc/reference/crecordset-class.md#checkrowseterror)|Função virtual que manipula os erros que ocorrem durante a busca.|
|[DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange)|Implementa a troca de campo de registro em massa. Chamado automaticamente para transferir várias linhas de dados da fonte de dados para o objeto Recordset.|
|[GetRowsetSize](../../mfc/reference/crecordset-class.md#getrowsetsize)|Recupera a configuração atual para o tamanho do conjunto de linhas.|
|[GetRowsFetched](../../mfc/reference/crecordset-class.md#getrowsfetched)|Informa quantas linhas foram realmente recuperadas após uma determinada busca. Na maioria dos casos, esse é o tamanho do conjunto de linhas, a menos que um conjunto de linhas incompleto tenha sido buscado.|
|[GetRowStatus](../../mfc/reference/crecordset-class.md#getrowstatus)|Retorna um status de busca para uma linha específica dentro de um conjunto de linhas.|
|[RefreshRowset](../../mfc/reference/crecordset-class.md#refreshrowset)|Atualiza os dados e o status de uma linha específica dentro de um conjunto de linhas.|
|[SetRowsetCursorPosition](../../mfc/reference/crecordset-class.md#setrowsetcursorposition)|Move o cursor para uma linha específica dentro de um conjunto de linhas.|
|[SetRowsetSize](../../mfc/reference/crecordset-class.md#setrowsetsize)|Função virtual que altera a configuração do tamanho do conjunto de linhas para o valor especificado.|

##  <a name="special-considerations"></a><a name="_core_special_considerations"></a>Considerações especiais

Embora a busca de linha em massa seja um lucro de desempenho, determinados recursos operam de forma diferente. Antes de decidir implementar a busca em massa de linha, considere o seguinte:

- A estrutura chama automaticamente a função de membro `DoBulkFieldExchange` para transferir dados da fonte de dados para o objeto Recordset. No entanto, os dados não são transferidos do conjunto de registros de volta para a fonte de dados. Chamar as funções de membro `AddNew`, `Edit`, `Delete`ou `Update` resulta em uma asserção com falha. Embora `CRecordset` atualmente não forneça um mecanismo para atualizar linhas de dados em massa, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`. Para obter mais informações sobre `SQLSetPos`, consulte a *referência do programador do ODBC SDK* na documentação do MSDN.

- As funções membro `IsDeleted`, `IsFieldDirty`, `IsFieldNull`, `IsFieldNullable`, `SetFieldDirty`e `SetFieldNull` não podem ser usadas em conjuntos de registros que implementam busca de linha em massa. No entanto, você pode chamar `GetRowStatus` no lugar de `IsDeleted`e `GetODBCFieldInfo` no lugar de `IsFieldNullable`.

- As operações de `Move` reposicionam seu conjunto de registros por conjunto de linhas. Por exemplo, suponha que você abra um conjunto de registros que tenha 100 registros com um tamanho de conjunto de linhas inicial de 10. `Open` busca as linhas de 1 a 10, com o registro atual posicionado na linha 1. Uma chamada para `MoveNext` busca o próximo conjunto de linhas, não a próxima linha. Esse conjunto de linhas consiste nas linhas de 11 a 20, com o registro atual posicionado na linha 11. Observe que `MoveNext` e `Move( 1 )` não são equivalentes quando a busca de linha em massa é implementada. `Move( 1 )` busca o conjunto de linhas que inicia 1 linha do registro atual. Neste exemplo, chamar `Move( 1 )` depois de chamar `Open` busca o conjunto de linhas que consiste em linhas de 2 a 11, com o registro atual posicionado na linha 2. Para obter mais informações, consulte a função [mover](../../mfc/reference/crecordset-class.md#move) membro.

- Ao contrário do registro de campo, os assistentes não dão suporte à troca de campo de registro em massa. Isso significa que você deve declarar manualmente os membros de dados de campo e substituir manualmente `DoBulkFieldExchange` gravando chamadas para as funções de suporte RFX em massa. Para obter mais informações, consulte [Record Field Exchange Functions](../../mfc/reference/record-field-exchange-functions.md) na *referência da biblioteca de classes*.

##  <a name="how-to-implement-bulk-record-field-exchange"></a><a name="_core_how_to_implement_bulk_record_field_exchange"></a>Como implementar a troca de campo de registro em massa

A troca de campo de registro em massa transfere um conjunto de linhas de dados da fonte de dados para o objeto Recordset. As funções de suporte RFX em massa usam matrizes para armazenar esses dados, bem como matrizes para armazenar o comprimento de cada item de dados no conjunto de linhas. Em sua definição de classe, você deve definir os membros de dados de campo como ponteiros para acessar as matrizes de dados. Além disso, você deve definir um conjunto de ponteiros para acessar as matrizes de comprimentos. Quaisquer membros de dados de parâmetro não devem ser declarados como ponteiros; a declaração de membros de dados de parâmetro ao usar a troca de campo de registro em massa é a mesma que declará-los ao usar a troca de campo de registro. O código a seguir mostra um exemplo simples:

```cpp
class MultiRowSet : public CRecordset
{
public:
   // Field/Param Data
      // field data members
      long* m_rgID;
      LPSTR m_rgName;

      // pointers for the lengths
      // of the field data
      long* m_rgIDLengths;
      long* m_rgNameLengths;

      // input parameter data member
      CString m_strNameParam;

   .
   .
   .
}
```

Você pode alocar esses buffers de armazenamento manualmente ou fazer com que a estrutura faça a alocação. Para alocar os buffers por conta própria, você deve especificar a opção `CRecordset::userAllocMultiRowBuffers` do parâmetro *dwOptions* na função de membro `Open`. Certifique-se de definir os tamanhos das matrizes pelo menos igual ao tamanho do conjunto de linhas. Se desejar que a estrutura faça a alocação, você deverá inicializar seus ponteiros para NULL. Normalmente, isso é feito no construtor do objeto Recordset:

```cpp
MultiRowSet::MultiRowSet( CDatabase* pDB )
   : CRecordset( pDB )
{
   m_rgID = NULL;
   m_rgName = NULL;
   m_rgIDLengths = NULL;
   m_rgNameLengths = NULL;
   m_strNameParam = "";

   m_nFields = 2;
   m_nParams = 1;

   .
   .
   .
}
```

Por fim, você deve substituir a função membro `DoBulkFieldExchange`. Para os membros de dados de campo, chame as funções de suporte RFX em massa; para qualquer membro de dados de parâmetro, chame as funções suporte RFX. Se você abriu o conjunto de registros passando uma instrução SQL ou um procedimento armazenado para `Open`, a ordem na qual você faz as chamadas de suporte RFX em massa deve corresponder à ordem das colunas no conjunto de registros; da mesma forma, a ordem das chamadas suporte RFX para parâmetros deve corresponder à ordem dos parâmetros na instrução SQL ou no procedimento armazenado.

```cpp
void MultiRowSet::DoBulkFieldExchange( CFieldExchange* pFX )
{
   // call the Bulk RFX functions
   // for field data members
   pFX->SetFieldType( CFieldExchange::outputColumn );
   RFX_Long_Bulk( pFX, _T( "[colRecID]" ),
                  &m_rgID, &m_rgIDLengths );
   RFX_Text_Bulk( pFX, _T( "[colName]" ),
                  &m_rgName, &m_rgNameLengths, 30 );

   // call the RFX functions for
   // for parameter data members
   pFX->SetFieldType( CFieldExchange::inputParam );
   RFX_Text( pFX, "NameParam", m_strNameParam );
}
```

> [!NOTE]
>  Você deve chamar a função de membro `Close` antes de a classe derivada `CRecordset` sair do escopo. Isso garante que qualquer memória alocada pela estrutura seja liberada. É uma boa prática de programação sempre chamar explicitamente `Close`, independentemente se você implementou a busca em massa de linhas.

Para obter mais informações sobre a troca de campo de registro (suporte RFX), consulte [gravar campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre como usar parâmetros, consulte [CFieldExchange:: SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) e [Recordset: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[CRecordset:: m_nFields](../../mfc/reference/crecordset-class.md#m_nfields)<br/>
[CRecordset:: m_nParams](../../mfc/reference/crecordset-class.md#m_nparams)
