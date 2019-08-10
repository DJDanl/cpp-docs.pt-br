---
title: Classe CDacl
ms.date: 11/04/2016
f1_keywords:
- CDacl
- ATLSECURITY/ATL::CDacl
- ATLSECURITY/ATL::CDacl::CDacl
- ATLSECURITY/ATL::CDacl::AddAllowedAce
- ATLSECURITY/ATL::CDacl::AddDeniedAce
- ATLSECURITY/ATL::CDacl::GetAceCount
- ATLSECURITY/ATL::CDacl::RemoveAce
- ATLSECURITY/ATL::CDacl::RemoveAllAces
helpviewer_keywords:
- CDacl class
ms.assetid: 2dc76616-6362-4967-b6cf-e2d39ca37ddd
ms.openlocfilehash: 2bc962407bac947f475368b43f5039bca3c1da1e
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915810"
---
# <a name="cdacl-class"></a>Classe CDacl

Essa classe é um wrapper para uma estrutura DACL (lista de controle de acesso condicional).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CDacl : public CAcl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::CDacl](#cdacl)|O construtor.|
|[CDacl:: ~ CDacl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::AddAllowedAce](#addallowedace)|Adiciona uma ACE permitida (entrada de controle de acesso) ao `CDacl` objeto.|
|[CDacl::AddDeniedAce](#adddeniedace)|Adiciona uma ACE negada ao `CDacl` objeto.|
|[CDacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas de controle de acesso) no `CDacl` objeto.|
|[CDacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) do `CDacl` objeto.|
|[CDacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CDacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

O descritor de segurança de um objeto pode conter uma DACL. Uma DACL contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Se uma DACL estiver vazia (ou seja, ela contiver zero ACEs), nenhum acesso será explicitamente concedido, portanto o acesso será negado implicitamente. No entanto, se o descritor de segurança de um objeto não tiver uma DACL, o objeto será desprotegido e todos terão acesso completo.

Para recuperar a DACL de um objeto, você deve ser o proprietário do objeto ou ter acesso READ_CONTROL ao objeto. Para alterar a DACL de um objeto, você deve ter acesso WRITE_DAC ao objeto.

Use os métodos de classe fornecidos para criar, adicionar, remover e excluir ACEs do `CDacl` objeto. Consulte também [AtlGetDacl](security-global-functions.md#atlgetdacl) e [AtlSetDacl](security-global-functions.md#atlsetdacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cacls](../../atl/reference/cacl-class.md)

`CDacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="addallowedace"></a>  CDacl::AddAllowedAce

Adiciona uma ACE permitida (entrada de controle de acesso) ao `CDacl` objeto.

```
bool AddAllowedAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags = 0) throw(...);

bool AddAllowedAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Um objeto [CSid](../../atl/reference/csid-class.md) .

*AccessMask*<br/>
Especifica a máscara de direitos de acesso a ser permitida para o `CSid` objeto especificado.

*AceFlags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança da ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retornará true se a Ace for adicionada ao `CDacl` objeto, false em caso de falha.

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Esse método adiciona uma ACE que permite o `CDacl` acesso ao objeto.

Consulte [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidos no `AceFlags` parâmetro.

##  <a name="adddeniedace"></a>  CDacl::AddDeniedAce

Adiciona uma ACE negada (entrada de controle de acesso) `CDacl` ao objeto.

```
bool AddDeniedAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags = 0) throw(...);

bool AddDeniedAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Um objeto `CSid`.

*AccessMask*<br/>
Especifica a máscara de direitos de acesso a ser negada para `CSid` o objeto especificado.

*AceFlags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança da ACE. O padrão é 0 na primeira forma do método.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retornará true se a Ace for adicionada ao `CDacl` objeto, false em caso de falha.

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Esse método adiciona uma ACE que nega o `CDacl` acesso ao objeto.

Consulte [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidos no `AceFlags` parâmetro.

##  <a name="cdacl"></a>  CDacl::CDacl

O construtor.

```
CDacl (const ACL& rhs) throw(...);
CDacl () throw();
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Uma estrutura `ACL` existente (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CDacl` objeto pode ser criado opcionalmente usando uma estrutura `ACL` existente. É importante observar que apenas uma DACL (lista de controle de acesso condicional) e não uma SACL (lista de controle de acesso do sistema) deve ser passada como esse parâmetro. Em compilações de depuração, a passagem de uma SACL causará uma declaração. Em compilações de versão, a passagem de uma SACL fará com que as ACEs (entradas de controle de acesso) na ACL sejam ignoradas e nenhum erro ocorrerá.

##  <a name="dtor"></a>  CDacl::~CDacl

O destruidor.

```
~CDacl () throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso) usando [CDacl:: RemoveAllAces](#removeallaces).

##  <a name="getacecount"></a>  CDacl::GetAceCount

Retorna o número de ACEs (entradas de controle de acesso) no `CDacl` objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de ACEs contidas no `CDacl` objeto.

##  <a name="operator_eq"></a>CDacl:: Operator =

Operador de atribuição.

```
CDacl& operator= (const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A ACL (lista de controle de acesso) a ser atribuída ao objeto existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao objeto atualizado `CDacl` .

### <a name="remarks"></a>Comentários

Você deve garantir que você passe apenas uma DACL (lista de controle de acesso discricionário) para essa função. Passar uma SACL (lista de controle de acesso do sistema) para essa função causará uma declaração em builds de depuração, mas não causará nenhum erro nas compilações de versão.

##  <a name="removeace"></a>  CDacl::RemoveAce

Remove uma ACE específica (entrada de controle de acesso) do `CDacl` objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexe para a entrada ACE a ser removida.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray:: RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeallaces"></a>  CDacl::RemoveAllAces

Remove todas as ACEs (entradas de controle de acesso) contidas no `CDacl` objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove toda `ACE` estrutura (entrada de controle de acesso) (se houver) `CDacl` no objeto.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/desktop/SecAuthZ/access-control-lists)<br/>
[Ases](/windows/desktop/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
