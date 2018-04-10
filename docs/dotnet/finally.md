---
title: Por fim | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- finally keyword [C++]
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: dd357c8eeed9eddc6940ce02de6e5d2b4f8c68d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="finally"></a>finally
Além `try` e `catch` cláusulas, suporte de tratamento de exceções de CLR um `finally` cláusula. A semântica é idêntica do `__finally` bloco em (SEH) de tratamento de exceções estruturado. Um `__finally` bloco pode seguir um `try` ou `catch` bloco.  
  
## <a name="remarks"></a>Comentários  
 A finalidade de `finally` bloco é limpar os recursos que, após a exceção ocorreu. Observe que o `finally` bloco sempre é executado, mesmo se nenhuma exceção foi lançada. O `catch` bloco é executado apenas se uma exceção gerenciada é gerada em associado `try` bloco.  
  
 `finally`é uma palavra-chave contextual; consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
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