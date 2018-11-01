---
title: Erro fatal C1047
ms.date: 11/04/2016
f1_keywords:
- C1047
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
ms.openlocfilehash: 053c4d828b3583d0e16ab8f4fe03a4b0bbed96f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50663171"
---
# <a name="fatal-error-c1047"></a>Erro fatal C1047

O arquivo de biblioteca ou objeto 'file' foi criado com um compilador mais antigo que os demais objetos; recriar os objetos e bibliotecas antigas

C1047 é causado quando os arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.

Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não faça uma nova recompilação de arquivos de objeto existente ou bibliotecas.

Para resolver C1047, recompile todos os arquivos de objeto ou bibliotecas.