---
title: Erro das Ferramentas de Vinculador LNK1241
ms.date: 11/04/2016
f1_keywords:
- LNK1241
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
ms.openlocfilehash: 87f73680d7ed40b9b2db9f40f9140976d552ab6b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160647"
---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241

arquivo de recurso 'arquivo de recurso' já especificado

Esse erro é gerado se você executar **cvtres** manualmente a partir da linha de comando e se você passar o obj resultantes de arquivos para o vinculador além para outros arquivos. res.

Para especificar vários arquivos. res, passá-los todos para o vinculador como arquivos. res, não de dentro arquivos. obj criado por **cvtres**.