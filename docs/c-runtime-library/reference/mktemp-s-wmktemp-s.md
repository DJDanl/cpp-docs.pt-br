---
title: "_mktemp_s, _wmktemp_s | Microsoft Docs"
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
  - "_mktemp_s"
  - "_wmktemp_s"
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
  - "wmktemp_s"
  - "mktemp_s"
  - "_mktemp_s"
  - "_wmktemp_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mktemp_s"
  - "Função _tmktemp_s"
  - "Função _wmktemp_s"
  - "Arquivos  [C++], temporário"
  - "Função mktemp_s"
  - "arquivos temporários [C++]"
  - "Função tmktemp_s"
  - "Função wmktemp_s"
ms.assetid: 92a7e269-7f3d-4c71-bad6-14bc827a451d
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mktemp_s, _wmktemp_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um nome de arquivo exclusivo.  Essas são as versões de [\_mktemp, \_wmktemp](../../c-runtime-library/reference/mktemp-wmktemp.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _mktemp_s(  
   char *template,  
   size_t sizeInChars  
);  
errno_t _wmktemp_s(  
   wchar_t *template,  
   size_t sizeInChars  
);  
template <size_t size>  
errno_t _mktemp_s(  
   char (&template)[size]  
); // C++ only  
template <size_t size>  
errno_t _wmktemp_s(  
   wchar_t (&template)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 `template`  
 Padrão de nome de arquivo.  
  
 `sizeInChars`  
 Tamanho do buffer em caracteres de byte único em `_mktemp_s`; caracteres amplos em `_wmktemp_s`, incluindo o terminador nulo.  
  
## Valor de retorno  
 Retornam zero de ambas as funções no êxito; um código de erro da falha.  
  
### Condições de erro  
  
|`template`|`sizeInChars`|**valor de retorno**|**novo valor de no modelo**|  
|----------------|-------------------|--------------------------|---------------------------------|  
|`NULL`|any|`EINVAL`|`NULL`|  
|Formato incorreto \(consulte a seção de `Remarks` para o formato correto\)|any|`EINVAL`|cadeia de caracteres vazia|  
|any|\<\= número x|`EINVAL`|cadeia de caracteres vazia|  
  
 Se qualquer uma das condições de erro acima ocorrerem, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EINVAL` e as funções retornam `EINVAL`.  
  
## Comentários  
 A função de `_mktemp_s` cria um nome de arquivo exclusivo alterando o argumento de `template` , de modo que depois da chamada, o ponteiro de `template` a uma cadeia de caracteres que contém o novo nome do arquivo.  `_mktemp_s` controla automaticamente argumentos de cadeia de caracteres de multibyte\- caracteres conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código de multibyte atualmente em uso pelo sistema de tempo de execução.  `_wmktemp_s` é uma versão de ampla caractere de `_mktemp_s`; o argumento de `_wmktemp_s` é uma cadeia de caracteres de ampla caractere.  `_wmktemp_s` e `_mktemp_s` se comportam idêntica de outra forma, exceto que `_wmktemp_s` não trata as cadeias de caracteres de multibyte\- caractere.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tmktemp_s`|`_mktemp_s`|`_mktemp_s`|`_wmktemp_s`|  
  
 O argumento de `template` tem o formato `baseXXXXXX`, onde `base` é a parte do novo nome do arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por `_mktemp_s`.  Cada caractere de espaço reservado em `template` deve ser maiúsculo X.  `_mktemp_s` preserva `base` e substitui o primeiro X da direita com um caractere alfabético.  `_mktemp_s` substitui os seguintes x para a direita com um valor de cinco dígitos; esse valor é um número exclusivo que identifica o processo de chamada, ou em programas multi\-threaded, o thread de chamada.  
  
 Cada chamada bem\-sucedida a `_mktemp_s` altera `template`.  Em cada chamada subsequente do mesmo processo ou threads com o mesmo argumento de `template` , verificações de `_mktemp_s` para nomes de arquivo que correspondem aos nomes retornados por `_mktemp_s` em chamadas anteriores.  Se nenhum arquivo existir para um nome específico, `_mktemp_s` retorna esse nome.  Se os arquivos existe para todos os nomes anteriormente retornados, `_mktemp_s` cria um novo nome substituindo o caractere alfabético que usa o nome anteriormente retornado com a letra minúscula disponível seguinte, em ordem, “a” por “z”.  Por exemplo, se `base` é:  
  
```  
fn  
```  
  
 e o valor de cinco dígitos fornecido por `_mktemp_s` é 12345, o nome retornado é:  
  
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
  
 `_mktemp_s` pode criar um máximo de 26 nomes de arquivo exclusivos para qualquer determinada combinação de valores base e do modelo.  Consequentemente, FNZ12345 é o nome de arquivo exclusivo o último `_mktemp_s` pode criar para os valores de `base` e de `template` usados neste exemplo.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mktemp_s`|\<io.h\>|  
|`_wmktemp_s`|\<io.h ou\> wchar.h \<\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_mktemp_s.cpp  
/* The program uses _mktemp to create  
 * five unique filenames. It opens each filename  
 * to ensure that the next name is unique.  
 */  
  
#include <io.h>  
#include <string.h>  
#include <stdio.h>  
  
char *fnTemplate = "fnXXXXXX";  
char names[5][9];  
  
int main()  
{  
   int i, err, sizeInChars;  
   FILE *fp;  
  
   for( i = 0; i < 5; i++ )  
   {  
      strcpy_s( names[i], sizeof(names[i]), fnTemplate );  
      /* Get the size of the string and add one for the null terminator.*/  
      sizeInChars = strnlen(names[i], 9) + 1;  
      /* Attempt to find a unique filename: */  
      err = _mktemp_s( names[i], sizeInChars );  
      if( err != 0 )  
         printf( "Problem creating the template" );  
      else  
      {  
         if( fopen_s( &fp, names[i], "w" ) == 0 )  
            printf( "Unique filename is %s\n", names[i] );  
         else  
            printf( "Cannot open %s\n", names[i] );  
         fclose( fp );  
      }  
   }  
  
   return 0;  
}  
```  
  
## Saída de Exemplo  
  
```  
Unique filename is fna03188  
Unique filename is fnb03188  
Unique filename is fnc03188  
Unique filename is fnd03188  
Unique filename is fne03188  
```  
  
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
 [tmpfile\_s](../Topic/tmpfile_s.md)