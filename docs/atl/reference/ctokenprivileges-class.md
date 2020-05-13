---
title: Classe CTokenPrivileges
ms.date: 11/04/2016
f1_keywords:
- CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges::CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges::Add
- ATLSECURITY/ATL::CTokenPrivileges::Delete
- ATLSECURITY/ATL::CTokenPrivileges::DeleteAll
- ATLSECURITY/ATL::CTokenPrivileges::GetCount
- ATLSECURITY/ATL::CTokenPrivileges::GetDisplayNames
- ATLSECURITY/ATL::CTokenPrivileges::GetLength
- ATLSECURITY/ATL::CTokenPrivileges::GetLuidsAndAttributes
- ATLSECURITY/ATL::CTokenPrivileges::GetNamesAndAttributes
- ATLSECURITY/ATL::CTokenPrivileges::GetPTOKEN_PRIVILEGES
- ATLSECURITY/ATL::CTokenPrivileges::LookupPrivilege
helpviewer_keywords:
- CTokenPrivileges class
ms.assetid: 89590105-f001-4014-870d-142926091231
ms.openlocfilehash: 75c09f723860540aa54cf3744cde7e61d9202f79
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747355"
---
# <a name="ctokenprivileges-class"></a>Classe CTokenPrivileges

Esta aula é um `TOKEN_PRIVILEGES` invólucro para a estrutura.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CTokenPrivileges
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::CTokenPrivileges](#ctokenprivileges)|O construtor.|
|[CTokenPrivileges::~CTokenPrivileges](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::Adicionar](#add)|Adiciona um ou mais `CTokenPrivileges` privilégios ao objeto.|
|[CTokenPrivileges::Delete](#delete)|Exclui um privilégio `CTokenPrivileges` do objeto.|
|[CTokenPrivileges::DeleteAll](#deleteall)|Exclui todos os privilégios do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetCount](#getcount)|Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetDisplayNames](#getdisplaynames)|Recupera nomes de exibição para `CTokenPrivileges` os privilégios contidos no objeto.|
|[CTokenPrivileges::GetLength](#getlength)|Retorna o tamanho do buffer em `TOKEN_PRIVILEGES` bytes `CTokenPrivileges` necessários para segurar a estrutura representada pelo objeto.|
|[CTokenPrivileges::GetLuidsAndAttributes](#getluidsandattributes)|Recupera os identificadores localmente únicos (LUIDs) `CTokenPrivileges` e atributo soa bandeiras do objeto.|
|[CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes)|Recupera os nomes de privilégios `CTokenPrivileges` e as bandeiras de atributo do objeto.|
|[CTokenPrivileges::GetPTOKEN_PRIVILEGES](#getptoken_privileges)|Devolve um ponteiro `TOKEN_PRIVILEGES` para a estrutura.|
|[CTokenPrivileges::LookupPrivilege](#lookupprivilege)|Recupera o atributo associado a um nome de privilégio dado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::TOKEN_PRIVILEGES de const do operador *](#operator_const_token_privileges__star)|Lança um valor para um `TOKEN_PRIVILEGES` ponteiro para a estrutura.|
|[CTokenPrivileges::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou segmento e é alocado para cada usuário conectado em um sistema Windows.

O token de acesso é usado para descrever os vários privilégios de segurança concedidos a cada usuário. Um privilégio consiste em um número de 64 bits chamado identificador localmente único [(LUID)](/windows/win32/api/winnt/ns-winnt-luid)e uma seqüência de descritores.

A `CTokenPrivileges` classe é um invólucro para a estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) e contém 0 ou mais privilégios. Os privilégios podem ser adicionados, excluídos ou consultados usando os métodos de classe fornecidos.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="ctokenprivilegesadd"></a><a name="add"></a>CTokenPrivileges::Adicionar

Adiciona um ou mais `CTokenPrivileges` privilégios ao objeto token de acesso.

```
bool Add(LPCTSTR pszPrivilege, bool bEnable) throw(...);
void Add(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Pointer para uma seqüência de seqüência de terminadas nula que especifica o nome do privilégio, conforme definido no WINNT. Arquivo h cabeçalho.

*Benable*<br/>
Se for verdade, o privilégio está habilitado. Se for falso, o privilégio é desativado.

*rPrivileges*<br/>
Referência a uma estrutura [TOKEN_PRIVILEGES.](/windows/win32/api/winnt/ns-winnt-token_privileges) Os privilégios e atributos são copiados `CTokenPrivileges` desta estrutura e adicionados ao objeto.

### <a name="return-value"></a>Valor retornado

A primeira forma deste método retorna verdadeira se os privilégios forem adicionados com sucesso, falso sem outra forma.

## <a name="ctokenprivilegesctokenprivileges"></a><a name="ctokenprivileges"></a>CTokenPrivileges::CTokenPrivileges

O construtor.

```
CTokenPrivileges() throw();
CTokenPrivileges(const CTokenPrivileges& rhs) throw(... );
CTokenPrivileges(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenPrivileges` objeto a atribuir ao novo objeto.

*rPrivileges*<br/>
A [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) estrutura para atribuir `CTokenPrivileges` ao novo objeto.

### <a name="remarks"></a>Comentários

O `CTokenPrivileges` objeto pode ser criado `TOKEN_PRIVILEGES` opcionalmente usando uma `CTokenPrivileges` estrutura ou um objeto previamente definido.

## <a name="ctokenprivilegesctokenprivileges"></a><a name="dtor"></a>CTokenPrivileges::~CTokenPrivileges

O destruidor.

```
virtual ~CTokenPrivileges() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

## <a name="ctokenprivilegesdelete"></a><a name="delete"></a>CTokenPrivileges::Delete

Exclui um privilégio `CTokenPrivileges` do objeto token de acesso.

```
bool Delete(LPCTSTR pszPrivilege) throw();
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Pointer para uma seqüência de seqüência de terminadas nula que especifica o nome do privilégio, conforme definido no WINNT. Arquivo h cabeçalho. Por exemplo, esse parâmetro poderia especificar o SE_SECURITY_NAME constante ou sua seqüência correspondente, "SeSecurityPrivilege".

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o privilégio foi excluído com sucesso, falso de outra forma.

### <a name="remarks"></a>Comentários

Este método é útil como uma ferramenta para criar tokens restritos.

## <a name="ctokenprivilegesdeleteall"></a><a name="deleteall"></a>CTokenPrivileges::DeleteAll

Exclui todos os privilégios do `CTokenPrivileges` objeto token de acesso.

```cpp
void DeleteAll() throw();
```

### <a name="remarks"></a>Comentários

Exclui todos os privilégios `CTokenPrivileges` contidos no objeto token de acesso.

## <a name="ctokenprivilegesgetdisplaynames"></a><a name="getdisplaynames"></a>CTokenPrivileges::GetDisplayNames

Recupera nomes de exibição para `CTokenPrivileges` os privilégios contidos no objeto token de acesso.

```cpp
void GetDisplayNames(CNames* pDisplayNames) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDisplayNames*<br/>
Um ponteiro para uma matriz de objetos `CString`. `CNames`é definido como um `CTokenPrivileges::CAtlArray<CString>`typedef: .

### <a name="remarks"></a>Comentários

O parâmetro `pDisplayNames` é um ponteiro `CString` para uma matriz de objetos que receberão `CTokenPrivileges` os nomes de exibição correspondentes aos privilégios contidos no objeto. Este método recupera nomes de exibição apenas para os privilégios especificados na seção Privilégios Definidos do WINNT. H.

Este método recupera um nome exibivel: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome exibivel é "Force shutdown from a remote system". Para obter o nome do sistema, use [CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes).

## <a name="ctokenprivilegesgetcount"></a><a name="getcount"></a>CTokenPrivileges::GetCount

Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.

```
UINT GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de privilégios contidos no `CTokenPrivileges` objeto.

## <a name="ctokenprivilegesgetlength"></a><a name="getlength"></a>CTokenPrivileges::GetLength

Retorna o comprimento `CTokenPrivileges` do objeto.

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de bytes `TOKEN_PRIVILEGES` necessários `CTokenPrivileges` para manter uma estrutura representada pelo objeto, incluindo todas as entradas de privilégio que ele contém.

## <a name="ctokenprivilegesgetluidsandattributes"></a><a name="getluidsandattributes"></a>CTokenPrivileges::GetLuidsAndAttributes

Recupera os identificadores localmente únicos (LUIDs) `CTokenPrivileges` e atributo soa bandeiras do objeto.

```cpp
void GetLuidsAndAttributes(
    CLUIDArray* pPrivileges,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Ponteiro para uma matriz de objetos [LUID.](/windows/win32/api/winnt/ns-winnt-luid) `CLUIDArray`é um typedef `CAtlArray<LUID> CLUIDArray`definido como .

*pAtributos*<br/>
Ponteiro para uma matriz de objetos DWORD. Se este parâmetro for omitido ou NULO, os atributos não serão recuperados. `CAttributes`é um typedef `CAtlArray <DWORD> CAttributes`definido como .

### <a name="remarks"></a>Comentários

Este método enumerará todos os privilégios `CTokenPrivileges` contidos no objeto de token de acesso e colocará os LUIDs individuais e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

## <a name="ctokenprivilegesgetnamesandattributes"></a><a name="getnamesandattributes"></a>CTokenPrivileges::GetNamesAndAttributes

Recupera o nome e as `CTokenPrivileges` bandeiras de atributo do objeto.

```cpp
void GetNamesAndAttributes(
    CNames* pNames,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pNomes*<br/>
Ponteiro para uma `CString` matriz de objetos. `CNames`é um typedef `CAtlArray <CString> CNames`definido como .

*pAtributos*<br/>
Ponteiro para uma matriz de objetos DWORD. Se este parâmetro for omitido ou NULO, os atributos não serão recuperados. `CAttributes`é um typedef `CAtlArray <DWORD> CAttributes`definido como .

### <a name="remarks"></a>Comentários

Este método enumerará todos os privilégios `CTokenPrivileges` contidos no objeto, colocando o nome e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

Este método recupera o nome do atributo, em vez do nome exibivel: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome do sistema é "SeRemoteShutdownPrivilege". Para obter o nome exibivel, use o método [CTokenPrivileges::GetDisplayNames](#getdisplaynames).

## <a name="ctokenprivilegesgetptoken_privileges"></a><a name="getptoken_privileges"></a>CTokenPrivileges::GetPTOKEN_PRIVILEGES

Devolve um ponteiro `TOKEN_PRIVILEGES` para a estrutura.

```
const TOKEN_PRIVILEGES* GetPTOKEN_PRIVILEGES() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura [TOKEN_PRIVILEGES.](/windows/win32/api/winnt/ns-winnt-token_privileges)

## <a name="ctokenprivilegeslookupprivilege"></a><a name="lookupprivilege"></a>CTokenPrivileges::LookupPrivilege

Recupera o atributo associado a um nome de privilégio dado.

```
bool LookupPrivilege(
    LPCTSTR pszPrivilege,
    DWORD* pdwAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Pointer para uma seqüência de seqüência de terminadas nula que especifica o nome do privilégio, conforme definido no WINNT. Arquivo h cabeçalho. Por exemplo, esse parâmetro poderia especificar o SE_SECURITY_NAME constante ou sua seqüência correspondente, "SeSecurityPrivilege".

*Pdwattributes*<br/>
Ponteiro para uma variável que recebe os atributos.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o atributo for recuperado com sucesso, falso de outra forma.

## <a name="ctokenprivilegesoperator-"></a><a name="operator_eq"></a>CTokenPrivileges::operador =

Operador de atribuição.

```
CTokenPrivileges& operator= (const TOKEN_PRIVILEGES& rPrivileges) throw(...);
CTokenPrivileges& operator= (const CTokenPrivileges& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
A [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) estrutura para `CTokenPrivileges` atribuir ao objeto.

*rhs*<br/>
O `CTokenPrivileges` objeto a atribuir ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna o `CTokenPrivileges` objeto atualizado.

## <a name="ctokenprivilegesoperator-const-token_privileges-"></a><a name="operator_const_token_privileges__star"></a>CTokenPrivileges::TOKEN_PRIVILEGES de const do operador\*

Lança um valor para um `TOKEN_PRIVILEGES` ponteiro para a estrutura.

```
operator const TOKEN_PRIVILEGES *() const throw(...);
```

### <a name="remarks"></a>Comentários

Lança um valor para um ponteiro para a estrutura [TOKEN_PRIVILEGES.](/windows/win32/api/winnt/ns-winnt-token_privileges)

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Token_privileges](/windows/win32/api/winnt/ns-winnt-token_privileges)<br/>
[Luid](/windows/win32/api/winnt/ns-winnt-luid)<br/>
[LUID_AND_ATTRIBUTES](/windows/win32/api/winnt/ns-winnt-luid_and_attributes)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
