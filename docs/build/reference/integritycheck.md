---
title: /INTEGRITYCHECK
ms.date: 12/28/2017
f1_keywords:
- /INTEGRITYCHECK
helpviewer_keywords:
- -INTEGRITYCHECK editbin options
- /INTEGRITYCHECK editbin options
- INTEGRITYCHECK editbin options
ms.openlocfilehash: 4174e22dcdadb3b3319998614285c13741fe3a88
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814233"
---
# <a name="integritycheck"></a>/INTEGRITYCHECK

Especifica que a assinatura digital da imagem binária deve ser verificada em tempo de carregamento.

> **/INTEGRITYCHECK**[**: NENHUMA**]

## <a name="remarks"></a>Comentários

No cabeçalho do arquivo DLL ou arquivo executável, essa opção define um sinalizador que requer uma verificação de assinatura digital pelo Gerenciador de memória para carregar a imagem no Windows. Versões do Windows anteriores ao Windows Vista ignoram este sinalizador. Essa opção deve ser definida para DLLs de 64 bits que implementam o código do modo kernel e são recomendadas para todos os drivers de dispositivo. Para obter mais informações, consulte [requisitos de assinatura de código de modo Kernel](/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-).

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
