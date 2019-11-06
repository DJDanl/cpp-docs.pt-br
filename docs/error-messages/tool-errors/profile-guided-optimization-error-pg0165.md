---
title: Erro de Otimização Guiada por perfil PG0165
description: Descreve erros de PG0165 na leitura de dados de PGO (otimização guiada por perfil).
ms.date: 10/30/2019
f1_keywords:
- PG0165
helpviewer_keywords:
- PG0165
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
ms.openlocfilehash: c5e5c5d37f8c70a6c2a3d9f7a43c13bb46d0e25a
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626796"
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de Otimização Guiada por perfil PG0165

Ocorreu um erro ao ler dados de otimização guiados por perfil. Esse erro pode aparecer em várias formas:

> Leitura de '*filename. pgd*': ' a versão de PGD não é suportada (incompatibilidade de versão) '.

Arquivos PGD são específicos de um conjunto de ferramentas de compilador específico. Esse erro é gerado quando você está usando um compilador diferente daquele usado para criar *filename. pgd*. O erro indica que este conjunto de ferramentas de compilador não pode usar os dados de *filename. pgd* para otimizar o programa atual. Para resolver esse problema, gere o *filename*. pgd usando o conjunto de ferramentas do compilador atual.

> Lendo '*filename. pgd*': ' o arquivo PGD é somente leitura '.

Esse erro é exibido quando o arquivo PGD é marcado como somente leitura no sistema de arquivos. Para resolver esse problema, altere os atributos do arquivo para leitura/gravação.
