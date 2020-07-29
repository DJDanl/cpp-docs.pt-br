---
title: /EH (modelo de tratamento de exceções)
description: Guia de referência para as opções de compilador do Microsoft C++/EH (modelo de tratamento de exceções) no Visual Studio.
ms.date: 04/14/2020
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ExceptionHandling
- /eh
- VC.Project.VCCLCompilerTool.ExceptionHandling
helpviewer_keywords:
- exception handling, compiler model
- cl.exe compiler, exception handling
- EH compiler option [C++]
- -EH compiler option [C++]
- /EH compiler option [C++]
no-loc:
- ':::no-loc(SEH):::'
- ':::no-loc(try):::'
- ':::no-loc(catch):::'
- ':::no-loc(throw):::'
- ':::no-loc(extern):::'
- ':::no-loc(finally):::'
- ':::no-loc(noexcept):::'
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
ms.openlocfilehash: f158e951d595d5934ff513254871710db5920bf1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232710"
---
# <a name="eh-exception-handling-model"></a>/EH (modelo de tratamento de exceções)

Especifica o suporte ao modelo de manipulação de exceção gerado pelo compilador. Os argumentos especificam se a sintaxe deve ser aplicada `:::no-loc(catch):::(...)` a exceções C++ estruturadas e padrão, se o código ** :::no-loc(extern)::: "C"** é considerado para :::no-loc(throw)::: exceções e se é possível otimizar a ausência de **`:::no-loc(noexcept):::`** verificações específicas.

## <a name="syntax"></a>Sintaxe

> **`/EHa`**[**`-`**]\
> **`/EHs`**[**`-`**]\
> **`/EHc`**[**`-`**]\
> **`/EHr`**[**`-`**]

## <a name="arguments"></a>Argumentos

**`a`**\
Habilita o desenrolamento de pilha C++ padrão. O captura as exceções estruturadas (assíncronas) e C++ padrão (síncronas) quando você usa a `:::no-loc(catch):::(...)` sintaxe. **`/EHa`** Substitui ambos **`/EHs`** os **`/EHc`** argumentos e.

**`s`**\
Habilita o desenrolamento de pilha C++ padrão. Captura apenas exceções C++ padrão quando você usa a `:::no-loc(catch):::(...)` sintaxe. A menos que **`/EHc`** também seja especificado, o compilador assume que as funções declaradas como ** :::no-loc(extern)::: "C"** podem ser :::no-loc(throw)::: uma exceção de C++.

**`c`**\
Quando usado com **`/EHs`** , o compilador assume que funções declaradas como ** :::no-loc(extern)::: "C"** nunca são :::no-loc(throw)::: uma exceção de C++. Ele não tem efeito quando usado com **`/EHa`** (ou seja, **`/EHca`** é equivalente a **`/EHa`** ). **`/EHc`** será ignorado se **`/EHs`** ou **`/EHa`** não for especificado.

**`r`**\
Informa ao compilador para sempre gerar verificações de término de tempo de execução para todas as **`:::no-loc(noexcept):::`** funções. Por padrão, as verificações de tempo de execução **`:::no-loc(noexcept):::`** podem ser otimizadas se o compilador determinar que as chamadas de função são apenas :::no-loc(throw)::: funções não ing. Essa opção fornece a conformidade do C++ estrita ao custo de algum código extra. **`/EHr`** será ignorado se **`/EHs`** ou **`/EHa`** não for especificado.

**`-`**\
Limpa o argumento de opção anterior. Por exemplo, **`/EHsc-`** é interpretado como **`/EHs /EHc-`** e é equivalente a **`/EHs`** .

**`/EH`** os argumentos podem ser especificados separadamente ou combinados, em qualquer ordem. Se mais de uma instância do mesmo argumento for especificada, a última substituirá as anteriores.  Por exemplo, **`/EHr- /EHc /EHs`** é o mesmo que **`/EHscr-`** e **`/EHscr- /EHr`** tem o mesmo efeito que **`/EHscr`** .

## <a name="remarks"></a>Comentários

### <a name="default-exception-handling-behavior"></a>Comportamento de tratamento de exceção padrão

