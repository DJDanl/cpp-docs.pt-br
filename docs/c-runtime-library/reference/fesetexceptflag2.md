---
title: fesetexceptflag
ms.date: 04/05/2018
api_name:
- fesetexceptflag
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
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fesetexceptflag
- fenv/fesetexceptflag
helpviewer_keywords:
- fesetexceptflag function
ms.assetid: 2f7dad77-9e54-4097-a3e3-35176ace4de5
ms.openlocfilehash: b16de7ea54b5f1df21b6626febe773c8cef556f5
ms.sourcegitcommit: ba4180a2d79d7e391f2f705797505d4aedbc2a5e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2020
ms.locfileid: "76972141"
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
Ponteiro para um objeto de **fexcept_t** que contém os valores para os quais definir os sinalizadores de status de exceção. O objeto pode ser definido por uma chamada anterior a [fegetexceptflag](fegetexceptflag2.md).

*exceções*<br/>
Os sinalizadores do status de exceção de ponto flutuante que serão definidos.

## <a name="return-value"></a>Valor de retorno

Se todos os sinalizadores de status de exceção especificados forem definidos com êxito, retornará 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

A função **fesetexceptflag** define o estado dos sinalizadores de status de exceção de ponto flutuante especificados por *, exceto* para os valores correspondentes definidos no objeto de **fexcept_t** apontado por *pStatus*.  Ela não gera exceções. O ponteiro *pStatus* deve apontar para um objeto de **fexcept_t** válido, ou o comportamento subsequente é indefinido. A função **fesetexceptflag** dá suporte a esses valores de macro de exceção em *Except*, definidos em \<fenv. h >:

|Macro de exceção|Descrição|
|---------------------|-----------------|
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|
|FE_ALL_EXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|

O argumento *Except* pode ser zero, uma das macros de exceção de ponto flutuante com suporte, ou a bit e vírgula de duas ou mais macros. O efeito de qualquer outro valor de argumento é indefinido.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos do

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fesetexceptflag**|\<fenv.h>|\<cfenv>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Veja também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fegetexceptflag](fegetexceptflag2.md)<br/>
