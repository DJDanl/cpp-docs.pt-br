---
title: fwide
ms.date: 11/04/2016
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
helpviewer_keywords:
- fwide function
ms.assetid: a4641f5b-d74f-4946-95d5-53a64610d28d
ms.openlocfilehash: d992ebc527744beeb4ef14175e3f10646a77a064
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62287610"
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

*stream*<br/>
Ponteiro para **arquivo** estrutura (ignorada).

*modo*<br/>
A nova largura do fluxo: positiva para caractere largo, negativa para byte e zero para deixar inalterado. (Este valor é ignorado.)

## <a name="return-value"></a>Valor de retorno

Essa função atualmente retorna somente *modo*.

## <a name="remarks"></a>Comentários

A versão atual dessa função não está em conformidade com o Padrão.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fwide**|\<wchar.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).