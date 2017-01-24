---
title: "snprintf, snprintf, snprintf_l, snwprintf, snwprintf_l | Microsoft Docs"
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
  - "_snwprintf"
  - "_snprintf"
  - "_snprintf_l"
  - "_snwprintf_l"
  - "snprintf"
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
  - "_snprintf"
  - "snprintf_l"
  - "snwprintf_l"
  - "sntprintf"
  - "snprintf"
  - "_sntprintf"
  - "_sntprintf_l"
  - "sntprintf_l"
  - "snwprintf"
  - "_snprintf_l"
  - "_snwprintf"
  - "_snwprintf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função snwprintf_l"
  - "Função sntprintf_l"
  - "Função snprintf_l"
  - "Função _snwprintf_l"
  - "Função _sntprintf_l"
  - "Função _snwprintf"
  - "Função _snprintf"
  - "Função _sntprintf"
  - "Função _snprintf_l"
  - "Função snwprintf"
  - "Função snprintf"
  - "Função sntprintf"
  - "texto formatado [C++]"
ms.assetid: 5976c9c8-876e-4ac9-a515-39f3f7fd0925
caps.latest.revision: 35
caps.handback.revision: 35
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# snprintf, snprintf, snprintf_l, snwprintf, snwprintf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava dados formatados em uma cadeia de caracteres. Versões mais seguras dessas funções estão disponíveis; consulte [\_snprintf\_s, \_snprintf\_s\_l, \_snwprintf\_s, \_snwprintf\_s\_l](../../c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l.md).  
  
## Sintaxe  
  
