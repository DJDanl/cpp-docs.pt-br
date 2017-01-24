---
title: "Como realizar marshaling de cadeias de caracteres Unicode usando interop C++ | Microsoft Docs"
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
  - "Interoperabilidade C++, cadeias de caracteres"
  - "realização de marshaling em dados [C++], cadeias de caracteres"
  - "interoperabilidade [C++], cadeias de caracteres"
  - "realização de marshaling [C++], cadeias de caracteres"
  - "Unicode, realizando marshaling em cadeias de caracteres"
ms.assetid: 96c2141d-6c5d-43ef-a1aa-5785afb9a9aa
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de cadeias de caracteres Unicode usando interop C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra uma faceta de interoperabilidade do Visual C\+\+.  Para obter mais informações, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas essas funções interoperam da mesma forma que se definido em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 Este tópico mostra como as cadeias de caracteres Unicode podem ser passadas de um gerenciado para uma função não gerenciado, e vice\-versa.  Para interoperar com outros tipos de cadeias de caracteres, consulte os seguintes tópicos:  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop C\+\+](../Topic/How%20to:%20Marshal%20ANSI%20Strings%20Using%20C++%20Interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres COM usando interop C\+\+](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)  
  
## Exemplo  
 Para transmitir uma cadeia de caracteres Unicode de um gerenciado para uma função não gerenciado, a função de PtrToStringChars \(declarada em Vcclr.h\) pode ser usada para acessar na memória na cadeia de caracteres gerenciado é armazenada.  Como esse endereço será transmitido para uma função nativo, é importante que a memória está fixada com [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md) para impedir que os dados de cadeia de caracteres estado realocado, deve um ciclo de coleta de lixo ocorrer quando a função não gerenciado executar.  
  
```  
// MarshalUnicode1.cpp  
// compile with: /clr  
#include <iostream>  
#include <stdio.h>  
#include <vcclr.h>  
  
using namespace std;  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma unmanaged  
  
void NativeTakesAString(const wchar_t* p) {  
   printf_s("(native) received '%S'\n", p);  
}  
  
#pragma managed  
  
int main() {  
   String^ s = gcnew String("test string");  
   pin_ptr<const wchar_t> str = PtrToStringChars(s);  
  
   Console::WriteLine("(managed) passing string to native func...");  
   NativeTakesAString( str );  
}  
```  
  
## Exemplo  
 O exemplo a seguir demonstra o marshaling de dados exigido para acessar uma cadeia de caracteres Unicode em uma função gerenciada chamada por uma função não gerenciado.  A função gerenciada, ao receber a cadeia de caracteres Unicode nativo, convertida em uma cadeia de caracteres gerenciado usando o método de <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> .  
  
```  
// MarshalUnicode2.cpp  
// compile with: /clr  
#include <iostream>  
  
using namespace std;  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma managed  
  
void ManagedStringFunc(wchar_t* s) {  
   String^ ms = Marshal::PtrToStringUni((IntPtr)s);  
   Console::WriteLine("(managed) received '{0}'", ms);  
}  
  
#pragma unmanaged  
  
void NativeProvidesAString() {  
   cout << "(unmanaged) calling managed func...\n";  
   ManagedStringFunc(L"test string");  
}  
  
#pragma managed  
  
int main() {  
   NativeProvidesAString();  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)