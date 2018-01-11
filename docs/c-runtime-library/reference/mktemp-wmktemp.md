---
title: _mktemp, _wmktemp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wmktemp
- _mktemp
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tmktemp
- wmktemp
- tmktemp
- _wmktemp
- _mktemp
dev_langs: C++
helpviewer_keywords:
- _wmktemp function
- _mktemp function
- files [C++], temporary
- tmktemp function
- _tmktemp function
- wmktemp function
- mktemp function
- temporary files [C++]
ms.assetid: 055eb539-a8c2-4a7d-be54-f5b6d1eb5c85
caps.latest.revision: "25"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ac2fd19254cce03b7cd7efc4324f5dc03c608b7a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mktemp-wmktemp"></a>_mktemp, _wmktemp
Cria um nome de arquivo exclusivo. Estão disponíveis versões mais seguras dessas funções; consulte [_mktemp_s, _wmktemp_s](../../c-runtime-library/reference/mktemp-s-wmktemp-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `template`  
 Padrão de nome de arquivo.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o modelo modificado. A função retorna `NULL` se `template` está mal formado ou não é possível criar mais nomes exclusivos com base no modelo.  
  
## <a name="remarks"></a>Comentários  
 A função `_mktemp` cria um nome de arquivo exclusivo modificando o argumento `template`. `_mktemp` manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte que está sendo usada no momento pelo sistema de tempo de execução. `_wmktemp` é uma versão de caractere largo de `_mktemp`; o argumento e o valor retornado de `_wmktemp` são cadeias de caracteres largos. `_wmktemp` e `_mktemp` têm comportamento idêntico, caso contrário, exceto pelo fato de que `_wmktemp` não manipula cadeias de caracteres multibyte.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tmktemp`|`_mktemp`|`_mktemp`|`_wmktemp`|  
  
 O `template` argumento tem o formato `base` *XXXXXX*, onde `base` é a parte do novo nome do arquivo que você fornecer e cada X é um espaço reservado para um caractere fornecido pelo `_mktemp`. Cada caractere de espaço reservado em `template` deve ser um X maiúsculo. `_mktemp` preserva `base` e substitui o primeiro X à direita por um caractere alfabético. `_mktemp` substitui o seguinte X à direita por um valor de cinco dígitos, esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.  
  
 Cada chamada bem-sucedida para `_mktemp` modifica `template`. Em cada chamada subsequente do mesmo processo ou thread com o mesmo argumento `template`, `_mktemp` verifica os nomes de arquivos que correspondem aos nomes retornados por `_mktemp` em chamadas anteriores. Se não existir nenhum arquivo para um determinado nome, `_mktemp` retornará esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, o `_mktemp` criará um novo nome substituindo o caractere alfabético que ele usou no nome retornado anteriormente pela próxima letra em minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se `base` for:  
  
```  
fn  
```  
  
 e o valor de cinco dígitos fornecido pelo `_mktemp` for 12345, o primeiro nome retornado será:  
  
```  
fna12345  
```  
  
 Se esse nome for usado para criar o arquivo FNA12345 e esse nome de arquivo já existir, o próximo nome retornado em uma chamada do mesmo processo ou thread com o mesmo `base` para `template` será:  
  
```  
fnb12345  
```  
  
 Se FNA12345 não existir, o próximo nome retornado será novamente:  
  
```  
fna12345  
```  
  
 `_mktemp` pode criar no máximo 26 nomes de arquivo exclusivos para qualquer determinada combinação de valores de base e o modelo. Portanto, FNZ12345 é o último nome de arquivo exclusivo que `_mktemp` pode criar para os valores `base` e `template` usados neste exemplo.  
  
 Em caso de falha, `errno` é definido. Se `template` tiver um formato inválido (por exemplo, menos de 6 X), `errno` será definido como `EINVAL`. Se `_mktemp` não puder criar um nome exclusivo porque todos os 26 nomes de arquivo possíveis já existem, o `_mktemp` definirá o modelo como uma cadeia de caracteres vazia e retornará `EEXIST`.  
  
 No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mktemp`|\<io.h>|  
|`_wmktemp`|\<io.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
Unique filename is fna03912  
Unique filename is fnb03912  
Unique filename is fnc03912  
Unique filename is fnd03912  
Unique filename is fne03912  
Unique filename is fnf03912  
Unique filename is fng03912  
Unique filename is fnh03912  
Unique filename is fni03912  
Unique filename is fnj03912  
Unique filename is fnk03912  
Unique filename is fnl03912  
Unique filename is fnm03912  
Unique filename is fnn03912  
Unique filename is fno03912  
Unique filename is fnp03912  
Unique filename is fnq03912  
Unique filename is fnr03912  
Unique filename is fns03912  
Unique filename is fnt03912  
Unique filename is fnu03912  
Unique filename is fnv03912  
Unique filename is fnw03912  
Unique filename is fnx03912  
Unique filename is fny03912  
Unique filename is fnz03912  
Problem creating the template.  
Out of unique filenames.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [_getpid](../../c-runtime-library/reference/getpid.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [_tempnam, _wtempnam, tmpnam, _wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)   
 [tmpfile](../../c-runtime-library/reference/tmpfile.md)