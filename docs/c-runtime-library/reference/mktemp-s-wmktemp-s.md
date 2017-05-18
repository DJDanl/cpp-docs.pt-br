---
title: _mktemp_s, _wmktemp_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mktemp_s
- _wmktemp_s
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
- wmktemp_s
- mktemp_s
- _mktemp_s
- _wmktemp_s
dev_langs:
- C++
helpviewer_keywords:
- _tmktemp_s function
- mktemp_s function
- _wmktemp_s function
- _mktemp_s function
- files [C++], temporary
- tmktemp_s function
- wmktemp_s function
- temporary files [C++]
ms.assetid: 92a7e269-7f3d-4c71-bad6-14bc827a451d
caps.latest.revision: 23
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
ms.openlocfilehash: 6231031dd0bbc5b455e3555731f711ee7de971e7
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="mktemps-wmktemps"></a>_mktemp_s, _wmktemp_s
Cria um nome de arquivo exclusivo. Estas são versões de [_mktemp, _wmktemp](../../c-runtime-library/reference/mktemp-wmktemp.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `template`  
 Padrão de nome de arquivo.  
  
 `sizeInChars`  
 Tamanho do buffer em caracteres de byte único no `_mktemp_s`, caracteres largos em `_wmktemp_s`, incluindo o terminador nulo.  
  
## <a name="return-value"></a>Valor de retorno  
 Ambas as funções retornam zero em caso de êxito, um código de erro em caso de falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`template`|`sizeInChars`|**valor retornado**|**novo valor no modelo**|  
|----------------|-------------------|----------------------|-------------------------------|  
|`NULL`|qualquer|`EINVAL`|`NULL`|  
|Formato incorreto (consulte a seção `Remarks` para o formato correto)|qualquer|`EINVAL`|cadeia de caracteres vazia|  
|qualquer|<= número de X's|`EINVAL`|cadeia de caracteres vazia|  
  
 Se qualquer uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e as funções retornarão `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_mktemp_s` cria um nome de arquivo exclusivo modificando o argumento `template`, para que depois da chamada o ponteiro `template` aponte para uma cadeia de caracteres que contém o novo nome de arquivo. `_mktemp_s` manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte que está sendo usada no momento pelo sistema de tempo de execução. `_wmktemp_s` é uma versão de caractere largo de `_mktemp_s`, o argumento de `_wmktemp_s` é uma cadeia de caracteres largos. `_wmktemp_s` e `_mktemp_s` têm comportamento idêntico, caso contrário, exceto pelo fato de que `_wmktemp_s` não manipula cadeias de caracteres multibyte.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tmktemp_s`|`_mktemp_s`|`_mktemp_s`|`_wmktemp_s`|  
  
 O argumento `template` tem o formato `baseXXXXXX`, em que `base` é a parte do novo nome de arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido pelo `_mktemp_s`. Cada caractere de espaço reservado em `template` deve ser um X maiúsculo. `_mktemp_s` preserva `base` e substitui o primeiro X à direita por um caractere alfabético. `_mktemp_s` substitui o seguinte X à direita por um valor de cinco dígitos, esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.  
  
 Cada chamada bem-sucedida para `_mktemp_s` modifica `template`. Em cada chamada subsequente do mesmo processo ou thread com o mesmo argumento `template`, `_mktemp_s` verifica os nomes de arquivos que correspondem aos nomes retornados por `_mktemp_s` em chamadas anteriores. Se não existir nenhum arquivo para um determinado nome, `_mktemp_s` retornará esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, o `_mktemp_s` criará um novo nome substituindo o caractere alfabético que ele usou no nome retornado anteriormente pela próxima letra em minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se `base` for:  
  
```  
fn  
```  
  
 e o valor de cinco dígitos fornecido pelo `_mktemp_s` for 12345, o primeiro nome retornado será:  
  
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
  
 `_mktemp_s` pode criar no máximo 26 nomes de arquivo exclusivos para qualquer determinada combinação de valores de base e o modelo. Portanto, FNZ12345 é o último nome de arquivo exclusivo que `_mktemp_s` pode criar para os valores `base` e `template` usados neste exemplo.  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mktemp_s`|\<io.h>|  
|`_wmktemp_s`|\<io.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
Unique filename is fna03188  
Unique filename is fnb03188  
Unique filename is fnc03188  
Unique filename is fnd03188  
Unique filename is fne03188  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [_getpid](../../c-runtime-library/reference/getpid.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [_tempnam, _wtempnam, tmpnam, _wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)   
 [tmpfile_s](../../c-runtime-library/reference/tmpfile-s.md)
