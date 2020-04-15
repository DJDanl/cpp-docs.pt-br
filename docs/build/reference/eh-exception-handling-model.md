---
title: /EH (modelo de tratamento de exceções)
ms.date: 08/14/2018
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
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
ms.openlocfilehash: 8546b14995317afb57e4cc23a5d6f81c2172a1a6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328290"
---
# <a name="eh-exception-handling-model"></a>/EH (modelo de tratamento de exceções)

Especifica o tipo de manipulação de exceção usada pelo compilador, quando otimizar verificações de exceção e se deve destruir objetos C++ que saem do escopo por causa de uma exceção. Se **/EH** não for especificado, o compilador habilita seu código para capturar exceções estruturadas assíncronas e exceções C++, mas não destrói objetos C++ que saem do escopo por causa de uma exceção assíncrona.

## <a name="syntax"></a>Sintaxe

> **/EH**{**s**|**a**}[c][r ][**r****-**]**c**

## <a name="arguments"></a>Argumentos

**Um**<br/>
O modelo de manipulação de exceções que captura exceções assíncronas (estruturadas) e `catch(...)` síncronas (C++) pelo uso de sintaxe C++.

**s**<br/>
O modelo de manipulação de exceções que captura apenas exceções síncronas (C++) e diz ao compilador para assumir que funções declaradas como **"C" extern** podem abrir uma exceção.

**C**<br/>
Se usado com **s** (**/EHsc**), pega apenas exceções C++ e diz ao compilador para assumir que as funções declaradas como **extern "C"** nunca lançam uma exceção C++. **/EHca** é equivalente a **/EHa**.

**r**<br/>
Diz ao compilador para sempre gerar verificações de terminação em tempo de execução para todas as funções **não exceto.** Por padrão, as verificações de tempo de execução para **não-exceção** podem ser otimizadas se o compilador determinar que a função chama apenas funções de não-arremesso.

## <a name="remarks"></a>Comentários

