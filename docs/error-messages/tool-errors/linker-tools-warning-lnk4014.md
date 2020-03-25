---
title: Aviso LNK4014 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4014
helpviewer_keywords:
- LNK4014
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
ms.openlocfilehash: 5de53abc2342e3ed743f6b4abb871e05606dfc37
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194272"
---
# <a name="linker-tools-warning-lnk4014"></a>Aviso LNK4014 (Ferramentas de Vinculador)

Não é possível localizar o objeto de membro "ObjectName"

LIB não pôde localizar `objectname` na biblioteca.

As opções **/Remove** e **/Extract** exigem o nome completo do objeto de membro que será excluído ou copiado em um arquivo. O nome completo inclui o caminho do arquivo de objeto original. Para ver os nomes completos dos objetos membro em uma biblioteca, Use DUMPBIN [/ARCHIVEMEMBERS](../../build/reference/archivemembers.md) ou lib [/list](../../build/reference/managing-a-library.md).
