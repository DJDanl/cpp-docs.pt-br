---
title: Reutilizando arquivos embutidos
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, reusing NMAKE
- revising inline files
- NMAKE program, inline files
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
ms.openlocfilehash: c4e3d9ba54a4db28ca9635725c9761e6316c4b62
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421788"
---
# <a name="reusing-inline-files"></a>Reutilizando arquivos embutidos

Para reutilizar um arquivo embutido, especifique <<*filename* onde o arquivo é definido e usado pela primeira vez, em seguida, reutilizar *filename* sem << posterior no mesmo ou outro comando. O comando para criar o arquivo embutido deve ser executado antes de todos os comandos que usam o arquivo.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)
