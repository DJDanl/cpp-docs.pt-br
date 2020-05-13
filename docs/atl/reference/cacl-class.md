---
title: Classe cacls
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
ms.openlocfilehash: 3beef0fc6a75a952956f032d3e0e4cbe4faed86b
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168443"
---
# <a name="cacl-class"></a>Classe cacls

Essa classe é um wrapper para uma `ACL` estrutura (lista de controle de acesso).

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
class CAcl
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[Cacls:: CAccessMaskArray](#caccessmaskarray)|Uma matriz de ACCESS_MASKs.|
|[Cacls:: CAceFlagArray](#caceflagarray)|Uma matriz de BYTEs.|
|[Cacls:: CAceTypeArray](#cacetypearray)|Uma matriz de BYTEs.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Cacls:: cacls](#cacl)|O construtor.|
|[Cacls:: ~ cacls](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Cacls:: GetAceCount](#getacecount)|Retorna o número de objetos de ACE (Access-Control entry).|
|[Cacls:: GetAclEntries](#getaclentries)|Recupera as entradas da ACL (lista de controle de acesso) `CAcl` do objeto.|
|[Cacls:: GetAclEntry](#getaclentry)|Recupera todas as informações sobre uma entrada em um `CAcl` objeto.|
|[Cacls:: GetLength](#getlength)|Retorna o comprimento da ACL.|
|[Cacls:: GetPACL](#getpacl)|Retorna um PACL (ponteiro para uma ACL).|
|[Cacls:: IsEmpty](#isempty)|Testa o `CAcl` objeto para entradas.|
|[Cacls:: IsNull](#isnull)|Retorna o status do `CAcl` objeto.|
|[Cacls:: RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) do `CAcl` objeto.|
|[Cacls:: RemoveAces](#removeaces)|Remove todas as ACEs (entradas de controle de acesso) `CAcl` do que se aplicam `CSid`ao determinado.|
|[Cacls:: setempty](#setempty)|Marca o `CAcl` objeto como vazio.|
|[Cacls:: SetNull](#setnull)|Marca o `CAcl` objeto como nulo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[% Cacls:: operador const ACL *](#operator_const_acl__star)|Converte um `CAcl` objeto em uma `ACL` estrutura.|
|[Cacls:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

A `ACL` estrutura é o cabeçalho de uma ACL (lista de controle de acesso). Uma ACL inclui uma lista sequencial de zero ou mais [ACEs](/windows/win32/SecAuthZ/access-control-entries) (entradas de controle de acesso). As ACEs individuais em uma ACL são numeradas de 0 a *n-1*, em que *n* é o número de ACEs na ACL. Ao editar uma ACL, um aplicativo se refere a uma ACE (entrada de controle de acesso) dentro da ACL por seu índice.

Há dois tipos de ACL:

- DACL

- Sistema

Uma ACL discricionária é controlada pelo proprietário de um objeto ou por qualquer pessoa que tenha concedido WRITE_DAC acesso ao objeto. Especifica o acesso que usuários e grupos específicos podem ter a um objeto. Por exemplo, o proprietário de um arquivo pode usar uma ACL discricionária para controlar quais usuários e grupos podem e não podem ter acesso ao arquivo.

Um objeto também pode ter informações de segurança no nível do sistema associadas a ele, na forma de uma ACL do sistema controlada por um administrador do sistema. Uma ACL do sistema pode permitir que o administrador do sistema faça auditoria de qualquer tentativa de obter acesso a um objeto.

Para obter mais detalhes, consulte a discussão de [ACL](/windows/win32/SecAuthZ/access-control-lists) na SDK do Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="caclcaccessmaskarray"></a><a name="caccessmaskarray"></a>Cacls:: CAccessMaskArray

Uma matriz de objetos ACCESS_MASK.

```cpp
typedef CAtlArray<ACCESS_MASK> CAccessMaskArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz que pode ser usado para armazenar os direitos de acesso usados nas ACEs (entradas de controle de acesso).

## <a name="caclcaceflagarray"></a><a name="caceflagarray"></a>Cacls:: CAceFlagArray

Uma matriz de BYTEs.

```cpp
typedef CAtlArray<BYTE> CAceFlagArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir os sinalizadores de controle específicos do tipo ACE (Access-Control entry). Consulte a definição de [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter a lista completa de possíveis sinalizadores.

## <a name="caclcacetypearray"></a><a name="cacetypearray"></a>Cacls:: CAceTypeArray

Uma matriz de BYTEs.

```cpp
typedef CAtlArray<BYTE> CAceTypeArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir a natureza dos objetos ACE (Access-Control entry), como ACCESS_ALLOWED_ACE_TYPE ou ACCESS_DENIED_ACE_TYPE. Consulte a definição de [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter a lista completa de tipos possíveis.

## <a name="caclcacl"></a><a name="cacl"></a>Cacls:: cacls

O construtor.

```cpp
CAcl() throw();
CAcl(const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um objeto `CAcl` existente.

### <a name="remarks"></a>Comentários

O `CAcl` objeto pode ser criado opcionalmente usando um objeto `CAcl` existente.

## <a name="caclcacl"></a><a name="dtor"></a>Cacls:: ~ cacls

O destruidor.

```cpp
virtual ~CAcl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

## <a name="caclgetacecount"></a><a name="getacecount"></a>Cacls:: GetAceCount

Retorna o número de objetos de ACE (Access-Control entry).

```cpp
virtual UINT GetAceCount() const throw() = 0;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de entradas ACE no `CAcl` objeto.

## <a name="caclgetaclentries"></a><a name="getaclentries"></a>Cacls:: GetAclEntries

Recupera as entradas da ACL (lista de controle de acesso) `CAcl` do objeto.

```cpp
void GetAclEntries(
    CSid::CSidArray* pSids,
    CAccessMaskArray* pAccessMasks = NULL,
    CAceTypeArray* pAceTypes = NULL,
    CAceFlagArray* pAceFlags = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Um ponteiro para uma matriz de objetos [CSid](../../atl/reference/csid-class.md) .

*pAccessMasks*<br/>
As máscaras de acesso.

*pAceTypes*<br/>
Os tipos de ACE (Access-Control entry).

*pAceFlags*<br/>
Os sinalizadores de ACE.

### <a name="remarks"></a>Comentários

Esse método preenche os parâmetros de matriz com os detalhes de cada objeto ACE contido no `CAcl` objeto. Use NULL quando os detalhes dessa matriz específica não forem necessários.

O conteúdo de cada matriz corresponde um ao outro, ou seja, o primeiro elemento da `CAccessMaskArray` matriz corresponde ao primeiro elemento na `CSidArray` matriz e assim por diante.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter mais detalhes sobre os tipos e sinalizadores de Ace.

## <a name="caclgetaclentry"></a><a name="getaclentry"></a>Cacls:: GetAclEntry

Recupera todas as informações sobre uma entrada em uma ACL (lista de controle de acesso).

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
Índice para a entrada de ACL a ser recuperada.

*pSid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) ao qual a entrada ACL se aplica.

*pMask*<br/>
A máscara que especifica permissões para conceder ou negar acesso.

*pType*<br/>
O tipo ACE.

*pFlags*<br/>
Os sinalizadores de ACE.

*pObjectType*<br/>
O tipo de objeto. Isso será definido como GUID_NULL se o tipo de objeto não for especificado na ACE ou se a ACE não for uma ACE de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado. Isso será definido como GUID_NULL se o tipo de objeto herdado não for especificado na ACE ou se a ACE não for uma ACE de objeto.

### <a name="remarks"></a>Comentários

Esse método irá recuperar todas as informações sobre uma ACE individual, fornecendo mais informações do que o [cacls:: GetAclEntries](#getaclentries) sozinho disponibiliza.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter mais detalhes sobre os tipos e sinalizadores de Ace.

## <a name="caclgetlength"></a><a name="getlength"></a>Cacls:: GetLength

Retorna o comprimento da lista de controle de acesso (ACL).

```cpp
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento necessário em bytes necessários para manter a `ACL` estrutura.

## <a name="caclgetpacl"></a><a name="getpacl"></a>Cacls:: GetPACL

Retorna um ponteiro para uma lista de controle de acesso (ACL).

```cpp
const ACL* GetPACL() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a `ACL` estrutura.

## <a name="caclisempty"></a><a name="isempty"></a>Cacls:: IsEmpty

Testa o `CAcl` objeto para entradas.

```cpp
bool IsEmpty() const throw();
```

### <a name="remarks"></a>Comentários

Retornará TRUE se o `CAcl` objeto não for nulo e não contiver entradas. Retornará FALSE se o `CAcl` objeto for nulo ou contiver pelo menos uma entrada.

## <a name="caclisnull"></a><a name="isnull"></a>Cacls:: IsNull

Retorna o status do `CAcl` objeto.

```cpp
bool IsNull() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o `CAcl` objeto for nulo; caso contrário, false.

## <a name="cacloperator-const-acl-"></a><a name="operator_const_acl__star"></a>% Cacls:: operador const ACL *

Converte um `CAcl` objeto em uma `ACL` estrutura (lista de controle de acesso).

```cpp
operator const ACL *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço da `ACL` estrutura.

## <a name="cacloperator-"></a><a name="operator_eq"></a>Cacls:: Operator =

Operador de atribuição.

```cpp
CAcl& operator= (const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CAcl` a ser atribuído ao objeto existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto atualizado `CAcl` .

## <a name="caclremoveace"></a><a name="removeace"></a>Cacls:: RemoveAce

Remove uma ACE específica (entrada de controle de acesso) do `CAcl` objeto.

```cpp
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexe para a entrada ACE a ser removida.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray:: RemoveAt](../../atl/reference/catlarray-class.md#removeat).

## <a name="caclremoveaces"></a><a name="removeaces"></a>Cacls:: RemoveAces

Remove ACEs alls (entradas de controle de acesso) do `CAcl` que se aplicam ao `CSid`determinado.

```cpp
bool RemoveAces(const CSid& rSid) throw(...)
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Uma referência a um objeto `CSid`.

## <a name="caclsetempty"></a><a name="setempty"></a>Cacls:: setempty

Marca o `CAcl` objeto como vazio.

```cpp
void SetEmpty() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois Estados são distintos.

## <a name="caclsetnull"></a><a name="setnull"></a>Cacls:: SetNull

Marca o `CAcl` objeto como nulo.

```cpp
void SetNull() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois Estados são distintos.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
