---
title: _set_error_mode
ms.date: 11/04/2016
api_name:
- _set_error_mode
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_error_mode
- _set_error_mode
helpviewer_keywords:
- _set_error_mode function
- set_error_mode function
ms.assetid: f0807be5-73d1-4a32-a701-3c9bdd139c5c
ms.openlocfilehash: 15a6d72a79f0498fb7d81094ed3595dea1cf444f
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948558"
---
# <a name="_set_error_mode"></a>_set_error_mode

Modifica **__error_mode** para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que pode encerrar o programa.

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

Controla o coletor de saída de erro definindo o valor de **__error_mode**. Por exemplo, você pode direcionar a saída para um erro padrão ou usar a API **MessageBox** .

O parâmetro *mode_val* pode ser definido como um dos valores a seguir.

|Parâmetro|Descrição|
|---------------|-----------------|
|**_OUT_TO_DEFAULT**|O coletor de erro é determinado por **__app_type**.|
|**_OUT_TO_STDERR**|O coletor de erros é um erro padrão.|
|**_OUT_TO_MSGBOX**|O coletor de erros é uma caixa de mensagem.|
|**_REPORT_ERRMODE**|Relatar o valor de **__error_mode** atual.|

Se um valor diferente dos listados for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **_set_error_mode** definirá **errno** como **EINVAL** e retornará-1.

Quando usado com uma [declaração](assert-macro-assert-wassert.md), **_set_error_mode** exibe a instrução com falha na caixa de diálogo e oferece a opção de escolher o botão **ignorar** para que você possa continuar a executar o programa.

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