```  
int snprintf(  
   char *buffer,  
   size_t count,  
   const char *format [,  
   argument] ...   
);  
int _snprintf(  
   char *buffer,  
   size_t count,  
   const char *format [,  
   argument] ...   
);  
int _snprintf_l(  
   char *buffer,  
   size_t count,  
   const char *format,  
   locale_t locale [,  
   argument] ...   
);  
int _snwprintf(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format [,  
   argument] ...   
);  
int _snwprintf_l(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
);  
template <size_t size>  
int _snprintf(  
   char (&buffer)[size],  
   size_t count,  
   const char *format [,  
   argument] ...   
); // C++ only  
template <size_t size>  
int _snprintf_l(  
   char (&buffer)[size],  
   size_t count,  
   const char *format,  
   locale_t locale [,  
   argument] ...   
); // C++ only  
template <size_t size>  
int _snwprintf(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format [,  
   argument] ...   
); // C++ only  
template <size_t size>  
int _snwprintf_l(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para a saída.  
  
 `count`  
 Número máximo de caracteres a ser armazenado.  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 Permitir que `len` ser o comprimento da cadeia de caracteres formatada de dados, não incluindo a terminação nula. Ambos `len` e `count` estão em bytes para `snprintf` e `_snprintf`, caracteres largos para `_snwprintf`.  
  
 Para todas as funções, se `len` \< `count`, `len` caracteres são armazenados em `buffer`, um terminador nulo será anexado, e `len` é retornado.  
  
 O `snprintf` função trunca a saída quando `len` for maior ou igual a `count`, colocando um terminador nulo no `buffer[count-1]`. O valor retornado é `len`, o número de caracteres que teria sido saída se `count` era grande o suficiente. O `snprintf` função retorna um valor negativo, se ocorrer um erro de codificação.  
  
 Para todas as funções que `snprintf`, se `len` \= `count`, `len` caracteres são armazenados em `buffer`, nenhum terminador nulo será anexado, e `len` é retornado. Se `len` \> `count`, `count` caracteres são armazenados em `buffer`, nenhum terminador nulo será anexado, e um valor negativo é retornado.  
  
 Se `buffer` for um ponteiro nulo e `count` for zero, `len` é retornado como a contagem de caracteres necessários para formatar a saída, não incluindo a terminação nula. Para fazer uma chamada bem\-sucedida com o mesmo `argument` e `locale` parâmetros, alocar um buffer que contém pelo menos `len` \+ 1 caracteres.  
  
 Se `buffer` for um ponteiro nulo e `count` é diferente de zero, ou se `format` é um ponteiro nulo, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão \-1 e defina `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `snprintf` função e o `_snprintf` família do formato de funções e armazenamento `count` ou menos caracteres em `buffer`. O `snprintf` função sempre armazena um caractere nulo de encerramento truncar a saída, se necessário. O `_snprintf` família de funções somente acrescenta um caractere de terminação nula se o comprimento da cadeia de caracteres formatada é estritamente menor que `count` caracteres. Cada `argument` \(se houver\) é convertido e gerado de acordo com a especificação de formato correspondente em `format`. O formato consiste em caracteres comuns e tem o mesmo formato e função que o `format` argumento [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md). Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Certifique\-se de que `format` não é uma cadeia de caracteres definida pelo usuário. Porque o `_snprintf` funções não garante a terminação NULL — em particular, quando o valor de retorno é `count`— Certifique\-se de que eles sejam seguidos pelo código que adiciona o terminador nulo. Para obter mais informações, consulte [evitando saturações de Buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 Começando com o UCRT no Visual Studio 2015 e Windows 10, `snprintf` não é idêntico ao `_snprintf`. O `snprintf` comportamento da função agora é padrão C99 compatível.  
  
 `_snwprintf` é uma versão de caractere largo de `_snprintf`; os argumentos de ponteiro para `_snwprintf` são cadeias de caracteres largos. Detecção de erros de codificação `_snwprintf` pode ser diferente do que em `_snprintf`.`_snwprintf`, assim como `swprintf`, grava a saída para uma cadeia de caracteres em vez de um destino do tipo `FILE`.  
  
 As versões dessas funções que têm o `_l` sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.  
  
 No C\+\+, essas funções têm sobrecargas de modelo que invocam suas correspondentes mais seguras e mais recentes. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_sntprintf`|`_snprintf`|`_snprintf`|`_snwprintf`|  
|`_sntprintf_l`|`_snprintf_l`|`_snprintf_l`|`_snwprintf_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`snprintf`, `_snprintf`,  `_snprintf_l`|\< stdio \>|  
|`_snwprintf`, `_snwprintf_l`|\< stdio \> ou \< WCHAR \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```c  
// crt_snprintf.c  
// compile with: /W3  
#include <stdio.h>  
#include <stdlib.h>  
  
#if !defined(__cplusplus)  
typedef int bool;  
const bool true = 1;  
const bool false = 0;  
#endif  
  
#define FAIL 0 // change to 1 and see what happens  
  
int main(void)  
{  
   char buffer[200];  
   const static char s[] = "computer"  
#if FAIL  
"computercomputercomputercomputercomputercomputercomputercomputer"  
"computercomputercomputercomputercomputercomputercomputercomputer"  
"computercomputercomputercomputercomputercomputercomputercomputer"  
"computercomputercomputercomputercomputercomputercomputercomputer"  
#endif  
   ;  
   const char c = 'l';   
   const int i = 35;  
#if FAIL  
   const double fp = 1e300; // doesn't fit in the buffer  
#else  
   const double fp = 1.7320534;  
#endif  
   /* !subtract one to prevent "squeezing out" the terminal nul! */  
   const int bufferSize = sizeof(buffer)/sizeof(buffer[0]) - 1;  
   int bufferUsed = 0;  
   int bufferLeft = bufferSize - bufferUsed;  
   bool bSuccess = true;  
   buffer[0] = 0;  
  
   /* Format and print various data: */  
  
   if (bufferLeft > 0)  
   {  
      int perElementBufferUsed = _snprintf(&buffer[bufferUsed],   
      bufferLeft, "   String: %s\n", s ); // C4996  
      // Note: _snprintf is deprecated; consider _snprintf_s instead  
      if (bSuccess = (perElementBufferUsed >= 0))  
      {  
         bufferUsed += perElementBufferUsed;  
         bufferLeft -= perElementBufferUsed;  
         if (bufferLeft > 0)  
         {  
            int perElementBufferUsed = _snprintf(&buffer[bufferUsed],   
            bufferLeft, "   Character: %c\n", c ); // C4996  
            if (bSuccess = (perElementBufferUsed >= 0))  
            {  
               bufferUsed += perElementBufferUsed;  
               bufferLeft -= perElementBufferUsed;  
               if (bufferLeft > 0)  
               {  
                  int perElementBufferUsed = _snprintf(&buffer  
                  [bufferUsed], bufferLeft, "   Integer: %d\n", i ); // C4996  
                  if (bSuccess = (perElementBufferUsed >= 0))  
                  {  
                     bufferUsed += perElementBufferUsed;  
                     bufferLeft -= perElementBufferUsed;  
                     if (bufferLeft > 0)  
                     {  
                        int perElementBufferUsed = _snprintf(&buffer  
                        [bufferUsed], bufferLeft, "   Real: %f\n", fp ); // C4996  
                        if (bSuccess = (perElementBufferUsed >= 0))  
                        {  
                           bufferUsed += perElementBufferUsed;  
                        }  
                     }  
                  }  
               }  
            }  
         }  
      }  
   }  
  
   if (!bSuccess)  
   {  
      printf("%s\n", "failure");  
   }  
   else  
   {  
      /* !store nul because _snprintf doesn't necessarily (if the string   
       * fits without the terminal nul, but not with it)!  
       * bufferUsed might be as large as bufferSize, which normally is   
       * like going one element beyond a buffer, but in this case   
       * subtracted one from bufferSize, so we're ok.  
       */  
      buffer[bufferUsed] = 0;  
      printf( "Output:\n%s\ncharacter count = %d\n", buffer, bufferUsed );  
   }  
   return EXIT_SUCCESS;  
}  
```  
  
```Output  
Saída: a cadeia de caracteres: computador caractere: l inteiro: 35 Real: 1.732053 contagem de caracteres = 69  
```  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)