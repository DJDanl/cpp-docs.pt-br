---
title: Erro de otimização orientada a perfil PG0165
ms.date: 11/04/2016
f1_keywords:
- PG0165
helpviewer_keywords:
- PG0165
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
ms.openlocfilehash: f39bbe6540ebec10cd25c41ac2fe9f2acfca9b13
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359729"
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165

Leitura de 'Filename.pgd': ' Não há suporte para a versão do PGD (incompatibilidade de versão)'.

Arquivos PGD são específicos para um conjunto de ferramentas do compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*. PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados do *Filename*. PGD para otimizar o programa atual.

Para resolver esse problema, regenerar *Filename*PGD usando o conjunto de ferramentas do compilador atual.