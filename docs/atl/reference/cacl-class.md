---
title: Classe CAcl
ms.date: 11/04/2016
f1_keywords:
- CAcl
- ATLSECURITY/ATL::CAcl
- ATLSECURITY/ATL::CAcl::CAccessMaskArray
- ATLSECURITY/ATL::CAcl::CAceFlagArray
- ATLSECURITY/ATL::CAcl::CAceTypeArray
- ATLSECURITY/ATL::CAcl::CAcl
- ATLSECURITY/ATL::CAcl::GetAceCount
- ATLSECURITY/ATL::CAcl::GetAclEntries
- ATLSECURITY/ATL::CAcl::GetAclEntry
- ATLSECURITY/ATL::CAcl::GetLength
- ATLSECURITY/ATL::CAcl::GetPACL
- ATLSECURITY/ATL::CAcl::IsEmpty
- ATLSECURITY/ATL::CAcl::IsNull
- ATLSECURITY/ATL::CAcl::RemoveAce
- ATLSECURITY/ATL::CAcl::RemoveAces
- ATLSECURITY/ATL::CAcl::SetEmpty
- ATLSECURITY/ATL::CAcl::SetNull
helpviewer_keywords:
- CAcl class
ms.assetid: 20bcb9af-dc1c-4737-b923-3864776680d6
ms.openlocfilehash: 458f7cd50462a145d005f3f81d87cc06fc7e01b1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748777"
---
# <a name="cacl-class"></a>Classe CAcl

