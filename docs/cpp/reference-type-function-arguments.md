---
title: Argumentos de função do tipo de referência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: fad8fc85a37aec80d09ed6df9280a78de0540f01
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409051"
---
# <a name="reference-type-function-arguments"></a>Argumentos de funções de tipo de referência
É geralmente mais eficiente passar referências, em vez de objetos grandes, para funções. Isso permite que o compilador passe o endereço do objeto enquanto mantém a sintaxe que seria usada para acessar o objeto. Considere o seguinte exemplo que usa a estrutura `Date`:  
  
```cpp 
// reference_type_function_arguments.cpp  
struct Date  
{  
short DayOfWeek;  
short Month;  
short Day;  
short Year;  
};  
  
// Create a Julian date of the form DDDYYYY  
// from a Gregorian date.  
long JulianFromGregorian( Date& GDate )  
{  
static int cDaysInMonth[] = {  
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  
   };  
long JDate = 0;  
// Add in days for months already elapsed.  
for ( int i = 0; i < GDate.Month - 1; ++i )  
JDate += cDaysInMonth[i];  
// Add in days for this month.  
JDate += GDate.Day;  
  
// Check for leap year.  
if ( GDate.Year % 100 != 0 && GDate.Year % 4 == 0 )  
JDate++;  
// Add in year.  
JDate *= 10000;  
JDate += GDate.Year;  
  
return JDate;  
}  
  
int main()  
{  
}  
```  
  
 O código anterior mostra que os membros de uma estrutura passada por referência são acessados usando o operador de seleção de membros (**.**) em vez do operador de seleção de membro do ponteiro (**->**).  
  
 Embora os argumentos passados como tipos de referência observem a sintaxe de tipos de não ponteiro, eles retêm uma característica importante de tipos de ponteiro: são modificáveis a menos que declarado como **const**. Como a intenção do código anterior não é alterar o objeto `GDate`, um protótipo de função mais apropriado é:  
  
```cpp 
long JulianFromGregorian( const Date& GDate );  
```  
  
 Esse protótipo garante que a função `JulianFromGregorian` não alterará seu argumento.  
  
 Qualquer função cujo protótipo é usar um tipo de referência pode aceitar um objeto do mesmo tipo em seu lugar, porque não há uma conversão padrão de *typename* para * * typename**&**.  
  
## <a name="see-also"></a>Consulte também  
 [Referências](../cpp/references-cpp.md)