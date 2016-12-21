---
title: "-/RTC (verifica&#231;&#245;es de erro de tempo de execu&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/rtc"
  - "VC.Project.VCCLCompilerTool.SmallerTypeCheck"
  - "VC.Project.VCCLCompilerTool.UninitializedVariableCheck"
  - "VC.Project.VCCLCompilerTool.StackFrameCheck"
  - "VC.Project.VCCLCompilerTool.BasicRuntimeChecks"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /RTCs (C++)"
  - "Opção de compilador -RTC1 [C++]"
  - "erros de tempo de execução, verificações de erro"
  - "Opção de compilador -RTCu [C++]"
  - "Opção de compilador /RTC1 (C++)"
  - "Opção de compilador /RTCc (C++)"
  - "Opção de compilador /RTCu (C++)"
  - "Macro __MSVC_RUNTIME_CHECKS"
  - "Opção de compilador -RTCs [C++]"
  - "Opção de compilador  (RTCs)"
  - "Opção de compilador  (RTC1)"
  - "erros de tempo de execução, verificações de tempo de execução"
  - "verificações de tempo de execução, opção /RTC"
  - "Opção de compilador RTCu"
  - "Opção de compilador  (RTCc)"
  - "Opção de compilador -RTCc [C++]"
ms.assetid: 9702c558-412c-4004-acd5-80761f589368
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /RTC (verifica&#231;&#245;es de erro de tempo de execu&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usada para habilitar e desabilitar o recurso de verificações de erro de tempo de execução, em conjunto com o [runtime\_checks](../Topic/runtime_checks.md) pragma.  
  
## Sintaxe  
  
```  
/RTC1  
/RTCc  
/RTCs  
/RTCu  
```  
  
## Arguments  
 `1`  
 Equivalente a **\/RTC**`su`.  
  
 `c`  
 Informa quando um valor é atribuído a um tipo de dados menor e resulta em perda de dados. Por exemplo, se um valor do tipo `short 0x101` é atribuído a uma variável do tipo `char`.  
  
 Essa opção informa situações em que você pretende truncate, por exemplo, se você quiser que os primeiros oito bits de um `int` retornado como um `char`. Porque **\/RTC**`c` causa um erro de tempo de execução se todas as informações são perdidas como resultado da atribuição, você pode mascarar desativar as informações necessárias para evitar um erro de tempo de execução como resultado de **\/RTC**`c`. Por exemplo:  
  
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
 Habilita o quadro erro de tempo de execução de verificação de pilha, da seguinte maneira:  
  
-   Inicialização de variáveis locais para um valor diferente de zero. Isso ajuda a identificar bugs que não são exibidas durante a execução no modo de depuração. Há uma chance maior que variáveis de pilha ainda será zero em uma compilação de depuração em comparação comparada uma compilação de versão devido a otimizações do compilador de variáveis de pilha em uma compilação de versão. Depois que um programa tenha usado uma área de sua pilha, ele nunca é redefinido como 0 pelo compilador. Portanto, variáveis de pilha não inicializada subsequentes que usem a mesma área de pilha podem retornar valores resultados do uso anterior dessa memória de pilha.  
  
-   Detecção de estouros e falhas de variáveis locais, como matrizes.**\/RTC**`s` não irá detectar saturações ao acessar a memória que resulta do preenchimento de compilador dentro de uma estrutura. Preenchimento pode ocorrer ao usar [align](../../cpp/align-cpp.md), [\/Zp \(alinhamento de membro do Struct\)](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md), ou [pack](../../preprocessor/pack.md), ou se você solicitar elementos de estrutura de forma exigir o compilador a adicionar preenchimento.  
  
-   Verificação de ponteiro de pilha, que detecta corrupção do ponteiro de pilha. Corrompimento de ponteiro de pilha pode ser causado por uma incompatibilidade de convenção de chamada. Por exemplo, usando um ponteiro de função, você chamar uma função em uma DLL que é exportada como [\_\_stdcall](../../cpp/stdcall.md) mas declara o ponteiro para a função como [\_\_cdecl](../Topic/__cdecl.md).  
  
 `u`  
 Informa quando uma variável for usada sem ter sido inicializado. Por exemplo, uma instrução que gera `C4701` também pode gerar um erro de tempo de execução em **\/RTC**`u`. Qualquer instrução que gera [Aviso C4700 \(compilador\) \(nível 1 e nível 4\)](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) irá gerar um erro de tempo de execução em **\/RTC**`u`.  
  
 No entanto, considere o fragmento de código a seguir:  
  
```  
int a, *b, c;  
if ( 1 )  
b = &a;  
c = a;  // No run-time error with /RTCu  
```  
  
 Se uma variável pode ter sido inicializada, ele não será relatado em tempo de execução por **\/RTC**`u`. Por exemplo, depois que uma variável é um alias através de um ponteiro, o compilador não rastreará a variável e relatório usa não inicializada. Na verdade, você pode inicializar uma variável colocando seu endereço. A & operador funciona como um operador de atribuição nessa situação.  
  
## Comentários  
 Verificações de erro em tempo de execução são uma maneira para localizar problemas em seu código em execução; Para obter mais informações, consulte [Como usar verificações de tempo de execução nativas](../Topic/How%20to:%20Use%20Native%20Run-Time%20Checks.md).  
  
 Se você compilar seu programa na linha de comando usando qualquer um do **\/RTC** opções do compilador, qualquer pragma [optimize](../../preprocessor/optimize.md) instruções em seu código falhará silenciosamente. Isso ocorre porque as verificações de erro em tempo de execução não são válidas em uma compilação de versão \(otimizado\).  
  
 Você deve usar **\/RTC** para compilações de desenvolvimento; **\/RTC** não deve ser usado para uma versão comercial.**\/RTC** não pode ser usado com otimizações do compilador \([\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)\). Imagem de um programa compilado com **\/RTC** será um pouco maior e um pouco mais lenta do que uma imagem criada com **\/Od** \(até 5% mais lento do que um **\/Od** de compilação\).  
  
 A política de pré\-processador msvc\_runtime\_checks será definida quando você usar qualquer **\/RTC** opção ou [\/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique o **C\/C\+\+** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar uma ou ambas as seguintes propriedades: **verificações básicas do tempo de execução** ou **verificação de tipo menor**.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SmallerTypeCheck%2A> Propriedades.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Como usar verificações de tempo de execução nativas](../Topic/How%20to:%20Use%20Native%20Run-Time%20Checks.md)