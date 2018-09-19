---
title: Erro das LNK2008 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2008
dev_langs:
- C++
helpviewer_keywords:
- LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 18eda06e7f133ada4de1b7ec28ac21be205a71f7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086805"
---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008

O alvo da correção não está alinhado 'symbol_name'

LINK encontrado um alvo da correção em seu arquivo de objeto não foi devidamente alinhado.

Esse erro pode ser causado pelo alinhamento secton personalizado (#pragma, por exemplo, [pack](../../preprocessor/pack.md)), [alinhar](../../cpp/align-cpp.md) modificador, ou usando o código de linguagem assembly que modifica secton alinhamento.

Se seu código não usa nenhuma das opções acima, isso pode ser causado pelo compilador.