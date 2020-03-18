---
title: /NATVIS (adicionar o Natvis ao PDB)
ms.date: 08/10/2017
f1_keywords:
- /natvis
helpviewer_keywords:
- NATVIS linker option
- /NATVIS linker option
- -NATVIS linker option
- Add Natvis file to PDB
ms.assetid: 8747fc0c-701a-4796-bb4d-818ab4465cca
ms.openlocfilehash: a16e320a2f8f946912fef6a354f27f6514a67e29
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439280"
---
# <a name="natvis-add-natvis-to-pdb"></a>/NATVIS (adicionar o Natvis ao PDB)

> /NATVIS:*nome de arquivo*

## <a name="parameters"></a>Parâmetros

*filename*<br/>
Um arquivo Natvis para adicionar ao arquivo PDB. Ele incorpora as visualizações do depurador no arquivo Natvis no PDB.

## <a name="remarks"></a>Comentários

A opção/NATVIS incorpora as visualizações do depurador definidas no *nome* do arquivo de NATVIS no arquivo PDB gerado pelo link. Isso permite que o depurador exiba as visualizações independentemente do arquivo. natvis. Você pode usar várias opções de/NATVIS para inserir mais de um arquivo Natvis no arquivo PDB gerado.

O LINK ignora/NATVIS quando um arquivo PDB não é criado usando uma opção [/debug](debug-generate-debug-info.md) . Para obter informações sobre a criação e o uso de arquivos. natvis, consulte [criar exibições personalizadas de objetos nativos no depurador do Visual Studio](/visualstudio/debugger/create-custom-views-of-native-objects).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de **linha de comando** na pasta do **vinculador** .

1. Adicione a opção/NATVIS à caixa de texto **Opções adicionais** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
