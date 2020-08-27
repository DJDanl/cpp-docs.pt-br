---
title: /EH (modelo de tratamento de exceções)
description: Guia de referência para as opções de compilador do Microsoft C++/EH (modelo de tratamento de exceções) no Visual Studio.
ms.date: 08/25/2020
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
- SEH
- try
- catch
- throw
- extern
- finally
- noexcept
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
ms.openlocfilehash: 0d18d0f1d73b1de46b12262deecb2436c34e6176
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898378"
---
# <a name="eh-exception-handling-model"></a>`/EH` (Modelo de tratamento de exceção)

Especifica o suporte ao modelo de manipulação de exceção gerado pelo compilador. Os argumentos especificam se a sintaxe deve ser aplicada `catch(...)` a exceções C++ estruturadas e padrão, se o código ** extern "C"** é considerado para throw exceções e se é possível otimizar a ausência de **`noexcept`** verificações específicas.

## <a name="syntax"></a>Sintaxe

> **`/EHa`**[**`-`**]\
> **`/EHs`**[**`-`**]\
> **`/EHc`**[**`-`**]\
> **`/EHr`**[**`-`**]

## <a name="arguments"></a>Argumentos

**`a`**\
Habilita o desenrolamento de pilha C++ padrão. O captura as exceções estruturadas (assíncronas) e C++ padrão (síncronas) quando você usa a `catch(...)` sintaxe. **`/EHa`** Substitui ambos **`/EHs`** os **`/EHc`** argumentos e.

**`s`**\
Habilita o desenrolamento de pilha C++ padrão. Captura apenas exceções C++ padrão quando você usa a `catch(...)` sintaxe. A menos que **`/EHc`** também seja especificado, o compilador assume que as funções declaradas como ** extern "C"** podem ser throw uma exceção de C++.

**`c`**\
Quando usado com **`/EHs`** , o compilador assume que funções declaradas como ** extern "C"** nunca são throw uma exceção de C++. Ele não tem efeito quando usado com **`/EHa`** (ou seja, **`/EHca`** é equivalente a **`/EHa`** ). **`/EHc`** será ignorado se **`/EHs`** ou **`/EHa`** não for especificado.

**`r`**\
Informa ao compilador para sempre gerar verificações de término de tempo de execução para todas as **`noexcept`** funções. Por padrão, as verificações de tempo de execução **`noexcept`** podem ser otimizadas se o compilador determinar que as chamadas de função são apenas throw funções não ing. Essa opção fornece a conformidade do C++ estrita ao custo de algum código extra. **`/EHr`** será ignorado se **`/EHs`** ou **`/EHa`** não for especificado.

**`-`**\
Limpa o argumento de opção anterior. Por exemplo, **`/EHsc-`** é interpretado como **`/EHs /EHc-`** e é equivalente a **`/EHs`** .

**`/EH`** os argumentos podem ser especificados separadamente ou combinados, em qualquer ordem. Se mais de uma instância do mesmo argumento for especificada, a última substituirá as anteriores.  Por exemplo, **`/EHr- /EHc /EHs`** é o mesmo que **`/EHscr-`** e **`/EHscr- /EHr`** tem o mesmo efeito que **`/EHscr`** .

## <a name="remarks"></a>Comentários

### <a name="default-exception-handling-behavior"></a>Comportamento de tratamento de exceção padrão

O compilador sempre gera código que dá suporte ao tratamento de exceção estruturada assíncrona ( SEH ). Por padrão (ou seja, se nenhuma **`/EHsc`** **`/EHs`** opção, ou **`/EHa`** for especificada), o compilador oferece suporte a SEH manipuladores na cláusula C++ nativa `catch(...)` . No entanto, ele também gera código que dá suporte parcial apenas a exceções C++. O código de desenrolamento de exceção padrão não destrói objetos C++ automáticos fora dos [`try`](../../cpp/try-throw-and-catch-statements-cpp.md) blocos que saem do escopo devido a uma exceção. Vazamentos de recursos e comportamento indefinido podem ocorrer quando uma exceção de C++ é throw n.

### <a name="standard-c-exception-handling"></a>Manipulação de exceção padrão do C++

Suporte completo ao compilador para o modelo de manipulação de exceção C++ padrão que o desenrola com segurança de objetos de pilha requer **`/EHsc`** (recomendado), **`/EHs`** ou **`/EHa`** .

Se você usar **`/EHs`** ou **`/EHsc`** , suas `catch(...)` cláusulas não são catch exceções estruturadas assíncronas. Quaisquer violações de acesso e <xref:System.Exception?displayProperty=fullName> exceções gerenciadas vão despercebidas. E, os objetos no escopo quando ocorre uma exceção assíncrona não são destruídos, mesmo que o código manipule a exceção assíncrona. Esse comportamento é um argumento para deixar exceções estruturadas sem tratamento. Em vez disso, considere essas exceções fatais.

Quando você usa **`/EHs`** **`/EHsc`** o ou o, o compilador supõe que as exceções só podem ocorrer em uma **`throw`** instrução ou em uma chamada de função. Essa suposição permite que o compilador elimine o código para acompanhar o tempo de vida de muitos objetos desenrolados, o que pode reduzir significativamente o tamanho do código. Se você usar **`/EHa`** o, a imagem executável poderá ser maior e mais lenta, pois o compilador não otimiza os **`try`** blocos de forma agressiva. Ele também deixa em filtros de exceção que limpam automaticamente os objetos locais, mesmo que o compilador não veja qualquer código que possa throw uma exceção de C++.

