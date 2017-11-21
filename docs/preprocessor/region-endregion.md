---
title: "região, endregion | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.endregion
- endregion_CPP
- region_CPP
- vc-pragma.region
dev_langs: C++
helpviewer_keywords:
- pragmas, region
- pragmas, endregion
- endregion pragma
- region pragma
ms.assetid: c697f807-622f-4796-851b-68a42bbecd84
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0c807e4c6c6850182e913b5a1bba394d33ad2cc3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="region-endregion"></a>region, endregion
**região #pragma** permite que você especifique um bloco de código que você pode expandir ou recolher ao usar o [recurso de estrutura de tópicos](/visualstudio/ide/outlining) do Editor de código do Visual Studio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma region name  
#pragma endregion comment  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `comment`(opcional)  
 Um comentário será exibido no editor de códigos.  
  
 *nome*(opcional)  
 O nome da região.  Esse nome será exibido no editor de códigos.  
  
## <a name="remarks"></a>Comentários  
 **endregion #pragma** marca o fim de um **#pragma região** bloco.  
  
 Um `#region` bloco deve ser terminado com **#pragma endregion**.  
  
## <a name="example"></a>Exemplo  
  
```  
// pragma_directives_region.cpp  
#pragma region Region_1  
void Test() {}  
void Test2() {}  
void Test3() {}  
#pragma endregion Region_1  
  
int main() {}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)