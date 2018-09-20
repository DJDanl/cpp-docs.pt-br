---
title: -Fx (mesclar código injetado) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ExpandAttributedSource
- /Fx
- VC.Project.VCCLCompilerTool.ExpandAttributedSource
dev_langs:
- C++
helpviewer_keywords:
- Fx compiler option [C++]
- -Fx compiler option [C++]
- injected code
- merging injected code
- /Fx compiler option [C++]
ms.assetid: 14f0e301-3bab-45a3-bbdf-e7ce66f20560
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ca8522f85a8ce10bc694ab1144e7f24ed3fca6fa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46425739"
---
# <a name="fx-merge-injected-code"></a>/Fx (mesclar código injetado)

Produz uma cópia de cada arquivo de origem com o código injetado mesclado com o código-fonte.

## <a name="syntax"></a>Sintaxe

```
/Fx
```

## <a name="remarks"></a>Comentários

Para distinguir um arquivo de origem mesclada de um arquivo de origem original **/Fx** adiciona uma extensão. mrg entre o nome de arquivo e extensão de arquivo. Por exemplo, um arquivo chamado MyCode.cpp que contém o código atribuído e compilados com **/Fx** cria um arquivo chamado MyCode.mrg.cpp que contém o código a seguir:

```
//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has
                               // already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping
                               // injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute
                               // providers
//--- End Injected Code
```

Em um arquivo. mrg, o código que foi inserido por causa de um atributo será delimitado da seguinte maneira:

```
//+++ Start Injected Code
...
//--- End Injected Code
```

O [no_injected_text](../../windows/no-injected-text.md) é inserido em um arquivo. mrg, que permite a compilação do arquivo. mrg sem texto sendo reinjected.

Você deve estar ciente de que o arquivo de origem. mrg destina-se para ser uma representação do código-fonte injetado pelo compilador. O arquivo. mrg não pode compilar ou executar exatamente como o arquivo de origem.

As macros não são expandidas no arquivo. mrg.

Se seu programa inclui um arquivo de cabeçalho que usa o código injetado **/Fx** gera um. arquivo mrg.h desse cabeçalho. **/FX** direta não inclui arquivos que não usam o código injetado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **arquivos de saída** página de propriedades.

1. Modificar a **expandir origem atribuída** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExpandAttributedSource%2A>.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)