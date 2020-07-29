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
ms.openlocfilehash: 661d3cb92b20fc929a9bae3cad7bb55740e5e096
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213002"
---
# <a name="handlet-class"></a>Classe HandleT

Representa um identificador para um objeto.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename HandleTraits>
class HandleT;
```

### <a name="parameters"></a>parâmetros

*HandleTraits*<br/>
Uma instância da estrutura [HandleTraits](handletraits-structure.md) que define características comuns de um identificador.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome     | Descrição
-------- | -----------------------------
`Traits` | Um sinônimo de `HandleTraits`.

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | --------------------------------------------------
[Identificador:: Handled](#handlet)        | Inicializa uma nova instância da classe `HandleT`.
[Identificadort:: ~ Identificadort](#tilde-handlet) | Desinicializa uma instância da `HandleT` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                         | Descrição
---------------------------- | ----------------------------------------------------------------------
[Identificadore:: Attach](#attach)   | Associa o identificador especificado ao objeto atual `HandleT` .
[Identificador:: fechar](#close)     | Fecha o objeto `HandleT` atual.
[Identificadort::D Etach](#detach)   | Desassocia o objeto atual `HandleT` de seu identificador subjacente.
[Identificador:: Get](#get)         | Obtém o valor do identificador subjacente.
[Identificadort:: IsValid](#isvalid) | Indica se o `HandleT` objeto atual representa um identificador.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                     | Descrição
---------------------------------------- | ------------------------------------
[Identificadort:: InternalClose](#internalclose) | Fecha o objeto `HandleT` atual.

### <a name="public-operators"></a>Operadores públicos

Nome                                   | Descrição
-------------------------------------- | ----------------------------------------------------------------------------------
[Identificadort:: Operator =](#operator-assign) | Move o valor do objeto especificado `HandleT` para o objeto atual `HandleT` .

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------------------------------
[Identificador:: handle_](#handle) | Contém o identificador representado pelo `HandleT` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="handlethandlet"></a><a name="tilde-handlet"></a>Identificadort:: ~ Identificadort

Desinicializa uma instância da `HandleT` classe.

```cpp
~HandleT();
```

## <a name="handletattach"></a><a name="attach"></a>Identificadore:: Attach

Associa o identificador especificado ao objeto atual `HandleT` .

```cpp
void Attach(
   typename HandleTraits::Type h
);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
Um identificador.

## <a name="handletclose"></a><a name="close"></a>Identificador:: fechar

Fecha o objeto `HandleT` atual.

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

O identificador que se baseia na atual `HandleT` é fechado e o `HandleT` é definido como o estado inválido.

Se o identificador não fechar corretamente, uma exceção será gerada no thread de chamada.

## <a name="handletdetach"></a><a name="detach"></a>Identificadort::D Etach

Desassocia o objeto atual `HandleT` de seu identificador subjacente.

```cpp
typename HandleTraits::Type Detach();
```

### <a name="return-value"></a>Valor retornado

O identificador subjacente.

### <a name="remarks"></a>Comentários

Quando essa operação for concluída, a atual `HandleT` será definida como o estado inválido.

## <a name="handletget"></a><a name="get"></a>Identificador:: Get

Obtém o valor do identificador subjacente.

```cpp
typename HandleTraits::Type Get() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador.

## <a name="handlethandle_"></a><a name="handle"></a>Identificador:: handle_

Contém o identificador representado pelo `HandleT` objeto.

```cpp
typename HandleTraits::Type handle_;
```

## <a name="handlethandlet"></a><a name="handlet"></a>Identificador:: Handled

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

### <a name="parameters"></a>parâmetros

*h*<br/>
Um identificador.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um `HandleT` objeto que não é um identificador válido para um objeto. O segundo construtor cria um novo `HandleT` objeto do parâmetro *h*.

## <a name="handletinternalclose"></a><a name="internalclose"></a>Identificadort:: InternalClose

Fecha o objeto `HandleT` atual.

```cpp
virtual bool InternalClose();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual for `HandleT` fechado com êxito; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

`InternalClose()`é **`protected`** .

## <a name="handletisvalid"></a><a name="isvalid"></a>Identificadort:: IsValid

Indica se o `HandleT` objeto atual representa um identificador.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o `HandleT` representar um identificador; caso contrário, **`false`** .

## <a name="handletoperator"></a><a name="operator-assign"></a>Identificadort:: Operator =

Move o valor do objeto especificado `HandleT` para o objeto atual `HandleT` .

```cpp
HandleT& operator=(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
Uma referência de rvalue a um identificador.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto atual `HandleT` .

### <a name="remarks"></a>Comentários

Esta operação invalida o `HandleT` objeto especificado pelo parâmetro *h*.
