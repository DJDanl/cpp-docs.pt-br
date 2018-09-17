---
title: Extraindo um membro da biblioteca | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- Lib
dev_langs:
- C++
helpviewer_keywords:
- LIB [C++], extracting library members
- EXTRACT library manager option
- libraries, extracting members
- -EXTRACT library manager option
- extracting library members
- /EXTRACT library manager option
ms.assetid: a2c5c2a1-9b7e-489a-a9a4-1dec694e1fc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9207a77868b3257d09f0d9efe38e4765cb8f4906
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726512"
---
# <a name="extracting-a-library-member"></a>Extraindo um membro da biblioteca

Você pode usar LIB para criar um arquivo de objeto (. obj) que contém uma cópia de um membro de uma biblioteca existente. Para extrair uma cópia de um membro, use a seguinte sintaxe:

```
LIB library /EXTRACT:member /OUT:objectfile
```

Este comando cria um arquivo. obj chamado *objectfile* que contém uma cópia de um `member` de uma *biblioteca*. O `member` nome diferencia maiusculas de minúsculas. Você pode extrair somente um membro em um único comando. A opção /out sobrescreve é necessária; Não há nenhum nome de saída padrão. Se um arquivo chamado *objectfile* já existe no diretório especificado (ou o diretório atual, se nenhum diretório for especificado com *objectfile*), extraída *objectfile*substitui o arquivo existente.

## <a name="see-also"></a>Consulte também

[Referência de LIB](../../build/reference/lib-reference.md)