---
title: finally
ms.date: 11/04/2016
helpviewer_keywords:
- finally keyword [C++]
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
ms.openlocfilehash: b3331c17fc2313cbd6146db3beb015cd8d8c1eeb
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221452"
---
# <a name="finally"></a>finally

Além das **`try`** **`catch`** cláusulas e, a manipulação de exceção do CLR dá suporte a uma **`finally`** cláusula. A semântica é idêntica ao **`__finally`** bloco no SEH (manipulação de exceção estruturada). Um **`__finally`** bloco pode seguir um **`try`** **`catch`** bloco ou.

## <a name="remarks"></a>Comentários

A finalidade do **`finally`** bloco é limpar todos os recursos deixados depois que a exceção ocorreu. Observe que o **`finally`** bloco é sempre executado, mesmo que nenhuma exceção tenha sido lançada. O **`catch`** bloco só será executado se uma exceção gerenciada for lançada dentro do **`try`** bloco associado.

`finally`é uma palavra-chave sensível ao contexto; consulte [palavras-chave sensíveis ao contexto](../extensions/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra um **`finally`** bloco simples:

```cpp
// keyword__finally.cpp
// compile with: /clr
using namespace System;

ref class MyException: public System::Exception{};

void ThrowMyException() {
   throw gcnew MyException;
}

int main() {
   try {
      ThrowMyException();
   }
   catch ( MyException^ e ) {
      Console::WriteLine(  "in catch" );
      Console::WriteLine( e->GetType() );
   }
   finally {
      Console::WriteLine(  "in finally" );
   }
}
```

```Output
in catch
MyException
in finally
```

## <a name="see-also"></a>Confira também

[Tratamento de exceção](../extensions/exception-handling-cpp-component-extensions.md)
