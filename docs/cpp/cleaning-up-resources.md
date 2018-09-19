---
title: Limpeza de recursos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- termination handlers [C++], cleaning up resources
- exception handling [C++], cleaning up resources
- C++ exception handling, termination handlers
- resources [C++], cleaning up
- exception handling [C++], cleanup code
- try-catch keyword [C++], termination handlers
ms.assetid: 65753efe-6a27-4750-b90c-50635775c1b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df75602dec8b27d12535e41b14fb2d7ca64061d1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076457"
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