---
title: Operadores &lt;system_error&gt;
ms.date: 11/04/2016
f1_keywords:
- system_error/std::operator!=
- system_error/std::operator==
ms.assetid: c14edefb-bd8a-4e90-88d3-c59c98e6f73c
ms.openlocfilehash: 5cf6a455beb5654ef65f7411db4783a32c71d625
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246220"
---
# <a name="ltsystemerrorgt-operators"></a>Operadores &lt;system_error&gt;

## <a name="op_eq_eq"></a> operador = =

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

*À esquerda*\
O objeto a ser testado quanto à igualdade.

*Certo*\
O objeto a ser testado quanto à igualdade.

### <a name="return-value"></a>Valor de retorno

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

### <a name="remarks"></a>Comentários

Essa função retorna `left.category() == right.category() && left.value() == right.value()`.

## <a name="op_neq"></a> operador! =

Testa se o objeto à esquerda do operador é diferente do objeto à direita.

```cpp
bool operator!=(const error_code& left, const error_condition& right);
bool operator!=(const error_condition& left, const error_code& right);
bool operator!=(const error_code& left, const error_code& right);
bool operator!=(const error_condition& left, const error_condition& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
O objeto a ser testado quanto à desigualdade.

*Certo*\
O objeto a ser testado quanto à desigualdade.

### <a name="return-value"></a>Valor de retorno

**True** se o objeto passado *esquerdo* não é igual ao objeto passado *direita*; caso contrário **false**.

### <a name="remarks"></a>Comentários

Essa função retorna `!(left == right)`.

## <a name="op_lt"></a> Operador&lt;

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

*À esquerda*\
O objeto a ser comparado.

*Certo*\
O objeto a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto passado *esquerdo* é menor que o objeto passado em *direita*; Caso contrário, **falsos**.

### <a name="remarks"></a>Comentários

Essa função testa a ordem do erro.

## <a name="op_ostream"></a> operador&lt;&lt;

```cpp
template <class charT, class traits> 
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const error_code& ec);
```
