---
title: _endthread, _endthreadex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _endthread
- _endthreadex
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _endthread
- endthreadex
- _endthreadex
- endthread
dev_langs:
- C++
helpviewer_keywords:
- _endthread function
- endthread function
- terminating threads
- endthreadex function
- _endthreadex function
- threading [C++], terminating threads
ms.assetid: 18a91f2f-659e-40b4-b266-ec12dcf2abf5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 794dc5c4bbaf9653c5b6bbb08ea3e0a60ca438c4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="endthread-endthreadex"></a>_endthread, _endthreadex
Encerra um thread; `_endthread` encerra um thread que é criado por `_beginthread` e `_endthreadex` encerra um thread que é criado pela `_beginthreadex`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _endthread( void );  
void _endthreadex(   
   unsigned retval   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `retval`  
 Código de saída do thread.  
  
## <a name="remarks"></a>Comentários  
 Você pode chamar a função `_endthread` ou `_endthreadex` explicitamente para terminar um thread. No entanto, a função `_endthread` ou `_endthreadex` é chamada automaticamente quando o thread volta da rotina apresentada como parâmetro à função `_beginthread` ou `_beginthreadex`. Chamar a função `endthread` ou `_endthreadex` para terminar um thread ajuda a garantir que os recursos alocados ao thread sejam devidamente recuperados.  
  
> [!NOTE]
>  No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659.aspx) do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. As funções `_endthread` e `_endthreadex` recuperam os recursos alocados ao thread e chamam a API `ExitThread`.  
  
 A função `_endthread` fecha o identificador de thread automaticamente. O comportamento da API `ExitThread` do Win32 é diferente. Portanto, ao usar `_beginthread` e `_endthread`, não feche explicitamente o identificador de thread chamando a API [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211.aspx) do Win32.  
  
 Como a API `ExitThread` do Win32, a função `_endthreadex` não fecha o identificador de thread. Portanto, ao usar as funções `_beginthreadex` e `_endthreadex`, você deve fechar o identificador de thread explicitamente chamando a API `CloseHandle` do Win32 para fechar o identificador de thread.  
  
> [!NOTE]
>  As funções `_endthread` e `_endthreadex` fazem com que os destruidores C++ pendentes no thread não sejam chamados.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_endthread`|\<process.h>|  
|`_endthreadex`|\<process.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [_beginthread, _beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md)