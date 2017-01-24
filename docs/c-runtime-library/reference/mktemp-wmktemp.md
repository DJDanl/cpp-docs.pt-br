---
title: "_mktemp, _wmktemp | Microsoft Docs"
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
  - "_wmktemp"
  - "_mktemp"
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
  - "_tmktemp"
  - "wmktemp"
  - "tmktemp"
  - "_wmktemp"
  - "_mktemp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mktemp"
  - "Função _tmktemp"
  - "Função _wmktemp"
  - "Arquivos  [C++], temporário"
  - "Função mktemp"
  - "arquivos temporários [C++]"
  - "Função tmktemp"
  - "Função wmktemp"
ms.assetid: 055eb539-a8c2-4a7d-be54-f5b6d1eb5c85
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mktemp, _wmktemp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um nome de arquivo exclusivo.  Versões mais seguras dessas funções estão disponíveis; consulte [\_mktemp\_s, \_wmktemp\_s](../../c-runtime-library/reference/mktemp-s-wmktemp-s.md).  
  
## Sintaxe  
  
```  
char *_mktemp(  
   char *template   
);  
wchar_t *_wmktemp(  
   wchar_t *template   
);  
template <size_t size>  
char *_mktemp(  
   char (&template)[size]  
); // C++ only  
template <size_t size>  
wchar_t *_wmktemp(  
   wchar_t (&template)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 `template`  
 Padrão de nome de arquivo.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o modelo modificado.  A função retorna `NULL` se `template` é formado ruim ou não mais nome exclusivo pode ser criado no determinado modelo.  
  
## Comentários  
 A função de `_mktemp` cria um nome de arquivo exclusivo alterando o argumento de `template` .  `_mktemp` controla automaticamente argumentos de cadeia de caracteres de multibyte\- caracteres conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código de multibyte atualmente em uso pelo sistema de tempo de execução.  `_wmktemp` é uma versão de ampla caractere de `_mktemp`; o argumento e o valor de retorno de `_wmktemp` são cadeias de caracteres de ampla caractere.  `_wmktemp` e `_mktemp` se comportam idêntica de outra forma, exceto que `_wmktemp` não trata as cadeias de caracteres de multibyte\- caractere.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tmktemp`|`_mktemp`|`_mktemp`|`_wmktemp`|  
  
 O argumento de `template` tem o formato `base`XXXXXX, onde `base` é a parte do novo nome do arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por `_mktemp`.  Cada caractere de espaço reservado em `template` deve ser maiúsculo X.  `_mktemp` preserva `base` e substitui o primeiro X da direita com um caractere alfabético.  `_mktemp` substitui os seguintes x para a direita com um valor de cinco dígitos; esse valor é um número exclusivo que identifica o processo de chamada, ou em programas multi\-threaded, o thread de chamada.  
  
 Cada chamada bem\-sucedida a `_mktemp` altera `template`.  Em cada chamada subsequente do mesmo processo ou threads com o mesmo argumento de `template` , verificações de `_mktemp` para nomes de arquivo que correspondem aos nomes retornados por `_mktemp` em chamadas anteriores.  Se nenhum arquivo existir para um nome específico, `_mktemp` retorna esse nome.  Se os arquivos existe para todos os nomes anteriormente retornados, `_mktemp` cria um novo nome substituindo o caractere alfabético que usa o nome anteriormente retornado com a letra minúscula disponível seguinte, em ordem, “a” por “z”.  Por exemplo, se `base` é:  
  
```  
fn  
```  
  
 e o valor de cinco dígitos fornecido por `_mktemp` é 12345, o nome retornado é:  
  
```  
fna12345  
```  
  
 Se esse nome é usado para criar o arquivo FNA12345 e esse arquivo ainda existir, o nome do próximo retornado em uma chamada do mesmo processo ou thread com o mesmo `base` para `template` é:  
  
```  
fnb12345  
```  
  
 Se FNA12345 não existir, o nome seguir é retornado novamente:  
  
