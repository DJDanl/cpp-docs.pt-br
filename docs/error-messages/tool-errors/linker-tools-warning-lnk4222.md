---
title: Aviso LNK4222 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4222
dev_langs: C++
helpviewer_keywords: LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2a54c452a5df6f99260d6d01fbf4bb9f2f17b955
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4222"></a>Aviso LNK4222 (Ferramentas de Vinculador)
símbolo exportado 'symbol' não deve ser atribuído um ordinal  
  
 Os seguintes símbolos não devem ser exportados por ordinal:  
  
-   `DllCanUnloadNow`  
  
-   `DllGetClassObject`  
  
-   `DllGetClassFactoryFromClassString`  
  
-   `DllInstall`  
  
-   `DllRegisterServer`  
  
-   `DllRegisterServerEx`  
  
-   `DllUnregisterServer`  
  
 Essas funções sempre estão localizadas, por nome, usando `GetProcAddress`. O vinculador avisa sobre esse tipo de exportação é porque isso poderia resultar em uma imagem maior. Isso pode acontecer se o intervalo de suas exportações ordinais for grande, com poucas exportações. Por exemplo,  
  
```  
EXPORTS  
   DllGetClassObject   @1  
   MyOtherAPI      @100  
```  
  
 requer 100 slots na tabela de endereço de exportação com 98 deles preenchimento apenas (2-99). Por outro lado  
  
```  
EXPORTS  
   DllGetClassObject  
   MyOtherAPI      @100  
```  
  
 requer dois slots. (Lembre-se de que você também pode exportar com o [/exportação](../../build/reference/export-exports-a-function.md) opção de vinculador.)