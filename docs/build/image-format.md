---
title: Formato de imagem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 3ca3654b-42fe-4253-9f2e-723644041aa0
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5cc70468d5b3ce9f678c1cd563ac79f172cedcc8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="image-format"></a>Formato de imagem
O formato de imagem executável é PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes para que endereçamento relativo com um deslocamento de 32 bits pode ser usado para tratar dados de imagem estática. Esses dados incluem a tabela de importação de endereço, constantes de cadeia de caracteres, estáticos dados globais e assim por diante.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)