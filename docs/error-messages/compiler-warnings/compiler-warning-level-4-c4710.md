---
title: "Compilador (nível 4) de aviso C4710 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4710
dev_langs: C++
helpviewer_keywords: C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f1008d8ab97119ff7fbe828d58ca5b2d4e4f8101
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4710"></a>Compilador C4710 de aviso (nível 4)
'function': função não embutida  
  
 A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.  
  
 Inlining é executada a critério do compilador. O **embutido** palavra-chave, como o **registrar** palavra-chave é usada como uma dica para o compilador. O compilador usa heurística para determinar se deveria embutido uma função específica para acelerar o código durante a compilação para a velocidade ou se deveria embutido uma função específica para diminuir o código durante a compilação de espaço. O compilador será apenas embutido muito pequenas funções durante a compilação de espaço.  
  
 Em alguns casos, o compilador será embutido não uma função específica por motivos mecânicos. Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos que o compilador pode embutido uma função.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.