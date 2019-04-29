---
title: '&lt;chrono&gt;'
ms.date: 11/04/2016
f1_keywords:
- chrono/std::chrono::nanoseconds
- chrono/std::chrono::minutes
- chrono/std::chrono::seconds
- <chrono>
- chrono/std::chrono::hours
- chrono/std::chrono::milliseconds
- chrono/std::chrono::microseconds
ms.assetid: 844de749-f306-482e-89bc-6f53c99c8324
ms.openlocfilehash: 1fcf87d84b2c99b89217b7f2e0fc7fecd55fff02
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62279093"
---
# <a name="ltchronogt"></a>&lt;chrono&gt;

Inclua o cabeçalho padrão \<chrono> para definir classes e funções que representam e manipulam durações de tempo e instantes de tempo.

A partir do Visual Studio 2015, a implementação de `steady_clock` mudou para atender aos requisitos do padrão C++ de estabilidade e monotonicidade. `steady_clock` agora é baseado em QueryPerformanceCounter() e `high_resolution_clock` agora é uma typedef para `steady_clock`. Como resultado, no Visual C++ `steady_clock::time_point` agora é uma typedef para `chrono::time_point<steady_clock>`; no entanto, esse não é necessariamente o caso para outras implementações.

## <a name="syntax"></a>Sintaxe

```cpp
#include <chrono>
```

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe duration](../standard-library/duration-class.md)|Descreve um tipo que contém um intervalo de tempo.|
|[Classe time_point](../standard-library/time-point-class.md)|Descreve um tipo que representa um ponto no tempo.|

### <a name="structs"></a>Structs

|Nome|Descrição|
|----------|-----------------|
|[Estrutura common_type](../standard-library/common-type-structure.md)|Descreve especializações da classe de modelo [common_type](../standard-library/common-type-class.md) para instanciações de `duration` e `time_point`.|
|[Estrutura duration_values](../standard-library/duration-values-structure.md)|Fornece valores específicos para o parâmetro de modelo `duration` `Rep`.|
|[Struct steady_clock](../standard-library/steady-clock-struct.md)|Representa um relógio `steady`.|
|[Estrutura system_clock](../standard-library/system-clock-structure.md)|Representa um *tipo de relógio* baseado no relógio em tempo real do sistema.|
|[Estrutura treat_as_floating_point](../standard-library/treat-as-floating-point-structure.md)|Especifica se um tipo pode ser tratado como um tipo de ponto flutuante.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[duration_cast](../standard-library/chrono-functions.md#duration_cast)|Converte um objeto `duration` em um tipo especificado.|
|[time_point_cast](../standard-library/chrono-functions.md#time_point_cast)|Converte um objeto `time_point` em um tipo especificado.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|----------|-----------------|
|[operator-](../standard-library/chrono-operators.md#operator-)|Operador de subtração ou negação de objetos `duration` e `time_point`.|
|[operator!=](../standard-library/chrono-operators.md#op_neq)|Operador de desigualdade usado com objetos `duration` ou `time_point`.|
|[módulo do operador](../standard-library/chrono-operators.md#op_modulo)|Operador para operações de módulo em objetos `duration`.|
|[operator*](../standard-library/chrono-operators.md#op_star)|Operador de multiplicação para objetos `duration`.|
|[operator/](../standard-library/chrono-operators.md#op_div)|Operador de divisão para objetos `duration`.|
|[operator+](../standard-library/chrono-operators.md#op_add)|Adiciona objetos `duration` e `time_point`.|
|[operator&lt;](../standard-library/chrono-operators.md#op_lt)|Determina se um objeto `duration` ou `time_point` é menor que outro objeto `duration` ou `time_point`.|
|[operator&lt;=](../standard-library/chrono-operators.md#op_lt_eq)|Determina se um objeto `duration` ou `time_point` é menor ou igual a outro objeto `duration` ou `time_point`.|
|[operator==](../standard-library/chrono-operators.md#op_eq_eq)|Determina se dois objetos `duration` representam intervalos de tempo que têm o mesmo tamanho ou se dois objetos `time_point` representam o mesmo ponto no tempo.|
|[operator&gt;](../standard-library/chrono-operators.md#op_gt)|Determina se um objeto `duration` ou `time_point` é maior que outro objeto `duration` ou `time_point`.|
|[operator&gt;=](../standard-library/chrono-operators.md#op_gt_eq)|Determina se um objeto `duration` ou `time_point` é maior ou igual a outro objeto `duration` ou `time_point`.|

### <a name="predefined-duration-types"></a>Tipos predefinidos de duração

Para obter mais informações sobre tipos de índice usados nas seguintes typedefs, consulte [\<índice>](../standard-library/ratio.md).

|DefTipo|Descrição|
|-------------|-----------------|
|`typedef duration<long long, nano> nanoseconds;`|O sinônimo de um tipo `duration` que tem um período de escala de um nanossegundo.|
|`typedef duration<long long, micro> microseconds;`|O sinônimo de um tipo `duration` que tem um período de escala de um microssegundo.|
|`typedef duration<long long, milli> milliseconds;`|O sinônimo de um tipo `duration` que tem um período de escala de um milissegundo.|
|`typedef duration<long long> seconds;`|O sinônimo de um tipo `duration` que tem um período de escala de um segundo.|
|`typedef duration<int, ratio<60> > minutes;`|O sinônimo de um tipo `duration` que tem um período de escala de um minuto.|
|`typedef duration<int, ratio<3600> > hours;`|O sinônimo de um tipo `duration` que tem um período de escala de uma hora.|

### <a name="literals"></a>Literais

**(C++11)**  As \<chrono > cabeçalho define os seguintes [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md) que você pode usar para maior conveniência, tipo de segurança e facilidade de manutenção do seu código. Esses literais são definidos no namespace embutido `literals::chrono_literals` e estão no escopo quando std::chrono está no escopo.

|Literal|Descrição|
|-------------|-----------------|
|chrono::hours operator "" h(unsigned long long Val)|Especifica horas como um valor integral.|
|chrono::duration\<double, ratio\<3600> > operator "" h(long double Val)|Especifica horas como um valor de ponto flutuante.|
|chrono::minutes (operator "" min)(unsigned long long Val)|Especifica minutos como um valor integral.|
|chrono::duration\<double, ratio\<60> > (operator "" min)( long double Val)|Especifica minutos como um valor de ponto flutuante.|
|chrono::seconds operator "" s(unsigned long long Val)|Especifica minutos como um valor integral.|
|chrono::duration\<double> operator "" s(long double Val)|Especifica segundos como um valor de ponto flutuante.|
|chrono::milliseconds operator "" ms(unsigned long long Val)|Especifica milissegundos como um valor integral.|
|chrono::duration\<double, milli> operator "" ms(long double Val)|Especifica milissegundos como um valor de ponto flutuante.|
|chrono::microseconds operator "" us(unsigned long long Val)|Especifica microssegundos como um valor integral.|
|chrono::duration\<double, micro> operator "" us(long double Val)|Especifica microssegundos como um valor de ponto flutuante.|
|chrono::nanoseconds operator "" ns(unsigned long long Val)|Especifica nanossegundos como um valor integral.|
|chrono::duration\<double, nano> operator "" ns(long double Val)|Especifica nanossegundos como um valor de ponto flutuante.|
|||

Os exemplos a seguir mostram como usar os literais chrono.

```cpp
constexpr auto day = 24h;
constexpr auto week = 24h* 7;
constexpr auto my_duration_unit = 108ms;
```

## <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
