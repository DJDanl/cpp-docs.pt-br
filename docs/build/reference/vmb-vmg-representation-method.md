---
title: "/vmb, /vmg (m&#233;todo de representa&#231;&#227;o) | Microsoft Docs"
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
  - "/vmb"
  - "/vmg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /vmb (C++)"
  - "Opção de compilador /vmg (C++)"
  - "opções de compilador de método de representação [C++]"
  - "Opção de compilador vmb [C++]"
  - "Opção de compilador -vmb [C++]"
  - "Opção de compilador vmg [C++]"
  - "Opção de compilador -vmg [C++]"
ms.assetid: ecdb391c-7dab-40b1-916b-673d10889fd4
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /vmb, /vmg (m&#233;todo de representa&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Selecione o método do compilador usa para representar ponteiros para classificar membros.  
  
 Use **\/vmb** se você sempre defina uma classe antes que você declara um ponteiro para um membro da classe.  
  
 Use **\/vmg** para declarar um ponteiro para um membro de uma classe antes de definir a classe.  Essa necessidade pode ocorrer se você definirá membros em duas classes diferentes que se fizerem referência.  Para essas classes mutuamente de referência, uma classe deve ser referenciada antes de ser definida.  
  
## Sintaxe  
  
```  
/vmb  
/vmg  
```  
  
## Comentários  
 Você também pode usar [pointers\_to\_members](../Topic/pointers_to_members.md) ou [Palavras\-chave de herança](../../cpp/inheritance-keywords.md) em seu código para especificar uma representação do ponteiro.  
  
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