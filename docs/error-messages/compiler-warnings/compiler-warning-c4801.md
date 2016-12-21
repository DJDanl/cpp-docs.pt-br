---
title: "Aviso do compilador C4801 | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4801"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4801"
ms.assetid: 05b29dff-15ef-42ca-9712-dc993afc4fd6
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4801
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O retornado pela referência não é verificável: motivo  
  
 Você não pode armazenar uma referência de controle em uma variável local e depois em um retorno ele seguros de verificação.  
  
 Uma referência só pode seguros de verificação ser retornada quando pode ser acompanhada pelo verificador de criação para retornar o ponto e quando é uma referência a um elemento de uma matriz, ou um membro de uma classe.  
  
 Para obter mais informações, consulte [Peverify.exe \(Ferramenta PEVerify\)](../Topic/Peverify.exe%20\(PEVerify%20Tool\).md).  
  
 Uma referência deve permanecer na pilha de criação retornar para ser verificável.  
  
 C4801 é emitido sempre como um erro.  Você pode desativar esse aviso com `#pragma warning` ou **\/wd**; consulte [warning](../../preprocessor/warning.md) ou [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.  
  
## Exemplo  
 C4801 será gerado se o verificador não puder ver o endereço executado, portanto deve pressupor que pode ser uma referência não controlável.  O exemplo a seguir produz C4801.  
  
```  
// C4801.cpp  
// compile with: /clr:safe /c  
int% f(int% p) {  
   return p;   // C4801  
}  
```  
  
## Exemplo  
 O exemplo a seguir produz C4801.  
  
```  
// C4801_b.cpp  
// compile with: /clr:safe /c  
  
int% f(int i, array<int>^ ar) {  
   int x;  
   int% bri = x;   // cannot return a byref to a local.  
   if (i < ar->Length) {  
      bri = ar[i];   // this byref is ok.  
   }  
  
   return bri;   // C4801 not returned within the basic block  
}  
```  
  
## Exemplo  
 C4801 também pode ocorrer se você tentar desreferenciar e retornar um valor de referência em um bloco try.  Isso resulta em código que não pode ser verificado porque a pilha é desmarcada ao final de um bloco try, destruindo nenhum valor de retorno na pilha.  Em vez disso, desreferenciar o tipo de referência e atribuí\-lo a uma variável, para garantir que nenhuma exceção seja gerada.  Em seguida, no final da função, desreferenciar o tipo de referência novamente e o retorna.  
  
 O exemplo a seguir produz C4801.  
  
```  
// C4801_c.cpp  
// compile with: /clr:safe  
using namespace System;  
  
ref class StackEmptyException : public System::Exception {};  
ref class StackFullException : public System::Exception {};  
  
template <typename T>  
ref struct Stack {  
  
   Stack() {  
      topElem = -1;   // initialize stack  
      stackPtr = gcnew array<T>(10);  
   }  
  
   void push(const T%);  
   T% top();  
  
private:  
   int topElem;    
   array<T>^ stackPtr;    
};  
  
template <typename T>   
T% Stack<T>::top() {  
   try {  
      return stackPtr[topElem];   // C4801  
      // Try the following line instead.  
      // T% deadstore = stackPtr[topElem] ;  
   }  
  
   catch (System::IndexOutOfRangeException ^ e) {  
      throw gcnew StackEmptyException();  
   }  
  
   catch (System::Exception ^ e) {  
      throw;  
   }  
  
   return stackPtr[topElem] ;  
}  
  
int main() {  
   typedef Stack<Int32> IntStack;  
   IntStack ^ is = gcnew IntStack();  
  
   int i = 1;  
   while (1) {  
      try {  
         is->push(i++);  
      }  
      catch (System::Exception ^ e) {  
         break;  
      }  
      Console::Write("{0} ", is->top());  
   }  
}  
```