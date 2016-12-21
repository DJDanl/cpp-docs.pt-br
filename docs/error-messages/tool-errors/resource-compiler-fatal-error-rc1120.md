---
title: "Erro fatal RC1120 (compilador de recurso) | Microsoft Docs"
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
  - "RC1120"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC1120"
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal RC1120 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

fora de memória, número de bytes necessária  
  
 O compilador de recursos faltou de armazenamento para os itens no heap.  Normalmente esse é o resultado de ter muitos símbolos.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Aumentar o espaço de arquivo de permuta do windows.  Para obter mais informações sobre como aumentar o espaço de arquivo de permuta, consulte a memória virtual em uma ajuda do windows.  
  
2.  Eliminar desnecessário incluem arquivos, especialmente `#define`desnecessários s e protótipos de função.  
  
3.  Divida o arquivo atual em dois ou mais arquivos e criá\-las separadamente.  
  
4.  Remover outros programas ou drivers em execução no sistema, que pode consumir quantidades significativas de memória.