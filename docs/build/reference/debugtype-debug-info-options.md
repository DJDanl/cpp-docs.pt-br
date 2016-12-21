---
title: "/DEBUGTYPE (op&#231;&#245;es de informa&#231;&#245;es de depura&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/debugtype"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DEBUGTYPE"
  - "Opção de vinculador DEBUGTYPE"
  - "Opção de vinculador -DEBUGTYPE"
ms.assetid: 1ddcb718-7fec-4f92-a319-3f70f04fe742
caps.latest.revision: 2
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DEBUGTYPE (op&#231;&#245;es de informa&#231;&#245;es de depura&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A opção \/DEBUGTYPE Especifica os tipos de informações de depuração gerado pela opção \/DEBUG.  
  
```  
/DEBUGTYPE:[CV | PDATA | FIXUP]  
```  
  
## Argumentos  
 VC  
 Informe ao vinculador para emitir informações de depuração para símbolos, números de linha e outras informações de compilação do objeto no arquivo PDB.  Por padrão, essa opção é habilitada quando **\/DEBUG** for especificado e **\/DEBUGTYPE** não for especificado.  
  
 PDATA  
 Informe ao vinculador para adicionar entradas pData e. XData para as informações de fluxo de depuração no arquivo PDB.  Por padrão, essa opção é habilitada quando tanto o **\/DEBUG** e **\/DRIVER** Opções são especificadas.  Se **\/DEBUGTYPE:PDATA** for especificado, o vinculador inclui automaticamente os símbolos no arquivo PDB de depuração.  Se **\/DEBUGTYPE:PDATA,FIXUP** for especificado, o vinculador não inclue símbolos no arquivo PDB de depuração.  
  
 CORREÇÃO  
 Informe ao vinculador para adicionar entradas de tabela de realocação para as informações de fluxo de depuração no arquivo PDB.  Por padrão, essa opção é habilitada quando tanto o **\/DEBUG** e **\/PROFILE** Opções são especificadas.  Se **\/DEBUGTYPE:FIXUP** ou **\/DEBUGTYPE:FIXUP,PDATA** for especificado, o vinculador não inclue símbolos no arquivo PDB de depuração.  
  
 Argumentos para **\/DEBUGTYPE** podem ser combinados em qualquer ordem, separando\-os com uma vírgula.  O **\/DEBUGTYPE** opção e seus argumentos não diferenciam maiúsculas de minúsculas.  
  
## Comentários  
 Use o **\/DEBUGTYPE** opção para especificar a inclusão de informações de cabeçalho realocação tabela dados ou pData e. XData no fluxo de depuração.  Isso faz com que o vinculador a incluir informações sobre o código de modo de usuário que é visível em um depurador de kernel quando significativas no código do modo kernel.  Para disponibilizar os símbolos de depuração quando **FIXUP** for especificado, inclua o **CV** argumento.  
  
 Para depurar o código no modo de usuário, que é comum para aplicativos, o **\/DEBUGTYPE** opção não é necessária.  Por padrão, as opções de compilador que especificam a depuração de saída \([\/Z7, \/Zi, \/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)\) emite todas as informações necessárias pelo Visual Studio do depurador.  Use **\/DEBUGTYPE:PDATA** ou **\/DEBUGTYPE:CV,PDATA,FIXUP** para depurar o código que combina os componentes do modo de usuário e modo kernel, como um aplicativo de configuração para um driver de dispositivo.  Para obter mais informações sobre os depuradores de modo kernel, consulte [Debugging Tools for Windows \(WinDbg, KD, CDB, NTSD\)](http://go.microsoft.com/fwlink/p?LinkID=285651)  
  
## Consulte também  
 [\/DEBUG \(gerar informações de depuração\)](../../build/reference/debug-generate-debug-info.md)   
 [\/DRIVER \(driver de modo Kernel do Windows NT\)](../../build/reference/driver-windows-nt-kernel-mode-driver.md)   
 [\/PROFILE \(criador de perfil das ferramentas de desempenho\)](../../build/reference/profile-performance-tools-profiler.md)   
 [Ferramentas de depuração para Windows \(WinDbg, KD, CDB, NTSD\)](http://go.microsoft.com/fwlink/p?LinkID=285651)