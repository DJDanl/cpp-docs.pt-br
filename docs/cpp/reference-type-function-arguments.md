---
title: "Argumentos da fun&#231;&#227;o de tipo de refer&#234;ncia | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "argumentos [C++], Função "
  - "argumentos de função, tipo de referência"
  - "parâmetros de função, tipo de referência"
  - "funções [C++], parâmetros"
  - "passando parâmetros, argumentos de tipo de referência"
ms.assetid: 0a70e831-9e76-46c0-821d-aeba13d73cc0
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Argumentos da fun&#231;&#227;o de tipo de refer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É geralmente mais eficiente passar referências, em vez de objetos grandes, para funções.  Isso permite que o compilador passe o endereço do objeto enquanto mantém a sintaxe que seria usada para acessar o objeto.  Considere o seguinte exemplo que usa a estrutura `Date`:  
  
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
  
 O código anterior mostra que os membros de uma estrutura passada por referência são acessados usando o operador de seleção de membro \(**.**\) em vez do operador de seleção de membro de ponteiro \(**–\>**\).  
  
 Embora os argumentos passados como tipos de referência observem a sintaxe de tipos de não ponteiro, eles retêm uma característica importante de tipos de ponteiro: são modificáveis a menos que declarados como **const**.  Como a intenção do código anterior não é alterar o objeto `GDate`, um protótipo de função mais apropriado é:  
  
```  
long JulianFromGregorian( const Date& GDate );  
```  
  
 Esse protótipo garante que a função `JulianFromGregorian` não alterará seu argumento.  
  
 Qualquer função cujo protótipo é usar um tipo de referência pode aceitar um objeto do mesmo tipo em seu lugar, porque não há uma conversão padrão de *typename* para *typename***&**.  
  
## Consulte também  
 [Referências](../cpp/references-cpp.md)