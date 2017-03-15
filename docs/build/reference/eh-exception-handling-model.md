---
title: "-EH (modelo de tratamento de exce&#231;&#245;es) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.ExceptionHandling"
  - "/eh"
  - "VC.Project.VCCLCompilerTool.ExceptionHandling"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "manipulação de exceção, o modelo de compilador"
  - "compilador cl.exe, tratamento de exceção"
  - "Opção de compilador EH [C++]"
  - "Opção de compilador -EH [C++]"
  - "Opção de compilador /EH (C++)"
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /EH (modelo de tratamento de exce&#231;&#245;es)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o tipo de tratamento de exceção usado pelo compilador, ao otimizar exceção ausente verifica e se deseja destruir objetos C\+\+ que saem do escopo devido a uma exceção. Se **\/EH** não for especificado, o compilador captura exceções estruturadas assíncronas e exceções do C\+\+, mas não destrói os objetos C\+\+ que saem do escopo devido a uma exceção assíncrona.  
  
## Sintaxe  
  
```  
/EH{s|a}[c][r][-]  
```  
  
## Arguments  
 **a**  
 O modelo de tratamento de exceções que captura assíncrona \(estruturada\) e síncronas exceções \(C\+\+\).  
  
 **s**  
 O modelo de tratamento de exceções que captura somente exceções C\+\+ e informa o compilador suponha que as funções declaradas como `extern "C"` pode lançar uma exceção.  
  
 **c**  
 Se usado com **s** \(**\/EHsc**\), captura somente exceções C\+\+ e diz ao compilador para assumir que as funções declaradas como `extern "C"` nunca lançam uma exceção de C\+\+.  
  
 **\/EHca** é equivalente a **\/EHa**.  
  
 **r**  
 Informa ao compilador para gerar sempre verificações de término do tempo de execução para todos os `noexcept` funções. Por padrão, verificações de tempo de execução para `noexcept` pode ser otimizada se o compilador determina a função chama não lançar somente funções.  
  
## Comentários  
 O **\/EHa** opção de compilador é usada para oferecer suporte à manipulação de exceções estruturadas assíncronas \(SEH\) com o C\+\+ nativo `catch(...)` cláusula. Para implementar SEH sem especificar **\/EHa**, você pode usar o `__try`, `__except`, e `__finally` sintaxe. Embora o Windows e Visual C\+\+ suportem SEH, é altamente recomendável que você use o tratamento de exceções C\+\+ padrão ISO \(**\/EHs** ou **\/EHsc**\) porque ela torna o código mais portátil e flexível. No entanto, no código existente ou para tipos específicos de programas — por exemplo, no código compilado para oferecer suporte a common language runtime \([\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)\) — você ainda pode precisar usar o SEH. Para obter mais informações, consulte [Tratamento de exceções estruturado](../../cpp/structured-exception-handling-c-cpp.md).  
  
 Especificando **\/EHa** e tentar manipular todas as exceções usando `catch(...)` pode ser perigoso. Na maioria dos casos, exceções assíncronas são irrecuperáveis em devem ser consideradas fatais. Capturá\-las e continuar podem causar corrompimento de processo e gerar bugs que são difíceis de encontrar e corrigir.  
  
 Se você usar **\/EHs** ou **\/EHsc**, o `catch(...)` cláusula catch não estruturado de exceções assíncronas. Violações de acesso e gerenciado <xref:System.Exception?displayProperty=fullName> exceções não são capturadas e objetos no escopo quando uma exceção assíncrona for gerada não são destruídos, mesmo se a exceção assíncrona é tratada.  
  
 Se você usar **\/EHa**, a imagem poderá ser maior e pode executar menos bem porque o compilador não otimiza um `try` bloquear mais agressiva. Ele também deixa filtros de exceção que chamam automaticamente os destruidores de todos os objetos locais mesmo se o compilador não vê qualquer código que pode lançar uma exceção de C\+\+. Isso permite que a liberação para exceções assíncronas, bem como para exceções C\+\+ segura da pilha. Quando você usa **\/EHs**, o compilador pressupõe que as exceções só podem ocorrer em um `throw` instrução ou em uma chamada de função. Isso permite que o compilador eliminar o código para controlar o tempo de vida de muitos objetos liberáveis, e isso pode reduzir significativamente o tamanho do código.  
  
 É recomendável que você não pode vincular objetos compilados usando **\/EHa** juntamente com os objetos compilados usando **\/EHs** no mesmo módulo executável. Se você precisa lidar com uma exceção assíncrona usando **\/EHa** em qualquer lugar no seu módulo, use **\/EHa** para compilar todo o código no módulo. Você pode usar a sintaxe no mesmo módulo código compilado por meio de manipulação de exceção estruturada **\/EHs**, mas você não pode misturar a sintaxe SEH com `try`, `throw`, e `catch` na mesma função.  
  
 Use **\/EHa** se você deseja capturar uma exceção é gerada por algo diferente de um `throw`. Este exemplo gera e captura uma exceção estruturada:  
  
```  
  
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
  
 O **\/EHc** opção requer que **\/EHs** ou **\/EHa** for especificado. O **\/clr** opção implica **\/EHa** \(ou seja, **\/clr \/EHa** é redundante\). O compilador gera um erro se **\/EHs \[c\]** é usada após **\/clr**. Otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invocará o destruidor de classe ou os destruidores de um ou mais objetos que estão no mesmo escopo da exceção. Quando uma exceção não é detectada, esses destruidores não são executados.  
  
 Para obter informações sobre restrições em de manipulação de exceção **\/clr**, consulte [\_set\_se\_translator](../../c-runtime-library/reference/set-se-translator.md).  
  
 A opção pode ser limpa usando o símbolo **\-**. Por exemplo, **\/EHsc\-** é interpretado como **\/EHs \/EHc\-** e é equivalente a **\/EHs**.  
  
 O **\/EHr** opção de compilador força verificações de término do tempo de execução em todas as funções que têm um `noexcept` atributo. Por padrão, verificações de tempo de execução podem ser removidas se o back\-end do compilador determina que uma função apenas chama *não lançar* funções. Funções geradoras de não são todas as funções que têm um atributo que especifica que nenhuma exceção pode ser lançada. Isso inclui funções marcadas `noexcept`, `throw()`, `__declspec(nothrow)`, e quando **\/EHc** for especificado, `extern "C"` funções. Funções geradoras de não incluem também qualquer que o compilador determinou são não lançam por inspeção. Você pode definir explicitamente o padrão usando **\/EHr\-**.  
  
 No entanto, o atributo não lançar não é uma garantia de que nenhuma exceção pode ser lançada por uma função. Ao contrário do comportamento de um `noexcept` função, o compilador do Visual C\+\+ considera uma exceção acionada por uma função declarada usando `throw()`, `__declspec(nothrow)`, ou `extern "C"` como um comportamento indefinido. Funções que usam esses atributos de três declaração não impõem verificações de término do tempo de execução para exceções. Você pode usar o **\/EHr** opção para ajudá\-lo a identificar esse comportamento indefinido, forçando o compilador para gerar verificações de tempo de execução para exceções não tratadas escape uma `noexcept` função.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  No painel esquerdo, expanda **Propriedades de configuração**, **C\/C\+\+**, **geração de código**.  
  
3.  Modificar o **habilita exceções C\+\+** propriedade.  
  
     Ou defina **habilita exceções C\+\+** para **não**, e, em seguida, o **linha de comando** página de propriedade, no **Opções adicionais** caixa, adicione a opção de compilador.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Erros e tratamento de exceções](../../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Especificações de exceção \(lançar\)](../../cpp/exception-specifications-throw-cpp.md)   
 [Tratamento de exceções estruturado](../../cpp/structured-exception-handling-c-cpp.md)