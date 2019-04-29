---
title: Erro fatal C1052
ms.date: 05/08/2017
f1_keywords:
- C1052
helpviewer_keywords:
- C1052
ms.assetid: f2c09a2f-d3c1-4420-9501-ffcb65caf87b
ms.openlocfilehash: b381cc3cfe27d4c4a9d744a6b854a0e43727fe71
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62243651"
---
# <a name="fatal-error-c1052"></a>Erro fatal C1052

> arquivo de banco de dados do programa, '*filename*', foi gerado pelo vinculador com /debug: fastlink; compilador não pode atualizar esses arquivos PDB; exclua-o ou use /Fd para especificar um nome de arquivo PDB diferente

O compilador não é possível atualizar os mesmos arquivos de banco de dados (PDB) do programa, que são gerados pelo vinculador quando o [/Debug: fastlink](../../build/reference/debug-generate-debug-info.md) opção for especificada. Normalmente, os arquivos PDB gerado pelo compilador e os arquivos PDB gerado pelo vinculador têm nomes diferentes. No entanto, se elas estiverem definidas para usar os mesmos nomes, esse erro pode resultar.

Para corrigir esse problema, você pode excluir explicitamente os arquivos PDB antes de você compilar novamente, ou você pode criar nomes diferentes para os arquivos PDB gerado pelo compilador e geradas pelo vinculador.

Para especificar o nome do arquivo PDB gerado pelo compilador na linha de comando, use o [/Fd](../../build/reference/fd-program-database-file-name.md) opção de compilador. Para especificar o nome do arquivo PDB gerado pelo compilador no IDE, abra o **páginas de propriedades** caixa de diálogo para o seu projeto e nos **propriedades de configuração**, **C/C++**,  **Arquivos de saída** , defina a **nome do arquivo de banco de dados de programa** propriedade. Por padrão, essa propriedade é `$(IntDir)vc$(PlatformToolsetVersion).pdb`.

Como alternativa, você pode definir o nome do arquivo PDB gerado pelo vinculador. Para especificar o nome do arquivo PDB gerado pelo vinculador na linha de comando, use o [/PDB](../../build/reference/pdb-use-program-database.md) a opção de vinculador. Para especificar o nome do arquivo PDB gerado pelo vinculador no IDE, abra o **páginas de propriedades** caixa de diálogo para o seu projeto e nos **propriedades de configuração**, **vinculador**,  **Depurando** , defina a **gerar arquivo de banco de dados do programa** propriedade. Por padrão, essa propriedade é definida como `$(OutDir)$(TargetName).pdb`.
