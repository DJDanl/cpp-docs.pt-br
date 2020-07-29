---
title: /Zc:ternary (Aplicar regras de operador condicional)
ms.date: 09/12/2019
f1_keywords:
- /Zc:ternary
helpviewer_keywords:
- /Zc:ternary
- Zc:ternary
- -Zc:ternary
ms.openlocfilehash: 04bd0c49528d86ddd4d1e6c77804cf64278db188
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211873"
---
# <a name="zcternary-enforce-conditional-operator-rules"></a>`/Zc:ternary`(Impor regras de operador condicional)

Habilite a imposição de regras padrão do C++ para os tipos e a qualificação const ou volátil (CV) do segundo e terceiro operandos em uma expressão de operador condicional.

## <a name="syntax"></a>Sintaxe

> **`/Zc:ternary`**[**`-`**]

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2017, o compilador dá suporte ao comportamento do *operador condicional* padrão C++ ( **`?:`** ). Ele também é conhecido como o *operador ternário*. O padrão C++ exige que os operandos de ternário satisfaçam uma das três condições: os operandos devem ser do mesmo tipo e **`const`** ou de **`volatile`** qualificação (qualificação de CV), ou apenas um operando deve ser convertido de forma não ambígua para o mesmo tipo e qualificação de CV que o outro. Ou, um ou ambos os operandos devem ser uma expressão throw. Em versões anteriores ao Visual Studio 2017 versão 15,5, o compilador permitia conversões que são consideradas ambíguas pelo padrão.

Quando a **`/Zc:ternary`** opção é especificada, o compilador está em conformidade com o padrão. Ele rejeita o código que não satisfaz as regras para tipos correspondentes e qualificação de CV do segundo e terceiro operandos.

A **`/Zc:ternary`** opção está desativada por padrão no Visual Studio 2017. Use **`/Zc:ternary`** para habilitar o comportamento de conformidade ou **`/Zc:ternary-`** para especificar explicitamente o comportamento de compilador não compatível anterior. A [`/permissive-`](permissive-standards-conformance.md) opção habilita implicitamente essa opção, mas pode ser substituída usando **`/Zc:ternary-`** .

### <a name="examples"></a>Exemplos

Este exemplo mostra como uma classe que fornece inicialização não explícita de um tipo e conversão para um tipo pode levar a conversões ambíguas. Esse código é aceito pelo compilador por padrão, mas rejeitado quando **/`Zc:ternary`** ou **`/permissive-`** é especificado.

```cpp
// zcternary1.cpp
// Compile by using: cl /EHsc /W4 /nologo /Zc:ternary zcternary1.cpp

struct A
{
   long l;
   A(int i) : l{i} {}    // explicit prevents conversion of int
   operator int() const { return static_cast<int>(l); }
};

int main()
{
   A a(42);
   // Accepted when /Zc:ternary (or /permissive-) is not used
   auto x = true ? 7 : a;  // old behavior prefers A(7) over (int)a
   auto y = true ? A(7) : a;   // always accepted
   auto z = true ? 7 : (int)a; // always accepted
   return x + y + z;
}
```

Para corrigir esse código, faça uma conversão explícita para o tipo comum preferencial ou Evite uma direção de conversão de tipo. Você pode impedir que o compilador corresponda a uma conversão de tipo, tornando a conversão explícita.

Uma exceção importante para esse padrão comum é quando o tipo dos operandos é um dos tipos de cadeia de caracteres terminadas em nulo, como `const char*` , `const char16_t*` e assim por diante. Você também pode reproduzir o efeito com tipos de matriz e os tipos de ponteiro que eles decaimento. O comportamento quando o segundo ou terceiro operando real `?:` é um literal de cadeia de caracteres do tipo correspondente depende do padrão de idioma usado. O c++ 17 alterou a semântica para esse caso do C++ 14. Como resultado, o compilador aceita o código no exemplo a seguir sob o padrão **`/std:c++14`** , mas rejeita-o quando você especifica **`/std:c++17`** .

