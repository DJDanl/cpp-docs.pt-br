---
title: _setmbcp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _setmbcp
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _setmbcp
- setmbcp
dev_langs: C++
helpviewer_keywords:
- setmbcp function
- _setmbcp function
- multibyte code pages
ms.assetid: cfde53b5-0b73-4684-81b1-a8d3aafc85de
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0b09953ffdb1523078f31cad08d53253b9d79892
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setmbcp"></a>_setmbcp
Define uma nova página de código multibyte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _setmbcp(  
   int codepage   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `codepage`  
 Nova configuração de página de código para rotinas multibyte independentes da localidade.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se a página de código é definida com êxito. Se um valor de página de código inválido é fornecido para `codepage`, retorna -1 e a configuração de página de código é alterada. Define `errno` para `EINVAL` se ocorre uma falha de alocação de memória.  
  
## <a name="remarks"></a>Comentários  
 A função `_setmbcp` especifica uma nova página de código multibyte. Por padrão, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema. A configuração de página de código multibyte afeta todas as rotinas multibyte que não são dependentes da localidade. No entanto, é possível instruir o `_setmbcp` para usar a página de código definida para a localidade atual (consulte a lista de constantes de manifesto e resultados de comportamento associados a seguir). Para obter uma lista das rotinas de multibyte que dependem da página de código de localidade em vez da página de código multibyte, consulte [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).  
  
 A página de código multibyte também afeta o processamento de caracteres multibyte pelas rotinas de biblioteca em tempo de execução a seguir:  
  
||||  
|-|-|-|  
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[_mktemp](../../c-runtime-library/reference/mktemp-wmktemp.md)|[_stat](../../c-runtime-library/reference/stat-functions.md)|  
|[_fullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|[_tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
|[_makepath](../../c-runtime-library/reference/makepath-wmakepath.md)|[_splitpath](../../c-runtime-library/reference/splitpath-wsplitpath.md)|[tmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
  
 Além disso, todas as rotinas da biblioteca em tempo de execução que recebem argumentos de programa `argv` ou `envp` de caracteres multibyte como parâmetros (assim como as famílias `_exec` e `_spawn`) processam essas cadeias de caracteres de acordo com a página de código multibyte. Portanto, essas rotinas também são afetadas por uma chamada para `_setmbcp` que altera a página de código multibyte.  
  
 O argumento `codepage` pode ser definido como qualquer um dos seguintes valores:  
  
-   `_MB_CP_ANSI` Use a página de código ANSI obtida do sistema operacional na inicialização do programa.  
  
-   `_MB_CP_LOCALE` Use a página de código da localidade atual obtida de uma chamada anterior a [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md).  
  
-   `_MB_CP_OEM` Use a página de código OEM obtida do sistema operacional na inicialização do programa.  
  
-   `_MB_CP_SBCS` Use a página de código de byte único. Quando a página de código está definida como `_MB_CP_SBCS`, uma rotina como [_ismbblead](../../c-runtime-library/reference/ismbblead-ismbblead-l.md) sempre retorna false.  
  
-   Qualquer outro valor de página de código válido, independentemente de ser um valor ANSI, OEM ou outra página de código com suporte pelo sistema operacional (exceto UTF-7 e UTF-8, que não têm suporte).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_setmbcp`|\<mbctype.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)