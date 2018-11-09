---
title: _setjmp3
ms.date: 11/04/2016
apiname:
- _setjmp3
apilocation:
- msvcrt.dll
- msvcr90.dll
- msvcr110.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- setjmp3
- _setjmp3
helpviewer_keywords:
- _setjmp3 function
- setjmp3 function
ms.assetid: 6129c2f3-8bac-4fdb-a827-44e1eebba500
ms.openlocfilehash: 4509738f8e0128e2f9277e744a5965f557f65439
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50563992"
---
# <a name="setjmp3"></a>_setjmp3

Função CRT interna. Uma nova implementação da função `setjmp`.

## <a name="syntax"></a>Sintaxe

```
int _setjmp3(
   OUT jmp_buf env,
   int count,
   (optional parameters)
);
```

#### <a name="parameters"></a>Parâmetros

*env*<br/>
[out] Endereço do buffer para armazenar informações de estado.

*count*<br/>
[in] O número de `DWORD`s adicionais de informações armazenadas no `optional parameters`.

*parâmetros opcionais*<br/>
[in] Dados adicionais enviados por push pelo `setjmp` intrínseco. O primeiro `DWORD` é um ponteiro de função usado para desenrolar dados extras e retornar para um estado de registro não volátil. O segundo `DWORD` é o nível de tentativa a ser restaurado. Todos os demais dados são salvos na matriz de dados genérica no `jmp_buf`.

## <a name="return-value"></a>Valor retornado

Sempre retorna 0.

## <a name="remarks"></a>Comentários

Não use essa função em um programa C++. É uma função intrínseca que não tem suporte para C++. Para obter mais informações sobre como usar o `setjmp`, consulte [Usando setjmp/longjmp](../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[setjmp](../c-runtime-library/reference/setjmp.md)