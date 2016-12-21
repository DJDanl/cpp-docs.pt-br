---
title: "vfscanf, vfwscanf | Microsoft Docs"
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
  - "vfwscanf"
  - "vfscanf"
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
  - "vfwscanf"
  - "_vftscanf"
  - "vfscanf"
dev_langs: 
  - "C++"
  - "C"
ms.assetid: c06450ef-03f1-4d24-a8ac-d2dd98847918
caps.latest.revision: 6
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vfscanf, vfwscanf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados de um fluxo.  Versões mais seguras dessas funções estão disponíveis; consulte [vfscanf\_s, vfwscanf\_s](../../c-runtime-library/reference/vfscanf-s-vfwscanf-s.md).  
  
## Sintaxe  
  
```  
int vfscanf(   
   FILE *stream,  
   const char *format,  
   va_list argptr   
);  
int vfwscanf(   
   FILE *stream,  
   const wchar_t *format,  
   va_list argptr   
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `arglist`  
 Lista de argumentos variável.  
  
## Valor de retorno  
 Cada uma dessas funções retorna o número de campos que com êxito são convertidos e atribuídos; o valor de retorno não inclui os campos que são lidos mas não atribuídos.  Um valor de retorno 0 indica que nenhum campo foi atribuído.  Se ocorrer um erro ou se o final do fluxo de arquivos for atingido antes da primeira conversão, o valor do retorno será `EOF` para `vfscanf` e `vfwscanf`.  
  
 Essas funções validam seus parâmetros.  Se `stream` ou `format` são um ponteiro nulo, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
## Comentários  
 A função `vfscanf` lê os dados da posição atual de `stream` nos locais que são fornecidos pela lista de argumento `arglist`.  Cada argumento da lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`.  `format` controla a interpretação dos campos de entrada e tem o mesmo formulário e função que o argumento `format` para `scanf`; consulte [scanf](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md) para obter uma descrição do `format`.  
  
 `vfwscanf` é uma versão de caractere largo de `vfscanf`; os argumentos de formato para `vfwscanf` referem\-se à cadeia de caracteres ampla.  Essas funções se comportam de forma idêntica se o fluxo for aberto no modo de ANSI.  `vfscanf` não oferece suporte a entrada de um fluxo de UNICODE.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vftscanf`|`vfscanf`|`vfscanf`|`vfwscanf`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`vfscanf`|\<stdio.h\>|  
|`vfwscanf`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_vfscanf.c  
// compile with: /W3  
// This program writes formatted  
// data to a file. It then uses vfscanf to  
// read the various data back from the file.  
  
#include <stdio.h>  
#include <stdarg.h>  
  
FILE *stream;  
  
int call_vfscanf(FILE * istream, char * format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vfscanf(istream, format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int main(void)  
{  
    long l;  
    float fp;  
    char s[81];  
    char c;  
  
    if (fopen_s(&stream, "vfscanf.out", "w+") != 0)  
    {  
        printf("The file vfscanf.out was not opened\n");  
    }  
    else  
    {  
        fprintf(stream, "%s %ld %f%c", "a-string",  
            65000, 3.14159, 'x');  
        // Security caution!  
        // Beware loading data from a file without confirming its size,  
        // as it may lead to a buffer overrun situation.  
  
        // Set pointer to beginning of file:  
        fseek(stream, 0L, SEEK_SET);  
  
        // Read data back from file:  
        call_vfscanf(stream, "%s %ld %f%c", s, &l, &fp, &c);  
  
        // Output data read:   
        printf("%s\n", s);  
        printf("%ld\n", l);  
        printf("%f\n", fp);  
        printf("%c\n", c);  
  
        fclose(stream);  
    }  
}  
  
```  
  
  **Cadeia de caracteres a**  
**65000**  
**3.141590**  
**x**   
## Equivalência do .NET Framework  
 [System::IO::StreamReader::ReadLine](https://msdn.microsoft.com/en-us/library/system.io.streamreader.readline.aspx). Consulte também métodos de `Parse` , como [System::Double::Parse](https://msdn.microsoft.com/en-us/library/system.double.parse.aspx).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_cscanf, \_cscanf\_l, \_cwscanf, \_cwscanf\_l](../../c-runtime-library/reference/cscanf-cscanf-l-cwscanf-cwscanf-l.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [fscanf\_s, \_fscanf\_s\_l, fwscanf\_s, \_fwscanf\_s\_l](../../c-runtime-library/reference/fscanf-s-fscanf-s-l-fwscanf-s-fwscanf-s-l.md)   
 [vfscanf\_s, vfwscanf\_s](../../c-runtime-library/reference/vfscanf-s-vfwscanf-s.md)