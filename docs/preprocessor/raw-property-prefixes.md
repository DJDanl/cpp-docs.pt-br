---
title: atributo de importação de raw_property_prefixes
ms.date: 08/29/2019
f1_keywords:
- raw_property_prefixes
helpviewer_keywords:
- raw_property_prefixes attribute
ms.assetid: 03a0f48c-c460-4175-a762-9f7f8d84b12f
ms.openlocfilehash: d4d91470781e7c5f673fd228c24904322d1db8b3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216044"
---
# <a name="raw_property_prefixes-import-attribute"></a>atributo de importação de raw_property_prefixes

**C++Determinados**

Especifica prefixos alternativos para três métodos da propriedade.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **raw_property_prefixes (** "*getprefix*" **,** "*PutPrefix*" **,** "*PutRefPrefix*" **)**

### <a name="parameters"></a>Parâmetros

*Getprefix*\
Prefixo a ser usado para `propget` os métodos.

*PutPrefix*\
Prefixo a ser usado para `propput` os métodos.

*PutRefPrefix*\
Prefixo a ser usado para `propputref` os métodos.

## <a name="remarks"></a>Comentários

Por padrão, os métodos de `propget`nível `propput`baixo, `propputref` e são expostos por funções de membro chamadas usando prefixos `put_`de `get_`, `putref_`e, respectivamente. Esses prefixos são compatíveis com os nomes usados nos arquivos de cabeçalho gerados pelo MIDL.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
