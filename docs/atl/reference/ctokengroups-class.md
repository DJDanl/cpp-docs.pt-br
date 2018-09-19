---
title: Classe CTokenGroups | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CTokenGroups
- ATLSECURITY/ATL::CTokenGroups
- ATLSECURITY/ATL::CTokenGroups::CTokenGroups
- ATLSECURITY/ATL::CTokenGroups::Add
- ATLSECURITY/ATL::CTokenGroups::Delete
- ATLSECURITY/ATL::CTokenGroups::DeleteAll
- ATLSECURITY/ATL::CTokenGroups::GetCount
- ATLSECURITY/ATL::CTokenGroups::GetLength
- ATLSECURITY/ATL::CTokenGroups::GetPTOKEN_GROUPS
- ATLSECURITY/ATL::CTokenGroups::GetSidsAndAttributes
- ATLSECURITY/ATL::CTokenGroups::LookupSid
dev_langs:
- C++
helpviewer_keywords:
- CTokenGroups class
ms.assetid: 2ab08076-4b08-4487-bc70-ec6dee304190
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1d14a839cded7d22236912ba52a733a9ce15f7aa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103226"
---
# <a name="ctokengroups-class"></a>Classe CTokenGroups

Essa classe é um wrapper para o `TOKEN_GROUPS` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CTokenGroups
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::CTokenGroups](#ctokengroups)|O construtor.|
|[CTokenGroups::~CTokenGroups](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::Add](#add)|Adiciona uma `CSid` ou existentes `TOKEN_GROUPS` estrutura para o `CTokenGroups` objeto.|
|[CTokenGroups::Delete](#delete)|Exclui um `CSid` e seus atributos associados a partir de `CTokenGroups` objeto.|
|[CTokenGroups::DeleteAll](#deleteall)|Exclui todos os `CSid` objetos e seus atributos associados a partir de `CTokenGroups` objeto.|
|[CTokenGroups::GetCount](#getcount)|Retorna o número de `CSid` objetos e atributos associados, contidos no `CTokenGroups` objeto.|
|[CTokenGroups::GetLength](#getlength)|Retorna o tamanho do `CTokenGroups` objeto.|
|[CTokenGroups::GetPTOKEN_GROUPS](#getptoken_groups)|Recupera um ponteiro para o `TOKEN_GROUPS` estrutura.|
|[CTokenGroups::GetSidsAndAttributes](#getsidsandattributes)|Recupera o `CSid` objetos e atributos que pertencem ao `CTokenGroups` objeto.|
|[CTokenGroups::LookupSid](#lookupsid)|Recupera os atributos associados com um `CSid` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::operator TOKEN_GROUPS de const *](#operator_const_token_groups__star)|Conversões de `CTokenGroups` objeto em um ponteiro para o `TOKEN_GROUPS` estrutura.|
|[CTokenGroups::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Uma [token de acesso](/windows/desktop/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado no sistema Windows.

O `CTokenGroups` classe é um wrapper para o [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura, que contém informações sobre os identificadores de segurança (SIDs) do grupo em um token de acesso.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="add"></a>  CTokenGroups::Add

Adiciona uma `CSid` ou existentes `TOKEN_GROUPS` estrutura para o `CTokenGroups` objeto.

```
void Add(const CSid& rSid, DWORD dwAttributes) throw(... );
void Add(const TOKEN_GROUPS& rTokenGroups) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Um [CSid](../../atl/reference/csid-class.md) objeto.

*dwAttributes*<br/>
Os atributos para associar o `CSid` objeto.

*rTokenGroups*<br/>
Um [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura.

### <a name="remarks"></a>Comentários

Esses métodos de adicionam um ou mais `CSid` objetos e seus atributos associados para o `CTokenGroups` objeto.

##  <a name="ctokengroups"></a>  CTokenGroups::CTokenGroups

O construtor.

```
CTokenGroups() throw();
CTokenGroups(const CTokenGroups& rhs) throw(... );
CTokenGroups(const TOKEN_GROUPS& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenGroups` objeto ou [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura com a qual construir a `CTokenGroups` objeto.

### <a name="remarks"></a>Comentários

O `CTokenGroups` objeto opcionalmente pode ser criado usando um `TOKEN_GROUPS` estrutura ou definida anteriormente `CTokenGroups` objeto.

##  <a name="dtor"></a>  CTokenGroups::~CTokenGroups

O destruidor.

```
virtual ~CTokenGroups() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="delete"></a>  CTokenGroups::Delete

Exclui um `CSid` e seus atributos associados a partir de `CTokenGroups` objeto.

```
bool Delete(const CSid& rSid) throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O [CSid](../../atl/reference/csid-class.md) objeto para o qual o identificador de segurança (SID) e os atributos devem ser removidos.

### <a name="return-value"></a>Valor de retorno

Retornará true se o `CSid` for removido, false caso contrário.

##  <a name="deleteall"></a>  CTokenGroups::DeleteAll

Exclui todos os `CSid` objetos e seus atributos associados a partir de `CTokenGroups` objeto.

```
void DeleteAll() throw();
```

##  <a name="getcount"></a>  CTokenGroups::GetCount

Retorna o número de `CSid` objetos contidos no `CTokenGroups`.

```
UINT GetCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de [CSid](../../atl/reference/csid-class.md) objetos e seus atributos associados, contidos no `CTokenGroups` objeto.

##  <a name="getlength"></a>  CTokenGroups::GetLength

Retorna o tamanho do `CTokenGroup` objeto.

```
UINT GetLength() const throw();
```

### <a name="remarks"></a>Comentários

Retorna o tamanho total do `CTokenGroup` objeto, em bytes.

##  <a name="getptoken_groups"></a>  CTokenGroups::GetPTOKEN_GROUPS

Recupera um ponteiro para o `TOKEN_GROUPS` estrutura.

```
const TOKEN_GROUPS* GetPTOKEN_GROUPS() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Recupera um ponteiro para o [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura que pertencem ao `CTokenGroups` objeto de token de acesso.

##  <a name="getsidsandattributes"></a>  CTokenGroups::GetSidsAndAttributes

Recupera o `CSid` atributos que pertencem a objetos e (opcionalmente) o `CTokenGroups` objeto.

```
void GetSidsAndAttributes(
    CSid::CSidArray* pSids,
    CAtlArray<DWORD>* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Ponteiro para uma matriz de [CSid](../../atl/reference/csid-class.md) objetos.

*pAttributes*<br/>
Ponteiro para uma matriz de DWORDs. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados.

### <a name="remarks"></a>Comentários

Esse método vai enumerar todos os `CSid` objetos contidos no `CTokenGroups` do objeto e colocá-los e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

##  <a name="lookupsid"></a>  CTokenGroups::LookupSid

Recupera os atributos associados com um `CSid` objeto.

```
bool LookupSid(  
    const CSid& rSid,
    DWORD* pdwAttributes = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O [CSid](../../atl/reference/csid-class.md) objeto.

*pdwAttributes*<br/>
Ponteiro para um DWORD que aceitará o `CSid` atributo do objeto. Se omitido ou nulo, o atributo não será recuperado.

### <a name="return-value"></a>Valor de retorno

Retornará true se o `CSid` for encontrada, FALSO caso contrário.

### <a name="remarks"></a>Comentários

Definindo *pdwAttributes* para nulo fornece uma maneira de confirmar a existência da `CSid` sem acessar o atributo. Observe que esse método não deve ser usado para verificar os direitos de acesso. Em vez disso, os aplicativos devem usar o [CAccessToken::CheckTokenMembership](../../atl/reference/caccesstoken-class.md#checktokenmembership) método.

##  <a name="operator_eq"></a>  CTokenGroups::operator =

Operador de atribuição.

```
CTokenGroups& operator= (const TOKEN_GROUPS& rhs) throw(...);
CTokenGroups& operator= (const CTokenGroups& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenGroups` objeto ou [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura para atribuir ao `CTokenGroups` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CTokenGroups` objeto.

##  <a name="operator_const_token_groups__star"></a>  CTokenGroups::operator TOKEN_GROUPS de const *

Converte um valor para um ponteiro para o `TOKEN_GROUPS` estrutura.

```
operator const TOKEN_GROUPS *() const throw(...);
```

### <a name="remarks"></a>Comentários

Converte um valor para um ponteiro para o [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-_token_groups) estrutura.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../visual-cpp-samples.md)<br/>
[Classe CSid](../../atl/reference/csid-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
