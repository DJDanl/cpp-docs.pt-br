---
title: 'Como: cadeias de caracteres COM marshaling usando Interop C++ | Microsoft Docs'
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
- COM [C++], marshaling strings
ms.assetid: 06590759-bf99-4e34-a3a9-4527ea592cc2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 918825dd6563f59167baa844b94edfc1033498a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33133319"
---
# <a name="how-to-marshal-com-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres COM usando interop C++
Este tópico demonstra como um BSTR (o formato de cadeia de caracteres básicas vantajosa em programação COM) pode ser passados do gerenciada em uma função não gerenciada e vice-versa. Para interagir com outros tipos de cadeias de caracteres, consulte os tópicos a seguir:  
  
-   [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)  
  
 O código a seguir exemplos de uso de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) #pragma diretivas para implementar gerenciados e funções no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definida em arquivos separados. Arquivos que contêm apenas as funções não gerenciadas não precisam ser compilada com [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como um BSTR (um formato de cadeia de caracteres usado na programação COM) pode ser transmitido de gerenciado para uma função não gerenciada. Chamada gerenciado usa função <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> para obter o endereço de uma representação de BSTR do conteúdo do System .NET. Esse ponteiro é fixado usando [pin_ptr (C + + CLI)](../windows/pin-ptr-cpp-cli.md) para garantir que seu endereço físico não é alterado durante um ciclo de coleta de lixo quando é executado, a função não gerenciada. O coletor de lixo é proibido de mover a memória até que o [pin_ptr (C + + CLI)](../windows/pin-ptr-cpp-cli.md) sai do escopo.  
  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como um BSTR pode ser transmitido de um não gerenciado para uma função não gerenciada. O recebimento de função gerenciada pode usar a cadeia de caracteres como um BSTR ou usar <xref:System.Runtime.InteropServices.Marshal.PtrToStringBSTR%2A> para convertê-lo para um <xref:System.String> para uso com outras funções gerenciadas. Porque a memória que representa o BSTR é alocada no heap gerenciado, nenhum anexação é necessária, porque não há nenhuma coleta de lixo do heap não gerenciado.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)