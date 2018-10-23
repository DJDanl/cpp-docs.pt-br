---
title: Excluir (#import) | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- exclude
dev_langs:
- C++
helpviewer_keywords:
- exclude attribute
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c345d9268f63a714eeae4beff78a7ac39ce545a1
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49807894"
---
# <a name="exclude-import"></a>Excluir (\#importar)

**Específico do C++**

Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.

## <a name="syntax"></a>Sintaxe

```
exclude("Name1"[, "Name2",...])
```

### <a name="parameters"></a>Parâmetros

*Nome1*<br/>
O primeiro item a ser excluído.

*Nome2*<br/>
O segundo item a ser excluído (se necessário).

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. Esse atributo pode usar qualquer número de argumentos, cada um sendo um item da biblioteca de tipos de nível superior a ser excluído.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)