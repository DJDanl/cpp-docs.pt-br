---
title: Aviso LNK4098 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4098
dev_langs:
- C++
helpviewer_keywords:
- LNK4098
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8aadf25d968d6d457f891cab49a43591455b9d12
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4098"></a>Aviso LNK4098 (Ferramentas de Vinculador)
conflitos de 'library' defaultlib com o usam de outras bibliotecas; Use /NODEFAULTLIB: Library  
  
 Você está tentando se vincular com bibliotecas incompatíveis.  
  
> [!NOTE]
>  Agora, as bibliotecas de tempo de execução contém diretivas para evitar misturar tipos diferentes. Você receberá esse aviso se você tentar usar tipos diferentes ou depurar e versões de depuração não da biblioteca de tempo de execução no mesmo programa. Por exemplo, se você compilou um arquivo para usar uma biblioteca de tipo de tempo de execução e outro arquivo para usar outro tipo (por exemplo, single-threaded versus multithread) e tentaram vinculá-los, você receberá esse aviso. Você deve compilar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução. Consulte o [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md) (**/MD**, **/MT**, **/LD**) opções do compilador para obter mais informações.  
  
 Você pode usar o vinculador [/verbose: lib](../../build/reference/verbose-print-progress-messages.md) switch para determinar quais bibliotecas o vinculador está procurando. Se você receber LNK4098 e desejar criar um arquivo executável que usa, por exemplo, o thread único, bibliotecas de tempo de execução sem depuração, use o **/verbose: lib** opção para descobrir o que está procurando o vinculador de bibliotecas. O vinculador deve imprimir LIBC.lib e não LIBCMT.lib, MSVCRT.lib, LIBCD.lib, LIBCMTD.lib ou MSVCRTD.lib como as bibliotecas pesquisadas. Você pode informar o vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.  
  
 A tabela a seguir mostra quais bibliotecas devem ser ignoradas dependendo de qual biblioteca de tempo de execução você deseja usar.  
  
|Para usar essa biblioteca de tempo de execução|Ignorar essas bibliotecas|  
|-----------------------------------|----------------------------|  
|Single-threaded (libc.lib)|libcmt.lib, msvcrt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|Multithread (libcmt.lib)|libc.lib, msvcrt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|Multithread usando DLL (msvcrt.lib)|libc.lib, libcmt.lib, libcd.lib, libcmtd.lib, msvcrtd.lib|  
|Depurar Single-threaded (libcd.lib)|libc.lib, libcmt.lib, msvcrt.lib, libcmtd.lib, msvcrtd.lib|  
|Depuração com multithread (libcmtd.lib)|libc.lib, libcmt.lib, msvcrt.lib, libcd.lib, msvcrtd.lib|  
|Depurar Multithreaded usando DLL (msvcrtd.lib)|libc.lib, libcmt.lib, msvcrt.lib, libcd.lib, libcmtd.lib|  
  
 Por exemplo, se você recebeu esse aviso e você deseja criar um arquivo executável que usa a versão de não-debug, single-threaded das bibliotecas de tempo de execução, você pode usar as seguintes opções com o vinculador:  
  
```  
/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib  
```