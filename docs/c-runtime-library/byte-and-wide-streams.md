---
title: Fluxos de byte e largos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- Byte and Wide Streams
dev_langs:
- C++
helpviewer_keywords:
- byte streams
- wide streams
ms.assetid: 61ef0587-4cbc-4eb8-aae5-4c298dbbc6f9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: de026c8887e19e76bbce533db8997193679d1371
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32389878"
---
# <a name="byte-and-wide-streams"></a>Byte e fluxos largos
Um fluxo de bytes trata um arquivo como uma sequência de bytes. Dentro do programa, o fluxo é a sequência idêntica de bytes.  
  
 Por outro lado, um fluxo largo trata um arquivo como uma sequência de caracteres de vários bytes generalizados, que pode ter uma ampla gama de regras de codificação. (Arquivos de texto e binários ainda são lidos e gravados conforme descrito anteriormente.) Dentro do programa, o fluxo é semelhante à sequência de caracteres largos correspondente. Conversões entre as duas representações ocorrem dentro da biblioteca C padrão. As regras de conversão podem, em princípio, ser alteradas por uma chamada para [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md), que altera a categoria `LC_CTYPE`. Cada fluxo largo determina suas regras de conversão no momento em que se torna orientado à largura e mantém essas regras mesmo se a categoria `LC_CTYPE` mudar posteriormente.  
  
 O posicionamento em um fluxo largo sofre com as mesmas limitações que um fluxo de texto. Além disso, o indicador de posição do arquivo também pode precisar lidar com uma codificação dependente de estado. Normalmente, inclui deslocamento de byte dentro do fluxo e um objeto do tipo `mbstate_t`. Portanto, o único modo confiável de obter uma posição de arquivo em um fluxo largo é chamando [fgetpos](../c-runtime-library/reference/fgetpos.md); o único modo confiável para restaurar uma posição obtida dessa maneira é chamando [fsetpos](../c-runtime-library/reference/fsetpos.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)