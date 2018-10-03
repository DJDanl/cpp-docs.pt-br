---
title: Funções SafeInt | Microsoft Docs
ms.custom: ''
ms.date: 09/28/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeInt functions
- SafeAdd
- SafeCast
- SafeDivide
- SafeEquals
- SafeGreaterThan
- SafeGreaterThanEquals
- SafeLessThan
- SafeLessThanEquals
- SafeModulus
- SafeMultiply
- SafeNotEquals
- SafeSubtract
dev_langs:
- C++
helpviewer_keywords:
- functions, SafeInt
- SafeAdd function
- SafeCast function
- SafeDivide function
- SafeEquals function
- SafeGreaterThan function
- SafeGreaterThanEquals function
- SafeLessThan function
- SafeLessThanEquals function
- SafeModulus function
- SafeMultiply function
- SafeNotEquals function
- SafeSubtract function
ms.assetid: fdc208e5-5d8a-41a9-8271-567fd438958d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 504cfe0780cfb0116f59ae67937ea5f0370dc8b2
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235562"
---
# <a name="safeint-functions"></a>Funções (SafeInt)

A biblioteca de SafeInt fornece várias funções que você pode usar sem criar uma instância das [classe SafeInt](../windows/safeint-class.md). Se você quiser proteger uma única operação matemática de estouro de inteiro, você pode usar essas funções. Se você quiser proteger várias operações matemáticas, você deve criar `SafeInt` objetos. É mais eficiente criar `SafeInt` objetos que usar essas funções várias vezes.

Essas funções permitem comparar ou executar operações matemáticas sobre dois tipos diferentes de parâmetros sem precisar primeiro convertê-los para o mesmo tipo.

Cada uma dessas funções tem dois tipos de modelo: `T` e `U`. Cada um desses tipos pode ser um booliano, caractere ou tipo integral. Tipos integrais podem ser com ou sem sinal e qualquer tamanho de 8 bits para 64 bits.

## <a name="in-this-section"></a>Nesta seção

