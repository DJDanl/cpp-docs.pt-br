---
title: _set_error_mode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _set_error_mode
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
- set_error_mode
- _set_error_mode
dev_langs:
- C++
helpviewer_keywords:
- _set_error_mode function
- set_error_mode function
ms.assetid: f0807be5-73d1-4a32-a701-3c9bdd139c5c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bae0e413e46776d9d0df0508a30905b9fdb09062
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="seterrormode"></a>_set_error_mode
Modifica `__error_mode` para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que pode finalizar o programa.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _set_error_mode(  
   int modeval   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `modeval`  
 Destino das mensagens de erro.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornará a configuração antiga ou -1 se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 Controla o coletor de saída de erro configurando o valor de `__error_mode`. Por exemplo, você pode direcionar a saída para um erro padrão ou usar a API `MessageBox`.  
  
 O parâmetro `modeval` é definido para um dos valores a seguir.  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_OUT_TO_DEFAULT`|O coletor de erros é determinado por `__app_type`.|  
|`_OUT_TO_STDERR`|O coletor de erros é um erro padrão.|  
|`_OUT_TO_MSGBOX`|O coletor de erros é uma caixa de mensagem.|  
|`_REPORT_ERRMODE`|Relate o valor de `__error_mode` atual.|  
  
 Se um valor diferente dos listados for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `_set_error_mode` define `errno` para `EINVAL` e retorna -1.  
  
 Quando ele é usado com um [assert](../../c-runtime-library/reference/assert-macro-assert-wassert.md), `_set_error_mode` exibe a instrução com falha na caixa de diálogo e lhe dá a opção de escolher o botão `Ignore` para que você possa continuar a executar o programa.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_error_mode`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
  
```C  
// crt_set_error_mode.c  
// compile with: /c  
#include <stdlib.h>  
#include <assert.h>  
  
int main()  
{  
   _set_error_mode(_OUT_TO_STDERR);  
   assert(2+2==5);  
}  
```  
  
```Output  
Assertion failed: 2+2==5, file crt_set_error_mode.c, line 8  
  
This application has requested the Runtime to terminate it in an unusual way.  
Please contact the application's support team for more information.  
```  
  
## <a name="see-also"></a>Consulte também  
 [assert Macro, _assert, _wassert](../../c-runtime-library/reference/assert-macro-assert-wassert.md)