---
title: Classe CComGITPTR
ms.date: 11/04/2016
f1_keywords:
- CComGITPtr
- ATLBASE/ATL::CComGITPtr
- ATLBASE/ATL::CComGITPtr::CComGITPtr
- ATLBASE/ATL::CComGITPtr::Attach
- ATLBASE/ATL::CComGITPtr::CopyTo
- ATLBASE/ATL::CComGITPtr::Detach
- ATLBASE/ATL::CComGITPtr::GetCookie
- ATLBASE/ATL::CComGITPtr::Revoke
- ATLBASE/ATL::CComGITPtr::m_dwCookie
helpviewer_keywords:
- CComGITPtr class
ms.assetid: af895acb-525a-4555-bb67-b241b7df515b
ms.openlocfilehash: 230eeb1577189d2057e530e1df8ef99c611fb32b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327833"
---
# <a name="ccomgitptr-class"></a>Classe CComGITPTR

Esta classe fornece métodos para lidar com ponteiros de interface e a tabela de interface global (GIT).

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CComGITPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do ponteiro de interface a ser armazenado no GIT.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComGITPtr::CComGITPtr](#ccomgitptr)|O construtor.|
|[CComGITPtr::~CComGITPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComGITPtr::Anexar](#attach)|Chame este método para registrar o ponteiro de interface na tabela de interface global (GIT).|
|[CComGITPtr::CopyTo](#copyto)|Chame este método para copiar a interface da tabela de interface global (GIT) para o ponteiro aprovado.|
|[CComGITPtr::Detach](#detach)|Chame este método para desassociar `CComGITPtr` a interface do objeto.|
|[CComGITPtr::GetCookie](#getcookie)|Chame este método para devolver `CComGITPtr` o cookie do objeto.|
|[CComGITPtr::Revogar](#revoke)|Chame este método para remover a interface da tabela de interface global (GIT).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComGITPtr::operador DWORD](#operator_dword)|Devolve o cookie `CComGITPtr` do objeto.|
|[CComGITPtr::operador](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComGITPtr::m_dwCookie](#m_dwcookie)|O biscoito.|

## <a name="remarks"></a>Comentários

Objetos que agregam o marshaler threaded livre e precisam usar ponteiros de interface obtidos de outros objetos devem tomar medidas extras para garantir que as interfaces sejam corretamente empacotadas. Normalmente, isso envolve armazenar os ponteiros de interface no GIT e obter o ponteiro do GIT cada vez que ele é usado. A `CComGITPtr` classe é fornecida para ajudá-lo a usar ponteiros de interface armazenados no GIT.

> [!NOTE]
> A instalação global de tabela de interface só está disponível no Windows 95 com a versão 1.1 do DCOM e posterior, o Windows 98, o Windows NT 4.0 com o Service Pack 3 e posterior, e o Windows 2000.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomgitptrattach"></a><a name="attach"></a>CComGITPtr::Anexar

Chame este método para registrar o ponteiro de interface na tabela de interface global (GIT).

```
HRESULT Attach(T* p) throw();

HRESULT Attach(DWORD dwCookie) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
O ponteiro de interface a ser adicionado ao GIT.

*Dwcookie*<br/>
O cookie usado para identificar o ponteiro da interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se o GIT não for válido ou se o cookie for igual a NULL.

## <a name="ccomgitptrccomgitptr"></a><a name="ccomgitptr"></a>CComGITPtr::CComGITPtr

O construtor.

```
CComGITPtr() throw();
CComGITPtr(T* p);
CComGITPtr(const CComGITPtr& git);
explicit CComGITPtr(DWORD dwCookie) throw();
CComGITPtr(CComGITPtr&& rv);
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Um ponteiro de interface a ser armazenado na tabela de interface global (GIT).

*Git*<br/>
[em] Uma referência a `CComGITPtr` um objeto existente.

*Dwcookie*<br/>
[em] Um cookie usado para identificar o ponteiro de interface.

*Rv*<br/>
[em] O `CComGITPtr` objeto de origem para mover dados de.

### <a name="remarks"></a>Comentários

Cria um `CComGITPtr` novo objeto, opcionalmente `CComGITPtr` usando um objeto existente.

O construtor que utiliza *o rv* é um construtor move. Os dados são movidos da fonte, *rv*, e, em seguida, *o rv* é limpo.

## <a name="ccomgitptrccomgitptr"></a><a name="dtor"></a>CComGITPtr::~CComGITPtr

O destruidor.

```
~CComGITPtr() throw();
```

### <a name="remarks"></a>Comentários

Remove a interface da tabela de interface global (GIT), usando [CComGITPtr::Revoke](#revoke).

## <a name="ccomgitptrcopyto"></a><a name="copyto"></a>CComGITPtr::CopyTo

Chame este método para copiar a interface da tabela de interface global (GIT) para o ponteiro aprovado.

```
HRESULT CopyTo(T** pp) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pp*<br/>
O ponteiro que é para receber a interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

A interface do GIT é copiada para o ponteiro passado. O ponteiro deve ser liberado pelo chamador quando não for mais necessário.

## <a name="ccomgitptrdetach"></a><a name="detach"></a>CComGITPtr::Detach

Chame este método para desassociar `CComGITPtr` a interface do objeto.

```
DWORD Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Devolve o cookie `CComGITPtr` do objeto.

### <a name="remarks"></a>Comentários

Cabe ao chamador remover a interface do GIT, usando [CComGITPtr::Revogar](#revoke).

## <a name="ccomgitptrgetcookie"></a><a name="getcookie"></a>CComGITPtr::GetCookie

Chame este método para devolver `CComGITPtr` o cookie do objeto.

```
DWORD GetCookie() const;
```

### <a name="return-value"></a>Valor retornado

Devolve o biscoito.

### <a name="remarks"></a>Comentários

O cookie é uma variável usada para identificar uma interface e sua localização.

## <a name="ccomgitptrm_dwcookie"></a><a name="m_dwcookie"></a>CComGITPtr::m_dwCookie

O biscoito.

```
DWORD m_dwCookie;
```

### <a name="remarks"></a>Comentários

O cookie é uma variável de membro usada para identificar uma interface e sua localização.

## <a name="ccomgitptroperator-"></a><a name="operator_eq"></a>CComGITPtr::operador

O operador de atribuição.

```
CComGITPtr& operator= (T* p);
CComGITPtr& operator= (const CComGITPtr& git);
CComGITPtr& operator= (DWORD dwCookie);
CComGITPtr& operator= (CComGITPtr&& rv);
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Um ponteiro para uma interface.

*Git*<br/>
[em] Uma referência `CComGITPtr` a um objeto.

*Dwcookie*<br/>
[em] Um cookie usado para identificar o ponteiro de interface.

*Rv*<br/>
[em] O `CComGITPtr` para mover dados de.

### <a name="return-value"></a>Valor retornado

Retorna o `CComGITPtr` objeto atualizado.

### <a name="remarks"></a>Comentários

Atribui um novo valor `CComGITPtr` a um objeto, seja de um objeto existente ou de uma referência a uma tabela de interface global.

## <a name="ccomgitptroperator-dword"></a><a name="operator_dword"></a>CComGITPtr::operador DWORD

Retorna o cookie `CComGITPtr` associado ao objeto.

```
operator DWORD() const;
```

### <a name="remarks"></a>Comentários

O cookie é uma variável usada para identificar uma interface e sua localização.

## <a name="ccomgitptrrevoke"></a><a name="revoke"></a>CComGITPtr::Revogar

Chame este método para remover a interface atual da tabela de interface global (GIT).

```
HRESULT Revoke() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Remove a interface do GIT.

## <a name="see-also"></a>Confira também

[Marshaler livre de threads](../../atl/atl-and-the-free-threaded-marshaler.md)<br/>
[Acessando interfaces em apartamentos](/windows/win32/com/accessing-interfaces-across-apartments)<br/>
[Quando usar a tabela de interface global](/windows/win32/com/when-to-use-the-global-interface-table)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
