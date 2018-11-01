---
title: Erro do compilador C3861
ms.date: 03/23/2018
f1_keywords:
- C3861
helpviewer_keywords:
- C3861
ms.assetid: 0a1eee30-b3db-41b1-b1e5-35949c3924d7
ms.openlocfilehash: 4ebfd3b0129e25cf543cac803a3b33fb074f3d70
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530800"
---
# <a name="compiler-error-c3861"></a>Erro do compilador C3861

> '*identificador*': identificador não encontrado

O compilador não pôde resolver uma referência a um identificador, mesmo usando a pesquisa dependente de argumento.

## <a name="remarks"></a>Comentários

Para corrigir esse erro, compare o uso de *identificador* à declaração de identificador de caso e a ortografia. Verifique [operadores de resolução de escopo](../../cpp/scope-resolution-operator.md) e o namespace [diretivas using](../../cpp/namespaces-cpp.md#using_directives) estão sendo usadas corretamente. Se o identificador for declarado em um arquivo de cabeçalho, verifique se o cabeçalho incluído antes do identificador é referenciado. Se o identificador deve ser visível externamente, certifique-se de que ela é declarada em qualquer arquivo de origem que o utiliza. Verifique também a declaração do identificador ou a definição não é excluída por [diretivas de compilação condicional](../../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).

As alterações para remover funções obsoletas da biblioteca em tempo de execução C no Visual Studio 2015 podem causar c3861:. Para resolver esse erro, remova as referências a essas funções ou substituí-los com seus alternativas seguras, se houver. Para obter mais informações, consulte [funções obsoletas](../../c-runtime-library/obsolete-functions.md).

Se o erro c3861: aparecer após a migração de projeto de versões anteriores do compilador, você pode ter problemas relacionados a versões do Windows com suporte. Visual C++ não oferece mais suporte ao direcionamento de Windows 95, Windows 98, Windows ME, Windows NT ou Windows 2000. Se suas macros **WINVER** ou **_WIN32_WINNT** forem atribuídas a uma dessas versões do Windows, você deverá modificar as macros. Para obter mais informações, consulte [modificando WINVER e _WIN32_WINNT](../../porting/modifying-winver-and-win32-winnt.md).

## <a name="examples"></a>Exemplos

### <a name="undefined-identifier"></a>Identificador indefinido

O exemplo a seguir gera c3861: porque o identificador não está definido.

```cpp
// C3861.cpp
void f2(){}
int main() {
   f();    // C3861
   f2();   // OK
}
```

### <a name="identifier-not-in-scope"></a>Identificador não está no escopo

O exemplo a seguir gera c3861: como um identificador só é visível no escopo de arquivo de sua definição, a menos que ela é declarada em outros arquivos de origem que usá-lo.

```cpp
// C3861_a1.cpp
// Compile with: cl /EHsc /W4 C3861_a1.cpp C3861_a2.cpp
#include <iostream>
// Uncomment the following line to fix:
// int f();  // declaration makes external function visible
int main() {
   std::cout << f() << std::endl;    // C3861
}
```

```cpp
// C3861_a2.cpp
int f() {  // declared and defined here
   return 42;
}
```

### <a name="namespace-qualification-required"></a>Qualificação de Namespace necessárias

Classes de exceção na biblioteca padrão C++ requerem o `std` namespace.

```cpp
// C3861_b.cpp
// compile with: /EHsc
#include <iostream>
int main() {
   try {
      throw exception("Exception");   // C3861
      // try the following line instead
      // throw std::exception("Exception");
   }
   catch (...) {
      std::cout << "caught an exception" << std::endl;
   }
}
```

### <a name="obsolete-function-called"></a>Chamada de função obsoleta

Funções obsoletas foram removidas da biblioteca do CRT.

```cpp
// C3861_c.cpp
#include <stdio.h>
int main() {
   char line[21]; // room for 20 chars + '\0'
   gets( line );  // C3861
   // Use gets_s instead.
   printf( "The line entered was: %s\n", line );
}
```

### <a name="adl-and-friend-functions"></a>Funções ADL e friend

O exemplo a seguir gera C3767 porque o compilador não pode usar a pesquisa dependente de argumento para `FriendFunc`:

```cpp
namespace N {
   class C {
      friend void FriendFunc() {}
      friend void AnotherFriendFunc(C* c) {}
   };
}

int main() {
   using namespace N;
   FriendFunc();   // C3861 error
   C* pC = new C();
   AnotherFriendFunc(pC);   // found via argument-dependent lookup
}
```

Para corrigir o erro, declare o amigo no escopo de classe e defini-lo no escopo de namespace:

```cpp
class MyClass {
   int m_private;
   friend void func();
};

void func() {
   MyClass s;
   s.m_private = 0;
}

int main() {
   func();
}
```
