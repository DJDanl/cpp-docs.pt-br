---
title: '/ZC: ternary (Aplicar regras de operador condicional)'
ms.date: 3/06/2018
f1_keywords:
- /Zc:ternary
helpviewer_keywords:
- /Zc:ternary
- Zc:ternary
- -Zc:ternary
ms.openlocfilehash: cb9a4f8468a9cb57af711cdca36ee343e5092493
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315424"
---
# <a name="zcternary-enforce-conditional-operator-rules"></a>/ZC: ternary (Aplicar regras de operador condicional)

Habilite a imposição de regras padrão do C++ para os tipos e const ou volatile qualificação (VC) do segundo e terceiro operandos em uma expressão de operador condicional.

## <a name="syntax"></a>Sintaxe

> **/Zc:ternary**[**-**]

## <a name="remarks"></a>Comentários

Visual Studio versão 15.3 habilita o suporte de compilador para operador condicional (ou Ternário) padrão do C++ (**?:**) comportamento. O padrão C++ requer que ambos os operandos para ser do mesmo tipo e qualificação de cv, ou apenas um operando ser inequivocamente conversível para o mesmo tipo e qualificação de cv como o outro ou para um ou ambos os operandos ser uma expressão de lançamento. Nas versões anteriores do Visual Studio versão 15.5, o compilador permitia conversões que são consideradas ambíguas pelo padrão. Quando o **/ZC: ternary** opção for especificada, o compilador esteja de acordo com o padrão e rejeita o código que não satisfazem as regras para tipos correspondentes e qualificação de cv-os segundo e terceiro operandos.

O **/ZC: ternary** opção está desativada por padrão. Use **/ZC: ternary** para habilitar o comportamento de conformidade, ou **/Zc:ternary-** para especificar explicitamente o comportamento do compilador anterior não conformes. O [/permissive--](permissive-standards-conformance.md) opção implicitamente habilita essa opção, mas ele pode ser substituído usando **/Zc:ternary-**.

### <a name="examples"></a>Exemplos

Este exemplo mostra como uma classe que fornece os dois não explícita a inicialização de um tipo e a conversão para um tipo pode levar a conversões ambíguas. Esse código é aceito pelo compilador, por padrão, mas rejeitado quando **/ZC: ternary** ou **/permissive--** for especificado.

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

É a correção necessária fazer uma conversão explícita para o tipo preferencial de comum ou impedir uma direção de conversão da participação na pesquisa de compilador para que uma correspondência de tipo ao fazer a conversão explícita.

Uma exceção importante para esse padrão comum é quando o tipo dos operandos é um dos tipos de cadeia de caracteres terminada em nulo, tais como `const char*`, `const char16_t*`e assim por diante. Você também pode reproduzir isso com tipos de matriz e eles decay para os tipos de ponteiro. O comportamento quando o operando de segundo ou terceiro real para?: é um literal de cadeia de caracteres de tipo correspondente depende do idioma padrão usado. C++17 mudou a semântica para esse caso de C + + 14. Como resultado, o código no exemplo a seguir é aceito em **/std:c++17 + + 14** (o padrão do compilador), mas é rejeitada quando **/std: c + + 17** for especificado.

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

Sob **/ZC: ternary**, os operadores condicionais de compilador rejeita onde um dos argumentos é do tipo void e o outro não é uma expressão de lançamento. Um uso comum desses está nas macros de declaração:

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

A solução típica é simplesmente substituir o argumento não nulo com void().

Este exemplo mostra o código que gera um erro em ambos **/ZC: ternary** e **/Zc:ternary-**:

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

Esse código anteriormente deu a esse erro:

```Output
error C2446: ':': no conversion from 'foo::<lambda_f6cd18702c42f6cd636bfee362b37033>' to 'foo::<lambda_717fca3fc65510deea10bc47e2b06be4>'
note: No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
```

Com o **/ZC: ternary** o motivo da falha se torna mais claro; em arquiteturas em que qualquer uma das várias convenções de chamada definido pela implementação pode ser usado para gerar cada lambda, o compilador não expressa nenhuma preferência entre eles que pode resolver a ambiguidade as assinaturas de lambda possíveis. A nova saída tem esta aparência:

```Output
error C2593: 'operator ?' is ambiguous
note: could be 'built-in C++ operator?(bool (__cdecl *)(int,int), bool (__cdecl *)(int,int))'
note: or       'built-in C++ operator?(bool (__stdcall *)(int,int), bool (__stdcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__fastcall *)(int,int), bool (__fastcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__vectorcall *)(int,int), bool (__vectorcall *)(int,int))'
note: while trying to match the argument list '(foo::<lambda_717fca3fc65510deea10bc47e2b06be4>, foo::<lambda_f6cd18702c42f6cd636bfee362b37033>)'
```

Uma fonte comum de problemas relacionados à adoção **/ZC: ternary** vem do uso do operador condicional no modelo metaprogramação, conforme alguns dos tipos result alteram sob essa opção. O exemplo a seguir demonstra dois casos em que **/ZC: ternary** altera o tipo de resultado de uma expressão condicional em um contexto de programação de meta:

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

A resolução comum nesses casos é aplicar um `std::remove_reference` onde for necessário para preservar o comportamento antigo de tipo de característica no resultado.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: ternary** ou **/Zc:ternary-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)
