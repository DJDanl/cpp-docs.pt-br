---
title: feholdexcept | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
apiname:
- feholdexcept
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
- feholdexcept
- fenv/feholdexcept
dev_langs:
- C++
helpviewer_keywords:
- feholdexcept function
ms.assetid: 88e512ae-b5d8-452c-afe9-c824cd3ef1d8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6250de98b2eb3f8cc8c475d341c1d63a79262362
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32397536"
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
Ponteiro para um **fenv_t** objeto para conter uma cópia do ambiente de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Retorna zero se e somente se a função é capaz de ativar o tratamento de exceções de ponto flutuante contínuas com êxito.

## <a name="remarks"></a>Comentários

O **feholdexcept** função é usada para armazenar o estado do ambiente de ponto flutuante atual no **fenv_t** objeto apontada pelo *penv*e para definir o ambiente Não interrompa a execução em exceções de ponto flutuantes. Isso é conhecido como modo contínuo.  Esse modo continua até que o ambiente seja restaurado usando [fesetenv](fesetenv1.md) ou [feupdateenv](feupdateenv.md).

Você pode usar essa função no início de uma sub-rotina que precisa ocultar uma ou mais exceções de ponto flutuante do chamador. Para relatar uma exceção, você pode simplesmente limpar as exceções indesejadas usando [feclearexcept,](feclearexcept1.md) e, em seguida, encerrar o modo contínuo com uma chamada para **feupdateenv**.

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
