---
title: "Anota&#231;&#245;es de SAL | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Anotação __bcount"
  - "Anotação __checkreturn"
  - "Anotação __deref"
  - "Anotação __deref_opt"
  - "Anotação __ecount"
  - "Anotação __full"
  - "Anotação __in"
  - "Anotação __inout"
  - "Anotação __nz"
  - "Anotação __opt"
  - "Anotação __out"
  - "Anotação __part"
  - "Anotação __ref"
  - "Anotação __z"
  - "Anotação _bcount"
  - "_CA_SHOULD_CHECK_RETURN"
  - "Anotação _deref"
  - "Anotação _deref_opt"
  - "Anotação _ecount"
  - "Anotação _full"
  - "Anotação _in"
  - "Anotação _inout"
  - "Anotação _nz"
  - "Anotação _opt"
  - "Anotação _out"
  - "Anotação _part"
  - "Anotação _ref"
  - "Anotação _z"
  - "Anotações [C++]"
  - "Anotação bcount"
  - "Anotação deref"
  - "Anotação deref_opt"
  - "Anotação ecount"
  - "Anotação completa"
  - "em anotação"
  - "Anotação inout"
  - "Anotação nz"
  - "Anotação opt"
  - "Anotação out"
  - "Anotação part"
  - "Anotação ref"
  - "anotações de SAL"
  - "anotações de SAL, _CA_SHOULD_CHECK_RETURN"
  - "Anotação z"
ms.assetid: 81893638-010c-41a0-9cb3-666fe360f3e0
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Anota&#231;&#245;es de SAL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você examinar os arquivos de cabeçalho de biblioteca, você pode observar algumas anotações incomuns, por exemplo, `_In_z` e `_Out_z_cap_(_Size)`.  Estes são exemplos de linguagem de anotação a Microsoft código\-fonte \(SAL\), que fornece um conjunto de anotações para descrever como uma função usa seus parâmetros, por exemplo, as suposições faz sobre eles e as garantias faz em Concluir.  O arquivo de cabeçalho \< sal \> define as anotações.  
  
 Para obter mais informações sobre como usar as anotações SAL [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)], consulte [Usando anotações de SAL para reduzir defeitos de código do C\/C\+\+](../Topic/Using%20SAL%20Annotations%20to%20Reduce%20C-C++%20Code%20Defects.md).  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)