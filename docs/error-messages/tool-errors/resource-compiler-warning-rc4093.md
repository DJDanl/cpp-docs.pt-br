---
title: "Aviso RC4093 (compilador de recurso) | Microsoft Docs"
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
  - "RC4093"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC4093"
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso RC4093 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

nova linha de unescape na constante de caractere em código inativo  
  
 A expressão constante de `#if`, de `#elif`, de **\#ifdef**, ou política de pré\-processador de **\#ifndef** avaliada como zero, tornando o código a seguir inativo.  Dentro desse código inativa, um caractere de nova linha foi exibido dentro de um conjunto de aspas simples ou duplas.  
  
 Todo o texto até as aspas duplas seguir foi considerado estar em uma constante de caractere.