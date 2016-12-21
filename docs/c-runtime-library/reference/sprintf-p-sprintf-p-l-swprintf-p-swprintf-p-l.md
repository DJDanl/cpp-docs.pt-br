---
title: "sprintf_p, sprintf_p_l, swprintf_p, swprintf_p_l | Microsoft Docs"
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
  - "_sprintf_p"
  - "_swprintf_p_l"
  - "_swprintf_p"
  - "_sprintf_p_l"
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
  - "_sprintf_p"
  - "_swprintf_p_l"
  - "_sprintf_p_l"
  - "_swprintf_p"
  - "sprintf_p"
  - "swprint_p_l"
  - "swprintf_p"
  - "swprintf_p_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função sprintf_p_l"
  - "Função swprintf_p"
  - "Função swprintf_p_l"
  - "Função _sprintf_p"
  - "Função _sprintf_p_l"
  - "Função _swprintf_p"
  - "Função sprintf_p"
  - "Função _stprintf_p"
  - "Função stprintf_p"
  - "Função _swprintf_p_l"
  - "Função stprintf_p_l"
  - "texto formatado [C++]"
  - "Função _stprintf_p_l"
ms.assetid: a2ae78e8-6b0c-48d5-87a9-ea2365b0693d
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# sprintf_p, sprintf_p_l, swprintf_p, swprintf_p_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Dados formatados de gravação a uma cadeia de caracteres com a capacidade de especificar a ordem em que os parâmetros são usados na cadeia de caracteres de formato.  
  
## Sintaxe  
  
```  
int _sprintf_p(  
   char *buffer,  
   size_t sizeOfBuffer,  
   const char *format [,  
   argument] ...   
);  
int _sprintf_p_l(  
   char *buffer,  
   size_t sizeOfBuffer,  
   const char *format,  
   locale_t locale [,  
   argument] ...   
);  
int _swprintf_p(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   const wchar_t *format [,  
   argument]...  
);  
int _swprintf_p_l(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] …   
);  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída  
  
 `sizeOfBuffer`  
 O número máximo de caracteres a ser armazenado.  
  
 `format`  
 Cadeia de caracteres de controle de formato  
  
 `argument`  
 Argumentos opcionais  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 O número de caracteres gravados, ou – 1 se ocorrer um erro.  
  
## Comentários  
 A função de `_sprintf_p` formata e armazena uma série de caracteres e valores em `buffer`.  Cada `argument` \(se houver\) é convertido e gerado de acordo com a especificação de formato correspondente em `format`.  O formato consiste em caracteres similares e tem o mesmo formulário e função que o argumento de `format` para `printf_p`.  Um caractere de `NULL` é adicionado depois do último caractere gravado.  Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  A diferença entre `_sprintf_p` e `sprintf_s` é que `_sprintf_p` oferece suporte aos parâmetros posicionais, o que permite especificar a ordem em que os argumentos são usados na cadeia de caracteres de formato.  Para obter mais informações, consulte [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md).  
  
 `_swprintf_p` é uma versão de caractere largo de `_sprintf_p`; os argumentos de ponteiro para `_swprintf_p` são cadeias de caractere amplo.  A detecção de erros de codificação em `_swprintf_p` pode ser diferente da detecção em `_sprintf_p`.  `_swprintf_p` e `fwprintf_p` se comportam de forma idêntica exceto que `_swprintf_p` grava a saída para uma cadeia de caracteres em vez de para um destino do tipo `FILE` e `_swprintf_p` exige que o parâmetro `count` especifique o número máximo de caracteres a serem gravados.  As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
 `_sprintf_p` retorna o número de bytes armazenados em `buffer`, não pelo caractere terminador de `NULL` .  `_swprintf_p`retorna o número de caracteres amplos armazenados em `buffer`, não pelo caractere largo encerramento de `NULL` .  Se `buffer` ou `format` for um ponteiro nulo, ou se a cadeia de formato contiver caracteres de formatação inválidos, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` a `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_stprintf_p`|`_sprintf_p`|`_sprintf_p`|`_swprintf_p`|  
|`_stprintf_p_l`|`_sprintf_p_l`|`_sprintf_p_l`|`_swprintf_p_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_sprintf_p`, `_sprintf_p_l`|\<stdio.h\>|  
|`_swprintf_p`, `_swprintf_p_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_sprintf_p.c  
// This program uses _sprintf_p to format various  
// data and place them in the string named buffer.  
//  
  
#include <stdio.h>  
  
int main( void )  
{  
    char     buffer[200],  
            s[] = "computer", c = 'l';  
    int      i = 35,  
            j;  
    float    fp = 1.7320534f;  
  
    // Format and print various data:   
    j  = _sprintf_p( buffer, 200,  
                     "   String:    %s\n", s );  
    j += _sprintf_p( buffer + j, 200 - j,   
                     "   Character: %c\n", c );  
    j += _sprintf_p( buffer + j, 200 - j,   
                     "   Integer:   %d\n", i );  
    j += _sprintf_p( buffer + j, 200 - j,   
                     "   Real:      %f\n", fp );  
  
    printf( "Output:\n%s\ncharacter count = %d\n",   
            buffer, j );  
}  
```  
  
  **Saída:**  
 **String:    computer**  
 **Caractere: l**  
 **Inteiro:   35**  
 **Real:      1,732053**  
**contagem de caracteres \= 79**   
## Exemplo  
  
```  
// crt_swprintf_p.c  
// This is the wide character example which  
// also demonstrates _swprintf_p returning  
// error code.  
#include <stdio.h>  
  
#define BUFFER_SIZE 100  
  
int main( void )  
{  
    wchar_t buffer[BUFFER_SIZE];  
    int     len;  
  
    len = _swprintf_p(buffer, BUFFER_SIZE, L"%2$s %1$d",  
                      0, L" marbles in your head.");  
    _printf_p( "Wrote %d characters\n", len );  
  
    // _swprintf_p fails because string contains WEOF (\xffff)  
    len = _swprintf_p(buffer, BUFFER_SIZE, L"%s",   
                      L"Hello\xffff world" );  
    _printf_p( "Wrote %d characters\n", len );  
}  
```  
  
  **Gravou 24 caracteres**  
**Gravou \-1 caracteres**   
## Equivalência do .NET Framework  
 [System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_fprintf\_p, \_fprintf\_p\_l, \_fwprintf\_p, \_fwprintf\_p\_l](../../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [\_printf\_p, \_printf\_p\_l, \_wprintf\_p, \_wprintf\_p\_l](../../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [sscanf\_s, \_sscanf\_s\_l, swscanf\_s, \_swscanf\_s\_l](../Topic/sscanf_s,%20_sscanf_s_l,%20swscanf_s,%20_swscanf_s_l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)   
 [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md)