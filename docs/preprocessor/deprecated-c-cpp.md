---
title: pragma preterido
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.deprecated
- deprecated_CPP
helpviewer_keywords:
- deprecated pragma
- pragmas, deprecated
ms.assetid: 9c046f12-7875-499a-8d5d-12f8642fed2d
ms.openlocfilehash: 2e76d1c53cb900c108e2839a9aad17b330143a5d
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222408"
---
# <a name="deprecated-pragma"></a>pragma preterido

O pragma preterido permite que você indique que uma função, tipo ou qualquer outro identificador pode não ter mais suporte em uma versão futura ou não deve mais ser usado.

> [!NOTE]
> Para obter informações sobre o atributo `[[deprecated]]` c++ 14 e orientação sobre quando usar esse atributo em vez do modificador `__declspec(deprecated)` da Microsoft ou o pragma preterido, consulte [atributos em C++ ](../cpp/attributes.md).

## <a name="syntax"></a>Sintaxe

> **#pragma preterido (** *identifier1* [ **,** *identifier2* ...] **)**

## <a name="remarks"></a>Comentários

Quando o compilador encontra um identificador especificado por um pragma **substituído** , ele emite o aviso do compilador [C4995](../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md).

Você pode preterir nomes de macro. Coloque o nome da macro entre aspas. Caso contrário, haverá uma expansão na macro.

Como o pragma preterido funciona em todos os identificadores correspondentes e não leva em conta as assinaturas, não é a melhor opção para a substituição de versões específicas de funções sobrecarregadas. Qualquer nome de função correspondente que é colocado no escopo dispara o aviso.

Recomendamos que você use o atributo `[[deprecated]]` c++ 14, quando possível, em vez do pragma preterido. O modificador de Declaração [_ declspec (preterido)](../cpp/deprecated-cpp.md) específico da Microsoft também é uma opção melhor em muitos casos do que o pragma preterido. O `[[deprecated]]` atributo e `__declspec(deprecated)` o modificador permitem que você especifique o status preterido para formulários específicos de funções sobrecarregadas. O aviso de diagnóstico só aparece em referências à função sobrecarregada específica à qual o atributo ou o modificador se aplica.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_deprecated.cpp
// compile with: /W3
#include <stdio.h>
void func1(void) {
}

void func2(void) {
}

int main() {
   func1();
   func2();
   #pragma deprecated(func1, func2)
   func1();   // C4995
   func2();   // C4995
}
```

O exemplo a seguir mostra como preterir uma classe:

```cpp
// pragma_directive_deprecated2.cpp
// compile with: /W3
#pragma deprecated(X)
class X {  // C4995
public:
   void f(){}
};

int main() {
   X x;   // C4995
}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)