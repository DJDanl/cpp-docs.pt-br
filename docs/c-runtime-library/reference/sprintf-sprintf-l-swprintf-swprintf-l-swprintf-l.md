---
title: "sprintf, _sprintf_l, swprintf, _swprintf_l, __swprintf_l | Microsoft Docs"
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
  - "__swprintf_l"
  - "sprintf"
  - "_sprintf_l"
  - "_swprintf_l"
  - "swprintf"
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
  - "_stprintf_l"
  - "__swprintf_l"
  - "sprintf_l"
  - "swprintf"
  - "_sprintf_l"
  - "sprintf"
  - "_stprintf"
  - "stprintf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __swprintf_l"
  - "_CRT_NON_CONFORMING_SWPRINTFS"
  - "Função _sprintf_l"
  - "Função _stprintf"
  - "Função _stprintf_l"
  - "Função _swprintf_l"
  - "texto formatado [C++]"
  - "Função sprintf"
  - "Função sprintf_l"
  - "Função stprintf"
  - "Função stprintf_l"
  - "cadeias de caracteres [C++], gravando em"
  - "Função swprintf"
  - "Função swprintf_l"
ms.assetid: f6efe66f-3563-4c74-9455-5411ed939b81
caps.latest.revision: 36
caps.handback.revision: 34
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# sprintf, _sprintf_l, swprintf, _swprintf_l, __swprintf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gravar dados formatados em uma cadeia de caracteres.  Versões mais seguras de algumas dessas funções estão disponíveis; consulte[sprintf\_s, \_sprintf\_s\_l, swprintf\_s, \_swprintf\_s\_l](../../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md).  As versões seguras`swprintf`e`_swprintf_l`não têm um`count`parâmetro.  
  
## Sintaxe  
  
```  
int sprintf(  
   char *buffer,  
   const char *format [,  
   argument] ...   
);  
int _sprintf_l(  
   char *buffer,  
   const char *format,  
   locale_t locale [,  
   argument] ...   
);  
int swprintf(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format [,  
   argument]...  
);  
int _swprintf_l(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
);  
int __swprintf_l(  
   wchar_t *buffer,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
);  
template <size_t size>  
int sprintf(  
   char (&buffer)[size],  
   const char *format [,  
   argument] ...   
); // C++ only  
template <size_t size>  
int _sprintf_l(  
   char (&buffer)[size],  
   const char *format,  
   locale_t locale [,  
   argument] ...   
); // C++ only  
  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída  
  
 `count`  
 Número máximo de caracteres para armazenar a versão Unicode dessa função.  
  
 `format`  
 Cadeia de caracteres de controle de formato  
  
 `argument`  
 Argumentos opcionais  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte[especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 O número de caracteres gravados, ou \-1 se ocorreu um erro.  Se`buffer`ou`format`é um ponteiro nulo, o manipulador de parâmetro inválido é chamado, conforme descrito em[Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` como `EINVAL`.  
  
 `sprintf`Retorna o número de bytes armazenados em`buffer`sem contar o caractere de terminação nula.  `swprintf`retorna o número de caracteres largos armazenados em`buffer`sem contar o caractere largo nulo de terminação.  
  
## Comentários  
 O`sprintf`função formata e armazena uma série de caracteres e valores em`buffer`.  Cada`argument`\(se houver\) é convertido e saída de acordo com a especificação de formato correspondente em`format`.  O formato consiste em caracteres comuns e tem o mesmo formato e função que o argumento `format` para [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  Um caractere nulo é acrescentado depois do último caractere escrito.  Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Usando`sprintf`não é possível limitar o número de caracteres gravados, o que significa que o código usando`sprintf`é suscetível a estouros de buffer.  Considere usar a função related[snprintf](../../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md)que especifica um número máximo de caracteres a serem gravados`buffer`ou use[scprintf](../Topic/_scprintf,%20_scprintf_l,%20_scwprintf,%20_scwprintf_l.md)para determinar quanto um buffer é necessário.  Além disso, verifique se`format`não é uma cadeia de caracteres definida pelo usuário.  
  
 `swprintf` é uma versão de caractere largo de `sprintf`; os argumentos de ponteiro para `swprintf` são cadeias de caracteres largos.  Detecção de erros de codificação`swprintf`pode ser diferente no`sprintf`.  `swprintf`e`fwprintf`comportamento idêntico, exceto que`swprintf`grava a saída em uma cadeia de caracteres em vez de um destino do tipo`FILE`e`swprintf`requer o`count`parâmetro para especificar o número máximo de caracteres a ser gravado.  As versões dessas funções com o`_l`sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.  
  
 `swprintf`está em conformidade com o ISO C Standard, que requer o segundo parâmetro,`count`do tipo`size_t`.  Para forçar o antigo comportamento padrão, defina`_CRT_NON_CONFORMING_SWPRINTFS`.  Em uma versão futura, o comportamento antigo pode ser removido, para que o código deve ser alterado para usar o novo comportamento compatível.  
  
 Em C\+\+, essas funções têm sobrecargas de modelo que invocam os contrapartes mais recentes, seguras dessas funções.  Para obter mais informações, consulte[Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_stprintf`|`sprintf`|`sprintf`|`_swprintf`|  
|`_stprintf_l`|`_sprintf_l`|`_sprintf_l`|`__swprintf_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`sprintf`, `_sprintf_l`|\<stdio.h\>|  
|`swprintf`, `_swprintf_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_sprintf.c  
// compile with: /W3  
// This program uses sprintf to format various  
// data and place them in the string named buffer.  
  
#include <stdio.h>  
  
int main( void )  
{  
   char  buffer[200], s[] = "computer", c = 'l';  
   int   i = 35, j;  
   float fp = 1.7320534f;  
  
   // Format and print various data:   
   j  = sprintf( buffer,     "   String:    %s\n", s ); // C4996  
   j += sprintf( buffer + j, "   Character: %c\n", c ); // C4996  
   j += sprintf( buffer + j, "   Integer:   %d\n", i ); // C4996  
   j += sprintf( buffer + j, "   Real:      %f\n", fp );// C4996  
   // Note: sprintf is deprecated; consider using sprintf_s instead  
  
   printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );  
}  
```  
  
  **Saída:**  
 **Cadeia de caracteres: computador**  
 **Caractere: l**  
 **Inteiro: 35**  
 **Real: 1.732053**  
**Contagem de caracteres \= 79**   
## Exemplo  
  
```  
// crt_swprintf.c  
// wide character example  
// also demonstrates swprintf returning error code  
#include <stdio.h>  
  
int main( void )  
{  
   wchar_t buf[100];  
   int len = swprintf( buf, 100, L"%s", L"Hello world" );  
   printf( "wrote %d characters\n", len );  
   len = swprintf( buf, 100, L"%s", L"Hello\xffff world" );  
   // swprintf fails because string contains WEOF (\xffff)  
   printf( "wrote %d characters\n", len );  
}  
```  
  
  **escrevi 11 caracteres**  
**escrevi\-1 caracteres**   
## Equivalência do .NET Framework  
 [System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)