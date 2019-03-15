---
title: /DLL (compilar uma DLL)
ms.date: 11/04/2016
f1_keywords:
- /dll
helpviewer_keywords:
- -DLL linker option
- /DLL linker option [C++]
- exporting DLLs [C++], specifying exports
- DLLs [C++], building
- DLL linker option [C++]
ms.assetid: c7685aec-31d0-490f-9503-fb5171a23609
ms.openlocfilehash: 5f7907d659ee3bedc590b88320df03edce005b06
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820501"
---
# <a name="dll-build-a-dll"></a>/DLL (compilar uma DLL)

```
/DLL
```

## <a name="remarks"></a>Comentários

A opção /DLL compila uma DLL que o arquivo de saída principal. Geralmente, uma DLL contém exportações que podem ser usadas por outro programa. Há três métodos para especificação de exportações, listadas na ordem recomendada de uso:

1. [dllexport](../../cpp/dllexport-dllimport.md) no código-fonte

1. Uma [exportações](exports.md) instrução em um arquivo. def

1. Uma [/exportação](export-exports-a-function.md) especificação em um comando LINK

Um programa pode usar mais de um método.

Outra maneira de criar uma DLL é com o **biblioteca** instrução de definição de módulo. As opções /BASE e /DLL juntos são equivalentes para o **biblioteca** instrução.

Não especifique essa opção dentro do ambiente de desenvolvimento. Essa opção é para uso somente na linha de comando. Essa opção é definida quando você cria um projeto de DLL com um Assistente de aplicativo.

Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao compilar a biblioteca de importação.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **propriedades de configuração** pasta.

1. Clique o **geral** página de propriedades.

1. Modificar a **tipo de configuração** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCPropertySheet.ConfigurationType%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
