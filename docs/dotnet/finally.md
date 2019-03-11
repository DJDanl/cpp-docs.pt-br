---
title: finally
ms.date: 11/04/2016
helpviewer_keywords:
- finally keyword [C++]
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
ms.openlocfilehash: cb2bbdb36a102c7ef8974a9ac210473f2306f5d6
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57746767"
---
# <a name="finally"></a>finally

Além `try` e `catch` cláusulas, dá suporte a tratamento de exceção do CLR um `finally` cláusula. A semântica é idêntica a `__finally` bloquear (SEH) de manipulação de exceção estruturada. Um `__finally` bloco pode seguir uma `try` ou `catch` bloco.

## <a name="remarks"></a>Comentários

A finalidade de `finally` bloco é limpar todos os recursos, após a exceção ocorreu. Observe que o `finally` bloco sempre será executado mesmo se nenhuma exceção foi lançada. O `catch` bloco é executado somente se uma exceção gerenciada é gerada dentro associado `try` bloco.

`finally` é uma palavra-chave contextual; ver [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra um simples `finally` bloco:

```
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

[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)
