---
title: _purecall
ms.date: 4/2/2020
api_name:
- _purecall
- _o__purecall
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
- ntoskrnl.exe
- ucrtbase.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- purecall
- _purecall
helpviewer_keywords:
- _purecall function
- purecall function
ms.assetid: 56135d9b-3403-4e22-822d-e714523801cc
ms.openlocfilehash: 19ad6c2f517d9ddf277a7bdda6e46c7940f0d3f1
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913336"
---
# <a name="_purecall"></a>_purecall

O manipulador de erro de chamada de função pura virtual padrão. O compilador gera código para chamar esta função quando uma função membro pura virtual é chamada.

## <a name="syntax"></a>Sintaxe

```C
extern "C" int __cdecl _purecall();
```

## <a name="remarks"></a>Comentários

A função **_purecall** é um detalhe de implementação específico da Microsoft do compilador do Microsoft C++. Essa função não se destina a ser chamada diretamente pelo seu código e não tem nenhuma declaração de cabeçalho público. Ela está documentada aqui porque é uma exportação pública da Biblioteca de Runtime  C.

Uma chamada para uma função virtual pura é um erro porque não tem nenhuma implementação. O compilador gera código para invocar a **_purecall** função de manipulador de erro quando uma função virtual pura é chamada. Por padrão, **_purecall** encerra o programa. Antes de encerrar, a função **_purecall** invoca uma função **_purecall_handler** se uma tiver sido definida para o processo. Você pode instalar sua própria função de manipulador de erro para chamadas de função pura virtual, para capturá-las para fins de depuração ou relatório. Para usar seu próprio manipulador de erro, crie uma função que tenha a assinatura **_purecall_handler** e, em seguida, use [_set_purecall_handler](get-purecall-handler-set-purecall-handler.md) para torná-la o manipulador atual.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

A função **_purecall** não tem uma declaração de cabeçalho. O typedef **_purecall_handler** é definido no \<> STDLIB. h.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_purecall_handler, _set_purecall_handler](get-purecall-handler-set-purecall-handler.md)<br/>
