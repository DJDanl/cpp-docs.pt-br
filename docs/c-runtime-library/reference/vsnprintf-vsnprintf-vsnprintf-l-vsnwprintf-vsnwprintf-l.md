---
title: "vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l | Microsoft Docs"
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
  - "_vsnprintf"
  - "_vsnprintf_l"
  - "_vsnwprintf"
  - "_vsnwprintf_l"
  - "_vsnprintf"
  - "_vsnprintf;"
  - "vsnprintf; _vsnprintf"
  - "_vsnwprintf;"
  - "_vsnprintf_l;"
  - "_vsnwprintf_l;"
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
  - "_vsnprintf"
  - "_vsnwprintf"
  - "_vsntprintf"
  - "vsnprintf"
  - "stdio/vsnprintf"
  - "stdio/_vsnprintf"
  - "stdio/_vsnprintf_l"
  - "stdio/_vsnwprintf"
  - "stdio/_vsnwprintf_l"
  - "_vsnprintf_l"
  - "_vsnwprintf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função vsntprintf"
  - "Função _vsnwprintf_l"
  - "Função vsnwprintf_l"
  - "Função vsntprintf_l"
  - "Função _vsntprintf"
  - "Função _vsnprintf_l"
  - "Função vsnprintf"
  - "Função _vsntprintf_l"
  - "Função vsnprintf_l"
  - "Função _vsnwprintf"
  - "Função _vsnprintf"
  - "texto formatado [C++]"
  - "Função vsnwprintf"
ms.assetid: a97f92df-c2f8-4ea0-9269-76920d2d566a
caps.latest.revision: 35
caps.handback.revision: 35
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grave saída formatada usando um ponteiro para uma lista de argumentos. Versões mais seguras dessas funções estão disponíveis; consulte [vsnprintf\_s, \_vsnprintf\_s, \_vsnprintf\_s\_l, \_vsnwprintf\_s, \_vsnwprintf\_s\_l](../../c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md).  
  
## Sintaxe  
  
```  
int vsnprintf(  
   char *buffer,  
   size_t count,  
   const char *format,  
   va_list argptr   
);  
int _vsnprintf(  
   char *buffer,  
   size_t count,  
   const char *format,  
   va_list argptr   
);  
int _vsnprintf_l(  
   char *buffer,  
   size_t count,  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);  
int _vsnwprintf(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   va_list argptr   
);  
int _vsnwprintf_l(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
template <size_t size>  
int vsnprintf(  
   char (&buffer)[size],  
   size_t count,  
   const char *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsnprintf(  
   char (&buffer)[size],  
   size_t count,  
   const char *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsnprintf_l(  
   char (&buffer)[size],  
   size_t count,  
   const char *format,  
   locale_t locale,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsnwprintf(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsnwprintf_l(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída.  
  
 `count`  
 Número máximo de caracteres a serem gravados.  
  
 `format`  
 Especificação de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 O `vsnprintf` função retorna o número de caracteres gravados, sem contar o caractere de terminação nula. Se o tamanho do buffer especificado por `count` não é suficientemente grande para conter a saída especificada por `format` e `argptr`, o valor de retorno de `vsnprintf` é o número de caracteres que seria gravado, sem contar o caractere nulo, se `count` foram suficientemente grande. Se o valor de retorno for maior que `count` \- 1, a saída foi truncada. Um valor de retorno\-1 indica que ocorreu um erro de codificação.  
  
 Ambos `_vsnprintf` e `_vsnwprintf` funções retornam o número de caracteres gravados se o número de caracteres a serem gravados é menor ou igual a `count`; se o número de caracteres a serem gravados é maior do que `count`, essas funções de retorno \-1 indicando que a saída foi truncada.  
  
 O valor retornado por todas essas funções não inclui a terminação nula, se um for gravado ou não. Quando `count` for zero, o valor retornado é o número de caracteres que as funções escreveria, não incluindo nenhum terminação nula. Você pode usar esse resultado para alocar espaço suficiente no buffer para a cadeia de caracteres e sua terminação nula e, em seguida, chame a função novamente para preencher o buffer.  
  
 Se `format` for `NULL`, ou se `buffer` for NULL e `count` não é igual a zero, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão \-1 e defina `errno` para `EINVAL`.  
  
## Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos, em seguida, formata os dados e grava até `count` caracteres para a memória apontada por `buffer`. O `vsnprintf` função sempre grava um terminador nulo, mesmo se ele trunca a saída. Ao usar `_vsnprintf` e `_vsnwprintf`, o buffer será ser terminada em nulo apenas se houver espaço no final \(ou seja, se o número de caracteres a serem gravados é menor que `count`\).  
  
> [!IMPORTANT]
>  Para impedir que certos tipos de riscos de segurança, certifique\-se de que `format` não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [evitando saturações de Buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
> [!NOTE]
>  Para garantir que haja espaço para a terminação nula ao chamar `_vsnprintf`, `_vsnprintf_l`, `_vsnwprintf` e `_vsnwprintf_l`, certifique\-se de que `count` é estritamente menor que o comprimento do buffer e inicializar o buffer para nulo antes de chamar a função.  
>   
>  Porque `vsnprintf` sempre grava a terminação nula, o `count` parâmetro pode ser igual ao tamanho do buffer.  
  
 Começando com o UCRT no Visual Studio 2015 e Windows 10, `vsnprintf` não é idêntico ao `_vsnprintf`. O `vsnprintf` função está em conformidade com o padrão C99; `_vnsprintf` é mantido para compatibilidade com o código anterior do Visual Studio.  
  
 As versões dessas funções com o `_l` sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.  
  
 No C\+\+, essas funções têm sobrecargas de modelo que invocam as contrapartes seguros, mais recentes dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_vsntprintf`|`_vsnprintf`|`_vsnprintf`|`_vsnwprintf`|  
