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
ms.openlocfilehash: 05d9d5fe9cc344be3f903f247f34003056404c9d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258561"
---
# <a name="cacl-class"></a>Classe CAcl

Essa classe é um wrapper para um `ACL` estrutura (lista de controle de acesso).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAcl
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAcl::CAccessMaskArray](#caccessmaskarray)|Uma matriz de ACCESS_MASKs.|
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
|[CAcl::GetAceCount](#getacecount)|Retorna o número de controle de acesso a objetos ACE (entrada).|
|[CAcl::GetAclEntries](#getaclentries)|Recupera as entradas ACL (lista) de controle de acesso do `CAcl` objeto.|
|[CAcl::GetAclEntry](#getaclentry)|Recupera todas as informações sobre uma entrada em um `CAcl` objeto.|
|[CAcl::GetLength](#getlength)|Retorna o comprimento da ACL.|
|[CAcl::GetPACL](#getpacl)|Retorna um PACL (ponteiro para uma ACL).|
|[CAcl::IsEmpty](#isempty)|Testes de `CAcl` objeto para as entradas.|
|[CAcl::IsNull](#isnull)|Retorna o status do `CAcl` objeto.|
|[CAcl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) a `CAcl` objeto.|
|[CAcl::RemoveAces](#removeaces)|Remove todas as ACEs (entradas de controle de acesso) a `CAcl` que se aplicam à determinado `CSid`.|
|[CAcl::SetEmpty](#setempty)|As marcas de `CAcl` do objeto como vazio.|
|[CAcl::SetNull](#setnull)|As marcas de `CAcl` objeto como NULL.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[ACL de CAcl::operator const *](#operator_const_acl__star)|Conversões de um `CAcl` do objeto para um `ACL` estrutura.|
|[CAcl::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

O `ACL` estrutura é o cabeçalho de uma ACL (lista de controle de acesso). Uma ACL inclui uma lista sequencial de zero ou mais [ACEs](/windows/desktop/SecAuthZ/access-control-entries) (entradas de controle de acesso). As ACEs individuais em uma ACL são numeradas de 0 a *n-1*, onde *n* é o número de ACEs na ACL. Ao editar uma ACL, um aplicativo se refere a uma entrada de controle de acesso (ACE) na ACL por seu índice.

Há dois tipos ACL:

- Discricionário

- Sistema

Uma ACL discricionária é controlada pelo proprietário de um objeto ou qualquer pessoa que concedeu acesso WRITE_DAC no objeto. Ele especifica que os usuários de acesso específico e grupos podem ter a um objeto. Por exemplo, o proprietário de um arquivo pode usar uma ACL discricionária para controlar quais usuários e grupos podem e não pode ter acesso ao arquivo.

Um objeto também pode ter informações de segurança em nível de sistema associadas a ele, na forma de um sistema de ACL controlado por um administrador do sistema. Um ACL de sistema pode permitir que o administrador do sistema qualquer tentativa de obter acesso a um objeto de auditoria.

Para obter mais detalhes, consulte o [ACL](/windows/desktop/SecAuthZ/access-control-lists) discussão no SDK do Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="caccessmaskarray"></a>  CAcl::CAccessMaskArray

Uma matriz de objetos ACCESS_MASK.

```
typedef CAtlArray<ACCESS_MASK> CAccessMaskArray;
```

### <a name="remarks"></a>Comentários

Este typedef Especifica o tipo de matriz que pode ser usado para armazenar os direitos de acesso usados nas entradas de controle de acesso (ACEs).

##  <a name="caceflagarray"></a>  CAcl::CAceFlagArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceFlagArray;
```

### <a name="remarks"></a>Comentários

Este typedef Especifica o tipo de matriz usado para definir os sinalizadores de controle específicos do tipo ACE (entrada) controle de acesso. Consulte a [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) definição para a lista completa dos sinalizadores possíveis.

##  <a name="cacetypearray"></a>  CAcl::CAceTypeArray

Uma matriz de BYTEs.

```
typedef CAtlArray<BYTE> CAceTypeArray;
```

### <a name="remarks"></a>Comentários

Este typedef Especifica o tipo de matriz usado para definir a natureza dos objetos ACE (entrada) do controle de acesso, como ACCESS_ALLOWED_ACE_TYPE ou ACCESS_DENIED_ACE_TYPE. Consulte a [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) definição para a lista completa de tipos possíveis.

##  <a name="cacl"></a>  CAcl::CAcl

O construtor.

```
CAcl() throw();
CAcl(const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um objeto `CAcl` existente.

### <a name="remarks"></a>Comentários

O `CAcl` objeto pode ser criado, opcionalmente, usar um existente `CAcl` objeto.

##  <a name="dtor"></a>  CAcl::~CAcl

O destruidor.

```
virtual ~CAcl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto.

##  <a name="getacecount"></a>  CAcl::GetAceCount

Retorna o número de controle de acesso a objetos ACE (entrada).

```
virtual UINT GetAceCount() const throw() = 0;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de entradas ACE no `CAcl` objeto.

##  <a name="getaclentries"></a>  CAcl::GetAclEntries

Recupera as entradas ACL (lista) de controle de acesso do `CAcl` objeto.

```
void GetAclEntries(
    CSid::CSidArray* pSids,
    CAccessMaskArray* pAccessMasks = NULL,
    CAceTypeArray* pAceTypes = NULL,
    CAceFlagArray* pAceFlags = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Um ponteiro para uma matriz de [CSid](../../atl/reference/csid-class.md) objetos.

*pAccessMasks*<br/>
As máscaras de acesso.

*pAceTypes*<br/>
Os tipos ACE (entrada) do controle de acesso.

*pAceFlags*<br/>
Os sinalizadores da ACE.

### <a name="remarks"></a>Comentários

Esse método preenche os parâmetros de matriz com os detalhes de cada objeto ACE contido no `CAcl` objeto. Use NULL quando os detalhes para essa matriz específica não são necessários.

O conteúdo de cada matriz corresponde uns aos outros, ou seja, o primeiro elemento do `CAccessMaskArray` matriz corresponde ao primeiro elemento no `CSidArray` matriz e assim por diante.

Ver [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) para obter mais detalhes sobre os tipos ACE e sinalizadores.

##  <a name="getaclentry"></a>  CAcl::GetAclEntry

Recupera todas as informações sobre uma entrada em uma lista de controle de acesso (ACL).

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

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice para a entrada ACL para recuperar.

*pSid*<br/>
O [CSid](../../atl/reference/csid-class.md) do objeto ao qual a entrada ACL se aplica.

*pMask*<br/>
A máscara especificando permissões para conceder ou negar acesso.

*pType*<br/>
O tipo ACE.

*pFlags*<br/>
Os sinalizadores da ACE.

*pObjectType*<br/>
O tipo de objeto. Isso será definido para GUID_NULL se o tipo de objeto não for especificado na ACE, ou se a ACE não é uma ACE de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado. Isso será definido para GUID_NULL se o tipo de objeto herdado não for especificado na ACE, ou se a ACE não é uma ACE de objeto.

### <a name="remarks"></a>Comentários

Esse método irá recuperar todas as informações sobre uma ACE individual, fornecendo mais informações do que [CAcl::GetAclEntries](#getaclentries) sozinho torna disponível.

Ver [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) para obter mais detalhes sobre os tipos ACE e sinalizadores.

##  <a name="getlength"></a>  CAcl::GetLength

Retorna o comprimento da lista de controle de acesso (ACL).

```
UINT GetLength() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o tamanho necessário em bytes necessário para manter o `ACL` estrutura.

##  <a name="getpacl"></a>  CAcl::GetPACL

Retorna um ponteiro para uma lista de controle de acesso (ACL).

```
const ACL* GetPACL() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o `ACL` estrutura.

##  <a name="isempty"></a>  CAcl::IsEmpty

Testes de `CAcl` objeto para as entradas.

```
bool IsEmpty() const throw();
```

### <a name="remarks"></a>Comentários

Retorna VERDADEIRO se o `CAcl` objeto não for nulo e não contém entradas. Retornará FALSE se o `CAcl` objeto é NULL ou contém pelo menos uma entrada.

##  <a name="isnull"></a>  CAcl::IsNull

Retorna o status do `CAcl` objeto.

```
bool IsNull() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o `CAcl` objeto for nulo, FALSO caso contrário.

##  <a name="operator_const_acl__star"></a>  ACL de CAcl::operator const *

Conversões de um `CAcl` do objeto para um `ACL` estrutura (lista de controle de acesso).

```
operator const ACL *() const throw(...);
```

### <a name="remarks"></a>Comentários

Retorna o endereço do `ACL` estrutura.

##  <a name="operator_eq"></a>  CAcl::operator =

Operador de atribuição.

```
CAcl& operator= (const CAcl& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CAcl` para atribuir ao objeto existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a atualização `CAcl` objeto.

##  <a name="removeace"></a>  CAcl::RemoveAce

Remove uma ACE específica (entrada de controle de acesso) a `CAcl` objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice para a entrada do ACE a ser removido.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeaces"></a>  CAcl::RemoveAces

Remove a todos as ACEs (entradas de controle de acesso) a `CAcl` que se aplicam à determinado `CSid`.

```
bool RemoveAces(const CSid& rSid) throw(...)
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Uma referência a um objeto `CSid`.

##  <a name="setempty"></a>  CAcl::SetEmpty

As marcas de `CAcl` do objeto como vazio.

```
void SetEmpty() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou como NULL: os dois estados são diferentes.

##  <a name="setnull"></a>  CAcl::SetNull

As marcas de `CAcl` objeto como NULL.

```
void SetNull() throw();
```

### <a name="remarks"></a>Comentários

O `CAcl` pode ser definido como vazio ou como NULL: os dois estados são diferentes.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
