---
title: atributo de importação de no_auto_exclude
ms.date: 08/29/2019
f1_keywords:
- no_auto_exclude
helpviewer_keywords:
- no_auto_exclude attribute
ms.assetid: 3241ef9c-758a-4e86-bdc5-37da6072430f
ms.openlocfilehash: 530c2b2adf24e964cb0a512371f4430a61bf8b11
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216083"
---
# <a name="no_auto_exclude-import-attribute"></a>atributo de importação de no_auto_exclude

**C++Determinados**

Desabilita a exclusão automática.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_auto_exclude**

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens. Isso faz com que a [C4192 de aviso do compilador (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md) seja emitida para cada item a ser excluído. Você pode desabilitar a exclusão automática usando este atributo.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
