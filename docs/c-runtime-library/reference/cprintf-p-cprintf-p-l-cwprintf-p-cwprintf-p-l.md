---
title: "_cprintf_p, _cprintf_p_l, _cwprintf_p, _cwprintf_p_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_cprintf_p_l"
  - "_cwprintf_p_l"
  - "_cwprintf_p"
  - "_cprintf_p"
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
  - "cprintf_p"
  - "cwprintf_p"
  - "tcprintf_p"
  - "_cwprintf_p_l"
  - "_cprintf_p"
  - "csprintf_p_l"
  - "_cprintf_p_l"
  - "_cwprintf_p"
  - "_tcprintf_p"
  - "cprintf_p_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _cprintf_p"
  - "Função _cprintf_p_l"
  - "Função _cwprintf_p"
  - "Função _cwprintf_p_l"
  - "Função _tcprintf_p"
  - "Função _tcprintf_p_l"
  - "Função cprintf_p"
  - "Função cprintf_p_l"
  - "Função cwprintf_p"
  - "Função cwprintf_p_l"
  - "Função tcprintf_p"
  - "Função tcprintf_p_l"
ms.assetid: 1f82fd7d-13c8-4c4a-a3e4-db0df3873564
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _cprintf_p, _cprintf_p_l, _cwprintf_p, _cwprintf_p_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Formata e imprime no console e oferece suporte a parâmetros posicionais na cadeia de caracteres de formato.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _cprintf_p(   
   const char * format [,   
   argument] ...   
);  
int _cprintf_p_l(   
   const char * format,  
   locale_t locale [,   
   argument] ...   
);  
int _cwprintf_p(  
   const wchar * format [,   
   argument] ...  
);  
int _cwprintf_p_l(  
   const wchar * format,  
   locale_t locale [,  
   argument] ...  
);  
```  
  
#### Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Parâmetros opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 O número de caracteres impressos ou um valor negativo, se ocorrer um erro.  
  
## Comentários  
 Essas funções Formatar e imprimir uma série de caracteres e valores diretamente para o console usando o`_putch`e`_putwch`funciona para caracteres de saída.  Cada`argument`\(se houver\) é convertido e saída de acordo com a especificação de formato correspondente em`format`.  O formato tem o mesmo formato e função que o`format`parâmetro para o[printf\_p](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)função.  A diferença entre`_cprintf_p`e`cprintf_s`que`_cprintf_p`parâmetros posicionais oferece suporte, que permite especificar a ordem em que os argumentos são usados na cadeia de caracteres de formato.  Para obter mais informações, consulte[Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md).  
  
 Ao contrário do`fprintf_p``printf_p`e`sprintf_p`funções, nem`_cprintf_p`nem`_cwprintf_p`converte caracteres de alimentação de linha em combinações de alimentação de linha de retorno \(CR\-LF\) carro durante a impressão.  Uma distinção importante é que`_cwprintf_p`exibe caracteres Unicode quando usado no Windows NT.  Ao contrário de`_cprintf_p``_cwprintf_p`usa as configurações atuais de localidade do console.  
  
 As versões dessas funções com o`_l`sufixo são idênticas, exceto que eles usam o parâmetro de localidade informado em vez da localidade atual.  
  
> [!IMPORTANT]
>  Verifique se `format` não é uma cadeia de caracteres definida pelo usuário.  
  
 Além disso, como`_cprintf_s`e`_cwprintf_s`eles validam o ponteiro de entrada e a cadeia de caracteres de formato.  Se`format`ou`argument`são`NULL`ou do formato de cadeia de caracteres contém caracteres inválidos de formatação, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em[Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` como `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcprintf_p`|`_cprintf_p`|`_cprintf_p`|`_cwprintf_p`|  
|`_tcprintf_p_l`|`_cprintf_p_l`|`_cprintf_p_l`|`_cwprintf_p_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_cprintf_p`,`_cprintf_p_l`|\< conio.h \>|  
|`_cwprintf_p`,`_cwprintf_p_l`|\< conio.h \>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_cprintf_p.c  
// This program displays some variables to the console  
// using the _cprintf_p function.  
  
#include <conio.h>  
  
int main( void )  
{  
    int         i = -16,  
                h = 29;  
    unsigned    u = 62511;  
    char        c = 'A';  
    char        s[] = "Test";  
  
    // Note that console output does not translate  
    // \n as standard output does. Use \r\n instead.  
    _cprintf_p( "%2$d  %1$.4x  %3$u  %4$c %5$s\r\n",   
                h, i, u, c, s );  
}  
```  
  
  **d\-16 001 62511 um teste**   
## Consulte também  
 [Console e E\/S de porta](../../c-runtime-library/console-and-port-i-o.md)   
 [\_cscanf, \_cscanf\_l, \_cwscanf, \_cwscanf\_l](../../c-runtime-library/reference/cscanf-cscanf-l-cwscanf-cwscanf-l.md)   
 [\_cscanf\_s, \_cscanf\_s\_l, \_cwscanf\_s, \_cwscanf\_s\_l](../../c-runtime-library/reference/cscanf-s-cscanf-s-l-cwscanf-s-cwscanf-s-l.md)   
 [\_fprintf\_p, \_fprintf\_p\_l, \_fwprintf\_p, \_fwprintf\_p\_l](../../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)   
 [fprintf\_s, \_fprintf\_s\_l, fwprintf\_s, \_fwprintf\_s\_l](../../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md)   
 [\_printf\_p, \_printf\_p\_l, \_wprintf\_p, \_wprintf\_p\_l](../../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)   
 [printf\_s, \_printf\_s\_l, wprintf\_s, \_wprintf\_s\_l](../../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)   
 [sprintf\_p, sprintf\_p\_l, swprintf\_p, swprintf\_p\_l](../../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)   
 [\_vfprintf\_p, \_vfprintf\_p\_l, \_vfwprintf\_p, \_vfwprintf\_p\_l](../../c-runtime-library/reference/vfprintf-p-vfprintf-p-l-vfwprintf-p-vfwprintf-p-l.md)   
 [\_cprintf\_s, \_cprintf\_s\_l, \_cwprintf\_s, \_cwprintf\_s\_l](../../c-runtime-library/reference/cprintf-s-cprintf-s-l-cwprintf-s-cwprintf-s-l.md)   
 [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)