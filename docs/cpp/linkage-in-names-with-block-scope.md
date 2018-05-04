---
title: Ligação em nomes com escopo de bloco | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- scope [C++], linkage rules
- linkage [C++], scope linkage rules
- names [C++], scope linkage rules
- block scope [C++]
- external linkage, scope linkage rules
ms.assetid: 73efa91a-f761-47f7-bbd9-9f9e3508e218
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ab7758e962c028c4746836e470ee43eaab510f9e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="linkage-in-names-with-block-scope"></a>Ligação em nomes com escopo de bloco
As regras de vinculação a seguir se aplicam aos nomes com escopo de bloco (nomes locais):  
  
-   Nomes declarados como `extern` possuir vínculo externo, a menos que eles foram declarados anteriormente como **estático**.  
  
-   Todos os outros nomes com escopo de bloco não tem nenhuma vinculação.  
  
## <a name="see-also"></a>Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)