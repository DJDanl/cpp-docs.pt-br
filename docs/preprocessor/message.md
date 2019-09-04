---
title: Pragma message
ms.date: 08/29/2019
f1_keywords:
- message_CPP
- vc-pragma.message
helpviewer_keywords:
- message pragma
- pragmas, message
ms.assetid: 67414f25-ed47-4079-a5dc-21d9d1a39754
ms.openlocfilehash: 48605fbef3b6d81c140e663e950429cd3dcf9b19
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218797"
---
# <a name="message-pragma"></a>Pragma message

Envia uma literal de cadeia de caracteres para a saída padrão sem terminar a compilação.

## <a name="syntax"></a>Sintaxe

> **mensagem de #pragma (** *cadeia de caracteres de mensagem* **)**

## <a name="remarks"></a>Comentários

Um uso típico do pragma da **mensagem** é para exibir mensagens informativas em tempo de compilação.

O parâmetro *Message-String* pode ser uma macro que se expande para um literal de cadeia de caracteres e você pode concatenar essas macros com literais de cadeia de caracteres em qualquer combinação.

Se você usar uma macro predefinida no pragma da **mensagem** , a macro deverá retornar uma cadeia de caracteres. Caso contrário, você precisará converter a saída da macro em uma cadeia de caracteres.

O fragmento de código a seguir usa o pragma da **mensagem** para exibir mensagens durante a compilação:

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
