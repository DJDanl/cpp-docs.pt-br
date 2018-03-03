---
title: Ferramentas de vinculador LNK2039 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2039
dev_langs:
- C++
helpviewer_keywords:
- LNK2039
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 441765d85ce65a80102ed94b3f4394ae48c0e29f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2039"></a>Erro das Ferramentas de Vinculador LNK2039
importando ref class\<tipo >' que é definido no another.obj; ele deve ser importada ou definida, mas não ambos  
  
 A classe ref ' <`type`>' foi importada para o arquivo. obj especificado, mas também está definido em outro arquivo. obj. Essa condição pode causar falha de tempo de execução ou outro comportamento inesperado.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se '`type`' deve ser definido em outro arquivo. obj e verifique se ele deve ser importado do arquivo. winmd.  
  
2.  Remova a definição ou a importação.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)   
 [Erro das ferramentas de vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)