### <a name="structured-and-standard-c-exception-handling"></a>Manipulação de exceção C++ estruturada e Standard

A **`/EHa`** opção de compilador habilita o desenrolamento de pilha segura para exceções assíncronas e exceções de C++. Ele dá suporte ao tratamento de C++ padrão e de exceções estruturadas usando a `catch(...)` cláusula c++ nativa. Para implementar SEH sem especificar **`/EHa`** , você pode usar a **`__try`** **`__except`** sintaxe, e **`__finally`** . Para obter mais informações, consulte [manipulação de exceção estruturada](../../cpp/structured-exception-handling-c-cpp.md).

> [!IMPORTANT]
> Especificar **`/EHa`** e o try ing para lidar com todas as exceções usando o `catch(...)` pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.
>
> Embora o suporte ao Windows e Visual C++ SEH , é altamente recomendável que você use a manipulação de exceção do C++ padrão ISO ( **`/EHsc`** ou **`/EHs`** ). Ele torna seu código mais portátil e flexível. Ainda pode haver ocasiões em que você precisa usar SEH no código herdado ou em determinados tipos de programas. Ele é necessário no código compilado para dar suporte ao Common Language Runtime ( [`/clr`](clr-common-language-runtime-compilation.md) ), por exemplo. Para obter mais informações, consulte [manipulação de exceção estruturada](../../cpp/structured-exception-handling-c-cpp.md).
>
> Recomendamos que você nunca vincule arquivos de objeto compilados usando **`/EHa`** para aqueles compilados usando **`/EHs`** **`/EHsc`** o ou no mesmo módulo executável. Se você precisar manipular uma exceção assíncrona usando **`/EHa`** qualquer lugar em seu módulo, use **`/EHa`** para compilar todo o código no módulo. Você pode usar a sintaxe de manipulação de exceção estruturada no mesmo módulo que o código que é compilado usando o **`/EHs`** . No entanto, você não pode misturar a SEH sintaxe com C++ **`try`** , **`throw`** e **`catch`** na mesma função.

Use **`/EHa`** se você quiser catch uma exceção que seja gerada por algo diferente de a **`throw`** . Este exemplo gera e catch es uma exceção estruturada:

```cpp
// compiler_options_EHA.cpp
// compile with: /EHa
#include <iostream>
#include <excpt.h>
using namespace std;

void fail()
{
    // generates SE and attempts to catch it using catch(...)
    try
    {
        int i = 0, j = 1;
        j /= i;   // This will throw a SE (divide by zero).
        printf("%d", j);
    }
    catch(...)
    {
        // catch block will only be executed under /EHa
        cout << "Caught an exception in catch(...)." << endl;
    }
}

int main()
{
    __try
    {
        fail();
    }

    // __except will only catch an exception here
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        // if the exception was not caught by the catch(...) inside fail()
        cout << "An exception was caught in __except." << endl;
    }
}
```

### <a name="exception-handling-under-clr"></a>Tratamento de exceção sob/CLR

A **`/clr`** opção implica **`/EHa`** (ou seja, **`/clr /EHa`** é redundante). O compilador gerará um erro se **`/EHs`** ou **`/EHsc`** for usado após **`/clr`** . As otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invoca os destruidores de classe para todos os objetos que estão no mesmo escopo que a exceção. Se uma exceção não for detectada, esses destruidores não serão executados.

Para obter informações sobre restrições de tratamento **`/clr`** de exceção em, consulte [_set_se_translator](../../c-runtime-library/reference/set-se-translator.md).

### <a name="runtime-exception-checks"></a>Verificações de exceção de tempo de execução

A **`/EHr`** opção força as verificações de término do tempo de execução em todas as funções que têm um **`noexcept`** atributo. Por padrão, as verificações de tempo de execução poderão ser otimizadas se o back-end do compilador determinar que uma função só chama funções *não throw ing* . Funções não throw ing são funções que têm um atributo que especifica que nenhuma exceção pode ser throw n. Eles incluem funções marcadas **`noexcept`** , `throw()` , `__declspec(nothrow)` e, quando **`/EHc`** é especificado, **`extern "C"`** funções. throwAs funções não-ing também incluem qualquer que o compilador determinado seja não- throw ing por inspeção. Você pode definir explicitamente o comportamento padrão usando **`/EHr-`** .

Um atributo não- throw ing não é uma garantia de que as exceções não podem ser throw n por uma função. Ao contrário do comportamento de uma **`noexcept`** função, o compilador MSVC considera uma exceção throw n por uma função declarada usando `throw()` , `__declspec(nothrow)` ou como um **`extern "C"`** comportamento indefinido. As funções que usam esses três atributos de declaração não impõem verificações de término de tempo de execução para exceções. Você pode usar a **`/EHr`** opção para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador a gerar verificações de tempo de execução para exceções sem tratamento que escapem uma **`noexcept`** função.

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
[Especificações de exceção ( throw )](../../cpp/exception-specifications-throw-cpp.md)\
[Manipulação de exceção estruturada (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)
