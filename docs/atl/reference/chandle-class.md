---
title: Classe CHandle
ms.date: 07/09/2019
f1_keywords:
- CHandle
- ATLBASE/ATL::CHandle
- ATLBASE/ATL::CHandle::CHandle
- ATLBASE/ATL::CHandle::Attach
- ATLBASE/ATL::CHandle::Close
- ATLBASE/ATL::CHandle::Detach
- ATLBASE/ATL::CHandle::m_h
helpviewer_keywords:
- CHandle class
ms.assetid: 883e9db5-40ec-4e29-9c74-4dd2ddd2e35d
ms.openlocfilehash: 7c72ded75298ed69efe73c1a81abf404545ea9b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326931"
---
# <a name="chandle-class"></a>Classe CHandle

Esta classe fornece métodos para criar e usar um objeto de alça.

## <a name="syntax"></a>Sintaxe

```
class CHandle
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::CHandle](#chandle)|O construtor.|
|[CHandle::~CHandle](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::attach](#attach)|Chame este método `CHandle` para anexar o objeto a uma alça existente.|
|[CHandle::Fechar](#close)|Chame este método `CHandle` para fechar um objeto.|
|[CHandle::Detach](#detach)|Chame este método para separar `CHandle` uma alça de um objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::manipulação do operador](#operator_handle)|Devolve o valor da pega armazenada.|
|[CHandle::operador =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::m_h](#m_h)|A variável membro que armazena a alça.|

## <a name="remarks"></a>Comentários

Um `CHandle` objeto pode ser usado sempre que uma alça `CHandle` for necessária: a principal diferença é que o objeto será automaticamente excluído.

> [!NOTE]
> Algumas funções de API usarão NULL como uma alça vazia ou inválida, enquanto outras usarão INVALID_HANDLE_VALUE. `CHandle`só usa NULL e tratará INVALID_HANDLE_VALUE como uma alça real. Se você ligar para uma API que pode retornar INVALID_HANDLE_VALUE, você deve verificar se `CHandle` há esse valor antes de ligar para [CHandle:::Anexar](#attach) ou passá-la para o construtor e, em vez disso, passar NULL.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="chandleattach"></a><a name="attach"></a>CHandle::attach

Chame este método `CHandle` para anexar o objeto a uma alça existente.

```
void Attach(HANDLE h) throw();
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
`CHandle`tomará posse da alça *h*.

### <a name="remarks"></a>Comentários

Atribui o `CHandle` objeto à alça *h* e, em seguida, chama **h.Desapego()**. Em compilações de debugs, um ATLASSERT será levantado se *h* for NULL. Não é feita outra verificação quanto à validade da alça.

## <a name="chandlechandle"></a><a name="chandle"></a>CHandle::CHandle

O construtor.

```
CHandle() throw();
CHandle(CHandle& h) throw();
explicit CHandle(HANDLE h) throw();
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Uma alça existente `CHandle`ou .

### <a name="remarks"></a>Comentários

Cria um `CHandle` novo objeto, opcionalmente usando `CHandle` uma alça ou objeto existente.

## <a name="chandlechandle"></a><a name="dtor"></a>CHandle::~CHandle

O destruidor.

```
~CHandle() throw();
```

### <a name="remarks"></a>Comentários

Libera o `CHandle` objeto chamando [CHandle::Close](#close).

## <a name="chandleclose"></a><a name="close"></a>CHandle::Fechar

Chame este método `CHandle` para fechar um objeto.

```
void Close() throw();
```

### <a name="remarks"></a>Comentários

Fecha uma alça de objeto aberta. Se a alça for NULA, `Close` o que será o caso se já tiver sido chamado, um ATLASSERT será levantado em compilações de depuração.

## <a name="chandledetach"></a><a name="detach"></a>CHandle::Detach

Chame este método para separar `CHandle` uma alça de um objeto.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Devolve a alça sendo desapegada.

### <a name="remarks"></a>Comentários

Libera a propriedade da alça.

## <a name="chandlem_h"></a><a name="m_h"></a>CHandle::m_h

A variável membro que armazena a alça.

```
HANDLE m_h;
```

## <a name="chandleoperator-"></a><a name="operator_eq"></a>CHandle::operador =

O operador de atribuição.

```
CHandle& operator=(CHandle& h) throw();
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
`CHandle`tomará posse da alça *h*.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CHandle` ao novo objeto.

### <a name="remarks"></a>Comentários

Se `CHandle` o objeto contiver atualmente uma alça, ele será fechado. O `CHandle` objeto que está sendo passado terá sua referência de alça definida como NULL. Isso garante que `CHandle` dois objetos nunca contenham a mesma alça ativa.

## <a name="chandleoperator-handle"></a><a name="operator_handle"></a>CHandle::manipulação do operador

Devolve o valor da pega armazenada.

```
operator HANDLE() const throw();
```

### <a name="remarks"></a>Comentários

Retorna o valor armazenado em [CHandle::m_h](#m_h).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
