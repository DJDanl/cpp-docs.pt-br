---
title: exclude (#import)
ms.date: 10/18/2018
f1_keywords:
- exclude
helpviewer_keywords:
- exclude attribute
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
ms.openlocfilehash: d6a320089d5954b2cf1d0d96ae1f37656f2ddd58
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389314"
---
# <a name="exclude-import"></a>Excluir (\#importar)

**Específico do C++**

Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.

## <a name="syntax"></a>Sintaxe

```
exclude("Name1"[, "Name2",...])
```

### <a name="parameters"></a>Parâmetros

*Name1*<br/>
O primeiro item a ser excluído.

*Name2*<br/>
O segundo item a ser excluído (se necessário).

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. Esse atributo pode usar qualquer número de argumentos, cada um sendo um item da biblioteca de tipos de nível superior a ser excluído.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)