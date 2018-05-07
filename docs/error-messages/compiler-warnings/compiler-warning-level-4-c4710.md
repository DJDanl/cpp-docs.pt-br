---
title: Compilador (nível 4) de aviso C4710 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4710
dev_langs:
- C++
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c1cc77d8ee5393fe600ceadd9c1335d76e32efe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4710"></a>Compilador C4710 de aviso (nível 4)
'function': função não embutida  
  
 A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.  
  
 Inlining é executada a critério do compilador. O **embutido** palavra-chave, como o **registrar** palavra-chave é usada como uma dica para o compilador. O compilador usa heurística para determinar se deveria embutido uma função específica para acelerar o código durante a compilação para a velocidade ou se deveria embutido uma função específica para diminuir o código durante a compilação de espaço. O compilador será apenas embutido muito pequenas funções durante a compilação de espaço.  
  
 Em alguns casos, o compilador será embutido não uma função específica por motivos mecânicos. Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos que o compilador pode embutido uma função.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.