---
title: "/V (n&#250;mero de vers&#227;o) | Microsoft Docs"
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
  - "/v"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /V (C++)"
  - "inserindo cadeias de caracteres de versão"
  - "Opção de compilador V [C++]"
  - "Opção de compilador -V [C++]"
  - "números de versão, especificando para .obj"
ms.assetid: 3e93fb7a-5dfd-49a6-bd49-3dca8052e0f3
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /V (n&#250;mero de vers&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Insere um stringin texto doarquivo de .obj.  Preterido.  
  
## Sintaxe  
  
```  
/Vstring  
```  
  
## Arguments  
 `string`  
 Uma cadeia de caracteres que especifica o aviso do número de versão ou de direitos autorais ser inserido em um arquivo de .obj.  
  
## Comentários  
 O rótulo stringcanum arquivo de .obj com um número de versão ou um aviso de direitos reservados.  Todo o espaço ou caracteres de tabulação devem ser colocados entre aspas duplas \("\) se são parte da cadeia de caracteres.  Uma barra invertida \(\\\) deve preceder todos aspas duplas se são parte da cadeia de caracteres.  Um espaço entre **\/V** e `string` é opcional.  
  
 Você também pode usar [comment](../../preprocessor/comment-c-cpp.md) com o argumento de comentário\- tipo do compilador para colocar o nome e o número da versão do compilador no arquivo de .obj.  
  
 **\/V** é substituído; **\/V** foi usado principalmente para drivers de dispositivo virtuais \(VxDs\) de compilação suporte, e a compilação VxDs não tem mais suporte do conjunto de ferramentas de [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] .  Para obter mais informações, consulte [Deprecated Compiler Options in Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
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