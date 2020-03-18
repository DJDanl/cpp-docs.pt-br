---
title: Propriedades da etapa de build personalizada (Linux C++)
ms.date: 06/07/2019
ms.assetid: 77a9c1fb-7c41-4a9b-9418-18ac17ce4e74
ms.openlocfilehash: 67b281e245c4fff8f37baff8875cbc3dc84ca718
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441334"
---
# <a name="custom-build-step-properties-linux-c"></a>Propriedades da etapa de build personalizada (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

| Propriedade | Descrição |
|--|--|
| Linha de comando | O comando a ser executado pela etapa de compilação personalizada. |
| Descrição | Uma mensagem que será exibida quando a etapa de compilação personalizada for executada. |
| Saídas | O arquivo de saída gerado pela etapa de compilação personalizada. Essa configuração é necessária para que as compilações incrementais funcionem corretamente. |
| {1&gt;Dependências adicionais&lt;1} | Uma lista delimitada por ponto-e-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada. |
| Executar depois e executar antes | Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados. Os destinos mais comumente listados são BuildGenerateSources, BuildCompile e BuildLink, porque representam as etapas principais no processo de compilação. Outros destinos frequentemente listados são Midl, CLCompile e Link. |
| Tratar saída como conteúdo | Essa opção apenas é significativa para aplicativos da Microsoft Store ou do Windows Phone, que incluem todos os arquivos de conteúdo no pacote .appx. |

::: moniker-end
