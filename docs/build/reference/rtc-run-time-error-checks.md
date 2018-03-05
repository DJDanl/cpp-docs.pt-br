---
title: "-RTC (verificações de erro de tempo de execução) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /rtc
- VC.Project.VCCLCompilerTool.SmallerTypeCheck
- VC.Project.VCCLCompilerTool.UninitializedVariableCheck
- VC.Project.VCCLCompilerTool.StackFrameCheck
- VC.Project.VCCLCompilerTool.BasicRuntimeChecks
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8699a96dcd7c04bc1b2707e964afb4b68068147e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `1`  
 Equivalente a **/RTC**`su`.  
  
 `c`  
 Relata quando um valor é atribuído a um tipo de dados menor e resulta em perda de dados. Por exemplo, se um valor do tipo `short 0x101` é atribuído a uma variável do tipo `char`.  
  
 Essa opção informa situações em que você pretende truncate, por exemplo, se você quiser que os primeiros oito bits de um `int` retornado como um `char`. Porque **/RTC** `c` causa um erro de tempo de execução se qualquer informação é perdida como resultado da atribuição, você pode mascarar desativar as informações necessárias para evitar um erro de tempo de execução como resultado de **/RTC** `c`. Por exemplo:  
  
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
  
 `s`  
 Habilita quadro erro de tempo de execução de verificação de pilha, da seguinte maneira:  
  
-   Inicialização de variáveis locais para um valor diferente de zero. Isso ajuda a identificar erros que não aparecem quando em execução no modo de depuração. Há uma possibilidade maior de que variáveis de pilha ainda será zero em uma compilação de depuração em comparação comparada uma versão de compilação devido a otimizações do compilador de variáveis de pilha em uma compilação de versão. Depois que um programa usado uma área de pilha, ele nunca é redefinido como 0 pelo compilador. Portanto, variáveis de pilha não inicializada subsequentes que usem a mesma área de pilha podem retornar valores restantes do uso da memória pilha anterior.  
  
-   Detecção de estouros e falhas de variáveis locais, como matrizes. **/RTC** `s` não irá detectar saturações ao acessar a memória que os resultados de preenchimento de compilador dentro de uma estrutura. O preenchimento pode ocorrer por meio [alinhar](../../cpp/align-cpp.md), [/Zp (alinhamento de membro de Struct)](../../build/reference/zp-struct-member-alignment.md), ou [pacote](../../preprocessor/pack.md), ou se você classificar os elementos de estrutura em forma a exigir o compilador a adicionar preenchimento.  
  
-   Verificação de ponteiro de pilha, que detecta corrupção do ponteiro de pilha. Corrompimento de ponteiro de pilha pode ser causado por uma incompatibilidade de convenção de chamada. Por exemplo, usando um ponteiro de função, você chama uma função em uma DLL que é exportada como [stdcall](../../cpp/stdcall.md) , mas o ponteiro para a função que você declara [cdecl](../../cpp/cdecl.md).  
  
 `u`  
 Relata quando uma variável for usada sem ter sido inicializada. Por exemplo, uma instrução que gera `C4701` também pode gerar um erro de tempo de execução em **/RTC**`u`. Qualquer instrução que gera [C4700 de aviso do compilador (nível 1 e nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) gerará um erro de tempo de execução em **/RTC**`u`.  
  
 No entanto, considere o fragmento de código a seguir:  
  
```cpp  
int a, *b, c;  
if ( 1 )  
b = &a;  
c = a;  // No run-time error with /RTCu  
```  
  
 Se uma variável pode ter sido inicializada, ele não será relatado em tempo de execução por **/RTC**`u`. Por exemplo, depois de uma variável é um alias através de um ponteiro, o compilador não rastreará a variável e de relatório usa não inicializada. Na verdade, você pode inicializar uma variável por obter seu endereço. A & operador funciona como um operador de atribuição nessa situação.  
  
## <a name="remarks"></a>Comentários  
 Verificações de erro de tempo de execução são uma maneira para localizar problemas em seu código em execução; Para obter mais informações, consulte [como: usar verificações de tempo de execução nativo](/visualstudio/debugger/how-to-use-native-run-time-checks).  
  
 Se você compilar seu programa na linha de comando usando qualquer um do **/RTC** opções do compilador, qualquer pragma [otimizar](../../preprocessor/optimize.md) instruções em seu código falhará de modo silencioso. Isso ocorre porque as verificações de erro de tempo de execução não são válidas em uma compilação de versão (otimizado).  
  
 Você deve usar **/RTC** para compilações de desenvolvimento; **/RTC** não deve ser usado para uma versão comercial. **/RTC** não pode ser usado com otimizações do compilador ([/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)). Uma imagem de programa compilada com **/RTC** será um pouco maior e um pouco mais lenta do que uma imagem criada com **/Od** (até 5 por cento mais lento do que um **/Od** criar).  
  
 A diretiva de pré-processador msvc_runtime_checks será definida quando você usar qualquer **/RTC** opção ou [/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar uma ou ambas das seguintes propriedades: **verificações de tempo de execução básico** ou **verificação de tipo menor**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SmallerTypeCheck%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Como usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks)