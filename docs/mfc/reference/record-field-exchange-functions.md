---
title: Registrar funções de troca de campos
ms.date: 09/17/2019
f1_keywords:
- AFXDB/RFX_Binary
- AFXDB/RFX_Bool
- AFXDB/RFX_Byte
- AFXDB/RFX_Date
- AFXDB/RFX_Double
- AFXDB/RFX_Int
- AFXDB/RFX_Long
- AFXDB/RFX_LongBinary
- AFXDB/RFX_Single
- AFXDB/RFX_Text
- AFXDB/RFX_Binary_Bulk
- AFXDB/RFX_Bool_Bulk
- AFXDB/RFX_Byte_Bulk
- AFXDB/RFX_Date_Bulk
- AFXDB/RFX_Double_Bulk
- AFXDB/RFX_Int_Bulk
- AFXDB/RFX_Long_Bulk
- AFXDB/RFX_Single_Bulk
- AFXDB/RFX_Text_Bulk
- AFXDB/DFX_Binary
- AFXDB/DFX_Bool
- AFXDB/DFX_Byte
- AFXDB/DFX_Currency
- AFXDB/DFX_DateTime
- AFXDB/DFX_Double
- AFXDB/DFX_Long
- AFXDB/DFX_LongBinary
- AFXDB/DFX_Short
- AFXDB/DFX_Single
- AFXDB/DFX_Text
helpviewer_keywords:
- DAO (Data Access Objects), record field exchange (DFX)
- ODBC, bulk RFX data exchange functions [MFC]
- RFX (record field exchange), ODBC classes
- DFX (DAO record field exchange), data exchange functions [MFC]
- DFX functions [MFC]
- bulk RFX functions [MFC]
- DFX (DAO record field exchange)
- RFX (record field exchange), DAO classes
- ODBC, RFX
- RFX (record field exchange), data exchange functions [MFC]
- RFX (record field exchange)
ms.assetid: 6e4c5c1c-acb7-4c18-bf51-bf7959a696cd
ms.openlocfilehash: 9bb1b7bcbce16bba8029fcfbbeea7552b1d4a0ba
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843593"
---
# <a name="record-field-exchange-functions"></a>Registrar funções de troca de campos

Este tópico lista as funções de troca de campo de registro (suporte RFX, suporte RFX em massa e DFX) usadas para automatizar a transferência de dados entre um objeto Recordset e sua fonte de dados e executar outras operações nos dados.

Se você estiver usando as classes baseadas em ODBC e tiver implementado a busca de linha em massa, será necessário substituir manualmente a `DoBulkFieldExchange` função de membro do `CRecordset` chamando as funções de suporte RFX em massa para cada membro de dados correspondente a uma coluna de fonte de dados.

Se você não tiver implementado a busca de linha em massa nas classes baseadas em ODBC ou se estiver usando as classes baseadas em DAO (obsoleto), ClassWizard substituirá a `DoFieldExchange` função membro de `CRecordset` ou `CDaoRecordset` chamando as funções suporte RFX (para classes ODBC) ou as funções DFX (para classes DAO) para cada membro de dados de campo em seu conjunto de registros.

O campo registro troca funções de transferência cada vez que a estrutura chama `DoFieldExchange` ou `DoBulkFieldExchange` . Cada função transfere um tipo de dados específico.

