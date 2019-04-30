---
title: Erro PRJ0025 (compilação de projeto)
ms.date: 08/27/2018
f1_keywords:
- PRJ0025
helpviewer_keywords:
- PRJ0025
ms.assetid: 57725c78-bc63-44f3-9667-2969b2d7c41d
ms.openlocfilehash: 5f3699dce75a20b9cc6e1d712bc5702543ab7b6c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383939"
---
# <a name="project-build-error-prj0025"></a>Erro PRJ0025 (compilação de projeto)

> Arquivo em lotes '*arquivo*' contém conteúdo Unicode que não pôde ser convertido na página de código ANSI do usuário.
>
> *Conteúdo UNICODE do arquivo*

O sistema de projeto encontrado conteúdo Unicode em um personalizado regra de compilação ou criar um evento que não pode ser convertido corretamente na página de código ANSI atual do usuário.

A resolução para esse erro é atualizar o conteúdo da regra de compilação ou evento para usar o ANSI ou para instalar a página de código em seu computador e defini-lo como o padrão do sistema de compilação.

Para obter mais informações sobre personalizado etapas de build e eventos de build, consulte [Noções básicas sobre etapas de compilação personalizadas e eventos de Build](../../build/understanding-custom-build-steps-and-build-events.md).