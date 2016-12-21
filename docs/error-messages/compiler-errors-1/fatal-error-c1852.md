---
title: "Erro fatal C1852 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C1852"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1852"
ms.assetid: fa011004-b8d6-46f1-ba80-4785e4ce137f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1852
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'filename' não é um arquivo de cabeçalho pré\-compilado válido  
  
 O arquivo não é um cabeçalho pré\-compilado.  
  
### Para corrigir verificando as possíveis causas  
  
1.  Arquivo inválido especificado com **\/Yu** ou **\#pragma hdrstop**.  
  
2.  O compilador pressupõe uma extensão de arquivo de. pch se você não especifique o contrário.