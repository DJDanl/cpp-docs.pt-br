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
ms.openlocfilehash: f4ecc96ee53d6c688d17afa9957ccbf5060ca3fd
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496277"
---
# <a name="ctokenprivileges-class"></a>Classe CTokenPrivileges

Essa classe é um wrapper para a `TOKEN_PRIVILEGES` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
|[CTokenPrivileges::Add](#add)|Adiciona um ou mais privilégios ao `CTokenPrivileges` objeto.|
|[CTokenPrivileges::Delete](#delete)|Exclui um privilégio do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::DeleteAll](#deleteall)|Exclui todos os privilégios do `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetCount](#getcount)|Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetDisplayNames](#getdisplaynames)|Recupera nomes de exibição para os privilégios contidos no `CTokenPrivileges` objeto.|
|[CTokenPrivileges::GetLength](#getlength)|Retorna o tamanho do buffer em bytes necessários para manter `TOKEN_PRIVILEGES` a estrutura representada `CTokenPrivileges` pelo objeto.|
|[CTokenPrivileges::GetLuidsAndAttributes](#getluidsandattributes)|Recupera os identificadores locais exclusivos (LUIDs) e os sinalizadores de atributo `CTokenPrivileges` do objeto.|
|[CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes)|Recupera os nomes de privilégio e os sinalizadores de `CTokenPrivileges` atributo do objeto.|
|[CTokenPrivileges::GetPTOKEN_PRIVILEGES](#getptoken_privileges)|Retorna um ponteiro para a `TOKEN_PRIVILEGES` estrutura.|
|[CTokenPrivileges::LookupPrivilege](#lookupprivilege)|Recupera o atributo associado a um determinado nome de privilégio.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenPrivileges:: Operator const TOKEN_PRIVILEGES *](#operator_const_token_privileges__star)|Converte um valor em um ponteiro para a `TOKEN_PRIVILEGES` estrutura.|
|[CTokenPrivileges:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado em um sistema Windows.

O token de acesso é usado para descrever os vários privilégios de segurança concedidos a cada usuário. Um privilégio consiste em um número de 64 bits chamado identificador local exclusivo ( [LUID](/windows/win32/api/winnt/ns-winnt-luid)) e uma cadeia de caracteres de descritor.

A `CTokenPrivileges` classe é um wrapper para a estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) e contém 0 ou mais privilégios. Os privilégios podem ser adicionados, excluídos ou consultados usando os métodos de classe fornecidos.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="add"></a>  CTokenPrivileges::Add

Adiciona um ou mais privilégios ao objeto `CTokenPrivileges` de token de acesso.

```
bool Add(LPCTSTR pszPrivilege, bool bEnable) throw(...);
void Add(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido no WINNT. Arquivo de cabeçalho H.

*bEnable*<br/>
Se for true, o privilégio será habilitado. Se for false, o privilégio será desabilitado.

*rPrivileges*<br/>
Referência a uma estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) . Os privilégios e atributos são copiados dessa estrutura e adicionados ao `CTokenPrivileges` objeto.

### <a name="return-value"></a>Valor de retorno

O primeiro formulário desse método retornará true se os privilégios forem adicionados com êxito; caso contrário, false.

##  <a name="ctokenprivileges"></a>  CTokenPrivileges::CTokenPrivileges

O construtor.

```
CTokenPrivileges() throw();
CTokenPrivileges(const CTokenPrivileges& rhs) throw(... );
CTokenPrivileges(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenPrivileges` objeto a ser atribuído ao novo objeto.

*rPrivileges*<br/>
A estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) a ser atribuída ao novo `CTokenPrivileges` objeto.

### <a name="remarks"></a>Comentários

O `CTokenPrivileges` objeto pode, opcionalmente, ser criado `TOKEN_PRIVILEGES` usando uma estrutura ou um `CTokenPrivileges` objeto definido anteriormente.

##  <a name="dtor"></a>  CTokenPrivileges::~CTokenPrivileges

O destruidor.

```
virtual ~CTokenPrivileges() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="delete"></a>  CTokenPrivileges::Delete

Exclui um privilégio do objeto `CTokenPrivileges` de token de acesso.

```
bool Delete(LPCTSTR pszPrivilege) throw();
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido no WINNT. Arquivo de cabeçalho H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".

### <a name="return-value"></a>Valor de retorno

Retornará true se o privilégio tiver sido excluído com êxito; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse método é útil como uma ferramenta para a criação de tokens restritos.

##  <a name="deleteall"></a>  CTokenPrivileges::DeleteAll

Exclui todos os privilégios do `CTokenPrivileges` objeto de token de acesso.

```
void DeleteAll() throw();
```

### <a name="remarks"></a>Comentários

Exclui todos os privilégios contidos no `CTokenPrivileges` objeto de token de acesso.

##  <a name="getdisplaynames"></a>  CTokenPrivileges::GetDisplayNames

Recupera nomes de exibição para os privilégios contidos no `CTokenPrivileges` objeto de token de acesso.

```
void GetDisplayNames(CNames* pDisplayNames) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDisplayNames*<br/>
Um ponteiro para uma matriz de objetos `CString`. `CNames`é definido como um typedef: `CTokenPrivileges::CAtlArray<CString>`.

### <a name="remarks"></a>Comentários

O parâmetro `pDisplayNames` é um ponteiro para uma matriz de `CString` objetos que receberá os nomes de exibição correspondentes aos privilégios contidos no `CTokenPrivileges` objeto. Esse método recupera nomes de exibição somente para os privilégios especificados na seção de privilégios definidos do WINNT. T.

Esse método recupera um nome que poderia ser reproduzido: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome de exibição será "forçar o desligamento de um sistema remoto". Para obter o nome do sistema, use [CTokenPrivileges:: GetNamesAndAttributes](#getnamesandattributes).

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

Retorna o número de bytes necessários para manter uma `TOKEN_PRIVILEGES` estrutura representada `CTokenPrivileges` pelo objeto, incluindo todas as entradas de privilégio que ele contém.

##  <a name="getluidsandattributes"></a>  CTokenPrivileges::GetLuidsAndAttributes

Recupera os identificadores locais exclusivos (LUIDs) e os sinalizadores de atributo `CTokenPrivileges` do objeto.

```
void GetLuidsAndAttributes(
    CLUIDArray* pPrivileges,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Ponteiro para uma matriz de objetos [LUID](/windows/win32/api/winnt/ns-winnt-luid) . `CLUIDArray`é um typedef definido como `CAtlArray<LUID> CLUIDArray`.

*pAttributes*<br/>
Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não serão recuperados. `CAttributes`é um typedef definido como `CAtlArray <DWORD> CAttributes`.

### <a name="remarks"></a>Comentários

Esse método irá enumerar todos os privilégios contidos no `CTokenPrivileges` objeto de token de acesso e posicionar o LUIDs individual e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

##  <a name="getnamesandattributes"></a>  CTokenPrivileges::GetNamesAndAttributes

Recupera os sinalizadores de nome e atributo do `CTokenPrivileges` objeto.

```
void GetNamesAndAttributes(
    CNames* pNames,
    CAttributes* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pNames*<br/>
Ponteiro para uma matriz de `CString` objetos. `CNames`é um typedef definido como `CAtlArray <CString> CNames`.

*pAttributes*<br/>
Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não serão recuperados. `CAttributes`é um typedef definido como `CAtlArray <DWORD> CAttributes`.

### <a name="remarks"></a>Comentários

Esse método irá enumerar todos os privilégios contidos no `CTokenPrivileges` objeto, colocando o nome e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

Esse método recupera o nome do atributo, em vez do nome que é exibível: por exemplo, se o nome do atributo for SE_REMOTE_SHUTDOWN_NAME, o nome do sistema será "SeRemoteShutdownPrivilege". Para obter o nome de exibição, use o método [CTokenPrivileges::](#getdisplaynames)GetDisplayNames.

##  <a name="getptoken_privileges"></a>  CTokenPrivileges::GetPTOKEN_PRIVILEGES

Retorna um ponteiro para a `TOKEN_PRIVILEGES` estrutura.

```
const TOKEN_PRIVILEGES* GetPTOKEN_PRIVILEGES() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) .

##  <a name="lookupprivilege"></a>CTokenPrivileges::LookupPrivilege

Recupera o atributo associado a um determinado nome de privilégio.

```
bool LookupPrivilege(
    LPCTSTR pszPrivilege,
    DWORD* pdwAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido no WINNT. Arquivo de cabeçalho H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".

*pdwAttributes*<br/>
Ponteiro para uma variável que recebe os atributos.

### <a name="return-value"></a>Valor de retorno

Retorna true se o atributo for recuperado com êxito; caso contrário, false.

##  <a name="operator_eq"></a>CTokenPrivileges:: Operator =

Operador de atribuição.

```
CTokenPrivileges& operator= (const TOKEN_PRIVILEGES& rPrivileges) throw(...);
CTokenPrivileges& operator= (const CTokenPrivileges& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
A estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) a ser atribuída ao `CTokenPrivileges` objeto.

*rhs*<br/>
O `CTokenPrivileges` objeto a ser atribuído ao objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CTokenPrivileges` atualizado.

##  <a name="operator_const_token_privileges__star"></a>CTokenPrivileges:: Operator const TOKEN_PRIVILEGES\*

Converte um valor em um ponteiro para a `TOKEN_PRIVILEGES` estrutura.

```
operator const TOKEN_PRIVILEGES *() const throw(...);
```

### <a name="remarks"></a>Comentários

Converte um valor em um ponteiro para a estrutura [TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges) .

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[TOKEN_PRIVILEGES](/windows/win32/api/winnt/ns-winnt-token_privileges)<br/>
[LUID](/windows/win32/api/winnt/ns-winnt-luid)<br/>
[LUID_AND_ATTRIBUTES](/windows/win32/api/winnt/ns-winnt-luid_and_attributes)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
