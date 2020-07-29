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
ms.openlocfilehash: 49f0e4bace5f3dd199b58854e838204bd2cd5f3b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222011"
---
# <a name="rtc-run-time-error-checks"></a>/RTC (verificações de erro de tempo de execução)

Usado para habilitar e desabilitar o recurso de verificações de erro em tempo de execução, em conjunto com o [runtime_checks](../../preprocessor/runtime-checks.md) pragma.

## <a name="syntax"></a>Sintaxe

```
/RTC1
/RTCc
/RTCs
/RTCu
```

## <a name="arguments"></a>Argumentos

**1**<br/>
Equivalente a **/RTC** `su` .

**&**<br/>
Relata quando um valor é atribuído a um tipo de dados menor e resulta em uma perda de dados. Por exemplo, se um valor do tipo `short 0x101` for atribuído a uma variável do tipo **`char`** .

Essa opção relata as situações em que você pretende truncar, por exemplo, se desejar os primeiros oito bits de um **`int`** retornado como um **`char`** . Como **/RTC** `c` causa um erro de tempo de execução se alguma informação for perdida como resultado da atribuição, você poderá mascarar as informações necessárias para evitar um erro em tempo de execução como resultado de **/RTC** `c` . Por exemplo:

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

**&**<br/>
Habilita a verificação de erros em tempo de execução de quadro de pilha, da seguinte maneira:

- Inicialização de variáveis locais para um valor diferente de zero. Isso ajuda a identificar bugs que não aparecem durante a execução no modo de depuração. Há uma chance maior de que as variáveis de pilha ainda serão zero em uma compilação de depuração em comparação a uma compilação de versão devido a otimizações de compilador de variáveis de pilha em uma compilação de versão. Depois que um programa tiver usado uma área de sua pilha, ele nunca será redefinido como 0 pelo compilador. Portanto, as variáveis de pilha subsequentes não inicializadas que acontecem para usar a mesma área de pilha podem retornar valores restantes do uso anterior dessa memória de pilha.

- Detecção de saturações e subexecuções de variáveis locais, como matrizes. **/RTC** `s` não detectará saturações ao acessar a memória que resulta do preenchimento do compilador dentro de uma estrutura. O preenchimento pode ocorrer com o uso de [align](../../cpp/align-cpp.md), [/ZP (alinhamento de Membro struct)](zp-struct-member-alignment.md)ou [Pack](../../preprocessor/pack.md), ou se você ordenar elementos de estrutura de forma a exigir que o compilador adicione preenchimento.

- Verificação de ponteiro de pilha, que detecta corrupção de ponteiro de pilha. A corrupção de ponteiro de pilha pode ser causada por uma incompatibilidade de Convenção de chamada. Por exemplo, usando um ponteiro de função, você chama uma função em uma DLL que é exportada como [__stdcall](../../cpp/stdcall.md) , mas você declara o ponteiro para a função como [__cdecl](../../cpp/cdecl.md).

**u**<br/>
Relata quando uma variável é usada sem ter sido inicializada. Por exemplo, uma instrução que gera `C4701` também pode gerar um erro em tempo de execução em **/RTC** `u` . Qualquer instrução que gera o [aviso do compilador (nível 1 e nível 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) gerará um erro em tempo de execução em **/RTC** `u` .

No entanto, considere o seguinte fragmento de código:

```cpp
int a, *b, c;
if ( 1 )
b = &a;
c = a;  // No run-time error with /RTCu
```

Se uma variável puder ter sido inicializada, ela não será relatada em tempo de execução por **/RTC** `u` . Por exemplo, depois que uma variável é alias por meio de um ponteiro, o compilador não rastreará a variável e relatará usos não inicializados. Na verdade, você pode inicializar uma variável assumindo seu endereço. O operador & funciona como um operador de atribuição nessa situação.

## <a name="remarks"></a>Comentários

As verificações de erro de tempo de execução são uma maneira de encontrar problemas em seu código em execução; para obter mais informações, consulte [como: usar verificações nativas em tempo de execução](/visualstudio/debugger/how-to-use-native-run-time-checks).

Se você compilar seu programa na linha de comando usando qualquer uma das opções do compilador **/RTC** , qualquer instrução pragma [Optimize](../../preprocessor/optimize.md) em seu código falhará silenciosamente. Isso ocorre porque as verificações de erro em tempo de execução não são válidas em uma compilação de versão (otimizada).

Você deve usar **/RTC** para compilações de desenvolvimento; **/RTC** não deve ser usado para uma compilação de varejo. **/RTC** não pode ser usado com otimizações de compilador ([/O opções (otimizar código)](o-options-optimize-code.md)). Uma imagem de programa criada com **/RTC** será ligeiramente maior e ligeiramente mais lenta do que uma imagem criada com **/OD** (até 5% mais lenta do que uma compilação **/OD** ).

A diretiva de pré-processador de __MSVC_RUNTIME_CHECKS será definida quando você usar qualquer opção **/RTC** ou [/gz](gz-enable-stack-frame-run-time-error-checking.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++** .

1. Clique na página de propriedades **geração de código** .

1. Modifique uma ou ambas as propriedades a seguir: **verificações básicas de tempo de execução** ou **verificação de tipo menor**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SmallerTypeCheck%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Como: usar verificações nativas em tempo de execução](/visualstudio/debugger/how-to-use-native-run-time-checks)
