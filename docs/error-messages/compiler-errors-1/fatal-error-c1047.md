---
title: Erro fatal C1047
ms.date: 11/04/2016
f1_keywords:
- C1047
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
ms.openlocfilehash: 5ab98c46d60d15cdcb6de22aa922d62453d41880
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204484"
---
# <a name="fatal-error-c1047"></a>Erro fatal C1047

O arquivo de objeto ou de biblioteca ' file ' foi criado com um compilador mais antigo do que outros objetos; Recompilar objetos e bibliotecas antigos

C1047 é causado quando arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criados com versões diferentes C++ do conjunto de ferramentas Visual.

Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não fizer uma recompilação limpa de arquivos de objeto ou bibliotecas existentes.

Para resolver C1047, recompile todos os arquivos de objeto ou bibliotecas.
