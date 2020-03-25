---
title: Erro das Ferramentas de Vinculador LNK2039
ms.date: 11/04/2016
f1_keywords:
- LNK2039
helpviewer_keywords:
- LNK2039
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
ms.openlocfilehash: 7712747deb865ec62fa007fcd95ad09630d00cea
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194493"
---
# <a name="linker-tools-error-lnk2039"></a>Erro das Ferramentas de Vinculador LNK2039

importar a classe ref '\<Type > ' definida em outro. obj; Ele deve ser importado ou definido, mas não ambos

A classe ref ' <`type`> ' é importada no arquivo. obj especificado, mas também está definida em outro arquivo. obj. Essa condição pode causar falha de tempo de execução ou outro comportamento inesperado.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se '`type`' deve ser definido no outro arquivo. obj e verifique se ele deve ser importado do arquivo. winmd.

1. Remova a definição ou a importação.

## <a name="see-also"></a>Confira também

[Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)<br/>
[Erro das ferramentas de vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)
