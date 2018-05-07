---
title: Ferramentas de vinculador LNK2039 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2039
dev_langs:
- C++
helpviewer_keywords:
- LNK2039
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 954ea12eb9b49c2bdf59b31a1ec2ec2e66c124ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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