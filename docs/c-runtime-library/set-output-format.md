---
title: "_set_output_format | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_set_output_format"
apilocation: 
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr90.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_output_format"
  - "_set_output_format"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _TWO_DIGIT_EXPONENT"
  - "formatação de saída"
  - "Constante TWO_DIGIT_EXPONENT"
  - "Função _set_output_format"
  - "Função set_output_format"
ms.assetid: 1cb48df8-44b4-4400-bd27-287831d6b3ff
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_output_format
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Personaliza os formatos de saída usados pelas funções de e\/s formatadas.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ele não está disponível no CRT.  
  
## Sintaxe  
  
```  
unsigned int _set_output_format(  
   unsigned int format  
);  
```  
  
#### Parâmetros  
 \[in\] `format`  
 Um valor que representa o formato a ser usado.  
  
## Valor de retorno  
 O formato de saída anterior.  
  
## Comentários  
 `_set_output_format` é usado para configurar a saída das funções de e\/s formatadas como [printf\_s](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md). No momento, a convenção de formatação só pode ser alterada por essa função é o número de dígitos exibidos nos expoentes na saída de números de ponto flutuante.  
  
 Por padrão, a saída de flutuante apontar números por funções como `printf_s`, `wprintf_s`, e funções relacionadas na biblioteca C padrão do Visual C\+\+ imprime três dígitos para o expoente, mesmo se os três dígitos não forem necessários para representar o valor do expoente. Zeros são usados para preencher o valor a três dígitos.`_set_output_format` permite alterar esse comportamento para que somente dois dígitos são impressas no expoente, a menos que um terceiro dígito é necessária para o tamanho do expoente.  
  
 Para habilitar os expoentes de dois dígitos, chame essa função com o parâmetro `_TWO_DIGIT_EXPONENT`, conforme mostrado no exemplo. Para desabilitar dois expoentes dígito, chame essa função com um argumento de 0.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_output_format`|\< stdio \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md) na introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Exemplo  
  
```  
// crt_set_output_format.c  
#include <stdio.h>  
  
void printvalues(double x, double y)  
{  
   printf_s("%11.4e %11.4e\n", x, y);  
   printf_s("%11.4E %11.4E\n", x, y);  
   printf_s("%11.4g %11.4g\n", x, y);  
   printf_s("%11.4G %11.4G\n", x, y);  
}  
  
int main()  
{  
   double x = 1.211E-5;  
   double y = 2.3056E-112;  
   unsigned int old_exponent_format;  
  
   // Use the default format  
   printvalues(x, y);  
  
   // Enable two-digit exponent format  
   old_exponent_format = _set_output_format(_TWO_DIGIT_EXPONENT);  
  
   printvalues(x, y);  
  
   // Disable two-digit exponent format  
   _set_output_format( old_exponent_format );  
  
   printvalues(x, y);  
}  
```  
  
```Output  
1.2110e-005 2.3056e-112 1.2110E-005 2.3056E-112 1.211e-005 2.306e-112 1.211E-005 2.306E-112 1.2110e-05 2.3056e-112 1.2110E-05 2.3056E-112 1.211e-05 2.306e-112 1.211E-05 2.306E-112 1.2110e-005 2.3056e-112 1.2110E-005 2.3056E-112 1.211e-005 2.306e-112 1.211E-005 2.306E-112  
```  
  
## Consulte também  
 [printf\_s, \_printf\_s\_l, wprintf\_s, \_wprintf\_s\_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)   
 [\_get\_output\_format](../c-runtime-library/get-output-format.md)