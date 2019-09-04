---
title: atributo de importação de raw_native_types
ms.date: 08/29/2019
f1_keywords:
- raw_native_types
helpviewer_keywords:
- raw_native_types attribute
ms.assetid: 9f38daa8-8dc0-46a5-aff9-f1ff9c1e6f48
ms.openlocfilehash: eb08a8e7cb081bd7a470c3c1ecf1492a7a65f833
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216064"
---
# <a name="raw_native_types-import-attribute"></a>atributo de importação de raw_native_types

**C++Determinados**

Desabilita o uso de classes de suporte COM em funções de wrapper de alto nível e força o uso de tipos de dados de nível baixo em vez disso.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **raw_native_types**

## <a name="remarks"></a>Comentários

Por padrão, os métodos de tratamento de erros de alto nível usam as classes de suporte com [_bstr_t](../cpp/bstr-t-class.md) e [_variant_t](../cpp/variant-t-class.md) no `BSTR` lugar `VARIANT` dos tipos de dados e ponteiros de interface com brutos. Essas classes encapsulam os detalhes da alocação e da desalocação do armazenamento de memória para esses tipos de dados e simplificam significativamente as operações de conversão e de conversão de tipos.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
