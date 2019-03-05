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
ms.openlocfilehash: f8820be3073c6ffaffdaa9d04a7338ad584d36ca
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57267284"
---
# <a name="csacl-class"></a>Classe CSacl

Essa classe é um wrapper para uma estrutura SACL (lista de controle de acesso do sistema).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSacl : public CAcl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::CSacl](#csacl)|O construtor.|
|[CSacl::~CSacl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::AddAuditAce](#addauditace)|Adiciona uma entrada de controle de acesso de auditoria (ACE) para o `CSacl` objeto.|
|[CSacl::GetAceCount](#getacecount)|Retorna o número de entradas de controle de acesso (ACEs) no `CSacl` objeto.|
|[CSacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) a `CSacl` objeto.|
|[CSacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CSacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Uma SACL contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança de um controlador de domínio. Observe que uma SACL gera entradas de log somente no controlador de domínio em que ocorreu a tentativa de acesso, não em cada controlador de domínio que contém uma réplica do objeto.

Para definir ou recuperar a SACL no descritor de segurança de um objeto, o privilégio SE_SECURITY_NAME deve estar habilitado no token de acesso do thread solicitante. O grupo Administradores tem esse privilégio concedido por padrão, e ela pode ser concedida a outros usuários ou grupos. Ter o privilégio concedido não é tudo o que é necessário: antes da operação definida pelo privilégio pode ser executada, o privilégio deve ser habilitado no token de acesso de segurança para entrar em vigor. O modelo permite que os privilégios para ser habilitada somente para operações específicas do sistema e, em seguida, desabilitada quando eles não são mais necessários. Ver [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl) para obter exemplos de como habilitar SE_SECURITY_NAME.

Use os métodos da classe fornecidos para adicionar, remover, criar e excluir as ACEs do `SACL` objeto. Consulte também [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CAcl](../../atl/reference/cacl-class.md)

`CSacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="addauditace"></a>  CSacl::AddAuditAce

Adiciona uma entrada de controle de acesso de auditoria (ACE) para o `CSacl` objeto.

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
O [CSid](../../atl/reference/csid-class.md) objeto.

*AccessMask*<br/>
Especifica a máscara de direitos de acesso a serem auditados especificado `CSid` objeto.

*bSuccess*<br/>
Especifica se as tentativas de acesso permitido a serem auditados. Defina esse sinalizador para True para habilitar a auditoria; Caso contrário, defina-o como false.

*bFailure*<br/>
Especifica se as tentativas de acesso negado são a serem auditados. Defina esse sinalizador para True para habilitar a auditoria; Caso contrário, defina-o como false.

*AceFlags*<br/>
Um conjunto de sinalizadores de bit que controlam a herança da ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a ACE é adicionada a `CSacl` do objeto, falso em caso de falha.

### <a name="remarks"></a>Comentários

Um `CSacl` objeto contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança. Esse método adiciona tal uma ACE para o `CSacl` objeto.

Ver [ACE_HEADER](/windows/desktop/api/winnt/ns-winnt-_ace_header) para obter uma descrição dos vários sinalizadores que podem ser definidas na *AceFlags* parâmetro.

##  <a name="csacl"></a>  CSacl::CSacl

O construtor.

```
CSacl() throw();
CSacl(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Um existente `ACL` estrutura (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CSacl` objeto pode ser criado, opcionalmente, usar um existente `ACL` estrutura. Certifique-se de que esse parâmetro é uma lista de controle de acesso do sistema (SACL) e não uma lista de controle de acesso discricionário (DACL). Em compilações de depuração, se uma DACL é fornecida uma asserção ocorrerá. Em compilações de versão, todas as entradas de uma DACL são ignoradas.

##  <a name="dtor"></a>  CSacl::~CSacl

O destruidor.

```
~CSacl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as entradas de controle de acesso (ACEs).

##  <a name="getacecount"></a>  CSacl::GetAceCount

Retorna o número de entradas de controle de acesso (ACEs) no `CSacl` objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de ACEs contidos no `CSacl` objeto.

##  <a name="operator_eq"></a>  CSacl::operator =

Operador de atribuição.

```
CSacl& operator=(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `ACL` (lista de controle de acesso) para atribuir ao objeto existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a atualização `CSacl` objeto. Certifique-se de que o `ACL` parâmetro é, na verdade, uma sistema de controle de acesso SACL (lista) e não uma lista de controle de acesso discricionário (DACL). Em compilações de depuração, ocorrerá uma asserção, em builds de versão a `ACL` parâmetro será ignorado.

##  <a name="removeace"></a>  CSacl::RemoveAce

Remove uma ACE específica (entrada de controle de acesso) a `CSacl` objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice para a entrada do ACE a ser removido.

### <a name="remarks"></a>Comentários

Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

##  <a name="removeallaces"></a>  CSacl::RemoveAllAces

Remove todas as entradas de controle de acesso (ACEs) contidas no `CSacl` objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove todos os `ACE` estruturar (se houver) na `CSacl` objeto.

## <a name="see-also"></a>Consulte também

[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/desktop/SecAuthZ/access-control-lists)<br/>
[ACEs](/windows/desktop/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
