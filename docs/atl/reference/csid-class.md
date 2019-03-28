---
title: Classe CSid
ms.date: 03/27/2019
f1_keywords:
- CSid
- ATLSECURITY/ATL::CSid
- ATLSECURITY/ATL::CSid::CSidArray
- ATLSECURITY/ATL::CSid::CSid
- ATLSECURITY/ATL::CSid::AccountName
- ATLSECURITY/ATL::CSid::Domain
- ATLSECURITY/ATL::CSid::EqualPrefix
- ATLSECURITY/ATL::CSid::GetLength
- ATLSECURITY/ATL::CSid::GetPSID
- ATLSECURITY/ATL::CSid::GetPSID_IDENTIFIER_AUTHORITY
- ATLSECURITY/ATL::CSid::GetSubAuthority
- ATLSECURITY/ATL::CSid::GetSubAuthorityCount
- ATLSECURITY/ATL::CSid::IsValid
- ATLSECURITY/ATL::CSid::LoadAccount
- ATLSECURITY/ATL::CSid::Sid
- ATLSECURITY/ATL::CSid::SidNameUse
helpviewer_keywords:
- CSid class
ms.assetid: be58b7ca-5958-49c3-a833-ca341aaaf753
ms.openlocfilehash: 4c8d05fd193254f2431bbec7692ff25420c1bf05
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565864"
---
# <a name="csid-class"></a>Classe CSid

