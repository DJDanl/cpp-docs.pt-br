---
title: BIBLIOTECA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- LIBRARY
dev_langs:
- C++
helpviewer_keywords:
- LIBRARY .def file statement
ms.assetid: 1d7ccc92-e088-4ef7-9ef0-25c3862cc051
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d2fb7e69b0557bf96601666c390b3d59412b5a0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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