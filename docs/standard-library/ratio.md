---
title: '&lt;ratio&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ratio/std::mega
- ratio/std::peta
- ratio/std::ratio_greater
- ratio/std::micro
- ratio/std::ratio_add
- ratio/std::ratio_not_equal
- ratio/std::hecto
- ratio/std::nano
- ratio/std::ratio_less_equal
- ratio/std::ratio_less
- ratio/std::centi
- ratio/std::ratio_greater_equal
- ratio/std::ratio_subtract
- <ratio>
- ratio/std::atto
- ratio/std::tera
- ratio/std::milli
- ratio/std::ratio_multiply
- ratio/std::kilo
- ratio/std::ratio_divide
- ratio/std::giga
- ratio/std::pico
- ratio/std::femto
- ratio/std::ratio_equal
- ratio/std::ratio
- ratio/std::exa
- ratio/std::deci
- ratio/std::deca
dev_langs:
- C++
ms.assetid: 8543e912-2d84-45ea-b3c0-bd7bfacee405
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 39fdef1976a506c36a553d575c83462e7c6e9ee0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ltratiogt"></a>&lt;ratio&gt;
Inclua o cabeçalho padrão \<ratio> para definir as constantes e os modelos que são usados para armazenar e manipular números racionais no tempo de compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
#include <ratio>  
```  
  
### <a name="ratio-structure"></a>Estrutura da proporção  

```
struct ratio
{
    static constexpr intmax_t num;
    static constexpr intmax_t den;
    typedef ratio<num, den>  type;
};
```  
 A [Estrutura ratio](http://msdn.microsoft.com/en-us/3f7961f4-802b-4251-b3c3-090ef91c0dba) define as constantes estáticas `num` e `den` de maneira que `num` / `den` == N / D e `num` e `den` não têm nenhum fator comum. `num` / `den` é o `value` que é representado pela classe de modelo. Portanto, `type` designa a instanciação `ratio<N0, D0>` para a qual `num` == N0 e `den` == D0.  
  
### <a name="specializations"></a>Especializações  
 \<ratio> também define especializações de `ratio` que têm o seguinte formato.  
  
 `template <class R1, class R2> struct ratio_specialization`  
  
 Cada especialização adota dois parâmetros de modelo que também devem ser especializações de `ratio`. O valor de `type` é determinado por uma operação lógica associada.  
  
|Nome|Valor `type`|  
|----------|------------------|  
|`ratio_add`|`R1 + R2`|  
|`ratio_divide`|`R1 / R2`|  
|`ratio_equal`|`R1 == R2`|  
|`ratio_greater`|`R1 > R2`|  
|`ratio_greater_equal`|`R1 >= R2`|  
|`ratio_less`|`R1 < R2`|  
|`ratio_less_equal`|`R1 <= R2`|  
|`ratio_multiply`|`R1 * R2`|  
|`ratio_not_equal`|`!(R1 == R2)`|  
|`ratio_subtract`|`R1 - R2`|  
  
### <a name="typedefs"></a>typedefs  
  
```
typedef ratio<1,  1000000000000000000> atto;
typedef ratio<1,     1000000000000000> femto;
typedef ratio<1,        1000000000000> pico;
typedef ratio<1, 1000000000> nano;
typedef ratio<1, 1000000> micro;
typedef ratio<1, 1000> milli;
typedef ratio<1,  100> centi;
typedef ratio<1,   10> deci;
typedef ratio<10, 1> deca;
typedef ratio<100, 1> hecto;
typedef ratio<1000, 1> kilo;
typedef ratio<1000000, 1> mega;
typedef ratio<1000000000, 1> giga;
typedef ratio<1000000000000, 1> tera;
typedef ratio<1000000000000000, 1> peta;
typedef ratio<1000000000000000000, 1> exa;
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)




