---
title: Usando interop C++ (PInvoke implícito)
ms.date: 11/04/2016
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
ms.openlocfilehash: d26fbefd87b3ba6d6ca7e183be78608777f383b5
ms.sourcegitcommit: 27d9db019f6d84c94de9e6aff0170d918cee6738
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/06/2020
ms.locfileid: "75676925"
---
# <a name="using-c-interop-implicit-pinvoke"></a>Usando interop C++ (PInvoke implícito)

Ao contrário de outras linguagens C++ .net, o Visual tem suporte de interoperabilidade que permite que o código gerenciado e não gerenciado exista no mesmo aplicativo e mesmo no mesmo arquivo (com os pragmas [gerenciados e não](../preprocessor/managed-unmanaged.md) gerenciados). Isso permite que C++ os desenvolvedores visuais integrem a funcionalidade do C++ .net em aplicativos visuais existentes sem perturbar o restante do aplicativo.

Você também pode chamar funções não gerenciadas de um compiland gerenciado usando [dllexport, DllImport](../cpp/dllexport-dllimport.md).

O PInvoke implícito é útil quando você não precisa especificar como os parâmetros de função serão empacotados ou qualquer um dos outros detalhes que podem ser especificados ao chamar explicitamente DllImportAttribute.

O C++ Visual fornece duas maneiras para que as funções gerenciadas e não gerenciadas interoperem:

- [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)

O PInvoke explícito é suportado pelo .NET Framework e está disponível na maioria das linguagens .NET. Mas como o nome sugere, C++ a interoperabilidade é C++específica para o Visual.

## <a name="c-interop"></a>Interoperabilidade C++

C++A interoperabilidade fornece melhor segurança de tipo e, em geral, é menos entediante de implementar. No entanto, C++ a interoperabilidade não será uma opção se o código-fonte não gerenciado não estiver disponível ou para projetos de plataforma cruzada.

## <a name="c-com-interop"></a>Interoperabilidade COM C++

Os recursos de interoperabilidade com C++ suporte do Visual oferecem uma vantagem específica sobre outras linguagens .net quando se trata de interoperar COM componentes com. Em vez de serem limitados às restrições do .NET Framework [Tlbimp. exe (tipo de importador de biblioteca de tipos)](/dotnet/framework/tools/tlbimp-exe-type-library-importer), como suporte limitado para tipos de dados e a exposição obrigatória de cada membro de cada C++ interface com, a interoperabilidade permite que os componentes com sejam acessados no e não exigem assemblies de interoperabilidade separados. Ao contrário de C#Visual Basic e C++ , o Visual pode usar objetos com diretamente usando os mecanismos com usuais (como **CoCreateInstance** e **QueryInterface**). Isso é possível devido a C++ recursos de interoperabilidade que fazem com que o compilador insira automaticamente o código de transição para migrar de funções gerenciadas para não gerenciadas e de volta novamente.

Usando C++ a interoperabilidade, os componentes com podem ser usados, pois normalmente são usados ou podem C++ ser encapsulados dentro de classes. Essas classes de wrapper são chamadas de wrappers callable de tempo de execução personalizados, ou CRCWs, e têm duas vantagens em relação ao uso de COM diretamente no código do aplicativo:

- A classe resultante pode ser usada em outros idiomas que não C++sejam o Visual.

- Os detalhes da interface COM podem ser ocultados do código do cliente gerenciado. Os tipos de dados do .NET podem ser usados no lugar de tipos nativos, e os detalhes do marshaling de dados podem ser executados de forma transparente dentro do CRCW.

Independentemente de o COM ser usado diretamente ou por meio de um CRCW, tipos de argumento que não sejam simples, os tipos blittable devem ser empacotados.

## <a name="blittable-types"></a>Tipos blittable

Para APIs não gerenciadas que usam tipos simples e intrínsecos (consulte [tipos de transferência de bits e não-blittable](/dotnet/framework/interop/blittable-and-non-blittable-types)), nenhuma codificação especial é necessária porque esses tipos de dados têm a mesma representação na memória, mas os tipos de dados mais complexos exigem o marshaling explícito de dados. Para obter um exemplo, consulte [como: chamar DLLs nativas do código gerenciado usando PInvoke](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md).

## <a name="example"></a>Exemplo

```cpp
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

- [Como realizar marshaling de cadeias de caracteres ANSI usando interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres COM usando interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)

- [Como realizar marshaling de estruturas usando interop do C++](../dotnet/how-to-marshal-structures-using-cpp-interop.md)

- [Como realizar marshaling de matrizes usando interop do C++](../dotnet/how-to-marshal-arrays-using-cpp-interop.md)

- [Como realizar marshaling de retornos de chamada e delegados usando interop do C++](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)

- [Como realizar marshaling de ponteiros inseridos usando interop do C++](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md)

- [Como acessar caracteres em um System::String](../dotnet/how-to-access-characters-in-a-system-string.md)

- [Como converter a cadeia de caracteres char * na matriz System::Byte](../dotnet/how-to-convert-char-star-string-to-system-byte-array.md)

- [Como: converter System:: String em wchar_t * ou Char\*](../dotnet/how-to-convert-system-string-to-wchar-t-star-or-char-star.md)

- [Como converter System::String em uma cadeia de caracteres padrão](../dotnet/how-to-convert-system-string-to-standard-string.md)

- [Como converter uma cadeia de caracteres padrão em System::String](../dotnet/how-to-convert-standard-string-to-system-string.md)

- [Como obter um ponteiro para uma matriz de bytes](../dotnet/how-to-obtain-a-pointer-to-byte-array.md)

- [Como carregar recursos não gerenciados em uma matriz de bytes](../dotnet/how-to-load-unmanaged-resources-into-a-byte-array.md)

- [Como modificar a classe de referência em uma função nativa](../dotnet/how-to-modify-reference-class-in-a-native-function.md)

- [Como determinar se uma imagem é nativa ou CLR](../dotnet/how-to-determine-if-an-image-is-native-or-clr.md)

- [Como adicionar a DLL nativa ao cache de assembly global](../dotnet/how-to-add-native-dll-to-global-assembly-cache.md)

- [Como manter a referência para o tipo de valor no tipo nativo](../dotnet/how-to-hold-reference-to-value-type-in-native-type.md)

- [Como manter a referência do objeto na memória não gerenciada](../dotnet/how-to-hold-object-reference-in-unmanaged-memory.md)

- [Como detectar a compilação/CLR](../dotnet/how-to-detect-clr-compilation.md)

- [Como converter entre System::Guid e _GUID](../dotnet/how-to-convert-between-system-guid-and-guid.md)

- [Como especificar um parâmetro out](../dotnet/how-to-specify-an-out-parameter.md)

- [Como: usar um tipo nativo em uma compilação/CLR](../dotnet/how-to-use-a-native-type-in-a-clr-compilation.md)

- [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md)

- [Como encapsular a classe nativa a ser usada por C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)

Para obter informações sobre como usar delegados em um cenário de interoperabilidade, consulte [delegar (extensõesC++ de componente)](../extensions/delegate-cpp-component-extensions.md).

## <a name="see-also"></a>Veja também

- [Chamando funções nativas de código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)
