---
title: Classe CDataConnection
ms.date: 03/27/2019
f1_keywords:
- ATL::CDataConnection
- ATL.CDataConnection
- CDataConnection
- CDataConnection.CDataConnection
- ATL.CDataConnection.CDataConnection
- CDataConnection::CDataConnection
- ATL::CDataConnection::CDataConnection
- CDataConnection.Copy
- ATL.CDataConnection.Copy
- ATL::CDataConnection::Copy
- CDataConnection::Copy
- CDataConnection.Open
- ATL.CDataConnection.Open
- CDataConnection::Open
- ATL::CDataConnection::Open
- CDataConnection.OpenNewSession
- ATL.CDataConnection.OpenNewSession
- ATL::CDataConnection::OpenNewSession
- OpenNewSession
- CDataConnection::OpenNewSession
- CDataConnection::operatorBOOL
- ATL::CDataConnection::operatorBOOL
- CDataConnection.operatorBOOL
- ATL.CDataConnection.operatorBOOL
- CDataSource&
- CDataConnection.operatorCDataSource&
- operatorCDataSource&
- CDataConnection::operatorCDataSource&
- CDataSource*
- CDataConnection::operatorCDataSource*
- CDataConnection.operatorCDataSource*
- operatorCDataSource*
- CSession&
- CDataConnection::operatorCSession&
- CDataConnection.operatorCSession&
- operatorCSession&
- CDataConnection.operatorCSession*
- CDataConnection::operatorCSession*
- operatorCSession*
- CSession*
helpviewer_keywords:
- CDataConnection class
- CDataConnection class, constructor
- Copy method
- Open method
- OpenNewSession method
- BOOL operator
- operator bool
- BOOL operator
- operator bool
- CDataSource& operator
- operator & (CDataSource)
- CDataSource* operator
- operator * (CDataSource)
- operator CSession&
- CSession& operator
- operator CSession*
- CSession* operator
ms.assetid: 77432d85-4e20-49ec-a0b0-142137828471
ms.openlocfilehash: 385445081f84f65ff7030466a238a5a96abd63be
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212051"
---
# <a name="cdataconnection-class"></a>Classe CDataConnection

