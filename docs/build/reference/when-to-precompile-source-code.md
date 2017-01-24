---
title: "Quando pr&#233;-compilar o c&#243;digo-fonte | Microsoft Docs"
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
  - "pch"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de cabeçalho pré-compilado, quando pré-compilar"
  - "código-fonte, pré-compilando"
ms.assetid: eb8ba193-fd87-40d3-9545-c75deabe37cb
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Quando pr&#233;-compilar o c&#243;digo-fonte
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O código pré\-compilado é útil durante o ciclo de desenvolvimento reduzir o tempo de compilação, especialmente se:  
  
-   Você sempre usa um grande corpo de código que se altera raramente.  
  
-   O programa compreende vários módulos, que use um conjunto padrão incluem arquivos e as mesmas opções de compilação.  Nesse caso, todos incluem arquivos podem ser pré\-compiladas em um cabeçalho pré\-compilado.  
  
 A primeira compilação — aquela que cria o arquivo de cabeçalho pré\-compilado — usa compilações do que subsequentes de um bit mais demorada.  As compilações subsequentes podem continuar mais rapidamente incluindo o código pré\-compilado.  
  
 Você pode precompile programas de 2.0 C e C\+\+.  Em programação C\+\+, é uma prática comum separar as informações da interface da classe em arquivos de cabeçalho.  Esses arquivos de cabeçalho podem ser incluídos em programas que usam a classe.  Precompiling esses cabeçalhos, você pode reduzir o tempo que leva para criar um programa.  
  
> [!NOTE]
>  Embora você possa usar apenas um arquivo pré\-compilado de cabeçalho \(\) .pch pelo arquivo de origem, você pode usar vários arquivos de .pch em um projeto.  
  
## Consulte também  
 [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)