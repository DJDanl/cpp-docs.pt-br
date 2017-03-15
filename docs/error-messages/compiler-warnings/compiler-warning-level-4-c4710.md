---
title: "Compilador aviso (nível 4) C4710 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4710
dev_langs:
- C++
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f72293adf411fb35873dbadd24631f2ec342f667
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4710"></a>Compilador C4710 de aviso (nível 4)
'function': função não embutida  
  
 A função fornecida foi selecionada para a expansão embutida, mas o compilador não executou o inlining.  
  
 Embutir é executada a critério do compilador. O **embutido** palavra-chave, como o **registrar** palavra-chave é usada como uma dica para o compilador. O compilador usa heurística para determinar se deveria embutir uma função específica para acelerar o código durante a compilação de velocidade, ou se ele deve embutir uma função específica para diminuir o código durante a compilação para o espaço. O compilador criará somente embutido muito pequenas funções durante a compilação de espaço.  
  
 Em alguns casos, o compilador criará não embutir uma função específica por motivos mecânicos. Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos que o compilador pode embutir uma função.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
