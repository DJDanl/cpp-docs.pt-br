---
title: Erro do compilador C3675
ms.date: 11/04/2016
f1_keywords:
- C3675
helpviewer_keywords:
- C3675
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
ms.openlocfilehash: c154a0fe1989c92bb5e07c0710d3846883d1a113
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50546299"
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