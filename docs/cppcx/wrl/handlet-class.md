---
title: Classe HandleT
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Attach
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Close
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Detach
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Get
- corewrappers/Microsoft::WRL::Wrappers::HandleT::handle_
- corewrappers/Microsoft::WRL::Wrappers::HandleT::HandleT
- corewrappers/Microsoft::WRL::Wrappers::HandleT::InternalClose
- corewrappers/Microsoft::WRL::Wrappers::HandleT::IsValid
- corewrappers/Microsoft::WRL::Wrappers::HandleT::operator=
- corewrappers/Microsoft::WRL::Wrappers::HandleT::~HandleT
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleT class
- Microsoft::WRL::Wrappers::HandleT::Attach method
- Microsoft::WRL::Wrappers::HandleT::Close method
- Microsoft::WRL::Wrappers::HandleT::Detach method
- Microsoft::WRL::Wrappers::HandleT::Get method
- Microsoft::WRL::Wrappers::HandleT::handle_ data member
- Microsoft::WRL::Wrappers::HandleT::HandleT, constructor
- Microsoft::WRL::Wrappers::HandleT::InternalClose method
- Microsoft::WRL::Wrappers::HandleT::IsValid method
- Microsoft::WRL::Wrappers::HandleT::operator= operator
- Microsoft::WRL::Wrappers::HandleT::~HandleT, destructor
ms.assetid: 3822b32a-a426-4d94-a54d-919d4df60ee2
ms.openlocfilehash: 6e5824da03fb85e52f413f5678ea6e0fd6c77ddd
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783948"
---
# <a name="handlet-class"></a>Classe HandleT

Representa um identificador para um objeto.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename HandleTraits>
class HandleT;
```

### <a name="parameters"></a>Parâmetros

*HandleTraits*<br/>
Uma instância das [HandleTraits](handletraits-structure.md) estrutura que define as características comuns de um identificador.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome     | Descrição
-------- | -----------------------------
`Traits` | Um sinônimo de `HandleTraits`.

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | --------------------------------------------------
[HandleT::HandleT](#handlet)        | Inicializa uma nova instância da classe `HandleT`.
[HandleT:: ~ HandleT](#tilde-handlet) | Realiza o desligamento de uma instância da `HandleT` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                         | Descrição
---------------------------- | ----------------------------------------------------------------------
[Handlet:: Attach](#attach)   | Associa o identificador especificado atual `HandleT` objeto.
[Handlet:: Close](#close)     | Fecha o objeto `HandleT` atual.
[HandleT::Detach](#detach)   | Desassocia atual `HandleT` objeto a partir de seu identificador subjacente.
[HandleT::Get](#get)         | Obtém o valor do identificador subjacente.
[HandleT::IsValid](#isvalid) | Indica se o atual `HandleT` objeto representa um identificador.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                     | Descrição
---------------------------------------- | ------------------------------------
[HandleT::InternalClose](#internalclose) | Fecha o objeto `HandleT` atual.

### <a name="public-operators"></a>Operadores públicos

Nome                                   | Descrição
-------------------------------------- | ----------------------------------------------------------------------------------
[HandleT::operator=](#operator-assign) | Move o valor de especificado `HandleT` o objeto atual `HandleT` objeto.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------------------------------
[HandleT::handle_](#handle) | Contém o identificador que é representado pela `HandleT` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-handlet"></a>HandleT:: ~ HandleT

Realiza o desligamento de uma instância da `HandleT` classe.

```cpp
~HandleT();
```

## <a name="attach"></a>Handlet:: Attach

Associa o identificador especificado atual `HandleT` objeto.

```cpp
void Attach(
   typename HandleTraits::Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador.

## <a name="close"></a>Handlet:: Close

Fecha o objeto `HandleT` atual.

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

O identificador subjacente ao atual `HandleT` for fechada e o `HandleT` é definido como o estado inválido.

Se o identificador não fechar corretamente, uma exceção é gerada no thread de chamada.

## <a name="detach"></a>HandleT::Detach

Desassocia atual `HandleT` objeto a partir de seu identificador subjacente.

```cpp
typename HandleTraits::Type Detach();
```

### <a name="return-value"></a>Valor de retorno

O identificador subjacente.

### <a name="remarks"></a>Comentários

Quando essa operação for concluída, atual `HandleT` é definido como o estado inválido.

## <a name="get"></a>HandleT::Get

Obtém o valor do identificador subjacente.

```cpp
typename HandleTraits::Type Get() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador.

## <a name="handle"></a>HandleT::handle_

Contém o identificador que é representado pela `HandleT` objeto.

```cpp
typename HandleTraits::Type handle_;
```

## <a name="handlet"></a>HandleT::HandleT

Inicializa uma nova instância da classe `HandleT`.

```cpp
explicit HandleT(
   typename HandleTraits::Type h =
      HandleTraits::GetInvalidValue()
);

HandleT(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um `HandleT` objeto que não é um identificador válido para um objeto. O segundo construtor cria um novo `HandleT` objeto de parâmetro *h*.

## <a name="internalclose"></a>HandleT::InternalClose

Fecha o objeto `HandleT` atual.

```cpp
virtual bool InternalClose();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o atual `HandleT` fechado com êxito; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

`InternalClose()` é `protected`.

## <a name="isvalid"></a>HandleT::IsValid

Indica se o atual `HandleT` objeto representa um identificador.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o `HandleT` representa um identificador; caso contrário, **falso**.

## <a name="operator-assign"></a>Handlet:: Operator =

Move o valor de especificado `HandleT` o objeto atual `HandleT` objeto.

```cpp
HandleT& operator=(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Uma referência rvalue para um identificador.

### <a name="return-value"></a>Valor de retorno

Uma referência ao atual `HandleT` objeto.

### <a name="remarks"></a>Comentários

Esta operação invalida a `HandleT` objeto especificado pelo parâmetro *h*.
