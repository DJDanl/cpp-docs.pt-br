---
title: "Erro fatal C1060 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1060"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1060"
ms.assetid: feaf305c-c84c-4160-b974-50e283412849
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1060
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o compilador está fora do espaço de heap  
  
 O sistema operacional ou a biblioteca de tempo de execução não pode preencher uma solicitação de memória.  
  
### Para corrigir esse erro tente as seguintes soluções possíveis  
  
1.  Se o compilador também emitir os erros [C1076](../Topic/Fatal%20Error%20C1076.md) e [C3859](../Topic/Compiler%20Error%20C3859.md), use a opção [\/Zm](../Topic/-Zm%20\(Specify%20Precompiled%20Header%20Memory%20Allocation%20Limit\).md) do compilador para diminuir o limite de alocação de memória.  Mais espaço de heap está disponível para o aplicativo se você diminuir a alocação da memória restante.  
  
     Se a opção [\/Zm](../Topic/-Zm%20\(Specify%20Precompiled%20Header%20Memory%20Allocation%20Limit\).md) já estiver definida, tente removê\-la.  O espaço de heap pode se esgotar porque o limite de alocação de memória especificado na opção é muito alto.  O compilador usa um limite padrão se você remover a opção [\/Zm](../Topic/-Zm%20\(Specify%20Precompiled%20Header%20Memory%20Allocation%20Limit\).md).  
  
2.  Se você estiver compilando em uma plataforma de 64 bits, use o conjunto de ferramentas do compilador de 64 bits.  Para obter informações, consulte [Como habilitar um Conjunto de Ferramentas Visual C\+\+ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).  
  
3.  No Windows de 32 bits, tente usar o comutador boot.ini de [\/3GB](http://go.microsoft.com/fwlink/?LinkId=177831).  
  
4.  Aumente o tamanho do arquivo de permuta do Windows.  
  
5.  Feche outros programas em execução.  
  
6.  Elimine arquivos de inclusão desnecessários.  
  
7.  Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.  
  
8.  Elimine declarações não usadas.  
  
9. Divida o arquivo atual em arquivos menores.