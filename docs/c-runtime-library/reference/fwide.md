---
title: fwide
ms.date: 11/04/2016
api_name:
- fwide
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
- DLLExport
topic_type:
- apiref
f1_keywords:
- fwide
helpviewer_keywords:
- fwide function
ms.assetid: a4641f5b-d74f-4946-95d5-53a64610d28d
ms.openlocfilehash: 652aee03bfb5504a51d74efb326cc7a3d7c28649
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171197"
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

### <a name="parameters"></a>parâmetros

*fluxo*<br/>
Ponteiro para a estrutura do **arquivo** (ignorado).

*mode*<br/>
A nova largura do fluxo: positiva para caractere largo, negativa para byte e zero para deixar inalterado. (Este valor é ignorado.)

## <a name="return-value"></a>Valor retornado

Essa função atualmente apenas retorna o *modo*.

## <a name="remarks"></a>Comentários

A versão atual dessa função não está em conformidade com o Padrão.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fwide**|\<wchar.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).
