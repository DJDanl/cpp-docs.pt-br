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
ms.openlocfilehash: 5d03154597f800042846e82d0a0cf5e7c46b613f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418142"
---
# <a name="cacl-class"></a>Classe cacls

Essa classe é um wrapper para uma estrutura de `ACL` (lista de controle de acesso).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CAcl
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cacls:: CAccessMaskArray](#caccessmaskarray)|Uma matriz de ACCESS_MASKs.|
|[Cacls:: CAceFlagArray](#caceflagarray)|Uma matriz de BYTEs.|
|[Cacls:: CAceTypeArray](#cacetypearray)|Uma matriz de BYTEs.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cacls:: cacls](#cacl)|O construtor.|
|[Cacls:: ~ cacls](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cacls:: GetAceCount](#getacecount)|Retorna o número de objetos de ACE (Access-Control entry).|
|[Cacls:: GetAclEntries](#getaclentries)|Recupera as entradas da ACL (lista de controle de acesso) do objeto `CAcl`.|
|[Cacls:: GetAclEntry](#getaclentry)|Recupera todas as informações sobre uma entrada em um objeto `CAcl`.|
|[Cacls:: GetLength](#getlength)|Retorna o comprimento da ACL.|
|[Cacls:: GetPACL](#getpacl)|Retorna um PACL (ponteiro para uma ACL).|
|[Cacls:: IsEmpty](#isempty)|Testa o objeto `CAcl` para entradas.|
|[Cacls:: IsNull](#isnull)|Retorna o status do objeto `CAcl`.|
|[Cacls:: RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) do objeto `CAcl`.|
|[Cacls:: RemoveAces](#removeaces)|Remove todas as ACEs (entradas de controle de acesso) da `CAcl` que se aplicam ao `CSid`especificado.|
|[Cacls:: setempty](#setempty)|Marca o objeto `CAcl` como vazio.|
|[Cacls:: SetNull](#setnull)|Marca o objeto `CAcl` como nulo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[% Cacls:: operador const ACL *](#operator_const_acl__star)|Converte um objeto `CAcl` em uma estrutura de `ACL`.|
|[Cacls:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

A estrutura de `ACL` é o cabeçalho de uma ACL (lista de controle de acesso). Uma ACL inclui uma lista sequencial de zero ou mais [ACEs](/windows/win32/SecAuthZ/access-control-entries) (entradas de controle de acesso). As ACEs individuais em uma ACL são numeradas de 0 a *n-1*, em que *n* é o número de ACEs na ACL. Ao editar uma ACL, um aplicativo se refere a uma ACE (entrada de controle de acesso) dentro da ACL por seu índice.

Há dois tipos de ACL:

- DACL

- Sistema

Uma ACL discricionária é controlada pelo proprietário de um objeto ou por qualquer pessoa que tenha concedido WRITE_DAC acesso ao objeto. Especifica o acesso que usuários e grupos específicos podem ter a um objeto. Por exemplo, o proprietário de um arquivo pode usar uma ACL discricionária para controlar quais usuários e grupos podem e não podem ter acesso ao arquivo.

Um objeto também pode ter informações de segurança no nível do sistema associadas a ele, na forma de uma ACL do sistema controlada por um administrador do sistema. Uma ACL do sistema pode permitir que o administrador do sistema faça auditoria de qualquer tentativa de obter acesso a um objeto.

Para obter mais detalhes, consulte a discussão de [ACL](/windows/win32/SecAuthZ/access-control-lists) na SDK do Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="caccessmaskarray"></a>Cacls:: CAccessMaskArray

Uma matriz de objetos ACCESS_MASK.

```
typedef CAtlArray<ACCESS_MASK> CAccessMaskArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz que pode ser usado para armazenar os direitos de acesso usados nas ACEs (entradas de controle de acesso).

##  <a name="caceflagarray"></a>Cacls:: CAceFlagArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceFlagArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir os sinalizadores de controle específicos do tipo ACE (Access-Control entry). Consulte a definição de [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter a lista completa de possíveis sinalizadores.

##  <a name="cacetypearray"></a>Cacls:: CAceTypeArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceTypeArray;
```

### <a name="remarks"></a>Comentários

Este typedef especifica o tipo de matriz usado para definir a natureza dos objetos ACE (Access-Control entry), como ACCESS_ALLOWED_ACE_TYPE ou ACCESS_DENIED_ACE_TYPE. Consulte a definição de [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter a lista completa de tipos possíveis.

##  <a name="cacl"></a>Cacls:: cacls

O construtor.

```
CAcl() throw();
CAcl(const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>parâmetros

*rhs*<br/>
Um objeto `CAcl` existente.

### <a name="remarks"></a>Comentários

O objeto `CAcl` pode ser criado opcionalmente usando um objeto `CAcl` existente.

##  <a name="dtor"></a>Cacls:: ~ cacls

O destruidor.

```
virtual ~CAcl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

##  <a name="getacecount"></a>Cacls:: GetAceCount

Retorna o número de objetos de ACE (Access-Control entry).

```
virtual UINT GetAceCount() const throw() = 0;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de entradas ACE no objeto `CAcl`.

##  <a name="getaclentries"></a>Cacls:: GetAclEntries

Recupera as entradas da ACL (lista de controle de acesso) do objeto `CAcl`.

```
void GetAclEntries(
    CSid::CSidArray* pSids,
    CAccessMaskArray* pAccessMasks = NULL,
    CAceTypeArray* pAceTypes = NULL,
    CAceFlagArray* pAceFlags = NULL) const throw(...);
```

### <a name="parameters"></a>parâmetros

*pSids*<br/>
Um ponteiro para uma matriz de objetos [CSid](../../atl/reference/csid-class.md) .

*pAccessMasks*<br/>
As máscaras de acesso.

*pAceTypes*<br/>
Os tipos de ACE (Access-Control entry).

*pAceFlags*<br/>
Os sinalizadores de ACE.

### <a name="remarks"></a>Comentários

Esse método preenche os parâmetros de matriz com os detalhes de cada objeto ACE contido no objeto `CAcl`. Use NULL quando os detalhes dessa matriz específica não forem necessários.

O conteúdo de cada matriz corresponde um ao outro, ou seja, o primeiro elemento da matriz de `CAccessMaskArray` corresponde ao primeiro elemento na matriz de `CSidArray` e assim por diante.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter mais detalhes sobre os tipos e sinalizadores de Ace.

##  <a name="getaclentry"></a>Cacls:: GetAclEntry

Recupera todas as informações sobre uma entrada em uma ACL (lista de controle de acesso).

```
void GetAclEntry(
    UINT nIndex,
    CSid* pSid,
    ACCESS_MASK* pMask = NULL,
    BYTE* pType = NULL,
    BYTE* pFlags = NULL,
    GUID* pObjectType = NULL,
    GUID* pInheritedObjectType = NULL) const throw(...);
```

### <a name="parameters"></a>parâmetros

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

##  <a name="getlength"></a>Cacls:: GetLength

Retorna o comprimento da lista de controle de acesso (ACL).

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento necessário em bytes necessários para manter a estrutura de `ACL`.

##  <a name="getpacl"></a>Cacls:: GetPACL

Retorna um ponteiro para uma lista de controle de acesso (ACL).

```
const ACL* GetPACL() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura de `ACL`.

##  <a name="isempty"></a>Cacls:: IsEmpty

Testa o objeto `CAcl` para entradas.

```
bool IsEmpty() const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o objeto `CAcl` não é nulo e não contém entradas. Retorna FALSE se o objeto `CAcl` é nulo ou contém pelo menos uma entrada.

##  <a name="isnull"></a>Cacls:: IsNull

Retorna o status do objeto `CAcl`.

```
bool IsNull() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o objeto `CAcl` for NULL; caso contrário, FALSE.

##  <a name="operator_const_acl__star"></a>% Cacls:: operador const ACL *

Converte um objeto `CAcl` em uma estrutura de `ACL` (lista de controle de acesso).

```
operator const ACL *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço da estrutura de `ACL`.

##  <a name="operator_eq"></a>Cacls:: Operator =

Operador de atribuição.

```
CAcl& operator= (const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>parâmetros

*rhs*<br/>
O `CAcl` a ser atribuído ao objeto existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto de `CAcl` atualizado.

##  <a name="removeace"></a>Cacls:: RemoveAce

Remove uma ACE específica (entrada de controle de acesso) do objeto `CAcl`.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Indexe para a entrada ACE a ser removida.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray:: RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeaces"></a>Cacls:: RemoveAces

Remove as ACEs alls (entradas de controle de acesso) da `CAcl` que se aplicam ao `CSid`especificado.

```
bool RemoveAces(const CSid& rSid) throw(...)
```

### <a name="parameters"></a>parâmetros

*rSid*<br/>
Uma referência a um objeto `CSid`.

##  <a name="setempty"></a>Cacls:: setempty

Marca o objeto `CAcl` como vazio.

```
void SetEmpty() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois Estados são distintos.

##  <a name="setnull"></a>Cacls:: SetNull

Marca o objeto `CAcl` como nulo.

```
void SetNull() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou nulo: os dois Estados são distintos.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
