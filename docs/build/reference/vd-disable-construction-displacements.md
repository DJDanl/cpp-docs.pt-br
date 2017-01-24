---
title: "/vd (desabilitar deslocamentos de constru&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/vd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /vd0 (C++)"
  - "Opção de compilador /vd1 (C++)"
  - "Opção de compilador /vdn (Desabilitar Deslocamento de Construção)"
  - "deslocamentos de construção"
  - "Opção de compilador Desabilitar Deslocamentos de Construção"
  - "Opção de compilador de deslocamentos"
  - "Opção de compilador vd0 [C++]"
  - "Opção de compilador -vd0 [C++]"
  - "Opção de compilador vd1 [C++]"
  - "Opção de compilador -vd1 [C++]"
  - "campos vtordisp"
ms.assetid: 93258964-14d7-4b1c-9cbc-d6f4d74eab69
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /vd (desabilitar deslocamentos de constru&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
/vdn  
```  
  
## Arguments  
 `0`  
 Suprime o membro do deslocamento do construtor\/destruidor de vtordisp.  Escolha essa opção somente se você tiver certeza de que todos os destruidores classificam construtores e chamadas de funções virtuais inclusão.  
  
 `1`  
 Permite criação de membros ocultos de deslocamento de destruidor\/construtor de vtordisp.  Esta opção é o padrão.  
  
 `2`  
 Permite que você use [Operador dynamic\_cast](../../cpp/dynamic-cast-operator.md) em um objeto que está sendo construído.  Por exemplo, um dynamic\_cast de uma classe base virtual em uma classe derivada.  
  
 **\/vd2** adiciona um campo de vtordisp quando você tiver uma base virtual com funções virtuais.  **\/vd1** deve ser suficiente.  A maioria dos casos comum onde são **\/vd2** é necessário quando a única função virtual em sua base virtual é um destruidor.  
  
## Comentários  
 Essas opções se aplicam apenas ao código C\+\+ que usa bases virtuais.  
  
 [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] implementa o suporte de deslocamento da construção C\+\+ em situações onde a herança virtual é usada.  Deslocamentos de construção resolver o problema criado quando uma função virtual, declarada em uma base virtual e substituído em uma classe derivada, é chamada de um construtor durante a compilação de uma classe derivada adicional.  
  
 O problema é que a função virtual pode ser passada um ponteiro incorreto de `this` no resultado das discrepâncias entre os deslocamentos às bases virtuais de uma classe e os deslocamentos a suas classes derivadas.  A solução fornece um único ajuste de deslocamento da construção, chamado de campo de vtordisp, para cada base virtual de uma classe.  
  
 Por padrão, os campos de vtordisp são introduzidas sempre que o código define construtores definidos pelo usuário e destruidores e também substitui funções virtuais de bases virtuais.  
  
 Essas opções afetam arquivos de origem inteiros.  Use [vtordisp](../Topic/vtordisp.md) para suprimir e reabilitar em campos de vtordisp em uma base de classe\-por\- classe.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)