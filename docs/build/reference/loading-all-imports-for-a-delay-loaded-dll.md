---
title: Carregando todas as importações para uma DLL carregada com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- __HrLoadAllImportsForDll linker option
ms.assetid: 975fcd97-1a56-4a16-9698-e1a249d2d592
ms.openlocfilehash: a144f3d4e0d6dbf306938dcc3fddd4faca73c17c
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421162"
---
# <a name="loading-all-imports-for-a-delay-loaded-dll"></a>Carregando todas as importações para uma DLL carregada com atraso

O **hrloadallimportsfordll** função, que é definida no delayhlp.cpp, instrui o vinculador para carregar todas as importações de uma DLL que foi especificada com o [/delayload](../../build/reference/delayload-delay-load-import.md) a opção de vinculador.

Carregando todas as importações permite que você coloque em um único lugar no seu código de tratamento de erros e não precisa usar em torno de chamadas reais para as importações de tratamento de exceções. Isso também evita uma situação em que seu aplicativo falha parcialmente por meio de um processo como resultado o código auxiliar apresentar falha ao carregar uma importação.

Chamando **hrloadallimportsfordll** não altera o comportamento de erro e ganchos tratamento; veja [tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md) para obter mais informações.

O nome da DLL passado para **hrloadallimportsfordll** é comparado com o nome armazenado dentro da própria DLL e diferencia maiusculas de minúsculas.

O exemplo a seguir mostra como chamar **hrloadallimportsfordll**:

```
if (FAILED(__HrLoadAllImportsForDll("delay1.dll"))) {
   printf ( "failed on snap load, exiting\n" );
   exit(2);
}
```

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)
