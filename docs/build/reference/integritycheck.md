---
title: /INTEGRITYCHECK | Microsoft Docs
ms.custom: ''
ms.date: 12/28/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /INTEGRITYCHECK
dev_langs:
- C++
helpviewer_keywords:
- -INTEGRITYCHECK editbin options
- /INTEGRITYCHECK editbin options
- INTEGRITYCHECK editbin options
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b0adf9add2d191ae89aec0a5d756ade8e9f7725
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="integritycheck"></a>/INTEGRITYCHECK

Especifica que a assinatura digital da imagem binária deve ser verificada em tempo de carregamento.

> **/INTEGRITYCHECK**[**: NENHUM**]

## <a name="remarks"></a>Comentários

No cabeçalho do arquivo DLL ou arquivo executável, esta opção define um sinalizador que requer uma verificação de assinatura digital pelo Gerenciador de memória ao carregar a imagem do Windows. Versões do Windows anterior ao Windows Vista ignoram esse sinalizador. Essa opção deve ser definida para DLLs de 64 bits que implementem o código de modo kernel e são recomendados para todos os drivers de dispositivo. Para obter mais informações, consulte [requisitos de assinatura de código de modo Kernel](/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-).

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)  
