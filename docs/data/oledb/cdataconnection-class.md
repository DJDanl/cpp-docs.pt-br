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
ms.openlocfilehash: 94c7025185a24b07d5968157d49c856d4359b33a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62209276"
---
# <a name="cdataconnection-class"></a>Classe CDataConnection

Gerencia a conexão com a fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
class CDataConnection
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CDataConnection](#cdataconnection)|Construtor. Cria uma instância e inicializa um `CDataConnection` objeto.|
|[Copiar](#copy)|Cria uma cópia de uma conexão de dados existente.|
|[Abrir](#open)|Abre uma conexão a uma fonte de dados usando uma cadeia de caracteres de inicialização.|
|[OpenNewSession](#opennewsession)|Abre uma nova sessão em que a conexão atual.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador BOOL](#op_bool)|Determina se a sessão atual está aberta ou não.|
|[operator bool](#op_bool_ole)|Determina se a sessão atual está aberta ou não.|
|[operador CDataSource &](#op_cdata_amp)|Retorna uma referência ao independente `CDataSource` objeto.|
|[operador CDataSource *](#op_cdata_star)|Retorna um ponteiro para o independente `CDataSource` objeto.|
|[operador CSession &](#op_csession_amp)|Retorna uma referência ao independente `CSession` objeto.|
|[operador CSession *](#op_csession_star)|Retorna um ponteiro para o independente `CSession` objeto.|

## <a name="remarks"></a>Comentários

`CDataConnection` é uma classe útil para a criação de clientes porque ele encapsula os objetos necessários (fonte de dados e de sessão) e parte do trabalho que você precisa fazer ao se conectar a uma fonte de dados

Sem `CDataConnection`, você precisa criar um `CDataSource` de objeto, chame seu [OpenFromInitializationString](../../data/oledb/cdatasource-openfrominitializationstring.md) método, em seguida, crie uma instância de uma [CSession](../../data/oledb/csession-class.md) de objeto, chame seu [ Abra](../../data/oledb/csession-open.md) método, em seguida, crie um [CCommand](../../data/oledb/ccommand-class.md) objeto e chame seu `Open`* métodos.

Com `CDataConnection`, você só precisará criar um objeto de conexão, passá-lo em uma cadeia de caracteres de inicialização e, em seguida, usar essa conexão para abrir comandos. Se você planeja usar sua conexão ao banco de dados repetidamente, ela é uma boa ideia manter a conexão aberta, e `CDataConnection` fornece uma maneira conveniente de fazer isso.

> [!NOTE]
>  Se você estiver criando um aplicativo de banco de dados que precisa para lidar com várias sessões, você precisará usar [OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md).

## <a name="cdataconnection"></a> Cdataconnection:: Cdataconnection

Cria uma instância e inicializa um `CDataConnection` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection();
CDataConnection(const CDataConnection &ds);
```

#### <a name="parameters"></a>Parâmetros

*ds*<br/>
[in] Uma referência a uma conexão de dados existente.

### <a name="remarks"></a>Comentários

A primeira substituição cria um novo `CDataConnection` objeto com as configurações padrão.

A segunda substituição cria um novo `CDataConnection` objeto com as configurações equivalentes ao objeto de conexão de dados que você especificar.

## <a name="copy"></a> Cdataconnection:: Copy

Cria uma cópia de uma conexão de dados existente.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection& Copy(const CDataConnection & ds) throw();
```

#### <a name="parameters"></a>Parâmetros

*ds*<br/>
[in] Uma referência a uma conexão de dados existente para copiar.

## <a name="open"></a> Cdataconnection:: Open

Abre uma conexão a uma fonte de dados usando uma cadeia de caracteres de inicialização.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(LPCOLESTR szInitString) throw();
```

#### <a name="parameters"></a>Parâmetros

*szInitString*<br/>
[in] A cadeia de caracteres de inicialização da fonte de dados.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="opennewsession"></a> CDataConnection::OpenNewSession

Abre uma nova sessão usando a fonte de dados do objeto de conexão atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenNewSession(CSession & session) throw();
```

#### <a name="parameters"></a>Parâmetros

*session*<br/>
[entrada/saída] Uma referência ao novo objeto de sessão.

### <a name="remarks"></a>Comentários

A nova sessão usa o objeto de fonte de dados independente do objeto de conexão atual como seu pai e pode acessar todas as mesmas informações que a fonte de dados.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="op_bool"></a> Cdataconnection:: Operator BOOL

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator BOOL() throw();
```

### <a name="remarks"></a>Comentários

Retorna **BOOL** valor (typedef MFC). **TRUE** significa que a sessão atual está aberta. **Falsos** significa que a sessão atual está fechada.

## <a name="op_bool_ole"></a> Cdataconnection:: Operator bool (OLE DB)

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator bool() throw();
```

### <a name="remarks"></a>Comentários

Retorna um **bool** valor (tipo de dados do C++). **True** significa que a sessão atual está aberta. **falsos** significa que a sessão atual está fechada.

## <a name="op_cdata_amp"></a> Cdataconnection:: Operator CDataSource&amp;

Retorna uma referência ao independente `CDataSource` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource&() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna uma referência ao independente `CDataSource` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CDataSource` referência é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma função (como `func` abaixo) que usa um `CDataSource` referência, você pode usar `CDataSource&` para passar um `CDataConnection` do objeto em vez disso.

[!code-cpp[NVC_OLEDB_Consumer#3](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#4](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_2.cpp)]

## <a name="op_cdata_star"></a> Cdataconnection:: Operator CDataSource *

Retorna um ponteiro para o independente `CDataSource` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource*() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna um ponteiro para o independente `CDataSource` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CDataSource` ponteiro é esperado.

Ver [operador CDataSource &](../../data/oledb/cdataconnection-operator-cdatasource-amp.md) para obter um exemplo de uso.

## <a name="op_csession_amp"></a> Cdataconnection:: Operator CSession&amp;

Retorna uma referência ao independente `CSession` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession&();
```

### <a name="remarks"></a>Comentários

Esse operador retorna uma referência ao independente `CSession` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CSession` referência é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma função (como `func` abaixo) que usa um `CSession` referência, você pode usar `CSession&` para passar um `CDataConnection` do objeto em vez disso.

[!code-cpp[NVC_OLEDB_Consumer#5](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#6](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_2.cpp)]

## <a name="op_csession_star"></a> Cdataconnection:: Operator CSession *

Retorna um ponteiro para o independente `CSession` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession*() throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna um ponteiro para o independente `CSession` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CSession` ponteiro é esperado.

### <a name="example"></a>Exemplo

Ver [operador CSession &](../../data/oledb/cdataconnection-operator-csession-amp.md) para obter um exemplo de uso.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)