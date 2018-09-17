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
ms.openlocfilehash: 062ce019fe1b622661be880d8a06eac9c5971103
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45709197"
---
# <a name="integritycheck"></a>/INTEGRITYCHECK

Especifica que a assinatura digital da imagem binária deve ser verificada em tempo de carregamento.

> **/INTEGRITYCHECK**[**: NENHUMA**]

## <a name="remarks"></a>Comentários

No cabeçalho do arquivo DLL ou arquivo executável, essa opção define um sinalizador que requer uma verificação de assinatura digital pelo Gerenciador de memória para carregar a imagem no Windows. Versões do Windows anteriores ao Windows Vista ignoram este sinalizador. Essa opção deve ser definida para DLLs de 64 bits que implementam o código do modo kernel e são recomendadas para todos os drivers de dispositivo. Para obter mais informações, consulte [requisitos de assinatura de código de modo Kernel](/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-).

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)
