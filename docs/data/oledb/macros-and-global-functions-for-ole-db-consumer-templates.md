---
title: Macros e funções globais para modelos de consumidor de banco de dados OLE
ms.date: 02/11/2019
f1_keywords:
- ATL.AtlTraceErrorRecords
- ATL::AtlTraceErrorRecords
- AtlTraceErrorRecords
- BEGIN_ACCESSOR
- BEGIN_ACCESSOR_MAP
- END_ACCESSOR
- END_ACCESSOR_MAP
- BEGIN_COLUMN_MAP
- BLOB_ENTRY
- BLOB_ENTRY_LENGTH
- BLOB_ENTRY_LENGTH_STATUS
- BLOB_ENTRY_STATUS
- BLOB_NAME
- BLOB_NAME_LENGTH
- BLOB_NAME_LENGTH_STATUS
- BLOB_NAME_STATUS
- BOOKMARK_ENTRY
- COLUMN_ENTRY
- COLUMN_ENTRY_EX
- COLUMN_ENTRY_LENGTH
- COLUMN_ENTRY_LENGTH_STATUS
- COLUMN_ENTRY_PS
- COLUMN_ENTRY_PS_LENGTH
- COLUMN_ENTRY_PS_LENGTH_STATUS
- COLUMN_ENTRY_PS_STATUS
- COLUMN_ENTRY_STATUS
- COLUMN_ENTRY_TYPE
- COLUMN_ENTRY_TYPE_SIZE
- COLUMN_NAME
- COLUMN_NAME_EX
- COLUMN_NAME_LENGTH
- COLUMN_NAME_LENGTH_STATUS
- COLUMN_NAME_PS
- COLUMN_NAME_PS_LENGTH
- COLUMN_NAME_PS_LENGTH_STATUS
- COLUMN_NAME_PS_STATUS
- COLUMN_NAME_STATUS
- COLUMN_NAME_TYPE
- COLUMN_NAME_TYPE_PS
- COLUMN_NAME_TYPE_SIZE
- COLUMN_NAME_TYPE_STATUS
- END_COLUMN_MAP
- DEFINE_COMMAND
- DEFINE_COMMAND_EX
- BEGIN_PARAM_MAP
- END_PARAM_MAP
- SET_PARAM_TYPE
helpviewer_keywords:
- OLE DB consumer templates, macros
- macros, OLE DB consumer template
- AtlTraceErrorRecords function
- BEGIN_ACCESSOR macro, syntax
- BEGIN_ACCESSOR macro
- BEGIN_ACCESSOR_MAP macro
- END_ACCESSOR macro
- END_ACCESSOR_MAP macro
- BEGIN_COLUMN_MAP macro
- BLOB_ENTRY macro
- BLOB_ENTRY_LENGTH macro
- BLOB_ENTRY_LENGTH_STATUS macro
- BLOB_ENTRY_STATUS macro
- BLOB_NAME macro
- BLOB_NAME_LENGTH macro
- BLOB_NAME_LENGTH_STATUS macro
- BLOB_NAME_STATUS macro
- BOOKMARK_ENTRY macro
- COLUMN_ENTRY macro
- COLUMN_ENTRY_EX macro
- COLUMN_ENTRY_LENGTH macro
- COLUMN_ENTRY_LENGTH_STATUS macro
- COLUMN_ENTRY_PS macro
- COLUMN_ENTRY_PS_LENGTH macro
- COLUMN_ENTRY_PS_LENGTH_STATUS macro
- COLUMN_ENTRY_PS_STATUS macro
- COLUMN_ENTRY_STATUS macro
- COLUMN_ENTRY_TYPE macro
- COLUMN_ENTRY_TYPE_SIZE macro
- COLUMN_NAME macro
- COLUMN_NAME_EX macro
- COLUMN_NAME_LENGTH macro
- COLUMN_NAME_LENGTH_STATUS macro
- COLUMN_NAME_PS macro
- COLUMN_NAME_PS_LENGTH macro
- COLUMN_NAME_PS_LENGTH_STATUS macro
- COLUMN_NAME_PS_STATUS macro
- COLUMN_NAME_STATUS macro
- COLUMN_NAME_TYPE macro
- COLUMN_NAME_TYPE_PS macro
- COLUMN_NAME_TYPE_SIZE macro
- COLUMN_NAME_TYPE_STATUS macro
- END_COLUMN_MAP macro
- DEFINE_COMMAND macro
- DEFINE_COMMAND_EX macro
- BEGIN_PARAM_MAP macro
- END_PARAM_MAP macro
- SET_PARAM_TYPE macro
ms.assetid: 8765eb7b-32dd-407c-bacf-8890ef959837
ms.openlocfilehash: 07fbdf7dfcd82937721955c5ba08e2241df162e5
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846531"
---
# <a name="macros-and-global-functions-for-ole-db-consumer-templates"></a>Macros e funções globais para modelos de consumidor de banco de dados OLE

