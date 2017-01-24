---
title: "Controlando fluxos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "Controlling Streams"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "controlando fluxos"
  - "fluxos"
  - "fluxos, controlando"
ms.assetid: 267e9013-9afc-45f6-91e3-ca093230d9d9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Controlando fluxos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[fopen](../c-runtime-library/reference/fopen-wfopen.md) retorna o endereço de um objeto de tipo `FILE`.  Você usa esse endereço como o argumento de `stream` a várias funções da biblioteca para executar várias operações em um arquivo aberto.  Para um fluxo de bytes, qualquer entrada ocorre como se cada caractere é lido chamando [fgetc](../Topic/fgetc,%20fgetwc.md), e todas as saídas ocorrem como se cada caractere é gravado chamando [fputc](../c-runtime-library/reference/fputc-fputwc.md).  Para um fluxo todo o servidor, qualquer entrada ocorre como se cada caractere é lido chamando [fgetwc](../Topic/fgetc,%20fgetwc.md), e todas as saídas ocorrem como se cada caractere é gravado chamando [fputwc](../c-runtime-library/reference/fputc-fputwc.md).  
  
 Você pode fechar um arquivo chamando [fclose](../c-runtime-library/reference/fclose-fcloseall.md), depois da qual o endereço do objeto de `FILE` não é válido.  
  
 Um objeto de `FILE` armazena o estado de um fluxo, incluindo:  
  
-   Um conjunto de indicadores de erro diferente de zero por uma função que encontrar um erro de leitura ou gravação.  
  
-   Um conjunto de indicadores de participante de Arquivo diferente de zero por uma função que atenda ao final do arquivo para leitura.  
  
-   Um indicador de arquivo posição especifica o byte seguir no fluxo para ler ou gravar, se o arquivo pode dar suporte a solicitações de posicionamento.  
  
-   [estado de fluxo](../Topic/Stream%20States.md) especifica se o fluxo aceitará leitura e\/ou gravações e se o fluxo será não associadas, orientado por byte, ou orientado a largura.  
  
-   Um estado de conversão registros o estado de caractere generalizado parcialmente montado ou gerado alguns multibyte, bem como qualquer estado do turno para a sequência de bytes no arquivo\).  
  
-   Um buffer de arquivo especifica o endereço e o tamanho de um objeto da matriz que as funções da biblioteca podem usar para melhorar o desempenho de leitura e as operações de gravação no fluxo.  
  
 Não altere nenhum valor armazenado em um objeto de `FILE` ou em um buffer do arquivo que você especifica para uso com aquele objeto.  Você não pode copiar um objeto de `FILE` e portably usar o endereço de cópia como um argumento de `stream` a uma função de biblioteca.  
  
## Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)