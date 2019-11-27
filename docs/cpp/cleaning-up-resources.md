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
ms.openlocfilehash: 225c3ccaf3342f11ad4eb6d6575ad3ac542acfd2
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246644"
---
# <a name="cleaning-up-resources"></a>Limpando recursos

Durante a execução do manipulador de término, talvez você não saiba quais recursos foram realmente alocados antes que o manipulador de término seja chamado. É possível que o bloco de instrução de **__try** tenha sido interrompido antes de todos os recursos serem alocados, para que nem todos os recursos fossem abertos.

Portanto, para garantir, você deve verificar quais recursos estão realmente abertos antes de continuar com a limpeza da manipulação de término. Um procedimento recomendado é fazer o seguinte:

1. Inicialize os identificadores como NULL.

1. No bloco de instrução **__try** , aloque recursos. Os identificadores são definidos como valores positivos conforme o recurso é alocado.

1. No bloco de instrução **__finally** , libere cada recurso cuja variável identificador ou sinalizador correspondente seja diferente de zero ou não seja nulo.

## <a name="example"></a>Exemplo

Por exemplo, o código a seguir usa um manipulador de encerramento para fechar três arquivos e um bloco de memória que foram alocados no bloco de instrução **__try** . Antes de limpar um recurso, o código primeiro verifica se o recurso foi alocado.

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

[Escrevendo um manipulador de encerramento](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)