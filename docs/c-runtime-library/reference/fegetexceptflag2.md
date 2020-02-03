---
title: fegetexceptflag
ms.date: 04/05/2018
api_name:
- fegetexceptflag
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
- fegetexceptflag
- fenv/fegetexceptflag
helpviewer_keywords:
- fegetexceptflag function
ms.assetid: 2d28f0ca-70c9-4cff-be8b-3d876eacde71
ms.openlocfilehash: b840408ce704ad5519fbf233de41c8d5422006ad
ms.sourcegitcommit: ba4180a2d79d7e391f2f705797505d4aedbc2a5e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2020
ms.locfileid: "76972182"
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
Um ponteiro para um objeto **fexcept_t** para conter os valores atuais dos sinalizadores de exceção especificados por *Except*.

*exceções*<br/>
Os sinalizadores de exceção de ponto flutuante para armazenar em *pStatus*.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

A função **fegetexceptflag** armazena o estado atual dos sinalizadores de status de exceção de ponto flutuante especificados por *, exceto* no objeto de **fexcept_t** apontado por *pStatus*.  *pStatus* deve apontar para um objeto de **fexcept_t** válido, ou o comportamento subsequente é indefinido. A função **fegetexceptflag** dá suporte a essas macros de exceção, definidas em \<fenv. h >:

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
|**fegetexceptflag**|\<fenv.h>|\<cfenv>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Veja também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
