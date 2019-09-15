---
title: feholdexcept
ms.date: 04/05/2018
api_name:
- feholdexcept
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
- feholdexcept
- fenv/feholdexcept
helpviewer_keywords:
- feholdexcept function
ms.assetid: 88e512ae-b5d8-452c-afe9-c824cd3ef1d8
ms.openlocfilehash: bd55a4ed627d731f7246d589d4b74b4173e31d4e
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70941195"
---
# <a name="feholdexcept"></a>feholdexcept

Salva o ambiente atual de ponto flutuante no objeto especificado, limpa os sinalizadores de status do ponto flutuante e, se possível, coloca o ambiente de ponto flutuante no modo contínuo.

## <a name="syntax"></a>Sintaxe

```C
int feholdexcept(
   fenv_t *penv
);
```

### <a name="parameters"></a>Parâmetros

*penv*<br/>
Ponteiro para um objeto **fenv_t** para conter uma cópia do ambiente de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Retornará zero se e somente se a função for capaz de ativar com êxito a manipulação de exceção de ponto flutuante sem parada.

## <a name="remarks"></a>Comentários

A função **feholdexcept** é usada para armazenar o estado do ambiente de ponto flutuante atual no objeto **fenv_t** apontado pelo *penv*e para definir o ambiente para não interromper a execução em exceções de ponto flutuante. Isso é conhecido como modo contínuo.  Esse modo continua até que o ambiente seja restaurado usando [fesetenv](fesetenv1.md) ou [feupdateenv](feupdateenv.md).

Você pode usar essa função no início de uma sub-rotina que precisa ocultar uma ou mais exceções de ponto flutuante do chamador. Para relatar uma exceção, você pode simplesmente limpar as exceções indesejadas usando [feclearexcept](feclearexcept1.md) e finalizar o modo não parado com uma chamada para **feupdateenv**.

Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**feholdexcept**|\<fenv.h>|\<cfenv>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[feclearexcept](feclearexcept1.md)<br/>
[fesetenv](fesetenv1.md)<br/>
[feupdateenv](feupdateenv.md)<br/>
