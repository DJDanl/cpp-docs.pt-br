---
title: "/Fx (mesclar c&#243;digo injetado) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.ExpandAttributedSource"
  - "/Fx"
  - "VC.Project.VCCLCompilerTool.ExpandAttributedSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Fx (C++)"
  - "Opção de compilador Fx [C++]"
  - "Opção de compilador -Fx [C++]"
  - "código injetado"
  - "mesclando código injetado"
ms.assetid: 14f0e301-3bab-45a3-bbdf-e7ce66f20560
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Fx (mesclar c&#243;digo injetado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencie uma cópia de cada arquivo de origem com o código SQL injetado mesclada na origem.  
  
## Sintaxe  
  
```  
/Fx  
```  
  
## Comentários  
 Para diferenciar um arquivo de origem mesclada de um arquivo de origem, **\/Fx** adiciona uma extensão de .mrg entre o nome do arquivo e a extensão de arquivo.  Por exemplo, um arquivo denominado MyCode.cpp que contém o código atribuído e compilado com **\/Fx** cria um arquivo denominado MyCode.mrg.cpp que contém o seguinte código:  
  
```  
//+++ Start Injected Code  
[no_injected_text(true)];      // Suppress injected text, it has   
                               // already been injected  
#pragma warning(disable: 4543) // Suppress warnings about skipping   
                               // injected text  
#pragma warning(disable: 4199) // Suppress warnings from attribute   
                               // providers  
//--- End Injected Code  
```  
  
 Em um arquivo de .mrg, o código que foi injetado devido a um atributo será limitado a seguinte maneira:  
  
```  
//+++ Start Injected Code  
...  
//--- End Injected Code  
```  
  
 O atributo de [no\_injected\_text](../../windows/no-injected-text.md) é inserido em um arquivo de .mrg, que permite a criação do arquivo de .mrg sem texto que está sendo reinjected.  
  
 Lembre\-se de que o arquivo de origem de .mrg é pretendido ser uma representação do código\-fonte injetada pelo compilador.  O arquivo de .mrg não pode criar ou executar exatamente como o arquivo de origem original.  
  
 Macros não são expandidos no arquivo de .mrg.  
  
 Se seu programa inclui um arquivo de cabeçalho que usa o código SQL injetado, **\/Fx** gerencie um arquivo de .mrg.h para esse cabeçalho.  **\/Fx** não mesclar inclui arquivos que não usam o código SQL injetado.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **ARQUIVOS DE SAÍDA** .  
  
4.  Modifique a propriedade de **Expande a Fonte Atribuída** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExpandAttributedSource%2A>.  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)