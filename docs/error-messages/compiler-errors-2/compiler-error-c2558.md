---
title: Erro do compilador C2558
ms.date: 11/04/2016
f1_keywords:
- C2558
helpviewer_keywords:
- C2558
ms.assetid: 822b701e-dcae-423a-b21f-47f36aff9c90
ms.openlocfilehash: 2504b42f49ccb040f676f0aead8f243d33c7dd1a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207739"
---
# <a name="compiler-error-c2558"></a>Erro do compilador C2558

'identificador': nenhum construtor de cópia disponível ou construtor de cópia declarado como 'explicit'

Um construtor de cópia inicializa um objeto a partir de outro objeto do mesmo tipo. (Ele faz uma cópia do objeto.) O compilador gera um construtor de cópia padrão se você não definir nenhum construtor.

### <a name="to-fix-this-error"></a>Para corrigir esse erro

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é **`private`** . Na maioria dos casos, uma classe que tem um **`private`** Construtor de cópia não deve ser copiada. Uma técnica de programação comum declara um **`private`** Construtor de cópia para evitar o uso direto de uma classe. A classe pode ser inútil isoladamente ou exigir outra classe para funcionar corretamente.

   Se você determinar que é seguro usar uma classe que tenha um construtor de **`private`** cópia, derive uma nova classe da classe que tem o **`private`** Construtor e torne um **`public`** Construtor de **`protected`** cópia disponível na nova classe. Use a classe derivada em vez da original.

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é explícito. Declarar um construtor de cópia como **`explicit`** impede a passagem/retorno de objetos de uma classe de/para funções. Para obter mais informações sobre construtores explícitos, consulte [conversões de tipo definidas pelo usuário](../../cpp/user-defined-type-conversions-cpp.md).

1. O problema pode ocorrer quando é feita uma tentativa de copiar uma instância de classe declarada **`const`** usando um construtor de cópia que não usa um **`const`** parâmetro de referência. Declare o construtor de cópia com uma **`const`** referência de tipo em vez de uma referência de tipo não const.
