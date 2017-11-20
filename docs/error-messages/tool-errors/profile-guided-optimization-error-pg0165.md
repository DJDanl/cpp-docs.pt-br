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
ms.openlocfilehash: dbc85ad329a990ecdd7bc3a05f28d16a0c58c8e8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165
Ler 'Filename.pgd': ' não há suporte para a versão do PGD (incompatibilidade de versão)'.  
  
 Arquivos PGD são específicos para um conjunto de ferramentas de compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados de *Filename*PGD para otimizar o programa atual.  
  
 Para resolver esse problema, regenerar *Filename*PGD usando o conjunto de ferramentas de compilador atual.