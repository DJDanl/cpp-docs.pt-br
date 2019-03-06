---
title: /INCREMENTAL (vincular de maneira incremental)
ms.date: 11/04/2016
f1_keywords:
- /incremental
- VC.Project.VCLinkerTool.LinkIncremental
helpviewer_keywords:
- /INCREMENTAL linker option
- -INCREMENTAL linker option
- INCREMENTAL linker option
- link incrementally option
- LINK tool [C++], options for full linking
- incremental linking
ms.assetid: 135656ff-94fa-4ad4-a613-22e1a2a5d16b
ms.openlocfilehash: 60cec41173afc9955bddf9df0bd6796b5df6285c
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414077"
---
# <a name="incremental-link-incrementally"></a>/INCREMENTAL (vincular de maneira incremental)

```
/INCREMENTAL[:NO]
```

## <a name="remarks"></a>Comentários

Controla como o vinculador manipula a vinculação incremental.

Por padrão, o vinculador é executado no modo incremental. Para substituir um link incremental padrão, especifique /INCREMENTAL:NO.

Um programa incrementalmente vinculado é funcionalmente equivalente a um programa que está vinculado não incrementalmente. No entanto, porque ele está preparado para links incrementais subsequentes, uma biblioteca vinculada incrementalmente de executável, estática ou arquivo de biblioteca de vínculo dinâmico:

- É maior do que um programa vinculado não incrementalmente devido ao preenchimento de código e dados. Preenchimento permite que o vinculador aumentar o tamanho das funções e dos dados sem recriar o arquivo.

- Pode conter conversões de atalho para manipular a realocação de funções para novos endereços.

   > [!NOTE]
   > Para garantir que a compilação de lançamento final não tenha preenchimento ou conversões, vincule seu programa de forma não incremental.

Para vincular de maneira incremental independentemente do padrão, especifique /INCREMENTAL. Quando essa opção é selecionada, o vinculador emitirá um aviso se ele não é possível vincular incrementalmente e vincula o programa de forma não incremental. Determinadas opções e situações substituem /INCREMENTAL.

A maioria dos programas pode ser vinculada incrementalmente. Entretanto, algumas alterações são muito grandes e algumas opções são incompatíveis com a vinculação incremental. O LINK executa uma vinculação completa se qualquer uma das seguintes opções for especificada:

- Vincular Incrementalmente não está selecionado (/INCREMENTAL:NO)

- /OPT:REF está selecionado

- /OPT:ICF está selecionado

- /OPT:LBR está selecionado

- /ORDER está selecionado

/INCREMENTAL é inferido quando [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado.

Além disso, o LINK executa uma vinculação completa se qualquer uma das seguintes situações ocorrer:

- Está faltando o arquivo de status incremental (.ilk). (O LINK cria um novo arquivo .ilk em preparação para a vinculação incremental subsequente.)

- Não há permissão de gravação para o arquivo .ilk. (O LINK ignora o arquivo. ilk e links de forma não incremental.)

- Está faltando o arquivo de saída .exe ou .dll.

- O carimbo de data/hora de .ilk, .exe ou .dll foi alterado.

- Uma opção LINK foi modificada. A maioria das opções LINK, quando alteradas entre as compilações, causa uma vinculação completa.

- Um arquivo de objeto (.obj) foi adicionado ou omitido.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **geral** página de propriedades.

1. Modificar a **habilitar vinculação Incremental** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkIncremental%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
