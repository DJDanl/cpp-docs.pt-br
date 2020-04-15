---
title: /Zc:ternary (Aplicar regras de operador condicional)
ms.date: 09/12/2019
f1_keywords:
- /Zc:ternary
helpviewer_keywords:
- /Zc:ternary
- Zc:ternary
- -Zc:ternary
ms.openlocfilehash: 7c95f061e195ccf7fef8a6a21d193b257baa5f39
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335671"
---
# <a name="zcternary-enforce-conditional-operator-rules"></a>/Zc:ternary (Aplicar regras de operador condicional)

Permitir a aplicação das regras padrão C++ para os tipos e qualificação const ou volátil (cv) do segundo e terceiro operands em uma expressão de operador condicional.

## <a name="syntax"></a>Sintaxe

> **/Zc:ternário****-**[ ]

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2017, o compilador suporta o comportamento *do operador padrão* C++ (**?:**). Também é conhecido como o *operador ternário.* A Norma C++ exige que os operands de ternário satisfaçam uma das três condições: Os operands devem ser do mesmo tipo e qualificação **const** ou **volátil** (cv-qualificação), ou apenas um operand deve ser inequivocamente conversível para o mesmo tipo e cv-qualificação como o outro. Ou, um ou ambos os operands deve ser uma expressão de arremesso. Em versões anteriores ao Visual Studio 2017 versão 15.5, o compilador permitiu conversões que são consideradas ambíguas pela norma.

Quando a opção **/Zc:ternário** é especificada, o compilador está de acordo com o padrão. Ele rejeita código que não satisfaz as regras para tipos combinados e qualificação cv do segundo e terceiro operands.

A opção **/Zc:ternary** está desligada por padrão no Visual Studio 2017. Use **/Zc:ternary** para permitir o comportamento em conformidade, ou **/Zc:ternary-** para especificar explicitamente o comportamento anterior do compilador não conforme. A opção [/permissiva](permissive-standards-conformance.md) permite implicitamente essa opção, mas pode ser substituída usando **/Zc:ternário-**.

### <a name="examples"></a>Exemplos

Esta amostra mostra como uma classe que fornece inicialização não explícita de um tipo e conversão para um tipo, pode levar a conversões ambíguas. Este código é aceito pelo compilador por padrão, mas rejeitado quando **/Zc:ternary** ou **/permissivo-** é especificado.

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

Para corrigir este código, faça um elenco explícito para o tipo comum preferido ou impeça uma direção de conversão de tipo. Você pode impedir que o compilador corresponda a uma conversão de tipo, tornando a conversão explícita.

Uma exceção importante para este padrão comum é quando o tipo de operands `const char*` `const char16_t*`é um dos tipos de cordas nulamente terminadas, como , e assim por diante. Você também pode reproduzir o efeito com os tipos de matriz e os tipos de ponteiros para os seus tipos de decomposição. O comportamento quando o segundo ou `?:` terceiro operativo real é uma seqüência literal do tipo correspondente depende do padrão linguístico utilizado. C++17 mudou a semântica para este caso de C++14. Como resultado, o compilador aceita o código no exemplo a seguir no padrão **/std:c++14**, mas o rejeita quando você especifica **/std:c++17**.

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

Para corrigir este código, lance um dos operands explicitamente.

Em **/Zc:ternário,** o compilador rejeita operadores condicionais onde um dos argumentos é de **tipo vazio,** e o outro não é uma expressão de arremesso. Um uso comum desse padrão está em macros semelhantes a ASSERT:

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

A solução típica é substituir o `void()`argumento não nulo por .

Esta amostra mostra o código que gera um erro em **/Zc:ternary** e **/Zc:ternary-**:

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

Este código anteriormente deu este erro:

```Output
error C2446: ':': no conversion from 'foo::<lambda_f6cd18702c42f6cd636bfee362b37033>' to 'foo::<lambda_717fca3fc65510deea10bc47e2b06be4>'
note: No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
```

Com **/Zc:ternário,** a razão do fracasso torna-se mais clara. Qualquer uma das várias convenções de chamada definidas pela implementação poderia ser usada para gerar cada lambda. No entanto, o compilador não tem regra de preferência para desambiguizar as possíveis assinaturas de lambda. A nova saída é assim:

```Output
error C2593: 'operator ?' is ambiguous
note: could be 'built-in C++ operator?(bool (__cdecl *)(int,int), bool (__cdecl *)(int,int))'
note: or       'built-in C++ operator?(bool (__stdcall *)(int,int), bool (__stdcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__fastcall *)(int,int), bool (__fastcall *)(int,int))'
note: or       'built-in C++ operator?(bool (__vectorcall *)(int,int), bool (__vectorcall *)(int,int))'
note: while trying to match the argument list '(foo::<lambda_717fca3fc65510deea10bc47e2b06be4>, foo::<lambda_f6cd18702c42f6cd636bfee362b37033>)'
```

Uma fonte comum de problemas encontrados por **/Zc:ternary** vem de operadores condicionais usados na metaprogramação de modelos. Alguns dos tipos de resultados mudam sob este interruptor. O exemplo a seguir demonstra dois casos em que **/Zc:ternário** altera o tipo de resultado de uma expressão condicional em um contexto não meta-programação:

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

A correção típica `std::remove_reference` é aplicar uma característica no tipo de resultado, onde necessário para preservar o comportamento antigo.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [Comportamento Não Padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de**propriedade** **Configuração Propriedades** > **C/C++.** > 

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc:ternary** ou **/Zc:ternary-** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
