---
title: Unicode e MBCS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- _mbcs
dev_langs:
- C++
helpviewer_keywords:
- MBCS [C++], Unicode
- MFC [C++], character sets
- character sets [C++], multibyte
- run-time libraries [C++], language portability
- character sets [C++], Unicode
- Unicode [C++], MFC and C run-time functions
- multibyte characters [C++]
- runtime [C++], language portability
ms.assetid: 677baec6-71b4-4579-94df-64f18bc117c4
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2e10c07e11cbe940b5f7cfee460ddd33f6f5ff1f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="unicode-and-mbcs"></a>Unicode e MBCS
A biblioteca Microsoft Foundation Classes (MFC), a biblioteca de tempo de execução C para o Visual C++ e o ambiente de desenvolvimento do Visual C++ são habilitados para ajudar sua programação internacional. Eles fornecem:  
  
-   O suporte ao padrão Unicode no Windows. Unicode é o padrão atual e deve ser usado sempre que possível.  
  
     Unicode é um caractere de 16 bits de codificação, fornecendo suficiente codificações para todos os idiomas. Todos os caracteres ASCII são incluídos em Unicode como caracteres largo.  
  
-   Suporte a um formulário de conjunto de caracteres multibyte (MBCS) chamado conjunto de caracteres de dois bytes (DBCS) em todas as plataformas.  
  
     Caracteres DBCS são compostos de 1 ou 2 bytes. Alguns intervalos de bytes são reservou para uso como bytes de cliente potencial. Um byte inicial Especifica que ele e o byte seguinte de trilha compõem um único caractere de byte-todo o 2. Você deve manter controle das quais bytes são lead bytes. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando esses intervalos se sobrepõem, pode ser necessário avaliar o contexto para determinar se um determinado byte está funcionando como um byte inicial ou um byte final.  
  
-   Suporte para as ferramentas que simplificam a programação MBCS de aplicativos criados para mercados internacionais.  
  
     Quando executado em uma versão habilitada MBCS do sistema operacional Windows, o sistema de desenvolvimento do Visual C++, incluindo o editor de código fonte integrado, depurador e ferramentas de linha de comando — é habilitada completamente MBCS. Para obter mais informações, consulte [suporte de MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md).  
  
> [!NOTE]
>  Nesta documentação, MBCS é usado para descrever todo o suporte não Unicode em caracteres multibyte. No Visual C++, MBCS sempre significa DBCS. Conjuntos de caracteres maior que 2 bytes não são suportados.  
  
 Por definição, o conjunto de caracteres ASCII é um subconjunto de todos os conjuntos de caracteres multibyte. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, em cadeias de caracteres ASCII e MBCS, de 1 byte **nulo** caractere ('\0') tem valor 0x00 e indica o caractere null de terminação.  
  
## <a name="see-also"></a>Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Habilitação internacional](../text/international-enabling.md)