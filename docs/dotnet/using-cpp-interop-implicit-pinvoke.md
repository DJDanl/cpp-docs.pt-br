---
title: "Usando interop C++ (PInvoke impl&#237;cito) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - ".NET [C++], movimentando C++ nativo para"
  - "tipos que permitem transferência de bits [C++]"
  - "Interoperabilidade COM C++"
  - "Interoperabilidade C++"
  - "C++, interoperabilidade"
  - "Interfaces COM [C++]"
  - "realização de marshaling em dados [C++], recursos de interoperabilidade C++"
  - "exemplos [C++], interoperabilidade"
  - "invocação de plataforma implícita"
  - "interoperabilidade [C++], recursos"
  - "interoperabilidade [C++]"
  - "interoperabilidade [C++], PInvoke implícita"
  - "realização de marshaling [C++], recursos de interoperabilidade C++"
  - "invocação de plataforma [C++], exemplos"
  - "invocação de plataforma [C++], implícito"
  - "movimentando [C++], C++ nativo para .NET"
  - "tipos [C++], blittable"
ms.assetid: 5f710bf1-88ae-4c4e-8326-b3f0b7c4c68a
caps.latest.revision: 27
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando interop C++ (PInvoke impl&#237;cito)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao contrário de outros linguagens .NET, Visual C\+\+ tem o suporte de interoperabilidade que permite que o código gerenciado e não gerenciados existir no mesmo aplicativo e até mesmo no mesmo arquivo \(com os pragmas de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) \).  Isso permite que os desenvolvedores do Visual C\+\+ integrem a funcionalidade de .NET em aplicativos existentes do Visual C\+\+ sem afetar o restante do aplicativo.  
  
 Você também pode chamar funções não gerenciados de um compiland gerenciado usando [dllexport, dllimport](../cpp/dllexport-dllimport.md).  
  
 PInvoke implícita é útil quando você não precisa especificar como os parâmetros de marshaling de função, ou qualquer um dos outros detalhes que podem ser especificadas ao chamar explicitamente DllImportAttribute.  
  
 Visual C\+\+ fornece dois modos para que as funções gerenciados e não gerenciados interoperem:  
  
-   [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)  
  
 PInvoke explícito tem suporte do.NET Framework e está disponível na maioria das linguagens .NET.  Mas como seu nome, implica C\+\+ Interoperabilidade é específico ao Visual C\+\+.  
  
## Interoperabilidade C\+\+  
 C\+\+ Interoperabilidade é recomendado sobre PInvoke explícito porque fornece a melhor segurança de tipo, normalmente é menos fastidioso de implementá\-los, é de perdão se a API não gerenciado é alterado, e torna aprimoramentos de desempenho possíveis que não é possível com PInvoke explícito.  No entanto, C\+\+ Interoperabilidade não é possível se o código\-fonte não gerenciado não está disponível ou criar com **\/clr:safe** \(consulte [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md) para obter mais informações\).  
  
## Interoperabilidade COM C\+\+  
 Os recursos de interoperabilidade com suporte pelo Visual C\+\+ oferecem uma vantagem específico em outras linguagens .NET quando se trata a interação com componentes COM.  Em vez de restrição às limitações do .NET Framework [Tlbimp.exe \(Importador de Biblioteca de Tipos\)](../Topic/Tlbimp.exe%20\(Type%20Library%20Importer\).md), como suporte limitado para tipos de dados e a possibilidade obrigatória de cada membro de cada interface COM, C\+\+ Interoperabilidade permite que os componentes COM sejam acessados em e não requer assemblies separados de interoperabilidade.  Para obter mais informações, consulte [Using COM from .NET](http://msdn.microsoft.com/pt-br/03976661-6278-4227-a6c1-3b3315502c15).  
  
## Tipos blittables  
 Para as APIs não gerenciado que usam tipos simples, intrínsecos \(consulte [Tipos blittable e não blittable](../Topic/Blittable%20and%20Non-Blittable%20Types.md)\), nenhuma codificação especial necessária porque esses tipos de dados têm a mesma representação na memória, mas os tipos de dados requerem mais complexos marshaling explícito de dados.  Para ver um exemplo, consulte [Como chamar DLLs nativas a partir do código gerenciado usando PInvoke](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md).  
  
## Exemplo  
  
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
  
  **Inicie o sinal acústico**  
**Concluído**   
## Nesta seção  
  
-   [Como realizar marshaling de cadeias de caracteres ANSI usando interop C\+\+](../Topic/How%20to:%20Marshal%20ANSI%20Strings%20Using%20C++%20Interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres Unicode usando interop C\+\+](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de cadeias de caracteres COM usando interop C\+\+](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)  
  
-   [Como realizar marshaling de estruturas usando interop C\+\+](../dotnet/how-to-marshal-structures-using-cpp-interop.md)  
  
-   [Como realizar marshaling de matrizes usando interop C\+\+](../dotnet/how-to-marshal-arrays-using-cpp-interop.md)  
  
-   [Como realizar marshal de retornos de chamadas e delegados usando o C\+\+ Interop](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)  
  
-   [Como realizar marshaling de ponteiros inseridos usando interop C\+\+](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md)  
  
-   [Como acessar caracteres em um System::String](../dotnet/how-to-access-characters-in-a-system-string.md)  
  
-   [Como converter a cadeia de caracteres char \* na matriz System::Byte](../dotnet/how-to-convert-char-star-string-to-system-byte-array.md)  
  
-   [Como converter System::String em wchar\_t\* ou char\*](../dotnet/how-to-convert-system-string-to-wchar-t-star-or-char-star.md)  
  
-   [Como converter System::String na cadeia de caracteres padrão](../dotnet/how-to-convert-system-string-to-standard-string.md)  
  
-   [Como converter cadeia de caracteres padrão em System::String](../dotnet/how-to-convert-standard-string-to-system-string.md)  
  
-   [Como obter um ponteiro para matriz de bytes](../dotnet/how-to-obtain-a-pointer-to-byte-array.md)  
  
-   [Como carregar recursos não gerenciados em uma matriz de bytes](../Topic/How%20to:%20Load%20Unmanaged%20Resources%20into%20a%20Byte%20Array.md)  
  
-   [Como modificar classe de referência em uma função nativa](../Topic/How%20to:%20Modify%20Reference%20Class%20in%20a%20Native%20Function.md)  
  
-   [Como determinar se uma imagem é nativa ou CLR](../Topic/How%20to:%20Determine%20if%20an%20Image%20is%20Native%20or%20CLR.md)  
  
-   [Como adicionar DLL nativo ao cache de assembly global](../dotnet/how-to-add-native-dll-to-global-assembly-cache.md)  
  
-   [Como manter a referência para tipo de valor em tipo nativo](../dotnet/how-to-hold-reference-to-value-type-in-native-type.md)  
  
-   [Como manter referência de objeto na memória não gerenciada](../dotnet/how-to-hold-object-reference-in-unmanaged-memory.md)  
  
-   [Como detectar a compilação \/clr](../dotnet/how-to-detect-clr-compilation.md)  
  
-   [Como fazer uma conversão entre System::Guid e \_GUID](../Topic/How%20to:%20Convert%20Between%20System::Guid%20and%20_GUID.md)  
  
-   [Como especificar um parâmetro out](../dotnet/how-to-specify-an-out-parameter.md)  
  
-   [Como usar um tipo nativo em uma compilação \/clr](../Topic/How%20to:%20Use%20a%20Native%20Type%20in%20a%20-clr%20Compilation.md)  
  
-   [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md)  
  
-   [Como encapsular classe nativa a ser usada por C\#](../Topic/How%20to:%20Wrap%20Native%20Class%20for%20Use%20by%20C%23.md)  
  
 Para obter informações sobre como usar delegados em um cenário de interoperabilidade, consulte [delegado](../windows/delegate-cpp-component-extensions.md).  
  
## Consulte também  
 [Chamando funções nativas a partir do código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)