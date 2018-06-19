---
title: chrono literals | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
ms.assetid: 1a9e23b1-256f-4570-8226-5fa7364fb032
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 022f2bb5355b59ca9ee614c79fee310526e094d8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33840925"
---
# <a name="chrono-literals"></a>literais chrono

(C++14) O cabeçalho \<chrono> define 12 [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md) para facilitar o uso de literais que representam horas, minutos, segundos, milissegundos, microssegundos e nanossegundos. Cada literal definido pelo usuário tem um integral e uma sobrecarga de ponto flutuante. Os literais são definidos no namespace embutido literals::chrono_literals que é colocado no escopo automaticamente quando std::chrono está no escopo.

## <a name="syntax"></a>Sintaxe

```cpp
inline namespace literals {
    inline namespace chrono_literals {
 // return integral hours
    constexpr chrono::hours operator"" h(unsigned long long Val);

// return floating-point hours
    constexpr chrono::duration<double, ratio<3600>> operator"" h(long double Val);

// return integral minutes
    constexpr chrono::minutes(operator"" min)(unsigned long long Val);

// return floating-point minutes
    constexpr chrono::duration<double, ratio<60>>(operator"" min)(long double Val);

// return integral seconds
    constexpr chrono::seconds operator"" s(unsigned long long Val);

// return floating-point seconds
    constexpr chrono::duration<double> operator"" s(long double Val);

// return integral milliseconds
    constexpr chrono::milliseconds operator"" ms(unsigned long long Val);

// return floating-point milliseconds
    constexpr chrono::duration<double, milli> operator"" ms(long double Val);

// return integral microseconds
    constexpr chrono::microseconds operator"" us(unsigned long long Val);

// return floating-point microseconds
    inline constexpr chrono::duration<double, micro> operator"" us(long double Val);

// return integral nanoseconds
    inline constexpr chrono::nanoseconds operator"" ns(unsigned long long Val);

// return floating-point nanoseconds
    constexpr chrono::duration<double, nano> operator"" ns(long double Val);

}// inline namespace chrono_literals
}// inline namespace literals
```

## <a name="return-value"></a>Valor de retorno

Os literais que pegam um argumento `long long` retornam um valor ou o tipo correspondente. Os literais que pegam um argumento de ponto flutuante retornam uma [duração](../standard-library/duration-class.md).

## <a name="example"></a>Exemplo

Os exemplos a seguir mostram como usar os literais chrono.

```cpp
constexpr auto day = 24h;
constexpr auto week = 24h* 7;
constexpr auto my_duration_unit = 108ms;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<chrono>

**Namespace**: std::literals::chrono_literals

## <a name="see-also"></a>Consulte também

[\<chrono>](../standard-library/chrono.md)<br/>
