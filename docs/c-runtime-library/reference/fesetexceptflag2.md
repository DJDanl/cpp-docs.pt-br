---
title: fesetexceptflag | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
apiname:
- fesetexceptflag
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
- fesetexceptflag
- fenv/fesetexceptflag
dev_langs:
- C++
helpviewer_keywords:
- fesetexceptflag function
ms.assetid: 2f7dad77-9e54-4097-a3e3-35176ace4de5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eef8ba1c91e6db4f0d620ef820a6487b3b17e649
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32398602"
---
# <a name="fesetexceptflag"></a>fesetexceptflag

Define os sinalizadores de status de ponto flutuante especificados no ambiente atual de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
int fesetexceptflag(
     const fexcept_t *pstatus,
     int excepts
);
```

### <a name="parameters"></a>Parâmetros

*pstatus*<br/>
Ponteiro para um **fexcept_t** objeto que contém os valores para definir a exceção sinalizadores de status. O objeto pode ser definido por uma chamada anterior a [fegetexceptflag](fegetexceptflag2.md).

*excepts*<br/>
Os sinalizadores do status de exceção de ponto flutuante que serão definidos.

## <a name="return-value"></a>Valor de retorno

Se todos os sinalizadores de status de exceção especificados forem definidos com êxito, retornará 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **fesetexceptflag** função define o estado dos sinalizadores de status de exceção de ponto flutuante especificado por *excepts* para os valores correspondentes definidos no **fexcept_t** objeto apontada pelo *pstatus*.  Ela não gera exceções. O *pstatus* ponteiro deve apontar para um válida **fexcept_t** objeto ou subsequente comportamento é indefinido. O **fesetexceptflag** função oferece suporte a esses valores de exceção de macro em *excepts*, definido em \<fenv.h >:

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
|**fesetexceptflag**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fegetexceptflag](fegetexceptflag2.md)<br/>