```cpp
// zcternary2.cpp
// Compile by using: cl /EHsc /W4 /nologo /Zc:ternary /std:c++17 zcternary2.cpp

struct MyString
{
   const char * p;
   MyString(const char* s = "") noexcept : p{s} {} // from char*
   operator const char*() const noexcept { return p; } // to char*
};

int main()
{
   MyString s;
   auto x = true ? "A" : s; // MyString: permissive prefers MyString("A") over (const char*)s
}
```

Para corrigir esse código, converta um dos operandos explicitamente.

Em **`/Zc:ternary`** , o compilador rejeita operadores condicionais em que um dos argumentos é do tipo **`void`** e o outro não é uma **`throw`** expressão. Um uso comum desse padrão é em macros semelhantes a ASSERT:

```cpp
// zcternary3.cpp
// Compile by using: cl /EHsc /W4 /nologo /Zc:ternary /c zcternary3.cpp

void myassert(const char* text, const char* file, int line);
#define ASSERT(ex) (void)((ex) ? 0 : myassert(#ex, __FILE__, __LINE__))
// To fix, define it this way instead:
// #define ASSERT(ex) (void)((ex) ? void() : myassert(#ex, __FILE__, __LINE__))

int main()
{
   ASSERT(false);  // C3447
}
```

A solução típica é substituir o argumento não void por `void()` .

Este exemplo mostra o código que gera um erro em **`/Zc:ternary`** e **`/Zc:ternary-`** :

```cpp
// zcternary4.cpp
// Compile by using:
//   cl /EHsc /W4 /nologo /Zc:ternary zcternary4.cpp
//   cl /EHsc /W4 /nologo /Zc:ternary zcternary4.cpp

int main() {
   auto p1 = [](int a, int b) { return a > b; };
   auto p2 = [](int a, int b) { return a > b; };
   auto p3 = true ? p1 : p2; // C2593 under /Zc:ternary, was C2446
}
```

Esse código fornecia esse erro anteriormente:

```Output
error C2446: ':': no conversion from 'foo::<lambda_f6cd18702c42f6cd636bfee362b37033>' to 'foo::<lambda_717fca3fc65510deea10bc47e2b06be4>'
note: No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
```

Com **`/Zc:ternary`** o, o motivo da falha se torna mais claro. Qualquer uma das várias convenções de chamada definidas pela implementação poderia ser usada para gerar cada lambda. No entanto, o compilador não tem nenhuma regra de preferência para desambiguar as possíveis assinaturas lambda. A nova saída tem a seguinte aparência:

```Output
error C2593: 'operator ?' is ambiguous
note: could be 'built-in C++ operator?(bool (__cdecl *)(int,int), bool (__cdecl *)(int,int))'
note: or       'built-in C++ operator?(bool (__stdcall *)(int,int), bool (__stdcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__fastcall *)(int,int), bool (__fastcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__vectorcall *)(int,int), bool (__vectorcall *)(int,int))'
note: while trying to match the argument list '(foo::<lambda_717fca3fc65510deea10bc47e2b06be4>, foo::<lambda_f6cd18702c42f6cd636bfee362b37033>)'
```

Uma fonte comum de problemas encontrados **`/Zc:ternary`** vem de operadores condicionais usados na meta-programação de modelo. Alguns dos tipos de resultado mudam nessa opção. O exemplo a seguir demonstra dois casos em que o **`/Zc:ternary`** altera o tipo de resultado de uma expressão condicional em um contexto de não meta-programação:

```cpp
// zcternary5.cpp
// Compile by using: cl /EHsc /W4 /nologo /Zc:ternary zcternary5.cpp

int main(int argc, char**) {
   char a = 'A';
   const char b = 'B';
   decltype(auto) x = true ? a : b; // char without, const char& with /Zc:ternary
   const char(&z)[2] = argc > 3 ? "A" : "B"; // const char* without /Zc:ternary
   return x > *z;
}
```

A correção típica é aplicar uma `std::remove_reference` característica no tipo de resultado, quando necessário para preservar o comportamento antigo.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **`/Zc:ternary`** ou **`/Zc:ternary-`** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[`/Zc`Conformidade](zc-conformance.md)
