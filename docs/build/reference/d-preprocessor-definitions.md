---
title: "-D (definições de pré-processador) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCNMakeTool.PreprocessorDefinitions
- VC.Project.VCCLCompilerTool.PreprocessorDefinitions
- /d
dev_langs: C++
helpviewer_keywords:
- preprocessor definition symbols
- constants, defining
- macros, compiling
- /D compiler option [C++]
- -D compiler option [C++]
- D compiler option [C++]
ms.assetid: b53fdda7-8da1-474f-8811-ba7cdcc66dba
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 08812cdd0a4ffb27b387cce8cfb26e72ef80770a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="d-preprocessor-definitions"></a>/D (definições de pré-processador)
Define um símbolo de pré-processamento para um arquivo de código-fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Dname[= | # [{string | number}] ]  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar esse símbolo junto com `#if` ou `#ifdef` para compilar o código-fonte condicionalmente. A definição de símbolo permanece em vigor até que seja redefinida no código ou indefinida no código pela diretiva `#undef`.  
  
 **/D** tem o mesmo efeito que o `#define` diretiva no início de um arquivo de código fonte, exceto que **/D** retira aspas na linha de comando e `#define` retém.  
  
 Por padrão, o valor associado a um símbolo é 1. Por exemplo, **/D** `name` é equivalente a **/D**`name`**= 1**. O exemplo no final deste artigo, a definição de **teste** é mostrado para imprimir `1`.  
  
 Compilando usando **/D** `name`  **=**  faz com que o símbolo de não têm nenhum valor associado. Embora o símbolo ainda possa ser usado para compilar o código condicionalmente, em outros casos, sua avaliação não resulta em nada. No exemplo, se você compila usando **/DTEST =**, ocorrerá um erro. Esse comportamento é semelhante ao uso de `#define` com ou sem um valor.  
  
 Este comando define o símbolo DEBUG em TEST.c:  
  
 **TESTE DE /DDEBUG DE CL. C**  
  
 Esse comando remove todas as ocorrências da palavra-chave `__far` em TEST.c:  
  
 **CL /D__far = TEST. C**  
  
 O **CL** variável de ambiente não pode ser definida como uma cadeia de caracteres que contém o sinal de igual. Para usar **/D** junto com o **CL** ambiente variável, você deve especificar o sinal de número em vez do sinal de igual:  
  
```  
SET CL=/DTEST#0  
```  
  
 Quando você definir um símbolo de pré-processamento no prompt de comando, considere as regras de análise do compilador e do shell. Por exemplo, para definir um símbolo de pré-processamento de sinal porcentagem (%) em seu programa, especifique dois caracteres de sinal de porcentagem (%%) no prompt de comando: se você especificar apenas um, um erro de análise será emitido.  
  
```  
CL /DTEST=%% TEST.C  
```  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, selecione **propriedades de configuração**, **C/C++**, **pré-processador**.  
  
3.  No painel direito, na coluna à direita do **definições de pré-processador** propriedade, abra o menu suspenso e escolha **editar**.  
  
4.  No **definições de pré-processador** caixa de diálogo Adicionar (um por linha), modificar ou excluir uma ou mais definições. Escolha **Okey** para salvar suas alterações.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PreprocessorDefinitions%2A>.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
TEST defined 1  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/U, /u (Indefinir símbolos)](../../build/reference/u-u-undefine-symbols.md)   
 [#undef diretiva (C/C++)](../../preprocessor/hash-undef-directive-c-cpp.md)   
 [Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)