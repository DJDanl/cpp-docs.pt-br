---
title: . /SAFESEH | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .SAFESEH
dev_langs: C++
helpviewer_keywords:
- registering functions as exception handlers
- SAFESEH directive
- .SAFESEH directive
ms.assetid: 6eaac8c4-c46f-47ae-8a66-f5cfeb267e43
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 09a1848ce12eba4cf0ba08d0898e135d70e14fe1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safeseh"></a>.SAFESEH
Registra uma função como um manipulador de exceção estruturada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
.SAFESEH identifier  
```  
  
## <a name="remarks"></a>Comentários  
 *identificador* deve ser a identificação de definida localmente [PROC](../../assembler/masm/proc.md) ou [EXTRN](../../assembler/masm/extrn.md) PROC. Um [rótulo](../../assembler/masm/label-masm.md) não é permitido. A. Diretiva SAFESEH requer o [/safeseh](../../assembler/masm/ml-and-ml64-command-line-reference.md) ml.exe opção de linha de comando.  
  
 Para obter mais informações sobre manipuladores de exceção estruturada, consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md).  
  
 Por exemplo, para registrar um manipulador de exceção de segurança, crie um novo arquivo MASM (da seguinte maneira) montar com /safeseh e adicioná-lo para os objetos vinculados.  
  
```  
.386  
.model  flat  
MyHandler   proto  
.safeseh    MyHandler  
end  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)