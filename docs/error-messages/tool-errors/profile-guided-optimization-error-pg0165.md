---
title: "PG0165 de erro de Otimização Guiada por perfil | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PG0165
dev_langs: C++
helpviewer_keywords: PG0165
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 32b9f5f3ee335aac0a8382377aa850c3b91a27a0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165
Ler 'Filename.pgd': ' não há suporte para a versão do PGD (incompatibilidade de versão)'.  
  
 Arquivos PGD são específicos para um conjunto de ferramentas de compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados de *Filename*PGD para otimizar o programa atual.  
  
 Para resolver esse problema, regenerar *Filename*PGD usando o conjunto de ferramentas de compilador atual.