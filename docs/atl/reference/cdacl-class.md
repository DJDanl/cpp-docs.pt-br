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
ms.openlocfilehash: 1540c90e3538d763708e161ba6c1a5e459bb2bdf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327145"
---
# <a name="cdacl-class"></a>Classe CDacl

Esta classe é um invólucro para uma estrutura DACL (lista de controle de acesso discricionário).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CDacl : public CAcl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::CDacl](#cdacl)|O construtor.|
|[CDacl::~CDacl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::AddAllowedAce](#addallowedace)|Adiciona um ACE (entrada de controle `CDacl` de acesso) permitido ao objeto.|
|[CDacl::AddDeniedAce](#adddeniedace)|Adiciona um ACE `CDacl` negado ao objeto.|
|[CDacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas `CDacl` de controle de acesso) no objeto.|
|[CDacl::RemoveAce](#removeace)|Remove um ACE específico (entrada de `CDacl` controle de acesso) do objeto.|
|[CDacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CDacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

O descritor de segurança de um objeto pode conter um DACL. Um DACL contém Zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Se um DACL estiver vazio (ou seja, ele contém zero ACEs), nenhum acesso é explicitamente concedido, então o acesso é implicitamente negado. No entanto, se o descritor de segurança de um objeto não tiver um DACL, o objeto está desprotegido e todos têm acesso completo.

Para recuperar o DACL de um objeto, você deve ser o proprietário do objeto ou ter acesso READ_CONTROL ao objeto. Para alterar o DACL de um objeto, você deve ter acesso WRITE_DAC ao objeto.

Use os métodos de classe fornecidos para criar, adicionar, `CDacl` remover e excluir ACEs do objeto. Veja também [AtlGetDacl](security-global-functions.md#atlgetdacl) e [AtlSetDacl](security-global-functions.md#atlsetdacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cacl](../../atl/reference/cacl-class.md)

`CDacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="cdacladdallowedace"></a><a name="addallowedace"></a>CDacl::AddAllowedAce

Adiciona um ACE (entrada de controle `CDacl` de acesso) permitido ao objeto.

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
Um objeto [CSid.](../../atl/reference/csid-class.md)

*Accessmask*<br/>
Especifica a máscara dos direitos de acesso `CSid` a ser permitida para o objeto especificado.

*Aceflags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o ACE `CDacl` for adicionado ao objeto, FALSE on failure( FALSO/ FALSO).

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém Zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona um ACE `CDacl` que permite o acesso ao objeto.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter uma descrição das várias bandeiras que podem ser definidas no `AceFlags` parâmetro.

## <a name="cdacladddeniedace"></a><a name="adddeniedace"></a>CDacl::AddDeniedAce

Adiciona um ACE negado (entrada de `CDacl` controle de acesso) ao objeto.

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
Um objeto `CSid` .

*Accessmask*<br/>
Especifica a máscara dos direitos de acesso `CSid` a ser negada para o objeto especificado.

*Aceflags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança ACE. Padrão para 0 na primeira forma do método.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o ACE `CDacl` for adicionado ao objeto, FALSE on failure( FALSO/ FALSO).

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém Zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona um ACE `CDacl` que nega o acesso ao objeto.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter uma descrição das várias bandeiras que podem ser definidas no `AceFlags` parâmetro.

## <a name="cdaclcdacl"></a><a name="cdacl"></a>CDacl::CDacl

O construtor.

```
CDacl (const ACL& rhs) throw(...);
CDacl () throw();
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Uma estrutura `ACL` existente (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CDacl` objeto pode ser criado opcionalmente `ACL` usando uma estrutura existente. É importante notar que apenas um DACL (lista de controle de acesso discricionário), e não um SACL (lista de controle de acesso ao sistema), deve ser passado como parâmetro. Nas compilações de depuração, passar por um SACL causará um ASSERT. Nas compilações de lançamento, a aprovação de um SACL fará com que as ACEs (entradas de controle de acesso) na ACL sejam ignoradas e nenhum erro ocorrerá.

## <a name="cdaclcdacl"></a><a name="dtor"></a>CDacl::~CDacl

O destruidor.

```
~CDacl () throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso) usando [CDacl::RemoveAllAces](#removeallaces).

## <a name="cdaclgetacecount"></a><a name="getacecount"></a>CDacl::GetAceCount

Retorna o número de ACEs (entradas `CDacl` de controle de acesso) no objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de ACEs contidos no `CDacl` objeto.

## <a name="cdacloperator-"></a><a name="operator_eq"></a>CDacl::operador =

Operador de atribuição.

```
CDacl& operator= (const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A ACL (lista de controle de acesso) para atribuir ao objeto existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CDacl` ao objeto atualizado.

### <a name="remarks"></a>Comentários

Você deve garantir que você só passe um DACL (lista de controle de acesso discricionário) para esta função. Passar uma SACL (lista de controle de acesso ao sistema) para esta função causará uma assert em compilações de depuração, mas não causará nenhum erro nas compilações de versão.

## <a name="cdaclremoveace"></a><a name="removeace"></a>CDacl::RemoveAce

Remove um ACE específico (entrada de `CDacl` controle de acesso) do objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexar a entrada ACE para remover.

### <a name="remarks"></a>Comentários

Este método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

## <a name="cdaclremoveallaces"></a><a name="removeallaces"></a>CDacl::RemoveAllAces

Remove todas as ACEs (entradas de controle `CDacl` de acesso) contidas no objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove toda `ACE` a estrutura (entrada de controle `CDacl` de acesso) (se houver) no objeto.

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/win32/SecAuthZ/access-control-lists)<br/>
[Ases](/windows/win32/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
