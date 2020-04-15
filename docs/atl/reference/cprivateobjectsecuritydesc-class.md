---
title: Classe CPrivateObjectSecurityDesc
ms.date: 11/04/2016
f1_keywords:
- CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::ConvertToAutoInherit
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Create
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Get
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Set
helpviewer_keywords:
- CPrivateObjectSecurityDesc class
ms.assetid: 2c4bbb13-bf99-4833-912a-197f6815bb5d
ms.openlocfilehash: 2fcfdfecab649b571047613ec0889b02d2c7a7a0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331406"
---
# <a name="cprivateobjectsecuritydesc-class"></a>Classe CPrivateObjectSecurityDesc

Esta classe representa um objeto descritor de segurança de objeto privado.

## <a name="syntax"></a>Sintaxe

```
class CPrivateObjectSecurityDesc : public CSecurityDesc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc:CPrivateObjectSecurityDesc](#cprivateobjectsecuritydesc)|O construtor.|
|[CPrivateObjectSecurityDesc::~CPrivateObjectSecurityDesc](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc:ConvertToAutoInherit](#converttoautoinherit)|Chame este método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) para um formato que suporte a propagação automática de entradas de controle de acesso hereditárias (ACEs).|
|[CPrivateObjectSecurityDesc::Criar](#create)|Chame esse método para alocar e inicializar um descritor de segurança auto-relativo para o objeto privado criado pelo gerenciador de recursos de chamada.|
|[CPrivateObjectSecurityDesc::Get](#get)|Chame este método para recuperar informações do descritor de segurança de um objeto privado.|
|[CPrivateObjectSecurityDesc::Set](#set)|Chame este método para modificar o descritor de segurança de um objeto privado.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Esta classe, derivada do [CSecurityDesc,](../../atl/reference/csecuritydesc-class.md)fornece métodos para criar e gerenciar o descritor de segurança de um objeto privado.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Csecuritydesc](../../atl/reference/csecuritydesc-class.md)

`CPrivateObjectSecurityDesc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="cprivateobjectsecuritydescconverttoautoinherit"></a><a name="converttoautoinherit"></a>CPrivateObjectSecurityDesc:ConvertToAutoInherit

Chame este método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) para um formato que suporte a propagação automática de entradas de controle de acesso hereditárias (ACEs).

```
bool ConvertToAutoInherit(
    const CSecurityDesc* pParent,
    GUID* ObjectType,
    bool bIsDirectoryObject,
    PGENERIC_MAPPING GenericMapping) throw();
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
Ponteiro para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) fazendo referência ao contêiner pai do objeto. Se não houver recipiente pai, este parâmetro é NULO.

*Objecttype*<br/>
Ponteiro para `GUID` uma estrutura que identifica o tipo de objeto associado ao objeto atual. Defina *ObjectType* para NULL se o objeto não tiver um GUID.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor de verdade indica que o novo objeto é um recipiente. Um valor falso indica que o novo objeto não é um recipiente.

*Mapeamento genérico*<br/>
Ponteiro para uma estrutura [de GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico a direitos específicos para o objeto.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Este método tenta determinar se as ACEs na lista de controle de acesso discricionário (DACL) e na lista de controle de acesso do sistema (SACL) do descritor de segurança atual foram herdadas do descritor de segurança pai. Ele chama a função [ConvertToAutoInheritPrivateObjectSecurity.](/windows/win32/api/securitybaseapi/nf-securitybaseapi-converttoautoinheritprivateobjectsecurity)

## <a name="cprivateobjectsecuritydesccprivateobjectsecuritydesc"></a><a name="cprivateobjectsecuritydesc"></a>CPrivateObjectSecurityDesc:CPrivateObjectSecurityDesc

O construtor.

```
CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o objeto `CPrivateObjectSecurityDesc`.

## <a name="cprivateobjectsecuritydesccprivateobjectsecuritydesc"></a><a name="dtor"></a>CPrivateObjectSecurityDesc::~CPrivateObjectSecurityDesc

O destruidor.

```
~CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados e exclui o descritor de segurança do objeto privado.

## <a name="cprivateobjectsecuritydesccreate"></a><a name="create"></a>CPrivateObjectSecurityDesc::Criar

Chame esse método para alocar e inicializar um descritor de segurança auto-relativo para o objeto privado criado pelo gerenciador de recursos de chamada.

```
bool Create(
    const CSecurityDesc* pParent,
    const CSecurityDesc* pCreator,
    bool bIsDirectoryObject,
    const CAccessToken& Token,
    PGENERIC_MAPPING GenericMapping) throw();

