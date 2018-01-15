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
ms.workload: cplusplus
ms.openlocfilehash: c0761acfe02b7d86f9316d06913de15347e9d522
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="image-format"></a>Formato de imagem
O formato de imagem executável é PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes para que endereçamento relativo com um deslocamento de 32 bits pode ser usado para tratar dados de imagem estática. Esses dados incluem a tabela de importação de endereço, constantes de cadeia de caracteres, estáticos dados globais e assim por diante.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)