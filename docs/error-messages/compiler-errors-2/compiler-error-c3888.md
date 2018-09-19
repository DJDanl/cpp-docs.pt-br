---
title: Erro do compilador C3888 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3888
dev_langs:
- C++
helpviewer_keywords:
- C3888
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b9292f54fee467a5f8d01202b6ed7ca991b52d43
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46096451"
---
# <a name="compiler-error-c3888"></a>Erro do compilador C3888

'name': a expressão const associada a este membro de dados literal não é suportada pelo C + + / CLI

O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se o membro de dados literal declarado é um tipo com suporte.

## <a name="see-also"></a>Consulte também

[literal](../../windows/literal-cpp-component-extensions.md)