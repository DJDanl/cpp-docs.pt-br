---
title: feraiseexcept | Microsoft Docs
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
- feraiseexcept
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
- feraiseexcept
- fenv/feraiseexcept
dev_langs:
- C++
helpviewer_keywords:
- feraiseexcept function
ms.assetid: 87e89151-83c2-4563-9a9a-45666245d437
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 93414d09b898212e3748c1de510796b401b6aa56
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="feraiseexcept"></a>feraiseexcept

Gera as exceções de ponto flutuante especificadas.

## <a name="syntax"></a>Sintaxe

```C
int feraiseexcept(
   int excepts
);
```

### <a name="parameters"></a>Parâmetros

*excepts*<br/>
As exceções de ponto flutuante que serão geradas.

## <a name="return-value"></a>Valor de retorno

Se todas as exceções especificadas forem geradas com êxito, retornará 0.

## <a name="remarks"></a>Comentários

O **feraiseexcept** função tenta gerar as exceções de ponto flutuantes especificadas por *excepts*.   O **feraiseexcept** função oferece suporte a essas macros de exceção, definidas em \<fenv.h >:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O *excepts* argumento pode ser zero, um dos valores de exceção de macro ou bit a bit ou dos dois ou mais as macros de exceção com suporte. Se uma das macros de exceção especificadas for FE_OVERFLOW ou FE_UNDERFLOW, a exceção FE_INEXACT poderá ser gerada como um efeito colateral.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

**Microsoft Specific:** exceções especificadas na *excepts* são gerados na ordem FE_INVALID, FE_DIVBYZERO, FE_OVERFLOW, FE_UNDERFLOW, FE_INEXACT. No entanto, FE_INEXACT pode ser gerado quando FE_OVERFLOW ou FE_UNDERFLOW é gerado, mesmo se não for especificado em *excepts*. **Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|*feraiseexcept*|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
[feholdexcept](feholdexcept2.md)<br/>
[fetestexcept](fetestexcept1.md)<br/>
[feupdateenv](feupdateenv.md)<br/>
