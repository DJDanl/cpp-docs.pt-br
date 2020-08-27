---
title: Limpando recursos
description: Como liberar recursos durante um manipulador de encerramento para manipulação de exceção estruturada.
ms.date: 08/24/2020
helpviewer_keywords:
- termination handlers [C++], cleaning up resources
- exception handling [C++], cleaning up resources
- C++ exception handling, termination handlers
- resources [C++], cleaning up
- exception handling [C++], cleanup code
- try-catch keyword [C++], termination handlers
ms.assetid: 65753efe-6a27-4750-b90c-50635775c1b6
ms.openlocfilehash: dae92a515db25b9985a890d7d08cc213f88ecfea
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898440"
---
# <a name="cleaning-up-resources"></a>Limpando recursos

Durante a execução do manipulador de encerramento, talvez você não saiba quais recursos foram adquiridos antes de o manipulador de encerramento ser chamado. É possível que o **`__try`** bloco de instruções tenha sido interrompido antes de todos os recursos serem adquiridos, para que nem todos os recursos fossem abertos.

Para ser seguro, você deve verificar para ver quais recursos estão abertos antes de prosseguir com a limpeza do tratamento de encerramento. Um procedimento recomendado é fazer o seguinte:

1. Inicialize os identificadores como NULL.

1. No **`__try`** bloco de instruções, adquira recursos. Os identificadores são definidos como valores positivos conforme o recurso é adquirido.

1. No **`__finally`** bloco de instruções, libere cada recurso cuja variável identificador ou sinalizador correspondente seja diferente de zero ou não seja nulo.

## <a name="example"></a>Exemplo

Por exemplo, o código a seguir usa um manipulador de encerramento para fechar três arquivos e liberar um bloco de memória. Esses recursos foram adquiridos no **`__try`** bloco de instruções. Antes de limpar um recurso, o código verifica primeiro se o recurso foi adquirido.

```cpp
// exceptions_Cleaning_up_Resources.cpp
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>

void fileOps() {
   FILE  *fp1 = NULL,
         *fp2 = NULL,
         *fp3 = NULL;
   LPVOID lpvoid = NULL;
   errno_t err;

   __try {
      lpvoid = malloc( BUFSIZ );

      err = fopen_s(&fp1, "ADDRESS.DAT", "w+" );
      err = fopen_s(&fp2, "NAMES.DAT", "w+" );
      err = fopen_s(&fp3, "CARS.DAT", "w+" );
   }
   __finally {
      if ( fp1 )
         fclose( fp1 );
      if ( fp2 )
         fclose( fp2 );
      if ( fp3 )
         fclose( fp3 );
      if ( lpvoid )
         free( lpvoid );
   }
}

int main() {
   fileOps();
}
```

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
