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
ms.openlocfilehash: 414cf428cebe8105d90b3add93cc7f1e76927c2a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330912"
---
# <a name="csid-class"></a>Classe CSid

Esta classe é um `SID` invólucro para uma estrutura (identificador de segurança).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSid
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::CSidArray](#csidarray)|Uma matriz de objetos `CSid`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::CSid](#csid)|O construtor.|
|[CSid::~CSid](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSid::Nome da conta](#accountname)|Retorna o nome da conta `CSid` associada ao objeto.|
|[CSid::Domain](#domain)|Retorna o nome do domínio `CSid` associado ao objeto.|
|[CSid::EqualPrefix](#equalprefix)|Testes `SID` (identificador de segurança) prefixos para igualdade.|
|[CSid::GetLength](#getlength)|Retorna o comprimento `CSid` do objeto.|
|[CSid::GetPSID](#getpsid)|Devolve um ponteiro `SID` para uma estrutura.|
|[CSid::GetPSID_IDENTIFIER_AUTHORITY](#getpsid_identifier_authority)|Devolve um ponteiro `SID_IDENTIFIER_AUTHORITY` para a estrutura.|
|[CSid::GetSubAuthority](#getsubauthority)|Retorna uma subautoridade especificada em uma `SID` estrutura.|
|[CSid::GetSubAuthorityCount](#getsubauthoritycount)|Retorna a contagem de sub-autoridades.|
|[CSid::IsValid](#isvalid)|Testa `CSid` o objeto para validade.|
|[Csid::LoadAccount](#loadaccount)|Atualiza o `CSid` objeto dado o nome e `SID` o domínio da conta ou uma estrutura existente.|
|[CSid::Sid](#sid)|Retorna a seqüência de id.|
|[CSid::SidNameUse](#sidnameuse)|Retorna uma descrição do `CSid` estado do objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Operador de atribuição.|
|[operador const SID *](#operator_const_sid__star)|Lança um `CSid` objeto para um `SID` ponteiro para uma estrutura.|

### <a name="global-operators"></a>Operadores Globais

|||
|-|-|
|[operador ==](#operator_eq_eq)|Testa dois objetos descritores de segurança para igualdade|
|[operador !=](#operator_neq)|Testa dois objetos descritores de segurança para desigualdade|
|[Operador\<](#operator_lt)|Compara o valor relativo de dois objetos descritores de segurança.|
|[operador >](#operator_gt)|Compara o valor relativo de dois objetos descritores de segurança.|
|[Operador\<=](#operator_lt__eq)|Compara o valor relativo de dois objetos descritores de segurança.|
|[operador >=](#operator_gt__eq)|Compara o valor relativo de dois objetos descritores de segurança.|

## <a name="remarks"></a>Comentários

A `SID` estrutura é uma estrutura de comprimento variável usada para identificar exclusivamente usuários ou grupos.

Os aplicativos não `SID` devem modificar a estrutura diretamente, mas usar os métodos fornecidos nesta classe de invólucro. Consulte também [AtlGetOwnerSid](security-global-functions.md#atlgetownersid), [AtlSetGroupSid,](security-global-functions.md#atlsetgroupsid) [AtlGetGroupSid](security-global-functions.md#atlgetgroupsid)e [AtlSetOwnerSid](security-global-functions.md#atlsetownersid).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="csidaccountname"></a><a name="accountname"></a>CSid::Nome da conta

Retorna o nome da conta `CSid` associada ao objeto.

```
LPCTSTR AccountName() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna o LPCTSTR apontando para o nome da conta.

### <a name="remarks"></a>Comentários

Este método tenta encontrar um nome `SID` para o especificado (identificador de segurança). Para obter detalhes completos, consulte [LookupAccountSid](/windows/win32/api/winbase/nf-winbase-lookupaccountsidw).

Se nenhum nome `SID` da conta `AccountName` para o pode ser encontrado, retorna uma seqüência vazia. Isso pode ocorrer se um tempo de rede impedir que esse método descubra o nome. Também ocorre para identificadores de segurança sem `SID` nome da conta correspondente, como um que identifica uma sessão de login.

## <a name="csidcsid"></a><a name="csid"></a>CSid::CSid

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
Uma estrutura `CSid` de `SID` objeto ou (identificador de segurança) existente.

*Autoridade de identificadores*<br/>
A autoridade.

*nSubAuthorityCount*<br/>
A contagem de sub-autoridades.

*pszAccountName*<br/>
O nome da conta.

*pszSystem*<br/>
O nome do sistema. Esta seqüência pode ser o nome de um computador remoto. Se esta seqüência for NULL, o sistema local será usado em vez disso.

*Psid*<br/>
Um ponteiro `SID` para uma estrutura.

### <a name="remarks"></a>Comentários

O construtor inicializa `CSid` o objeto, definindo um membro de dados interno para *SidTypeInvalid,* ou copiando as configurações de uma conta existente `CSid` `SID`ou existente.

Se a inicialização falhar, o construtor lançará uma [classe CAtlException](../../atl/reference/catlexception-class.md).

## <a name="csidcsid"></a><a name="dtor"></a>CSid::~CSid

O destruidor.

```
virtual ~CSid() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

## <a name="csidcsidarray"></a><a name="csidarray"></a>CSid::CSidArray

Uma matriz de objetos [CSid.](../../atl/reference/csid-class.md)

```
typedef CAtlArray<CSid> CSidArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz que pode ser usado para recuperar identificadores de segurança de uma ACL (lista de controle de acesso). Consulte [CAcl::GetAclEntries](../../atl/reference/cacl-class.md#getaclentries).

## <a name="csiddomain"></a><a name="domain"></a>CSid::Domain

Retorna o nome do domínio `CSid` associado ao objeto.

```
LPCTSTR Domain() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna `LPCTSTR` o apontamento para o domínio.

### <a name="remarks"></a>Comentários

Este método tenta encontrar um nome `SID` para o especificado (identificador de segurança). Para obter detalhes completos, consulte [LookupAccountSid](/windows/win32/api/winbase/nf-winbase-lookupaccountsidw).

Se nenhum nome `SID` da conta `Domain` para o pode ser encontrado, retorna o domínio como uma seqüência de string vazia. Isso pode ocorrer se um tempo de rede impedir que esse método descubra o nome. Também ocorre para identificadores de segurança sem `SID` nome da conta correspondente, como um que identifica uma sessão de login.

## <a name="csidequalprefix"></a><a name="equalprefix"></a>CSid::EqualPrefix

Testes `SID` (identificador de segurança) prefixos para igualdade.

```
bool EqualPrefix(const SID& rhs) const throw();
bool EqualPrefix(const CSid& rhs) const throw();
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `SID` estrutura (identificador `CSid` de segurança) ou objeto para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Consulte [EqualPrefixSid](/windows/win32/api/securitybaseapi/nf-securitybaseapi-equalprefixsid) no Windows SDK para obter mais detalhes.

## <a name="csidgetlength"></a><a name="getlength"></a>CSid::GetLength

Retorna o comprimento `CSid` do objeto.

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento em bytes do `CSid` objeto.

### <a name="remarks"></a>Comentários

Se `CSid` a estrutura não for válida, o valor de retorno é indefinido. Antes `GetLength`de ligar, use a função [membro CSid::IsValid](#isvalid) para verificar se `CSid` é válida.

> [!NOTE]
> Em compilações de depuração, a `CSid` função causará uma ASSERT se o objeto não for válido.

## <a name="csidgetpsid"></a><a name="getpsid"></a>CSid::GetPSID

Retorna um ponteiro `SID` para uma estrutura (identificador de segurança).

```
const SID* GetPSID() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço `CSid` da estrutura `SID` subjacente do objeto.

## <a name="csidgetpsid_identifier_authority"></a><a name="getpsid_identifier_authority"></a>CSid::GetPSID_IDENTIFIER_AUTHORITY

Devolve um ponteiro `SID_IDENTIFIER_AUTHORITY` para a estrutura.

```
const SID_IDENTIFIER_AUTHORITY* GetPSID_IDENTIFIER_AUTHORITY() const throw();
```

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, `SID_IDENTIFIER_AUTHORITY` ele retorna o endereço da estrutura. Se falhar, o valor de retorno é indefinido. A falha pode `CSid` ocorrer se o objeto não for válido, nesse caso o método [CSid::IsValid](#isvalid) retorna FALSO. A `GetLastError` função pode ser chamada para informações de erro estendidas.

> [!NOTE]
> Em compilações de depuração, a `CSid` função causará uma ASSERT se o objeto não for válido.

## <a name="csidgetsubauthority"></a><a name="getsubauthority"></a>CSid::GetSubAuthority

Retorna uma subautoridade especificada em uma `SID` estrutura (identificador de segurança).

```
DWORD GetSubAuthority(DWORD nSubAuthority) const throw();
```

### <a name="parameters"></a>Parâmetros

*nSubAutoridade*<br/>
A sub-autoridade.

### <a name="return-value"></a>Valor retornado

Retorna a subautoridade referenciada por *nSubAuthority.* O valor da subautoridade é um identificador relativo (RID).

### <a name="remarks"></a>Comentários

O parâmetro *nSubAuthority* especifica um valor de índice que identifica o elemento de matriz de subautoridade que o método retornará. O método não realiza testes de validação neste valor. Um aplicativo pode chamar [CSid::GetSubAuthorityCount](#getsubauthoritycount) para descobrir a gama de valores aceitáveis.

> [!NOTE]
> Em compilações de depuração, a `CSid` função causará uma ASSERT se o objeto não for válido.

## <a name="csidgetsubauthoritycount"></a><a name="getsubauthoritycount"></a>CSid::GetSubAuthorityCount

Retorna a contagem de sub-autoridades.

```
UCHAR GetSubAuthorityCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, o valor de retorno é a contagem de subautoridades.

Se o método falhar, o valor de retorno é indefinido. O método falha `CSid` se o objeto for inválido. Para obter outras informações sobre o erro, chame `GetLastError`.

> [!NOTE]
> Em compilações de depuração, a `CSid` função causará uma ASSERT se o objeto não for válido.

## <a name="csidisvalid"></a><a name="isvalid"></a>CSid::IsValid

Testa `CSid` o objeto para validade.

```
bool IsValid() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE `CSid` se o objeto for válido, FALSO se não. Não há informações de erro estendidas para este método; não ligue `GetLastError`.

### <a name="remarks"></a>Comentários

O `IsValid` método valida o `CSid` objeto verificando se o número de revisão está dentro de um intervalo conhecido e que o número de subautoridades é menor que o máximo.

## <a name="csidloadaccount"></a><a name="loadaccount"></a>Csid::LoadAccount

Atualiza o `CSid` objeto dado o nome e o domínio da conta ou uma estrutura SID (identificador de segurança) existente.

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
O nome do sistema. Esta seqüência pode ser o nome de um computador remoto. Se esta seqüência for NULL, o sistema local será usado em vez disso.

*Psid*<br/>
Um ponteiro para uma estrutura [SID.](/windows/win32/api/winnt/ns-winnt-sid)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

`LoadAccount`tentativas de encontrar um identificador de segurança para o nome especificado. Consulte [LookupAccountSid](/windows/win32/api/winbase/nf-winbase-lookupaccountsidw) para obter mais detalhes.

## <a name="csidoperator-"></a><a name="operator_eq"></a>CSid::operador =

Operador de atribuição.

```
CSid& operator= (const CSid& rhs) throw(...);
CSid& operator= (const SID& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou `CSid` atribuir ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CSid` ao objeto atualizado.

## <a name="csidoperator-"></a><a name="operator_eq_eq"></a>CSid::operador ==

Testa dois objetos de descritor de segurança para igualdade.

```
bool operator==(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador ==.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador ==.

### <a name="return-value"></a>Valor retornado

TRUE se os descritores de segurança forem iguais, caso contrário, FALSO.

## <a name="csidoperator-"></a><a name="operator_neq"></a>CSid::operador !=

Testa dois objetos de descritor de segurança para desigualdade.

```
bool operator!=(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador !=.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador !=.

### <a name="return-value"></a>Valor retornado

TRUE se os descritores de segurança não forem iguais, caso contrário, FALSO.

## <a name="csidoperator-lt"></a><a name="operator_lt"></a>CSid::operador&lt;

Compara o valor relativo de dois objetos descritores de segurança.

```
bool operator<(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador !=.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador !=.

### <a name="return-value"></a>Valor retornado

VERDADE se *lhs* é menor que *rhs*, caso contrário FALSO.

## <a name="csidoperator-lt"></a><a name="operator_lt__eq"></a>CSid::operador&lt;=

Compara o valor relativo de dois objetos descritores de segurança.

```
bool operator<=(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador !=.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador !=.

### <a name="return-value"></a>Valor retornado

VERDADE se *lhs* é menor ou igual a *rhs,* caso contrário, FALSO.

## <a name="csidoperator-gt"></a><a name="operator_gt"></a>CSid::operador&gt;

Compara o valor relativo de dois objetos descritores de segurança.

```
bool operator>(
    const CSid& lhs,
    const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador !=.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador !=.

### <a name="return-value"></a>Valor retornado

VERDADE se *lhs* é maior que *rhs*, caso contrário FALSO.

## <a name="csidoperator-gt"></a><a name="operator_gt__eq"></a>CSid::operador&gt;=

Compara o valor relativo de dois objetos descritores de segurança.

```
bool operator>=(
    const CSid& lhs,
    const CSid& rhs) throw());
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado esquerdo do operador !=.

*rhs*<br/>
O `SID` (identificador de `CSid` segurança) ou que aparece no lado direito do operador !=.

### <a name="return-value"></a>Valor retornado

VERDADE se *lhs* é maior ou igual a *rhs,* caso contrário, FALSO.

## <a name="csidoperator-const-sid-"></a><a name="operator_const_sid__star"></a>CSid::operador const SID\*

Lança um `CSid` objeto para um `SID` ponteiro para uma estrutura (identificador de segurança).

```
operator const SID *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço `SID` da estrutura.

## <a name="csidsid"></a><a name="sid"></a>CSid::Sid

Retorna `SID` a estrutura (identificador de segurança) como uma string.

```
LPCTSTR Sid() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna `SID` a estrutura como uma string em um formato adequado para exibição, armazenamento ou transmissão. Equivalente a [ConvertSidToStringSid](/windows/win32/api/sddl/nf-sddl-convertsidtostringsidw).

## <a name="csidsidnameuse"></a><a name="sidnameuse"></a>CSid::SidNameUse

Retorna uma descrição do `CSid` estado do objeto.

```
SID_NAME_USE SidNameUse() const throw();
```

### <a name="return-value"></a>Valor retornado

Devolve o valor do membro de dados que armazena `CSid` um valor descrevendo o estado do objeto.

|Valor|Descrição|
|-----------|-----------------|
|SidTypeUser|Indica um `SID` usuário (identificador de segurança).|
|SidTypeGroup|Indica um `SID`grupo .|
|SidTypeDomain|Indica um `SID`domínio .|
|SidTypeAlias|Indica um `SID`pseudônimo .|
|SidTypewellconhecido|Indica `SID` um para um grupo bem conhecido.|
|SidTypeExcluídoConta|Indica `SID` a para uma conta excluída.|
|SidTypeInvalid|Indica um `SID`inválido .|
|SidTypeUnknown|Indica um `SID` tipo desconhecido.|
|SidTypeComputer|Indica `SID` um para um computador.|

### <a name="remarks"></a>Comentários

Ligue para [CSid::LoadAccount](#loadaccount) para atualizar o `CSid` objeto antes de ligar `SidNameUse` para retornar seu estado. `SidNameUse`não altera o estado do objeto `LookupAccountName` (ligando para ou), `LookupAccountSid`mas apenas retorna o estado atual.

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)<br/>
[Operadores](../../atl/reference/atl-operators.md)
