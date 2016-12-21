---
title: "_mbsnbset, _mbsnbset_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbsnbset"
  - "_mbsnbset_l"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbsnbset"
  - "mbsnbset_l"
  - "_mbsnbset"
  - "_mbsnbset_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbset"
  - "Função _mbsnbset_l"
  - "Função _tcsnset"
  - "Função _tcsnset_l"
  - "Função mbsnbset"
  - "Função mbsnbset_l"
  - "Função tcsnset"
  - "Função tcsnset_l"
ms.assetid: 8e46ef75-9a56-42d2-a522-a08450c67c19
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbset, _mbsnbset_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Defina os primeiros bytes `n` de uma cadeia de caracteres multibyte como um caractere especificado.  Versões mais seguras dessas funções estão disponíveis; consulte [\_mbsnbset\_s, \_mbsnbset\_s\_l](../../c-runtime-library/reference/mbsnbset-s-mbsnbset-s-l.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
unsigned char *_mbsnbset(  
   unsigned char *str,  
   unsigned int c,  
   size_t count   
);  
unsigned char *_mbsnbset_l(  
   unsigned char *str,  
   unsigned int c,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres a ser alterada.  
  
 `c`  
 Configuração de caractere de byte único ou multibyte.  
  
 `count`  
 Número de bytes a serem definidos.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_mbsnbset` retorna um ponteiro para a cadeia de caracteres alterada.  
  
## Comentários  
 As funções `_mbsnbset` e `_mbsnbset_l` definem, no máximo, os primeiros `count` bytes de `str` para `c`.  Se `count` for maior que o tamanho de `str`, o tamanho de `str` será usado no lugar de `count`.  Se `c` for um caractere de multibyte e não puder ser definido completamente no último byte especificado por `count`, o último byte será preenchido com um caractere em branco.  `_mbsnbset` e `_mbsnbset_l`não colocam um nulo de conclusão no final de `str`.  
  
 `_mbsnbset` e `_mbsnbset_l`são semelhantes a `_mbsnset`, exceto que define os bytes de `count` em vez de caracteres`count` de `c`.  
  
 Se `str` for `NULL` ou `count` for zero, essa função gerará uma exceção de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  Além disso, se `c` não for um caractere multibyte válido, `errno` será definido como `EINVAL` e será usado um espaço no lugar.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  A versão `_mbsnbset` dessa função usa o local atual para esse comportamento dependente de local; a versão `_mbsnbset_l` é idêntica, exceto pelo fato de que ela usa o parâmetro de local transmitido.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 **Observação de segurança** Esta API resulta em uma potencial ameaça causada por um problema de estouro de buffer.  Problemas de saturação de buffer é um método frequente de ataque do sistema, resultando em elevação injustificável de privilégio.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnset`|`_strnset`|`_mbsnbset`|`_wcsnset`|  
|`_tcsnset_l`|`_strnset_l`|`_mbsnbset_l`|`_wcsnset_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbset`|\<mbstring.h\>|  
|`_mbsnbset_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_mbsnbset.c  
// compile with: /W3  
#include <mbstring.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[15] = "This is a test";  
   /* Set not more than 4 bytes of string to be *'s */  
   printf( "Before: %s\n", string );  
   _mbsnbset( string, '*', 4 ); // C4996  
   // Note; _mbsnbset is deprecated; consider _mbsnbset_s  
   printf( "After:  %s\n", string );  
}  
```  
  
## Saída  
  
```  
Before: This is a test  
After:  **** is a test  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcat, \_mbsnbcat\_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [\_strnset, \_strnset\_l, \_wcsnset, \_wcsnset\_l, \_mbsnset, \_mbsnset\_l](../../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)