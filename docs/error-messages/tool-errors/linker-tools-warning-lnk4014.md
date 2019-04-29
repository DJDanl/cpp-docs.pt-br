---
title: Aviso LNK4014 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4014
helpviewer_keywords:
- LNK4014
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
ms.openlocfilehash: f67990ed74f500f1b954edcf1d6437f64f93f0d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298601"
---
# <a name="linker-tools-warning-lnk4014"></a>Aviso LNK4014 (Ferramentas de Vinculador)

não é possível localizar o objeto de membro "objectname"

Não foi possível encontrar LIB `objectname` na biblioteca.

O **/remover** e **/extract** opções exigem o nome completo do objeto membro que deve ser excluído ou copiados para um arquivo. O nome completo inclui o caminho do arquivo original do objeto. Para ver os nomes completos de objetos de membro em uma biblioteca, use DUMPBIN [/ARCHIVEMEMBERS](../../build/reference/archivemembers.md) ou LIB [/lista](../../build/reference/managing-a-library.md).