---
title: fegetexceptflag | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- fegetexceptflag
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
- fegetexceptflag
- fenv/fegetexceptflag
dev_langs:
- C++
helpviewer_keywords:
- fegetexceptflag function
ms.assetid: 2d28f0ca-70c9-4cff-be8b-3d876eacde71
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5f81f89b6e004ff188b381ec38e3af6ef3d7585d
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fegetexceptflag"></a>fegetexceptflag

Armazena o estado atual dos sinalizadores de exceção de ponto flutuante especificados.

## <a name="syntax"></a>Sintaxe

```C
int fegetexceptflag(
   fexcept_t* pstatus,
   int excepts
);

```

### <a name="parameters"></a>Parâmetros

*pstatus*<br/>
Um ponteiro para um **fexcept_t** objeto para conter os valores atuais dos sinalizadores de exceção especificados por *excepts*.

*excepts*<br/>
Os sinalizadores de exceção de ponto flutuante para armazenar em *pstatus*.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **fegetexceptflag** função armazena o estado atual dos sinalizadores de status de exceção de ponto flutuante especificado por *excepts* no **fexcept_t** objeto apontada pelo *pstatus*.  *pstatus* deve apontar para um válida **fexcept_t** objeto ou subsequente comportamento é indefinido. O **fegetexceptflag** função oferece suporte a essas macros de exceção, definidas em \<fenv.h >:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O *excepts* argumento pode ser zero, uma das macros de exceção de ponto flutuante com suporte ou o bit a bit ou de duas ou mais das macros. O efeito de qualquer outro valor de argumento é indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fegetexceptflag**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
