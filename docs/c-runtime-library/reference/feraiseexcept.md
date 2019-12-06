---
title: feraiseexcept
ms.date: 04/05/2018
api_name:
- feraiseexcept
api_location:
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
api_type:
- HeaderDef
f1_keywords:
- feraiseexcept
- fenv/feraiseexcept
helpviewer_keywords:
- feraiseexcept function
ms.assetid: 87e89151-83c2-4563-9a9a-45666245d437
ms.openlocfilehash: 07c8a79e0a9569db80607e1ec1e16cd4b502783c
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857821"
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

*exceções*<br/>
As exceções de ponto flutuante que serão geradas.

## <a name="return-value"></a>Valor retornado

Se todas as exceções especificadas forem geradas com êxito, retornará 0.

## <a name="remarks"></a>Comentários

A função **feraiseexcept** tenta gerar as exceções de ponto flutuante especificadas por *Except*.   A função **feraiseexcept** dá suporte a essas macros de exceção, definidas em \<fenv. h >:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O argumento *Except* pode ser zero, um dos valores da macro de exceção, ou o bit e de duas ou mais das macros de exceção com suporte. Se uma das macros de exceção especificadas for FE_OVERFLOW ou FE_UNDERFLOW, a exceção FE_INEXACT poderá ser gerada como um efeito colateral.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

**Específico da Microsoft:** As exceções especificadas em *Except* são geradas na ordem FE_INVALID, FE_DIVBYZERO, FE_OVERFLOW, FE_UNDERFLOW FE_INEXACT. No entanto, FE_INEXACT pode ser gerado quando FE_OVERFLOW ou FE_UNDERFLOW é gerado, mesmo que não seja especificado em *Except*.

## <a name="requirements"></a>Requisitos do

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|*feraiseexcept*|\<fenv.h>|\<cfenv>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
[feholdexcept](feholdexcept2.md)<br/>
[fetestexcept](fetestexcept1.md)<br/>
[feupdateenv](feupdateenv.md)<br/>
