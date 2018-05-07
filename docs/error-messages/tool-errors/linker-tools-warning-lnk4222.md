---
title: Aviso LNK4222 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4222
dev_langs:
- C++
helpviewer_keywords:
- LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 359af4c4d3b1079b2d56f108bff0ee1488ea71f9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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