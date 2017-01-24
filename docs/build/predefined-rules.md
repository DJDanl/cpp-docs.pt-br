---
title: "Regras predefinidas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "regras predefinidas"
  - "Programa NMAKE, regras predefinidas"
  - "regras predefinidas em NMAKE"
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras predefinidas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso predefinido das regras de inferência NMAKE\- forneceu macros de comando e das opções.  
  
|Regra|Comando|Padrão<br /><br /> ação|Lote<br /><br /> Regra|O nmake da plataforma executado|  
|-----------|-------------|---------------------|--------------------|-------------------------------------|  
|.asm.exe|$ \(AS\) AFLAGS $ \($\)\<|ml $\<|não|x86|  
|.asm.obj|$ \(AS\) $ \($\) AFLAGS \/c\<|$ ml \/c\<|sim|x86|  
|.asm.exe|$ \(AS\) AFLAGS $ \($\)\<|ml64 $\<|não|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|.asm.obj|$ \(AS\) $ \($\) AFLAGS \/c\<|$ ml64 \/c\<|sim|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|.c.exe|$ \(CC \($\) CFLAGS $\)\<|cl $\<|não|all|  
|.c.obj|$ \(CC \($\) CFLAGS \/c $\)\<|$ cl \/c\<|sim|all|  
|.cc.exe|$ \(CC \($\) CFLAGS $\)\<|cl $\<|não|all|  
|.cc.obj|$ \(CC \($\) CFLAGS \/c $\)\<|$ cl \/c\<|sim|all|  
|.cpp.exe|$ \(\) CPP $ \($\) CPPFLAGS\<|cl $\<|não|all|  
|.cpp.obj|$ \(\) CPP $ \($\) CPPFLAGS \/c\<|$ cl \/c\<|sim|all|  
|.cxx.exe|$ \(\) CXX $ \($\) CXXFLAGS\<|cl $\<|não|all|  
|.cxx.obj|$ \(\) CXX $ \($\) CXXFLAGS \/c\<|$ cl \/c\<|sim|all|  
|.rc.res|$ \(RC \($\) RFLAGS \/r $\)\<|rc $ \/r\<|não|all|  
  
## Consulte também  
 [Regras de inferência](../build/inference-rules.md)