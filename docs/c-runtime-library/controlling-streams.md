---
title: Controlando fluxos
ms.date: 11/04/2016
f1_keywords:
- Controlling Streams
helpviewer_keywords:
- streams, controlling
- controlling streams
- streams
ms.assetid: 267e9013-9afc-45f6-91e3-ca093230d9d9
ms.openlocfilehash: 85c7e1b22519287fbd03d89487d6639f197a8b63
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57743318"
---
# <a name="controlling-streams"></a>Controlando fluxos

[fopen](../c-runtime-library/reference/fopen-wfopen.md) retorna o endereço de um objeto do tipo `FILE`. Use esse endereço como o argumento `stream` em várias funções de biblioteca para executar diversas operações em um arquivo aberto. Para um fluxo de bytes, todas as entradas ocorrem como se cada caractere fosse lido chamando [fgetc](../c-runtime-library/reference/fgetc-fgetwc.md), e todas as saídas ocorrem como se cada caractere fosse gravado chamando [fputc](../c-runtime-library/reference/fputc-fputwc.md). Para um fluxo largo, todas as entradas ocorrem como se cada caractere fosse lido chamando [fgetc](../c-runtime-library/reference/fgetc-fgetwc.md), e todas as saídas ocorrem como se cada caractere fosse gravado chamando [fputc](../c-runtime-library/reference/fputc-fputwc.md).

Você pode fechar um arquivo chamando [fclose](../c-runtime-library/reference/fclose-fcloseall.md), após o qual o endereço do objeto `FILE` fica inválido.

Um objeto `FILE` armazena o estado de um fluxo, incluindo:

- Um indicador de erro definido para diferente de zero por uma função que encontra um erro de leitura ou gravação.

- Um indicador de final de arquivo definido para diferente de zero por uma função que encontra o final do arquivo durante a leitura.

- Um indicador de posição de arquivo especifica o próximo byte no fluxo para leitura ou gravação, se o arquivo oferecer suporte a solicitações de posicionamento.

- Um [estado de fluxo](../c-runtime-library/stream-states.md) especifica se o fluxo aceita leituras e/ou gravações e se é não associado, orientado a byte a ou orientado a largura.

- Um estado de conversão lembra o estado de qualquer caractere multibyte generalizado parcialmente montado ou gerado, bem como qualquer estado de deslocamento para a sequência de bytes do arquivo).

- Um buffer de arquivo especifica o endereço e o tamanho de um objeto de matriz que as funções de biblioteca podem usar para melhorar o desempenho de operações de leitura e gravação no fluxo.

Não altere os valores armazenados em um objeto `FILE` ou buffer de arquivo que você especificar para uso com esse objeto. Não é possível copiar um objeto `FILE` e usar o endereço da cópia de forma portátil como `stream` argumento para uma função de biblioteca.

## <a name="see-also"></a>Consulte também

[Arquivos e fluxos](../c-runtime-library/files-and-streams.md)
