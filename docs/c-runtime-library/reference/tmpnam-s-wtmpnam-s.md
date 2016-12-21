---
title: "tmpnam_s, _wtmpnam_s | Microsoft Docs"
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
  - "tmpnam_s"
  - "_wtmpnam_s"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "tmpnam_s"
  - "_wtmpnam_s"
  - "L_tmpnam_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _wtmpnam_s"
  - "nomes de arquivos [C++], criando temporário"
  - "nomes de arquivos [C++], temporário"
  - "Constante L_tmpnam_s"
  - "arquivos temporários, criando"
  - "Função tmpnam_s"
  - "Função wtmpnam_s"
ms.assetid: e70d76dc-49f5-4aee-bfa2-f1baa2bcd29f
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# tmpnam_s, _wtmpnam_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia nomes que você pode usar para criar arquivos temporários.  Essas são versões de [tmpnam e \_wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t tmpnam_s(  
   char * str,  
   size_t sizeInChars   
);  
errno_t _wtmpnam_s(  
   wchar_t *str,  
   size_t sizeInChars   
);  
template <size_t size>  
errno_t tmpnam_s(  
   char (&str)[size]  
); // C++ only  
template <size_t size>  
errno_t _wtmpnam_s(  
   wchar_t (&str)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `str`  
 Ponteiro que conterá o nome gerado.  
  
 \[entrada\] `sizeInChars`  
 O tamanho do buffer em caracteres.  
  
## Valor de retorno  
 Essas duas funções retornam 0 se bem\-sucedido ou um número de erro de falha.  
  
### Condições de erro  
  
|||||  
|-|-|-|-|  
|`str`|`sizeInChars`|**Valor de Retorno**|**Contents of**  `str`|  
|`NULL`|any|`EINVAL`|não modificado|  
|não `NULL` \(pontos para a memória válido\)|muito curto|`ERANGE`|não modificado|  
  
 Se `str` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
## Comentários  
 Cada uma dessas funções retorna o nome de um arquivo que não existe no momento.  `tmpnam_s` retorna um nome exclusivo no diretório de trabalho atual.  A observe que quando um nome de arquivo pre\-pended com uma barra invertida e nenhuma informação de caminho, como \\ fname21, isso indicará que o nome é válido para o diretório de trabalho atual.  
  
 Para `tmpnam_s`, você pode armazenar este nome de arquivo gerado em `str`.  O comprimento máximo de uma cadeia de caracteres retornada por `tmpnam_s` é `L_tmpnam_s`, definido em. STDIO.H.  Se `str` é `NULL`, então `tmpnam_s` permite que o resultado em um buffer interno estático.  Para todas as chamadas subsequentes destroem esse valor.  O nome gerado por `tmpnam_s` consiste em um nome de arquivo gerado por programa e, depois da primeira chamada a `tmpnam_s`, uma extensão de arquivo de números sequenciais na base 32 \(.1\-.1vvvvvu, quando `TMP_MAX_S` em STDIO.H é INT\_MAX\).  
  
 `tmpnam_s` controla automaticamente argumentos de cadeia de caracteres de multibyte\- caracteres conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código OEM obtida do sistema operacional.  `_wtmpnam_s` é uma versão de ampla caractere de `tmpnam_s`; o argumento e o valor de retorno de `_wtmpnam_s` são cadeias de caracteres de ampla caractere.  `_wtmpnam_s` e `tmpnam_s` se comportam idêntica exceto que `_wtmpnam_s` não trata as cadeias de caracteres de multibyte\- caractere.  
  
 No C\+\+, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_ttmpnam_s`|`tmpnam_s`|`tmpnam_s`|`_wtmpnam_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`tmpnam_s`|\<stdio.h\>|  
|`_wtmpnam_s`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_tmpnam_s.c  
// This program uses tmpnam_s to create a unique filename in the  
// current working directory.   
//  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{     
   char name1[L_tmpnam_s];  
   errno_t err;  
   int i;  
  
   for (i = 0; i < 15; i++)  
   {  
      err = tmpnam_s( name1, L_tmpnam_s );  
      if (err)  
      {  
         printf("Error occurred creating unique filename.\n");  
         exit(1);  
      }  
      else  
      {  
         printf( "%s is safe to use as a temporary file.\n", name1 );  
      }  
   }    
}  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [tmpfile\_s](../Topic/tmpfile_s.md)