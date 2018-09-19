---
title: Aviso de BSCMAKE BK4504 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK4504
dev_langs:
- C++
helpviewer_keywords:
- BK4504
ms.assetid: b56ee2d4-ad44-40f4-98c0-75934ea44a6c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c8a2da8903dade37faf3b14175b65f3169efd908
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46049756"
---
# <a name="bscmake-warning-bk4504"></a>Aviso BK4504 (BSCMAKE)

arquivo contém muitas referências; Ignorando referência posterior desta fonte

O arquivo. cpp contém mais de 64.000 referências de símbolo. Quando BSCMAKE encontrou 64.000 referências em um arquivo, ele ignora todas as referências adicionais.

Para corrigir o problema, em Dividir o arquivo em dois ou mais arquivos, cada um deles tem menos de 64.000 referências de símbolo, ou usarem o `#pragma component(browser)` diretiva de pré-processador para símbolos de limite que são gerados para referências específicas. Para obter mais informações, consulte [componente](../../preprocessor/component.md).