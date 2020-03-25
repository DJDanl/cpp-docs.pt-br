---
title: Erro de Build PRJ0008 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0008
helpviewer_keywords:
- PRJ0008
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
ms.openlocfilehash: 7d1c11ab7539f25d371c0bfbd2853b6155c9661c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192946"
---
# <a name="project-build-error-prj0008"></a>Erro de Build PRJ0008 no Projeto

Não foi possível excluir o arquivo ' file '.

**Verifique se o arquivo não está aberto por outro processo e não está protegido contra gravação.**

Durante uma recompilação ou limpeza, C++ o Visual exclui todos os arquivos de saída e intermediários conhecidos para a compilação, bem como todos os arquivos que atendem às especificações de curinga nas **extensões a serem excluídas na propriedade limpar** na [página de propriedades definições de configuração geral](../../build/reference/general-property-page-project.md).

Você verá esse erro se o Visual C++ não puder excluir um arquivo. Para resolver o erro, torne o arquivo e seu diretório graváveis para o usuário que está fazendo a compilação.