```  
fna12345  
```  
  
 `_mktemp` pode criar um máximo de 26 nomes de arquivo exclusivos para qualquer determinada combinação de valores base e do modelo.  Consequentemente, FNZ12345 é o nome de arquivo exclusivo o último `_mktemp` pode criar para os valores de `base` e de `template` usados neste exemplo.  
  
 Em caso de falha, `errno` é definido.  Se `template` tem um formato inválido \(por exemplo, menos de 6 x\), `errno` está definido como `EINVAL`.  Se `_mktemp` é não é possível criar um nome exclusivo porque todos os nomes de arquivos 26 possíveis já existirem, `_mktemp` define o modelo para uma cadeia de caracteres vazia e retorna `EEXIST`.  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mktemp`|\<io.h\>|  
|`_wmktemp`|\<io.h ou\> wchar.h \<\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_mktemp.c  
// compile with: /W3  
/* The program uses _mktemp to create  
 * unique filenames. It opens each filename  
 * to ensure that the next name is unique.  
 */  
  
#include <io.h>  
#include <string.h>  
#include <stdio.h>  
#include <errno.h>  
  
char *template = "fnXXXXXX";  
char *result;  
char names[27][9];  
  
int main( void )  
{  
   int i;  
   FILE *fp;  
  
   for( i = 0; i < 27; i++ )  
   {  
      strcpy_s( names[i], sizeof( names[i] ), template );  
      /* Attempt to find a unique filename: */  
      result = _mktemp( names[i] );  // C4996  
      // Note: _mktemp is deprecated; consider using _mktemp_s instead  
      if( result == NULL )  
      {  
         printf( "Problem creating the template\n" );  
         if (errno == EINVAL)  
         {  
             printf( "Bad parameter\n");  
         }  
         else if (errno == EEXIST)  
         {  
             printf( "Out of unique filenames\n");   
         }  
      }  
      else  
      {  
         fopen_s( &fp, result, "w" );  
         if( fp != NULL )  
            printf( "Unique filename is %s\n", result );  
         else  
            printf( "Cannot open %s\n", result );  
         fclose( fp );  
      }  
   }  
}  
```  
  
  **O nome de arquivo é exclusivo fna03912**  
**O nome de arquivo é exclusivo fnb03912**  
**O nome de arquivo é exclusivo fnc03912**  
**O nome de arquivo é exclusivo fnd03912**  
**O nome de arquivo é exclusivo fne03912**  
**O nome de arquivo é exclusivo fnf03912**  
**O nome de arquivo é exclusivo fng03912**  
**O nome de arquivo é exclusivo fnh03912**  
**O nome de arquivo é exclusivo fni03912**  
**O nome de arquivo é exclusivo fnj03912**  
**O nome de arquivo é exclusivo fnk03912**  
**O nome de arquivo é exclusivo fnl03912**  
**O nome de arquivo é exclusivo fnm03912**  
**O nome de arquivo é exclusivo fnn03912**  
**O nome de arquivo é exclusivo fno03912**  
**O nome de arquivo é exclusivo fnp03912**  
**O nome de arquivo é exclusivo fnq03912**  
**O nome de arquivo é exclusivo fnr03912**  
**O nome de arquivo é exclusivo fns03912**  
**O nome de arquivo é exclusivo fnt03912**  
**O nome de arquivo é exclusivo fnu03912**  
**O nome de arquivo é exclusivo fnv03912**  
**O nome de arquivo é exclusivo fnw03912**  
**O nome de arquivo é exclusivo fnx03912**  
**O nome de arquivo é exclusivo fny03912**  
**O nome de arquivo é exclusivo fnz03912**  
**Problema ao modelo.**  
**Fora dos nomes de arquivo exclusivos.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [\_getpid](../Topic/_getpid.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [\_tempnam, \_wtempnam, tmpnam, \_wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)   
 [tmpfile](../../c-runtime-library/reference/tmpfile.md)