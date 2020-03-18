---
title: Extraindo um membro da biblioteca
ms.date: 11/04/2016
helpviewer_keywords:
- LIB [C++], extracting library members
- EXTRACT library manager option
- libraries, extracting members
- -EXTRACT library manager option
- extracting library members
- /EXTRACT library manager option
ms.assetid: a2c5c2a1-9b7e-489a-a9a4-1dec694e1fc5
ms.openlocfilehash: 874866627099eb5aeb318273db26a976e99bac7f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439872"
---
# <a name="extracting-a-library-member"></a>Extraindo um membro da biblioteca

Você pode usar a LIB para criar um arquivo de objeto (. obj) que contém uma cópia de um membro de uma biblioteca existente. Para extrair uma cópia de um membro, use a seguinte sintaxe:

```
LIB library /EXTRACT:member /OUT:objectfile
```

Esse comando cria um arquivo. obj chamado *objectfile* que contém uma cópia de um `member` de uma *biblioteca*. O nome do `member` diferencia maiúsculas de minúsculas. Você pode extrair apenas um membro em um único comando. A opção/OUT é necessária; Não há nenhum nome de saída padrão. Se um arquivo chamado *objectfile* já existir no diretório especificado (ou no diretório atual, se nenhum diretório for especificado com *objectfile*), o *objectfile* extraído substituirá o arquivo existente.

## <a name="see-also"></a>Consulte também

[Referência de LIB](lib-reference.md)
