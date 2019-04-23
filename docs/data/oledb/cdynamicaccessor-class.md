---
title: Classe CDynamicAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL.CDynamicAccessor
- ATL::CDynamicAccessor
- CDynamicAccessor
- ATL::CDynamicAccessor::AddBindEntry
- AddBindEntry
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
- GetColumnFlags
- GetColumnInfo
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
ms.openlocfilehash: 19b8d0c86044e04cc60fd7aab89ec828c46f5fb9
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59040962"
---
# <a name="cdynamicaccessor-class"></a>Classe CDynamicAccessor

Permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura de base do banco de dados).

## <a name="syntax"></a>Sintaxe

```cpp
class CDynamicAccessor : public CAccessorBase
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddBindEntry](#addbindentry)|Adiciona uma entrada de associação para as colunas de saída ao substituir o acessador padrão.|
|[CDynamicAccessor](#cdynamicaccessor)|Cria uma instância e inicializa o `CDynamicAccessor` objeto.|
|[Fechar](#close)|Desvincula todas as colunas, libera a memória alocada e libera o [IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85)) ponteiro de interface na classe.|
|[GetBlobHandling](#getblobhandling)|Recupera o BLOB de manipulação de valor para a linha atual.|
|[GetBlobSizeLimit](#getblobsizelimit)|Recupera o tamanho máximo do BLOB em bytes.|
|[GetBookmark](#getbookmark)|Recupera o indicador da linha atual.|
|[GetColumnCount](#getcolumncount)|Recupera o número de colunas no conjunto de linhas.|
|[GetColumnFlags](#getcolumnflags)|Recupera as características da coluna.|
|[GetColumnInfo](#getcolumninfo)|Recupera os metadados da coluna.|
|[GetColumnName](#getcolumnname)|Recupera o nome de uma coluna especificada.|
|[GetColumnType](#getcolumntype)|Recupera o tipo de dados de uma coluna especificada.|
|[GetLength](#getlength)|Recupera o tamanho máximo possível de uma coluna em bytes.|
|[GetOrdinal](#getordinal)|Recupera o índice de coluna recebe um nome de coluna.|
|[GetStatus](#getstatus)|Recupera o status de uma coluna especificada.|
|[GetValue](#getvalue)|Recupera os dados do buffer.|
|[SetBlobHandling](#setblobhandling)|Define o BLOB de manipulação de valor para a linha atual.|
|[SetBlobSizeLimit](#setblobsizelimit)|Define o tamanho máximo do BLOB em bytes.|
|[SetLength](#setlength)|Define o comprimento da coluna em bytes.|
|[SetStatus](#setstatus)|Define o status de uma coluna especificada.|
|[SetValue](#setvalue)|Armazena os dados no buffer.|

## <a name="remarks"></a>Comentários

Use `CDynamicAccessor` métodos para obter informações de coluna como nomes de coluna, contagem de colunas, tipo de dados e assim por diante. Você, em seguida, usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer que é criado e gerenciado por essa classe. Obter dados de buffer usando [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md).

Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).

## <a name="addbindentry"></a> CDynamicAccessor::AddBindEntry

Adiciona uma entrada de associação para as colunas de saída.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT AddBindEntry(const DBCOLUMNINFO& info) throw();
```

#### <a name="parameters"></a>Parâmetros

