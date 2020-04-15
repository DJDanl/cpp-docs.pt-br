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
ms.openlocfilehash: fe954e218a099fa7956748904a4baa89f741c52f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368611"
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
|[Cdataconnection](#cdataconnection)|Construtor. Instancia e inicializa `CDataConnection` um objeto.|
|[Cópia](#copy)|Cria uma cópia de uma conexão de dados existente.|
|[Abrir](#open)|Abre uma conexão a uma fonte de dados usando uma seqüência de inicialização.|
|[OpenNewSession](#opennewsession)|Abre uma nova sessão sobre a conexão atual.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador BOOL](#op_bool)|Determina se a sessão atual está aberta ou não.|
|[operador bool](#op_bool_ole)|Determina se a sessão atual está aberta ou não.|
|[operador CDataSource&](#op_cdata_amp)|Retorna uma referência `CDataSource` ao objeto contido.|
|[operador CDataSource*](#op_cdata_star)|Retorna um ponteiro `CDataSource` para o objeto contido.|
|[operador CSession&](#op_csession_amp)|Retorna uma referência `CSession` ao objeto contido.|
|[Operador CSession*](#op_csession_star)|Retorna um ponteiro `CSession` para o objeto contido.|

## <a name="remarks"></a>Comentários

`CDataConnection`é uma classe útil para criar clientes porque encapsula objetos necessários (fonte de dados e sessão) e alguns dos trabalhos que você precisa fazer ao se conectar a uma fonte de dados

Sem `CDataConnection`, você `CDataSource` tem que criar um objeto, chamar o método [OpenFromInitializationString](../../data/oledb/cdatasource-openfrominitializationstring.md) e, em seguida, criar uma `Open`instância de um objeto [CSession,](../../data/oledb/csession-class.md) chamar seu método [Aberto](../../data/oledb/csession-open.md) e, em seguida, criar um objeto [CCommand](../../data/oledb/ccommand-class.md) e chamar seus métodos * .

Com `CDataConnection`, você só precisa criar um objeto de conexão, passar-lhe uma seqüência de inicialização e, em seguida, usar essa conexão para abrir comandos. Se você planeja usar sua conexão com o banco de dados repetidamente, é uma boa ideia manter a conexão aberta, e `CDataConnection` fornece uma maneira conveniente de fazer isso.

> [!NOTE]
> Se você estiver criando um aplicativo de banco de dados que precisa lidar com várias sessões, você precisará usar [o OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md).

## <a name="cdataconnectioncdataconnection"></a><a name="cdataconnection"></a>Conexão CData::Conexão CData

Instancia e inicializa `CDataConnection` um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection();
CDataConnection(const CDataConnection &ds);
```

#### <a name="parameters"></a>Parâmetros

*Ds*<br/>
[em] Uma referência a uma conexão de dados existente.

### <a name="remarks"></a>Comentários

A primeira substituição cria `CDataConnection` um novo objeto com configurações padrão.

A segunda substituição cria `CDataConnection` um novo objeto com configurações equivalentes ao objeto de conexão de dados especificado.

## <a name="cdataconnectioncopy"></a><a name="copy"></a>Conexão CData::Copiar

Cria uma cópia de uma conexão de dados existente.

### <a name="syntax"></a>Sintaxe

```cpp
CDataConnection& Copy(const CDataConnection & ds) throw();
```

#### <a name="parameters"></a>Parâmetros

*Ds*<br/>
[em] Uma referência a uma conexão de dados existente para copiar.

## <a name="cdataconnectionopen"></a><a name="open"></a>Conexão CData::Abrir

Abre uma conexão a uma fonte de dados usando uma seqüência de inicialização.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(LPCOLESTR szInitString) throw();
```

#### <a name="parameters"></a>Parâmetros

*szInitString*<br/>
[em] A seqüência de inicialização da fonte de dados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cdataconnectionopennewsession"></a><a name="opennewsession"></a>CDataConnection::OpenNewSession

Abre uma nova sessão usando a fonte de dados do objeto de conexão atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenNewSession(CSession & session) throw();
```

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[dentro/fora] Uma referência ao novo objeto de sessão.

### <a name="remarks"></a>Comentários

A nova sessão usa o objeto de origem de dados contido do objeto de conexão atual como seu pai e pode acessar todas as mesmas informações que a fonte de dados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cdataconnectionoperator-bool"></a><a name="op_bool"></a>CDataConnection::operator BOOL

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator BOOL() throw();
```

### <a name="remarks"></a>Comentários

Retorna o valor **bool** (tipo MFC). **TRUE** significa que a sessão atual está aberta; **FALSE** significa que a sessão atual está fechada.

## <a name="cdataconnectionoperator-bool-ole-db"></a><a name="op_bool_ole"></a>CDataConnection::operator bool (OLE DB)

Determina se a sessão atual está aberta ou não.

### <a name="syntax"></a>Sintaxe

```cpp
operator bool() throw();
```

### <a name="remarks"></a>Comentários

Retorna um valor **bool** (tipo de dados C++). **verdade** significa que a sessão atual está aberta; **falso** significa que a sessão atual está fechada.

## <a name="cdataconnectionoperator-cdatasourceamp"></a><a name="op_cdata_amp"></a>CDataConnection::operador CDataSource&amp;

Retorna uma referência `CDataSource` ao objeto contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource&() throw();
```

### <a name="remarks"></a>Comentários

Este operador retorna uma `CDataSource` referência ao objeto contido, permitindo que você passe um `CDataConnection` objeto onde uma `CDataSource` referência é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma `func` função (como `CDataSource` abaixo) que `CDataSource&` toma uma `CDataConnection` referência, você pode usar para passar um objeto em vez disso.

[!code-cpp[NVC_OLEDB_Consumer#3](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#4](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_2.cpp)]

## <a name="cdataconnectionoperator-cdatasource"></a><a name="op_cdata_star"></a>CDataConnection::operador CDataSource*

Retorna um ponteiro `CDataSource` para o objeto contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CDataSource*() throw();
```

### <a name="remarks"></a>Comentários

Este operador retorna um `CDataSource` ponteiro para o objeto `CDataConnection` contido, `CDataSource` permitindo que você passe um objeto onde um ponteiro é esperado.

Consulte [o operador CDataSource&](../../data/oledb/cdataconnection-operator-cdatasource-amp.md) para obter um exemplo de uso.

## <a name="cdataconnectionoperator-csessionamp"></a><a name="op_csession_amp"></a>CDataConnection::operador CSession&amp;

Retorna uma referência `CSession` ao objeto contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession&();
```

### <a name="remarks"></a>Comentários

Este operador retorna uma `CSession` referência ao objeto contido, permitindo que você passe um `CDataConnection` objeto onde uma `CSession` referência é esperada.

### <a name="example"></a>Exemplo

Se você tiver uma `func` função (como `CSession` abaixo) que `CSession&` toma uma `CDataConnection` referência, você pode usar para passar um objeto em vez disso.

[!code-cpp[NVC_OLEDB_Consumer#5](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_1.cpp)]

[!code-cpp[NVC_OLEDB_Consumer#6](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_2.cpp)]

## <a name="cdataconnectionoperator-csession"></a><a name="op_csession_star"></a>CDataConnection::operator CSession*

Retorna um ponteiro `CSession` para o objeto contido.

### <a name="syntax"></a>Sintaxe

```cpp
operator const CSession*() throw();
```

### <a name="remarks"></a>Comentários

Este operador retorna um `CSession` ponteiro para o objeto `CDataConnection` contido, `CSession` permitindo que você passe um objeto onde um ponteiro é esperado.

### <a name="example"></a>Exemplo

Consulte [o operador CSession&](../../data/oledb/cdataconnection-operator-csession-amp.md) para obter um exemplo de uso.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
