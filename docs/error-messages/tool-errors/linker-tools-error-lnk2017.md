---
title: Erro das Ferramentas de Vinculador LNK2017
ms.date: 11/04/2016
f1_keywords:
- LNK2017
helpviewer_keywords:
- LNK2017
ms.assetid: f7c21733-b0fb-4888-a295-9b453ba6ee77
ms.openlocfilehash: 02e80de5c34809a331003f3b0fb28d32e138a531
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194727"
---
# <a name="linker-tools-error-lnk2017"></a>Erro das Ferramentas de Vinculador LNK2017

realocação de ' Symbol ' para ' Segment ' inválida sem/LARGEADDRESSAWARE: NO

Você está tentando criar uma imagem de 64 bits com endereços de 32 bits. Para fazer isso, você deve:

- Use um endereço de carga fixo.

- Restrinja a imagem a 3 GB.

- Especifique [/LARGEADDRESSAWARE: no](../../build/reference/largeaddressaware-handle-large-addresses.md).