bool Create(
    const CSecurityDesc* pParent,
    const CSecurityDesc* pCreator,
    GUID* ObjectType,
    bool bIsContainerObject,
    ULONG AutoInheritFlags,
    const CAccessToken& Token,
    PGENERIC_MAPPING GenericMapping) throw();
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
Pointer para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) fazendo referência ao diretório pai no qual um novo objeto está sendo criado. Definir como NULO se não houver diretório pai.

*pCriador*<br/>
Ponteiro para um descritor de segurança fornecido pelo criador do objeto. Se o criador do objeto não passar explicitamente informações de segurança para o novo objeto, defina este parâmetro como NULO.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor de verdade indica que o novo objeto é um recipiente. Um valor falso indica que o novo objeto não é um recipiente.

*Token*<br/>
Consulte o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) para o processo do cliente em cujo nome o objeto está sendo criado.

*Mapeamento genérico*<br/>
Ponteiro para uma estrutura [de GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico a direitos específicos para o objeto.

*Objecttype*<br/>
Ponteiro para `GUID` uma estrutura que identifica o tipo de objeto associado ao objeto atual. Defina *ObjectType* para NULL se o objeto não tiver um GUID.

*bIsContainerObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor de verdade indica que o novo objeto é um recipiente. Um valor falso indica que o novo objeto não é um recipiente.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bits que controlam como as entradas de controle de acesso (ACEs) são herdadas do *pParent*. Consulte [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Este método chama [CreatePrivateObjectSercurity](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity) ou [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex).

O segundo método permite especificar o guid tipo de objeto do novo objeto ou controlar como as ACEs são herdadas.

> [!NOTE]
> Um descritor de segurança auto-relativo é um descritor de segurança que armazena todas as suas informações de segurança em um bloco de memória contíguo.

## <a name="cprivateobjectsecuritydescget"></a><a name="get"></a>CPrivateObjectSecurityDesc::Get

Chame este método para recuperar informações do descritor de segurança de um objeto privado.

```
bool Get(
    SECURITY_INFORMATION si,
    CSecurityDesc* pResult) const throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
Um conjunto de sinalizadores de bits que indicam as partes do descritor de segurança para recuperar. Este valor pode ser uma combinação das [bandeiras de SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) bit.

*Presult*<br/>
Pointer para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) que recebe uma cópia das informações solicitadas do descritor de segurança especificado.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O descritor de segurança é uma estrutura e dados associados que contém as informações de segurança de um objeto securável.

## <a name="cprivateobjectsecuritydescoperator-"></a><a name="operator_eq"></a>CPrivateObjectSecurityDesc::operador =

Operador de atribuição.

```
CPrivateObjectSecurityDesc& operator= (const CPrivateObjectSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O objeto `CPrivateObjectSecurityDesc` a ser atribuído ao objeto atual.

### <a name="return-value"></a>Valor retornado

Retorna o `CPrivateObjectSecurityDesc` objeto atualizado.

## <a name="cprivateobjectsecuritydescset"></a><a name="set"></a>CPrivateObjectSecurityDesc::Set

Chame este método para modificar o descritor de segurança de um objeto privado.

```
bool Set(
    SECURITY_INFORMATION si,
    const CSecurityDesc& Modification,
    PGENERIC_MAPPING GenericMapping,
    const CAccessToken& Token) throw();

bool Set(
    SECURITY_INFORMATION si,
    const CSecurityDesc& Modification,
    ULONG AutoInheritFlags,
    PGENERIC_MAPPING GenericMapping,
    const CAccessToken& Token) throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
Um conjunto de sinalizadores de bits que indicam as partes do descritor de segurança a definir. Este valor pode ser uma combinação das [bandeiras de SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) bit.

*Modification*<br/>
Ponteiro para um objeto [CSecurityDesc.](../../atl/reference/csecuritydesc-class.md) As partes deste descritor de segurança indicadas pelo parâmetro *si* são aplicadas ao descritor de segurança do objeto.

*Mapeamento genérico*<br/>
Ponteiro para uma estrutura [de GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico a direitos específicos para o objeto.

*Token*<br/>
Consulte o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) para o processo do cliente em cujo nome o objeto está sendo criado.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bits que controlam como as entradas de controle de acesso (ACEs) são herdadas do *pParent*. Consulte [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O segundo método permite especificar o guid tipo de objeto do objeto ou controlar como as ACEs são herdadas.

## <a name="see-also"></a>Confira também

[Security_descriptor](/windows/win32/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)<br/>
[Classe CSecurityDesc](../../atl/reference/csecuritydesc-class.md)
