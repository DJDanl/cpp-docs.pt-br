---
title: Erro das LNK1164 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1164
dev_langs:
- C++
helpviewer_keywords:
- LNK1164
ms.assetid: da89765c-affa-4f88-b170-6d6b19a577cf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b07dcf360a58b07b84abe655641b758d6137d0e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087417"
---
# <a name="linker-tools-error-lnk1164"></a>Erro das Ferramentas de Vinculador LNK1164

alinhamento de seção de seção (número) maior que valor /ALIGN

O tamanho de alinhamento da seção específica no arquivo de objeto excede o valor especificado com o [/ALINHAR](../../build/reference/align-section-alignment.md) opção. O **/ALINHAR** valor deve ser uma potência de 2 e deve ser igual ou exceder o alinhamento de seção fornecido no arquivo de objeto.

A recompilação com um menor alinhamento de seção ou aumentar o **/ALINHAR** valor.