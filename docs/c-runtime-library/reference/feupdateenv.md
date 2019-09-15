---
title: feupdateenv
ms.date: 04/05/2018
api_name:
- feupdateenv
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
- feupdateenv
- fenv/feupdateenv
helpviewer_keywords:
- feupdateenv function
ms.assetid: 3d170042-dfd5-4e4f-a55f-038cf2296cc9
ms.openlocfilehash: 8f40cab42e4a89b1fc5a100587b11b0e2aeeb55c
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70940982"
---
# <a name="feupdateenv"></a>feupdateenv

Salva as exceções de ponto flutuante geradas no momento, restaura o estado do ambiente de ponto flutuante especificado e, em seguida, gera as exceções de ponto flutuante salvas.

## <a name="syntax"></a>Sintaxe

```C
int feupdateenv(
   const fenv_t* penv
);
```

### <a name="parameters"></a>Parâmetros

*penv*<br/>
Ponteiro para um objeto **fenv_t** que contém um ambiente de ponto flutuante, conforme definido por uma chamada para [fegetenv](fegetenv1.md) ou [feholdexcept](feholdexcept2.md). Você também pode especificar o ambiente de ponto flutuante de inicialização padrão usando a macro FE_DFL_ENV.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se todas as ações forem concluídas com êxito. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

A função **feupdateenv** executa várias ações. Primeiro, ela armazena os sinalizadores atuais de status de exceção de ponto flutuante gerados no armazenamento automático. Em seguida, ele define o ambiente de ponto flutuante atual a partir do valor armazenado no objeto **fenv_t** apontado por *penv*. Se *penv* não for **FE_DFL_ENV** ou não apontar para um objeto **fenv_t** válido, o comportamento subsequente será indefinido. Por fim, **feupdateenv** gera as exceções de ponto flutuante armazenadas localmente.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feupdateenv**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[fegetenv](fegetenv1.md)<br/>
[feclearexcept](feclearexcept1.md)<br/>
[feholdexcept](feholdexcept2.md)<br/>
[fesetexceptflag](fesetexceptflag2.md)<br/>
