---
title: fesetexceptflag
ms.date: 04/05/2018
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
helpviewer_keywords:
- fesetexceptflag function
ms.assetid: 2f7dad77-9e54-4097-a3e3-35176ace4de5
ms.openlocfilehash: 9ac79e790f0b1e7a89413a0d4974f6053c95616e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62333989"
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
Ponteiro para um **fexcept_t** objeto que contém os valores para definir sinalizadores de status de exceção para. O objeto pode ser definido por uma chamada anterior a [fegetexceptflag](fegetexceptflag2.md).

*excepts*<br/>
Os sinalizadores do status de exceção de ponto flutuante que serão definidos.

## <a name="return-value"></a>Valor de retorno

Se todos os sinalizadores de status de exceção especificados forem definidos com êxito, retornará 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

O **fesetexceptflag** função define o estado dos sinalizadores de status de exceção de ponto flutuante especificado por *, exceto* para os valores correspondentes definidos **fexcept_t** objeto apontado por *pstatus*.  Ela não gera exceções. O *pstatus* ponteiro deve apontar para um válido **fexcept_t** objeto ou o comportamento subsequente será indefinido. O **fesetexceptflag** função dá suporte a esses valores de macro de exceção no *, exceto*, definida em \<fenv. h >:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O *, exceto* argumento pode ser zero, uma das macros de exceção de ponto flutuante com suporte ou bit a bit ou de duas ou mais das macros. O efeito de qualquer outro valor de argumento é indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fesetexceptflag**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fegetexceptflag](fegetexceptflag2.md)<br/>
