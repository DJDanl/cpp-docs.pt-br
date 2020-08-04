---
title: /RTC (verificações de erro em tempo de execução)
ms.date: 07/31/2020
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
ms.openlocfilehash: eefec0956bebe9f72324f3cbc61fccbc5e2e24d7
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520532"
---
# <a name="rtc-run-time-error-checks"></a>`/RTC`(Verificações de erro em tempo de execução)

Usado para habilitar e desabilitar o recurso de verificações de erro em tempo de execução, em conjunto com o [runtime_checks](../../preprocessor/runtime-checks.md) pragma.

## <a name="syntax"></a>Sintaxe

> **`/RTC1`**\
> **`/RTCc`**\
> **`/RTCs`**\
> **`/RTCu`**

## <a name="arguments"></a>Argumentos

**`/RTC1`**<br/>
Equivalente a **`/RTCsu`** .

**`/RTCc`**<br/>
Relata quando um valor é atribuído a um tipo de dados menor e resulta em uma perda de dados. Por exemplo, ele relata se um **`short`** valor de tipo `0x0101` é atribuído a uma variável do tipo **`char`** .

Essa opção pode relatar situações nas quais você pretende truncar. Por exemplo, quando você deseja que os primeiros 8 bits de um sejam **`int`** retornados como um **`char`** . Como **`/RTCc`** o causa um erro de tempo de execução se uma atribuição causa qualquer perda de informações, primeiro mascara as informações necessárias para evitar o erro em tempo de execução. Por exemplo:

```C
#include <crtdbg.h>

char get8bits(unsigned value, int position) {
   _ASSERT(position < 32);
   return (char)(value >> position);
   // Try the following line instead:
   // return (char)((value >> position) & 0xff);
}

int main() {
   get8bits(12341235,3);
}
```

Como **`/RTCc`** o rejeita o código que está de acordo com o padrão, não há suporte para ele na biblioteca padrão do C++. O código que usa **`/RTCc`** o e a biblioteca C++ Standard pode causar erros de [C1189](../../error-messages/compiler-errors-1/fatal-error-c1189.md)de compilador. Você pode definir `_ALLOW_RTCc_IN_STL` para silenciar o aviso e usar a **`/RTCc`** opção.

**`/RTCs`**<br/>
Habilita a verificação de erros em tempo de execução de quadro de pilha, da seguinte maneira:

- Inicialização de variáveis locais para um valor diferente de zero. Essa opção ajuda a identificar bugs que não aparecem durante a execução no modo de depuração. Há uma chance maior de que as variáveis de pilha ainda tenham um valor zero em uma compilação de depuração em comparação a uma compilação de versão. Isso ocorre devido a otimizações do compilador de variáveis de pilha em uma compilação de versão. Depois que um programa tiver usado uma área de sua pilha, ele nunca será redefinido como 0 pelo compilador. Isso significa que qualquer variável de pilha não inicializada que use a mesma área de pilha mais tarde pode retornar valores restantes do uso anterior dessa memória de pilha.

- Detecção de saturações e subexecuções de variáveis locais, como matrizes. **`/RTCs`** não detecta saturações ao acessar a memória que resulta do preenchimento do compilador dentro de uma estrutura. O preenchimento pode ocorrer usando [`align`](../../cpp/align-cpp.md) , [ `/Zp` (alinhamento de Membro struct)](zp-struct-member-alignment.md)ou [`pack`](../../preprocessor/pack.md) , ou se você ordenar elementos de estrutura de forma a exigir que o compilador adicione preenchimento.

- Verificação de ponteiro de pilha, que detecta corrupção de ponteiro de pilha. A corrupção de ponteiro de pilha pode ser causada por uma incompatibilidade de Convenção de chamada. Por exemplo, usando um ponteiro de função, você chama uma função em uma DLL que é exportada como, [`__stdcall`](../../cpp/stdcall.md) mas você declara o ponteiro para a função como [`__cdecl`](../../cpp/cdecl.md) .

**`/RTCu`**<br/>
Relata quando uma variável é usada sem ter sido inicializada. Por exemplo, uma instrução que gera aviso C4701 também pode gerar um erro em tempo de execução em **`/RTCu`** . Qualquer instrução que gere o [aviso do compilador (nível 1 e nível 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) gerará um erro em tempo de execução em **`/RTCu`** .

No entanto, considere o seguinte fragmento de código:

```cpp
int a, *b, c;
if ( 1 )
b = &a;
c = a;  // No run-time error with /RTCu
```

Se uma variável puder ter sido inicializada, ela não será relatada em tempo de execução pelo **`/RTCu`** . Por exemplo, depois que uma variável é alias por meio de um ponteiro, o compilador não rastreia a variável e relata usos não inicializados. Na verdade, você pode inicializar uma variável assumindo seu endereço. O **`&`** operador funciona como um operador de atribuição nessa situação.

## <a name="remarks"></a>Comentários

As verificações de erro de tempo de execução são uma maneira de encontrar problemas em seu código em execução; para obter mais informações, consulte [como: usar verificações nativas em tempo de execução](/visualstudio/debugger/how-to-use-native-run-time-checks).

Você pode especificar mais de uma **`/RTC`** opção na linha de comando. Os argumentos de opção podem ser combinados; por exemplo, **`/RTCcu`** é o mesmo que **`/RTCc /RTCu`** .

Se você compilar seu programa na linha de comando usando qualquer uma das **`/RTC`** Opções do compilador, quaisquer [`optimize`](../../preprocessor/optimize.md) instruções de pragma em seu código falharão silenciosamente. Isso ocorre porque as verificações de erro em tempo de execução não são válidas em uma compilação de versão (otimizada).

Usar **`/RTC`** para Builds de desenvolvimento; Não use **`/RTC`** para uma compilação de versão. **`/RTC`** Não pode ser usado com otimizações de compilador ([ `/O` Opções (otimizar código)](o-options-optimize-code.md)). Uma imagem de programa criada com **`/RTC`** é ligeiramente maior e ligeiramente mais lenta do que uma imagem criada com **`/Od`** (até 5% mais lenta do que uma **`/Od`** compilação).

A `__MSVC_RUNTIME_CHECKS` diretiva de pré-processador será definida quando você usar qualquer **`/RTC`** opção ou [`/GZ`](gz-enable-stack-frame-run-time-error-checking.md) .

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração**de  >  geração de**código** **C/C++**.  

1. Modifique uma ou ambas as propriedades a seguir: **verificações básicas de tempo de execução** ou **verificação de tipo menor**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SmallerTypeCheck%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Como usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks)
