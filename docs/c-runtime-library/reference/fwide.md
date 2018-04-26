---
title: fwide | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- fwide
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
apitype: DLLExport
f1_keywords:
- fwide
dev_langs:
- C++
helpviewer_keywords:
- fwide function
ms.assetid: a4641f5b-d74f-4946-95d5-53a64610d28d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a055df312215b5ff424aff54cfee54e0568ab307
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fwide"></a>fwide

Não implementado.

## <a name="syntax"></a>Sintaxe

```C
int fwide(
   FILE *stream,
   int mode;
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para **arquivo** estrutura (ignorada).

*modo*<br/>
A nova largura do fluxo: positiva para caractere largo, negativa para byte e zero para deixar inalterado. (Este valor é ignorado.)

## <a name="return-value"></a>Valor de retorno

Essa função retorna atualmente apenas *modo*.

## <a name="remarks"></a>Comentários

A versão atual dessa função não está em conformidade com o Padrão.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fwide**|\<wchar.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).