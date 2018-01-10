---
title: Controlando fluxos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Controlling Streams
dev_langs: C++
helpviewer_keywords:
- streams, controlling
- controlling streams
- streams
ms.assetid: 267e9013-9afc-45f6-91e3-ca093230d9d9
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3d6b2678add561eda41a7426a840b9c4ad074301
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="controlling-streams"></a>Controlando fluxos
[fopen](../c-runtime-library/reference/fopen-wfopen.md) retorna o endereço de um objeto do tipo `FILE`. Use esse endereço como o argumento `stream` em várias funções de biblioteca para executar diversas operações em um arquivo aberto. Para um fluxo de bytes, todas as entradas ocorrem como se cada caractere fosse lido chamando [fgetc](../c-runtime-library/reference/fgetc-fgetwc.md), e todas as saídas ocorrem como se cada caractere fosse gravado chamando [fputc](../c-runtime-library/reference/fputc-fputwc.md). Para um fluxo largo, todas as entradas ocorrem como se cada caractere fosse lido chamando [fgetc](../c-runtime-library/reference/fgetc-fgetwc.md), e todas as saídas ocorrem como se cada caractere fosse gravado chamando [fputc](../c-runtime-library/reference/fputc-fputwc.md).  
  
 Você pode fechar um arquivo chamando [fclose](../c-runtime-library/reference/fclose-fcloseall.md), após o qual o endereço do objeto `FILE` fica inválido.  
  
 Um objeto `FILE` armazena o estado de um fluxo, incluindo:  
  
-   Um indicador de erro definido para diferente de zero por uma função que encontra um erro de leitura ou gravação.  
  
-   Um indicador de final de arquivo definido para diferente de zero por uma função que encontra o final do arquivo durante a leitura.  
  
-   Um indicador de posição de arquivo especifica o próximo byte no fluxo para leitura ou gravação, se o arquivo oferecer suporte a solicitações de posicionamento.  
  
-   Um [estado de fluxo](../c-runtime-library/stream-states.md) especifica se o fluxo aceita leituras e/ou gravações e se é não associado, orientado a byte a ou orientado a largura.  
  
-   Um estado de conversão lembra o estado de qualquer caractere multibyte generalizado parcialmente montado ou gerado, bem como qualquer estado de deslocamento para a sequência de bytes do arquivo).  
  
-   Um buffer de arquivo especifica o endereço e o tamanho de um objeto de matriz que as funções de biblioteca podem usar para melhorar o desempenho de operações de leitura e gravação no fluxo.  
  
 Não altere os valores armazenados em um objeto `FILE` ou buffer de arquivo que você especificar para uso com esse objeto. Não é possível copiar um objeto `FILE` e usar o endereço da cópia de forma portátil como `stream` argumento para uma função de biblioteca.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)