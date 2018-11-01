---
title: fetestexcept
ms.date: 04/05/2018
apiname:
- fetestexcept
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
- fetestexcept
- fenv/fetestexcept
helpviewer_keywords:
- fetestexept function
ms.assetid: ca4dc43f-5573-440d-bc19-ead7571b13dc
ms.openlocfilehash: ae170e4c5826e2053b330d81773b75f176303332
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50667435"
---
# <a name="fetestexcept"></a>fetestexcept

Determina qual dos sinalizadores de status de exceção de ponto flutuante especificados estão definidos no momento.

## <a name="syntax"></a>Sintaxe

```C
int fetestexcept(
   int excepts
);

```

### <a name="parameters"></a>Parâmetros

*exceções de*<br/>
Um OR bit a bit dos sinalizadores de status de ponto flutuante para testar.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna uma bitmask contendo um OR bit a bit das macros de exceção de ponto flutuante que correspondem aos sinalizadores de status de exceção atualmente definidos. Retorna 0 se nenhuma das exceções for definida.

## <a name="remarks"></a>Comentários

Use a função fetestexcept para determinar quais exceções foram geradas pela operação de ponto flutuante. Use o *, exceto* parâmetro para especificar quais sinalizadores de status de exceção para testar. O **fetestexcept** função usa essas macros de exceção definidas em \<fenv. h > na *exceções* e o valor de retorno:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

Especificado *, exceto* argumento pode ser 0, uma das macros de exceção de ponto flutuante com suporte ou bit a bit ou de duas ou mais das macros. O efeito de qualquer outro *, exceto* o valor do argumento é indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fetestexcept**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[feclearexcept](feclearexcept1.md)<br/>
[feraiseexcept](feraiseexcept.md)<br/>
