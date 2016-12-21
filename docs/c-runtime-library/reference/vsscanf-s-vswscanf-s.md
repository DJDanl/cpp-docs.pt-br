---
title: "vsscanf_s, vswscanf_s | Microsoft Docs"
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
  - "vswscanf_s"
  - "vsscanf_s"
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
  - "vsscanf_s"
  - "vswscanf_s"
  - "_vstscanf_s"
dev_langs: 
  - "C++"
ms.assetid: 7b732e68-c6f4-4579-8917-122f5a7876e1
caps.latest.revision: 6
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsscanf_s, vswscanf_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados de uma cadeia de caracteres.  Essas versões de [vsscanf, vswscanf](../../c-runtime-library/reference/vsscanf-vswscanf.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int vsscanf_s(  
   const char *buffer,  
   const char *format,  
   va_list argptr  
);   
int vswscanf_s(  
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
  
 Se `buffer` ou `format` são um ponteiro nulo `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` a `EINVAL`  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `vsscanf_s` lê os dados de `buffer` nos locais que são fornecidos por cada argumento na lista de argumentos `arglist`.  Os argumentos na lista de argumentos, especificam ponteiros para variáveis que têm um tipo que corresponde um especificador de tipo no `format`.  Ao contrário da versão menos segura `vsscanf`, parâmetro de tamanho do buffer é necessário quando você usa os caracteres `c`, `C`, `s`, `S`, ou conjuntos de controle de cadeia de caracteres que estão incluídos no `[]`.  O tamanho do buffer em caracteres deve ser fornecido como um parâmetro adicional, imediatamente após cada parâmetro que o buffer requer.  
  
 O tamanho do buffer inclui a terminação nula.  Um campo de especificação de largura pode ser usado para garantir que o símbolo que é lido cabe no buffer.  Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado ao buffer.  
  
 Para obter mais informações, consulte [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md) e [Caracteres de campo de tipo scanf](../../c-runtime-library/scanf-type-field-characters.md).  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, e não `size_t`.  
  
 O argumento `format` controla a interpretação dos campos de entrada e tem o mesmo formulário e função que o argumento `format` para a função `scanf_s`.  Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 `vswscanf_s` é uma versão de caractere largo de `vsscanf_s`; os argumentos para `vswscanf_s` são cadeias de caractere amplo.  O `vsscanf_s` não trata caracteres hexadecimais de multibyte.  O `vswscanf_s` não trata caracteres hexadecimais de Unicode largos ou de "zona de compatibilidade".  Caso contrário, `vswscanf_s` e `vsscanf_s` se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vstscanf_s`|`vsscanf_s`|`vsscanf_s`|`vswscanf_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`vsscanf_s`|\<stdio.h\>|  
|`vswscanf_s`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_vsscanf_s.c  
// compile with: /W3  
// This program uses vsscanf_s to read data items  
// from a string named tokenstring, then displays them.  
  
#include <stdio.h>  
#include <stdarg.h>  
#include <stdlib.h>  
  
int call_vsscanf_s(char *tokenstring, char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vsscanf_s(tokenstring, format, arglist);  
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
    call_vsscanf_s(tokenstring, "%80s", s, _countof(s));  
    call_vsscanf_s(tokenstring, "%c", &c, sizeof(char));  
    call_vsscanf_s(tokenstring, "%d", &i);  
    call_vsscanf_s(tokenstring, "%f", &fp);  
  
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
 [sscanf\_s, \_sscanf\_s\_l, swscanf\_s, \_swscanf\_s\_l](../Topic/sscanf_s,%20_sscanf_s_l,%20swscanf_s,%20_swscanf_s_l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [vsscanf, vswscanf](../../c-runtime-library/reference/vsscanf-vswscanf.md)