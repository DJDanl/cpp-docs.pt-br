---
title: Propriedades da etapa de build personalizada (Linux C++) | Microsoft Docs
ms.custom: 
ms.date: 10/17/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 77a9c1fb-7c41-4a9b-9418-18ac17ce4e74
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: ae749fa161dba2957f3e621ce42c610153594e66
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="custom-build-step-properties-linux-c"></a>Propriedades da etapa de build personalizada (Linux C++)

propriedade | Descrição
--- | ---
Linha de Comando | O comando a ser executado pela etapa de compilação personalizada.
Descrição | Uma mensagem que será exibida quando a etapa de compilação personalizada for executada.
Saídas | O arquivo de saída gerado pela etapa de compilação personalizada. Essa configuração é necessária para que as compilações incrementais funcionem corretamente.
Dependências adicionais | Uma lista delimitada por ponto-e-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada.
Executar depois e executar antes | Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados. Os destinos mais comumente listados são BuildGenerateSources, BuildCompile e BuildLink, porque representam as etapas principais no processo de compilação. Outros destinos frequentemente listados são Midl, CLCompile e Link.
Tratar saída como conteúdo | Essa opção só é significativa para aplicativos da Windows Store ou do Windows Phone, que incluem todos os arquivos de conteúdo no pacote .appx.