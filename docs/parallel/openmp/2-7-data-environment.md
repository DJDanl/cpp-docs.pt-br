---
title: 2.7 Ambiente de dados
ms.date: 11/04/2016
ms.assetid: 74e44b3c-e18c-4773-8e78-cd6c4413ae57
ms.openlocfilehash: b65dfc7d7694b36ef4f89351579cd73e07ab537c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491957"
---
# <a name="27-data-environment"></a>2.7 Ambiente de dados

Esta seção apresenta uma diretiva e várias cláusulas para controlar o ambiente de dados durante a execução de regiões em paralelo, da seguinte maneira:

- Um **threadprivate** diretiva (consulte a seção a seguir) é fornecida para tornar o escopo de arquivo, escopo de namespace ou variáveis estáticas de escopo de bloco local para um thread.

- As cláusulas que podem ser especificadas em que as diretivas para controlar os atributos de compartilhamento de variáveis para a duração das construções paralelas ou compartilhamento de trabalho são descritas em [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.