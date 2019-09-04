---
title: atributo de importação de no_registry
ms.date: 08/29/2019
f1_keywords:
- no_registry
helpviewer_keywords:
- no_registry attribute
ms.assetid: d30de4e2-551c-428c-98fd-951330d578d3
ms.openlocfilehash: 7c81cc2f570cb9ac4e977dac6d55cb69e491d3b2
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220717"
---
# <a name="no_registry-import-attribute"></a>atributo de importação de no_registry

**no_registry** informa o compilador para não Pesquisar o registro em busca de bibliotecas de `#import`tipos importadas com o.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_registry**

### <a name="parameters"></a>Parâmetros

*biblioteca de tipos*\
Uma biblioteca de tipos.

## <a name="remarks"></a>Comentários

Se uma biblioteca de tipos referenciada não for encontrada nos diretórios de inclusão, a compilação falhará mesmo que a biblioteca de tipos esteja no registro.  o **no_registry** se propaga para outras bibliotecas de tipos importadas implicitamente com `auto_search`o.

O compilador nunca pesquisa o registro em busca de bibliotecas de tipos que são especificadas por nome de arquivo `#import`e passadas diretamente para.

Quando `auto_search` é especificado, as diretivas `#import` adicionais são geradas usando a configuração **no_registry** do inicial `#import`. Se a diretiva `#import` inicial era **no_registry**, um `auto_search`-generated `#import` também é **no_registry**.

**no_registry** será útil se você quiser importar bibliotecas de tipo de referência cruzada. Ele impede que o compilador localize uma versão mais antiga do arquivo no registro. **no_registry** também será útil se a biblioteca de tipos não estiver registrada.

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
