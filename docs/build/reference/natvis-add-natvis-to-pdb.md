---
title: /NATVIS (adicionar o Natvis ao PDB)
ms.date: 08/10/2017
f1_keywords:
- /natvis
- VC.Project.VCLinkerTool.ImportLIbrary
helpviewer_keywords:
- NATVIS linker option
- /NATVIS linker option
- -NATVIS linker option
- Add Natvis file to PDB
ms.assetid: 8747fc0c-701a-4796-bb4d-818ab4465cca
ms.openlocfilehash: e758a49b41a17d805b752947cd1944087c8ff852
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809230"
---
# <a name="natvis-add-natvis-to-pdb"></a>/NATVIS (adicionar o Natvis ao PDB)

> /NATVIS:*filename*

## <a name="parameters"></a>Parâmetros

*filename*<br/>
Um arquivo Natvis para adicionar o arquivo PDB. Ele incorpora as visualizações do depurador no arquivo Natvis ao PDB.

## <a name="remarks"></a>Comentários

A opção /NATVIS incorpora as visualizações de depurador definidas no arquivo Natvis *filename* no arquivo PDB gerado pelo LINK. Isso permite que o depurador exibir as visualizações independentemente do arquivo. natvis. Você pode usar várias opções de /NATVIS para inserir mais de um arquivo Natvis no arquivo PDB gerado.

LINK ignora /NATVIS quando um arquivo PDB não é criado usando um [/Debug](debug-generate-debug-info.md) opção. Para obter informações sobre a criação e uso de arquivos. natvis, consulte [criar exibições personalizadas de objetos nativos no depurador do Visual Studio](/visualstudio/debugger/create-custom-views-of-native-objects).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **linha de comando** página de propriedades na **vinculador** pasta.

1. Adicione a opção /NATVIS para o **opções adicionais** caixa de texto.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