A opção **compilador /EHa** é usada para suportar o manuseio de exceção estruturada `catch(...)` assíncrona (SEH) com a cláusula C++ nativa. Para implementar seh sem especificar **/EHa,** você pode usar a **__try,** **__except**e **__finally** sintaxe. Embora o Windows e o Visual C++ suportem seh, recomendamos fortemente que você use o manuseio de exceção ISO-standard C++ (**/EHs** ou **/EHsc**) porque torna o código mais portátil e flexível. No entanto, no código existente ou em determinados tipos de programas — por exemplo, em código compilado para suportar o tempo de execução do idioma comum[(/clr (Common Language Runtime Compilation)](clr-common-language-runtime-compilation.md)— você ainda pode ter que usar SEH. Para obter mais informações, consulte [Tratamento estruturado de exceções (C/C++)](../../cpp/structured-exception-handling-c-cpp.md).

Especificar **/EHa** e tentar lidar com `catch(...)` todas as exceções usando pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.

Se você usar **/EHs** ou **/EHsc**, então sua `catch(...)` cláusula não captura exceções estruturadas assíncronas. As violações de acesso e as exceções <xref:System.Exception?displayProperty=fullName> gerenciadas não são capturadas, e os objetos no escopo quando uma exceção assíncrona é gerada não são destruídos ainda que a exceção assíncrona seja tratada.

Se você usar **/EHa**, a imagem pode ser maior e pode funcionar menos bem porque o compilador não otimiza um bloco **de tentativa** tão agressivamente. Ele também deixa em exceção filtros que automaticamente chamam os destruidores de todos os objetos locais, mesmo que o compilador não veja nenhum código que possa lançar uma exceção C++. Isso permite que a pilha segura se descontraa para exceções assíncronas, bem como para exceções C++. Quando você usa **/EHs**, o compilador assume que exceções só podem ocorrer em uma declaração **de lançamento** ou em uma chamada de função. Isso permite que o compilador elimine o código para acompanhar o tempo de vida útil de muitos objetos liberáveis, e isso pode reduzir significativamente o tamanho de código.

Recomendamos que você não vincule objetos compilados usando **/EHa** juntamente com objetos compilados usando **/EHs** ou **/EHsc** no mesmo módulo executável. Se você tiver que lidar com uma exceção assíncrona usando **/EHa** em qualquer lugar do seu módulo, use **/EHa** para compilar todo o código do módulo. Você pode usar sintaxe de manipulação de exceção estruturada no mesmo módulo que o código que é compilado usando **/EHs**, mas você não pode misturar a sintaxe SEH com **try**, **throw**, e **pegar** na mesma função.

Use **/EHa** se você quiser pegar uma exceção que é levantada por algo que não seja um **arremesso**. Este exemplo gera e captura uma exceção estruturada:

```cpp
// compiler_options_EHA.cpp
// compile with: /EHa
#include <iostream>
#include <excpt.h>
using namespace std;

void fail() {   // generates SE and attempts to catch it using catch(...)
   try {
      int i = 0, j = 1;
      j /= i;   // This will throw a SE (divide by zero).
      printf("%d", j);
   }
   catch(...) {   // catch block will only be executed under /EHa
      cout<<"Caught an exception in catch(...)."<<endl;
   }
}

int main() {
   __try {
      fail();
   }

   // __except will only catch an exception here
   __except(EXCEPTION_EXECUTE_HANDLER) {
      // if the exception was not caught by the catch(...) inside fail()
      cout << "An exception was caught in __except." << endl;
   }
}
```

A opção **/EHc** requer que **/EHs** ou **/EHa** seja especificado. A opção **/clr** implica **/EHa** (isto é, **/clr** **/EHa** é redundante). O compilador gera um erro se **/EHs s** ou **/EHsc** for usado após **/clr**. As otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invoca o destruidor ou os destruidores de classe do objeto ou dos objetos que estão no mesmo escopo da exceção. Quando uma exceção não é detectada, esses destruidores não são executados.

Para obter informações sobre restrições de tratamento de exceções **em /clr,** consulte [_set_se_translator](../../c-runtime-library/reference/set-se-translator.md).

A opção pode ser limpa **-** usando o símbolo . Por exemplo, **/EHsc-** é interpretado como **/EHs** **/EHc-** e é equivalente a **/EHs**.

A **opção /EHr** compilou as verificações de terminação em tempo de execução em todas as funções que tenham um atributo **noexcept.** Por padrão, as verificações de tempo de execução podem ser otimizadas se o back-end do compilador determinar que uma função só chama funções *de não-arremesso.* Funções de não-arremesso são quaisquer funções que tenham um atributo que especifica que nenhuma exceção pode ser lançada. Isso inclui funções marcadas `throw()` `__declspec(nothrow)` **como noexcept**, , e, quando **/EHc** é especificado, **extern funções "C".** As funções de não-arremesso também incluem qualquer que o compilador tenha determinado que não sejam arremessadas por inspeção. Você pode definir explicitamente o padrão usando **/EHr-**.

No entanto, o atributo não-arremesso não é uma garantia de que nenhuma exceção pode ser lançada por uma função. Ao contrário do comportamento de uma função **noexcept,** o compilador MSVC `throw()` `__declspec(nothrow)`considera uma exceção lançada por uma função declarada usando , ou **extern "C"** como comportamento indefinido. As funções que usam esses três atributos de declaração não aplicam verificações de terminação em tempo de execução para exceções. Você pode usar a opção **/EHr** para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador a gerar verificações de tempo de execução para exceções não manuseadas que escapam a uma função **não exceto.**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **propriedades de** > configuração**C/C++** > **Geração de código**.

1. Modifique a propriedade **Ativar exceções C++.**

   Ou, **defina Ativar exceções C++** para **Não**e, em seguida, na página de propriedade **Linha de Comando,** na caixa **Opções adicionais,** adicione a opção compilador.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Erros e tratamento de exceções](../../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[Tratamento estruturado de exceções (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)
