---
title: Classe CPrivateObjectSecurityDesc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::ConvertToAutoInherit
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Create
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Get
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Set
dev_langs:
- C++
helpviewer_keywords:
- CPrivateObjectSecurityDesc class
ms.assetid: 2c4bbb13-bf99-4833-912a-197f6815bb5d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d14b4598020358de01a7914b369eac2b8f5b016d
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076094"
---
# <a name="cprivateobjectsecuritydesc-class"></a>Classe CPrivateObjectSecurityDesc

Essa classe representa um objeto de descritor de segurança do objeto privado.

## <a name="syntax"></a>Sintaxe

```
class CPrivateObjectSecurityDesc : public CSecurityDesc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc](#cprivateobjectsecuritydesc)|O construtor.|
|[CPrivateObjectSecurityDesc::~CPrivateObjectSecurityDesc](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrivateObjectSecurityDesc::ConvertToAutoInherit](#converttoautoinherit)|Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que dá suporte à propagação automática de entradas de controle de acesso herdadas (ACEs).|
|[CPrivateObjectSecurityDesc::Create](#create)|Chame esse método para alocar e inicializar um descritor de segurança autorrelativo para o objeto particular criado pelo Gerenciador de recursos chamada.|
|[CPrivateObjectSecurityDesc::Get](#get)|Chame esse método para recuperar informações do descritor de segurança de um objeto particular.|
|[CPrivateObjectSecurityDesc::Set](#set)|Chame esse método para modificar o descritor de segurança de um objeto particular.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Essa classe, derivada de [CSecurityDesc](../../atl/reference/csecuritydesc-class.md), fornece métodos para criar e gerenciar o descritor de segurança de um objeto particular.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CSecurityDesc](../../atl/reference/csecuritydesc-class.md)

`CPrivateObjectSecurityDesc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="converttoautoinherit"></a>  CPrivateObjectSecurityDesc::ConvertToAutoInherit

Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que dá suporte à propagação automática de entradas de controle de acesso herdadas (ACEs).

```
bool ConvertToAutoInherit(
    const CSecurityDesc* pParent,
    GUID* ObjectType,
    bool bIsDirectoryObject,
    PGENERIC_MAPPING GenericMapping) throw();
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
Ponteiro para um [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto referenciando o contêiner pai do objeto. Se não houver nenhum contêiner pai, esse parâmetro é NULL.

*ObjectType*<br/>
Ponteiro para um `GUID` estrutura que identifica o tipo de objeto associado ao objeto atual. Definir *ObjectType* como NULL se o objeto não tem um GUID.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*GenericMapping*<br/>
Ponteiro para um [GENERIC_MAPPING](/windows/desktop/api/winnt/ns-winnt-_generic_mapping) estrutura que especifica o mapeamento de cada direito genérico de direitos específicos para o objeto.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Esse método tenta determinar se as ACEs no controle de acesso discricionário listam (DACL) e a lista de controle de acesso do sistema (SACL) do descritor de segurança atual foram herdados do descritor de segurança do pai. Ele chama o [ConvertToAutoInheritPrivateObjectSecurity](https://msdn.microsoft.com/library/windows/desktop/aa376403) função.

##  <a name="cprivateobjectsecuritydesc"></a>  CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc

O construtor.

```
CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o objeto `CPrivateObjectSecurityDesc`.

##  <a name="dtor"></a>  CPrivateObjectSecurityDesc::~CPrivateObjectSecurityDesc

O destruidor.

