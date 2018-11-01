---
title: mensagem
ms.date: 11/04/2016
f1_keywords:
- message_CPP
- vc-pragma.message
helpviewer_keywords:
- message pragma
- pragmas, message
ms.assetid: 67414f25-ed47-4079-a5dc-21d9d1a39754
ms.openlocfilehash: a55721fb954cf9383022b4fc8e84327ea4c772e7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50627377"
---
# <a name="message"></a>mensagem
Envia uma literal de cadeia de caracteres para a saída padrão sem terminar a compilação.

## <a name="syntax"></a>Sintaxe

```
#pragma message( messagestring )
```

## <a name="remarks"></a>Comentários

Um uso típico de **mensagem** pragma é exibir mensagens informativas em tempo de compilação.

O *messagestring* parâmetro pode ser uma macro que se expande para um literal de cadeia de caracteres, e você pode concatenar essas macros com literais de cadeia de caracteres em qualquer combinação.

Se você usar uma macro predefinida na **mensagem** pragma, a macro deverá retornar uma cadeia de caracteres, caso contrário, será necessário converter a saída da macro em uma cadeia de caracteres.

O fragmento de código a seguir usa o **mensagem** pragma para exibir mensagens durante a compilação:

```cpp
// pragma_directives_message1.cpp
// compile with: /LD
#if _M_IX86 >= 500
#pragma message("_M_IX86 >= 500")
#endif

#pragma message("")

#pragma message( "Compiling " __FILE__ )
#pragma message( "Last modified on " __TIMESTAMP__ )

#pragma message("")

// with line number
#define STRING2(x) #x
#define STRING(x) STRING2(x)

#pragma message (__FILE__ "[" STRING(__LINE__) "]: test")

#pragma message("")
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)