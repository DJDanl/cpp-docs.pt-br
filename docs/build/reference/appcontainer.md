---
title: -APPCONTAINER | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /APPCONTAINER
dev_langs:
- C++
helpviewer_keywords:
- APPCONTAINER editbin option
- -APPCONTAINER editbin option
- /APPCONTAINER editbin option
ms.assetid: 0ca4f1ec-c8de-4a37-b3e2-deda7af0bb88
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 08966cd2b9da434c45750edb57644c182a14baf2
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="appcontainer"></a>/APPCONTAINER
Marca um executável que deve ser executado em um contêiner do aplicativo — por exemplo, um aplicativo Microsoft Store ou Universal do Windows.  
  
```  
  
/APPCONTAINER[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Um executável que tem o **/APPCONTAINER** opção set só pode ser executado em um contêiner do aplicativo, que é o ambiente de isolamento do processo introduzido no Windows 8. Para aplicativos da Microsoft Store e Universal do Windows, essa opção deve ser definida.  
  
## <a name="see-also"></a>Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [O que é um aplicativo Universal do Windows?](http://go.microsoft.com/fwlink/p/?LinkID=522074)