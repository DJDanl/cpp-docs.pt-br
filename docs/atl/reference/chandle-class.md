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
ms.openlocfilehash: 86d2cba6c3ee2e914d96ae2a09b642d556d46027
ms.sourcegitcommit: 07b34ca1c1fecced9fadc95de15dc5fee4f31e5a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2019
ms.locfileid: "67693409"
---
# <a name="chandle-class"></a>Classe CHandle

Essa classe fornece métodos para criar e usar um objeto de identificador.

## <a name="syntax"></a>Sintaxe

```
class CHandle
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::CHandle](#chandle)|O construtor.|
|[CHandle:: ~ CHandle](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::Attach](#attach)|Chame este método para anexar o `CHandle` objeto para um identificador existente.|
|[CHandle::Close](#close)|Chame esse método para fechar um `CHandle` objeto.|
|[CHandle::Detach](#detach)|Chame esse método para desanexar um identificador de um `CHandle` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::operator identificador](#operator_handle)|Retorna o valor do identificador armazenado.|
|[CHandle::operator =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHandle::m_h](#m_h)|A variável de membro que armazena o identificador.|

## <a name="remarks"></a>Comentários

Um `CHandle` objeto pode ser usado sempre que um identificador é necessário: a principal diferença é que o `CHandle` objeto será excluído automaticamente.

> [!NOTE]
>  Algumas funções de API usará NULL como um identificador inválido ou vazio, enquanto outros usam INVALID_HANDLE_VALUE. `CHandle` usa apenas NULL e irá trata INVALID_HANDLE_VALUE como um identificador real. Se você chamar uma API que pode retornar INVALID_HANDLE_VALUE, você deve verificar esse valor antes de chamar [CHandle::Attach](#attach) ou passá-lo para o `CHandle` construtor e, em vez disso, transmita nulo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="attach"></a>  CHandle::Attach

Chame este método para anexar o `CHandle` objeto para um identificador existente.

```
void Attach(HANDLE h) throw();
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
`CHandle` assumirá a propriedade do identificador *h*.

### <a name="remarks"></a>Comentários

Atribui a `CHandle` do objeto para o *h* identificador e, em seguida, chama **h.Detach()** . Em builds de depurações, será gerado um {1&gt;ATLASSERT&lt;1 se *h* é NULL. Nenhuma outra verificação em relação à validade do identificador é feita.

##  <a name="chandle"></a>  CHandle::CHandle

O construtor.

```
CHandle() throw();
CHandle(CHandle& h) throw();
explicit CHandle(HANDLE h) throw();
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador existente ou `CHandle`.

### <a name="remarks"></a>Comentários

Cria um novo `CHandle` do objeto, opcionalmente usando um identificador existente ou `CHandle` objeto.

##  <a name="dtor"></a>  CHandle:: ~ CHandle

O destruidor.

```
~CHandle() throw();
```

### <a name="remarks"></a>Comentários

Libera os `CHandle` objeto chamando [CHandle::Close](#close).

##  <a name="close"></a>  CHandle::Close

Chame esse método para fechar um `CHandle` objeto.

```
void Close() throw();
```

### <a name="remarks"></a>Comentários

Fecha um identificador de objeto aberta. Se o identificador for NULL, o que será o caso se `Close` já foi chamado, uma {1&gt;ATLASSERT&lt;1 será gerado em compilações de depuração.

##  <a name="detach"></a>  CHandle::Detach

Chame esse método para desanexar um identificador de um `CHandle` objeto.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o identificador que está sendo desanexado.

### <a name="remarks"></a>Comentários

Libera a propriedade do identificador.

##  <a name="m_h"></a>  CHandle::m_h

A variável de membro que armazena o identificador.

```
HANDLE m_h;
```

##  <a name="operator_eq"></a>  CHandle::operator =

O operador de atribuição.

```
CHandle& operator=(CHandle& h) throw();
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
`CHandle` assumirá a propriedade do identificador *h*.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao novo `CHandle` objeto.

### <a name="remarks"></a>Comentários

Se o `CHandle` objeto contém um identificador no momento, ela será fechada. O `CHandle` do objeto que está sendo passado terá sua referência de identificador definida como NULL. Isso garante que duas `CHandle` objetos nunca conterá o mesmo identificador de Active Directory.

##  <a name="operator_handle"></a>  CHandle::operator identificador

Retorna o valor do identificador armazenado.

```
operator HANDLE() const throw();
```

### <a name="remarks"></a>Comentários

Retorna o valor armazenado no [CHandle::m_h](#m_h).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
