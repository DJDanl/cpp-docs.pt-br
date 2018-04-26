---
title: _set_error_mode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
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
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 557af6f9fe37db1e0811508f247eadd0fcfa74a2
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="seterrormode"></a>_set_error_mode

Modifica **__error_mode** para determinar um local diferente do padrão onde o tempo de execução do C grava uma mensagem de erro para um erro que pode finalizar o programa.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _set_error_mode(
   int mode_val
);
```

### <a name="parameters"></a>Parâmetros

*mode_val*<br/>
Destino das mensagens de erro.

## <a name="return-value"></a>Valor de retorno

Retornará a configuração antiga ou -1 se ocorrer um erro.

## <a name="remarks"></a>Comentários

Controla o coletor de saída de erro definindo o valor de **__error_mode**. Por exemplo, você pode direcionar a saída para um erro padrão ou usar o **MessageBox** API.

O *mode_val* parâmetro pode ser definido como um dos valores a seguir.

|Parâmetro|Descrição|
|---------------|-----------------|
|**_OUT_TO_DEFAULT**|Coletor de erros é determinado pelo **__app_type**.|
|**_OUT_TO_STDERR**|O coletor de erros é um erro padrão.|
|**_OUT_TO_MSGBOX**|O coletor de erros é uma caixa de mensagem.|
|**_REPORT_ERRMODE**|Relatório atual **__error_mode** valor.|

Se um valor diferente dos listados for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **set_error_mode** define **errno** para **EINVAL** e retorna -1.

Quando ele é usado com um [assert](assert-macro-assert-wassert.md), **set_error_mode** exibe a instrução com falha na caixa de diálogo e lhe dá a opção de escolher o **ignorar** botão para que você possa Continue a executar o programa.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_error_mode**|\<stdlib.h>|

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

[assert Macro, _assert, _wassert](assert-macro-assert-wassert.md)<br/>
