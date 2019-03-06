---
title: /RTC (verificações de erro de tempo de execução)
ms.date: 11/04/2016
f1_keywords:
- /rtc
- VC.Project.VCCLCompilerTool.SmallerTypeCheck
- VC.Project.VCCLCompilerTool.UninitializedVariableCheck
- VC.Project.VCCLCompilerTool.StackFrameCheck
- VC.Project.VCCLCompilerTool.BasicRuntimeChecks
helpviewer_keywords:
- /RTCs compiler option [C++]
- -RTC1 compiler option [C++]
- run-time errors, error checks
- -RTCu compiler option [C++]
- /RTC1 compiler option [C++]
- /RTCc compiler option [C++]
- /RTCu compiler option [C++]
- __MSVC_RUNTIME_CHECKS macro
- -RTCs compiler option [C++]
- RTCs compiler option
- RTC1 compiler option
- run-time errors, run-time checks
- run-time checks, /RTC option
- RTCu compiler option
- RTCc compiler option
- -RTCc compiler option [C++]
ms.assetid: 9702c558-412c-4004-acd5-80761f589368
ms.openlocfilehash: 3ac70904332f5f05463b317f02a2ab8d3bfc7bb3
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57424607"
---
# <a name="rtc-run-time-error-checks"></a>/RTC (verificações de erro de tempo de execução)

Usada para habilitar e desabilitar o recurso de verificações de erro de tempo de execução, em conjunto com o [runtime_checks](../../preprocessor/runtime-checks.md) pragma.

## <a name="syntax"></a>Sintaxe

```
/RTC1
/RTCc
/RTCs
/RTCu
```

## <a name="arguments"></a>Arguments

**1**<br/>
Equivalente a **/RTC**`su`.

**c**<br/>
Informa quando um valor é atribuído a um tipo de dados menor e resulta em perda de dados. Por exemplo, se um valor do tipo `short 0x101` é atribuído a uma variável do tipo `char`.

Esta opção relata situações em que você pretende truncar, por exemplo, se você quiser que os primeiros oito bits de um `int` retornado como um `char`. Porque **/RTC** `c` causa um erro de tempo de execução se houver informações perdidas como resultado da atribuição, você pode mascarar as informações necessárias para evitar um erro de tempo de execução como resultado de **/RTC** `c`. Por exemplo:

```
#include <crtdbg.h>

char get8bits(int value, int position) {
   _ASSERT(position < 32);
   return (char)(value >> position);
   // Try the following line instead:
   // return (char)((value >> position) & 0xff);
}

int main() {
   get8bits(12341235,3);
}
```

**s**<br/>
Permite empilhar quadro tempo de execução verificação de erros, da seguinte maneira:

- Inicialização de variáveis locais para um valor diferente de zero. Isso ajuda a identificar bugs que não aparecem quando em execução no modo de depuração. Há uma chance maior de que variáveis de pilha ainda será zero em uma compilação de depuração em comparação comparada um build de versão devido a otimizações do compilador de variáveis de pilha em um build de versão. Depois que um programa tenha usado uma área de sua pilha, ele nunca é redefinido como 0 pelo compilador. Portanto, as variáveis de pilha subsequentes, não inicializado que usam a mesma área de pilha podem retornar valores restantes do uso anterior dessa memória de pilha.

- Detecção de saturações e falhas de variáveis locais, como matrizes. **/RTC** `s` não irá detectar estouros ao acessar a memória que resulta do preenchimento de compilador dentro de uma estrutura. Preenchimento pode ocorrer por meio [alinhar](../../cpp/align-cpp.md), [/Zp (alinhamento de membro de Struct)](../../build/reference/zp-struct-member-alignment.md), ou [pack](../../preprocessor/pack.md), ou se você ordenar os elementos de estrutura de forma exigir o compilador a adicionar preenchimento.

- Verificação de ponteiro de pilha, que detecta dano do ponteiro de pilha. Corrompimento de ponteiro de pilha pode ser causado por uma incompatibilidade de convenção de chamada. Por exemplo, usando um ponteiro de função, você chama uma função em uma DLL que é exportada como [stdcall](../../cpp/stdcall.md) , mas você declara o ponteiro para a função como [cdecl](../../cpp/cdecl.md).

**u**<br/>
Informa quando uma variável for usada sem ter sido inicializada. Por exemplo, uma instrução que gera `C4701` também pode gerar um erro de tempo de execução sob **/RTC**`u`. Qualquer instrução que gera [aviso do compilador (nível 1 e nível 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) gerará um erro de tempo de execução sob **/RTC**`u`.

No entanto, considere o fragmento de código a seguir:

```cpp
int a, *b, c;
if ( 1 )
b = &a;
c = a;  // No run-time error with /RTCu
```

Se uma variável pode ter sido inicializada, ele não será relatado em tempo de execução **/RTC**`u`. Por exemplo, depois que uma variável é um alias por meio de um ponteiro, o compilador não rastreará a variável e de relatório usa não inicializada. Na verdade, você pode inicializar uma variável por meio de seu endereço. A & funciona de operador como um operador de atribuição nessa situação.

## <a name="remarks"></a>Comentários

Verificações de erro em tempo de execução são uma maneira de localizar problemas em seu código em execução; Para obter mais informações, consulte [como: Usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks).

Se você compilar seu programa na linha de comando usando qualquer um dos **/RTC** opções do compilador, qualquer pragma [otimizar](../../preprocessor/optimize.md) instruções em seu código falhará silenciosamente. Isso ocorre porque as verificações de erro em tempo de execução não são válidas em um build de versão (otimizado).

Você deve usar **/RTC** para compilações de desenvolvimento; **/RTC** não deve ser usado para um build de varejo. **/RTC** não pode ser usado com as otimizações do compilador ([/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)). Imagem de um programa compilado com **/RTC** será um pouco maior e um pouco mais lento do que uma imagem criada com **/Od** (até 5% mais lento do que uma **/Od** compilar).

A diretiva de pré-processador msvc_runtime_checks será definida quando você usar qualquer **/RTC** opção ou [/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **geração de código** página de propriedades.

1. Modifique uma ou ambas as propriedades a seguir: **Verificações de tempo de execução básico** ou **verificação de tipo menor**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SmallerTypeCheck%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Como: Usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks)
