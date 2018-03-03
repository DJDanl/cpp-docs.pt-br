---
title: "-DEBUGTYPE (opções de informações de depuração) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /debugtype
dev_langs:
- C++
helpviewer_keywords:
- /DEBUGTYPE linker option
- DEBUGTYPE linker option
- -DEBUGTYPE linker option
ms.assetid: 1ddcb718-7fec-4f92-a319-3f70f04fe742
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7c069caca9831b841c3cb4be347331b58f538ba6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="debugtype-debug-info-options"></a>/DEBUGTYPE (opções de informações de depuração)
A opção /DEBUGTYPE Especifica os tipos de informações de depuração geradas pela opção /DEBUG.  
  
```  
/DEBUGTYPE:[CV | PDATA | FIXUP]  
```  
  
## <a name="arguments"></a>Arguments  
 VC  
 Informa o vinculador para emitir informações de depuração para símbolos, números de linha e outras informações de compilação do objeto no arquivo PDB. Por padrão, essa opção é habilitada quando **/Debug** for especificado e **/DEBUGTYPE** não for especificado.  
  
 PDATA  
 Informa o vinculador para adicionar entradas. pData e .xdata para as informações de fluxo de depuração no arquivo PDB. Por padrão, essa opção é habilitada quando tanto o **/Debug** e **/DRIVER** opções são especificadas. Se **/DEBUGTYPE:PDATA** especificado por si só, o vinculador inclui automaticamente os símbolos no arquivo PDB de depuração. Se **/DEBUGTYPE:PDATA, correção** for especificado, o vinculador não inclui símbolos no arquivo PDB de depuração.  
  
 CORREÇÃO  
 Informa o vinculador para adicionar entradas de tabela de realocação para as informações de fluxo de depuração no arquivo PDB. Por padrão, essa opção é habilitada quando tanto o **/Debug** e **/Profile** opções são especificadas. Se **/DEBUGTYPE:FIXUP** ou **/DEBUGTYPE:FIXUP, PDATA** for especificado, o vinculador não inclui símbolos no arquivo PDB de depuração.  
  
 Argumentos para **/DEBUGTYPE** podem ser combinadas em qualquer ordem, separando-os com uma vírgula. O **/DEBUGTYPE** opção e seus argumentos não diferenciam maiusculas de minúsculas.  
  
## <a name="remarks"></a>Comentários  
 Use o **/DEBUGTYPE** opção para especificar a inclusão de informações de cabeçalho realocação tabela .xdata ou. pData e dados no fluxo de depuração. Isso faz com que o vinculador incluir informações sobre o código de modo de usuário que é visível em um depurador de kernel quando recentes no código do modo kernel. Para disponibilizar os símbolos de depuração quando **correção** é especificado, inclua o **VC** argumento.  
  
 Para depurar o código no modo de usuário, que é típico para aplicativos, o **/DEBUGTYPE** opção não é necessária. Por padrão, as opções de compilador que especificam a depuração de saída ([/Z7, /Zi, /ZI](../../build/reference/z7-zi-zi-debug-information-format.md)) emite todas as informações necessárias pelo Visual Studio do depurador. Use **/DEBUGTYPE:PDATA** ou **/debugtype: CV, PDATA, correção** para depurar o código que combina os componentes do modo de usuário e o modo de kernel, como um aplicativo de configuração para um driver de dispositivo. Para obter mais informações sobre os depuradores de modo kernel, consulte [ferramentas de depuração para Windows (WinDbg, KD, CDBS, NTSD)](http://go.microsoft.com/fwlink/p?LinkID=285651)  
  
## <a name="see-also"></a>Consulte também  
 [/Debug (gerar informações de depuração)](../../build/reference/debug-generate-debug-info.md)   
 [/ DRIVER (Driver de modo de Kernel do Windows NT)](../../build/reference/driver-windows-nt-kernel-mode-driver.md)   
 [/Profile (criador de perfil de ferramentas de desempenho)](../../build/reference/profile-performance-tools-profiler.md)   
 [Ferramentas de depuração para Windows (WinDbg, KD, CDBS, NTSD)](http://go.microsoft.com/fwlink/p?LinkID=285651)