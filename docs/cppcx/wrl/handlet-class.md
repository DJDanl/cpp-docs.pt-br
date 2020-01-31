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
ms.openlocfilehash: f66fbe23c305be15e09928242175dfa7ce8c141b
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821812"
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
Uma instância da estrutura [HandleTraits](handletraits-structure.md) que define características comuns de um identificador.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

Name     | Descrição
-------- | -----------------------------
`Traits` | Um sinônimo de `HandleTraits`.

### <a name="public-constructors"></a>Construtores Públicos

Name                                | Descrição
----------------------------------- | --------------------------------------------------
[HandleT::HandleT](#handlet)        | Inicializa uma nova instância da classe `HandleT` .
[Identificadort:: ~ Identificadort](#tilde-handlet) | Desinicializa uma instância da classe `HandleT`.

### <a name="public-methods"></a>Métodos Públicos

Name                         | Descrição
---------------------------- | ----------------------------------------------------------------------
[Identificadore:: Attach](#attach)   | Associa o identificador especificado ao objeto de `HandleT` atual.
[Identificador:: fechar](#close)     | Fecha o objeto `HandleT` atual.
[HandleT::Detach](#detach)   | Desassocia o objeto `HandleT` atual de seu identificador subjacente.
[Identificador:: Get](#get)         | Obtém o valor do identificador subjacente.
[HandleT::IsValid](#isvalid) | Indica se o objeto de `HandleT` atual representa um identificador.

### <a name="protected-methods"></a>Métodos protegidos

Name                                     | Descrição
---------------------------------------- | ------------------------------------
[Identificadort:: InternalClose](#internalclose) | Fecha o objeto `HandleT` atual.

### <a name="public-operators"></a>Operadores públicos

Name                                   | Descrição
-------------------------------------- | ----------------------------------------------------------------------------------
[HandleT::operator=](#operator-assign) | Move o valor do objeto `HandleT` especificado para o objeto `HandleT` atual.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Name                        | Descrição
--------------------------- | ----------------------------------------------------------------
[HandleT::handle_](#handle) | Contém o identificador representado pelo objeto `HandleT`.

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`HandleT`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="tilde-handlet"></a>Identificadort:: ~ Identificadort

Desinicializa uma instância da classe `HandleT`.

```cpp
~HandleT();
```

## <a name="attach"></a>Identificadore:: Attach

Associa o identificador especificado ao objeto de `HandleT` atual.

```cpp
void Attach(
   typename HandleTraits::Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador.

## <a name="close"></a>Identificador:: fechar

Fecha o objeto `HandleT` atual.

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

O identificador que se baseia na `HandleT` atual está fechado e o `HandleT` está definido como o estado inválido.

Se o identificador não fechar corretamente, uma exceção será gerada no thread de chamada.

## <a name="detach"></a>HandleT::Detach

Desassocia o objeto `HandleT` atual de seu identificador subjacente.

```cpp
typename HandleTraits::Type Detach();
```

### <a name="return-value"></a>Valor de retorno

O identificador subjacente.

### <a name="remarks"></a>Comentários

Quando essa operação for concluída, a `HandleT` atual será definida como o estado inválido.

## <a name="get"></a>Identificador:: Get

Obtém o valor do identificador subjacente.

```cpp
typename HandleTraits::Type Get() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador.

## <a name="handle"></a>Identificador:: handle_

Contém o identificador representado pelo objeto `HandleT`.

```cpp
typename HandleTraits::Type handle_;
```

## <a name="handlet"></a>HandleT::HandleT

Inicializa uma nova instância da classe `HandleT` .

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

O primeiro construtor inicializa um objeto `HandleT` que não é um identificador válido para um objeto. O segundo construtor cria um novo objeto `HandleT` do parâmetro *h*.

## <a name="internalclose"></a>HandleT::InternalClose

Fecha o objeto `HandleT` atual.

```cpp
virtual bool InternalClose();
```

### <a name="return-value"></a>Valor de retorno

**true** se o `HandleT` atual for fechado com êxito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

`InternalClose()` é `protected`.

## <a name="isvalid"></a>HandleT::IsValid

Indica se o objeto de `HandleT` atual representa um identificador.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o `HandleT` representar um identificador; caso contrário, **false**.

## <a name="operator-assign"></a>Identificadort:: Operator =

Move o valor do objeto `HandleT` especificado para o objeto `HandleT` atual.

```cpp
HandleT& operator=(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Uma referência de rvalue a um identificador.

### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto de `HandleT` atual.

### <a name="remarks"></a>Comentários

Esta operação invalida o objeto `HandleT` especificado pelo parâmetro *h*.
