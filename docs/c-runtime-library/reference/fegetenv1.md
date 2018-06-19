---
title: fegetenv | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- fetegenv function
ms.assetid: 68962421-6978-4b27-8e4c-ad1577830cf6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc8b5d189838c2788bc6200f9072c9511e61d42f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32396164"
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
Ponteiro para um **fenv_t** objeto para conter os valores de ponto flutuante do ambiente atual.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se o ambiente de ponto flutuante com êxito foi armazenado em *penv*. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **fegetenv** função armazena o ambiente de ponto flutuante atual no objeto apontado pelo *penv*. O ambiente de ponto flutuante é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de pontos flutuantes. Isso inclui o modo de direção de arredondamento e os sinalizadores de status para exceções de ponto flutuante.  Se *penv* não aponta para um válida **fenv_t** objeto subsequente comportamento será indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fegetenv**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetenv](fesetenv1.md)<br/>
