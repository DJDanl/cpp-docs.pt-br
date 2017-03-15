---
title: "PG0165 de erro de Otimização Guiada por perfil | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PG0165
dev_langs:
- C++
helpviewer_keywords:
- PG0165
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 06aacaa572506189b2caf7854db197239033af1f
ms.lasthandoff: 02/25/2017

---
# <a name="profile-guided-optimization-error-pg0165"></a>Erro de otimização orientada a perfil PG0165
Ler 'Filename.pgd': ' não há suporte para a versão PGD (incompatibilidade de versão)'.  
  
 Arquivos PGD são específicos para um conjunto de ferramentas do compilador específico. Esse erro é gerado quando você estiver usando um compilador diferente daquela usada para *Filename*. PGD. Esse erro indica que esse conjunto de ferramentas do compilador não pode usar os dados de *Filename*. PGD para otimizar o programa atual.  
  
 Para resolver esse problema, regenerar *Filename*. PGD usando o conjunto de ferramentas atual do compilador.
