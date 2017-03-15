---
title: "finally | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave finally [C++]"
ms.assetid: b55f3c8e-1af0-43e8-bcfb-99c3685d2578
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# finally
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além de `try` e cláusulas de `catch` , a manipulação de exceção de CLR oferece suporte a uma cláusula de `finally` .  A semântica é idêntica ao bloco de `__finally` a manipulação de exceção estruturado \(SEH\).  Um bloco de `__finally` pode seguir um bloco de `try` ou de `catch` .  
  
## Comentários  
 O propósito do bloco de `finally` é limpar todos os recursos restantes depois da exceção ocorreu.  Observe que o bloco de `finally` é executado sempre, mesmo se nenhuma exceção foi gerada.  O bloco de `catch` é executado apenas se uma exceção gerenciada é gerada dentro do bloco associado de `try` .  
  
 `finally` é uma palavra\-chave sensível ao contexto; consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir demonstra um bloco simples de `finally` :  
  
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
  
  **na captura**  
**MyException**  
**em finalmente**   
## Consulte também  
 [Exception Handling](../windows/exception-handling-cpp-component-extensions.md)