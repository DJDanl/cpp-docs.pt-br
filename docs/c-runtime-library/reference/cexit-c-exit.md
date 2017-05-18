---
title: _cexit, _c_exit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _c_exit
- _cexit
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
- _cexit
- c_exit
- _c_exit
- cexit
dev_langs:
- C++
helpviewer_keywords:
- cleanup operations during processes
- cexit function
- _c_exit function
- _cexit function
- c_exit function
ms.assetid: f3072045-9924-4b1a-9fef-b0dcd6d12663
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.openlocfilehash: a68b803ee7dc444439d7a62f43cf7157e7fbf505
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="cexit-cexit"></a>_cexit, _c_exit
Executa operações de limpeza e retorna sem encerrar o processo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _cexit( void );  
void _c_exit( void );  
```  
  
## <a name="remarks"></a>Comentários  
 A função `_cexit` chama, na ordem UEPS (último a entrar, primeiro a sair), as funções registradas por `atexit` e `_onexit`. Em seguida, `_cexit` libera todos os buffers de E/S e fecha todos os fluxos abertos antes de retornar. `_c_exit` é o mesmo que `_exit`, mas retorna para o processo de chamada sem processar `atexit` ou `_onexit` ou liberar buffers de fluxo. O comportamento de `exit`, `_exit`, `_cexit` e `_c_exit` é mostrado na tabela a seguir.  
  
|Função|Comportamento|  
|--------------|--------------|  
|`exit`|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|  
|`_exit`|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|  
|`_cexit`|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|  
|`_c_exit`|Executa procedimentos rápidos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|  
  
 Quando você chama a função `_cexit` ou `_c_exit`, os destruidores de quaisquer objetos temporários ou automáticos que existem no momento da chamada não são chamados. Um objeto automático é um objeto definido em uma função na qual o objeto não é declarado como estático. Um objeto temporário é um objeto criado pelo compilador. Para destruir um objeto automático antes de chamar `_cexit` ou `_c_exit`, chame explicitamente o destruidor do objeto da seguinte maneira:  
  
```  
myObject.myClass::~myClass( );  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_cexit`|\<process.h>|  
|`_c_exit`|\<process.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)
