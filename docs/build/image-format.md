---
title: Formato de imagem
ms.date: 11/04/2016
ms.assetid: 3ca3654b-42fe-4253-9f2e-723644041aa0
ms.openlocfilehash: 71456af35960114ab64b076ebb9c0f9102613744
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509935"
---
# <a name="image-format"></a>Formato de imagem

O formato de imagem executável é PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes, para que o endereçamento relativo com um deslocamento de 32 bits pode ser usado para tratar dados de imagem estática. Esses dados incluem a tabela de endereços de importação, constantes de cadeia de caracteres, os dados globais estáticos e assim por diante.

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)