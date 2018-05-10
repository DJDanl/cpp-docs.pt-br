---
title: Efeitos do buffer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- buffers, effects of buffering
- buffering, effects of
ms.assetid: 5d544812-e95e-4f28-b15a-edef3f3414fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c28deb0f5e30d3ec28fac4805a86645bebf27f22
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="effects-of-buffering"></a>Efeitos do buffer

O exemplo a seguir mostra os efeitos do buffer. Você pode esperar o programa imprimir `please wait`, aguardar 5 segundos e, em seguida, continuar. No entanto, ele não necessariamente funcionará dessa forma porque a saída é armazenada em buffer.

```cpp
// effects_buffering.cpp
// compile with: /EHsc
#include <iostream>
#include <time.h>
using namespace std;

int main( )
{
   time_t tm = time( NULL ) + 5;
   cout << "Please wait...";
   while ( time( NULL ) < tm )
      ;
   cout << "\nAll done" << endl;
}
```

Para fazer com que o programa funcione logicamente, o objeto `cout` deve se esvaziar quando a mensagem for exibida. Para liberar um objeto `ostream`, envie-o ao manipulador `flush`:

```cpp
cout <<"Please wait..." <<flush;
```

Esta etapa libera o buffer, garantindo que a mensagem seja impressa antes da espera. Você também pode usar o `endl` manipulator, que libera o buffer e gera um retorno de carro e avanço de linha, ou você pode usar o `cin` objeto. Esse objeto (com os objetos `cerr` ou `clog`) geralmente é vinculado ao objeto `cout`. Assim, qualquer uso de `cin` (ou dos objetos `cerr` ou `clog`) libera o objeto `cout`.

## <a name="see-also"></a>Consulte também

[Fluxos de saída](../standard-library/output-streams.md)<br/>
