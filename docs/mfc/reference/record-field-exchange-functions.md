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
ms.openlocfilehash: bfd3ba64a33547b8a27e0f3bc896f39c94486464
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372987"
---
# <a name="record-field-exchange-functions"></a>Registrar funções de troca de campos

Este tópico lista as funções De Campo de Registro (RFX, Bulk RFX e DFX) usadas para automatizar a transferência de dados entre um objeto de conjunto de registros e sua fonte de dados e para realizar outras operações nos dados.

Se você estiver usando as classes baseadas no ODBC e tiver implementado `DoBulkFieldExchange` a busca `CRecordset` em linha em massa, você deve substituir manualmente a função de membro, chamando as funções De RFX em massa para cada membro de dados correspondente a uma coluna de origem de dados.

Se você não tiver implementado a busca de linhas em massa nas classes baseadas em ODBC ou se `DoFieldExchange` estiver usando `CRecordset` `CDaoRecordset` as classes baseadas em DAO (obsoletas), o ClassWizard substituirá a função de membro ou chamando as funções RFX (para classes ODBC) ou as funções DFX (para classes DAO) para cada membro de dados de campo em seu conjunto de registros.

As funções de troca de campo `DoFieldExchange` de `DoBulkFieldExchange`registro transferem dados cada vez que o framework chama ou . Cada função transfere um tipo de dados específico.

