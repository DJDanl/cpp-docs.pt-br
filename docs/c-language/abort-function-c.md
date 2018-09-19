---
title: Função abort (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- abort function
ms.assetid: caa62d67-ffc4-4481-87a4-0c1e2b0f537c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7c6d83a597716ed86870cc11ef2f063edd34642b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081931"
---
# <a name="abort-function-c"></a>Função abort (C)

**ANSI 4.10.4.1** O comportamento da função **abort** em relação aos arquivos abertos e temporários

A função **abort** não fecha os arquivos que estão abertos ou são temporários. Ela não libera os buffers de fluxo.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)