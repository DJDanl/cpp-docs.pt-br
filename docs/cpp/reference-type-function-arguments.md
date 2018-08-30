---
title: Argumentos de função do tipo de referência | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- arguments [C++], function
- functions [C++], paramters
- function parameters [C++], reference-type
- function arguments [C++], reference-type
- passing parameters [C++], reference-type arguments
ms.assetid: 0a70e831-9e76-46c0-821d-aeba13d73cc0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 042f609988a87beb8a990405e0426405bc874128
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209745"
---
# <a name="reference-type-function-arguments"></a>Argumentos de funções de tipo de referência

É geralmente mais eficiente passar referências, em vez de objetos grandes, para funções. Isso permite que o compilador passe o endereço do objeto enquanto mantém a sintaxe que seria usada para acessar o objeto. Considere o seguinte exemplo que usa a estrutura `Date`:

```cpp
// reference_type_function_arguments.cpp
#include <iostream>

struct Date
{
    short Month;
    short Day;
    short Year;
};

// Create a date of the form DDDYYYY (day of year, year)
// from a Date.
long DateOfYear( Date& date )
{
    static int cDaysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    long dateOfYear = 0;

    // Add in days for months already elapsed.
    for ( int i = 0; i < date.Month - 1; ++i )
        dateOfYear += cDaysInMonth[i];

    // Add in days for this month.
    dateOfYear += date.Day;

    // Check for leap year.
    if ( date.Month > 2 &&
        (( date.Year % 100 != 0 || date.Year % 400 == 0 ) &&
        date.Year % 4 == 0 ))
        dateOfYear++;

    // Add in year.
    dateOfYear *= 10000;
    dateOfYear += date.Year;

    return dateOfYear;
}

int main()
{
    Date date{ 8, 27, 2018 };
    long dateOfYear = DateOfYear(date);
    std::cout << dateOfYear << std::endl;
}
```

O código anterior mostra que os membros de uma estrutura passada por referência são acessados usando o operador de seleção de membros (**.**) em vez do operador de seleção de membro do ponteiro (**->**).

Embora os argumentos passados como tipos de referência observem a sintaxe de tipos de não ponteiro, eles retêm uma característica importante de tipos de ponteiro: são modificáveis a menos que declarado como **const**. Como a intenção do código anterior não é alterar o objeto `date`, um protótipo de função mais apropriado é:

```cpp
long DateOfYear( const Date& date );
```

Esse protótipo garante que a função `DateOfYear` não alterará seu argumento.

Qualquer função cujo protótipo é usar um tipo de referência pode aceitar um objeto do mesmo tipo em seu lugar, porque não há uma conversão padrão de *typename* à *typename* <strong>&</strong>.

## <a name="see-also"></a>Consulte também

[Referências](../cpp/references-cpp.md)<br/>
