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
ms.openlocfilehash: aaa07373b7dd22807290ceefa9197b4013c61fe5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384511"
---
# <a name="using-c-interop-implicit-pinvoke"></a>Usando interop C++ (PInvoke implícito)

Ao contrário de outras linguagens .NET, Visual C++ tem suporte de interoperabilidade que permite que o código gerenciado e existir no mesmo aplicativo e até mesmo no mesmo arquivo (com o [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) pragmas). Isso permite que os desenvolvedores de Visual C++ integrar a funcionalidade do .NET em aplicativos existentes do Visual C++ sem afetar o restante do aplicativo.

Você também pode chamar funções não gerenciadas compiland gerenciado que usa [dllexport, dllimport](../cpp/dllexport-dllimport.md).

PInvoke implícita é útil quando você não precisa especificar como os parâmetros de função serão empacotados ou qualquer um dos outros detalhes que podem ser especificados ao chamar explicitamente DllImportAttribute.

Visual C++ fornece funções gerenciadas e a interoperação de duas maneiras:

- [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)

PInvoke explícito tem suporte pelo .NET Framework e está disponível na maioria das linguagens .NET. Mas como o nome sugere, Interop do C++ é específico para o Visual C++.

## <a name="c-interop"></a>Interoperabilidade C++

Interoperabilidade de C++ é recomendável PInvoke explícito porque fornece melhor segurança de tipo, é normalmente menos tedioso implementar, é mais tolerante se a API não gerenciada é modificada e torna os aprimoramentos de desempenho possíveis que não são possíveis com explícita PInvoke. No entanto, a interoperabilidade de C++ não é possível se o código-fonte não gerenciado não estiver disponível.

## <a name="c-com-interop"></a>Interoperabilidade COM C++

Os recursos de interoperabilidade com suporte pelo Visual C++ oferecem uma vantagem em particular em outras linguagens .NET quando se trata de interoperar com componentes COM. Em vez de ficar limitado às restrições do .NET Framework [Tlbimp.exe (importador da biblioteca)](/dotnet/framework/tools/tlbimp-exe-type-library-importer), como o suporte limitado para tipos de dados e a exposição obrigatória de todos os membros de cada interface COM, interoperabilidade de C++ permite que o COM componentes sejam acessados em será e não exige que os assemblies de interoperabilidade separados. Ao contrário do Visual Basic e C#, Visual C++ pode usar objetos COM diretamente usando os mecanismos COM usual (como **CoCreateInstance** e **QueryInterface**). Isso é possível devido aos recursos de interoperabilidade de C++ que fazem com que o compilador a inserir automaticamente o código de transição para mover de gerenciado para funções e vice-versa.

Usando Interop do C++, componentes COM podem ser usados como são normalmente usadas, ou eles podem ser encapsulados dentro de classes do C++. Essas classes de wrapper são chamadas callable wrappers do tempo de execução personalizado ou CRCWs e tem duas vantagens em relação ao uso COM diretamente no código do aplicativo:

- A classe resultante pode ser usada de idiomas diferentes do Visual C++.

- Os detalhes da interface COM podem estar ocultos do código do cliente gerenciado. Tipos de dados do .NET podem ser usados no lugar de tipos nativos e os detalhes de marshaling de dados podem ser realizados de forma transparente dentro do CRCW.

Independentemente se o COM é usado diretamente ou por meio de um CRCW, tipos de argumento que não sejam os tipos blittable simples, devem ser empacotados.

## <a name="blittable-types"></a>Tipos blittable

Para APIs não gerenciadas que usam tipos simples, intrínseco (consulte [Blittable e não blittable](/dotnet/framework/interop/blittable-and-non-blittable-types)), nenhuma codificação especial é necessária porque esses tipos de dados têm a mesma representação na memória, mas exigem tipos de dados mais complexos marshaling de dados explícitos. Para obter um exemplo, consulte [ Chamar DLLs nativas de código gerenciado usando PInvoke](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md).

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

- [Como: realizar marshaling de cadeias de caracteres ANSI usando a interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)

- [Como: realizar marshaling de cadeias de caracteres Unicode usando a interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como: realizar marshaling de cadeias de caracteres COM usando a interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)

- [Como: realizar marshaling de estruturas usando a interop do C++](../dotnet/how-to-marshal-structures-using-cpp-interop.md)

- [Como: realizar marshaling de matrizes usando a interop do C++](../dotnet/how-to-marshal-arrays-using-cpp-interop.md)

- [Como: realizar marshaling de retornos de chamada e delegados usando a interop do C++](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)

- [Como: realizar marshaling de ponteiros inseridos usando a interop do C++](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md)

- [Como: acessar caracteres em um System::String](../dotnet/how-to-access-characters-in-a-system-string.md)

- [Como: converter a cadeia de caracteres char* na matriz System::Byte](../dotnet/how-to-convert-char-star-string-to-system-byte-array.md)

- [Como: Converter System:: String em wchar_t * ou char\*](../dotnet/how-to-convert-system-string-to-wchar-t-star-or-char-star.md)

- [Como: converter System::String em uma cadeia de caracteres padrão](../dotnet/how-to-convert-system-string-to-standard-string.md)

- [Como: converter uma cadeia de caracteres padrão em System::String](../dotnet/how-to-convert-standard-string-to-system-string.md)

- [Como: obter um ponteiro para uma matriz de bytes](../dotnet/how-to-obtain-a-pointer-to-byte-array.md)

- [Como: carregar recursos não gerenciados em uma matriz de bytes](../dotnet/how-to-load-unmanaged-resources-into-a-byte-array.md)

- [Como: modificar a classe de referência em uma função nativa](../dotnet/how-to-modify-reference-class-in-a-native-function.md)

- [Como: determinar se uma imagem é nativa ou CLR](../dotnet/how-to-determine-if-an-image-is-native-or-clr.md)

- [Como: adicionar a DLL nativa ao Cache de Assembly Global ](../dotnet/how-to-add-native-dll-to-global-assembly-cache.md)

- [Como: manter a referência ao tipo de valor em tipo nativo](../dotnet/how-to-hold-reference-to-value-type-in-native-type.md)

- [Como: manter a referência do objeto na memória não gerenciada](../dotnet/how-to-hold-object-reference-in-unmanaged-memory.md)

- [Como: Detectar a compilação /clr](../dotnet/how-to-detect-clr-compilation.md)

- [Como: converter entre System::Guid e _GUID](../dotnet/how-to-convert-between-system-guid-and-guid.md)

- [Como: especificar um parâmetro externo](../dotnet/how-to-specify-an-out-parameter.md)

- [Como: Usar um tipo nativo em uma compilação /clr](../dotnet/how-to-use-a-native-type-in-a-clr-compilation.md)

- [Como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md)

- [Como: encapsular a classe nativa a ser usada pelo C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)

Para obter informações sobre como usar delegados em um cenário de interoperabilidade, consulte [delegado (extensões de componentes C++)](../extensions/delegate-cpp-component-extensions.md).

## <a name="see-also"></a>Consulte também

- [Chamando funções nativas de código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)
