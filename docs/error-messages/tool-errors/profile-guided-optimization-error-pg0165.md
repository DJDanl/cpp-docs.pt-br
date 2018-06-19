---
title: PG0165 de erro de Otimização Guiada por perfil | Microsoft Docs
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
ms.openlocfilehash: acad97411480112d06dadd454d1368dcfdf2c87f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318409"
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165
Ler 'Filename.pgd': ' não há suporte para a versão do PGD (incompatibilidade de versão)'.  
  
 Arquivos PGD são específicos para um conjunto de ferramentas de compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados de *Filename*PGD para otimizar o programa atual.  
  
 Para resolver esse problema, regenerar *Filename*PGD usando o conjunto de ferramentas de compilador atual.