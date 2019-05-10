---
title: _purecall
ms.date: 11/04/2016
apiname:
- _purecall
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
- ntoskrnl.exe
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- purecall
- _purecall
helpviewer_keywords:
- _purecall function
- purecall function
ms.assetid: 56135d9b-3403-4e22-822d-e714523801cc
ms.openlocfilehash: df6dde91ccb952e66eb77c841b2b1ace12756b8c
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446635"
---
# <a name="purecall"></a>_purecall

O manipulador de erro de chamada de função pura virtual padrão. O compilador gera código para chamar esta função quando uma função membro pura virtual é chamada.

## <a name="syntax"></a>Sintaxe

```C
extern "C" int __cdecl _purecall();
```

## <a name="remarks"></a>Comentários

O **purecall** função é um detalhe de implementação específico da Microsoft do Microsoft C++ compilador. Essa função não se destina a ser chamada diretamente pelo seu código e não tem nenhuma declaração de cabeçalho público. Ela está documentada aqui porque é uma exportação pública da Biblioteca de Tempo de Execução C.

Uma chamada para uma função virtual pura é um erro porque não tem nenhuma implementação. O compilador gera código para invocar o **purecall** função de manipulador de erro quando uma função virtual pura é chamada. Por padrão, **purecall** encerra o programa. Antes de terminar, o **purecall** função invocará um **_purecall_handler** se uma tiver sido definida para o processo de função. Você pode instalar sua própria função de manipulador de erro para chamadas de função pura virtual, para capturá-las para fins de depuração ou relatório. Para usar seu próprio manipulador de erro, crie uma função que tem o **_purecall_handler** assinatura, em seguida, use [set_purecall_handler](get-purecall-handler-set-purecall-handler.md) para torná-lo o manipulador atual.

## <a name="requirements"></a>Requisitos

O **purecall** a função não tem uma declaração de cabeçalho. O **_purecall_handler** typedef é definido em \<stdlib. h >.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_purecall_handler, _set_purecall_handler](get-purecall-handler-set-purecall-handler.md)<br/>