Para obter mais informações sobre como essas funções são usadas, consulte os artigos [registro de campo Exchange: How suporte RFX Works (ODBC)](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Para colunas de dados que você associa dinamicamente, você também pode chamar as funções suporte RFX ou DFX, conforme explicado no conjunto de [registros de artigos: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md). Além disso, você pode escrever suas próprias rotinas suporte RFX ou DFX personalizadas, conforme explicado na observação técnica [43](../../mfc/tn043-rfx-routines.md) (para ODBC) e nota técnica [53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) (para o DAO).

Para obter um exemplo de suporte RFX e funções de suporte RFX em massa como aparecem `DoFieldExchange` nas `DoBulkFieldExchange` funções e, consulte [RFX_Text](#rfx_text) e [RFX_Text_Bulk] #rfx_text_bulk). As funções DFX são muito semelhantes às funções suporte RFX.

### <a name="rfx-functions-odbc"></a>Funções suporte RFX (ODBC)

|Nome|Descrição|
|-|-|
|[RFX_Binary](#rfx_binary)|Transfere matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|
|[RFX_Bool](#rfx_bool)|Transfere dados boolianos.|
|[RFX_Byte](#rfx_byte)|Transfere um único byte de dados.|
|[RFX_Date](#rfx_date)|Transfere dados de data e hora usando [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou TIMESTAMP_STRUCT.|
|[RFX_Double](#rfx_double)|Transfere dados float de precisão dupla.|
|[RFX_Int](#rfx_int)|Transfere dados inteiros.|
|[RFX_Long](#rfx_long)|Transfere dados inteiros longos.|
|[RFX_LongBinary](#rfx_longbinary)|Transfere dados BLOB (objeto binário grande) com um objeto da classe [CLongBinary](clongbinary-class.md) .|
|[RFX_Single](#rfx_single)|Transfere dados float.|
|[RFX_Text](#rfx_text)|Transfere dados de cadeia de caracteres.|

### <a name="bulk-rfx-functions-odbc"></a>Funções de suporte RFX em massa (ODBC)

|Nome|Descrição|
|-|-|
|[RFX_Binary_Bulk](#rfx_binary_bulk)|Transfere matrizes de dados de byte.|
|[RFX_Bool_Bulk](#rfx_bool_bulk)|Transfere matrizes de dados boolianos.|
|[RFX_Byte_Bulk](#rfx_byte_bulk)|Transfere matrizes de bytes únicos.|
|[RFX_Date_Bulk](#rfx_date_bulk)|Transfere matrizes de dados do tipo TIMESTAMP_STRUCT.|
|[RFX_Double_Bulk](#rfx_double_bulk)|Transfere matrizes de dados de ponto flutuante de precisão dupla.|
|[RFX_Int_Bulk](#rfx_int_bulk)|Transfere matrizes de dados inteiros.|
|[RFX_Long_Bulk](#rfx_long_bulk)|Transfere matrizes de dados inteiros longos.|
|[RFX_Single_Bulk](#rfx_single_bulk)|Transfere matrizes de dados de ponto flutuante.|
|[RFX_Text_Bulk](#rfx_text_bulk)|Transfere matrizes de dados do tipo LPSTR.|

### <a name="dfx-functions-dao"></a>Funções DFX (DAO)

|Nome|Descrição|
|-|-|
|[DFX_Binary](#dfx_binary)|Transfere matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|
|[DFX_Bool](#dfx_bool)|Transfere dados boolianos.|
|[DFX_Byte](#dfx_byte)|Transfere um único byte de dados.|
|[DFX_Currency](#dfx_currency)|Transfere dados de moeda, do tipo [COleCurrency](colecurrency-class.md).|
|[DFX_DateTime](#dfx_datetime)|Transfere dados de data e hora, do tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md).|
|[DFX_Double](#dfx_double)|Transfere dados float de precisão dupla.|
|[DFX_Long](#dfx_long)|Transfere dados inteiros longos.|
|[DFX_LongBinary](#dfx_longbinary)|Transfere dados BLOB (objeto binário grande) com um objeto da `CLongBinary` classe. Para o DAO, é recomendável que você use [DFX_Binary](#dfx_binary) em vez disso.|
|[DFX_Short](#dfx_short)|Transfere dados inteiros curtos.|
|[DFX_Single](#dfx_single)|Transfere dados float.|
|[DFX_Text](#dfx_text)|Transfere dados de cadeia de caracteres.|

=============================================

## <a name="rfx_binary"></a><a name="rfx_binary"></a> RFX_Binary

Transfere matrizes de bytes entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_BINARY, SQL_VARBINARY ou SQL_LONGVARBINARY.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Binary(
   CFieldExchange* pFX,
   const char* szName,
   CByteArray& value,
   int nMaxLength = 255);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CByteArray](cbytearray-class.md), é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nMaxLength*<br/>
O comprimento máximo permitido da cadeia de caracteres ou da matriz que está sendo transferida. O valor padrão de *nMaxLength* é 255. Os valores válidos são de 1 a INT_MAX. A estrutura aloca essa quantidade de espaço para os dados. Para obter o melhor desempenho, passe um valor grande o suficiente para acomodar o maior item de dados esperado.

### <a name="remarks"></a>Comentários

Os dados na fonte de dados desses tipos são mapeados para e de tipo `CByteArray` no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_bool"></a><a name="rfx_bool"></a> RFX_Bool

Transfere dados boolianos entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_BIT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Bool(
   CFieldExchange* pFX,
   const char* szName,
   BOOL& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BOOL, é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_byte"></a><a name="rfx_byte"></a> RFX_Byte

Transfere um único byte entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_TINYINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Byte(
   CFieldExchange* pFX,
   const char* szName,
   BYTE& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BYTE, é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_date"></a><a name="rfx_date"></a> RFX_Date

Transfere `CTime` ou TIMESTAMP_STRUCT dados entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_DATE, SQL_TIME ou SQL_TIMESTAMP.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Date(
   CFieldExchange* pFX,
   const char* szName,
   CTime& value);

void RFX_Date(
   CFieldExchange* pFX,
   const char* szName,
   TIMESTAMP_STRUCT& value);

void RFX_Date(
   CFieldExchange* pFX,
   const char* szName,
   COleDateTime& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado; o valor a ser transferido. As várias versões da função usam tipos de dados diferentes para o valor:

A primeira versão da função usa uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) . Para uma transferência do conjunto de registros para a fonte de dados, esse valor é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

A segunda versão da função usa uma referência a uma `TIMESTAMP_STRUCT` estrutura. Você deve configurar essa estrutura por conta própria antes da chamada. Não há suporte para o suporte de campo DDX (troca de dados de caixa de diálogo) nem para o assistente de código para esta versão. A terceira versão da função funciona de forma semelhante à primeira versão, exceto que ela usa uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) .

### <a name="remarks"></a>Comentários

A `CTime` versão da função impõe a sobrecarga de algum processamento intermediário e tem um intervalo um pouco limitado. Se você encontrar qualquer um desses fatores limitando, use a segunda versão da função. Mas Observe sua falta de assistente de código e suporte campo DDX e o requisito que você mesmo configurou a estrutura.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_double"></a><a name="rfx_double"></a> RFX_Double

Transfere dados **float duplos** entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_DOUBLE.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Double(
   CFieldExchange* pFX,
   const char* szName,
   double& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`double`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_int"></a><a name="rfx_int"></a> RFX_Int

Transfere dados inteiros entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_SMALLINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Int(
   CFieldExchange* pFX,
   const char* szName,
   int& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`int`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_long"></a><a name="rfx_long"></a> RFX_Long

Transfere dados inteiros longos entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_INTEGER.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Long(
   CFieldExchange* pFX,
   const char* szName,
   LONG&
value );
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`long`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_longbinary"></a><a name="rfx_longbinary"></a> RFX_LongBinary

Transfere dados BLOB (objeto binário grande) usando a classe [CLongBinary](clongbinary-class.md) entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_LONGVARBINARY ou SQL_LONGVARCHAR.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_LongBinary(
   CFieldExchange* pFX,
   const char* szName,
   CLongBinary& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo `CLongBinary` , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_single"></a><a name="rfx_single"></a> RFX_Single

Transfere dados de ponto flutuante entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_REAL.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Single(
   CFieldExchange* pFX,
   const char* szName,
   float& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`float`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_text"></a><a name="rfx_text"></a> RFX_Text

Transfere `CString` dados entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_LONGVARCHAR, SQL_CHAR, SQL_VARCHAR, SQL_DECIMAL ou SQL_NUMERIC.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Text(
   CFieldExchange* pFX,
   const char* szName,
   CString& value,
   int nMaxLength = 255,
   int nColumnType = SQL_VARCHAR,
   short nScale = 0);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe `CFieldExchange` . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo `CString` , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nMaxLength*<br/>
O comprimento máximo permitido da cadeia de caracteres ou da matriz que está sendo transferida. O valor padrão de *nMaxLength* é 255. Os valores válidos são de 1 a INT_MAX). A estrutura aloca essa quantidade de espaço para os dados. Para obter o melhor desempenho, passe um valor grande o suficiente para acomodar o maior item de dados esperado.

*nColumnType*<br/>
Usado principalmente para parâmetros. Um inteiro que indica o tipo de dados do parâmetro. O tipo é um tipo de dados ODBC do formulário **SQL_XXX**.

*nScale*<br/>
Especifica a escala de valores do tipo ODBC SQL_DECIMAL ou SQL_NUMERIC. *nScale* só é útil ao definir valores de parâmetro. Para obter mais informações, consulte o tópico "precisão, escala, comprimento e tamanho de exibição" no Apêndice D da *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

Os dados na fonte de dados de todos esses tipos são mapeados para e de `CString` no conjunto de registros.

### <a name="example"></a>Exemplo

Este exemplo mostra várias chamadas para `RFX_Text` . Observe também as duas chamadas para `CFieldExchange::SetFieldType` . Para parâmetros, você deve gravar a chamada `SetFieldType` e sua chamada suporte RFX. A chamada de coluna de saída e suas chamadas suporte RFX associadas são normalmente gravadas por um assistente de código.

```cpp
void CCustomer::DoFieldExchange(CFieldExchange* pFX)
{
   pFX->SetFieldType(CFieldExchange::outputColumn);
   // Macros such as RFX_Text() and RFX_Int() are dependent on the
   // type of the member variable, not the type of the field in the database.
   // ODBC will try to automatically convert the column value to the requested type
   RFX_Long(pFX, _T("[CustomerID]"), m_CustomerID);
   RFX_Text(pFX, _T("[ContactFirstName]"), m_ContactFirstName);
   RFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
   RFX_Text(pFX, _T("[L_Name]"), m_L_Name);
   RFX_Long(pFX, _T("[BillingID]"), m_BillingID);

   pFX->SetFieldType(CFieldExchange::inputParam);
   RFX_Text(pFX, _T("Param"), m_strParam);
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_binary_bulk"></a><a name="rfx_binary_bulk"></a> RFX_Binary_Bulk

Transfere várias linhas de dados de byte de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Binary_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BYTE** prgByteVals,
   long** prgLengths,
   int nMaxLength);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgByteVals*<br/>
Um ponteiro para uma matriz de valores de BYTE. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgByteVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

*nMaxLength*<br/>
O comprimento máximo permitido dos valores armazenados na matriz apontada por *prgByteVals*. Para garantir que os dados não serão truncados, passe um valor grande o suficiente para acomodar o maior item de dados esperado.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo ODBC de SQL_BINARY, SQL_VARBINARY ou SQL_LONGVARBINARY. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para BYTE.

Se você inicializar *prgByteVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_bool_bulk"></a><a name="rfx_bool_bulk"></a> RFX_Bool_Bulk

Transfere várias linhas de dados boolianos de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Bool_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BOOL** prgBoolVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgBoolVals*<br/>
Um ponteiro para uma matriz de valores BOOL. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgBoolVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de fonte de dados deve ter um tipo ODBC de SQL_BIT. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para BOOL.

Se você inicializar *prgBoolVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_byte_bulk"></a><a name="rfx_byte_bulk"></a> RFX_Byte_Bulk

Transfere várias linhas de bytes únicos de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Byte_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BYTE** prgByteVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgByteVals*<br/>
Um ponteiro para uma matriz de valores de BYTE. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgByteVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de fonte de dados deve ter um tipo ODBC de SQL_TINYINT. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para BYTE.

Se você inicializar *prgByteVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_date_bulk"></a><a name="rfx_date_bulk"></a> RFX_Date_Bulk

Transfere várias linhas de TIMESTAMP_STRUCT dados de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Date_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   TIMESTAMP_STRUCT** prgTSVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgTSVals*<br/>
Um ponteiro para uma matriz de valores de TIMESTAMP_STRUCT. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros. Para obter mais informações sobre o tipo de dados TIMESTAMP_STRUCT, consulte o tópico "C Data Types" no Apêndice D da *referência do programador do ODBC SDK*.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgTSVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo ODBC de SQL_DATE, SQL_TIME ou SQL_TIMESTAMP. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para TIMESTAMP_STRUCT.

Se você inicializar *prgTSVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_double_bulk"></a><a name="rfx_double_bulk"></a> RFX_Double_Bulk

Transfere várias linhas de dados de ponto flutuante de precisão dupla de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Double_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   double** prgDblVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgDblVals*<br/>
Um ponteiro para uma matriz de **`double`** valores. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgDblVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de fonte de dados deve ter um tipo ODBC de SQL_DOUBLE. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para **`double`** .

Se você inicializar *prgDblVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_int_bulk"></a><a name="rfx_int_bulk"></a> RFX_Int_Bulk

Transfere dados inteiros entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_SMALLINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Int(
   CFieldExchange* pFX,
   const char* szName,
   int& value);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações sobre as operações que um `CFieldExchange` objeto pode especificar, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`int`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Consulte [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_long_bulk"></a><a name="rfx_long_bulk"></a> RFX_Long_Bulk

Transfere várias linhas de dados inteiros longos de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Long_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   long** prgLongVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgLongVals*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgLongVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de fonte de dados deve ter um tipo ODBC de SQL_INTEGER. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para **`long`** .

Se você inicializar *prgLongVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_single_bulk"></a><a name="rfx_single_bulk"></a> RFX_Single_Bulk

Transfere várias linhas de dados de ponto flutuante de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Single_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   float** prgFltVals,
   long** prgLengths);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgFltVals*<br/>
Um ponteiro para uma matriz de **`float`** valores. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgFltVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de fonte de dados deve ter um tipo ODBC de SQL_REAL. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para **`float`** .

Se você inicializar *prgFltVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Consulte [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="rfx_text_bulk"></a><a name="rfx_text_bulk"></a> RFX_Text_Bulk

Transfere várias linhas de dados de caractere de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset` objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Text_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   LPSTR* prgStrVals,
   long** prgLengths,
   int nMaxLength);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](cfieldexchange-class.md) . Esse objeto contém informações para definir o contexto para cada chamada da função. Para obter mais informações, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

*szName*<br/>
O nome de uma coluna de dados.

*prgStrVals*<br/>
Um ponteiro para uma matriz de valores LPSTR. Essa matriz irá armazenar os dados a serem transferidos da fonte de dados para o conjunto de registros. Observe que, com a versão atual do ODBC, esses valores não podem ser Unicode.

*prgLengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Essa matriz irá armazenar o comprimento em bytes de cada valor na matriz apontada por *prgStrVals*. Esse comprimento exclui o caractere de término nulo. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor nulo. Para obter mais detalhes, consulte a função da API ODBC `SQLBindCol` na *referência do programador do ODBC SDK*.

*nMaxLength*<br/>
O comprimento máximo permitido dos valores armazenados na matriz apontada por *prgStrVals*, incluindo o caractere de término nulo. Para garantir que os dados não serão truncados, passe um valor grande o suficiente para acomodar o maior item de dados esperado.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo ODBC de SQL_LONGVARCHAR, SQL_CHAR, SQL_VARCHAR, SQL_DECIMAL ou SQL_NUMERIC. O conjunto de registros deve definir um membro de dados de campo do tipo LPSTR.

Se você inicializar *prgStrVals* e *prgLengths* como NULL, as matrizes às quais eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> Campo de registro em massa o Exchange transfere apenas dados da fonte de dados para o objeto Recordset. Para tornar o conjunto de registros atualizável, você deve usar a função da API do ODBC `SQLSetPos` .

Para obter mais informações, consulte o [conjunto de registros de artigos: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Você deve gravar manualmente as chamadas na sua `DoBulkFieldExchange` substituição. Este exemplo mostra uma chamada para `RFX_Text_Bulk` , bem como uma chamada para `RFX_Long_Bulk` , para transferência de dados. Essas chamadas são precedidas por uma chamada para [CFieldExchange:: SetFieldType](cfieldexchange-class.md#setfieldtype). Observe que, para parâmetros, você deve chamar as funções suporte RFX em vez das funções de suporte RFX em massa.

```cpp
void CMultiCustomer::DoBulkFieldExchange(CFieldExchange* pFX)
{
   pFX->SetFieldType(CFieldExchange::outputColumn);
   RFX_Long_Bulk(pFX, _T("[CustomerID]"), &m_pCustomerID, &m_pcCustomerID);
   RFX_Text_Bulk(pFX, _T("[ContactFirstName]"), &m_pContactFirstName, &m_pcContactFirstName, 50);
   RFX_Text_Bulk(pFX, _T("[PostalCode]"), &m_pPostalCode, &m_pcPostalCode, 50);
   RFX_Text_Bulk(pFX, _T("[L_Name]"), &m_pL_Name, &m_pcL_Name, 50);
   RFX_Long_Bulk(pFX, _T("[BillingID]"), &m_pBillingID, &m_pcBillingID);

   pFX->SetFieldType(CFieldExchange::inputParam);
   RFX_Text(pFX, _T("Param"), m_strParam);
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="dfx_binary"></a><a name="dfx_binary"></a> DFX_Binary

Transfere matrizes de bytes entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Binary(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   CByteArray& value,
   int nPreAllocSize = AFX_DAO_BINARY_DEFAULT_SIZE,
   DWORD dwBindOptions = 0);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CByteArray](cbytearray-class.md), é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nPreAllocSize*<br/>
A estrutura prefixa essa quantidade de memória. Se os dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para obter um melhor desempenho, defina esse tamanho como um valor grande o suficiente para evitar realocações. O tamanho padrão é definido em AFXDAO. Arquivo H como AFX_DAO_BINARY_DEFAULT_SIZE.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_DISABLE_FIELD_CACHE, não usa buffer duplo, e você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) por conta própria. O outro valor possível, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo, e você não precisa fazer trabalho adicional para marcar os campos com problemas ou nulos. Por motivos de desempenho e de memória, evite esse valor, a menos que os dados binários sejam relativamente pequenos.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo para todos os campos por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo [CByteArray](cbytearray-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_bool"></a><a name="dfx_bool"></a> DFX_Bool

Transfere dados boolianos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Bool(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   BOOL& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BOOL, é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BOOL no DAO e o tipo BOOL no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_byte"></a><a name="dfx_byte"></a> DFX_Byte

Transfere um único byte entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Byte(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   BYTE& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BYTE, é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo BYTE no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_currency"></a><a name="dfx_currency"></a> DFX_Currency

Transfere dados de moeda entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Currency(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   COleCurrency& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, esse valor é obtido do membro de dados especificado, do tipo [COleCurrency](colecurrency-class.md). Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_CURRENCY no DAO e o tipo [COleCurrency](colecurrency-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_datetime"></a><a name="dfx_datetime"></a> DFX_DateTime

Transfere dados de data e hora entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_DateTime(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   COleDateTime& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. A função usa uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) . Para uma transferência do conjunto de registros para a fonte de dados, esse valor é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_DATE no DAO e o tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) no conjunto de registros.

> [!NOTE]
> `COleDateTime` Substitui [CTime](../../atl-mfc-shared/reference/ctime-class.md) e TIMESTAMP_STRUCT para essa finalidade nas classes DAO. `CTime` e TIMESTAMP_STRUCT ainda são usados para as classes de acesso a dados baseadas em ODBC.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_double"></a><a name="dfx_double"></a> DFX_Double

Transfere dados **float duplos** entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Double(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   double& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`double`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_R8 no DAO e digitam o **float duplo** no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_long"></a><a name="dfx_long"></a> DFX_Long

Transfere dados inteiros longos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Long(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   long& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`long`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_I4 no DAO e digitam **`long`** o conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_longbinary"></a><a name="dfx_longbinary"></a> DFX_LongBinary

**Importante** É recomendável que você use [DFX_Binary](#dfx_binary) em vez desta função.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_LongBinary(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   CLongBinary& value,
   DWORD dwPreAllocSize = AFX_DAO_LONGBINARY_DEFAULT_SIZE,
   DWORD dwBindOptions = 0);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CLongBinary](clongbinary-class.md), é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwPreAllocSize*<br/>
A estrutura prefixa essa quantidade de memória. Se os dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para obter um melhor desempenho, defina esse tamanho como um valor grande o suficiente para evitar realocações.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DISABLE_FIELD_CACHE, não usa buffer duplo. O outro valor possível é AFX_DAO_ENABLE_FIELD_CACHE. Usa buffer duplo e você não precisa fazer mais trabalho para marcar os campos com problemas ou nulos. Por motivos de desempenho e de memória, evite esse valor, a menos que os dados binários sejam relativamente pequenos.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

`DFX_LongBinary` é fornecido para compatibilidade com as classes ODBC do MFC. A `DFX_LongBinary` função transfere dados binários de objeto grande (BLOB) usando `CLongBinary` a classe entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados. Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo [CLongBinary](clongbinary-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_short"></a><a name="dfx_short"></a> DFX_Short

Transfere dados inteiros curtos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Short(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   short& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`short`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_I2 no DAO e digitam **`short`** o conjunto de registros.

> [!NOTE]
> `DFX_Short` é equivalente a [RFX_Int](#rfx_int) para as classes baseadas em ODBC.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_single"></a><a name="dfx_single"></a> DFX_Single

Transfere dados de ponto flutuante entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Single(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   float& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **`float`** , é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar `SetFieldDirty` e por `SetFieldNull` conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_R4 no DAO e digitam **`float`** o conjunto de registros.

### <a name="example"></a>Exemplo

Consulte [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="dfx_text"></a><a name="dfx_text"></a> DFX_Text

Transfere `CString` dados entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Text(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   CString& value,
   int nPreAllocSize = AFX_DAO_TEXT_DEFAULT_SIZE,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Esse objeto contém informações para definir o contexto para cada chamada da função.

*szName*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md), é obtido do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nPreAllocSize*<br/>
A estrutura prefixa essa quantidade de memória. Se os dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para obter um melhor desempenho, defina esse tamanho como um valor grande o suficiente para evitar realocações.

*dwBindOptions*<br/>
Uma opção que permite aproveitar o mecanismo de buffer duplo do MFC para detectar campos do conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa buffer duplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar esse valor, o MFC não fará nenhuma verificação nesse campo. Você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) por conta própria.

> [!NOTE]
> Você pode controlar se os dados são armazenados em buffer duplo por padrão, definindo [CDaoRecordset:: m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_CHAR no DAO (ou, se o símbolo _UNICODE for definido, DAO_WCHAR) e o tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md) no conjunto de registros.  n

### <a name="example"></a>Exemplo

Este exemplo mostra várias chamadas para `DFX_Text` . Observe também as duas chamadas para [CDaoFieldExchange:: SetFieldType](cdaofieldexchange-class.md#setfieldtype). Você deve gravar a primeira chamada para `SetFieldType` e sua chamada **DFX** . A segunda chamada e suas chamadas **DFX** associadas são normalmente gravadas pelo assistente de código que gerou a classe.

```cpp
void CCustSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
   pFX->SetFieldType(CDaoFieldExchange::param);
   DFX_Text(pFX, _T("Param"), m_strParam);
   pFX->SetFieldType(CDaoFieldExchange::outputColumn);
   DFX_Short(pFX, _T("EmployeeID"), m_EmployeeID);
   DFX_Text(pFX, _T("LastName"), m_LastName);
   DFX_Short(pFX, _T("Age"), m_Age);
   DFX_DateTime(pFX, _T("hire_date"), m_hire_date);
   DFX_DateTime(pFX, _T("termination_date"), m_termination_date);

   CDaoRecordset::DoFieldExchange(pFX);
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[CRecordset::D oFieldExchange](crecordset-class.md#dofieldexchange)<br/>
[CRecordset::D oBulkFieldExchange](crecordset-class.md#dobulkfieldexchange)<br/>
[CDaoRecordset::D oFieldExchange](cdaorecordset-class.md#dofieldexchange)
