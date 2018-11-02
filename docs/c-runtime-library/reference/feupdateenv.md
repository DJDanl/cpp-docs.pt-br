---
title: feupdateenv
ms.date: 04/05/2018
apiname:
- feupdateenv
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
apitype: HeaderDef
f1_keywords:
- feupdateenv
- fenv/feupdateenv
helpviewer_keywords:
- feupdateenv function
ms.assetid: 3d170042-dfd5-4e4f-a55f-038cf2296cc9
ms.openlocfilehash: 6d553d6899f55f5bdfb3ff313e88abfcb56ab4ec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50605082"
---
# <a name="feupdateenv"></a>feupdateenv

Salva as exceções de ponto flutuante geradas no momento, restaura o estado do ambiente de ponto flutuante especificado e, em seguida, gera as exceções de ponto flutuante salvas.

## <a name="syntax"></a>Sintaxe

```C
int feupdateenv(
   const fenv_t* penv
);
```

### <a name="parameters"></a>Parâmetros

*penv*<br/>
Ponteiro para um **fenv_t** objeto que contém um ambiente de ponto flutuante conforme definido por uma chamada para [fegetenv](fegetenv1.md) ou [feholdexcept](feholdexcept2.md). Você também pode especificar o ambiente de ponto flutuante de inicialização padrão usando a macro FE_DFL_ENV.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se todas as ações forem concluídas com êxito. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **feupdateenv** função executa várias ações. Primeiro, ela armazena os sinalizadores atuais de status de exceção de ponto flutuante gerados no armazenamento automático. Em seguida, ele define o ambiente atual de ponto flutuante do valor armazenado na **fenv_t** objeto apontado por *penv*. Se *penv* não está **FE_DFL_ENV** ou não apontar para um válido **fenv_t** do objeto, o comportamento subsequente será indefinido. Por fim, **feupdateenv** gera as exceções de ponto flutuantes armazenadas localmente.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feupdateenv**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[fegetenv](fegetenv1.md)<br/>
[feclearexcept](feclearexcept1.md)<br/>
[feholdexcept](feholdexcept2.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
