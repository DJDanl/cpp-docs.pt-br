---
title: Erro das Ferramentas de Vinculador LNK2039
ms.date: 11/04/2016
f1_keywords:
- LNK2039
helpviewer_keywords:
- LNK2039
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
ms.openlocfilehash: 57d0c101358f84816c8d0cf96eb5137833df0b48
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59027526"
---
# <a name="linker-tools-error-lnk2039"></a>Erro das Ferramentas de Vinculador LNK2039

importando ref class\<tipo >' que está definido em another.obj; ele deve ser importada ou definida, mas não ambos

A classe ref ' <`type`>' é importado no arquivo. obj especificado, mas também é definido em outro arquivo. obj. Essa condição pode causar falha de tempo de execução ou outro comportamento inesperado.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se '`type`' deve ser definido no arquivo. obj e verifique se ele deve ser importado do arquivo. winmd.

1. Remova a definição ou a importação.

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)<br/>
[Erro das Ferramentas de Vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)