---
title: _findclose | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _findclose
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _findclose
- findclose
dev_langs:
- C++
helpviewer_keywords:
- _findclose function
- findclose function
ms.assetid: 9216c573-0878-444c-b5d7-cdaf16fb9163
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 89c1f515bb072c649a93b77e49b500ea4636e423
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="findclose"></a>_findclose

Fecha o identificador de pesquisa especificado e libera os recursos associados.

## <a name="syntax"></a>Sintaxe

```C
int _findclose(
   intptr_t handle
);
```

### <a name="parameters"></a>Parâmetros

*Identificador*<br/>
Identificador de pesquisa retornado por uma chamada anterior a **FindFirst**.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **FindClose** retornará 0. Caso contrário, retornará -1 e define **errno** para **ENOENT**, indicando que a correspondência não mais arquivos pôde ser encontrado.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_findclose**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Chamadas do sistema](../../c-runtime-library/system-calls.md)<br/>
[Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md)<br/>
