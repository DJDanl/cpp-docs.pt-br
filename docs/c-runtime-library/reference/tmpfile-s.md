---
title: tmpfile_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- tmpfile_s
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
- tmpfile_s
dev_langs:
- C++
helpviewer_keywords:
- temporary files
- tmpfile_s function
- temporary files, creating
ms.assetid: 50879c69-215e-425a-a2a3-8b5467121eae
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: e66ffa5fdbb1785191865eba92c9d673fb847ada
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="tmpfiles"></a>tmpfile_s
Cria um arquivo temporário. Trata-se de uma versão de [tmpfile](../../c-runtime-library/reference/tmpfile.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t tmpfile_s(  
   FILE** pFilePtr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pFilePtr`  
 O endereço de um ponteiro para armazenar o endereço do ponteiro gerado em um fluxo.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornará 0 se for bem-sucedido; um código de erro em caso de falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`pFilePtr`|**Valor retornado**|**Conteúdo de**  `pFilePtr`|  
|----------------|----------------------|---------------------------------|  
|`NULL`|`EINVAL`|não alterado|  
  
 Se ocorrer o erro de validação de parâmetro acima, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e o valor retornado será `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `tmpfile_s` cria um arquivo temporário e coloca um ponteiro nesse fluxo no argumento `pFilePtr`. O arquivo temporário é criado no diretório raiz. Para criar um arquivo temporário em um diretório que não seja a raiz, use [tmpnam_s](../../c-runtime-library/reference/tmpnam-s-wtmpnam-s.md) ou [tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) em conjunto com [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
 Se não for possível abrir o arquivo, `tmpfile_s` gravará `NULL` no parâmetro `pFilePtr`. O arquivo temporário é excluído automaticamente quando o arquivo é fechado, quando o programa é encerrado normalmente ou quando `_rmtmp` é chamado, supondo que o diretório de trabalho atual não é alterado. O arquivo temporário é aberto no modo `w+b` (leitura/gravação binária).  
  
 Poderá ocorrer uma falha se você tentar mais de `TMP_MAX_S` chamadas (consulte STDIO.H) com `tmpfile_s.`  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`tmpfile_s`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
> [!NOTE]
>  Esse exemplo exige privilégios administrativos para ser executado no Windows Vista.  
  
```  
// crt_tmpfile_s.c  
// This program uses tmpfile_s to create a  
// temporary file, then deletes this file with _rmtmp.  
//  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char tempstring[] = "String to be written";  
   int  i;  
   errno_t err;  
  
   // Create temporary files.  
   for( i = 1; i <= 3; i++ )  
   {  
      err = tmpfile_s(&stream);  
      if( err )  
         perror( "Could not open new temporary file\n" );  
      else  
         printf( "Temporary file %d was created\n", i );  
   }  
  
   // Remove temporary files.  
   printf( "%d temporary files deleted\n", _rmtmp() );  
}  
```  
  
```Output  
Temporary file 1 was created  
Temporary file 2 was created  
Temporary file 3 was created  
3 temporary files deleted  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_rmtmp](../../c-runtime-library/reference/rmtmp.md)   
 [_tempnam, _wtempnam, tmpnam, _wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)
