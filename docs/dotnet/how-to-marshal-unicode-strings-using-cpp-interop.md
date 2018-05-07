---
title: 'Como: cadeias de caracteres Unicode marshaling usando Interop C++ | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
- Unicode, marshaling strings
ms.assetid: 96c2141d-6c5d-43ef-a1aa-5785afb9a9aa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: e5290958a55c61dd55adac0f182af7163896d694
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-marshal-unicode-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres Unicode usando interop C++
Este tópico demonstra uma faceta de interoperabilidade do Visual C++. Para obter mais informações, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 O código a seguir exemplos de uso de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) #pragma diretivas para implementar gerenciados e funções no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definida em arquivos separados. Arquivos que contêm apenas as funções não gerenciadas não precisam ser compilada com [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 Este tópico demonstra como cadeias de caracteres Unicode podem ser passados do gerenciada em uma função não gerenciada e vice-versa. Para interagir com outros tipos de cadeias de caracteres, consulte os tópicos a seguir:  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres COM usando interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)  
  
## <a name="example"></a>Exemplo  
 Para passar uma cadeia de caracteres Unicode de um gerenciado para uma função não gerenciada, a função PtrToStringChars (declarada em Vcclr.h) pode ser usada para acessar na memória em que a cadeia de caracteres gerenciada é armazenada. Como esse endereço será passado para uma função nativa, é importante que a memória ser fixado com [pin_ptr (C + + CLI)](../windows/pin-ptr-cpp-cli.md) para impedir que os dados de cadeia de caracteres que está sendo realocado, um ciclo de coleta de lixo sejam efetuadas durante o executa a função não gerenciada.  
  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o marshaling de dados necessárias para acessar uma cadeia de caracteres Unicode em uma função gerenciada chamada por uma função não gerenciada. A função gerenciada, ao receber a cadeia de caracteres Unicode nativo, converte-o em uma cadeia de caracteres gerenciada usando o <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> método.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)