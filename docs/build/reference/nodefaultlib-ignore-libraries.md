---
title: /NODEFAULTLIB (ignorar bibliotecas)
ms.date: 11/04/2016
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
ms.openlocfilehash: 12a6e988828d1e4e2dbdc46d49da5ff2fe9e9d8d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50473769"
---
# <a name="nodefaultlib-ignore-libraries"></a>/NODEFAULTLIB (ignorar bibliotecas)

```
/NODEFAULTLIB[:library]
```

## <a name="arguments"></a>Arguments

*Biblioteca*<br/>
Uma biblioteca que você deseja que o vinculador ignore ao resolver referências externas.

## <a name="remarks"></a>Comentários

A opção /NODEFAULTLIB informa o vinculador para remover uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas.

Para criar um arquivo. obj que contém referências a bibliotecas padrão, use [/Zl (omitir nome da biblioteca padrão)](../../build/reference/zl-omit-default-library-name.md).

Por padrão, /NODEFAULTLIB remove todas as bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas. Opcional *biblioteca* parâmetro permite que você remover uma biblioteca especificada ou bibliotecas da lista de bibliotecas que busca ao resolver referências externas. Especifica uma opção /NODEFAULTLIB para cada biblioteca que você deseja excluir.

O vinculador resolve referências para definições externas por meio da pesquisa pela primeira vez em bibliotecas que você especificar explicitamente, em seguida, em default bibliotecas especificada com a opção de /DEFAULTLIB e, em seguida, nas bibliotecas padrão chamadas nos arquivos. obj.

/NODEFAULTLIB:*biblioteca* substitui [/DEFAULTLIB:](../../build/reference/defaultlib-specify-default-library.md)*biblioteca* quando o mesmo *biblioteca* nome é especificado em ambos.

Se você usar /NODEFAULTLIB, por exemplo, para compilar seu programa sem a biblioteca de tempo de execução C, talvez você precise usar também [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar o ponto de entrada (função) em seu programa. Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **entrada**página de propriedades.

1. Selecione o **ignorar todas as bibliotecas padrão** propriedade ou especifique uma lista das bibliotecas que você deseja ignorar na **ignorar biblioteca específica** propriedade. O **linha de comando** página de propriedade mostra o efeito das alterações que você pode fazer a essas propriedades.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreDefaultLibraryNames%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreAllDefaultLibraries%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)