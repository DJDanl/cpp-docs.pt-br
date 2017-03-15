---
title: "/Zs (apenas verifica&#231;&#227;o da sintaxe) | Microsoft Docs"
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
  - "/zs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Zs (C++)"
  - "Opção de compilador Apenas Verificação de Sintaxe"
  - "Opção de compilador Zs"
  - "Opção de compilador -Zs [C++]"
ms.assetid: b4b41e6a-3f41-4d09-9cb6-fde5aa2cfecf
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zs (apenas verifica&#231;&#227;o da sintaxe)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Informa o compilador para verificar somente a sintaxe de arquivos de origem na linha de comando.  
  
## Sintaxe  
  
```  
/Zs  
```  
  
## Comentários  
 Ao usar essa opção, nenhum arquivo de saída é criado, e as mensagens de erro são gravadas para a saída padrão.  
  
 A opção de **\/Zs** fornece um modo rápido de localizar e erros de sintaxe corretos antes de compilar e vincula um arquivo de origem.  
  
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