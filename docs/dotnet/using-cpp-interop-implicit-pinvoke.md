---
title: Usando Interop C++ (PInvoke implícito) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- blittable types [C++]
- platform invoke [C++], implicit
- interop [C++], features
- data marshaling [C++], C++ Interop features
- porting [C++], C++ native to .NET
- COM interfaces [C++]
- implicit platform invoke
- examples [C++], interoperability
- types [C++], blittable
- marshaling [C++], C++ Interop features
- platform invoke [C++], examples
- interoperability [C++]
- C++ Interop
- interoperability [C++], Implicit PInvoke
- C++, interop
- C++ COM Interop
- .NET [C++], porting C++ native to
ms.assetid: 5f710bf1-88ae-4c4e-8326-b3f0b7c4c68a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a91c9833358744730b9ad9c63f5a14729d9d0968
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-c-interop-implicit-pinvoke"></a>Usando interop C++ (PInvoke implícito)
Ao contrário de outras linguagens .NET, Visual C++ tem suporte de interoperabilidade que permite que o código gerenciado e existir no mesmo aplicativo e até mesmo no mesmo arquivo (com o [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) pragmas). Isso permite que os desenvolvedores do Visual C++ integrar a funcionalidade do .NET em aplicativos existentes do Visual C++ sem afetar o restante do aplicativo.  
  
 Você também pode chamar funções não gerenciadas compiland gerenciado usa [dllexport, dllimport](../cpp/dllexport-dllimport.md).  
  
 PInvoke implícita é útil quando você não precisa especificar como os parâmetros de função serão empacotados ou qualquer um dos outros detalhes que podem ser especificados ao chamar explicitamente DllImportAttribute.  
  
 Visual C++ fornece funções gerenciadas e para a interoperação de duas maneiras:  
  
-   [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)  
  
 PInvoke explícito é suportado pelo .NET Framework e está disponível na maioria das linguagens .NET. Mas, como o nome sugere, interoperabilidade C++ é específica para o Visual C++.  
  
## <a name="c-interop"></a>Interoperabilidade C++  
 Interoperabilidade C++ é recomendável PInvoke explícito porque ele fornece melhor segurança de tipo, é geralmente menor entediante implementar, é mais tolerante se a API não gerenciada é modificada e torna os aprimoramentos de desempenho possíveis que não são possíveis com explícita PInvoke. No entanto, a interoperabilidade C++ não é possível se o código-fonte não gerenciada não está disponível.  
  
