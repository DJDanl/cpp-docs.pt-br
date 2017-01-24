---
title: "Como realizar marshaling de cadeias de caracteres COM usando interop C++ | Microsoft Docs"
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
  - "COM [C++], realizando marshaling em cadeias de caracteres"
  - "realização de marshaling em dados [C++], cadeias de caracteres"
  - "interoperabilidade [C++], cadeias de caracteres"
  - "realização de marshaling [C++], cadeias de caracteres"
ms.assetid: 06590759-bf99-4e34-a3a9-4527ea592cc2
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de cadeias de caracteres COM usando interop C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como um BSTR \(o formato básico de cadeia de caracteres favorecido em COM que programa\) pode ser passado de um gerenciado para uma função não gerenciado, e vice\-versa.  Para interoperar com outros tipos de cadeias de caracteres, consulte os seguintes tópicos:  
  
-   [Como realizar marshaling de cadeias de caracteres Unicode usando interop C\+\+](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop C\+\+](../Topic/How%20to:%20Marshal%20ANSI%20Strings%20Using%20C++%20Interop.md)  
  
 Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas essas funções interoperam da mesma forma que se definido em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como um BSTR \(um formato de cadeia de caracteres COM usado na programação\) pode ser passado de um gerenciado para uma função não gerenciado.  A função gerenciada chamada usa <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> para obter o endereço de uma representação de BSTR do conteúdo de um .NET System.String.  Esse ponteiro é fixado usando [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md) para garantir que o endereço físico não foi alterada durante um ciclo de coleta de lixo quando a função não gerenciado executar.  O coletor de lixo é proibido de mover a memória até que [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md) saia do escopo.  
  
```  
// MarshalBSTR1.cpp  
// compile with: /clr  
#define WINVER 0x0502  
#define _AFXDLL  
#include <afxwin.h>  
  
#include <iostream>  
using namespace std;  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma unmanaged  
  
void NativeTakesAString(BSTR bstr) {  
   printf_s("%S", bstr);  
}  
  
#pragma managed  
  
int main() {  
   String^ s = "test string";  
  
   IntPtr ip = Marshal::StringToBSTR(s);  
   BSTR bs = static_cast<BSTR>(ip.ToPointer());  
   pin_ptr<BSTR> b = &bs;  
  
   NativeTakesAString( bs );  
   Marshal::FreeBSTR(ip);  
}  
```  
  
## Exemplo  
 O exemplo a seguir demonstra como um BSTR pode ser passado de um não gerenciada em uma função não gerenciado.  A função gerenciada pull pode usar a cadeia de caracteres em como um BSTR ou usar <xref:System.Runtime.InteropServices.Marshal.PtrToStringBSTR%2A> para convertê\-los em <xref:System.String> para uso com outras funções gerenciadas.  Como a memória que representa o BSTR é atribuída no heap não gerenciado, nenhum fixar\-se é necessário, pois não há nenhuma coleta de lixo no heap não gerenciado.  
  
```  
// MarshalBSTR2.cpp  
// compile with: /clr  
#define WINVER 0x0502  
#define _AFXDLL  
#include <afxwin.h>  
  
#include <iostream>  
using namespace std;  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma managed  
  
void ManagedTakesAString(BSTR bstr) {  
   String^ s = Marshal::PtrToStringBSTR(static_cast<IntPtr>(bstr));  
   Console::WriteLine("(managed) convered BSTR to String: '{0}'", s);  
}  
  
#pragma unmanaged  
  
void UnManagedFunc() {  
   BSTR bs = SysAllocString(L"test string");  
   printf_s("(unmanaged) passing BSTR to managed func...\n");  
   ManagedTakesAString(bs);  
}  
  
#pragma managed  
  
int main() {  
   UnManagedFunc();  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)