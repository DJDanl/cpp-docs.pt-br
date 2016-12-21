---
title: "_tempnam, _wtempnam, tmpnam, _wtmpnam | Microsoft Docs"
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
  - "_wtempnam"
  - "_wtmpnam"
  - "tmpnam"
  - "_tempnam"
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
  - "wtempnam"
  - "_wtmpnam"
  - "wtmpnam"
  - "tmpnam"
  - "_wtempnam"
  - "_tempnam"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tempnam"
  - "Função _ttmpnam"
  - "Função _wtempnam"
  - "Função _wtmpnam"
  - "nomes de arquivos [C++], criando temporário"
  - "nomes de arquivos [C++], temporário"
  - "Função tempnam"
  - "arquivos temporários, criando"
  - "Função tmpnam"
  - "Função ttmpnam"
  - "Função wtempnam"
  - "Função wtmpnam"
ms.assetid: 3ce75f0f-5e30-42a6-9791-8d7cbfe70fca
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _tempnam, _wtempnam, tmpnam, _wtmpnam
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia nomes que você pode usar para criar arquivos temporários.  Versões mais seguras de algumas dessas funções estão disponíveis; consulte [tmpnam\_s, \_wtmpnam\_s](../../c-runtime-library/reference/tmpnam-s-wtmpnam-s.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `prefix`  
 A cadeia de caracteres que pre\-pended aos nomes retornado por `_tempnam`.  
  
 `dir`  
 O caminho usado no nome do arquivo se não houver nenhuma variável de ambiente de TMP, ou se TMP não é um diretório válido.  
  
 `str`  
 Ponteiro que conterá o nome gerado e será idêntico ao nome retornado pela função.  Essa é uma maneira conveniente de salvar o nome gerado.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o nome gerado ou a `NULL` se houver uma falha.  A falha pode ocorrer se você tentar mais do que `TMP_MAX` \(consulte\) STDIO.H chama com `tmpnam` ou se você usar `_tempnam`e há um nome de diretório inválido especificado na variável de ambiente e TMP do parâmetro de `dir` .  
  
> [!NOTE]
>  Os ponteiros retornados por `tmpnam` e pelo ponto de `_wtmpnam` aos buffers internos estáticos.  [livre](../../c-runtime-library/reference/free.md) não deve ser chamado para desalocar os ponteiros.  `free` precisa ser chamado para os ponteiros atribuídos por `_tempnam` e por `_wtempnam`.  
  
## Comentários  
 Cada uma dessas funções retorna o nome de um arquivo que não existe no momento.  `tmpnam` retorna um nome exclusivo no diretório de trabalho atual e `_tempnam` permite gerar um nome exclusivo em um diretório diferente atual.  A observe que quando um nome de arquivo pre\-pended com uma barra invertida e nenhuma informação de caminho, como \\ fname21, isso indicará que o nome é válido para o diretório de trabalho atual.  
  
 Para `tmpnam`, você pode armazenar este nome de arquivo gerado em `str`.  Se `str` é `NULL`, então `tmpnam` permite que o resultado em um buffer interno estático.  Para todas as chamadas subsequentes destroem esse valor.  O nome gerado por `tmpnam` consiste em um nome de arquivo gerado por programa e, depois da primeira chamada a `tmpnam`, uma extensão de arquivo de números sequenciais na base 32 \(.1\-.vvu, quando `TMP_MAX` em STDIO.H é 32.767\).  
  
 `_tempnam` gerará um nome de arquivo exclusivo para um diretório escolhido por seguintes regras:  
  
-   Se a variável de ambiente de TMP é definido e definido como um nome de diretório válido, os nomes de arquivo exclusivos serão gerados para o diretório especificado por TMP.  
  
-   Se a variável de ambiente de TMP não é definido ou se for definido como o nome de um diretório que não existe, `_tempnam` usará o parâmetro de `dir` como o caminho para que gerará nomes exclusivos.  
  
-   Se a variável de ambiente de TMP não é definido ou se for definido como o nome de um diretório que não existe, e se `dir` é `NULL` ou defina como o nome de um diretório que não existe, `_tempnam` usará o diretório de trabalho atual para gerar nomes exclusivos.  Atualmente, se TMP e nomes de diretórios `dir` especificam que não existem, a chamada da função de `_tempnam` falhará.  
  
 O nome retornado por `_tempnam` será uma concatenação de `prefix` e um número sequencial, que combina para criar um nome de arquivo exclusivo para o diretório especificado.  `_tempnam` gerencia os nomes de arquivo que não têm nenhuma extensão.  `_tempnam` usa [malloc](../../c-runtime-library/reference/malloc.md) para alocar espaço para o nome do arquivo; o programa é responsável para liberar esse espaço quando ele não for mais necessário.  
  
 `_tempnam` e de `tmpnam` argumentos de cadeia de caracteres de multibyte\- caractere de identificador automaticamente conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código OEM obtida do sistema operacional.  `_wtempnam` é uma versão de ampla caractere de `_tempnam`; os argumentos e o valor de retorno de `_wtempnam` são cadeias de caracteres de ampla caractere.  `_wtempnam` e `_tempnam` se comportam idêntica exceto que `_wtempnam` não trata as cadeias de caracteres de multibyte\- caractere.  `_wtmpnam` é uma versão de ampla caractere de `tmpnam`; o argumento e o valor de retorno de `_wtmpnam` são cadeias de caracteres de ampla caractere.  `_wtmpnam` e `tmpnam` se comportam idêntica exceto que `_wtmpnam` não trata as cadeias de caracteres de multibyte\- caractere.  
  
 Se `_DEBUG` e `_CRTDBG_MAP_ALLOC` são definidos, `_tempnam` e `_wtempnam` são substituídos por chamadas a [\_tempnam\_dbg e \_wtempnam\_dbg](../../c-runtime-library/reference/tempnam-dbg-wtempnam-dbg.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_ttmpnam`|`tmpnam`|`tmpnam`|`_wtmpnam`|  
|`_ttempnam`|`_tempnam`|`_tempnam`|`_wtempnam`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_tempnam`|\<stdio.h\>|  
|`_wtempnam`, `_wtmpnam`|\<stdio.h\> ou \<wchar.h\>|  
|`tmpnam`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
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
  
  **\\ s1gk. é seguro de usar como um arquivo temporário.**  
**C:\\DOCUME~1\\user\\LOCALS~1\\Temp\\2\\stq2 é seguro de usar como um arquivo temporário.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [tmpfile](../../c-runtime-library/reference/tmpfile.md)   
 [tmpfile\_s](../Topic/tmpfile_s.md)