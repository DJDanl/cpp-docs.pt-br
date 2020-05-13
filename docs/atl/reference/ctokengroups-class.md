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
ms.openlocfilehash: ccfa628f4a099f7e13eb09d272c72c2bdd846f37
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746384"
---
# <a name="ctokengroups-class"></a>Classe CTokenGroups

Esta aula é um `TOKEN_GROUPS` invólucro para a estrutura.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CTokenGroups::Adicionar](#add)|Adiciona `CSid` uma `TOKEN_GROUPS` estrutura ou `CTokenGroups` existente ao objeto.|
|[CTokenGroups::Delete](#delete)|Exclui a `CSid` e seus atributos associados do `CTokenGroups` objeto.|
|[CTokenGroups::DeleteAll](#deleteall)|Exclui todos `CSid` os objetos e `CTokenGroups` seus atributos associados do objeto.|
|[CTokenGroups::GetCount](#getcount)|Retorna o `CSid` número de objetos e `CTokenGroups` atributos associados contidos no objeto.|
|[CTokenGroups::GetLength](#getlength)|Retorna o tamanho `CTokenGroups` do objeto.|
|[CTokenGroups::GetPTOKEN_GROUPS](#getptoken_groups)|Recupera um ponteiro `TOKEN_GROUPS` para a estrutura.|
|[CTokenGroups::GetSidsAndAttributes](#getsidsandattributes)|Recupera os `CSid` objetos e atributos pertencentes ao `CTokenGroups` objeto.|
|[CTokenGroups::LookupSid](#lookupsid)|Recupera os atributos `CSid` associados a um objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTokenGroups::TOKEN_GROUPS const do operador *](#operator_const_token_groups__star)|Lança o `CTokenGroups` objeto para um `TOKEN_GROUPS` ponteiro para a estrutura.|
|[CTokenGroups::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou segmento e é alocado para cada usuário conectado em um sistema Windows.

A `CTokenGroups` classe é um invólucro para a estrutura [TOKEN_GROUPS,](/windows/win32/api/winnt/ns-winnt-token_groups) contendo informações sobre os identificadores de segurança do grupo (SIDs) em um token de acesso.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="ctokengroupsadd"></a><a name="add"></a>CTokenGroups::Adicionar

Adiciona `CSid` uma `TOKEN_GROUPS` estrutura ou `CTokenGroups` existente ao objeto.

```cpp
void Add(const CSid& rSid, DWORD dwAttributes) throw(... );
void Add(const TOKEN_GROUPS& rTokenGroups) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Um objeto [CSid.](../../atl/reference/csid-class.md)

*dwAttributeS*<br/>
Os atributos para `CSid` associar com o objeto.

*rTokenGroups*<br/>
Uma estrutura [TOKEN_GROUPS.](/windows/win32/api/winnt/ns-winnt-token_groups)

### <a name="remarks"></a>Comentários

Esses métodos adicionam `CSid` um ou mais objetos e seus atributos associados ao `CTokenGroups` objeto.

## <a name="ctokengroupsctokengroups"></a><a name="ctokengroups"></a>CTokenGroups::CTokenGroups

O construtor.

```
CTokenGroups() throw();
CTokenGroups(const CTokenGroups& rhs) throw(... );
CTokenGroups(const TOKEN_GROUPS& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenGroups` objeto ou [TOKEN_GROUPS](/windows/win32/api/winnt/ns-winnt-token_groups) estrutura `CTokenGroups` com a qual construir o objeto.

### <a name="remarks"></a>Comentários

O `CTokenGroups` objeto pode ser criado `TOKEN_GROUPS` opcionalmente usando uma `CTokenGroups` estrutura ou um objeto previamente definido.

## <a name="ctokengroupsctokengroups"></a><a name="dtor"></a>CTokenGroups::~CTokenGroups

O destruidor.

```
virtual ~CTokenGroups() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

## <a name="ctokengroupsdelete"></a><a name="delete"></a>CTokenGroups::Delete

Exclui a `CSid` e seus atributos associados do `CTokenGroups` objeto.

```
bool Delete(const CSid& rSid) throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) para o qual o identificador de segurança (SID) e os atributos devem ser removidos.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro `CSid` se for removido, falso de outra forma.

## <a name="ctokengroupsdeleteall"></a><a name="deleteall"></a>CTokenGroups::DeleteAll

Exclui todos `CSid` os objetos e `CTokenGroups` seus atributos associados do objeto.

```cpp
void DeleteAll() throw();
```

## <a name="ctokengroupsgetcount"></a><a name="getcount"></a>CTokenGroups::GetCount

Retorna o `CSid` número de `CTokenGroups`objetos contidos em .

```
UINT GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de objetos [CSid](../../atl/reference/csid-class.md) e `CTokenGroups` seus atributos associados contidos no objeto.

## <a name="ctokengroupsgetlength"></a><a name="getlength"></a>CTokenGroups::GetLength

Retorna o tamanho `CTokenGroup` do objeto.

```
UINT GetLength() const throw();
```

### <a name="remarks"></a>Comentários

Retorna o tamanho `CTokenGroup` total do objeto, em bytes.

## <a name="ctokengroupsgetptoken_groups"></a><a name="getptoken_groups"></a>CTokenGroups::GetPTOKEN_GROUPS

Recupera um ponteiro `TOKEN_GROUPS` para a estrutura.

```
const TOKEN_GROUPS* GetPTOKEN_GROUPS() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro [TOKEN_GROUPS](/windows/win32/api/winnt/ns-winnt-token_groups) para a estrutura `CTokenGroups` TOKEN_GROUPS pertencente ao objeto token de acesso.

## <a name="ctokengroupsgetsidsandattributes"></a><a name="getsidsandattributes"></a>CTokenGroups::GetSidsAndAttributes

Recupera os `CSid` objetos e (opcionalmente) os `CTokenGroups` atributos pertencentes ao objeto.

```cpp
void GetSidsAndAttributes(
    CSid::CSidArray* pSids,
    CAtlArray<DWORD>* pAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSids*<br/>
Ponteiro para uma matriz de objetos [CSid.](../../atl/reference/csid-class.md)

*pAtributos*<br/>
Ponteiro para uma matriz de DWORDs. Se este parâmetro for omitido ou NULO, os atributos não serão recuperados.

### <a name="remarks"></a>Comentários

Este método enumerará todos `CSid` os objetos contidos no objeto e os `CTokenGroups` colocará e (opcionalmente) os sinalizadores de atributo em objetos de matriz.

## <a name="ctokengroupslookupsid"></a><a name="lookupsid"></a>CTokenGroups::LookupSid

Recupera os atributos `CSid` associados a um objeto.

```
bool LookupSid(
    const CSid& rSid,
    DWORD* pdwAttributes = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [CSid.](../../atl/reference/csid-class.md)

*Pdwattributes*<br/>
Ponteiro para um DWORD `CSid` que aceitará o atributo do objeto. Se omitido ou NULO, o atributo não será recuperado.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro `CSid` se for encontrado, falso de outra forma.

### <a name="remarks"></a>Comentários

Definir *pdwAttributes* to NULL fornece uma maneira `CSid` de confirmar a existência do sem acessar o atributo. Observe que este método não deve ser usado para verificar os direitos de acesso. Os aplicativos devem, em vez disso, usar o método [CAccessToken::CheckTokenMembership.](../../atl/reference/caccesstoken-class.md#checktokenmembership)

## <a name="ctokengroupsoperator-"></a><a name="operator_eq"></a>CTokenGroups::operador =

Operador de atribuição.

```
CTokenGroups& operator= (const TOKEN_GROUPS& rhs) throw(...);
CTokenGroups& operator= (const CTokenGroups& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CTokenGroups` objeto ou [TOKEN_GROUPS](/windows/win32/api/winnt/ns-winnt-token_groups) estrutura `CTokenGroups` para atribuir ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna o `CTokenGroups` objeto atualizado.

## <a name="ctokengroupsoperator-const-token_groups-"></a><a name="operator_const_token_groups__star"></a>CTokenGroups::TOKEN_GROUPS const do operador *

Lança um valor para um `TOKEN_GROUPS` ponteiro para a estrutura.

```
operator const TOKEN_GROUPS *() const throw(...);
```

### <a name="remarks"></a>Comentários

Lança um valor para um ponteiro para a estrutura [TOKEN_GROUPS.](/windows/win32/api/winnt/ns-winnt-token_groups)

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Classe CSid](../../atl/reference/csid-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
