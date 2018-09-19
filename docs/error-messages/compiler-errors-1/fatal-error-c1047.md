---
title: Erro fatal C1047 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1047
dev_langs:
- C++
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1983fa0a18667d98f84dfe5049afd4e872d87d93
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46021584"
---
# <a name="fatal-error-c1047"></a>Erro fatal C1047

O arquivo de biblioteca ou objeto 'file' foi criado com um compilador mais antigo que os demais objetos; recriar os objetos e bibliotecas antigas

C1047 é causado quando os arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.

Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não faça uma nova recompilação de arquivos de objeto existente ou bibliotecas.

Para resolver C1047, recompile todos os arquivos de objeto ou bibliotecas.