---
title: Erro do compilador C3888
ms.date: 11/04/2016
f1_keywords:
- C3888
helpviewer_keywords:
- C3888
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
ms.openlocfilehash: 40156dfaad5965d30a32d3aa2ac574a5f91999ba
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176398"
---
# <a name="compiler-error-c3888"></a>Erro do compilador C3888

' name ': a expressão const associada a este membro de dados literal não é suportada por C++/CLI

O membro de dados de *nome* declarado com a palavra-chave [literal](../../extensions/literal-cpp-component-extensions.md) é inicializado com um valor ao qual o compilador não oferece suporte. O compilador oferece suporte apenas a tipos de cadeia de caracteres, de enumeração ou integral constantes. A causa provável para o erro **C3888** é que o membro de dados é inicializado com uma matriz de bytes.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se o membro de dados literal declarado é um tipo com suporte.

## <a name="see-also"></a>Confira também

[literal](../../extensions/literal-cpp-component-extensions.md)
