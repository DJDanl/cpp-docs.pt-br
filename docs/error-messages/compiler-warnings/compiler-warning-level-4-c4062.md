---
title: Compilador aviso (nível 4) C4062
ms.date: 04/05/2019
f1_keywords:
- C4062
helpviewer_keywords:
- C4062
ms.assetid: 36d1c6ae-c917-4b08-bf30-2eb49ee94169
ms.openlocfilehash: 79658afc31565b708cdbd8a88f49b887cdd10cf3
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59237179"
---
# <a name="compiler-warning-level-4-c4062"></a>Compilador aviso (nível 4) C4062

> enumerador '*identificador*'na opção de enumeração'*enumeração*' não é tratado

O enumerador *identificador* não tem nenhum associado `case` manipulador em um `switch` instrução e não há nenhum `default` rótulo que pode capturá-la. O caso ausente pode ser uma falha e é um erro potencial em seu código. Para um aviso relacionado em enumeradores não utilizados no `switch` declarações que têm um `default` case, consulte [C4061](compiler-warning-level-4-c4061.md).

Esse aviso é desativado por padrão. Para obter mais informações sobre como habilitar os avisos são desativados por padrão, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4062 e mostra como corrigi-lo:

```cpp
// C4062.cpp
// compile with: /EHsc /W4
#pragma warning(default : 4062)
enum E { a, b, c };
void func ( E e ) {
   switch(e) {
      case a:
      case b:
   // case c:  // to fix, uncomment this line
      break;   // no default label
   }   // C4062, enumerator 'c' not handled
}

int main() {
}
```

## <a name="see-also"></a>Consulte também

[Aviso do compilador (nível 4) C4061](compiler-warning-level-4-c4061.md)
