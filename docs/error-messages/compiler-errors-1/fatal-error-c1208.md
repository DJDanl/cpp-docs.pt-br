---
title: Erro fatal C1208 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1208
dev_langs:
- C++
helpviewer_keywords:
- C1208
ms.assetid: 4eefd8f0-5c2e-4a11-9e63-293e1139db65
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab70449232c7177a555700b96d4965c617692e1a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46023560"
---
# <a name="fatal-error-c1208"></a>Erro fatal C1208

Não há suporte para alocar classes de referência na pilha pela versão do tempo de execução instalado

C1208 ocorre quando você tem um compilador para a versão atual, mas um common language runtime de uma versão anterior.

Algumas funcionalidades do compilador podem não funcionar em uma versão anterior do tempo de execução.

Instale a versão common language runtime que é destinado para uso com o compilador.