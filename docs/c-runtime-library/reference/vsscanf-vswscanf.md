---
title: "vsscanf, vswscanf | Microsoft Docs"
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
  - "vsscanf"
  - "vswscanf"
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
  - "_vstscanf"
  - "vsscanf"
  - "vswscanf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função vsscanf"
  - "Função vswscanf"
ms.assetid: e96180f2-df46-423d-b4eb-0a49ab819bde
caps.latest.revision: 9
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsscanf, vswscanf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados de uma cadeia de caracteres.  Versões mais seguras dessas funções estão disponíveis; consulte [vsscanf\_s, vswscanf\_s](../../c-runtime-library/reference/vsscanf-s-vswscanf-s.md).  
  
## Sintaxe  
  
```  
int vsscanf(  
   const char *buffer,  
   const char *format,  
   va_list arglist  
);  
int vswscanf(  
   const wchar_t *buffer,  
   const wchar_t *format,  
   va_list arglist  
);  
```  
  
#### Parâmetros  
 `buffer`  
 Dados armazenados  
  
 `format`  
 Cadeia de caracteres de controle de formato.  Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md).  
  
 `arglist`  
 Lista de argumentos variável.  
  
## Valor de retorno  
 Cada uma dessas funções retorna o número de campos que com êxito são convertidos e atribuídos; o valor de retorno não inclui os campos que foram lidos mas não atribuídos.  Um valor de retorno 0 indica que nenhum campo foi atribuído.  O valor de retorno é `EOF` para um erro ou se o final da cadeia de caracteres for atingido antes da primeira conversão.  
  
 Se `buffer` ou `format` são um ponteiro nulo `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` a `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `vsscanf` lê os dados de `buffer` nos locais que são fornecidos por cada argumento na lista de argumentos `arglist`.  Na lista, cada argumento deve ser um ponteiro para uma variável com um tipo que corresponda a um especificador de tipo em `format`.  O argumento `format` controla a interpretação dos campos de entrada e tem o mesmo formulário e função que o argumento `format` para a função `scanf`.  Se a cópia for feita entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Quando você usa `vsscanf` para ler uma cadeia de caracteres, especifique sempre uma largura para o formato de `%s` \(por exemplo, `"%32s"` em vez de `"%s"`\); caso contrário, a entrada formatada incorretamente pode causar um estouro de buffer.  
  
 `vswscanf` é uma versão de caractere largo de `vsscanf`; os argumentos para `vswscanf` são cadeias de caractere amplo.  O `vsscanf` não trata caracteres hexadecimais de multibyte.  O `vswscanf` não trata caracteres hexadecimais de Unicode largos ou de "zona de compatibilidade".  Caso contrário, `vswscanf` e `vsscanf` se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vstscanf`|`vsscanf`|`vsscanf`|`vswscanf`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`vsscanf`|\<stdio.h\>|  
|`vswscanf`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_vsscanf.c  
// compile with: /W3  
// This program uses vsscanf to read data items  
// from a string named tokenstring, then displays them.  
  
#include <stdio.h>  
#include <stdarg.h>  
  
int call_vsscanf(char *tokenstring, char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vsscanf(tokenstring, format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int main( void )  
{  
    char  tokenstring[] = "15 12 14...";  
    char  s[81];  
    char  c;  
    int   i;  
    float fp;  
  
    // Input various data from tokenstring:  
    // max 80 character string:  
    call_vsscanf(tokenstring, "%80s", s);  
    call_vsscanf(tokenstring, "%c", &c);  
    call_vsscanf(tokenstring, "%d", &i);  
    call_vsscanf(tokenstring, "%f", &fp);  
  
    // Output the data read  
    printf("String    = %s\n", s);  
    printf("Character = %c\n", c);  
    printf("Integer:  = %d\n", i);  
    printf("Real:     = %f\n", fp);  
}  
```  
  
  **Cadeia de Caracteres    \= 15**  
**Caractere \= 1**  
**Inteiro: \= 15**  
**Real:     \= 15,000000**   
## Equivalência do .NET Framework  
 Consulte métodos de `Parse` , como [System::Double::Parse](https://msdn.microsoft.com/en-us/library/system.double.parse.aspx).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [vsscanf\_s, vswscanf\_s](../../c-runtime-library/reference/vsscanf-s-vswscanf-s.md)