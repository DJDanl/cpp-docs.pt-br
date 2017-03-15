---
title: "/BIND | Microsoft Docs"
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
  - "/bind"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /BIND (editbin)"
  - "opção editbin BIND"
  - "opção editbin -BIND"
  - "pontos de entrada"
  - "pontos de entrada, endereços"
  - "importar tabela de endereços"
ms.assetid: 3772b330-1868-4c90-857d-c31faa867982
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /BIND
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/BIND[:PATH=path]  
```  
  
## Comentários  
 Essa opção define os endereços dos pontos de entrada na tabela de endereço de importação para um arquivo executável ou uma DLL.  Use essa opção para reduzir o tempo de carregamento de um programa.  
  
 Especifique o arquivo executável e as dlls de programas no argumento de *arquivos* na linha de comando de EDITBIN.  O argumento opcional do *caminho* a \/BIND especifica o local dos arquivos DLL usados pelos especificados.  Vários diretórios separados por um ponto\-e\-vírgula \(**;**\).  Se *o caminho* não for especificado, EDITBIN pesquisa os diretórios especificados na variável de ambiente PATH.  Se *o caminho* for especificado, EDITBIN ignora a variável PATH.  
  
 Por padrão, o carregador de programa define os endereços de pontos de entrada quando carrega um programa.  A quantidade de tempo que esse processo leva varia, dependendo do número de DLL e o número de pontos de entrada no programa referenciados.  Se um programa tiver sido modificado com \/BIND e, se os endereços de base para o arquivo executável e seus dlls não entram em conflito com DLL que já estão carregados, o sistema operacional não precisa definir esses endereços.  Em uma situação em que os arquivos sejam baseados incorretamente, o sistema operacional realoca as dlls de programa e recalcular os endereços de ponto de, o que adiciona ao tempo de carregamento de programa.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)