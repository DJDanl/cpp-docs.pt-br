---
title: "Como realizar marshal de retornos de chamadas e delegados usando o C++ Interop | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interoperabilidade C++, retornos de chamado e delegados"
  - "retornos de chamada [C++], marshaling"
  - "realização de marshaling em dados [C++], retornos de chamado e delegados"
  - "delegados [C++], marshaling"
  - "interoperabilidade [C++], retornos de chamado e delegados"
  - "realização de marshaling [C++], retornos de chamado e delegados"
ms.assetid: 2313e9eb-5df9-4367-be0f-14b4712d8d2d
caps.latest.revision: 23
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshal de retornos de chamadas e delegados usando o C++ Interop
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra o marshalling de retornos de chamada e de representantes \(a versão gerenciado de um retorno de chamada\) entre o código gerenciado e não gerenciados usando o Visual C\+\+.  
  
 Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas as funções também podem ser definidas em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar a API não gerenciados para disparar um representante gerenciado.  Um representante gerenciado é criado e um dos métodos de interoperabilidade, <xref:System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate%2A>, é usado para recuperar o ponto de entrada subjacente para o representante.  Este endereço é então passado para a função não gerenciado, que chama o sem o conhecimento do fato de que é implementada como uma função gerenciada.  
  
 Observe que ele é possível, mas não for necessário, para fixar o delegado que usa [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md) para impedir que seja encontrado novamente ou que indicado pelo coletor de lixo.  A proteção de coleta de lixo prematura é necessária, mas fixar\-se fornece proteção mais do que é necessário, pois impede a coleção mas também impede a realocação.  
  
 Se um representante novamente for encontrado por uma coleta de lixo, não afetará o retorno de chamada é gerenciado underlaying, portanto <xref:System.Runtime.InteropServices.GCHandle.Alloc%2A> é usado para adicionar uma referência ao representante, permitindo a realocação de delegação, mas impedindo a eliminação.  Usar GCHandle em vez de pin\_ptr reduz a possibilidade de fragmentação de heap gerenciado.  
  
```  
// MarshalDelegate1.cpp  
// compile with: /clr  
#include <iostream>  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma unmanaged  
  
// Declare an unmanaged function type that takes two int arguments  
// Note the use of __stdcall for compatibility with managed code  
typedef int (__stdcall *ANSWERCB)(int, int);  
  
int TakesCallback(ANSWERCB fp, int n, int m) {  
   printf_s("[unmanaged] got callback address, calling it...\n");  
   return fp(n, m);  
}  
  
#pragma managed  
  
public delegate int GetTheAnswerDelegate(int, int);  
  
int GetNumber(int n, int m) {  
   Console::WriteLine("[managed] callback!");  
   return n + m;  
}  
  
int main() {  
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);  
   GCHandle gch = GCHandle::Alloc(fp);  
   IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);  
   ANSWERCB cb = static_cast<ANSWERCB>(ip.ToPointer());  
   Console::WriteLine("[managed] sending delegate as callback...");  
  
// force garbage collection cycle to prove  
// that the delegate doesn't get disposed  
   GC::Collect();  
  
   int answer = TakesCallback(cb, 243, 257);  
  
// release reference to delegate  
   gch.Free();  
}  
```  
  
## Exemplo  
 O exemplo a seguir é semelhante ao exemplo anterior, mas o ponteiro fornecido da função é armazenado nesse caso a API não gerenciado, o que pode invocar a qualquer momento, requerendo que a coleta de lixo seja suprimida para um período de tempo arbitrário.  No, o exemplo a seguir usa uma instância de <xref:System.Runtime.InteropServices.GCHandle> global para impedir que o representante estado realocado, independentemente do escopo da função.  Como discutido no primeiro exemplo, usar o pin\_ptr é desnecessária para esses exemplos, mas nesse caso não funcionaria de qualquer forma, porque o escopo de um pin\_ptr é limitado a uma única função.  
  
```  
// MarshalDelegate2.cpp  
// compile with: /clr   
#include <iostream>  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma unmanaged  
  
// Declare an unmanaged function type that takes two int arguments  
// Note the use of __stdcall for compatibility with managed code  
typedef int (__stdcall *ANSWERCB)(int, int);  
static ANSWERCB cb;  
  
int TakesCallback(ANSWERCB fp, int n, int m) {  
   cb = fp;  
   if (cb) {  
      printf_s("[unmanaged] got callback address (%d), calling it...\n", cb);  
      return cb(n, m);  
   }  
   printf_s("[unmanaged] unregistering callback");  
   return 0;  
}  
  
#pragma managed  
  
public delegate int GetTheAnswerDelegate(int, int);  
  
int GetNumber(int n, int m) {  
   Console::WriteLine("[managed] callback!");  
   static int x = 0;  
   ++x;  
  
   return n + m + x;  
}  
  
static GCHandle gch;  
  
int main() {  
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);  
  
   gch = GCHandle::Alloc(fp);  
  
   IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);  
   ANSWERCB cb = static_cast<ANSWERCB>(ip.ToPointer());  
   Console::WriteLine("[managed] sending delegate as callback...");  
  
   int answer = TakesCallback(cb, 243, 257);  
  
   // possibly much later (in another function)...  
  
   Console::WriteLine("[managed] releasing callback mechanisms...");  
   TakesCallback(0, 243, 257);  
   gch.Free();  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)