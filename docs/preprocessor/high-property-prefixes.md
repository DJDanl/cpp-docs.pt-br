---
title: atributo de importação de high_property_prefixes
ms.date: 08/29/2019
f1_keywords:
- high_property_prefixes
helpviewer_keywords:
- high_property_prefixes attribute
ms.assetid: 91c6cc2b-19b6-4aba-8831-d9e5cccb58b5
ms.openlocfilehash: 9e44f6f1afae479f803f4c6d866ef3ee38744561
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219005"
---
# <a name="high_property_prefixes-import-attribute"></a>atributo de importação de high_property_prefixes

**C++Determinados**

Especifica prefixos alternativos para três métodos da propriedade.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **high_property_prefixes (** "*getprefix*" **,** "*PutPrefix*" **,** "*PutRefPrefix*" **)**

### <a name="parameters"></a>Parâmetros

*Getprefix*\
Prefixo a ser usado para os `propget` métodos.

*PutPrefix*\
Prefixo a ser usado para os `propput` métodos.

*PutRefPrefix*\
Prefixo a ser usado para os `propputref` métodos.

## <a name="remarks"></a>Comentários

Por padrão, `propget`o tratamento de erros de alto nível, `propput`e `propputref` os métodos são `Get`expostos por funções de membro nomeadas com `Put`prefixos, e `PutRef`, respectivamente.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
