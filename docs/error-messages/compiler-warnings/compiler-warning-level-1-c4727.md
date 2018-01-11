---
title: "Compilador (nível 1) de aviso C4727 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4727
dev_langs: C++
helpviewer_keywords: C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 813c2ab18cc81c4477ae094e6c2aa771e3135b7a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4727"></a>Compilador C4727 de aviso (nível 1)
"PCH nomeado pch_file com mesmo carimbo de hora encontrado em obj_file_1 e obj_file_2.  Usando primeiro PCH.  
  
 C4727 ocorre durante a compilação de vários compilandos com **/Yc**, e onde o compilador pôde marcar todos os arquivos. obj com o mesmo carimbo de hora. pch.  
  
 Para resolver, compilar um arquivo de origem com **/Yc /c** (cria pch), e os outros compile separadamente com **/Yu /c** (usa pch), em seguida, vinculá-los juntos.  
  
 Portanto, se você fez o seguinte e gera C4727:  
  
 **Cl /clr /GL a.cpp b.cpp c.cpp /Ycstdafx.h**  
  
 Você deve fazer o seguinte em vez disso:  
  
 **Cl /clr /GL a.cpp /Ycstdafx.h /c**  
  
 **Cl /clr /GL b.cpp c.cpp /Yustdafx.h /link a.obj**  
  
 Para saber mais, veja  
  
-   [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)  
  
-   [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)