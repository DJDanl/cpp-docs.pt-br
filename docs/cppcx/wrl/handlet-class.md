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
ms.openlocfilehash: bde7d7f1bd6730d96cb0f7a0d191a32eb8ed3e8c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371459"
---
# <a name="handlet-class"></a>Classe HandleT

Representa uma alça para um objeto.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename HandleTraits>
class HandleT;
```

### <a name="parameters"></a>Parâmetros

*HandleTraits*<br/>
Um exemplo da estrutura [HandleTraits](handletraits-structure.md) que define características comuns de uma alça.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome     | Descrição
-------- | -----------------------------
`Traits` | Um sinônimo de `HandleTraits`.

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | --------------------------------------------------
[HandleT::HandleT](#handlet)        | Inicia uma nova instância da classe `HandleT`.
[HandleT::~Handlet](#tilde-handlet) | Desinicializa uma instância `HandleT` da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                         | Descrição
---------------------------- | ----------------------------------------------------------------------
[HandleT::Anexar](#attach)   | Associa a alça especificada `HandleT` com o objeto atual.
[HandleT::Fechar](#close)     | Fecha o objeto `HandleT` atual.
[HandleT::Detach](#detach)   | Desassocia o `HandleT` objeto atual de sua alça subjacente.
[handlet::Get](#get)         | Obtém o valor da alça subjacente.
[handlet::isvalid](#isvalid) | Indica se `HandleT` o objeto atual representa uma alça.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                     | Descrição
---------------------------------------- | ------------------------------------
[handlet::InternalClose](#internalclose) | Fecha o objeto `HandleT` atual.

### <a name="public-operators"></a>Operadores públicos

Nome                                   | Descrição
-------------------------------------- | ----------------------------------------------------------------------------------
[HandleT::operador=](#operator-assign) | Move o valor do `HandleT` objeto especificado para o objeto atual. `HandleT`

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------------------------------
[handleT::handle_](#handle) | Contém a alça representada `HandleT` pelo objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="handlethandlet"></a><a name="tilde-handlet"></a>HandleT::~Handlet

Desinicializa uma instância `HandleT` da classe.

```cpp
~HandleT();
```

## <a name="handletattach"></a><a name="attach"></a>HandleT::Anexar

Associa a alça especificada `HandleT` com o objeto atual.

```cpp
void Attach(
   typename HandleTraits::Type h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Um identificador.

## <a name="handletclose"></a><a name="close"></a>HandleT::Fechar

Fecha o objeto `HandleT` atual.

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

A alça que sustenta `HandleT` a corrente `HandleT` está fechada, e a está definida como estado inválido.

Se a alça não fechar corretamente, uma exceção será levantada na linha de chamada.

## <a name="handletdetach"></a><a name="detach"></a>HandleT::Detach

Desassocia o `HandleT` objeto atual de sua alça subjacente.

```cpp
typename HandleTraits::Type Detach();
```

### <a name="return-value"></a>Valor retornado

A alça subjacente.

### <a name="remarks"></a>Comentários

Quando esta operação é `HandleT` concluída, a corrente é definida para o estado inválido.

## <a name="handletget"></a><a name="get"></a>handlet::Get

Obtém o valor da alça subjacente.

```cpp
typename HandleTraits::Type Get() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador.

## <a name="handlethandle_"></a><a name="handle"></a>handleT::handle_

Contém a alça representada `HandleT` pelo objeto.

```cpp
typename HandleTraits::Type handle_;
```

## <a name="handlethandlet"></a><a name="handlet"></a>HandleT::HandleT

Inicia uma nova instância da classe `HandleT`.

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

*H*<br/>
Um identificador.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa `HandleT` um objeto que não é uma alça válida para um objeto. O segundo construtor cria `HandleT` um novo objeto a partir do parâmetro *h*.

## <a name="handletinternalclose"></a><a name="internalclose"></a>handlet::InternalClose

Fecha o objeto `HandleT` atual.

```cpp
virtual bool InternalClose();
```

### <a name="return-value"></a>Valor retornado

**verdade** se `HandleT` a corrente fechou com sucesso; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

`InternalClose()` é `protected`.

## <a name="handletisvalid"></a><a name="isvalid"></a>handlet::isvalid

Indica se `HandleT` o objeto atual representa uma alça.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor retornado

**verdade** se `HandleT` o representa uma alça; caso contrário, **falso**.

## <a name="handletoperator"></a><a name="operator-assign"></a>HandleT::operador=

Move o valor do `HandleT` objeto especificado para o objeto atual. `HandleT`

```cpp
HandleT& operator=(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Uma referência de valor a uma alça.

### <a name="return-value"></a>Valor retornado

Uma referência ao `HandleT` objeto atual.

### <a name="remarks"></a>Comentários

Esta operação invalida o `HandleT` objeto especificado pelo parâmetro *h*.
