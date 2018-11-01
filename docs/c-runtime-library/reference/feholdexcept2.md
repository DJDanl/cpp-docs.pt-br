---
title: feholdexcept
ms.date: 04/05/2018
apiname:
- feholdexcept
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
- feholdexcept
- fenv/feholdexcept
helpviewer_keywords:
- feholdexcept function
ms.assetid: 88e512ae-b5d8-452c-afe9-c824cd3ef1d8
ms.openlocfilehash: 26097398b9f9d498ab4c56690dc9c6cbb950bafb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525730"
---
# <a name="feholdexcept"></a>feholdexcept

Salva o ambiente atual de ponto flutuante no objeto especificado, limpa os sinalizadores de status do ponto flutuante e, se possível, coloca o ambiente de ponto flutuante no modo contínuo.

## <a name="syntax"></a>Sintaxe

```C
int feholdexcept(
   fenv_t *penv
);
```

### <a name="parameters"></a>Parâmetros

*penv*<br/>
Ponteiro para um **fenv_t** objeto para conter uma cópia do ambiente de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Retorna zero se e somente se a função é capaz de ativar o tratamento de exceções de ponto flutuante contínuas com êxito.

## <a name="remarks"></a>Comentários

O **feholdexcept** função é usada para armazenar o estado do ambiente de ponto flutuante atual na **fenv_t** objeto apontado por *penv*e para definir o ambiente como Não interrompa a execução em exceções de ponto flutuante. Isso é conhecido como modo contínuo.  Esse modo continua até que o ambiente seja restaurado usando [fesetenv](fesetenv1.md) ou [feupdateenv](feupdateenv.md).

Você pode usar essa função no início de uma sub-rotina que precisa ocultar uma ou mais exceções de ponto flutuante do chamador. Para relatar uma exceção, basta limpar as exceções indesejadas usando [feclearexcept](feclearexcept1.md) e, em seguida, encerrar o modo contínuo com uma chamada para **feupdateenv**.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feholdexcept**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[feclearexcept](feclearexcept1.md)<br/>
[fesetenv](fesetenv1.md)<br/>
[feupdateenv](feupdateenv.md)<br/>
