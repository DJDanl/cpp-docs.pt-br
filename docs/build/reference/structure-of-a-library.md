---
title: Estrutura de uma biblioteca | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- libraries, structure
ms.assetid: a5fda8e8-4a1b-4499-9095-0df935262ce4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 03c2c66d45ee415ddc4f3ba27b6a100c5e2ec1dc
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45702098"
---
# <a name="structure-of-a-library"></a>Estrutura de uma biblioteca

Uma biblioteca contém objetos COFF. Os objetos em uma biblioteca contêm funções e os dados que podem ser referenciados externamente por outros objetos em um programa. Um objeto em uma biblioteca, às vezes é chamado de um membro da biblioteca.

Você pode obter informações adicionais sobre o conteúdo de uma biblioteca, executando a ferramenta DUMPBIN com a opção /LINKERMEMBER. Para obter mais informações sobre essa opção, consulte [referência de DUMPBIN](../../build/reference/dumpbin-reference.md).

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](../../build/reference/overview-of-lib.md)