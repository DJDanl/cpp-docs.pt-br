---
title: /NOENTRY (sem ponto de entrada)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.ResourceOnlyDLL
- /noentry
helpviewer_keywords:
- entry points [C++], linker specifying
- -NOENTRY linker option
- resource-only DLLs [C++], creating
- NOENTRY linker option
- /NOENTRY linker option [C++]
- DLLs [C++], creating
ms.assetid: 0214dd41-35ad-43ab-b892-e636e038621a
ms.openlocfilehash: fef4340fa4bb130ac54f4d5e66d4cd4d2f2a3049
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607357"
---
# <a name="noentry-no-entry-point"></a>/NOENTRY (sem ponto de entrada)

```
/NOENTRY
```

## <a name="remarks"></a>Comentários

A opção /NOENTRY é necessária para a criação de uma DLL apenas de recursos que não contenha códigos executáveis. Para obter mais informações, consulte [criando uma DLL Resource-Only](../../build/creating-a-resource-only-dll.md).

Use essa opção para impedir que o LINK vincule uma referência a `_main` na DLL.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **avançado** página de propriedades.

1. Modificar a **nenhum ponto de entrada** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ResourceOnlyDLL%2A>.

## <a name="see-also"></a>Consulte também

[Criando uma DLL somente de recurso](../../build/creating-a-resource-only-dll.md)<br/>
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)