```
~CPrivateObjectSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados e exclui o descritor de segurança do objeto privado.

##  <a name="create"></a>  CPrivateObjectSecurityDesc::Create

Chame esse método para alocar e inicializar um descritor de segurança autorrelativo para o objeto particular criado pelo Gerenciador de recursos chamada.

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
Ponteiro para um [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto referenciando o diretório pai no qual um novo objeto é criado. Definido como NULL se não houver nenhum diretório pai.

*pCreator*<br/>
Ponteiro para um descritor de segurança fornecido pelo criador do objeto. Se o criador do objeto não passar explicitamente as informações de segurança para o novo objeto, defina esse parâmetro como NULL.

*bIsDirectoryObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*token*<br/>
Referência para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto para o processo do cliente em cujo nome o objeto está sendo criado.

*GenericMapping*<br/>
Ponteiro para um [GENERIC_MAPPING](/windows/desktop/api/winnt/ns-winnt-_generic_mapping) estrutura que especifica o mapeamento de cada direito genérico de direitos específicos para o objeto.

*ObjectType*<br/>
Ponteiro para um `GUID` estrutura que identifica o tipo de objeto associado ao objeto atual. Definir *ObjectType* como NULL se o objeto não tem um GUID.

*bIsContainerObject*<br/>
Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bit que controlam como as entradas de controle de acesso (ACEs) são herdadas de *pParent*. Ver [CreatePrivateObjectSecurityEx](https://msdn.microsoft.com/library/windows/desktop/aa446581) para obter mais detalhes.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Este método chama [CreatePrivateObjectSercurity](https://msdn.microsoft.com/library/windows/desktop/aa376405) ou [CreatePrivateObjectSecurityEx](https://msdn.microsoft.com/library/windows/desktop/aa446581).

O segundo método permite especificar o tipo de objeto GUID do novo objeto ou controlar como as ACEs são herdadas.

> [!NOTE]
>  Um descritor de segurança autorrelativo é um descritor de segurança que armazena todas as suas informações de segurança em um bloco contíguo de memória.

##  <a name="get"></a>  CPrivateObjectSecurityDesc::Get

Chame esse método para recuperar informações do descritor de segurança de um objeto particular.

```
bool Get(
    SECURITY_INFORMATION si,
    CSecurityDesc* pResult) const throw();
```

### <a name="parameters"></a>Parâmetros

*si*<br/>
Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança para recuperar. Esse valor pode ser uma combinação da [SECURITY_INFORMATION](/windows/desktop/SecAuthZ/security-information) sinalizadores de bit.

*pResult*<br/>
Ponteiro para um [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto que recebe uma cópia das informações solicitadas do descritor de segurança especificado.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O descritor de segurança é uma estrutura e dados associados que contém as informações de segurança de um objeto protegível.

##  <a name="operator_eq"></a>  CPrivateObjectSecurityDesc::operator =

Operador de atribuição.

```
CPrivateObjectSecurityDesc& operator= (const CPrivateObjectSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O objeto `CPrivateObjectSecurityDesc` a ser atribuído ao objeto atual.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CPrivateObjectSecurityDesc` objeto.

##  <a name="set"></a>  CPrivateObjectSecurityDesc::Set

Chame esse método para modificar o descritor de segurança de um objeto particular.

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
Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança para definir. Esse valor pode ser uma combinação da [SECURITY_INFORMATION](/windows/desktop/SecAuthZ/security-information) sinalizadores de bit.

*Modificação*<br/>
Ponteiro para um [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto. As partes desse descritor de segurança é indicada pela *si* parâmetro são aplicadas ao descritor de segurança do objeto.

*GenericMapping*<br/>
Ponteiro para um [GENERIC_MAPPING](/windows/desktop/api/winnt/ns-winnt-_generic_mapping) estrutura que especifica o mapeamento de cada direito genérico de direitos específicos para o objeto.

*token*<br/>
Referência para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto para o processo do cliente em cujo nome o objeto está sendo criado.

*AutoInheritFlags*<br/>
Um conjunto de sinalizadores de bit que controlam como as entradas de controle de acesso (ACEs) são herdadas de *pParent*. Ver [CreatePrivateObjectSecurityEx](https://msdn.microsoft.com/library/windows/desktop/aa446581) para obter mais detalhes.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

O segundo método permite especificar o tipo de objeto GUID do objeto ou controlar como as ACEs são herdadas.

## <a name="see-also"></a>Consulte também

[SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-_security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)<br/>
[Classe CSecurityDesc](../../atl/reference/csecuritydesc-class.md)
