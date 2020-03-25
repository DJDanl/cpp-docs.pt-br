---
title: Erro das Ferramentas de Vinculador LNK1241
ms.date: 11/04/2016
f1_keywords:
- LNK1241
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
ms.openlocfilehash: 6e2b955787166c94be4ca35e1c58df5becd243f2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183807"
---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241

arquivo de recurso ' arquivo de recurso ' já especificado

Esse erro será gerado se você executar o **CVTRES** manualmente na linha de comando e, em seguida, passar o arquivo. obj resultante para o vinculador, além de outros arquivos. res.

Para especificar vários arquivos. res, passe-os para o vinculador como arquivos. res, não de dentro dos arquivos. obj criados por **CVTRES**.
