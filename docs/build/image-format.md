---
title: Formato de imagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 3ca3654b-42fe-4253-9f2e-723644041aa0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0e69d1a7c62d4e9c52cc628f30f94c346d83647f
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45715410"
---
# <a name="image-format"></a>Formato de imagem

O formato de imagem executável é PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes, para que o endereçamento relativo com um deslocamento de 32 bits pode ser usado para tratar dados de imagem estática. Esses dados incluem a tabela de endereços de importação, constantes de cadeia de caracteres, os dados globais estáticos e assim por diante.

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)