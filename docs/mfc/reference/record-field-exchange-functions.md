---
title: "Registrar funções de troca de campo | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), record field exchange (DFX)
- ODBC, bulk RFX data exchange functions
- RFX (record field exchange), ODBC classes
- DFX (DAO record field exchange), data exchange functions
- DFX functions
- bulk RFX functions
- DFX (DAO record field exchange)
- RFX (record field exchange), DAO classes
- ODBC, RFX
- RFX (record field exchange), data exchange functions
- RFX (record field exchange)
ms.assetid: 6e4c5c1c-acb7-4c18-bf51-bf7959a696cd
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 87b658cab22ad1aa5db17a00d1d3817e55ff4fc7
ms.lasthandoff: 02/25/2017

---
# <a name="record-field-exchange-functions"></a>Registrar funções de troca de campos
Este tópico lista a troca de campos do registro (RFX em massa RFX e DFX) funções usadas para automatizar a transferência de dados entre um objeto recordset e sua fonte de dados e executar outras operações nos dados.  
  
 Se você estiver usando as classes baseadas em ODBC e implementou busca de linhas em massa, você deve substituir manualmente o `DoBulkFieldExchange` função de membro `CRecordset` chamando as funções RFX em massa para cada membro de dados correspondente a uma coluna de fonte de dados.  
  
 Se você não implementou busca de linhas em massa nas classes com base em ODBC, ou se você estiver usando as classes baseadas em DAO, em seguida, ClassWizard substituirá o `DoFieldExchange` função de membro `CRecordset` ou `CDaoRecordset` chamando as funções RFX (para classes do ODBC) ou as funções DFX (para classes DAO) para cada membro de dados do campo de registros.  
  
 As funções de troca de campos de registro transferir dados cada vez que o framework chama `DoFieldExchange` ou `DoBulkFieldExchange`. Cada função transfere um tipo de dados específico.  
  
 Para obter mais informações sobre como essas funções são usadas, consulte os artigos [registrar troca de campos: como RFX Works (ODBC)](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Para colunas de dados que você associar dinamicamente, você também pode chamar as funções RFX ou DFX, conforme explicado nos artigos [Recordset: dinamicamente associando dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md). Além disso, você pode escrever suas próprias rotinas RFX ou DFX personalizadas, conforme explicado na Observação técnica [43](../../mfc/tn043-rfx-routines.md) (para ODBC) e nota técnica [53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) (para DAO).  
  
 Para obter um exemplo de RFX e RFX em massa funciona como aparecem no `DoFieldExchange` e `DoBulkFieldExchange` funções, consulte [RFX_Text](#rfx_text) e [RFX_Text_Bulk] #rfx_text_bulk). Funções DFX são muito semelhantes às funções RFX.  
  
### <a name="rfx-functions-odbc"></a>Funções RFX (ODBC)  
  
|||  
|-|-|  
|[RFX_Binary](#rfx_binary)|Transferências de matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|  
|[RFX_Bool](#rfx_bool)|Transferências de dados booleano.|  
|[RFX_Byte](#rfx_byte)|Transfere um único byte de dados.|  
|[RFX_Date](#rfx_date)|Transferências de hora e data de dados usando [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou **TIMESTAMP_STRUCT**.|  
|[RFX_Double](#rfx_double)|Transferências de dados flutuante de precisão dupla.|  
|[RFX_Int](#rfx_int)|Transferências de dados inteiro.|  
|[RFX_Long](#rfx_long)|Transferências de dados integer de comprimento.|  
|[RFX_LongBinary](#rfx_longbinary)|Transfere os dados de objeto binário grande (BLOB) com um objeto de [CLongBinary](clongbinary-class.md) classe.|  
|[RFX_Single](#rfx_single)|Transferências de dados de flutuação.|  
|[RFX_Text](#rfx_text)|Transferências de dados de cadeia de caracteres.|  
  
### <a name="bulk-rfx-functions-odbc"></a>Funções RFX em massa (ODBC)  
  
|||  
|-|-|  
|[RFX_Binary_Bulk](#rfx_binary_bulk)|Transferências de matrizes de bytes de dados.|  
|[RFX_Bool_Bulk](#rfx_bool_bulk)|Matrizes de dados booliano é transferido.|  
|[RFX_Byte_Bulk](#rfx_byte_bulk)|Transferências de matrizes de bytes simples.|  
|[RFX_Date_Bulk](#rfx_date_bulk)|Transfere conjuntos de dados do tipo **TIMESTAMP_STRUCT**.|  
|[RFX_Double_Bulk](#rfx_double_bulk)|Transferências de conjuntos de dados de ponto flutuantes de precisão dupla.|  
|[RFX_Int_Bulk](#rfx_int_bulk)|Transferências de matrizes de dados inteiro.|  
|[RFX_Long_Bulk](#rfx_long_bulk)|Transferências de conjuntos de dados de inteiro longo.|  
|[RFX_Single_Bulk](#rfx_single_bulk)|Transferências de conjuntos de dados de ponto flutuante.|  
|[RFX_Text_Bulk](#rfx_text_bulk)|Transfere conjuntos de dados do tipo **LPSTR**.|  
  
### <a name="dfx-functions-dao"></a>Funções DFX (DAO)  
  
|||
|-|-|  
|[DFX_Binary](#dfx_binary)|Transferências de matrizes de bytes do tipo [CByteArray](cbytearray-class.md).|  
|[DFX_Bool](#dfx_bool)|Transferências de dados booleano.|  
|[DFX_Byte](#dfx_byte)|Transfere um único byte de dados.|  
|[DFX_Currency](#dfx_currency)|Transfere dados de moeda, do tipo [COleCurrency](colecurrency-class.md).|  
|[DFX_DateTime](#dfx_datetime)|Transferências de dados de data e hora, do tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md).|  
|[DFX_Double](#dfx_double)|Transferências de dados flutuante de precisão dupla.|  
|[DFX_Long](#dfx_long)|Transferências de dados integer de comprimento.|  
|[DFX_LongBinary](#dfx_longbinary)|Transfere os dados de objeto binário grande (BLOB) com um objeto de `CLongBinary` classe. Para o DAO, é recomendável que você use [DFX_Binary](#dfx_binary) em vez disso.|  
|[DFX_Short](#dfx_short)|Transferências de dados integer de curta.|  
|[DFX_Single](#dfx_single)|Transferências de dados de flutuação.|  
|[DFX_Text](#dfx_text)|Transferências de dados de cadeia de caracteres.|  

 =============================================

## <a name="rfx_binary"></a>RFX_Binary
Transferências de matrizes de bytes entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_BINARY**, **SQL_VARBINARY**, ou **SQL_LONGVARBINARY**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Binary(  
   CFieldExchange* pFX,  
   const char* szName,  
   CByteArray& value,  
   int nMaxLength = 255);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo [CByteArray](cbytearray-class.md), é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `nMaxLength`  
 O comprimento máximo permitido da cadeia de caracteres ou matriz que está sendo transferido. O valor padrão de `nMaxLength` é 255. Os valores válidos são 1 para `INT_MAX`. O framework aloca essa quantidade de espaço para os dados. Para melhor desempenho, passe um valor grande o suficiente para acomodar o item de dados maior que você espera.  
  
### <a name="remarks"></a>Comentários  
 Os dados na fonte de dados desses tipos são mapeados para e do tipo `CByteArray` no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_bool"></a>RFX_Bool
Transfere dados booleanos entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_BIT**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Bool(  
   CFieldExchange* pFX,  
   const char* szName,  
   BOOL& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **BOOL**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_byte"></a>RFX_Byte
Transferências de simples bytes entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_TINYINT**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Byte(  
   CFieldExchange* pFX,  
   const char* szName,  
   BYTE& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **bytes**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_date"></a>RFX_Date
Transferências de `CTime` ou **TIMESTAMP_STRUCT** dados entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_DATE**, **SQL_TIME**, ou **SQL_TIMESTAMP**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
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
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado; o valor a ser transferido. As várias versões da função executar diferentes tipos de dados de valor:  
  
 A primeira versão da função pega uma referência para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto. Para uma transferência de conjunto de registros a fonte de dados, esse valor é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 A segunda versão da função pega uma referência para um **TIMESTAMP_STRUCT** estrutura. Você deve configurar essa estrutura por conta própria antes da chamada. Suporte a nenhuma troca de dados de caixa de diálogo (DDX) nem suporte do Assistente de código está disponível para esta versão. A terceira versão da função funciona da mesma forma para a primeira versão exceto que assume uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CTime` versão da função impõe a sobrecarga de algum processamento intermediário e tem uma variedade limitada. Se você encontrar qualquer um desses fatores muito limitado, use a segunda versão da função. Mas observe sua falta de Assistente de código e suporte DDX e o requisito que você definir a estrutura por conta própria.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_double"></a>RFX_Double
Transferências de **duplo flutuante** dados entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_DOUBLE**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Double(  
   CFieldExchange* pFX,  
   const char* szName,  
   double& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **double**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="RFX_Int"></a>RFX_Int
Transfere dados inteiros entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_SMALLINT**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Int(  
   CFieldExchange* pFX,  
   const char* szName,  
   int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo `int`, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="RFX_Long"></a>RFX_Long
Transfere dados de inteiro longo entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_INTEGER**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Long(  
   CFieldExchange* pFX,  
   const char* szName,  
   LONG&   
value );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **longo**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
## <a name="RFX_LongBinary"></a>RFX_LongBinary
Transfere dados de objeto binário grande (BLOB) usando a classe [CLongBinary](clongbinary-class.md) entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_LONGVARBINARY** ou **SQL_LONGVARCHAR**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_LongBinary(  
   CFieldExchange* pFX,  
   const char* szName,  
   CLongBinary& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo `CLongBinary`, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_single"></a>RFX_Single
Transferências de dados de ponto flutuante entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_REAL**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Single(  
   CFieldExchange* pFX,  
   const char* szName,  
   float& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **float**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  

## <a name="rfx_text"></a>RFX_Text
Transferências de `CString` dados entre os membros de dados de campo de um `CRecordset` objeto e colunas de um registro na fonte de dados do tipo ODBC **SQL_LONGVARCHAR**, **SQL_CHAR**, **SQL_VARCHAR**, **SQL_DECIMAL**, ou **SQL_NUMERIC**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Text(  
   CFieldExchange* pFX,  
   const char* szName,  
   CString& value,  
   int nMaxLength = 255,  
   int nColumnType = SQL_VARCHAR,  
   short nScale = 0);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe `CFieldExchange`. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo `CString`, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `nMaxLength`  
 O comprimento máximo permitido da cadeia de caracteres ou matriz que está sendo transferido. O valor padrão de `nMaxLength` é 255. Valores válidos são de 1 a `INT_MAX`). O framework aloca essa quantidade de espaço para os dados. Para melhor desempenho, passe um valor grande o suficiente para acomodar o item de dados maior que você espera.  
  
 *nColumnType*  
 Usado principalmente para parâmetros. Um inteiro que indica o tipo de dados do parâmetro. O tipo é um tipo de dados ODBC do formulário **SQL_XXX**.  
  
 `nScale`  
 Especifica a escala de valores do tipo ODBC **SQL_DECIMAL** ou **SQL_NUMERIC**. `nScale`só é útil ao definir os valores de parâmetro. Para obter mais informações, consulte o tópico "Precisão, escala, comprimento e tamanho de exibição" no Apêndice D do *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 Os dados na fonte de dados de todos esses tipos são mapeados para e de `CString` no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Este exemplo mostra várias chamadas para `RFX_Text`. Observe também as duas chamadas para `CFieldExchange::SetFieldType`. Para parâmetros, você deve escrever a chamada para `SetFieldType` e sua chamada RFX. A chamada de coluna de saída e suas chamadas RFX associadas normalmente são escritas por um Assistente de código.  
  
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
 **Cabeçalho:** afxdb. h  


## <a name="rfx_binary_Bulk"></a>RFX_Binary_Bulk
Transfere várias linhas de dados byte de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Binary_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   BYTE** prgByteVals,  
   long** prgLengths,  
   int nMaxLength);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgByteVals`  
 Um ponteiro para uma matriz de **bytes** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgByteVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
 `nMaxLength`  
 O máximo permitido de valores armazenados na matriz apontada por `prgByteVals`. Para garantir que os dados não serão truncados, passe um valor grande o suficiente para acomodar o maior item de dados esperado.  
  
### <a name="remarks"></a>Comentários  
 A coluna de origem de dados pode ter um tipo ODBC de **SQL_BINARY**, **SQL_VARBINARY**, ou **SQL_LONGVARBINARY**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **bytes**.  
  
 Se você inicializar `prgByteVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_bool_Bulk"></a>RFX_Bool_Bulk
Transfere várias linhas de dados Boolean de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Bool_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   BOOL** prgBoolVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgBoolVals`  
 Um ponteiro para uma matriz de **BOOL** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgBoolVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de fonte de dados deve ter um tipo ODBC de **SQL_BIT**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **BOOL**.  
  
 Se você inicializar `prgBoolVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_byte_Bulk"></a>RFX_Byte_Bulk
Transfere várias linhas de bytes simples de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Byte_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   BYTE** prgByteVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgByteVals`  
 Um ponteiro para uma matriz de **bytes** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgByteVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de fonte de dados deve ter um tipo ODBC de **SQL_TINYINT**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **bytes**.  
  
 Se você inicializar `prgByteVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
## <a name="rfx_date_Bulk"></a>RFX_Date_Bulk
Transferências de várias linhas de **TIMESTAMP_STRUCT** dados de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Date_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   TIMESTAMP_STRUCT** prgTSVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgTSVals`  
 Um ponteiro para uma matriz de **TIMESTAMP_STRUCT** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros. Para obter mais informações sobre o **TIMESTAMP_STRUCT** tipo de dados, consulte o tópico "Tipos de dados C" no Apêndice D do *referência do programador de ODBC SDK*.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgTSVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de origem de dados pode ter um tipo ODBC de **SQL_DATE**, **SQL_TIME**, ou **SQL_TIMESTAMP**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **TIMESTAMP_STRUCT**.  
  
 Se você inicializar `prgTSVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_double_Bulk"></a>RFX_Double_Bulk
Transfere várias linhas de dados de ponto flutuantes de precisão dupla de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Double_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   double** prgDblVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgDblVals`  
 Um ponteiro para uma matriz de **duplo** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgDblVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de fonte de dados deve ter um tipo ODBC de **SQL_DOUBLE**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **duplo**.  
  
 Se você inicializar `prgDblVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="RFX_Int_Bulk"></a>RFX_Int_Bulk
Transfere dados inteiros entre os membros de dados de campo de um `CRecordset` objeto e as colunas de um registro na fonte de dados do tipo ODBC **SQL_SMALLINT**.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Int(  
   CFieldExchange* pFX,  
   const char* szName,  
   int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CFieldExchange](cfieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações sobre as operações de um `CFieldExchange` objeto pode especificar, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo `int`, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text](#rfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="RFX_Long_Bulk"></a>RFX_Long_Bulk
Transfere várias linhas de dados de inteiro longo de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Long_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   long** prgLongVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgLongVals`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgLongVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de fonte de dados deve ter um tipo ODBC de **SQL_INTEGER**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **longo**.  
  
 Se você inicializar `prgLongVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

## <a name="rfx_single_Bulk"></a>RFX_Single_Bulk
Transfere várias linhas de dados de ponto flutuante de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Single_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   float** prgFltVals,  
   long** prgLengths);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgFltVals`  
 Um ponteiro para uma matriz de **float** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgFltVals`. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
### <a name="remarks"></a>Comentários  
 A coluna de fonte de dados deve ter um tipo ODBC de **SQL_REAL**. O conjunto de registros deve definir um membro de dados de campo do tipo ponteiro para **float**.  
  
 Se você inicializar `prgFltVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [RFX_Text_Bulk](#rfx_text_bulk).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  

## <a name="rfx_text_Bulk"></a>RFX_Text_Bulk
Transfere várias linhas de dados de caracteres de uma coluna de uma fonte de dados ODBC para uma matriz correspondente em um `CRecordset`-objeto derivado.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void RFX_Text_Bulk(  
   CFieldExchange* pFX,  
   LPCTSTR szName,  
   LPSTR* prgStrVals,  
   long** prgLengths,  
   int nMaxLength);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um [CFieldExchange](cfieldexchange-class.md) objeto. Este objeto contém informações para definir o contexto de cada chamada da função. Para obter mais informações, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 `prgStrVals`  
 Um ponteiro para uma matriz de **LPSTR** valores. Essa matriz armazenará os dados devem ser transferidos da fonte de dados para o conjunto de registros. Observe que, com a versão atual do ODBC, esses valores podem ser Unicode.  
  
 `prgLengths`  
 Um ponteiro para uma matriz de inteiros longos. Essa matriz armazenará o comprimento em bytes de cada valor na matriz apontada por `prgStrVals`. Esse comprimento exclui o caractere de terminação nula. Observe que o valor **SQL_NULL_DATA** será armazenado se o item de dados correspondente contém um valor nulo. Para obter mais detalhes, consulte a função de API ODBC **SQLBindCol** no *referência do programador de ODBC SDK*.  
  
 `nMaxLength`  
 O máximo permitido de valores armazenados na matriz apontada por `prgStrVals`, incluindo o caractere de terminação nula. Para garantir que os dados não serão truncados, passe um valor grande o suficiente para acomodar o maior item de dados esperado.  
  
### <a name="remarks"></a>Comentários  
 A coluna de origem de dados pode ter um tipo ODBC de **SQL_LONGVARCHAR**, **SQL_CHAR**, **SQL_VARCHAR**, **SQL_DECIMAL**, ou **SQL_NUMERIC**. O conjunto de registros deve definir um membro de dados do campo de tipo **LPSTR**.  
  
 Se você inicializar `prgStrVals` e `prgLengths` para **nulo**, em seguida, as matrizes que eles apontem para serão alocadas automaticamente, com tamanhos iguais ao tamanho do conjunto de linhas.  
  
> [!NOTE]
>  Troca de campos de registro em massa só transfere dados da fonte de dados para o objeto recordset. Para tornar seu recordset atualizável, você deve usar a função ODBC API **SQLSetPos**.  
  
 Para obter mais informações, consulte os artigos [conjunto de registros: recuperando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md) e [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).  
  
### <a name="example"></a>Exemplo  
 Você deve escrever manualmente chamadas em seu `DoBulkFieldExchange` substituir. Este exemplo mostra uma chamada para `RFX_Text_Bulk`, bem como uma chamada para `RFX_Long_Bulk`, transferência de dados. Essas chamadas são precedidas por uma chamada a [CFieldExchange::SetFieldType](CFieldExchange::SetFieldType.md). Observe que para os parâmetros, você deve chamar as funções RFX em vez das funções RFX em massa.  
  
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
 **Cabeçalho:** afxdb. h  

## <a name="dfx_binary"></a>DFX_Binary
Transferências de matrizes de bytes entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Binary(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   CByteArray& value,  
   int nPreAllocSize = AFX_DAO_BINARY_DEFAULT_SIZE,  
   DWORD dwBindOptions = 0);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo [CByteArray](cbytearray-class.md), é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `nPreAllocSize`  
 O framework pré-alocar essa quantidade de memória. Se seus dados forem maiores, a estrutura será alocada mais espaço conforme necessário. Para obter melhor desempenho, defina esse tamanho para um valor grande o suficiente para evitar realocações. O tamanho padrão é definido no AFXDAO. Arquivo H como **AFX_DAO_BINARY_DEFAULT_SIZE**.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_DISABLE_FIELD_CACHE`, não usar buffer duplo, e você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) por conta própria. O outro valor possível, `AFX_DAO_ENABLE_FIELD_CACHE`, buffer duplo usa e você não precisa fazer o trabalho extra para marcar campos sujo ou Null. Por motivos de memória e desempenho, evite esse valor, a menos que os dados binários são relativamente pequenos.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer para todos os campos por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_BYTES** em DAO e digite [CByteArray](cbytearray-class.md) no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  

## <a name="dfx_bool"></a>DFX_Bool
Transfere dados booleanos entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Bool(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   BOOL& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **BOOL**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_BOOL** em DAO e digite **BOOL** no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_byte"></a>DFX_Byte
Transferências de simples bytes entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Byte(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   BYTE& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **bytes**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_BYTES** em DAO e digite **bytes** no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_currency"></a>DFX_Currency
Transfere dados de moeda entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Currency(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   COleCurrency& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros a fonte de dados, esse valor é obtido do membro de dados especificado do tipo [COleCurrency](colecurrency-class.md). Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_CURRENCY** em DAO e digite [COleCurrency](colecurrency-class.md) no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_datetime"></a>DFX_DateTime
Transfere os dados de data e hora entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_DateTime(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   COleDateTime& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. A função pega uma referência para um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto. Para uma transferência de conjunto de registros a fonte de dados, esse valor é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_DATE** em DAO e digite [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) no conjunto de registros.  
  
> [!NOTE]
>  `COleDateTime`substitui [CTime](../../atl-mfc-shared/reference/ctime-class.md) e **TIMESTAMP_STRUCT** para essa finalidade nas classes DAO. `CTime`e **TIMESTAMP_STRUCT** ainda é usado para as classes de acesso de dados com base em ODBC.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_double"></a>DFX_Double
Transferências de **duplo flutuante** dados entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Double(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   double& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **double**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_R8** em DAO e digite **duplo flutuante** no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_long"></a>DFX_Long
Transfere dados de inteiro longo entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Long(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   long& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **longo**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_I4** em DAO e digite **longo** no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  

## <a name="dfx_longbinary"></a>DFX_LongBinary
**Importante** é recomendável que você use [DFX_Binary](#dfx_binary) em vez dessa função.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_LongBinary(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   CLongBinary& value,  
   DWORD dwPreAllocSize = AFX_DAO_LONGBINARY_DEFAULT_SIZE,  
   DWORD dwBindOptions = 0);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo [CLongBinary](clongbinary-class.md), é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 *dwPreAllocSize*  
 O framework pré-alocar essa quantidade de memória. Se seus dados forem maiores, a estrutura será alocada mais espaço conforme necessário. Para obter melhor desempenho, defina esse tamanho para um valor grande o suficiente para evitar realocações.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, **AFX_DISABLE_FIELD_CACHE**, não usa o buffer duplo. O outro valor possível é `AFX_DAO_ENABLE_FIELD_CACHE`. Buffer duplo usa e você não precisa fazer o trabalho extra para marcar campos sujo ou Null. Por motivos de memória e desempenho, evite esse valor, a menos que os dados binários são relativamente pequenos.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 `DFX_LongBinary`é fornecido para compatibilidade com as classes MFC ODBC. O `DFX_LongBinary` função transfere dados binários-BLOB (objeto grande) usando a classe `CLongBinary` entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados. Os dados são mapeados entre o tipo **DAO_BYTES** em DAO e digite [CLongBinary](clongbinary-class.md) no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_short"></a>DFX_Short
Curto de transferências de dados inteiros entre os membros de dados de campo um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Short(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   short& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **curto**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_I2** em DAO e digite **curto** no conjunto de registros.  
  
> [!NOTE]
>  `DFX_Short`é equivalente a [RFX_Int](#rfx_int) para as classes baseadas em ODBC.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  

## <a name="dfx_single"></a>DFX_Single
Transferências de dados de ponto flutuante entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e as colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Single(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   float& value,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo **float**, é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_R4** em DAO e digite **float** no conjunto de registros.  
  
### <a name="example"></a>Exemplo  
 Consulte [DFX_Text](#dfx_text).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

## <a name="dfx_text"></a>DFX_Text
Transferências de `CString` dados entre os membros de dados de campo de um [CDaoRecordset](cdaorecordset-class.md) objeto e colunas de um registro na fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```
void AFXAPI DFX_Text(  
   CDaoFieldExchange* pFX,  
   LPCTSTR szName,  
   CString& value,  
   int nPreAllocSize = AFX_DAO_TEXT_DEFAULT_SIZE,  
   DWORD dwBindOptions = AFX_DAO_ENABLE_FIELD_CACHE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Um ponteiro para um objeto da classe [CDaoFieldExchange](cdaofieldexchange-class.md). Este objeto contém informações para definir o contexto de cada chamada da função.  
  
 `szName`  
 O nome de uma coluna de dados.  
  
 *value*  
 O valor armazenado no membro de dados indicado, o valor a ser transferido. Para uma transferência de conjunto de registros à fonte de dados, o valor do tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md), é obtido do membro de dados especificado. Para uma transferência de fonte de dados para o conjunto de registros, o valor é armazenado no membro de dados especificado.  
  
 `nPreAllocSize`  
 O framework pré-alocar essa quantidade de memória. Se seus dados forem maiores, a estrutura será alocada mais espaço conforme necessário. Para obter melhor desempenho, defina esse tamanho para um valor grande o suficiente para evitar realocações.  
  
 `dwBindOptions`  
 Uma opção que permite que você tire proveito do mecanismo de armazenamento em buffer duplo do MFC para detectar os campos de conjunto de registros que foram alterados. O padrão, `AFX_DAO_ENABLE_FIELD_CACHE`, usa o buffer duplo. O outro valor possível é `AFX_DAO_DISABLE_FIELD_CACHE`. Se você especificar esse valor, o MFC não faz nenhuma verificação neste campo. Você deve chamar [SetFieldDirty](cdaorecordset-class.md#setfielddirty) e [SetFieldNull](cdaorecordset-class.md#setfieldnull) por conta própria.  
  
> [!NOTE]
>  Você pode controlar se os dados estão duplos em buffer por padrão definindo [CDaoRecordset::m_bCheckCacheForDirtyFields](cdaorecordset-class.md#m_bcheckcachefordirtyfields).  
  
### <a name="remarks"></a>Comentários  
 Os dados são mapeados entre o tipo **DAO_CHAR** em DAO (ou, se o símbolo **Unicode** for definida, **DAO_WCHAR**) e digite [CString](../../atl-mfc-shared/reference/cstringt-class.md) no conjunto de registros.  n
  
### <a name="example"></a>Exemplo  
 Este exemplo mostra várias chamadas para `DFX_Text`. Observe também as duas chamadas para [CDaoFieldExchange::SetFieldType](cdaofieldexchange-class.md#setfieldtype). Você deve escrever a primeira chamada para `SetFieldType` e sua **DFX** chamar. A segunda chamada e seus associados **DFX** chamadas normalmente são gravadas pelo Assistente de código que gerou a classe.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [CRecordset::DoFieldExchange](crecordset-class.md#dofieldexchange)   
 [CRecordset::DoBulkFieldExchange](crecordset-class.md#dobulkfieldexchange)   
 [CDaoRecordset::DoFieldExchange](cdaorecordset-class.md#dofieldexchange)


