---
title: "Erro do Compilador C2097 | Microsoft Docs"
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
  - "C2097"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2097"
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2097
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

inicialização ilegal  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Inicialização de uma variável usando um valor não constante.  
  
2.  Inicialização de um endereço curto com um endereço longo.  
  
3.  Inicialização de uma estrutura, de uma união, ou matriz local com uma expressão não constante durante a criação com **\/Za**.  
  
4.  Inicialização com uma expressão que contém um operador vírgula.  
  
5.  Inicialização com uma expressão que é ou constante ou do token.