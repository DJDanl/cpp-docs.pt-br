---
title: Erro de Build prj0006 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0006
dev_langs:
- C++
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 264b2f90a2d778b1545117ce5c3b1272626ebad6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073246"
---
# <a name="project-build-error-prj0006"></a>Erro de Build PRJ0006 no Projeto

Não foi possível abrir o arquivo temporário 'arquivo'. Verifique se o arquivo existe e que o diretório não está protegido contra gravação.

Visual C++ não foi possível criar um arquivo temporário durante o processo de compilação. Motivos para isso:

- Nenhum diretório temporário.

- Diretório temporário de somente leitura.

- Espaço em disco.

- A pasta $ (IntDir) é somente leitura ou contém arquivos temporários que são somente leitura.

Esse erro também ocorrerá erro prj0007 na seguir: não foi possível criar o diretório de saída 'diretório'. Erro prj0007 no significa que não foi possível criar o diretório $ (IntDir), indicando a criação de arquivos temporariamente também falharão.

Arquivos temporários são criados sempre que você especificar:

- Um arquivo de resposta.

- Uma etapa de compilação personalizada.

- Um evento de build.