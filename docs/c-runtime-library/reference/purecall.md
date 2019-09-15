---
title: _purecall
ms.date: 11/04/2016
api_name:
- _purecall
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
ms.openlocfilehash: 5d62ec30731ce26c4683afc88474d4bddb63a697
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70950162"
---
# <a name="_purecall"></a>_purecall

O manipulador de erro de chamada de função pura virtual padrão. O compilador gera código para chamar esta função quando uma função membro pura virtual é chamada.

## <a name="syntax"></a>Sintaxe

```C
extern "C" int __cdecl _purecall();
```

## <a name="remarks"></a>Comentários

A função **_purecall** é um detalhe de implementação específico da Microsoft do compilador C++ da Microsoft. Essa função não se destina a ser chamada diretamente pelo seu código e não tem nenhuma declaração de cabeçalho público. Ela está documentada aqui porque é uma exportação pública da Biblioteca de Tempo de Execução C.

Uma chamada para uma função virtual pura é um erro porque não tem nenhuma implementação. O compilador gera código para invocar a função de manipulador de erro **_purecall** quando uma função virtual pura é chamada. Por padrão, o **_purecall** encerra o programa. Antes de encerrar, a função **_purecall** invocará uma função **_purecall_handler** se uma tiver sido definida para o processo. Você pode instalar sua própria função de manipulador de erro para chamadas de função pura virtual, para capturá-las para fins de depuração ou relatório. Para usar seu próprio manipulador de erro, crie uma função que tenha a assinatura **_purecall_handler** e, em seguida, use [_set_purecall_handler](get-purecall-handler-set-purecall-handler.md) para torná-la o manipulador atual.

## <a name="requirements"></a>Requisitos

A função **_purecall** não tem uma declaração de cabeçalho. O typedef **_purecall_handler** é definido em \<STDLIB. h >.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_purecall_handler, _set_purecall_handler](get-purecall-handler-set-purecall-handler.md)<br/>
