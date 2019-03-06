---
title: Extraindo um membro da biblioteca
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- LIB [C++], extracting library members
- EXTRACT library manager option
- libraries, extracting members
- -EXTRACT library manager option
- extracting library members
- /EXTRACT library manager option
ms.assetid: a2c5c2a1-9b7e-489a-a9a4-1dec694e1fc5
ms.openlocfilehash: 4d7629707d99130551401fdda39a972ab2447480
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412881"
---
# <a name="extracting-a-library-member"></a>Extraindo um membro da biblioteca

Você pode usar LIB para criar um arquivo de objeto (. obj) que contém uma cópia de um membro de uma biblioteca existente. Para extrair uma cópia de um membro, use a seguinte sintaxe:

```
LIB library /EXTRACT:member /OUT:objectfile
```

Este comando cria um arquivo. obj chamado *objectfile* que contém uma cópia de um `member` de uma *biblioteca*. O `member` nome diferencia maiusculas de minúsculas. Você pode extrair somente um membro em um único comando. A opção /out sobrescreve é necessária; Não há nenhum nome de saída padrão. Se um arquivo chamado *objectfile* já existe no diretório especificado (ou o diretório atual, se nenhum diretório for especificado com *objectfile*), extraída *objectfile*substitui o arquivo existente.

## <a name="see-also"></a>Consulte também

[Referência de LIB](../../build/reference/lib-reference.md)
