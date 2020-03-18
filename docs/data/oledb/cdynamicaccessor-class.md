---
title: Classe CDynamicAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL.CDynamicAccessor
- ATL::CDynamicAccessor
- CDynamicAccessor
- ATL::CDynamicAccessor::AddBindEntry
- CDynamicAccessor.AddBindEntry
- CDynamicAccessor::AddBindEntry
- ATL.CDynamicAccessor.AddBindEntry
- CDynamicAccessor::CDynamicAccessor
- ATL::CDynamicAccessor::CDynamicAccessor
- ATL.CDynamicAccessor.CDynamicAccessor
- CDynamicAccessor.CDynamicAccessor
- ATL::CDynamicAccessor::Close
- ATL.CDynamicAccessor.Close
- CDynamicAccessor.Close
- CDynamicAccessor::Close
- ATL.CDynamicAccessor.GetBlobHandling
- CDynamicAccessor::GetBlobHandling
- ATL::CDynamicAccessor::GetBlobHandling
- GetBlobHandling
- CDynamicAccessor.GetBlobHandling
- ATL::CDynamicAccessor::GetBlobSizeLimit
- CDynamicAccessor.GetBlobSizeLimit
- CDynamicAccessor::GetBlobSizeLimit
- GetBlobSizeLimit
- ATL.CDynamicAccessor.GetBlobSizeLimit
- CDynamicAccessor.GetBookmark
- GetBookmark
- CDynamicAccessor::GetBookmark
- ATL.CDynamicAccessor.GetBookmark
- ATL::CDynamicAccessor::GetBookmark
- ATL.CDynamicAccessor.GetColumnCount
- ATL::CDynamicAccessor::GetColumnCount
- CDynamicAccessor::GetColumnCount
- CDynamicAccessor.GetColumnCount
- GetColumnCount
- CDynamicAccessor.GetColumnFlags
- ATL::CDynamicAccessor::GetColumnFlags
- ATL.CDynamicAccessor.GetColumnFlags
- CDynamicAccessor::GetColumnFlags
- ATL.CDynamicAccessor.GetColumnInfo
- ATL::CDynamicAccessor::GetColumnInfo
- CDynamicAccessor.GetColumnInfo
- CDynamicAccessor::GetColumnInfo
- ATL::CDynamicAccessor::GetColumnName
- GetColumnName
- ATL.CDynamicAccessor.GetColumnName
- CDynamicAccessor::GetColumnName
- CDynamicAccessor.GetColumnName
- ATL.CDynamicAccessor.GetColumnType
- CDynamicAccessor::GetColumnType
- GetColumnType
- CDynamicAccessor.GetColumnType
- ATL::CDynamicAccessor::GetColumnType
- CDynamicAccessor.GetLength
- ATL.CDynamicAccessor.GetLength
- CDynamicAccessor::GetLength
- ATL::CDynamicAccessor::GetLength
- CDynamicAccessor.GetOrdinal
- ATL::CDynamicAccessor::GetOrdinal
- CDynamicAccessor::GetOrdinal
- ATL.CDynamicAccessor.GetOrdinal
- GetOrdinal
- ATL::CDynamicAccessor::GetStatus
- CDynamicAccessor.GetStatus
- ATL.CDynamicAccessor.GetStatus
- CDynamicAccessor::GetStatus
- GetValue
- CDynamicAccessor::GetValue<ctype>
- ATL.CDynamicAccessor.GetValue<ctype>
- CDynamicAccessor.GetValue
- CDynamicAccessor::GetValue
- ATL.CDynamicAccessor.GetValue
- ATL::CDynamicAccessor::GetValue
- ATL::CDynamicAccessor::GetValue<ctype>
- CDynamicAccessor::SetBlobHandling
- CDynamicAccessor.SetBlobHandling
- ATL::CDynamicAccessor::SetBlobHandling
- SetBlobHandling
- ATL.CDynamicAccessor.SetBlobHandling
- CDynamicAccessor::SetBlobSizeLimit
- SetBlobSizeLimit
- CDynamicAccessor.SetBlobSizeLimit
- ATL.CDynamicAccessor.SetBlobSizeLimit
- ATL::CDynamicAccessor::SetBlobSizeLimit
- ATL::CDynamicAccessor::SetLength
- CDynamicAccessor.SetLength
- CDynamicAccessor::SetLength
- ATL.CDynamicAccessor.SetLength
- CDynamicAccessor::SetStatus
- ATL::CDynamicAccessor::SetStatus
- CDynamicAccessor.SetStatus
- ATL.CDynamicAccessor.SetStatus
- ATL.CDynamicAccessor.SetValue
- ATL::CDynamicAccessor::SetValue
- ATL::CDynamicAccessor::SetValue<ctype>
- CDynamicAccessor.SetValue
- ATL.CDynamicAccessor.SetValue<ctype>
- CDynamicAccessor::SetValue
- CDynamicAccessor::SetValue<ctype>
helpviewer_keywords:
- CDynamicAccessor class
- AddBindEntry method
- CDynamicAccessor class, constructor
- Close method
- GetBlobHandling method
- GetBlobSizeLimit method
- GetBookmark method
- GetColumnCount method
- GetColumnFlags method
- GetColumnInfo method
- GetColumnName method
- GetColumnType method
- GetLength method
- GetOrdinal method
- GetStatus method
- GetValue method
- SetBlobHandling method
- SetBlobSizeLimit method
- SetLength method
- SetStatus method
- SetValue method
ms.assetid: 374b13b7-1f09-457d-9e6b-df260ff4d178
ms.openlocfilehash: 08e36606ae5d8dc34b9e25dd7d8dbc6d606520da
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447386"
---
# <a name="cdynamicaccessor-class"></a>Classe CDynamicAccessor

