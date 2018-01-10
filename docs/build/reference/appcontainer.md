---
title: -APPCONTAINER | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /APPCONTAINER
dev_langs: C++
helpviewer_keywords:
- APPCONTAINER editbin option
- -APPCONTAINER editbin option
- /APPCONTAINER editbin option
ms.assetid: 0ca4f1ec-c8de-4a37-b3e2-deda7af0bb88
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 19e926cbfd1fc58e04c8370825dd83eacff05dfe
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="appcontainer"></a>/APPCONTAINER
Marca um executável que deve ser executado em um contêiner do aplicativo — por exemplo, um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] ou aplicativo Universal do Windows.  
  
```  
  
/APPCONTAINER[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Um executável que tem o **/APPCONTAINER** opção set só pode ser executado em um contêiner do aplicativo, que é o ambiente de isolamento do processo introduzido no Windows 8. Para [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] e aplicativos universais do Windows, essa opção deve ser definida.  
  
## <a name="see-also"></a>Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [O que é um aplicativo Universal do Windows?](http://go.microsoft.com/fwlink/p/?LinkID=522074)