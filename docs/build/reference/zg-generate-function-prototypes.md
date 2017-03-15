---
title: "-Zg (gerar prot&#243;tipos de fun&#231;&#227;o) | Microsoft Docs"
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
  - "/zg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador Zg [C++]"
  - "Opção de compilador /Zg (C++)"
  - "protótipos de função, gerar a opção de compilador de protótipos de função"
  - "Opção de compilador -Zg [C++]"
  - "Opção de compilador gerar protótipos de função"
ms.assetid: c8df1b46-24ff-46f2-8356-e0a144b21dd2
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zg (gerar prot&#243;tipos de fun&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Removido. Cria um protótipo de função para cada função definida no arquivo de origem, mas não compila o arquivo de origem.  
  
## Sintaxe  
  
```  
/Zg  
```  
  
## Comentários  
 Essa opção de compilador não está mais disponível. Ele foi removido no Visual C\+\+ 2015. Esta página permanece para usuários de versões anteriores do Visual C\+\+.  
  
 O protótipo de função inclui o tipo de retorno da função e uma lista de tipo de argumento. Lista de tipo de argumento é criada entre os tipos dos parâmetros formais da função. Qualquer protótipos de função já está presentes no arquivo de origem são ignorados.  
  
 A lista de protótipos é gravada na saída padrão. Nesta lista podem ser úteis para verificar se os argumentos reais e parâmetros formais de uma função são compatíveis. Você pode salvar a lista redirecionando a saída padrão para um arquivo. Você pode usar **\#include** para tornar a lista de protótipos de função uma parte de seu arquivo de origem. Isso faz com que o compilador execute a verificação de tipo de argumento.  
  
 Se você usar o **\/Zg** opção e o programa contém parâmetros formais struct, enum, ou tipo de união \(ou ponteiros para esses tipos\), a declaração de cada estrutura, enum ou tipo de união deve ter uma marca \(nome\). No exemplo a seguir, o nome da marca é `MyStruct`.  
  
```  
// Zg_compiler_option.c  
// compile with: /Zg  
typedef struct MyStruct { int i; } T2;  
void f2(T2 * t) {}  
```  
  
 **\/Zg** foi preterido. O compilador do Visual C\+\+ planos remover o suporte para código anterior, do estilo C. Para obter mais informações, consulte [preterido opções do compilador do Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique o **C\/C\+\+** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **Opções adicionais** caixa.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)