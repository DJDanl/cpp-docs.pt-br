---
title: /ZC:ternary (Aplicar regras de operador condicional) | Microsoft Docs
ms.date: 3/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Zc:ternary
dev_langs:
- C++
helpviewer_keywords:
- /Zc:ternary
- Zc:ternary
- -Zc:ternary
author: corob-msft
ms.author: corob
ms.openlocfilehash: 613381795fb962e1f10ec01598748b617b7543aa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32380817"
---
# <a name="zcternary-enforce-conditional-operator-rules"></a>/ZC:ternary (Aplicar regras de operador condicional)

Habilite a imposição de regras de C++ padrão para os tipos e const ou volátil qualificação (VC) do segundo e terceiro operandos em uma expressão de operador condicional.

## <a name="syntax"></a>Sintaxe

> **/Zc:ternary**[**-**]

## <a name="remarks"></a>Comentários

Visual Studio versão 15,3 habilita o suporte de compilador para operador condicional (ou Ternário) padrão do C++ (**?:**) comportamento. O padrão C++ requer operandos para ser do mesmo tipo e VC-qualificação, ou apenas um operando ser inequivocamente conversível para o mesmo tipo e VC-qualificação como o outro ou para um ou ambos os operandos ser uma expressão throw. Nas versões anteriores do Visual Studio versão 15,5, o compilador permitidas conversões que são considerados ambíguos por padrão. Quando o **/Zc:ternary** opção for especificada, o compilador está de acordo com o padrão e rejeita o código que não satisfazem as regras para tipos correspondentes e VC-qualificação de segundo e terceiro operandos.

O **/Zc:ternary** opção está desativada por padrão. Use **/Zc:ternary** para habilitar o comportamento de conformidade, ou **/Zc:ternary-** para especificar explicitamente o comportamento do compilador não conformes anterior. O [/ permissivo-](permissive-standards-conformance.md) opção implicitamente habilita essa opção, mas ele pode ser substituído usando **/Zc:ternary-**.

### <a name="examples"></a>Exemplos

Este exemplo mostra como uma classe que fornece os dois inicialização não explícita de um tipo e a conversão para um tipo pode levar a conversões ambíguas. Esse código é aceita pelo compilador por padrão, mas rejeitada quando **/Zc:ternary** ou **/ permissivo-** for especificado.

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

A correção necessária é fazer uma conversão explícita para o tipo preferencial de comuns, ou impedir que uma direção de conversão de participação na pesquisa de compilador para um tipo de correspondência, tornando a conversão explícita.

Uma exceção a esse padrão comum é quando o tipo dos operandos é um dos tipos de cadeia de caracteres terminada em nulo, como `const char*`, `const char16_t*`e assim por diante. Você também pode reproduzir isso com tipos de matriz e os tipos de ponteiro para que eles decay. O comportamento quando o operando real de segundo ou de terceiro para?: é um literal de cadeia de caracteres do tipo correspondente depende do idioma padrão usado. C++ 17 foi alterado semântica para esse caso de C + + 14. Como resultado, o código no exemplo a seguir é aceito em **/std:c + + 14** (o padrão do compilador), mas é rejeitada quando **/std:c + + 17** for especificado.

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

Em **/Zc:ternary**, os operadores condicionais de compilador rejeita onde um dos argumentos é do tipo nulo e o outro não é uma expressão throw. Um uso comum deles está em macros de declaração:

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

A solução típica é simplesmente substitua o argumento não void void().

Este exemplo mostra o código que gera um erro em ambos **/Zc:ternary** e **/Zc:ternary-**:

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

Esse código fornecido anteriormente este erro:

```Output
error C2446: ':': no conversion from 'foo::<lambda_f6cd18702c42f6cd636bfee362b37033>' to 'foo::<lambda_717fca3fc65510deea10bc47e2b06be4>'
note: No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
```

Com **/Zc:ternary** o motivo da falha se torna mais claro; arquiteturas onde qualquer uma das várias convenções de chamada definido pela implementação pode ser usado para gerar cada lambda, o compilador expressa sem preferência entre eles que pode resolver a ambiguidade as assinaturas de lambda possíveis. A nova saída terá esta aparência:

```Output
error C2593: 'operator ?' is ambiguous
note: could be 'built-in C++ operator?(bool (__cdecl *)(int,int), bool (__cdecl *)(int,int))'
note: or       'built-in C++ operator?(bool (__stdcall *)(int,int), bool (__stdcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__fastcall *)(int,int), bool (__fastcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__vectorcall *)(int,int), bool (__vectorcall *)(int,int))'
note: while trying to match the argument list '(foo::<lambda_717fca3fc65510deea10bc47e2b06be4>, foo::<lambda_f6cd18702c42f6cd636bfee362b37033>)'
```

Uma fonte comum de problemas relacionados a adoção de **/Zc:ternary** vêm com o uso do operador condicional no modelo metaprogramação, como alguns dos tipos de resultado altera de acordo com essa opção. O exemplo a seguir demonstra dois casos onde **/Zc:ternary** altera o tipo de resultado de uma expressão condicional em um contexto de programação de metadados:

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

A resolução típica nesses casos é aplicar uma `std::remove_reference` característica no resultado de tipo quando for necessário para preservar o comportamento antigo.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:ternary** ou **/Zc:ternary-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)  
