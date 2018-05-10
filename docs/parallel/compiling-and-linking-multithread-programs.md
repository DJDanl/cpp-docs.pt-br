---
title: Compilando e vinculando programas Multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- compiling multithreaded programs
- multithreading [C++], linking programs
- threading [C++], linking programs
- multithreading [C++], compiled programs
- threading [C++], compiled programs
- compiling source code [C++], multithread programs
- linking [C++], multithread programs
ms.assetid: 27589afc-daf2-4f26-b868-a99de5c9dfec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c77cb217fe841e15f4c7470340bd3fbb502f6a9
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="compiling-and-linking-multithread-programs"></a>Compilando e vinculando programas multithread
O programa Bounce.c foi introduzido no [do programa C Multithread exemplo](../parallel/sample-multithread-c-program.md).  
  
 Programas compilados multithread por padrão.  
  
#### <a name="to-compile-and-link-the-multithread-program-bouncec-from-within-the-development-environment"></a>Compilar e vincular o programa multithread Bounce.c do ambiente de desenvolvimento  
  
1.  No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.  
  
2.  No **tipos de projeto** painel, clique em **Win32**.  
  
3.  No **modelos** painel, clique em **aplicativo do Console Win32**e, em seguida, nomeie o projeto.  
  
4.  Adicione o arquivo que contém o código-fonte C para o projeto.  
  
5.  No **criar** menu compilar o projeto clicando o **criar** comando.  
  
#### <a name="to-compile-and-link-the-multithread-program-bouncec-from-the-command-line"></a>Compilar e vincular o programa multithread Bounce.c da linha de comando  
  
1.  Compilar e vincular o programa:  
  
    ```  
    CL BOUNCE.C  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)