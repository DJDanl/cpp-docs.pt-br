---
title: Aviso LNK4104 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4104
dev_langs:
- C++
helpviewer_keywords:
- LNK4104
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
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
ms.openlocfilehash: d2eebc34c34c3748fae78f615a163430b1c2ac22
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4104"></a>Aviso LNK4104 (Ferramentas de Vinculador)
exportação do símbolo 'symbol' deve ser PRIVADO  
  
 O `symbol` pode ser uma das seguintes opções:  
  
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
  
 Esse aviso é emitido quando você estiver criando uma biblioteca de importação para uma DLL e exportar uma das funções acima sem especificá-lo como particular no arquivo de definição de módulo. Em geral, essas funções são exportadas para uso somente pelo OLE. Colocá-los na biblioteca de importação pode levar a um comportamento incomum quando um programa vinculado incorretamente para a biblioteca faz chamadas para eles. Para obter mais informações sobre a palavra-chave PRIVADA, consulte [exportações](../../build/reference/exports.md).
