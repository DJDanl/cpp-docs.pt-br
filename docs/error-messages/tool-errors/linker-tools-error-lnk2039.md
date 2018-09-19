---
title: Erro das LNK2039 das ferramentas de vinculador | Microsoft Docs
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
ms.openlocfilehash: ac4fdde90911427a1a193bfb6f3a950a7bdcf180
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081787"
---
# <a name="linker-tools-error-lnk2039"></a>Erro das Ferramentas de Vinculador LNK2039

importando ref class\<tipo >' que está definido em another.obj; ele deve ser importada ou definida, mas não ambos

A classe ref ' <`type`>' é importado no arquivo. obj especificado, mas também é definido em outro arquivo. obj. Essa condição pode causar falha de tempo de execução ou outro comportamento inesperado.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se '`type`' deve ser definido no arquivo. obj e verifique se ele deve ser importado do arquivo. winmd.

1. Remova a definição ou a importação.

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)<br/>
[Erro das ferramentas de vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)