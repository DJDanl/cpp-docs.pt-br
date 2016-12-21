---
title: "_vcprintf_p, _vcprintf_p_l, _vcwprintf_p, _vcwprintf_p_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_vcprintf_p"
  - "_vcwprintf_p_l"
  - "_vcprintf_p_l"
  - "_vcwprintf_p"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "vcwprintf_p"
  - "vcprintf_p_l"
  - "_vcprintf_p"
  - "_vcprintf_p_l"
  - "vcwprintf_p_l"
  - "vcprintf_p"
  - "_vcwprintf_p"
  - "_vcwprintf_p_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _vtcprintf_p_l"
  - "Função vcprintf_p_l"
  - "Função _vcprintf_p_l"
  - "Função vtcprintf_p_l"
  - "Função vcprintf_p"
  - "Função _vcwprintf_p"
  - "Função _vcprintf_p"
  - "Função vcwprintf_p"
  - "Função vcwprintf_p_l"
  - "Função vtcprintf_p"
  - "Função _vcwprintf_p_l"
  - "Função _vtcprintf_p"
ms.assetid: 611024cc-90e7-41db-8e85-145ca95012b1
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _vcprintf_p, _vcprintf_p_l, _vcwprintf_p, _vcwprintf_p_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava a saída formatada para o console usando um ponteiro para uma lista de argumentos e oferece suporte a parâmetros posicionais na cadeia de caracteres de formato.  
  
> [!IMPORTANT]
>  Essa API não pode ser usado em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _vcprintf_p(  
   const char* format,  
   va_list argptr  
);  
int _vcprintf_p_l(  
   const char* format,  
   locale_t locale,  
   va_list argptr  
);  
int _vcwprintf_p(  
   const wchar_t* format,  
   va_list argptr  
);  
int _vcwprintf_p_l(  
   const wchar_t* format,  
   locale_t locale,  
   va_list argptr  
);  
```  
  
#### Parâmetros  
 `format`  
 A especificação de formato.  
  
 `argptr`  
 Um ponteiro para uma lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 O número de caracteres que são gravados ou um valor negativo, se ocorrer um erro de saída. Se `format` for um ponteiro nulo, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `errno` é definido como `EINVAL` e \-1 será retornado.  
  
## Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, usa o `_putch` função Formatar e gravar os dados fornecidos no console. \(`_vcwprintf_p` usa `_putwch` em vez de `_putch`.`_vcwprintf_p` é a versão de caractere largo do `_vcprintf_p`. Uma cadeia de caracteres largos ele usa como um argumento.\)  
  
 As versões dessas funções que têm o `_l` sufixo são idênticas, exceto que elas usam o parâmetro de localidade que é passado em vez da localidade atual.  
  
 Cada `argument` \(se houver\) é convertido e gerado de acordo com a especificação de formato correspondente em `format`. A especificação de formato oferece suporte a parâmetros posicionais para que você pode especificar a ordem em que os argumentos são usados na cadeia de caracteres de formato. Para obter mais informações, consulte [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md).  
  
 Essas funções não traduzir caracteres de alimentação de linha em combinações de alimentação de linha de retorno \(CR\-LF\) do carro quando eles forem gerados.  
  
> [!IMPORTANT]
>  Certifique\-se de que `format` não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [evitando saturações de Buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 Essas funções validam o ponteiro de entrada e a cadeia de caracteres de formato. Se `format` ou `argument` é `NULL`, ou se a cadeia de caracteres de formato contém caracteres inválidos de formatação, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão \-1 e defina `errno` para `EINVAL`.  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_vtcprintf_p`|`_vcprintf_p`|`_vcprintf_p`|`_vcwprintf_p`|  
|`_vtcprintf_p_l`|`_vcprintf_p_l`|`_vcprintf_p_l`|`_vcwprintf_p_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_vcprintf_p`, `_vcprintf_p_l`|\< conio.h \> e \< stdarg. h \>|  
|`_vcwprintf_p`, `_vcwprintf_p_l`|\< conio.h \> e \< stdarg. h \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
  
      // crt_vcprintf_p.c  
// compile with: /c  
#include <conio.h>  
#include <stdarg.h>  
  
// An error formatting function that's used to print to the console.  
int eprintf(const char* format, ...)  
{  
  va_list args;  
  va_start(args, format);  
  return _vcprintf_p(format, args);  
}  
  
int main()  
{  
   int n = eprintf("parameter 2 = %2$d; parameter 1 = %1$s\r\n",  
      "one", 222);  
   _cprintf_s("%d characters printed\r\n");  
}  
```  
  
```Output  
parâmetro 2 = 222; parâmetro 1 = um 38 caracteres impressos  
```  
  
## Consulte também  
 [Console e E\/S de porta](../../c-runtime-library/console-and-port-i-o.md)   
 [\_cprintf, \_cprintf\_l, \_cwprintf, \_cwprintf\_l](../../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)   
 [va\_arg, va\_copy, va\_end, va\_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)   
 [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md)