Permite que você acesse uma fonte de dados quando não tem nenhum conhecimento do esquema de banco (a estrutura subjacente do banco de dado).

## <a name="syntax"></a>Sintaxe

```cpp
class CDynamicAccessor : public CAccessorBase
```

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho**: atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[AddBindEntry](#addbindentry)|Adiciona uma entrada de associação às colunas de saída ao substituir o acessador padrão.|
|[CDynamicAccessor](#cdynamicaccessor)|Cria uma instância e inicializa o objeto `CDynamicAccessor`.|
|[Fechar](#close)|Desassocia todas as colunas, libera a memória alocada e libera o ponteiro de interface [IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85)) na classe.|
|[GetBlobHandling](#getblobhandling)|Recupera o valor de manipulação de BLOB para a linha atual.|
|[GetBlobSizeLimit](#getblobsizelimit)|Recupera o tamanho máximo do BLOB em bytes.|
|[GetBookmark](#getbookmark)|Recupera o indicador para a linha atual.|
|[Getnúmerodecolunas](#getcolumncount)|Recupera o número de colunas no conjunto de linhas.|
|[GetColumnFlags](#getcolumnflags)|Recupera as características da coluna.|
|[GetColumnInfo](#getcolumninfo)|Recupera os metadados da coluna.|
|[GetColumnName](#getcolumnname)|Recupera o nome de uma coluna especificada.|
|[GetColumnType](#getcolumntype)|Recupera o tipo de dados de uma coluna especificada.|
|[GetLength](#getlength)|Recupera o tamanho máximo possível de uma coluna em bytes.|
|[GetOrdinal](#getordinal)|Recupera o índice de coluna dado um nome de coluna.|
|[GetStatus](#getstatus)|Recupera o status de uma coluna especificada.|
|[GetValue](#getvalue)|Recupera os dados do buffer.|
|[SetBlobHandling](#setblobhandling)|Define o valor de manipulação de BLOB para a linha atual.|
|[SetBlobSizeLimit](#setblobsizelimit)|Define o tamanho máximo do BLOB em bytes.|
|[SetLength](#setlength)|Define o comprimento da coluna em bytes.|
|[SetStatus](#setstatus)|Define o status de uma coluna especificada.|
|[SetValue](#setvalue)|Armazena os dados no buffer.|

## <a name="remarks"></a>Comentários

Use os métodos `CDynamicAccessor` para obter informações de coluna, como nomes de coluna, contagem de colunas, tipo de dados e assim por diante. Em seguida, você usa essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer que é criado e gerenciado por essa classe. Obtenha dados do buffer usando [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md).

Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).

## <a name="addbindentry"></a>CDynamicAccessor::AddBindEntry

Adiciona uma entrada de associação às colunas de saída.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT AddBindEntry(const DBCOLUMNINFO& info) throw();
```

#### <a name="parameters"></a>Parâmetros

*info*<br/>
no Uma estrutura de `DBCOLUMNINFO` que contém informações de coluna. Consulte "estruturas DBCOLUMNINFO" em [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Use esse método ao substituir o acessador padrão criado com `CDynamicAccessor` (consulte [como posso buscar dados?](../../data/oledb/fetching-data.md)).

## <a name="cdynamicaccessor"></a>CDynamicAccessor::CDynamicAccessor

Cria uma instância e inicializa o objeto `CDynamicAccessor`.

### <a name="syntax"></a>Sintaxe

```cpp
CDynamicAccessor(DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,
   DBLENGTH nBlobSize = 8000);
```

#### <a name="parameters"></a>Parâmetros

*eBlobHandling*<br/>
Especifica como os dados do objeto binário grande (BLOB) serão manipulados. O valor padrão é DBBLOBHANDLING_DEFAULT. Consulte [SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição dos valores de DBBLOBHANDLINGENUM.

*nBlobSize*<br/>
O tamanho máximo do BLOB em bytes; os dados de coluna sobre esse valor são tratados como um BLOB. O valor padrão é 8.000. Consulte [SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.

### <a name="remarks"></a>Comentários

Se você usar o construtor para inicializar o objeto `CDynamicAccessor`, poderá especificar como ele associará BLOBs. Os BLOBs podem conter dados binários, como gráficos, som ou código compilado. O comportamento padrão é tratar colunas com mais de 8.000 bytes como BLOBs e tentar associá-las a um objeto `ISequentialStream`. No entanto, você pode especificar um valor diferente para ser o tamanho do BLOB.

Você também pode especificar como o `CDynamicAccessor` trata os dados da coluna que se qualificam como dados de BLOB: ele pode manipular dados de BLOB da maneira padrão; Ele pode ignorar (não associa) dados de BLOB; ou pode associar dados de BLOB na memória alocada pelo provedor.

## <a name="close"></a>CDynamicAccessor:: fechar

Desassocia todas as colunas, libera a memória alocada e libera o ponteiro de interface [IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85)) na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

## <a name="getblobhandling"></a>CDynamicAccessor::GetBlobHandling

Recupera o valor de manipulação de BLOB para a linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
const DBBLOBHANDLINGENUM GetBlobHandling() const;
```

### <a name="remarks"></a>Comentários

Retorna o valor de manipulação de BLOB *eBlobHandling* conforme definido por [SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md).

## <a name="getblobsizelimit"></a>CDynamicAccessor::GetBlobSizeLimit

Recupera o tamanho máximo do BLOB em bytes.

### <a name="syntax"></a>Sintaxe

```cpp
const DBLENGTH GetBlobSizeLimit() const;
```

### <a name="remarks"></a>Comentários

Retorna o valor de manipulação de BLOB *nBlobSize* conforme definido por [SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md).

## <a name="getbookmark"></a>CDynamicAccessor:: GetBookmark

Recupera o indicador para a linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetBookmark(CBookmark< >* pBookmark) const throw();
```

#### <a name="parameters"></a>Parâmetros

*pBookmark*<br/>
fora Um ponteiro para o objeto [CBookmark](../../data/oledb/cbookmark-class.md) .

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Você precisa definir `DBPROP_IRowsetLocate` como VARIANT_TRUE para recuperar um indicador.

## <a name="getcolumncount"></a>CDynamicAccessor:: GetColumnCount

Recupera o número de colunas.

### <a name="syntax"></a>Sintaxe

```cpp
DBORDINAL GetColumnCount() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de colunas recuperadas.

## <a name="getcolumnflags"></a>CDynamicAccessor::GetColumnFlags

Recupera as características da coluna.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetColumnFlags(DBORDINAL nColumn,
   DBCOLUMNFLAGS* pFlags) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pFlags*<br/>
fora Um ponteiro para uma bitmask que descreve as características da coluna. Consulte "DBCOLUMNFLAGS enumerated Type" em [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Retornará **true** se as características da coluna forem recuperadas com êxito. Caso contrário, retornará **false**.

### <a name="remarks"></a>Comentários

O número da coluna é deslocado de um. A coluna zero é um caso especial; é o indicador, se disponível.

## <a name="getcolumninfo"></a>CDynamicAccessor:: GetColumnInfo

Retorna os metadados de coluna necessários para a maioria dos consumidores.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetColumnInfo(IRowset* pRowset,
   DBORDINAL* pColumns,
   DBCOLUMNINFO** ppColumnInfo,
   OLECHAR** ppStringsBuffer) throw();
```

#### <a name="parameters"></a>Parâmetros

*pRowset*<br/>
no Um ponteiro para a interface [IRowset](/previous-versions/windows/desktop/ms720986(v=vs.85)) .

*pColumns*<br/>
fora Um ponteiro para a memória na qual retornar o número de colunas no conjunto de linhas; Esse número inclui a coluna de indicadores, se houver uma.

*ppColumnInfo*<br/>
fora Um ponteiro para a memória na qual retornar uma matriz de estruturas de `DBCOLUMNINFO`. Consulte "estruturas DBCOLUMNINFO" em [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

*ppStringsBuffer*<br/>
fora Um ponteiro para a memória no qual retornar um ponteiro para o armazenamento para todos os valores de cadeia de caracteres (nomes usados dentro de *columnid* ou *pwszName*) em um único bloco de alocação.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulte [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB* para obter informações sobre os tipos de dados `DBORDINAL`, `DBCOLUMNINFO`e `OLECHAR`.

## <a name="getcolumnname"></a>CDynamicAccessor:: getColumnName

Recupera o nome da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetColumnName(DBORDINAL nColumn) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

### <a name="return-value"></a>Valor retornado

O nome da coluna especificada.

## <a name="getcolumntype"></a>CDynamicAccessor:: getColumnType

Recupera o tipo de dados de uma coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetColumnType(DBORDINAL nColumn,
   DBTYPE* pType) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pType*<br/>
fora Um ponteiro para o tipo de dados da coluna especificada.

### <a name="return-value"></a>Valor retornado

Retorna **verdadeiro** em caso de êxito ou **falso** em caso de falha.

## <a name="getlength"></a>CDynamicAccessor::GetLength

Recupera o comprimento da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetLength(DBORDINAL nColumn,
   DBLENGTH* pLength) const throw();

bool GetLength(const CHAR* pColumnName,
   DBLENGTH* pLength) const throw();

bool GetLength(const WCHAR* pColumnName,
   DBLENGTH* pLength) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pLength*<br/>
fora Um ponteiro para o inteiro que contém o comprimento da coluna em bytes.

### <a name="return-value"></a>Valor retornado

Retornará **true** se a coluna especificada for encontrada. Caso contrário, essa função retornará **false**.

### <a name="remarks"></a>Comentários

A primeira substituição usa o número da coluna, e a segunda e terceira substitui o nome da coluna no formato ANSI ou Unicode, respectivamente.

## <a name="getordinal"></a>CDynamicAccessor:: GetOrdinal

Recupera o número da coluna de acordo com um nome de coluna.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetOrdinal(const CHAR* pColumnName,
   DBORDINAL* pOrdinal) const throw();

bool GetOrdinal(const WCHAR* pColumnName,
   DBORDINAL* pOrdinal) const throw();
```

#### <a name="parameters"></a>Parâmetros

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pOrdinal*<br/>
fora Um ponteiro para o número da coluna.

### <a name="return-value"></a>Valor retornado

Retornará **true** se uma coluna com o nome especificado for encontrada. Caso contrário, essa função retornará **false**.

## <a name="getstatus"></a>CDynamicAccessor:: GetStatus

Recupera o status da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetStatus(DBORDINAL nColumn,
   DBSTATUS* pStatus) const throw();

bool GetStatus(const CHAR* pColumnName,
   DBSTATUS* pStatus) const throw();

bool GetStatus(const WCHAR* pColumnName,
   DBSTATUS* pStatus) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pStatus*<br/>
fora Um ponteiro para a variável que contém o status da coluna. Consulte [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

### <a name="return-value"></a>Valor retornado

Retornará **true** se a coluna especificada for encontrada. Caso contrário, essa função retornará **false**.

## <a name="getvalue"></a>CDynamicAccessor:: GetValue

Recupera os dados de uma coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
void* GetValue(DBORDINAL nColumn) const throw();

void* GetValue(const CHAR* pColumnName) const throw();

void* GetValue(const WCHAR* pColumnName) const throw();

template < class ctype >
bool GetValue(DBORDINAL nColumn, ctype* pData) const throw();

template < class ctype >
bool GetValue(const CHAR* pColumnName, ctype* pData) const throw();

template < class ctype >
bool GetValue(const WCHAR* pColumnName, ctype* pData) const throw();
```

#### <a name="parameters"></a>Parâmetros

*ctype*<br/>
no Um parâmetro de modelo que manipula qualquer tipo de dados, exceto os tipos de cadeia de caracteres (`CHAR*`, `WCHAR*`), que exigem tratamento especial. `GetValue` usa o tipo de dados apropriado com base no que você especificar aqui.

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pColumnName*<br/>
no O nome da coluna.

*pData*<br/>
fora O ponteiro para o conteúdo da coluna especificada.

### <a name="return-value"></a>Valor retornado

Se você quiser passar dados de cadeia de caracteres, use as versões não modeladas do `GetValue`. As versões não modeladas desse método retornam `void*`, que aponta para a parte do buffer que contém os dados de coluna especificados. Retornará NULL se a coluna não for encontrada.

Para todos os outros tipos de dados, é mais simples usar as versões modeladas do `GetValue`. As versões do modelo retornam **true** em caso de êxito ou **falso** em caso de falha.

### <a name="remarks"></a>Comentários

Use as versões não modeladas para retornar colunas que contêm cadeias de caracteres e as versões de modelo para colunas que contêm outros tipos de dados.

No modo de depuração, você receberá uma asserção se o tamanho de *pData* for diferente do tamanho da coluna para a qual ele aponta.

## <a name="setblobhandling"></a>CDynamicAccessor::SetBlobHandling

Define o valor de manipulação de BLOB para a linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetBlobHandling(DBBLOBHANDLINGENUM eBlobHandling);
```

#### <a name="parameters"></a>Parâmetros

*eBlobHandling*<br/>
Especifica como os dados de BLOB serão manipulados. Pode usar os seguintes valores:

- DBBLOBHANDLING_DEFAULT: tratar dados de coluna maiores que *nBlobSize* (conforme definido por `SetBlobSizeLimit`) como dados de BLOB e recuperá-los por meio de um objeto `ISequentialStream` ou `IStream`. Esta opção tentará associar todas as colunas que contêm dados maiores que *nBlobSize* ou listados como DBTYPE_IUNKNOWN dados de BLOB.

- DBBLOBHANDLING_NOSTREAMS: manipule dados de coluna maiores do que *nBlobSize* (conforme definido por `SetBlobSizeLimit`) como dados de BLOB e recupere-os por meio de referência em memória de consumidor alocada para o provedor. Essa opção é útil para tabelas que têm mais de uma coluna de BLOB, e o provedor dá suporte a apenas um objeto `ISequentialStream` por acessador.

- DBBLOBHANDLING_SKIP: ignorar (não associar) colunas que contenham BLOBs (o acessador não associará ou recuperará o valor da coluna, mas ainda recuperará o status e o comprimento da coluna).

### <a name="remarks"></a>Comentários

Você deve chamar `SetBlobHandling` antes de chamar `Open`.

O método de construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o valor de manipulação de BLOB para DBBLOBHANDLING_DEFAULT.

## <a name="setblobsizelimit"></a>CDynamicAccessor::SetBlobSizeLimit

Define o tamanho máximo do BLOB em bytes.

### <a name="syntax"></a>Sintaxe

```cpp
void SetBlobSizeLimit(DBLENGTH nBlobSize);
```

#### <a name="parameters"></a>Parâmetros

*nBlobSize*<br/>
Especifica o limite de tamanho do BLOB.

### <a name="remarks"></a>Comentários

Define o tamanho máximo do BLOB em bytes; os dados de coluna maiores que esse valor são tratados como um BLOB. Alguns provedores fornecem tamanhos extremamente grandes para colunas (como 2 GB). Em vez de tentar alocar memória para uma coluna com esse tamanho, você normalmente tentaria associar essas colunas como BLOBs. Dessa forma, você não precisa alocar toda a memória, mas ainda pode ler todos os dados sem medo de truncamento. No entanto, há alguns casos em que você talvez queira forçar `CDynamicAccessor` a associar colunas grandes em seus tipos de dados nativos. Para fazer isso, chame `SetBlobSizeLimit` antes de chamar `Open`.

O método do construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o tamanho máximo do blob para um valor padrão de 8.000 bytes.

## <a name="setlength"></a>CDynamicAccessor:: SetLength

Define o comprimento da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetLength(DBORDINAL nColumn,
   DBLENGTH nLength)throw();

bool SetLength(const CHAR* pColumnName,
   DBLENGTH nLength) throw();

bool SetLength(const WCHAR* pColumnName,
   DBLENGTH nLength) throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*nLength*<br/>
no O comprimento da coluna em bytes.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor retornado

Retornará **true** se o comprimento da coluna especificada for definido com êxito. Caso contrário, essa função retornará **false**.

## <a name="setstatus"></a>CDynamicAccessor:: SetStatus

Define o status da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetStatus(DBORDINAL nColumn,
   DBSTATUS status)throw();

bool SetStatus(const CHAR* pColumnName,
   DBSTATUS status) throw();

bool SetStatus(const WCHAR* pColumnName,
   DBSTATUS status) throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*status*<br/>
no O status da coluna. Consulte [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor retornado

Retornará **true** se o status da coluna especificada for definido com êxito. Caso contrário, essa função retornará **false**.

## <a name="setvalue"></a>CDynamicAccessor:: SetValue

Armazena dados em uma coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
template <class ctype>
bool SetValue(
   DBORDINAL nColumn,
   constctype& data) throw( );

template <class ctype> 
bool SetValue(
   const CHAR * pColumnName,
   const ctype& data) throw( );

template <class ctype>
bool SetValue(
   const WCHAR *pColumnName,
   const ctype& data) throw( );
```

#### <a name="parameters"></a>Parâmetros

*ctype*<br/>
no Um parâmetro de modelo que manipula qualquer tipo de dados, exceto os tipos de cadeia de caracteres (`CHAR*`, `WCHAR*`), que exigem tratamento especial. `GetValue` usa o tipo de dados apropriado com base no que você especificar aqui.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*data*<br/>
no O ponteiro para a memória que contém os dados.

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

### <a name="return-value"></a>Valor retornado

Se você quiser definir dados de cadeia de caracteres, use as versões não modeladas do `GetValue`. As versões não modeladas desse método retornam `void*`, que aponta para a parte do buffer que contém os dados de coluna especificados. Retornará NULL se a coluna não for encontrada.

Para todos os outros tipos de dados, é mais simples usar as versões modeladas do `GetValue`. As versões do modelo retornam **true** em caso de êxito ou **falso** em caso de falha.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)