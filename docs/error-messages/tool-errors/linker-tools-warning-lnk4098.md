---
title: Aviso LNK4098 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4098
dev_langs:
- C++
helpviewer_keywords:
- LNK4098
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
caps.latest.revision: 9
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
ms.openlocfilehash: bb163d525e26d68ad8804fd118c51374dcc6b581
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4098"></a>Aviso LNK4098 (Ferramentas de Vinculador)
conflitos de 'library' defaultlib com o usam de outras bibliotecas; Use /NODEFAULTLIB:library  
  
 Você está tentando vincular com bibliotecas incompatíveis.  
  
> [!NOTE]
>  As bibliotecas de tempo de execução agora contêm diretivas para evitar misturar tipos diferentes. Você receberá esse aviso se você tentar usar tipos diferentes ou depurar e versões de depuração não da biblioteca de tempo de execução no mesmo programa. Por exemplo, se você compilou um arquivo para usar uma biblioteca de tipo de tempo de execução e outro arquivo para usar outro tipo (por exemplo, single-threaded versus multithread) e tentou vinculá-las, você receberá esse aviso. Você deve compilar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução. Consulte o [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md) (**/MD**, **/MT**, **/LD**) opções do compilador para obter mais informações.  
  
 Você pode usar o vinculador [/VERBOSE:LIB](../../build/reference/verbose-print-progress-messages.md) switch para determinar quais bibliotecas o vinculador está procurando. Se você receber LNK4098 e desejar criar um arquivo executável que usa, por exemplo, o thread único, não depuração bibliotecas de tempo de execução, use o **/VERBOSE:LIB** opção para descobrir quais bibliotecas o vinculador está procurando. O vinculador deve imprimir libc. lib e não libcmt, MSVCRT, LIBCD.lib, Libcmtd ou Msvcrtd como as bibliotecas de pesquisados. Você pode informar ao vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.  
  
 A tabela a seguir mostra quais bibliotecas devem ser ignoradas, dependendo de qual biblioteca de tempo de execução você deseja usar.  
  
|Para usar esta biblioteca de tempo de execução|Ignorar essas bibliotecas|  
|-----------------------------------|----------------------------|  
|Single-threaded (libc. lib)|libcmt, MSVCRT, libcd.lib, Libcmtd, Msvcrtd|  
|Multithreaded (libcmt)|libc. lib, MSVCRT, libcd.lib, Libcmtd, Msvcrtd|  
|Multithreaded usando DLL (Msvcrt)|libc. lib, libcmt, libcd.lib, Libcmtd, Msvcrtd|  
|Depurar Single-threaded (libcd.lib)|libc. lib, libcmt, MSVCRT, Libcmtd, Msvcrtd|  
|Depurar vários threads (Libcmtd)|libc. lib, libcmt, MSVCRT, libcd.lib, Msvcrtd|  
|Depurar Multithreaded usando DLL (Msvcrtd)|libc. lib, libcmt, MSVCRT, libcd.lib, Libcmtd|  
  
 Por exemplo, se você recebeu esse aviso e você deseja criar um arquivo executável que usa a versão não-debug, single-threaded das bibliotecas de tempo de execução, você pode usar as seguintes opções com o vinculador:  
  
```  
/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib  
```
