---
title: Classe CSacl
ms.date: 11/04/2016
f1_keywords:
- CSacl
- ATLSECURITY/ATL::CSacl
- ATLSECURITY/ATL::CSacl::CSacl
- ATLSECURITY/ATL::CSacl::AddAuditAce
- ATLSECURITY/ATL::CSacl::GetAceCount
- ATLSECURITY/ATL::CSacl::RemoveAce
- ATLSECURITY/ATL::CSacl::RemoveAllAces
helpviewer_keywords:
- CSacl class
ms.assetid: 8624889b-aebc-4183-9d29-a20f07837f05
ms.openlocfilehash: c4bbdfccb2d6d8b167c537b7ae4df57c89438479
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496511"
---
# <a name="csacl-class"></a>Classe CSacl

Essa classe é um wrapper para uma estrutura SACL (lista de controle de acesso do sistema).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CSacl : public CAcl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::CSacl](#csacl)|O construtor.|
|[CSacl::~CSacl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::AddAuditAce](#addauditace)|Adiciona uma ACE (entrada de controle de acesso) de auditoria `CSacl` ao objeto.|
|[CSacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas de controle de acesso) no `CSacl` objeto.|
|[CSacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) do `CSacl` objeto.|
|[CSacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CSacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Uma SACL contém ACEs (entradas de controle de acesso) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança de um controlador de domínio. Observe que uma SACL gera entradas de log somente no controlador de domínio em que ocorreu a tentativa de acesso, não em cada controlador de domínio que contém uma réplica do objeto.

Para definir ou recuperar a SACL no descritor de segurança de um objeto, o privilégio SE_SECURITY_NAME deve ser habilitado no token de acesso do thread solicitante. O grupo Administradores tem esse privilégio concedido por padrão e pode ser concedido a outros usuários ou grupos. Ter o privilégio concedido não é tudo o que é necessário: antes que a operação definida pelo privilégio possa ser executada, o privilégio deve ser habilitado no token de acesso de segurança para entrar em vigor. O modelo permite que os privilégios sejam habilitados apenas para operações específicas do sistema e, em seguida, desabilitados quando não forem mais necessários. Consulte [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl) para obter exemplos de como habilitar o SE_SECURITY_NAME.

Use os métodos de classe fornecidos para adicionar, remover, criar e excluir ACEs do `SACL` objeto. Consulte também [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cacls](../../atl/reference/cacl-class.md)

`CSacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="addauditace"></a>  CSacl::AddAuditAce

Adiciona uma ACE (entrada de controle de acesso) de auditoria `CSacl` ao objeto.

```
bool AddAuditAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    bool bSuccess,
    bool bFailure,
    BYTE AceFlags = 0) throw(...);

bool AddAuditAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    bool bSuccess,
    bool bFailure,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) .

*AccessMask*<br/>
Especifica a máscara dos direitos de acesso a serem auditados para o `CSid` objeto especificado.

*bSuccess*<br/>
Especifica se as tentativas de acesso permitidas devem ser auditadas. Defina esse sinalizador como true para habilitar a auditoria; caso contrário, defina-o como false.

*bFailure*<br/>
Especifica se as tentativas de acesso negadas devem ser auditadas. Defina esse sinalizador como true para habilitar a auditoria; caso contrário, defina-o como false.

*AceFlags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança da ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retornará true se a Ace for adicionada ao `CSacl` objeto, false em caso de falha.

### <a name="remarks"></a>Comentários

Um `CSacl` objeto contém ACEs (entradas de controle de acesso) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança. Esse método adiciona uma ACE desse tipo ao `CSacl` objeto.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidos no parâmetro *AceFlags* .

##  <a name="csacl"></a>  CSacl::CSacl

O construtor.

```
CSacl() throw();
CSacl(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Uma estrutura `ACL` existente (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CSacl` objeto pode ser criado opcionalmente usando uma estrutura `ACL` existente. Verifique se esse parâmetro é uma SACL (lista de controle de acesso do sistema) e não uma DACL (lista de controle de acesso discricionário). Em compilações de depuração, se uma DACL for fornecida, ocorrerá uma asserção. Em versão, compila as entradas de uma DACL são ignoradas.

##  <a name="dtor"></a>  CSacl::~CSacl

O destruidor.

```
~CSacl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso).

##  <a name="getacecount"></a>  CSacl::GetAceCount

Retorna o número de ACEs (entradas de controle de acesso) no `CSacl` objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de ACEs contidas no `CSacl` objeto.

##  <a name="operator_eq"></a>  CSacl::operator =

Operador de atribuição.

```
CSacl& operator=(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `ACL` (lista de controle de acesso) a ser atribuída ao objeto existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao objeto atualizado `CSacl` . Verifique se o `ACL` parâmetro é, na verdade, uma SACL (lista de controle de acesso) do sistema e não uma DACL (lista de controle de acesso discricionário). Em Debug builds, uma asserção ocorrerá e, na versão `ACL` builds, o parâmetro será ignorado.

##  <a name="removeace"></a>  CSacl::RemoveAce

Remove uma ACE específica (entrada de controle de acesso) do `CSacl` objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexe para a entrada ACE a ser removida.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray:: RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeallaces"></a>  CSacl::RemoveAllAces

Remove todas as ACEs (entradas de controle de acesso) contidas no `CSacl` objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove cada `ACE` estrutura (se houver) `CSacl` no objeto.

## <a name="see-also"></a>Consulte também

[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/win32/SecAuthZ/access-control-lists)<br/>
[Ases](/windows/win32/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
