---
title: _setjmp3
ms.date: 11/04/2016
api_name:
- _setjmp3
api_location:
- msvcrt.dll
- msvcr90.dll
- msvcr110.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr120.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- setjmp3
- _setjmp3
helpviewer_keywords:
- _setjmp3 function
- setjmp3 function
ms.assetid: 6129c2f3-8bac-4fdb-a827-44e1eebba500
ms.openlocfilehash: d7120ddd10322d0b7391608fd388d9f45c1600e8
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957803"
---
# <a name="_setjmp3"></a>_setjmp3

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

## <a name="return-value"></a>Valor de retorno

Sempre retorna 0.

## <a name="remarks"></a>Comentários

Não use essa função em um programa C++. É uma função intrínseca que não tem suporte para C++. Para obter mais informações sobre como usar o `setjmp`, consulte [Usando setjmp/longjmp](../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[setjmp](../c-runtime-library/reference/setjmp.md)
