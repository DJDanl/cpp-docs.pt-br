---
title: "/HEAP (definir tamanho do heap) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.HeapCommitSize"
  - "/heap"
  - "VC.Project.VCLinkerTool.HeapReserveSize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /HEAP"
  - "alocação de heap, definindo tamanho de heap"
  - "opção de vinculador HEAP"
  - "opção de vinculador -HEAP"
ms.assetid: a3f71927-7f1d-492c-9fdb-dfccb1a043da
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /HEAP (definir tamanho do heap)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/HEAP:reserve[,commit]  
```  
  
## Comentários  
 As opções definidas \/HEAP do tamanho do heap em bytes.  Essa opção é somente para uso durante a criação de um arquivo .exe.  
  
 O argumento *de permitir* especifica a alocação total de heap na memória virtual.  O tamanho padrão do heap é 1 MB.  O vinculador acima arredonda o valor especificado para o mais próximo de 4 bytes.  
  
 O argumento opcional de `commit` está sujeito a interpretação pelo sistema operacional.  No Windows NT\/Windows 2000, especifica a quantidade de memória física para alocar em cada vez.  O espaço confirmada as causas de memória virtual a ser reservada no arquivo de paginação.  Um valor mais alto de `commit` economiza tempo quando o aplicativo precisar de mais espaço de heap, mas aumenta os requisitos de memória e possivelmente o tempo de inicialização.  
  
 Especifique *a reserva* e os valores de `commit` em notação decimal do ou do C \- idioma.  
  
 Essa funcionalidade também está disponível por meio de um arquivo de definição de módulo com [HEAPSIZE](../../build/reference/heapsize.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Sistema** .  
  
4.  Modifique a propriedade de **Tamanho de Confirmação de Heap** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapReserveSize%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapCommitSize%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)