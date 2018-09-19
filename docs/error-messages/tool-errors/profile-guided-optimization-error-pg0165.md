---
title: Erro de PG0165 Otimização Guiada por perfil | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PG0165
dev_langs:
- C++
helpviewer_keywords:
- PG0165
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 332751a123bf7d6414c40b79870b5edf27a3d8a7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084205"
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165

Leitura de 'Filename.pgd': ' não há suporte para a versão do PGD (incompatibilidade de versão)'.

Arquivos PGD são específicos para um conjunto de ferramentas do compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*. PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados do *Filename*. PGD para otimizar o programa atual.

Para resolver esse problema, regenerar *Filename*PGD usando o conjunto de ferramentas do compilador atual.