---
title: Aviso PRJ0041 de Build de Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0041
helpviewer_keywords:
- PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
ms.openlocfilehash: bb6469b1daf193223a9b3361cc3e4bfb96d0c751
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191920"
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto

Não é possível encontrar a dependência ' Dependency ' ausente para o arquivo ' file '. Seu projeto ainda pode ser compilado, mas pode continuar aparecendo desatualizado até que esse arquivo seja encontrado.

Um arquivo (arquivo de recurso ou. idl/. ODL, por exemplo, continha uma instrução include que o sistema de projeto não pôde resolver.

Como o sistema de projeto não processa instruções de pré-processador (#if, por exemplo), a instrução incorreta pode não ser realmente parte da compilação.

Para resolver esse aviso, exclua todo o código desnecessário em arquivos. rc ou adicione arquivos de espaço reservado do nome apropriado.
