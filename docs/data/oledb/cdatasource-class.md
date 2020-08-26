---
title: Classe CDataSource
ms.date: 11/04/2016
f1_keywords:
- ATL.CDataSource
- ATL::CDataSource
- CDataSource
- ATL::CDataSource::Close
- ATL.CDataSource.Close
- CDataSource::Close
- CDataSource.Close
- ATL::CDataSource::GetInitializationString
- CDataSource.GetInitializationString
- GetInitializationString
- CDataSource::GetInitializationString
- ATL.CDataSource.GetInitializationString
- CDataSource::GetProperties
- ATL.CDataSource.GetProperties
- CDataSource.GetProperties
- ATL::CDataSource::GetProperties
- ATL::CDataSource::GetProperty
- ATL.CDataSource.GetProperty
- CDataSource.GetProperty
- CDataSource::GetProperty
- ATL::CDataSource::Open
- ATL.CDataSource.Open
- CDataSource::Open
- CDataSource.Open
- CDataSource::OpenFromFileName
- ATL::CDataSource::OpenFromFileName
- OpenFromFileName
- CDataSource.OpenFromFileName
- ATL.CDataSource.OpenFromFileName
- CDataSource.OpenFromInitializationString
- OpenFromInitializationString
- CDataSource::OpenFromInitializationString
- ATL::CDataSource::OpenFromInitializationString
- ATL.CDataSource.OpenFromInitializationString
- CDataSource.OpenWithPromptFileName
- OpenWithPromptFileName
- ATL::CDataSource::OpenWithPromptFileName
- ATL.CDataSource.OpenWithPromptFileName
- CDataSource::OpenWithPromptFileName
- CDataSource::OpenWithServiceComponents
- OpenWithServiceComponents
- CDataSource.OpenWithServiceComponents
helpviewer_keywords:
- CDataSource class
- Close method
- GetInitializationString method
- GetProperties method
- GetProperty method
- Open method
- OpenFromFileName method
- OpenFromInitializationString method
- OpenWithPromptFileName method
- OpenWithServiceComponents method
ms.assetid: 99bf862c-9d5c-4117-9501-aa0e2672085c
ms.openlocfilehash: 2ce5090d7e1c74607a82ddbb79afebe185a1dca7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838341"
---
# <a name="cdatasource-class"></a>Classe CDataSource

