---
title: Operadores &lt;system_error&gt;
ms.date: 11/04/2016
f1_keywords:
- system_error/std::operator!=
- system_error/std::operator==
ms.assetid: c14edefb-bd8a-4e90-88d3-c59c98e6f73c
ms.openlocfilehash: 5cf6a455beb5654ef65f7411db4783a32c71d625
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78876245"
---
# <a name="ltsystem_errorgt-operators"></a>Operadores &lt;system_error&gt;

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto à esquerda do operador é igual ao objeto à direita.

```cpp
bool operator==(const error_code& left,
    const error_condition& right);

bool operator==(const error_condition& left,
    const error_code& right);

bool operator==(const error_condition& left,
    const error_condition& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O objeto a ser testado quanto à igualdade.

\ *à direita*
O objeto a ser testado quanto à igualdade.

### <a name="return-value"></a>Valor retornado

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

### <a name="remarks"></a>Comentários

Essa função retorna `left.category() == right.category() && left.value() == right.value()`.

## <a name="op_neq"></a>operador! =

Testa se o objeto à esquerda do operador é diferente do objeto à direita.

```cpp
bool operator!=(const error_code& left, const error_condition& right);
bool operator!=(const error_condition& left, const error_code& right);
bool operator!=(const error_code& left, const error_code& right);
bool operator!=(const error_condition& left, const error_condition& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O objeto a ser testado quanto à desigualdade.

\ *à direita*
O objeto a ser testado quanto à desigualdade.

### <a name="return-value"></a>Valor retornado

**true** se o objeto passado para a *esquerda* não for igual ao objeto passado para a *direita*; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Essa função retorna `!(left == right)`.

## <a name="op_lt">Operador </a>&lt;

Testa se um objeto é menor que o objeto passado para comparação.

```cpp
template <class _Enum>
inline bool operator<(
    _Enum left,
    typename enable_if<is_error_code_enum<_Enum>::value,
    const error_code&>::type right);

template <class _Enum>
inline bool operator<(
    typename enable_if<is_error_code_enum<_Enum>::value,
    const error_code&>::type left, _Enum right);

template <class _Enum>
inline bool operator<(
    _Enum left,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    const error_condition&>::type right);

template <class _Enum>
inline bool operator<(
    typename enable_if<is_error_condition_enum<_Enum>::value,
    const error_condition&>::type left, _Enum right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O objeto a ser comparado.

\ *à direita*
O objeto a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto passado para a *esquerda* for menor que o objeto passado para a *direita*; Caso contrário, **false**.

### <a name="remarks"></a>Comentários

Essa função testa a ordem do erro.

## <a name="op_ostream"></a>&lt; de&lt;do operador

```cpp
template <class charT, class traits> 
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const error_code& ec);
```
