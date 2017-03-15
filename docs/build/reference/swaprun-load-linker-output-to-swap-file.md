---
title: "/SWAPRUN (carregar sa&#237;da do vinculador para trocar arquivo) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.SwapRunFromNet"
  - "/swaprun"
  - "VC.Project.VCLinkerTool.SwapRunFromCD"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /SWAPRUN"
  - "Arquivos  [C++], LINK"
  - "ferramenta LINK [C++], saída"
  - "vinculador [C++], copiando saída no arquivo swap"
  - "arquivos de saída, vinculador"
  - "arquivo swap para a saída de vinculador"
  - "opção de vinculador SWAPRUN"
  - "opção de vinculador -SWAPRUN"
ms.assetid: 4a1e7f46-4399-4161-8dfc-d6a71beaf683
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SWAPRUN (carregar sa&#237;da do vinculador para trocar arquivo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/SWAPRUN:{NET|CD}  
```  
  
## Comentários  
 A opção \/SWAPRUN diz ao sistema operacional para a primeira cópia a saída do vinculador a um arquivo de permuta, e executa a imagem de lá.  Esse é um recurso do Windows NT 4.0 \(ou posterior\).  
  
 Se a O for especificada, o sistema operacional primeiro copiar a imagem binária da rede de um arquivo de permuta e para carregá\-los de lá.  Essa opção é útil para executar aplicativos pela rede.  Quando o CD for especificado, o sistema operacional deve copiar a imagem em um disco removível em um arquivo de paginação e carregar\-a\-&z em.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Sistema** .  
  
4.  Modifique uma das seguintes propriedades:  
  
    -   **Alternar a execução do CD**  
  
    -   **Alternar a execução da rede**  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromCD%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromNet%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)