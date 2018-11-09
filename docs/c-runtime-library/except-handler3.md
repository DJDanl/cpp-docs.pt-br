---
title: _except_handler3
ms.date: 11/04/2016
apiname:
- _except_handler3
apilocation:
- msvcrt.dll
- msvcr90.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr100.dll
- msvcr110.dll
apitype: DLLExport
f1_keywords:
- _except_handler3
- except_handler3
helpviewer_keywords:
- _except_handler3 function
- except_handler3 function
ms.assetid: b0c64898-0ae5-48b7-9724-80135a0813e2
ms.openlocfilehash: 144bf25495d803a4db42ab45fcb0b101b09fe7cc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50613857"
---
# <a name="excepthandler3"></a>_except_handler3

Função CRT interna. Usada por uma estrutura para encontrar o manipulador de exceção apropriado para processar a exceção atual.

## <a name="syntax"></a>Sintaxe

```
int _except_handler3(
   PEXCEPTION_RECORD exception_record,
   PEXCEPTION_REGISTRATION registration,
   PCONTEXT context,
   PEXCEPTION_REGISTRATION dispatcher
);
```

#### <a name="parameters"></a>Parâmetros

*exception_record*<br/>
[in] Informações sobre a exceção específica.

*registration*<br/>
[in] O registro que indica qual tabela de escopo deve ser usada para encontrar o manipulador de exceção.

*context*<br/>
[in] Reservado.

*dispatcher*<br/>
[in] Reservado.

## <a name="return-value"></a>Valor retornado

Caso uma exceção deva ser desconsiderada, retorna `DISPOSITION_DISMISS`. Caso a exceção deva ser passada um nível acima para os manipuladores de exceção de encapsulamento, retorna `DISPOSITION_CONTINUE_SEARCH`.

## <a name="remarks"></a>Comentários

Caso encontre um manipulador de exceção apropriado, o método passa a exceção para o manipulador. Nessa situação, esse método não retorna ao código que o chamou e o valor retornado é irrelevante.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)