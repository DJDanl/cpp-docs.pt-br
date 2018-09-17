---
title: – CORREÇÃO (endereço básico fixo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /fixed
- VC.Project.VCLinkerTool.FixedBaseAddress
dev_langs:
- C++
helpviewer_keywords:
- preferred base address for loading program
- /FIXED linker option
- -FIXED linker option
- FIXED linker option
ms.assetid: 929bba5e-b7d8-40ed-943e-056aa3710fc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 697f6ccfd98059175311cd04e4e82038877b2110
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723392"
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