---
title: /INTEGRITYCHECK | Microsoft Docs
ms.custom: 
ms.date: 12/28/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 99caec18162a7506b8b7a467eb7374b6fe4a38d9
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="integritycheck"></a>/INTEGRITYCHECK

Especifica que a assinatura digital da imagem binária deve ser verificada em tempo de carregamento.

> **/INTEGRITYCHECK**[**: NENHUM**]

## <a name="remarks"></a>Comentários

No cabeçalho do arquivo DLL ou arquivo executável, esta opção define um sinalizador que requer uma verificação de assinatura digital pelo Gerenciador de memória ao carregar a imagem do Windows. Versões do Windows anterior ao Windows Vista ignoram esse sinalizador. Essa opção deve ser definida para DLLs de 64 bits que implementem o código de modo kernel e são recomendados para todos os drivers de dispositivo. Para obter mais informações, consulte [requisitos de assinatura de código de modo Kernel](/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-).

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)  
