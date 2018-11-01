---
title: Reutilizando arquivos embutidos
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, reusing NMAKE
- revising inline files
- NMAKE program, inline files
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
ms.openlocfilehash: 15c0fa5eb10389faf7962c29cc8452443512f739
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453537"
---
# <a name="reusing-inline-files"></a>Reutilizando arquivos embutidos

Para reutilizar um arquivo embutido, especifique <<*filename* onde o arquivo é definido e usado pela primeira vez, em seguida, reutilizar *filename* sem << posterior no mesmo ou outro comando. O comando para criar o arquivo embutido deve ser executado antes de todos os comandos que usam o arquivo.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)