Gerencia a conexão com a fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
class CDataConnection
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CDataConnection](#cdataconnection)|Construtor. Cria uma instância e inicializa um objeto `CDataConnection`.|
|[Copy](#copy)|Cria uma cópia de uma conexão de dados existente.|
|[Abrir](#open)|Abre uma conexão com uma fonte de dados usando uma cadeia de inicialização.|
|[OpenNewSession](#opennewsession)|Abre uma nova sessão na conexão atual.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[BOOLIANo de operador](#op_bool)|Determina se a sessão atual está aberta ou não.|
|[operator bool](#op_bool_ole)|Determina se a sessão atual está aberta ou não.|
|[& do operador CDataSource](#op_cdata_amp)|Retorna uma referência ao objeto de `CDataSource` contido.|
|[CDataSource do operador *](#op_cdata_star)|Retorna um ponteiro para o objeto `CDataSource` contido.|
|[& do operador CSession](#op_csession_amp)|Retorna uma referência ao objeto de `CSession` contido.|
|[CSession do operador *](#op_csession_star)|Retorna um ponteiro para o objeto `CSession` contido.|

## <a name="remarks"></a>Comentários

`CDataConnection` é uma classe útil para criar clientes porque ele encapsula os objetos necessários (fonte de dados e sessão) e parte do trabalho que você precisa fazer ao se conectar a uma fonte de dados

Sem `CDataConnection`, você precisa criar um objeto `CDataSource`, chamar o método [OpenFromInitializationString](../../data/oledb/cdatasource-openfrominitializationstring.md) e, em seguida, criar uma instância de um objeto [CSession](../../data/oledb/csession-class.md) , chamar o método [Open](../../data/oledb/csession-open.md) e, em seguida, criar um objeto [CCommand](../../data/oledb/ccommand-class.md) e chamar seus métodos `Open`*.

Com `CDataConnection`, você só precisa criar um objeto de conexão, passá-lo como uma cadeia de inicialização e, em seguida, usar essa conexão para abrir comandos. Se você planeja usar a conexão com o banco de dados repetidamente, é uma boa ideia manter a conexão aberta e `CDataConnection` fornece uma maneira conveniente de fazer isso.

> [!NOTE]
>  Se você estiver criando um aplicativo de banco de dados que precisa lidar com várias sessões, será necessário usar o [OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md).

## <a name="cdataconnectioncdataconnection"></a><a name="cdataconnection"></a>CDataConnection::CDataConnection

Cria uma instância e inicializa um objeto `CDataConnection`.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection();
CDataConnection(const CDataConnection &ds);
```

#### <a name="parameters"></a>parâmetros

*AD*<br/>
no Uma referência a uma conexão de dados existente.

### <a name="remarks"></a>Comentários

A primeira substituição cria um novo objeto `CDataConnection` com as configurações padrão.

A segunda substituição cria um novo objeto `CDataConnection` com configurações equivalentes ao objeto de conexão de dados que você especificar.

## <a name="cdataconnectioncopy"></a><a name="copy"></a>CDataConnection:: copiar

Cria uma cópia de uma conexão de dados existente.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection& Copy(const CDataConnection & ds) throw();
```

#### <a name="parameters"></a>parâmetros

*AD*<br/>
no Uma referência a uma conexão de dados existente a ser copiada.

## <a name="cdataconnectionopen"></a><a name="open"></a>CDataConnection:: abrir

Abre uma conexão com uma fonte de dados usando uma cadeia de inicialização.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(LPCOLESTR szInitString) throw();
```

#### <a name="parameters"></a>parâmetros

*szInitString*<br/>
no A cadeia de inicialização da fonte de dados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cdataconnectionopennewsession"></a><a name="opennewsession"></a>CDataConnection::OpenNewSession

Abre uma nova sessão usando a fonte de dados do objeto de conexão atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenNewSession(CSession & session) throw();
```

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
[entrada/saída] Uma referência ao novo objeto de sessão.

### <a name="remarks"></a>Comentários

A nova sessão usa o objeto de fonte de dados independente do objeto de conexão atual como seu pai e pode acessar todas as mesmas informações que a fonte de dados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cdataconnectionoperator-bool"></a><a name="op_bool"></a>BOOLIANo de CDataConnection:: Operator

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator BOOL() throw();
```

### <a name="remarks"></a>Comentários

Retorna o valor de **bool** (MFC typedef). **Verdadeiro** significa que a sessão atual está aberta; **False** significa que a sessão atual está fechada.

## <a name="cdataconnectionoperator-bool-ole-db"></a><a name="op_bool_ole"></a>CDataConnection:: Operator bool (OLE DB)

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator bool() throw();
```

### <a name="remarks"></a>Comentários

Retorna um **bool** valor boolC++ (tipo de dados). **verdadeiro** significa que a sessão atual está aberta; **false** significa que a sessão atual está fechada.

## <a name="cdataconnectionoperator-cdatasourceamp"></a><a name="op_cdata_amp"></a>CDataConnection:: Operator CDataSource&amp;

Retorna uma referência ao objeto de `CDataSource` contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource&() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna uma referência ao objeto `CDataSource` contido, permitindo que você passe um objeto `CDataConnection` onde uma referência `CDataSource` é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma função (como `func` abaixo) que usa uma referência `CDataSource`, você poderá usar `CDataSource&` para passar um objeto `CDataConnection`.

[!code-cpp[NVC_OLEDB_Consumer#3](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#4](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_2.cpp)]

## <a name="cdataconnectionoperator-cdatasource"></a><a name="op_cdata_star"></a>CDataConnection:: Operator CDataSource *

Retorna um ponteiro para o objeto `CDataSource` contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource*() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna um ponteiro para o objeto `CDataSource` contido, permitindo que você passe um objeto `CDataConnection` onde um ponteiro `CDataSource` é esperado.

Consulte [Operator CDataSource &](../../data/oledb/cdataconnection-operator-cdatasource-amp.md) para obter um exemplo de uso.

## <a name="cdataconnectionoperator-csessionamp"></a><a name="op_csession_amp"></a>CDataConnection:: Operator CSession&amp;

Retorna uma referência ao objeto de `CSession` contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession&();
```

### <a name="remarks"></a>Comentários

Esse operador retorna uma referência ao objeto `CSession` contido, permitindo que você passe um objeto `CDataConnection` onde uma referência `CSession` é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma função (como `func` abaixo) que usa uma referência `CSession`, você poderá usar `CSession&` para passar um objeto `CDataConnection`.

[!code-cpp[NVC_OLEDB_Consumer#5](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#6](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_2.cpp)]

## <a name="cdataconnectionoperator-csession"></a><a name="op_csession_star"></a>CDataConnection:: Operator CSession *

Retorna um ponteiro para o objeto `CSession` contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession*() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna um ponteiro para o objeto `CSession` contido, permitindo que você passe um objeto `CDataConnection` onde um ponteiro `CSession` é esperado.

### <a name="example"></a>Exemplo

Consulte [Operator CSession &](../../data/oledb/cdataconnection-operator-csession-amp.md) para obter um exemplo de uso.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
