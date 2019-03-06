---
title: /FIXED (endereço básico fixo)
ms.date: 11/04/2016
f1_keywords:
- /fixed
- VC.Project.VCLinkerTool.FixedBaseAddress
helpviewer_keywords:
- preferred base address for loading program
- /FIXED linker option
- -FIXED linker option
- FIXED linker option
ms.assetid: 929bba5e-b7d8-40ed-943e-056aa3710fc5
ms.openlocfilehash: ccb89b7dfed78ddebf73aaf6e2a1a8529b065042
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423034"
---
# <a name="fixed-fixed-base-address"></a>/FIXED (endereço básico fixo)

```
/FIXED[:NO]
```

## <a name="remarks"></a>Comentários

Informa o sistema operacional para carregar o programa somente em seu endereço base preferido. Se o endereço básico preferido não estiver disponível, o sistema operacional não carregará o arquivo. Para obter mais informações, consulte [/BASE (Endereço Básico)](../../build/reference/base-base-address.md).

/Fixed: no é a configuração padrão para uma DLL e /FIXED é a configuração padrão para qualquer outro tipo de projeto.

Quando /fixo é especificado, o LINK não gera uma seção de realocação no programa. Em tempo de execução, se o sistema operacional é não é possível carregar o programa no endereço especificado, ele emite uma mensagem de erro e não carrega o programa.

Especifica /fixed: para gerar uma seção de realocação no programa.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Digite o nome da opção e a definição na **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
