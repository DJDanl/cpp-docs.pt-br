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
ms.openlocfilehash: 6cc89df76e48ee258a7c6608aab12573ab11729b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292478"
---
# <a name="fixed-fixed-base-address"></a>/FIXED (endereço básico fixo)

```
/FIXED[:NO]
```

## <a name="remarks"></a>Comentários

Informa o sistema operacional para carregar o programa somente em seu endereço base preferido. Se o endereço básico preferido não estiver disponível, o sistema operacional não carregará o arquivo. Para obter mais informações, consulte [/BASE (Endereço Básico)](base-base-address.md).

/Fixed: no é a configuração padrão para uma DLL e /FIXED é a configuração padrão para qualquer outro tipo de projeto.

Quando /fixo é especificado, o LINK não gera uma seção de realocação no programa. Em tempo de execução, se o sistema operacional é não é possível carregar o programa no endereço especificado, ele emite uma mensagem de erro e não carrega o programa.

Especifica /fixed: para gerar uma seção de realocação no programa.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Digite o nome da opção e a definição na **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
