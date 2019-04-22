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
ms.openlocfilehash: 1beac6106b825c775012b85ccd01226c3dfab795
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58770013"
---
# <a name="cdacl-class"></a>Classe CDacl

Essa classe é um wrapper para uma estrutura da DACL (lista de controle de acesso discricionário).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CDacl::AddAllowedAce](#addallowedace)|Adiciona uma permitidos ACE (entrada de controle de acesso) para o `CDacl` objeto.|
|[CDacl::AddDeniedAce](#adddeniedace)|Adiciona uma ACE negado para o `CDacl` objeto.|
|[CDacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas de controle de acesso) no `CDacl` objeto.|
|[CDacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) a `CDacl` objeto.|
|[CDacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CDacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDacl::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Descritor de segurança de um objeto pode conter uma DACL. Uma DACL contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Se uma DACL estiver vazia (ou seja, ele contém zero ACEs), nenhum acesso é concedido explicitamente, portanto, o acesso é negado implicitamente. No entanto, se o descritor de segurança de um objeto não tiver uma DACL, o objeto está desprotegido e todos têm acesso completo.

Para recuperar DACL um objeto, você deve ser o proprietário do objeto ou ter acesso READ_CONTROL ao objeto. Para alterar a DACL de um objeto, você deve ter acesso WRITE_DAC no objeto.

Usar os métodos de classe fornecidos para criar, adicionar, remover e excluir as ACEs do `CDacl` objeto. Consulte também [AtlGetDacl](security-global-functions.md#atlgetdacl) e [AtlSetDacl](security-global-functions.md#atlsetdacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CAcl](../../atl/reference/cacl-class.md)

`CDacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="addallowedace"></a>  CDacl::AddAllowedAce

Adiciona uma permitidos ACE (entrada de controle de acesso) para o `CDacl` objeto.

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
Um [CSid](../../atl/reference/csid-class.md) objeto.

*AccessMask*<br/>
Especifica a máscara de direitos de acesso seja permitido especificado `CSid` objeto.

*AceFlags*<br/>
Um conjunto de sinalizadores de bit que controlam a herança da ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a ACE é adicionada a `CDacl` do objeto, falso em caso de falha.

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Esse método adiciona uma ACE que permite o acesso para o `CDacl` objeto.

Ver [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidas no `AceFlags` parâmetro.

##  <a name="adddeniedace"></a>  CDacl::AddDeniedAce

Adiciona um negado ACE (entrada de controle de acesso) para o `CDacl` objeto.

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
Especifica a máscara de direitos de acesso seja negado especificado `CSid` objeto.

*AceFlags*<br/>
Um conjunto de sinalizadores de bit que controlam a herança da ACE. O padrão é 0 na primeira forma do método.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a ACE é adicionada a `CDacl` do objeto, falso em caso de falha.

### <a name="remarks"></a>Comentários

Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Esse método adiciona uma ACE que nega o acesso para o `CDacl` objeto.

Ver [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidas no `AceFlags` parâmetro.

##  <a name="cdacl"></a>  CDacl::CDacl

O construtor.

```
CDacl (const ACL& rhs) throw(...);
CDacl () throw();
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um existente `ACL` estrutura (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CDacl` objeto pode ser criado, opcionalmente, usar um existente `ACL` estrutura. É importante observar que somente uma DACL (lista de controle de acesso discricionário), e não uma SACL (lista de controle de acesso do sistema), deve ser passado como este parâmetro. Em compilações de depuração, passar uma SACL fará com que uma declaração. Em compilações de versão, passar uma SACL fará com que as ACEs (entradas de controle de acesso) na ACL devem ser ignorados, e nenhum erro ocorrerá.

##  <a name="dtor"></a>  CDacl::~CDacl

O destruidor.

```
~CDacl () throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso) usando [CDacl::RemoveAllAces](#removeallaces).

##  <a name="getacecount"></a>  CDacl::GetAceCount

Retorna o número de ACEs (entradas de controle de acesso) no `CDacl` objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de ACEs contidos no `CDacl` objeto.

##  <a name="operator_eq"></a>  CDacl::operator =

Operador de atribuição.

```
CDacl& operator= (const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A ACL (lista de controle de acesso) para atribuir ao objeto existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a atualização `CDacl` objeto.

### <a name="remarks"></a>Comentários

Você deve garantir que você passe uma DACL (lista de controle de acesso discricionário) para essa função. Passando uma SACL (lista de controle de acesso do sistema) para essa função fará com que uma declaração em compilações de depuração, mas não fará com que nenhum erro em compilações de versão.

##  <a name="removeace"></a>  CDacl::RemoveAce

Remove uma ACE específica (entrada de controle de acesso) a `CDacl` objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice para a entrada do ACE a ser removido.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeallaces"></a>  CDacl::RemoveAllAces

Remove todas as ACEs (entradas de controle de acesso) contidas no `CDacl` objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove todos os `ACE` estrutura (entrada de controle de acesso) (se houver) na `CDacl` objeto.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/desktop/SecAuthZ/access-control-lists)<br/>
[ACEs](/windows/desktop/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
