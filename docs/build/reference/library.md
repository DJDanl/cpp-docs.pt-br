---
title: BIBLIOTECA | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LIBRARY
dev_langs:
- C++
helpviewer_keywords:
- LIBRARY .def file statement
ms.assetid: 1d7ccc92-e088-4ef7-9ef0-25c3862cc051
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 71637c83eda0ee641a4b66d94ba113162baa7bf2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="library"></a>LIBRARY
Informa o LINK para criar uma DLL. Ao mesmo tempo, o LINK cria uma biblioteca de importação, a menos que um arquivo. EXP é usado na compilação.  
  
```  
LIBRARY [library][BASE=address]  
```  
  
## <a name="remarks"></a>Comentários  
 O *biblioteca* argumento especifica o nome da DLL. Você também pode usar o [/out](../../build/reference/out-output-file-name.md) opção de vinculador para especificar o nome de saída da DLL.  
  
 A BASE =*endereço* argumento define o endereço base que o sistema operacional usa para carregar a DLL. Esse argumento substitui o local de DLL padrão do 0x10000000. Consulte a descrição do [/BASE](../../build/reference/base-base-address.md) opção para obter detalhes sobre os endereços de base.  
  
 Lembre-se de usar o [/DLL](../../build/reference/dll-build-a-dll.md) opção de vinculador quando você cria uma DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)