---
title: Reutilizando arquivos embutidos
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, reusing NMAKE
- revising inline files
- NMAKE program, inline files
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
ms.openlocfilehash: ceaba468427b2acbe355c9004655de7bc6178041
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824336"
---
# <a name="reusing-inline-files"></a>Reutilizando arquivos embutidos

Para reutilizar um arquivo embutido, especifique <<*filename* onde o arquivo é definido e usado pela primeira vez, em seguida, reutilizar *filename* sem << posterior no mesmo ou outro comando. O comando para criar o arquivo embutido deve ser executado antes de todos os comandos que usam o arquivo.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](inline-files-in-a-makefile.md)
