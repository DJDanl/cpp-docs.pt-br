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
ms.openlocfilehash: e8707ac716a010ea1d3dc0fa51740e76a5822462
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51329294"
---
# <a name="eh-exception-handling-model"></a>/EH (modelo de tratamento de exceções)

Especifica o tipo de manipulação de exceção usado pelo compilador, ao otimizar exceção distante verificações e se deseja destruir objetos de C++ que saem do escopo devido a uma exceção. Se **/EH** não for especificado, o compilador permite que seu código capturar exceções estruturadas assíncronas e exceções do C++, mas não destrói os objetos de C++ que saem do escopo devido a uma exceção assíncrona.

## <a name="syntax"></a>Sintaxe

> **/EH**{**s**|**um**} [**c**] [**r**] [**-**]

## <a name="arguments"></a>Arguments

**a**<br/>
O modelo de tratamento de exceções que captura assíncronas (estruturadas) e exceções síncronas (C++), pelo uso do C++ `catch(...)` sintaxe.

**s**<br/>
O modelo de tratamento de exceções que captura somente exceções síncronas (C++) e informa ao compilador para assumir que as funções declaradas como **extern "C"** pode lançar uma exceção.

**c**<br/>
Se usado com **s** (**/EHsc**), captura somente exceções C++ e informa ao compilador para assumir que as funções declaradas como **extern "C"** nunca geram uma exceção de C++. **/ EHca** é equivalente a **/EHa**.

**r**<br/>
Informa ao compilador sempre gera verificações de término do tempo de execução para todos os **noexcept** funções. Por padrão, tempo de execução procura **noexcept** podem ser removidas se o compilador determina a função chama funções de não lançamento somente.

## <a name="remarks"></a>Comentários

O **/EHa** opção de compilador é usada para dar suporte a tratamento de exceções estruturadas assíncronas (SEH) com o C++ nativo `catch(...)` cláusula. Para implementar SEH sem especificar **/EHa**, você pode usar o **Try**, **EXCEPT**, e **Finally** sintaxe. Embora o Windows e Visual C++ ofereçam suporte para SEH, é altamente recomendável que você use o tratamento de exceções do C++ padrão ISO (**/EHs** ou **/EHsc**) pois ele torna o código mais portável e flexível. No entanto, no código existente ou para tipos específicos de programas — por exemplo, no código compilado para dar suporte a common language runtime ([/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md)) — você ainda pode precisar usar o SEH. Para obter mais informações, consulte [tratamento de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md).

Especificando **/EHa** e tentar manipular todas as exceções usando `catch(...)` pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.

Se você usar **/EHs** ou **/EHsc**, em seguida, seu `catch(...)` cláusula não capturará exceções estruturadas assíncronas. As violações de acesso e as exceções <xref:System.Exception?displayProperty=fullName> gerenciadas não são capturadas, e os objetos no escopo quando uma exceção assíncrona é gerada não são destruídos ainda que a exceção assíncrona seja tratada.

Se você usar **/EHa**, a imagem pode ser maior e talvez um desempenho inferior porque o compilador não otimiza um **tente** bloquear agressivamente. Ele também deixa filtros de exceção que chamam automaticamente os destruidores de todos os objetos locais, mesmo que o compilador não vê qualquer código que pode lançar uma exceção de C++. Isso permite que a liberação para exceções assíncronas, bem como para exceções C++ segura da pilha. Quando você usa **/EHs**, o compilador pressupõe que as exceções só podem ocorrer em um **throw** instrução ou em uma chamada de função. Isso permite que o compilador elimine o código para acompanhar o tempo de vida útil de muitos objetos liberáveis, e isso pode reduzir significativamente o tamanho de código.

É recomendável que você não vincular objetos compilados usando **/EHa** junto com objetos compilados usando **/EHs** ou **/EHsc** no mesmo módulo executável. Se você precisa lidar com uma exceção assíncrona, usando **/EHa** em qualquer lugar em seu módulo, use **/EHa** para compilar todo o código no módulo. Você pode usar a sintaxe no mesmo módulo do código que é compilado por meio de manipulação de exceção estruturada **/EHs**, mas você não pode misturar a sintaxe SEH com **tente**, **lançar**e **catch** na mesma função.

Use **/EHa** se você deseja capturar uma exceção que é gerada por algo diferente de uma **throw**. Este exemplo gera e captura uma exceção estruturada:

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

O **/EHc** opção requer que **/EHs** ou **/EHa** for especificado. O **/clr** opção implica **/EHa** (ou seja, **/clr** **/EHa** é redundante). O compilador gera um erro se **/EHs** ou **/EHsc** é usada após **/clr**. As otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invoca o destruidor ou os destruidores de classe do objeto ou dos objetos que estão no mesmo escopo da exceção. Quando uma exceção não é detectada, esses destruidores não são executados.

Para obter informações sobre restrições em de tratamento de exceções **/clr**, consulte [set_se_translator](../../c-runtime-library/reference/set-se-translator.md).

A opção pode ser limpa usando o símbolo **-**. Por exemplo, **/EHsc-** será interpretado como **/EHs** **/EHc-** e é equivalente a **/EHs**.

O **/EHr** opção de compilador força verificações de término do tempo de execução em todas as funções que têm um **noexcept** atributo. Por padrão, verificações de tempo de execução podem ser removidas se o back-end do compilador determina que uma função apenas chama *sem lançamento* funções. Funções geradoras de não são todas as funções que têm um atributo que especifica que nenhuma exceção pode ser lançada. Isso inclui funções assinaladas **noexcept**, `throw()`, `__declspec(nothrow)`e, quando **/EHc** for especificado, **extern "C"** funções. Funções geradoras de não também pode incluir qualquer um que o compilador determinou que são não lançamento por inspeção. Você pode definir explicitamente o padrão usando **/EHr-**.

No entanto, o atributo de não lançamento não é uma garantia de que nenhuma exceção pode ser gerada por uma função. Ao contrário do comportamento de um **noexcept** função, o compilador do Visual C++ considera uma exceção gerada por uma função declarada usando `throw()`, `__declspec(nothrow)`, ou **extern "C"** como indefinido comportamento. Funções que usam esses atributos de três declaração não impõem verificações de término para exceções de tempo de execução. Você pode usar o **/EHr** opção para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador gere verificações de tempo de execução para exceções sem tratamento que escapam de um **noexcept** função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione **propriedades de configuração** > **C/C++** > **geração de código**.

1. Modificar a **habilita exceções C++** propriedade.

   Ou então, defina **habilita exceções C++** para **não**e, em seguida, no **linha de comando** página de propriedades no **opções adicionais** caixa, adicione o opção de compilador.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Erros e tratamento de exceções](../../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)