|`_vsntprintf_l`|`_vsnprintf_l`|`_vsnprintf_l`|`_vsnwprintf_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário \(C\)|Cabeçalho necessário \(C\+\+\)|  
|------------|--------------------------------|------------------------------------|  
|`vsnprintf`, `_vsnprintf`, `_vsnprintf_l`|\< stdio \>|\< stdio \> ou \< cstdio \>|  
|`_vsnwprintf`, `_vsnwprintf_l`|\< stdio \> ou \< WCHAR \>|\< stdio \>, \< WCHAR \>, \< cstdio \> ou \< cwchar \>|  
  
 O `_vsnprintf`, `_vsnprintf_l`, `_vsnwprintf` e `_vsnwprintf_l` funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```c  
// crt_vsnwprintf.c  
// compile by using: cl /W3 crt_vsnwprintf.c  
  
// To turn off error C4996, define this symbol:  
#define _CRT_SECURE_NO_WARNINGS  
  
#include <stdio.h>  
#include <wtypes.h>  
  
#define BUFFCOUNT (10)  
  
void FormatOutput(LPCWSTR formatstring, ...)  
{  
    int nSize = 0;  
    wchar_t buff[BUFFCOUNT];  
    memset(buff, 0, sizeof(buff));  
    va_list args;  
    va_start(args, formatstring);  
    // Note: _vsnwprintf is deprecated; consider vsnwprintf_s instead  
    nSize = _vsnwprintf(buff, BUFFCOUNT - 1, formatstring, args); // C4996  
    wprintf(L"nSize: %d, buff: %ls\n", nSize, buff);  
}  
  
int main() {  
    FormatOutput(L"%ls %ls", L"Hi", L"there");  
    FormatOutput(L"%ls %ls", L"Hi", L"there!");  
    FormatOutput(L"%ls %ls", L"Hi", L"there!!");  
}  
```  
  
```Output  
nSize: 8, incansável: Olá nSize lá: 9, incansável: Olá lá! nSize: -1, incansável: Olá lá!  
```  
  
 As alterações de comportamento se você usar vsnprintf em vez disso, junto com os parâmetros de cadeia de caracteres estreita. O `count` parâmetro pode ser o tamanho inteiro do buffer e o valor de retorno é o número de caracteres que teriam sido gravadas se `count` era grande o suficiente:  
  
## Exemplo  
  
```c  
// crt_vsnprintf.c  
// compile by using: cl /W4 crt_vsnprintf.c  
#include <stdio.h>  
#include <stdarg.h> // for va_list, va_start  
#include <string.h> // for memset  
  
#define BUFFCOUNT (10)  
  
void FormatOutput(char* formatstring, ...)  
{  
    int nSize = 0;  
    char buff[BUFFCOUNT];  
    memset(buff, 0, sizeof(buff));  
    va_list args;  
    va_start(args, formatstring);  
    nSize = vsnprintf(buff, sizeof(buff), formatstring, args);  
    printf("nSize: %d, buff: %s\n", nSize, buff);  
}  
  
int main() {  
    FormatOutput("%s %s", "Hi", "there");   //  8 chars + null  
    FormatOutput("%s %s", "Hi", "there!");  //  9 chars + null  
    FormatOutput("%s %s", "Hi", "there!!"); // 10 chars + null  
}  
```  
  
```Output  
nSize: 8, incansável: Olá nSize lá: 9, incansável: Olá lá! nSize: 10, incansável: Olá lá!  
```  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [va\_arg, va\_copy, va\_end, va\_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)