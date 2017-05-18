---
title: _tempnam, _wtempnam, tmpnam, _wtmpnam | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wtempnam
- _wtmpnam
- tmpnam
- _tempnam
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
- wtempnam
- _wtmpnam
- wtmpnam
- tmpnam
- _wtempnam
- _tempnam
dev_langs:
- C++
helpviewer_keywords:
- wtempnam function
- file names [C++], creating temporary
- _tempnam function
- ttmpnam function
- tmpnam function
- tempnam function
- wtmpnam function
- temporary files, creating
- file names [C++], temporary
- _ttmpnam function
- _wtmpnam function
- _wtempnam function
ms.assetid: 3ce75f0f-5e30-42a6-9791-8d7cbfe70fca
caps.latest.revision: 20
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 0600d44b2b87ed3bb56e7d1c64fffd762e77aff2
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="tempnam-wtempnam-tmpnam-wtmpnam"></a>_tempnam, _wtempnam, tmpnam, _wtmpnam
Gere nomes que podem ser usados para criar arquivos temporários. Versões mais seguras de algumas dessas funções estão disponíveis; consulte [tmpnam_s, _wtmpnam_s](../../c-runtime-library/reference/tmpnam-s-wtmpnam-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_tempnam(  
   const char *dir,  
   const char *prefix   
);  
wchar_t *_wtempnam(  
   const wchar_t *dir,  
   const wchar_t *prefix   
);  
char *tmpnam(  
   char *str   
);  
wchar_t *_wtmpnam(  
   wchar_t *str   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `prefix`  
 A cadeia de caracteres que será pré-anexada a nomes retornados pelo `_tempnam`.  
  
 `dir`  
 O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.  
  
 `str`  
 Ponteiro que conterá o nome gerado e será idêntico ao nome retornado pela função. Essa é uma maneira conveniente de salvar o nome gerado.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o nome gerado ou `NULL` no caso de uma falha. Falha pode ocorrer se você tentar mais de `TMP_MAX` (consulte STDIO. H) chamadas com `tmpnam` ou se você usar `_tempnam` e há um nome de diretório inválido especificado na variável de ambiente TMP e no `dir` parâmetro.  
  
> [!NOTE]
>  Os ponteiros retornados por `tmpnam` e `_wtmpnam` apontam para buffers estáticos internos. [free](../../c-runtime-library/reference/free.md) não deve ser chamado para desalocar esses ponteiros. `free` precisa ser chamado para ponteiros alocados por `_tempnam` e `_wtempnam`.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções retorna o nome de um arquivo que não existe no momento. `tmpnam` retorna um nome exclusivo no diretório de trabalho atual e `_tempnam` permite gerar um nome exclusivo em um diretório diferente do atual. Observe que quando um nome de arquivo é precedido por uma barra invertida e nenhuma informação de caminho, como \fname21, isso indica que o nome é válido para o diretório de trabalho atual.  
  
 Para `tmpnam`, é possível armazenar esse nome de arquivo gerado em `str`. Se `str` for `NULL`, `tmpnam` deixará o resultado em um buffer estático interno. Portanto, todas as chamadas posteriores destroem esse valor. O nome gerado por `tmpnam` consiste em um nome de arquivo gerado pelo programa e, após a primeira chamada a `tmpnam`, uma extensão de arquivo de números sequenciais em base 32 (.1-.vvu quando `TMP_MAX` em STDIO.H é 32.767).  
  
 `_tempnam` gerará um nome de arquivo exclusivo para um diretório escolhido pelas seguintes regras:  
  
-   Se a variável de ambiente TMP for definida com um nome de diretório válido, nomes de arquivo exclusivos serão gerados para o diretório especificado por TMP.  
  
-   Se a variável de ambiente TMP não for definida ou se for definida com o nome de um diretório que não existe, `_tempnam` usará o parâmetro `dir` como o caminho para o qual ele gerará nomes exclusivos.  
  
-   Se a variável de ambiente TMP não for definida ou se for definida com o nome de um diretório que não existe e se `dir` for `NULL` ou for definido com o nome de um diretório que não existe, `_tempnam` usará o diretório de trabalho atual para gerar nomes exclusivos. Atualmente, se TMP e `dir` especificarem nomes de diretórios que não existem, a chamada de função `_tempnam` falhará.  
  
 O nome retornado por `_tempnam` será uma concatenação de `prefix` e um número sequencial, que serão combinados para criar um nome de arquivo exclusivo para o diretório especificado. `_tempnam` gera nomes de arquivo que não tem nenhuma extensão. `_tempnam` usa [malloc](../../c-runtime-library/reference/malloc.md) para alocar espaço ao nome do arquivo; o programa é responsável por liberar esse espaço quando ele não é mais necessário.  
  
 `_tempnam` e `tmpnam` manipulam automaticamente argumentos da cadeia de caracteres multibyte conforme apropriado, reconhecendo as sequências de caracteres multibyte de acordo com a página de código do OEM obtida do sistema operacional. `_wtempnam` é uma versão de caractere largo de `_tempnam`; os argumentos e o valor retornado de `_wtempnam` são cadeias de caracteres largos. `_wtempnam` e `_tempnam` têm comportamento idêntico, exceto pelo fato de que `_wtempnam` não manipula cadeias de caracteres multibyte. `_wtmpnam` é uma versão de caractere largo de `tmpnam`; o argumento e o valor retornado de `_wtmpnam` são cadeias de caracteres largos. `_wtmpnam` e `tmpnam` têm comportamento idêntico, exceto pelo fato de que `_wtmpnam` não manipula cadeias de caracteres multibyte.  
  
 Se `_DEBUG` e `_CRTDBG_MAP_ALLOC` forem definidos, `_tempnam` e `_wtempnam` serão substituídos por chamadas a [_tempnam_dbg e _wtempnam_dbg](../../c-runtime-library/reference/tempnam-dbg-wtempnam-dbg.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_ttmpnam`|`tmpnam`|`tmpnam`|`_wtmpnam`|  
|`_ttempnam`|`_tempnam`|`_tempnam`|`_wtempnam`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_tempnam`|\<stdio.h>|  
|`_wtempnam`, `_wtmpnam`|\<stdio.h> ou \<wchar.h>|  
|`tmpnam`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_tempnam.c  
// compile with: /W3  
// This program uses tmpnam to create a unique filename in the  
// current working directory, then uses _tempnam to create   
// a unique filename with a prefix of stq.   
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{     
   char* name1 = NULL;  
   char* name2 = NULL;  
  
   // Create a temporary filename for the current working directory:   
   if( ( name1 = tmpnam( NULL ) ) != NULL ) // C4996  
   // Note: tmpnam is deprecated; consider using tmpnam_s instead  
      printf( "%s is safe to use as a temporary file.\n", name1 );  
   else  
      printf( "Cannot create a unique filename\n" );  
  
   // Create a temporary filename in temporary directory with the  
   // prefix "stq". The actual destination directory may vary  
   // depending on the state of the TMP environment variable and  
   // the global variable P_tmpdir.     
  
   if( ( name2 = _tempnam( "c:\\tmp", "stq" ) ) != NULL )  
      printf( "%s is safe to use as a temporary file.\n", name2 );   
   else  
      printf( "Cannot create a unique filename\n" );  
  
   // When name2 is no longer needed :     
   if(name2)  
     free(name2);  
  
}  
```  
  
```Output  
\s1gk. is safe to use as a temporary file.  
C:\DOCUME~1\user\LOCALS~1\Temp\2\stq2 is safe to use as a temporary file.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [tmpfile](../../c-runtime-library/reference/tmpfile.md)   
 [tmpfile_s](../../c-runtime-library/reference/tmpfile-s.md)
