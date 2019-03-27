---
title: /NODEFAULTLIB (ignorar bibliotecas)
ms.date: 03/26/2019
f1_keywords:
- VC.Project.VCLinkerTool.OVERWRITEAllDefaultLibraries
- VC.Project.VCLinkerTool.OVERWRITEDefaultLibraryNames
- /nodefaultlib
helpviewer_keywords:
- default libraries, removing
- -NODEFAULTLIB linker option
- libraries, ignore
- NODEFAULTLIB linker option
- /NODEFAULTLIB linker option
- ignore libraries linker option
ms.assetid: 7270b673-6711-468e-97a7-c2925ac2be6e
ms.openlocfilehash: 24528eb4c387c4cd0921ab089370d72b076ad640
ms.sourcegitcommit: 06fc71a46e3c4f6202a1c0bc604aa40611f50d36
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/27/2019
ms.locfileid: "58508748"
---
# <a name="nodefaultlib-ignore-libraries"></a>/NODEFAULTLIB (ignorar bibliotecas)

> **/NODEFAULTLIB**[__:__*library*]

## <a name="arguments"></a>Arguments

*library*<br/>
Uma biblioteca que você deseja que o vinculador ignore ao resolver referências externas.

## <a name="remarks"></a>Comentários

A opção /NODEFAULTLIB informa o vinculador para remover uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas.

Para criar um arquivo. obj que não contém nenhuma referência às bibliotecas padrão, use [/Zl (omitir nome da biblioteca padrão)](zl-omit-default-library-name.md).

Por padrão, /NODEFAULTLIB remove todas as bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas. Opcional *biblioteca* parâmetro permite que você remover uma biblioteca especificada da lista de bibliotecas que busca ao resolver referências externas. Especifica uma opção /NODEFAULTLIB para cada biblioteca que você deseja excluir.

O vinculador resolve referências para definições externas por meio da pesquisa pela primeira vez em bibliotecas que você especificar explicitamente, em seguida, em default bibliotecas especificado com o [/DEFAULTLIB:](defaultlib-specify-default-library.md) opção, e, em seguida, em default bibliotecas nomeado em. obj arquivos.

/NODEFAULTLIB:*biblioteca* substitui /DEFAULTLIB:*biblioteca* quando o mesmo *biblioteca* nome é especificado em ambos.

Se você usar /NODEFAULTLIB para compilar o programa sem a biblioteca de tempo de execução C, talvez você precise usar também [/ENTRY](entry-entry-point-symbol.md) para especificar a função de ponto de entrada em seu programa. Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **entrada** página de propriedades.

1. Selecione o **ignorar todas as bibliotecas padrão** propriedade. Ou, especifique uma lista separada por vírgulas das bibliotecas que você deseja ignorar na **ignorar bibliotecas padrão específicas** propriedade. O **linha de comando** página de propriedades mostra o efeito das alterações que você pode fazer a essas propriedades.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreDefaultLibraryNames%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreAllDefaultLibraries%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
