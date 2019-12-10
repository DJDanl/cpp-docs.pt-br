---
title: finally
ms.date: 11/04/2016
helpviewer_keywords:
- finally keyword [C++]
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
ms.openlocfilehash: 2574ba5a10bbf5eddc68d6e0265d5dfc99c6d8fc
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988340"
---
# <a name="finally"></a>finally

Além das cláusulas `try` e `catch`, a manipulação de exceção do CLR dá suporte a uma cláusula `finally`. A semântica é idêntica à `__finally` bloco no SEH (manipulação de exceção estruturada). Um bloco de `__finally` pode seguir um `try` ou `catch` bloco.

## <a name="remarks"></a>Comentários

A finalidade do bloco de `finally` é limpar todos os recursos deixados depois que a exceção ocorreu. Observe que o bloco de `finally` é sempre executado, mesmo que nenhuma exceção tenha sido lançada. O bloco de `catch` só será executado se uma exceção gerenciada for lançada dentro do bloco de `try` associado.

`finally` é uma palavra-chave sensível ao contexto; consulte [palavras-chave sensíveis ao contexto](../extensions/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra um bloco de `finally` simples:

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

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../extensions/exception-handling-cpp-component-extensions.md)