## <a name="c-com-interop"></a>Interoperabilidade COM C++  
 Os recursos de interoperabilidade com suporte pelo Visual C++ oferecem uma vantagem sobre outras linguagens .NET em particular quando se trata de interagir com componentes COM. Em vez de estar limitado às restrições do .NET Framework [Tlbimp.exe (importador da biblioteca)](/dotnet/framework/tools/tlbimp-exe-type-library-importer), como suporte limitado para tipos de dados e a exposição obrigatória de todos os membros de interface COM, interoperabilidade C++ permite COM componentes sejam acessados em será e não exige que os assemblies de interoperabilidade separados. Para obter mais informações, consulte [usando COM do .NET](http://msdn.microsoft.com/en-us/03976661-6278-4227-a6c1-3b3315502c15).  
  
## <a name="blittable-types"></a>Tipos blittable  
 Para APIs não gerenciadas que usam tipos simples, intrínsecos (consulte [Blittable e tipos Blittable não](http://msdn.microsoft.com/Library/d03b050e-2916-49a0-99ba-f19316e5c1b3)), nenhuma codificação especial é necessária porque esses tipos de dados têm a mesma representação na memória, mas os tipos de dados mais complexos requerem marshaling em dados explícitos. Para obter um exemplo, consulte [como: chamar DLLs nativas de PInvoke de uso de código gerenciado](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// vcmcppv2_impl_dllimp.cpp  
// compile with: /clr:pure user32.lib  
using namespace System::Runtime::InteropServices;  
  
// Implicit DLLImport specifying calling convention  
extern "C" int __stdcall MessageBeep(int);  
  
// explicit DLLImport needed here to use P/Invoke marshalling because  
// System::String ^ is not the type of the first parameter to printf  
[DllImport("msvcrt.dll", EntryPoint = "printf", CallingConvention = CallingConvention::Cdecl,  CharSet = CharSet::Ansi)]  
// or just  
// [DllImport("msvcrt.dll")]  
int printf(System::String ^, ...);   
  
int main() {  
   // (string literals are System::String by default)  
   printf("Begin beep\n");  
   MessageBeep(100000);  
   printf("Done\n");  
}  
```  
  
```Output  
Begin beep  
Done  
```  
  
## <a name="in-this-section"></a>Nesta seção  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres COM usando interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de estruturas usando interop do C++](../dotnet/how-to-marshal-structures-using-cpp-interop.md)  
  
-   [Como realizar marshaling de matrizes usando interop do C++](../dotnet/how-to-marshal-arrays-using-cpp-interop.md)  
  
-   [Como realizar marshaling de retornos de chamada e delegados usando interop do C++](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)  
  
-   [Como realizar marshaling de ponteiros inseridos usando interop do C++](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md)  
  
-   [Como acessar caracteres em um System::String](../dotnet/how-to-access-characters-in-a-system-string.md)  
  
-   [Como converter a cadeia de caracteres char * na matriz System::Byte](../dotnet/how-to-convert-char-star-string-to-system-byte-array.md)  
  
-   [Como: converter System:: String em wchar_t * ou char\*](../dotnet/how-to-convert-system-string-to-wchar-t-star-or-char-star.md)  
  
-   [Como converter System::String em uma cadeia de caracteres padrão](../dotnet/how-to-convert-system-string-to-standard-string.md)  
  
-   [Como converter uma cadeia de caracteres padrão em System::String](../dotnet/how-to-convert-standard-string-to-system-string.md)  
  
-   [Como obter um ponteiro para uma matriz de bytes](../dotnet/how-to-obtain-a-pointer-to-byte-array.md)  
  
-   [Como carregar recursos não gerenciados em uma matriz de bytes](../dotnet/how-to-load-unmanaged-resources-into-a-byte-array.md)  
  
-   [Como modificar a classe de referência em uma função nativa](../dotnet/how-to-modify-reference-class-in-a-native-function.md)  
  
-   [Como determinar se uma imagem é nativa ou CLR](../dotnet/how-to-determine-if-an-image-is-native-or-clr.md)  
  
-   [Como adicionar a DLL nativa ao cache de assembly global](../dotnet/how-to-add-native-dll-to-global-assembly-cache.md)  
  
-   [Como manter a referência para o tipo de valor no tipo nativo](../dotnet/how-to-hold-reference-to-value-type-in-native-type.md)  
  
-   [Como manter a referência do objeto na memória não gerenciada](../dotnet/how-to-hold-object-reference-in-unmanaged-memory.md)  
  
-   [Como: detectar a compilação /clr](../dotnet/how-to-detect-clr-compilation.md)  
  
-   [Como converter entre System::Guid e _GUID](../dotnet/how-to-convert-between-system-guid-and-guid.md)  
  
-   [Como especificar um parâmetro out](../dotnet/how-to-specify-an-out-parameter.md)  
  
-   [Como: usar um tipo nativo em uma compilação /clr](../dotnet/how-to-use-a-native-type-in-a-clr-compilation.md)  
  
-   [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md)  
  
-   [Como encapsular a classe nativa a ser usada por C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)  
  
 Para obter informações sobre como usar representantes em um cenário de interoperabilidade, consulte [delegado (extensões de componentes C++)](../windows/delegate-cpp-component-extensions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Chamando funções nativas de código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)