O compilador sempre gera código que dá suporte ao tratamento de exceção estruturada assíncrona ( :::no-loc(SEH)::: ). Por padrão (ou seja, se nenhuma **`/EHsc`** **`/EHs`** opção, ou **`/EHa`** for especificada), o compilador oferece suporte a :::no-loc(SEH)::: manipuladores na cláusula C++ nativa `:::no-loc(catch):::(...)` . No entanto, ele também gera código que dá suporte parcial apenas a exceções C++. O código de desenrolamento de exceção padrão não destrói objetos C++ automáticos fora dos [:::no-loc(try):::](../../cpp/:::no-loc(try):::-:::no-loc(throw):::-and-:::no-loc(catch):::-statements-cpp.md) blocos que saem do escopo devido a uma exceção. Vazamentos de recursos e comportamento indefinido podem ocorrer quando uma exceção de C++ é :::no-loc(throw)::: n.

### <a name="standard-c-exception-handling"></a>Manipulação de exceção padrão do C++

Suporte completo ao compilador para o modelo de manipulação de exceção C++ padrão que o desenrola com segurança de objetos de pilha requer **`/EHsc`** (recomendado), **`/EHs`** ou **`/EHa`** .

Se você usar **`/EHs`** ou **`/EHsc`** , suas `:::no-loc(catch):::(...)` cláusulas não são :::no-loc(catch)::: exceções estruturadas assíncronas. Quaisquer violações de acesso e <xref:System.Exception?displayProperty=fullName> exceções gerenciadas vão despercebidas. E, os objetos no escopo quando ocorre uma exceção assíncrona não são destruídos, mesmo que o código manipule a exceção assíncrona. Esse comportamento é um argumento para deixar exceções estruturadas sem tratamento. Em vez disso, considere essas exceções fatais.

Quando você usa **`/EHs`** **`/EHsc`** o ou o, o compilador supõe que as exceções só podem ocorrer em uma **`:::no-loc(throw):::`** instrução ou em uma chamada de função. Essa suposição permite que o compilador elimine o código para acompanhar o tempo de vida de muitos objetos desenrolados, o que pode reduzir significativamente o tamanho do código. Se você usar **`/EHa`** o, a imagem executável poderá ser maior e mais lenta, pois o compilador não otimiza os **`:::no-loc(try):::`** blocos de forma agressiva. Ele também deixa em filtros de exceção que limpam automaticamente os objetos locais, mesmo que o compilador não veja qualquer código que possa :::no-loc(throw)::: uma exceção de C++.

### <a name="structured-and-standard-c-exception-handling"></a>Manipulação de exceção C++ estruturada e Standard

A **`/EHa`** opção de compilador habilita o desenrolamento de pilha segura para exceções assíncronas e exceções de C++. Ele dá suporte ao tratamento de C++ padrão e de exceções estruturadas usando a `:::no-loc(catch):::(...)` cláusula c++ nativa. Para implementar :::no-loc(SEH)::: sem especificar **`/EHa`** , você pode usar a **sintaxe :::no-loc(try)::: _ _**, **`__except`** e **`__:::no-loc(finally):::`** . Para obter mais informações, consulte [manipulação de exceção estruturada](../../cpp/structured-exception-handling-c-cpp.md).

> [!IMPORTANT]
> Especificar **`/EHa`** e o :::no-loc(try)::: ing para lidar com todas as exceções usando o `:::no-loc(catch):::(...)` pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.
>
> Embora o suporte ao Windows e Visual C++ :::no-loc(SEH)::: , é altamente recomendável que você use a manipulação de exceção do C++ padrão ISO ( **`/EHsc`** ou **`/EHs`** ). Ele torna seu código mais portátil e flexível. Ainda pode haver ocasiões em que você precisa usar :::no-loc(SEH)::: no código herdado ou em determinados tipos de programas. Ele é necessário no código compilado para dar suporte ao Common Language Runtime ([/CLR](clr-common-language-runtime-compilation.md)), por exemplo. Para obter mais informações, consulte [manipulação de exceção estruturada](../../cpp/structured-exception-handling-c-cpp.md).
>
> Recomendamos que você nunca vincule arquivos de objeto compilados usando **`/EHa`** para aqueles compilados usando **`/EHs`** **`/EHsc`** o ou no mesmo módulo executável. Se você precisar manipular uma exceção assíncrona usando **`/EHa`** qualquer lugar em seu módulo, use **`/EHa`** para compilar todo o código no módulo. Você pode usar a sintaxe de manipulação de exceção estruturada no mesmo módulo que o código que é compilado usando o **`/EHs`** . No entanto, você não pode misturar a :::no-loc(SEH)::: sintaxe com C++ **`:::no-loc(try):::`** , **`:::no-loc(throw):::`** e **`:::no-loc(catch):::`** na mesma função.

