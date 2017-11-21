---
title: "Argumentos de função de tipo de referência | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- arguments [C++], function
- functions [C++], paramters
- function parameters [C++], reference-type
- function arguments [C++], reference-type
- passing parameters [C++], reference-type arguments
ms.assetid: 0a70e831-9e76-46c0-821d-aeba13d73cc0
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 63eb2b4c7415dc463b38346909bd2b6fd902c332
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="reference-type-function-arguments"></a>Argumentos de funções de tipo de referência
É geralmente mais eficiente passar referências, em vez de objetos grandes, para funções. Isso permite que o compilador passe o endereço do objeto enquanto mantém a sintaxe que seria usada para acessar o objeto. Considere o seguinte exemplo que usa a estrutura `Date`:  
  
```  
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
  
 O código anterior mostra que os membros de uma estrutura passado por referência são acessados usando o operador de seleção de membro (**.**) em vez do operador de seleção de membro de ponteiro (**->**).  
  
 Embora os argumentos passados como tipos de referência observar a sintaxe dos tipos de ponteiro não, eles mantêm uma característica importante dos tipos de ponteiro: estiverem modificáveis, a menos que declarado como **const**. Como a intenção do código anterior não é alterar o objeto `GDate`, um protótipo de função mais apropriado é:  
  
```  
long JulianFromGregorian( const Date& GDate );  
```  
  
 Esse protótipo garante que a função `JulianFromGregorian` não alterará seu argumento.  
  
 Qualquer função prototipada como colocar um tipo de referência pode aceitar um objeto do mesmo tipo em seu lugar, porque não há uma conversão padrão de *typename* para *typename*  **&** .  
  
## <a name="see-also"></a>Consulte também  
 [Referências](../cpp/references-cpp.md)