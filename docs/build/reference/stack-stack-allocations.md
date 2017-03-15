---
title: "/STACK (aloca&#231;&#245;es da pilha) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.StackReserveSize"
  - "VC.Project.VCLinkerTool.StackCommitSize"
  - "/stack"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opção de vinculador STACK"
  - "opção de vinculador -STACK"
  - "alocação de memória, a pilha"
  - "Opção de vinculador /STACK"
  - "pilha, definindo o tamanho"
ms.assetid: 73283660-e4bd-47cc-b5ca-04c5d739034c
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /STACK (aloca&#231;&#245;es da pilha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/STACK:reserve[,commit]  
```  
  
## Comentários  
 As opções definidas \/STACK do tamanho da pilha em bytes.  Use essa opção apenas quando você cria um arquivo .exe.  
  
 O valor de `reserve` especifica a alocação de pilha total na memória virtual.  Para o BRAÇO, dos computadores x86 e de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] , o tamanho padrão da pilha é 1 MB.  
  
 `commit` está sujeito a interpretação pelo sistema operacional.  No windows WindowsRT especifica a quantidade de memória física para alocar em cada vez.  O espaço confirmada as causas de memória virtual a ser reservada no arquivo de paginação.  Um valor mais alto de `commit` economiza tempo quando o aplicativo precisar de mais espaço da pilha, mas aumenta os requisitos de memória e possivelmente o tempo de inicialização.  Para o BRAÇO, dos computadores x86 e de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] , o valor padrão de confirmação é 4 KB.  
  
 Especificar os valores de `reserve` e de `commit` em notação decimal do ou do C \- idioma.  
  
 Outra maneira de definir o tamanho da pilha é com a instrução de [STACKSIZE](../../build/reference/stacksize.md) em um arquivo do definição \(.def\).  **STACKSIZE** substitui a opção de alocação de pilha \(\/STACK\) se ambos forem especificados.  Você pode alterar o tamanho da pilha depois que o arquivo foi criado usando a ferramenta de [EDITBIN](../Topic/EDITBIN%20Reference.md) .  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do **Vinculador**.  
  
3.  Selecione a página de propriedades de **Sistema** .  
  
4.  Modifique uma das seguintes propriedades:  
  
    -   **Pilha o tamanho de confirmação**  
  
    -   **Pilha o tamanho de reserva**  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StackCommitSize%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StackReserveSize%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)