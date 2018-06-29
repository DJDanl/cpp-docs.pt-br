---
title: feclearexcept1 | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- feclearexcept function
ms.assetid: ef419da3-c248-4432-b53c-8e7a475d9533
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: face2637f308a56d95baa7563a6409dd38870d73
ms.sourcegitcommit: 2f571220e16f6c20e1fdb005f6cbc9e7ef5608f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37070071"
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

Retorna zero se *excepts* for zero, ou se todas as exceções especificadas foram limpas com êxito. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **feclearexcept** função tenta limpar flutuante ponto sinalizadores de status de exceção especificados por *excepts*. A função dá suporte a essas macros de exceção, definidas em fenv.h:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALL_EXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O *excepts* argumento pode ser zero ou o OR bit a bit de um ou mais as macros de exceção com suporte. O resultado de qualquer outro valor de argumento é indefinido.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feclearexcept**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fetestexcept](fetestexcept1.md)<br/>
