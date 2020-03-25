---
title: Erro do compilador C2558
ms.date: 11/04/2016
f1_keywords:
- C2558
helpviewer_keywords:
- C2558
ms.assetid: 822b701e-dcae-423a-b21f-47f36aff9c90
ms.openlocfilehash: 93b6e414f26c56702a1c7ac12863cbcd5063b570
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177489"
---
# <a name="compiler-error-c2558"></a>Erro do compilador C2558

'identificador': nenhum construtor de cópia disponível ou construtor de cópia declarado como 'explicit'

Um construtor de cópia inicializa um objeto a partir de outro objeto do mesmo tipo. (Ele faz uma cópia do objeto.) O compilador gera um construtor de cópia padrão se você não definir nenhum construtor.

### <a name="to-fix-this-error"></a>Para corrigir o erro

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é `private`. Na maioria dos casos, uma classe que tem um construtor de cópia `private` não deve ser copiada. Uma técnica de programação comum declara um construtor de cópia `private` para evitar o uso direto de uma classe. A classe pode ser inútil isoladamente ou exigir outra classe para funcionar corretamente.

   Se você determinar que é seguro usar uma classe que tem um construtor de cópia `private`, derive uma nova classe da classe que tem o construtor `private` e torne um construtor de cópia `public` ou de `protected` disponível na nova classe. Use a classe derivada em vez da original.

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é explicit. Declarar um construtor de cópia como `explicit` evita passar/retornar objetos de uma classe para/de funções. Para obter mais informações sobre construtores explícitos, consulte [conversões de tipo definidas pelo usuário](../../cpp/user-defined-type-conversions-cpp.md).

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma instância da classe declarada como `const` usando um construtor de cópia que não usa um parâmetro de referência `const`. Declare o construtor de cópia com uma referência de tipo `const` em vez de uma referência de tipo não const.
