---
title: /VERSION (informações da versão)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.Version
- /version
helpviewer_keywords:
- -VERSION linker option
- Version Information linker option
- version numbers, specifying in .exe
- /VERSION linker option
- VERSION linker option
ms.assetid: b86d0e86-dca6-4316-aee2-d863ccb9f223
ms.openlocfilehash: 626461fc7a9fc6dd7b6578e836733d154a66862a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316490"
---
# <a name="version-version-information"></a>/VERSION (informações da versão)

```
/VERSION:major[.minor]
```

## <a name="arguments"></a>Arguments

*principais* e *secundária*<br/>
O número de versão que você deseja no cabeçalho do arquivo. dll ou. .exe.

## <a name="remarks"></a>Comentários

A opção /VERSION informa o vinculador para colocar um número de versão no cabeçalho do arquivo. dll ou. .exe. Use DUMPBIN [/HEADERS](headers.md) para ver o campo de versão de imagem do OPTIONAL HEADER VALUES para ver o efeito de /Version.

O *principais* e *secundárias* argumentos são números decimais no intervalo de 0 a 65.535. O padrão é a versão 0.0.

As informações especificadas com /VERSION não afetam as informações de versão que aparece para um aplicativo quando você exibe suas propriedades no Explorador de arquivos. Essas informações de versão vem de um arquivo de recurso que é usado para compilar o aplicativo. Ver [Editor de informações de versão](../../windows/version-information-editor.md) para obter mais informações.

Outra maneira de inserir um número de versão é com o [versão](version-c-cpp.md) instrução de definição de módulo.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **geral** página de propriedades.

1. Modificar a **versão** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Version%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
