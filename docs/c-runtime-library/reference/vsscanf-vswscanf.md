---
title: vsscanf, vswscanf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- vsscanf
- vswscanf
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- _vstscanf
- vsscanf
- vswscanf
dev_langs:
- C++
helpviewer_keywords:
- vswscanf function
- vsscanf function
ms.assetid: e96180f2-df46-423d-b4eb-0a49ab819bde
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 06c26fdeb5d63a446600bc288f99ca9cc903d002
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="vsscanf-vswscanf"></a>vsscanf, vswscanf
Lê dados formatados de uma cadeia de caracteres. Estão disponíveis versões mais seguras dessas funções; consulte [vsscanf_s, vswscanf_s](../../c-runtime-library/reference/vsscanf-s-vswscanf-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Dados armazenados  
  
 `format`  
 Cadeia de caracteres de controle de formato. Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).  
  
 `arglist`  
 Lista de argumentos variáveis.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna o número de campos que são convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será `EOF` para um erro ou se o fim da cadeia de caracteres for alcançado antes da primeira conversão.  
  
 Se `buffer` ou `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `vsscanf` lê dados de `buffer` nos locais fornecidos por cada argumento na lista de argumentos `arglist`. Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. O argumento `format` controla a interpretação dos campos de entrada e tem o mesmo formato e a mesma função que o argumento `format` para a função `scanf`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Quando você usa `vsscanf` para ler uma cadeia de caracteres, especifique sempre uma largura para o formato `%s` (por exemplo, `"%32s"` em vez de `"%s"`); caso contrário, entrada formatada incorretamente poderá causar um estouro de buffer.  
  
 `vswscanf` é uma versão de caractere largo de `vsscanf`; os argumentos para `vswscanf` são cadeias de caracteres largas. `vsscanf` não manipula caracteres hexadecimais multibyte. `vswscanf` não manipula hexadecimal de largura total do Unicode nem caracteres de "zona de compatibilidade". Caso contrário, `vswscanf` e `vsscanf` comportam-se de modo idêntico.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_vstscanf`|`vsscanf`|`vsscanf`|`vswscanf`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`vsscanf`|\<stdio.h>|  
|`vswscanf`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
String    = 15  
Character = 1  
Integer:  = 15  
Real:     = 15.000000  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [scanf, _scanf_l, wscanf, _wscanf_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, _sscanf_l, swscanf, _swscanf_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [vsscanf_s, vswscanf_s](../../c-runtime-library/reference/vsscanf-s-vswscanf-s.md)
