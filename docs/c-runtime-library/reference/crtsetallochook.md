---
title: _CrtSetAllocHook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtSetAllocHook
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
- _CrtSetAllocHook
- CrtSetAllocHook
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetAllocHook function
- CrtSetAllocHook function
ms.assetid: 405df37b-2fd1-42c8-83bc-90887f17f29d
caps.latest.revision: 15
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
ms.openlocfilehash: fa03fb135907d9f516544f5f4b202c9f4e779fc3
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtsetallochook"></a>_CrtSetAllocHook
Instala uma função de alocação definida pelo cliente vinculando-a ao processo de alocação de memória de depuração em tempo de execução C (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_CRT_ALLOC_HOOK _CrtSetAllocHook(  
   _CRT_ALLOC_HOOK allocHook   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `allocHook`  
 Nova função de alocação definida pelo cliente a ser vinculada ao processo de alocação de memória de depuração em tempo de execução C.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornará a função de gancho de alocação previamente definida ou `NULL` se `allocHook` for `NULL`.  
  
## <a name="remarks"></a>Comentários  
 `_CrtSetAllocHook` permite que um aplicativo vincule sua própria função de alocação ao processo de alocação de memória da biblioteca de depuração em tempo de execução C. Como resultado, todas as chamadas a uma função de alocação de depuração para alocar, realocar ou liberar um bloco de memória disparam uma chamada à função de gancho do aplicativo. O `_CrtSetAllocHook` fornece um aplicativo com um método fácil para testar como o aplicativo trata situações de memória insuficiente, a capacidade de examinar padrões de alocação e a oportunidade de registrar informações de alocação para análise posterior. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtSetAllocHook` são removidas durante o pré-processamento.  
  
 A função `_CrtSetAllocHook` instala a nova função de alocação definida pelo cliente especificada em `allocHook` e retorna a função de gancho definida anteriormente. O seguinte exemplo demonstra como um gancho de alocação definido pelo cliente deve ser prototipado:  
  
```  
int YourAllocHook( int allocType, void *userData, size_t size, int   
blockType, long requestNumber, const unsigned char *filename, int   
lineNumber);  
```  
  
 O argumento `allocType` especifica o tipo de operação de alocação (`(_HOOK_ALLOC`, `_HOOK_REALLOC` e `_HOOK_FREE`) que disparou a chamada à função de gancho da alocação. Quando o tipo de alocação de gatilho é `_HOOK_FREE`, `userData` é um ponteiro para a seção de dados do usuário do bloco de memória prestes a ser liberado. No entanto, quando o tipo de alocação de gatilho é `_HOOK_ALLOC` ou `_HOOK_REALLOC`, `userData` é `NULL`, pois o bloco de memória ainda não foi alocado.  
  
 `size` especifica o tamanho do bloco de memória em bytes, `blockType` indica o tipo do bloco de memória, `requestNumber` é o número de ordem de alocação do objeto do bloco de memória e, se disponível, `filename` e `lineNumber` especificam o nome do arquivo de origem e o número de linha em que a operação de alocação de gatilho foi iniciada.  
  
 Depois que a função de gancho concluir o processamento, ela deve retornar um valor booliano, que explica ao processo principal de alocação em tempo de execução C como continuar. Quando a função de gancho desejar que o processo de alocação principal continue como se a função de gancho nunca tivesse sido chamada, a função de gancho deverá retornar `TRUE`. Isso faz com que a operação de alocação de gatilho original seja executada. Ao usar essa implementação, a função de gancho pode coletar e salvar as informações de alocação para análise posterior, sem interferir na operação de alocação atual ou no estado do heap de depuração.  
  
 Quando a função de gancho desejar que o processo de alocação principal continue como se a operação de alocação de gatilho tivesse sido chamada e falhado, a função de gancho deverá retornar `FALSE`. Ao usar essa implementação, a função de gancho pode simular uma ampla variedade de condições de memória e estados de heap de depuração para testar como o aplicativo manipula cada situação.  
  
 Para limpar a função de gancho, passe `NULL` para `_CrtSetAllocHook`.  
  
 Para obter mais informações sobre como `_CrtSetAllocHook` pode ser usado com outras funções de gerenciamento de memória ou como escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).  
  
> [!NOTE]
> Não há suporte para  `_CrtSetAllocHook` em `/clr:pure`. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtSetAllocHook`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_CrtSetAllocHook`, consulte [crt_dbg2](http://msdn.microsoft.com/en-us/21e1346a-6a17-4f57-b275-c76813089167).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtGetAllocHook](../../c-runtime-library/reference/crtgetallochook.md)
