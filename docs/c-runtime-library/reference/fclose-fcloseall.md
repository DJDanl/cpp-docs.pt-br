---
title: fclose, _fcloseall | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fclose
- _fcloseall
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
- fclose
- _fcloseall
dev_langs: C++
helpviewer_keywords:
- fclose function
- streams, closing
- _fcloseall function
ms.assetid: c3c6ea72-92c6-450a-a33e-3e568d2784a4
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2d670ead8214f54323cf9f6b284eaaef9a582757
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fclose-fcloseall"></a>fclose, _fcloseall
Fecha um fluxo (`fclose`) ou fecha todos os fluxos abertos (`_fcloseall`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fclose(   
   FILE *stream   
);  
int _fcloseall( void );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 `fclose` retorna 0 se o fluxo for fechado com êxito. `_fcloseall` retorna o número total de fluxos fechados. Ambas as funções retornam `EOF` para indicar um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `fclose` fecha `stream`. Se `stream` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `fclose` definirá `errno` para `EINVAL` e retornará `EOF`. É recomendável que o ponteiro `stream` sempre seja verificado antes de chamar essa função.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.  
  
 A função `_fcloseall` fecha todos os fluxos exceto `stdin`, `stdout`, `stderr` (e, no MS-DOS, `_stdaux` e `_stdprn`). Ela também fecha e exclui todos os arquivos temporários criados por `tmpfile`. Em ambas as funções, todos os buffers associados com o fluxo são liberados antes do fechamento. Buffers alocados pelo sistema são liberados quando o fluxo está fechado. Buffers atribuídos pelo usuário com `setbuf` e `setvbuf` não são liberados automaticamente.  
  
 **Observação:** quando essas funções são usadas para fechar um fluxo, o descritor de arquivo subjacente e o identificador de arquivo do sistema operacional (ou soquete) são fechados, bem como o fluxo. Assim, se o arquivo foi aberto originalmente como um identificador de arquivo ou descritor de arquivo e for fechado com `fclose`, não chame `_close` para fechar o descritor de arquivo. Não chame a função Win32 `CloseHandle` para fechar o identificador de arquivo.  
  
 `fclose` e `_fcloseall` incluem o código para proteção contra interferência de outros threads. Para uma versão sem bloqueio de um `fclose`, consulte `_fclose_nolock`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fclose`|\<stdio.h>|  
|`_fcloseall`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_close](../../c-runtime-library/reference/close.md)   
 [_fdopen, _wfdopen](../../c-runtime-library/reference/fdopen-wfdopen.md)   
 [fflush](../../c-runtime-library/reference/fflush.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)