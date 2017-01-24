---
title: "Como depurar uma compila&#231;&#227;o da vers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "depurando [C++], compilações de lançamento"
  - "compilações de lançamento, depuração"
ms.assetid: d333e4d1-4e6c-4384-84a9-cb549702da25
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como depurar uma compila&#231;&#227;o da vers&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode depurar uma construção da versão de um aplicativo.  
  
### Para depurar uma construção de versão  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** para o projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique no nó de **C\/C\+\+** .  Definir **Formato de Informação de Depuração** a [C7 correspondente \(\/Z7\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) ou a **Base de dados do programa \(\/Zi\)**.  
  
3.  Expanda **Vinculador** e clique no nó de **Geral** .  Definir **Habilitar Vinculação Incremental** a [Nenhum \(\/INCREMENTAL: NOT\)](../../build/reference/incremental-link-incrementally.md).  
  
4.  Selecione o nó de **Depuração** .  Definir **Gerar informações de depuração** a [Sim \(\/DEBUG\)](../../build/reference/debug-generate-debug-info.md).  
  
5.  Selecione o nó de **Otimização** .  Definir **Referências** a [\/OPT: Referência](../../build/reference/opt-optimizations.md) e **Habilitar Dobra COMDAT** a [\/OPT: ICF](../../build/reference/opt-optimizations.md).  
  
6.  Agora você pode depurar seu aplicativo de criação da versão.  Para localizar um problema, vá com o código \(ou use a depuração just\-in\-time\) até localizar onde a falha ocorre, e determine os parâmetros ou o código incorreto.  
  
     Se um aplicativo trabalha em uma compilação de depuração, mas falhar em uma compilação de versão, uma das otimizações de compilador pode expor um defeito no código\-fonte.  Para isolar o problema, desabilite selecionou otimizações para cada arquivo de origem até que você localize o arquivo e otimização que está causando o problema. \(Para para agilizar o processo, você pode dividir os arquivos em dois grupos, desabilitar a otimização em um grupo, e quando você encontrar um problema em um grupo, continua a dividir até que você isolar o arquivo do problema.\)  
  
     Você pode usar [\/RTC](../../build/reference/rtc-run-time-error-checks.md) para tentar expor como bug nas construções de depuração.  
  
     Para obter mais informações, consulte [Otimizando o código](../../build/reference/optimizing-your-code.md).  
  
## Consulte também  
 [Corrigindo problemas de compilação da versão](../../build/reference/fixing-release-build-problems.md)