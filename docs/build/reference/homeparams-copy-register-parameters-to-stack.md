---
title: "/homeparams (copiar par&#226;metros de registro para pilha) | Microsoft Docs"
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
  - "/homeparams"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /homeparams (C++)"
  - "Opção de compilador -homeparams [C++]"
ms.assetid: 51067de4-24f7-436b-b8d9-bc867a7d53aa
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /homeparams (copiar par&#226;metros de registro para pilha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Força os parâmetros passados em registros a serem gravados em seus locais na pilha em cima de entrada da função.  
  
## Sintaxe  
  
```  
/homeparams  
```  
  
## Comentários  
 Esta opção de compilador é somente para os compiladores [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] \(compilação nativa e cruzada\).  
  
 Quando os parâmetros são passados em uma compilação de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] , chamando convenções requer o stackspace para parâmetros, mesmo para os parâmetros passados em registros.  Para obter mais informações, consulte [Passagem de parâmetro](../../build/parameter-passing.md).  No entanto, por padrão em uma compilação de versão, os parâmetros de registro não serão gravados na pilha, no espaço fornecido já para os parâmetros.  Isso dificulta a depurar uma construção \(otimizada da versão\) do programa.  
  
 Para uma construção de versão, use **\/homeparams** para assegurar que você pode depurar seu aplicativo.  **\/homeparams** implica uma desvantagem de desempenho, pois o exige um ciclo carregar sobre os parâmetros do registro à pilha.  
  
 Em uma compilação de depuração, a pilha sempre é populada com os parâmetros passados em registros.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)