---
title: _CrtMemDumpStatistics | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtMemDumpStatistics
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
- CrtMemDumpStatistics
- _CrtMemDumpStatistics
dev_langs:
- C++
helpviewer_keywords:
- _CrtMemDumpStatistics function
- CrtMemDumpStatistics function
ms.assetid: 27b9d731-3184-4a2d-b9a7-6566ab28a9fe
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.openlocfilehash: 524c875f5cf25eb41d09e0f5dc99c32efcae8661
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtmemdumpstatistics"></a>_CrtMemDumpStatistics
Despeja as informações de cabeçalho de depuração de um estado de heap especificado em um formato legível pelo usuário (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _CrtMemDumpStatistics(   
   const _CrtMemState *state   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `state`  
 Ponteiro para o estado de heap a ser despejado.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtMemDumpStatistics` despeja as informações de cabeçalho de depuração para um estado especificado do heap em um formato legível pelo usuário. As estatísticas de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. O estado de memória pode conter um estado de heap específico ou a diferença entre dois estados. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtMemDumpStatistics` são removidas durante o pré-processamento.  
  
 O parâmetro `state` deve ser um ponteiro para uma estrutura `_CrtMemState` que foi preenchida por [_CrtMemCheckpoint](../../c-runtime-library/reference/crtmemcheckpoint.md) ou retornada por [_CrtMemDifference](../../c-runtime-library/reference/crtmemdifference.md) antes de `_CrtMemDumpStatistics` ser chamado. Se `state` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e nenhuma ação será realizada. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter mais informações sobre as funções de estado de heap e a estrutura `_CrtMemState`, consulte [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|-------------|---------------------|----------------------|  
|`_CrtMemDumpStatistics`|\<crtdbg.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
