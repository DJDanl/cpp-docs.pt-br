---
title: Propriedades da etapa de build personalizada (Linux C++)
ms.date: 10/17/2017
ms.assetid: 77a9c1fb-7c41-4a9b-9418-18ac17ce4e74
ms.openlocfilehash: 5e6580263e63547e3564eaee260158a312e5fa6a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644698"
---
# <a name="custom-build-step-properties-linux-c"></a>Propriedades da etapa de build personalizada (Linux C++)

Propriedade | Descrição
--- | ---
Linha de Comando | O comando a ser executado pela etapa de compilação personalizada.
Descrição | Uma mensagem que será exibida quando a etapa de compilação personalizada for executada.
Saídas | O arquivo de saída gerado pela etapa de compilação personalizada. Essa configuração é necessária para que as compilações incrementais funcionem corretamente.
Dependências adicionais | Uma lista delimitada por ponto-e-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada.
Executar depois e executar antes | Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados. Os destinos mais comumente listados são BuildGenerateSources, BuildCompile e BuildLink, porque representam as etapas principais no processo de compilação. Outros destinos frequentemente listados são Midl, CLCompile e Link.
Tratar saída como conteúdo | Essa opção apenas é significativa para aplicativos da Microsoft Store ou do Windows Phone, que incluem todos os arquivos de conteúdo no pacote .appx.