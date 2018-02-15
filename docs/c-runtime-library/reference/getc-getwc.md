---
title: getc, getwc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- getwc
- getc
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
- _gettc
- getwc
- _gettchar
- getc
dev_langs:
- C++
helpviewer_keywords:
- characters, reading
- _gettc function
- getwchar function
- streams, reading characters from
- reading characters from streams
- getc function
- getwc function
- gettc function
ms.assetid: 354ef514-d0c7-404b-92f5-995f6a834bb3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fca8635d0597f1f48c16cac28410a62c7bc723ba
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getc-getwc"></a>getc, getwc
Lê um caractere de um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int getc(   
   FILE *stream   
);  
wint_t getwc(   
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Fluxo de entrada.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o caractere lido. Para indicar um erro de leitura ou uma condição de fim de arquivo, `getc` retorna `EOF` e `getwc` retorna `WEOF`. Para `getc`, use `ferror` ou `feof` para verificar se há um erro ou se o final do arquivo foi atingido. Se `stream` for `NULL`, `getc` e `getwc` invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam `EOF` (ou `WEOF` para `getwc`) e defina `errno` para `EINVAL`.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.  
  
## <a name="remarks"></a>Comentários  
 Cada rotina lê um único caractere de um arquivo na posição atual e incrementa o ponteiro de arquivo associado (se definido) para apontar para o caractere seguinte. O arquivo é associado a `stream`.  
  
 Essas funções bloqueiam o thread de chamada e, portanto, são thread-safe. Para ver uma versão sem bloqueio, consulte [_getc_nolock, _getwc_nolock](../../c-runtime-library/reference/getc-nolock-getwc-nolock.md).  
  
 Veja comentários específicos sobre a rotina a seguir.  
  
|Rotina|Comentários|  
|-------------|-------------|  
|`getc`|O mesmo que `fgetc`, mas implementado como uma função e como uma macro.|  
|`getwc`|Versão de caractere largo de `getc`. Lê um caractere multibyte ou um caractere largo, dependendo de `stream` ser aberto no modo de texto ou binário.|  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_gettc`|`getc`|`getc`|`getwc`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`getc`|\<stdio.h>|  
|`getwc`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_getc.c  
// Use getc to read a line from a file.  
  
#include <stdio.h>  
  
int main()  
{  
    char buffer[81];  
    int i, ch;  
    FILE* fp;  
  
    // Read a single line from the file "crt_getc.txt".   
  
    fopen_s(&fp, "crt_getc.txt", "r");  
    if (!fp)  
    {  
       printf("Failed to open file crt_getc.txt.\n");  
       exit(1);  
    }  
  
    for (i = 0; (i < 80) && ((ch = getc(fp)) != EOF)  
                         && (ch != '\n'); i++)  
    {  
        buffer[i] = (char) ch;  
    }  
  
    // Terminate string with a null character   
    buffer[i] = '\0';  
    printf( "Input was: %s\n", buffer);  
  
    fclose(fp);  
}  
```  
  
## <a name="input-crtgetctxt"></a>Entrada: crt_getc.txt  
  
```  
Line one.  
Line two.  
```  
  
### <a name="output"></a>Saída  
  
```  
Input was: Line one.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetc, fgetwc](../../c-runtime-library/reference/fgetc-fgetwc.md)   
 [_getch, _getwch](../../c-runtime-library/reference/getch-getwch.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)   
 [ungetc, ungetwc](../../c-runtime-library/reference/ungetc-ungetwc.md)