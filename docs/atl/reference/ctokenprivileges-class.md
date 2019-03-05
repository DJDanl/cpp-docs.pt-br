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
ms.openlocfilehash: 80302d59d081b7cdf6f29960c3d8f4859b4ecbf4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57280440"
---
# <a name="ctokenprivileges-class"></a>Classe CTokenPrivileges

Essa classe é um wrapper para o `TOKEN_PRIVILEGES` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CTokenPrivileges
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::CTokenPrivileges](#ctokenprivileges)|O construtor.|
|[CTokenPrivileges::~CTokenPrivileges](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::Add](#add)|Adiciona um ou mais privilégios para o `CTokenPrivileges` objeto.|
|[CTokenPrivileges::Delete](#delete)|Exclui um privilégio do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::DeleteAll](#deleteall)|Exclui todos os privilégios do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetCount](#getcount)|Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetDisplayNames](#getdisplaynames)|Recupera exibe nomes para os privilégios contidos no `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetLength](#getlength)|Retorna o tamanho do buffer em bytes, necessários para manter o `TOKEN_PRIVILEGES` estrutura representada pelo `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetLuidsAndAttributes](#getluidsandattributes)|Recupera os identificadores exclusivos localmente (LUID) e os sinalizadores de atributo do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes)|Recupera os nomes de privilégio e os sinalizadores de atributo do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetPTOKEN_PRIVILEGES](#getptoken_privileges)|Retorna um ponteiro para o `TOKEN_PRIVILEGES` estrutura.|
|[CTokenPrivileges::LookupPrivilege](#lookupprivilege)|Recupera um atributo associado ao nome de um determinado privilégio.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges::operator TOKEN_PRIVILEGES de const *](#operator_const_token_privileges__star)|Converte um valor para um ponteiro para o `TOKEN_PRIVILEGES` estrutura.|
|[CTokenPrivileges::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Uma [token de acesso](/windows/desktop/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado no sistema Windows.

O token de acesso é usado para descrever os vários privilégios de segurança concedidos a cada usuário. Um privilégio consiste em um número de 64 bits, chamado de um identificador local exclusivo ( [LUID](/windows/desktop/api/winnt/ns-winnt-_luid)) e uma cadeia de caracteres do descritor.

O `CTokenPrivileges` classe é um wrapper para o [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estruturar e contém 0 ou mais privilégios. Privilégios podem ser adicionados, excluídos ou consultado usando os métodos da classe fornecida.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="add"></a>  CTokenPrivileges::Add

Adiciona um ou mais privilégios para o `CTokenPrivileges` objeto de token de acesso.

```
bool Add(LPCTSTR pszPrivilege, bool bEnable) throw(...);
void Add(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho de H.

*bEnable*<br/>
Se for true, o privilégio está habilitado. Se for false, o privilégio está desabilitado.

*rPrivileges*<br/>
Referência a um [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estrutura. Os privilégios e atributos são copiados a partir dessa estrutura e adicionados ao `CTokenPrivileges` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira forma desse método retornará true se os privilégios são adicionado com êxito, false caso contrário.

##  <a name="ctokenprivileges"></a>  CTokenPrivileges::CTokenPrivileges

O construtor.

```
CTokenPrivileges() throw();
CTokenPrivileges(const CTokenPrivileges& rhs) throw(... );
CTokenPrivileges(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenPrivileges` objeto para atribuir ao novo objeto.

*rPrivileges*<br/>
O [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estrutura para atribuir ao novo `CTokenPrivileges` objeto.

### <a name="remarks"></a>Comentários

O `CTokenPrivileges` objeto opcionalmente pode ser criado usando um `TOKEN_PRIVILEGES` estrutura ou definida anteriormente `CTokenPrivileges` objeto.

##  <a name="dtor"></a>  CTokenPrivileges::~CTokenPrivileges

O destruidor.

```
virtual ~CTokenPrivileges() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="delete"></a>  CTokenPrivileges::Delete

Exclui um privilégio do `CTokenPrivileges` objeto de token de acesso.

```
bool Delete(LPCTSTR pszPrivilege) throw();
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho de H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME, ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o privilégio foi excluído com êxito, false caso contrário.

### <a name="remarks"></a>Comentários

Esse método é útil como uma ferramenta para criar tokens restritos.

##  <a name="deleteall"></a>  CTokenPrivileges::DeleteAll

Exclui todos os privilégios do `CTokenPrivileges` objeto de token de acesso.

```
void DeleteAll() throw();
```

### <a name="remarks"></a>Comentários

Exclui todos os privilégios contidos no `CTokenPrivileges` objeto de token de acesso.

##  <a name="getdisplaynames"></a>  CTokenPrivileges::GetDisplayNames

Recupera exibe nomes para os privilégios contidos no `CTokenPrivileges` objeto de token de acesso.

```
void GetDisplayNames(CNames* pDisplayNames) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDisplayNames*<br/>
Um ponteiro para uma matriz de objetos `CString`. `CNames` é definido como um typedef: `CTokenPrivileges::CAtlArray<CString>`.

### <a name="remarks"></a>Comentários

O parâmetro `pDisplayNames` é um ponteiro para uma matriz de `CString` objetos que receberão os nomes de exibição correspondente aos privilégios contidos no `CTokenPrivileges` objeto. Esse método recupera nomes de exibição somente para os privilégios especificados na seção definido privilégios de WINNT. H.

Esse método recupera um nome de exibição: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome de exibição é "Forçar o desligamento de um sistema remoto." Para obter o nome do sistema, use [CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes).

##  <a name="getcount"></a>  CTokenPrivileges::GetCount

Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.

```
UINT GetCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de privilégios contidos no `CTokenPrivileges` objeto.

##  <a name="getlength"></a>  CTokenPrivileges::GetLength

Retorna o comprimento do `CTokenPrivileges` objeto.

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de bytes necessários para manter uma `TOKEN_PRIVILEGES` estrutura representada pelo `CTokenPrivileges` objeto, incluindo todas as entradas de privilégio que ele contém.

##  <a name="getluidsandattributes"></a>  CTokenPrivileges::GetLuidsAndAttributes

Recupera os identificadores exclusivos localmente (LUID) e os sinalizadores de atributo do `CTokenPrivileges` objeto.

```
void GetLuidsAndAttributes(
    CLUIDArray* pPrivileges,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Ponteiro para uma matriz de [LUID](/windows/desktop/api/winnt/ns-winnt-_luid) objetos. `CLUIDArray` um typedef que é definido como `CAtlArray<LUID> CLUIDArray`.

*pAttributes*<br/>
Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados. `CAttributes` um typedef que é definido como `CAtlArray <DWORD> CAttributes`.

### <a name="remarks"></a>Comentários

Esse método vai enumerar todos os privilégios contidos no `CTokenPrivileges` objeto de token de acesso e colocar os LUIDs individuais e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

##  <a name="getnamesandattributes"></a>  CTokenPrivileges::GetNamesAndAttributes

Recupera os nome e o atributo de sinalizadores do `CTokenPrivileges` objeto.

```
void GetNamesAndAttributes(
    CNames* pNames,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pNames*<br/>
Ponteiro para uma matriz de `CString` objetos. `CNames` um typedef que é definido como `CAtlArray <CString> CNames`.

*pAttributes*<br/>
Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados. `CAttributes` um typedef que é definido como `CAtlArray <DWORD> CAttributes`.

### <a name="remarks"></a>Comentários

Esse método vai enumerar todos os privilégios contidos no `CTokenPrivileges` objeto, colocando o nome e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

Esse método recupera o nome do atributo, em vez do nome de exibição: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome do sistema é "SeRemoteShutdownPrivilege". Para obter o nome de exibição, use o método [CTokenPrivileges::GetDisplayNames](#getdisplaynames).

##  <a name="getptoken_privileges"></a>  CTokenPrivileges::GetPTOKEN_PRIVILEGES

Retorna um ponteiro para o `TOKEN_PRIVILEGES` estrutura.

```
const TOKEN_PRIVILEGES* GetPTOKEN_PRIVILEGES() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estrutura.

##  <a name="lookupprivilege"></a>  CTokenPrivileges::LookupPrivilege

Recupera um atributo associado ao nome de um determinado privilégio.

```
bool LookupPrivilege(
    LPCTSTR pszPrivilege,
    DWORD* pdwAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho de H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME, ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".

*pdwAttributes*<br/>
Ponteiro para uma variável que recebe os atributos.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o atributo for recuperada com sucesso, false caso contrário.

##  <a name="operator_eq"></a>  CTokenPrivileges::operator =

Operador de atribuição.

```
CTokenPrivileges& operator= (const TOKEN_PRIVILEGES& rPrivileges) throw(...);
CTokenPrivileges& operator= (const CTokenPrivileges& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
O [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estrutura para atribuir ao `CTokenPrivileges` objeto.

*rhs*<br/>
O `CTokenPrivileges` objeto a ser atribuído ao objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CTokenPrivileges` objeto.

##  <a name="operator_const_token_privileges__star"></a>  CTokenPrivileges::operator TOKEN_PRIVILEGES de const \*

Converte um valor para um ponteiro para o `TOKEN_PRIVILEGES` estrutura.

```
operator const TOKEN_PRIVILEGES *() const throw(...);
```

### <a name="remarks"></a>Comentários

Converte um valor para um ponteiro para o [TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges) estrutura.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../visual-cpp-samples.md)<br/>
[TOKEN_PRIVILEGES](/windows/desktop/api/winnt/ns-winnt-_token_privileges)<br/>
[LUID](/windows/desktop/api/winnt/ns-winnt-_luid)<br/>
[LUID_AND_ATTRIBUTES](/windows/desktop/api/winnt/ns-winnt-_luid_and_attributes)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
