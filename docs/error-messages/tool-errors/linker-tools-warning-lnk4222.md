---
title: Aviso LNK4222 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4222
dev_langs:
- C++
helpviewer_keywords:
- LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
caps.latest.revision: 8
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
ms.openlocfilehash: 0948dc9de4d6b2c83e408b563e437f16b68f2fa4
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4222"></a>Aviso LNK4222 (Ferramentas de Vinculador)
símbolo exportado 'symbol' não deve ser atribuído um ordinal  
  
 Os símbolos a seguir não devem ser exportados por ordinal:  
  
-   `DllCanUnloadNow`  
  
-   `DllGetClassObject`  
  
-   `DllGetClassFactoryFromClassString`  
  
-   `DllInstall`  
  
-   `DllRegisterServer`  
  
-   `DllRegisterServerEx`  
  
-   `DllUnregisterServer`  
  
 Essas funções são sempre localizadas por nome, usando `GetProcAddress`. O vinculador avisa sobre esse tipo de exportação é porque isso poderia resultar em uma imagem maior. Isso pode ocorrer se o intervalo de suas exportações ordinais é grande com relativamente poucas exportações. Por exemplo,  
  
```  
EXPORTS  
   DllGetClassObject   @1  
   MyOtherAPI      @100  
```  
  
 requer 100 slots na tabela de endereço de exportação 98 deles preenchimento apenas (2-99). Por outro lado  
  
```  
EXPORTS  
   DllGetClassObject  
   MyOtherAPI      @100  
```  
  
 requer dois slots. (Lembre-se de que você também pode exportar com a [/exportar](../../build/reference/export-exports-a-function.md) opção de vinculador.)
