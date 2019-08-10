---
title: Classe CTokenGroups
ms.date: 11/04/2016
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
helpviewer_keywords:
- CTokenGroups class
ms.assetid: 2ab08076-4b08-4487-bc70-ec6dee304190
ms.openlocfilehash: 4e5d06ca01201bf415afedbe6f6e5bca096f68fa
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915584"
---
# <a name="ctokengroups-class"></a>Classe CTokenGroups

Essa classe é um wrapper para a `TOKEN_GROUPS` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CTokenGroups
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::CTokenGroups](#ctokengroups)|O construtor.|
|[CTokenGroups::~CTokenGroups](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::Add](#add)|Adiciona uma `CSid` estrutura existente `TOKEN_GROUPS` ao `CTokenGroups` objeto.|
|[CTokenGroups::Delete](#delete)|Exclui um `CSid` e seus atributos associados `CTokenGroups` do objeto.|
|[CTokenGroups::DeleteAll](#deleteall)|Exclui todos `CSid` os objetos e seus atributos associados `CTokenGroups` do objeto.|
|[CTokenGroups::GetCount](#getcount)|Retorna o número de `CSid` objetos e atributos associados contidos `CTokenGroups` no objeto.|
|[CTokenGroups::GetLength](#getlength)|Retorna o tamanho do `CTokenGroups` objeto.|
|[CTokenGroups::GetPTOKEN_GROUPS](#getptoken_groups)|Recupera um ponteiro para a `TOKEN_GROUPS` estrutura.|
|[CTokenGroups::GetSidsAndAttributes](#getsidsandattributes)|Recupera os `CSid` objetos e atributos `CTokenGroups` que pertencem ao objeto.|
|[CTokenGroups::LookupSid](#lookupsid)|Recupera os atributos associados a um `CSid` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups:: Operator const TOKEN_GROUPS *](#operator_const_token_groups__star)|Converte o `CTokenGroups` objeto em um ponteiro para a `TOKEN_GROUPS` estrutura.|
|[CTokenGroups::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/desktop/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado em um sistema Windows.

A `CTokenGroups` classe é um wrapper para a estrutura [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) , que contém informações sobre os SIDs (identificadores de segurança) de grupo em um token de acesso.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="add"></a>  CTokenGroups::Add

Adiciona uma `CSid` estrutura existente `TOKEN_GROUPS` ao `CTokenGroups` objeto.

```
void Add(const CSid& rSid, DWORD dwAttributes) throw(... );
void Add(const TOKEN_GROUPS& rTokenGroups) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Um objeto [CSid](../../atl/reference/csid-class.md) .

*dwAttributes*<br/>
Os atributos a serem associados `CSid` ao objeto.

*rTokenGroups*<br/>
Uma estrutura [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) .

### <a name="remarks"></a>Comentários

Esses métodos adicionam um ou `CSid` mais objetos e seus atributos associados `CTokenGroups` ao objeto.

##  <a name="ctokengroups"></a>  CTokenGroups::CTokenGroups

O construtor.

```
CTokenGroups() throw();
CTokenGroups(const CTokenGroups& rhs) throw(... );
CTokenGroups(const TOKEN_GROUPS& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `CTokenGroups` estrutura de objeto ou [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) com a qual construir `CTokenGroups` o objeto.

### <a name="remarks"></a>Comentários

O `CTokenGroups` objeto pode, opcionalmente, ser criado `TOKEN_GROUPS` usando uma estrutura ou um `CTokenGroups` objeto definido anteriormente.

##  <a name="dtor"></a>  CTokenGroups::~CTokenGroups

O destruidor.

```
virtual ~CTokenGroups() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="delete"></a>  CTokenGroups::Delete

Exclui um `CSid` e seus atributos associados `CTokenGroups` do objeto.

```
bool Delete(const CSid& rSid) throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) para o qual o Sid (identificador de segurança) e os atributos devem ser removidos.

### <a name="return-value"></a>Valor de retorno

Retorna true se o `CSid` for removido; caso contrário, false.

##  <a name="deleteall"></a>  CTokenGroups::DeleteAll

Exclui todos `CSid` os objetos e seus atributos associados `CTokenGroups` do objeto.

```
void DeleteAll() throw();
```

##  <a name="getcount"></a>  CTokenGroups::GetCount

Retorna o número de `CSid` objetos contidos em `CTokenGroups`.

```
UINT GetCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de objetos [CSid](../../atl/reference/csid-class.md) e seus atributos associados contidos no `CTokenGroups` objeto.

##  <a name="getlength"></a>  CTokenGroups::GetLength

Retorna o tamanho do `CTokenGroup` objeto.

```
UINT GetLength() const throw();
```

### <a name="remarks"></a>Comentários

Retorna o tamanho total do `CTokenGroup` objeto, em bytes.

##  <a name="getptoken_groups"></a>  CTokenGroups::GetPTOKEN_GROUPS

Recupera um ponteiro para a `TOKEN_GROUPS` estrutura.

```
const TOKEN_GROUPS* GetPTOKEN_GROUPS() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Recupera um ponteiro para a estrutura [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) que pertence ao `CTokenGroups` objeto token de acesso.

##  <a name="getsidsandattributes"></a>  CTokenGroups::GetSidsAndAttributes

Recupera os `CSid` objetos e (opcionalmente) os atributos `CTokenGroups` que pertencem ao objeto.

```
void GetSidsAndAttributes(
    CSid::CSidArray* pSids,
    CAtlArray<DWORD>* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Ponteiro para uma matriz de objetos [CSid](../../atl/reference/csid-class.md) .

*pAttributes*<br/>
Ponteiro para uma matriz de DWORDs. Se esse parâmetro for omitido ou nulo, os atributos não serão recuperados.

### <a name="remarks"></a>Comentários

Esse método irá enumerar todos `CSid` os objetos contidos `CTokenGroups` no objeto e colocá-los e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

##  <a name="lookupsid"></a>  CTokenGroups::LookupSid

Recupera os atributos associados a um `CSid` objeto.

```
bool LookupSid(
    const CSid& rSid,
    DWORD* pdwAttributes = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) .

*pdwAttributes*<br/>
Ponteiro para um DWORD que aceitará o `CSid` atributo do objeto. Se omitido ou NULL, o atributo não será recuperado.

### <a name="return-value"></a>Valor de retorno

Retorna true se o `CSid` for encontrado; caso contrário, false.

### <a name="remarks"></a>Comentários

Definir *pdwAttributes* como NULL fornece uma maneira de confirmar a existência do `CSid` sem acessar o atributo. Observe que esse método não deve ser usado para verificar os direitos de acesso. Em vez disso, os aplicativos devem usar o método [CAccessToken:: CheckTokenMembership](../../atl/reference/caccesstoken-class.md#checktokenmembership) .

##  <a name="operator_eq"></a>  CTokenGroups::operator =

Operador de atribuição.

```
CTokenGroups& operator= (const TOKEN_GROUPS& rhs) throw(...);
CTokenGroups& operator= (const CTokenGroups& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `CTokenGroups` estrutura de objeto ou [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) `CTokenGroups` a ser atribuída ao objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CTokenGroups` atualizado.

##  <a name="operator_const_token_groups__star"></a>CTokenGroups:: Operator const TOKEN_GROUPS *

Converte um valor em um ponteiro para a `TOKEN_GROUPS` estrutura.

```
operator const TOKEN_GROUPS *() const throw(...);
```

### <a name="remarks"></a>Comentários

Converte um valor em um ponteiro para a estrutura [TOKEN_GROUPS](/windows/desktop/api/winnt/ns-winnt-token_groups) .

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[Classe CSid](../../atl/reference/csid-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