Função                      | Descrição
----------------------------- | --------------------------------------------------------------
[SafeAdd](#safeadd)           | Adiciona dois números e protege contra estouro.
[SafeCast](#safecast)         | Converte um tipo de parâmetro em outro tipo.
[SafeDivide](#safedivide)     | Divide dois números e protege contra a divisão por zero.
[SafeEquals](#safeequals), [SafeGreaterThan](#safegreaterthan), [SafeGreaterThanEquals](#safegreaterthanequals), [SafeLessThan](#safelessthan), [SafeLessThanEquals](#safelessthanequals), [ SafeNotEquals](#safenotequals) | Compara dois números. Essas funções permitem que você comparar dois tipos diferentes de números sem alterar seus tipos.
[SafeModulus](#safemodulus)   | Executa a operação de módulo em dois números.
[SafeMultiply](#safemultiply) | Multiplica dois números juntos e protege contra estouro.
[SafeSubtract](#safesubtract) | Subtrai dois números e protege contra estouro.

## <a name="related-sections"></a>Seções relacionadas

Seção                                                  | Descrição
-------------------------------------------------------- | ----------------------------------------------------
[SafeInt](../windows/safeint-class.md)                   | O `SafeInt` classe.
[SafeIntException](../windows/safeintexception-class.md) | A classe de exceção específica para a biblioteca de SafeInt.

## <a name="safeadd"></a>SafeAdd

Adiciona dois números de uma maneira que proteja contra estouro.

```cpp
template<typename T, typename U>
inline bool SafeAdd (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a adicionar. Isso deve ser do tipo T.

*u*<br/>
[in] O segundo número a adicionar. Isso deve ser do tipo u

*resultado*<br/>
[out] O parâmetro onde `SafeAdd` armazena o resultado.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.

## <a name="safecast"></a>SafeCast

Converte um tipo de número em outro tipo.

```cpp
template<typename T, typename U>
inline bool SafeCast (
   const T From,
   U& To
);
```

### <a name="parameters"></a>Parâmetros

*From*<br/>
[in] O número de origem a ser convertido. Isso deve ser do tipo `T`.

*To*<br/>
[out] Uma referência para o novo tipo de número. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.

## <a name="safedivide"></a>SafeDivide

Divide dois números de uma maneira que protege contra a divisão por zero.

```cpp
template<typename T, typename U>
inline bool SafeDivide (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O divisor. Isso deve ser do tipo T.

*u*<br/>
[in] O dividendo. Isso deve ser do tipo u

*resultado*<br/>
[out] O parâmetro onde `SafeDivide` armazena o resultado.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.

## <a name="safeequals"></a>SafeEquals

Compara dois números para determinar se eles são iguais.

```cpp
template<typename T, typename U>
inline bool SafeEquals (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo T.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo u

### <a name="return-value"></a>Valor de retorno

`true` Se *t* e *u* forem iguais; caso contrário `false`.

### <a name="remarks"></a>Comentários

O método aprimora `==` porque `SafeEquals` permite comparar dois tipos diferentes de números.

## <a name="safegreaterthan"></a>SafeGreaterThan

Compara dois números.

```cpp
template<typename T, typename U>
inline bool SafeGreaterThan (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se *t* é maior que *u*; caso contrário `false`.

### <a name="remarks"></a>Comentários

`SafeGreaterThan` estende o operador de comparação regular, permitindo que você comparar dois tipos diferentes de números.

## <a name="safegreaterthanequals"></a>SafeGreaterThanEquals

Compara dois números.

```cpp
template <typename T, typename U>
inline bool SafeGreaterThanEquals (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se *t* é maior que ou igual a *u*; caso contrário `false`.

### <a name="remarks"></a>Comentários

`SafeGreaterThanEquals` aprimora o operador de comparação padrão porque ela permite que você compare dois tipos diferentes de números.

## <a name="safelessthan"></a>SafeLessThan

Determina se um número é menor que outro.

```cpp
template<typename T, typename U>
inline bool SafeLessThan (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se *t* é menor que *u*; caso contrário `false`.

### <a name="remarks"></a>Comentários

Esse método melhora o operador de comparação padrão, pois `SafeLessThan` permite comparar dois tipos diferentes de número.

## <a name="safelessthanequals"></a>SafeLessThanEquals

Compara dois números.

```cpp
template <typename T, typename U>
inline bool SafeLessThanEquals (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se *t* é menor que ou igual a *u*; caso contrário `false`.

### <a name="remarks"></a>Comentários

`SafeLessThanEquals` estende o operador de comparação regular, permitindo que você comparar dois tipos diferentes de números.

## <a name="safemodulus"></a>SafeModulus

Executa a operação de módulo em dois números.

```cpp
template<typename T, typename U>
inline bool SafeModulus (
   const T t,
   const U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O divisor. Isso deve ser do tipo `T`.

*u*<br/>
[in] O dividendo. Isso deve ser do tipo `U`.

*resultado*<br/>
[out] O parâmetro onde `SafeModulus` armazena o resultado.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.

## <a name="safemultiply"></a>SafeMultiply

Multiplica dois números juntos de forma que protege contra estouro.

```cpp
template<typename T, typename U>
inline bool SafeMultiply (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a multiplicar. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a multiplicar. Isso deve ser do tipo `U`.

*resultado*<br/>
[out] O parâmetro onde `SafeMultiply` armazena o resultado.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.

## <a name="safenotequals"></a>SafeNotEquals

Determina se dois números não são iguais.

```cpp
template<typename T, typename U>
inline bool SafeNotEquals (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo `U`.

### <a name="return-value"></a>Valor de retorno

`true` Se *t* e *u* não forem iguais; caso contrário `false`.

### <a name="remarks"></a>Comentários

O método aprimora `!=` porque `SafeNotEquals` permite comparar dois tipos diferentes de números.

## <a name="safesubtract"></a>SafeSubtract

Subtrai dois números de uma maneira que proteja contra estouro.

```cpp
template<typename T, typename U>
inline bool SafeSubtract (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número na subtração. Isso deve ser do tipo `T`.

*u*<br/>
[in] O número para subtrair de *t*. Isso deve ser do tipo `U`.

*resultado*<br/>
[out] O parâmetro onde `SafeSubtract` armazena o resultado.

### <a name="return-value"></a>Valor de retorno

`true` Se nenhum erro ocorrer; `false` se ocorrer um erro.
