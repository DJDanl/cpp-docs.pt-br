---
title: "/F (definir tamanho da pilha) | Microsoft Docs"
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
  - "/f"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /F (C++)"
  - "Opção de compilador F [C++]"
  - "Opção de compilador -F [C++]"
  - "Opção de compilador definir tamanho de pilha"
  - "stack, definindo tamanho"
ms.assetid: 17320b6f-8305-445b-9ec2-75833f4b29e0
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /F (definir tamanho da pilha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o tamanho da pilha de programa em bytes.  
  
## Sintaxe  
  
```  
/F number  
```  
  
## Arguments  
 `number`  
 O tamanho da pilha em bytes.  
  
## Comentários  
 Sem esta opção o tamanho da pilha padrão é 1 MB.  O argumento de `number` pode estar em notação decimal do ou do C \- idioma.  O argumento pode variar de 1 ao tamanho máximo da pilha aceito pelo vinculador.  O vinculador acima arredonda o valor especificado para o mais próximo de 4 bytes.  O espaço entre **\/F** e `number`é opcional.  
  
 Talvez seja necessário aumentar o tamanho da pilha se seu programa recebe mensagens de permissão com base em fila estouro.  
  
 Você também pode definir o tamanho da pilha por:  
  
-   Usando a opção do vinculador de **\/STACK** .  Para obter mais informações, consulte [\/STACK](../../build/reference/stack.md).  
  
-   Usando EDITBIN no arquivo .exe.  Para obter mais informações, consulte [Referência de EDITBIN](../Topic/EDITBIN%20Reference.md).  
  
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