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
ms.openlocfilehash: ec4d83481f6335d4c40ffb8f004b617f2ee09c62
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367028"
---
# <a name="recordset-fetching-records-in-bulk-odbc"></a>Conjunto de registros: recuperando registros em massa (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

A `CRecordset` classe fornece suporte para a busca de linhas em massa, o que significa que vários registros podem ser recuperados de uma só vez durante uma única busca, em vez de recuperar um registro de cada vez da fonte de dados. Você pode implementar a busca em `CRecordset` massa em uma classe derivada. O processo de transferência de dados da fonte de dados para o objeto recordset é chamado de troca de campo de registro em massa (Bulk RFX). Observe que se você não estiver usando `CRecordset`a busca de linha em massa em uma classe derivada, os dados são transferidos via record field exchange (RFX). Para obter mais informações, consulte [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

Este tópico explica:

- [Como o CRecordset suporta a busca de linhas em massa](#_core_how_crecordset_supports_bulk_row_fetching).

- [Algumas considerações especiais ao usar a busca de linhas a granel](#_core_special_considerations).

- [Como implementar a troca de campo de registro em massa](#_core_how_to_implement_bulk_record_field_exchange).

## <a name="how-crecordset-supports-bulk-row-fetching"></a><a name="_core_how_crecordset_supports_bulk_row_fetching"></a>Como o CRecordset suporta a busca de linhas em massa

Antes de abrir o objeto do conjunto de `SetRowsetSize` gravações, você pode definir um tamanho de conjunto de linhas com a função membro. O tamanho do conjunto de linhas especifica quantos registros devem ser recuperados durante uma única busca. Quando a busca de linhas em massa é implementada, o tamanho padrão do conjunto de linhas é de 25. Se a busca de linhas a granel não for implementada, o tamanho do conjunto de linhas permanece fixo em 1.

Depois de inicializar o tamanho do conjunto de linhas, chame a função De membro [Aberto.](../../mfc/reference/crecordset-class.md#open) Aqui você deve `CRecordset::useMultiRowFetch` especificar a opção do parâmetro *dwOptions* para implementar a busca de linhas em massa. Além disso, você `CRecordset::userAllocMultiRowBuffers` pode definir a opção. O mecanismo de troca de campo de registro em massa usa matrizes para armazenar as várias linhas de dados recuperados durante uma busca. Esses buffers de armazenamento podem ser alocados automaticamente pela estrutura ou você pode alocá-los manualmente. Especificar `CRecordset::userAllocMultiRowBuffers` a opção significa que você fará a alocação.

A tabela a seguir lista as `CRecordset` funções de membro fornecidas para suportar a busca em linha em massa.

|Função de membro|Descrição|
|---------------------|-----------------|
|[Checkrowseterror](../../mfc/reference/crecordset-class.md#checkrowseterror)|Função virtual que lida com quaisquer erros que ocorrem durante a busca.|
|[Dobulkfieldexchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange)|Implementa a troca de campo de registro em massa. Chamado automaticamente para transferir várias linhas de dados da fonte de dados para o objeto recordset.|
|[GetRowsetSize](../../mfc/reference/crecordset-class.md#getrowsetsize)|Recupera a configuração atual para o tamanho do conjunto de linhas.|
|[GetRowsFetched](../../mfc/reference/crecordset-class.md#getrowsfetched)|Diz quantas linhas foram realmente recuperadas após uma dada busca. Na maioria dos casos, este é o tamanho do conjunto de linhas, a menos que um conjunto de linhas incompleto tenha sido buscado.|
|[Getrowstatus](../../mfc/reference/crecordset-class.md#getrowstatus)|Retorna um status de buscar para uma linha específica dentro de um conjunto de linhas.|
|[Refreshrowset](../../mfc/reference/crecordset-class.md#refreshrowset)|Atualiza os dados e o status de uma linha específica dentro de um conjunto de linhas.|
|[Setrowsetcursorposition](../../mfc/reference/crecordset-class.md#setrowsetcursorposition)|Move o cursor para uma linha específica dentro de um conjunto de linhas.|
|[Setrowsetsize](../../mfc/reference/crecordset-class.md#setrowsetsize)|Função virtual que altera a configuração do tamanho do conjunto de linhas para o valor especificado.|

## <a name="special-considerations"></a><a name="_core_special_considerations"></a>Considerações Especiais

Embora a busca de linhas em massa seja um ganho de desempenho, certos recursos operam de forma diferente. Antes de decidir implementar a busca de linhas em massa, considere o seguinte:

- A estrutura chama `DoBulkFieldExchange` automaticamente a função de membro para transferir dados da fonte de dados para o objeto recordset. No entanto, os dados não são transferidos do conjunto de registros de volta para a fonte de dados. Chamar `AddNew`as `Edit` `Delete`funções `Update` de membro ou membro resulta em uma afirmação falha. Embora `CRecordset` atualmente não forneça um mecanismo para atualizar linhas em massa de dados, você pode `SQLSetPos`escrever suas próprias funções usando a função API ODBC . Para obter `SQLSetPos`mais informações sobre , consulte a *referência do programador ODBC SDK* na documentação do MSDN.

- O membro `IsDeleted`funciona `IsFieldDirty` `IsFieldNull`, `IsFieldNullable` `SetFieldDirty`, `SetFieldNull` , , , , e não pode ser usado em conjuntos de registros que implementam a busca de linhas em massa. No entanto, `GetRowStatus` você `IsDeleted`pode `GetODBCFieldInfo` ligar no `IsFieldNullable`lugar de , e no lugar de .

- As `Move` operações reposicionam seu conjunto de registros por conjunto de linhas. Por exemplo, suponha que você abra um conjunto de registros que tenha 100 registros com um tamanho inicial de linha de 10. `Open`busca linhas 1 a 10, com o recorde atual posicionado na linha 1. Uma chamada `MoveNext` para buscar o próximo conjunto de linhas, não a próxima linha. Este conjunto de linhas consiste em linhas 11 a 20, com o recorde atual posicionado na linha 11. Observe `MoveNext` que `Move( 1 )` e não são equivalentes quando a busca de linhas a granel é implementada. `Move( 1 )`busca o conjunto de linhas que começa 1 linha do registro atual. Neste exemplo, `Move( 1 )` chamar `Open` após a chamada busca o conjunto de linhas que consiste nas linhas 2 a 11, com o registro atual posicionado na linha 2. Para obter mais informações, consulte a função [Mover](../../mfc/reference/crecordset-class.md#move) membro.

- Ao contrário da troca de campo de registro, os assistentes não suportam a troca de campo de registro em massa. Isso significa que você deve declarar manualmente seus `DoBulkFieldExchange` membros de dados de campo e substituir manualmente escrevendo chamadas para as funções RFX em massa. Para obter mais informações, consulte [Funções de troca de campo de registro](../../mfc/reference/record-field-exchange-functions.md) na referência da biblioteca de *classe*.

## <a name="how-to-implement-bulk-record-field-exchange"></a><a name="_core_how_to_implement_bulk_record_field_exchange"></a>Como implementar o field exchange de registro em massa

A troca de campo de registro em massa transfere um conjunto de dados da fonte de dados para o objeto recordset. As funções Bulk RFX usam arrays para armazenar esses dados, bem como matrizes para armazenar o comprimento de cada item de dados no conjunto de linhas. Na definição de classe, você deve definir seus membros de dados de campo como ponteiros para acessar os arrays de dados. Além disso, você deve definir um conjunto de ponteiros para acessar as matrizes de comprimentos. Quaisquer membros de dados de parâmetros não devem ser declarados como ponteiros; declarar membros de dados de parâmetros ao usar a troca de campo de registro em massa é o mesmo que declará-los ao usar a troca de campo de registro. O código a seguir mostra um exemplo simples:

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

Você pode alocar esses buffers de armazenamento manualmente ou fazer com que a estrutura faça a alocação. Para alocar os buffers você `CRecordset::userAllocMultiRowBuffers` mesmo, você deve especificar `Open` a opção do parâmetro *dwOptions* na função membro. Certifique-se de definir os tamanhos das matrizes pelo menos iguais ao tamanho do conjunto de linhas. Se você quiser que a estrutura faça a alocação, você deve inicializar seus ponteiros para NULL. Isso é normalmente feito no construtor do objeto recordset:

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

Finalmente, você deve `DoBulkFieldExchange` substituir a função do membro. Para os membros de dados de campo, ligue para as funções Bulk RFX; para quaisquer membros de dados de parâmetros, ligue para as funções RFX. Se você abriu o conjunto de registros passando uma `Open`declaração SQL ou procedimento armazenado para , a ordem na qual você faz as chamadas RFX em massa deve corresponder à ordem das colunas no conjunto de registros; da mesma forma, a ordem das chamadas RFX para parâmetros deve corresponder à ordem dos parâmetros na declaração SQL ou no procedimento armazenado.

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
> Você deve `Close` chamar a função `CRecordset` de membro antes que sua classe derivada saia do escopo. Isso garante que qualquer memória alocada pela estrutura seja liberada. É uma boa prática de programação `Close`para sempre chamar explicitamente, independentemente de você ter implementado a busca em linha em massa.

Para obter mais informações sobre o Record Field Exchange (RFX), consulte [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre o uso de parâmetros, consulte [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) e [Recordset: Parametisizing a Recordset (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros de c::m_nFields](../../mfc/reference/crecordset-class.md#m_nfields)<br/>
[CRecordset::m_nParams](../../mfc/reference/crecordset-class.md#m_nparams)