Para obter mais informações sobre como essas funções são usadas, consulte os artigos [Record Field Exchange: How RFX Works (ODBC)](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Para colunas de dados que você vincula dinamicamente, você também pode chamar as funções RFX ou DFX você mesmo, conforme explicado nos artigos [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md). Além disso, você pode escrever suas próprias rotinas personalizadas de RFX ou DFX, conforme explicado na Nota Técnica [43](../../mfc/tn043-rfx-routines.md) (para ODBC) e Nota Técnica [53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) (para DAO).

Para um exemplo de funções RFX e Bulk `DoFieldExchange` `DoBulkFieldExchange` RFX à medida que aparecem nas funções e funções, consulte [RFX_Text](#rfx_text) e [RFX_Text_Bulk]#rfx_text_bulk). As funções DFX são muito semelhantes às funções RFX.

### <a name="rfx-functions-odbc"></a>Funções RFX (ODBC)

|||
|-|-|
|[RFX_Binary](#rfx_binary)|Transfere matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|
|[RFX_Bool](#rfx_bool)|Transfere dados booleanos.|
|[RFX_Byte](#rfx_byte)|Transfere um único byte de dados.|
|[RFX_Date](#rfx_date)|Transfere dados de data e hora usando [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou TIMESTAMP_STRUCT.|
|[RFX_Double](#rfx_double)|Transfere dados flutuantes de dupla precisão.|
|[RFX_Int](#rfx_int)|Transfere dados inteiros.|
|[RFX_Long](#rfx_long)|Transfere dados inteiros longos.|
|[RFX_LongBinary](#rfx_longbinary)|Transfere dados binários de objeto grande (BLOB) com um objeto da classe [CLongBinary.](clongbinary-class.md)|
|[RFX_Single](#rfx_single)|Transfere dados flutuantes.|
|[RFX_Text](#rfx_text)|Transfere dados de seqüência.|

### <a name="bulk-rfx-functions-odbc"></a>Funções RFX em massa (ODBC)

|||
|-|-|
|[RFX_Binary_Bulk](#rfx_binary_bulk)|Transfere matrizes de dados de byte.|
|[RFX_Bool_Bulk](#rfx_bool_bulk)|Transfere matrizes de dados booleanos.|
|[RFX_Byte_Bulk](#rfx_byte_bulk)|Transfere matrizes de bytes únicos.|
|[RFX_Date_Bulk](#rfx_date_bulk)|Transfere matrizes de dados de TIMESTAMP_STRUCT tipo.|
|[RFX_Double_Bulk](#rfx_double_bulk)|Transfere matrizes de dados de ponto flutuante de dupla precisão.|
|[RFX_Int_Bulk](#rfx_int_bulk)|Transfere matrizes de dados inteiros.|
|[RFX_Long_Bulk](#rfx_long_bulk)|Transfere matrizes de dados inteiros longos.|
|[RFX_Single_Bulk](#rfx_single_bulk)|Transfere matrizes de dados de ponto flutuante.|
|[RFX_Text_Bulk](#rfx_text_bulk)|Transfere matrizes de dados do tipo LPSTR.|

### <a name="dfx-functions-dao"></a>Funções DFX (DAO)

|||
|-|-|
|[DFX_Binary](#dfx_binary)|Transfere matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|
|[DFX_Bool](#dfx_bool)|Transfere dados booleanos.|
|[DFX_Byte](#dfx_byte)|Transfere um único byte de dados.|
|[DFX_Currency](#dfx_currency)|Transfere dados de moeda, do tipo [COleCurrency](colecurrency-class.md).|
|[DFX_DateTime](#dfx_datetime)|Transfere dados de hora e data, do tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md).|
|[DFX_Double](#dfx_double)|Transfere dados flutuantes de dupla precisão.|
|[DFX_Long](#dfx_long)|Transfere dados inteiros longos.|
|[DFX_LongBinary](#dfx_longbinary)|Transfere dados binários de objeto grande `CLongBinary` (BLOB) com um objeto da classe. Para DAO, recomenda-se que você use [DFX_Binary](#dfx_binary) em vez disso.|
|[DFX_Short](#dfx_short)|Transfere dados inteiros curtos.|
|[DFX_Single](#dfx_single)|Transfere dados flutuantes.|
|[DFX_Text](#dfx_text)|Transfere dados de seqüência.|

=============================================

## <a name="rfx_binary"></a><a name="rfx_binary"></a>Rfx_binary

Transfere matrizes de bytes entre `CRecordset` os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_BINARY, SQL_VARBINARY ou SQL_LONGVARBINARY.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Binary(
   CFieldExchange* pFX,
   const char* szName,
   CByteArray& value,
   int nMaxLength = 255);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CByteArray,](cbytearray-class.md)é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*Nmaxlength*<br/>
O comprimento máximo permitido da seqüência ou matriz sendo transferido. O valor padrão do *nMaxLength* é 255. Os valores legais são de 1 a INT_MAX. A estrutura aloca essa quantidade de espaço para os dados. Para obter o melhor desempenho, passe um valor grande o suficiente para acomodar o maior item de dados que você espera.

### <a name="remarks"></a>Comentários

Os dados na fonte de dados desses tipos `CByteArray` são mapeados de e para o tipo no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_bool"></a><a name="rfx_bool"></a>RFX_Bool

Transfere dados booleanos entre `CRecordset` os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_BIT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Bool(
   CFieldExchange* pFX,
   const char* szName,
   BOOL& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BOOL, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_byte"></a><a name="rfx_byte"></a>RFX_Byte

Transfere bytes únicos entre os `CRecordset` membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_TINYINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Byte(
   CFieldExchange* pFX,
   const char* szName,
   BYTE& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BYTE, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_date"></a><a name="rfx_date"></a>Rfx_date

Transfere `CTime` ou TIMESTAMP_STRUCT dados entre `CRecordset` os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_DATE, SQL_TIME ou SQL_TIMESTAMP.

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

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado; o valor a ser transferido. As várias versões da função levam diferentes tipos de dados por valor:

A primeira versão da função faz uma referência a um objeto [CTime.](../../atl-mfc-shared/reference/ctime-class.md) Para uma transferência do conjunto de registros para a fonte de dados, esse valor é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

A segunda versão da função faz `TIMESTAMP_STRUCT` referência a uma estrutura. Você deve montar esta estrutura você mesmo antes da chamada. Nem o suporte ao DDX (Troca de dados de diálogo) nem o suporte ao assistente de código estão disponíveis para esta versão. A terceira versão da função funciona de forma semelhante à primeira versão, exceto que ela leva uma referência a um objeto [COleDateTime.](../../atl-mfc-shared/reference/coledatetime-class.md)

### <a name="remarks"></a>Comentários

A `CTime` versão da função impõe a sobrecarga de algum processamento intermediário e tem um alcance um pouco limitado. Se você encontrar qualquer um desses fatores muito limitador, use a segunda versão da função. Mas note sua falta de assistente de código e suporte ao DDX e a exigência de que você mesmo configure a estrutura.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_double"></a><a name="rfx_double"></a>RFX_Double

Transfere dados **de flutuação** dupla `CRecordset` entre os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_DOUBLE.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Double(
   CFieldExchange* pFX,
   const char* szName,
   double& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **duplo,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_int"></a><a name="rfx_int"></a>Rfx_int

Transfere dados inteiros entre os `CRecordset` membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_SMALLINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Int(
   CFieldExchange* pFX,
   const char* szName,
   int& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, de tipo **int,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_long"></a><a name="rfx_long"></a>RFX_Long

Transfere dados inteiros longos entre `CRecordset` os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_INTEGER.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Long(
   CFieldExchange* pFX,
   const char* szName,
   LONG&
value );
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, de **tipo longo,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_longbinary"></a><a name="rfx_longbinary"></a>RFX_LongBinary

Transfere dados binários de objeto grande (BLOB) usando a `CRecordset` classe [CLongBinary](clongbinary-class.md) entre os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_LONGVARBINARY ou SQL_LONGVARCHAR.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_LongBinary(
   CFieldExchange* pFX,
   const char* szName,
   CLongBinary& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para `CLongBinary`a fonte de dados, o valor, do tipo, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_single"></a><a name="rfx_single"></a>RFX_Single

Transfere dados de ponto flutuante entre `CRecordset` os membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_REAL.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Single(
   CFieldExchange* pFX,
   const char* szName,
   float& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **float,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_text"></a><a name="rfx_text"></a>Rfx_text

Transfere `CString` dados entre os `CRecordset` membros de dados de campo de um objeto e colunas de um registro na fonte de dados do tipo ODBC SQL_LONGVARCHAR, SQL_CHAR, SQL_VARCHAR, SQL_DECIMAL ou SQL_NUMERIC.

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

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um `CFieldExchange`objeto de classe. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para `CString`a fonte de dados, o valor, do tipo, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*Nmaxlength*<br/>
O comprimento máximo permitido da seqüência ou matriz sendo transferido. O valor padrão do *nMaxLength* é 255. Os valores legais são de 1 a INT_MAX). A estrutura aloca essa quantidade de espaço para os dados. Para obter o melhor desempenho, passe um valor grande o suficiente para acomodar o maior item de dados que você espera.

*nColumnType*<br/>
Usado principalmente para parâmetros. Um inteiro indicando o tipo de dados do parâmetro. O tipo é um tipo de dados ODBC do formulário **SQL_XXX**.

*nEscala*<br/>
Especifica a escala para valores do tipo ODBC SQL_DECIMAL ou SQL_NUMERIC. *nScale* só é útil ao definir valores de parâmetros. Para obter mais informações, consulte o tópico "Precisão, Escala, Comprimento e Tamanho de Exibição" no apêndice D da *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

Os dados na fonte de dados de todos `CString` esses tipos são mapeados de e para dentro do conjunto de registros.

### <a name="example"></a>Exemplo

Este exemplo mostra `RFX_Text`várias chamadas para . Observe também as `CFieldExchange::SetFieldType`duas chamadas para . Para parâmetros, você `SetFieldType` deve escrever a chamada e sua chamada RFX. A chamada da coluna de saída e suas chamadas RFX associadas são normalmente escritas por um assistente de código.

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

**Cabeçalho:** afxdb.h

## <a name="rfx_binary_bulk"></a><a name="rfx_binary_bulk"></a>RFX_Binary_Bulk

Transfere várias linhas de dados de byte de uma coluna de `CRecordset`uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Binary_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BYTE** prgByteVals,
   long** prgLengths,
   int nMaxLength);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prgbytevals*<br/>
Um ponteiro para uma matriz de valores BYTE. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgByteVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

*Nmaxlength*<br/>
O comprimento máximo permitido dos valores armazenados na matriz apontado por *prgByteVals*. Para garantir que os dados não sejam truncados, passe um valor grande o suficiente para acomodar o maior item de dados que você espera.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo de SQL_BINARY, SQL_VARBINARY ou SQL_LONGVARBINARY da ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para BYTE.

Se você inicializar *prgByteVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, você `SQLSetPos`deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_bool_bulk"></a><a name="rfx_bool_bulk"></a>RFX_Bool_Bulk

Transfere várias linhas de dados booleanos de uma coluna de `CRecordset`uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Bool_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BOOL** prgBoolVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prgboolvals*<br/>
Um ponteiro para uma matriz de valores BOOL. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgBoolVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados deve ter um tipo de SQL_BIT ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para BOOL.

Se você inicializar *prgBoolVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_byte_bulk"></a><a name="rfx_byte_bulk"></a>RFX_Byte_Bulk

Transfere várias linhas de bytes únicos de uma coluna de uma `CRecordset`fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Byte_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   BYTE** prgByteVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prgbytevals*<br/>
Um ponteiro para uma matriz de valores BYTE. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgByteVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna de origem de dados deve ter um tipo de SQL_TINYINT ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para BYTE.

Se você inicializar *prgByteVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_date_bulk"></a><a name="rfx_date_bulk"></a>RFX_Date_Bulk

Transfere várias linhas de dados TIMESTAMP_STRUCT de uma coluna de uma `CRecordset`fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Date_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   TIMESTAMP_STRUCT** prgTSVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*prgTSVals*<br/>
Um ponteiro para uma matriz de valores TIMESTAMP_STRUCT. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros. Para obter mais informações sobre o TIMESTAMP_STRUCT tipo de dados, consulte o tópico "C Data Types" no apêndice D da *referência do programador ODBC SDK*.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgTSVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo de SQL_DATE, SQL_TIME ou SQL_TIMESTAMP da ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para TIMESTAMP_STRUCT.

Se você inicializar *prgTSVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_double_bulk"></a><a name="rfx_double_bulk"></a>RFX_Double_Bulk

Transfere várias linhas de dados de ponto flutuante de dupla precisão de uma coluna `CRecordset`de uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Double_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   double** prgDblVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*prgDblVals*<br/>
Um ponteiro para uma matriz de valores **duplos.** Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgDblVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados deve ter um tipo de SQL_DOUBLE ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para **dobrar**.

Se você inicializar *prgDblVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_int_bulk"></a><a name="rfx_int_bulk"></a>RFX_Int_Bulk

Transfere dados inteiros entre os `CRecordset` membros de dados de campo de um objeto e as colunas de um registro na fonte de dados do tipo ODBC SQL_SMALLINT.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Int(
   CFieldExchange* pFX,
   const char* szName,
   int& value);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações `CFieldExchange` sobre as operações que um objeto pode especificar, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, de tipo **int,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

### <a name="example"></a>Exemplo

Veja [RFX_Text](#rfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_long_bulk"></a><a name="rfx_long_bulk"></a>RFX_Long_Bulk

Transfere várias linhas de dados inteiros longos de uma coluna de `CRecordset`uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Long_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   long** prgLongVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prglongvals*<br/>
Um ponteiro para uma matriz de inteiros longos. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgLongVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados deve ter um tipo de SQL_INTEGER ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo por **muito tempo**.

Se você inicializar *prgLongVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_single_bulk"></a><a name="rfx_single_bulk"></a>RFX_Single_Bulk

Transfere várias linhas de dados de ponto flutuante de uma coluna de `CRecordset`uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Single_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   float** prgFltVals,
   long** prgLengths);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prgfltvals*<br/>
Um ponteiro para uma matriz de valores **flutuantes.** Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgFltVals*. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

### <a name="remarks"></a>Comentários

A coluna fonte de dados deve ter um tipo de SQL_REAL ODBC. O conjunto de registros deve definir um membro de dados de campo do ponteiro de tipo para **flutuar**.

Se você inicializar *prgFltVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Veja [RFX_Text_Bulk](#rfx_text_bulk).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="rfx_text_bulk"></a><a name="rfx_text_bulk"></a>RFX_Text_Bulk

Transfere várias linhas de dados de caracteres de uma coluna `CRecordset`de uma fonte de dados ODBC para uma matriz correspondente em um objeto derivado.

### <a name="syntax"></a>Sintaxe

```cpp
void RFX_Text_Bulk(
   CFieldExchange* pFX,
   LPCTSTR szName,
   LPSTR* prgStrVals,
   long** prgLengths,
   int nMaxLength);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](cfieldexchange-class.md) Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

*Szname*<br/>
O nome de uma coluna de dados.

*Prgstrvals*<br/>
Um ponteiro para uma matriz de valores LPSTR. Este array armazenará os dados a serem transferidos da fonte de dados para o conjunto de registros. Observe que, com a versão atual do ODBC, esses valores não podem ser Unicode.

*Prglengths*<br/>
Um ponteiro para uma matriz de inteiros longos. Esta matriz armazenará o comprimento em bytes de cada valor na matriz apontada por *prgStrVals*. Este comprimento exclui o caractere de rescisão nula. Observe que o valor SQL_NULL_DATA será armazenado se o item de dados correspondente contiver um valor Nulo. Para obter mais detalhes, consulte `SQLBindCol` a função API ODBC na *referência do programador ODBC SDK*.

*Nmaxlength*<br/>
O comprimento máximo permitido dos valores armazenados na matriz apontado por *prgStrVals*, incluindo o caractere de rescisão nula. Para garantir que os dados não sejam truncados, passe um valor grande o suficiente para acomodar o maior item de dados que você espera.

### <a name="remarks"></a>Comentários

A coluna fonte de dados pode ter um tipo de SQL_LONGVARCHAR, SQL_CHAR, SQL_VARCHAR, SQL_DECIMAL ou SQL_NUMERIC da ODBC. O conjunto de registros deve definir um membro de dados de campo do tipo LPSTR.

Se você inicializar *prgStrVals* e *prgLengths* para NULL, então as matrizes que eles apontam serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.

> [!NOTE]
> A troca de campo de registro em massa apenas transfere dados da fonte de dados para o objeto recordset. Para tornar o seu conjunto de registros atualizável, `SQLSetPos`você deve usar a função API ODBC .

Para obter mais informações, consulte os artigos [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

### <a name="example"></a>Exemplo

Você deve escrever manualmente `DoBulkFieldExchange` chamadas em seu dispositivo. Este exemplo mostra `RFX_Text_Bulk`uma chamada para, `RFX_Long_Bulk`bem como uma chamada para , para transferência de dados. Essas chamadas são precedidas por uma chamada para [CFieldExchange::SetFieldType](cfieldexchange-class.md#setfieldtype). Observe que, para parâmetros, você deve chamar as funções RFX em vez das funções Bulk RFX.

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

**Cabeçalho:** afxdb.h

## <a name="dfx_binary"></a><a name="dfx_binary"></a>Dfx_binary

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

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CByteArray,](cbytearray-class.md)é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nPreAllocSize*<br/>
A estrutura pré-aloca essa quantidade de memória. Se seus dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para um melhor desempenho, defina este tamanho para um valor grande o suficiente para evitar realocação. O tamanho padrão é definido no AFXDAO. Arquivo H como AFX_DAO_BINARY_DEFAULT_SIZE.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_DISABLE_FIELD_CACHE, não usa bufferduplo, e você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) você mesmo. O outro valor possível, AFX_DAO_ENABLE_FIELD_CACHE, usa buffering duplo, e você não precisa fazer trabalho extra para marcar campos sujos ou Nulos. Por razões de desempenho e memória, evite esse valor a menos que seus dados binários sejam relativamente pequenos.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos para todos os campos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo [CByteArray](cbytearray-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_bool"></a><a name="dfx_bool"></a>DFX_Bool

Transfere dados booleanos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Bool(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   BOOL& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BOOL, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BOOL no DAO e o tipo BOOL no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_byte"></a><a name="dfx_byte"></a>DFX_Byte

Transfere bytes únicos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Byte(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   BYTE& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo BYTE, é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo BYTE no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_currency"></a><a name="dfx_currency"></a>DFX_Currency

Transfere dados de moeda entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Currency(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   COleCurrency& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, esse valor é retirado do membro de dados especificado, do tipo [COleCurrency](colecurrency-class.md). Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_CURRENCY no DAO e o tipo [COleCurrency](colecurrency-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_datetime"></a><a name="dfx_datetime"></a>DFX_DateTime

Transfere dados de data e hora entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_DateTime(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   COleDateTime& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. A função faz uma referência a um objeto [COleDateTime.](../../atl-mfc-shared/reference/coledatetime-class.md) Para uma transferência do conjunto de registros para a fonte de dados, esse valor é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_DATE no DAO e o tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) no conjunto de registros.

> [!NOTE]
> `COleDateTime`substitui [CTime](../../atl-mfc-shared/reference/ctime-class.md) e TIMESTAMP_STRUCT para este fim nas classes DAO. `CTime`e TIMESTAMP_STRUCT ainda são usados para as classes de acesso a dados baseadas em ODBC.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_double"></a><a name="dfx_double"></a>DFX_Double

Transfere dados **de flutuação dupla** entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Double(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   double& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **duplo,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_R8 no DAO e o tipo **de flutuação dupla** no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_long"></a><a name="dfx_long"></a>DFX_Long

Transfere dados inteiros longos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Long(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   long& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, de **tipo longo,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_I4 no DAO e o **tipo longo** no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_longbinary"></a><a name="dfx_longbinary"></a>DFX_LongBinary

**Importante** Recomenda-se que você use [DFX_Binary](#dfx_binary) em vez desta função.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_LongBinary(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   CLongBinary& value,
   DWORD dwPreAllocSize = AFX_DAO_LONGBINARY_DEFAULT_SIZE,
   DWORD dwBindOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CLongBinary,](clongbinary-class.md)é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwPreAllocSize*<br/>
A estrutura pré-aloca essa quantidade de memória. Se seus dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para um melhor desempenho, defina este tamanho para um valor grande o suficiente para evitar realocação.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DISABLE_FIELD_CACHE, não usa bufferduplo. O outro valor possível é AFX_DAO_ENABLE_FIELD_CACHE. Usa buffering duplo, e você não precisa fazer um trabalho extra para marcar campos sujos ou nulos. Por razões de desempenho e memória, evite esse valor a menos que seus dados binários sejam relativamente pequenos.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

`DFX_LongBinary`é fornecido para compatibilidade com as classes MFC ODBC. A `DFX_LongBinary` função transfere dados binários de `CLongBinary` objeto grande (BLOB) usando classe entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados. Os dados são mapeados entre o tipo DAO_BYTES no DAO e o tipo [CLongBinary](clongbinary-class.md) no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_short"></a><a name="dfx_short"></a>DFX_Short

Transfere dados inteiros curtos entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Short(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   short& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **curto,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_I2 no DAO e o tipo **curto** no conjunto de registros.

> [!NOTE]
> `DFX_Short`equivale a [RFX_Int](#rfx_int) para as classes baseadas em ODBC.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_single"></a><a name="dfx_single"></a>DFX_Single

Transfere dados de ponto flutuante entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e as colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Single(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   float& value,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo **float,** é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve `SetFieldDirty` `SetFieldNull` ligar e a si mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_R4 no DAO e o tipo **flutuar** no conjunto de registros.

### <a name="example"></a>Exemplo

Veja [DFX_Text](#dfx_text).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="dfx_text"></a><a name="dfx_text"></a>Dfx_text

Transfere `CString` dados entre os membros de dados de campo de um objeto [CDaoRecordset](cdaorecordset-class.md) e colunas de um registro na fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI DFX_Text(
   CDaoFieldExchange* pFX,
   LPCTSTR szName,
   CString& value,
   int nPreAllocSize = AFX_DAO_TEXT_DEFAULT_SIZE,
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.

*Szname*<br/>
O nome de uma coluna de dados.

*value*<br/>
O valor armazenado no membro de dados indicado — o valor a ser transferido. Para uma transferência do conjunto de registros para a fonte de dados, o valor, do tipo [CString,](../../atl-mfc-shared/reference/cstringt-class.md)é retirado do membro de dados especificado. Para uma transferência da fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.

*nPreAllocSize*<br/>
A estrutura pré-aloca essa quantidade de memória. Se seus dados forem maiores, a estrutura alocará mais espaço conforme necessário. Para um melhor desempenho, defina este tamanho para um valor grande o suficiente para evitar realocação.

*dwBindOptions*<br/>
Uma opção que permite que você aproveite o mecanismo de buffer duplo do MFC para detectar campos de conjunto de registros que foram alterados. O padrão, AFX_DAO_ENABLE_FIELD_CACHE, usa bufferduplo. O outro valor possível é AFX_DAO_DISABLE_FIELD_CACHE. Se você especificar este valor, o MFC não verificará este campo. Você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) você mesmo.

> [!NOTE]
> Você pode controlar se os dados são duplamente protegidos por padrão, definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).

### <a name="remarks"></a>Comentários

Os dados são mapeados entre o tipo DAO_CHAR no DAO (ou, se o símbolo _UNICODE for definido, DAO_WCHAR) e tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md) no conjunto de registros.  n

### <a name="example"></a>Exemplo

Este exemplo mostra `DFX_Text`várias chamadas para . Observe também as duas chamadas para [CDaoFieldExchange::SetFieldType](cdaofieldexchange-class.md#setfieldtype). Você deve escrever a `SetFieldType` primeira chamada e sua chamada **DFX.** A segunda chamada e suas chamadas **DFX** associadas são normalmente escritas pelo assistente de código que gerou a classe.

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

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[CRecordset::DoFieldExchange](crecordset-class.md#dofieldexchange)<br/>
[CRecordset::DoBulkFieldExchange](crecordset-class.md#dobulkfieldexchange)<br/>
[CDaoRecordset::DoFieldExchange](cdaorecordset-class.md#dofieldexchange)
