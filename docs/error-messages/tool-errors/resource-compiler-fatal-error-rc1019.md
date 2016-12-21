---
title: "Erro fatal RC1019 (compilador de recurso) | Microsoft Docs"
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
  - "RC1019"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC1019"
ms.assetid: 432fff44-04a9-4e13-91c6-870df6f0b4e4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal RC1019 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“\#else inesperado”  
  
 A política de `#else` não foi exibido dentro de `#if`, de **\#ifdef**, ou de compilação de **\#ifndef** .  
  
 Verifique se há `#if`, **\#ifdef**, ou uma instrução de **\#ifndef** aplicado antes dessa instrução.