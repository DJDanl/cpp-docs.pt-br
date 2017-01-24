---
title: "/Oy (omiss&#227;o do ponteiro de quadro) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.OmitFramePointers"
  - "/oy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Oy (C++)"
  - "Opção de compilador de omissão de ponteiro de quadro [C++]"
  - "omitir ponteiro de quadro"
  - "Opção de compilador Oy [C++]"
  - "Opção de compilador -Oy [C++]"
  - "Opção de compilador de ponteiro de quadro de pilha [C++]"
  - "suprimir criação de ponteiro de quadro"
ms.assetid: c451da86-5297-4c5a-92bc-561d41379853
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Oy (omiss&#227;o do ponteiro de quadro)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inibe a criação de ponteiros de quadros na pilha de chamadas.  
  
## Sintaxe  
  
```  
/Oy[-]  
```  
  
## Comentários  
 Essa opção acelera chamadas de função, porque nenhum ponteiro de quadro precisa ser configurado e removido.  Também libera mais um registro, \(EBP no Intel 386 ou posterior\) para armazenar variáveis e subexpressões usadas frequentemente.  
  
 **\/Oy** permite a omissão de ponteiro de quadro e **\/Oy\-** desabilita a omissão.  **\/Oy** está disponível somente em compiladores x86.  
  
 Se seu código exigir tratamento baseado em EBP, você poderá especificar a opção **\/Oy–** após a opção **\/Ox** ou usar [optimize](../../preprocessor/optimize.md) com os argumentos “**y**” e **off** para obter a máxima otimização com tratamento baseado em EBP.  O compilador detecta a maioria das situações em que o tratamento baseado em EBP é necessário \(por exemplo, com as funções `_alloca` e `setjmp` e o tratamento estruturado de exceções\).  
  
 As opções [\/Ox \(otimização total\)](../../build/reference/ox-full-optimization.md) e [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) implicam **\/Oy**.  Especificar **\/Oy–** depois da opção **\/Ox**, **\/O1** ou **\/Oy** desabilita **\/O2**, seja explícita ou implícita.  
  
 A opção de compilador **\/Oy** torna o uso do depurador mais difícil porque o compilador suprime as informações do ponteiro de quadro.  Se você especificar uma opção de compilador de depuração \([\/Z7, \/Zi, \/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)\), é recomendável especificar a opção **\/Oy\-** depois das outras opções de compilador de otimização.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Otimização**.  
  
4.  Modifique a propriedade de **Omite Ponteiros de Quadros**.  Essa propriedade adiciona ou remove somente a opção **\/Oy**.  Se você quiser adicionar a opção **\/Oy\-**, clique em **Linha de Comando** e modifique **Opções adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitFramePointers%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)