---
title: "região, endregion | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.endregion
- endregion_CPP
- region_CPP
- vc-pragma.region
dev_langs:
- C++
helpviewer_keywords:
- pragmas, region
- pragmas, endregion
- endregion pragma
- region pragma
ms.assetid: c697f807-622f-4796-851b-68a42bbecd84
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1fda2aba5fdb0aa83066c1762822bfce5fc5f6b4
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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