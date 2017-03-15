---
title: _endthread, _endthreadex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 21
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
ms.openlocfilehash: e1e2211a34a7cc146d1ce3b791927ffc206edaef
ms.lasthandoff: 02/25/2017

---
# <a name="endthread-endthreadex"></a>_endthread, _endthreadex
Termina um thread; a `_endthread` termina um thread criado pela função`_beginthread` e a `_endthreadex` termina um thread criado pela função `_beginthreadex`.  
  
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
> As funções  `_endthread` e `_endthreadex` fazem com que os destruidores C++ pendentes no thread não sejam chamados.  
  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [_beginthread, _beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md)