Essa classe é um wrapper para um `SID` estrutura (identificador de segurança).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSid
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::CSidArray](#csidarray)|Uma matriz de objetos de `CSid`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::CSid](#csid)|O construtor.|
|[CSid::~CSid](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::AccountName](#accountname)|Retorna o nome da conta associada com o `CSid` objeto.|
|[CSid::Domain](#domain)|Retorna o nome do domínio associado com o `CSid` objeto.|
|[CSid::EqualPrefix](#equalprefix)|Testes `SID` prefixos (identificador de segurança) quanto à igualdade.|
|[CSid::GetLength](#getlength)|Retorna o comprimento do `CSid` objeto.|
|[CSid::GetPSID](#getpsid)|Retorna um ponteiro para um `SID` estrutura.|
|[CSid::GetPSID_IDENTIFIER_AUTHORITY](#getpsid_identifier_authority)|Retorna um ponteiro para o `SID_IDENTIFIER_AUTHORITY` estrutura.|
|[CSid::GetSubAuthority](#getsubauthority)|Retorna uma subautoridade especificada em um `SID` estrutura.|
|[CSid::GetSubAuthorityCount](#getsubauthoritycount)|Retorna a contagem de subautoridade.|
|[CSid::IsValid](#isvalid)|Testes de `CSid` objeto quanto à validade.|
|[CSid::LoadAccount](#loadaccount)|Atualizações do `CSid` objeto, considerando o nome da conta e o domínio ou um existente `SID` estrutura.|
|[CSid::Sid](#sid)|Retorna a cadeia de caracteres de ID.|
|[CSid::SidNameUse](#sidnameuse)|Retorna uma descrição do estado do `CSid` objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator =](#operator_eq)|Operador de atribuição.|
|[operador SID const *](#operator_const_sid__star)|Conversões de um `CSid` objeto em um ponteiro para um `SID` estrutura.|

### <a name="global-operators"></a>Operadores globais

|||
|-|-|
|[operator ==](#operator_eq_eq)|Testa dois objetos do descritor de segurança quanto à igualdade|
|[operator !=](#operator_neq)|Testa dois objetos do descritor de segurança quanto à desigualdade|
|[operador \<](#operator_lt)|Compara o valor relativo de dois objetos do descritor de segurança.|
|[operador >](#operator_gt)|Compara o valor relativo de dois objetos do descritor de segurança.|
|[operador \<=](#operator_lt__eq)|Compara o valor relativo de dois objetos do descritor de segurança.|
|[operador > =](#operator_gt__eq)|Compara o valor relativo de dois objetos do descritor de segurança.|

## <a name="remarks"></a>Comentários

O `SID` estrutura é uma estrutura de comprimento variável usada para identificar exclusivamente os usuários ou grupos.

Aplicativos não devem modificar o `SID` estrutura diretamente, mas em vez disso, use os métodos fornecidos nesta classe wrapper. Consulte também [AtlGetOwnerSid](security-global-functions.md#atlgetownersid), [AtlSetGroupSid](security-global-functions.md#atlsetgroupsid), [AtlGetGroupSid](security-global-functions.md#atlgetgroupsid), e [AtlSetOwnerSid](security-global-functions.md#atlsetownersid).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="accountname"></a>  CSid::AccountName

Retorna o nome da conta associada com o `CSid` objeto.

```
LPCTSTR AccountName() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna o LPCTSTR apontando para o nome da conta.

### <a name="remarks"></a>Comentários

Esse método tenta localizar um nome especificado `SID` (identificador de segurança). Para obter detalhes completos, consulte [LookupAccountSid](/windows/desktop/api/winbase/nf-winbase-lookupaccountsida).

Se nenhum nome de conta para o `SID` pode ser encontrado, `AccountName` retorna uma cadeia de caracteres vazia. Isso pode ocorrer se um tempo limite da rede impede que esse método encontrando o nome. Isso também ocorre para identificadores de segurança sem nome de conta correspondente, como um `SID` que identifica uma sessão de entrada.

##  <a name="csid"></a>  CSid::CSid

O construtor.

```
CSid() throw();
CSid(const SID& rhs) throw(...);
CSid(const CSid& rhs) throw(...);

CSid(
    const SID_IDENTIFIER_AUTHORITY& IdentifierAuthority,
    BYTE nSubAuthorityCount,
    ...) throw(...);

explicit CSid(
    LPCTSTR pszAccountName,
    LPCTSTR pszSystem = NULL) throw(...);

explicit CSid(
    const SID* pSid,
    LPCTSTR pszSystem = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um existente `CSid` objeto ou `SID` estrutura (identificador de segurança).

*IdentifierAuthority*<br/>
A autoridade.

*nSubAuthorityCount*<br/>
A contagem de subautoridade.

*pszAccountName*<br/>
O nome da conta.

*pszSystem*<br/>
O nome do sistema. Essa cadeia de caracteres pode ser o nome de um computador remoto. Se essa cadeia de caracteres for NULL, o sistema local é usado em vez disso.

*pSid*<br/>
Um ponteiro para um `SID` estrutura.

### <a name="remarks"></a>Comentários

O construtor inicializa o `CSid` objeto, definindo um membro de dados interno *SidTypeInvalid*, ou copiando as configurações de uma já existente `CSid`, `SID`, ou a conta existente.

Se a inicialização falhar, o construtor lançará uma [classe CAtlException](../../atl/reference/catlexception-class.md).

##  <a name="dtor"></a>  CSid::~CSid

O destruidor.

```
virtual ~CSid() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

##  <a name="csidarray"></a>  CSid::CSidArray

Uma matriz de [CSid](../../atl/reference/csid-class.md) objetos.

```
typedef CAtlArray<CSid> CSidArray;
```

### <a name="remarks"></a>Comentários

Este typedef Especifica o tipo de matriz que pode ser usado para recuperar identificadores de segurança de uma ACL (lista de controle de acesso). Ver [CAcl::GetAclEntries](../../atl/reference/cacl-class.md#getaclentries).

##  <a name="domain"></a>  CSid::Domain

Retorna o nome do domínio associado com o `CSid` objeto.

```
LPCTSTR Domain() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna o `LPCTSTR` apontando para o domínio.

### <a name="remarks"></a>Comentários

Esse método tenta localizar um nome especificado `SID` (identificador de segurança). Para obter detalhes completos, consulte [LookupAccountSid](/windows/desktop/api/winbase/nf-winbase-lookupaccountsida).

Se nenhum nome de conta para o `SID` pode ser encontrado, `Domain` retorna o domínio como uma cadeia de caracteres vazia. Isso pode ocorrer se um tempo limite da rede impede que esse método encontrando o nome. Isso também ocorre para identificadores de segurança sem nome de conta correspondente, como um `SID` que identifica uma sessão de entrada.

##  <a name="equalprefix"></a>  CSid::EqualPrefix

Testes `SID` prefixos (identificador de segurança) quanto à igualdade.

```
bool EqualPrefix(const SID& rhs) const throw();
bool EqualPrefix(const CSid& rhs) const throw();
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `SID` estrutura (identificador de segurança) ou `CSid` objeto a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Ver [EqualPrefixSid](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid) no SDK do Windows para obter mais detalhes.

##  <a name="getlength"></a>  CSid::GetLength

Retorna o comprimento do `CSid` objeto.

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o comprimento em bytes do `CSid` objeto.

### <a name="remarks"></a>Comentários

Se o `CSid` estrutura não é válida, o valor retornado será indefinido. Antes de chamar `GetLength`, use o [CSid::IsValid](#isvalid) a função de membro para verificar se `CSid` é válido.

> [!NOTE]
>  Em compilações de depuração, a função causará uma declaração se o `CSid` objeto não é válido.

##  <a name="getpsid"></a>  CSid::GetPSID

Retorna um ponteiro para um `SID` estrutura (identificador de segurança).

```
const SID* GetPSID() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna o endereço do `CSid` de base do objeto `SID` estrutura.

##  <a name="getpsid_identifier_authority"></a>  CSid::GetPSID_IDENTIFIER_AUTHORITY

Retorna um ponteiro para o `SID_IDENTIFIER_AUTHORITY` estrutura.

```
const SID_IDENTIFIER_AUTHORITY* GetPSID_IDENTIFIER_AUTHORITY() const throw();
```

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retorna o endereço do `SID_IDENTIFIER_AUTHORITY` estrutura. Se ele falhar, o valor retornado será indefinido. Falha pode ocorrer se o `CSid` objeto não é válido, caso em que o [CSid::IsValid](#isvalid) método retornará FALSE. A função `GetLastError` pode ser chamado para obter informações de erro estendido.

> [!NOTE]
>  Em compilações de depuração, a função causará uma declaração se o `CSid` objeto não é válido.

##  <a name="getsubauthority"></a>  CSid::GetSubAuthority

Retorna uma subautoridade especificada em um `SID` estrutura (identificador de segurança).

```
DWORD GetSubAuthority(DWORD nSubAuthority) const throw();
```

### <a name="parameters"></a>Parâmetros

*nSubAuthority*<br/>
Subautoridade.

### <a name="return-value"></a>Valor de retorno

Retorna a subautoridade referenciada pelo *nSubAuthority.* O valor de subautoridade é um identificador relativo (RID).

### <a name="remarks"></a>Comentários

O *nSubAuthority* parâmetro especifica um valor de índice que identifica o elemento da matriz subautoridade o método será retornado. O método não realiza nenhum teste de validação nesse valor. Um aplicativo pode chamar [CSid::GetSubAuthorityCount](#getsubauthoritycount) para descobrir o intervalo de valores aceitáveis.

> [!NOTE]
>  Em compilações de depuração, a função causará uma declaração se o `CSid` objeto não é válido.

##  <a name="getsubauthoritycount"></a>  CSid::GetSubAuthorityCount

Retorna a contagem de subautoridade.

```
UCHAR GetSubAuthorityCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, o valor de retorno é a contagem de subautoridade.

Se o método falhar, o valor retornado será indefinido. O método falhará se o `CSid` objeto é inválido. Para obter outras informações sobre o erro, chame `GetLastError`.

> [!NOTE]
>  Em compilações de depuração, a função causará uma declaração se o `CSid` objeto não é válido.

##  <a name="isvalid"></a>  CSid::IsValid

Testes de `CSid` objeto quanto à validade.

```
bool IsValid() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o `CSid` objeto for válido, FALSE se não for. Não há nenhuma informação de erro estendidas para este método; Não chame `GetLastError`.

### <a name="remarks"></a>Comentários

O `IsValid` método valida o `CSid` objeto verificando que o número de revisão está dentro do intervalo conhecido e que o número de subautoridades é menor que o máximo.

##  <a name="loadaccount"></a>  CSid::LoadAccount

Atualizações de `CSid` objeto, considerando o nome da conta e o domínio ou uma estrutura existente de SID (identificador de segurança).

```
bool LoadAccount(
    LPCTSTR pszAccountName,
    LPCTSTR pszSystem = NULL) throw(...);

bool LoadAccount(
    const SID* pSid,
    LPCTSTR pszSystem = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszAccountName*<br/>
O nome da conta.

*pszSystem*<br/>
O nome do sistema. Essa cadeia de caracteres pode ser o nome de um computador remoto. Se essa cadeia de caracteres for NULL, o sistema local é usado em vez disso.

*pSid*<br/>
Um ponteiro para um [SID](/windows/desktop/api/winnt/ns-winnt-_sid) estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

`LoadAccount` tenta localizar um identificador de segurança para o nome especificado. Ver [LookupAccountSid](/windows/desktop/api/winbase/nf-winbase-lookupaccountsida) para obter mais detalhes.

##  <a name="operator_eq"></a>  CSid::operator =

Operador de atribuição.

```
CSid& operator= (const CSid& rhs) throw(...);
CSid& operator= (const SID& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` para atribuir ao `CSid` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a atualização `CSid` objeto.

##  <a name="operator_eq_eq"></a>  CSid::operator = =

Testa dois objetos do descritor de segurança quanto à igualdade.

```
bool operator==(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo do operador = =.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito do operador = =.

### <a name="return-value"></a>Valor de retorno

TRUE se os descritores de segurança forem iguais, caso contrário, FALSE.

##  <a name="operator_neq"></a>  CSid::operator! =

Testa dois objetos do descritor de segurança quanto à desigualdade.

```
bool operator!=(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo da! = operador.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito da! = operador.

### <a name="return-value"></a>Valor de retorno

TRUE se os descritores de segurança não forem iguais, caso contrário, FALSE.

##  <a name="operator_lt"></a>  CSid::operator &lt;

Compara o valor relativo de dois objetos do descritor de segurança.

```
bool operator<(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo da! = operador.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito da! = operador.

### <a name="return-value"></a>Valor de retorno

TRUE se *lhs* é menor que *rhs*, caso contrário, FALSE.

##  <a name="operator_lt__eq"></a>  CSid::operator &lt;=

Compara o valor relativo de dois objetos do descritor de segurança.

```
bool operator<=(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo da! = operador.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito da! = operador.

### <a name="return-value"></a>Valor de retorno

TRUE se *lhs* é menor que ou igual a *rhs*, caso contrário, FALSE.

##  <a name="operator_gt"></a>  CSid::operator &gt;

Compara o valor relativo de dois objetos do descritor de segurança.

```
bool operator>(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo da! = operador.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito da! = operador.

### <a name="return-value"></a>Valor de retorno

TRUE se *lhs* é maior que *rhs*, caso contrário, FALSE.

##  <a name="operator_gt__eq"></a>  CSid::operator &gt;=

Compara o valor relativo de dois objetos do descritor de segurança.

```
bool operator>=(
    const CSid& lhs,
    const CSid& rhs) throw());
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado esquerdo da! = operador.

*rhs*<br/>
O `SID` (identificador de segurança) ou `CSid` que aparece no lado direito da! = operador.

### <a name="return-value"></a>Valor de retorno

TRUE se *lhs* é maior que ou igual a *rhs*, caso contrário, FALSE.

##  <a name="operator_const_sid__star"></a>  SID de const CSid::operator \*

Conversões de um `CSid` objeto em um ponteiro para um `SID` estrutura (identificador de segurança).

```
operator const SID *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço do `SID` estrutura.

##  <a name="sid"></a>  CSid::Sid

Retorna o `SID` estrutura (identificador de segurança) como uma cadeia de caracteres.

```
LPCTSTR Sid() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna o `SID` estrutura como uma cadeia de caracteres em um formato adequado para exibição, armazenamento e transmissão. Equivalente a [ConvertSidToStringSid](/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida).

##  <a name="sidnameuse"></a>  CSid::SidNameUse

Retorna uma descrição do estado do `CSid` objeto.

```
SID_NAME_USE SidNameUse() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o valor do membro de dados que armazena um valor que descreve o estado do `CSid` objeto.

|Valor|Descrição|
|-----------|-----------------|
|SidTypeUser|Indica que um usuário `SID` (identificador de segurança).|
|SidTypeGroup|Indica um grupo `SID`.|
|SidTypeDomain|Indica um domínio `SID`.|
|SidTypeAlias|Indica um alias `SID`.|
|SidTypeWellKnownGroup|Indica um `SID` para um grupo bem conhecido.|
|SidTypeDeletedAccount|Indica um `SID` para uma conta excluída.|
|SidTypeInvalid|Indica um inválido `SID`.|
|SidTypeUnknown|Indica desconhecida `SID` tipo.|
|SidTypeComputer|Indica um `SID` para um computador.|

### <a name="remarks"></a>Comentários

Chame [CSid::LoadAccount](#loadaccount) para atualizar o `CSid` objeto antes de chamar `SidNameUse` para retornar a seu estado. `SidNameUse` não altera o estado do objeto (chamando `LookupAccountName` ou `LookupAccountSid`), mas só retorna o estado atual.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)<br/>
[Operadores](../../atl/reference/atl-operators.md)
