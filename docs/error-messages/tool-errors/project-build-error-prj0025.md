---
title: Erro de Build prj0025 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0025
dev_langs:
- C++
helpviewer_keywords:
- PRJ0025
ms.assetid: 57725c78-bc63-44f3-9667-2969b2d7c41d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 949e36424fc213459e56332c0802d2719581bac1
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209806"
---
# <a name="project-build-error-prj0025"></a>Erro de Build PRJ0025 no Projeto

> Arquivo em lotes '*arquivo*' contém conteúdo Unicode que não pôde ser convertido na página de código ANSI do usuário.
>
> *Conteúdo UNICODE do arquivo*

O sistema de projeto encontrado conteúdo Unicode em um personalizado regra de compilação ou criar um evento que não pode ser convertido corretamente na página de código ANSI atual do usuário.

A resolução para esse erro é atualizar o conteúdo da regra de compilação ou evento para usar o ANSI ou para instalar a página de código em seu computador e defini-lo como o padrão do sistema de compilação.

Para obter mais informações sobre personalizado etapas de build e eventos de build, consulte [Noções básicas sobre etapas de compilação personalizadas e eventos de Build](../../ide/understanding-custom-build-steps-and-build-events.md).