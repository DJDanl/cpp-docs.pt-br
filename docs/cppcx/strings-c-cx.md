---
title: Cadeias de caracteres (C++/CX)
ms.date: 01/22/2017
ms.assetid: 5b34e1df-7c2b-4269-aba8-b767d36c49d9
ms.openlocfilehash: a67b9a4552dc83791c05029cca76f60fd83df0f1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745353"
---
# <a name="strings-ccx"></a>Cadeias de caracteres (C++/CX)

O texto no Tempo de execução do Windows é representado em C++/CX pela [Plataforma::String Class](../cppcx/platform-string-class.md). Use `Platform::String Class` o quando você passar as strings para frente e para trás para métodos nas classes de tempo de execução do Windows ou quando estiver interagindo com outros componentes do Windows Runtime através do limite de interface binária de aplicativo (ABI). `Platform::String Class` fornece métodos para várias operações comuns de cadeia de caracteres, mas não foi projetado para ser uma classe de cadeia de caracteres completa. Em seu módulo C++, use tipos de cadeia de caracteres C++ padrão, como [wstring](../standard-library/basic-string-class.md) para qualquer processamento de texto significativo e, em seguida, converta o resultado final em [Platform::String^](../cppcx/platform-string-class.md) antes de transmiti-lo de ou para uma interface pública. A conversão entre `wstring` ou `wchar_t*` e `Platform::String`é fácil e eficiente.

**Passagem rápida**

Em alguns casos, o compilador pode verificar se pode construir com segurança uma `Platform::String` ou passar uma `String` a uma função sem copiar os dados da cadeia de caracteres subjacente. Essas operações são conhecidas como *passagens rápidas* e ocorrem de modo transparente.

## <a name="string-construction"></a>Construção da cadeia de caracteres

O valor de um objeto `String` é uma sequência imutável (somente leitura) de caracteres `char16` (Unicode de 16 bits). Como um objeto `String` é imutável, a atribuição de uma nova cadeia de caracteres literal a uma variável `String` na verdade substitui o objeto `String` original por um novo objeto `String` . As operações de concatenação envolvem a destruição do objeto `String` original e a criação de um novo objeto.

**Literais**

Um *caractere literal* é um caractere colocado entre aspas simples e uma *cadeia de caracteres literal* é uma sequência de caractere colocada entre aspas duplas. Se você usar um literal para inicializar uma variável String^, o compilador assumirá que o literal consiste em caracteres `char16` . Ou seja, você não tem que preceder o literal com o modificador de cadeia de caracteres 'L', nem colocar o literal em uma macro **_T()** ou **TEXT()** . Para obter mais informações sobre o suporte do C++ para Unicode, consulte [Unicode Programming Summary](../text/unicode-programming-summary.md).

O exemplo a seguir mostra várias maneiras de construir objetos `String` .

