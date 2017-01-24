---
title: "Erro das Ferramentas de Vinculador LNK1188 | Microsoft Docs"
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
  - "LNK1188"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1188"
ms.assetid: 4af574b0-5b41-4580-9a37-52a634add995
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1188
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

BADFIXUPSECTION:: destino inválido “símbolo” de fixup; seção possível de comprimento zero  
  
 Durante um link de VxD, o destino de uma realocação não tinha uma seção.  Com LINK386 \(uma versão anterior\), um registro de GROUP de OMF \(gerado por uma política de GROUP de MASM\) pode ter sido usado para combinar a seção de comprimento zero com outra seção diferente de zero de comprimento.  O formato de COFF não oferece suporte a política de GROUP BY e as seções de comprimento zero.  Quando o LINK converte automaticamente esse tipo de OMF management objects COFF, esse erro poderá ocorrer.