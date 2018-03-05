---
title: "-EH (modelo de tratamento de exceções) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ExceptionHandling
- /eh
- VC.Project.VCCLCompilerTool.ExceptionHandling
dev_langs:
- C++
helpviewer_keywords:
- exception handling, compiler model
- cl.exe compiler, exception handling
- EH compiler option [C++]
- -EH compiler option [C++]
- /EH compiler option [C++]
ms.assetid: 754b916f-d206-4472-b55a-b6f1b0f2cb4d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1c56020d5013e951d9d43ed799d34641d114d612
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eh-exception-handling-model"></a>/EH (modelo de tratamento de exceções)
Especifica o tipo de tratamento de exceção usado pelo compilador, ao otimizar exceção ausente verifica e se deseja destruir os objetos C++ que ultrapassarem o escopo devido a uma exceção. Se **/EH** não for especificado, o compilador captura estruturado de exceções assíncronas e exceções do C++, mas não destrói C++ os objetos fora do escopo devido a uma exceção assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/EH{s|a}[c][r][-]  
```  
  
## <a name="arguments"></a>Arguments  
 **a**  
 O modelo de tratamento de exceções que captura exceções assíncronas (estruturadas) e síncronas (C++).  
  
 **s**  
 O modelo de tratamento de exceções que captura somente exceções C++ e diz ao compilador para assumir que as funções declaradas como `extern "C"` podem gerar um exceção.  
  
 **c**  
 Se usado com **s** (**/EHsc**), captura somente exceções C++ e informa ao compilador para assumir que funções declaradas como `extern "C"` nunca lançam uma exceção de C++.  
  
 **/ EHca** é equivalente a **/EHa**.  
  
 **r**  
 Informa ao compilador para gerar sempre verificações de término do tempo de execução para todas as `noexcept` funções. Por padrão, verificações de tempo de execução para `noexcept` podem ser removidas se o compilador determina a função chama funções de não lançamento somente.  
  
## <a name="remarks"></a>Comentários  
 O **/EHa** opção de compilador é usada para dar suporte ao tratamento estruturado de exceções assíncronas (SEH) com o C++ nativo `catch(...)` cláusula. Para implementar SEH sem especificar **/EHa**, você pode usar o `__try`, `__except`, e `__finally` sintaxe. Embora o Windows e o Visual C++ suportem SEH, é altamente recomendável que você use o tratamento de exceção de C++ padrão ISO (**/EHs** ou **/EHsc**) porque ela torna o código mais portáteis e flexível. No entanto, no código existente ou para tipos específicos de programas — por exemplo, no código compilado para dar suporte a common language runtime ([/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)) — você ainda pode ter que usar SEH. Para obter mais informações, consulte [manipulação de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md).  
  
 Especificando **/EHa** e tentar tratar todas as exceções usando `catch(...)` pode ser perigoso. Na maioria dos casos, as exceções assíncronas são irrecuperáveis e devem ser consideradas fatais. Capturá-las e continuar pode causar o corrompimento do processo e gerar bugs que são difíceis de localizar e corrigir.  
  
 Se você usar **/EHs** ou **/EHsc**, o `catch(...)` cláusula catch não estruturado de exceções assíncronas. As violações de acesso e as exceções <xref:System.Exception?displayProperty=fullName> gerenciadas não são capturadas, e os objetos no escopo quando uma exceção assíncrona é gerada não são destruídos ainda que a exceção assíncrona seja tratada.  
  
 Se você usar **/EHa**, a imagem pode ser maior e pode executar menos também porque o compilador não otimizar um `try` bloquear mais agressiva. Ele também deixa em filtros de exceção que chamam automaticamente destruidores de todos os objetos de locais, mesmo que o compilador não vê qualquer código que pode gerar uma exceção de C++. Isso permite que a pilha segura desenrolamento para exceções assíncronas, bem como para as exceções do C++. Quando você usa **/EHs**, o compilador assumirá que exceções só podem ocorrer em um `throw` instrução ou em uma chamada de função. Isso permite que o compilador elimine o código para acompanhar o tempo de vida útil de muitos objetos liberáveis, e isso pode reduzir significativamente o tamanho de código.  
  
 É recomendável que você não pode vincular objetos compilados usando **/EHa** juntamente com objetos compilados usando **/EHs** no mesmo módulo executável. Se você precisa lidar com uma exceção assíncrona usando **/EHa** em qualquer lugar em seu módulo, use **/EHa** compilar todo o código do módulo. Você pode usar a sintaxe do mesmo módulo como código que é compilado com o uso de manipulação de exceção estruturada **/EHs**, mas você não pode misturar a sintaxe SEH com `try`, `throw`, e `catch` na mesma função.  
  
 Use **/EHa** se você deseja capturar uma exceção que é gerada por algo diferente de um `throw`. Este exemplo gera e captura uma exceção estruturada:  
  
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
  
 O **/EHc** opção requer que **/EHs** ou **/EHa** for especificado. O **/clr** opção implica **/EHa** (ou seja, **/clr /EHa** é redundante). O compilador gerará um erro se **/EHs [c]** é usado depois **/clr**. As otimizações não afetam esse comportamento. Quando uma exceção é detectada, o compilador invoca o destruidor ou os destruidores de classe do objeto ou dos objetos que estão no mesmo escopo da exceção. Quando uma exceção não é detectada, esses destruidores não são executados.  
  
 Para obter informações sobre restrições em de tratamento de exceção **/clr**, consulte [set_se_translator](../../c-runtime-library/reference/set-se-translator.md).  
  
 A opção pode ser apagada usando o símbolo  **-** . Por exemplo, **/EHsc-** é interpretado como **/EHs /EHc-** e é equivalente a **/EHs**.  
  
 O **/EHr** opção de compilador força verificações de término do tempo de execução de todas as funções que têm um `noexcept` atributo. Por padrão, verificações de tempo de execução podem ser removidas se o back-end do compilador determina que só chama uma função *não gerar* funções. Funções geradoras de não são todas as funções que têm um atributo que especifica que nenhuma exceção pode ser lançada. Isso inclui funções assinaladas como `noexcept`, `throw()`, `__declspec(nothrow)`e, quando **/EHc** for especificado, `extern "C"` funções. Funções geradoras de não também pode incluir qualquer uma que o compilador determinou são não lançamento por inspeção. Você pode definir explicitamente o padrão usando **/EHr-**.  
  
 No entanto, o atributo de não lançamento não é uma garantia de que nenhuma exceção pode ser gerada por uma função. Ao contrário do comportamento de um `noexcept` função, o compilador do Visual C++ considera uma exceção gerada por uma função declarada usando `throw()`, `__declspec(nothrow)`, ou `extern "C"` como um comportamento indefinido. Funções que usam esses atributos de três declaração não impõem verificações de término do tempo de execução para exceções. Você pode usar o **/EHr** opção para ajudá-lo a identificar esse comportamento indefinido, forçando o compilador gere verificações de tempo de execução para exceções não tratadas escape um `noexcept` função.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, expanda **propriedades de configuração**, **C/C++**, **geração de código**.  
  
3.  Modificar o **habilitar exceções de C++** propriedade.  
  
     Ou, defina **habilitar exceções de C++** para **não**e, em seguida, no **linha de comando** página de propriedade, no **opções adicionais** caixa, adicione o opção de compilador.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExceptionHandling%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Erros e tratamento de exceção](../../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)   
 [Tratamento de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md)