---
title: Usando VERIFY em vez de ASSERT
ms.date: 05/06/2019
helpviewer_keywords:
- ASSERT statements
- debugging [MFC], ASSERT statements
- VERIFY macro
- assertions, troubleshooting ASSERT statements
- debugging assertions
- assertions, debugging
ms.assetid: 4c46397b-3fb1-49c1-a09b-41a72fae3797
ms.openlocfilehash: bfc0847677ae232fef67ab6200c626472f042bdb
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438616"
---
# <a name="using-verify-instead-of-assert"></a>Usando VERIFY em vez de ASSERT

Suponha que, quando você executar a versão de depuração do aplicativo MFC, não haja nenhum problema. No entanto, a versão de lançamento do mesmo aplicativo falha, retorna resultados incorretos e/ou exibe algum outro comportamento anormal.

Esse problema pode ser causado quando você coloca um código importante em uma instrução ASSERT para verificar se ele é executado corretamente. Como as instruções ASSERT são comentadas em uma compilação de versão de um programa MFC, o código não é executado em uma compilação de versão.

Se você estiver usando o ASSERT para confirmar que uma chamada de função foi bem-sucedida, considere usar [Verify](../mfc/reference/diagnostic-services.md#verify) em vez disso. A macro VERIFY avalia seus próprios argumentos nas compilações de depuração e de versão do aplicativo.

Outra técnica preferida é atribuir o valor de retorno da função a uma variável temporária e, em seguida, testar a variável em uma instrução ASSERT.

Examine o fragmento de código a seguir:

```
enum {
    sizeOfBuffer = 20
};
char *buf;
ASSERT(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));
strcpy_s( buf, sizeOfBuffer, "Hello, World" );
free( buf );
```

Esse código é executado perfeitamente em uma versão de depuração de um aplicativo MFC. Se a chamada para `calloc( )` falhar, será exibida uma mensagem de diagnóstico que inclui o arquivo e o número da linha. No entanto, em uma compilação de varejo de um aplicativo MFC:

- a chamada para `calloc( )` nunca ocorre, deixando `buf` não inicializado ou

- `strcpy_s( )`copia "`Hello, World`" em uma parte aleatória da memória, possivelmente falhando no aplicativo ou fazendo com que o sistema pare de responder ou

- `free()`Tenta liberar memória que nunca foi alocada.

Para usar o ASSERT corretamente, o exemplo de código deve ser alterado para o seguinte:

```
enum {
    sizeOfBuffer = 20
};
char *buf;
buf = (char *) calloc(sizeOfBuffer, sizeof(char) );
ASSERT( buf != NULL );
strcpy_s( buf, sizeOfBuffer, "Hello, World" );
free( buf );
```

Ou então, você pode usar VERIFY:

```
enum {
    sizeOfBuffer = 20
};
char *buf;
VERIFY(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));
strcpy_s( buf, sizeOfBuffer, "Hello, World" );
free( buf );
```

## <a name="see-also"></a>Confira também

[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