Use **`/EHa`** se você quiser :::no-loc(catch)::: uma exceção que seja gerada por algo diferente de a **`:::no-loc(throw):::`** . Este exemplo gera e :::no-loc(catch)::: es uma exceção estruturada:

```cpp
// compiler_options_EHA.cpp
// compile with: /EHa
#include <iostream>
#include <excpt.h>
using namespace std;

void fail()
{
    // generates SE and attempts to :::no-loc(catch)::: it using :::no-loc(catch):::(...)
    :::no-loc(try):::
    {
        int i = 0, j = 1;
        j /= i;   // This will :::no-loc(throw)::: a SE (divide by zero).
        printf("%d", j);
    }
    :::no-loc(catch):::(...)
    {
        // :::no-loc(catch)::: block will only be executed under /EHa
        cout << "Caught an exception in :::no-loc(catch):::(...)." << endl;
    }
}

int main()
{
    __:::no-loc(try):::
    {
        fail();
    }

    // __except will only :::no-loc(catch)::: an exception here
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        // if the exception was not caught by the :::no-loc(catch):::(...) inside fail()
        cout << "An exception was caught in __except." << endl;
    }
}
```

### <a name="exception-handling-under-clr"></a>Tratamento de exceção sob/CLR

A **`/clr`** opção implica **`/EHa`** (ou seja, **`/clr /EHa`** é redundante). O compilador gerará um erro se **`/EHs`** ou **`/EHsc`** for usado após **`/clr`** . As otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invoca os destruidores de classe para todos os objetos que estão no mesmo escopo que a exceção. Se uma exceção não for detectada, esses destruidores não serão executados.

Para obter informações sobre restrições de tratamento **`/clr`** de exceção em, consulte [_set_se_translator](../../c-runtime-library/reference/set-se-translator.md).

### <a name="runtime-exception-checks"></a>Verificações de exceção de tempo de execução

A **`/EHr`** opção força as verificações de término do tempo de execução em todas as funções que têm um **`:::no-loc(noexcept):::`** atributo. Por padrão, as verificações de tempo de execução poderão ser otimizadas se o back-end do compilador determinar que uma função só chama funções *não :::no-loc(throw)::: ing* . Funções não :::no-loc(throw)::: ing são funções que têm um atributo que especifica que nenhuma exceção pode ser :::no-loc(throw)::: n. Elas incluem funções marcadas **`:::no-loc(noexcept):::`** , `:::no-loc(throw):::()` , `__declspec(no:::no-loc(throw):::)` e, quando **`/EHc`** é especificada, ** :::no-loc(extern)::: "C"** functions. :::no-loc(throw):::As funções não-ing também incluem qualquer que o compilador determinado seja não- :::no-loc(throw)::: ing por inspeção. Você pode definir explicitamente o comportamento padrão usando **`/EHr-`** .

Um atributo não- :::no-loc(throw)::: ing não é uma garantia de que as exceções não podem ser :::no-loc(throw)::: n por uma função. Ao contrário do comportamento de uma **`:::no-loc(noexcept):::`** função, o compilador MSVC considera uma exceção :::no-loc(throw)::: n por uma função declarada usando `:::no-loc(throw):::()` , `__declspec(no:::no-loc(throw):::)` ou ** :::no-loc(extern)::: "C"** como comportamento indefinido. As funções que usam esses três atributos de declaração não impõem verificações de término de tempo de execução para exceções. Você pode usar a **`/EHr`** opção para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador a gerar verificações de tempo de execução para exceções sem tratamento que escapem uma **`:::no-loc(noexcept):::`** função.

## <a name="set-the-option-in-visual-studio-or-programmatically"></a>Definir a opção no Visual Studio ou programaticamente

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **Propriedades de configuração**  >  geração de código**C/C++**  >  **Code Generation**.

1. Modifique a propriedade **Habilitar exceções C++** .

   Ou defina **Habilitar exceções do C++** como **não**e, em seguida, na página de propriedades da **linha de comando** , na caixa **Opções adicionais** , adicione a opção do compilador.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)\
[Erros e tratamento de exceção](../../cpp/errors-and-exception-handling-modern-cpp.md)\
[Especificações de exceção ( :::no-loc(throw)::: )](../../cpp/exception-specifications-:::no-loc(throw):::-cpp.md)\
[Manipulação de exceção estruturada (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)
