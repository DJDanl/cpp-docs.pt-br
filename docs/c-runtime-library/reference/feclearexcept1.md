---
title: feclearexcept1
ms.date: 04/05/2018
apiname:
- feclearexcept
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
- feclearexcept
- fenv/feclearexcept
helpviewer_keywords:
- feclearexcept function
ms.assetid: ef419da3-c248-4432-b53c-8e7a475d9533
ms.openlocfilehash: 3c2f037a5be903fc006debfa7319c483431fdd92
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334730"
---
# <a name="feclearexcept"></a>feclearexcept

Tenta limpar os sinalizadores de exceção de ponto flutuante especificados pelo argumento.

## <a name="syntax"></a>Sintaxe

```C
int feclearexcept(
   int excepts
);
```

### <a name="parameters"></a>Parâmetros

*excepts*<br/>
Os sinalizadores de status de exceção para limpar.

## <a name="return-value"></a>Valor de retorno

Retorna zero se *, exceto* for zero, ou se todas as exceções especificadas foram limpas com êxito. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **feclearexcept** sinalizadores de status de exceção especificados por ponto de função tenta limpar flutuante *, exceto*. A função dá suporte a essas macros de exceção, definidas em fenv.h:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALL_EXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O *, exceto* argumento pode ser zero ou o OR bit a bit de um ou mais das macros de exceção com suporte. O resultado de qualquer outro valor de argumento é indefinido.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feclearexcept**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fetestexcept](fetestexcept1.md)<br/>
