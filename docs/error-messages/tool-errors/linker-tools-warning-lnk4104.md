---
title: Aviso LNK4104 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4104
dev_langs:
- C++
helpviewer_keywords:
- LNK4104
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d9ea3e074cc0db9591cd0ffe9329ff7f1936563f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4104"></a>Aviso LNK4104 (Ferramentas de Vinculador)
exportação de símbolo 'symbol' deve ser PRIVATE  
  
 O `symbol` pode ser um dos seguintes:  
  
-   `DllCanUnloadNow`  
  
-   `DllGetClassObject`  
  
-   `DllGetClassFactoryFromClassString`  
  
-   `DllGetDocumentation`  
  
-   `DllInitialize`  
  
-   `DllInstall`  
  
-   `DllRegisterServer`  
  
-   `DllRegisterServerEx`  
  
-   `DllRegisterServerExW`  
  
-   `DllUnload`  
  
-   `DllUnregisterServer`  
  
-   `RasCustomDeleteEntryNotify`  
  
-   `RasCustomDial`  
  
-   `RasCustomDialDlg`  
  
-   `RasCustomEntryDlg`  
  
 Esse aviso é emitido quando você estiver criando uma biblioteca de importação para uma DLL e exportar uma das funções acima sem especificá-lo como particular no arquivo de definição de módulo. Em geral, essas funções são exportadas para uso somente pelo OLE. Colocando-as na biblioteca de importação pode resultar em comportamento incomum quando um programa vinculado à biblioteca incorretamente faz chamadas a eles. Para obter mais informações sobre a palavra-chave PRIVADA, consulte [exportações](../../build/reference/exports.md).