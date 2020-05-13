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
ms.openlocfilehash: 8b898990672f590f6047eef6fdfd1ed7eecb3f92
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369820"
---
# <a name="macros-and-global-functions-for-ole-db-consumer-templates"></a>Macros e funções globais para modelos de consumidor de banco de dados OLE

Os modelos de consumo do OLE DB incluem as seguintes macros e funções globais:

## <a name="global-functions"></a>Funções Globais

|||
|-|-|
|[AtlTraceErrorRecords](#atltraceerrorrecords)|Despeja informações do Registro de erro do OLE DB no dispositivo de despejo se um erro for devolvido.|

## <a name="accessor-map-macros"></a>Macros do mapa do acessório

|||
|-|-|
|[BEGIN_ACCESSOR](#begin_accessor)|Marca o início de uma entrada de acessório.|
|[BEGIN_ACCESSOR_MAP](#begin_accessor_map)|Marca o início das entradas do mapa do acessório.|
|[END_ACCESSOR](#end_accessor)|Marca o fim de uma entrada de acessório.|
|[END_ACCESSOR_MAP](#end_accessor_map)|Marca o fim das entradas do mapa do acessório.|

## <a name="column-map-macros"></a>Macros do mapa da coluna

|||
|-|-|
|[BEGIN_COLUMN_MAP](#begin_column_map)|Marca o início das entradas do mapa da coluna na classe de registro do usuário.|
|[BLOB_ENTRY](#blob_entry)|Usado para ligar um objeto grande binário (BLOB).|
|[BLOB_ENTRY_LENGTH](#blob_entry_length)|Informa o comprimento da coluna de dados BLOB.|
|[BLOB_ENTRY_LENGTH_STATUS](#blob_entry_length_status)|Informa o comprimento e o status da coluna de dados BLOB.|
|[BLOB_ENTRY_STATUS](#blob_entry_status)|Informa o status da coluna de dados BLOB.|
|[Blob_name](#blob_name)|Usado para vincular um objeto grande binário por nome de coluna.|
|[BLOB_NAME_LENGTH](#blob_name_length)|Informa o comprimento da coluna de dados BLOB.|
|[BLOB_NAME_LENGTH_STATUS](#blob_name_length_status)|Informa o comprimento e o status da coluna de dados BLOB.|
|[BLOB_NAME_STATUS](#blob_name_status)|Informa o status da coluna de dados BLOB.|
|[BOOKMARK_ENTRY](#bookmark_entry)|Representa uma entrada de marcador no conjunto de linhas. Uma entrada de marcador é um tipo especial de entrada de coluna.|
|[COLUMN_ENTRY](#column_entry)|Representa uma vinculação a uma coluna específica no banco de dados.|
|[COLUMN_ENTRY_EX](#column_entry_ex)|Representa uma vinculação à coluna específica no banco de dados. Suporta *parâmetros de tipo,* *comprimento,* *precisão,* *escala*e *status.*|
|[COLUMN_ENTRY_LENGTH](#column_entry_length)|Representa uma vinculação à coluna específica no banco de dados. Suporta a variável *comprimento.*|
|[COLUMN_ENTRY_LENGTH_STATUS](#column_entry_length_status)|Representa uma vinculação à coluna específica no banco de dados. Suporta parâmetros *de status* e *comprimento.*|
|[COLUMN_ENTRY_PS](#column_entry_ps)|Representa uma vinculação à coluna específica no banco de dados. Suporta parâmetros *de precisão* e *escala.*|
|[COLUMN_ENTRY_PS_LENGTH](#column_entry_ps_length)|Representa uma vinculação à coluna específica no banco de dados. Suporta os parâmetros de variável *de comprimento,* *precisão* e *escala.*|
|[COLUMN_ENTRY_PS_LENGTH_STATUS](#column_entry_ps_length_status)|Representa uma vinculação à coluna específica no banco de dados. Suporta variáveis *de status* e *comprimento,* parâmetros *de precisão* e *escala.*|
|[COLUMN_ENTRY_PS_STATUS](#column_entry_ps_status)|Representa uma vinculação à coluna específica no banco de dados. Suporta os parâmetros de variável *de status,* *precisão* e *escala.*|
|[COLUMN_ENTRY_STATUS](#column_entry_status)|Representa uma vinculação à coluna específica no banco de dados. Suporta a variável *de status.*|
|[COLUMN_ENTRY_TYPE](#column_entry_type)|Representa uma vinculação a uma coluna específica no banco de dados. Suporta parâmetro *de tipo.*|
|[COLUMN_ENTRY_TYPE_SIZE](#column_entry_type_size)|Representa uma vinculação à coluna específica no banco de dados. Suporta parâmetros *de tipo* e *tamanho.*|
|[Column_name](#column_name)|Representa uma vinculação a uma coluna específica no banco de dados por nome.|
|[COLUMN_NAME_EX](#column_name_ex)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do tipo de dados, tamanho, precisão, escala, comprimento da coluna e status da coluna.|
|[COLUMN_NAME_LENGTH](#column_name_length)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do comprimento da coluna.|
|[COLUMN_NAME_LENGTH_STATUS](#column_name_length_status)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do comprimento e status da coluna.|
|[COLUMN_NAME_PS](#column_name_ps)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação de precisão e escala.|
|[COLUMN_NAME_PS_LENGTH](#column_name_ps_length)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação de precisão, escala e comprimento da coluna.|
|[COLUMN_NAME_PS_LENGTH_STATUS](#column_name_ps_length_status)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação de precisão, escala, comprimento da coluna e status da coluna.|
|[COLUMN_NAME_PS_STATUS](#column_name_ps_status)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação de precisão, escala e status da coluna.|
|[COLUMN_NAME_STATUS](#column_name_status)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do status da coluna.|
|[COLUMN_NAME_TYPE](#column_name_type)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do tipo de dados.|
|[COLUMN_NAME_TYPE_PS](#column_name_type_ps)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação de tipo de dados, precisão e escala.|
|[COLUMN_NAME_TYPE_SIZE](#column_name_type_size)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do tipo e tamanho dos dados.|
|[COLUMN_NAME_TYPE_STATUS](#column_name_type_status)|Representa uma vinculação a uma coluna específica no banco de dados por nome. Suporta especificação do tipo de dados e status da coluna.|
|[END_COLUMN_MAP](#end_column_map)|Marca o fim das entradas do mapa da coluna.|

## <a name="command-macros"></a>Macros de comando

|||
|-|-|
|[DEFINE_COMMAND](#define_command)|Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand.](../../data/oledb/ccommand-class.md) Aceita apenas tipos de string que correspondam ao tipo de aplicativo especificado (ANSI ou Unicode). Recomenda-se que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.|
|[DEFINE_COMMAND_EX](#define_command_ex)|Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand.](../../data/oledb/ccommand-class.md) Suporta aplicativos ANSI e Unicode.|

## <a name="parameter-map-macros"></a>Macros do mapa do parâmetro

|||
|-|-|
|[BEGIN_PARAM_MAP](#begin_param_map)|Marca o início das entradas do mapa de parâmetros na classe de registro do usuário.|
|[END_PARAM_MAP](#end_param_map)|Marca o fim das entradas do mapa do parâmetro.|
|[SET_PARAM_TYPE](#set_param_type)|Especifica COLUMN_ENTRY macros que seguem a SET_PARAM_TYPE macro como entrada, saída ou entrada/saída.|

### <a name="atltraceerrorrecords"></a><a name="atltraceerrorrecords"></a>AtlTraceErrorRecords

Despeja informações do Registro de erro do OLE DB no dispositivo de despejo se um erro for devolvido.

#### <a name="syntax"></a>Sintaxe

```cpp
inline void AtlTraceErrorRecords(HRESULT hrErr = S_OK);
```

#### <a name="parameters"></a>Parâmetros

*Herr*<br/>
[em] Um HRESULT retornado por uma função de membro do Modelo de Consumo OLE DB.

#### <a name="remarks"></a>Comentários

Se *o hErr* `AtlTraceErrorRecords` não estiver S_OK, despeje as informações do Registro de Erro do OLE DB no dispositivo de despejo (a guia **Debug** da janela Saída ou um arquivo). As informações do Registro de Erro, obtidas do provedor, incluem número de linha, origem, descrição, arquivo de ajuda, contexto e GUID para cada entrada de registro de erro. `AtlTraceErrorRecords`despeja essas informações apenas em compilações de depuração. Nas compilações de lançamento, é um stub vazio que é otimizado para fora. Para obter mais informações, consulte [CDBErrorInfo Class](../../data/oledb/cdberrorinfo-class.md).

### <a name="begin_accessor"></a><a name="begin_accessor"></a>Begin_accessor

Marca o início de uma entrada de acessório.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_ACCESSOR(num, bAuto)
```

#### <a name="parameters"></a>Parâmetros

*num*<br/>
[em] O número de deslocamento zero para o acessório neste mapa acessório.

*bAuto*<br/>
[em] Especifica se este acessório é um acessório automático ou um acessório manual. Se **for verdade,** o acessório é automático; se **falso,** o acessório é manual. Um acessório automático significa que os dados são buscados para você em operações de movimento.

#### <a name="remarks"></a>Comentários

No caso de vários acessórios em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessório individual. A macro BEGIN_ACCESSOR é completada com a END_ACCESSOR macro. A BEGIN_ACCESSOR_MAP macro é completada com a END_ACCESSOR_MAP macro.

#### <a name="example"></a>Exemplo

Veja [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="begin_accessor_map"></a><a name="begin_accessor_map"></a>Begin_accessor_map

Marca o início das entradas do mapa do acessório.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_ACCESSOR_MAP(x, num)
```

#### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe de registro de usuário.

*num*<br/>
[em] O número de acessórios neste mapa acessório.

#### <a name="remarks"></a>Comentários

No caso de vários acessórios em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP no início e usar a macro BEGIN_ACCESSOR para cada acessório individual. A macro BEGIN_ACCESSOR é completada com a END_ACCESSOR macro. O mapa do acessório é preenchido com a END_ACCESSOR_MAP macro.

Se você tiver apenas um acessório no registro do usuário, use o [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)macro .

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

### <a name="end_accessor"></a><a name="end_accessor"></a>END_ACCESSOR

Marca o fim de uma entrada de acessório.

#### <a name="syntax"></a>Sintaxe

```cpp
END_ACCESSOR()
```

#### <a name="remarks"></a>Comentários

Para vários acessórios em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessório individual. A macro BEGIN_ACCESSOR é completada com a END_ACCESSOR macro. A BEGIN_ACCESSOR_MAP macro é completada com a END_ACCESSOR_MAP macro.

#### <a name="example"></a>Exemplo

Veja [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="end_accessor_map"></a><a name="end_accessor_map"></a>END_ACCESSOR_MAP

Marca o fim das entradas do mapa do acessório.

#### <a name="syntax"></a>Sintaxe

```cpp
END_ACCESSOR_MAP()
```

#### <a name="remarks"></a>Comentários

Para vários acessórios em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR para cada acessório individual. A macro BEGIN_ACCESSOR é completada com a END_ACCESSOR macro. A BEGIN_ACCESSOR_MAP macro é completada com a END_ACCESSOR_MAP macro.

#### <a name="example"></a>Exemplo

Veja [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="begin_column_map"></a><a name="begin_column_map"></a>Begin_column_map

Marca o início de uma entrada de mapa de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_COLUMN_MAP(x)
```

#### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe de `CAccessor`registro de usuário derivado de .

#### <a name="remarks"></a>Comentários

Esta macro é usada no caso de um único acessório em um conjunto de linhas. Se você tiver vários acessórios em um conjunto de linhas, use [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

A BEGIN_COLUMN_MAP macro é completada com a END_COLUMN_MAP macro. Esta macro é usada quando há apenas um acessório necessário no registro do usuário.

As colunas correspondem aos campos no conjunto de linhas que você deseja vincular.

#### <a name="example"></a>Exemplo

Aqui está uma coluna de exemplo e mapa de parâmetros:

<!--[!CODE [NVC_OLEDB_Consumer#16](../codesnippet/vs_snippets_cpp/nvc_oledb_consumer#16)]  -->

### <a name="blob_entry"></a><a name="blob_entry"></a>Blob_entry

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85))

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY(nOrdinal, IID, flags, data)
```

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar uma bolha?](../../data/oledb/retrieving-a-blob.md)

### <a name="blob_entry_length"></a><a name="blob_entry_length"></a>BLOB_ENTRY_LENGTH

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_ENTRY,](../../data/oledb/blob-entry.md)exceto que esta macro também obtém o comprimento em bytes da coluna BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY_LENGTH(nOrdinal, IID, flags, data, length)
```

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[fora] O comprimento (real) em bytes da coluna BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar uma bolha?](../../data/oledb/retrieving-a-blob.md)

### <a name="blob_entry_length_status"></a><a name="blob_entry_length_status"></a>BLOB_ENTRY_LENGTH_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_ENTRY,](../../data/oledb/blob-entry.md)exceto que esta macro também obtém o comprimento e o status da coluna BLOB.

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

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[fora] O comprimento (real) em bytes da coluna BLOB.

*status*<br/>
[fora] O status da coluna de dados BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar uma bolha?](../../data/oledb/retrieving-a-blob.md)

### <a name="blob_entry_status"></a><a name="blob_entry_status"></a>BLOB_ENTRY_STATUS

Usado com BEGIN_COLUMN_MAP ou BEGIN_ACCESSOR_MAP para ligar um objeto grande binário[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_ENTRY,](../../data/oledb/blob-entry.md)exceto que esta macro também obtém o status da coluna BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_ENTRY_STATUS(nOrdinal, IID, flags, data, status)
```

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[fora] O status do campo BLOB.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar uma bolha?](../../data/oledb/retrieving-a-blob.md)

### <a name="blob_name"></a><a name="blob_name"></a>Blob_name

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que esta macro leva um nome de coluna em vez de um número de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME(pszName, IID, flags, data )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="example"></a>Exemplo

Veja [como posso recuperar uma bolha?](../../data/oledb/retrieving-a-blob.md)

### <a name="blob_name_length"></a><a name="blob_name_length"></a>BLOB_NAME_LENGTH

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_NAME,](../../data/oledb/blob-name.md)exceto que esta macro também obtém o comprimento em bytes da coluna de dados BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_LENGTH(pszName, IID, flags, data, length )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[fora] O comprimento (real) em bytes da coluna BLOB.

### <a name="blob_name_length_status"></a><a name="blob_name_length_status"></a>BLOB_NAME_LENGTH_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_NAME,](../../data/oledb/blob-name.md)exceto que esta macro também obtém o comprimento e o status da coluna de dados BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_LENGTH_STATUS(pszName, IID, flags, data, length, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[fora] O comprimento (real) em bytes da coluna BLOB.

*status*<br/>
[fora] O status do campo BLOB.

### <a name="blob_name_status"></a><a name="blob_name_status"></a>BLOB_NAME_STATUS

Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para ligar um objeto binário grande[(BLOB).](/previous-versions/windows/desktop/ms711511(v=vs.85)) Semelhante ao [BLOB_NAME,](../../data/oledb/blob-name.md)exceto que esta macro também obtém o status da coluna de dados BLOB.

#### <a name="syntax"></a>Sintaxe

```cpp
BLOB_NAME_STATUS(pszName, IID, flags, data, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*IID*<br/>
[em] Interface GUID, `IDD_ISequentialStream`como , usado para recuperar o BLOB.

*Sinalizadores*<br/>
[em] O modo de armazenamento sinaliza conforme definido pelo modelo `STGM_READ`de armazenamento estruturado OLE (por exemplo, ).

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[fora] O status do campo BLOB.

### <a name="bookmark_entry"></a><a name="bookmark_entry"></a>Bookmark_entry

Liga a coluna do marcador.

#### <a name="syntax"></a>Sintaxe

```cpp
BOOKMARK_ENTRY(variable)
```

#### <a name="parameters"></a>Parâmetros

*variável*<br/>
[em] A variável a ser vinculada à coluna de marcadores.

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

Para obter mais informações, consulte [Usando marcadores](using-bookmarks.md) e [classe CBookmark](../../data/oledb/cbookmark-class.md).

### <a name="column_entry"></a><a name="column_entry"></a>Column_entry

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY(nOrdinal, data)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

A macro COLUMN_ENTRY é usada nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

#### <a name="example"></a>Exemplo

Veja os exemplos nos tópicos macro, [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).

### <a name="column_entry_ex"></a><a name="column_entry_ex"></a>COLUMN_ENTRY_EX

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_EX(nOrdinal, wType, nLength, nPrecision, nScale, data, length, status)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*wType*<br/>
[em] O tipo de dados.

*Nlength*<br/>
[em] O tamanho dos dados em bytes.

*nPrecisão*<br/>
[em] A precisão máxima a ser usada `DBTYPE_NUMERIC`ao obter dados e *wType* é . Caso contrário, este parâmetro é ignorado.

*nEscala*<br/>
[em] A escala a ser usada ao `DBTYPE_NUMERIC` `DBTYPE_DECIMAL`obter dados e *wType* é ou .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

A macro COLUMN_ENTRY_EX é usada nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

#### <a name="example"></a>Exemplo

Veja [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="column_entry_length"></a><a name="column_entry_length"></a>COLUMN_ENTRY_LENGTH

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_LENGTH(nOrdinal, data, length)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna, começando com um. Marcador corresponde à coluna zero.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Esta macro suporta a variável *comprimento.* É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_length_status"></a><a name="column_entry_length_status"></a>COLUMN_ENTRY_LENGTH_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_LENGTH_STATUS(nOrdinal, data, length, status)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Use esta macro quando quiser suportar variáveis de comprimento e status. É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_ps"></a><a name="column_entry_ps"></a>COLUMN_ENTRY_PS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS(nOrdinal, nPrecision, nScale, data)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Permite especificar a precisão e a escala da coluna que deseja vincular. É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_ps_length"></a><a name="column_entry_ps_length"></a>COLUMN_ENTRY_PS_LENGTH

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_LENGTH(nOrdinal, nPrecision, nScale, data, length)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna, começando com um. Marcador corresponde à coluna zero.

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Permite especificar a precisão e a escala da coluna que deseja vincular. Esta macro suporta a variável *comprimento.* É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_ps_length_status"></a><a name="column_entry_ps_length_status"></a>COLUMN_ENTRY_PS_LENGTH_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_LENGTH_STATUS(nOrdinal, nPrecision, nScale, data, length, status)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Permite especificar a precisão e a escala da coluna que deseja vincular. Use esta macro quando quiser suportar variáveis de comprimento e status. É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_ps_status"></a><a name="column_entry_ps_status"></a>COLUMN_ENTRY_PS_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_PS_STATUS(nOrdinal, nPrecision, nScale, data, status)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Permite especificar a precisão e a escala da coluna que deseja vincular. Esta macro suporta a variável *de status.* É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_status"></a><a name="column_entry_status"></a>COLUMN_ENTRY_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no banco de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_STATUS(nOrdinal, data, status)
```

#### <a name="parameters"></a>Parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*.

*nOrdinal*<br/>
[em] O número da coluna.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Esta macro suporta a variável *de status.* É usado nos seguintes lugares:

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_entry_type"></a><a name="column_entry_type"></a>COLUMN_ENTRY_TYPE

Representa uma vinculação à coluna específica no banco de dados. Suporta parâmetro *de tipo.*

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_TYPE (nOrdinal, wType, data)
```

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*wType*<br/>
[em] Tipo de dados de entrada de coluna.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Esta macro é uma variante especializada da [macro COLUMN_ENTRY](../../data/oledb/column-entry.md) que fornece um meio de especificar o tipo de dados.

### <a name="column_entry_type_size"></a><a name="column_entry_type_size"></a>COLUMN_ENTRY_TYPE_SIZE

Representa uma vinculação à coluna específica no banco de dados. Suporta parâmetros *de tipo* e *tamanho.*

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_ENTRY_TYPE_SIZE(nOrdinal, wType, nLength, data)
```

#### <a name="parameters"></a>Parâmetros

*nOrdinal*<br/>
[em] O número da coluna.

*wType*<br/>
[em] Tipo de dados de entrada de coluna.

*Nlength*<br/>
[em] Tamanho da entrada da coluna em bytes.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Esta macro é uma variante especializada da [COLUMN_ENTRY](../../data/oledb/column-entry.md) macro que fornece um meio de especificar tamanho e tipo de dados.

### <a name="column_name"></a><a name="column_name"></a>Column_name

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_ENTRY,](../../data/oledb/column-entry.md)exceto que esta macro leva o nome da coluna em vez do número da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME(pszName, data)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

As macros COLUMN_NAME_* são usadas nos mesmos lugares [que COLUMN_ENTRY:](../../data/oledb/column-entry.md)

- Entre as [macros BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP.](../../data/oledb/end-column-map.md)

- Entre as [macros BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR.](../../data/oledb/end-accessor.md)

- Entre as [macros BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP.](../../data/oledb/end-param-map.md)

### <a name="column_name_ex"></a><a name="column_name_ex"></a>COLUMN_NAME_EX

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva tipo de dados, tamanho, precisão, escala, comprimento da coluna e status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_EX(pszName, wType, nLength, nPrecision, nScale, data, length, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*wType*<br/>
[em] O tipo de dados.

*Nlength*<br/>
[em] O tamanho dos dados em bytes.

*nPrecisão*<br/>
[em] A precisão máxima a ser usada `DBTYPE_NUMERIC`ao obter dados e *wType* é . Caso contrário, este parâmetro é ignorado.

*nEscala*<br/>
[em] A escala a ser usada ao `DBTYPE_NUMERIC` `DBTYPE_DECIMAL`obter dados e *wType* é ou .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_length"></a><a name="column_name_length"></a>COLUMN_NAME_LENGTH

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva comprimento da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_LENGTH(pszName, data, length)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_length_status"></a><a name="column_name_length_status"></a>COLUMN_NAME_LENGTH_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva comprimento da coluna e status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_LENGTH_STATUS(pszName, data, length, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_ps"></a><a name="column_name_ps"></a>COLUMN_NAME_PS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva precisão e escala.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS(pszName, nPrecision, nScale, data )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_ps_length"></a><a name="column_name_ps_length"></a>COLUMN_NAME_PS_LENGTH

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva precisão, escala e comprimento da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_LENGTH(pszName, nPrecision, nScale, data, length )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_ps_length_status"></a><a name="column_name_ps_length_status"></a>COLUMN_NAME_PS_LENGTH_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também requer precisão, escala, comprimento da coluna e status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_LENGTH_STATUS(pszName, nPrecision, nScale, data, length, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*length*<br/>
[em] A variável a ser ligada ao comprimento da coluna.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_ps_status"></a><a name="column_name_ps_status"></a>COLUMN_NAME_PS_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), exceto que esta macro também leva precisão, escala e status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_PS_STATUS(pszName, nPrecision, nScale, data, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*nPrecisão*<br/>
[em] A precisão máxima da coluna que você deseja vincular.

*nEscala*<br/>
[em] A escala da coluna que você deseja vincular.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_status"></a><a name="column_name_status"></a>COLUMN_NAME_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também tem status de coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_STATUS(pszName, data, status )
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_type"></a><a name="column_name_type"></a>COLUMN_NAME_TYPE

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva tipo de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE(pszName, wType, data)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*wType*<br/>
[em] O tipo de dados.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_type_ps"></a><a name="column_name_type_ps"></a>COLUMN_NAME_TYPE_PS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que essa macro também leva tipo de dados, precisão e escala.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_PS(pszName, wType, nPrecision, nScale, data)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*wType*<br/>
[em] O tipo de dados.

*nPrecisão*<br/>
[em] A precisão máxima a ser usada `DBTYPE_NUMERIC`ao obter dados e *wType* é . Caso contrário, este parâmetro é ignorado.

*nEscala*<br/>
[em] A escala a ser usada ao `DBTYPE_NUMERIC` `DBTYPE_DECIMAL`obter dados e *wType* é ou .

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_type_size"></a><a name="column_name_type_size"></a>COLUMN_NAME_TYPE_SIZE

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva tipo e tamanho de dados.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_SIZE(pszName, wType, nLength, data)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*wType*<br/>
[em] O tipo de dados.

*Nlength*<br/>
[em] O tamanho dos dados em bytes.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="column_name_type_status"></a><a name="column_name_type_status"></a>COLUMN_NAME_TYPE_STATUS

Representa uma vinculação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME,](../../data/oledb/column-name.md)exceto que esta macro também leva o tipo de dados e o status da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
COLUMN_NAME_TYPE_STATUS(pszName, wType, status, data)
```

#### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
[em] Um ponteiro para o nome da coluna. O nome deve ser uma seqüência Unicode. Você pode conseguir isso colocando um 'L' na frente `L"MyColumn"`do nome, por exemplo: .

*wType*<br/>
[em] O tipo de dados.

*status*<br/>
[em] A variável a ser vinculada ao status da coluna.

*dados*<br/>
[em] O membro de dados correspondente no registro do usuário.

#### <a name="remarks"></a>Comentários

Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_* são usadas.

### <a name="end_column_map"></a><a name="end_column_map"></a>END_COLUMN_MAP

Marca o fim das entradas do mapa da coluna.

#### <a name="syntax"></a>Sintaxe

```cpp
END_COLUMN_MAP()
```

#### <a name="remarks"></a>Comentários

É usado com um único acessório em um conjunto de linhas. A BEGIN_COLUMN_MAP macro é completada com a END_COLUMN_MAP macro.

#### <a name="example"></a>Exemplo

Veja [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).

### <a name="define_command"></a><a name="define_command"></a>DEFINE_COMMAND

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand.](../../data/oledb/ccommand-class.md) Aceita apenas tipos de string que correspondam ao tipo de aplicativo especificado (ANSI ou Unicode).

> [!NOTE]
> Recomenda-se que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.

#### <a name="syntax"></a>Sintaxe

```cpp
DEFINE_COMMAND(x, szCommand)
```

#### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe registro de usuário (comando).

*Szcommand*<br/>
[em] A seqüência de comando saem para criar o conjunto de linhas ao usar [cCommand](../../data/oledb/ccommand-class.md).

#### <a name="remarks"></a>Comentários

A seqüência de comando susceptência será usada como padrão se você não especificar o texto de comando no método [CCommand::Abrir.](../../data/oledb/ccommand-open.md)

Essa macro aceita strings ANSI se você criar seu aplicativo como ANSI ou unicode strings se você criar seu aplicativo como Unicode. Recomenda-se que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND, pois o primeiro aceita strings Unicode, independentemente do tipo de aplicativo ANSI ou Unicode.

#### <a name="example"></a>Exemplo

Veja [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="define_command_ex"></a><a name="define_command_ex"></a>DEFINE_COMMAND_EX

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe [CCommand.](../../data/oledb/ccommand-class.md) Suporta aplicativos Unicode e ANSI.

#### <a name="syntax"></a>Sintaxe

```cpp
DEFINE_COMMAND_EX(x, wszCommand)
```

#### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe registro de usuário (comando).

*wszCommand*<br/>
[em] A seqüência de comando saem para criar o conjunto de linhas ao usar [cCommand](../../data/oledb/ccommand-class.md).

#### <a name="remarks"></a>Comentários

A seqüência de comando susceptência será usada como padrão se você não especificar o texto de comando no método [CCommand::Abrir.](../../data/oledb/ccommand-open.md)

Esta macro aceita strings Unicode, independentemente do tipo de aplicativo. Essa macro é preferível em relação [DEFINE_COMMAND](../../data/oledb/define-command.md) porque suporta aplicativos Unicode e ANSI.

#### <a name="example"></a>Exemplo

Veja [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

### <a name="begin_param_map"></a><a name="begin_param_map"></a>BEGIN_PARAM_MAP

Marca o início das entradas do mapa do parâmetro.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PARAM_MAP(x)
```

#### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe de registro de usuário.

#### <a name="remarks"></a>Comentários

Os parâmetros são usados por [comandos](/previous-versions/windows/desktop/ms724608(v=vs.85)).

#### <a name="example"></a>Exemplo

Veja o exemplo da [macro BEGIN_COLUMN_MAP.](../../data/oledb/begin-column-map.md)

### <a name="end_param_map"></a><a name="end_param_map"></a>END_PARAM_MAP

Marca o fim das entradas do mapa do parâmetro.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PARAM_MAP()
```

#### <a name="example"></a>Exemplo

Veja o exemplo da [macro BEGIN_PARAM_MAP.](../../data/oledb/begin-param-map.md)

### <a name="set_param_type"></a><a name="set_param_type"></a>Set_param_type

Especifica COLUMN_ENTRY macros que seguem a SET_PARAM_TYPE de entrada, saída ou entrada/saída de macro.

#### <a name="syntax"></a>Sintaxe

```cpp
SET_PARAM_TYPE(type)
```

#### <a name="parameters"></a>Parâmetros

*type*<br/>
[em] O tipo a definir para o parâmetro.

#### <a name="remarks"></a>Comentários

Os provedores suportam apenas os tipos de entrada/saída de parâmetros suportados pela fonte de dados subjacente. O tipo é uma combinação `DBPARAMIO` de um ou mais valores (consulte [Estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador OLE DB*):

- `DBPARAMIO_NOTPARAM`O acessório não tem parâmetros. Normalmente, você `eParamIO` define esse valor em acessórios de linha para lembrar ao usuário que os parâmetros são ignorados.

- `DBPARAMIO_INPUT`Um parâmetro de entrada.

- `DBPARAMIO_OUTPUT`Um parâmetro de saída.

- `DBPARAMIO_INPUT | DBPARAMIO_OUTPUT`O parâmetro é tanto um parâmetro de entrada quanto de saída.

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

**Cabeçalho:** atldbcli.h

## <a name="see-also"></a>Confira também

[Macros e funções globais para modelos de consumidor de banco de dados OLE](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
