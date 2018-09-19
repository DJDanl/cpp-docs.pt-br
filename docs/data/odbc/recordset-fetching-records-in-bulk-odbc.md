---
title: 'Conjunto de registros: Buscando registros em massa (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0dce69b180a00ca44fdb2916136ac8107a4d94dd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103913"
---
# <a name="recordset-fetching-records-in-bulk-odbc"></a>Conjunto de registros: recuperando registros em massa (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Classe `CRecordset` fornece suporte para busca de linhas em massa, o que significa que vários registros podem ser recuperados de uma vez durante uma única busca, em vez de recuperar um registro por vez da fonte de dados. Você pode implementar a busca de linhas em massa em uma derivada `CRecordset` classe. O processo de transferência de dados da fonte de dados para o objeto recordset é chamado em massa registrar troca de campos (RFX em massa). Observe que, se você não estiver usando a busca de linhas em massa em uma `CRecordset`-classe derivada, os dados é transferido por registrar troca de campos (RFX). Para obter mais informações, consulte [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
Este tópico explica:  
  
- [Como CRecordset dá suporte à busca de linhas em massa](#_core_how_crecordset_supports_bulk_row_fetching).  
  
- [Busca de linhas em massa de algumas considerações especiais ao usar](#_core_special_considerations).  
  
- [Como implementar a troca de campos de registro em massa](#_core_how_to_implement_bulk_record_field_exchange).  
  
##  <a name="_core_how_crecordset_supports_bulk_row_fetching"></a> Como CRecordset dá suporte à busca de linhas em massa  

Antes de abrir seu objeto de conjunto de registros, você pode definir um tamanho de conjunto de linhas com o `SetRowsetSize` função de membro. O tamanho do conjunto de linhas Especifica quantos registros devem ser recuperado durante uma única busca. Quando a busca de linhas em massa é implementada, o tamanho do conjunto de linhas padrão é 25. Se não for implementado a busca de linhas em massa, o tamanho do conjunto de linhas permanece fixo em 1.  
  
Após você ter inicializado o tamanho do conjunto de linhas, chame o [abrir](../../mfc/reference/crecordset-class.md#open) função de membro. Aqui, você deve especificar o `CRecordset::useMultiRowFetch` opção do *dwOptions* parâmetro para implementar a busca de linhas em massa. Além disso, você pode definir o `CRecordset::userAllocMultiRowBuffers` opção. O mecanismo de troca de campos de registro em massa usa matrizes para armazenar várias linhas de dados recuperados durante uma busca. Esses buffers de armazenamento podem ser alocados automaticamente pela estrutura, ou pode alocá-los manualmente. Especificando o `CRecordset::userAllocMultiRowBuffers` opção significa que você fará a alocação.  
  
A tabela a seguir lista as funções de membro fornecidas pelo `CRecordset` para dar suporte à busca de linhas em massa.  
  
|Função de membro|Descrição|  
|---------------------|-----------------|  
|[CheckRowsetError](../../mfc/reference/crecordset-class.md#checkrowseterror)|Função virtual que trata os erros que ocorrem durante a busca.|  
|[DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange)|Implementa em massa a troca de campos de registro. Chamado automaticamente para transferências de várias linhas de dados da fonte de dados para o objeto de conjunto de registros.|  
|[GetRowsetSize](../../mfc/reference/crecordset-class.md#getrowsetsize)|Recupera a configuração atual para o tamanho do conjunto de linhas.|  
|[GetRowsFetched](../../mfc/reference/crecordset-class.md#getrowsfetched)|Informa quantas linhas foram realmente recuperadas após uma busca de determinado. Na maioria dos casos, isso é o tamanho do conjunto de linhas, a menos que um conjunto de linhas incompleto foi buscado.|  
|[GetRowStatus](../../mfc/reference/crecordset-class.md#getrowstatus)|Retorna um status de busca para uma linha específica dentro de um conjunto de linhas.|  
|[RefreshRowset](../../mfc/reference/crecordset-class.md#refreshrowset)|Atualiza os dados e o status de uma linha específica dentro de um conjunto de linhas.|  
|[SetRowsetCursorPosition](../../mfc/reference/crecordset-class.md#setrowsetcursorposition)|Move o cursor para uma linha específica dentro de um conjunto de linhas.|  
|[SetRowsetSize](../../mfc/reference/crecordset-class.md#setrowsetsize)|Função virtual que altera a configuração para o tamanho do conjunto de linhas para o valor especificado.|  
  
##  <a name="_core_special_considerations"></a> Considerações especiais  

Embora a busca de linhas em massa é um ganho de desempenho, certos recursos operam de forma diferente. Antes de decidir implementar a busca de linhas em massa, considere o seguinte:  
  
- O framework chama automaticamente o `DoBulkFieldExchange` a função de membro para transferir dados da fonte de dados para o objeto de conjunto de registros. No entanto, dados não são transferidos do conjunto de volta para a fonte de dados. Chamar o `AddNew`, `Edit`, `Delete`, ou `Update` resultados de funções de membro em uma declaração com falha. Embora `CRecordset` atualmente não fornece um mecanismo para atualizar linhas em massa de dados, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`. Para obter mais informações sobre `SQLSetPos`, consulte o *referência do programador de ODBC SDK* na documentação do MSDN.  
  
- As funções de membro `IsDeleted`, `IsFieldDirty`, `IsFieldNull`, `IsFieldNullable`, `SetFieldDirty`, e `SetFieldNull` não pode ser usado em conjuntos de registros que implementam a busca de linhas em massa. No entanto, você pode chamar `GetRowStatus` em vez de `IsDeleted`, e `GetODBCFieldInfo` no lugar de `IsFieldNullable`.  
  
- O `Move` operações reposiciona seu conjunto de registros por conjunto de linhas. Por exemplo, suponha que você abrir um conjunto de registros que tem 100 registros com um tamanho inicial do conjunto de linhas de 10. `Open` busca linhas 1 a 10, com o registro atual posicionadas na linha 1. Uma chamada para `MoveNext` busca o próximo conjunto de linhas, não a próxima linha. Esse conjunto de linhas consiste em linhas 11 a 20, com o registro atual posicionadas na linha 11. Observe que `MoveNext` e `Move( 1 )` não são equivalentes quando a busca de linhas em massa é implementada. `Move( 1 )` busca o conjunto de linhas que começa a 1 linha do registro atual. Neste exemplo, chamando `Move( 1 )` depois de chamar `Open` busca o conjunto de linhas consiste em linhas de 2 a 11, com o registro atual posicionado na linha 2. Para obter mais informações, consulte o [mover](../../mfc/reference/crecordset-class.md#move) função de membro.  
  
- Ao contrário de troca de campos de registro, os assistentes não oferecem suporte a troca de campos de registro em massa. Isso significa que você deve declarar manualmente seus membros de dados de campo e substituir manualmente `DoBulkFieldExchange` escrevendo chamadas para as funções RFX em massa. Para obter mais informações, consulte [funções de troca de campo do registro](../../mfc/reference/record-field-exchange-functions.md) na *referência da biblioteca de classe*.  
  
##  <a name="_core_how_to_implement_bulk_record_field_exchange"></a> Como implementar a troca de campos de registro em massa  

Troca de campos de registro em massa transfere um conjunto de linhas de dados da fonte de dados para o objeto de conjunto de registros. As funções RFX em massa usarem matrizes para armazenar esses dados, bem como matrizes para armazenar o comprimento de cada item de dados no conjunto de linhas. Em sua definição de classe, você deve definir seus membros de dados do campo como ponteiros para acessar os conjuntos de dados. Além disso, você deve definir um conjunto de ponteiros para as matrizes de comprimentos de acesso. Quaisquer membros de dados de parâmetro não devem ser declarados como ponteiros; declarar membros de dados de parâmetro ao usar o exchange de campos de registro em massa é o mesmo que declará-los ao usar o exchange de campos de registro. O código a seguir mostra um exemplo simples:  
  
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
  
Você pode alocar esses buffers de armazenamento manualmente, ou ter o framework fazem a alocação. Para alocar os buffers, você deve especificar o `CRecordset::userAllocMultiRowBuffers` opção do *dwOptions* parâmetro no `Open` função de membro. Certifique-se de definir os tamanhos das matrizes pelo menos igual ao tamanho do conjunto de linhas. Se você quiser ter o framework fazem a alocação, você deve inicializar os ponteiros como NULL. Normalmente, isso é feito no construtor do objeto de conjunto de registros:  
  
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
  
Por fim, você deve substituir o `DoBulkFieldExchange` função de membro. Para os membros de dados de campo, chame as funções RFX em massa; para qualquer membro de dados de parâmetro, chame as funções RFX. Se você abriu o conjunto de registros passando uma instrução SQL ou procedimento armazenado para `Open`, a ordem na qual você fazer as chamadas de RFX em massa deve corresponder à ordem de colunas no conjunto de registros; da mesma forma, a ordem do RFX chama para parâmetros devem corresponder ordem dos parâmetros na instrução SQL ou procedimento armazenado.  
  
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
>  Você deve chamar o `Close` função de membro antes de sua derivada `CRecordset` classe sai do escopo. Isso garante que toda a memória alocada pela estrutura sejam liberados. Ela é boa prática chamar sempre explicitamente `Close`, independentemente de se você tiver implementado a busca de linhas em massa.  
  
Para obter mais informações sobre como registrar troca de campos (RFX), consulte [troca de campos do registro: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre como usar parâmetros, consulte [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) e [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
## <a name="see-also"></a>Consulte também  

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[CRecordset::m_nFields](../../mfc/reference/crecordset-class.md#m_nfields)<br/>
[CRecordset::m_nParams](../../mfc/reference/crecordset-class.md#m_nparams)

