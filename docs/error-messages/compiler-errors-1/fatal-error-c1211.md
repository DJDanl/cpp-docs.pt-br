---
title: Erro fatal C1211 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1211
dev_langs:
- C++
helpviewer_keywords:
- C1211
ms.assetid: df0ca70d-ec6e-4400-926a-b877e2599978
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 444d2bc25c2eddd5ea9a0170272bd3e71b61f94f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46018516"
---
# <a name="fatal-error-c1211"></a>Erro fatal C1211

Não há suporte para o atributo personalizado TypeForwardedTo pela versão do tempo de execução instalado

C1211 ocorre quando você tem um compilador para a versão atual, mas um common language runtime de uma versão anterior.

Algumas funcionalidades do compilador podem não funcionar em uma versão anterior do tempo de execução.

Para resolver C1211 instalar o common language runtime que acompanham o compilador você está usando.

Para obter mais informações, consulte [encaminhamento de tipo (C + + / CLI)](../../windows/type-forwarding-cpp-cli.md).