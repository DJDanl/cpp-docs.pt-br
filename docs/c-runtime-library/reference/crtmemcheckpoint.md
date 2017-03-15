---
title: _CrtMemCheckpoint | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtMemCheckpoint
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
- CrtMemCheckpoint
- _CrtMemCheckpoint
- crtdbg/_CrtMemCheckpoint
dev_langs:
- C++
helpviewer_keywords:
- CrtMemCheckpoint function
- _CrtMemCheckpoint function
ms.assetid: f1bacbaa-5a0c-498a-ac7a-b6131d83dfbc
caps.latest.revision: 18
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 5f9b0615a51318ea0e783a90d7a450b6e11372d2
ms.lasthandoff: 02/25/2017

---
# <a name="crtmemcheckpoint"></a>_CrtMemCheckpoint
Obtém o estado atual do heap de depuração e o armazena em uma estrutura `_CrtMemState` fornecida pelo aplicativo (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _CrtMemCheckpoint(  
   _CrtMemState *state   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `state`  
 Ponteiro para uma estrutura `_CrtMemState` a ser preenchida com o ponto de verificação de memória.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtMemCheckpoint` cria um instantâneo do estado atual do heap de depuração em determinado momento. Esse instantâneo pode ser usado por outras funções de estado de heap como [_CrtMemDifference](../../c-runtime-library/reference/crtmemdifference.md) para ajudar a detectar perdas de memória e outros problemas. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtMemState` são removidas durante o pré-processamento.  
  
 O aplicativo deve passar um ponteiro para uma instância alocada anteriormente da estrutura `_CrtMemState`, definida em Crtdbg.h, no parâmetro `state`. Se `_CrtMemCheckpoint` encontrar um erro durante a criação do ponto de verificação, a função gerará um relatório de depuração `_CRT_WARN` descrevendo o problema.  
  
 Para obter mais informações sobre as funções de estado de heap e a estrutura `_CrtMemState`, consulte [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
 Se `state` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) serão definidos como `EINVAL` e a função será retornada.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtMemCheckpoint`|\<crtdbg.h>, \<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** somente versões de depuração do UCRT.  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtMemDifference](../../c-runtime-library/reference/crtmemdifference.md)
