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
ms.openlocfilehash: f62d289418280a05f390bf9cdec23ea30632aed2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833498"
---
# <a name="cprivateobjectsecuritydesc-class"></a>Classe CPrivateObjectSecurityDesc

Essa classe representa um objeto de descritor de segurança de objeto privado.

## <a name="syntax"></a>Sintaxe

```
class CPrivateObjectSecurityDesc : public CSecurityDesc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc](#cprivateobjectsecuritydesc)|O construtor.|
|[CPrivateObjectSecurityDesc:: ~ CPrivateObjectSecurityDesc](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc::ConvertToAutoInherit](#converttoautoinherit)|Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que ofereça suporte à propagação automática de ACEs (entradas de controle de acesso) herdáveis.|
|[CPrivateObjectSecurityDesc:: criar](#create)|Chame esse método para alocar e inicializar um descritor de segurança auto-relativo para o objeto particular criado pelo Gerenciador de recursos de chamada.|
|[CPrivateObjectSecurityDesc:: Get](#get)|Chame esse método para recuperar informações do descritor de segurança de um objeto privado.|
|[CPrivateObjectSecurityDesc:: Set](#set)|Chame esse método para modificar o descritor de segurança de um objeto privado.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Essa classe, derivada de [CSecurityDesc](../../atl/reference/csecuritydesc-class.md), fornece métodos para criar e gerenciar o descritor de segurança de um objeto particular.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CSecurityDesc](../../atl/reference/csecuritydesc-class.md)

`CPrivateObjectSecurityDesc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="cprivateobjectsecuritydescconverttoautoinherit"></a><a name="converttoautoinherit"></a> CPrivateObjectSecurityDesc::ConvertToAutoInherit

Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que ofereça suporte à propagação automática de ACEs (entradas de controle de acesso) herdáveis.

```
bool ConvertToAutoInherit(
    const CSecurityDesc* pParent,
    GUID* ObjectType,
    bool bIsDirectoryObject,
    PGENERIC_MAPPING GenericMapping) throw();
```

### <a name="parameters"></a>parâmetros

*pParent*<br/>
Ponteiro para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) que faz referência ao contêiner pai do objeto. Se não houver nenhum contêiner pai, esse parâmetro será NULL.

*ObjectType*<br/>
Ponteiro para uma `GUID` estrutura que identifica o tipo de objeto associado ao objeto atual. Defina *objecttype* como NULL se o objeto não tiver um GUID.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*GenericMapping*<br/>
Ponteiro para uma estrutura de [GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Esse método tenta determinar se as ACEs na lista de controle de acesso discricional (DACL) e na lista de controle de acesso do sistema (SACL) do descritor de segurança atual foram herdadas do descritor de segurança pai. Ele chama a função [ConvertToAutoInheritPrivateObjectSecurity](/windows/win32/api/securitybaseapi/nf-securitybaseapi-converttoautoinheritprivateobjectsecurity) .

## <a name="cprivateobjectsecuritydesccprivateobjectsecuritydesc"></a><a name="cprivateobjectsecuritydesc"></a> CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc

O construtor.

```
CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o objeto `CPrivateObjectSecurityDesc`.

## <a name="cprivateobjectsecuritydesccprivateobjectsecuritydesc"></a><a name="dtor"></a> CPrivateObjectSecurityDesc:: ~ CPrivateObjectSecurityDesc

O destruidor.

```
~CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados e exclui o descritor de segurança do objeto privado.

## <a name="cprivateobjectsecuritydesccreate"></a><a name="create"></a> CPrivateObjectSecurityDesc:: criar

Chame esse método para alocar e inicializar um descritor de segurança auto-relativo para o objeto particular criado pelo Gerenciador de recursos de chamada.

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

### <a name="parameters"></a>parâmetros

*pParent*<br/>
Ponteiro para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) que faz referência ao diretório pai no qual um novo objeto está sendo criado. Defina como NULL se não houver um diretório pai.

*pCreator*<br/>
Ponteiro para um descritor de segurança fornecido pelo criador do objeto. Se o criador do objeto não transmitir explicitamente as informações de segurança para o novo objeto, defina esse parâmetro como NULL.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*Token*<br/>
Referência ao objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) para o processo do cliente em cujo nome o objeto está sendo criado.

*GenericMapping*<br/>
Ponteiro para uma estrutura de [GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.

*ObjectType*<br/>
Ponteiro para uma `GUID` estrutura que identifica o tipo de objeto associado ao objeto atual. Defina *objecttype* como NULL se o objeto não tiver um GUID.

*bIsContainerObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bits que controlam como as ACEs (entradas de controle de acesso) são herdadas de *pParent*. Consulte [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) para obter mais detalhes.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Esse método chama [CreatePrivateObjectSercurity](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity) ou [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex).

O segundo método permite especificar o GUID de tipo de objeto do novo objeto ou controlar como as ACEs são herdadas.

> [!NOTE]
> Um descritor de segurança auto-relativo é um descritor de segurança que armazena todas as suas informações de segurança em um bloco contíguo de memória.

## <a name="cprivateobjectsecuritydescget"></a><a name="get"></a> CPrivateObjectSecurityDesc:: Get

Chame esse método para recuperar informações do descritor de segurança de um objeto privado.

```
bool Get(
    SECURITY_INFORMATION si,
    CSecurityDesc* pResult) const throw();
```

### <a name="parameters"></a>parâmetros

*SL*<br/>
Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança a serem recuperadas. Esse valor pode ser uma combinação dos sinalizadores de bit de [SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) .

*pResult*<br/>
Ponteiro para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) que recebe uma cópia das informações solicitadas do descritor de segurança especificado.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O descritor de segurança é uma estrutura e dados associados que contêm as informações de segurança para um objeto protegível.

## <a name="cprivateobjectsecuritydescoperator-"></a><a name="operator_eq"></a> CPrivateObjectSecurityDesc:: Operator =

Operador de atribuição.

```
CPrivateObjectSecurityDesc& operator= (const CPrivateObjectSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>parâmetros

*rhs*<br/>
O objeto `CPrivateObjectSecurityDesc` a ser atribuído ao objeto atual.

### <a name="return-value"></a>Valor Retornado

Retorna o `CPrivateObjectSecurityDesc` objeto atualizado.

## <a name="cprivateobjectsecuritydescset"></a><a name="set"></a> CPrivateObjectSecurityDesc:: Set

Chame esse método para modificar o descritor de segurança de um objeto privado.

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

### <a name="parameters"></a>parâmetros

*SL*<br/>
Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança a serem definidas. Esse valor pode ser uma combinação dos sinalizadores de bit de [SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) .

*Modification*<br/>
Ponteiro para um objeto [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) . As partes desse descritor de segurança indicadas pelo parâmetro *si* são aplicadas ao descritor de segurança do objeto.

*GenericMapping*<br/>
Ponteiro para uma estrutura de [GENERIC_MAPPING](/windows/win32/api/winnt/ns-winnt-generic_mapping) que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.

*Token*<br/>
Referência ao objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) para o processo do cliente em cujo nome o objeto está sendo criado.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bits que controlam como as ACEs (entradas de controle de acesso) são herdadas de *pParent*. Consulte [CreatePrivateObjectSecurityEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) para obter mais detalhes.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O segundo método permite especificar o GUID de tipo de objeto do objeto ou controlar como as ACEs são herdadas.

## <a name="see-also"></a>Confira também

[SECURITY_DESCRIPTOR](/windows/win32/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)<br/>
[Classe CSecurityDesc](../../atl/reference/csecuritydesc-class.md)
