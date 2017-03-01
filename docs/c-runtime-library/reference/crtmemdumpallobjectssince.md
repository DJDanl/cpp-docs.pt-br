---
title: _CrtMemDumpAllObjectsSince | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtMemDumpAllObjectsSince
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
- CrtMemDumpAllObjectsSince
- _CrtMemDumpAllObjectsSince
dev_langs:
- C++
helpviewer_keywords:
- _CrtMemDumpAllObjectsSince function
- CrtMemDumpAllObjectsSince function
ms.assetid: c48a447a-e6bb-475c-9271-a3021182a0dc
caps.latest.revision: 11
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e94e06d8a1c597b0b7353dee9ae9b2988e1e7b26
ms.lasthandoff: 02/25/2017

---
# <a name="crtmemdumpallobjectssince"></a>_CrtMemDumpAllObjectsSince
Despeja informações sobre objetos no heap a partir do início da execução do programa ou de um estado de heap especificado (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void _CrtMemDumpAllObjectsSince(   
   const _CrtMemState *state   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `state`  
 Ponteiro para o estado de heap do qual o despejo será iniciado ou **NULL**.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtMemDumpAllObjectsSince` despeja as informações de cabeçalho de depuração de objetos alocados no heap em um formato legível pelo usuário. As informações de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtMemDumpAllObjectsSince` são removidas durante o pré-processamento.  
  
 `_CrtMemDumpAllObjectsSince` usa o valor do parâmetro `state` para determinar em que ponto a operação de despejo será iniciada. Para iniciar o despejo de um estado de heap especificado, o parâmetro `state` deve ser um ponteiro para uma estrutura **_CrtMemState** que tenha sido preenchida por [_CrtMemCheckpoint](../../c-runtime-library/reference/crtmemcheckpoint.md) antes da chamada a `_CrtMemDumpAllObjectsSince`. Quando `state` for **NULL**, a função iniciará o despejo a partir do início da execução do programa.  
  
 Se o aplicativo tiver instalado uma função de gancho de despejo por meio da chamada a [_CrtSetDumpClient](../../c-runtime-library/reference/crtsetdumpclient.md), sempre que `_CrtMemDumpAllObjectsSince` despejar informações sobre um tipo de bloco `_CLIENT_BLOCK`, ele também chamará a função de despejo fornecida pelo aplicativo. Por padrão, os blocos internos em tempo de execução C (`_CRT_BLOCK`) não são incluídos em operações de despejo de memória. A função [_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) pode ser usada para ativar o bit `_CRTDBG_CHECK_CRT_DF` de **_crtDbgFlag** para incluir esses blocos. Além disso, os blocos marcados como liberados ou ignorados (**_FREE_BLOCK**, **_IGNORE_BLOCK**) não são incluídos no despejo de memória.  
  
 Para obter mais informações sobre as funções de estado de heap e a estrutura `_CrtMemState`, consulte [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|**_CrtMemDumpAll-ObjectsSince**|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_CrtMemDumpAllObjectsSince`, consulte [crt_dbg2](http://msdn.microsoft.com/en-us/21e1346a-6a17-4f57-b275-c76813089167).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)
