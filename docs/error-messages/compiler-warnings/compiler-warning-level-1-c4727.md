---
title: "Compilador aviso (nível 1) C4727 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4727
dev_langs:
- C++
helpviewer_keywords:
- C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c3d77b053fb866a16e6642ba2e6a24ff6d85798f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4727"></a>Compilador C4727 de aviso (nível 1)
"Chamado pch_file com carimbo de hora mesmo encontrado no obj_file_1 e obj_file_2 PCH.  Usando PCH primeiro.  
  
 C4727 ocorre durante a compilação de vários compilandos com **/Yc**, e onde o compilador pôde marcar todos os arquivos. obj com o mesmo carimbo de hora. pch.  
  
 Para resolver, compilar um arquivo de origem com **/Yc /c** (cria pch), e os outros compile separadamente com **/Yu /c** (usa pch), vinculá-los juntos.  
  
 Portanto, se você fez o seguinte e gera C4727:  
  
 **Cl /clr /GL a.cpp b.cpp c.cpp /Ycstdafx.h**  
  
 Você deve fazer o seguinte em vez disso:  
  
 **Cl /clr /GL a.cpp /Ycstdafx.h /c**  
  
 **Cl /clr /GL b.cpp c.cpp /Yustdafx.h /link a.obj**  
  
 Para saber mais, veja  
  
-   [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)  
  
-   [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)
