---
title: Erro das Ferramentas de Vinculador LNK2017
ms.date: 11/04/2016
f1_keywords:
- LNK2017
helpviewer_keywords:
- LNK2017
ms.assetid: f7c21733-b0fb-4888-a295-9b453ba6ee77
ms.openlocfilehash: ce5332c2812740ef0b8c7d8e9c64a095d20a4e2b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62299049"
---
# <a name="linker-tools-error-lnk2017"></a>Erro das Ferramentas de Vinculador LNK2017

realocação de 'symbol' para 'segmento' inválida sem /LARGEADDRESSAWARE: no

Você está tentando criar uma imagem de 64 bits com endereços de 32 bits. Para fazer isso, faça o seguinte:

- Use um endereço de carga fixa.

- Restringir a imagem para 3 GB.

- Especificar [/LARGEADDRESSAWARE: no](../../build/reference/largeaddressaware-handle-large-addresses.md).