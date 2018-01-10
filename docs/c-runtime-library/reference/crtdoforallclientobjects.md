---
title: _CrtDoForAllClientObjects | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CrtDoForAllClientObjects
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
- _CrtDoForAllClientObjects
- CrtDoForAllClientObjects
- crtdbg/_CrdDoForAllClientObjects
dev_langs: C++
helpviewer_keywords:
- _CrtDoForAllClientObjects function
- CrtDoForAllClientObjects function
ms.assetid: d0fdb835-3cdc-45f1-9a21-54208e8df248
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dff8b99d6378928583cea0c5eec7d69130c56557
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtdoforallclientobjects"></a>_CrtDoForAllClientObjects
Chama uma função fornecida por aplicativo para todos os tipos de `_CLIENT_BLOCK` no heap (apenas versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _CrtDoForAllClientObjects(   
   void ( * pfn )( void *, void * ),  
   void *context  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pfn`  
 Ponteiro para a função de retorno de chamada da função fornecida pelo aplicativo. O primeiro parâmetro para essa função aponta para os dados. O segundo parâmetro é o ponteiro de contexto enviado à chamada para `_CrtDoForAllClientObjects`.  
  
 `context`  
 Ponteiro para o contexto fornecido pelo aplicativo para enviar à função fornecida pelo aplicativo.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtDoForAllClientObjects` pesquisa na lista vinculada do heap por blocos de memória com o tipo `_CLIENT_BLOCK` e chama a função fornecida pelo aplicativo quando um bloco desse tipo é encontrado. O bloco encontrado e o parâmetro `context` são enviados como argumentos para a função fornecida pelo aplicativo. Durante a depuração, um aplicativo pode rastrear um grupo específico de alocações de forma explícita, chamando as funções de heap de depuração para alocar a memória e especificar quais blocos estão atribuídos ao tipo de bloco `_CLIENT_BLOCK`. Esses blocos podem ser rastreados separadamente e relatados de modo diferente durante a detecção de vazamento e o relatório de estado da memória.  
  
 Se o campo de bits `_CRTDBG_ALLOC_MEM_DF` do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) não estiver ativado, `_CrtDoForAllClientObjects` será retornado imediatamente. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtDoForAllClientObjects` são removidas durante o pré-processamento.  
  
 Para obter mais informações sobre o tipo `_CLIENT_BLOCK` e como ele pode ser usado por outras funções de depuração, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
 Se `pfn` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) serão definidos como `EINVAL` e a função será retornada.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtDoForAllClientObjects`|\<crtdbg.h>, \<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** somente versões de depuração de bibliotecas universais em tempo de execução C.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md)   
 [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details)   
 [_CrtReportBlockType](../../c-runtime-library/reference/crtreportblocktype.md)