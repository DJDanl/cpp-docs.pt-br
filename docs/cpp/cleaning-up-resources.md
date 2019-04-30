---
title: Limpando recursos
ms.date: 11/04/2016
helpviewer_keywords:
- termination handlers [C++], cleaning up resources
- exception handling [C++], cleaning up resources
- C++ exception handling, termination handlers
- resources [C++], cleaning up
- exception handling [C++], cleanup code
- try-catch keyword [C++], termination handlers
ms.assetid: 65753efe-6a27-4750-b90c-50635775c1b6
ms.openlocfilehash: 0db21b20b94dc1a3f347bd848c999a961398759b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386116"
---
# <a name="cleaning-up-resources"></a>Limpando recursos

Durante a execução do manipulador de término, talvez você não saiba quais recursos foram realmente alocados antes que o manipulador de término seja chamado. É possível que o **Try** bloco de instrução foi interrompido antes que todos os recursos alocados, para que nem todos os recursos que foram abertos.

Portanto, para garantir, você deve verificar quais recursos estão realmente abertos antes de continuar com a limpeza da manipulação de término. Um procedimento recomendado é fazer o seguinte:

1. Inicialize os identificadores como NULL.

1. No **Try** instrução bloquear, aloque recursos. Os identificadores são definidos como valores positivos conforme o recurso é alocado.

1. No **Finally** bloco de instrução, libere cada recurso cuja correspondente variável handle ou flag é diferente de zero ou not NULL.

## <a name="example"></a>Exemplo

Por exemplo, o código a seguir usa um manipulador de término para fechar três arquivos e um bloco de memória que foram alocados na **Try** bloco de instrução. Antes de limpar um recurso, o código primeiro verifica se o recurso foi alocado.

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

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)