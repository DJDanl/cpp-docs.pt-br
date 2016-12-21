---
title: "Aviso LNK4098 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4098"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4098"
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4098 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o defaultlib “biblioteca” entra em conflito com o uso de outros liberais; use \/NODEFAULTLIB:library  
  
 Você está tentando vincular a bibliotecas incompatíveis.  
  
> [!NOTE]
>  As bibliotecas de tempo de execução agora contêm políticas para evitar tipos diferentes de combinação.  Receberá este aviso se você tentar usar tipos diferentes ou os depuração e versões que não seja de depuração da biblioteca de tempo de execução no mesmo programa.  Por exemplo, se você criou um arquivo para usar um tipo da biblioteca de tempo de execução e de outro arquivo para usar outro tipo \(por exemplo, de thread único e de vários threads\) e o tentou o vincular, você obterá esse aviso.  Você deve criar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução.  Consulte as opções do compilador de [Use a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md) \(**\/MD**, **\/MT**, **\/LD**\) para obter mais informações.  
  
 Você pode usar a opção de [\/VERBOSE: LIB](../../build/reference/verbose-print-progress-messages.md) do vinculador para determinar quais bibliotecas o vinculador está pesquisando.  Se você receber LNK4098 e deseja criar um arquivo executável que usa, por exemplo, o de thread único, as bibliotecas de tempo de execução de não depuração, use a opção de **\/VERBOSE:LIB** descobrir quais as bibliotecas o vinculador estão procurando.  O vinculador deve LIBC.lib imprimir e não LIBCMT.lib, MSVCRT.lib, LIBCD.lib, LIBCMTD.lib, ou MSVCRTD.lib como as bibliotecas procurararam.  Você pode informar o vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [\/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.  
  
 A tabela a seguir mostra que as bibliotecas devem ser ignoradas dependendo da biblioteca de tempo de execução você deseja usar.  
  
|Para usar essa biblioteca de tempo de execução|Ignorar essas bibliotecas|  
|----------------------------------------------------|-------------------------------|  
|De thread único \(libc.lib\)|libcmt.lib, msvcrt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|Multithread \(libcmt.lib\)|libc.lib, msvcrt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|DLL do uso de vários threads \(msvcrt.lib\)|libc.lib, libcmt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|Depuração de thread único \(libcd.lib\)|libc.lib, libcmt.lib, msvcrt.lib, libcmtd.lib, msvcrtd.lib|  
|Depuração de vários threads \(libcmtd.lib\)|libc.lib, libcmt.lib, msvcrt.lib, libcd.lib, msvcrtd.lib|  
|DLL do uso de vários threads de depuração \(msvcrtd.lib\)|libc.lib, libcmt.lib, msvcrt.lib, libcd.lib, libcmtd.lib|  
  
 Por exemplo, se você recebeu esse aviso e você deseja criar um arquivo executável que usa a não depuração, versão de thread único das bibliotecas de tempo de execução, você pode usar as seguintes opções com o vinculador:  
  
```  
/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib  
```