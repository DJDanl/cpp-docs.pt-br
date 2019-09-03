---
title: atributo de importação de raw_interfaces_only
ms.date: 08/29/2019
f1_keywords:
- raw_interfaces_only
helpviewer_keywords:
- raw_interfaces_only attribute
ms.assetid: 87056c6d-3f34-4248-af58-f5775a35bfb7
ms.openlocfilehash: 4b79aa4dbafa204d84f4d6ed7ec78fdec1b81fa7
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216210"
---
# <a name="raw_interfaces_only-import-attribute"></a>atributo de importação de raw_interfaces_only

**C++Determinados**

Suprime a geração de funções de wrapper de tratamento de erros e declarações de [Propriedade](../cpp/property-cpp.md) que usam essas funções de wrapper.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **raw_interfaces_only**

## <a name="remarks"></a>Comentários

O atributo **raw_interfaces_only** também causa o prefixo padrão usado ao nomear as funções que não são de propriedade a serem removidas. Normalmente, o prefixo é `raw_`. Se esse atributo for especificado, os nomes de função serão obtidos diretamente da biblioteca de tipos.

Esse atributo permite que você exiba somente o conteúdo de nível baixo da biblioteca de tipos.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
