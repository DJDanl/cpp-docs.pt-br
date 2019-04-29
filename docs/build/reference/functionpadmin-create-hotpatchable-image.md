---
title: /FUNCTIONPADMIN (Criar imagem hotpatchable)
ms.date: 03/09/2018
f1_keywords:
- /functionpadmin
helpviewer_keywords:
- -FUNCTIONPADMIN linker option
- /FUNCTIONPADMIN linker option
ms.assetid: 25b02c13-1add-4fbd-add9-fcb30eb2cae7
ms.openlocfilehash: 699da3cea9914b5a10bdf769015d41c33936a902
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292387"
---
# <a name="functionpadmin-create-hotpatchable-image"></a>/FUNCTIONPADMIN (Criar imagem hotpatchable)

Prepara uma imagem para patch instantâneo.

## <a name="syntax"></a>Sintaxe

> **/FUNCTIONPADMIN**[**:**_space_]

### <a name="arguments"></a>Arguments

*space*<br/>
A quantidade de preenchimento a ser adicionado ao início de cada função em bytes. Em x86, o padrão será a 5 bytes de preenchimento e em x64, o padrão será a 6 bytes. Em outros destinos, um valor deve ser fornecido.

## <a name="remarks"></a>Comentários

Em ordem para o vinculador produzir uma imagem de hotpatchable, os arquivos. obj devem ter sido compilados com [/hotpatch (Criar imagem de Hotpatchable)](hotpatch-create-hotpatchable-image.md).

Quando você compila e vincula uma imagem com uma única chamada de cl.exe, **/hotpatch** implica **/functionpadmin**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/FUNCTIONPADMIN** opção **opções adicionais**. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