*info*<br/>
[in] Um `DBCOLUMNINFO` estrutura que contém informações de coluna. Consulte "Estruturas DBCOLUMNINFO" na [icolumnsinfo:: Getcolumninfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Use este método quando substituindo o acessador padrão criado com `CDynamicAccessor` (consulte [como faço para buscar dados?](../../data/oledb/fetching-data.md)).

## <a name="cdynamicaccessor"></a> Cdynamicaccessor:: Cdynamicaccessor

Cria uma instância e inicializa o `CDynamicAccessor` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CDynamicAccessor(DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,
   DBLENGTH nBlobSize = 8000);
```

#### <a name="parameters"></a>Parâmetros

*eBlobHandling*<br/>
Especifica como os dados de objeto binário grande (BLOB) deve ser tratada. O valor padrão é DBBLOBHANDLING_DEFAULT. Ver [SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição dos valores DBBLOBHANDLINGENUM.

*nBlobSize*<br/>
O tamanho máximo do BLOB em bytes. dados da coluna sobre esse valor são tratados como um BLOB. O valor padrão é de 8.000. Ver [SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.

### <a name="remarks"></a>Comentários

Se você usar o construtor para inicializar o `CDynamicAccessor` do objeto, você pode especificar como ele se associa os BLOBs. BLOBs podem conter dados binários, como o código de elementos gráficos, som ou compilada. O comportamento padrão é tratar mais de 8.000 bytes de colunas como BLOBs e tentar associá-las para um `ISequentialStream` objeto. No entanto, você pode especificar um valor diferente para ser o tamanho do BLOB.

Você também pode especificar como `CDynamicAccessor` lida com os dados de coluna que qualificam-se como dados de BLOB: pode lidar com dados BLOB da maneira padrão; ele pode ignorar (não associar) dados BLOB; ou ele pode associar dados BLOB na memória alocada pelo provedor.

## <a name="close"></a> Cdynamicaccessor:: Close

Desvincula todas as colunas, libera a memória alocada e libera o [IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85)) ponteiro de interface na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

## <a name="getblobhandling"></a> CDynamicAccessor::GetBlobHandling

Recupera o BLOB de manipulação de valor para a linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
const DBBLOBHANDLINGENUM GetBlobHandling() const;
```

### <a name="remarks"></a>Comentários

Retorna o valor de tratamento de BLOB *eBlobHandling* conforme definido por [SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md).

## <a name="getblobsizelimit"></a> CDynamicAccessor::GetBlobSizeLimit

Recupera o tamanho máximo do BLOB em bytes.

### <a name="syntax"></a>Sintaxe

```cpp
const DBLENGTH GetBlobSizeLimit() const;
```

### <a name="remarks"></a>Comentários

Retorna o valor de tratamento de BLOB *nBlobSize* conforme definido por [SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md).

## <a name="getbookmark"></a> CDynamicAccessor::GetBookmark

Recupera o indicador da linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetBookmark(CBookmark< >* pBookmark) const throw();
```

#### <a name="parameters"></a>Parâmetros

*pBookmark*<br/>
[out] Um ponteiro para o [CBookmark](../../data/oledb/cbookmark-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Você precisa definir `DBPROP_IRowsetLocate` como VARIANT_TRUE para recuperar um indicador.

## <a name="getcolumncount"></a> Cdynamicaccessor:: Getcolumncount

Recupera o número de colunas.

### <a name="syntax"></a>Sintaxe

```cpp
DBORDINAL GetColumnCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número de colunas recuperadas.

## <a name="getcolumnflags"></a> CDynamicAccessor::GetColumnFlags

Recupera as características da coluna.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetColumnFlags(DBORDINAL nColumn,
   DBCOLUMNFLAGS* pFlags) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pFlags*<br/>
[out] Um ponteiro para um bitmask que descreve as características da coluna. Consulte o "Tipo enumerado DBCOLUMNFLAGS" na [icolumnsinfo:: Getcolumninfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se as características de coluna são recuperadas com êxito. Caso contrário, retornará **falsos**.

### <a name="remarks"></a>Comentários

O número da coluna é deslocado de um. Coluna zero é um caso especial; é o indicador se disponível.

## <a name="getcolumninfo"></a> Cdynamicaccessor:: Getcolumninfo

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
[in] Um ponteiro para o [IRowset](/previous-versions/windows/desktop/ms720986(v=vs.85)) interface.

*pColumns*<br/>
[out] Um ponteiro de memória no qual retornar o número de colunas no conjunto de linhas; Esse número inclui a coluna de indicador, se houver um.

*ppColumnInfo*<br/>
[out] Um ponteiro de memória no qual retornar uma matriz de `DBCOLUMNINFO` estruturas. Consulte "Estruturas DBCOLUMNINFO" na [icolumnsinfo:: Getcolumninfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador do OLE DB*.

*ppStringsBuffer*<br/>
[out] Um ponteiro de memória no qual retornar um ponteiro para o armazenamento para todos os valores de cadeia de caracteres (nomes usados dentro *columnid* ou para *pwszName*) dentro de um único bloco de alocação.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Ver [icolumnsinfo:: Getcolumninfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador DB OLE* para obter informações sobre os tipos de dados `DBORDINAL`, `DBCOLUMNINFO`, e `OLECHAR`.

## <a name="getcolumnname"></a> CDynamicAccessor::GetColumnName

Recupera o nome da coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetColumnName(DBORDINAL nColumn) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

### <a name="return-value"></a>Valor de retorno

O nome da coluna especificada.

## <a name="getcolumntype"></a> Cdynamicaccessor:: Getcolumntype

Recupera o tipo de dados de uma coluna especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetColumnType(DBORDINAL nColumn,
   DBTYPE* pType) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pType*<br/>
[out] Um ponteiro para o tipo de dados da coluna especificada.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.

## <a name="getlength"></a> CDynamicAccessor::GetLength

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
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pLength*<br/>
[out] Um ponteiro para o inteiro que contém o comprimento da coluna em bytes.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se a coluna especificada for encontrada. Caso contrário, essa função retornará **falsos**.

### <a name="remarks"></a>Comentários

A primeira substituição usa o número da coluna e as substituições de segunda e terceira aceitar o nome da coluna no formato ANSI ou Unicode, respectivamente.

## <a name="getordinal"></a> CDynamicAccessor::GetOrdinal

Recupera o número de coluna recebe um nome de coluna.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetOrdinal(const CHAR* pColumnName,
   DBORDINAL* pOrdinal) const throw();

bool GetOrdinal(const WCHAR* pColumnName,
   DBORDINAL* pOrdinal) const throw();
```

#### <a name="parameters"></a>Parâmetros

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pOrdinal*<br/>
[out] Um ponteiro para o número da coluna.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se uma coluna com o nome especificado for encontrada. Caso contrário, essa função retornará **falsos**.

## <a name="getstatus"></a> CDynamicAccessor::GetStatus

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
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*pStatus*<br/>
[out] Um ponteiro para a variável que contém o status da coluna. Ver [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se a coluna especificada for encontrada. Caso contrário, essa função retornará **falsos**.

## <a name="getvalue"></a> CDynamicAccessor::GetValue

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
[in] Um parâmetro de modelo que lida com qualquer tipo de dados, exceto os tipos de cadeia de caracteres (`CHAR*`, `WCHAR*`), que requerem tratamento especial. `GetValue` usa o tipo de dados apropriado com base no que você especificar aqui.

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pColumnName*<br/>
[in] O nome da coluna.

*pData*<br/>
[out] O ponteiro para o conteúdo da coluna especificada.

### <a name="return-value"></a>Valor de retorno

Se você quiser passar dados de cadeia de caracteres, use as versões sem modelo `GetValue`. As versões sem modelo desse método de retorno `void*`, que aponta para a parte do buffer que contém os dados da coluna especificada. Retorna NULL se a coluna não for encontrada.

Para todos os outros tipos de dados, é mais simples de usar as versões com modelo `GetValue`. As versões de modelo retornam **verdadeira** em caso de sucesso ou **falso** em caso de falha.

### <a name="remarks"></a>Comentários

Use as versões sem modelo para retornar colunas que contêm cadeias de caracteres e as versões de modelo para colunas que contêm outros tipos de dados.

No modo de depuração, você obterá uma asserção se o tamanho de *pData* não for igual ao tamanho da coluna à qual ele aponta.

## <a name="setblobhandling"></a> CDynamicAccessor::SetBlobHandling

Define o BLOB de manipulação de valor para a linha atual.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetBlobHandling(DBBLOBHANDLINGENUM eBlobHandling);
```

#### <a name="parameters"></a>Parâmetros

*eBlobHandling*<br/>
Especifica como os dados de BLOB deve ser tratada. Ele pode usar os seguintes valores:

- DBBLOBHANDLING_DEFAULT: Lidar com dados de coluna maiores do que *nBlobSize* (conforme definido por `SetBlobSizeLimit`) como os dados do BLOB e recuperá-lo por meio de uma `ISequentialStream` ou `IStream` objeto. Esta opção tentará associar cada coluna que contém dados maiores que *nBlobSize* ou listados como DBTYPE_IUNKNOWN como dados BLOB.

- DBBLOBHANDLING_NOSTREAMS: Lidar com dados de coluna maiores *nBlobSize* (conforme definido por `SetBlobSizeLimit`) como os dados do BLOB e recuperá-lo por meio de referência na memória alocada pelo provedor, a propriedade do consumidor. Essa opção é útil para tabelas que têm mais de uma coluna BLOB e o provedor oferece suporte a apenas um `ISequentialStream` objeto por acessador.

- DBBLOBHANDLING_SKIP: Ignorar (não associar) colunas qualificadas como contendo BLOBs (o acessador não associar ou recuperar o valor da coluna, mas ainda irá recuperar o status da coluna e o comprimento).

### <a name="remarks"></a>Comentários

Você deve chamar `SetBlobHandling` antes de chamar `Open`.

O método de construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o BLOB de manipulação de valor a ser DBBLOBHANDLING_DEFAULT.

## <a name="setblobsizelimit"></a> CDynamicAccessor::SetBlobSizeLimit

Define o tamanho máximo do BLOB em bytes.

### <a name="syntax"></a>Sintaxe

```cpp
void SetBlobSizeLimit(DBLENGTH nBlobSize);
```

#### <a name="parameters"></a>Parâmetros

*nBlobSize*<br/>
Especifica o limite de tamanho do BLOB.

### <a name="remarks"></a>Comentários

Define o tamanho máximo do BLOB em bytes. dados de coluna maiores que esse valor são tratados como um BLOB. Alguns provedores oferecem tamanhos muito grandes para colunas (por exemplo, 2 GB). Em vez de tentar alocar memória para uma coluna desse tamanho, você normalmente tentaria associar essas colunas como BLOBs. Dessa forma, você não precisa alocar toda a memória, mas você ainda pode ler todos os dados sem medo de truncamento. No entanto, há alguns casos em que você talvez queira forçar `CDynamicAccessor` associar colunas grandes em seus tipos de dados nativos. Para fazer isso, chame `SetBlobSizeLimit` antes de chamar `Open`.

O método de construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o tamanho máximo do BLOB como um valor padrão de 8.000 bytes.

## <a name="setlength"></a> CDynamicAccessor::SetLength

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
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*nLength*<br/>
[in] O comprimento da coluna em bytes.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se o comprimento da coluna especificada for definido com êxito. Caso contrário, essa função retornará **falsos**.

## <a name="setstatus"></a> CDynamicAccessor::SetStatus

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
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*status*<br/>
[in] O status da coluna. Ver [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se o status de coluna especificada é definido com êxito. Caso contrário, essa função retornará **falsos**.

## <a name="setvalue"></a> CDynamicAccessor::SetValue

Armazena dados para uma coluna especificada.

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
[in] Um parâmetro de modelo que lida com qualquer tipo de dados, exceto os tipos de cadeia de caracteres (`CHAR*`, `WCHAR*`), que requerem tratamento especial. `GetValue` usa o tipo de dados apropriado com base no que você especificar aqui.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*data*<br/>
[in] O ponteiro para a memória que contém os dados.

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

### <a name="return-value"></a>Valor de retorno

Se você quiser definir os dados de cadeia de caracteres, use as versões sem modelo `GetValue`. As versões sem modelo desse método de retorno `void*`, que aponta para a parte do buffer que contém os dados da coluna especificada. Retorna NULL se a coluna não for encontrada.

Para todos os outros tipos de dados, é mais simples de usar as versões com modelo `GetValue`. As versões de modelo retornam **verdadeira** em caso de sucesso ou **falso** em caso de falha.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)