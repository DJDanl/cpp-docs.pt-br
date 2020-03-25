---
title: Aviso BK4504 (BSCMAKE)
ms.date: 11/04/2016
f1_keywords:
- BK4504
helpviewer_keywords:
- BK4504
ms.assetid: b56ee2d4-ad44-40f4-98c0-75934ea44a6c
ms.openlocfilehash: 57858827439ac8cc11e3718d7a484124ae8a6d74
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197438"
---
# <a name="bscmake-warning-bk4504"></a>Aviso BK4504 (BSCMAKE)

o arquivo contém muitas referências; ignorando referências adicionais desta fonte

O arquivo. cpp contém mais de 64.000 referências de símbolo. Quando BSCMAKE encontrou 64.000 referências em um arquivo, ele ignora todas as referências adicionais.

Para corrigir o problema, divida o arquivo em dois ou mais arquivos, cada um com menos de 64.000 referências de símbolo ou use a diretiva de pré-processador de `#pragma component(browser)` para limitar os símbolos que são gerados para referências específicas. Para obter mais informações, consulte [componente](../../preprocessor/component.md).