[!code-cpp[cx_strings#01](../cppcx/codesnippet/CPP/cppcx_strings/class1.cpp#01)]

## <a name="string-handling-operations"></a>Operações de manipulação de cadeia de caracteres

A classe `String` fornece métodos e operadores para concatenação, cadeias de caracteres de comparação e outras operações básicas de cadeia de caracteres. Para executar manipulações de cadeia de caracteres mais extensivas, use a função de membro `String::Data()` para recuperar o valor do objeto `String^` como um `const wchar_t*`. Em seguida, use esse valor para inicializar `std::wstring`, que fornece ricas funções de manipulação de cadeia de caracteres.

[!code-cpp[cx_strings#03](../cppcx/codesnippet/CPP/cppcx_strings/class1.cpp#03)]

## <a name="string-conversions"></a>Conversões de cadeia de caracteres

Uma `Platform::String` pode conter apenas caracteres `char16` ou o caractere `NULL` . Se o aplicativo tiver que funcionar com caracteres de 8 bits, `const wchar_t*`use o [String::Data](../cppcx/platform-string-class.md#data) para extrair o texto como um . Você pode usar as funções apropriadas do Windows ou as funções de Biblioteca Padrão para operar nos dados e convertê-los novamente em `wchar_t*` ou [wstring](../standard-library/basic-string-class.md), que poderá usar para construir uma nova `Platform::String`.

O fragmento de código a seguir mostra como converter uma variável `String^` de e em uma variável `wstring` . Para obter mais informações sobre a manipulação de cadeia de caracteres usada nesse exemplo, consulte [basic_string::replace](../standard-library/basic-string-class.md#replace).

[!code-cpp[cx_strings#04](../cppcx/codesnippet/CPP/cppcx_strings/class1.cpp#04)]

## <a name="string-length-and-embedded-null-values"></a>Valores de comprimento da cadeia de caracteres e NULL inserido

A [seqüência::Comprimento](../cppcx/platform-string-class.md#length) retorna o número de caracteres na seqüência, não o número de bytes. O caractere NULL de terminação não é contado, a menos que você o especifique explicitamente ao usar semântica de pilha para construir uma cadeia de caracteres.

Uma `Platform::String` pode conter valores NULL inseridos, mas somente quando o NULL for o resultado de uma operação de concatenação. Não há suporte para NULLs inseridos em cadeias de caracteres literais; portanto, você não pode usar NULLs inseridos nessa questão para inicializar `Platform::String`. Os valores NULL inseridos em uma `Platform::String` são ignorados quando a cadeia de caracteres é exibida, por exemplo, quando é atribuída a uma propriedade `TextBlock::Text` . NULLs inseridos são removidos quando o valor da cadeia de caracteres é retornado pela propriedade `Data` .

## <a name="stringreference"></a>StringReference

Em alguns casos, seu código (a) recebe um std::wstring, ou wchar_t string ou L"" string literal e apenas passa-o para outro método que toma um String^ como parâmetro de entrada. Contanto que o buffer da cadeia de caracteres original em si permaneça válido e não seja modificado antes de a função retornar, você pode converter a cadeia de caracteres `wchar_t*` ou o literal da cadeia de caracteres em [Platform::StringReference](../cppcx/platform-stringreference-class.md)e transmiti-lo em vez de `Platform::String^`. Isso é permitido porque `StringReference` tem uma conversão definida pelo usuário para `Platform::String^`. Usando `StringReference` , você pode evitar a necessidade de fazer uma cópia extra dos dados da cadeia de caracteres. Em loops em que você estiver transmitindo uma grande quantidade de cadeias de caracteres, ou ao transmitir cadeias de caracteres muito grandes, você poderá obter uma melhoria significativa de desempenho usando `StringReference`. Mas como `StringReference` essencialmente pega emprestado o buffer da cadeia de caracteres original, você deve ter extremo cuidado para evitar danos à memória. Você não deve transmitir `StringReference` a um método assíncrono a menos que a cadeia de caracteres original faça parte do escopo quando esse método retornar. Uma String^ inicializada a partir de uma StringReference forçará uma alocação e uma cópia dos dados da cadeia de caracteres se uma segunda operação de atribuição ocorrer. Nesse caso, você perderá o benefício de desempenho da `StringReference`.

Observe que `StringReference` é um tipo de classe C++ padrão, não uma classe ref, e não é possível usá-la na interface pública das classes ref que você definir.

O exemplo a seguir mostra como usar StringReference:

```cpp
void GetDecodedStrings(std::vector<std::wstring> strings)
{
    using namespace Windows::Security::Cryptography;
    using namespace Windows::Storage::Streams;

    for (auto&& s : strings)
    {
        // Method signature is IBuffer^ CryptographicBuffer::DecodeFromBase64String (Platform::String^)
        // Call using StringReference:
        IBuffer^ buffer = CryptographicBuffer::DecodeFromBase64String(StringReference(s.c_str()));

        //...do something with buffer
    }
}
```
