---
title: /EH (modelo de tratamento de exceções)
description: Guia de referência para as opções de compilador Microsoft C++ /EH (Modelo de Tratamento de Exceção) no Visual Studio.
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
- SEH
- try
- catch
- throw
- extern
- finally
- noexcept
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
ms.openlocfilehash: 68d6af657e7c20c0f5e84674dd91803beb35fba0
ms.sourcegitcommit: 0e4feb35b47c507947262d00349d4a893863a6d3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/15/2020
ms.locfileid: "81396284"
---
# <a name="eh-exception-handling-model"></a>/EH (modelo de tratamento de exceções)

Especifica o suporte do modelo de tratamento de exceção gerado pelo compilador. Os argumentos especificam se devem aplicar `catch(...)` sintaxe às exceções C++ estruturadas e padrão, se o throw **noexcept** ** extern código "C"** é assumido em exceções e se otimizam certas verificações.

## <a name="syntax"></a>Sintaxe

> **`/EHa`**[**`-`**]\
> **`/EHs`**[**`-`**]\
> **`/EHc`**[**`-`**]\
> **`/EHr`**[**`-`**]

## <a name="arguments"></a>Argumentos

**`a`**\
Permite o desenrolar padrão da pilha C++. Captura exceções estruturadas (assíncronas) e C++ padrão (síncronas) quando você usa `catch(...)` sintaxe. **`/EHa`** substitui ambos **`/EHs`** **`/EHc`** e argumentos.

**`s`**\
Permite o desenrolar padrão da pilha C++. Captura apenas exceções C++ `catch(...)` padrão quando você usa sintaxe. A **`/EHc`** menos que também seja especificado, o compilador assume que throw as funções declaradas como ** extern "C"** podem uma exceção C++.

**`c`**\
Quando usado **`/EHs`** com , o compilador assume que as funções declaradas como ** extern "C"** nunca throw uma exceção C++. Não tem efeito quando **`/EHa`** usado com **`/EHca`** (isto é, é equivalente a **`/EHa`**). **`/EHc`** é ignorado **`/EHs`** se **`/EHa`** ou não for especificado.

**`r`**\
Diz ao compilador para sempre gerar verificações de terminação em tempo de execução para todas as **noexcept** funções. Por padrão, as **noexcept** verificações de tempo de execução podem ser otimizadas se o compilador determinar que a função chama apenas funções de não-arremesso. Esta opção oferece conformidade C++ estrita ao custo de algum código extra. **`/EHr`** é ignorado **`/EHs`** se **`/EHa`** ou não for especificado.

**`-`**\
Limpa o argumento da opção anterior. Por exemplo, **`/EHsc-`** é **`/EHs /EHc-`** interpretado como **`/EHs`**, e é equivalente a .

**`/EH`** argumentos podem ser especificados separadamente ou combinados, em qualquer ordem. Se mais de uma instância do mesmo argumento for especificada, a última substitui as anteriores.  Por **`/EHr- /EHc /EHs`** exemplo, é **`/EHscr-`** o **`/EHscr- /EHr`** mesmo que , **`/EHscr`** e tem o mesmo efeito que .

## <a name="remarks"></a>Comentários

### <a name="default-exception-handling-behavior"></a>Comportamento padrão de manipulação de exceções

O compilador sempre gera código que suporta o manuseio deSEHexceções estruturadas assíncronas ( ). Por padrão (isto **`/EHsc`** é, **`/EHs`** se não , ou **`/EHa`** opção for SEH especificada), o compilador suporta manipuladores na cláusula C++ `catch(...)` nativa. No entanto, ele também gera código que suporta apenas parcialmente exceções C++. O código de desbobinamento de exceção padrão [try](../../cpp/try-throw-and-catch-statements-cpp.md) não destrói objetos C++ automáticos fora de blocos que ficam fora do escopo por causa de uma exceção. Vazamentos de recursos e comportamento indefinido podem resultar quando uma exceção C++ é lançada.

### <a name="standard-c-exception-handling"></a>Manuseio padrão de exceção C++

Suporte completo ao compilador para o modelo de manuseio de exceção **`/EHsc`** Standard C++ que desenrola com segurança objetos de pilha requer (recomendado), **`/EHs`** ou **`/EHa`**.

Se você **`/EHs`** **`/EHsc`** usar ou `catch(...)` , então catch suas cláusulas não assíncronas exceções estruturadas. Quaisquer violações de <xref:System.Exception?displayProperty=fullName> acesso e exceções gerenciadas não são capturadas. E, objetos no escopo quando ocorre uma exceção assíncrona não são destruídos, mesmo que o código manuseie a exceção assíncrona. Esse comportamento é um argumento para deixar exceções estruturadas não tratadas. Em vez disso, considere essas exceções fatais.

Quando você **`/EHs`** **`/EHsc`** usa ou , o compilador assume que **throw** exceções só podem ocorrer em uma declaração ou em uma chamada de função. Essa suposição permite que o compilador elimine o código para rastrear a vida útil de muitos objetos incontroláveis, o que pode reduzir significativamente o tamanho do código. Se você **`/EHa`** usar, sua imagem executável pode ser maior e mais **try** lenta, porque o compilador não otimiza blocos tão agressivamente. Ele também deixa em exceção filtros que limpam automaticamente objetos locais, mesmo throw que o compilador não veja nenhum código que possa uma exceção C++.