Os modelos de consumidor OLE DB incluem as seguintes macros e funções globais:

## <a name="global-functions"></a>Funções globais

| Nome | Descrição |
|-|-|
|[AtlTraceErrorRecords](#atltraceerrorrecords)|Despeja OLE DB informações de registro de erro no dispositivo de despejo se um erro for retornado.|

## <a name="accessor-map-macros"></a>Macros de mapa do acessador

| Nome | Descrição |
|-|-|
|[BEGIN_ACCESSOR](#begin_accessor)|Marca o início de uma entrada de acessador.|
|[BEGIN_ACCESSOR_MAP](#begin_accessor_map)|Marca o início das entradas do mapa do acessador.|
|[END_ACCESSOR](#end_accessor)|Marca o final de uma entrada de acessador.|
|[END_ACCESSOR_MAP](#end_accessor_map)|Marca o final das entradas do mapa do acessador.|

## <a name="column-map-macros"></a>Macros de mapa de coluna

| Nome | Descrição |
|-|-|
|[BEGIN_COLUMN_MAP](#begin_column_map)|Marca o início das entradas de mapa de coluna na classe de registro de usuário.|
|[BLOB_ENTRY](#blob_entry)|Usado para associar um BLOB (objeto binário grande).|
|[BLOB_ENTRY_LENGTH](#blob_entry_length)|Relata o comprimento da coluna de dados de BLOB.|
|[BLOB_ENTRY_LENGTH_STATUS](#blob_entry_length_status)|Relata o comprimento e o status da coluna de dados de BLOB.|
|[BLOB_ENTRY_STATUS](#blob_entry_status)|Relata o status da coluna de dados de BLOB.|
|[BLOB_NAME](#blob_name)|Usado para associar um objeto binário grande por nome de coluna.|
|[BLOB_NAME_LENGTH](#blob_name_length)|Relata o comprimento da coluna de dados de BLOB.|
|[BLOB_NAME_LENGTH_STATUS](#blob_name_length_status)|Relata o comprimento e o status da coluna de dados de BLOB.|
|[BLOB_NAME_STATUS](#blob_name_status)|Relata o status da coluna de dados de BLOB.|
|[BOOKMARK_ENTRY](#bookmark_entry)|Representa uma entrada de indicador no conjunto de linhas. Uma entrada de indicador é um tipo especial de entrada de coluna.|
|[COLUMN_ENTRY](#column_entry)|Representa uma associação a uma coluna específica no banco de dados.|
|[COLUMN_ENTRY_EX](#column_entry_ex)|Representa uma associação à coluna específica no banco de dados. Dá suporte a parâmetros de *tipo*, *comprimento*, *precisão*, *escala*e *status* .|
|[COLUMN_ENTRY_LENGTH](#column_entry_length)|Representa uma associação à coluna específica no banco de dados. Dá suporte à variável de *comprimento* .|
|[COLUMN_ENTRY_LENGTH_STATUS](#column_entry_length_status)|Representa uma associação à coluna específica no banco de dados. Dá suporte a parâmetros de *status* e *comprimento* .|
|[COLUMN_ENTRY_PS](#column_entry_ps)|Representa uma associação à coluna específica no banco de dados. Dá suporte a parâmetros de *precisão* e *escala* .|
|[COLUMN_ENTRY_PS_LENGTH](#column_entry_ps_length)|Representa uma associação à coluna específica no banco de dados. Dá suporte aos parâmetros de variável de *comprimento* , *precisão* e *escala* .|
|[COLUMN_ENTRY_PS_LENGTH_STATUS](#column_entry_ps_length_status)|Representa uma associação à coluna específica no banco de dados. Dá suporte a variáveis de *status* e *comprimento* , parâmetros de *precisão* e *escala* .|
|[COLUMN_ENTRY_PS_STATUS](#column_entry_ps_status)|Representa uma associação à coluna específica no banco de dados. Dá suporte à variável de *status* , aos parâmetros de *precisão* e *escala* .|
|[COLUMN_ENTRY_STATUS](#column_entry_status)|Representa uma associação à coluna específica no banco de dados. Dá suporte à variável de *status* .|
|[COLUMN_ENTRY_TYPE](#column_entry_type)|Representa uma associação a uma coluna específica no banco de dados. Dá suporte ao parâmetro de *tipo* .|
|[COLUMN_ENTRY_TYPE_SIZE](#column_entry_type_size)|Representa uma associação à coluna específica no banco de dados. Dá suporte a parâmetros de *tipo* e *tamanho* .|
|[COLUMN_NAME](#column_name)|Representa uma associação a uma coluna específica no banco de dados por nome.|
|[COLUMN_NAME_EX](#column_name_ex)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de tipo de dados, tamanho, precisão, escala, comprimento da coluna e status da coluna.|
|[COLUMN_NAME_LENGTH](#column_name_length)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de comprimento de coluna.|
|[COLUMN_NAME_LENGTH_STATUS](#column_name_length_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de comprimento e status de coluna.|
|[COLUMN_NAME_PS](#column_name_ps)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de precisão e escala.|
|[COLUMN_NAME_PS_LENGTH](#column_name_ps_length)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de precisão, escala e comprimento de coluna.|
|[COLUMN_NAME_PS_LENGTH_STATUS](#column_name_ps_length_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de precisão, escala, comprimento de coluna e status de coluna.|
|[COLUMN_NAME_PS_STATUS](#column_name_ps_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de precisão, escala e status de coluna.|
|[COLUMN_NAME_STATUS](#column_name_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de status de coluna.|
|[COLUMN_NAME_TYPE](#column_name_type)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação do tipo de dados.|
|[COLUMN_NAME_TYPE_PS](#column_name_type_ps)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de tipo de dados, precisão e escala.|
|[COLUMN_NAME_TYPE_SIZE](#column_name_type_size)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de tipo e tamanho de dados.|
|[COLUMN_NAME_TYPE_STATUS](#column_name_type_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Dá suporte à especificação de tipo de dados e status de coluna.|
|[END_COLUMN_MAP](#end_column_map)|Marca o final das entradas de mapa de coluna.|

## <a name="command-macros"></a>Macros de comando

| Nome | Descrição |
|-|-|
|[DEFINE_COMMAND](#define_command)|Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand](../../data/oledb/ccommand-class.md) . Aceita somente tipos de cadeia de caracteres que correspondem ao tipo de aplicativo especificado (ANSI ou Unicode). É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.|
|[DEFINE_COMMAND_EX](#define_command_ex)|Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand](../../data/oledb/ccommand-class.md) . Dá suporte a aplicativos ANSI e Unicode.|

## <a name="parameter-map-macros"></a>Macros de mapa de parâmetro

| Nome | Descrição |
|-|-|
|[BEGIN_PARAM_MAP](#begin_param_map)|Marca o início das entradas do mapa de parâmetros na classe de registro do usuário.|
|[END_PARAM_MAP](#end_param_map)|Marca o final das entradas do mapa de parâmetros.|
|[SET_PARAM_TYPE](#set_param_type)|Especifica COLUMN_ENTRY macros que seguem a macro SET_PARAM_TYPE como entrada, saída ou entrada/saída.|

### <a name="atltraceerrorrecords"></a><a name="atltraceerrorrecords"></a> AtlTraceErrorRecords

Despeja OLE DB informações de registro de erro no dispositivo de despejo se um erro for retornado.

#### <a name="syntax"></a>Sintaxe

```cpp
inline void AtlTraceErrorRecords(HRESULT hrErr = S_OK);
```

#### <a name="parameters"></a>parâmetros

*hErr*<br/>
no Um HRESULT retornado por uma OLE DB função de membro de modelo de consumidor.

#### <a name="remarks"></a>Comentários

Se *Herr* não for S_OK, `AtlTraceErrorRecords` o Despeja OLE DB informações de registro de erro no dispositivo de despejo (a guia **depurar** da janela de saída ou de um arquivo). As informações de registro de erro, que são obtidas do provedor, incluem número de linha, origem, descrição, arquivo de ajuda, contexto e GUID para cada entrada de registro de erro. `AtlTraceErrorRecords` Despeja essas informações somente em compilações de depuração. Em builds de versão, é um stub vazio que é otimizado. Para obter mais informações, consulte [classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md).

### <a name="begin_accessor"></a><a name="begin_accessor"></a> BEGIN_ACCESSOR

Marca o início de uma entrada de acessador.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_ACCESSOR(num, bAuto)
```

#### <a name="parameters"></a>parâmetros

*num*<br/>
no O número de deslocamento zero para o acessador neste mapa de acessador.

*bAuto*<br/>
no Especifica se este acessador é um acessador automático ou um acessador manual. Se **`true`** , o acessador é auto; se **`false`** , o acessador é manual. Um acessador automático significa que os dados são buscados para você em operações de movimentação.

#### <a name="remarks"></a>Comentários

No caso de vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="begin_accessor_map"></a><a name="begin_accessor_map"></a> BEGIN_ACCESSOR_MAP

Marca o início das entradas do mapa do acessador.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_ACCESSOR_MAP(x, num)
```

#### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe de registro do usuário.

*num*<br/>
no O número de acessadores neste mapa de acessador.

#### <a name="remarks"></a>Comentários

No caso de vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP no início e usar a macro BEGIN_ACCESSOR para cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. O mapa do acessador é concluído com a macro END_ACCESSOR_MAP.

Se você tiver apenas um acessador no registro de usuário, use a macro [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).

#### <a name="example"></a>Exemplo

```cpp
class CArtistsAccessor
{
public:
// Data Elements
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];
   short m_nAge;

// Output binding map
BEGIN_ACCESSOR_MAP(CArtistsAccessor, 2)
   BEGIN_ACCESSOR(0, true)
      COLUMN_ENTRY(1, m_szFirstName)
      COLUMN_ENTRY(2, m_szLastName)
   END_ACCESSOR()
   BEGIN_ACCESSOR(1, false) // Not an auto accessor
      COLUMN_ENTRY(3, m_nAge)
   END_ACCESSOR()
END_ACCESSOR_MAP()

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsAccessor, L" \
   SELECT \
      FirstName, \
      LastName, \
      Age \
      FROM Artists")
};
```

### <a name="end_accessor"></a><a name="end_accessor"></a> END_ACCESSOR

Marca o final de uma entrada de acessador.

#### <a name="syntax"></a>Sintaxe

```cpp
END_ACCESSOR()
```

#### <a name="remarks"></a>Comentários

Para vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="end_accessor_map"></a><a name="end_accessor_map"></a> END_ACCESSOR_MAP

Marca o final das entradas do mapa do acessador.

#### <a name="syntax"></a>Sintaxe

```cpp
END_ACCESSOR_MAP()
```

#### <a name="remarks"></a>Comentários

Para vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="begin_column_map"></a><a name="begin_column_map"></a> BEGIN_COLUMN_MAP

Marca o início de uma entrada de mapa de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_COLUMN_MAP(x)
```

#### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe de registro de usuário derivada de `CAccessor` .

#### <a name="remarks"></a>Comentários

Essa macro é usada no caso de um único acessador em um conjunto de linhas. Se você tiver vários acessadores em um conjunto de linhas, use [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

A macro BEGIN_COLUMN_MAP é concluída com a macro END_COLUMN_MAP. Essa macro é usada quando há apenas um acessador necessário no registro do usuário.

As colunas correspondem aos campos no conjunto de linhas que você deseja associar.

#### <a name="example"></a>Exemplo

Veja uma coluna de exemplo e um mapa de parâmetro:

<!--[!CODE [NVC_OLEDB_Consumer#16](../codesnippet/vs_snippets_cpp/nvc_oledb_consumer#16)]  -->

### <a name="blob_entry"></a><a name="blob_entry"></a> BLOB_ENTRY

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande).

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY(nOrdinal, IID, flags, data)
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar um blob?](../../data/oledb/retrieving-a-blob.md).

### <a name="blob_entry_length"></a><a name="blob_entry_length"></a> BLOB_ENTRY_LENGTH

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro também obtém o comprimento em bytes da coluna BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY_LENGTH(nOrdinal, IID, flags, data, length)
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
fora O comprimento (real) em bytes da coluna de BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar um blob?](../../data/oledb/retrieving-a-blob.md).

### <a name="blob_entry_length_status"></a><a name="blob_entry_length_status"></a> BLOB_ENTRY_LENGTH_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro também obtém o comprimento e o status da coluna de BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY_LENGTH_STATUS(
    nOrdinal,
    IID,
    flags,
    data,
    length,
    status )
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
fora O comprimento (real) em bytes da coluna de BLOB.

*status*<br/>
fora O status da coluna de dados de BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar um blob?](../../data/oledb/retrieving-a-blob.md).

### <a name="blob_entry_status"></a><a name="blob_entry_status"></a> BLOB_ENTRY_STATUS

Usado com BEGIN_COLUMN_MAP ou BEGIN_ACCESSOR_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro também obtém o status da coluna de BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY_STATUS(nOrdinal, IID, flags, data, status)
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
fora O status do campo de BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar um blob?](../../data/oledb/retrieving-a-blob.md).

### <a name="blob_name"></a><a name="blob_name"></a> BLOB_NAME

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro usa um nome de coluna em vez de um número de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME(pszName, IID, flags, data )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar um blob?](../../data/oledb/retrieving-a-blob.md).

### <a name="blob_name_length"></a><a name="blob_name_length"></a> BLOB_NAME_LENGTH

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_NAME](../../data/oledb/blob-name.md), exceto que essa macro também obtém o comprimento em bytes da coluna de dados de BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_LENGTH(pszName, IID, flags, data, length )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
fora O comprimento (real) em bytes da coluna de BLOB.

### <a name="blob_name_length_status"></a><a name="blob_name_length_status"></a> BLOB_NAME_LENGTH_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_NAME](../../data/oledb/blob-name.md), exceto que essa macro também obtém o comprimento e o status da coluna de dados de BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_LENGTH_STATUS(pszName, IID, flags, data, length, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
fora O comprimento (real) em bytes da coluna de BLOB.

*status*<br/>
fora O status do campo de BLOB.

### <a name="blob_name_status"></a><a name="blob_name_status"></a> BLOB_NAME_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um[blob](/previous-versions/windows/desktop/ms711511(v=vs.85))(objeto binário grande). Semelhante a [BLOB_NAME](../../data/oledb/blob-name.md), exceto que essa macro também obtém o status da coluna de dados de BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_STATUS(pszName, IID, flags, data, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*IID*<br/>
no GUID de interface, como `IDD_ISequentialStream` , usado para recuperar o blob.

*sinalizadores*<br/>
no Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ` ).

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
fora O status do campo de BLOB.

### <a name="bookmark_entry"></a><a name="bookmark_entry"></a> BOOKMARK_ENTRY

Associa a coluna de indicador.

#### <a name="syntax"></a>Sintaxe

```cpp
BOOKMARK_ENTRY(variable)
```

#### <a name="parameters"></a>parâmetros

*variable*<br/>
no A variável a ser associada à coluna de indicadores.

#### <a name="example"></a>Exemplo

```cpp
class CArtistsBookmark
{
public:
// Data Elements
   CBookmark<4> m_bookmark;
   short m_nAge;
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];

// Output binding map
BEGIN_COLUMN_MAP(CArtistsBookmark)
   BOOKMARK_ENTRY(m_bookmark)
   COLUMN_ENTRY(1, m_nAge)
   COLUMN_ENTRY(2, m_szFirstName)
   COLUMN_ENTRY(3, m_szLastName)
END_COLUMN_MAP()

   void GetRowsetProperties(CDBPropSet* pPropSet)
   {
      pPropSet->AddProperty(DBPROP_BOOKMARKS, true);
   }

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsBookmark, L" \
   SELECT \
      Age, \
      FirstName, \
      LastName \
      FROM Artists")
};
```

Para obter mais informações, consulte [usando indicadores](using-bookmarks.md) e a [classe CBookmark](../../data/oledb/cbookmark-class.md).

### <a name="column_entry"></a><a name="column_entry"></a> COLUMN_ENTRY

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY(nOrdinal, data)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

A macro COLUMN_ENTRY é usada nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

#### <a name="example"></a>Exemplo

Consulte os exemplos nos tópicos de macro, [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="column_entry_ex"></a><a name="column_entry_ex"></a> COLUMN_ENTRY_EX

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_EX(nOrdinal, wType, nLength, nPrecision, nScale, data, length, status)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*wType*<br/>
no O tipo de dados.

*nLength*<br/>
no O tamanho dos dados em bytes.

*nPrecision*<br/>
no A precisão máxima a ser usada ao obter dados *wType* e wType `DBTYPE_NUMERIC` . Caso contrário, esse parâmetro será ignorado.

*nScale*<br/>
no A escala a ser usada ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

A macro COLUMN_ENTRY_EX é usada nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

#### <a name="example"></a>Exemplo

Consulte [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="column_entry_length"></a><a name="column_entry_length"></a> COLUMN_ENTRY_LENGTH

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_LENGTH(nOrdinal, data, length)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna, começando com um. O indicador corresponde à coluna zero.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Esta macro dá suporte à variável de *comprimento* . Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_length_status"></a><a name="column_entry_length_status"></a> COLUMN_ENTRY_LENGTH_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_LENGTH_STATUS(nOrdinal, data, length, status)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Use essa macro quando desejar dar suporte a variáveis de comprimento e status. Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_ps"></a><a name="column_entry_ps"></a> COLUMN_ENTRY_PS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS(nOrdinal, nPrecision, nScale, data)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Permite que você especifique a precisão e a escala da coluna que deseja associar. Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_ps_length"></a><a name="column_entry_ps_length"></a> COLUMN_ENTRY_PS_LENGTH

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_LENGTH(nOrdinal, nPrecision, nScale, data, length)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna, começando com um. O indicador corresponde à coluna zero.

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Permite que você especifique a precisão e a escala da coluna que deseja associar. Esta macro dá suporte à variável de *comprimento* . Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_ps_length_status"></a><a name="column_entry_ps_length_status"></a> COLUMN_ENTRY_PS_LENGTH_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_LENGTH_STATUS(nOrdinal, nPrecision, nScale, data, length, status)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Permite que você especifique a precisão e a escala da coluna que deseja associar. Use essa macro quando desejar dar suporte a variáveis de comprimento e status. Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_ps_status"></a><a name="column_entry_ps_status"></a> COLUMN_ENTRY_PS_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_STATUS(nOrdinal, nPrecision, nScale, data, status)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Permite que você especifique a precisão e a escala da coluna que deseja associar. Esta macro dá suporte à variável de *status* . Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_status"></a><a name="column_entry_status"></a> COLUMN_ENTRY_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_STATUS(nOrdinal, data, status)
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no O número da coluna.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Esta macro dá suporte à variável de *status* . Ele é usado nos seguintes locais:

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_entry_type"></a><a name="column_entry_type"></a> COLUMN_ENTRY_TYPE

Representa uma associação à coluna específica no banco de dados. Dá suporte ao parâmetro de *tipo* .

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_TYPE (nOrdinal, wType, data)
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*wType*<br/>
no Tipo de dados da entrada de coluna.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Essa macro é uma variante especializada da macro [COLUMN_ENTRY](../../data/oledb/column-entry.md) que fornece um meio de especificar o tipo de dados.

### <a name="column_entry_type_size"></a><a name="column_entry_type_size"></a> COLUMN_ENTRY_TYPE_SIZE

Representa uma associação à coluna específica no banco de dados. Dá suporte a parâmetros de *tipo* e *tamanho* .

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_TYPE_SIZE(nOrdinal, wType, nLength, data)
```

#### <a name="parameters"></a>parâmetros

*nOrdinal*<br/>
no O número da coluna.

*wType*<br/>
no Tipo de dados da entrada de coluna.

*nLength*<br/>
no Tamanho da entrada da coluna em bytes.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Essa macro é uma variante especializada da macro [COLUMN_ENTRY](../../data/oledb/column-entry.md) que fornece um meio de especificar o tamanho e o tipo dos dados.

### <a name="column_name"></a><a name="column_name"></a> COLUMN_NAME

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [COLUMN_ENTRY](../../data/oledb/column-entry.md), exceto que essa macro usa o nome da coluna em vez do número da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME(pszName, data)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

As macros COLUMN_NAME_ * são usadas nos mesmos locais que [COLUMN_ENTRY](../../data/oledb/column-entry.md):

- Entre as macros [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) .

- Entre as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

- Entre as macros [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) .

### <a name="column_name_ex"></a><a name="column_name_ex"></a> COLUMN_NAME_EX

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o tipo de dados, o tamanho, a precisão, a escala, o comprimento da coluna e o status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_EX(pszName, wType, nLength, nPrecision, nScale, data, length, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*wType*<br/>
no O tipo de dados.

*nLength*<br/>
no O tamanho dos dados em bytes.

*nPrecision*<br/>
no A precisão máxima a ser usada ao obter dados *wType* e wType `DBTYPE_NUMERIC` . Caso contrário, esse parâmetro será ignorado.

*nScale*<br/>
no A escala a ser usada ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_length"></a><a name="column_name_length"></a> COLUMN_NAME_LENGTH

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa comprimento de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_LENGTH(pszName, data, length)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_length_status"></a><a name="column_name_length_status"></a> COLUMN_NAME_LENGTH_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o comprimento da coluna e o status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_LENGTH_STATUS(pszName, data, length, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_ps"></a><a name="column_name_ps"></a> COLUMN_NAME_PS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa precisão e escala.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS(pszName, nPrecision, nScale, data )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_ps_length"></a><a name="column_name_ps_length"></a> COLUMN_NAME_PS_LENGTH

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa precisão, escala e comprimento de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_LENGTH(pszName, nPrecision, nScale, data, length )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_ps_length_status"></a><a name="column_name_ps_length_status"></a> COLUMN_NAME_PS_LENGTH_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa precisão, escala, comprimento de coluna e status de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_LENGTH_STATUS(pszName, nPrecision, nScale, data, length, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*length*<br/>
no A variável a ser associada ao comprimento da coluna.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_ps_status"></a><a name="column_name_ps_status"></a> COLUMN_NAME_PS_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa precisão, escala e status de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_STATUS(pszName, nPrecision, nScale, data, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*nPrecision*<br/>
no A precisão máxima da coluna que você deseja associar.

*nScale*<br/>
no A escala da coluna que você deseja associar.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_status"></a><a name="column_name_status"></a> COLUMN_NAME_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também obtém o status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_STATUS(pszName, data, status )
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

*status*<br/>
no A variável a ser associada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_type"></a><a name="column_name_type"></a> COLUMN_NAME_TYPE

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o tipo de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE(pszName, wType, data)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*wType*<br/>
no O tipo de dados.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_type_ps"></a><a name="column_name_type_ps"></a> COLUMN_NAME_TYPE_PS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o tipo de dados, a precisão e a escala.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_PS(pszName, wType, nPrecision, nScale, data)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*wType*<br/>
no O tipo de dados.

*nPrecision*<br/>
no A precisão máxima a ser usada ao obter dados *wType* e wType `DBTYPE_NUMERIC` . Caso contrário, esse parâmetro será ignorado.

*nScale*<br/>
no A escala a ser usada ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL` .

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_type_size"></a><a name="column_name_type_size"></a> COLUMN_NAME_TYPE_SIZE

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o tipo e o tamanho dos dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_SIZE(pszName, wType, nLength, data)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*wType*<br/>
no O tipo de dados.

*nLength*<br/>
no O tamanho dos dados em bytes.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="column_name_type_status"></a><a name="column_name_type_status"></a> COLUMN_NAME_TYPE_STATUS

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante a [column_name](../../data/oledb/column-name.md), exceto que essa macro também usa o tipo de dados e o status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_STATUS(pszName, wType, status, data)
```

#### <a name="parameters"></a>parâmetros

*pszName*<br/>
no Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um ' L' na frente do nome, por exemplo: `L"MyColumn"` .

*wType*<br/>
no O tipo de dados.

*status*<br/>
no A variável a ser associada ao status da coluna.

*data*<br/>
no O membro de dados correspondente no registro de usuário.

#### <a name="remarks"></a>Comentários

Consulte [column_name](../../data/oledb/column-name.md) para obter informações sobre onde as macros de COLUMN_NAME_ * são usadas.

### <a name="end_column_map"></a><a name="end_column_map"></a> END_COLUMN_MAP

Marca o final das entradas de mapa de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
END_COLUMN_MAP()
```

#### <a name="remarks"></a>Comentários

Ele é usado com um único acessador em um conjunto de linhas. A macro BEGIN_COLUMN_MAP é concluída com a macro END_COLUMN_MAP.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).

### <a name="define_command"></a><a name="define_command"></a> DEFINE_COMMAND

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand](../../data/oledb/ccommand-class.md) . Aceita somente tipos de cadeia de caracteres que correspondem ao tipo de aplicativo especificado (ANSI ou Unicode).

> [!NOTE]
> É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.

#### <a name="syntax"></a>Sintaxe

```cpp
DEFINE_COMMAND(x, szCommand)
```

#### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe de registro (comando) do usuário.

*szCommand*<br/>
no A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).

#### <a name="remarks"></a>Comentários

A cadeia de caracteres de comando que você especificar será usada como padrão se você não especificar o texto do comando no método [CCommand:: Open](../../data/oledb/ccommand-open.md) .

Essa macro aceita cadeias de caracteres ANSI se você compilar seu aplicativo como ANSI, ou cadeias de caracteres Unicode, se você compilar seu aplicativo como Unicode. É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND, porque o primeiro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo ANSI ou Unicode.

#### <a name="example"></a>Exemplo

Consulte [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="define_command_ex"></a><a name="define_command_ex"></a> DEFINE_COMMAND_EX

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand](../../data/oledb/ccommand-class.md) . Dá suporte a aplicativos Unicode e ANSI.

#### <a name="syntax"></a>Sintaxe

```cpp
DEFINE_COMMAND_EX(x, wszCommand)
```

#### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe de registro (comando) do usuário.

*wszCommand*<br/>
no A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).

#### <a name="remarks"></a>Comentários

A cadeia de caracteres de comando que você especificar será usada como padrão se você não especificar o texto do comando no método [CCommand:: Open](../../data/oledb/ccommand-open.md) .

Essa macro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo. Essa macro é preferida em [DEFINE_COMMAND](../../data/oledb/define-command.md) porque oferece suporte a Unicode, bem como a aplicativos ANSI.

#### <a name="example"></a>Exemplo

Consulte [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="begin_param_map"></a><a name="begin_param_map"></a> BEGIN_PARAM_MAP

Marca o início das entradas do mapa de parâmetros.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PARAM_MAP(x)
```

#### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe de registro do usuário.

#### <a name="remarks"></a>Comentários

Os parâmetros são usados por [comandos](/previous-versions/windows/desktop/ms724608(v=vs.85)).

#### <a name="example"></a>Exemplo

Consulte o exemplo da macro [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) .

### <a name="end_param_map"></a><a name="end_param_map"></a> END_PARAM_MAP

Marca o final das entradas do mapa de parâmetros.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PARAM_MAP()
```

#### <a name="example"></a>Exemplo

Consulte o exemplo da macro [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) .

### <a name="set_param_type"></a><a name="set_param_type"></a> SET_PARAM_TYPE

Especifica COLUMN_ENTRY macros que seguem o SET_PARAM_TYPE entrada/saída da macro.

#### <a name="syntax"></a>Sintaxe

```cpp
SET_PARAM_TYPE(type)
```

#### <a name="parameters"></a>parâmetros

*tipo*<br/>
no O tipo a ser definido para o parâmetro.

#### <a name="remarks"></a>Comentários

Os provedores dão suporte apenas a tipos de entrada/saída de parâmetro que são suportados pela fonte de dados subjacente. O tipo é uma combinação de um ou mais `DBPARAMIO` valores (consulte [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*):

- `DBPARAMIO_NOTPARAM` O acessador não tem parâmetros. Normalmente, você define `eParamIO` para esse valor em acessadores de linha para lembrar o usuário de que os parâmetros são ignorados.

- `DBPARAMIO_INPUT` Um parâmetro de entrada.

- `DBPARAMIO_OUTPUT` Um parâmetro de saída.

- `DBPARAMIO_INPUT | DBPARAMIO_OUTPUT` O parâmetro é um parâmetro de entrada e de saída.

#### <a name="example"></a>Exemplo

```cpp
class CArtistsProperty
{
public:
   short m_nReturn;
   short m_nAge;
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];

BEGIN_PARAM_MAP(CArtistsProperty)
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)
   COLUMN_ENTRY(1, m_nReturn)
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(2, m_nAge)
END_PARAM_MAP()

BEGIN_COLUMN_MAP(CArtistsProperty)
   COLUMN_ENTRY(1, m_szFirstName)
   COLUMN_ENTRY(2, m_szLastName)
END_COLUMN_MAP()

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsProperty, L" \
      { ? = SELECT Age FROM Artists WHERE Age < ? }")
};
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Confira também

[Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
