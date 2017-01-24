---
title: "/D (defini&#231;&#245;es de pr&#233;-processador) | Microsoft Docs"
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
  - "VC.Project.VCNMakeTool.PreprocessorDefinitions"
  - "VC.Project.VCCLCompilerTool.PreprocessorDefinitions"
  - "/d"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /D (C++)"
  - "constantes, definindo"
  - "Opção de compilador D [C++]"
  - "Opção de compilador -D [C++]"
  - "Macros , compilando"
  - "símbolos de definição de pré-processador"
ms.assetid: b53fdda7-8da1-474f-8811-ba7cdcc66dba
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /D (defini&#231;&#245;es de pr&#233;-processador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um símbolo de pré\-processamento para um arquivo de código\-fonte.  
  
## Sintaxe  
  
```  
/Dname[= | # [{string | number}] ]  
```  
  
## Comentários  
 Você pode usar esse símbolo junto com `#if` ou `#ifdef` para compilar o código\-fonte condicionalmente.  A definição de símbolo permanece em vigor até que seja redefinida no código ou indefinida no código pela diretiva `#undef`.  
  
 **\/D** tem o mesmo efeito que a diretiva `#define` no início de um arquivo de código\-fonte, exceto que **\/D** extrai as aspas na linha de comando e `#define` as mantém.  
  
 Por padrão, o valor associado a um símbolo é 1.  Por exemplo, **\/D**`name` equivale a **\/D**`name`**\=1**.  No exemplo no final deste artigo, a definição de **TEST** é mostrada para imprimir `1`.  
  
 Compilar usando **\/D**`name`**\=** faz com que o símbolo não tenha nenhum valor associado.  Embora o símbolo ainda possa ser usado para compilar o código condicionalmente, em outros casos, sua avaliação não resulta em nada.  No exemplo, se você compilar usando **\/DTEST\=**, ocorrerá um erro.  Esse comportamento é semelhante ao uso de `#define` com ou sem um valor.  
  
 Este comando define o símbolo DEBUG em TEST.c:  
  
 **CL \/DDEBUG  TEST.C**  
  
 Esse comando remove todas as ocorrências da palavra\-chave `__far` em TEST.c:  
  
 **CL \/D\_\_far\=  TEST.C**  
  
 A variável de ambiente **CL** não pode ser definida como uma cadeia de caracteres que contenha o sinal de igualdade.  Para usar **\/D** junto com a variável de ambiente **CL**, você deve especificar o sinal de número em vez do sinal de igualdade:  
  
```  
SET CL=/DTEST#0  
```  
  
 Quando você definir um símbolo de pré\-processamento no prompt de comando, considere as regras de análise do compilador e do shell.  Por exemplo, para definir um símbolo de pré\-processamento de sinal porcentagem \(%\) em seu programa, especifique dois caracteres de sinal de porcentagem \(%%\) no prompt de comando: se você especificar apenas um, um erro de análise será emitido.  
  
```  
CL /DTEST=%% TEST.C  
```  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  No painel esquerdo, selecione **Propriedades de Configuração**, **C\/C\+\+**, **Pré\-processador**.  
  
3.  No painel direito, na coluna à direita da propriedade **Definições do Pré\-processador**, abra o menu suspenso e escolha **Editar**.  
  
4.  Na caixa de diálogo **Definições do Pré\-processador**, adicione \(uma linha por linha\), modifique ou exclua uma ou mais definições.  Escolha **OK** para salvar suas alterações.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PreprocessorDefinitions%2A>.  
  
## Exemplo  
  
```  
// cpp_D_compiler_option.cpp  
// compile with: /DTEST  
#include <stdio.h>  
  
int main( )  
{  
    #ifdef TEST  
        printf_s("TEST defined %d\n", TEST);  
    #else  
        printf_s("TEST not defined\n");  
    #endif  
}  
```  
  
  **TESTE definido 1**   
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/U, \/u \(indefinir símbolos\)](../Topic/-U,%20-u%20\(Undefine%20Symbols\).md)   
 [Diretiva \#undef](../../preprocessor/hash-undef-directive-c-cpp.md)   
 [Diretiva \#define](../../preprocessor/hash-define-directive-c-cpp.md)