Esta classe é um `ACL` invólucro para uma estrutura (lista de controle de acesso).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAcl
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAcl::CAccessMaskArray](#caccessmaskarray)|Uma série de ACCESS_MASKs.|
|[CAcl::CAceFlagArray](#caceflagarray)|Uma matriz de BYTEs.|
|[CAcl::CAceTypeArray](#cacetypearray)|Uma matriz de BYTEs.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAcl::CAcl](#cacl)|O construtor.|
|[CAcl::~CAcl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAcl::GetAceCount](#getacecount)|Retorna o número de objetos ace (access-control entry) de entrada de acesso.|
|[CAcl::GetAclEntries](#getaclentries)|Recupera as entradas a célquanto da `CAcl` lista de controle de acesso (ACL) do objeto.|
|[CAcl::GetAclEntry](#getaclentry)|Recupera todas as informações sobre uma `CAcl` entrada em um objeto.|
|[CAcl::GetLength](#getlength)|Retorna o comprimento da ACL.|
|[CAcl::GetPACL](#getpacl)|Retorna um PACL (ponteiro para uma ACL).|
|[CAcl::IsEmpty](#isempty)|Testa `CAcl` o objeto para entradas.|
|[CAcl::IsNull](#isnull)|Retorna o status `CAcl` do objeto.|
|[CAcl::RemoveAce](#removeace)|Remove um ACE específico (entrada de `CAcl` controle de acesso) do objeto.|
|[CAcl::RemoveAces](#removeaces)|Remove todas as ACEs (entradas de `CAcl` controle de `CSid`acesso) das que se aplicam ao dado .|
|[CAcl::SetEmpty](#setempty)|Marca `CAcl` o objeto como vazio.|
|[CAcl::SetNull](#setnull)|Marca `CAcl` o objeto como NULO.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAcl::operador const ACL *](#operator_const_acl__star)|Lança um `CAcl` objeto `ACL` para uma estrutura.|
|[CAcl::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

A `ACL` estrutura é o cabeçalho de uma ACL (lista de controle de acesso). Uma ACL inclui uma lista seqüencial de Zero ou mais [ACEs](/windows/win32/SecAuthZ/access-control-entries) (entradas de controle de acesso). As ACEs individuais em uma ACL são numeradas de 0 a *n-1*, onde *n* é o número de ACEs na ACL. Ao editar uma ACL, um aplicativo refere-se a uma entrada de controle de acesso (ACE) dentro da ACL pelo seu índice.

Existem dois tipos de ACL:

- Discricionário

- Sistema

Uma ACL discricionária é controlada pelo proprietário de um objeto ou qualquer pessoa que tenha acesso WRITE_DAC ao objeto. Ele especifica o acesso que determinados usuários e grupos podem ter a um objeto. Por exemplo, o proprietário de um arquivo pode usar uma ACL discricionária para controlar quais usuários e grupos podem e não podem ter acesso ao arquivo.

Um objeto também pode ter informações de segurança em nível de sistema associadas a ele, na forma de um sistema ACL controlado por um administrador do sistema. Uma ACL do sistema pode permitir que o administrador do sistema audite quaisquer tentativas de obter acesso a um objeto.

Para obter mais detalhes, consulte a discussão [da ACL](/windows/win32/SecAuthZ/access-control-lists) no SDK do Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="caclcaccessmaskarray"></a><a name="caccessmaskarray"></a>CAcl::CAccessMaskArray

Uma série de objetos ACCESS_MASK.

```
typedef CAtlArray<ACCESS_MASK> CAccessMaskArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz que pode ser usado para armazenar direitos de acesso usados em entradas de controle de acesso (ACEs).

## <a name="caclcaceflagarray"></a><a name="caceflagarray"></a>CAcl::CAceFlagArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceFlagArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir os sinalizadores de controle de entrada de acesso (ACE) específicos do tipo ACE. Veja a [definição ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para a lista completa de possíveis bandeiras.

## <a name="caclcacetypearray"></a><a name="cacetypearray"></a>CAcl::CAceTypeArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceTypeArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir a natureza dos objetos ACE (Access-Control Entry, entrada de controle de acesso), como ACCESS_ALLOWED_ACE_TYPE ou ACCESS_DENIED_ACE_TYPE. Veja a [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) definição para a lista completa de possíveis tipos.

## <a name="caclcacl"></a><a name="cacl"></a>CAcl::CAcl

O construtor.

```
CAcl() throw();
CAcl(const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um objeto `CAcl` existente.

### <a name="remarks"></a>Comentários

O `CAcl` objeto pode ser criado opcionalmente `CAcl` usando um objeto existente.

## <a name="caclcacl"></a><a name="dtor"></a>CAcl::~CAcl

O destruidor.

```
virtual ~CAcl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

## <a name="caclgetacecount"></a><a name="getacecount"></a>CAcl::GetAceCount

Retorna o número de objetos ace (access-control entry) de entrada de acesso.

```
virtual UINT GetAceCount() const throw() = 0;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de entradas ACE no `CAcl` objeto.

## <a name="caclgetaclentries"></a><a name="getaclentries"></a>CAcl::GetAclEntries

Recupera as entradas a célquanto da `CAcl` lista de controle de acesso (ACL) do objeto.

```cpp
void GetAclEntries(
    CSid::CSidArray* pSids,
    CAccessMaskArray* pAccessMasks = NULL,
    CAceTypeArray* pAceTypes = NULL,
    CAceFlagArray* pAceFlags = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Um ponteiro para uma matriz de objetos [CSid.](../../atl/reference/csid-class.md)

*pAccessMasks*<br/>
As máscaras de acesso.

*pAceTypes*<br/>
Os tipos ace (access-control entry, entrada de controle de acesso).

*pAceFlags*<br/>
As bandeiras ace.

### <a name="remarks"></a>Comentários

Este método preenche os parâmetros da matriz com `CAcl` os detalhes de cada objeto ACE contido no objeto. Use NULL quando os detalhes dessa matriz em particular não forem necessários.

O conteúdo de cada matriz corresponde entre si, `CAccessMaskArray` ou seja, o primeiro `CSidArray` elemento da matriz corresponde ao primeiro elemento na matriz, e assim por diante.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter mais detalhes sobre os tipos de ACE e bandeiras.

## <a name="caclgetaclentry"></a><a name="getaclentry"></a>CAcl::GetAclEntry

Recupera todas as informações sobre uma entrada em uma lista de controle de acesso (ACL).

```cpp
void GetAclEntry(
    UINT nIndex,
    CSid* pSid,
    ACCESS_MASK* pMask = NULL,
    BYTE* pType = NULL,
    BYTE* pFlags = NULL,
    GUID* pObjectType = NULL,
    GUID* pInheritedObjectType = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexar a entrada ACL para recuperar.

*Psid*<br/>
O [objeto CSid](../../atl/reference/csid-class.md) ao qual a entrada ACL se aplica.

*pMask*<br/>
A máscara especificando permissões para conceder ou negar acesso.

*Ptype*<br/>
O tipo ACE.

*pFlags*<br/>
As bandeiras ace.

*pObjectType*<br/>
O tipo de objeto. Isso será definido como GUID_NULL se o tipo de objeto não estiver especificado no ACE ou se o ACE não for um ACE object.

*pInheritedObjectType*<br/>
O tipo de objeto herdado. Isso será definido para GUID_NULL se o tipo de objeto herdado não for especificado no ACE ou se o ACE não for um ACE object.

### <a name="remarks"></a>Comentários

Este método recuperará todas as informações sobre um ACE individual, fornecendo mais informações do que [cacl::GetAclEntries](#getaclentries) sozinho disponibiliza.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter mais detalhes sobre os tipos de ACE e bandeiras.

## <a name="caclgetlength"></a><a name="getlength"></a>CAcl::GetLength

Retorna o comprimento da lista de controle de acesso (ACL).

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento necessário em bytes necessários para segurar a `ACL` estrutura.

## <a name="caclgetpacl"></a><a name="getpacl"></a>CAcl::GetPACL

Retorna um ponteiro para uma lista de controle de acesso (ACL).

```
const ACL* GetPACL() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Devolve um ponteiro `ACL` para a estrutura.

## <a name="caclisempty"></a><a name="isempty"></a>CAcl::IsEmpty

Testa `CAcl` o objeto para entradas.

```
bool IsEmpty() const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE `CAcl` se o objeto não for NULO e não houver entradas. Retorna FALSO `CAcl` se o objeto for NULO ou contiver pelo menos uma entrada.

## <a name="caclisnull"></a><a name="isnull"></a>CAcl::IsNull

Retorna o status `CAcl` do objeto.

```
bool IsNull() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE `CAcl` se o objeto for NULO, FALSO de outra forma.

## <a name="cacloperator-const-acl-"></a><a name="operator_const_acl__star"></a>CAcl::operador const ACL *

Lança um `CAcl` objeto `ACL` para uma estrutura (lista de controle de acesso).

```
operator const ACL *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço `ACL` da estrutura.

## <a name="cacloperator-"></a><a name="operator_eq"></a>CAcl::operador =

Operador de atribuição.

```
CAcl& operator= (const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CAcl` para atribuir ao objeto existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CAcl` ao objeto atualizado.

## <a name="caclremoveace"></a><a name="removeace"></a>CAcl::RemoveAce

Remove um ACE específico (entrada de `CAcl` controle de acesso) do objeto.

```cpp
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexar a entrada ACE para remover.

### <a name="remarks"></a>Comentários

Este método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

## <a name="caclremoveaces"></a><a name="removeaces"></a>CAcl::RemoveAces

Remove todas as ACEs (entradas de `CAcl` controle de acesso) das que se aplicam ao dado `CSid`.

```
bool RemoveAces(const CSid& rSid) throw(...)
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Uma referência a um objeto `CSid`.

## <a name="caclsetempty"></a><a name="setempty"></a>CAcl::SetEmpty

Marca `CAcl` o objeto como vazio.

```cpp
void SetEmpty() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois estados são distintos.

## <a name="caclsetnull"></a><a name="setnull"></a>CAcl::SetNull

Marca `CAcl` o objeto como NULO.

```cpp
void SetNull() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois estados são distintos.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