Corresponde a um objeto de fonte de dados OLE DB, que representa uma conexão por meio de um provedor para uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
class CDataSource
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[Fechar](#close)|Encerra a conexão.|
|[Getinicializastring](#getinitializationstring)|Recupera a cadeia de caracteres de inicialização da fonte de dados que está aberta no momento.|
|[GetProperties](#getproperties)|Obtém os valores das propriedades atualmente definidas para a fonte de dados conectada.|
|[GetProperty](#getproperty)|Obtém o valor de uma única propriedade definida atualmente para a fonte de dados conectada.|
|[Abrir](#open)|Cria uma conexão com um provedor (fonte de dados) usando um `CLSID` `ProgID` moniker, ou um `CEnumerator` identificador de origem fornecido pelo chamador.|
|[OpenFromFileName](#openfromfilename)|Abre uma fonte de dados de um arquivo especificado pelo nome de arquivo fornecido pelo usuário.|
|[OpenFromInitializationString](#openfrominitializationstring)|Abre a fonte de dados especificada por uma cadeia de caracteres de inicialização.|
|[OpenWithPromptFileName](#openwithpromptfilename)|Permite que o usuário selecione um arquivo de link de dados criado anteriormente para abrir a fonte de dados correspondente.|
|[OpenWithServiceComponents](#openwithservicecomponents)|Abre um objeto de fonte de dados usando a caixa de diálogo link de dados.|

## <a name="remarks"></a>Comentários

Uma ou mais sessões de banco de dados podem ser criadas para uma única conexão. Essas sessões são representadas por `CSession` . Você deve chamar [CDataSource:: Open](../../data/oledb/cdatasource-open.md) para abrir a conexão antes de criar uma sessão com `CSession::Open` .

Para obter um exemplo de como usar `CDataSource` o, consulte o exemplo [CatDB](../../overview/visual-cpp-samples.md) .

## <a name="cdatasourceclose"></a><a name="close"></a> CDataSource:: fechar

Fecha a conexão liberando o `m_spInit` ponteiro.

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

## <a name="cdatasourcegetinitializationstring"></a><a name="getinitializationstring"></a> CDataSource:: getinicializastring

Recupera a cadeia de inicialização de uma fonte de dados aberta no momento.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetInitializationString(BSTR* pInitializationString,
   bool bIncludePassword = false) throw();
```

#### <a name="parameters"></a>parâmetros

*pInitializationString*<br/>
fora Um ponteiro para a cadeia de inicialização.

*bIncludePassword*<br/>
[in] **`true`** se a cadeia de caracteres incluir uma senha; caso contrário **`false`** .

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A cadeia de inicialização resultante pode ser usada para reabrir essa conexão de fonte de dados posteriormente.

## <a name="cdatasourcegetproperties"></a><a name="getproperties"></a> CDataSource:: GetProperties

Retorna as informações de propriedade solicitadas para o objeto de fonte de dados conectada.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetProperties(ULONG ulPropIDSets,
   constDBPROPIDSET* pPropIDSet,
   ULONG* pulPropertySets,
   DBPROPSET** ppPropsets) const throw();
```

#### <a name="parameters"></a>parâmetros

Consulte [IDBProperties:: GetProperties](/previous-versions/windows/desktop/ms714344(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter uma única propriedade, use [GetProperty](../../data/oledb/cdatasource-getproperty.md).

## <a name="cdatasourcegetproperty"></a><a name="getproperty"></a> CDataSource:: GetProperty

Retorna o valor de uma propriedade especificada para o objeto de fonte de dados conectada.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetProperty(const GUID& guid,
   DBPROPID propid,
   VARIANT* pVariant) const throw();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID que identifica o conjunto de propriedades para o qual retornar a propriedade.

*propid*<br/>
no A ID da propriedade a ser retornada.

*pVariant*<br/>
fora Um ponteiro para a variante em que `GetProperty` retorna o valor da propriedade.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter várias propriedades, use [GetProperties](../../data/oledb/cdatasource-getproperties.md).

## <a name="cdatasourceopen"></a><a name="open"></a> CDataSource:: abrir

Abre uma conexão com uma fonte de dados usando `CLSID` um `ProgID` moniker, ou ou `CEnumerator` solicita ao usuário uma caixa de diálogo do localizador.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CLSID& clsid,
   DBPROPSET* pPropSet = NULL,
   ULONG nPropertySets = 1) throw();

HRESULT Open(const CLSID& clsid,
   LPCTSTR pName,
   LPCTSTR pUserName = NULL,
   LPCTSTR pPassword = NULL,
   long nInitMode = 0) throw();HRESULT Open(LPCTSTR szProgID,
   DBPROPSET* pPropSet = NULL,
   ULONG nPropertySets = 1) throw();HRESULT Open(LPCTSTR szProgID,
   LPCTSTR pName,  LPCTSTR pUserName = NULL,
   LPCTSTR pPassword = NULL,
   long nInitMode = 0) throw();

HRESULT Open(const CEnumerator& enumerator,
   DBPROPSET* pPropSet = NULL,
   ULONG nPropertySets = 1) throw();

HRESULT Open(const CEnumerator& enumerator,
   LPCTSTR pName,
   LPCTSTR pUserName = NULL,
   LPCTSTR pPassword = NULL,
   long nInitMode = 0) throw();

HRESULT Open(HWND hWnd = GetActiveWindow(),
   DBPROMPTOPTIONS dwPromptOptions = DBPROMPTOPTIONS_WIZARDSHEET) throw();

HRESULT Open(LPCWSTR szProgID,
   DBPROPSET* pPropSet = NULL,
   ULONG nPropertySets = 1) throw();

HRESULT Open(LPCSTR szProgID,
   LPCTSTR pName,LPCTSTR pUserName = NULL,
   LPCTSTR pPassword = NULL,
   long nInitMode = 0) throw();
```

#### <a name="parameters"></a>parâmetros

*clsid*<br/>
no O `CLSID` do provedor de dados.

*pPropSet*<br/>
no Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que contém propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

*nPropertySets*<br/>
no O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passadas no argumento *pPropSet* .

*pName*<br/>
no O nome do banco de dados ao qual se conectar.

*pUserName*<br/>
no O nome do usuário.

*pPassword*<br/>
no A senha do usuário.

*nInitMode*<br/>
no Modo de inicialização do banco de dados. Consulte [Propriedades de inicialização](/previous-versions/windows/desktop/ms723127(v=vs.85))na *referência do programador de OLE DB* no SDK do Windows para obter uma lista de modos de inicialização válidos. Se *nInitMode* for zero, nenhum modo de inicialização será incluído no conjunto de propriedades usado para abrir a conexão.

*szProgID*<br/>
no Um identificador de programa.

*enumera*<br/>
no Um objeto [CEnumerator](../../data/oledb/cenumerator-class.md) usado para obter um moniker para abrir a conexão quando o chamador não especifica um `CLSID` .

*hWnd*<br/>
no Manipule a janela que será o pai da caixa de diálogo. Usar a sobrecarga de função que usa o parâmetro *HWND* invocará automaticamente os componentes de serviço; consulte comentários para obter detalhes.

*dwPromptOptions*<br/>
no Determina o estilo da caixa de diálogo do localizador a ser exibida. Consulte Msdasc. h para obter os valores possíveis.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A sobrecarga do método que usa o parâmetro *HWND* abre um objeto de fonte de dados com os componentes de serviço no oledb32.dll; Essa DLL contém a implementação de recursos de componentes de serviço, como pool de recursos, inscrição automática de transações e assim por diante. Para obter mais informações, consulte a referência de OLE DB no [Guia do programador de OLE DB](/previous-versions/windows/desktop/ms713643(v=vs.85)).

As sobrecargas de método que não usam o parâmetro *HWND* abrem um objeto de fonte de dados sem usar os componentes de serviço no oledb32.dll. Um objeto [CDataSource](../../data/oledb/cdatasource-class.md) aberto com essas sobrecargas de função não poderá utilizar nenhuma das funcionalidades dos componentes de serviço.

### <a name="example"></a>Exemplo

O código a seguir mostra como abrir uma fonte de dados do Jet 4,0 com modelos de OLE DB. Você trata a fonte de dados Jet como uma fonte de dados OLE DB. No entanto, sua chamada para `Open` precisa de dois conjuntos de propriedades: um para DBPROPSET_DBINIT e o outro para DBPROPSET_JETOLEDB_DBINIT, para que você possa definir DBPROP_JETOLEDB_DATABASEPASSWORD.

[!code-cpp[NVC_OLEDB_Consumer#7](../../data/oledb/codesnippet/cpp/cdatasource-open_1.cpp)]

## <a name="cdatasourceopenfromfilename"></a><a name="openfromfilename"></a> CDataSource::OpenFromFileName

Abre uma fonte de dados de um arquivo especificado pelo nome de arquivo fornecido pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenFromFileName(LPCOLESTR szFileName) throw();
```

#### <a name="parameters"></a>parâmetros

*szFileName*<br/>
no O nome de um arquivo, geralmente uma conexão de fonte de dados (. UDL).

Para obter mais informações sobre arquivos de link de dados (arquivos. udl), consulte [visão geral da API de link de dados](/previous-versions/windows/desktop/ms718102(v=vs.85)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método abre um objeto de fonte de dados usando os componentes de serviço no oledb32.dll; Essa DLL contém a implementação de recursos de componentes de serviço, como pool de recursos, inscrição automática de transações e assim por diante. Para obter mais informações, consulte a referência de OLE DB no [Guia do programador de OLE DB](/previous-versions/windows/desktop/ms713643(v=vs.85)).

## <a name="cdatasourceopenfrominitializationstring"></a><a name="openfrominitializationstring"></a> CDataSource::OpenFromInitializationString

Abre uma fonte de dados especificada pela cadeia de inicialização fornecida pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenFromInitializationString(LPCOLESTR szInitializationString,
   bool fPromptForInfo= false) throw();
```

#### <a name="parameters"></a>parâmetros

*szInitializationString*<br/>
no A cadeia de inicialização.

*fPromptForInfo*<br/>
no Se esse argumento for definido como **`true`** , `OpenFromInitializationString` o definirá a propriedade DBPROP_INIT_PROMPT como DBPROMPT_COMPLETEREQUIRED, que especifica que o usuário será solicitado somente se mais informações forem necessárias. Isso é útil para situações em que a cadeia de inicialização especifica um banco de dados que requer uma senha, mas a cadeia de caracteres não contém a senha. O usuário será solicitado a fornecer uma senha (ou qualquer outra informação ausente) ao tentar se conectar ao banco de dados.

O valor padrão é **`false`** , que especifica que o usuário nunca será solicitado (define DBPROP_INIT_PROMPT como DBPROMPT_NOPROMPT).

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método abre um objeto de fonte de dados usando os componentes de serviço no oledb32.dll; Essa DLL contém a implementação de recursos de componentes de serviço, como pool de recursos, inscrição automática de transações e assim por diante.

## <a name="cdatasourceopenwithpromptfilename"></a><a name="openwithpromptfilename"></a> CDataSource::OpenWithPromptFileName

Esse método solicita ao usuário uma caixa de diálogo e, em seguida, abre uma fonte de dados usando o arquivo especificado pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenWithPromptFileName(HWND hWnd = GetActiveWindow(   ),
   DBPROMPTOPTIONS dwPromptOptions = DBPROMPTOPTIONS_NONE,
   LPCOLESTR szInitialDirectory = NULL) throw();
```

#### <a name="parameters"></a>parâmetros

*hWnd*<br/>
no Manipule a janela que será o pai da caixa de diálogo.

*dwPromptOptions*<br/>
no Determina o estilo da caixa de diálogo do localizador a ser exibida. Consulte Msdasc. h para obter os valores possíveis.

*szInitialDirectory*<br/>
no O diretório inicial a ser exibido na caixa de diálogo localizador.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método abre um objeto de fonte de dados usando os componentes de serviço no oledb32.dll; Essa DLL contém a implementação de recursos de componentes de serviço, como pool de recursos, inscrição automática de transações e assim por diante. Para obter mais informações, consulte a referência de OLE DB no [Guia do programador de OLE DB](/previous-versions/windows/desktop/ms713643(v=vs.85)).

## <a name="cdatasourceopenwithservicecomponents"></a><a name="openwithservicecomponents"></a> CDataSource::OpenWithServiceComponents

Abre um objeto de fonte de dados usando os componentes de serviço no oledb32.dll.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenWithServiceComponents (const CLSID clsid,
   DBPROPSET* pPropset = NULL,
   ULONG ulPropSets = 1);

HRESULT OpenWithServiceComponents (LPCSTR szProgID,
   DBPROPSET* pPropset = NULL,
   ULONG ulPropSets = 1);
```

#### <a name="parameters"></a>parâmetros

*clsid*<br/>
no O `CLSID` de um provedor de dados.

*szProgID*<br/>
no ID do programa de um provedor de dados.

*pPropset*<br/>
no Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que contém propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows. Se o objeto de fonte de dados for inicializado, as propriedades deverão pertencer ao grupo de propriedades fonte de dados. Se a mesma propriedade for especificada mais de uma vez em *pPropSet*, o valor usado será específico do provedor. Se *ulPropSets* for zero, esse parâmetro será ignorado.

*ulPropSets*<br/>
no O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passadas no argumento *pPropSet* . Se isso for zero, o provedor ignorará *pPropSet*.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método abre um objeto de fonte de dados usando os componentes de serviço no oledb32.dll; Essa DLL contém a implementação de recursos de componentes de serviço, como pool de recursos, inscrição automática de transações e assim por diante. Para obter mais informações, consulte a referência de OLE DB no [Guia do programador de OLE DB](/previous-versions/windows/desktop/ms713643(v=vs.85)).

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
