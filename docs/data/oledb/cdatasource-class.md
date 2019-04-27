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
- GetProperties
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
ms.openlocfilehash: 2564d4d9b0a2e5df1f575d6f2627ce80f48533c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62176077"
---
# <a name="cdatasource-class"></a>Classe CDataSource

Corresponde a um objeto de fonte de dados do OLE DB, que representa uma conexão por meio de um provedor para uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
class CDataSource
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fechar](#close)|Fecha a conexão.|
|[GetInitializationString](#getinitializationstring)|Recupera a cadeia de caracteres de inicialização da fonte de dados que está aberto no momento.|
|[GetProperties](#getproperties)|Obtém os valores de propriedades definidas no momento para a fonte de dados conectada.|
|[GetProperty](#getproperty)|Obtém o valor de uma única propriedade atualmente definida para a fonte de dados conectada.|
|[Abrir](#open)|Cria uma conexão a um provedor (fonte de dados) usando um `CLSID`, `ProgID`, ou um `CEnumerator` moniker fornecida pelo chamador.|
|[OpenFromFileName](#openfromfilename)|Abre uma fonte de dados de um arquivo especificado pelo nome do arquivo fornecido pelo usuário.|
|[OpenFromInitializationString](#openfrominitializationstring)|Abre a fonte de dados especificada por uma cadeia de caracteres de inicialização.|
|[OpenWithPromptFileName](#openwithpromptfilename)|Permite que o usuário selecione um arquivo de link de dados criada anteriormente para abrir a fonte de dados correspondente.|
|[OpenWithServiceComponents](#openwithservicecomponents)|Abre um objeto de fonte de dados usando a caixa de diálogo de conexão de dados.|

## <a name="remarks"></a>Comentários

Uma ou mais sessões do banco de dados podem ser criadas para uma única conexão. Essas sessões são representadas por `CSession`. Você deve chamar [cdatasource:: Open](../../data/oledb/cdatasource-open.md) para abrir a conexão antes de criar uma sessão com `CSession::Open`.

Para obter um exemplo de como usar `CDataSource`, consulte o [CatDB](../../overview/visual-cpp-samples.md) exemplo.

## <a name="close"></a> Cdatasource:: Close

Fecha a conexão, liberando o `m_spInit` ponteiro.

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

## <a name="getinitializationstring"></a> CDataSource::GetInitializationString

Recupera a cadeia de caracteres de inicialização de uma fonte de dados que está aberta no momento.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetInitializationString(BSTR* pInitializationString,
   bool bIncludePassword = false) throw();
```

#### <a name="parameters"></a>Parâmetros

*pInitializationString*<br/>
[out] Um ponteiro para a cadeia de caracteres de inicialização.

*bIncludePassword*<br/>
[in] **verdadeira** se a cadeia de caracteres inclui uma senha; caso contrário **falso**.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A cadeia de caracteres de inicialização resultante pode ser usada para mais tarde, reabrir esta conexão de fonte de dados.

## <a name="getproperties"></a> Cdatasource:: GetProperties

Retorna as informações de propriedade solicitadas para o objeto de fonte de dados conectada.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetProperties(ULONG ulPropIDSets,
   constDBPROPIDSET* pPropIDSet,
   ULONG* pulPropertySets,
   DBPROPSET** ppPropsets) const throw();
```

#### <a name="parameters"></a>Parâmetros

Ver [idbproperties:: GetProperties](/previous-versions/windows/desktop/ms714344(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter uma única propriedade, use [GetProperty](../../data/oledb/cdatasource-getproperty.md).

## <a name="getproperty"></a> Cdatasource:: GetProperty

Retorna o valor de uma propriedade especificada para o objeto de fonte de dados conectada.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetProperty(const GUID& guid,
   DBPROPID propid,
   VARIANT* pVariant) const throw();
```

#### <a name="parameters"></a>Parâmetros

*guid*<br/>
[in] Um GUID que identifica a propriedade definida para o qual retornar a propriedade.

*propid*<br/>
[in] ID da propriedade para a propriedade para retornar.

*pVariant*<br/>
[out] Um ponteiro para a variante onde `GetProperty` retorna o valor da propriedade.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter várias propriedades, use [GetProperties](../../data/oledb/cdatasource-getproperties.md).

## <a name="open"></a> Cdatasource:: Open

Abre uma conexão a uma fonte de dados usando um `CLSID`, `ProgID`, ou `CEnumerator` moniker ou solicita que o usuário com uma caixa de diálogo do localizador.

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

#### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O `CLSID` do provedor de dados.

*pPropSet*<br/>
[in] Um ponteiro para uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK.

*nPropertySets*<br/>
[in] O número de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas passada a *pPropSet* argumento.

*pName*<br/>
[in] O nome do banco de dados ao qual se conectar.

*pUserName*<br/>
[in] O nome do usuário.

*pPassword*<br/>
[in] A senha do usuário.

*nInitMode*<br/>
[in] Modo de inicialização do banco de dados. Ver [propriedades de inicialização](/previous-versions/windows/desktop/ms723127(v=vs.85))na *referência do programador DB OLE* no SDK do Windows para obter uma lista dos modos de inicialização válido. Se *nInitMode* é zero, nenhuma inicialização modo é incluído no conjunto de propriedades usado para abrir a conexão.

*szProgID*<br/>
[in] Um identificador de programa.

*enumerator*<br/>
[in] Um [CEnumerator](../../data/oledb/cenumerator-class.md) objeto usado para obter um identificador de origem para abrir a conexão quando o chamador não especificar um `CLSID`.

*hWnd*<br/>
[in] Identificador da janela que deve ser o pai da caixa de diálogo. Usando a sobrecarga de função que usa o *hWnd* parâmetro invocará automaticamente os componentes de serviço; Consulte comentários para obter detalhes.

*dwPromptOptions*<br/>
[in] Determina o estilo da caixa de diálogo do localizador para exibir. Consulte Msdasc.h para os valores possíveis.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A sobrecarga do método que usa o *hWnd* parâmetro abre um objeto de fonte de dados com os componentes de serviço no Oledb32,dll; essa DLL contém a implementação dos recursos de componentes de serviço como o pool de recursos, automático A inscrição de transação e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB programador em [ https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true ](https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).

As sobrecargas de método que não usam o *hWnd* parâmetro abrir um objeto de fonte de dados sem usar os componentes de serviço no Oledb32,dll. Um [CDataSource](../../data/oledb/cdatasource-class.md) objeto aberto com essas sobrecargas de função, será possível utilizar qualquer um da funcionalidade dos componentes de serviço.

### <a name="example"></a>Exemplo

O código a seguir mostra como abrir uma fonte de dados Jet 4.0 com modelos OLE DB. Você tratar a fonte de dados Jet como uma fonte de dados OLE DB. No entanto, sua chamada para `Open` precisa de dois conjuntos de propriedade: uma para DBPROPSET_DBINIT e outro para DBPROPSET_JETOLEDB_DBINIT, para que você possa definir DBPROP_JETOLEDB_DATABASEPASSWORD.

[!code-cpp[NVC_OLEDB_Consumer#7](../../data/oledb/codesnippet/cpp/cdatasource-open_1.cpp)]

## <a name="openfromfilename"></a> CDataSource::OpenFromFileName

Abre uma fonte de dados de um arquivo especificado pelo nome do arquivo fornecido pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenFromFileName(LPCOLESTR szFileName) throw();
```

#### <a name="parameters"></a>Parâmetros

*szFileName*<br/>
[in] O nome de um arquivo, normalmente, uma conexão de fonte de dados (. Arquivo UDL).

Para obter mais informações sobre arquivos de link de dados (arquivos. udl), consulte [visão geral da API de Link de dados](/previous-versions/windows/desktop/ms718102(v=vs.85)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32,dll; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, a inscrição automática de transação e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB programador em [ https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true ](https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).

## <a name="openfrominitializationstring"></a> CDataSource::OpenFromInitializationString

Abre uma fonte de dados especificada pela cadeia de caracteres de inicialização fornecida pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenFromInitializationString(LPCOLESTR szInitializationString,
   bool fPromptForInfo= false) throw();
```

#### <a name="parameters"></a>Parâmetros

*szInitializationString*<br/>
[in] A cadeia de caracteres de inicialização.

*fPromptForInfo*<br/>
[in] Se esse argumento for definido como **verdadeira**, em seguida, `OpenFromInitializationString` definirá a propriedade DBPROP_INIT_PROMPT para DBPROMPT_COMPLETEREQUIRED, que especifica que o usuário solicitado somente se precisar de mais informações. Isso é útil para situações em que a cadeia de caracteres de inicialização especifica um banco de dados que exige uma senha, mas a cadeia de caracteres não contém a senha. O usuário será solicitado para uma senha (ou qualquer outra informação ausente) ao tentar se conectar ao banco de dados.

O valor padrão é **falsos**, que especifica que o usuário nunca seja solicitados (conjuntos de DBPROP_INIT_PROMPT como DBPROMPT_NOPROMPT).

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32,dll; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, a inscrição automática de transação e assim por diante.

## <a name="openwithpromptfilename"></a> CDataSource::OpenWithPromptFileName

Este método solicita ao usuário uma caixa de diálogo, em seguida, abre uma fonte de dados usando o arquivo especificado pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenWithPromptFileName(HWND hWnd = GetActiveWindow(   ),
   DBPROMPTOPTIONS dwPromptOptions = DBPROMPTOPTIONS_NONE,
   LPCOLESTR szInitialDirectory = NULL) throw();
```

#### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] Identificador da janela que deve ser o pai da caixa de diálogo.

*dwPromptOptions*<br/>
[in] Determina o estilo da caixa de diálogo do localizador para exibir. Consulte Msdasc.h para os valores possíveis.

*szInitialDirectory*<br/>
[in] O diretório inicial para exibir na caixa de diálogo de localizador.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32,dll; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, a inscrição automática de transação e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB programador em [ https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true ](https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).

## <a name="openwithservicecomponents"></a> CDataSource::OpenWithServiceComponents

Abre um objeto de fonte de dados usando os componentes de serviço em Oledb32,dll.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenWithServiceComponents (const CLSID clsid,
   DBPROPSET* pPropset = NULL,
   ULONG ulPropSets = 1);

HRESULT OpenWithServiceComponents (LPCSTR szProgID,
   DBPROPSET* pPropset = NULL,
   ULONG ulPropSets = 1);
```

#### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O `CLSID` de um provedor de dados.

*szProgID*<br/>
[in] ID de um provedor de dados do programa.

*pPropset*<br/>
[in] Um ponteiro para uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK. Se o objeto de fonte de dados for inicializado, as propriedades devem pertencer ao grupo de propriedades de fonte de dados. Se a mesma propriedade for especificada mais de uma vez na *pPropset*, em seguida, o valor que é usado é específica do provedor. Se *ulPropSets* for zero, esse parâmetro será ignorado.

*ulPropSets*<br/>
[in] O número de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas passada a *pPropSet* argumento. Se isso for zero, o provedor ignora *pPropset*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32,dll; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, a inscrição automática de transação e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB programador em [ https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true ](https://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)