### <a name="structured-and-standard-c-exception-handling"></a>Tratamento de exceção C++ estruturado e padrão

A **`/EHa`** opção compilador permite o desenrolar da pilha segura para exceções assíncronas e exceções C++.. Ele suporta o manuseio de exceções c++ padrão e estruturadas `catch(...)` usando a cláusula C++ nativa. Para SEH implementar sem **`/EHa`** especificar, você pode usar a sintaxe **__try,** **__except**e **__finally.** Para obter mais informações, consulte [O tratamento de exceção estruturado](../../cpp/structured-exception-handling-c-cpp.md).

> [!IMPORTANT]
> Especificar **`/EHa`** e tentar lidar com `catch(...)` todas as exceções usando pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.
>
> Mesmo que o Windows e SEHo Visual C++ tenham suporte, recomendamos fortemente**`/EHsc`** **`/EHs`** que você use o manuseio de exceção C++ padrão ISO (ou ). Torna seu código mais portátil e flexível. Ainda pode haver momentos SEH que você tem que usar em código legado ou para determinados tipos de programas. É exigido em código compilado para suportar o tempo de execução da linguagem comum ([/clr),](clr-common-language-runtime-compilation.md)por exemplo. Para obter mais informações, consulte [O tratamento de exceção estruturado](../../cpp/structured-exception-handling-c-cpp.md).
>
> Recomendamos que você nunca vincule **`/EHa`** arquivos de objetos compilados usando aqueles compilados usando **`/EHs`** ou **`/EHsc`** no mesmo módulo executável. Se você tiver que lidar com uma **`/EHa`** exceção assíncrona usando qualquer lugar do seu módulo, use **`/EHa`** para compilar todo o código do módulo. Você pode usar sintaxe de manipulação de exceção estruturada **`/EHs`** no mesmo módulo que o código que é compilado usando . No entanto, você SEH não pode misturar a **try** **throw** sintaxe com C++ , e **catch** na mesma função.

Use **`/EHa`** se quiser catch uma exceção que seja levantada **throw** por algo diferente de um . Este exemplo gera e captura uma exceção estruturada:

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

### <a name="exception-handling-under-clr"></a>Tratamento de exceção em /clr

A **`/clr`** opção **`/EHa`** implica (isto é, **`/clr /EHa`** é redundante). O compilador gera um **`/EHs`** **`/EHsc`** erro se **`/clr`** ou é usado depois . Otimizações não afetam esse comportamento. Quando uma exceção é capturada, o compilador invoca os destruidores de classe para quaisquer objetos que estejam no mesmo escopo que a exceção. Se uma exceção não for capturada, os destruidores não serão executados.

Para obter informações sobre restrições de tratamento de exceções em **`/clr`**_set_se_translator . [_set_se_translator](../../c-runtime-library/reference/set-se-translator.md)

### <a name="runtime-exception-checks"></a>Verificações de exceção de tempo de execução

A **`/EHr`** opção força a interrupção em tempo **noexcept** de execução em todas as funções que tenham um atributo. Por padrão, as verificações de tempo de execução podem ser otimizadas se o back-end do compilador determinar que uma função só chama funções *de não-lançamento.* Funções de não-arremesso são quaisquer funções que tenham um atributo que especifica que nenhuma exceção pode ser lançada. Incluem funções **noexcept** marcadas `throw()`e, `__declspec(nothrow)` **`/EHc`** quando especificadas, ** extern ** funções "C". As funções de não-arremesso também incluem qualquer que o compilador tenha determinado que não sejam arremessadas por inspeção. Você pode definir explicitamente o **`/EHr-`** comportamento padrão usando .

Um atributo que não joga não é uma garantia de que exceções não podem ser jogadas por uma função. Ao contrário do **noexcept** comportamento de uma função, o compilador MSVC `throw()`considera `__declspec(nothrow)`uma exceção lançada por uma função declarada usando , ou ** extern "C"** como comportamento indefinido. As funções que usam esses três atributos de declaração não aplicam verificações de terminação em tempo de execução para exceções. Você pode **`/EHr`** usar a opção para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador **noexcept** a gerar verificações de tempo de execução para exceções não manuseadas que escapam a uma função.

## <a name="set-the-option-in-visual-studio-or-programmatically"></a>Defina a opção no Visual Studio ou programática

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **propriedades de** > configuração**C/C++** > **Geração de código**.

1. Modifique a propriedade **Ativar exceções C++.**

   Ou, **defina Ativar exceções C++** para **Não**e, em seguida, na página de propriedade **Linha de Comando,** na caixa **Opções adicionais,** adicione a opção compilador.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)\
[Erros e tratamento de exceções](../../cpp/errors-and-exception-handling-modern-cpp.md)\
[Especificaçõesthrowde exceção ( )](../../cpp/exception-specifications-throw-cpp.md)\
[Tratamento estruturado de exceções (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)
