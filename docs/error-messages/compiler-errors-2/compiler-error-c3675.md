---
title: Erro do compilador C3675
ms.date: 11/04/2016
f1_keywords:
- C3675
helpviewer_keywords:
- C3675
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
ms.openlocfilehash: e29e536bf89aef887dc043327e4b4596703d0538
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778870"
---
# <a name="compiler-error-c3675"></a>Erro do compilador C3675

'function': é reservado porque 'propriedade' está definida

Quando você declara uma propriedade simples, o compilador gera get e métodos de acessador set e aqueles nomes estão presentes no escopo do seu programa.  Os nomes gerados pelo compilador são formados acrescentando _ e set _ ao nome da propriedade.  Portanto, você não pode declarar funções com o mesmo nome que os acessadores gerado pelo compilador.

Ver [propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações.

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