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
ms.openlocfilehash: 72b5c9fee3868286f9e4a0917f46aeb732349c62
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330990"
---
# <a name="csacl-class"></a>Classe CSacl

Esta classe é um invólucro para uma estrutura SACL (system access-control list).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CSacl::AddAuditAce](#addauditace)|Adiciona uma ace (audit access-control `CSacl` entry, entrada de controle de acesso de auditoria) ao objeto.|
|[CSacl::GetAceCount](#getacecount)|Retorna o número de entradas de controle de `CSacl` acesso (ACEs) no objeto.|
|[CSacl::RemoveAce](#removeace)|Remove um ACE específico (entrada de `CSacl` controle de acesso) do objeto.|
|[CSacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas no `CSacl` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSacl::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Um SACL contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no registro de eventos de segurança de um controlador de domínio. Observe que um SACL gera entradas de log apenas no controlador de domínio onde ocorreu a tentativa de acesso, não em todos os controladores de domínio que contenham uma réplica do objeto.

Para definir ou recuperar o SACL no descritor de segurança de um objeto, o privilégio SE_SECURITY_NAME deve ser habilitado no token de acesso do segmento solicitante. O grupo administradores tem esse privilégio concedido por padrão, e ele pode ser concedido a outros usuários ou grupos. Ter o privilégio concedido não é tudo o que é necessário: antes que a operação definida pelo privilégio possa ser realizada, o privilégio deve ser habilitado no token de acesso de segurança para entrar em vigor. O modelo permite que privilégios sejam habilitados apenas para operações específicas do sistema e, em seguida, desativados quando não são mais necessários. Consulte [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl) para obter exemplos de habilitação SE_SECURITY_NAME.

Use os métodos de classe fornecidos para adicionar, remover, `SACL` criar e excluir ACEs do objeto. Veja também [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl).

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cacl](../../atl/reference/cacl-class.md)

`CSacl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="csacladdauditace"></a><a name="addauditace"></a>CSacl::AddAuditAce

Adiciona uma ace (audit access-control `CSacl` entry, entrada de controle de acesso de auditoria) ao objeto.

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
O objeto [CSid.](../../atl/reference/csid-class.md)

*Accessmask*<br/>
Especifica a máscara dos direitos de acesso a `CSid` ser auditada para o objeto especificado.

*bSucesso*<br/>
Especifica se as tentativas de acesso permitidas devem ser auditadas. Defina essa bandeira como verdadeira para permitir a auditoria; caso contrário, defini-lo como falso.

*bFalha*<br/>
Especifica se as tentativas de acesso negadas devem ser auditadas. Defina essa bandeira como verdadeira para permitir a auditoria; caso contrário, defini-lo como falso.

*Aceflags*<br/>
Um conjunto de sinalizadores de bits que controlam a herança ACE.

*pObjectType*<br/>
O tipo de objeto.

*pInheritedObjectType*<br/>
O tipo de objeto herdado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o ACE `CSacl` for adicionado ao objeto, FALSE on failure( FALSO/ FALSO).

### <a name="remarks"></a>Comentários

Um `CSacl` objeto contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no registro de eventos de segurança. Este método adiciona tal `CSacl` ACE ao objeto.

Consulte [ACE_HEADER](/windows/win32/api/winnt/ns-winnt-ace_header) para obter uma descrição das várias bandeiras que podem ser definidas no parâmetro *AceFlags.*

## <a name="csaclcsacl"></a><a name="csacl"></a>CSacl::CSacl

O construtor.

```
CSacl() throw();
CSacl(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
Uma estrutura `ACL` existente (lista de controle de acesso).

### <a name="remarks"></a>Comentários

O `CSacl` objeto pode ser criado opcionalmente `ACL` usando uma estrutura existente. Certifique-se de que esse parâmetro é uma lista de controle de acesso do sistema (SACL) e não uma lista de controle de acesso discricionária (DACL). Nas compilações de depuração, se um DACL for fornecido, ocorrerá uma afirmação. Na versão, todas as entradas de um DACL são ignoradas.

## <a name="csaclcsacl"></a><a name="dtor"></a>CSacl::~CSacl

O destruidor.

```
~CSacl() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as entradas de controle de acesso (ACEs).

## <a name="csaclgetacecount"></a><a name="getacecount"></a>CSacl::GetAceCount

Retorna o número de entradas de controle de `CSacl` acesso (ACEs) no objeto.

```
UINT GetAceCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de ACEs contidos no `CSacl` objeto.

## <a name="csacloperator-"></a><a name="operator_eq"></a>CSacl::operador =

Operador de atribuição.

```
CSacl& operator=(const ACL& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `ACL` (lista de controle de acesso) a atribuir ao objeto existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CSacl` ao objeto atualizado. Certifique-se `ACL` de que o parâmetro é, na verdade, uma lista de controle de acesso do sistema (SACL) e não uma lista de controle de acesso discricionária (DACL). Na compilação de depuração uma afirmação `ACL` ocorrerá, e na compilação de lançamento o parâmetro será ignorado.

## <a name="csaclremoveace"></a><a name="removeace"></a>CSacl::RemoveAce

Remove um ACE específico (entrada de `CSacl` controle de acesso) do objeto.

```
void RemoveAce(UINT nIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Indexar a entrada ACE para remover.

### <a name="remarks"></a>Comentários

Este método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).

## <a name="csaclremoveallaces"></a><a name="removeallaces"></a>CSacl::RemoveAllAces

Remove todas as entradas de controle de acesso (ACEs) contidas no `CSacl` objeto.

```
void RemoveAllAces() throw();
```

### <a name="remarks"></a>Comentários

Remove todas `ACE` as estruturas (se `CSacl` houver) no objeto.

## <a name="see-also"></a>Confira também

[Classe CAcl](../../atl/reference/cacl-class.md)<br/>
[ACLs](/windows/win32/SecAuthZ/access-control-lists)<br/>
[Ases](/windows/win32/SecAuthZ/access-control-entries)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
