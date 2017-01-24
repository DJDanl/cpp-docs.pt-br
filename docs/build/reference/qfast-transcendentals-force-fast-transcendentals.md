---
title: "/Qfast_transcendentals (for&#231;ar transcendentais r&#225;pidos) | Microsoft Docs"
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
  - "/Qfast_transcendentals"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "/Qfast_transcendentals"
  - "Forçar Transcendentais Rápidos"
ms.assetid: 4de24bd1-38e6-49d4-9a05-04c9937d24ac
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Qfast_transcendentals (for&#231;ar transcendentais r&#225;pidos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia o código em linha para funções transcendentais.  
  
## Sintaxe  
  
```  
/Qfast_transcendentals  
```  
  
## Comentários  
 Essa opção força do compilador as funções transcendentais a ser convertido no código em linha para melhorar a velocidade de execução.  Essa opção tem um efeito apenas quando emparelhada com **\/fp:except** ou **\/fp:precise**.  Gerar código embutida para funções transcendentais já é o comportamento padrão em **\/fp:fast**.  
  
 Essa opção é incompatível com **\/fp:strict**.  Consulte [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md) para obter mais informações sobre as opções do compilador de ponto flutuante.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)