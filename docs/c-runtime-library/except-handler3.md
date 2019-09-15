---
title: _except_handler3
ms.date: 11/04/2016
api_name:
- _except_handler3
api_location:
- msvcrt.dll
- msvcr90.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr100.dll
- msvcr110.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _except_handler3
- except_handler3
helpviewer_keywords:
- _except_handler3 function
- except_handler3 function
ms.assetid: b0c64898-0ae5-48b7-9724-80135a0813e2
ms.openlocfilehash: 5e1dbab97e0f193d4ff59c19229d2c00e2cd7d6a
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70944478"
---
# <a name="_except_handler3"></a>_except_handler3

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

## <a name="return-value"></a>Valor de retorno

Caso uma exceção deva ser desconsiderada, retorna `DISPOSITION_DISMISS`. Caso a exceção deva ser passada um nível acima para os manipuladores de exceção de encapsulamento, retorna `DISPOSITION_CONTINUE_SEARCH`.

## <a name="remarks"></a>Comentários

Caso encontre um manipulador de exceção apropriado, o método passa a exceção para o manipulador. Nessa situação, esse método não retorna ao código que o chamou e o valor retornado é irrelevante.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)
