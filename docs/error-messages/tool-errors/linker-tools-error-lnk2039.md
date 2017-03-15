---
title: Ferramentas de vinculador LNK2039 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2039
dev_langs:
- C++
helpviewer_keywords:
- LNK2039
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
caps.latest.revision: 4
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
ms.openlocfilehash: 4ba7ca8e0b8bbfb93b2148354fde839f99e8e6df
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2039"></a>Erro das Ferramentas de Vinculador LNK2039
Importar classes de ref\<tipo >' que é definido em another.obj; ele deve ser importado ou definido, mas não ambos  
  
 A classe ref`type`>' é importado no arquivo. obj especificado, mas também é definido em outro arquivo. obj. Essa condição pode causar falha de tempo de execução ou outro comportamento inesperado.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se '`type`' deve ser definido no arquivo. obj e verifique se ele deve ser importado do arquivo. winmd.  
  
2.  Remova a definição ou a importação.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)   
 [Erro das ferramentas de vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)
