---
title: "Erro fatal C1382 | Microsoft Docs"
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
  - "C1382"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1382"
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1382
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o arquivo “arquivo” de PCH foi reconstruído porque o “obj” foi gerado.Recriar esse objeto \(em inglês\)  
  
 Ao usar [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo de .pch com mais novo que um CIL .obj que ele aponta.  As informações no arquivo de CIL .obj estiver expirado.  A recriação do objeto.  
  
 C1382 também poderá ocorrer se você compila com **\/Yc**, mas também passa mais arquivos de origem ao compilador.  Para resolver, não use **\/Yc** ao transmitir diversas arquivo de origem ao compilador.  Para obter mais informações, consulte [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md).