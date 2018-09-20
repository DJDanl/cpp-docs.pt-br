---
title: Por fim | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- finally keyword [C++]
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 818ee6736d51303b047cb5a47aae02441557db29
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46447266"
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