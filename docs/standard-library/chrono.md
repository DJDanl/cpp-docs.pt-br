---
title: '&lt;chrono&gt;'
ms.date: 05/07/2019
f1_keywords:
- chrono/std::chrono::nanoseconds
- chrono/std::chrono::minutes
- chrono/std::chrono::seconds
- <chrono>
- chrono/std::chrono::hours
- chrono/std::chrono::milliseconds
- chrono/std::chrono::microseconds
ms.assetid: 844de749-f306-482e-89bc-6f53c99c8324
ms.openlocfilehash: e27ff146c75da6e90e6336106beba714dbe7c8a8
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689875"
---
# <a name="ltchronogt"></a>&lt;chrono&gt;

Inclua o cabeçalho padrão \<chrono> para definir classes e funções que representam e manipulam durações de tempo e instantes de tempo.

A partir do Visual Studio 2015, a implementação do `steady_clock` foi alterada para atender C++ aos requisitos padrão de enchente e monotônico. `steady_clock` agora é baseado em QueryPerformanceCounter() e `high_resolution_clock` agora é uma typedef para `steady_clock`. Como resultado, no Microsoft C++ Compiler `steady_clock::time_point` agora é um typedef para `chrono::time_point<steady_clock>`; no entanto, essa regra não é necessariamente o caso para outras implementações.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<chrono >

**Namespace:** std

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe duration](../standard-library/duration-class.md)|Descreve um tipo que contém um intervalo de tempo.|
|[Classe time_point](../standard-library/time-point-class.md)|Descreve um tipo que representa um ponto no tempo.|

### <a name="structs"></a>Structs

|||
|-|-|
|[Estrutura common_type](../standard-library/common-type-structure.md)|Descreve as especializações do modelo de classe [common_type](../standard-library/common-type-class.md) para instanciações de `duration` e `time_point`.|
|[Estrutura duration_values](../standard-library/duration-values-structure.md)|Fornece valores específicos para o parâmetro de modelo `duration` `Rep`.|
|[estrutura high_resolution_clock](../standard-library/high-resolution-clock-struct.md)||
|[Struct steady_clock](../standard-library/steady-clock-struct.md)|Representa um relógio `steady`.|
|[Estrutura system_clock](../standard-library/system-clock-structure.md)|Representa um *tipo de relógio* baseado no relógio em tempo real do sistema.|
|[Estrutura treat_as_floating_point](../standard-library/treat-as-floating-point-structure.md)|Especifica se um tipo pode ser tratado como um tipo de ponto flutuante.|

### <a name="functions"></a>Funções

|||
|-|-|
|[duration_cast](../standard-library/chrono-functions.md#duration_cast)|Converte um objeto `duration` em um tipo especificado.|
|[time_point_cast](../standard-library/chrono-functions.md#time_point_cast)|Converte um objeto `time_point` em um tipo especificado.|

### <a name="operators"></a>Operadores

|||
|-|-|
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

### <a name="typedefs-predefined-duration-types"></a>TYPEDEFs (tipos de duração predefinidos)

Para obter mais informações sobre tipos de índice usados nas seguintes typedefs, consulte [\<índice>](../standard-library/ratio.md).

|||
|-|-|
|`typedef duration<long long, nano> nanoseconds;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 nanossegundo.|
|`typedef duration<long long, micro> microseconds;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 microssegundo.|
|`typedef duration<long long, milli> milliseconds;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 milissegundo.|
|`typedef duration<long long> seconds;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 segundo.|
|`typedef duration<int, ratio<60> > minutes;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 minuto.|
|`typedef duration<int, ratio<3600> > hours;`|Sinônimo de um tipo de `duration` que tem um período de tique de 1 hora.|

### <a name="literals"></a>Literais

**(C++ 11)** O cabeçalho de > de \<chrono define os seguintes [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md) que você pode usar para maior conveniência, segurança de tipo e manutenção do seu código. Esses literais são definidos no namespace embutido `literals::chrono_literals` e estão no escopo quando std::chrono está no escopo.

|||
|-|-|
|operador de horas "" h (valor longo longo não atribuído)|Especifica horas como um valor integral.|
|duração \<double, ratio \<3600 > operador de > "" h (valor duplo longo)|Especifica horas como um valor de ponto flutuante.|
|minutos (operador "" min) (valor longo longo não atribuído)|Especifica minutos como um valor integral.|
|duração \<double, taxa \<60 > > (operador "" min) (valor duplo longo)|Especifica minutos como um valor de ponto flutuante.|
|operador de segundos "" s (valor longo longo sem sinal)|Especifica minutos como um valor integral.|
|Duration \<double operador de > "" s (valor duplo longo)|Especifica segundos como um valor de ponto flutuante.|
|operador de milissegundos "" MS (valor longo longo sem sinal)|Especifica milissegundos como um valor integral.|
|Duration \<double, operador de > Mili "" MS (valor duplo longo)|Especifica milissegundos como um valor de ponto flutuante.|
|operador de microssegundos "" US (valor longo longo sem sinal)|Especifica microssegundos como um valor integral.|
|duração \<double, operador de micro > "" US (valor duplo longo)|Especifica microssegundos como um valor de ponto flutuante.|
|operador de nanossegundos "" NS (valor longo longo sem sinal)|Especifica nanossegundos como um valor integral.|
|duração \<double, operador do nano > "" NS (valor duplo longo)|Especifica nanossegundos como um valor de ponto flutuante.|

Os exemplos a seguir mostram como usar os literais chrono.

```cpp
constexpr auto day = 24h;
constexpr auto week = 24h* 7;
constexpr auto my_duration_unit = 108ms;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
