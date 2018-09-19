---
title: Erro do compilador C3675 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3675
dev_langs:
- C++
helpviewer_keywords:
- C3675
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c4b6656753ab4a611dcb80d1473e0b44bf47a270
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094774"
---
# <a name="compiler-error-c3675"></a>Erro do compilador C3675

'function': é reservado porque 'propriedade' está definida

Quando você declara uma propriedade simples, o compilador gera get e métodos de acessador set e aqueles nomes estão presentes no escopo do seu programa.  Os nomes gerados pelo compilador são formados acrescentando _ e set _ ao nome da propriedade.  Portanto, você não pode declarar funções com o mesmo nome que os acessadores gerado pelo compilador.

Ver [propriedade](../../windows/property-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3675.

```
// C3675.cpp
// compile with: /clr /c
ref struct C {
public:
   property int Size;
   int get_Size() { return 0; }   // C3675
};
```