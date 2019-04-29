---
title: fegetenv
ms.date: 04/05/2018
apiname:
- fetegenv
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
- fegetenv
- fenv/fegetenv
helpviewer_keywords:
- fetegenv function
ms.assetid: 68962421-6978-4b27-8e4c-ad1577830cf6
ms.openlocfilehash: d3985e4dd2b3944bcdddb79605887def7ba15473
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334405"
---
# <a name="fegetenv"></a>fegetenv

Armazena o ambiente atual de ponto flutuante no objeto especificado.

## <a name="syntax"></a>Sintaxe

```C
int fegetenv(
   fenv_t *penv
);
```

### <a name="parameters"></a>Parâmetros

*penv*<br/>
Ponteiro para um **fenv_t** objeto para conter os valores atuais do ambiente de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se o ambiente de ponto flutuante foi armazenado com êxito no *penv*. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **fegetenv** função armazena o ambiente atual de ponto flutuante no objeto apontado por *penv*. O ambiente de ponto flutuante é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de pontos flutuantes. Isso inclui o modo de direção de arredondamento e os sinalizadores de status para exceções de ponto flutuante.  Se *penv* não apontar para um válido **fenv_t** do objeto, o comportamento subsequente será indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fegetenv**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetenv](fesetenv1.md)<br/>
